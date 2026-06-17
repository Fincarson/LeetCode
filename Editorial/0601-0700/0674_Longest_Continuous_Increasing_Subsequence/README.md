# 674. Longest Continuous Increasing Subsequence

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)  
`Array`

**Problem Link:** [LeetCode 674 - Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)

## Problem

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

### Example 1

```text
Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.
```

### Example 2

```text
Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.
```

## Constraints

- 1 <= nums.length <= 104
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Consecutive Characters](https://leetcode.com/problems/consecutive-characters/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Longest Increasing Subsequence II](https://leetcode.com/problems/longest-increasing-subsequence-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 674. Longest Continuous Increasing Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Sliding Window [Accepted] | Java, Python |

## Approach #1: Sliding Window [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int ans = 0, anchor = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i-1] >= nums[i]) anchor = i;
            ans = Math.max(ans, i - anchor + 1);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findLengthOfLCIS(self, nums):
        ans = anchor = 0
        for i in range(len(nums)):
            if i and nums[i-1] >= nums[i]: anchor = i
            ans = max(ans, i - anchor + 1)
        return ans
```

</details>
