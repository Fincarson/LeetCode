# 1822. Sign of the Product of an Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sign-of-the-product-of-an-array/)  
`Array` `Math`

**Problem Link:** [LeetCode 1822 - Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)

## Problem

Implement a function signFunc(x) that returns:

- 1 if x is positive.
- -1 if x is negative.
- 0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

### Example 1

```text
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

### Example 2

```text
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```

### Example 3

```text
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

## Constraints

- 1 <= nums.length <= 1000
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

# Editorial - 1822. Sign of the Product of an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting Negative Numbers | C++, Java, Python |
| Tracking the Sign of the Product | C++, Java, Python |

## Approach 1: Counting Negative Numbers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNegativeNumbers = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                countNegativeNumbers++;
            }
        }

        return countNegativeNumbers % 2 == 0 ? 1 : -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int arraySign(int[] nums) {
        int countNegativeNumbers = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                countNegativeNumbers++;
            }
        }

        return countNegativeNumbers % 2 == 0 ? 1 : -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def arraySign(self, nums):
        countNegativeNumbers = 0
        for num in nums:
            if num == 0:
                return 0
            if num < 0:
                countNegativeNumbers = countNegativeNumbers + 1

        if countNegativeNumbers %2 == 0:
            return 1
        return -1
```

</details>

<br>

## Approach 2: Tracking the Sign of the Product

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                sign = -1 * sign;
            }
        }

        return sign;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int arraySign(int[] nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                sign = -1 * sign;
            }
        }

        return sign;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def arraySign(self, nums):
        sign = 1
        for num in nums:
            if num == 0:
                return 0
            if num < 0:
                sign = -1 * sign

        return sign
```

</details>
