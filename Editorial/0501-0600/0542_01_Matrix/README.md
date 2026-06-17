# 542. 01 Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/01-matrix/)  
`Array` `Dynamic Programming` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 542 - 01 Matrix](https://leetcode.com/problems/01-matrix/)

## Problem

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

### Example 1

```text
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

### Example 2

```text
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 104
- 1 <= m * n <= 104
- mat[i][j] is either 0 or 1.
- There is at least one 0 in mat.

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Operations to Remove Adjacent Ones in Matrix](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 542. 01 Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<vector<int>> queue;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = mat[row][col];
                if (matrix[row][col] == 0) {
                    queue.push({row, col, 0});
                    seen[row][col] = true;
                }
            }
        }
        
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow, nextCol, steps + 1});
                    matrix[nextRow][nextCol] = steps + 1;
                }
            }
        }
        
        return matrix;
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class State {
    int row;
    int col;
    int steps;
    State(int row, int col, int steps) {
        this.row = row;
        this.col = col;
        this.steps = steps;
    }
}

class Solution {
    int m;
    int n;
    int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    public int[][] updateMatrix(int[][] mat) {
        m = mat.length;
        n = mat[0].length;
        
        int[][] matrix = new int[m][n];
        boolean[][] seen = new boolean[m][n];
        Queue<State> queue = new LinkedList<>();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = mat[row][col];
                if (mat[row][col] == 0) {
                    queue.add(new State(row, col, 0));
                    seen[row][col] = true;
                }
            }
        }
        
        while (!queue.isEmpty()) {
            State state = queue.remove();
            int row = state.row, col = state.col, steps = state.steps;
            
            for (int[] direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    queue.add(new State(nextRow, nextCol, steps + 1));
                    matrix[nextRow][nextCol] = steps + 1;
                }
            }
        }
        
        return matrix;
    }
    
    public boolean valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        def valid(row, col):
            return 0 <= row < m and 0 <= col < n
        
        matrix = [row[:] for row in mat]
        m = len(matrix)
        n = len(matrix[0])
        queue = deque()
        seen = set()
        
        for row in range(m):
            for col in range(n):
                if matrix[row][col] == 0:
                    queue.append((row, col, 0))
                    seen.add((row, col))
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        while queue:
            row, col, steps = queue.popleft()
            
            for dx, dy in directions:
                next_row, next_col = row + dy, col + dx
                if (next_row, next_col) not in seen and valid(next_row, next_col):
                    seen.add((next_row, next_col))
                    queue.append((next_row, next_col, steps + 1))
                    matrix[next_row][next_col] = steps + 1
        
        return matrix
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp;
        
        for (vector<int>& row: mat) {
            dp.emplace_back(row.begin(), row.end());
        }
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (dp[row][col] == 0) {
                    continue;
                }

                int minNeighbor = m * n;
                if (row > 0) {
                    minNeighbor = min(minNeighbor, dp[row - 1][col]);
                }
                
                if (col > 0) {
                    minNeighbor = min(minNeighbor, dp[row][col - 1]);
                }
                
                dp[row][col] = minNeighbor + 1;
            }
        }
        
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (dp[row][col] == 0) {
                    continue;
                }
                
                int minNeighbor = m * n;
                if (row < m - 1) {
                    minNeighbor = min(minNeighbor, dp[row + 1][col]);
                }
                
                if (col < n - 1) {
                    minNeighbor = min(minNeighbor, dp[row][col + 1]);
                }
                
                dp[row][col] = min(dp[row][col], minNeighbor + 1);
            }
        }
        
        return dp;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m][n];
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                dp[row][col] = mat[row][col];
            }
        } 

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (dp[row][col] == 0) {
                    continue;
                }

                int minNeighbor = m * n;
                if (row > 0) {
                    minNeighbor = Math.min(minNeighbor, dp[row - 1][col]);
                }
                
                if (col > 0) {
                    minNeighbor = Math.min(minNeighbor, dp[row][col - 1]);
                }
                
                dp[row][col] = minNeighbor + 1;
            }
        }
        
        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (dp[row][col] == 0) {
                    continue;
                }
                
                int minNeighbor = m * n;
                if (row < m - 1) {
                    minNeighbor = Math.min(minNeighbor, dp[row + 1][col]);
                }
                
                if (col < n - 1) {
                    minNeighbor = Math.min(minNeighbor, dp[row][col + 1]);
                }
                
                dp[row][col] = Math.min(dp[row][col], minNeighbor + 1);
            }
        }
        
        return dp;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        dp = [row[:] for row in mat]
        m, n = len(dp), len(dp[0])

        for row in range(m):
            for col in range(n):
                min_neighbor = inf
                if dp[row][col] != 0:
                    if row > 0:
                        min_neighbor = min(min_neighbor, dp[row - 1][col])
                    if col > 0:
                        min_neighbor = min(min_neighbor, dp[row][col - 1])
                        
                    dp[row][col] = min_neighbor + 1
    
        for row in range(m - 1, -1, -1):
            for col in range(n - 1, -1, -1):
                min_neighbor = inf
                if dp[row][col] != 0:
                    if row < m - 1:
                        min_neighbor = min(min_neighbor, dp[row + 1][col])
                    if col < n - 1:
                        min_neighbor = min(min_neighbor, dp[row][col + 1])
                        
                    dp[row][col] = min(dp[row][col], min_neighbor + 1)

        return dp
```

</details>
