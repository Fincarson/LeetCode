# 2684. Maximum Number of Moves in a Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 2684 - Maximum Number of Moves in a Grid](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/)

## Problem

You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

- From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.

Return the maximum number of moves that you can perform.

### Example 1

```text
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
```

### Example 2

```text
Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 1000
- 4 <= m * n <= 105
- 1 <= grid[i][j] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2684. Maximum Number of Moves in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Bottom-up Dynamic Programming | C++, Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // The three possible directions for the next column.
    const int dirs[3] = {-1, 0, 1};

    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        queue<vector<int>> q;
        vector<vector<int>> vis(M, vector<int>(N, 0));
        // Enqueue the cells in the first column.
        for (int i = 0; i < M; i++) {
            vis[i][0] = 1;
            q.push({i, 0, 0});
        }

        int maxMoves = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                vector<int> v = q.front();
                q.pop();

                // Current cell with the number of moves made so far.
                int row = v[0], col = v[1], count = v[2];

                maxMoves = max(maxMoves, count);

                for (int dir : dirs) {
                    // Next cell after the move.
                    int newRow = row + dir, newCol = col + 1;

                    // If the next cell isn't visited yet and is greater than
                    // the current cell value. Add it to the queue with the
                    // moves required.
                    if (newRow >= 0 && newCol >= 0 && newRow < M &&
                        newCol < N && !vis[newRow][newCol] &&
                        grid[row][col] < grid[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol, count + 1});
                    }
                }
            }
        }

        return maxMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // The three possible directions for the next column.
    private final int[] dirs = { -1, 0, 1 };

    public int maxMoves(int[][] grid) {
        int M = grid.length, N = grid[0].length;

        Queue<int[]> q = new LinkedList<>();
        boolean[][] vis = new boolean[M][N];

        // Enqueue the cells in the first column.
        for (int i = 0; i < M; i++) {
            vis[i][0] = true;
            q.offer(new int[] { i, 0, 0 });
        }

        int maxMoves = 0;
        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                int[] v = q.poll();

                // Current cell with the number of moves made so far.
                int row = v[0], col = v[1], count = v[2];

                maxMoves = Math.max(maxMoves, count);

                for (int dir : dirs) {
                    // Next cell after the move.
                    int newRow = row + dir, newCol = col + 1;

                    // If the next cell isn't visited yet and is greater than
                    // the current cell value, add it to the queue with the
                    // incremented move count.
                    if (
                        newRow >= 0 &&
                        newCol >= 0 &&
                        newRow < M &&
                        newCol < N &&
                        !vis[newRow][newCol] &&
                        grid[row][col] < grid[newRow][newCol]
                    ) {
                        vis[newRow][newCol] = true;
                        q.offer(new int[] { newRow, newCol, count + 1 });
                    }
                }
            }
        }

        return maxMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # The three possible directions for the next column.
    dirs = [-1, 0, 1]

    def maxMoves(self, grid):
        M, N = len(grid), len(grid[0])

        q = deque()
        vis = [[False] * N for _ in range(M)]

        # Enqueue the cells in the first column.
        for i in range(M):
            vis[i][0] = True
            q.append((i, 0, 0))

        max_moves = 0
        while q:
            sz = len(q)

            for _ in range(sz):
                row, col, count = q.popleft()

                # Update the maximum moves made so far.
                max_moves = max(max_moves, count)

                for dir in self.dirs:
                    # Next cell after the move.
                    new_row, new_col = row + dir, col + 1

                    # If the next cell isn't visited yet and is greater than
                    # the current cell value, add it to the queue with the
                    # incremented move count.
                    if (
                        0 <= new_row < M
                        and 0 <= new_col < N
                        and not vis[new_row][new_col]
                        and grid[row][col] < grid[new_row][new_col]
                    ):
                        vis[new_row][new_col] = True
                        q.append((new_row, new_col, count + 1))

        return max_moves
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // The three possible directions for the next column.
    const int dirs[3] = {-1, 0, 1};

    int DFS(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& dp) {
        int M = grid.size(), N = grid[0].size();

        // If we have calculated the moves required for this cell, return the
        // answer and skip the recursion.
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int maxMoves = 0;
        for (int dir : dirs) {
            // Next cell after the move.
            int newRow = row + dir, newCol = col + 1;

            // If the next cell is valid and greater than the current cell
            // value, perform recursion to that cell with updated value of
            // moves.
            if (newRow >= 0 && newCol >= 0 && newRow < M && newCol < N &&
                grid[row][col] < grid[newRow][newCol]) {
                maxMoves = max(maxMoves, 1 + DFS(newRow, newCol, grid, dp));
            }
        }

        return dp[row][col] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> dp(M, vector<int>(N, -1));

        int maxMoves = 0;
        for (int i = 0; i < M; i++) {
            int movesRequired = DFS(i, 0, grid, dp);

            maxMoves = max(maxMoves, movesRequired);
        }

        return maxMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // The three possible directions for the next column.
    private final int[] dirs = { -1, 0, 1 };

    private int DFS(int row, int col, int[][] grid, int[][] dp) {
        int M = grid.length, N = grid[0].length;

        // If we have calculated the moves required for this cell, return the answer and skip the recursion.
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int maxMoves = 0;
        for (int dir : dirs) {
            // Next cell after the move.
            int newRow = row + dir, newCol = col + 1;

            // If the next cell is valid and greater than the current cell value,
            // perform recursion to that cell with updated value of moves.
            if (
                newRow >= 0 &&
                newCol >= 0 &&
                newRow < M &&
                newCol < N &&
                grid[row][col] < grid[newRow][newCol]
            ) {
                maxMoves = Math.max(
                    maxMoves,
                    1 + DFS(newRow, newCol, grid, dp)
                );
            }
        }

        dp[row][col] = maxMoves;
        return maxMoves;
    }

    public int maxMoves(int[][] grid) {
        int M = grid.length, N = grid[0].length;

        int[][] dp = new int[M][N];
        for (int i = 0; i < M; i++) {
            Arrays.fill(dp[i], -1);
        }

        int maxMoves = 0;
        // Start DFS from each cell in the first column.
        for (int i = 0; i < M; i++) {
            int movesRequired = DFS(i, 0, grid, dp);
            maxMoves = Math.max(maxMoves, movesRequired);
        }

        return maxMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # The three possible directions for the next column.
    dirs = [-1, 0, 1]

    def DFS(self, row, col, grid, dp):
        M, N = len(grid), len(grid[0])

        # If we have already calculated the moves required for this cell, return the answer.
        if dp[row][col] != -1:
            return dp[row][col]

        max_moves = 0
        for dir in self.dirs:
            # Next cell after the move.
            new_row, new_col = row + dir, col + 1

            # If the next cell is valid and greater than the current cell value,
            # perform recursion to that cell with updated value of moves.
            if (
                0 <= new_row < M
                and 0 <= new_col < N
                and grid[row][col] < grid[new_row][new_col]
            ):
                max_moves = max(
                    max_moves, 1 + self.DFS(new_row, new_col, grid, dp)
                )

        dp[row][col] = max_moves
        return max_moves

    def maxMoves(self, grid):
        M, N = len(grid), len(grid[0])

        # Initialize the dp array with -1 indicating uncomputed cells.
        dp = [[-1] * N for _ in range(M)]

        max_moves = 0
        # Start DFS from each cell in the first column.
        for i in range(M):
            moves_required = self.DFS(i, 0, grid, dp)
            max_moves = max(max_moves, moves_required)

        return max_moves
```

</details>

<br>

## Approach 3: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> dp(M, vector<int>(N, 0));
        // Cells in the first column will have the moves as 1.
        // This is required to ensure we have a way if the cell reachable or not
        // from the first column.
        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        int maxMoves = 0;
        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {
                // Check all the three next possible cells
                // Check if the next cell is greater than the previous one
                // Check if the previous cell was reachable, if the value is > 0
                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                }

                maxMoves = max(maxMoves, dp[i][j] - 1);
            }
        }

        return maxMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxMoves(int[][] grid) {
        int M = grid.length, N = grid[0].length;

        int[][] dp = new int[M][N];
        // Cells in the first column will have the moves as 1.
        // This is required to ensure we have a way if the cell is reachable or not
        // from the first column.
        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        int maxMoves = 0;
        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {
                // Check all the three next possible cells
                // Check if the next cell is greater than the previous one
                // Check if the previous cell was reachable,
                // if the value is > 0
                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (
                    i - 1 >= 0 &&
                    grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][j - 1] > 0
                ) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (
                    i + 1 < M &&
                    grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][j - 1] > 0
                ) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 1);
                }

                maxMoves = Math.max(maxMoves, dp[i][j] - 1);
            }
        }

        return maxMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxMoves(self, grid):
        M, N = len(grid), len(grid[0])

        # Create a 2D list for dp, initialized to 0.
        dp = [[0] * N for _ in range(M)]

        # Initialize the first column with moves as 1.
        for i in range(M):
            dp[i][0] = 1

        max_moves = 0
        for j in range(1, N):
            for i in range(M):
                # Check all three possible previous cells:
                # (i, j-1), (i-1, j-1), (i+1, j-1)
                if grid[i][j] > grid[i][j - 1] and dp[i][j - 1] > 0:
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1)
                if (
                    i - 1 >= 0
                    and grid[i][j] > grid[i - 1][j - 1]
                    and dp[i - 1][j - 1] > 0
                ):
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
                if (
                    i + 1 < M
                    and grid[i][j] > grid[i + 1][j - 1]
                    and dp[i + 1][j - 1] > 0
                ):
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1)

                max_moves = max(max_moves, dp[i][j] - 1)

        return max_moves
```

</details>

<br>

## Approach 4: Space-Optimized Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();

        vector<vector<int>> dp(M, vector<int>(2, 0));

        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        int maxMoves = 0;
        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {
                if (grid[i][j] > grid[i][j - 1] && dp[i][0] > 0) {
                    dp[i][1] = max(dp[i][1], dp[i][0] + 1);
                }
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][0] > 0) {
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
                }
                if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][0] > 0) {
                    dp[i][1] = max(dp[i][1], dp[i + 1][0] + 1);
                }

                maxMoves = max(maxMoves, dp[i][1] - 1);
            }

            for (int k = 0; k < M; k++) {
                dp[k][0] = dp[k][1];
                dp[k][1] = 0;
            }
        }

        return maxMoves;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxMoves(int[][] grid) {
        int M = grid.length, N = grid[0].length;

        // Create a dp array to store moves, with each cell having a size of 2.
        int[][] dp = new int[M][2];

        // Initialize the first column cells as reachable.
        for (int i = 0; i < M; i++) {
            dp[i][0] = 1;
        }

        int maxMoves = 0;

        // Iterate over each column starting from the second one.
        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {
                // Check if moving from the same row
                // of the previous column is possible.
                if (grid[i][j] > grid[i][j - 1] && dp[i][0] > 0) {
                    dp[i][1] = Math.max(dp[i][1], dp[i][0] + 1);
                }
                // Check if moving from the upper diagonal is possible.
                if (
                    i - 1 >= 0 &&
                    grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][0] > 0
                ) {
                    dp[i][1] = Math.max(dp[i][1], dp[i - 1][0] + 1);
                }
                // Check if moving from the lower diagonal is possible.
                if (
                    i + 1 < M &&
                    grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][0] > 0
                ) {
                    dp[i][1] = Math.max(dp[i][1], dp[i + 1][0] + 1);
                }

                // Update the maximum moves so far.
                maxMoves = Math.max(maxMoves, dp[i][1] - 1);
            }

            // Shift dp values for the next iteration.
            for (int k = 0; k < M; k++) {
                dp[k][0] = dp[k][1];
                dp[k][1] = 0;
            }
        }

        return maxMoves;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])

        # Create a dp array to store moves, with each cell having a size of 2.
        dp = [[0] * 2 for _ in range(M)]

        # Initialize the first column cells as reachable.
        for i in range(M):
            dp[i][0] = 1

        max_moves = 0

        # Iterate over each column starting from the second one.
        for j in range(1, N):
            for i in range(M):
                # Check if moving from the same row of the previous column is possible.
                if grid[i][j] > grid[i][j - 1] and dp[i][0] > 0:
                    dp[i][1] = max(dp[i][1], dp[i][0] + 1)

                # Check if moving from the upper diagonal is possible.
                if (
                    i - 1 >= 0
                    and grid[i][j] > grid[i - 1][j - 1]
                    and dp[i - 1][0] > 0
                ):
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1)

                # Check if moving from the lower diagonal is possible.
                if (
                    i + 1 < M
                    and grid[i][j] > grid[i + 1][j - 1]
                    and dp[i + 1][0] > 0
                ):
                    dp[i][1] = max(dp[i][1], dp[i + 1][0] + 1)

                # Update the maximum moves so far.
                max_moves = max(max_moves, dp[i][1] - 1)

            # Shift dp values for the next iteration.
            for k in range(M):
                dp[k][0] = dp[k][1]
                dp[k][1] = 0

        return max_moves
```

</details>
