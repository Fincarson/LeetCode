# 3011. Find if Array Can Be Sorted

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-if-array-can-be-sorted/)  
`Array` `Bit Manipulation` `Sorting`

**Problem Link:** [LeetCode 3011 - Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/)

## Problem

You are given a 0-indexed array of positive integers nums.

In one operation, you can swap any two adjacent elements if they have the same number of set bits. You are allowed to do this operation any number of times (including zero).

Return true if you can sort the array in ascending order, else return false.

### Example 1

```text
Input: nums = [8,4,2,30,15]
Output: true
Explanation: Let's look at the binary representation of every element. The numbers 2, 4, and 8 have one set bit each with binary representation "10", "100", and "1000" respectively. The numbers 15 and 30 have four set bits each with binary representation "1111" and "11110".
We can sort the array using 4 operations:
- Swap nums[0] with nums[1]. This operation is valid because 8 and 4 have one set bit each. The array becomes [4,8,2,30,15].
- Swap nums[1] with nums[2]. This operation is valid because 8 and 2 have one set bit each. The array becomes [4,2,8,30,15].
- Swap nums[0] with nums[1]. This operation is valid because 4 and 2 have one set bit each. The array becomes [2,4,8,30,15].
- Swap nums[3] with nums[4]. This operation is valid because 30 and 15 have four set bits each. The array becomes [2,4,8,15,30].
The array has become sorted, hence we return true.
Note that there may be other sequences of operations which also sort the array.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: true
Explanation: The array is already sorted, hence we return true.
```

### Example 3

```text
Input: nums = [3,16,8,4,2]
Output: false
Explanation: It can be shown that it is not possible to sort the input array using any number of operations.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 28

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Integers by The Number of 1 Bits](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3011. Find if Array Can Be Sorted

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bubble Sort | C++, Java, Python3 |
| Sortable Segments | C++, Java, Python3 |
| Forward and Backward Pass | C++, Java, Python3 |

## Approach 1: Bubble Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        // Avoid modifying the input directly
        // Create a copy of the input array
        vector<int> values = nums;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (values[j] <= values[j + 1]) {
                    // No swap needed
                    continue;
                } else {
                    if (__builtin_popcount(nums[j]) ==
                        __builtin_popcount(nums[j + 1])) {
                        // Swap the elements
                        swap(values[j], values[j + 1]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canSortArray(int[] nums) {
        // Avoid modifying the input directly
        int[] values = Arrays.copyOf(nums, nums.length);

        int n = values.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (values[j] <= values[j + 1]) {
                    // No swap needed
                    continue;
                } else {
                    if (
                        Integer.bitCount(values[j]) ==
                        Integer.bitCount(values[j + 1])
                    ) {
                        // Swap the elements
                        int temp = values[j];
                        values[j] = values[j + 1];
                        values[j + 1] = temp;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canSortArray(self, nums):
        n = len(nums)

        # Avoid modifying the input directly
        # Create a copy of the input array
        values = nums.copy()

        for i in range(n):
            for j in range(n - i - 1):
                if values[j] <= values[j + 1]:
                    # No swap needed
                    continue
                else:
                    if bin(values[j]).count("1") == bin(values[j + 1]).count(
                        "1"
                    ):
                        # Swap the elements
                        values[j], values[j + 1] = values[j + 1], values[j]
                    else:
                        return False
        return True
```

</details>

<br>

## Approach 2: Sortable Segments

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // Number of set bits of the elements in the current segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        // Initialize max of the previous segment to the smallest possible
        // integer
        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) {
                // Element belongs to the same segment
                // Update min and max values of the segment
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            } else {  // Element belongs to a new segment
                // Check if the segments are arranged properly
                if (minOfSegment < maxOfPrevSegment) {
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // Start a new segment with the current element
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canSortArray(int[] nums) {
        // Number of set bits of the elements in the current segment
        int numOfSetBits = Integer.bitCount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        // Initialize max of the previous segment to the smallest possible integer
        int maxOfPrevSegment = Integer.MIN_VALUE;

        for (int i = 1; i < nums.length; i++) {
            if (Integer.bitCount(nums[i]) == numOfSetBits) {
                // Element belongs to the same segment
                // Update min and max values of the segment
                maxOfSegment = Math.max(maxOfSegment, nums[i]);
                minOfSegment = Math.min(minOfSegment, nums[i]);
            } else { // Element belongs to a new segment
                // Check if the segments are arranged properly
                if (minOfSegment < maxOfPrevSegment) {
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // Start a new segment with the current element
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = Integer.bitCount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canSortArray(self, nums):
        # Number of set bits of the elements in the current segment
        num_of_set_bits = bin(nums[0]).count("1")
        max_of_segment = nums[0]
        min_of_segment = nums[0]

        # Initialize max of the previous segment to the smallest possible integer
        max_of_prev_segment = float("-inf")

        for i in range(1, len(nums)):
            if bin(nums[i]).count("1") == num_of_set_bits:
                # Element belongs to the same segment
                # Update min and max values of the segment
                max_of_segment = max(max_of_segment, nums[i])
                min_of_segment = min(min_of_segment, nums[i])
            else:  # Element belongs to a new segment
                # Check if the segments are arranged properly
                if min_of_segment < max_of_prev_segment:
                    return False

                # Update the previous segment's max
                max_of_prev_segment = max_of_segment

                # Start a new segment with the current element
                max_of_segment = nums[i]
                min_of_segment = nums[i]
                num_of_set_bits = bin(nums[i]).count("1")

        # Final check for proper segment arrangement
        if min_of_segment < max_of_prev_segment:
            return False

        return True
```

</details>

<br>

## Approach 3: Forward and Backward Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> values = nums;  // Create a copy of the original array

        // First Pass: Iterate from left to right
        // Goal: Move the maximum value of each segment as far right as possible
        for (int i = 0; i < n - 1; i++) {
            // If the current element is less than or equal to the next,
            // continue
            if (values[i] <= values[i + 1]) {
                continue;
            } else {
                // Check if the current and next element have the same number of
                // set bits
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i + 1])) {
                    swap(values[i], values[i + 1]);  // Swap them if they do
                } else {
                    return false;  // Return false if they cannot be swapped
                }
            }
        }

        // Second Pass: Iterate from right to left
        // Goal: Move the minimum value of each segment as far left as possible
        for (int i = n - 1; i >= 1; i--) {
            // If the current element is greater than or equal to the previous,
            // continue
            if (values[i] >= values[i - 1]) {
                continue;
            } else {
                // Check if the current and previous element have the same
                // number of set bits
                if (__builtin_popcount(values[i]) ==
                    __builtin_popcount(values[i - 1])) {
                    swap(values[i], values[i - 1]);  // Swap them if they do
                } else {
                    return false;  // Return false if they cannot be swapped
                }
            }
        }

        // If both passes complete without returning false, the array can be
        // sorted
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canSortArray(int[] nums) {
        int n = nums.length;

        // Copy the original array to values
        int[] values = Arrays.copyOf(nums, n);

        // First Pass: Iterate from left to right
        // Goal: Move the maximum value of each segment as far right as possible
        for (int i = 0; i < n - 1; i++) {
            if (values[i] <= values[i + 1]) {
                continue;
            } else {
                // Count the number of set bits using Integer.bitCount
                if (
                    Integer.bitCount(values[i]) ==
                    Integer.bitCount(values[i + 1])
                ) {
                    // Swap them if they have the same number of set bits
                    int temp = values[i];
                    values[i] = values[i + 1];
                    values[i + 1] = temp;
                } else {
                    return false; // Return false if they cannot be swapped
                }
            }
        }

        // Second Pass: Iterate from right to left
        // Goal: Move the minimum value of each segment as far left as possible
        for (int i = n - 1; i >= 1; i--) {
            if (values[i] >= values[i - 1]) {
                continue;
            } else {
                // Count the number of set bits using Integer.bitCount
                if (
                    Integer.bitCount(values[i]) ==
                    Integer.bitCount(values[i - 1])
                ) {
                    // Swap them if they have the same number of set bits
                    int temp = values[i];
                    values[i] = values[i - 1];
                    values[i - 1] = temp;
                } else {
                    return false; // Return false if they cannot be swapped
                }
            }
        }

        // If both passes complete without returning false, the array can be sorted
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canSortArray(self, nums):
        n = len(nums)
        values = nums.copy()  # Create a copy of the original array

        # First Pass: Iterate from left to right
        # Goal: Move the maximum value of each segment as far right as possible
        for i in range(n - 1):
            if values[i] <= values[i + 1]:
                continue
            else:
                # Check if the current and next element have the same number of set bits
                if bin(values[i]).count("1") == bin(values[i + 1]).count("1"):
                    # Swap if they do
                    temp = values[i]
                    values[i] = values[i + 1]
                    values[i + 1] = temp
                else:
                    return False  # Return false if they cannot be swapped

        # Second Pass: Iterate from right to left
        # Goal: Move the minimum value of each segment as far left as possible
        for i in range(n - 1, 0, -1):
            if values[i] >= values[i - 1]:
                continue
            else:
                # Check if the current and previous element have the same number of set bits
                if bin(values[i]).count("1") == bin(values[i - 1]).count("1"):
                    # Swap if they do
                    temp = values[i]
                    values[i] = values[i - 1]
                    values[i - 1] = temp
                else:
                    return False  # Return false if they cannot be swapped

        # If both passes complete without returning false, the array can be sorted
        return True
```

</details>
