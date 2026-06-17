# 974. Subarray Sums Divisible by K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/subarray-sums-divisible-by-k/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 974 - Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

## Problem

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

### Example 2

```text
Input: nums = [5], k = 9
Output: 0
```

## Constraints

- 1 <= nums.length <= 3 * 104
- -104 <= nums[i] <= 104
- 2 <= k <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Bad Pairs](https://leetcode.com/problems/count-number-of-bad-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Divisibility Array of a String](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count of Interesting Subarrays](https://leetcode.com/problems/count-of-interesting-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Subarray Sum With Length Divisible by K](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 974. Subarray Sums Divisible by K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sums and Counting | C++, Java |

## Approach: Prefix Sums and Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0, result = 0;

        // There are k mod groups 0...k-1.
        vector<int> modGroups(k);
        modGroups[0] = 1;

        for (int num : nums) {
            // Take modulo twice to avoid negative remainders.
            prefixMod = (prefixMod + num % k + k) % k;
            // Add the count of subarrays that have the same remainder as the current
            // one to cancel out the remainders.
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        int prefixMod = 0, result = 0;

        // There are k mod groups 0...k-1.
        int[] modGroups = new int[k];
        modGroups[0] = 1;

        for (int num: nums) {
            // Take modulo twice to avoid negative remainders.
            prefixMod = (prefixMod + num % k + k) % k;
            // Add the count of subarrays that have the same remainder as the current
            // one to cancel out the remainders.
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }

        return result;
    }
}
```

</details>
