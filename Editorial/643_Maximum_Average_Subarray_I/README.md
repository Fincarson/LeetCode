# 643. Maximum Average Subarray I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-average-subarray-i/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 643 - Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)

## Problem

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

### Example 1

```text
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

### Example 2

```text
Input: nums = [5], k = 1
Output: 5.00000
```

## Constraints

- n == nums.length
- 1 <= k <= n <= 105
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 643. Maximum Average Subarray I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Cumulative Sum [Accepted] | Java |
| Approach #2 Sliding Window [Accepted] | Java |

## Approach #1 Cumulative Sum [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
	public double findMaxAverage(int[] nums, int k) {
		int[] sum = new int[nums.length];
		sum[0] = nums[0];
		for (int i = 1; i < nums.length; i++)
		sum[i] = sum[i - 1] + nums[i];
		double res = sum[k - 1] * 1.0 / k;
		for (int i = k; i < nums.length; i++) {
			res = Math.max(res, (sum[i] - sum[i - k]) * 1.0 / k);
		}
		return res;
	}
}
```

</details>

<br>

## Approach #2 Sliding Window [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double res=sum;
        for(int i=k;i<nums.length;i++){
            sum+=nums[i]-nums[i-k];
                res=Math.max(res,sum);
        }
        return res/k;
    }
}
```

</details>
