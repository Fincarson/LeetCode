# 576. Out of Boundary Paths

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/out-of-boundary-paths/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 576 - Out of Boundary Paths](https://leetcode.com/problems/out-of-boundary-paths/)

## Problem

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

### Example 1

```text
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
```

### Example 2

```text
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
```

## Constraints

- 1 <= m, n <= 50
- 0 <= maxMove <= 50
- 0 <= startRow < m
- 0 <= startColumn < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Execution of All Suffix Instructions Staying in a Grid](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 576. Out of Boundary Paths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Recursion with Memoization | Java |
| Dynamic Programming | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findPaths(int m, int n, int N, int i, int j) {
    if (i == m || j == n || i < 0 || j < 0) return 1;
    if (N == 0) return 0;
    return findPaths(m, n, N - 1, i - 1, j)
        + findPaths(m, n, N - 1, i + 1, j)
        + findPaths(m, n, N - 1, i, j - 1)
        + findPaths(m, n, N - 1, i, j + 1);
  }
}
```

</details>

<br>

## Approach 2: Recursion with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  int M = 1000000007;

  public int findPaths(int m, int n, int N, int i, int j) {
    int[][][] memo = new int[m][n][N + 1];
    for (int[][] l : memo) for (int[] sl : l) Arrays.fill(sl, -1);
    return findPaths(m, n, N, i, j, memo);
  }

  public int findPaths(int m, int n, int N, int i, int j, int[][][] memo) {
    if (i == m || j == n || i < 0 || j < 0) return 1;
    if (N == 0) return 0;
    if (memo[i][j][N] >= 0) return memo[i][j][N];
    memo[i][j][N] = (
        (findPaths(m, n, N - 1, i - 1, j, memo) + findPaths(m, n, N - 1, i + 1, j, memo)) % M +
        (findPaths(m, n, N - 1, i, j - 1, memo) + findPaths(m, n, N - 1, i, j + 1, memo)) % M
    ) % M;
    return memo[i][j][N];
  }
}
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findPaths(int m, int n, int N, int x, int y) {
    int M = 1000000000 + 7;
    int dp[][] = new int[m][n];
    dp[x][y] = 1;
    int count = 0;
    for (int moves = 1; moves <= N; moves++) {
      int[][] temp = new int[m][n];
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i == m - 1) count = (count + dp[i][j]) % M;
          if (j == n - 1) count = (count + dp[i][j]) % M;
          if (i == 0) count = (count + dp[i][j]) % M;
          if (j == 0) count = (count + dp[i][j]) % M;
          temp[i][j] = (
              ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
              ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M
          ) % M;
        }
      }
      dp = temp;
    }
    return count;
  }
}
```

</details>
