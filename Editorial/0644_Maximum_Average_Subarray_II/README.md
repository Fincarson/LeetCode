# 644. Maximum Average Subarray II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-average-subarray-ii/)  
`Array` `Binary Search` `Prefix Sum`

**Problem Link:** [LeetCode 644 - Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/)

## Problem

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is greater than or equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

### Example 1

```text
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation:
- When the length is 4, averages are [0.5, 12.75, 10.5] and the maximum average is 12.75
- When the length is 5, averages are [10.4, 10.8] and the maximum average is 10.8
- When the length is 6, averages are [9.16667] and the maximum average is 9.16667
The maximum average is when we choose a subarray of length 4 (i.e., the sub array [12, -5, -6, 50]) which has the max average 12.75, so we return 12.75
Note that we do not consider the subarrays of length < 4.
```

### Example 2

```text
Input: nums = [5], k = 1
Output: 5.00000
```

## Constraints

- n == nums.length
- 1 <= k <= n <= 104
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 644. Maximum Average Subarray II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Iterative method [Time Limit Exceeded] | Java |
| Approach #2 Using Binary Search [Accepted] | Java |

## Approach #1 Iterative method [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double res = Integer.MIN_VALUE;
        for (int s = 0; s < nums.length - k + 1; s++) {
            long sum = 0;
            for (int i = s; i < nums.length; i++) {
                sum += nums[i];
                if (i - s + 1 >= k)
                    res = Math.max(res, sum * 1.0 / (i - s + 1));
            }
        }
        return res;
    }
}
```

</details>

<br>

## Approach #2 Using Binary Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double max_val = Integer.MIN_VALUE;
        double min_val = Integer.MAX_VALUE;
        for (int n: nums) {
            max_val = Math.max(max_val, n);
            min_val = Math.min(min_val, n);
        }
        double prev_mid = max_val, error = Integer.MAX_VALUE;
        while (error > 0.00001) {
            double mid = (max_val + min_val) * 0.5;
            if (check(nums, mid, k))
                min_val = mid;
            else
                max_val = mid;
            error = Math.abs(prev_mid - mid);
            prev_mid = mid;
        }
        return min_val;
    }
    public boolean check(int[] nums, double mid, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i] - mid;
        if (sum >= 0)
            return true;
        for (int i = k; i < nums.length; i++) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = Math.min(prev, min_sum);
            if (sum >= min_sum)
                return true;
        }
        return false;
    }
}
```

</details>
