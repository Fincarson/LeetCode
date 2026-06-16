# 322. Coin Change

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/coin-change/)  
`Array` `Dynamic Programming` `Breadth-First Search`

**Problem Link:** [LeetCode 322 - Coin Change](https://leetcode.com/problems/coin-change/)

## Problem

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

### Example 1

```text
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

### Example 2

```text
Input: coins = [2], amount = 3
Output: -1
```

### Example 3

```text
Input: coins = [1], amount = 0
Output: 0
```

## Constraints

- 1 <= coins.length <= 12
- 1 <= coins[i] <= 231 - 1
- 0 <= amount <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Number of Operations to Convert Time](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Cost to Split an Array](https://leetcode.com/problems/minimum-cost-to-split-an-array/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count of Sub-Multisets With Bounded Sum](https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Length of the Longest Subsequence That Sums to Target](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Coins to be Added](https://leetcode.com/problems/minimum-number-of-coins-to-be-added/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Most Expensive Item That Can Not Be Bought](https://leetcode.com/problems/most-expensive-item-that-can-not-be-bought/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Inverse Coin Change](https://leetcode.com/problems/inverse-coin-change/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 322. Coin Change

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach 1 (Brute force) [Time Limit Exceeded] | Java, Python3 |
| Approach 2 (Dynamic programming - Top down) [Accepted] | Java, Python3 |
| Approach 3 (Dynamic programming - Bottom up) [Accepted] | Java, Python3 |

## Approach 1 (Brute force) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

  public int coinChange(int[] coins, int amount) {
    return coinChange(0, coins, amount);
  }

  private int coinChange(int idxCoin, int[] coins, int amount) {
    if (amount == 0)
      return 0;
    if (idxCoin < coins.length && amount > 0) {
      int maxVal = amount/coins[idxCoin];
      int minCost = Integer.MAX_VALUE;
      for (int x = 0; x <= maxVal; x++) {
        if (amount >= x * coins[idxCoin]) {
          int res = coinChange(idxCoin + 1, coins, amount - x * coins[idxCoin]);
          if (res != -1)
            minCost = Math.min(minCost, res + x);
        }
      }
      return (minCost == Integer.MAX_VALUE)? -1: minCost;
    }
    return -1;
  }
}

// Time Limit Exceeded
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        def dfs(idx, amount):
            if amount == 0:
                return 0
            if idx < n and amount > 0:
                min_cost = float('inf')
                for x in range(0, amount // coins[idx] + 1):
                    res = dfs(idx + 1, amount-x * coins[idx])
                    if res != -1:
                        min_cost = min(min_cost, res + x)
                return -1 if min_cost == float('inf') else min_cost
            return -1

        return dfs(0, amount)

    # Time Limit Exceeded
```

</details>

<br>

## Approach 2 (Dynamic programming - Top down) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

  public int coinChange(int[] coins, int amount) {
    if (amount < 1) return 0;
    return coinChange(coins, amount, new int[amount]);
  }

  private int coinChange(int[] coins, int rem, int[] count) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (count[rem - 1] != 0) return count[rem - 1];
    int min = Integer.MAX_VALUE;
    for (int coin : coins) {
      int res = coinChange(coins, rem - coin, count);
      if (res >= 0 && res < min)
        min = 1 + res;
    }
    count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
    return count[rem - 1];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from functools import lru_cache


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        @lru_cache(None)
        def dfs(rem):
            if rem < 0:
                return -1
            if rem == 0:
                return 0
            min_cost = float('inf')
            for coin in coins:
                res = dfs(rem - coin)
                if res != -1:
                    min_cost = min(min_cost, res + 1)
            return min_cost if min_cost != float('inf') else -1

        return dfs(amount)
```

</details>

<br>

## Approach 3 (Dynamic programming - Bottom up) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
  public int coinChange(int[] coins, int amount) {
    int max = amount + 1;
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, max);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.length; j++) {
        if (coins[j] <= i) {
          dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1
```

</details>
