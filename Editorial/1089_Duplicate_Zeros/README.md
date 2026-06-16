# 1089. Duplicate Zeros

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/duplicate-zeros/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 1089 - Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros/)

## Problem

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

### Example 1

```text
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```

### Example 2

```text
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

## Constraints

- 1 <= arr.length <= 104
- 0 <= arr[i] <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1089. Duplicate Zeros

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two pass, O(1) space | Java, Python |

## Approach 1: Two pass, O(1) space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void duplicateZeros(int[] arr) {
        int possibleDups = 0;
        int length_ = arr.length - 1;

        // Find the number of zeros to be duplicated
        // Stopping when left points beyond the last element in the original array
        // which would be part of the modified array
        for (int left = 0; left <= length_ - possibleDups; left++) {

            // Count the zeros
            if (arr[left] == 0) {

                // Edge case: This zero can't be duplicated. We have no more space,
                // as left is pointing to the last element which could be included  
                if (left == length_ - possibleDups) {
                    // For this zero we just copy it without duplication.
                    arr[length_] = 0;
                    length_ -= 1;
                    break;
                }
                possibleDups++;
            }
        }

        // Start backwards from the last element which would be part of new array.
        int last = length_ - possibleDups;

        // Copy zero twice, and non zero once.
        for (int i = last; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + possibleDups] = 0;
                possibleDups--;
                arr[i + possibleDups] = 0;
            } else {
                arr[i + possibleDups] = arr[i];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """

        possible_dups = 0
        length_ = len(arr) - 1

        # Find the number of zeros to be duplicated
        for left in range(length_ + 1):

            # Stop when left points beyond the last element in the original list
            # which would be part of the modified list
            if left > length_ - possible_dups:
                break

            # Count the zeros
            if arr[left] == 0:
                # Edge case: This zero can't be duplicated. We have no more space,
                # as left is pointing to the last element which could be included  
                if left == length_ - possible_dups:
                    arr[length_] = 0 # For this zero we just copy it without duplication.
                    length_ -= 1
                    break
                possible_dups += 1

        # Start backwards from the last element which would be part of new list.
        last = length_ - possible_dups

        # Copy zero twice, and non zero once.
        for i in range(last, -1, -1):
            if arr[i] == 0:
                arr[i + possible_dups] = 0
                possible_dups -= 1
                arr[i + possible_dups] = 0
            else:
                arr[i + possible_dups] = arr[i]
```

</details>
