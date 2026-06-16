# 1590. Make Sum Divisible by P

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/make-sum-divisible-by-p/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 1590 - Make Sum Divisible by P](https://leetcode.com/problems/make-sum-divisible-by-p/)

## Problem

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

### Example 1

```text
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
```

### Example 2

```text
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
```

### Example 3

```text
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= p <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Divisibility Array of a String](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1590. Make Sum Divisible by P

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Time Limit Exceeded) | C++, Java, Python3 |
| Prefix Sum Modulo | C++, Java, Python3 |

## Approach 1: Brute Force (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum =
            accumulate(nums.begin(), nums.end(), 0LL);  // Use long long for sum

        // If the total sum is already divisible by p, no subarray needs to be
        // removed
        if (totalSum % p == 0) return 0;

        int minLen = n;  // Initialize minLen to the size of the array

        // Try removing every possible subarray
        for (int start = 0; start < n; ++start) {
            long long subSum = 0;  // Use long long to avoid overflow
            for (int end = start; end < n; ++end) {
                subSum += nums[end];  // Calculate the subarray sum

                // Check if removing this subarray makes the remaining sum
                // divisible by p
                long long remainingSum = (totalSum - subSum) % p;

                if (remainingSum == 0) {
                    minLen = min(minLen,
                                 end - start +
                                     1);  // Update the smallest subarray length
                }
            }
        }

        // If no valid subarray is found, return -1
        return minLen == n ? -1 : minLen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        long totalSum = 0;

        // Calculate the total sum
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is already divisible by p, no subarray needs to be removed
        if (totalSum % p == 0) return 0;

        int minLen = n; // Initialize minLen to the size of the array

        // Try removing every possible subarray
        for (int start = 0; start < n; ++start) {
            long subSum = 0; // Initialize subarray sum
            for (int end = start; end < n; ++end) {
                subSum += nums[end]; // Calculate the subarray sum

                // Check if removing this subarray makes the remaining sum divisible by p
                long remainingSum = (totalSum - subSum) % p;

                if (remainingSum == 0) {
                    minLen = Math.min(minLen, end - start + 1); // Update the smallest subarray length
                }
            }
        }

        // If no valid subarray is found, return -1
        return minLen == n ? -1 : minLen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)

        # If the total sum is already divisible by p, no subarray needs to be removed
        if total_sum % p == 0:
            return 0

        n = len(nums)
        min_len = n  # Initialize min_len to the size of the array

        # Try removing every possible subarray
        for start in range(n):
            sub_sum = 0
            for end in range(start, n):
                sub_sum += nums[end]  # Calculate the subarray sum

                # Check if removing this subarray makes the remaining sum divisible by p
                remaining_sum = (total_sum - sub_sum) % p

                if remaining_sum == 0:
                    min_len = min(
                        min_len, end - start + 1
                    )  # Update the smallest subarray length

        # If no valid subarray is found, return -1
        return min_len if min_len != n else -1
```

</details>

<br>

## Approach 2: Prefix Sum Modulo

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate total sum and target remainder
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        if (target == 0) return 0;  // The array is already divisible by p

        // Step 2: Use a hash map to track prefix sum mod p
        unordered_map<int, int> modMap;
        modMap[0] =
            -1;  // To handle the case where the whole prefix is the answer
        int currentSum = 0, minLen = n;

        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate what we need to remove
            int needed = (currentSum - target + p) % p;

            // If we have seen the needed remainder, we can consider this
            // subarray
            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }

            // Store the current remainder and index
            modMap[currentSum] = i;
        }

        // Step 4: Return result
        return minLen == n ? -1 : minLen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minSubarray(int[] nums, int p) {
        int n = nums.length;
        int totalSum = 0;

        // Step 1: Calculate total sum and target remainder
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        if (target == 0) {
            return 0; // The array is already divisible by p
        }

        // Step 2: Use a hash map to track prefix sum mod p
        HashMap<Integer, Integer> modMap = new HashMap<>();
        modMap.put(0, -1); // To handle the case where the whole prefix is the answer
        int currentSum = 0;
        int minLen = n;

        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate what we need to remove
            int needed = (currentSum - target + p) % p;

            // If we have seen the needed remainder, we can consider this subarray
            if (modMap.containsKey(needed)) {
                minLen = Math.min(minLen, i - modMap.get(needed));
            }

            // Store the current remainder and index
            modMap.put(currentSum, i);
        }

        // Step 4: Return result
        return minLen == n ? -1 : minLen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        total_sum = 0

        # Step 1: Calculate total sum and target remainder
        for num in nums:
            total_sum = (total_sum + num) % p

        target = total_sum % p
        if target == 0:
            return 0  # The array is already divisible by p

        # Step 2: Use a dict to track prefix sum mod p
        mod_map = {
            0: -1
        }  # To handle the case where the whole prefix is the answer
        current_sum = 0
        min_len = n

        # Step 3: Iterate over the array
        for i in range(n):
            current_sum = (current_sum + nums[i]) % p

            # Calculate what we need to remove
            needed = (current_sum - target + p) % p

            # If we have seen the needed remainder, we can consider this subarray
            if needed in mod_map:
                min_len = min(min_len, i - mod_map[needed])

            # Store the current remainder and index
            mod_map[current_sum] = i

        # Step 4: Return result
        return -1 if min_len == n else min_len
```

</details>
