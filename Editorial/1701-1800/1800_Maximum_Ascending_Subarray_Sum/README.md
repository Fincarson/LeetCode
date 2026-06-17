# 1800. Maximum Ascending Subarray Sum

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-ascending-subarray-sum/)  
`Array`

**Problem Link:** [LeetCode 1800 - Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/)

## Problem

Given an array of positive integers nums, return the maximum possible sum of an strictly increasing subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

### Example 1

```text
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
```

### Example 2

```text
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
```

### Example 3

```text
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Number of Books You Can Take](https://leetcode.com/problems/maximum-number-of-books-you-can-take/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Strictly Increasing Subarrays](https://leetcode.com/problems/count-strictly-increasing-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1800. Maximum Ascending Subarray Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-Force | C++, Java, Python3 |
| Linear Scan | C++, Java, Python3 |

## Approach 1: Brute-Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        // Outer loop to start from each element in the array
        for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
            int currentSubarraySum = nums[startIdx];

            // Inner loop to check the next elements forming an ascending
            // subarray
            for (int endIdx = startIdx + 1;
                 endIdx < nums.size() && nums[endIdx] > nums[endIdx - 1];
                 endIdx++) {
                currentSubarraySum += nums[endIdx];
            }

            // Update maxSum if we find a larger ascending subarray sum
            maxSum = max(maxSum, currentSubarraySum);
        }

        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxAscendingSum(int[] nums) {
        int maxSum = 0;

        // Outer loop to start from each element in the array
        for (int startIdx = 0; startIdx < nums.length; startIdx++) {
            int currentSubarraySum = nums[startIdx];

            // Inner loop to check the next elements forming an ascending subarray
            for (
                int endIdx = startIdx + 1;
                endIdx < nums.length && nums[endIdx] > nums[endIdx - 1];
                endIdx++
            ) {
                currentSubarraySum += nums[endIdx];
            }

            // Update maxSum if we find a larger ascending subarray sum
            maxSum = Math.max(maxSum, currentSubarraySum);
        }

        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAscendingSum(self, nums):
        max_sum = 0

        # Outer loop to start from each element in the array
        for start_idx in range(len(nums)):
            current_subarray_sum = nums[start_idx]

            # Inner loop to check the next elements forming an ascending subarray
            end_idx = start_idx + 1
            while end_idx < len(nums) and nums[end_idx] > nums[end_idx - 1]:
                current_subarray_sum += nums[end_idx]
                end_idx += 1

            # Update max_sum if we find a larger ascending subarray sum
            max_sum = max(max_sum, current_subarray_sum)

        return max_sum
```

</details>

<br>

## Approach 2: Linear Scan

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSubarraySum = nums[0];

        // Loop through the array starting from the second element
        for (int currentIdx = 1; currentIdx < nums.size(); ++currentIdx) {
            if (nums[currentIdx] <= nums[currentIdx - 1]) {
                // If the current element is not greater than the previous one,
                // update maxSum
                maxSum = max(maxSum, currentSubarraySum);
                // Reset the sum for the next ascending subarray
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[currentIdx];
        }

        // Final check after the loop ends to account for the last ascending
        // subarray
        return max(maxSum, currentSubarraySum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxAscendingSum(int[] nums) {
        int maxSum = 0;
        int currentSubarraySum = nums[0];

        // Loop through the array starting from the second element
        for (int currentIdx = 1; currentIdx < nums.length; ++currentIdx) {
            if (nums[currentIdx] <= nums[currentIdx - 1]) {
                // If the current element is not greater than the previous one,
                // update maxSum
                maxSum = Math.max(maxSum, currentSubarraySum);
                // Reset the sum for the next ascending subarray
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[currentIdx];
        }

        // Final check after the loop ends to account for the last ascending
        // subarray
        return Math.max(maxSum, currentSubarraySum);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        maxSum = 0
        currentSubarraySum = nums[0]

        # Loop through the list starting from the second element
        for currentIdx in range(1, len(nums)):
            if nums[currentIdx] <= nums[currentIdx - 1]:
                # If the current element is not greater than the previous one,
                # update maxSum
                maxSum = max(maxSum, currentSubarraySum)
                # Reset the sum for the next ascending subarray
                currentSubarraySum = 0
            currentSubarraySum += nums[currentIdx]

        # Final check after the loop ends to account for the last ascending
        # subarray
        return max(maxSum, currentSubarraySum)
```

</details>
