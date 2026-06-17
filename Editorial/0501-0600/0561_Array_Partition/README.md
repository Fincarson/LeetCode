# 561. Array Partition

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/array-partition/)  
`Array` `Greedy` `Sorting` `Counting Sort`

**Problem Link:** [LeetCode 561 - Array Partition](https://leetcode.com/problems/array-partition/)

## Problem

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

### Example 1

```text
Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
```

### Example 2

```text
Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
```

## Constraints

- 1 <= n <= 104
- nums.length == 2 * n
- -104 <= nums[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [All Divisions With the Highest Score of a Binary Array](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 561. Array Partition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Counting Sort | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Sort the list in ascending order
        sort(nums.begin(), nums.end());
        // Initialize sum to zero
        int maxSum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            // Add every element at even positions (0-indexed)
            maxSum += nums[i];
        }
        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        // Sort the list in ascending order
        Arrays.sort(nums);
        // Initialize sum to zero
        int maxSum = 0;
        for (int i = 0; i < nums.length; i += 2) {
            // Add every element at even positions (0-indexed)
            maxSum += nums[i];
        }
        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        # Sort the list in ascending order
        nums.sort()
        # Initialize sum to zero
        max_sum = 0
        for i in range(0, len(nums), 2):
            # Add every element at even positions (0-indexed)
            max_sum += nums[i]
            
        return max_sum
```

</details>

<br>

## Approach 2: Counting Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const static int K = 10000;
        
    int arrayPairSum(vector<int>& nums) {
        // Store the frequency of each element
        int elementToCount[2 * K + 1] = {0};
        for (int element : nums) {
            // Add K to element to offset negative values
            elementToCount[element + K]++;
        }
        
        // Initialize sum to zero
        int maxSum = 0;
        bool isEvenIndex = true;
        for (int element = 0; element <= 2 * K; element++) {
            while (elementToCount[element]) {
                // Add element if it is at even position
                maxSum += (isEvenIndex ? element - K : 0);
                // Flip the value (one to zero or zero to one)
                isEvenIndex = !isEvenIndex;
                // Decrement the frequency count
                elementToCount[element]--;
            }
        }
        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    final static int K = 10000;
    
    public int arrayPairSum(int[] nums) {
        // Store the frequency of each element
        int[] elementToCount = new int[2 * K + 1];
        for (int element : nums) {
            // Add K to element to offset negative values
            elementToCount[element + K]++;
        }
        
        // Initialize sum to zero
        int maxSum = 0;
        boolean isEvenIndex = true;
        for (int element = 0; element <= 2 * K; element++) {
            while (elementToCount[element] > 0) {
                // Add element if it is at even position
                maxSum += (isEvenIndex ? element - K : 0);
                // Flip the value (one to zero or zero to one)
                isEvenIndex = !isEvenIndex;
                // Decrement the frequency count
                elementToCount[element]--;
            }
        }
        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        K = 10000
        # Store the frequency of each element
        element_to_count = [0] * (2 * K + 1)
        for element in nums:
            # Add K to element to offset negative values
            element_to_count[element + K] += 1
            
        # Initialize sum to zero
        max_sum = 0
        is_even_index = True
        for element in range(2 * K + 1):
            while element_to_count[element] > 0 :
                # Add element if it is at even index
                if is_even_index:
                    max_sum += element - K
                # Flip the value (one to zero or zero to one)
                is_even_index = not is_even_index;
                # Decrement the frequency count
                element_to_count[element] -= 1
        return max_sum
```

</details>
