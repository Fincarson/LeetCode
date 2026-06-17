# 2134. Minimum Swaps to Group All 1's Together II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 2134 - Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)

## Problem

A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

### Example 1

```text
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
```

### Example 2

```text
Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
```

### Example 3

```text
Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Swaps to Group All 1's Together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Time Needed to Rearrange a Binary String](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2134. Minimum Swaps to Group All 1's Together II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Suffix Sum | C++, Java, Python3 |
| Using Sliding Window | C++, Java, Python3 |
| Cleaner and More Intuitive Sliding Window | C++, Java, Python3 |

## Approach 1: Using Suffix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int op1 = minSwapsHelper(nums, 0);  // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1);  // Grouping all 1s together
        return min(op1, op2);
    }

private:
    int minSwapsHelper(const vector<int>& data, int val) {
        int length = data.size();
        vector<int> rightSuffixSum(length + 1, 0);

        // Construct the suffix sum array for counting opposite values
        // (val ^ 1)
        for (int i = length - 1; i >= 0; i--) {
            rightSuffixSum[i] = rightSuffixSum[i + 1];
            if (data[i] == (val ^ 1)) rightSuffixSum[i]++;
        }

        // Total zeros in the array if `val` is 1 (or vice versa)
        int totalSwapsNeeded = rightSuffixSum[0];
        // Track current number of required swaps in the current segment
        int currentSwapCount = 0;
        int minimumSwaps =
            totalSwapsNeeded - rightSuffixSum[length - totalSwapsNeeded];

        // Iterate to find the minimum swaps by sliding the potential block of
        // grouped `val`
        for (int i = 0; i < totalSwapsNeeded; i++) {
            if (data[i] == (val ^ 1)) currentSwapCount++;
            int remaining = (totalSwapsNeeded - i - 1);
            int requiredSwaps =
                ((i + 1) - currentSwapCount) +
                (remaining - rightSuffixSum[length - remaining]);
            minimumSwaps = min(minimumSwaps, requiredSwaps);
        }
        return minimumSwaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(int[] nums) {
        // Calculate the minimum swaps needed to group all 1s or all 0s together
        int op1 = minSwapsHelper(nums, 0); // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1); // Grouping all 1s together
        return Math.min(op1, op2);
    }

    // Helper function to calculate the minimum swaps required to group all `val` together
    public int minSwapsHelper(int[] data, int val) {
        int length = data.length;
        int[] rightSuffixSum = new int[length + 1];

        // Construct the suffix sum array for counting opposite values (val ^ 1)
        for (int i = length - 1; i >= 0; i--) {
            rightSuffixSum[i] = rightSuffixSum[i + 1];
            if (data[i] == (val ^ 1)) rightSuffixSum[i]++;
        }
        // Total zeros in the array if `val` is 1 (or vice versa)
        int totalSwapsNeeded = rightSuffixSum[0];
        // Track current number of required swaps in the current segment
        int currentSwapCount = 0;
        int minimumSwaps =
            totalSwapsNeeded - rightSuffixSum[length - totalSwapsNeeded];

        // Iterate to find the minimum swaps by sliding the potential block of grouped `val`
        for (int i = 0; i < totalSwapsNeeded; i++) {
            if (data[i] == (val ^ 1)) currentSwapCount++;
            int remaining = (totalSwapsNeeded - i - 1);
            int requiredSwaps =
                ((i + 1) - currentSwapCount) +
                (remaining - rightSuffixSum[length - remaining]);
            minimumSwaps = Math.min(minimumSwaps, requiredSwaps);
        }
        return minimumSwaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        op1 = self.min_swaps_helper(nums, 0)  # Grouping all 0s together
        op2 = self.min_swaps_helper(nums, 1)  # Grouping all 1s together
        return min(op1, op2)

    def min_swaps_helper(self, data: List[int], val: int) -> int:
        length = len(data)
        right_suffix_sum = [0] * (length + 1)

        # Construct the suffix sum array for counting opposite values
        # (val ^ 1)
        for i in range(length - 1, -1, -1):
            right_suffix_sum[i] = right_suffix_sum[i + 1]
            if data[i] == (val ^ 1):
                right_suffix_sum[i] += 1

        # Total zeros in the array if `val` is 1 (or vice versa)
        total_swaps_needed = right_suffix_sum[0]
        # Track current number of required swaps in the current segment
        current_swap_count = 0
        minimum_swaps = (
            total_swaps_needed - right_suffix_sum[length - total_swaps_needed]
        )

        # Iterate to find the minimum swaps by sliding
        # the potential block of grouped `val`
        for i in range(total_swaps_needed):
            if data[i] == (val ^ 1):
                current_swap_count += 1
            remaining = total_swaps_needed - i - 1
            required_swaps = ((i + 1) - current_swap_count) + (
                remaining - right_suffix_sum[length - remaining]
            )
            minimum_swaps = min(minimum_swaps, required_swaps)
        return minimum_swaps
```

</details>

<br>

## Approach 2: Using Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Calculate the minimum swaps needed to group all 1s or all 0s
        // together
        int op1 = minSwapsHelper(nums, 0);  // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1);  // Grouping all 1s together
        return min(op1, op2);
    }

    // Helper function to calculate the minimum swaps required to group all
    // `val` together
    int minSwapsHelper(vector<int>& data, int val) {
        int length = data.size();
        int totalValCount = 0;

        // Count the total number of `val` in the array
        for (int i = length - 1; i >= 0; i--) {
            if (data[i] == val) totalValCount++;
        }

        // If there is no `val` or the array is full of `val`, no swaps are
        // needed
        if (totalValCount == 0 || totalValCount == length) return 0;

        int start = 0, end = 0;
        int maxValInWindow = 0, currentValInWindow = 0;

        // Initial window setup: count the number of `val` in the first window
        // of size `totalValCount`
        while (end < totalValCount) {
            if (data[end++] == val) currentValInWindow++;
        }
        maxValInWindow = max(maxValInWindow, currentValInWindow);

        // Slide the window across the array to find the maximum number of
        // `val` in any window
        while (end < length) {
            if (data[start++] == val) currentValInWindow--;
            if (data[end++] == val) currentValInWindow++;
            maxValInWindow = max(maxValInWindow, currentValInWindow);
        }

        // Minimum swaps are the total `val` minus the maximum found in any
        // window
        return totalValCount - maxValInWindow;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(int[] nums) {
        // Calculate the minimum swaps needed to group all 1s or all 0s together
        int op1 = minSwapsHelper(nums, 0); // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1); // Grouping all 1s together
        return Math.min(op1, op2);
    }

    // Helper function to calculate the minimum swaps required
    // to group all `val` together
    public int minSwapsHelper(int[] data, int val) {
        int length = data.length;
        int totalValCount = 0;

        // Count the total number of `val` in the array
        for (int i = length - 1; i >= 0; i--) {
            if (data[i] == val) totalValCount++;
        }

        // If there is no `val` or the array is full of `val`,
        // no swaps are needed
        if (totalValCount == 0 || totalValCount == length) return 0;

        int start = 0, end = 0;
        int maxValInWindow = 0, currentValInWindow = 0;

        // Initial window setup: count the number of `val` in
        // the first window of size `totalValCount`
        while (end < totalValCount) {
            if (data[end++] == val) currentValInWindow++;
        }
        maxValInWindow = Math.max(maxValInWindow, currentValInWindow);

        // Slide the window across the array to find the
        // maximum number of `val` in any window
        while (end < length) {
            if (data[start++] == val) currentValInWindow--;
            if (data[end++] == val) currentValInWindow++;
            maxValInWindow = Math.max(maxValInWindow, currentValInWindow);
        }

        // Minimum swaps are the total `val` minus
        // the maximum found in any window
        return totalValCount - maxValInWindow;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        # Calculate the minimum swaps needed to group all 1s or all 0s together
        op1 = self.min_swaps_helper(nums, 0)  # Grouping all 0s together
        op2 = self.min_swaps_helper(nums, 1)  # Grouping all 1s together
        return min(op1, op2)

    def min_swaps_helper(self, data: List[int], val: int) -> int:
        length = len(data)
        total_val_count = 0

        # Count the total number of `val` in the array
        for i in range(length - 1, -1, -1):
            if data[i] == val:
                total_val_count += 1

        # If there is no `val` or the array is full of `val`, no swaps are needed
        if total_val_count == 0 or total_val_count == length:
            return 0

        start = 0
        end = 0
        max_val_in_window = 0
        current_val_in_window = 0

        # Initial window setup: count the number of `val` in the first window of size `total_val_count`
        while end < total_val_count:
            if data[end] == val:
                current_val_in_window += 1
            end += 1
        max_val_in_window = max(max_val_in_window, current_val_in_window)

        # Slide the window across the array to find the maximum number of `val` in any window
        while end < length:
            if data[start] == val:
                current_val_in_window -= 1
            start += 1
            if data[end] == val:
                current_val_in_window += 1
            end += 1
            max_val_in_window = max(max_val_in_window, current_val_in_window)

        # Minimum swaps are the total `val` minus the maximum found in any window
        return total_val_count - max_val_in_window
```

</details>

<br>

## Approach 3: Cleaner and More Intuitive Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Initialize minimum swaps to a large value
        int minimumSwaps = INT_MAX;

        // Calculate the total number of 1s in the array
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        // Initialize the count of 1s in the current window
        int onesCount = nums[0];
        int end = 0;

        // Slide the window across the array
        for (int start = 0; start < nums.size(); ++start) {
            // Adjust onesCount by removing the element that is sliding out of
            // the window
            if (start != 0) {
                onesCount -= nums[start - 1];
            }

            // Expand the window to the right until it reaches the desired size
            while (end - start + 1 < totalOnes) {
                end++;
                onesCount += nums[end % nums.size()];
            }

            // Update the minimum number of swaps needed
            minimumSwaps = min(minimumSwaps, totalOnes - onesCount);
        }

        return minimumSwaps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSwaps(int[] nums) {
        // Initialize minimum swaps to a large value
        int minimumSwaps = Integer.MAX_VALUE;

        // Calculate the total number of 1s in the array
        int totalOnes = 0;
        for (int num : nums) {
            totalOnes += num;
        }

        // Initialize the count of 1s in the current window
        int onesCount = nums[0];
        int end = 0;

        // Slide the window across the array
        for (int start = 0; start < nums.length; ++start) {
            // Adjust onesCount by removing the element that is sliding out of
            // the window
            if (start != 0) {
                onesCount -= nums[start - 1];
            }

            // Expand the window to the right until it reaches the desired size
            while (end - start + 1 < totalOnes) {
                end++;
                onesCount += nums[end % nums.length];
            }

            // Update the minimum number of swaps needed
            minimumSwaps = Math.min(minimumSwaps, totalOnes - onesCount);
        }

        return minimumSwaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        # Initialize minimum swaps to a large value
        minimum_swaps = float("inf")

        # Calculate the total number of 1s in the array
        total_ones = sum(nums)

        # Initialize the count of 1s in the current window
        ones_count = nums[0]
        end = 0

        # Slide the window across the array
        for start in range(len(nums)):
            # Adjust ones_count by removing the element that
            # is sliding out of the window
            if start != 0:
                ones_count -= nums[start - 1]

            # Expand the window to the right until it reaches the desired size
            while end - start + 1 < total_ones:
                end += 1
                ones_count += nums[end % len(nums)]

            # Update the minimum number of swaps needed
            minimum_swaps = min(minimum_swaps, total_ones - ones_count)

        return minimum_swaps
```

</details>
