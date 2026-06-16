# 3151. Special Array I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/special-array-i/)  
`Array`

**Problem Link:** [LeetCode 3151 - Special Array I](https://leetcode.com/problems/special-array-i/)

## Problem

An array is considered special if the parity of every pair of adjacent elements is different. In other words, one element in each pair must be even, and the other must be odd.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3151. Special Array I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Modulo Comparisons | C++, Java, Python3 |
| Bitwise Operations | C++, Java, Python3 |

## Approach 1: Modulo Comparisons

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.size() - 1; index++) {
            // Compare the parities of the current and next number
            if (nums[index] % 2 == nums[index + 1] % 2) {
                // If the two adjacent numbers have the same parity, return
                // false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are
        // found
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isArraySpecial(int[] nums) {
        // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.length - 1; index++) {
            // Compare the parities of the current and next number
            if (nums[index] % 2 == nums[index + 1] % 2) {
                // If the two adjacent numbers have the same parity, return false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are found
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isArraySpecial(self, nums):
        # Iterate through indexes 0 to n - 1
        for index in range(len(nums) - 1):

            # Compare the parities of the current and next number
            if nums[index] % 2 == nums[index + 1] % 2:

                # If the two adjacent numbers have the same parity, return False
                return False

        # Return True if no pair of adjacent numbers with the same parity are found
        return True
```

</details>

<br>

## Approach 2: Bitwise Operations

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.size() - 1; index++) {
            // Compare the parities of the current and next number
            if ((nums[index] & 1) ^ (nums[index + 1] & 1) == 0) {
                // If the two adjacent numbers have the same parity, return
                // false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are
        // found
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isArraySpecial(int[] nums) {
        // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.length - 1; index++) {
            // Compare the parities using bitwise operations
            if (((nums[index] & 1) ^ (nums[index + 1] & 1)) == 0) {
                // If the two adjacent numbers have the same parity, return false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are found
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isArraySpecial(self, nums):
        # Iterate through indexes 0 to n - 1
        for index in range(len(nums) - 1):

            # Compare the parities using bitwise operations
            if ((nums[index] & 1) ^ (nums[index + 1] & 1)) == 0:

                # If the two adjacent numbers have the same parity, return False
                return False

        # Return True if no pair of adjacent numbers with the same parity are found
        return True
```

</details>
