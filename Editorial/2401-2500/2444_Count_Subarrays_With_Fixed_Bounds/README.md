# 2444. Count Subarrays With Fixed Bounds

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)  
`Array` `Queue` `Sliding Window` `Monotonic Queue`

**Problem Link:** [LeetCode 2444 - Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

## Problem

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

- The minimum value in the subarray is equal to minK.
- The maximum value in the subarray is equal to maxK.

Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
```

### Example 2

```text
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
```

## Constraints

- 2 <= nums.length <= 105
- 1 <= nums[i], minK, maxK <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Number of Subarrays Where Boundary Elements Are Maximum](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2444. Count Subarrays With Fixed Bounds

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Two Pointers | C++, Java, Python3 |

## Approach: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // minPosition, maxPosition: the MOST RECENT positions of minK and maxK.
        // leftBound: the MOST RECENT value outside the range [minK, maxK].
        long long answer = 0;
        int minPosition = -1, maxPosition = -1, leftBound = -1;
        
        // Iterate over nums, for each number at index i:
        for (int i = 0; i < nums.size(); ++i) {
            // If the number is outside the range [minK, maxK], update the most recent leftBound.
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            // If the number is minK or maxK, update the most recent position.
            if (nums[i] == minK) 
                minPosition = i;
            if (nums[i] == maxK)
                maxPosition = i;

            // The number of valid subarrays equals the number of elements between leftBound and 
            // the smaller of the two most recent positions (minPosition and maxPosition).
            answer += max(0, min(maxPosition, minPosition) - leftBound);
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        // minPosition, maxPosition: the MOST RECENT positions of minK and maxK.
        // leftBound: the MOST RECENT value outside the range [minK, maxK].
        long answer = 0;
        int minPosition = -1, maxPosition = -1, leftBound = -1;

        // Iterate over nums, for each number at index i:
        for (int i = 0; i < nums.length; ++i) {
            // If the number is outside the range [minK, maxK], update the most recent leftBound.
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;

            // If the number is minK or maxK, update the most recent position.
            if (nums[i] == minK)
                minPosition = i;
            if (nums[i] == maxK)
                maxPosition = i;

            // The number of valid subarrays equals the number of elements between leftBound and 
            // the smaller of the two most recent positions (minPosition and maxPosition).
            answer += Math.max(0, Math.min(maxPosition, minPosition) - leftBound);
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        # min_position, max_position: the MOST RECENT positions of minK and maxK.
        # left_bound: the MOST RECENT value outside the range [minK, maxK].
        answer = 0
        min_position = max_position = left_bound = -1
        
        # Iterate over nums, for each number at index i:
        for i, number in enumerate(nums):
            # If the number is outside the range [minK, maxK], update the most recent left_bound.
            if number < minK or number > maxK:
                left_bound = i
                
            # If the number is minK or maxK, update the most recent position.
            if number == minK:
                min_position = i
            if number == maxK:
                max_position = i
                
            # The number of valid subarrays equals the number of elements between left_bound and 
            # the smaller of the two most recent positions.
            answer += max(0, min(min_position, max_position) - left_bound)
            
        return answer
```

</details>
