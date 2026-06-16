# 518. Coin Change II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/coin-change-ii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 518 - Coin Change II](https://leetcode.com/problems/coin-change-ii/)

## Problem

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.

### Example 1

```text
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

### Example 2

```text
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
```

### Example 3

```text
Input: amount = 10, coins = [10]
Output: 1
```

## Constraints

- 1 <= coins.length <= 300
- 1 <= coins[i] <= 5000
- All the values of coins are unique.
- 0 <= amount <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Number of Ways to Earn Points](https://leetcode.com/problems/number-of-ways-to-earn-points/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count of Sub-Multisets With Bounded Sum](https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Length of the Longest Subsequence That Sums to Target](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [The Number of Ways to Make the Sum](https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Inverse Coin Change](https://leetcode.com/problems/inverse-coin-change/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 518. Coin Change II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming with Space Optimization | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> coins;
    vector<vector<int>> memo;

    int numberOfWays(int i, int amount) {
        if (amount == 0) {
            return 1;
        }
        if (i == coins.size()) {
            return 0;
        }
        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        if (coins[i] > amount) {
            return memo[i][amount] = numberOfWays(i + 1, amount);
        }

        memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount);
        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return numberOfWays(0, amount);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    int[] coins;

    public int numberOfWays(int i, int amount) {
        if (amount == 0) {
            return 1;
        }
        if (i == coins.length) {
            return 0;
        }
        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        if (coins[i] > amount) {
            return memo[i][amount] = numberOfWays(i + 1, amount);
        }

        memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount);
        return memo[i][amount];
    }

    public int change(int amount, int[] coins) {
        this.coins = coins;
        memo = new int[coins.length][amount + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return numberOfWays(0, amount);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        def numberOfWays(i: int, amount: int) -> int:
            if amount == 0:
                return 1
            if i == len(coins):
                return 0
            if memo[i][amount] != -1:
                return memo[i][amount]

            if coins[i] > amount:
                memo[i][amount] = numberOfWays(i + 1, amount)
            else:
                memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount)
            
            return memo[i][amount]

        memo = [[-1] * (amount + 1) for _ in range(len(coins))]
        return numberOfWays(0, amount)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1)); // Use long long to handle large values

        // Initialize the base case: There's one way to make amount 0, which is by not using any coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Populate the dp table.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        // Check if the final result exceeds the integer limit and return accordingly.
        return dp[0][amount] <= INT_MAX ? dp[0][amount] : -1; // Return -1 if the result exceeds the int limit
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        long[][] dp = new long[n + 1][amount + 1]; // Use long to handle large values

        // Initialize the base case: There's one way to make amount 0, which is by not using any coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Initialize the base case: There's no way to make positive amounts with zero coins.
        for (int i = 1; i <= amount; i++) {
            dp[n][i] = 0;
        }

        // Populate the dp table.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        // Check if the final result exceeds the integer limit and return accordingly.
        return dp[0][amount] <= Integer.MAX_VALUE ? (int) dp[0][amount] : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]
        for i in range(n):
            dp[i][0] = 1

        for i in range(n - 1, -1, -1):
            for j in range(1, amount + 1):
                if coins[i] > j:
                    dp[i][j] = dp[i + 1][j]
                else:
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]]

        return dp[0][amount]
```

</details>

<br>

## Approach 3: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1); // Use unsigned long long to handle large values
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]]; // This will now use unsigned long long for addition
            }
        }

        return dp[amount] <= INT_MAX ? dp[amount] : -1; // Return -1 if the result exceeds the maximum int value
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        long[] dp = new long[amount + 1]; // Use long to avoid overflow
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount] <= Integer.MAX_VALUE ? (int) dp[amount] : -1; // Return -1 if result exceeds int limit
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [0] * (amount + 1)
        dp[0] = 1

        for i in range(n - 1, -1, -1):
            for j in range(coins[i], amount + 1):
                dp[j] += dp[j - coins[i]]

        return dp[amount]
```

</details>
