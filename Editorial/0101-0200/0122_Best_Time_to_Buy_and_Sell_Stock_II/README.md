# 122. Best Time to Buy and Sell Stock II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)  
`Array` `Dynamic Programming` `Greedy`

**Problem Link:** [LeetCode 122 - Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Problem

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

### Example 1

```text
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

### Example 2

```text
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

### Example 3

```text
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

## Constraints

- 1 <= prices.length <= 3 * 104
- 0 <= prices[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 122. Best Time to Buy and Sell Stock II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Peak Valley Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Simple One Pass | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int calculate(int* prices, int pricesSize, int s);
int maxProfit(int* prices, int pricesSize) {
    return calculate(prices, pricesSize, 0);
}
int calculate(int* prices, int pricesSize, int s) {
    if (s >= pricesSize) return 0;
    int max = 0;
    for (int start = s; start < pricesSize; start++) {
        int maxprofit = 0;
        for (int i = start + 1; i < pricesSize; i++) {
            if (prices[start] < prices[i]) {
                int profit = calculate(prices, pricesSize, i + 1) + prices[i] -
                             prices[start];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        if (maxprofit > max) max = maxprofit;
    }
    return max;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) { return calculate(prices, 0); }

private:
    int calculate(vector<int>& prices, int s) {
        if (s >= prices.size()) return 0;
        int max = 0;
        for (int start = s; start < prices.size(); start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.size(); i++) {
                if (prices[start] < prices[i]) {
                    int profit =
                        calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit) maxprofit = profit;
                }
            }
            if (maxprofit > max) max = maxprofit;
        }
        return max;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        return Calculate(prices, 0);
    }

    private int Calculate(int[] prices, int s) {
        if (s >= prices.Length)
            return 0;
        int max = 0;
        for (int start = s; start < prices.Length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.Length; i++) {
                if (prices[start] < prices[i]) {
                    int profit =
                        Calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }

            if (maxprofit > max)
                max = maxprofit;
        }

        return max;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func calculate(prices []int, s int) int {
    if s >= len(prices) {
        return 0
    }
    max := 0
    for start := s; start < len(prices); start++ {
        maxprofit := 0
        for i := start + 1; i < len(prices); i++ {
            if prices[start] < prices[i] {
                profit := calculate(prices, i+1) + prices[i] - prices[start]
                if profit > maxprofit {
                    maxprofit = profit
                }
            }
        }
        if maxprofit > max {
            max = maxprofit
        }
    }
    return max
}

func maxProfit(prices []int) int {
    return calculate(prices, 0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        return calculate(prices, 0);
    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length) return 0;
        int max = 0;
        for (int start = s; start < prices.length; start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit =
                        calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit) maxprofit = profit;
                }
            }
            if (maxprofit > max) max = maxprofit;
        }
        return max;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (prices) {
    return calculate(prices, 0);
};
var calculate = function (prices, s) {
    if (s >= prices.length) return 0;
    let max = 0;
    for (let start = s; start < prices.length; start++) {
        let maxprofit = 0;
        for (let i = start + 1; i < prices.length; i++) {
            if (prices[start] < prices[i]) {
                let profit =
                    calculate(prices, i + 1) + prices[i] - prices[start];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        if (maxprofit > max) max = maxprofit;
    }
    return max;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices):
        return self.calculate(prices, 0)

    def calculate(self, prices, s):
        if s >= len(prices):
            return 0
        max = 0
        for start in range(s, len(prices)):
            maxprofit = 0
            for i in range(start + 1, len(prices)):
                if prices[start] < prices[i]:
                    profit = (
                        self.calculate(prices, i + 1)
                        + prices[i]
                        - prices[start]
                    )
                    if profit > maxprofit:
                        maxprofit = profit
            if maxprofit > max:
                max = maxprofit
        return max
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    return calculate(prices, 0);
}
function calculate(prices: number[], s: number): number {
    if (s >= prices.length) return 0;
    let max = 0;
    for (let start = s; start < prices.length; start++) {
        let maxprofit = 0;
        for (let i = start + 1; i < prices.length; i++) {
            if (prices[start] < prices[i]) {
                let profit =
                    calculate(prices, i + 1) + prices[i] - prices[start];
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        if (maxprofit > max) max = maxprofit;
    }
    return max;
}
```

</details>

<br>

## Approach 2: Peak Valley Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    while (i < pricesSize - 1) {
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) i++;
        valley = prices[i];
        while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) i++;
        peak = prices[i];
        maxprofit += peak - valley;
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
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];
            maxprofit += peak - valley;
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
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.Length - 1) {
            while (i < prices.Length - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];
            while (i < prices.Length - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];
            maxprofit += peak - valley;
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
    i := 0
    valley := prices[0]
    peak := prices[0]
    maxprofit := 0
    for i < len(prices)-1 {
        for i < len(prices)-1 && prices[i] >= prices[i+1] {
            i++
        }
        valley = prices[i]
        for i < len(prices)-1 && prices[i] <= prices[i+1] {
            i++
        }
        peak = prices[i]
        maxprofit += peak - valley
    }
    return maxprofit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1]) i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1]) i++;
            peak = prices[i];
            maxprofit += peak - valley;
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
    let i = 0;
    let valley = prices[0];
    let peak = prices[0];
    let maxprofit = 0;
    while (i < prices.length - 1) {
        while (i < prices.length - 1 && prices[i] >= prices[i + 1]) i++;
        valley = prices[i];
        while (i < prices.length - 1 && prices[i] <= prices[i + 1]) i++;
        peak = prices[i];
        maxprofit += peak - valley;
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
        i = 0
        valley = prices[0]
        peak = prices[0]
        maxprofit = 0
        while i < len(prices) - 1:
            while i < len(prices) - 1 and prices[i] >= prices[i + 1]:
                i += 1
            valley = prices[i]
            while i < len(prices) - 1 and prices[i] <= prices[i + 1]:
                i += 1
            peak = prices[i]
            maxprofit += peak - valley
        return maxprofit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: Array<number>): number {
    let i = 0;
    let valley = prices[0];
    let peak = prices[0];
    let maxprofit = 0;
    while (i < prices.length - 1) {
        while (i < prices.length - 1 && prices[i] >= prices[i + 1]) i++;
        valley = prices[i];
        while (i < prices.length - 1 && prices[i] <= prices[i + 1]) i++;
        peak = prices[i];
        maxprofit += peak - valley;
    }
    return maxprofit;
}
```

</details>

<br>

## Approach 3: Simple One Pass

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) maxprofit += prices[i] - prices[i - 1];
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
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
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
        for (int i = 1; i < prices.Length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
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
    for i := 1; i < len(prices); i++ {
        if prices[i] > prices[i-1] {
            maxprofit += prices[i] - prices[i-1]
        }
    }
    return maxprofit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) maxprofit +=
            prices[i] - prices[i - 1];
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
    var maxprofit = 0;
    for (var i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) maxprofit += prices[i] - prices[i - 1];
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
        maxprofit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                maxprofit += prices[i] - prices[i - 1]
        return maxprofit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    let maxprofit: number = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            maxprofit += prices[i] - prices[i - 1];
        }
    }
    return maxprofit;
}
```

</details>
