# 714. Best Time to Buy and Sell Stock with Transaction Fee

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)  
`Array` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 714 - Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## Problem

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.

### Example 1

```text
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

### Example 2

```text
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

## Constraints

- 1 <= prices.length <= 5 * 104
- 1 <= prices[i] < 5 * 104
- 0 <= fee < 5 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 714. Best Time to Buy and Sell Stock with Transaction Fee

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> free(n, 0), hold(n, 0);
        
        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }
        
        return free[n - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[] free = new int[n], hold = new int[n];
        
        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = Math.max(hold[i - 1], free[i - 1] - prices[i]);
            free[i] = Math.max(free[i - 1], hold[i - 1] + prices[i] - fee);
        }
        
        return free[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        hold, free = [0] * n, [0] * n
        
        # In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0]
        
        for i in range(1, n):
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i])
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee)
        
        return free[-1]
```

</details>

<br>

## Approach 2: Space-Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int free = 0, hold = -prices[0];
        
        for (int i = 1; i < n; i++) {
            int tmp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, tmp + prices[i] - fee);
        }
        
        return free;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int free = 0, hold = -prices[0];
        
        for (int i = 1; i < n; i++) {
            int tmp = hold;
            hold = Math.max(hold, free - prices[i]);
            free = Math.max(free, tmp + prices[i] - fee);
        }
        
        return free;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        hold, free = -prices[0], 0
        
        for i in range(1, n):
            tmp = hold
            hold = max(hold, free - prices[i])
            free = max(free, tmp + prices[i] - fee)
        
        return free
```

</details>
