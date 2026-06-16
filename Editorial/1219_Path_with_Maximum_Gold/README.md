# 1219. Path with Maximum Gold

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/path-with-maximum-gold/)  
`Array` `Backtracking` `Matrix`

**Problem Link:** [LeetCode 1219 - Path with Maximum Gold](https://leetcode.com/problems/path-with-maximum-gold/)

## Problem

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

- Every time you are located in a cell you will collect all the gold in that cell.
- From your position, you can walk one step to the left, right, up, or down.
- You can't visit the same cell more than once.
- Never visit a cell with 0 gold.
- You can start and stop collecting gold from any position in the grid that has some gold.

### Example 1

```text
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
```

### Example 2

```text
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 15
- 0 <= grid[i][j] <= 100
- There are at most 25 cells containing gold.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1219. Path with Maximum Gold

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search with Backtracking | C++, Java, Python3 |
| Breadth-First Search with Backtracking | C++, Java, Python3 |

## Approach 1: Depth-First Search with Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;

        // Search for the path with the maximum gold starting from each cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxGold =
                    max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int dfsBacktrack(vector<vector<int>>& grid, int rows, int cols, int row,
                     int col) {
        // Base case: this cell is not in the matrix or this cell has no gold
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;

        // Mark the cell as visited and save the value
        int originalVal = grid[row][col];
        grid[row][col] = 0;

        // Backtrack in each of the four directions
        for (int direction = 0; direction < 4; direction++) {
            maxGold =
                max(maxGold,
                    dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row,
                                 DIRECTIONS[direction + 1] + col));
        }

        // Set the cell back to its original value
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private final int[] DIRECTIONS = new int[] { 0, 1, 0, -1, 0 };

    public int getMaximumGold(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int maxGold = 0;

        // Search for the path with the maximum gold starting from each cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxGold = Math.max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
            }
        }
        return maxGold;
    }

    private int dfsBacktrack(int[][] grid, int rows, int cols, int row, int col) {
        // Base case: this cell is not in the matrix or this cell has no gold
        if (row < 0 || col < 0 || row == rows || col == cols || grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;

        // Mark the cell as visited and save the value
        int originalVal = grid[row][col];
        grid[row][col] = 0;

        // Backtrack in each of the four directions
        for (int direction = 0; direction < 4; direction++) {
            maxGold = Math.max(maxGold,
                    dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row,
                            DIRECTIONS[direction + 1] + col));
        }

        // Set the cell back to its original value
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        DIRECTIONS = [0, 1, 0, -1, 0]
        rows = len(grid)
        cols = len(grid[0])
        max_gold = 0

        def dfs_backtrack(grid, rows, cols, row, col):
            # Base case: this cell is not in the matrix or has no gold
            if row < 0 or col < 0 or row == rows or col == cols or \
                    grid[row][col] == 0:
                return 0
            max_gold = 0

            # Mark the cell as visited and save the value
            original_val = grid[row][col]
            grid[row][col] = 0

            # Backtrack in each of the four directions
            for direction in range(4):
                max_gold = max(max_gold,
                               dfs_backtrack(grid, rows, cols, 
                                             DIRECTIONS[direction] + row,
                                             DIRECTIONS[direction + 1] + col))

            # Set the cell back to its original value
            grid[row][col] = original_val
            return max_gold + original_val

        # Search for the path with the maximum gold starting from each cell
        for row in range(rows):
            for col in range(cols):
                max_gold = max(max_gold, dfs_backtrack(grid, rows, cols, row, 
                                                       col))
        return max_gold
```

</details>

<br>

## Approach 2: Breadth-First Search with Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        //  Find the total amount of gold in the grid
        int totalGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                totalGold += grid[row][col];
            }
        }
        
        int maxGold = 0;

        // Search for the path with the maximum gold starting from each cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != 0) {
                    maxGold = max(maxGold, bfsBacktrack(grid, rows, cols, row, col));
                    // If we found a path with the total gold, it's the max gold
                    if (maxGold == totalGold)
                        return totalGold;
                }
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int bfsBacktrack(vector<vector<int>>& grid,
                      int rows, int cols, int row, int col) {
        queue<tuple<int, int, int, bitset<1024>>> queue;
        bitset<1024> visited;
        int maxGold = 0;
        visited[row * cols + col] = 1;
        queue.push({row, col, grid[row][col], visited});

        while (!queue.empty()) {
            auto [currRow, currCol, currGold, currVis] = queue.front();
            queue.pop();
            maxGold = max(maxGold, currGold);

            // Search for gold in each of the 4 neighbor cells
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = currRow + DIRECTIONS[direction];
                int nextCol = currCol + DIRECTIONS[direction + 1];

                // If the next cell is in the matrix, has gold, 
                // and has not been visited, add it to the queue
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                        grid[nextRow][nextCol] != 0 &&
                        !currVis[nextRow * cols + nextCol]) {
                    currVis[nextRow * cols + nextCol] = 1;
                    queue.push({nextRow, nextCol, currGold + grid[nextRow][nextCol], 
                                currVis});
                    currVis[nextRow * cols + nextCol] = 0;
                }
            }
        }
        return maxGold;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private final int[] DIRECTIONS = new int[] { 0, 1, 0, -1, 0 };
    public int getMaximumGold(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Find the total amount of gold in the grid
        int totalGold = 0;
        for (int[] row : grid) {
            for (int cell : row) {
                totalGold += cell;
            }
        }

        // Search for the path with the maximum gold starting from each cell
        int maxGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != 0) {
                    maxGold = Math.max(maxGold, bfsBacktrack(grid, rows, cols, row, col));
                    // If we found a path with the total gold, it's the max gold
                    if (maxGold == totalGold) {
                        return totalGold;
                    }
                }
            }
        }
        return maxGold;
    }

    // Helper function to perform BFS
    private int bfsBacktrack(int[][] grid, int rows, int cols, int row, int col) {
        Queue<Pair<int[], Set<String>>> queue = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        int maxGold = 0;
        visited.add(row + "," + col);
        queue.offer(new Pair<>(new int[] { row, col, grid[row][col] }, visited));

        while (!queue.isEmpty()) {
            Pair<int[], Set<String>> current = queue.poll();
            int currRow = current.getKey()[0];
            int currCol = current.getKey()[1];
            int currGold = current.getKey()[2];
            Set<String> currVis = current.getValue();
            maxGold = Math.max(maxGold, currGold);

            // Search for gold in each of the 4 neighbor cells
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = currRow + DIRECTIONS[direction];
                int nextCol = currCol + DIRECTIONS[direction + 1];

                // If the next cell is in the matrix, has gold,
                // and has not been visited, add it to the queue
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                        grid[nextRow][nextCol] != 0 &&
                        !currVis.contains(nextRow + "," + nextCol)) {
                    
                    currVis.add(nextRow + "," + nextCol);
                    Set<String> copyVis = new HashSet<>(currVis);
                    queue.offer(new Pair<>(new int[] { nextRow, nextCol, 
                                           currGold + grid[nextRow][nextCol]}, copyVis));
                    currVis.remove(nextRow + "," + nextCol);

                }
            }
        }
        return maxGold;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        DIRECTIONS = [0, 1, 0, -1, 0]
        rows = len(grid)
        cols = len(grid[0])
        
        def bfs_backtrack(row: int, col: int) -> int:
            queue = deque()
            visited = set()
            max_gold = 0
            visited.add((row, col))
            queue.append((row, col, grid[row][col], visited))
            while queue:
                curr_row, curr_col, curr_gold, curr_vis = queue.popleft()
                max_gold = max(max_gold, curr_gold)

                # Search for gold in each of the 4 neighbor cells
                for direction in range(4):
                    next_row = curr_row + DIRECTIONS[direction]
                    next_col = curr_col + DIRECTIONS[direction + 1]

                    # If the next cell is in the matrix, has gold, 
                    # and has not been visited, add it to the queue
                    if 0 <= next_row < rows and 0 <= next_col < cols and \
                            grid[next_row][next_col] != 0 and \
                            (next_row, next_col) not in curr_vis:
                        curr_vis.add((next_row, next_col))
                        queue.append((next_row, next_col, 
                                      curr_gold + grid[next_row][next_col], 
                                      curr_vis.copy()))
                        curr_vis.remove((next_row, next_col))
            return max_gold

        # Find the total amount of gold in the grid
        total_gold = sum(sum(row) for row in grid)
        
        # Search for the path with the maximum gold starting from each cell
        max_gold = 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] != 0:
                    max_gold = max(max_gold, bfs_backtrack(row, col))
                    # If we found a path with the total gold, it's the max gold
                    if max_gold == total_gold:
                        return total_gold
        return max_gold
```

</details>
