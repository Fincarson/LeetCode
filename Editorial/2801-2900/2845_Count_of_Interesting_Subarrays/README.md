# 2845. Count of Interesting Subarrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-of-interesting-subarrays/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 2845 - Count of Interesting Subarrays](https://leetcode.com/problems/count-of-interesting-subarrays/)

## Problem

You are given a 0-indexed integer array nums, an integer modulo, and an integer k.

Your task is to find the count of subarrays that are interesting.

A subarray nums[l..r] is interesting if the following condition holds:

- Let cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k.

Return an integer denoting the count of interesting subarrays.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [3,2,4], modulo = 2, k = 1
Output: 3
Explanation: In this example the interesting subarrays are:
The subarray nums[0..0] which is [3].
- There is only one index, i = 0, in the range [0, 0] that satisfies nums[i] % modulo == k.
- Hence, cnt = 1 and cnt % modulo == k.
The subarray nums[0..1] which is [3,2].
- There is only one index, i = 0, in the range [0, 1] that satisfies nums[i] % modulo == k.
- Hence, cnt = 1 and cnt % modulo == k.
The subarray nums[0..2] which is [3,2,4].
- There is only one index, i = 0, in the range [0, 2] that satisfies nums[i] % modulo == k.
- Hence, cnt = 1 and cnt % modulo == k.
It can be shown that there are no other interesting subarrays. So, the answer is 3.
```

### Example 2

```text
Input: nums = [3,1,9,6], modulo = 3, k = 0
Output: 2
Explanation: In this example the interesting subarrays are:
The subarray nums[0..3] which is [3,1,9,6].
- There are three indices, i = 0, 2, 3, in the range [0, 3] that satisfy nums[i] % modulo == k.
- Hence, cnt = 3 and cnt % modulo == k.
The subarray nums[1..1] which is [1].
- There is no index, i, in the range [1, 1] that satisfies nums[i] % modulo == k.
- Hence, cnt = 0 and cnt % modulo == k.
It can be shown that there are no other interesting subarrays. So, the answer is 2.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= modulo <= 109
- 0 <= k < modulo

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2845. Count of Interesting Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

long long countInterestingSubarrays(int *nums, int numsSize, int modulo,
                                    int k) {
    HashItem *cnt = NULL;
    long long res = 0;
    int prefix = 0;
    hashAddItem(&cnt, 0, 1);
    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i] % modulo == k;
        res += hashGetItem(&cnt, (prefix - k + modulo) % modulo, 0);
        hashSetItem(&cnt, prefix % modulo,
                    hashGetItem(&cnt, prefix % modulo, 0) + 1);
    }
    hashFree(&cnt);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
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
    public long CountInterestingSubarrays(IList<int> nums, int modulo, int k) {
        int n = nums.Count;
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k ? 1 : 0;
            res += cnt.ContainsKey((prefix - k + modulo) % modulo)
                       ? cnt[(prefix - k + modulo) % modulo]
                       : 0;
            if (cnt.ContainsKey(prefix % modulo)) {
                cnt[prefix % modulo]++;
            } else {
                cnt[prefix % modulo] = 1;
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
func countInterestingSubarrays(nums []int, modulo int, k int) int64 {
	n := len(nums)
	cnt := make(map[int]int)
	var res int64 = 0
	var prefix int = 0
	cnt[0] = 1
	for i := 0; i < n; i++ {
		if nums[i]%modulo == k {
			prefix++
		}
		res += int64(cnt[(prefix-k+modulo)%modulo])
		cnt[prefix%modulo]++
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countInterestingSubarrays(
        List<Integer> nums,
        int modulo,
        int k
    ) {
        int n = nums.size();
        HashMap<Integer, Integer> cnt = new HashMap<>();
        long res = 0;
        int prefix = 0;
        cnt.put(0, 1);
        for (int i = 0; i < n; i++) {
            prefix += nums.get(i) % modulo == k ? 1 : 0;
            res += cnt.getOrDefault((prefix - k + modulo) % modulo, 0);
            cnt.put(prefix % modulo, cnt.getOrDefault(prefix % modulo, 0) + 1);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countInterestingSubarrays = function (nums, modulo, k) {
    let n = nums.length;
    let cnt = new Map();
    let res = 0;
    let prefix = 0;
    cnt.set(0, 1);
    for (let i = 0; i < n; i++) {
        prefix += nums[i] % modulo === k ? 1 : 0;
        res += cnt.get((prefix - k + modulo) % modulo) || 0;
        cnt.set(prefix % modulo, (cnt.get(prefix % modulo) || 0) + 1);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countInterestingSubarrays(
        self, nums: List[int], modulo: int, k: int
    ) -> int:
        n = len(nums)
        cnt = Counter([0])
        res = 0
        prefix = 0
        for i in range(n):
            prefix += 1 if nums[i] % modulo == k else 0
            res += cnt[(prefix - k + modulo) % modulo]
            cnt[prefix % modulo] += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countInterestingSubarrays(
    nums: number[],
    modulo: number,
    k: number,
): number {
    let n = nums.length;
    let cnt = new Map<number, number>();
    let res = 0;
    let prefix = 0;
    cnt.set(0, 1);
    for (let i = 0; i < n; i++) {
        prefix += nums[i] % modulo === k ? 1 : 0;
        res += cnt.get((prefix - k + modulo) % modulo) || 0;
        cnt.set(prefix % modulo, (cnt.get(prefix % modulo) || 0) + 1);
    }
    return res;
}
```

</details>
