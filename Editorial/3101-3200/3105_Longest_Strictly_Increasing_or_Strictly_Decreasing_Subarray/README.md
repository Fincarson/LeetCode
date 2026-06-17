# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)  
`Array`

**Problem Link:** [LeetCode 3105 - Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)

## Problem

You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 50
- 1 <= nums[i] <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Single Iteration | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 0;

        // Find longest strictly increasing subarray
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                // Extend subarray if next element is larger
                if (nums[pos] > nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not increasing anymore
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        // Find longest strictly decreasing subarray
        for (int start = 0; start < nums.size(); start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.size(); pos++) {
                // Extend subarray if next element is smaller
                if (nums[pos] < nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not decreasing anymore
                    break;
                }
            }
            maxLength = max(maxLength, currLength);
        }

        return maxLength;  // Return the longer of increasing or decreasing
                           // sequences
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestMonotonicSubarray(int[] nums) {
        int maxLength = 0;

        // Find longest strictly increasing subarray
        for (int start = 0; start < nums.length; start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.length; pos++) {
                // Extend subarray if next element is larger
                if (nums[pos] > nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not increasing anymore
                    break;
                }
            }
            maxLength = Math.max(maxLength, currLength);
        }

        // Find longest strictly decreasing subarray
        for (int start = 0; start < nums.length; start++) {
            int currLength = 1;
            for (int pos = start + 1; pos < nums.length; pos++) {
                // Extend subarray if next element is smaller
                if (nums[pos] < nums[pos - 1]) {
                    currLength++;
                } else {
                    // Break if sequence is not decreasing anymore
                    break;
                }
            }
            maxLength = Math.max(maxLength, currLength);
        }

        return maxLength; // Return the longer of increasing or decreasing sequences
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestMonotonicSubarray(self, nums: list[int]) -> int:
        max_length = 0

        # Find longest strictly increasing subarray
        for start in range(len(nums)):
            curr_length = 1
            for pos in range(start + 1, len(nums)):
                # Extend subarray if next element is larger
                if nums[pos] > nums[pos - 1]:
                    curr_length += 1
                else:
                    # Break if sequence is not increasing anymore
                    break
            max_length = max(max_length, curr_length)

        # Find longest strictly decreasing subarray
        for start in range(len(nums)):
            curr_length = 1
            for pos in range(start + 1, len(nums)):
                # Extend subarray if next element is smaller
                if nums[pos] < nums[pos - 1]:
                    curr_length += 1
                else:
                    # Break if sequence is not decreasing anymore
                    break
            max_length = max(max_length, curr_length)

        return max_length  # Return the longer of increasing or decreasing sequences
```

</details>

<br>

## Approach 2: Single Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // Track current lengths of increasing and decreasing sequences
        int incLength = 1, decLength = 1;
        int maxLength = 1;

        // Iterate through array comparing adjacent elements
        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                // If next element is larger, extend increasing sequence
                incLength++;
                decLength = 1;  // Reset decreasing sequence
            } else if (nums[pos + 1] < nums[pos]) {
                // If next element is smaller, extend decreasing sequence
                decLength++;
                incLength = 1;  // Reset increasing sequence
            } else {
                // If elements are equal, reset both sequences
                incLength = 1;
                decLength = 1;
            }

            // Update max length considering both sequences
            maxLength = max(maxLength, max(incLength, decLength));
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

    public int longestMonotonicSubarray(int[] nums) {
        // Track current lengths of increasing and decreasing sequences
        int incLength = 1, decLength = 1;
        int maxLength = 1;

        // Iterate through array comparing adjacent elements
        for (int pos = 0; pos < nums.length - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                // If next element is larger, extend increasing sequence
                incLength++;
                decLength = 1; // Reset decreasing sequence
            } else if (nums[pos + 1] < nums[pos]) {
                // If next element is smaller, extend decreasing sequence
                decLength++;
                incLength = 1; // Reset increasing sequence
            } else {
                // If elements are equal, reset both sequences
                incLength = 1;
                decLength = 1;
            }

            // Update max length considering both sequences
            maxLength = Math.max(maxLength, Math.max(incLength, decLength));
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
    def longestMonotonicSubarray(self, nums: list[int]) -> int:
        # Track current lengths of increasing and decreasing sequences
        inc_length = dec_length = max_length = 1

        # Iterate through array comparing adjacent elements
        for pos in range(len(nums) - 1):
            if nums[pos + 1] > nums[pos]:
                # If next element is larger, extend increasing sequence
                inc_length += 1
                dec_length = 1  # Reset decreasing sequence
            elif nums[pos + 1] < nums[pos]:
                # If next element is smaller, extend decreasing sequence
                dec_length += 1
                inc_length = 1  # Reset increasing sequence
            else:
                # If elements are equal, reset both sequences
                inc_length = dec_length = 1

            # Update max length considering both sequences
            max_length = max(max_length, inc_length, dec_length)

        return max_length
```

</details>
