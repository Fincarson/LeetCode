# 494. Target Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/target-sum/)  
`Array` `Dynamic Programming` `Backtracking`

**Problem Link:** [LeetCode 494 - Target Sum](https://leetcode.com/problems/target-sum/)

## Problem

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

- For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

### Example 1

```text
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

### Example 2

```text
Input: nums = [1], target = 1
Output: 1
```

## Constraints

- 1 <= nums.length <= 20
- 0 <= nums[i] <= 1000
- 0 <= sum(nums[i]) <= 1000
- -1000 <= target <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Ways to Express an Integer as Sum of Powers](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 494. Target Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Recursion with Memoization | C++, Java, Python3 |
| 2D Dynamic Programming | C++, Java, Python3 |
| Space Optimized | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalWays = 0;  // Tracks the total number of ways to reach the target

    int findTargetSumWays(std::vector<int>& nums, int target) {
        calculateWays(nums, 0, 0, target);
        return totalWays;
    }

private:
    void calculateWays(std::vector<int>& nums, int currentIndex, int currentSum,
                       int target) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                totalWays++;
            }
        } else {
            // Include the current number with a positive sign
            calculateWays(nums, currentIndex + 1,
                          currentSum + nums[currentIndex], target);
            // Include the current number with a negative sign
            calculateWays(nums, currentIndex + 1,
                          currentSum - nums[currentIndex], target);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    // Tracks the total number of ways to reach the target
    int totalWays = 0;

    public int findTargetSumWays(int[] nums, int target) {
        calculateWays(nums, 0, 0, target);
        return totalWays;
    }

    private void calculateWays(
        int[] nums,
        int currentIndex,
        int currentSum,
        int target
    ) {
        if (currentIndex == nums.length) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                totalWays++;
            }
        } else {
            // Include the current number with a positive sign
            calculateWays(
                nums,
                currentIndex + 1,
                currentSum + nums[currentIndex],
                target
            );
            // Include the current number with a negative sign
            calculateWays(
                nums,
                currentIndex + 1,
                currentSum - nums[currentIndex],
                target
            );
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Tracks the total number of ways to reach the target
        self.total_ways = 0

    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.calculate_ways(nums, 0, 0, target)
        return self.total_ways

    def calculate_ways(
        self, nums: List[int], current_index: int, current_sum: int, target: int
    ):
        if current_index == len(nums):
            # Check if the current sum matches the target
            if current_sum == target:
                self.total_ways += 1
        else:

            # Include the current number with a positive sign
            self.calculate_ways(
                nums,
                current_index + 1,
                current_sum + nums[current_index],
                target,
            )

            # Include the current number with a negative sign
            self.calculate_ways(
                nums,
                current_index + 1,
                current_sum - nums[current_index],
                target,
            )
```

</details>

<br>

## Approach 2: Recursion with Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
        return calculateWays(nums, 0, 0, target, memo);
    }

    int calculateWays(vector<int>& nums, int currentIndex, int currentSum,
                      int target, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            // Check if the result is already computed
            if (memo[currentIndex][currentSum + totalSum] !=
                numeric_limits<int>::min()) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add =
                calculateWays(nums, currentIndex + 1,
                              currentSum + nums[currentIndex], target, memo);

            // Calculate ways by subtracting the current number
            int subtract =
                calculateWays(nums, currentIndex + 1,
                              currentSum - nums[currentIndex], target, memo);

            // Store the result in memoization table
            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    // Sum of all elements in the array
    int totalSum;

    public int findTargetSumWays(int[] nums, int target) {
        totalSum = Arrays.stream(nums).sum();

        int[][] memo = new int[nums.length][2 * totalSum + 1];
        for (int[] row : memo) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        return calculateWays(nums, 0, 0, target, memo);
    }

    private int calculateWays(
        int[] nums,
        int currentIndex,
        int currentSum,
        int target,
        int[][] memo
    ) {
        if (currentIndex == nums.length) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            // Check if the result is already computed
            if (
                memo[currentIndex][currentSum + totalSum] != Integer.MIN_VALUE
            ) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add = calculateWays(
                nums,
                currentIndex + 1,
                currentSum + nums[currentIndex],
                target,
                memo
            );

            // Calculate ways by subtracting the current number
            int subtract = calculateWays(
                nums,
                currentIndex + 1,
                currentSum - nums[currentIndex],
                target,
                memo
            );

            // Store the result in memoization table
            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.total_sum = sum(nums)
        memo = [
            [float("-inf")] * (2 * self.total_sum + 1) for _ in range(len(nums))
        ]
        return self.calculate_ways(nums, 0, 0, target, memo)

    def calculate_ways(
        self,
        nums: List[int],
        current_index: int,
        current_sum: int,
        target: int,
        memo: List[List[int]],
    ) -> int:
        if current_index == len(nums):
            # Check if the current sum matches the target
            return 1 if current_sum == target else 0
        else:
            # Check if the result is already computed
            if memo[current_index][current_sum + self.total_sum] != float(
                "-inf"
            ):
                return memo[current_index][current_sum + self.total_sum]

            # Calculate ways by adding the current number
            add = self.calculate_ways(
                nums,
                current_index + 1,
                current_sum + nums[current_index],
                target,
                memo,
            )

            # Calculate ways by subtracting the current number
            subtract = self.calculate_ways(
                nums,
                current_index + 1,
                current_sum - nums[current_index],
                target,
                memo,
            )

            # Store the result in memoization table
            memo[current_index][current_sum + self.total_sum] = add + subtract

            return memo[current_index][current_sum + self.total_sum]
```

</details>

<br>

## Approach 3: 2D Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));

        // Initialize the first row of the DP table
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] +=
                        dp[index - 1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] +=
                        dp[index - 1][sum + totalSum];
                }
            }
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0
                                      : dp[nums.size() - 1][target + totalSum];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findTargetSumWays(int[] nums, int target) {
        int totalSum = Arrays.stream(nums).sum();
        int[][] dp = new int[nums.length][2 * totalSum + 1];

        // Initialize the first row of the DP table
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        // Fill the DP table
        for (int index = 1; index < nums.length; index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] += dp[index -
                        1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] += dp[index -
                        1][sum + totalSum];
                }
            }
        }

        // Return the result if the target is within the valid range
        return Math.abs(target) > totalSum
            ? 0
            : dp[nums.length - 1][target + totalSum];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        dp = [[0] * (2 * total_sum + 1) for _ in range(len(nums))]

        # Initialize the first row of the DP table
        dp[0][nums[0] + total_sum] = 1
        dp[0][-nums[0] + total_sum] += 1

        # Fill the DP table
        for index in range(1, len(nums)):
            for sum_val in range(-total_sum, total_sum + 1):
                if dp[index - 1][sum_val + total_sum] > 0:
                    dp[index][sum_val + nums[index] + total_sum] += dp[
                        index - 1
                    ][sum_val + total_sum]
                    dp[index][sum_val - nums[index] + total_sum] += dp[
                        index - 1
                    ][sum_val + total_sum]

        # Return the result if the target is within the valid range
        return (
            0
            if abs(target) > total_sum
            else dp[len(nums) - 1][target + total_sum]
        )
```

</details>

<br>

## Approach 4: Space Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * totalSum + 1, 0);

        // Initialize the first row of the DP table
        dp[nums[0] + totalSum] = 1;    // Adding nums[0]
        dp[-nums[0] + totalSum] += 1;  // Subtracting nums[0]

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            vector<int> next(2 * totalSum + 1, 0);
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findTargetSumWays(int[] nums, int target) {
        int totalSum = Arrays.stream(nums).sum();
        int[] dp = new int[2 * totalSum + 1];

        // Initialize the first row of the DP table
        dp[nums[0] + totalSum] = 1; // Adding nums[0]
        dp[-nums[0] + totalSum] += 1; // Subtracting nums[0]

        // Fill the DP table
        for (int index = 1; index < nums.length; index++) {
            int[] next = new int[2 * totalSum + 1];
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        // Return the result if the target is within the valid range
        return Math.abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        dp = [0] * (2 * total_sum + 1)

        # Initialize the first row of the DP table
        dp[nums[0] + total_sum] = 1  # Adding nums[0]
        dp[-nums[0] + total_sum] += 1  # Subtracting nums[0]

        # Fill the DP table
        for index in range(1, len(nums)):
            next_dp = [0] * (2 * total_sum + 1)
            for sum_val in range(-total_sum, total_sum + 1):
                if dp[sum_val + total_sum] > 0:
                    next_dp[sum_val + nums[index] + total_sum] += dp[
                        sum_val + total_sum
                    ]
                    next_dp[sum_val - nums[index] + total_sum] += dp[
                        sum_val + total_sum
                    ]
            dp = next_dp

        # Return the result if the target is within the valid range
        return 0 if abs(target) > total_sum else dp[target + total_sum]
```

</details>
