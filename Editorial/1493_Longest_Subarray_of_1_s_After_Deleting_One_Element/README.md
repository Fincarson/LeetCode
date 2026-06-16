# 1493. Longest Subarray of 1's After Deleting One Element

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)  
`Array` `Dynamic Programming` `Sliding Window`

**Problem Link:** [LeetCode 1493 - Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

## Problem

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

### Example 1

```text
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
```

### Example 2

```text
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
```

### Example 3

```text
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
```

## Constraints

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1493. Longest Subarray of 1's After Deleting One Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Number of zero's in the window.
        int zeroCount = 0;
        int longestWindow = 0;
        // Left end of the window.
        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            zeroCount += (nums[i] == 0);
                          
            // Shrink the window until the count of zero's
            // is less than or equal to 1.
            while (zeroCount > 1) {
                zeroCount -= (nums[start] == 0);
                start++;
            }
              
            longestWindow = max(longestWindow, i - start);
        }

        return longestWindow;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestSubarray(int[] nums) {
        // Number of zero's in the window.
        int zeroCount = 0;
        int longestWindow = 0;
        // Left end of the window.
        int start = 0;
        
        for (int i = 0; i < nums.length; i++) {
            zeroCount += (nums[i] == 0 ? 1 : 0);
                          
            // Shrink the window until the count of zero's
            // is less than or equal to 1.
            while (zeroCount > 1) {
                zeroCount -= (nums[start] == 0 ? 1 : 0);
                start++;
            }
              
            longestWindow = Math.max(longestWindow, i - start);
        }

        return longestWindow;
    }
}
```

</details>
