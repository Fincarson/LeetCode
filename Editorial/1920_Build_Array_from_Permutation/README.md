# 1920. Build Array from Permutation

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/build-array-from-permutation/)  
`Array` `Simulation`

**Problem Link:** [LeetCode 1920 - Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/)

## Problem

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

### Example 1

```text
Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
```

### Example 2

```text
Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
```

## Constraints

- 1 <= nums.length <= 1000
- 0 <= nums[i] < nums.length
- The elements in nums are distinct.

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1920. Build Array from Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Build As Required | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Build In Place | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Build As Required

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = nums[nums[i]];
    }
    *returnSize = numsSize;
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[nums[i]]);
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
    public int[] BuildArray(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func buildArray(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	for i := 0; i < n; i++ {
		ans[i] = nums[nums[i]]
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] buildArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buildArray = function (nums) {
    const n = nums.length;
    const ans = [];
    for (let i = 0; i < n; ++i) {
        ans.push(nums[nums[i]]);
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        return [nums[nums[_]] for _ in range(n)]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function buildArray(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        ans.push(nums[nums[i]]);
    }
    return ans;
}
```

</details>

<br>

## Approach 2: Build In Place

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Build the final value on the first iteration
    for (int i = 0; i < numsSize; ++i) {
        nums[i] += 1000 * (nums[nums[i]] % 1000);
    }
    // Modified to final value on the second iteration
    for (int i = 0; i < numsSize; ++i) {
        nums[i] /= 1000;
    }
    *returnSize = numsSize;
    return nums;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[] BuildArray(int[] nums) {
        int n = nums.Length;
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func buildArray(nums []int) []int {
	n := len(nums)
	// Build the final value on the first iteration
	for i := 0; i < n; i++ {
		nums[i] += 1000 * (nums[nums[i]] % 1000)
	}
	// Modified to final value on the second iteration
	for i := 0; i < n; i++ {
		nums[i] /= 1000
	}
	return nums
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] buildArray(int[] nums) {
        int n = nums.length;
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buildArray = function (nums) {
    const n = nums.length;
    // Build the final value on the first iteration
    for (let i = 0; i < n; ++i) {
        nums[i] += 1000 * (nums[nums[i]] % 1000);
    }
    // Modified to final value on the second iteration
    for (let i = 0; i < n; ++i) {
        nums[i] = Math.floor(nums[i] / 1000);
    }
    return nums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        # Build the final value on the first iteration
        for i in range(n):
            nums[i] += 1000 * (nums[nums[i]] % 1000)
        # Modified to final value on the second iteration
        for i in range(n):
            nums[i] //= 1000
        return nums
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function buildArray(nums: number[]): number[] {
    const n = nums.length;
    // Build the final value on the first iteration
    for (let i = 0; i < n; ++i) {
        nums[i] += 1000 * (nums[nums[i]] % 1000);
    }
    // Modified to final value on the second iteration
    for (let i = 0; i < n; ++i) {
        nums[i] = Math.floor(nums[i] / 1000);
    }
    return nums;
}
```

</details>
