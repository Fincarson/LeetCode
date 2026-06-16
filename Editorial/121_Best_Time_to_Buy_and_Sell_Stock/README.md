# 121. Best Time to Buy and Sell Stock

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 121 - Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Problem

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Example 1

```text
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2

```text
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

## Constraints

- 1 <= prices.length <= 105
- 0 <= prices[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Sum of Beauty in the Array](https://leetcode.com/problems/sum-of-beauty-in-the-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock V](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 121. Best Time to Buy and Sell Stock

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Time Limit Exceeded) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int profit = prices[j] - prices[i];
            if (profit > maxprofit) maxprofit = profit;
        }
    }
    return maxprofit;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        return maxprofit;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.Length - 1; i++) {
            for (int j = i + 1; j < prices.Length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }

        return maxprofit;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProfit(prices []int) int {
    maxprofit := 0
    for i := 0; i < len(prices)-1; i++ {
        for j := i + 1; j < len(prices); j++ {
            profit := prices[j] - prices[i]
            if profit > maxprofit {
                maxprofit = profit
            }
        }
    }
    return maxprofit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxProfit(int prices[]) {
        int maxprofit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        return maxprofit;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (prices) {
    let maxprofit = 0;
    for (let i = 0; i < prices.length - 1; i++) {
        for (let j = i + 1; j < prices.length; j++) {
            let profit = prices[j] - prices[i];
            if (profit > maxprofit) maxprofit = profit;
        }
    }
    return maxprofit;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(len(prices) - 1):
            for j in range(i + 1, len(prices)):
                profit = prices[j] - prices[i]
                if profit > max_profit:
                    max_profit = profit

        return max_profit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    let maxprofit = 0;
    for (let i = 0; i < prices.length - 1; i++) {
        for (let j = i + 1; j < prices.length; j++) {
            let profit = prices[j] - prices[i];
            if (profit > maxprofit) maxprofit = profit;
        }
    }
    return maxprofit;
}
```

</details>

<br>

## Approach 2: One Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int minprice = INT_MAX;
    int maxprofit = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int minprice = int.MaxValue;
        int maxprofit = 0;
        for (int i = 0; i < prices.Length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }

        return maxprofit;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProfit(prices []int) int {
    minprice := int(^uint(0) >> 1)
    maxprofit := 0
    for i := 0; i < len(prices); i++ {
        if prices[i] < minprice {
            minprice = prices[i]
        } else if prices[i]-minprice > maxprofit {
            maxprofit = prices[i] - minprice
        }
    }
    return maxprofit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxProfit(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice) minprice = prices[i];
            else if (prices[i] - minprice > maxprofit) maxprofit = prices[i] -
            minprice;
        }
        return maxprofit;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (prices) {
    let minprice = Number.MAX_VALUE;
    let maxprofit = 0;
    for (let i = 0; i < prices.length; i++) {
        if (prices[i] < minprice) minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float("inf")
        max_profit = 0
        for i in range(len(prices)):
            if prices[i] < min_price:
                min_price = prices[i]
            elif prices[i] - min_price > max_profit:
                max_profit = prices[i] - min_price

        return max_profit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    let minprice = Number.MAX_VALUE;
    let maxprofit = 0;
    for (let i = 0; i < prices.length; i++) {
        if (prices[i] < minprice) minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}
```

</details>
