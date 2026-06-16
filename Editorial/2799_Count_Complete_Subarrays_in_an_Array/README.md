# 2799. Count Complete Subarrays in an Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-complete-subarrays-in-an-array/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 2799 - Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/)

## Problem

You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

- The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.

Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

### Example 1

```text
Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
```

### Example 2

```text
Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2799. Count Complete Subarrays in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sliding Window

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

void hashEraseItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    HASH_DEL(*obj, pEntry);
    free(pEntry);
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countCompleteSubarrays(int *nums, int numsSize) {
    int res = 0;
    HashItem *cnt = NULL;
    int n = numsSize;
    int right = 0;
    HashItem *distinct = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashAddItem(&distinct, nums[i], 1);
    }
    int distinct_count = HASH_COUNT(distinct);

    for (int left = 0; left < n; left++) {
        if (left > 0) {
            int remove = nums[left - 1];
            hashSetItem(&cnt, remove, hashGetItem(&cnt, remove, 0) - 1);
            if (hashGetItem(&cnt, remove, 0) == 0) {
                hashEraseItem(&cnt, remove);
            }
        }
        while (right < n && HASH_COUNT(cnt) < distinct_count) {
            int add = nums[right];
            hashSetItem(&cnt, add, hashGetItem(&cnt, add, 0) + 1);
            right++;
        }
        if (HASH_COUNT(cnt) == distinct_count) {
            res += (n - right + 1);
        }
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
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_count) {
                res += (n - right + 1);
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
    public int CountCompleteSubarrays(int[] nums) {
        int res = 0;
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        int n = nums.Length;
        int right = 0;
        int distinct = new HashSet<int>(nums).Count;

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.Remove(remove);
                }
            }
            while (right < n && cnt.Count < distinct) {
                int add = nums[right];
                if (!cnt.ContainsKey(add)) {
                    cnt[add] = 0;
                }
                cnt[add]++;
                right++;
            }
            if (cnt.Count == distinct) {
                res += (n - right + 1);
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
func countCompleteSubarrays(nums []int) int {
	res := 0
	cnt := make(map[int]int)
	n := len(nums)
	right := 0
	distinct := make(map[int]bool)
	for _, num := range nums {
		distinct[num] = true
	}
	distinctCount := len(distinct)
	for left := 0; left < n; left++ {
		if left > 0 {
			remove := nums[left-1]
			cnt[remove]--
			if cnt[remove] == 0 {
				delete(cnt, remove)
			}
		}
		for right < n && len(cnt) < distinctCount {
			add := nums[right]
			cnt[add]++
			right++
		}
		if len(cnt) == distinctCount {
			res += (n - right + 1)
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

    public int countCompleteSubarrays(int[] nums) {
        int res = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = nums.length;
        int right = 0;
        int distinct = new HashSet<>(
            Arrays.asList(Arrays.stream(nums).boxed().toArray(Integer[]::new))
        ).size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt.put(remove, cnt.get(remove) - 1);
                if (cnt.get(remove) == 0) {
                    cnt.remove(remove);
                }
            }
            while (right < n && cnt.size() < distinct) {
                int add = nums[right];
                cnt.put(add, cnt.getOrDefault(add, 0) + 1);
                right++;
            }
            if (cnt.size() == distinct) {
                res += (n - right + 1);
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
var countCompleteSubarrays = function (nums) {
    let res = 0;
    let cnt = new Map();
    const n = nums.length;
    let right = 0;
    const distinct = new Set(nums).size;

    for (let left = 0; left < n; left++) {
        if (left > 0) {
            const remove = nums[left - 1];
            cnt.set(remove, cnt.get(remove) - 1);
            if (cnt.get(remove) === 0) {
                cnt.delete(remove);
            }
        }
        while (right < n && cnt.size < distinct) {
            const add = nums[right];
            cnt.set(add, (cnt.get(add) || 0) + 1);
            right++;
        }
        if (cnt.size === distinct) {
            res += n - right + 1;
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
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        res = 0
        cnt = {}
        n = len(nums)
        right = 0
        distinct = len(set(nums))
        for left in range(n):
            if left > 0:
                remove = nums[left - 1]
                cnt[remove] -= 1
                if cnt[remove] == 0:
                    cnt.pop(remove)
            while right < n and len(cnt) < distinct:
                add = nums[right]
                cnt[add] = cnt.get(add, 0) + 1
                right += 1
            if len(cnt) == distinct:
                res += n - right + 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countCompleteSubarrays(nums: number[]): number {
    let res = 0;
    let cnt = new Map<number, number>();
    const n = nums.length;
    let right = 0;
    const distinct = new Set(nums).size;

    for (let left = 0; left < n; left++) {
        if (left > 0) {
            const remove = nums[left - 1];
            cnt.set(remove, cnt.get(remove)! - 1);
            if (cnt.get(remove) === 0) {
                cnt.delete(remove);
            }
        }
        while (right < n && cnt.size < distinct) {
            const add = nums[right];
            cnt.set(add, (cnt.get(add) || 0) + 1);
            right++;
        }
        if (cnt.size === distinct) {
            res += n - right + 1;
        }
    }
    return res;
}
```

</details>
