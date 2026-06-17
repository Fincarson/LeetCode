# 188. Best Time to Buy and Sell Stock IV

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 188 - Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

## Problem

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

### Example 1

```text
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

### Example 2

```text
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

## Constraints

- 1 <= k <= 100
- 1 <= prices.length <= 1000
- 0 <= prices[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Profit From Trading Stocks](https://leetcode.com/problems/maximum-profit-from-trading-stocks/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 188. Best Time to Buy and Sell Stock IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Merging | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        // dp[i][used_k][is_hold] = balance
        // is_hold: 0 not_hold, 1 hold
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        // initialize the array with -inf
        // we use INT_MIN/2 here to prevent overflow
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = INT_MIN / 2;
                dp[i][j][1] = INT_MIN / 2;
            }
        }

        // set starting value
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        // fill the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // transition equation
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // you can't hold stock without any transaction
                if (j > 0) {
                    dp[i][j][1] =
                        max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = max(res, dp[n - 1][j][0]);
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;

        // Solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += Math.max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        // dp[i][used_k][ishold] = balance
        // ishold: 0 nothold, 1 hold
        int[][][] dp = new int[n][k + 1][2];

        // initialize the array with -inf
        // we use -1e9 here to prevent overflow
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = -1000000000;
                dp[i][j][1] = -1000000000;
            }
        }

        // set starting value
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        // fill the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // transition equation
                dp[i][j][0] = Math.max(
                    dp[i - 1][j][0],
                    dp[i - 1][j][1] + prices[i]
                );
                // you can't hold stock without any transaction
                if (j > 0) {
                    dp[i][j][1] = Math.max(
                        dp[i - 1][j][1],
                        dp[i - 1][j - 1][0] - prices[i]
                    );
                }
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++) {
            res = Math.max(res, dp[n - 1][j][0]);
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k == 0:
            return 0

        if k * 2 >= n:
            res = 0
            for i, j in zip(prices[1:], prices[:-1]):
                res += max(0, i - j)
            return res

        # dp[i][used_k][ishold] = balance
        # ishold: 0 nothold, 1 hold
        dp = [[[-math.inf] * 2 for _ in range(k + 1)] for _ in range(n)]

        # set starting value
        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        # fill the array
        for i in range(1, n):
            for j in range(k + 1):
                # transition equation
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
                # you can't hold stock without any transaction
                if j > 0:
                    dp[i][j][1] = max(
                        dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]
                    )

        res = max(dp[n - 1][j][0] for j in range(k + 1))
        return res
```

</details>

<br>

## Approach 2: Merging

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        // find all consecutively increasing subsequence
        vector<vector<int>> transactions;
        int start = 0;
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                end = i;
            } else {
                if (end > start) {
                    vector<int> t = {start, end};
                    transactions.push_back(t);
                }
                start = i;
            }
        }
        if (end > start) {
            vector<int> t = {start, end};
            transactions.push_back(t);
        }

        while (transactions.size() > k) {
            // check delete loss
            int delete_index = 0;
            int min_delete_loss = INT_MAX;
            for (int i = 0; i < transactions.size(); i++) {
                vector<int> t = transactions[i];
                int profit_loss = prices[t[1]] - prices[t[0]];
                if (profit_loss < min_delete_loss) {
                    min_delete_loss = profit_loss;
                    delete_index = i;
                }
            }

            // check merge loss
            int merge_index = 0;
            int min_merge_loss = INT_MAX;
            for (int i = 1; i < transactions.size(); i++) {
                vector<int> t1 = transactions[i - 1];
                vector<int> t2 = transactions[i];
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_merge_loss) {
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }

            // delete or merge
            if (min_delete_loss <= min_merge_loss) {
                transactions.erase(transactions.begin() + delete_index);
            } else {
                vector<int>& t1 = transactions[merge_index - 1];
                vector<int>& t2 = transactions[merge_index];
                t1[1] = t2[1];
                transactions.erase(transactions.begin() + merge_index);
            }
        }

        int res = 0;
        for (auto& t : transactions) {
            res += prices[t[1]] - prices[t[0]];
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;

        // solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        // find all consecutively increasing subsequence
        ArrayList<int[]> transactions = new ArrayList<>();
        int start = 0;
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] >= prices[i - 1]) {
                end = i;
            } else {
                if (end > start) {
                    int[] t = { start, end };
                    transactions.add(t);
                }
                start = i;
            }
        }
        if (end > start) {
            int[] t = { start, end };
            transactions.add(t);
        }

        while (transactions.size() > k) {
            // check delete loss
            int delete_index = 0;
            int min_delete_loss = Integer.MAX_VALUE;
            for (int i = 0; i < transactions.size(); i++) {
                int[] t = transactions.get(i);
                int profit_loss = prices[t[1]] - prices[t[0]];
                if (profit_loss < min_delete_loss) {
                    min_delete_loss = profit_loss;
                    delete_index = i;
                }
            }

            // check merge loss
            int merge_index = 0;
            int min_merge_loss = Integer.MAX_VALUE;
            for (int i = 1; i < transactions.size(); i++) {
                int[] t1 = transactions.get(i - 1);
                int[] t2 = transactions.get(i);
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_merge_loss) {
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }

            // delete or merge
            if (min_delete_loss <= min_merge_loss) {
                transactions.remove(delete_index);
            } else {
                int[] t1 = transactions.get(merge_index - 1);
                int[] t2 = transactions.get(merge_index);
                t1[1] = t2[1];
                transactions.remove(merge_index);
            }
        }

        int res = 0;
        for (int[] t : transactions) {
            res += prices[t[1]] - prices[t[0]];
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        # solve special cases
        if not prices or k == 0:
            return 0

        # find all consecutively increasing subsequence
        transactions = []
        start = 0
        end = 0
        for i in range(1, n):
            if prices[i] >= prices[i - 1]:
                end = i
            else:
                if end > start:
                    transactions.append([start, end])
                start = i
        if end > start:
            transactions.append([start, end])

        while len(transactions) > k:
            # check delete loss
            delete_index = 0
            min_delete_loss = math.inf
            for i in range(len(transactions)):
                t = transactions[i]
                profit_loss = prices[t[1]] - prices[t[0]]
                if profit_loss < min_delete_loss:
                    min_delete_loss = profit_loss
                    delete_index = i

            # check merge loss
            merge_index = 0
            min_merge_loss = math.inf
            for i in range(1, len(transactions)):
                t1 = transactions[i - 1]
                t2 = transactions[i]
                profit_loss = prices[t1[1]] - prices[t2[0]]
                if profit_loss < min_merge_loss:
                    min_merge_loss = profit_loss
                    merge_index = i

            # delete or merge
            if min_delete_loss <= min_merge_loss:
                transactions.pop(delete_index)
            else:
                transactions[merge_index - 1][1] = transactions[merge_index][1]
                transactions.pop(merge_index)

        return sum(prices[j] - prices[i] for i, j in transactions)
```

</details>
