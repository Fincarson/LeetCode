# 3573. Best Time to Buy and Sell Stock V

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 3573 - Best Time to Buy and Sell Stock V](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/)

## Problem

You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

- Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
- Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.

### Example 1

### Example 2

## Constraints

- 2 <= prices.length <= 103
- 1 <= prices[i] <= 109
- 1 <= k <= prices.length / 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3573. Best Time to Buy and Sell Stock V

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Memoization Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long dfs(long long*** memo, int* prices, int n, int i, int j, int state) {
    if (j == 0) {
        return 0;
    }
    if (i == 0) {
        return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
    }
    if (memo[i][j][state] != -1) {
        return memo[i][j][state];
    }
    int p = prices[i];
    long long res;
    if (state == 0) {
        long long a = dfs(memo, prices, n, i - 1, j, 0);
        long long b = dfs(memo, prices, n, i - 1, j, 1) + p;
        long long c = dfs(memo, prices, n, i - 1, j, 2) - p;
        res = fmax(a, fmax(b, c));
    } else if (state == 1) {
        long long a = dfs(memo, prices, n, i - 1, j, 1);
        long long b = dfs(memo, prices, n, i - 1, j - 1, 0) - p;
        res = fmax(a, b);
    } else {
        long long a = dfs(memo, prices, n, i - 1, j, 2);
        long long b = dfs(memo, prices, n, i - 1, j - 1, 0) + p;
        res = fmax(a, b);
    }
    memo[i][j][state] = res;
    return res;
}

long long maximumProfit(int* prices, int pricesSize, int k) {
    long long*** memo = (long long***)malloc(sizeof(long long**) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        memo[i] = (long long**)malloc(sizeof(long long*) * (k + 1));
        for (int j = 0; j <= k; j++) {
            memo[i][j] = (long long*)malloc(sizeof(long long) * 3);
            memset(memo[i][j], -1, sizeof(long long) * 3);
        }
    }

    long long ret = dfs(memo, prices, pricesSize, pricesSize - 1, k, 0);
    for (int i = 0; i < pricesSize; i++) {
        for (int j = 0; j <= k; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }

    return ret;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> memo(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        function<long long(int, int, int)> dfs = [&](int i, int j,
                                                     int state) -> long long {
            if (j == 0) {
                return 0;
            }
            if (i == 0) {
                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
            }
            if (memo[i][j][state] != -1) {
                return memo[i][j][state];
            }

            int p = prices[i];
            long long res;
            if (state == 0) {
                res = max(dfs(i - 1, j, 0),
                          max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p));
            } else if (state == 1) {
                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
            } else {
                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
            }
            memo[i][j][state] = res;

            return res;
        };

        return dfs(n - 1, k, 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int[] prices;
    private long[,,] memo;

    public long MaximumProfit(int[] prices, int k) {
        this.prices = prices;
        int n = prices.Length;
        memo = new long[n, k + 1, 3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s < 3; s++) {
                    memo[i, j, s] = -1;
                }
            }
        }
        return Dfs(n - 1, k, 0);
    }

    private long Dfs(int i, int j, int state) {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
        }

        long res = memo[i, j, state];
        if (res != -1) {
            return res;
        }

        int p = prices[i];
        if (state == 0) {
            res = Math.Max(Dfs(i - 1, j, 0), Math.Max(Dfs(i - 1, j, 1) + p,
                                                      Dfs(i - 1, j, 2) - p));
        } else if (state == 1) {
            res = Math.Max(Dfs(i - 1, j, 1), Dfs(i - 1, j - 1, 0) - p);
        } else {
            res = Math.Max(Dfs(i - 1, j, 2), Dfs(i - 1, j - 1, 0) + p);
        }
        memo[i, j, state] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumProfit(prices []int, k int) int64 {
    n := len(prices)
    memo := make([][][]int64, n)
    for i := range memo {
        memo[i] = make([][]int64, k+1)
        for j := range memo[i] {
            memo[i][j] = make([]int64, 3)
            for s := range memo[i][j] {
                memo[i][j][s] = -1
            }
        }
    }
    
    var dfs func(int, int, int) int64
    dfs = func(i, j, state int) int64 {
        if j == 0 {
            return 0
        }
        if i == 0 {
            if state == 0 {
                return 0
            } else if state == 1 {
                return -int64(prices[0])
            } else {
                return int64(prices[0])
            }
        }
        if memo[i][j][state] != -1 {
            return memo[i][j][state]
        }
        
        p := prices[i]
        var res int64
        if state == 0 {
            res = max(dfs(i - 1, j, 0), max(dfs(i - 1, j, 1) + int64(p), dfs(i - 1, j, 2) - int64(p)))
        } else if state == 1 {
            res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - int64(p))
        } else {
            res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + int64(p))
        }
        memo[i][j][state] = res
        return res
    }
    
    return dfs(n-1, k, 0)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] prices;
    private long[][][] memo;

    public long maximumProfit(int[] prices, int k) {
        this.prices = prices;
        int n = prices.length;
        memo = new long[n][k + 1][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s < 3; s++) {
                    memo[i][j][s] = -1;
                }
            }
        }
        return dfs(n - 1, k, 0);
    }

    private long dfs(int i, int j, int state) {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
        }
        if (memo[i][j][state] != -1) {
            return memo[i][j][state];
        }

        int p = prices[i];
        long res;
        if (state == 0) {
            res = Math.max(
                dfs(i - 1, j, 0),
                Math.max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p)
            );
        } else if (state == 1) {
            res = Math.max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
        } else {
            res = Math.max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
        }
        memo[i][j][state] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumProfit = function (prices, k) {
    const n = prices.length;
    const memo = Array(n)
        .fill()
        .map(() =>
            Array(k + 1)
                .fill()
                .map(() => Array(3).fill(-1)),
        );

    const dfs = (i, j, state) => {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            return state == 0 ? 0 : state == 1 ? -prices[0] : prices[0];
        }
        if (memo[i][j][state] !== -1) {
            return memo[i][j][state];
        }
        const p = prices[i];
        let res;
        if (state === 0) {
            res = Math.max(
                dfs(i - 1, j, 0),
                Math.max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p),
            );
        } else if (state === 1) {
            res = Math.max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
        } else {
            res = Math.max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
        }
        memo[i][j][state] = res;
        return res;
    };

    return dfs(n - 1, k, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        @cache
        def dfs(i, j, state):
            if j == 0:
                return 0
            if i == 0:
                return (
                    0 if state == 0 else -prices[0] if state == 1 else prices[0]
                )
            p = prices[i]
            if state == 0:
                res = max(
                    dfs(i - 1, j, 0), dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p
                )
            elif state == 1:
                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p)
            else:
                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p)

            return res

        ans = dfs(n - 1, k, 0)
        dfs.cache_clear()
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumProfit(prices: number[], k: number): number {
    const n = prices.length;
    const memo: number[][][] = Array(n)
        .fill(null)
        .map(() =>
            Array(k + 1)
                .fill(null)
                .map(() => Array(3).fill(-1)),
        );

    const dfs = (i: number, j: number, state: number): number => {
        if (j == 0) {
            return 0;
        }
        if (i == 0) {
            return state == 0 ? 0 : state == 1 ? -prices[0] : prices[0];
        }
        if (memo[i][j][state] !== -1) {
            return memo[i][j][state];
        }
        const p = prices[i];
        let res: number;
        if (state === 0) {
            res = Math.max(
                dfs(i - 1, j, 0),
                Math.max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p),
            );
        } else if (state === 1) {
            res = Math.max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
        } else {
            res = Math.max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);
        }
        memo[i][j][state] = res;
        return res;
    };

    return dfs(n - 1, k, 0);
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long max(long long a, long long b) { return a > b ? a : b; }

long long maximumProfit(int* prices, int pricesSize, int k) {
    int n = pricesSize;
    long long dp[n][k + 1][3];
    memset(dp, 0, sizeof(dp));

    // initialize the state on day 0
    for (int j = 1; j <= k; j++) {
        dp[0][j][1] = -(long long)prices[0];
        dp[0][j][2] = (long long)prices[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(
                dp[i - 1][j][0],
                max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]));
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
        }
    }

    return dp[n - 1][k][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));
        // initialize the state on day 0
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] =
                    max(dp[i - 1][j][0], max(dp[i - 1][j][1] + prices[i],
                                             dp[i - 1][j][2] - prices[i]));
                dp[i][j][1] =
                    max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] =
                    max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System;

public class Solution {
    public long MaximumProfit(int[] prices, int k) {
        int n = prices.Length;
        long[,,] dp = new long[n, k + 1, 3];

        // initialize the state on day 0
        for (int j = 1; j <= k; j++) {
            dp[0, j, 1] = -prices[0];
            dp[0, j, 2] = prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i, j, 0] = Math.Max(dp[i - 1, j, 0],
                                       Math.Max(dp[i - 1, j, 1] + prices[i],
                                                dp[i - 1, j, 2] - prices[i]));
                dp[i, j, 1] =
                    Math.Max(dp[i - 1, j, 1], dp[i - 1, j - 1, 0] - prices[i]);
                dp[i, j, 2] =
                    Math.Max(dp[i - 1, j, 2], dp[i - 1, j - 1, 0] + prices[i]);
            }
        }

        return dp[n - 1, k, 0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumProfit(prices []int, k int) int64 {
    n := len(prices)
    dp := make([][][]int64, n)
    for i := range dp {
        dp[i] = make([][]int64, k + 1)
        for j := range dp[i] {
            dp[i][j] = make([]int64, 3)
        }
    }
    
    // initialize the state on day 0
    for j := 1; j <= k; j++ {
        dp[0][j][1] = int64(-prices[0])
        dp[0][j][2] = int64(prices[0])
    }
    
    for i := 1; i < n; i++ {
        for j := 1; j <= k; j++ {
            dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i-1][j][1] + int64(prices[i]), dp[i - 1][j][2] - int64(prices[i])))
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - int64(prices[i]))
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + int64(prices[i]))
        }
    }
    
    return dp[n - 1][k][0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        long[][][] dp = new long[n][k + 1][3];

        // initialize the state on day 0
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = Math.max(
                    dp[i - 1][j][0],
                    Math.max(
                        dp[i - 1][j][1] + prices[i],
                        dp[i - 1][j][2] - prices[i]
                    )
                );
                dp[i][j][1] = Math.max(
                    dp[i - 1][j][1],
                    dp[i - 1][j - 1][0] - prices[i]
                );
                dp[i][j][2] = Math.max(
                    dp[i - 1][j][2],
                    dp[i - 1][j - 1][0] + prices[i]
                );
            }
        }

        return dp[n - 1][k][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumProfit = function (prices, k) {
    const n = prices.length;
    const dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(k + 1);
        for (let j = 0; j <= k; j++) {
            dp[i][j] = new Array(3).fill(0);
        }
    }

    // initialize the state on day 0
    for (let j = 1; j <= k; j++) {
        dp[0][j][1] = -prices[0];
        dp[0][j][2] = prices[0];
    }
    for (let i = 1; i < n; i++) {
        for (let j = 1; j <= k; j++) {
            dp[i][j][0] = Math.max(
                dp[i - 1][j][0],
                Math.max(
                    dp[i - 1][j][1] + prices[i],
                    dp[i - 1][j][2] - prices[i],
                ),
            );
            dp[i][j][1] = Math.max(
                dp[i - 1][j][1],
                dp[i - 1][j - 1][0] - prices[i],
            );
            dp[i][j][2] = Math.max(
                dp[i - 1][j][2],
                dp[i - 1][j - 1][0] + prices[i],
            );
        }
    }

    return dp[n - 1][k][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        dp = [[[0] * 3 for _ in range(k + 1)] for _ in range(n)]

        # initialize the state on day 0
        for j in range(1, k + 1):
            dp[0][j][1] = -prices[0]
            dp[0][j][2] = prices[0]

        for i in range(1, n):
            for j in range(1, k + 1):
                dp[i][j][0] = max(
                    dp[i - 1][j][0],
                    max(
                        dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]
                    ),
                )
                dp[i][j][1] = max(
                    dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]
                )
                dp[i][j][2] = max(
                    dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]
                )

        return dp[n - 1][k][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumProfit(prices: number[], k: number): number {
    const n: number = prices.length;
    const dp: number[][][] = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(k + 1);
        for (let j = 0; j <= k; j++) {
            dp[i][j] = new Array(3).fill(0);
        }
    }

    // initialize the state on day 0
    for (let j = 1; j <= k; j++) {
        dp[0][j][1] = -prices[0];
        dp[0][j][2] = prices[0];
    }

    for (let i = 1; i < n; i++) {
        for (let j = 1; j <= k; j++) {
            dp[i][j][0] = Math.max(
                dp[i - 1][j][0],
                Math.max(
                    dp[i - 1][j][1] + prices[i],
                    dp[i - 1][j][2] - prices[i],
                ),
            );
            dp[i][j][1] = Math.max(
                dp[i - 1][j][1],
                dp[i - 1][j - 1][0] - prices[i],
            );
            dp[i][j][2] = Math.max(
                dp[i - 1][j][2],
                dp[i - 1][j - 1][0] + prices[i],
            );
        }
    }

    return dp[n - 1][k][0];
}
```

</details>
