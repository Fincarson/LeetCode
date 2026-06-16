# 2275. Largest Combination With Bitwise AND Greater Than Zero

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/)  
`Array` `Hash Table` `Bit Manipulation` `Counting`

**Problem Link:** [LeetCode 2275 - Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/)

## Problem

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

- For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
- Also, for nums = [7], the bitwise AND is 7.

You are given an array of positive integers candidates. Compute the bitwise AND for all possible combinations of elements in the candidates array.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

### Example 1

```text
Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
```

### Example 2

```text
Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.
```

## Constraints

- 1 <= candidates.length <= 105
- 1 <= candidates[i] <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2275. Largest Combination With Bitwise AND Greater Than Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using a Bit Count Array | C++, Java, Python3 |
| Direct Maximum Bit Count | C++, Java, Python3 |

## Approach 1: Using a Bit Count Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // Initialize a vector to store the count of each bit position.
        vector<int> bitCount(24, 0);
        for (int i = 0; i < 24; i++) {
            for (int num : candidates) {
                // Check if the i-th bit is set.
                if ((num & (1 << i)) != 0) {
                    bitCount[i]++;
                }
            }
        }
        // Return the maximum count.
        return *max_element(bitCount.begin(), bitCount.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int largestCombination(int[] candidates) {
        // Initialize an array to store the count of each bit position.
        int[] bitCount = new int[24];
        for (int i = 0; i < 24; i++) {
            for (int num : candidates) {
                // Check if the i-th bit is set.
                if ((num & (1 << i)) != 0) {
                    bitCount[i]++;
                }
            }
        }
        // Return the maximum count.
        int max = 0;
        for (int count : bitCount) {
            if (count > max) {
                max = count;
            }
        }
        return max;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        # Initialize a list to store the count of each bit position.
        bit_count = [0] * 24
        for i in range(24):
            for num in candidates:
                # Check if the i-th bit is set.
                if (num & (1 << i)) != 0:
                    bit_count[i] += 1

        return max(bit_count)
```

</details>

<br>

## Approach 2: Direct Maximum Bit Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;  // Variable to track the maximum count of set bits.
        for (int i = 0; i < 24; i++) {
            int count = 0;  // Count of numbers with the i-th bit set.
            for (int num : candidates) {
                if ((num & (1 << i)) != 0) {  // Check if the i-th bit is set.
                    count++;
                }
            }
            maxCount = max(maxCount, count);  // Update the maximum count.
        }
        return maxCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int largestCombination(int[] candidates) {
        int maxCount = 0; // Variable to track the maximum count of set bits.
        for (int i = 0; i < 24; i++) {
            int count = 0; // Count of numbers with the i-th bit set.
            for (int num : candidates) {
                if ((num & (1 << i)) != 0) { // Check if the i-th bit is set.
                    count++;
                }
            }
            maxCount = Math.max(maxCount, count); // Update the maximum count.
        }
        return maxCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestCombination(self, candidates):
        max_count = 0  # Variable to track the maximum count of set bits.
        for i in range(24):
            count = 0  # Count of numbers with the i-th bit set.
            for num in candidates:
                if (num & (1 << i)) != 0:  # Check if the i-th bit is set.
                    count += 1
            max_count = max(max_count, count)  # Update the maximum count.
        return max_count
```

</details>
