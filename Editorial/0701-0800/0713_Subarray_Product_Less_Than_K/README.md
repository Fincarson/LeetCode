# 713. Subarray Product Less Than K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/subarray-product-less-than-k/)  
`Array` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 713 - Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

## Problem

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

### Example 1

```text
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
```

### Example 2

```text
Input: nums = [1,2,3], k = 0
Output: 0
```

## Constraints

- 1 <= nums.length <= 3 * 104
- 1 <= nums[i] <= 1000
- 0 <= k <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 713. Subarray Product Less Than K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Sliding Window | C++, Java, Python3 |
| Using Binary Search | C++, Java, Python3 |

## Approach 1: Using Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // Handle edge cases where k is 0 or 1 (no subarrays possible)
    if (k <= 1) return 0;

    int totalCount = 0;
    int product = 1;

    // Use two pointers to maintain a sliding window
    for (int left = 0, right = 0; right < nums.size(); right++) {
      // Expand the window by including the element at the right pointer
      product *= nums[right];

      // Shrink the window from the left while the product is greater than or equal to k
      while (product >= k) {
        // Remove the element at the left pointer from the product
        product /= nums[left++];
      }

      // Update the total count by adding the number of valid subarrays with the current window size
      totalCount += right - left + 1;  // right - left + 1 represents the current window size
    }

    return totalCount;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        // Handle edge cases where k is 0 or 1 (no subarrays possible)
        if (k <= 1) return 0;

        int totalCount = 0;
        int product = 1;

        // Use two pointers to maintain a sliding window
        for (int left = 0, right = 0; right < nums.length; right++) {
            // Expand the window by including the element at the right pointer
            product *= nums[right];

            // Shrink the window from the left while the product is greater than or equal to k
            while (product >= k) {
                // Remove the element at the left pointer from the product
                product /= nums[left++];
            }

            // Update the total count by adding the number of valid subarrays with the current window size
            totalCount += right - left + 1;  // right - left + 1 represents the current window size
        }

        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # Handle edge cases where k is 0 or 1 (no subarrays possible)
        if k <= 1:
            return 0

        total_count = 0
        product = 1

        # Use two pointers to maintain a sliding window
        left = 0
        for right, num in enumerate(nums):
            product *= num  # Expand the window by including the element at the right pointer

            # Shrink the window from the left while the product is greater than or equal to k
            while product >= k:
                product //= nums[left]  # Remove the element at the left pointer from the product
                left += 1

            # Update the total count by adding the number of valid subarrays with the current window size
            total_count += right - left + 1  # right - left + 1 represents the current window size

        return total_count
```

</details>

<br>

## Approach 2: Using Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        double logK = log(k);
        int m = nums.size() + 1;
        vector<double> logsPrefixSum(m);

        // Calculate prefix sum of logarithms of elements
        for (int i = 0; i < nums.size(); i++) {
            logsPrefixSum[i + 1] = logsPrefixSum[i] + log(nums[i]);
        }

        int totalCount = 0;
        // Calculate subarray count with product less than k
        for (int currIdx = 0; currIdx < m; currIdx++) {
            int low = currIdx + 1, high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (logsPrefixSum[mid] < logsPrefixSum[currIdx] + logK - 1e-9) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            totalCount += low - currIdx - 1;
        }
        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0) return 0;
        double logK = Math.log(k);
        int m = nums.length + 1;
        double[] logsPrefixSum = new double[m];
        
        // Calculate prefix sum of logarithms of elements
        for (int i = 0; i < nums.length; i++) {
            logsPrefixSum[i + 1] = logsPrefixSum[i] + Math.log(nums[i]);
        }

        int totalCount = 0;
        // Calculate subarray count with product less than k
        for (int currIdx = 0; currIdx < m; currIdx++) {
            int low = currIdx + 1, high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (logsPrefixSum[mid] < logsPrefixSum[currIdx] + logK - 1e-9) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            totalCount += low - currIdx - 1;
        }
        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 0
        logK = math.log(k)

        # Calculate prefix sum of logarithms of elements
        logs_prefix_sum = [0]
        for num in nums:
            logs_prefix_sum.append(logs_prefix_sum[-1] + math.log(num))

        total_count = 0
        # Calculate subarray count with product less than k
        for i in range(len(logs_prefix_sum)):
            low, high = i + 1, len(logs_prefix_sum)
            while low < high:
                mid = (low + high) // 2
                if logs_prefix_sum[mid] < logs_prefix_sum[i] + logK - 1e-9:
                    low = mid + 1
                else:
                    high = mid
            total_count += low - i - 1

        return total_count
```

</details>
