# 1770. Maximum Score from Performing Multiplication Operations

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1770 - Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)

## Problem

You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:

- Choose one integer x from either the start or the end of the array nums.
- Add multipliers[i] * x to your score.

        Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
- Remove x from nums.

Return the maximum score after performing m operations.

### Example 1

```text
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```

### Example 2

```text
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
The total score is 50 + 15 - 9 + 4 + 42 = 102.
```

## Constraints

- n == nums.length
- m == multipliers.length
- 1 <= m <= 300
- m <= n <= 105
- -1000 <= nums[i], multipliers[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Stone Game VII](https://leetcode.com/problems/stone-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Spending After Buying Items](https://leetcode.com/problems/maximum-spending-after-buying-items/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1770. Maximum Score from Performing Multiplication Operations

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C, C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, nums, multipliers):

        # Number of Operations
        m = len(multipliers)

        def helper(nums, op):
            if op == m:
                return 0

            # Returning Maximum of Two
            # In first parameter we have chosen nums[start], thus subproblem will be nums excluding nums[start]
            # In second parameter we have chosen nums[end], thus subproblem will be nums excluding nums[end]
            return max(nums[0] * multipliers[op] + helper(nums[1:], op+1),
                       nums[-1] * multipliers[op] + helper(nums[:-1], op+1))

        return helper(nums, 0)
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dp(vector<vector<int>>& memo, vector<int>& nums, vector<int>& multipliers, int op, int left) {
        // For Right Pointer
        int n = int(nums.size());
        if (op == int(multipliers.size())) {
            return 0;
        }

        // If already computed, return
        if (memo[op][left] != INT_MIN) {
            return memo[op][left];
        }

        int l = nums[left] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left + 1);
        int r = nums[(n - 1) - (op - left)] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left);

        return memo[op][left] = max(l, r);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector memo(multipliers.size() + 1, vector<int>(multipliers.size() + 1, INT_MIN));
        // Zero operation done in the beginning
        return dp(memo, nums, multipliers, 0, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int dp(Integer[][] memo, int[] nums, int[] multipliers, int op, int left) {
        // For Right Pointer
        int n = nums.length;
        if (op == multipliers.length) {
            return 0;
        }

        // If already computed, return
        if (memo[op][left] != null) {
            return memo[op][left];
        }

        int l = nums[left] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left + 1);
        int r = nums[(n - 1) - (op - left)] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left);

        return memo[op][left] = Math.max(l, r);
    }

    public int maximumScore(int[] nums, int[] multipliers) {
        Integer[][] memo = new Integer[multipliers.length + 1][multipliers.length + 1];
        // Zero operation done in the beginning
        return dp(memo, nums, multipliers, 0, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:

        # Number of Operations
        m = len(multipliers)

        # For Right Pointer
        n = len(nums)

        memo = {}

        def dp(op, left):
            if op == m:
                return 0

            # If already computed, return
            if (op, left) in memo:
                return memo[(op, left)]

            l = nums[left] * multipliers[op] + dp(op+1, left+1)
            r = nums[(n-1)-(op-left)] * multipliers[op] + dp(op+1, left)

            memo[(op, left)] = max(l, r)

            return memo[(op, left)]

        # Zero operation done in the beginning
        return dp(0, 0)
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // For Right Pointer
        int n = int(nums.size());
        // Number of Operations
        int m = int(multipliers.size());
        vector dp(m + 1, vector<int>(m + 1, 0));
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left]);
            }
        }
        
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        // For Right Pointer
        int n = nums.length;
        // Number of Operations
        int m = multipliers.length;
        int[][] dp = new int[m + 1][m + 1];
        
        for (int i = 0; i <= m; i++)
            Arrays.fill(dp[i], 0);
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                dp[op][left] = Math.max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left]);
            }
        }
        
        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:

        # Number of Operations
        m = len(multipliers)

        # For Right Pointer
        n = len(nums)

        dp = [[0] * (m + 1) for _ in range(m + 1)]

        for op in range(m - 1, -1, -1):
            for left in range(op, -1, -1):

                dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left])

        return dp[0][0]
```

</details>

<br>

## Approach 4: Space-Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return a > b ? a : b; }

int maximumScore(int *nums, int numsSize, int *multipliers, int multipliersSize) {
    // For Right Pointer
    int n = numsSize;
    // Number of Operations
    int m = multipliersSize;
    int dp[m + 1];
    for (int i = 0; i <= m; i++) dp[i] = 0;
    
    for (int op = m - 1; op >= 0; op--) {
        for (int left = 0; left <= op; left++) {
            dp[left] = max(multipliers[op] * nums[left] + dp[left + 1],
                           multipliers[op] * nums[n - 1 - (op - left)] + dp[left]);
        }
    }
    return dp[0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // For Right Pointer
        int n = int(nums.size());
        // Number of Operations
        int m = int(multipliers.size());
        vector<int> dp(m + 1, 0);
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = 0; left <= op; left++) {
                dp[left] = max(multipliers[op] * nums[left] + dp[left + 1],
                               multipliers[op] * nums[n - 1 - (op - left)] + dp[left]);
            }
        }
        
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maximumScore(int[] nums, int[] multipliers) {
        // For Right Pointer
        int n = nums.length;
        // Number of Operations
        int m = multipliers.length;
        int[] dp = new int[m + 1];
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = 0; left <= op; left++) {
                dp[left] = Math.max(multipliers[op] * nums[left] + dp[left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[left]);
            }
        }
        
        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:

        m = len(multipliers)
        n = len(nums)

        dp = [0] * (m + 1)

        for op in range(m - 1, -1, -1):
            for left in range(0, op+1, 1):
                dp[left] = max(multipliers[op] * nums[left] + dp[left + 1],
                               multipliers[op] * nums[n - 1 - (op - left)] + dp[left])

        return dp[0]
```

</details>
