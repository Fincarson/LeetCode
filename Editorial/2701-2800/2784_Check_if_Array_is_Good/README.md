# 2784. Check if Array is Good

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-array-is-good/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 2784 - Check if Array is Good](https://leetcode.com/problems/check-if-array-is-good/)

## Problem

You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.

### Example 1

```text
Input: nums = [2, 1, 3]
Output: false
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
```

### Example 2

```text
Input: nums = [1, 3, 3, 2]
Output: true
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3. It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]). Therefore, the answer is true.
```

### Example 3

```text
Input: nums = [1, 1]
Output: true
Explanation: Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1. It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
```

### Example 4

```text
Input: nums = [3, 4, 4, 1, 2, 1]
Output: false
Explanation: Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4. However, base[4] has five elements but array nums has six. Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= num[i] <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2784. Check if Array is Good

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Frequency Counting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool isGood(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int n = numsSize - 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return false;
        }
    }
    return nums[n] == n;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        return nums[n] == n;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsGood(int[] nums) {
        Array.Sort(nums);
        int n = nums.Length - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        return nums[n] == n;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isGood(nums []int) bool {
	sort.Ints(nums)
	n := len(nums) - 1
	for i := 0; i < n; i++ {
		if nums[i] != i+1 {
			return false
		}
	}
	return nums[n] == n
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isGood(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }
        return nums[n] == n;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isGood = function (nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length - 1;
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return false;
        }
    }
    return nums[n] === n;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        nums.sort()
        n = len(nums) - 1
        for i in range(n):
            if nums[i] != i + 1:
                return False
        return nums[n] == n
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isGood(nums: number[]): boolean {
    nums.sort((a, b) => a - b);
    const n = nums.length - 1;
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return false;
        }
    }
    return nums[n] === n;
}
```

</details>

<br>

## Approach 2: Frequency Counting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isGood(int* nums, int numsSize) {
    int n = numsSize;
    int* count = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (a < 1 || a >= n) {
            free(count);
            return false;
        }
        if (a < n - 1 && count[a] > 0) {
            free(count);
            return false;
        }
        if (a == n - 1 && count[a] > 1) {
            free(count);
            return false;
        }
        count[a]++;
    }
    free(count);
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for (int a : nums) {
            if (a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsGood(int[] nums) {
        int n = nums.Length;
        int[] count = new int[n];
        foreach (int a in nums) {
            if (a < 1 || a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isGood(nums []int) bool {
	n := len(nums)
	count := make([]int, n)
	for _, a := range nums {
		if a < 1 || a >= n {
			return false
		}
		if a < n-1 && count[a] > 0 {
			return false
		}
		if a == n-1 && count[a] > 1 {
			return false
		}
		count[a]++
	}
	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isGood(int[] nums) {
        int n = nums.length;
        int[] count = new int[n];
        for (int a : nums) {
            if (a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isGood = function (nums) {
    const n = nums.length;
    const count = new Array(n).fill(0);
    for (const a of nums) {
        if (a >= n) {
            return false;
        }
        if (a < n - 1 && count[a] > 0) {
            return false;
        }
        if (a === n - 1 && count[a] > 1) {
            return false;
        }
        count[a]++;
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        count = [0] * n
        for a in nums:
            if a >= n:
                return False
            if a < n - 1 and count[a] > 0:
                return False
            if a == n - 1 and count[a] > 1:
                return False
            count[a] += 1
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isGood(nums: number[]): boolean {
    const n = nums.length;
    const count = new Array(n).fill(0);
    for (const a of nums) {
        if (a >= n) {
            return false;
        }
        if (a < n - 1 && count[a] > 0) {
            return false;
        }
        if (a === n - 1 && count[a] > 1) {
            return false;
        }
        count[a]++;
    }
    return true;
}
```

</details>
