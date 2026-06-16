# 80. Remove Duplicates from Sorted Array II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 80 - Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## Problem

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

```text
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be accepted.

### Example 1

```text
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2

```text
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## Constraints

- 1 <= nums.length <= 3 * 104
- -104 <= nums[i] <= 104
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 80. Remove Duplicates from Sorted Array II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Popping Unwanted Duplicates | C++, Java, Python3 |
| Overwriting unwanted duplicates | C++, Java, Python3 |

## Approach 1: Popping Unwanted Duplicates

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 1;     // Pointer for current index in the array
        int count = 1; // Count of the current element occurrences

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] == nums[j - 1]) {
                count++; // Increment count for the current element
            } else {
                count = 1; // Reset count for new element
            }

            if (count <= 2) {
                nums[i++] = nums[j]; // Update the array in place
            }
        }

        return i; // Return the new array length
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int i = 1; // Pointer for current index in the array
        int count = 1; // Count of the current element occurrences

        for (int j = 1; j < nums.length; j++) {
            if (nums[j] == nums[j - 1]) {
                count++; // Increment count for the current element
            } else {
                count = 1; // Reset count for new element
            }

            if (count <= 2) {
                nums[i++] = nums[j]; // Update the array in place
            }
        }

        return i; // Return the new array length
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Check for edge case where list is empty
        if not nums:
            return 0

        # Pointer for current index in the list
        i = 1
        # Count of the current element occurrences
        count = 1

        # Iterate through the list starting from the second element
        while i < len(nums):
            # Check if the current element is same as the previous one
            if nums[i] == nums[i - 1]:
                # Increment count for the current element
                count += 1
                # If count exceeds 2, remove the current element
                if count > 2:
                    nums.pop(i)
                    i -= 1
                    count -= 1
            else:
                # Reset count for new element
                count = 1
            # Move to the next element
            i += 1

        # Return the new list length
        return len(nums)
```

</details>

<br>

## Approach 2: Overwriting unwanted duplicates

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 1;      // Pointer to iterate through the array
        int j = 1;      // Pointer to track position for valid elements
        int count = 1;  // Count of occurrences of the current element

        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count > 2) {
                    i++;
                    continue;
                }
            } else {
                count = 1;
            }
            nums[j] = nums[i];
            j++;
            i++;
        }

        nums.resize(j);
        return j;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int i = 1; // Pointer to iterate through the array
        int j = 1; // Pointer to track position for valid elements
        int count = 1; // Count of occurrences of the current element

        while (i < nums.length) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count > 2) {
                    i++;
                    continue;
                }
            } else {
                count = 1;
            }
            nums[j] = nums[i];
            j++;
            i++;
        }

        // Java arrays can't be resized like C++ vectors,
        // so we return the size directly.
        return j;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        i = 1
        j = 1
        count = 1

        while i < len(nums):
            if nums[i] == nums[i - 1]:
                count += 1
                if count > 2:
                    i += 1
                    continue
            else:
                count = 1
            nums[j] = nums[i]
            j += 1
            i += 1

        del nums[j:]
        return len(nums)
```

</details>
