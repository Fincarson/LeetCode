# 560. Subarray Sum Equals K

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/subarray-sum-equals-k/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 560 - Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

## Problem

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,1,1], k = 2
Output: 2
```

### Example 2

```text
Input: nums = [1,2,3], k = 3
Output: 2
```

## Constraints

- 1 <= nums.length <= 2 * 104
- -1000 <= nums[i] <= 1000
- -107 <= k <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Sum Score of Array](https://leetcode.com/problems/maximum-sum-score-of-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 560. Subarray Sum Equals K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Using Cumulative Sum | Java |
| Without Space | Java |
| Using Hashmap | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 2: Using Cumulative Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 3: Without Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach 4: Using Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}
```

</details>
