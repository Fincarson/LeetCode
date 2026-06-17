# 410. Split Array Largest Sum

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/split-array-largest-sum/)  
`Array` `Binary Search` `Dynamic Programming` `Greedy` `Prefix Sum`

**Problem Link:** [LeetCode 410 - Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

## Problem

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

### Example 1

```text
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```

### Example 2

```text
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
```

## Constraints

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 106
- 1 <= k <= min(50, nums.length)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Divide Chocolate](https://leetcode.com/problems/divide-chocolate/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subsequence of Size K With the Largest Even Sum](https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Total Beauty of the Gardens](https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost to Split an Array](https://leetcode.com/problems/minimum-cost-to-split-an-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Distribute Elements Into Two Arrays I](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Distribute Elements Into Two Arrays II](https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 410. Split Array Largest Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Binary Search | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];
    
    int getMinimumLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.size() - 1;
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }
        
        // Base Case: If there is only one subarray left, then all of the remaining numbers
        // must go in the current subarray. So return the sum of the remaining numbers.
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        
        // Otherwise, use the recurrence relation to determine the minimum largest subarray
        // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
        int minimumLargestSplitSum = INT_MAX;
        for (int i = currIndex; i <= n - subarrayCount; i++) {
            // Store the sum of the first subarray.
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            
            // Find the maximum subarray sum for the current first split.
            int largestSplitSum = max(firstSplitSum, 
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            
            // Find the minimum among all possible combinations.
            minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);
             
            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }
                       
    int splitArray(vector<int>& nums, int m) {
        // Marking all values to -1 so that we can differentiate 
        // If we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // Store the prefix sum of nums array.
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    Integer[][] memo = new Integer[1001][51];
    
    private int getMinimumLargestSplitSum(int[] prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.length - 1;
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][subarrayCount] != null) {
            return memo[currIndex][subarrayCount];
        }
        
        // Base Case: If there is only one subarray left, then all of the remaining numbers
        // must go in the current subarray. So return the sum of the remaining numbers.
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        
        // Otherwise, use the recurrence relation to determine the minimum largest subarray
        // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
        int minimumLargestSplitSum = Integer.MAX_VALUE;
        for (int i = currIndex; i <= n - subarrayCount; i++) {
            // Store the sum of the first subarray.
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            
            // Find the maximum subarray sum for the current first split.
            int largestSplitSum = Math.max(firstSplitSum, 
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            
            // Find the minimum among all possible combinations.
            minimumLargestSplitSum = Math.min(minimumLargestSplitSum, largestSplitSum);
             
            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }
    
    public int splitArray(int[] nums, int m) {
        // Store the prefix sum of nums array.
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        n = len(nums)
        
        # Create a prefix sum array of nums.
        prefix_sum = [0] + list(itertools.accumulate(nums))
        
        @functools.lru_cache(None)
        def get_min_largest_split_sum(curr_index: int, subarray_count: int):
            # Base Case: If there is only one subarray left, then all of the remaining numbers
            # must go in the current subarray. So return the sum of the remaining numbers.
            if subarray_count == 1:
                return prefix_sum[n] - prefix_sum[curr_index]
        
            # Otherwise, use the recurrence relation to determine the minimum largest subarray sum
            # between curr_index and the end of the array with subarray_count subarrays remaining.
            minimum_largest_split_sum = prefix_sum[n]
            for i in range(curr_index, n - subarray_count + 1):
                # Store the sum of the first subarray.
                first_split_sum = prefix_sum[i + 1] - prefix_sum[curr_index]

                # Find the maximum subarray sum for the current first split.
                largest_split_sum = max(first_split_sum, 
                                        get_min_largest_split_sum(i + 1, subarray_count - 1))

                # Find the minimum among all possible combinations.
                minimum_largest_split_sum = min(minimum_largest_split_sum, largest_split_sum)

                if first_split_sum >= minimum_largest_split_sum:
                    break
            
            return minimum_largest_split_sum
        
        return get_min_largest_split_sum(0, m)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        // Store the prefix sum of nums array
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++) {
            for (int currIndex = 0; currIndex < n; currIndex++) {
               // Base Case: If there is only one subarray left, then all of the remaining numbers
               // must go in the current subarray. So return the sum of the remaining numbers.
                if (subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }

                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);

                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int[][] memo = new int[1001][51];
    
    public int splitArray(int[] nums, int m) {
        int n = nums.length;

        // Store the prefix sum of nums array
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++) {
            for (int currIndex = 0; currIndex < n; currIndex++) {
               // Base Case: If there is only one subarray left, then all of the remaining numbers
               // must go in the current subarray. So return the sum of the remaining numbers.
                if (subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }

                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = Integer.MAX_VALUE;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = Math.max(firstSplitSum, memo[i + 1][subarrayCount - 1]);

                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = Math.min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        n = len(nums)
        memo = [[0] * (m + 1) for _ in range(n)]
        
        # Create a prefix sum array of nums.
        prefix_sum = [0] + list(itertools.accumulate(nums))
        
        for subarray_count in range(1, m + 1):
            for curr_index in range(n):
                # Base Case: If there is only one subarray left, then all of the remaining numbers
                # must go in the current subarray. So return the sum of the remaining numbers.
                if subarray_count == 1:
                    memo[curr_index][subarray_count] = prefix_sum[n] - prefix_sum[curr_index]
                    continue

                # Otherwise, use the recurrence relation to determine the minimum largest subarray sum
                # between curr_index and the end of the array with subarray_count subarrays remaining.
                minimum_largest_split_sum = prefix_sum[n]
                for i in range(curr_index, n - subarray_count + 1):
                    # Store the sum of the first subarray.
                    first_split_sum = prefix_sum[i + 1] - prefix_sum[curr_index]

                    # Find the maximum subarray sum for the current first split.
                    largest_split_sum = max(first_split_sum, memo[i + 1][subarray_count - 1])

                    # Find the minimum among all possible combinations.
                    minimum_largest_split_sum = min(minimum_largest_split_sum, largest_split_sum)

                    if first_split_sum >= minimum_largest_split_sum:
                        break
            
                memo[curr_index][subarray_count] = minimum_largest_split_sum
        
        return memo[0][m]
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;
        
        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            } else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }
        }
        
        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }
        
        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {
            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;
            
            // Find the minimum splits. If splitsRequired is less than
            // or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
            } else {
                // Move towards right if splitsRequired is more than m
                left = maxSumAllowed + 1;
            }
        }
        
        return minimumLargestSplitSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int minimumSubarraysRequired(int[] nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;
        
        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            } else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }
        }
        
        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }
    
    public int splitArray(int[] nums, int m) {
        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = Integer.MIN_VALUE;
        for (int element : nums) {
            sum += element;
            maxElement = Math.max(maxElement, element);
        }
        
        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {
            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;
            
            // Find the minimum splits. If splitsRequired is less than
            // or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
            } else {
                // Move towards right if splitsRequired is more than m
                left = maxSumAllowed + 1;
            }
        }
        
        return minimumLargestSplitSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        
        def min_subarrays_required(max_sum_allowed: int) -> int:
            current_sum = 0
            splits_required = 0
            
            for element in nums:
                # Add element only if the sum doesn't exceed max_sum_allowed
                if current_sum + element <= max_sum_allowed:
                    current_sum += element
                else:
                    # If the element addition makes sum more than max_sum_allowed
                    # Increment the splits required and reset sum
                    current_sum = element
                    splits_required += 1

            # Return the number of subarrays, which is the number of splits + 1
            return splits_required + 1
        
        # Define the left and right boundary of binary search
        left = max(nums)
        right = sum(nums)
        while left <= right:
            # Find the mid value
            max_sum_allowed = (left + right) // 2
            
            # Find the minimum splits. If splits_required is less than
            # or equal to m move towards left i.e., smaller values
            if min_subarrays_required(max_sum_allowed) <= m:
                right = max_sum_allowed - 1
                minimum_largest_split_sum = max_sum_allowed
            else:
                # Move towards right if splits_required is more than m
                left = max_sum_allowed + 1
        
        return minimum_largest_split_sum
```

</details>
