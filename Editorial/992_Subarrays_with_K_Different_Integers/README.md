# 992. Subarrays with K Different Integers

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/subarrays-with-k-different-integers/)  
`Array` `Hash Table` `Sliding Window` `Counting`

**Problem Link:** [LeetCode 992 - Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Problem

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

- For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A subarray is a contiguous part of an array.

### Example 1

```text
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
```

### Example 2

```text
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
```

## Constraints

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i], k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Number of Unique Flavors After Sharing K Candies](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [K Divisible Elements Subarrays](https://leetcode.com/problems/k-divisible-elements-subarrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 992. Subarrays with K Different Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C++, Java, Python3 |
| Sliding Window in One Pass | C++, Java, Python3 |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }

private:
    // Helper function to count the number of subarrays with at most k distinct elements.
    int slidingWindowAtMost(vector<int>& nums, int distinctK) {
        // To store the occurrences of each element.
        unordered_map<int, int> freqMap;
        int left = 0, totalCount = 0;

        // Right pointer of the sliding window iterates through the array.
        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;

            // If the number of distinct elements in the window exceeds k,
            // we shrink the window from the left until we have at most k distinct elements.
            while (freqMap.size() > distinctK) {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) 
                    freqMap.erase(nums[left]);
                left++;
            }

            // Update the total count by adding the length of the current subarray.
            totalCount += (right - left + 1);
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
    public int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }

    // Helper function to count the number of subarrays with at most k distinct elements.
    private int slidingWindowAtMost(int[] nums, int distinctK) {
        // To store the occurrences of each element.
        Map<Integer, Integer> freqMap = new HashMap<>();
        int left = 0, totalCount = 0;

        // Right pointer of the sliding window iterates through the array.
        for (int right = 0; right < nums.length; right++) {
            freqMap.put(nums[right], freqMap.getOrDefault(nums[right], 0) + 1);

            // If the number of distinct elements in the window exceeds k,
            // we shrink the window from the left until we have at most k distinct elements.
            while (freqMap.size() > distinctK) {
                freqMap.put(nums[left], freqMap.get(nums[left]) - 1);
                if (freqMap.get(nums[left]) == 0) {
                    freqMap.remove(nums[left]);
                }
                left++;
            }

            // Update the total count by adding the length of the current subarray.
            totalCount += (right - left + 1);
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
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.slidingWindowAtMost(nums, k) - self.slidingWindowAtMost(nums, k - 1)

    # Helper function to count the number of subarrays with at most k distinct elements.
    def slidingWindowAtMost(self, nums: List[int], distinctK: int) -> int:
        # To store the occurrences of each element.
        freq_map = defaultdict(int)
        left = 0
        total_count  = 0

        # Right pointer of the sliding window iterates through the array.
        for right in range(len(nums)):
            freq_map[nums[right]] += 1

            # If the number of distinct elements in the window exceeds k,
            # we shrink the window from the left until we have at most k distinct elements.
            while len(freq_map) > distinctK:
                freq_map[nums[left]] -= 1
                if freq_map[nums[left]] == 0:
                    del freq_map[nums[left]]
                left += 1

            # Update the total count by adding the length of the current subarray.
            total_count  += right - left + 1

        return total_count
```

</details>

<br>

## Approach 2: Sliding Window in One Pass

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
   public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Array to store the count of distinct values encountered
        vector<int> distinctCount(nums.size() + 1, 0);

        int totalCount = 0;
        int left = 0;
        int right = 0;
        int currCount = 0;

        while (right < nums.size()) {
            // Increment the count of the current element in the window
            if (++distinctCount[nums[right++]] == 1) {
                // If encountering a new distinct element, decrement K
                k--;
            }

            // If K becomes negative, adjust the window from the left
            if (k < 0) {
                // Move the left pointer until the count of distinct elements
                // becomes valid again
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }

            // If K becomes zero, calculate subarrays
            if (k == 0) {
                // While the count of left remains greater than 1, keep
                // shrinking the window from the left
                while (distinctCount[nums[left]] > 1) {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                // Add the count of subarrays with k distinct elements to the
                // total count
                totalCount += (currCount + 1);
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
    public int subarraysWithKDistinct(int[] nums, int k) {
        // Array to store the count of distinct values encountered
        int[] distinctCount = new int[nums.length + 1];

        int totalCount = 0;
        int left = 0;
        int right = 0;
        int currCount = 0;

        while (right < nums.length) {
            // Increment the count of the current element in the window
            if (distinctCount[nums[right++]]++ == 0) {
                // If encountering a new distinct element, decrement K
                k--;
            }

            // If K becomes negative, adjust the window from the left
            if (k < 0) {
                // Move the left pointer until the count of distinct elements becomes valid again
                --distinctCount[nums[left++]];
                k++;
                currCount = 0;
            }

            // If K becomes zero, calculate subarrays
            if (k == 0) {
                // While the count of left remains greater than 1, keep shrinking the window from the left
                while (distinctCount[nums[left]] > 1) {
                    --distinctCount[nums[left++]];
                    currCount++;
                }
                // Add the count of subarrays with K distinct elements to the total count
                totalCount += (currCount + 1);
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
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # Dictionary to store the count of distinct values encountered
        distinct_count = [0] * (len(nums) + 1)

        total_count = 0
        left = 0
        right = 0
        curr_count = 0

        while right < len(nums):
            # Increment the count of the current element in the window
            distinct_count[nums[right]] += 1

            # If encountering a new distinct element, decrement K
            if distinct_count[nums[right]] == 1:
                k -= 1

            # If K becomes negative, adjust the window from the left
            if k < 0:
                # Move the left pointer until the count of distinct elements becomes valid again
                distinct_count[nums[left]] -= 1
                if distinct_count[nums[left]] == 0:
                    k += 1
                left += 1
                curr_count = 0

            # If K becomes zero, calculate subarrays
            if k == 0:
                # While the count of left remains greater than 1, keep shrinking the window from the left
                while distinct_count[nums[left]] > 1:
                    distinct_count[nums[left]] -= 1
                    left += 1
                    curr_count += 1
                # Add the count of subarrays with K distinct elements to the total count
                total_count += (curr_count + 1)

            # Move the right pointer to expand the window
            right += 1

        return total_count
```

</details>
