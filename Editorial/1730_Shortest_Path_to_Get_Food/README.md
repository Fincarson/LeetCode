# 1730. Shortest Path to Get Food

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-path-to-get-food/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1730 - Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/)

## Problem

You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

- '*' is your location. There is exactly one '*' cell.
- '#' is a food cell. There may be multiple food cells.
- 'O' is free space, and you can travel through these cells.
- 'X' is an obstacle, and you cannot travel through these cells.

You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.

### Example 1

```text
Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
Output: 3
Explanation: It takes 3 steps to reach the food.
```

### Example 2

```text
Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
Output: -1
Explanation: It is not possible to reach the food.
```

### Example 3

```text
Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
Output: 6
Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.
```

### Example 4

```text
Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["O","O","O","O","O","O","O","O"]]
Output: 5
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 200
- grid[row][col] is '*', 'X', 'O', or '#'.
- The grid contains exactly one '*'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [01 Matrix](https://leetcode.com/problems/01-matrix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1730. Shortest Path to Get Food

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java, Python3 |
| A* Path Finding Algorithm | C++, Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Possible moves: right, left, up, down
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Find starting position marked as '*'
        vector<int> start = {-1, -1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '*') {
                    start[0] = i;
                    start[1] = j;
                    break;
                }
            }
        }

        // BFS queue for level-by-level traversal
        queue<vector<int>> queue;
        queue.push(start);
        int steps = 1;

        // BFS traversal
        while (!queue.empty()) {
            int levelSize = queue.size();

            // Process all cells at current level
            while (levelSize-- > 0) {
                vector<int> pos = queue.front();
                queue.pop();

                // Try all four directions
                for (auto& d : dir) {
                    int newRow = d[0] + pos[0];
                    int newCol = d[1] + pos[1];

                    if (isValid(grid, newRow, newCol)) {
                        // Found food
                        if (grid[newRow][newCol] == '#') return steps;

                        // Mark as visited and add to queue
                        grid[newRow][newCol] = 'X';
                        queue.push({newRow, newCol});
                    }
                }
            }
            steps++;
        }

        // No path found to food
        return -1;
    }

private:
    // Check if position is within bounds and not blocked
    bool isValid(vector<vector<char>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size() && grid[row][col] != 'X';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Possible moves: right, left, up, down
    private final int[][] dir = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

    public int getFood(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Find starting position marked as '*'
        int[] start = { -1, -1 };
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '*') {
                    start[0] = i;
                    start[1] = j;
                    break;
                }
            }
        }

        // BFS queue for level-by-level traversal
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        int steps = 1;

        // BFS traversal
        while (!queue.isEmpty()) {
            int levelSize = queue.size();

            // Process all cells at current level
            while (levelSize-- > 0) {
                int[] pos = queue.poll();

                // Try all four directions
                for (int[] d : dir) {
                    int newRow = d[0] + pos[0];
                    int newCol = d[1] + pos[1];

                    if (isValid(grid, newRow, newCol)) {
                        // Found food
                        if (grid[newRow][newCol] == '#') return steps;

                        // Mark as visited and add to queue
                        grid[newRow][newCol] = 'X';
                        queue.add(new int[] { newRow, newCol });
                    }
                }
            }
            steps++;
        }

        // No path found to food
        return -1;
    }

    // Check if position is within bounds and not blocked
    private boolean isValid(char[][] grid, int row, int col) {
        return (
            row >= 0 &&
            col >= 0 &&
            row < grid.length &&
            col < grid[0].length &&
            grid[row][col] != 'X'
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getFood(self, grid: list[list[str]]) -> int:
        # Possible moves: right, left, up, down
        dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        rows, cols = len(grid), len(grid[0])

        # Find starting position marked as '*'
        start = next(
            (i, j)
            for i in range(rows)
            for j in range(cols)
            if grid[i][j] == "*"
        )

        # BFS queue for level-by-level traversal
        queue = deque([start])
        steps = 1

        # BFS traversal
        while queue:
            # Process all cells at current level
            for _ in range(len(queue)):
                row, col = queue.popleft()

                # Try all four directions
                for dx, dy in dirs:
                    new_row, new_col = row + dx, col + dy

                    if self._is_valid(grid, new_row, new_col):
                        # Found food
                        if grid[new_row][new_col] == "#":
                            return steps

                        # Mark as visited and add to queue
                        grid[new_row][new_col] = "X"
                        queue.append((new_row, new_col))
            steps += 1

        # No path found to food
        return -1

    # Check if position is within bounds and not blocked
    def _is_valid(self, grid: list[list[str]], row: int, col: int) -> bool:
        return (
            0 <= row < len(grid)
            and 0 <= col < len(grid[0])
            and grid[row][col] != "X"
        )
```

</details>

<br>

## Approach 2: A* Path Finding Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Direction vectors for up, down, left, right movement
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> start = {-1, -1};
        vector<vector<int>> foods;

        // Find starting position and all food locations
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '*') {
                    start = {r, c};
                } else if (grid[r][c] == '#') {
                    foods.push_back({r, c});
                }
            }
        }

        if (foods.empty()) {
            return -1;
        }

        // Track visited cells to avoid cycles
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));

        // Priority queue stores: [estimated total cost, steps taken, row, col]
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(
            comp);

        // Calculate initial Manhattan distance estimate to nearest food
        int initCost = calcDist(start[0], start[1], foods);
        pq.push({initCost, 0, start[0], start[1]});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int estCost = curr[0];
            int steps = curr[1];
            int r = curr[2];
            int c = curr[3];

            // Try all four directions
            for (auto& d : dirs) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (!isValid(grid, newR, newC) || seen[newR][newC]) {
                    continue;
                }

                // If food found, return total steps taken
                if (grid[newR][newC] == '#') {
                    return steps + 1;
                } else {
                    seen[newR][newC] = true;
                    // Calculate new Manhattan distance estimate
                    int newEst = calcDist(newR, newC, foods);
                    pq.push({newEst + steps + 1, steps + 1, newR, newC});
                }
            }
        }

        return -1;
    }

private:
    // Calculate Manhattan distance to nearest food
    int calcDist(int r, int c, vector<vector<int>>& foods) {
        int minDist = INT_MAX;
        for (const vector<int>& food : foods) {
            int dist = abs(food[0] - r) + abs(food[1] - c);
            minDist = min(minDist, dist);
        }
        return minDist;
    }

    // Check if position is within grid bounds and not an obstacle
    bool isValid(vector<vector<char>>& grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() &&
               grid[r][c] != 'X';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction vectors for up, down, left, right movement
    private final int[][] dirs = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

    public int getFood(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[] start = { -1, -1 };
        List<int[]> foods = new ArrayList<>();

        // Find starting position and all food locations
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '*') {
                    start = new int[] { r, c };
                } else if (grid[r][c] == '#') {
                    foods.add(new int[] { r, c });
                }
            }
        }

        if (foods.isEmpty()) {
            return -1;
        }

        // Track visited cells to avoid cycles
        boolean[][] seen = new boolean[rows][cols];

        // Priority queue stores: [estimated total cost, steps taken, row, col]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Calculate initial Manhattan distance estimate to nearest food
        int initCost = calcDist(start[0], start[1], foods);
        pq.add(new int[] { initCost, 0, start[0], start[1] });

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int estCost = curr[0];
            int steps = curr[1];
            int r = curr[2];
            int c = curr[3];

            // Try all four directions
            for (int[] d : dirs) {
                int newR = r + d[0];
                int newC = c + d[1];

                if (!isValid(grid, newR, newC) || seen[newR][newC]) {
                    continue;
                }

                // If food found, return total steps taken
                if (grid[newR][newC] == '#') {
                    return steps + 1;
                } else {
                    seen[newR][newC] = true;
                    // Calculate new Manhattan distance estimate
                    int newEst = calcDist(newR, newC, foods);
                    pq.add(
                        new int[] { newEst + steps + 1, steps + 1, newR, newC }
                    );
                }
            }
        }

        return -1;
    }

    // Calculate Manhattan distance to nearest food
    private int calcDist(int r, int c, List<int[]> foods) {
        int minDist = Integer.MAX_VALUE;
        for (int[] food : foods) {
            int dist = Math.abs(food[0] - r) + Math.abs(food[1] - c);
            minDist = Math.min(minDist, dist);
        }
        return minDist;
    }

    // Check if position is within grid bounds and not an obstacle
    private boolean isValid(char[][] grid, int r, int c) {
        return (
            r >= 0 &&
            c >= 0 &&
            r < grid.length &&
            c < grid[0].length &&
            grid[r][c] != 'X'
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Direction vectors for up, down, left, right movement
    _DIRS = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    def getFood(self, grid: list[list[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        start = None
        foods = []

        # Find starting position and all food locations
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "*":
                    start = [r, c]
                elif grid[r][c] == "#":
                    foods.append([r, c])

        if not foods:
            return -1

        # Track visited cells to avoid cycles
        seen = set()

        # Priority queue stores: (estimated total cost, steps taken, row, col)
        pq = [
            (self._calc_dist(start[0], start[1], foods), 0, start[0], start[1])
        ]

        while pq:
            est_cost, steps, r, c = heapq.heappop(pq)

            # Try all four directions
            for dr, dc in self._DIRS:
                new_r, new_c = r + dr, c + dc

                if (
                    not self._is_valid(grid, new_r, new_c)
                    or (new_r, new_c) in seen
                ):
                    continue

                # If food found, return total steps taken
                if grid[new_r][new_c] == "#":
                    return steps + 1

                seen.add((new_r, new_c))
                # Calculate new Manhattan distance estimate
                new_est = self._calc_dist(new_r, new_c, foods)
                heapq.heappush(
                    pq, (new_est + steps + 1, steps + 1, new_r, new_c)
                )

        return -1

    # Calculate Manhattan distance to nearest food
    def _calc_dist(self, r: int, c: int, foods: list[list[int]]) -> int:
        return min(abs(food[0] - r) + abs(food[1] - c) for food in foods)

    # Check if position is within grid bounds and not an obstacle
    def _is_valid(self, grid: list[list[str]], r: int, c: int) -> bool:
        return (
            0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] != "X"
        )
```

</details>
