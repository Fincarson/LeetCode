# 2537. Count the Number of Good Subarrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-good-subarrays/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 2537 - Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/)

## Problem

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
```

### Example 2

```text
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i], k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2537. Count the Number of Good Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two pointers

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

long long countGood(int *nums, int numsSize, int k) {
    int n = numsSize;
    int same = 0, right = -1;
    HashItem *cnt = NULL;
    long long ans = 0;
    for (int left = 0; left < n; ++left) {
        while (same < k && right + 1 < n) {
            ++right;
            same += hashGetItem(&cnt, nums[right], 0);
            hashSetItem(&cnt, nums[right],
                        hashGetItem(&cnt, nums[right], 0) + 1);
        }
        if (same >= k) {
            ans += n - right;
        }
        hashSetItem(&cnt, nums[left], hashGetItem(&cnt, nums[left], 0) - 1);
        same -= hashGetItem(&cnt, nums[left], 0);
    }
    hashFree(&cnt);
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt[nums[right]];
                ++cnt[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --cnt[nums[left]];
            same -= cnt[nums[left]];
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
    public long CountGood(int[] nums, int k) {
        int n = nums.Length;
        int same = 0, right = -1;
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                cnt.TryGetValue(nums[right], out int current);
                same += current;
                cnt[nums[right]] = current + 1;
            }
            if (same >= k) {
                ans += n - right;
            }
            cnt[nums[left]] = cnt[nums[left]] - 1;
            same -= cnt[nums[left]];
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countGood(nums []int, k int) int64 {
	n := len(nums)
	same, right := 0, -1
	cnt := make(map[int]int)
	var ans int64 = 0
	for left := 0; left < n; left++ {
		for same < k && right+1 < n {
			right++
			same += cnt[nums[right]]
			cnt[nums[right]]++
		}
		if same >= k {
			ans += int64(n - right)
		}
		cnt[nums[left]]--
		same -= cnt[nums[left]]
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countGood(int[] nums, int k) {
        int n = nums.length;
        int same = 0, right = -1;
        HashMap<Integer, Integer> cnt = new HashMap<>();
        long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                same += cnt.getOrDefault(nums[right], 0);
                cnt.put(nums[right], cnt.getOrDefault(nums[right], 0) + 1);
            }
            if (same >= k) {
                ans += n - right;
            }
            cnt.put(nums[left], cnt.get(nums[left]) - 1);
            same -= cnt.get(nums[left]);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countGood = function (nums, k) {
    const n = nums.length;
    let same = 0,
        right = -1;
    const cnt = new Map();
    let ans = 0;
    for (let left = 0; left < n; ++left) {
        while (same < k && right + 1 < n) {
            ++right;
            same += cnt.get(nums[right]) || 0;
            cnt.set(nums[right], (cnt.get(nums[right]) || 0) + 1);
        }
        if (same >= k) {
            ans += n - right;
        }
        cnt.set(nums[left], cnt.get(nums[left]) - 1);
        same -= cnt.get(nums[left]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        same, right = 0, -1
        cnt = Counter()
        ans = 0
        for left in range(n):
            while same < k and right + 1 < n:
                right += 1
                same += cnt[nums[right]]
                cnt[nums[right]] += 1
            if same >= k:
                ans += n - right
            cnt[nums[left]] -= 1
            same -= cnt[nums[left]]
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countGood(nums: number[], k: number): number {
    const n = nums.length;
    let same = 0,
        right = -1;
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let left = 0; left < n; ++left) {
        while (same < k && right + 1 < n) {
            ++right;
            same += cnt.get(nums[right]) || 0;
            cnt.set(nums[right], (cnt.get(nums[right]) || 0) + 1);
        }
        if (same >= k) {
            ans += n - right;
        }
        cnt.set(nums[left], (cnt.get(nums[left]) || 0) - 1);
        same -= cnt.get(nums[left]) || 0;
    }
    return ans;
}
```

</details>
