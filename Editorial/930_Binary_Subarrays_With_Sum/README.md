# 930. Binary Subarrays With Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-subarrays-with-sum/)  
`Array` `Hash Table` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 930 - Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)

## Problem

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

### Example 1

```text
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
```

### Example 2

```text
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```

## Constraints

- 1 <= nums.length <= 3 * 104
- nums[i] is either 0 or 1.
- 0 <= goal <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Ways to Split Array Into Good Subarrays](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find All Possible Stable Binary Arrays I](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 930. Binary Subarrays With Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | C++, Java, Python3 |
| Sliding Window | C++, Java, Python3 |
| Sliding Window in One Pass | C++, Java, Python3 |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        // {prefix: number of occurrence}
        unordered_map<int, int> freq; // To store the frequency of prefix sums

        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal){
                totalCount++;
            }

            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.find(currentSum - goal) != freq.end()){
                totalCount += freq[currentSum - goal];
            }

            freq[currentSum]++;
        }

        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        // {prefix: number of occurrence}
        Map<Integer, Integer> freq = new HashMap<>(); // To store the frequency of prefix sums

        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal){
                totalCount++;
            }

            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.containsKey(currentSum - goal)){
                totalCount += freq.get(currentSum - goal);
            }

            freq.put(currentSum, freq.getOrDefault(currentSum, 0) + 1);
        }

        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        total_count = 0
        current_sum = 0
        # {prefix: number of occurrence}
        freq = {}  # To store the frequency of prefix sums

        for num in nums:
            current_sum += num
            if current_sum == goal:
                total_count += 1

            # Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if current_sum - goal in freq:
                total_count += freq[current_sum - goal]

            freq[current_sum] = freq.get(current_sum, 0) + 1

        return total_count
```

</details>

<br>

## Approach 2: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
private:
    // Helper function to count the number of subarrays with sum at most the given goal
    int slidingWindowAtMost(vector<int> &nums, int goal){
        int start = 0, currentSum = 0, totalCount = 0; 
        
        // Iterate through the array using a sliding window approach
        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];
            
            // Adjust the window by moving the start pointer to the right
            // until the sum becomes less than or equal to the goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start++];
            }

            // Update the total count by adding the length of the current subarray
            totalCount += end - start + 1;
        }
        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Helper function to count the number of subarrays with sum at most the given goal
    private int slidingWindowAtMost(int[] nums, int goal) {
        int start = 0, currentSum = 0, totalCount = 0;

        // Iterate through the array using a sliding window approach
        for (int end = 0; end < nums.length; end++) {
            currentSum += nums[end];

            // Adjust the window by moving the start pointer to the right
            // until the sum becomes less than or equal to the goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start++];
            }

            // Update the total count by adding the length of the current subarray
            totalCount += end - start + 1;
        }
        return totalCount;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Helper function to count the number of subarrays with sum at most the given goal
    def sliding_window_at_most(self, nums: List[int], goal: int) -> int:
        start, current_sum, total_count = 0, 0, 0

        # Iterate through the array using a sliding window approach
        for end in range(len(nums)):
            current_sum += nums[end]

            # Adjust the window by moving the start pointer to the right
            # until the sum becomes less than or equal to the goal
            while start <= end and current_sum > goal:
                current_sum -= nums[start]
                start += 1

            # Update the total count by adding the length of the current subarray
            total_count += end - start + 1

        return total_count

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.sliding_window_at_most(nums, goal) - self.sliding_window_at_most(nums, goal - 1)
```

</details>

<br>

## Approach 3: Sliding Window in One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;
        
        // Loop through the array using end pointer
        for (int end = 0; end < nums.size(); ++end) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                currentSum -= nums[start];
                start += 1;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        
        return totalCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;

        // Loop through the array using end pointer
        for (int end = 0; end < nums.length; end++) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros++;
                }
                
                currentSum -= nums[start];
                start++;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        
        return totalCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        start = 0
        prefix_zeros = 0
        current_sum = 0
        total_count = 0
        
        # Loop through the array using end pointer
        for end, num in enumerate(nums):
            # Add current element to the sum
            current_sum += num
            
            # Slide the window while condition is met
            while start < end and (nums[start] == 0 or current_sum > goal):
                if nums[start] == 1:
                    prefix_zeros = 0
                else:
                    prefix_zeros += 1
                
                current_sum -= nums[start]
                start += 1
                
            # Count subarrays when window sum matches the goal
            if current_sum == goal:
                total_count += 1 + prefix_zeros  
                
        return total_count
```

</details>
