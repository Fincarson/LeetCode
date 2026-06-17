# 2615. Sum of Distances

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-distances/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 2615 - Sum of Distances](https://leetcode.com/problems/sum-of-distances/)

## Problem

You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.

### Example 1

```text
Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation:
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
When i = 4, arr[4] = 0 because there is no other index with value 2.
```

### Example 2

```text
Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109

Note: This question is the same as  2121: Intervals Between Identical Elements.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Make All Array Elements Equal](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2615. Sum of Distances

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Grouping + Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Grouping + Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int* indices;
    int count;
    int capacity;
    UT_hash_handle hh;
} Group;

long long* distance(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    long long* res = (long long*)calloc(numsSize, sizeof(long long));
    Group* map = NULL;

    for (int i = 0; i < numsSize; i++) {
        Group* g = NULL;
        HASH_FIND_INT(map, &nums[i], g);
        if (!g) {
            g = (Group*)malloc(sizeof(Group));
            g->key = nums[i];
            g->capacity = 16;
            g->indices = (int*)malloc(g->capacity * sizeof(int));
            g->count = 0;
            HASH_ADD_INT(map, key, g);
        }
        if (g->count == g->capacity) {
            g->capacity *= 2;
            g->indices = (int*)realloc(g->indices, g->capacity * sizeof(int));
        }
        g->indices[g->count++] = i;
    }

    Group *g, *tmp;
    HASH_ITER(hh, map, g, tmp) {
        long long total = 0;
        for (int j = 0; j < g->count; j++) {
            total += g->indices[j];
        }
        long long prefixTotal = 0;
        for (int j = 0; j < g->count; j++) {
            int idx = g->indices[j];
            res[idx] =
                total - prefixTotal * 2 + (long long)idx * (2 * j - g->count);
            prefixTotal += idx;
        }
        HASH_DEL(map, g);
        free(g->indices);
        free(g);
    }

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }
        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] =
                    total - prefixTotal * 2 + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long[] Distance(int[] nums) {
        int n = nums.Length;
        var groups = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            if (!groups.ContainsKey(nums[i])) {
                groups[nums[i]] = new List<int>();
            }
            groups[nums[i]].Add(i);
        }
        long[] res = new long[n];
        foreach (var group in groups.Values) {
            long total = 0;
            foreach (int idx in group) {
                total += idx;
            }
            long prefixTotal = 0;
            int sz = group.Count;
            for (int i = 0; i < sz; i++) {
                int idx = group[i];
                res[idx] = total - prefixTotal * 2 + (long)idx * (2 * i - sz);
                prefixTotal += idx;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func distance(nums []int) []int64 {
	n := len(nums)
	groups := make(map[int][]int)
	for i := 0; i < n; i++ {
		groups[nums[i]] = append(groups[nums[i]], i)
	}
	res := make([]int64, n)
	for _, group := range groups {
		var total int64
		for _, idx := range group {
			total += int64(idx)
		}
		var prefixTotal int64
		for i, idx := range group {
			res[idx] = total - prefixTotal*2 + int64(idx)*int64(2*i-len(group))
			prefixTotal += int64(idx)
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long[] distance(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            groups.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        long[] res = new long[n];
        for (List<Integer> group : groups.values()) {
            long total = 0;
            for (int idx : group) {
                total += idx;
            }
            long prefixTotal = 0;
            int sz = group.size();
            for (int i = 0; i < sz; i++) {
                int idx = group.get(i);
                res[idx] = total - prefixTotal * 2 + (long) idx * (2 * i - sz);
                prefixTotal += idx;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var distance = function (nums) {
    const n = nums.length;
    const groups = new Map();
    for (let i = 0; i < n; i++) {
        if (!groups.has(nums[i])) {
            groups.set(nums[i], []);
        }
        groups.get(nums[i]).push(i);
    }
    const res = new Array(n).fill(0);
    for (const group of groups.values()) {
        let total = 0;
        for (const idx of group) {
            total += idx;
        }
        let prefixTotal = 0;
        const sz = group.length;
        for (let i = 0; i < sz; i++) {
            const idx = group[i];
            res[idx] = total - prefixTotal * 2 + idx * (2 * i - sz);
            prefixTotal += idx;
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distance(self, nums: list[int]) -> list[int]:
        n = len(nums)
        groups = defaultdict(list)
        for i, v in enumerate(nums):
            groups[v].append(i)
        res = [0] * n
        for group in groups.values():
            total = sum(group)
            prefix_total = 0
            sz = len(group)
            for i, idx in enumerate(group):
                res[idx] = total - prefix_total * 2 + idx * (2 * i - sz)
                prefix_total += idx
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function distance(nums: number[]): number[] {
    const n = nums.length;
    const groups = new Map<number, number[]>();
    for (let i = 0; i < n; i++) {
        if (!groups.has(nums[i])) {
            groups.set(nums[i], []);
        }
        groups.get(nums[i])!.push(i);
    }
    const res = new Array(n).fill(0);
    for (const group of groups.values()) {
        let total = 0;
        for (const idx of group) {
            total += idx;
        }
        let prefixTotal = 0;
        const sz = group.length;
        for (let i = 0; i < sz; i++) {
            const idx = group[i];
            res[idx] = total - prefixTotal * 2 + idx * (2 * i - sz);
            prefixTotal += idx;
        }
    }
    return res;
}
```

</details>
