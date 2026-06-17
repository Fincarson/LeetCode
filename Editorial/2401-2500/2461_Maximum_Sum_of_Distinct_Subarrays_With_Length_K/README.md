# 2461. Maximum Sum of Distinct Subarrays With Length K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 2461 - Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

## Problem

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

- The length of the subarray is k, and
- All the elements of the subarray are distinct.

Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
```

### Example 2

```text
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
```

## Constraints

- 1 <= k <= nums.length <= 105
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Good Subarray Sum](https://leetcode.com/problems/maximum-good-subarray-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Power of K-Size Subarrays I](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Power of K-Size Subarrays II](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2461. Maximum Sum of Distinct Subarrays With Length K

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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0;
        int end = 0;

        unordered_map<int, int> numToIndex;

        while (end < nums.size()) {
            int currNum = nums[end];
            int lastOccurrence =
                (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

            // if current window already has number or if window is too big,
            // adjust window
            while (begin <= lastOccurrence || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }
            numToIndex[currNum] = end;
            currentSum += nums[end];
            if (end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
            end++;
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

    public long maximumSubarraySum(int[] nums, int k) {
        long ans = 0;
        long currentSum = 0;
        int begin = 0;
        int end = 0;

        HashMap<Integer, Integer> numToIndex = new HashMap<>();

        while (end < nums.length) {
            int currNum = nums[end];
            int lastOccurrence = numToIndex.getOrDefault(currNum, -1);
            // if current window already has number or if window is too big, adjust window
            while (begin <= lastOccurrence || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }
            numToIndex.put(currNum, end);
            currentSum += nums[end];
            if (end - begin + 1 == k) {
                ans = Math.max(ans, currentSum);
            }
            end++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        current_sum = 0
        begin = 0
        end = 0
        num_to_index = {}

        while end < len(nums):
            curr_num = nums[end]
            last_occurrence = num_to_index.get(curr_num, -1)
            # if current window already has number or if window is too big, adjust window
            while begin <= last_occurrence or end - begin + 1 > k:
                current_sum -= nums[begin]
                begin += 1
            num_to_index[curr_num] = end
            current_sum += nums[end]
            if end - begin + 1 == k:
                ans = max(ans, current_sum)
            end += 1
        return ans
```

</details>
