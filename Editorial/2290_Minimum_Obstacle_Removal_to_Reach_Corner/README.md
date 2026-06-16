# 2290. Minimum Obstacle Removal to Reach Corner

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)  
`Array` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Matrix` `Shortest Path`

**Problem Link:** [LeetCode 2290 - Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)

## Problem

You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

- 0 represents an empty cell,
- 1 represents an obstacle that may be removed.

You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

### Example 1

```text
Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.
```

### Example 2

```text
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 105
- 2 <= m * n <= 105
- grid[i][j] is either 0 or 1.
- grid[0][0] == grid[m - 1][n - 1] == 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2290. Minimum Obstacle Removal to Reach Corner

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dijkstra's Algorithm | C++, Java, Python3 |
| 0-1 Breadth-First Search (BFS) | C++, Java, Python3 |

## Approach 1: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        // Start from the top-left corner, accounting for its obstacle value
        minObstacles[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        // Add the starting cell to the priority queue
        pq.push({minObstacles[0][0], 0, 0});

        while (!pq.empty()) {
            // Process the cell with the fewest obstacles removed so far
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0], row = current[1], col = current[2];

            // If we've reached the bottom-right corner, return the result
            if (row == m - 1 && col == n - 1) {
                return obstacles;
            }

            // Explore all four possible directions from the current cell
            for (vector<int>& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol)) {
                    // Calculate the obstacles removed if moving to the new cell
                    int newObstacles = obstacles + grid[newRow][newCol];

                    // Update if we've found a path with fewer obstacles to the
                    // new cell
                    if (newObstacles < minObstacles[newRow][newCol]) {
                        minObstacles[newRow][newCol] = newObstacles;
                        pq.push({newObstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

    // Helper method to check if the cell is within the grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    // Directions for movement: right, left, down, up
    private final int[][] directions = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 },
    };

    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        int[][] minObstacles = new int[m][n];

        // Initialize all cells with a large value, representing unvisited cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minObstacles[i][j] = Integer.MAX_VALUE;
            }
        }

        // Start from the top-left corner, accounting for its obstacle value
        minObstacles[0][0] = grid[0][0];

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Add the starting cell to the priority queue
        pq.add(new int[] { minObstacles[0][0], 0, 0 });

        while (!pq.isEmpty()) {
            // Process the cell with the fewest obstacles removed so far
            int[] current = pq.poll();
            int obstacles = current[0], row = current[1], col = current[2];

            // If we've reached the bottom-right corner, return the result
            if (row == m - 1 && col == n - 1) {
                return obstacles;
            }

            // Explore all four possible directions from the current cell
            for (int[] dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol)) {
                    // Calculate the obstacles removed if moving to the new cell
                    int newObstacles = obstacles + grid[newRow][newCol];

                    // Update if we've found a path with fewer obstacles to the new cell
                    if (newObstacles < minObstacles[newRow][newCol]) {
                        minObstacles[newRow][newCol] = newObstacles;
                        pq.add(new int[] { newObstacles, newRow, newCol });
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

    // Helper method to check if the cell is within the grid bounds
    private boolean isValid(int[][] grid, int row, int col) {
        return (
            row >= 0 && col >= 0 && row < grid.length && col < grid[0].length
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions for movement: right, left, down, up
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minimumObstacles(self, grid):
        # Helper method to check if the cell is within the grid bounds
        def _is_valid(row, col):
            return 0 <= row < len(grid) and 0 <= col < len(grid[0])

        m, n = len(grid), len(grid[0])

        # Initialize distance matrix with infinity (large value)
        min_obstacles = [[float("inf")] * n for _ in range(m)]

        # Start from the top-left corner, accounting for its obstacle value
        min_obstacles[0][0] = grid[0][0]

        pq = [(min_obstacles[0][0], 0, 0)]  # (obstacles, row, col)

        while pq:
            obstacles, row, col = heapq.heappop(pq)

            # If we've reached the bottom-right corner, return the result
            if row == m - 1 and col == n - 1:
                return obstacles

            # Explore all four possible directions from the current cell
            for dr, dc in self.directions:
                new_row, new_col = row + dr, col + dc

                if _is_valid(new_row, new_col):
                    # Calculate the obstacles removed if moving to the new cell
                    new_obstacles = obstacles + grid[new_row][new_col]

                    # Update if we've found a path with fewer obstacles to the new cell
                    if new_obstacles < min_obstacles[new_row][new_col]:
                        min_obstacles[new_row][new_col] = new_obstacles
                        heapq.heappush(pq, (new_obstacles, new_row, new_col))

        return min_obstacles[m - 1][n - 1]
```

</details>

<br>

## Approach 2: 0-1 Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Directions for movement: right, left, down, up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Distance matrix to store the minimum obstacles removed to reach each
        // cell
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = 0;

        deque<array<int, 3>> deque;
        deque.push_back({0, 0, 0});  // {obstacles, row, col}

        while (!deque.empty()) {
            auto current = deque.front();
            deque.pop_front();
            int obstacles = current[0], row = current[1], col = current[2];

            // Explore all four possible directions from the current cell
            for (auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        // If it's an obstacle, add 1 to obstacles and push to
                        // the back
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deque.push_back({obstacles + 1, newRow, newCol});
                    } else {
                        // If it's an empty cell, keep the obstacle count and
                        // push to the front
                        minObstacles[newRow][newCol] = obstacles;
                        deque.push_front({obstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

private:
    // Helper method to check if the cell is within the grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    // Directions for movement: right, left, down, up
    private final int[][] directions = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 },
    };

    public int minimumObstacles(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        // Distance matrix to store the minimum obstacles removed to reach each cell
        int[][] minObstacles = new int[m][n];

        // Initialize all cells with a large value, representing unvisited cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minObstacles[i][j] = Integer.MAX_VALUE;
            }
        }

        minObstacles[0][0] = 0;

        Deque<int[]> deque = new ArrayDeque<>();
        deque.add(new int[] { 0, 0, 0 }); // {obstacles, row, col}

        while (!deque.isEmpty()) {
            int[] current = deque.poll();
            int obstacles = current[0], row = current[1], col = current[2];

            // Explore all four possible directions from the current cell
            for (int[] dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (
                    isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == Integer.MAX_VALUE
                ) {
                    if (grid[newRow][newCol] == 1) {
                        // If it's an obstacle, add 1 to obstacles and push to the back
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deque.addLast(
                            new int[] { obstacles + 1, newRow, newCol }
                        );
                    } else {
                        // If it's an empty cell, keep the obstacle count and push to the front
                        minObstacles[newRow][newCol] = obstacles;
                        deque.addFirst(new int[] { obstacles, newRow, newCol });
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

    // Helper method to check if the cell is within the grid bounds
    private boolean isValid(int[][] grid, int row, int col) {
        return (
            row >= 0 && col >= 0 && row < grid.length && col < grid[0].length
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions for movement: right, left, down, up
    _directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minimumObstacles(self, grid):
        # Helper method to check if the cell is within the grid bounds
        def _is_valid(row, col):
            return 0 <= row < len(grid) and 0 <= col < len(grid[0])

        m, n = len(grid), len(grid[0])

        # Distance matrix to store the minimum obstacles removed to reach each cell
        min_obstacles = [[float("inf")] * n for _ in range(m)]
        min_obstacles[0][0] = 0

        deque_cells = deque([(0, 0, 0)])  # (obstacles, row, col)

        while deque_cells:
            obstacles, row, col = deque_cells.popleft()

            # Explore all four possible directions from the current cell
            for dr, dc in self._directions:
                new_row, new_col = row + dr, col + dc

                if _is_valid(new_row, new_col) and min_obstacles[new_row][
                    new_col
                ] == float("inf"):
                    if grid[new_row][new_col] == 1:
                        # If it's an obstacle, add 1 to obstacles and push to the back
                        min_obstacles[new_row][new_col] = obstacles + 1
                        deque_cells.append((obstacles + 1, new_row, new_col))
                    else:
                        # If it's an empty cell, keep the obstacle count and push to the front
                        min_obstacles[new_row][new_col] = obstacles
                        deque_cells.appendleft((obstacles, new_row, new_col))

        return min_obstacles[m - 1][n - 1]
```

</details>
