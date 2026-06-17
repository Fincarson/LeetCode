# 1752. Check if Array Is Sorted and Rotated

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)  
`Array`

**Problem Link:** [LeetCode 1752 - Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

## Problem

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

### Example 1

```text
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
```

### Example 2

```text
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
```

### Example 3

```text
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if All A's Appears Before All B's](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1752. Check if Array Is Sorted and Rotated

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute force | C++, Java, Python3 |
| Compare with sorted array | C++, Java, Python3 |
| Find Smallest Element | C++, Java, Python3 |

## Approach 1: Brute force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // Construct the rotated array
        vector<int> checkSorted(n);

        // Iterate through all possible rotation offsets
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = nums[index];
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = nums[index];
            }

            // Check if the constructed array is sorted
            bool isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }

            // If sorted, return true
            if (isSorted) {
                return true;
            }
        }

        // If no rotation makes the array sorted, return false
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean check(int[] nums) {
        int n = nums.length;

        // Construct the rotated array
        int[] checkSorted = new int[n];

        // Iterate through all possible rotation offsets
        for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
            int currIndex = 0;
            for (int index = rotationOffset; index < n; ++index) {
                checkSorted[currIndex++] = nums[index];
            }
            for (int index = 0; index < rotationOffset; ++index) {
                checkSorted[currIndex++] = nums[index];
            }

            // Check if the constructed array is sorted
            boolean isSorted = true;
            for (int index = 0; index < n - 1; ++index) {
                if (checkSorted[index] > checkSorted[index + 1]) {
                    isSorted = false;
                    break;
                }
            }

            // If sorted, return true
            if (isSorted) {
                return true;
            }
        }

        // If no rotation makes the array sorted, return false
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)

        # Iterate through all possible rotation offsets
        for rotation_offset in range(n):
            check_sorted = []

            # Create the rotated array
            for index in range(rotation_offset, n):
                check_sorted.append(nums[index])
            for index in range(rotation_offset):
                check_sorted.append(nums[index])

            # Check if the constructed array is sorted
            is_sorted = True
            for index in range(n - 1):
                if check_sorted[index] > check_sorted[index + 1]:
                    is_sorted = False
                    break

            # If sorted, return true
            if is_sorted:
                return True

        # If no rotation makes the array sorted, return false
        return False
```

</details>

<br>

## Approach 2: Compare with sorted array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        // Create a sorted copy of the array
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // Compare the original array with the sorted array, considering all
        // possible rotations
        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            bool isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (nums[(rotationOffset + index) % size] !=
                    sortedNums[index]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean check(int[] nums) {
        int size = nums.length;

        // Create a sorted copy of the array
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);

        // Compare the original array with the sorted array, considering all possible rotations
        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            boolean isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (
                    nums[(rotationOffset + index) % size] != sortedNums[index]
                ) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def check(self, nums: List[int]) -> bool:
        size = len(nums)

        # Create a sorted copy of the list
        sorted_nums = sorted(nums)

        # Compare the original list with the sorted list, considering all possible rotations
        for rotation_offset in range(size):
            is_match = True
            for index in range(size):
                if nums[(rotation_offset + index) % size] != sorted_nums[index]:
                    is_match = False
                    break
            if is_match:
                return True

        return False
```

</details>

<br>

## Approach 3: Find Smallest Element

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        int inversionCount = 0;

        // For every pair, count the number of inversions.
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++inversionCount;
                if (inversionCount > 1) return false;
            }
        }

        // Also check between the last and
        // the first element due to rotation
        if (nums[0] < nums[n - 1]) {
            ++inversionCount;
        }

        return inversionCount <= 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean check(int[] nums) {
        int n = nums.length;
        if (n <= 1) return true;

        int inversionCount = 0;

        // For every pair, count the number of inversions.
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++inversionCount;
                if (inversionCount > 1) return false;
            }
        }

        // Also check between the last and the first element due to rotation
        if (nums[0] < nums[n - 1]) {
            ++inversionCount;
        }

        return inversionCount <= 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <= 1:
            return True

        inversion_count = 0

        # For every pair, count the number of inversions.
        for index in range(1, n):
            if nums[index] < nums[index - 1]:
                inversion_count += 1
                if inversion_count > 1:
                    return False

        # Also check between the last and the first element due to rotation
        if nums[0] < nums[n - 1]:
            inversion_count += 1

        return inversion_count <= 1
```

</details>
