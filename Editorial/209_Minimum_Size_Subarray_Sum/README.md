# 209. Minimum Size Subarray Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-size-subarray-sum/)  
`Array` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 209 - Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Problem

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

### Example 1

```text
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

### Example 2

```text
Input: target = 4, nums = [1,4,4]
Output: 1
```

### Example 3

```text
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

## Constraints

- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Product After K Increments](https://leetcode.com/problems/maximum-product-after-k-increments/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Subarray With OR at Least K I](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Positive Sum Subarray ](https://leetcode.com/problems/minimum-positive-sum-subarray/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 209. Minimum Size Subarray Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sumOfCurrentWindow = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++) {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target) {
                res = min(res, right - left + 1);
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0, right = 0, sumOfCurrentWindow = 0;
        int res = Integer.MAX_VALUE;

        for(right = 0; right < nums.length; right++) {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target) {
                res = Math.min(res, right - left + 1);
                sumOfCurrentWindow -= nums[left++];
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = 0
        right = 0
        sumOfCurrentWindow = 0
        res = float('inf')

        for right in range(0, len(nums)):
            sumOfCurrentWindow += nums[right]

            while sumOfCurrentWindow >= target:
                res = min(res, right - left + 1)
                sumOfCurrentWindow -= nums[left]
                left += 1

        return res if res != float('inf') else 0
```

</details>
