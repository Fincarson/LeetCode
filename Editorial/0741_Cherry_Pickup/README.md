# 741. Cherry Pickup

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/cherry-pickup/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 741 - Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)

## Problem

You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

- 0 means the cell is empty, so you can pass through,
- 1 means the cell contains a cherry that you can pick up and pass through, or
- -1 means the cell contains a thorn that blocks your way.

Return the maximum number of cherries you can collect by following the rules below:

- Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
- After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
- When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
- If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.

### Example 1

```text
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.
```

### Example 2

```text
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
```

## Constraints

- n == grid.length
- n == grid[i].length
- 1 <= n <= 50
- grid[i][j] is -1, 0, or 1.
- grid[0][0] != -1
- grid[n - 1][n - 1] != -1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Dungeon Game](https://leetcode.com/problems/dungeon-game/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Path Quality of a Graph](https://leetcode.com/problems/maximum-path-quality-of-a-graph/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 741. Cherry Pickup

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Greedy [Wrong Answer] | Java, Python |
| Approach #2: Dynamic Programming (Top Down) [Accepted] | Java, Python |
| Approach #3: Dynamic Programming (Bottom Up) [Accepted] | Java, Python |

## Approach #1: Greedy [Wrong Answer]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int ans = 0;
        int[][] path = bestPath(grid);
        if (path == null) {
            return 0;
        }
        for (int[] step: path) {
            ans += grid[step[0]][step[1]];
            grid[step[0]][step[1]] = 0;
        }

        for (int[] step: bestPath(grid)) {
            ans += grid[step[0]][step[1]];
        }

        return ans;
    }

    public int[][] bestPath(int[][] grid) {
        int N = grid.length;
        int[][] dp = new int[N][N];
        for (int[] row: dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        dp[N - 1][N - 1] = grid[N - 1][N - 1];
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] >= 0 && (i != N - 1 || j != N - 1)) {
                    dp[i][j] = Math.max(i + 1 < N ? dp[i + 1][j] : Integer.MIN_VALUE,
                                        j + 1 < N ? dp[i][j + 1] : Integer.MIN_VALUE);
                    dp[i][j] += grid[i][j];
                }
            }
        }
        if (dp[0][0] < 0) {
            return null;
        }
        int[][] ans = new int[2 * N - 1][2];
        int i = 0, j = 0, t = 0;
        while (i != N - 1 || j != N - 1) {
            if (j + 1 == N || i + 1 < N && dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            }
            else {
                j++;
            }

            ans[t][0] = i;
            ans[t][1] = j;
            t++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def cherryPickup(self, grid):
        def bestpath(grid):
            N = len(grid)
            NINF = float('-inf')
            dp = [[NINF] * N for _ in xrange(N)]
            dp[-1][-1] = grid[-1][-1]
            for i in xrange(N - 1, -1, -1):
                for j in xrange(N - 1, -1, -1):
                    if grid[i][j] >= 0 and (i != N - 1 or j != N - 1):
                        dp[i][j] = max(dp[i + 1][j] if i+1 < N else NINF,
                                       dp[i][j + 1] if j+1 < N else NINF)
                        dp[i][j] += grid[i][j]

            if dp[0][0] < 0:
                return None
            ans = [(0, 0)]
            i = j = 0
            while i != N - 1 or j != N - 1:
                if j + 1 == N or i+1 < N and dp[i + 1][j] >= dp[i][j + 1]:
                    i += 1
                else:
                    j += 1
                ans.append((i, j))
            return ans

        ans = 0
        path = bestpath(grid)
        if path is None:
            return 0

        for i, j in path:
            ans += grid[i][j]
            grid[i][j] = 0

        for i, j in bestpath(grid):
            ans += grid[i][j]

        return ans
```

</details>

<br>

## Approach #2: Dynamic Programming (Top Down) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][][] memo;
    int[][] grid;
    int N;
    public int cherryPickup(int[][] grid) {
        this.grid = grid;
        N = grid.length;
        memo = new int[N][N][N];
        for (int[][] layer: memo) {
            for (int[] row: layer) {
                Arrays.fill(row, Integer.MIN_VALUE);
            }
        }
        return Math.max(0, dp(0, 0, 0));
    }
    public int dp(int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (N == r1 || N == r2 || N == c1 || N == c2 ||
                grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -999999;        
        } else if (r1 == N - 1 && c1 == N - 1) {
            return grid[r1][c1];
        } else if (memo[r1][c1][c2] != Integer.MIN_VALUE) {
            return memo[r1][c1][c2];
        } else {
            int ans = grid[r1][c1];
            if (c1 != c2) {
                ans += grid[r2][c2];
            }
            ans += Math.max(Math.max(dp(r1, c1 + 1, c2 + 1), dp(r1 + 1, c1, c2 + 1)),
                            Math.max(dp(r1, c1 + 1, c2), dp(r1 + 1, c1, c2)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        memo = [[[None] * N for _1 in xrange(N)] for _2 in xrange(N)]
        def dp(r1, c1, c2):
            r2 = r1 + c1 - c2
            if (N == r1 or N == r2 or N == c1 or N == c2 or
                    grid[r1][c1] == -1 or grid[r2][c2] == -1):
                return float('-inf')
            elif r1 == c1 == N-1:
                return grid[r1][c1]
            elif memo[r1][c1][c2] is not None:
                return memo[r1][c1][c2]
            else:
                ans = grid[r1][c1] + (c1 != c2) * grid[r2][c2]
                ans += max(dp(r1, c1 + 1, c2 + 1), dp(r1 + 1, c1, c2 + 1),
                           dp(r1, c1 + 1, c2), dp(r1 + 1, c1, c2))

            memo[r1][c1][c2] = ans
            return ans

        return max(0, dp(0, 0, 0))
```

</details>

<br>

## Approach #3: Dynamic Programming (Bottom Up) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int cherryPickup(int[][] grid) {
        int N = grid.length;
        int[][] dp = new int[N][N];
        for (int[] row: dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2*N - 2; ++t) {
            int[][] dp2 = new int[N][N];
            for (int[] row: dp2) {
                Arrays.fill(row, Integer.MIN_VALUE);
            }

            for (int i = Math.max(0, t - (N - 1)); i <= Math.min(N - 1, t); ++i) {
                for (int j = Math.max(0, t - (N - 1)); j <= Math.min(N - 1, t); ++j) {
                    if (grid[i][t - i] == -1 || grid[j][t - j] == -1) {
                        continue;
                    }                    
                    int val = grid[i][t-i];
                    if (i != j) {
                        val += grid[j][t - j];
                    }
                    for (int pi = i - 1; pi <= i; ++pi) {
                        for (int pj = j - 1; pj <= j; ++pj) {
                            if (pi >= 0 && pj >= 0) {
                                dp2[i][j] = Math.max(dp2[i][j], dp[pi][pj] + val);
                            }
                        }
                    }
                }
            }
            dp = dp2;
        }
        return Math.max(0, dp[N - 1][N - 1]);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def cherryPickup(self, grid):
        N = len(grid)
        dp = [[float('-inf')] * N for _ in xrange(N)]
        dp[0][0] = grid[0][0]
        for t in xrange(1, 2 * N - 1):
            dp2 = [[float('-inf')] * N for _ in xrange(N)]
            for i in xrange(max(0, t - (N - 1)), min(N - 1, t) + 1):
                for j in xrange(max(0, t - (N - 1)), min(N - 1, t) + 1):
                    if grid[i][t - i] == -1 or grid[j][t - j] == -1:
                        continue
                    val = grid[i][t - i]
                    if i != j:
                        val += grid[j][t - j]
                    dp2[i][j] = max(dp[pi][pj] + val
                                    for pi in (i - 1, i) for pj in (j - 1, j)
                                    if pi >= 0 and pj >= 0)
            dp = dp2
        return max(0, dp[N - 1][N - 1])
```

</details>
