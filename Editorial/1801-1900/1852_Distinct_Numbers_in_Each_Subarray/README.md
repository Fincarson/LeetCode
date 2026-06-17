# 1852. Distinct Numbers in Each Subarray

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/distinct-numbers-in-each-subarray/)  
`Array` `Hash Table` `Sliding Window`

**Problem Link:** [LeetCode 1852 - Distinct Numbers in Each Subarray](https://leetcode.com/problems/distinct-numbers-in-each-subarray/)

## Problem

You are given an integer array nums of length n and an integer k. Your task is to find the number of distinct elements in every subarray of size k within nums.

Return an array ans such that ans[i] is the count of distinct elements in nums[i..(i + k - 1)] for each index 0 <= i < n - k.

### Example 1

```text
Input: nums = [1,2,3,2,2,1,3], k = 3
Output: [3,2,2,2,3]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0..2] = [1,2,3] so ans[0] = 3
- nums[1..3] = [2,3,2] so ans[1] = 2
- nums[2..4] = [3,2,2] so ans[2] = 2
- nums[3..5] = [2,2,1] so ans[3] = 2
- nums[4..6] = [2,1,3] so ans[4] = 3
```

### Example 2

```text
Input: nums = [1,1,1,1,2,3,4], k = 4
Output: [1,2,3,4]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0..3] = [1,1,1,1] so ans[0] = 1
- nums[1..4] = [1,1,1,2] so ans[1] = 2
- nums[2..5] = [1,1,2,3] so ans[2] = 3
- nums[3..6] = [1,2,3,4] so ans[3] = 4
```

## Constraints

- 1 <= k <= nums.length <= 105
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1852. Distinct Numbers in Each Subarray

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Map | C++, Java, Python3 |
| Frequency Array | C++, Java, Python3 |

## Approach 1: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> answer(len - k + 1);

        // Map to store number -> frequency count
        unordered_map<int, int> freqMap;

        // Process first window
        for (int pos = 0; pos < k; pos++) {
            freqMap[nums[pos]]++;
        }
        answer[0] = freqMap.size();

        // Slide window and update counts
        for (int pos = k; pos < len; pos++) {
            // Remove leftmost element of previous window
            int leftNum = nums[pos - k];
            freqMap[leftNum]--;
            if (freqMap[leftNum] == 0) {
                freqMap.erase(leftNum);
            }

            // Add rightmost element of current window
            int rightNum = nums[pos];
            freqMap[rightNum]++;

            // Store distinct count for current window
            answer[pos - k + 1] = freqMap.size();
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

    public int[] distinctNumbers(int[] nums, int k) {
        int len = nums.length;
        int[] answer = new int[len - k + 1];

        // Map to store number -> frequency count
        Map<Integer, Integer> freqMap = new HashMap<>();

        // Process first window
        for (int pos = 0; pos < k; pos++) {
            freqMap.put(nums[pos], freqMap.getOrDefault(nums[pos], 0) + 1);
        }
        answer[0] = freqMap.size();

        // Slide window and update counts
        for (int pos = k; pos < len; pos++) {
            // Remove leftmost element of previous window
            int leftNum = nums[pos - k];
            freqMap.put(leftNum, freqMap.get(leftNum) - 1);
            freqMap.remove(leftNum, 0);

            // Add rightmost element of current window
            int rightNum = nums[pos];
            freqMap.put(rightNum, freqMap.getOrDefault(rightNum, 0) + 1);

            // Store distinct count for current window
            answer[pos - k + 1] = freqMap.size();
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
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        len_nums = len(nums)
        answer = [0] * (len_nums - k + 1)

        # Track frequency of numbers in current window
        freq = {}

        # Process first window
        for num in nums[:k]:
            freq[num] = freq.get(num, 0) + 1
        answer[0] = len(freq)

        # Slide window and update counts
        for pos in range(k, len_nums):
            # Remove leftmost element
            left = nums[pos - k]
            freq[left] -= 1
            if freq[left] == 0:
                del freq[left]

            # Add rightmost element
            right = nums[pos]
            freq[right] = freq.get(right, 0) + 1

            answer[pos - k + 1] = len(freq)

        return answer
```

</details>

<br>

## Approach 2: Frequency Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        // Find the maximum value in the input array
        int maxValue = 0;
        for (int num : nums) {
            if (num > maxValue) {
                maxValue = num;
            }
        }

        // Create a frequency array based on the maximum value in the input
        vector<int> freq(maxValue + 1, 0);
        int distinctCount = 0;
        vector<int> answer;

        for (int pos = 0; pos < nums.size(); pos++) {
            // Add new number to window
            freq[nums[pos]]++;
            if (freq[nums[pos]] == 1) {
                distinctCount++;
            }

            // Remove number from previous window
            if (pos >= k) {
                freq[nums[pos - k]]--;
                if (freq[nums[pos - k]] == 0) {
                    distinctCount--;
                }
            }

            // Store result when window is complete
            if (pos + 1 >= k) {
                answer.push_back(distinctCount);
            }
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

    public int[] distinctNumbers(int[] nums, int k) {
        // Find the maximum value in the input array
        int maxValue = 0;
        for (int num : nums) {
            if (num > maxValue) {
                maxValue = num;
            }
        }

        // Create a frequency array based on the maximum value in the input
        int[] freq = new int[maxValue + 1];
        int distinctCount = 0;
        int[] answer = new int[nums.length - k + 1];
        int ansPos = 0;

        for (int pos = 0; pos < nums.length; pos++) {
            // Add new number to window
            freq[nums[pos]]++;
            if (freq[nums[pos]] == 1) {
                distinctCount++;
            }

            // Remove number from previous window
            if (pos >= k) {
                freq[nums[pos - k]]--;
                if (freq[nums[pos - k]] == 0) {
                    distinctCount--;
                }
            }

            // Store result when window is complete
            if (pos + 1 >= k) {
                answer[ansPos++] = distinctCount;
            }
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
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        # Find the maximum value in nums
        max_value = max(nums)

        # Create a frequency array based on the maximum value
        freq = [0] * (max_value + 1)
        distinct = 0
        answer = []

        for pos in range(len(nums)):
            # Add new number
            freq[nums[pos]] += 1
            if freq[nums[pos]] == 1:
                distinct += 1

            # Remove old number
            if pos >= k:
                freq[nums[pos - k]] -= 1
                if freq[nums[pos - k]] == 0:
                    distinct -= 1

            # Store result for complete window
            if pos + 1 >= k:
                answer.append(distinct)

        return answer
```

</details>
