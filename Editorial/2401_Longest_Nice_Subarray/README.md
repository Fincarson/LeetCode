# 2401. Longest Nice Subarray

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-nice-subarray/)  
`Array` `Bit Manipulation` `Sliding Window`

**Problem Link:** [LeetCode 2401 - Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/)

## Problem

You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

### Example 1

```text
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
```

### Example 2

```text
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-ors-of-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Get Equal Substrings Within Budget](https://leetcode.com/problems/get-equal-substrings-within-budget/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2401. Longest Nice Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLength = 1;  // Track the maximum nice subarray length found

        for (int start = 0; start < nums.size() - maxLength; start++) {
            int currentLength = 1;  // Length of current nice subarray
            int usedBits =
                nums[start];  // Track which bits are used in our subarray

            // Try to extend the subarray
            for (int end = start + 1; end < nums.size(); end++) {
                // If no bits overlap between current number and used bits, we
                // can extend
                if ((usedBits & nums[end]) == 0) {
                    usedBits |=
                        nums[end];  // Add new number's bits to our tracker
                    currentLength++;
                }
                // If bits overlap, this number can't be part of our nice
                // subarray
                else
                    break;
            }

            // Update max length if we found a longer nice subarray
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestNiceSubarray(int[] nums) {
        int maxLength = 1; // Track the maximum nice subarray length found

        for (int start = 0; start < nums.length - maxLength; start++) {
            int currentLength = 1; // Length of current nice subarray
            int usedBits = nums[start]; // Track which bits are used in our subarray

            // Try to extend the subarray
            for (int end = start + 1; end < nums.length; end++) {
                // If no bits overlap between current number and used bits, we can extend
                if ((usedBits & nums[end]) == 0) {
                    usedBits |= nums[end]; // Add new number's bits to our tracker
                    currentLength++;
                }
                // If bits overlap, this number can't be part of our nice subarray
                else break;
            }

            // Update max length if we found a longer nice subarray
            maxLength = Math.max(maxLength, currentLength);
        }

        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        max_length = 1  # Track the maximum nice subarray length found

        for start in range(len(nums) - max_length):
            current_length = 1  # Length of current nice subarray
            used_bits = nums[start]  # Track which bits are used in our subarray

            # Try to extend the subarray
            for end in range(start + 1, len(nums)):
                # If no bits overlap between current number and used bits, we can extend
                if (used_bits & nums[end]) == 0:
                    used_bits |= nums[
                        end
                    ]  # Add new number's bits to our tracker
                    current_length += 1
                # If bits overlap, this number can't be part of our nice subarray
                else:
                    break

            # Update max length if we found a longer nice subarray
            max_length = max(max_length, current_length)

        return max_length
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
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;     // Tracks bits used in current window
        int windowStart = 0;  // Start position of current window
        int maxLength = 0;    // Length of longest nice subarray found

        for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
            // If current number shares bits with window, shrink window from
            // left until there's no bit conflict
            while ((usedBits & nums[windowEnd]) != 0) {
                usedBits ^=
                    nums[windowStart];  // Remove leftmost element's bits
                windowStart++;
            }

            // Add current number to the window
            usedBits |= nums[windowEnd];

            // Update max length if current window is longer
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestNiceSubarray(int[] nums) {
        int usedBits = 0; // Tracks bits used in current window
        int windowStart = 0; // Start position of current window
        int maxLength = 0; // Length of longest nice subarray found

        for (int windowEnd = 0; windowEnd < nums.length; ++windowEnd) {
            // If current number shares bits with window, shrink window from left
            // until there's no bit conflict
            while ((usedBits & nums[windowEnd]) != 0) {
                usedBits ^= nums[windowStart]; // Remove leftmost element's bits
                windowStart++;
            }

            // Add current number to the window
            usedBits |= nums[windowEnd];

            // Update max length if current window is longer
            maxLength = Math.max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        used_bits = 0  # Tracks bits used in current window
        window_start = 0  # Start position of current window
        max_length = 0  # Length of longest nice subarray found

        for window_end in range(len(nums)):
            # If current number shares bits with window, shrink window from left
            # until there's no bit conflict
            while used_bits & nums[window_end] != 0:
                used_bits ^= nums[
                    window_start
                ]  # Remove leftmost element's bits
                window_start += 1  # Shrink window from left

            # Add current number to the window
            used_bits |= nums[window_end]

            # Update max length if current window is longer
            max_length = max(max_length, window_end - window_start + 1)

        return max_length
```

</details>
