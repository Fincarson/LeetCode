# 2154. Keep Multiplying Found Values by Two

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)  
`Array` `Hash Table` `Sorting` `Simulation`

**Problem Link:** [LeetCode 2154 - Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)

## Problem

You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

Return the final value of original.

### Example 1

```text
Input: nums = [5,3,6,1,12], original = 3
Output: 24
Explanation:
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
```

### Example 2

```text
Input: nums = [2,7,9], original = 4
Output: 4
Explanation:
- 4 is not found in nums. Thus, 4 is returned.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i], original <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Number At Least Twice of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Check If N and Its Double Exist](https://leetcode.com/problems/check-if-n-and-its-double-exist/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2154. Keep Multiplying Found Values by Two

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int findFinalValue(int* nums, int numsSize, int original) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (original == nums[i]) {
            original *= 2;
        }
    }
    return original;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (original == num) {
                original *= 2;
            }
        }
        return original;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindFinalValue(int[] nums, int original) {
        Array.Sort(nums);
        foreach (int num in nums) {
            if (original == num) {
                original *= 2;
            }
        }
        return original;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findFinalValue(nums []int, original int) int {
	sort.Ints(nums)
	for _, num := range nums {
		if original == num {
			original *= 2
		}
	}
	return original
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findFinalValue(int[] nums, int original) {
        Arrays.sort(nums);
        for (int num : nums) {
            if (original == num) {
                original *= 2;
            }
        }
        return original;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findFinalValue = function (nums, original) {
    nums.sort((a, b) => a - b);
    for (const num of nums) {
        if (original === num) {
            original *= 2;
        }
    }
    return original;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        nums.sort()
        for num in nums:
            if num == original:
                original *= 2
        return original
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findFinalValue(nums: number[], original: number): number {
    nums.sort((a, b) => a - b);
    for (const num of nums) {
        if (original === num) {
            original *= 2;
        }
    }
    return original;
}
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int findFinalValue(int* nums, int numsSize, int original) {
    HashItem* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashAddItem(&set, nums[i]);
    }
    while (hashFindItem(&set, original)) {
        original *= 2;
    }
    hashFree(&set);
    return original;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }
        return original;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindFinalValue(int[] nums, int original) {
        HashSet<int> set = new HashSet<int>(nums);
        while (set.Contains(original)) {
            original *= 2;
        }
        return original;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findFinalValue(nums []int, original int) int {
	set := make(map[int]bool)
	for _, num := range nums {
		set[num] = true
	}
	for set[original] {
		original *= 2
	}
	return original
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findFinalValue(int[] nums, int original) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        while (set.contains(original)) {
            original *= 2;
        }
        return original;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findFinalValue = function (nums, original) {
    const set = new Set(nums);
    while (set.has(original)) {
        original *= 2;
    }
    return original;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        s = set(nums)
        while original in s:
            original *= 2
        return original
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findFinalValue(nums: number[], original: number): number {
    const set = new Set(nums);
    while (set.has(original)) {
        original *= 2;
    }
    return original;
}
```

</details>
