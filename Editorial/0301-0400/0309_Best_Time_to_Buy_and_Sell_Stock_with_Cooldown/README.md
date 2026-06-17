# 309. Best Time to Buy and Sell Stock with Cooldown

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 309 - Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## Problem

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example 1

```text
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

### Example 2

```text
Input: prices = [1]
Output: 0
```

## Constraints

- 1 <= prices.length <= 5000
- 0 <= prices[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 309. Best Time to Buy and Sell Stock with Cooldown

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming with State Machine | Java, Python |
| Yet-Another Dynamic Programming | Java, Python |

## Approach 1: Dynamic Programming with State Machine

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int maxProfit(int[] prices) {

    int sold = Integer.MIN_VALUE, held = Integer.MIN_VALUE, reset = 0;

    for (int price : prices) {
      int preSold = sold;

      sold = held + price;
      held = Math.max(held, reset - price);
      reset = Math.max(reset, preSold);
    }

    return Math.max(sold, reset);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        sold, held, reset = float('-inf'), float('-inf'), 0

        for price in prices:
            # Alternative: the calculation is done in parallel.
            # Therefore no need to keep temporary variables
            #sold, held, reset = held + price, max(held, reset-price), max(reset, sold)

            pre_sold = sold
            sold = held + price
            held = max(held, reset - price)
            reset = max(reset, pre_sold)

        return max(sold, reset)
```

</details>

<br>

## Approach 2: Yet-Another Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int maxProfit(int[] prices) {
    int[] MP = new int[prices.length + 2];

    for (int i = prices.length - 1; i >= 0; i--) {
      int C1 = 0;
      // Case 1). buy and sell the stock
      for (int sell = i + 1; sell < prices.length; sell++) {
        int profit = (prices[sell] - prices[i]) + MP[sell + 2];
        C1 = Math.max(profit, C1);
      }

      // Case 2). do no transaction with the stock p[i]
      int C2 = MP[i + 1];

      // wrap up the two cases
      MP[i] = Math.max(C1, C2);
    }
    return MP[0];
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        L = len(prices)
        # padding the array with additional zero to simply the logic
        MP = [0] * (L + 2)

        for i in range(L-1, -1, -1):
            C1 = 0
            # Case 1). buy and sell the stock
            for sell in range(i + 1, L):
                profit = (prices[sell] - prices[i]) + MP[sell + 2]
                C1 = max(profit, C1)

            # Case 2). do no transaction with the stock p[i]
            C2 = MP[i + 1]

            # sum up two cases
            MP[i] = max(C1, C2)

        return MP[0]
```

</details>
