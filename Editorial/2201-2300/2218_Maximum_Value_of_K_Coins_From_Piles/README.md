# 2218. Maximum Value of K Coins From Piles

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/)  
`Array` `Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 2218 - Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/)

## Problem

There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

### Example 1

```text
Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
```

### Example 2

```text
Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.
```

## Constraints

- n == piles.length
- 1 <= n <= 1000
- 1 <= piles[i][j] <= 105
- 1 <= k <= sum(piles[i].length) <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Coin Change](https://leetcode.com/problems/coin-change/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Coin Change II](https://leetcode.com/problems/coin-change-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2218. Maximum Value of K Coins From Piles

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Top-Down Dynamic Programming (Memoization) | C++ |

## Approach 1: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            for (int coins = 0; coins <= k; coins++) {
                int currentSum = 0;
                for (int currentCoins = 0; currentCoins <= min((int)piles[i - 1].size(), coins); currentCoins++) {
                    if (currentCoins > 0) {
                        currentSum += piles[i - 1][currentCoins - 1];
                    }
                    dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - currentCoins] + currentSum);
                }
            }
        }
        return dp[n][k];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        int dp[][] = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int coins = 0; coins <= k; coins++) {
                int currentSum = 0;
                for (int currentCoins = 0; currentCoins <= Math.min((int)piles.get(i - 1).size(), coins); currentCoins++) {
                    if (currentCoins > 0) {
                        currentSum += piles.get(i - 1).get(currentCoins - 1);
                    }
                    dp[i][coins] = Math.max(dp[i][coins], dp[i - 1][coins - currentCoins] + currentSum);
                }
            }
        }
        return dp[n][k];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        dp = [[0] * (k + 1) for i in range(n + 1)]
        for i in range(1, n + 1):
            for coins in range(0, k + 1):
                current_sum = 0
                for current_coins in range(0, min(len(piles[i - 1]), coins) + 1):
                    if current_coins > 0:
                        current_sum += piles[i - 1][current_coins - 1]
                    dp[i][coins] = max(dp[i][coins],
                                       dp[i - 1][coins - current_coins] + current_sum)
        return dp[n][k]
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        function<int(int, int)> f = [&](int i, int coins) {
            if (i == 0) {
                return 0;
            }
            int result = 0, currentSum = 0;
            for (int currentCoins = 0; currentCoins <= min((int)piles[i - 1].size(), coins); currentCoins++) {
                if (currentCoins > 0) {
                    currentSum += piles[i - 1][currentCoins - 1];
                }
                result = max(result, f(i - 1, coins - currentCoins) + currentSum);
            }
            return result;
        };
        return f(n, k);
    }
};
```

</details>
