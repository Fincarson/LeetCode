# 1913. Maximum Product Difference Between Two Pairs

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)  
`Array` `Sorting`

**Problem Link:** [LeetCode 1913 - Maximum Product Difference Between Two Pairs](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)

## Problem

The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

- For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.

Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

### Example 1

```text
Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
```

### Example 2

```text
Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
```

## Constraints

- 4 <= nums.length <= 104
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1913. Maximum Product Difference Between Two Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | C++, Java, Python3 |
| Track the Two Biggest and the Two Smallest Elements | C++, Java, Python3 |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProductDifference(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length - 1] * nums[nums.length - 2] - nums[0] * nums[1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[-1] * nums[-2] - nums[0] * nums[1]
```

</details>

<br>

## Approach 2: Track the Two Biggest and the Two Smallest Elements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
            
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }
        
        return biggest * secondBiggest - smallest * secondSmallest;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProductDifference(int[] nums) {
        int biggest = 0;
        int secondBiggest = 0;
        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;
        
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = Math.max(secondBiggest, num);
            }
            
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = Math.min(secondSmallest, num);
            }
        }
        
        return biggest * secondBiggest - smallest * secondSmallest;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        biggest = 0
        second_biggest = 0
        smallest = inf
        second_smallest = inf
        
        for num in nums:
            if num > biggest:
                second_biggest = biggest
                biggest = num
            else:
                second_biggest = max(second_biggest, num)
                
            if num < smallest:
                second_smallest = smallest
                smallest = num
            else:
                second_smallest = min(second_smallest, num)
        
        return biggest * second_biggest - smallest * second_smallest
```

</details>
