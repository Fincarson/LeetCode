# 2779. Maximum Beauty of an Array After Applying Operation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/)  
`Array` `Binary Search` `Sliding Window` `Sorting`

**Problem Link:** [LeetCode 2779 - Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/)

## Problem

You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:

- Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
- Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].

The beauty of the array is the length of the longest subsequence consisting of equal elements.

Return the maximum possible beauty of the array nums after applying the operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements.

### Example 1

```text
Input: nums = [4,6,1,2], k = 2
Output: 3
Explanation: In this example, we apply the following operations:
- Choose index 1, replace it with 4 (from range [4,8]), nums = [4,4,1,2].
- Choose index 3, replace it with 4 (from range [0,4]), nums = [4,4,1,4].
After the applied operations, the beauty of the array nums is 3 (subsequence consisting of indices 0, 1, and 3).
It can be proven that 3 is the maximum possible length we can achieve.
```

### Example 2

```text
Input: nums = [1,1,1,1], k = 10
Output: 4
Explanation: In this example we don't have to apply any operations.
The beauty of the array nums is 4 (whole array).
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i], k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Partition Array Such That Maximum Difference Is K](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2779. Maximum Beauty of an Array After Applying Operation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |
| Line Sweep | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Find the farthest index where the value is within the range
            // [nums[i], nums[i] + 2*k]
            int upperBound = findUpperBound(nums, nums[i] + 2 * k);
            // Update the maximum beauty based on the current range
            maxBeauty = max(maxBeauty, upperBound - i + 1);
        }
        return maxBeauty;
    }

private:
    // Helper function to find the largest index where arr[index] <= val
    int findUpperBound(vector<int>& arr, int val) {
        int low = 0, high = arr.size() - 1, result = 0;

        // Perform binary search to find the upper bound
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= val) {
                result = mid;  // Update the result and move to the right half
                low = mid + 1;
            } else {
                high = mid - 1;  // Move to the left half
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

    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int maxBeauty = 0;

        for (int i = 0; i < nums.length; i++) {
            // Find the farthest index where the value is within the range [nums[i], nums[i] + 2*k]
            int upperBound = findUpperBound(nums, nums[i] + 2 * k);
            // Update the maximum beauty based on the current range
            maxBeauty = Math.max(maxBeauty, upperBound - i + 1);
        }
        return maxBeauty;
    }

    // Helper function to find the largest index where arr[index] <= val
    private int findUpperBound(int[] arr, int val) {
        int low = 0, high = arr.length - 1, result = 0;

        // Perform binary search to find the upper bound
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= val) {
                result = mid; // Update the result and move to the right half
                low = mid + 1;
            } else {
                high = mid - 1; // Move to the left half
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
    def maximumBeauty(self, nums: list[int], k: int) -> int:
        nums.sort()
        max_beauty = 0

        for i, num in enumerate(nums):
            # Find the farthest index where the value is within the range [num, num + 2 * k]
            upper_bound = self._find_upper_bound(nums, num + 2 * k)
            # Update the maximum beauty based on the current range
            max_beauty = max(max_beauty, upper_bound - i + 1)

        return max_beauty

    def _find_upper_bound(self, arr: list[int], val: int) -> int:
        low, high, result = 0, len(arr) - 1, 0

        # Perform binary search to find the upper bound
        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid] <= val:
                result = mid  # Update the result and move to the right half
                low = mid + 1
            else:
                high = mid - 1  # Move to the left half

        return result
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;  // Pointer for the end of the valid range
        int maxBeauty = 0;

        // Iterate through the array with the left pointer
        for (int left = 0; left < nums.size(); left++) {
            // Expand the right pointer while the range condition is met
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k) {
                right++;
            }
            // Update the maximum beauty based on the current range
            // We do not add 1 here as right is already pointing to one position
            // beyond the valid range.
            maxBeauty = max(maxBeauty, right - left);
        }
        return maxBeauty;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int right = 0; // Pointer for the end of the valid range
        int maxBeauty = 0;

        // Iterate through the array with the left pointer
        for (int left = 0; left < nums.length; left++) {
            // Expand the right pointer while the range condition is met
            while (right < nums.length && nums[right] - nums[left] <= 2 * k) {
                right++;
            }
            // Update the maximum beauty based on the current range
            // We do not add 1 here as right is already pointing to one position beyond the valid range.
            maxBeauty = Math.max(maxBeauty, right - left);
        }
        return maxBeauty;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBeauty(self, nums: list[int], k: int) -> int:
        nums.sort()
        left = 0
        max_beauty = 0

        # Iterate through the array with the right pointer
        for right in range(len(nums)):
            # Move the left pointer to maintain the valid range
            while nums[right] - nums[left] > 2 * k:
                left += 1
            # Update the maximum beauty based on the current range
            # We do not add 1 here as right is already pointing to one position beyond the valid range.
            max_beauty = max(max_beauty, right - left + 1)

        return max_beauty
```

</details>

<br>

## Approach 3: Line Sweep

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // If there's only one element, the maximum beauty is 1
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        // Find the maximum value in the array
        for (int num : nums) maxValue = max(maxValue, num);

        // Create an array to keep track of the count changes
        vector<int> count(maxValue + 1, 0);

        // Update the count array for each value's range [val - k, val + k]
        for (int num : nums) {
            count[max(num - k, 0)]++;  // Increment at the start of the range
            if (num + k + 1 <= maxValue)
                count[num + k + 1]--;  // Decrement after the range
        }

        int currentSum = 0;  // Tracks the running sum of counts
        // Calculate the prefix sum and find the maximum value
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumBeauty(int[] nums, int k) {
        // If there's only one element, the maximum beauty is 1
        if (nums.length == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        // Find the maximum value in the array
        for (int num : nums) maxValue = Math.max(maxValue, num);

        // Create an array to keep track of the count changes
        int[] count = new int[maxValue + 1];

        // Update the count array for each value's range [val - k, val + k]
        for (int num : nums) {
            count[Math.max(num - k, 0)]++; // Increment at the start of the range
            count[Math.min(num + k + 1, maxValue)]--; // Decrement after the range
        }

        int currentSum = 0; // Tracks the running sum of counts
        // Calculate the prefix sum and find the maximum value
        for (int val : count) {
            currentSum += val;
            maxBeauty = Math.max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumBeauty(self, nums: list[int], k: int) -> int:
        # If there's only one element, the maximum beauty is 1
        if len(nums) == 1:
            return 1

        max_value = max(nums)  # Find the maximum value in nums
        count = [0] * (max_value + 1)  # Array to track count changes

        # Update the count array for the range [val - k, val + k]
        for num in nums:
            count[max(num - k, 0)] += 1  # Increment at the start of the range
            if num + k + 1 <= max_value:
                count[num + k + 1] -= 1  # Decrement after the range

        max_beauty = 0
        current_sum = 0  # Tracks the running sum of counts

        # Calculate the prefix sum and find the maximum beauty
        for val in count:
            current_sum += val
            max_beauty = max(max_beauty, current_sum)

        return max_beauty
```

</details>
