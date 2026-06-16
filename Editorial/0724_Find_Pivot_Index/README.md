# 724. Find Pivot Index

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-pivot-index/)  
`Array` `Prefix Sum`

**Problem Link:** [LeetCode 724 - Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)

## Problem

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

### Example 1

```text
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
```

### Example 2

```text
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

### Example 3

```text
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
```

## Constraints

- 1 <= nums.length <= 104
- -1000 <= nums[i] <= 1000

Note: This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum Score of Array](https://leetcode.com/problems/maximum-sum-score-of-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 724. Find Pivot Index

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Prefix Sum [Accepted] | Java, Python |

## Approach #1: Prefix Sum [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < nums.length; ++i) {
            if (leftsum == sum - leftsum - nums[i]) {
                return i;
            }

            leftsum += nums[i];
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def pivotIndex(self, nums):
        S = sum(nums)
        leftsum = 0
        for i, x in enumerate(nums):
            if leftsum == (S - leftsum - x):
                return i
            leftsum += x
        return -1
```

</details>
