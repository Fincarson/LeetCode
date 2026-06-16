# 3005. Count Elements With Maximum Frequency

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-elements-with-maximum-frequency/)  
`Array` `Hash Table` `Counting`

**Problem Link:** [LeetCode 3005 - Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/)

## Problem

You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

### Example 1

```text
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
```

### Example 2

```text
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
```

## Constraints

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Frequency of an Element After Performing Operations I](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Frequency of an Element After Performing Operations II](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Difference Between Even and Odd Frequency II](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3005. Count Elements With Maximum Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Frequency and Max Frequency | C++, Java, Python3 |
| Sort Frequencies and Sum Max Frequencies | C++, Java, Python3 |
| One-Pass Sum Max Frequencies | C++, Java, Python3 |

## Approach 1: Count Frequency and Max Frequency

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Find the frequency of each element
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }

        // Determine the maximum frequency
        int maxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            maxFrequency = max(maxFrequency, frequency);
        }

        // Calculate the total frequencies of elements with the maximum frequency
        int frequencyOfMaxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            if (frequency == maxFrequency) {
                frequencyOfMaxFrequency++;
            }
        }
        return frequencyOfMaxFrequency * maxFrequency;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxFrequencyElements(int[] nums) {
        // Find the frequency of each element
        Map<Integer, Integer> frequencies = new HashMap<>();
        for (int num : nums) {
            frequencies.put(num, frequencies.getOrDefault(num, 0) + 1);
        }

        // Determine the maximum frequency
        int maxFrequency = 0;
        for (int frequency : frequencies.values()) {
            maxFrequency = Math.max(maxFrequency, frequency);
        }

        // Calculate the total frequencies of elements with the maximum frequency
        int frequencyOfMaxFrequency = 0;
        for (int frequency : frequencies.values()) {
            if (frequency == maxFrequency) {
                frequencyOfMaxFrequency++;
            }
        }
        return frequencyOfMaxFrequency * maxFrequency;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        # Find the frequency of each element
        frequencies = {}
        for num in nums:
            if num in frequencies:
                frequencies[num] += 1
            else:
                frequencies[num] = 1

        # Determine the maximum frequency
        max_frequency = 0
        for frequency in frequencies.values():
            max_frequency = max(max_frequency, frequency)

        # Calculate the total frequencies of elements with the maximum frequency
        frequency_of_max_frequency = 0
        for frequency in frequencies.values():
            if frequency == max_frequency:
                frequency_of_max_frequency += 1

        return frequency_of_max_frequency * max_frequency
```

</details>

<br>

## Approach 2: Sort Frequencies and Sum Max Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Find the frequency of each element
        vector<int> frequencies(100, 0);
        for (int num : nums) {
            frequencies[num - 1]++;
        }

        // Determine the maximum frequency, stored in the last index of the sorted array
        sort(frequencies.begin(), frequencies.end());
        int maxFreqIndex = frequencies.size() - 1;
        int totalFrequencies = frequencies[maxFreqIndex];

        // Calculate the total frequencies of elements with the maximum frequency
        // Start from the last index and iterate right to left
        while (maxFreqIndex > 0 && frequencies[maxFreqIndex] == frequencies[maxFreqIndex - 1]) {
            totalFrequencies += frequencies[maxFreqIndex];
            maxFreqIndex--;
        }
        return totalFrequencies;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxFrequencyElements(int[] nums) {
        // Find the frequency of each element
        int[] frequencies = new int[100];
        for (int num : nums) {
            frequencies[num - 1]++;
        }

        // Determine the maximum frequency, stored in the last index of the sorted array
        Arrays.sort(frequencies);
        int maxFreqIndex = frequencies.length - 1;
        int totalFrequencies = frequencies[maxFreqIndex];

        // Calculate the total frequencies of elements with the maximum frequency
        // Start from the last index and iterate right to left
        while (maxFreqIndex > 0 && frequencies[maxFreqIndex] == frequencies[maxFreqIndex - 1]) {
            totalFrequencies += frequencies[maxFreqIndex];
            maxFreqIndex--;
        }
        return totalFrequencies;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFrequencyElements(self, nums):
        # Find the frequency of each element
        frequencies = [0] * 100
        for num in nums:
            frequencies[num - 1] += 1

        # Determine the maximum frequency, stored in the last index of the sorted array
        frequencies.sort()
        max_freq_index = len(frequencies) - 1
        total_frequencies = frequencies[max_freq_index]

        # Calculate the total frequencies of elements with the maximum frequency
        # Start from the last index and iterate right to left
        while max_freq_index > 0 and frequencies[max_freq_index] == frequencies[max_freq_index - 1]:
            total_frequencies += frequencies[max_freq_index]
            max_freq_index -= 1
        return total_frequencies
```

</details>

<br>

## Approach 3: One-Pass Sum Max Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        int maxFrequency = 0;
        int totalFrequencies = 0;

        // Find the frequency of each element
        // Determine the maximum frequency
        // Calculate the total frequencies of elements with the maximum frequency
        for (int num : nums) {
            frequencies[num]++;
            int frequency = frequencies[num];

            // If we discover a higher frequency element
            // Update maxFrequency
            // Re-set totalFrequencies to the new max frequency
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                totalFrequencies = frequency;
                // If we find an element with the max frequency, add it to the total
            } else if (frequency == maxFrequency) {
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> frequencies = new HashMap<>();
        int maxFrequency = 0;
        int totalFrequencies = 0;

        // Find the frequency of each element
        // Determine the maximum frequency
        // Calculate the total frequencies of elements with the maximum frequency
        for (int num : nums) {
            frequencies.put(num, frequencies.getOrDefault(num, 0) + 1);
            int frequency = frequencies.get(num);

            // If we discover a higher frequency element
            // Update maxFrequency
            // Re-set totalFrequencies to the new max frequency
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                totalFrequencies = frequency;
                // If we find an element with the max frequency, add it to the total
            } else if (frequency == maxFrequency) {
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxFrequencyElements(self, nums):
        frequencies = {}
        max_frequency = 0
        total_frequencies = 0

        # Find the frequency of each element
        # Determine the maximum frequency
        # Calculate the total frequencies of elements with the maximum frequency
        for num in nums:
            frequencies[num] = frequencies.get(num, 0) + 1
            frequency = frequencies[num]

            # If we discover a higher frequency element
            # Update max_frequency
            # Re-set totalFrequencies to the new max frequency
            if frequency > max_frequency:
                max_frequency = frequency
                total_frequencies = frequency
            # If we find an element with the max frequency, add it to the total
            elif frequency == max_frequency:
                total_frequencies += frequency

        return total_frequencies
```

</details>
