# 396. Rotate Function

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/rotate-function/)  
`Array` `Math` `Dynamic Programming`

**Problem Link:** [LeetCode 396 - Rotate Function](https://leetcode.com/problems/rotate-function/)

## Problem

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

- F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].

Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

### Example 1

```text
Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
```

### Example 2

```text
Input: nums = [100]
Output: 0
```

## Constraints

- n == nums.length
- 1 <= n <= 105
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 396. Rotate Function

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxRotateFunction(int* nums, int numsSize) {
    int f = 0, numSum = 0;
    for (int i = 0; i < numsSize; i++) {
        f += i * nums[i];
        numSum += nums[i];
    }
    int res = f;
    for (int i = numsSize - 1; i > 0; i--) {
        f += numSum - numsSize * nums[i];
        res = MAX(res, f);
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = max(res, f);
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
    public int MaxRotateFunction(int[] nums) {
        int f = 0, n = nums.Length, numSum = nums.Sum();
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = Math.Max(res, f);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxRotateFunction(nums []int) int {
	numSum := 0
	for _, v := range nums {
		numSum += v
	}
	f := 0
	for i, num := range nums {
		f += i * num
	}
	ans := f
	for i := len(nums) - 1; i > 0; i-- {
		f += numSum - len(nums)*nums[i]
		ans = max(ans, f)
	}
	return ans
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxRotateFunction(int[] nums) {
        int f = 0;
        int n = nums.length;
        int numSum = Arrays.stream(nums).sum();
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = Math.max(res, f);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxRotateFunction = function (nums) {
    let f = 0,
        n = nums.length,
        numSum = _.sum(nums);
    for (let i = 0; i < n; i++) {
        f += i * nums[i];
    }
    let res = f;
    for (let i = n - 1; i > 0; i--) {
        f += numSum - n * nums[i];
        res = Math.max(res, f);
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f, n, numSum = 0, len(nums), sum(nums)
        for i, num in enumerate(nums):
            f += i * num
        res = f
        for i in range(n - 1, 0, -1):
            f = f + numSum - n * nums[i]
            res = max(res, f)
        return res
```

</details>
