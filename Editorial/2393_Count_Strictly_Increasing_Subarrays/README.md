# 2393. Count Strictly Increasing Subarrays

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-strictly-increasing-subarrays/)  
`Array` `Math` `Dynamic Programming`

**Problem Link:** [LeetCode 2393 - Count Strictly Increasing Subarrays](https://leetcode.com/problems/count-strictly-increasing-subarrays/)

## Problem

You are given an array nums consisting of positive integers.

Return the number of subarrays of nums that are in strictly increasing order.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [1,3,5,4,4,6]
Output: 10
Explanation: The strictly increasing subarrays are the following:
- Subarrays of length 1: [1], [3], [5], [4], [4], [6].
- Subarrays of length 2: [1,3], [3,5], [4,6].
- Subarrays of length 3: [1,3,5].
The total number of subarrays is 6 + 3 + 1 = 10.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: 15
Explanation: Every subarray is strictly increasing. There are 15 possible subarrays that we can take.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Ascending Subarray Sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2393. Count Strictly Increasing Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java |
| Greedy | C++, Java |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long currSubarray = 1;
        long long subarrayCount = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is greater, increase the subarrays.
            if (nums[i] > nums[i - 1]) {
                currSubarray++;
            } else {
                // Otherwise, reset the subarray size to 1.
                currSubarray = 1;
            }
            // Add the number of subarrays to the total count.
            subarrayCount += currSubarray;
        }
        
        return subarrayCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long countSubarrays(int[] nums) {
        long currSubarray = 1;
        long subarrayCount = 1;
        
        for (int i = 1; i < nums.length; i++) {
            // If the current element is greater, increase the subarrays.
            if (nums[i] > nums[i - 1]) {
                currSubarray++;
            } else {
                // Otherwise, reset the subarray size to 1.
                currSubarray = 1;
            }
            // Add the number of subarrays to the total count.
            subarrayCount += currSubarray;
        }
        
        return subarrayCount;
    }
}
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        // Variable to store the total number of subarrays.
        long subarrayCount = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Length of the current subarray.
            long currSubarray = 1;
            
            while (i + 1 < nums.size() && nums[i] < nums[i + 1]) {
                currSubarray++;
                i++;
            }
            
            // Add the total number of different subarrays possible from this length.
            subarrayCount += (currSubarray * (currSubarray + 1)) / 2;
        }
        
        return subarrayCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long countSubarrays(int[] nums) {
        // Variable to store the total number of subarrays.
        long subarrayCount = 0;
        
        for (int i = 0; i < nums.length; i++) {
            // Length of the current subarray.
            long currSubarray = 1;
            
            while (i + 1 < nums.length && nums[i] < nums[i + 1]) {
                currSubarray++;
                i++;
            }
            
            // Add the total number of different subarrays possible from this length.
            subarrayCount += (currSubarray * (currSubarray + 1)) / 2;
        }
        
        return subarrayCount;
    }
}
```

</details>
