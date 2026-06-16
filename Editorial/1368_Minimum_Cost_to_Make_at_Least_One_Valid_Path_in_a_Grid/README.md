# 1368. Minimum Cost to Make at Least One Valid Path in a Grid

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)  
`Array` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Matrix` `Shortest Path`

**Problem Link:** [LeetCode 1368 - Minimum Cost to Make at Least One Valid Path in a Grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

## Problem

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

- 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
- 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
- 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
- 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

### Example 1

```text
Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.
```

### Example 2

```text
Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).
```

### Example 3

```text
Input: grid = [[1,2],[4,3]]
Output: 1
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- 1 <= grid[i][j] <= 4

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Weighted Subgraph With the Required Paths](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Disconnect Path in a Binary Matrix by at Most One Flip](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1368. Minimum Cost to Make at Least One Valid Path in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Dijkstra's Algorithm | C++, Java, Python3 |
| 0-1 Breadth-First Search | C++, Java, Python3 |
| Depth-First Search + Breadth-First Search | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        vector<vector<int>> minChanges(numRows, vector<int>(numCols, INT_MAX));

        // Initialize all cells with max value
        minChanges[0][0] = 0;

        while (true) {
            // Store previous state to check for convergence
            vector<vector<int>> prevState = minChanges;

            // Forward pass: check cells coming from left and top
            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numCols; col++) {
                    // Check cell above
                    if (row > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row - 1][col] +
                                    (grid[row - 1][col] == 3 ? 0 : 1));
                    }
                    // Check cell to the left
                    if (col > 0) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col - 1] +
                                    (grid[row][col - 1] == 1 ? 0 : 1));
                    }
                }
            }

            // Backward pass: check cells coming from right and bottom
            for (int row = numRows - 1; row >= 0; row--) {
                for (int col = numCols - 1; col >= 0; col--) {
                    // Check cell below
                    if (row < numRows - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row + 1][col] +
                                    (grid[row + 1][col] == 4 ? 0 : 1));
                    }
                    // Check cell to the right
                    if (col < numCols - 1) {
                        minChanges[row][col] =
                            min(minChanges[row][col],
                                minChanges[row][col + 1] +
                                    (grid[row][col + 1] == 2 ? 0 : 1));
                    }
                }
            }

            // If no changes were made in this iteration, we've found optimal
            // solution
            if (prevState == minChanges) {
                break;
            }
        }

        return minChanges[numRows - 1][numCols - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(int[][] grid) {
        int numRows = grid.length, numCols = grid[0].length;
        int[][] minChanges = new int[numRows][numCols];

        // Initialize all cells with max value
        for (int[] row : minChanges) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        minChanges[0][0] = 0;

        while (true) {
            // Store previous state to check for convergence
            int[][] prevState = new int[numRows][numCols];
            for (int row = 0; row < numRows; row++) {
                prevState[row] = Arrays.copyOf(minChanges[row], numCols);
            }

            // Forward pass: check cells coming from left and top
            for (int row = 0; row < numRows; row++) {
                for (int col = 0; col < numCols; col++) {
                    // Check cell above
                    if (row > 0) {
                        minChanges[row][col] = Math.min(
                            minChanges[row][col],
                            minChanges[row - 1][col] +
                            (grid[row - 1][col] == 3 ? 0 : 1)
                        );
                    }
                    // Check cell to the left
                    if (col > 0) {
                        minChanges[row][col] = Math.min(
                            minChanges[row][col],
                            minChanges[row][col - 1] +
                            (grid[row][col - 1] == 1 ? 0 : 1)
                        );
                    }
                }
            }

            // Backward pass: check cells coming from right and bottom
            for (int row = numRows - 1; row >= 0; row--) {
                for (int col = numCols - 1; col >= 0; col--) {
                    // Check cell below
                    if (row < numRows - 1) {
                        minChanges[row][col] = Math.min(
                            minChanges[row][col],
                            minChanges[row + 1][col] +
                            (grid[row + 1][col] == 4 ? 0 : 1)
                        );
                    }
                    // Check cell to the right
                    if (col < numCols - 1) {
                        minChanges[row][col] = Math.min(
                            minChanges[row][col],
                            minChanges[row][col + 1] +
                            (grid[row][col + 1] == 2 ? 0 : 1)
                        );
                    }
                }
            }

            // If no changes were made in this iteration, we've found optimal solution
            if (Arrays.deepEquals(prevState, minChanges)) {
                break;
            }
        }

        return minChanges[numRows - 1][numCols - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        num_rows, num_cols = len(grid), len(grid[0])

        # Initialize all cells with max value
        min_changes = [[float("inf")] * num_cols for _ in range(num_rows)]
        min_changes[0][0] = 0

        while True:
            # Store previous state to check for convergence
            prev_state = [row[:] for row in min_changes]

            # Forward pass: check cells coming from left and top
            for row in range(num_rows):
                for col in range(num_cols):
                    # Check cell above
                    if row > 0:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row - 1][col]
                            + (0 if grid[row - 1][col] == 3 else 1),
                        )
                    # Check cell to the left
                    if col > 0:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row][col - 1]
                            + (0 if grid[row][col - 1] == 1 else 1),
                        )

            # Backward pass: check cells coming from right and bottom
            for row in range(num_rows - 1, -1, -1):
                for col in range(num_cols - 1, -1, -1):
                    # Check cell below
                    if row < num_rows - 1:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row + 1][col]
                            + (0 if grid[row + 1][col] == 4 else 1),
                        )
                    # Check cell to the right
                    if col < num_cols - 1:
                        min_changes[row][col] = min(
                            min_changes[row][col],
                            min_changes[row][col + 1]
                            + (0 if grid[row][col + 1] == 2 else 1),
                        )
            # If no changes were made in this iteration, we've found optimal solution
            if min_changes == prev_state:
                break

        return min_changes[num_rows - 1][num_cols - 1]
```

</details>

<br>

## Approach 2: Dijkstra's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Min-heap ordered by cost. Each element is {cost, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));
        minCost[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost) continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols) {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    int[][] dirs = new int[][] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public int minCost(int[][] grid) {
        int numRows = grid.length, numCols = grid[0].length;

        // Min-heap ordered by cost. Each element is [cost, row, col]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[] { 0, 0, 0 });

        // Track minimum cost to reach each cell
        int[][] minCost = new int[numRows][numCols];
        for (int row = 0; row < numRows; row++) {
            Arrays.fill(minCost[row], Integer.MAX_VALUE);
        }
        minCost[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int cost = curr[0], row = curr[1], col = curr[2];

            // Skip if we've found a better path to this cell
            if (minCost[row][col] != cost) continue;

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                // Check if new position is valid
                if (
                    newRow >= 0 &&
                    newRow < numRows &&
                    newCol >= 0 &&
                    newCol < numCols
                ) {
                    // Add cost=1 if we need to change direction
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    // Update if we found a better path
                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.offer(new int[] { newCost, newRow, newCol });
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    _dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minCost(self, grid: List[List[int]]) -> int:
        num_rows, num_cols = len(grid), len(grid[0])

        # Min-heap ordered by cost. Each element is (cost, row, col)
        pq = [(0, 0, 0)]  # Using list as heap, elements are tuples
        min_cost = [[float("inf")] * num_cols for _ in range(num_rows)]
        min_cost[0][0] = 0

        while pq:
            cost, row, col = heapq.heappop(pq)

            # Skip if we've found a better path to this cell
            if min_cost[row][col] != cost:
                continue

            # Try all four directions
            for d, (dx, dy) in enumerate(self._dirs):
                new_row, new_col = row + dx, col + dy

                # Check if new position is valid
                if 0 <= new_row < num_rows and 0 <= new_col < num_cols:
                    # Add cost=1 if we need to change direction
                    new_cost = cost + (d != (grid[row][col] - 1))

                    # Update if we found a better path
                    if min_cost[new_row][new_col] > new_cost:
                        min_cost[new_row][new_col] = new_cost
                        heapq.heappush(pq, (new_cost, new_row, new_col))

        return min_cost[num_rows - 1][num_cols - 1]
```

</details>

<br>

## Approach 3: 0-1 Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        deque<pair<int, int>> deque;
        deque.push_front({0, 0});
        minCost[0][0] = 0;

        while (!deque.empty()) {
            auto [row, col] = deque.front();
            deque.pop_front();

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                // If position is valid and we found a better path
                if (isValid(newRow, newCol, numRows, numCols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol]) {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    // Add to back if cost=1, front if cost=0
                    if (cost == 1) {
                        deque.push_back({newRow, newCol});
                    } else {
                        deque.push_front({newRow, newCol});
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // Check if coordinates are within grid bounds
    bool isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    private final int[][] dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public int minCost(int[][] grid) {
        int numRows = grid.length, numCols = grid[0].length;

        // Track minimum cost to reach each cell
        int[][] minCost = new int[numRows][numCols];
        for (int[] row : minCost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        Deque<int[]> deque = new ArrayDeque<>();
        deque.offerFirst(new int[] { 0, 0 });
        minCost[0][0] = 0;

        while (!deque.isEmpty()) {
            int[] curr = deque.pollFirst();
            int row = curr[0], col = curr[1];

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                // If position is valid and we found a better path
                if (
                    isValid(newRow, newCol, numRows, numCols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol]
                ) {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    // Add to back if cost=1, front if cost=0
                    if (cost == 1) {
                        deque.offerLast(new int[] { newRow, newCol });
                    } else {
                        deque.offerFirst(new int[] { newRow, newCol });
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

    // Check if coordinates are within grid bounds
    private boolean isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    _dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minCost(self, grid: List[List[int]]) -> int:
        num_rows, num_cols = len(grid), len(grid[0])

        # Track minimum cost to reach each cell
        min_cost = [[float("inf")] * num_cols for _ in range(num_rows)]
        min_cost[0][0] = 0

        # Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        deque = collections.deque([(0, 0)])

        while deque:
            row, col = deque.popleft()

            # Try all four directions
            for dir_idx, (dx, dy) in enumerate(self._dirs):
                new_row, new_col = row + dx, col + dy
                cost = 0 if grid[row][col] == dir_idx + 1 else 1

                # If position is valid and we found a better path
                if (
                    self._is_valid(new_row, new_col, num_rows, num_cols)
                    and min_cost[row][col] + cost < min_cost[new_row][new_col]
                ):

                    min_cost[new_row][new_col] = min_cost[row][col] + cost

                    # Add to back if cost=1, front if cost=0
                    if cost == 1:
                        deque.append((new_row, new_col))
                    else:
                        deque.appendleft((new_row, new_col))

        return min_cost[num_rows - 1][num_cols - 1]

    # Check if coordinates are within grid bounds
    def _is_valid(
        self, row: int, col: int, num_rows: int, num_cols: int
    ) -> bool:
        return 0 <= row < num_rows and 0 <= col < num_cols
```

</details>

<br>

## Approach 4: Depth-First Search + Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), cost = 0;

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Queue for BFS part - stores cells that need cost increment
        queue<pair<int, int>> queue;

        // Start DFS from origin with cost 0
        dfs(grid, 0, 0, minCost, cost, queue);

        // BFS part - process cells level by level with increasing cost
        while (!queue.empty()) {
            cost++;
            int levelSize = queue.size();

            while (levelSize-- > 0) {
                auto [row, col] = queue.front();
                queue.pop();

                // Try all 4 directions for next level
                for (int dir = 0; dir < 4; dir++) {
                    dfs(grid, row + dirs[dir][0], col + dirs[dir][1], minCost,
                        cost, queue);
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // DFS to explore all reachable cells with current cost
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& minCost, int cost,
             queue<pair<int, int>>& queue) {
        if (!isUnvisited(minCost, row, col)) return;

        minCost[row][col] = cost;
        queue.push({row, col});

        // Follow the arrow direction without cost increase
        int nextDir = grid[row][col] - 1;
        dfs(grid, row + dirs[nextDir][0], col + dirs[nextDir][1], minCost, cost,
            queue);
    }

    // Check if cell is within bounds and unvisited
    bool isUnvisited(vector<vector<int>>& minCost, int row, int col) {
        return row >= 0 && col >= 0 && row < minCost.size() &&
               col < minCost[0].size() && minCost[row][col] == INT_MAX;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    private final int[][] dirs = new int[][] {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 },
    };

    public int minCost(int[][] grid) {
        int numRows = grid.length, numCols = grid[0].length, cost = 0;

        // Track minimum cost to reach each cell
        int[][] minCost = new int[numRows][numCols];
        for (int row = 0; row < numRows; row++) {
            Arrays.fill(minCost[row], Integer.MAX_VALUE);
        }

        // Queue for BFS part - stores cells that need cost increment
        Queue<int[]> queue = new LinkedList<>();

        // Start DFS from origin with cost 0
        dfs(grid, 0, 0, minCost, cost, queue);

        // BFS part - process cells level by level with increasing cost
        while (!queue.isEmpty()) {
            cost++;
            int levelSize = queue.size();

            while (levelSize-- > 0) {
                int[] curr = queue.poll();
                int row = curr[0], col = curr[1];

                // Try all 4 directions for next level
                for (int dir = 0; dir < 4; dir++) {
                    dfs(
                        grid,
                        row + dirs[dir][0],
                        col + dirs[dir][1],
                        minCost,
                        cost,
                        queue
                    );
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

    // DFS to explore all reachable cells with current cost
    private void dfs(
        int[][] grid,
        int row,
        int col,
        int[][] minCost,
        int cost,
        Queue<int[]> queue
    ) {
        if (!isUnvisited(minCost, row, col)) return;

        minCost[row][col] = cost;
        queue.offer(new int[] { row, col });

        // Follow the arrow direction without cost increase
        int nextDir = grid[row][col] - 1;
        dfs(
            grid,
            row + dirs[nextDir][0],
            col + dirs[nextDir][1],
            minCost,
            cost,
            queue
        );
    }

    // Check if cell is within bounds and unvisited
    private boolean isUnvisited(int[][] minCost, int row, int col) {
        return (
            row >= 0 &&
            col >= 0 &&
            row < minCost.length &&
            col < minCost[0].length &&
            minCost[row][col] == Integer.MAX_VALUE
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    _dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minCost(self, grid: List[List[int]]) -> int:
        num_rows, num_cols = len(grid), len(grid[0])
        cost = 0

        # Track minimum cost to reach each cell
        min_cost = [[float("inf")] * num_cols for _ in range(num_rows)]

        # Queue for BFS part - stores cells that need cost increment
        queue = collections.deque()

        # Start DFS from origin with cost 0
        self._dfs(grid, 0, 0, min_cost, cost, queue)

        # BFS part - process cells level by level with increasing cost
        while queue:
            cost += 1
            level_size = len(queue)

            for _ in range(level_size):
                row, col = queue.popleft()

                # Try all 4 directions for next level
                for dir_idx, (dx, dy) in enumerate(self._dirs):
                    self._dfs(grid, row + dx, col + dy, min_cost, cost, queue)

        return min_cost[num_rows - 1][num_cols - 1]

    # DFS to explore all reachable cells with current cost
    def _dfs(
        self,
        grid: List[List[int]],
        row: int,
        col: int,
        min_cost: List[List[int]],
        cost: int,
        queue: collections.deque,
    ) -> None:
        if not self._is_unvisited(min_cost, row, col):
            return

        min_cost[row][col] = cost
        queue.append((row, col))

        # Follow the arrow direction without cost increase
        next_dir = grid[row][col] - 1
        dx, dy = self._dirs[next_dir]
        self._dfs(grid, row + dx, col + dy, min_cost, cost, queue)

    # Check if cell is within bounds and unvisited
    def _is_unvisited(
        self, min_cost: List[List[int]], row: int, col: int
    ) -> bool:
        return (
            0 <= row < len(min_cost)
            and 0 <= col < len(min_cost[0])
            and min_cost[row][col] == float("inf")
        )
```

</details>
