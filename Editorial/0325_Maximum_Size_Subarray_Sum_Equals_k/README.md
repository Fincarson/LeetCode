# 325. Maximum Size Subarray Sum Equals k

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 325 - Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

## Problem

Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there is not one, return 0 instead.

### Example 1

```text
Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
```

### Example 2

```text
Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
```

## Constraints

- 1 <= nums.length <= 2 * 105
- -104 <= nums[i] <= 104
- -109 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Subarray With OR at Least K II](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 325. Maximum Size Subarray Sum Equals k

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum + Hash Map | C++, Java, Python3 |

## Approach: Prefix Sum + Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long prefixSum = 0;
        long long longestSubarray = 0;
        unordered_map<long long, long long> indices;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if (prefixSum == k) {
                longestSubarray = i + 1;
            }
            
            // If any subarray seen so far sums to k, then
            // update the length of the longest_subarray. 
            if (indices.find((long long)prefixSum - k) != indices.end()) {
                longestSubarray = max(longestSubarray, (long long)i - indices[prefixSum - k]);
            }

            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (indices.find(prefixSum) == indices.end()) {
                indices[prefixSum] = i;
            }
        }
        
        return longestSubarray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int prefixSum = 0;
        int longestSubarray = 0;
        HashMap<Integer, Integer> indices = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if (prefixSum == k) {
                longestSubarray = i + 1;
            }

            // If any subarray seen so far sums to k, then
            // update the length of the longest_subarray. 
            if (indices.containsKey(prefixSum - k)) {
                longestSubarray = Math.max(longestSubarray, i - indices.get(prefixSum - k));
            }
            
            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (!indices.containsKey(prefixSum)) {
                indices.put(prefixSum, i);
            }
        }
        
        return longestSubarray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix_sum = longest_subarray = 0
        indices = {}
        
        for i, num in enumerate(nums):
            prefix_sum += num
            
            # Check if all of the numbers seen so far sum to k.
            if prefix_sum == k:
                longest_subarray = i + 1
                
            # If any subarray seen so far sums to k, then
            # update the length of the longest_subarray. 
            if prefix_sum - k in indices:
                longest_subarray = max(longest_subarray, i - indices[prefix_sum - k])
                
            # Only add the current prefix_sum index pair to the 
            # map if the prefix_sum is not already in the map.
            if prefix_sum not in indices:
                indices[prefix_sum] = i
        
        return longest_subarray
```

</details>
