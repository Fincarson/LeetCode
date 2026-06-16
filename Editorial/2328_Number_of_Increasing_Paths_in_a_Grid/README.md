# 2328. Number of Increasing Paths in a Grid

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/)  
`Array` `Dynamic Programming` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort` `Memoization` `Matrix`

**Problem Link:** [LeetCode 2328 - Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/)

## Problem

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

### Example 1

```text
Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
```

### Example 2

```text
Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 1 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Strictly Increasing Cells in a Matrix](https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2328. Number of Increasing Paths in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting + DP. | Java, Python3 |
| DFS with Memoization | Java, Python3 |

## Approach 1: Sorting + DP.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countPaths(int[][] grid) {
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.length, n = grid[0].length;
        int mod = 1_000_000_007;
        
        // Initialize dp, 1 stands for the path made by a cell itself.
        int[][] dp = new int[m][n];
        Arrays.stream(dp).forEach(row -> Arrays.fill(row, 1));
        
        // Sort all cells by value.
        int[][] cellList = new int[m * n][2];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = i * n + j;
                cellList[index][0] = i;
                cellList[index][1] = j;
            }      
        }
        Arrays.sort(cellList, (a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]);
        
        // Iterate over the sorted cells, for each cell grid[i][j]: 
        for (int[] cell : cellList) {
            int i = cell[0], j = cell[1];

            // Check its four neighbor cells, if a neighbor cell grid[currI][currJ] has a
            // larger value, increment dp[currI][currJ] by dp[i][j]
            for (int[] d : directions) {
                int currI = i + d[0], currJ = j + d[1];
                if (0 <= currI && currI < m && 0 <= currJ && currJ < n
                   && grid[currI][currJ] > grid[i][j]) {
                    dp[currI][currJ] += dp[i][j];
                    dp[currI][currJ] %= mod;
                }
            }
        }
        
        // Sum over dp[i][j].
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer += dp[i][j];
                answer %= mod;
            }
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10 ** 9 + 7
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        # Initialize dp, 1 stands for the path made by a cell itself.
        dp = [[1] * n for _ in range(m)]

        # Sort all cells by value.
        cell_list = [[i, j] for i in range(m) for j in range(n)]
        cell_list.sort(key = lambda x: grid[x[0]][x[1]])
        
        # Iterate over the sorted cells, for each cell grid[i][j]: 
        for i, j in cell_list:
            # Check its four neighbor cells, if a neighbor cell grid[curr_i][curr_j] has a
            # larger value, increment dp[curr_i][curr_j] by dp[i][j]
            for di, dj in directions:
                curr_i, curr_j = i + di, j + dj
                if 0 <= curr_i < m and 0 <= curr_j < n and grid[curr_i][curr_j] > grid[i][j]:
                    dp[curr_i][curr_j] += dp[i][j]
                    dp[curr_i][curr_j] %= mod
        
        # Sum over dp[i][j].
        return sum(sum(row) % mod for row in dp) % mod
```

</details>

<br>

## Approach 2: DFS with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] dp;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int mod = 1_000_000_007;
    
    int dfs(int[][] grid, int i, int j) {
        // If dp[i][j] is non-zero, it means we have got the value of dfs(i, j),
        // so just return dp[i][j].
        if (dp[i][j] != -1)
            return dp[i][j];

        // Otherwise, set answer = 1, the path made of grid[i][j] itself.
        int answer = 1;

        // Check its four neighbor cells, if a neighbor cell grid[prevI][prevJ] has a
        // smaller value, we move to this cell and solve the subproblem: dfs(prevI, prevJ).
        for (int[] d : directions) {
            int prevI = i + d[0], prevJ = j + d[1];
            if (0 <= prevI && prevI < grid.length && 0 <= prevJ && 
                prevJ < grid[0].length && grid[prevI][prevJ] < grid[i][j]) {
                answer += dfs(grid, prevI, prevJ);
                answer %= mod;
            }
        }

        // Update dp[i][j], so that we don't recalculate its value later.
        dp[i][j] = answer;
        return answer;
    }
    
    public int countPaths(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        dp = new int[m][n];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }

        // Iterate over all cells grid[i][j] and sum over dfs(i, j).
        int answer = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer = (answer + dfs(grid, i, j)) % mod;
            }
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPaths(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10 ** 9 + 7
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        dp = [[-1] * n for _ in range(m)]
        
        def dfs(i, j):
            # If dp[i][j] is non-zero, it means we have got the value of dfs(i, j),
            # so just return dp[i][j].
            if dp[i][j] != -1:
                return dp[i][j]

            # Otherwise, set answer = 1, the path made of grid[i][j] itself.
            answer = 1

            # Check its four neighbor cells, if a neighbor cell grid[prevI][prevJ] has a
            # smaller value, we move to this cell and solve the subproblem: dfs(prevI, prevJ).
            for di, dj in directions:
                prev_i, prev_j = i + di, j + dj
                if 0 <= prev_i < m and 0 <= prev_j < n and grid[prev_i][prev_j] < grid[i][j]:
                    answer += dfs(prev_i, prev_j) % mod
            
            # Update dp[i][j], so that we don't recalculate its value later.
            dp[i][j] = answer
            return answer
        
        # Iterate over all cells grid[i][j] and sum over dfs(i, j).
        return sum(dfs(i, j) for i in range(m) for j in range(n)) % mod
```

</details>
