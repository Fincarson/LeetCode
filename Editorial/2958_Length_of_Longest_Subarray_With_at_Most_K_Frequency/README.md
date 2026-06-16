# 2958. Length of Longest Subarray With at Most K Frequency

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 2958 - Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)

## Problem

You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

```text
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
```

### Example 2

```text
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
```

### Example 3

```text
Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= k <= nums.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2958. Length of Longest Subarray With at Most K Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting and Sliding Window | C++, Java, Python3 |
| Counting and Sliding Window without Nested Loops | C++, Java, Python3 |

## Approach 1: Counting and Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> frequency;
        
        for (int end = 0; end < nums.size(); end++) {
            frequency[nums[end]]++;
            while (frequency[nums[end]] > k) {
                start++;
                frequency[nums[start]]--;
            }
            ans = max(ans, end - start);
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
    public int maxSubarrayLength(int[] nums, int k) {
        int ans = 0, start = -1;
        Map<Integer, Integer> frequency = new HashMap();
        
        for (int end = 0; end < nums.length; end++) {
            frequency.put(nums[end], frequency.getOrDefault(nums[end], 0) + 1);
            while (frequency.get(nums[end]) > k) {
                start++;
                frequency.put(nums[start], frequency.get(nums[start]) - 1);
            }
            ans = Math.max(ans, end - start);
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
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans, start = 0, -1
        frequency = Counter()
        for end in range(len(nums)):
            frequency[nums[end]] += 1
            while frequency[nums[end]] > k:
                start += 1
                frequency[nums[start]] -= 1
            ans = max(ans, end - start)
        return ans
```

</details>

<br>

## Approach 2: Counting and Sliding Window without Nested Loops

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> frequency; 
        int start = 0;
        int charsWithFreqOverK = 0;
        
        for (int end = 0; end < n; end++) {
            frequency[nums[end]]++;
            if (frequency[nums[end]] == k + 1) {
                charsWithFreqOverK++;
            }
            if (charsWithFreqOverK > 0) {
                frequency[nums[start]]--;
                if (frequency[nums[start]] == k) {
                    charsWithFreqOverK--;
                }
                start++;
            }
        }
        return n - start;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> frequency = new HashMap();
        int start = 0;
        int charsWithFreqOverK = 0;
        
        for (int end = 0; end < n; end++) {
            frequency.put(nums[end], frequency.getOrDefault(nums[end], 0) + 1);
            if (frequency.get(nums[end]) == k + 1) { 
                charsWithFreqOverK++;
            }
            if (charsWithFreqOverK > 0) { 
                frequency.put(nums[start], frequency.get(nums[start]) - 1); 
                if (frequency.get(nums[start]) == k) { 
                    charsWithFreqOverK--; 
                }
                start++;
            }
        }
        return n - start; 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        frequency = Counter()
        start = 0
        chars_with_freq_over_k = 0
        for end in range(n):
            frequency[nums[end]] += 1
            if frequency[nums[end]] == k + 1:
                chars_with_freq_over_k += 1
            if chars_with_freq_over_k:
                frequency[nums[start]] -= 1
                if frequency[nums[start]] == k:
                    chars_with_freq_over_k -= 1
                start += 1
        return n - start
```

</details>
