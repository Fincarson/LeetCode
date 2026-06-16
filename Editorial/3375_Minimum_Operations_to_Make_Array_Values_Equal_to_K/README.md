# 3375. Minimum Operations to Make Array Values Equal to K

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 3375 - Minimum Operations to Make Array Values Equal to K](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/)

## Problem

You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

- Select an integer h that is valid for the current values in nums.
- For each index i where nums[i] > h, set nums[i] to h.

Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100
- 1 <= k <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3375. Minimum Operations to Make Array Values Equal to K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash map | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash map

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}
int minOperations(int *nums, int numsSize, int k) {
    HashItem *st = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            return -1;
        } else if (nums[i] > k) {
            hashAddItem(&st, nums[i]);
        }
    }
    int ret = HASH_COUNT(st);
    hashFree(&st);
    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.insert(x);
            }
        }
        return st.size();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinOperations(int[] nums, int k) {
        HashSet<int> st = new HashSet<int>();
        foreach (int x in nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.Add(x);
            }
        }
        return st.Count;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minOperations(nums []int, k int) int {
	st := make(map[int]bool)
	for _, x := range nums {
		if x < k {
			return -1
		} else if x > k {
			st[x] = true
		}
	}
	return len(st)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minOperations(int[] nums, int k) {
        Set<Integer> st = new HashSet<>();
        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.add(x);
            }
        }
        return st.size();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minOperations = function (nums, k) {
    const st = new Set();
    for (const x of nums) {
        if (x < k) {
            return -1;
        } else if (x > k) {
            st.add(x);
        }
    }
    return st.size;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        st = set()
        for x in nums:
            if x < k:
                return -1
            elif x > k:
                st.add(x)
        return len(st)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minOperations(nums: number[], k: number): number {
    const st = new Set<number>();
    for (const x of nums) {
        if (x < k) {
            return -1;
        } else if (x > k) {
            st.add(x);
        }
    }
    return st.size;
}
```

</details>
