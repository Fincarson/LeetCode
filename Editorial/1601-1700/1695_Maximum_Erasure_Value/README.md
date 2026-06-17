# 1695. Maximum Erasure Value

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-erasure-value/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 1695 - Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)

## Problem

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

### Example 1

```text
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
```

### Example 2

```text
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1695. Maximum Erasure Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), result = 0;
        unordered_set<int> seen;
        for (int start = 0; start < n; start++) {
            // reset seen and current sum for next subarray
            seen.clear();
            int currentSum = 0;
            for (int end = start; end < n && (seen.find(nums[end]) == seen.end());
                 end++) {
                currentSum += nums[end];
                seen.insert(nums[end]);
            }
            // update result with maximum sum found so far
            result = max(result, currentSum);
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
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int result = 0;
        HashSet set = new HashSet<>();
        for (int start = 0; start < n; start++) {
            // reset set and current sum for next subarray
            set.clear();
            int currentSum = 0;
            for (int end = start; end < n && !set.contains(nums[end]); end++) {
                currentSum += nums[end];
                set.add(nums[end]);
            }
            // update result with maximum sum found so far
            result = Math.max(result, currentSum);
        }
        return result;
    }
}
```

</details>
