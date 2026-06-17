# 2419. Longest Subarray With Maximum Bitwise AND

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/)  
`Array` `Bit Manipulation` `Brainteaser`

**Problem Link:** [LeetCode 2419 - Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/)

## Problem

You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

- In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.

Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

### Example 1

```text
Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
```

### Example 2

```text
Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Different Integers in a String](https://leetcode.com/problems/number-of-different-integers-in-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Remove Colored Pieces if Both Neighbors are the Same Color](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2419. Longest Subarray With Maximum Bitwise AND

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Longest consecutive sequence of the maximum value | C++, Java, Python3 |

## Approach: Longest consecutive sequence of the maximum value

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSubarray(int[] nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = Math.max(ans, currentStreak);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_val = ans = current_streak = 0
        for num in nums:
            if max_val < num:
                max_val = num
                ans = current_streak = 0

            if max_val == num:
                current_streak += 1
            else:
                current_streak = 0

            ans = max(ans, current_streak)
        return ans
```

</details>
