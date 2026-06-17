# 152. Maximum Product Subarray

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-product-subarray/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 152 - Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)

## Problem

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

### Example 1

```text
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

### Example 2

```text
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```

## Constraints

- 1 <= nums.length <= 2 * 104
- -10 <= nums[i] <= 10
- The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 152. Maximum Product Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Python TLE) | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Brute Force (Python TLE)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.length; i++) {
            int accu = 1;
            for (int j = i; j < nums.length; j++) {
                accu *= nums[j];
                result = Math.max(result, accu);
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProduct(self, nums):
        if len(nums) == 0:
            return 0

        result = nums[0]

        for i in range(len(nums)):
            accu = 1
            for j in range(i, len(nums)):
                accu *= nums[j]
                result = max(result, accu)

        return result
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            // Update max_so_far after updates to min_so_far to avoid
            // overwriting it
            max_so_far = temp_max;
            // Update the result with the maximum product found so far
            result = max(max_so_far, result);
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.length; i++) {
            int curr = nums[i];
            int temp_max = Math.max(
                curr,
                Math.max(max_so_far * curr, min_so_far * curr)
            );
            min_so_far = Math.min(
                curr,
                Math.min(max_so_far * curr, min_so_far * curr)
            );

            // Update max_so_far after min_so_far to avoid overwriting it
            max_so_far = temp_max;
            // Update the result with the maximum product found so far
            result = Math.max(max_so_far, result);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProduct(self, nums):
        if len(nums) == 0:
            return 0

        max_so_far = nums[0]
        min_so_far = nums[0]
        result = max_so_far

        for i in range(1, len(nums)):
            curr = nums[i]
            temp_max = max(curr, max(max_so_far * curr, min_so_far * curr))
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr))

            # Update max_so_far after updates to min_so_far to avoid overwriting it
            max_so_far = temp_max
            # Update the result with the maximum product found so far
            result = max(max_so_far, result)

        return result
```

</details>
