# 3719. Longest Balanced Subarray I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-balanced-subarray-i/)  
`Array` `Hash Table` `Divide and Conquer` `Segment Tree` `Prefix Sum`

**Problem Link:** [LeetCode 3719 - Longest Balanced Subarray I](https://leetcode.com/problems/longest-balanced-subarray-i/)

## Problem

You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 1500
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3719. Longest Balanced Subarray I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
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

bool hashEraseItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (pEntry) {
        HASH_DEL(*obj, pEntry);
        free(pEntry);
        return true;
    }
    return false;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL;
    HashItem* tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
    *obj = NULL;
}

int hashSize(HashItem* obj) { return HASH_COUNT(obj); }

int longestBalanced(int* nums, int numsSize) {
    size_t len = 0;
    for (size_t i = 0; i < numsSize; i++) {
        HashItem* odd = NULL;
        HashItem* even = NULL;
        for (size_t j = i; j < numsSize; j++) {
            int count = hashGetItem(&odd, nums[j], 0);
            if ((nums[j] & 1) == 1) {
                hashSetItem(&odd, nums[j], count + 1);
            } else {
                hashSetItem(&even, nums[j], count + 1);
            }
            if (hashSize(odd) == hashSize(even)) {
                len = fmax(len, j - i + 1);
            }
        }
        hashFree(&odd);
        hashFree(&even);
    }

    return (int)len;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        size_t len = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            auto odd = unordered_map<int, int>();
            auto even = unordered_map<int, int>();

            for (size_t j = i; j < nums.size(); j++) {
                auto& c = (nums[j] & 1) ? odd : even;
                c[nums[j]]++;

                if (odd.size() == even.size()) {
                    len = std::max(len, j - i + 1);
                }
            }
        }

        return int(len);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestBalanced(int[] nums) {
        int len = 0;

        for (int i = 0; i < nums.Length; i++) {
            var odd = new Dictionary<int, int>();
            var even = new Dictionary<int, int>();

            for (int j = i; j < nums.Length; j++) {
                var dict = (nums[j] & 1) == 1 ? odd : even;
                dict[nums[j]] = dict.GetValueOrDefault(nums[j]) + 1;

                if (odd.Count == even.Count) {
                    len = Math.Max(len, j - i + 1);
                }
            }
        }

        return len;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestBalanced(nums []int) int {
	maxLen := 0

	for i := 0; i < len(nums); i++ {
		odd := make(map[int]int)
		even := make(map[int]int)

		for j := i; j < len(nums); j++ {
			if nums[j]&1 == 1 {
				odd[nums[j]]++
			} else {
				even[nums[j]]++
			}

			if len(odd) == len(even) {
				if j-i+1 > maxLen {
					maxLen = j - i + 1
				}
			}
		}
	}

	return maxLen
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestBalanced(int[] nums) {
        int len = 0;

        for (int i = 0; i < nums.length; i++) {
            HashMap<Integer, Integer> odd = new HashMap<>();
            HashMap<Integer, Integer> even = new HashMap<>();

            for (int j = i; j < nums.length; j++) {
                HashMap<Integer, Integer> map = (nums[j] & 1) == 1 ? odd : even;
                map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);

                if (odd.size() == even.size()) {
                    len = Math.max(len, j - i + 1);
                }
            }
        }

        return len;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestBalanced = function (nums) {
    let len = 0;

    for (let i = 0; i < nums.length; i++) {
        const odd = new Map();
        const even = new Map();

        for (let j = i; j < nums.length; j++) {
            const c = nums[j] & 1 ? odd : even;

            c.set(nums[j], (c.get(nums[j]) ?? 0) + 1);

            if (odd.size == even.size) {
                len = Math.max(len, j - i + 1);
            }
        }
    }

    return len;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        max_len = 0

        for i in range(len(nums)):
            odd = {}
            even = {}

            for j in range(i, len(nums)):
                if nums[j] & 1:
                    odd[nums[j]] = odd.get(nums[j], 0) + 1
                else:
                    even[nums[j]] = even.get(nums[j], 0) + 1

                if len(odd) == len(even):
                    max_len = max(max_len, j - i + 1)

        return max_len
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestBalanced(nums: number[]): number {
    let len = 0;

    for (let i = 0; i < nums.length; i++) {
        const odd = new Map<number, number>();
        const even = new Map<number, number>();

        for (let j = i; j < nums.length; j++) {
            const c = nums[j] & 1 ? odd : even;

            c.set(nums[j], (c.get(nums[j]) ?? 0) + 1);

            if (odd.size == even.size) {
                len = Math.max(len, j - i + 1);
            }
        }
    }

    return len;
}
```

</details>
