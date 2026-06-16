# 2099. Find Subsequence of Length K With the Largest Sum

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)  
`Array` `Hash Table` `Sorting` `Heap (Priority Queue)`

**Problem Link:** [LeetCode 2099 - Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)

## Problem

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
```

### Example 2

```text
Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.
```

### Example 3

```text
Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].
```

## Constraints

- 1 <= nums.length <= 1000
- -105 <= nums[i] <= 105
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Difference in Sums After Removal of Elements](https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2099. Find Subsequence of Length K With the Largest Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int index;
    int value;
} Pair;

int compareValueDesc(const void* a, const void* b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

int compareIndexAsc(const void* a, const void* b) {
    return ((Pair*)a)->index - ((Pair*)b)->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    Pair* vals = (Pair*)malloc(numsSize * sizeof(Pair));  // auxiliary array
    for (int i = 0; i < numsSize; ++i) {
        vals[i].index = i;
        vals[i].value = nums[i];
    }
    // sort by numerical value in descending order
    qsort(vals, numsSize, sizeof(Pair), compareValueDesc);
    // select the first k elements and sort them in ascending order by index
    qsort(vals, k, sizeof(Pair), compareIndexAsc);
    int* res = (int*)malloc(k * sizeof(int));  // target subsequence
    for (int i = 0; i < k; ++i) {
        res[i] = vals[i].value;
    }
    *returnSize = k;
    free(vals);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;  // auxiliary array
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }
        // sort by numerical value in descending order
        sort(vals.begin(), vals.end(),
             [&](auto x1, auto x2) { return x1.second > x2.second; });
        // select the first k elements and sort them in ascending order by index
        sort(vals.begin(), vals.begin() + k);
        vector<int> res;  // target subsequence
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
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
    public int[] MaxSubsequence(int[] nums, int k) {
        int n = nums.Length;
        int[,] vals =
            new int[n, 2];  // two-dimensional array stores index and value
        for (int i = 0; i < n; ++i) {
            vals[i, 0] = i;        // store index
            vals[i, 1] = nums[i];  // store value
        }
        // sort by numerical value in descending order
        var sortedVals =
            Enumerable.Range(0, n)
                .Select(i => new { Index = vals[i, 0], Value = vals[i, 1] })
                .OrderByDescending(x => x.Value)
                .ToArray();
        // select the first k elements and sort them in ascending order by index
        var topK = sortedVals.Take(k).OrderBy(x => x.Index).ToArray();
        int[] res = new int[k];  // target subsequence
        for (int i = 0; i < k; ++i) {
            res[i] = topK[i].Value;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubsequence(nums []int, k int) []int {
	n := len(nums)
	vals := make([][]int, n) // auxiliary array
	for i := 0; i < n; i++ {
		vals[i] = []int{i, nums[i]}
	}
	// sort by numerical value in descending order
	sort.Slice(vals, func(i, j int) bool {
		return vals[i][1] > vals[j][1]
	})
	// select the first k elements and sort them in ascending order by index
	sort.Slice(vals[:k], func(i, j int) bool {
		return vals[i][0] < vals[j][0]
	})
	res := make([]int, k) // target subsequence
	for i := 0; i < k; i++ {
		res[i] = vals[i][1]
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int[][] vals = new int[n][2]; // two-dimensional array stores index and value
        for (int i = 0; i < n; ++i) {
            vals[i][0] = i; // store index
            vals[i][1] = nums[i]; // store value
        }
        // sort by numerical value in descending order
        Arrays.sort(vals, (x1, x2) -> Integer.compare(x2[1], x1[1]));
        // select the first k elements and sort them in ascending order by index
        Arrays.sort(vals, 0, k, (x1, x2) -> Integer.compare(x1[0], x2[0]));
        int[] res = new int[k]; // target subsequence
        for (int i = 0; i < k; ++i) {
            res[i] = vals[i][1];
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubsequence = function (nums, k) {
    const n = nums.length;
    const vals = []; // auxiliary array
    for (let i = 0; i < n; ++i) {
        vals.push({ index: i, value: nums[i] }); // store index and value
    }
    // sort by numerical value in descending order
    vals.sort((x1, x2) => x2.value - x1.value);
    // select the first k elements and sort them in ascending order by index
    const topK = vals.slice(0, k); // get the first k elements
    topK.sort((x1, x2) => x1.index - x2.index); // Sort the first k elements in ascending index
    const res = []; // target subsequence
    for (let i = 0; i < k; ++i) {
        res.push(topK[i].value); // add the sorted values to the result
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        vals = [[i, nums[i]] for i in range(n)]  # auxiliary array
        # sort by numerical value in descending order
        vals.sort(key=lambda x: -x[1])
        # select the first k elements and sort them in ascending order by index
        vals = sorted(vals[:k])
        res = [val for idx, val in vals]  # target subsequence
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubsequence(nums: number[], k: number): number[] {
    const n = nums.length;
    const vals: { index: number; value: number }[] = []; // auxiliary array
    for (let i = 0; i < n; ++i) {
        vals.push({ index: i, value: nums[i] }); // store index and value
    }
    // sort by numerical value in descending order
    vals.sort((x1, x2) => x2.value - x1.value);
    // select the first k elements and sort them in ascending order by index
    const topK = vals.slice(0, k); // get the first k elements
    topK.sort((x1, x2) => x1.index - x2.index); // Sort the first k elements in ascending index
    const res: number[] = []; // target subsequence
    for (let i = 0; i < k; ++i) {
        res.push(topK[i].value); // add the sorted values to the result
    }
    return res;
}
```

</details>
