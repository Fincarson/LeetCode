# 334. Increasing Triplet Subsequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/increasing-triplet-subsequence/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 334 - Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/)

## Problem

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

### Example 1

```text
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
```

### Example 2

```text
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
```

### Example 3

```text
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: One of the valid triplet is (1, 4, 5), because nums[1] == 1 < nums[4] == 4 < nums[5] == 6.
```

## Constraints

- 1 <= nums.length <= 5 * 105
- -231 <= nums[i] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Special Quadruplets](https://leetcode.com/problems/count-special-quadruplets/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Increasing Quadruplets](https://leetcode.com/problems/count-increasing-quadruplets/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 334. Increasing Triplet Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Scan | Java, Python3 |

## Approach 1: Linear Scan

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first_num = Integer.MAX_VALUE;
        int second_num = Integer.MAX_VALUE;
        for (int n: nums) {
            if (n <= first_num) {
                first_num = n;
            } else if (n <= second_num) {
                second_num = n;
            } else {
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
    def increasingTriplet(self, nums: List[int]) -> bool:
        first_num = float("inf")
        second_num = float("inf")
        for n in nums:
            if n <= first_num:
                first_num = n
            elif n <= second_num:
                second_num = n
            else:
                return True
        return False
```

</details>
