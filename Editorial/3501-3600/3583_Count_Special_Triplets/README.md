# 3583. Count Special Triplets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-special-triplets/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 3583 - Count Special Triplets](https://leetcode.com/problems/count-special-triplets/)

## Problem

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

- 0 <= i < j < k < n, where n = nums.length
- nums[i] == nums[j] * 2
- nums[k] == nums[j] * 2

Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.

### Example 1

### Example 2

### Example 3

## Constraints

- 3 <= n == nums.length <= 105
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3583. Count Special Triplets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumeration + Counting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Enumeration + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Enumeration + Counting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int specialTriplets(int* nums, int numsSize) {
    HashItem* numCnt = NULL;
    HashItem* numPartialCnt = NULL;

    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        hashSetItem(&numCnt, v, hashGetItem(&numCnt, v, 0) + 1);
    }

    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        int target = v * 2;
        int lCnt = hashGetItem(&numPartialCnt, target, 0);
        hashSetItem(&numPartialCnt, v, hashGetItem(&numPartialCnt, v, 0) + 1);
        int rCnt = hashGetItem(&numCnt, target, 0) -
                   hashGetItem(&numPartialCnt, target, 0);
        ans = (ans + (long long)lCnt * rCnt) % MOD;
    }

    hashFree(&numCnt);
    hashFree(&numPartialCnt);
    return (int)ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int v : nums) {
            numCnt[v]++;
        }

        int ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[v]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SpecialTriplets(int[] nums) {
        const int MOD = 1000000007;
        Dictionary<int, int> numCnt = new Dictionary<int, int>();
        Dictionary<int, int> numPartialCnt = new Dictionary<int, int>();

        foreach (int v in nums) {
            if (numCnt.ContainsKey(v)) {
                numCnt[v]++;
            } else {
                numCnt[v] = 1;
            }
        }

        long ans = 0;
        foreach (int v in nums) {
            int target = v * 2;
            int lCnt =
                numPartialCnt.ContainsKey(target) ? numPartialCnt[target] : 0;
            if (numPartialCnt.ContainsKey(v)) {
                numPartialCnt[v]++;
            } else {
                numPartialCnt[v] = 1;
            }

            int totalCnt = numCnt.ContainsKey(target) ? numCnt[target] : 0;
            int partialCnt =
                numPartialCnt.ContainsKey(target) ? numPartialCnt[target] : 0;
            int rCnt = totalCnt - partialCnt;

            ans = (ans + (long)lCnt * rCnt) % MOD;
        }

        return (int)ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func specialTriplets(nums []int) int {
	const MOD = 1000000007
	numCnt := make(map[int]int)
	numPartialCnt := make(map[int]int)

	for _, v := range nums {
		numCnt[v]++
	}

	ans := 0
	for _, v := range nums {
		target := v * 2
		lCnt := numPartialCnt[target]
		numPartialCnt[v]++
		rCnt := numCnt[target] - numPartialCnt[target]

		ans = (ans + lCnt*rCnt) % MOD
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int specialTriplets(int[] nums) {
        final int MOD = 1000000007;
        Map<Integer, Integer> numCnt = new HashMap<>();
        Map<Integer, Integer> numPartialCnt = new HashMap<>();

        for (int v : nums) {
            numCnt.put(v, numCnt.getOrDefault(v, 0) + 1);
        }

        long ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt.getOrDefault(target, 0);
            numPartialCnt.put(v, numPartialCnt.getOrDefault(v, 0) + 1);
            int rCnt =
                numCnt.getOrDefault(target, 0) -
                numPartialCnt.getOrDefault(target, 0);
            ans = (ans + (long) lCnt * rCnt) % MOD;
        }

        return (int) ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1e9 + 7;

var specialTriplets = function (nums) {
    const numCnt = new Map();
    const numPartialCnt = new Map();

    for (const v of nums) {
        numCnt.set(v, (numCnt.get(v) ?? 0) + 1);
    }

    let ans = 0;
    for (const v of nums) {
        const target = v * 2;
        const lCnt = numPartialCnt.get(target) ?? 0;

        numPartialCnt.set(v, (numPartialCnt.get(v) ?? 0) + 1);
        const rCnt =
            (numCnt.get(target) ?? 0) - (numPartialCnt.get(target) ?? 0);

        ans += (lCnt * rCnt) % MOD;
        ans %= MOD;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        num_cnt = {}
        num_partial_cnt = {}

        for v in nums:
            num_cnt[v] = num_cnt.get(v, 0) + 1

        ans = 0
        for v in nums:
            target = v * 2
            l_cnt = num_partial_cnt.get(target, 0)
            num_partial_cnt[v] = num_partial_cnt.get(v, 0) + 1
            r_cnt = num_cnt.get(target, 0) - num_partial_cnt.get(target, 0)
            ans = (ans + l_cnt * r_cnt) % MOD

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1e9 + 7;

function specialTriplets(nums: number[]): number {
    const numCnt = new Map<number, number>();
    const numPartialCnt = new Map<number, number>();

    for (const v of nums) {
        numCnt.set(v, (numCnt.get(v) ?? 0) + 1);
    }

    let ans = 0;
    for (const v of nums) {
        const target = v * 2;
        const lCnt = numPartialCnt.get(target) ?? 0;

        numPartialCnt.set(v, (numPartialCnt.get(v) ?? 0) + 1);
        const rCnt =
            (numCnt.get(target) ?? 0) - (numPartialCnt.get(target) ?? 0);

        ans += (lCnt * rCnt) % MOD;
        ans %= MOD;
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Enumeration + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

typedef struct {
    int key;
    int* indices;
    int size;
    int capacity;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int index) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (pEntry) {
        if (pEntry->size >= pEntry->capacity) {
            pEntry->capacity *= 2;
            pEntry->indices =
                realloc(pEntry->indices, pEntry->capacity * sizeof(int));
        }
        pEntry->indices[pEntry->size++] = index;
    } else {
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->capacity = 32;
        pEntry->size = 1;
        pEntry->indices = malloc(pEntry->capacity * sizeof(int));
        pEntry->indices[0] = index;
        HASH_ADD_INT(*obj, key, pEntry);
    }

    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->indices);
        free(curr);
    }
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int specialTriplets(int* nums, int numsSize) {
    HashItem* pos = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashAddItem(&pos, nums[i], i);
    }

    int ans = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        int target = nums[i] * 2;
        HashItem* pEntry = hashFindItem(&pos, target);
        if (pEntry == NULL || pEntry->size <= 1) {
            continue;
        }

        int* targetPos = pEntry->indices;
        int arrSize = pEntry->size;
        if (targetPos[0] >= i) {
            continue;
        }

        int split = upperBound(targetPos, arrSize, i);
        int l = split;
        int r = arrSize - split;
        if (nums[i] == 0) {
            l--;
        }
        if (l > 0 && r > 0) {
            ans = (int)((ans + (long long)l * r) % MOD);
        }
    }

    hashFree(&pos);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, vector<int>> pos;
        pos.reserve(nums.size() * 2);

        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;

        for (int i = 1; i < nums.size() - 1; i++) {
            int target = nums[i] * 2LL;
            if (pos.count(target) == 0) {
                continue;
            }

            const auto& arr = pos[target];
            if (arr.size() <= 1 || arr[0] >= i) {
                continue;
            }

            auto split = upper_bound(arr.begin(), arr.end(), i);
            int l = split - arr.begin();
            int r = arr.size() - l;

            if (nums[i] == 0) {
                l--;
            }
            ans = (ans + l * 1LL * r % MOD) % MOD;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System;
using System.Collections.Generic;

public class Solution {
    private const int MOD = 1000000007;

    public int SpecialTriplets(int[] nums) {
        Dictionary<int, List<int>> pos = new Dictionary<int, List<int>>();

        for (int i = 0; i < nums.Length; i++) {
            int v = nums[i];
            if (!pos.ContainsKey(v)) {
                pos[v] = new List<int>();
            }
            pos[v].Add(i);
        }

        int ans = 0;
        for (int i = 1; i < nums.Length - 1; i++) {
            int target = nums[i] * 2;
            if (pos.ContainsKey(target) && pos[target].Count > 1 &&
                pos[target][0] < i) {
                var (l, r) = UpperBound(pos[target], i);
                int leftCount = l;
                int rightCount = r;
                if (nums[i] == 0) {
                    leftCount--;
                }
                ans = (int)((ans + (long)leftCount * rightCount) % MOD);
            }
        }
        return ans;
    }

    private (int, int) UpperBound(List<int> arr, int i) {
        int l = 0, r = arr.Count - 1;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);
            if (i >= arr[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (l + 1, arr.Count - 1 - l);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func specialTriplets(nums []int) int {
    const MOD = 1000000007
    pos := make(map[int][]int)
    
    for i, v := range nums {
        pos[v] = append(pos[v], i)
    }
    
    ans := 0
    for i := 1; i < len(nums)-1; i++ {
        target := nums[i] * 2
        if targetPos, exists := pos[target]; exists && len(targetPos) > 1 && targetPos[0] < i {
            l, r := upperBound(targetPos, i)
            if nums[i] == 0 {
                l--
            }
            ans = (ans + l * r) % MOD
        }
    }
    return ans
}

func upperBound(arr []int, i int) (int, int) {
    l, r := 0, len(arr)-1
    for l < r {
        mid := l + ((r - l + 1) >> 1)
        if i >= arr[mid] {
            l = mid
        } else {
            r = mid - 1
        }
    }
    return l + 1, len(arr) - 1 - l
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int specialTriplets(int[] nums) {
        Map<Integer, List<Integer>> pos = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int v = nums[i];
            pos.computeIfAbsent(v, k -> new ArrayList<>()).add(i);
        }

        int ans = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            int target = nums[i] * 2;
            List<Integer> targetPos = pos.get(target);
            if (
                targetPos != null &&
                targetPos.size() > 1 &&
                targetPos.get(0) < i
            ) {
                int[] lr = upperBound(targetPos, i);
                int l = lr[0];
                int r = lr[1];
                if (nums[i] == 0) {
                    l--;
                }
                ans = (int) ((ans + (long) l * r) % MOD);
            }
        }
        return ans;
    }

    private int[] upperBound(List<Integer> arr, int i) {
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);
            if (i >= arr.get(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return new int[] { l + 1, arr.size() - 1 - l };
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1e9 + 7;

var specialTriplets = function (nums) {
    const pos = new Map();

    for (let i = 0; i < nums.length; i++) {
        const v = nums[i];
        if (pos.has(v)) {
            pos.get(v).push(i);
        } else {
            pos.set(v, [i]);
        }
    }

    const upperBound = (arr, i) => {
        let l = 0,
            r = arr.length - 1;

        while (l < r) {
            const mid = l + ((r - l + 1) >> 1);
            if (i >= arr[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return [l + 1, arr.length - 1 - l];
    };

    let ans = 0;
    for (let i = 1; i < nums.length - 1; i++) {
        const targetPos = pos.get(nums[i] * 2);
        if (targetPos && targetPos.length > 1 && targetPos[0] < i) {
            let [l, r] = upperBound(targetPos, i);
            if (nums[i] === 0) {
                l--;
            }
            ans += (l * r) % MOD;
            ans %= MOD;
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        pos = defaultdict(list)

        for i, v in enumerate(nums):
            pos[v].append(i)

        def upper_bound(arr, i):
            l, r = 0, len(arr) - 1
            while l < r:
                mid = l + ((r - l + 1) >> 1)
                if i >= arr[mid]:
                    l = mid
                else:
                    r = mid - 1
            return l + 1, len(arr) - 1 - l

        ans = 0
        for i in range(1, len(nums) - 1):
            target = nums[i] * 2
            if target in pos and len(pos[target]) > 1 and pos[target][0] < i:
                l, r = upper_bound(pos[target], i)
                if nums[i] == 0:
                    l -= 1
                ans = (ans + l * r) % MOD

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1e9 + 7;

function specialTriplets(nums: number[]): number {
    const pos = new Map<number, number[]>();

    for (let i = 0; i < nums.length; i++) {
        const v = nums[i];
        if (pos.has(v)) {
            pos.get(v)!.push(i);
        } else {
            pos.set(v, [i]);
        }
    }

    const upperBound = (arr: number[], i: number) => {
        let l = 0,
            r = arr.length - 1;

        while (l < r) {
            const mid = l + ((r - l + 1) >> 1);
            if (i >= arr[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return [l + 1, arr.length - 1 - l];
    };

    let ans = 0;
    for (let i = 1; i < nums.length - 1; i++) {
        const targetPos = pos.get(nums[i] * 2);
        if (targetPos && targetPos.length > 1 && targetPos[0] < i) {
            let [l, r] = upperBound(targetPos, i);
            if (nums[i] === 0) {
                l--;
            }
            ans += (l * r) % MOD;
            ans %= MOD;
        }
    }
    return ans;
}
```

</details>
