# 1064. Fixed Point

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/fixed-point/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 1064 - Fixed Point](https://leetcode.com/problems/fixed-point/)

## Problem

Given an array of distinct integers arr, where arr is sorted in ascending order, return the smallest index i that satisfies arr[i] == i. If there is no such index, return -1.

### Example 1

```text
Input: arr = [-10,-5,0,3,7]
Output: 3
Explanation: For the given array, arr[0] = -10, arr[1] = -5, arr[2] = 0, arr[3] = 3, thus the output is 3.
```

### Example 2

```text
Input: arr = [0,2,5,8,17]
Output: 0
Explanation: arr[0] = 0, thus the output is 0.
```

### Example 3

```text
Input: arr = [-10,-5,3,4,7,9]
Output: -1
Explanation: There is no such i that arr[i] == i, thus the output is -1.
```

## Constraints

- 1 <= arr.length < 104
- -109 <= arr[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1064. Fixed Point

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C++, Java, Python3 |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        // Initialize the boundary of search space
        int left = 0, right = arr.size() - 1;
        
        // Initialize answer to -1, 
        // If no answer is possible, we will return -1
        int answer = -1;
        
        // While the boundary size is non zero
        while (left <= right) {
            // The middle point in the search space
            // To divide the search space into two halves
            int mid = (left + right) / 2;
            
            if (arr[mid] == mid) {
                // Possible answer, 
                // But keep looking for smaller index on the left part
                answer = mid;
                right = mid - 1;
            } else if (arr[mid] < mid) {
                // No solution possible on left, move to the right half
                left = mid + 1;
            } else {
                // No solution possible on right, move to the left half
                right = mid - 1;
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int fixedPoint(int[] arr) {
        // Initialize the boundary of search space
        int left = 0, right = arr.length - 1;
        
        // Initialize answer to -1, 
        // If no answer is possible, we will return -1
        int answer = -1;
        
        // While the boundary size is non zero
        while (left <= right) {
            // The middle point in the search space
            // To divide the search space into two halves
            int mid = (left + right) / 2;
            
            if (arr[mid] == mid) {
                // Possible answer, 
                // But keep looking for smaller index on the left part
                answer = mid;
                right = mid - 1;
            } else if (arr[mid] < mid) {
                // No solution possible on left, move to the right half
                left = mid + 1;
            } else {
                // No solution possible on right, move to the left half
                right = mid - 1;
            }
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fixedPoint(self, arr: List[int]) -> int:
        # Initialize the boundary of search space
        left, right = 0, len(arr) - 1
        
        # Initialize answer to -1, 
        # If no answer is possible, we will return -1
        answer = -1

        # While the boundary size is non zero
        while left <= right:
            # The middle point in the search space
            # To divide the search space into two halves
            mid = (left + right) // 2

            if arr[mid] == mid:
                # We found a possible answer, but keep looking 
                # for a smaller index on the left part
                answer = mid
                right = mid - 1
            elif arr[mid] < mid:
                # No solution possible on left, move to the right half
                left = mid + 1
            else:
                # No solution possible on right, move to the left half
                right = mid - 1

        return answer
```

</details>
