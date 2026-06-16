# 945. Minimum Increment to Make Array Unique

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)  
`Array` `Greedy` `Sorting` `Counting`

**Problem Link:** [LeetCode 945 - Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)

## Problem

You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

### Example 1

```text
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
```

### Example 2

```text
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Product After K Increments](https://leetcode.com/problems/maximum-product-after-k-increments/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Operations to Make Elements in Array Distinct](https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 945. Minimum Increment to Make Array Unique

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Counting | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minIncrements = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            // Ensure each element is greater than its previous
            if (nums[i] <= nums[i - 1]) {
                // Add the required increment to minIncrements
                int increment = nums[i - 1] + 1 - nums[i];
                minIncrements += increment;

                // Set the element to be greater than its previous
                nums[i] = nums[i - 1] + 1;
            }
        }

        return minIncrements;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minIncrementForUnique(int[] nums) {
        int minIncrements = 0;

        Arrays.sort(nums);

        for (int i = 1; i < nums.length; i++) {
            // Ensure each element is greater than its previous
            if (nums[i] <= nums[i - 1]) {
                // Add the required increment to minIncrements
                int increment = nums[i - 1] + 1 - nums[i];
                minIncrements += increment;

                // Set the element to be greater than its previous
                nums[i] = nums[i - 1] + 1;
            }
        }

        return minIncrements;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        min_increments = 0

        nums.sort()

        for i in range(1, len(nums)):
            # Ensure each element is greater than its previous
            if nums[i] <= nums[i - 1]:
                # Add the required increment to minIncrements
                increment = nums[i - 1] + 1 - nums[i]
                min_increments += increment

                # Set the element to be greater than its previous
                nums[i] = nums[i - 1] + 1

        return min_increments
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        int minIncrements = 0;

        // Find maximum value in nums using a loop
        for (int val : nums) {
            max_val = max(max_val, val);
        }

        // Create a frequencyCount vector to store the frequency of each value
        // in nums
        vector<int> frequencyCount(n + max_val, 0);

        // Populate frequencyCount vector with the frequency of each value in
        // nums
        for (int val : nums) {
            frequencyCount[val]++;
        }

        // Iterate over the frequencyCount vector to make all values unique
        for (int i = 0; i < frequencyCount.size(); i++) {
            if (frequencyCount[i] <= 1) continue;

            // Determine excess occurrences, carry them over to the next value,
            // ensure single occurrence for current value, and update
            // minIncrements.
            int duplicates = frequencyCount[i] - 1;
            frequencyCount[i + 1] += duplicates;
            frequencyCount[i] = 1;
            minIncrements += duplicates;
        }

        return minIncrements;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minIncrementForUnique(int[] nums) {
        int n = nums.length;
        int max = 0;
        int minIncrements = 0;

        // Find maximum value in array to determine range of frequencyCount array
        for (int val : nums) {
            max = Math.max(max, val);
        }

        // Create a frequencyCount array to store the frequency of each value in nums
        int[] frequencyCount = new int[n + max];

        // Populate frequencyCount array with the frequency of each value in nums
        for (int val : nums) {
            frequencyCount[val]++;
        }

        // Iterate over the frequencyCount array to make all values unique
        for (int i = 0; i < frequencyCount.length; i++) {
            if (frequencyCount[i] <= 1) continue;

            // Determine excess occurrences, carry them over to the next value,
            // ensure single occurrence for current value, and update minIncrements.
            int duplicates = frequencyCount[i] - 1;
            frequencyCount[i + 1] += duplicates;
            frequencyCount[i] = 1;
            minIncrements += duplicates;
        }

        return minIncrements;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        n = len(nums)
        max_val = max(nums)
        min_increments = 0

        # Create a frequencyCount array to store the frequency of each value in nums
        frequency_count = [0] * (n + max_val)

        # Populate frequencyCount array with the frequency of each value in nums
        for val in nums:
            frequency_count[val] += 1

        # Iterate over the frequencyCount array to make all values unique
        for i in range(len(frequency_count)):
            if frequency_count[i] <= 1:
                continue

            # Determine excess occurrences, carry them over to the next value,
            # ensure single occurrence for current value, and update min_increments.
            duplicates = frequency_count[i] - 1
            frequency_count[i + 1] += duplicates
            frequency_count[i] = 1
            min_increments += duplicates

        return min_increments
```

</details>
