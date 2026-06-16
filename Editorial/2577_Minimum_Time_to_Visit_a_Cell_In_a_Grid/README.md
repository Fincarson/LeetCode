# 2577. Minimum Time to Visit a Cell In a Grid

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/)  
`Array` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Matrix` `Shortest Path`

**Problem Link:** [LeetCode 2577 - Minimum Time to Visit a Cell In a Grid](https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/)

## Problem

You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

### Example 1

```text
Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.
```

### Example 2

```text
Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 1000
- 4 <= m * n <= 105
- 0 <= grid[i][j] <= 105
- grid[0][0] == 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Minimum Time to Reach Last Room I](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Minimum Time to Reach Last Room II](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2577. Minimum Time to Visit a Cell In a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Modified Dijkstra's Algorithm | C++, Java, Python3 |

## Approach: Modified Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // If both initial moves require more than 1 second, impossible to
        // proceed
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        // Possible movements: down, up, right, left
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Priority queue stores {time, row, col}
        // Ordered by minimum time to reach each cell
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            // Check if reached target
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // Skip if cell already visited
            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            // Try all four directions
            for (auto& d : directions) {
                int nextRow = row + d[0], nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)) {
                    continue;
                }

                // Calculate the wait time needed to move to next cell
                int waitTime =
                    ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }

private:
    // Checks if given cell coordinates are valid and unvisited
    bool isValid(vector<vector<bool>>& visited, int row, int col) {
        return row >= 0 && col >= 0 && row < visited.size() &&
               col < visited[0].size() && !visited[row][col];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumTime(int[][] grid) {
        // If both initial moves require more than 1 second, impossible to proceed
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.length, cols = grid[0].length;
        // Possible movements: down, up, right, left
        int[][] directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        boolean[][] visited = new boolean[rows][cols];

        // Priority queue stores {time, row, col}
        // Ordered by minimum time to reach each cell
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) ->
            Integer.compare(a[0], b[0])
        );
        pq.add(new int[] { grid[0][0], 0, 0 });

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0], row = curr[1], col = curr[2];

            // Check if reached target
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // Skip if cell already visited
            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            // Try all four directions
            for (int[] d : directions) {
                int nextRow = row + d[0], nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)) {
                    continue;
                }

                // Calculate the wait time needed to move to next cell
                int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0)
                    ? 1
                    : 0;
                int nextTime = Math.max(
                    grid[nextRow][nextCol] + waitTime,
                    time + 1
                );
                pq.add(new int[] { nextTime, nextRow, nextCol });
            }
        }
        return -1;
    }

    // Checks if given cell coordinates are valid and unvisited
    private boolean isValid(boolean[][] visited, int row, int col) {
        return (
            row >= 0 &&
            col >= 0 &&
            row < visited.length &&
            col < visited[0].length &&
            !visited[row][col]
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # If both initial moves require more than 1 second, impossible to proceed
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1

        rows, cols = len(grid), len(grid[0])
        # Possible movements: down, up, right, left
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = set()

        # Priority queue stores (time, row, col)
        # Ordered by minimum time to reach each cell
        pq = [(grid[0][0], 0, 0)]

        while pq:
            time, row, col = heapq.heappop(pq)

            # Check if reached target
            if (row, col) == (rows - 1, cols - 1):
                return time

            # Skip if cell already visited
            if (row, col) in visited:
                continue
            visited.add((row, col))

            # Try all four directions
            for dx, dy in directions:
                next_row, next_col = row + dx, col + dy

                if not self._is_valid(visited, next_row, next_col, rows, cols):
                    continue

                # Calculate the wait time needed to move to next cell
                wait_time = (
                    1 if (grid[next_row][next_col] - time) % 2 == 0 else 0
                )
                next_time = max(grid[next_row][next_col] + wait_time, time + 1)
                heapq.heappush(pq, (next_time, next_row, next_col))

        return -1

    # Checks if given cell coordinates are valid and unvisited
    def _is_valid(self, visited, row, col, rows, cols):
        return 0 <= row < rows and 0 <= col < cols and (row, col) not in visited
```

</details>
