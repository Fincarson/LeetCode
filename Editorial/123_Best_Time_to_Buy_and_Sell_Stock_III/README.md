# 123. Best Time to Buy and Sell Stock III

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 123 - Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

## Problem

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example 1

```text
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

### Example 2

```text
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

### Example 3

```text
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

## Constraints

- 1 <= prices.length <= 105
- 0 <= prices[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Sum of 3 Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximize Win From Two Segments](https://leetcode.com/problems/maximize-win-from-two-segments/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 123. Best Time to Buy and Sell Stock III

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Bidirectional Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One-pass Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Bidirectional Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int x, int y) { return (x > y) ? x : y; }
int min(int x, int y) { return (x > y) ? y : x; }
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    int leftMin = prices[0];
    int rightMax = prices[pricesSize - 1];
    int leftProfits[pricesSize];
    int rightProfits[pricesSize + 1];
    memset(rightProfits, 0, sizeof(rightProfits));
    int base = 0;
    memset(leftProfits, base, sizeof(leftProfits));
    for (int l = 1; l < pricesSize; ++l) {
        leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
        leftMin = min(leftMin, prices[l]);
        int r = pricesSize - 1 - l;
        rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
        rightMax = max(rightMax, prices[r]);
    }
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; ++i)
        maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    return maxProfit;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[length - 1];

    vector<int> leftProfits(length, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rightProfits(length + 1, 0);

    // construct the bidirectional DP array
    for (int l = 1; l < length; ++l) {
      leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
      leftMin = min(leftMin, prices[l]);

      int r = length - 1 - l;
      rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
      rightMax = max(rightMax, prices[r]);
    }

    int maxProfit = 0;
    for (int i = 0; i < length; ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int length = prices.Length;
        if (length <= 1)
            return 0;
        int leftMin = prices[0];
        int rightMax = prices[length - 1];
        int[] leftProfits = new int[length];
        int[] rightProfits = new int[length + 1];
        for (var l = 1; l < length; ++l) {
            leftProfits[l] = Math.Max(leftProfits[l - 1], prices[l] - leftMin);
            leftMin = Math.Min(leftMin, prices[l]);
            int r = length - 1 - l;
            rightProfits[r] =
                Math.Max(rightProfits[r + 1], rightMax - prices[r]);
            rightMax = Math.Max(rightMax, prices[r]);
        }

        var maxProfit = 0;
        for (var i = 0; i < length; ++i)
            maxProfit =
                Math.Max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
        return maxProfit;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func max(x int, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x int, y int) int {
    if x > y {
        return y
    }
    return x
}

func maxProfit(prices []int) int {
    length := len(prices)
    if length <= 1 {
        return 0
    }
    leftMin := prices[0]
    rightMax := prices[length-1]
    leftProfits := make([]int, length)
    rightProfits := make([]int, length+1)
    for l := 1; l < length; l++ {
        leftProfits[l] = max(leftProfits[l-1], prices[l]-leftMin)
        leftMin = min(leftMin, prices[l])
        r := length - 1 - l
        rightProfits[r] = max(rightProfits[r+1], rightMax-prices[r])
        rightMax = max(rightMax, prices[r])
    }
    maxProfit := 0
    for i := 0; i < length; i++ {
        maxProfit = max(maxProfit, leftProfits[i]+rightProfits[i+1])
    }
    return maxProfit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        int length = prices.length;
        if (length <= 1) return 0;

        int leftMin = prices[0];
        int rightMax = prices[length - 1];

        int[] leftProfits = new int[length];
        // pad the right DP array with an additional zero for convenience.
        int[] rightProfits = new int[length + 1];

        // construct the bidirectional DP array
        for (int l = 1; l < length; ++l) {
            leftProfits[l] = Math.max(leftProfits[l - 1], prices[l] - leftMin);
            leftMin = Math.min(leftMin, prices[l]);

            int r = length - 1 - l;
            rightProfits[r] = Math.max(
                rightProfits[r + 1],
                rightMax - prices[r]
            );
            rightMax = Math.max(rightMax, prices[r]);
        }

        int maxProfit = 0;
        for (int i = 0; i < length; ++i) {
            maxProfit = Math.max(
                maxProfit,
                leftProfits[i] + rightProfits[i + 1]
            );
        }
        return maxProfit;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (prices) {
    if (prices.length <= 1) return 0;
    let left_min = prices[0];
    let right_max = prices[prices.length - 1];
    let length = prices.length;
    let left_profits = new Array(length).fill(0);
    let right_profits = new Array(length + 1).fill(0);
    for (let l = 1; l < length; ++l) {
        left_profits[l] = Math.max(left_profits[l - 1], prices[l] - left_min);
        left_min = Math.min(left_min, prices[l]);
        let r = length - 1 - l;
        right_profits[r] = Math.max(
            right_profits[r + 1],
            right_max - prices[r],
        );
        right_max = Math.max(right_max, prices[r]);
    }
    let max_profit = 0;
    for (let i = 0; i < length; ++i) {
        max_profit = Math.max(
            max_profit,
            left_profits[i] + right_profits[i + 1],
        );
    }
    return max_profit;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        left_min = prices[0]
        right_max = prices[-1]

        length = len(prices)
        left_profits = [0] * length
        # pad the right DP array with an additional zero for convenience.
        right_profits = [0] * (length + 1)

        # construct the bidirectional DP array
        for l in range(1, length):
            left_profits[l] = max(left_profits[l - 1], prices[l] - left_min)
            left_min = min(left_min, prices[l])

            r = length - 1 - l
            right_profits[r] = max(right_profits[r + 1], right_max - prices[r])
            right_max = max(right_max, prices[r])

        max_profit = 0
        for i in range(0, length):
            max_profit = max(max_profit, left_profits[i] + right_profits[i + 1])

        return max_profit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    if (prices.length <= 1) return 0;
    let left_min = prices[0];
    let right_max = prices[prices.length - 1];
    let left_profits: number[] = new Array(prices.length).fill(0);
    let right_profits: number[] = new Array(prices.length + 1).fill(0);
    for (let l = 1; l < prices.length; ++l) {
        left_profits[l] = Math.max(left_profits[l - 1], prices[l] - left_min);
        left_min = Math.min(left_min, prices[l]);
        let r = prices.length - 1 - l;
        right_profits[r] = Math.max(
            right_profits[r + 1],
            right_max - prices[r],
        );
        right_max = Math.max(right_max, prices[r]);
    }
    let max_profit = 0;
    for (let i = 0; i < prices.length; ++i)
        max_profit = Math.max(
            max_profit,
            left_profits[i] + right_profits[i + 1],
        );
    return max_profit;
}
```

</details>

<br>

## Approach 2: One-pass Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxProfit(int* prices, int pricesSize) {
    int t1Cost = INT_MAX, t2Cost = INT_MAX;
    int t1Profit = 0, t2Profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        // the maximum profit if only one transaction is allowed
        t1Cost = fmin(t1Cost, prices[i]);
        t1Profit = fmax(t1Profit, prices[i] - t1Cost);
        // reinvest the gained profit in the second transaction
        t2Cost = fmin(t2Cost, prices[i] - t1Profit);
        t2Profit = fmax(t2Profit, prices[i] - t2Cost);
    }
    return t2Profit;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, 
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }

    return t2Profit;
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProfit(int[] prices) {
        int t1Cost = Int32.MaxValue, t2Cost = Int32.MaxValue;
        int t1Profit = 0, t2Profit = 0;
        foreach (int price in prices) {
            // the maximum profit if only one transaction is allowed
            t1Cost = Math.Min(t1Cost, price);
            t1Profit = Math.Max(t1Profit, price - t1Cost);
            // reinvest the gained profit in the second transaction
            t2Cost = Math.Min(t2Cost, price - t1Profit);
            t2Profit = Math.Max(t2Profit, price - t2Cost);
        }

        return t2Profit;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProfit(prices []int) int {
    t1Cost := math.MaxInt32
    t2Cost := math.MaxInt32
    t1Profit := 0
    t2Profit := 0
    for _, price := range prices {
        // the maximum profit if only one transaction is allowed
        t1Cost = int(math.Min(float64(t1Cost), float64(price)))
        t1Profit = int(math.Max(float64(t1Profit), float64(price-t1Cost)))
        // reinvest the gained profit in the second transaction
        t2Cost = int(math.Min(float64(t2Cost), float64(price-t1Profit)))
        t2Profit = int(math.Max(float64(t2Profit), float64(price-t2Cost)))
    }
    return t2Profit
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxProfit(int[] prices) {
        int t1Cost = Integer.MAX_VALUE, t2Cost = Integer.MAX_VALUE;
        int t1Profit = 0, t2Profit = 0;

        for (int price : prices) {
            // the maximum profit if only one transaction is allowed
            t1Cost = Math.min(t1Cost, price);
            t1Profit = Math.max(t1Profit, price - t1Cost);
            // reinvest the gained profit in the second transaction
            t2Cost = Math.min(t2Cost, price - t1Profit);
            t2Profit = Math.max(t2Profit, price - t2Cost);
        }

        return t2Profit;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProfit = function (prices) {
    let t1Cost = Number.MAX_VALUE,
        t2Cost = Number.MAX_VALUE;
    let t1Profit = 0,
        t2Profit = 0;
    // iterate over prices
    for (let price of prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = Math.min(t1Cost, price);
        t1Profit = Math.max(t1Profit, price - t1Cost);
        // reinvest the gained profit in the second transaction
        t2Cost = Math.min(t2Cost, price - t1Profit);
        t2Profit = Math.max(t2Profit, price - t2Cost);
    }
    return t2Profit;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def maxProfit(self, prices: List[int]) -> int:
        t1_cost, t2_cost = float("inf"), float("inf")
        t1_profit, t2_profit = 0, 0

        for price in prices:
            # the maximum profit if only one transaction is allowed
            t1_cost = min(t1_cost, price)
            t1_profit = max(t1_profit, price - t1_cost)
            # reinvest the gained profit in the second transaction
            t2_cost = min(t2_cost, price - t1_profit)
            t2_profit = max(t2_profit, price - t2_cost)

        return t2_profit
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[]): number {
    let t1Cost = Number.MAX_VALUE,
        t2Cost = Number.MAX_VALUE;
    let t1Profit = 0,
        t2Profit = 0;
    for (let price of prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = Math.min(t1Cost, price);
        t1Profit = Math.max(t1Profit, price - t1Cost);
        // reinvest the gained profit in the second transaction
        t2Cost = Math.min(t2Cost, price - t1Profit);
        t2Profit = Math.max(t2Profit, price - t2Cost);
    }
    return t2Profit;
}
```

</details>
