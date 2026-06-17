# 2044. Count Number of Maximum Bitwise-OR Subsets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)  
`Array` `Backtracking` `Bit Manipulation` `Enumeration`

**Problem Link:** [LeetCode 2044 - Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)

## Problem

Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

### Example 1

```text
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
```

### Example 2

```text
Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
```

### Example 3

```text
Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
```

## Constraints

- 1 <= nums.length <= 16
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsets](https://leetcode.com/problems/subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Largest Combination With Bitwise AND Greater Than Zero](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2044. Count Number of Maximum Bitwise-OR Subsets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |
| Bit Manipulation + Dynamic Programming | C++, Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }
        return countSubsets(nums, 0, 0, maxOrValue);
    }

private:
    int countSubsets(vector<int>& nums, int index, int currentOr,
                     int targetOr) {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Don't include the current number
        int countWithout = countSubsets(nums, index + 1, currentOr, targetOr);

        // Include the current number
        int countWith =
            countSubsets(nums, index + 1, currentOr | nums[index], targetOr);

        // Return the sum of both cases
        return countWithout + countWith;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countMaxOrSubsets(int[] nums) {
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }
        return countSubsets(nums, 0, 0, maxOrValue);
    }

    private int countSubsets(
        int[] nums,
        int index,
        int currentOr,
        int targetOr
    ) {
        // Base case: reached the end of the array
        if (index == nums.length) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Don't include the current number
        int countWithout = countSubsets(nums, index + 1, currentOr, targetOr);

        // Include the current number
        int countWith = countSubsets(
            nums,
            index + 1,
            currentOr | nums[index],
            targetOr
        );

        // Return the sum of both cases
        return countWithout + countWith;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_value = 0
        for num in nums:
            max_or_value |= num
        return self._count_subsets(nums, 0, 0, max_or_value)

    def _count_subsets(
        self, nums: List[int], index: int, current_or: int, target_or: int
    ) -> int:
        # Base case: reached the end of the array
        if index == len(nums):
            return 1 if current_or == target_or else 0

        # Don't include the current number
        count_without = self._count_subsets(
            nums, index + 1, current_or, target_or
        )

        # Include the current number
        count_with = self._count_subsets(
            nums, index + 1, current_or | nums[index], target_or
        )

        # Return the sum of both cases
        return count_without + count_with
```

</details>

<br>

## Approach 2: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOrValue = 0;

        // Calculate the maximum OR value
        for (int num : nums) {
            maxOrValue |= num;
        }

        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));

        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
    }

private:
    int countSubsetsRecursive(vector<int>& nums, int index, int currentOr,
                              int targetOr, vector<vector<int>>& memo) {
        // Base case: reached the end of the array
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Check if the result for this state is already memoized
        if (memo[index][currentOr] != -1) {
            return memo[index][currentOr];
        }

        // Don't include the current number
        int countWithout =
            countSubsetsRecursive(nums, index + 1, currentOr, targetOr, memo);

        // Include the current number
        int countWith = countSubsetsRecursive(
            nums, index + 1, currentOr | nums[index], targetOr, memo);

        // Memoize and return the result
        return memo[index][currentOr] = countWithout + countWith;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int maxOrValue = 0;

        // Calculate the maximum OR value
        for (int num : nums) {
            maxOrValue |= num;
        }

        Integer[][] memo = new Integer[n][maxOrValue + 1];

        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
    }

    private int countSubsetsRecursive(
        int[] nums,
        int index,
        int currentOr,
        int targetOr,
        Integer[][] memo
    ) {
        // Base case: reached the end of the array
        if (index == nums.length) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        // Check if the result for this state is already memoized
        if (memo[index][currentOr] != null) {
            return memo[index][currentOr];
        }

        // Don't include the current number
        int countWithout = countSubsetsRecursive(
            nums,
            index + 1,
            currentOr,
            targetOr,
            memo
        );

        // Include the current number
        int countWith = countSubsetsRecursive(
            nums,
            index + 1,
            currentOr | nums[index],
            targetOr,
            memo
        );

        // Memoize and return the result
        return memo[index][currentOr] = countWithout + countWith;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_value = 0
        n = len(nums)

        # Calculate the maximum OR value
        for num in nums:
            max_or_value |= num

        # Initialize memo with -1
        memo = [[-1] * (max_or_value + 1) for _ in range(n)]

        return self._count_subsets_recursive(nums, 0, 0, max_or_value, memo)

    def _count_subsets_recursive(
        self,
        nums: List[int],
        index: int,
        current_or: int,
        target_or: int,
        memo: List[List[int]],
    ) -> int:
        # Base case: reached the end of the array
        if index == len(nums):
            return 1 if current_or == target_or else 0

        # Check if the result for this state is already memoized
        if memo[index][current_or] != -1:
            return memo[index][current_or]

        # Don't include the current number
        count_without = self._count_subsets_recursive(
            nums, index + 1, current_or, target_or, memo
        )

        # Include the current number
        count_with = self._count_subsets_recursive(
            nums, index + 1, current_or | nums[index], target_or, memo
        )

        # Memoize and return the result
        memo[index][current_or] = count_without + count_with
        return memo[index][current_or]
```

</details>

<br>

## Approach 3: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Calculate the maximum possible OR value
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }

        int totalSubsets = 1 << nums.size();  // 2^n subsets
        int subsetsWithMaxOr = 0;

        // Iterate through all possible subsets
        for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++) {
            int currentOrValue = 0;

            // Calculate OR value for the current subset
            for (int i = 0; i < nums.size(); i++) {
                if (((subsetMask >> i) & 1) == 1) {
                    currentOrValue |= nums[i];
                }
            }

            // If current subset's OR equals maxOrValue, increment count
            if (currentOrValue == maxOrValue) {
                subsetsWithMaxOr++;
            }
        }

        return subsetsWithMaxOr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countMaxOrSubsets(int[] nums) {
        // Calculate the maximum possible OR value
        int maxOrValue = 0;
        for (int num : nums) {
            maxOrValue |= num;
        }

        int totalSubsets = 1 << nums.length; // 2^n subsets
        int subsetsWithMaxOr = 0;

        // Iterate through all possible subsets
        for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++) {
            int currentOrValue = 0;

            // Calculate OR value for the current subset
            for (int i = 0; i < nums.length; i++) {
                if (((subsetMask >> i) & 1) == 1) {
                    currentOrValue |= nums[i];
                }
            }

            // If current subset's OR equals maxOrValue, increment count
            if (currentOrValue == maxOrValue) {
                subsetsWithMaxOr++;
            }
        }

        return subsetsWithMaxOr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        # Calculate the maximum possible OR value
        max_or_value = 0
        for num in nums:
            max_or_value |= num

        total_subsets = 1 << len(nums)  # 2^n subsets
        subsets_with_max_or = 0

        # Iterate through all possible subsets
        for subset_mask in range(total_subsets):
            current_or_value = 0

            # Calculate OR value for the current subset
            for i in range(len(nums)):
                if (subset_mask >> i) & 1:
                    current_or_value |= nums[i]

            # If current subset's OR equals max_or_value, increment count
            if current_or_value == max_or_value:
                subsets_with_max_or += 1

        return subsets_with_max_or
```

</details>

<br>

## Approach 4: Bit Manipulation + Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        vector<int> dp(1 << 17, 0);

        // Initialize the empty subset
        dp[0] = 1;

        // Iterate through each number in the input array
        for (int num : nums) {
            for (int i = max; i >= 0; i--) {
                // For each existing subset, create a new subset by including
                // the current number
                dp[i | num] += dp[i];
            }
            // Update the maximum OR value
            max |= num;
        }

        return dp[max];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countMaxOrSubsets(int[] nums) {
        int max = 0;
        int[] dp = new int[1 << 17];

        // Initialize the empty subset
        dp[0] = 1;

        // Iterate through each number in the input array
        for (int num : nums) {
            for (int i = max; i >= 0; i--) {
                // For each existing subset, create a new subset by including the current number
                dp[i | num] += dp[i];
            }
            // Update the maximum OR value
            max |= num;
        }

        return dp[max];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        max_or_value = 0
        dp = [0] * (1 << 17)

        # Initialize the empty subset
        dp[0] = 1

        # Iterate through each number in the input array
        for num in nums:
            for i in range(max_or_value, -1, -1):
                # For each existing subset, create a new subset by including the current number
                dp[i | num] += dp[i]

            # Update the maximum OR value
            max_or_value |= num

        return dp[max_or_value]
```

</details>
