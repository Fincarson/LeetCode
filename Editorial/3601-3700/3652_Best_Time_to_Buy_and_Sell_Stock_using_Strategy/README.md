# 3652. Best Time to Buy and Sell Stock using Strategy

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/)  
`Array` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 3652 - Best Time to Buy and Sell Stock using Strategy](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/)

## Problem

You are given two integer arrays prices and strategy, where:

- prices[i] is the price of a given stock on the ith day.
- strategy[i] represents a trading action on the ith day, where:

		-1 indicates buying one unit of the stock.
		0 indicates holding the stock.
		1 indicates selling one unit of the stock.

You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

- Selecting exactly k consecutive elements in strategy.
- Set the first k / 2 elements to 0 (hold).
- Set the last k / 2 elements to 1 (sell).

The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.

### Example 1

### Example 2

## Constraints

- 2 <= prices.length == strategy.length <= 105
- 1 <= prices[i] <= 105
- -1 <= strategy[i] <= 1
- 2 <= k <= prices.length
- k is even

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3652. Best Time to Buy and Sell Stock using Strategy

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maxProfit(int* prices, int pricesSize, int* strategy,
                    int strategySize, int k) {
    int n = pricesSize;
    long long* profitSum = (long long*)calloc(n + 1, sizeof(long long));
    long long* priceSum = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = 0; i < n; i++) {
        profitSum[i + 1] = profitSum[i] + (long long)prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    long long res = profitSum[n];
    for (int i = k - 1; i < n; i++) {
        long long leftProfit = profitSum[i - k + 1];
        long long rightProfit = profitSum[n] - profitSum[i + 1];
        long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
        long long total = leftProfit + changeProfit + rightProfit;
        if (total > res) res = total;
    }
    free(profitSum);
    free(priceSum);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profitSum(n + 1);
        vector<long long> priceSum(n + 1);
        for (int i = 0; i < n; i++) {
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        long long res = profitSum[n];
        for (int i = k - 1; i < n; i++) {
            long long leftProfit = profitSum[i - k + 1];
            long long rightProfit = profitSum[n] - profitSum[i + 1];
            long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
            res = max(res, leftProfit + changeProfit + rightProfit);
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.Length;
        long[] profitSum = new long[n + 1];
        long[] priceSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            profitSum[i + 1] = profitSum[i] + (long)prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        long res = profitSum[n];
        for (int i = k - 1; i < n; i++) {
            long leftProfit = profitSum[i - k + 1];
            long rightProfit = profitSum[n] - profitSum[i + 1];
            long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
            res = Math.Max(res, leftProfit + changeProfit + rightProfit);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProfit(prices []int, strategy []int, k int) int64 {
	n := len(prices)
	profitSum := make([]int64, n+1)
	priceSum := make([]int64, n+1)
	for i := 0; i < n; i++ {
		profitSum[i+1] = profitSum[i] + int64(prices[i])*int64(strategy[i])
		priceSum[i+1] = priceSum[i] + int64(prices[i])
	}
	res := profitSum[n]
	for i := k - 1; i < n; i++ {
		leftProfit := profitSum[i-k+1]
		rightProfit := profitSum[n] - profitSum[i+1]
		changeProfit := priceSum[i+1] - priceSum[i-k/2+1]
		res = max(res, leftProfit+changeProfit+rightProfit)
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.length;
        long[] profitSum = new long[n + 1];
        long[] priceSum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            profitSum[i + 1] = profitSum[i] + (long) prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        long res = profitSum[n];
        for (int i = k - 1; i < n; i++) {
            long leftProfit = profitSum[i - k + 1];
            long rightProfit = profitSum[n] - profitSum[i + 1];
            long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
            res = Math.max(res, leftProfit + changeProfit + rightProfit);
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maxProfit(prices, strategy, k) {
    const n = prices.length;
    const profitSum = new Array(n + 1).fill(0);
    const priceSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    let res = profitSum[n];
    for (let i = k - 1; i < n; i++) {
        const leftProfit = profitSum[i - k + 1];
        const rightProfit = profitSum[n] - profitSum[i + 1];
        const changeProfit =
            priceSum[i + 1] - priceSum[i - Math.floor(k / 2) + 1];
        res = Math.max(res, leftProfit + changeProfit + rightProfit);
    }
    return res;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        profitSum = [0] * (n + 1)
        priceSum = [0] * (n + 1)
        for i in range(n):
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i]
            priceSum[i + 1] = priceSum[i] + prices[i]
        res = profitSum[n]
        for i in range(k - 1, n):
            leftProfit = profitSum[i - k + 1]
            rightProfit = profitSum[n] - profitSum[i + 1]
            changeProfit = priceSum[i + 1] - priceSum[i - k // 2 + 1]
            res = max(res, leftProfit + changeProfit + rightProfit)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProfit(prices: number[], strategy: number[], k: number): number {
    const n = prices.length;
    const profitSum = new Array(n + 1).fill(0);
    const priceSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    let res = profitSum[n];
    for (let i = k - 1; i < n; i++) {
        const leftProfit = profitSum[i - k + 1];
        const rightProfit = profitSum[n] - profitSum[i + 1];
        const changeProfit =
            priceSum[i + 1] - priceSum[i - Math.floor(k / 2) + 1];
        res = Math.max(res, leftProfit + changeProfit + rightProfit);
    }
    return res;
}
```

</details>
