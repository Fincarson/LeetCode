# 3418. Maximum Amount of Money Robot Can Earn

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 3418 - Maximum Amount of Money Robot Can Earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)

## Problem

You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

The grid contains a value coins[i][j] in each cell:

- If coins[i][j] >= 0, the robot gains that many coins.
- If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.

The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

Note: The robot's total coins can be negative.

Return the maximum profit the robot can gain on the route.

### Example 1

### Example 2

## Constraints

- m == coins.length
- n == coins[i].length
- 1 <= m, n <= 500
- -1000 <= coins[i][j] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3418. Maximum Amount of Money Robot Can Earn

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Memoization Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int dfs(int** coins, int*** memo, int m, int n, int i, int j, int k) {
    if (i < 0 || j < 0) {
        return INT_MIN;
    }

    int x = coins[i][j];
    if (i == 0 && j == 0) {
        return k > 0 ? (x > 0 ? x : 0) : x;
    }
    if (memo[i][j][k] != INT_MIN) {
        return memo[i][j][k];
    }

    int res = fmax(dfs(coins, memo, m, n, i - 1, j, k),
                   dfs(coins, memo, m, n, i, j - 1, k)) +
              x;

    if (k > 0 && x < 0) {
        res = fmax(res, fmax(dfs(coins, memo, m, n, i - 1, j, k - 1),
                             dfs(coins, memo, m, n, i, j - 1, k - 1)));
    }

    memo[i][j][k] = res;
    return res;
}

int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    int m = coinsSize, n = coinsColSize[0];

    int*** memo = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        memo[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            memo[i][j] = (int*)malloc(3 * sizeof(int));
            for (int k = 0; k < 3; k++) {
                memo[i][j][k] = INT_MIN;
            }
        }
    }

    int res = dfs(coins, memo, m, n, m - 1, n - 1, 2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector memo(m, vector(n, array<int, 3>{INT_MIN, INT_MIN, INT_MIN}));

        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= m || j >= n) {
                return INT_MIN;
            }

            int x = coins[i][j];
            // arrive at the destination
            if (i == m - 1 && j == n - 1) {
                return k > 0 ? max(0, x) : x;
            }

            int res = memo[i][j][k];
            if (res != INT_MIN) {
                return res;
            }
            // not neutralize
            res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;
            if (k > 0 && x < 0) {
                // neutralize
                res = max({res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
            }
            return memo[i][j][k] = res;
        };

        return dfs(0, 0, 2);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximumAmount(int[][] coins) {
        int m = coins.Length, n = coins[0].Length;
        int[,,] memo = new int[m, n, 3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    memo[i, j, k] = int.MinValue;
                }
            }
        }

        return DFS(coins, memo, 0, 0, 2);
    }

    private int DFS(int[][] coins, int[,,] memo, int i, int j, int k) {
        int m = coins.Length, n = coins[0].Length;
        if (i >= m || j >= n) {
            return int.MinValue;
        }

        int x = coins[i][j];
        // arrive at the destination
        if (i == m - 1 && j == n - 1) {
            return k > 0 ? Math.Max(0, x) : x;
        }

        if (memo[i, j, k] != int.MinValue) {
            return memo[i, j, k];
        }

        // not neutralize
        int res = Math.Max(DFS(coins, memo, i + 1, j, k),
                           DFS(coins, memo, i, j + 1, k)) +
                  x;

        if (k > 0 && x < 0) {
            // neutralize
            res = Math.Max(res, Math.Max(DFS(coins, memo, i + 1, j, k - 1),
                                         DFS(coins, memo, i, j + 1, k - 1)));
        }

        memo[i, j, k] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumAmount(coins [][]int) int {
	m, n := len(coins), len(coins[0])
	memo := make([][][]int, m)
	for i := range memo {
		memo[i] = make([][]int, n)
		for j := range memo[i] {
			memo[i][j] = make([]int, 3)
			for k := range memo[i][j] {
				memo[i][j][k] = -1 << 31
			}
		}
	}

	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i >= m || j >= n {
			return -1 << 31
		}

		x := coins[i][j]
		// arrive at the destination
		if i == m-1 && j == n-1 {
			if k > 0 {
				return max(0, x)
			}
			return x
		}

		if memo[i][j][k] != -1<<31 {
			return memo[i][j][k]
		}

		// not neutralize
		res := max(dfs(i+1, j, k), dfs(i, j+1, k)) + x
		if k > 0 && x < 0 {
			// neutralize
			res = max(res, max(dfs(i+1, j, k-1), dfs(i, j+1, k-1)))
		}

		memo[i][j][k] = res
		return res
	}

	return dfs(0, 0, 2)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumAmount(int[][] coins) {
        int m = coins.length;
        int n = coins[0].length;
        int[][][] memo = new int[m][n][3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(memo[i][j], Integer.MIN_VALUE);
            }
        }

        return dfs(coins, memo, 0, 0, 2);
    }

    private int dfs(int[][] coins, int[][][] memo, int i, int j, int k) {
        int m = coins.length;
        int n = coins[0].length;
        if (i >= m || j >= n) {
            return Integer.MIN_VALUE;
        }

        int x = coins[i][j];
        // arrive at the destination
        if (i == m - 1 && j == n - 1) {
            return k > 0 ? Math.max(0, x) : x;
        }

        if (memo[i][j][k] != Integer.MIN_VALUE) {
            return memo[i][j][k];
        }

        // not neutralize
        int res =
            Math.max(
                dfs(coins, memo, i + 1, j, k),
                dfs(coins, memo, i, j + 1, k)
            ) +
            x;

        if (k > 0 && x < 0) {
            // neutralize
            res = Math.max(
                res,
                Math.max(
                    dfs(coins, memo, i + 1, j, k - 1),
                    dfs(coins, memo, i, j + 1, k - 1)
                )
            );
        }

        memo[i][j][k] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumAmount = function (coins) {
    const m = coins.length,
        n = coins[0].length;
    const memo = new Array(m);

    for (let i = 0; i < m; i++) {
        memo[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            memo[i][j] = new Array(3).fill(-Infinity);
        }
    }

    const dfs = (i, j, k) => {
        if (i < 0 || j < 0) {
            return -Infinity;
        }

        const x = coins[i][j];
        if (i === 0 && j === 0) {
            return k > 0 ? Math.max(0, x) : x;
        }

        if (memo[i][j][k] !== -Infinity) {
            return memo[i][j][k];
        }

        let res = Math.max(dfs(i - 1, j, k), dfs(i, j - 1, k)) + x;
        if (k > 0 && x < 0) {
            res = Math.max(res, dfs(i - 1, j, k - 1), dfs(i, j - 1, k - 1));
        }

        memo[i][j][k] = res;
        return res;
    };

    return dfs(m - 1, n - 1, 2);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        memo = [[[-inf] * 3 for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int, k: int) -> int:
            if i >= m or j >= n:
                return -inf

            x = coins[i][j]
            # arrive at the destination
            if i == m - 1 and j == n - 1:
                return max(0, x) if k > 0 else x

            if memo[i][j][k] != -inf:
                return memo[i][j][k]

            # not neutralize
            res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x
            if k > 0 and x < 0:
                # neutralize
                res = max(res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1))

            memo[i][j][k] = res
            return res

        return dfs(0, 0, 2)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumAmount(coins: number[][]): number {
    const m = coins.length,
        n = coins[0].length;
    const memo: number[][][] = new Array(m);

    for (let i = 0; i < m; i++) {
        memo[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            memo[i][j] = new Array(3).fill(-Infinity);
        }
    }

    const dfs = (i: number, j: number, k: number): number => {
        if (i < 0 || j < 0) {
            return -Infinity;
        }

        const x = coins[i][j];
        if (i === 0 && j === 0) {
            return k > 0 ? Math.max(0, x) : x;
        }

        if (memo[i][j][k] !== -Infinity) {
            return memo[i][j][k];
        }

        let res = Math.max(dfs(i - 1, j, k), dfs(i, j - 1, k)) + x;

        if (k > 0 && x < 0) {
            res = Math.max(res, dfs(i - 1, j, k - 1), dfs(i, j - 1, k - 1));
        }

        memo[i][j][k] = res;
        return res;
    };

    return dfs(m - 1, n - 1, 2);
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector dp(
            m, vector(n, array<int, 3>{INT_MIN / 2, INT_MIN / 2, INT_MIN / 2}));

        dp[0][0][0] = coins[0][0];
        for (int k = 1; k <= 2; k++) {
            dp[0][0][k] = max(coins[0][0], 0);
        }
        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            for (int k = 1; k <= 2; k++) {
                dp[0][j][k] = max(dp[0][j - 1][k] + coins[0][j],
                                  dp[0][j - 1][k - 1] + max(coins[0][j], 0));
            }
        }
        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k] + coins[i][0],
                                  dp[i - 1][0][k - 1] + max(coins[i][0], 0));
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] =
                    max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];
                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] =
                        max(max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i][j],
                            max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]));
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumAmount(int[][] coins) {
        int m = coins.length;
        int n = coins[0].length;

        int[][][] dp = new int[m][n][3];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(dp[i][j], Integer.MIN_VALUE / 2);
            }
        }

        dp[0][0][0] = coins[0][0];
        for (int k = 1; k <= 2; k++) {
            dp[0][0][k] = Math.max(coins[0][0], 0);
        }

        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];
            for (int k = 1; k <= 2; k++) {
                dp[0][j][k] = Math.max(
                    dp[0][j - 1][k] + coins[0][j],
                    dp[0][j - 1][k - 1] + Math.max(coins[0][j], 0)
                );
            }
        }

        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = Math.max(
                    dp[i - 1][0][k] + coins[i][0],
                    dp[i - 1][0][k - 1] + Math.max(coins[i][0], 0)
                );
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] =
                    Math.max(dp[i - 1][j][0], dp[i][j - 1][0]) + coins[i][j];

                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] = Math.max(
                        Math.max(dp[i - 1][j][k], dp[i][j - 1][k]) +
                        coins[i][j],
                        Math.max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1])
                    );
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[[-inf] * 3 for _ in range(n)] for _ in range(m)]

        dp[0][0][0] = coins[0][0]
        for k in range(1, 3):
            dp[0][0][k] = max(coins[0][0], 0)

        for j in range(1, n):
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j]
            x = max(coins[0][j], 0)
            for k in range(1, 3):
                dp[0][j][k] = max(
                    dp[0][j - 1][k] + coins[0][j], dp[0][j - 1][k - 1] + x
                )

        for i in range(1, m):
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0]
            x = max(coins[i][0], 0)
            for k in range(1, 3):
                dp[i][0][k] = max(
                    dp[i - 1][0][k] + coins[i][0], dp[i - 1][0][k - 1] + x
                )

        for i in range(1, m):
            for j in range(1, n):
                x = coins[i][j]
                dp[i][j][2] = max(
                    dp[i - 1][j][2] + x,
                    dp[i][j - 1][2] + x,
                    dp[i - 1][j][1],
                    dp[i][j - 1][1],
                )
                dp[i][j][1] = max(
                    dp[i - 1][j][1] + x,
                    dp[i][j - 1][1] + x,
                    dp[i - 1][j][0],
                    dp[i][j - 1][0],
                )
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + x

        return dp[m - 1][n - 1][2]
```

</details>
