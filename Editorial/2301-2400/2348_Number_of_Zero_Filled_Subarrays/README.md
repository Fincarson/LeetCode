# 2348. Number of Zero-Filled Subarrays

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-zero-filled-subarrays/)  
`Array` `Math`

**Problem Link:** [LeetCode 2348 - Number of Zero-Filled Subarrays](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

## Problem

Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
```

### Example 2

```text
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
```

### Example 3

```text
Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
```

## Constraints

- 1 <= nums.length <= 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Smooth Descent Periods of a Stock](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Length of the Longest Alphabetical Continuous Substring](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Consecutive Integers from a Data Stream](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2348. Number of Zero-Filled Subarrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Count the number of consecutive 0's. | C++, Java, Python |

## Approach: Count the number of consecutive 0's.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubarray = 0;
        
        // Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        // than the previous one, otherwise, it has 0 zero-filled subarray.
        for (auto num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0, numSubarray = 0;
        
        // Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        // than the previous one, otherwise, it has 0 zero-filled subarray.
        for (int num : nums) {
            if (num == 0)
                numSubarray++;
            else
                numSubarray = 0;
            ans += numSubarray;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, num_subarray = 0, 0
        
        # Iterate over nums, if num = 0, it has 1 more zero-filled subarray
        # than the previous one, otherwise, it has 0 zero-filled subarray.
        for num in nums:
            if num == 0: 
                num_subarray += 1
            else: 
                num_subarray = 0
            ans += num_subarray
            
        return ans
```

</details>
