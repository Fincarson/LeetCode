# 3097. Shortest Subarray With OR at Least K II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/)  
`Array` `Bit Manipulation` `Sliding Window`

**Problem Link:** [LeetCode 3097 - Shortest Subarray With OR at Least K II](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/)

## Problem

You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 2 * 105
- 0 <= nums[i] <= 109
- 0 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3097. Shortest Subarray With OR at Least K II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1;
        int right = nums.size();
        int minLength = -1;

        // Binary search on the length of subarray
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasValidSubarray(nums, k, mid)) {
                minLength = mid;
                right = mid - 1;  // Try to find smaller length
            } else {
                left = mid + 1;  // Try larger length
            }
        }

        return minLength;
    }

private:
    // Checks if there exists a subarray of given length whose bitwise OR is >=
    // k
    bool hasValidSubarray(vector<int>& nums, int targetSum, int windowSize) {
        int arrayLength = nums.size();
        vector<int> bitCounts(32,
                              0);  // Tracks count of set bits at each position

        // Sliding window approach
        for (int right = 0; right < arrayLength; right++) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[right], 1);

            // Remove leftmost number if window exceeds size
            if (right >= windowSize) {
                updateBitCounts(bitCounts, nums[right - windowSize], -1);
            }

            // Check if current window is valid
            if (right >= windowSize - 1 &&
                convertBitCountsToNumber(bitCounts) >= targetSum) {
                return true;
            }
        }
        return false;
    }

    // Updates bit count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if (((number >> bitPosition) & 1) != 0) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    int convertBitCountsToNumber(vector<int>& bitCounts) {
        int number = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                number |= 1 << bitPosition;
            }
        }
        return number;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumSubarrayLength(int[] nums, int k) {
        int left = 1;
        int right = nums.length;
        int minLength = -1;

        // Binary search on the length of subarray
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hasValidSubarray(nums, k, mid)) {
                minLength = mid;
                right = mid - 1; // Try to find smaller length
            } else {
                left = mid + 1; // Try larger length
            }
        }

        return minLength;
    }

    // Checks if there exists a subarray of given length whose bitwise OR is >= k
    private boolean hasValidSubarray(
        int[] nums,
        int targetSum,
        int windowSize
    ) {
        int arrayLength = nums.length;
        int[] bitCounts = new int[32]; // Tracks count of set bits at each position

        // Sliding window approach
        for (int right = 0; right < arrayLength; right++) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[right], 1);

            // Remove leftmost number if window exceeds size
            if (right >= windowSize) {
                updateBitCounts(bitCounts, nums[right - windowSize], -1);
            }

            // Check if current window is valid
            if (
                right >= windowSize - 1 &&
                convertBitCountsToNumber(bitCounts) >= targetSum
            ) {
                return true;
            }
        }
        return false;
    }

    // Updates bit count array when adding/removing a number from window
    private void updateBitCounts(int[] bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if (((number >> bitPosition) & 1) != 0) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    private int convertBitCountsToNumber(int[] bitCounts) {
        int number = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                number |= 1 << bitPosition;
            }
        }
        return number;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        # Binary search on the length of subarray
        left, right = 1, len(nums)
        min_length = -1

        while left <= right:
            mid = left + (right - left) // 2

            if self._has_valid_subarray(nums, k, mid):
                min_length = mid
                right = mid - 1  # Try to find smaller length
            else:
                left = mid + 1  # Try larger length

        return min_length

    def _has_valid_subarray(
        self, nums: list, target_sum: int, window_size: int
    ) -> bool:
        # Tracks count of set bits at each position
        bit_counts = [0] * 32

        # Sliding window approach
        for right in range(len(nums)):
            # Add current number to window
            self._update_bit_counts(bit_counts, nums[right], 1)

            # Remove leftmost number if window exceeds size
            if right >= window_size:
                self._update_bit_counts(
                    bit_counts, nums[right - window_size], -1
                )

            # Check if current window is valid
            if (
                right >= window_size - 1
                and self._convert_bits_to_num(bit_counts) >= target_sum
            ):
                return True

        return False

    def _update_bit_counts(
        self, bit_counts: list, number: int, delta: int
    ) -> None:
        # Update counts for each set bit in the number
        for pos in range(32):
            if number & (1 << pos):
                bit_counts[pos] += delta

    def _convert_bits_to_num(self, bit_counts: list) -> int:
        # Convert bit counts to number using OR operation
        return sum(1 << pos for pos in range(32) if bit_counts[pos])
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
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX;
        int windowStart = 0;
        int windowEnd = 0;
        vector<int> bitCounts(32,
                              0);  // Tracks count of set bits at each position

        // Expand window until end of array
        while (windowEnd < nums.size()) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            // Contract window while OR value is valid
            while (windowStart <= windowEnd &&
                   convertBitCountsToNumber(bitCounts) >= k) {
                // Update minimum length found so far
                minLength = min(minLength, windowEnd - windowStart + 1);

                // Remove leftmost number and shrink window
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }

            windowEnd++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Updates bit count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if ((number >> bitPosition) & 1) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    int convertBitCountsToNumber(const vector<int>& bitCounts) {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                result |= 1 << bitPosition;
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

    public int minimumSubarrayLength(int[] nums, int k) {
        int minLength = Integer.MAX_VALUE;
        int windowStart = 0;
        int windowEnd = 0;
        int[] bitCounts = new int[32]; // Tracks count of set bits at each position

        // Expand window until end of array
        while (windowEnd < nums.length) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            // Contract window while OR value is valid
            while (
                windowStart <= windowEnd &&
                convertBitCountsToNumber(bitCounts) >= k
            ) {
                // Update minimum length found so far
                minLength = Math.min(minLength, windowEnd - windowStart + 1);

                // Remove leftmost number and shrink window
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }

            windowEnd++;
        }

        return minLength == Integer.MAX_VALUE ? -1 : minLength;
    }

    // Updates bit count array when adding/removing a number from window
    private void updateBitCounts(int[] bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if (((number >> bitPosition) & 1) != 0) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    private int convertBitCountsToNumber(int[] bitCounts) {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                result |= 1 << bitPosition;
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
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        min_length = float("inf")
        window_start = window_end = 0
        bit_counts = [0] * 32  # Tracks count of set bits at each position

        # Expand window until end of array
        while window_end < len(nums):
            # Add current number to window
            self._update_bit_counts(bit_counts, nums[window_end], 1)

            # Contract window while OR value is valid
            while (
                window_start <= window_end
                and self._convert_bits_to_num(bit_counts) >= k
            ):
                # Update minimum length found so far
                min_length = min(min_length, window_end - window_start + 1)

                # Remove leftmost number and shrink window
                self._update_bit_counts(bit_counts, nums[window_start], -1)
                window_start += 1

            window_end += 1

        return -1 if min_length == float("inf") else min_length

    def _update_bit_counts(
        self, bit_counts: list, number: int, delta: int
    ) -> None:
        # Update counts for each set bit in the number
        for pos in range(32):
            if number & (1 << pos):
                bit_counts[pos] += delta

    def _convert_bits_to_num(self, bit_counts: list) -> int:
        # Convert bit counts to number using OR operation
        result = 0
        for pos in range(32):
            if bit_counts[pos]:
                result |= 1 << pos
        return result
```

</details>
