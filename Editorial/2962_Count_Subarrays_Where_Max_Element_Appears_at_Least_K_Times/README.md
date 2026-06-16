# 2962. Count Subarrays Where Max Element Appears at Least K Times

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)  
`Array` `Sliding Window`

**Problem Link:** [LeetCode 2962 - Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)

## Problem

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

### Example 1

```text
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
```

### Example 2

```text
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Number of Subarrays Where Boundary Elements Are Maximum](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2962. Count Subarrays Where Max Element Appears at Least K Times

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sliding Window | C++, Java, Python3 |
| Track Indexes of Max Element | C++, Java, Python3 |

## Approach 1: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0, start = 0;
        int maxElementsInWindow = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == maxElement) {
                maxElementsInWindow++;
            }
            while (maxElementsInWindow == k) {
                if (nums[start] == maxElement) {
                    maxElementsInWindow--;
                }
                start++;
            }
            ans += start;
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

    public long countSubarrays(int[] nums, int k) {
        int maxElement = Arrays.stream(nums).max().getAsInt();
        long ans = 0, start = 0;
        int maxElementsInWindow = 0;

        for (int end = 0; end < nums.length; end++) {
            if (nums[end] == maxElement) {
                maxElementsInWindow++;
            }
            while (maxElementsInWindow == k) {
                if (nums[(int) start] == maxElement) {
                    maxElementsInWindow--;
                }
                start++;
            }
            ans += start;
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
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element = max(nums)
        ans = start = max_elements_in_window = 0

        for end in range(len(nums)):
            if nums[end] == max_element:
                max_elements_in_window += 1
            while max_elements_in_window == k:
                if nums[start] == max_element:
                    max_elements_in_window -= 1
                start += 1
            ans += start
        return ans
```

</details>

<br>

## Approach 2: Track Indexes of Max Element

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> indexesOfMaxElements;
        long long ans = 0;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == maxElement) {
                indexesOfMaxElements.push_back(index);
            }

            int freq = indexesOfMaxElements.size();
            if (freq >= k) {
                ans += indexesOfMaxElements[freq - k] + 1;
            }
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

    public long countSubarrays(int[] nums, int k) {
        // Finding the maximum element in the array

        int maxElement = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
            }
        }

        ArrayList<Integer> indexesOfMaxElements = new ArrayList<>();
        long ans = 0;

        // Iterating through the array

        for (int index = 0; index < nums.length; index++) {
            if (nums[index] == maxElement) {
                indexesOfMaxElements.add(index);
            }

            int freq = indexesOfMaxElements.size();
            if (freq >= k) {
                ans += indexesOfMaxElements.get(freq - k) + 1;
            }
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
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element = max(nums)
        indexes_of_max_elements = []
        ans = 0

        for index, element in enumerate(nums):

            if element == max_element:
                indexes_of_max_elements.append(index)

            freq = len(indexes_of_max_elements)
            if freq >= k:
                ans += indexes_of_max_elements[-k] + 1

        return ans
```

</details>
