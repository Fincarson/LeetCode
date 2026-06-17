# 918. Maximum Sum Circular Subarray

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-sum-circular-subarray/)  
`Array` `Divide and Conquer` `Dynamic Programming` `Queue` `Monotonic Queue`

**Problem Link:** [LeetCode 918 - Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

## Problem

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

### Example 1

```text
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
```

### Example 2

```text
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
```

### Example 3

```text
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
```

## Constraints

- n == nums.length
- 1 <= n <= 3 * 104
- -3 * 104 <= nums[i] <= 3 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 918. Maximum Sum Circular Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Enumerate prefix and suffix sums | C++, Java |
| Calculate the "Minimum Subarray" | C++, Java |

## Approach 1: Enumerate prefix and suffix sums

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// This is the solution to Maximum Subarray, which is the maximum "normal sum"
// The algorithm is known as Kadane's algorithm

int maxSubArray(vector<int>& nums) {
    int currMax = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int num = nums[i];
        currMax = max(num, currMax + num);
        maxSum = max(maxSum, currMax);
    }

    return maxSum;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// This is the solution to Maximum Subarray, which is the maximum "normal sum"
// The algorithm is known as Kadane's algorithm
public int maxSubArray(int[] nums) {
    int currMax = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.length; i++) {
        int num = nums[i];
        currMax = Math.max(num, currMax + num);
        maxSum = Math.max(maxSum, currMax);
    }
    
    return maxSum;
}
```

</details>

<br>

## Approach 2: Calculate the "Minimum Subarray"

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = 0;
        
        for (int num: nums) {
            // Normal Kadane's
            curMax = max(curMax, 0) + num;
            maxSum = max(maxSum, curMax);
            
            // Kadane's but with min to find minimum subarray
            curMin = min(curMin, 0) + num;
            minSum = min(minSum, curMin);
            
            totalSum += num;  
        }

        if (totalSum == minSum) {
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int curMax = 0;
        int curMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = 0;
        
        for (int num: nums) {
            // Normal Kadane's
            curMax = Math.max(curMax, 0) + num;
            maxSum = Math.max(maxSum, curMax);
            
            // Kadane's but with min to find minimum subarray
            curMin = Math.min(curMin, 0) + num;
            minSum = Math.min(minSum, curMin);
            
            totalSum += num;  
        }

        if (totalSum == minSum) {
            return maxSum;
        }
        
        return Math.max(maxSum, totalSum - minSum);
    }
}
```

</details>
