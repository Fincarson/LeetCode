# 213. House Robber II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/house-robber-ii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 213 - House Robber II](https://leetcode.com/problems/house-robber-ii/)

## Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Example 1

```text
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

### Example 2

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Example 3

```text
Input: nums = [1,2,3]
Output: 3
```

## Constraints

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paint House](https://leetcode.com/problems/paint-house/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paint Fence](https://leetcode.com/problems/paint-fence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber III](https://leetcode.com/problems/house-robber-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Coin Path](https://leetcode.com/problems/coin-path/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 213. House Robber II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        if (nums.size() == 1) return nums[0];

        int max1 = rob_simple(nums, 0, nums.size() - 2);
        int max2 = rob_simple(nums, 1, nums.size() - 1);

        return max(max1, max2);
    }

private:
    int rob_simple(vector<int>& nums, int start, int end) {
        int t1 = 0, t2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = temp;
        }

        return t1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;

        if (nums.length == 1) return nums[0];

        int max1 = rob_simple(nums, 0, nums.length - 2);
        int max2 = rob_simple(nums, 1, nums.length - 1);

        return Math.max(max1, max2);
    }

    public int rob_simple(int[] nums, int start, int end) {
        int t1 = 0;
        int t2 = 0;

        for (int i = start; i <= end; i++) {
            int temp = t1;
            int current = nums[i];
            t1 = Math.max(current + t2, t1);
            t2 = temp;
        }

        return t1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0 or nums is None:
            return 0

        if len(nums) == 1:
            return nums[0]

        return max(self.rob_simple(nums[:-1]), self.rob_simple(nums[1:]))

    def rob_simple(self, nums: List[int]) -> int:
        t1 = 0
        t2 = 0
        for current in nums:
            temp = t1
            t1 = max(current + t2, t1)
            t2 = temp

        return t1
```

</details>
