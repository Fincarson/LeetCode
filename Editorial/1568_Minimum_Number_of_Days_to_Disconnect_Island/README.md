# 1568. Minimum Number of Days to Disconnect Island

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix` `Strongly Connected Component`

**Problem Link:** [LeetCode 1568 - Minimum Number of Days to Disconnect Island](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)

## Problem

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

### Example 1

```text
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
```

### Example 2

```text
Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 30
- grid[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Disconnect Path in a Binary Matrix by at Most One Flip](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Runes to Add to Cast Spell](https://leetcode.com/problems/minimum-runes-to-add-to-cast-spell/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1568. Minimum Number of Days to Disconnect Island

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Tarjan's Algorithm | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Directions for adjacent cells: right, left, down, up
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Count initial islands
        int initialIslandCount = countIslands(grid);

        // Already disconnected or no land
        if (initialIslandCount != 1) {
            return 0;
        }

        // Try removing each land cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) continue;  // Skip water

                // Temporarily change to water
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);

                // Check if disconnected
                if (newIslandCount != 1) return 1;

                // Revert change
                grid[row][col] = 1;
            }
        }

        return 2;
    }

private:
    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        // Iterate through all cells
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Found new island
                if (!visited[row][col] && grid[row][col] == 1) {
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    // Helper method to explore all cells of an island
    void exploreIsland(vector<vector<int>>& grid, int row, int col,
                       vector<vector<bool>>& visited) {
        visited[row][col] = true;

        // Check all adjacent cells
        for (const auto& direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            // Explore if valid land cell
            if (isValidLandCell(grid, newRow, newCol, visited)) {
                exploreIsland(grid, newRow, newCol, visited);
            }
        }
    }

    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col,
                         const vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Check bounds, land, and not visited
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1 && !visited[row][col];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for adjacent cells: right, left, down, up
    private static final int[][] DIRECTIONS = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 },
    };

    public int minDays(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Count initial islands
        int initialIslandCount = countIslands(grid);

        // Already disconnected or no land
        if (initialIslandCount != 1) {
            return 0;
        }

        // Try removing each land cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) continue; // Skip water

                // Temporarily change to water
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);

                // Check if disconnected
                if (newIslandCount != 1) return 1;

                // Revert change
                grid[row][col] = 1;
            }
        }

        return 2;
    }

    private int countIslands(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int islandCount = 0;

        // Iterate through all cells
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Found new island
                if (!visited[row][col] && grid[row][col] == 1) {
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    // Helper method to explore all cells of an island
    private void exploreIsland(
        int[][] grid,
        int row,
        int col,
        boolean[][] visited
    ) {
        visited[row][col] = true;

        // Check all adjacent cells
        for (int[] direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            // Explore if valid land cell
            if (isValidLandCell(grid, newRow, newCol, visited)) {
                exploreIsland(grid, newRow, newCol, visited);
            }
        }
    }

    private boolean isValidLandCell(
        int[][] grid,
        int row,
        int col,
        boolean[][] visited
    ) {
        int rows = grid.length;
        int cols = grid[0].length;
        // Check bounds, land, and not visited
        return (
            row >= 0 &&
            col >= 0 &&
            row < rows &&
            col < cols &&
            grid[row][col] == 1 &&
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
    def minDays(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        def _count_islands():
            visited = set()
            count = 0
            for i in range(rows):
                for j in range(cols):
                    if grid[i][j] == 1 and (i, j) not in visited:
                        _explore_island(i, j, visited)
                        count += 1
            return count

        def _explore_island(i, j, visited):
            if (
                i < 0
                or i >= rows
                or j < 0
                or j >= cols
                or grid[i][j] == 0
                or (i, j) in visited
            ):
                return
            visited.add((i, j))
            for di, dj in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                _explore_island(i + di, j + dj, visited)

        # Check if already disconnected
        if _count_islands() != 1:
            return 0

        # Check if can be disconnected in 1 day
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if _count_islands() != 1:
                        return 1
                    grid[i][j] = 1

        # If can't be disconnected in 0 or 1 day, return 2
        return 2
```

</details>

<br>

## Approach 2: Tarjan's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Directions for adjacent cells: right, down, left, up
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct ArticulationPointInfo {
        bool hasArticulationPoint;
        int time;

        ArticulationPointInfo(bool hasArticulationPoint, int time)
            : hasArticulationPoint(hasArticulationPoint), time(time) {}
    };

public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        ArticulationPointInfo apInfo(false, 0);
        int landCells = 0, islandCount = 0;

        // Arrays to store information for each cell
        vector<vector<int>> discoveryTime(
            rows,
            vector<int>(cols, -1));  // Time when a cell is first discovered
        vector<vector<int>> lowestReachable(
            rows,
            vector<int>(cols, -1));  // Lowest discovery time reachable from the
                                     // subtree rooted at this cell
        vector<vector<int>> parentCell(
            rows, vector<int>(cols, -1));  // Parent of each cell in DFS tree

        // Traverse the grid to find islands and articulation points
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    landCells++;
                    if (discoveryTime[i][j] == -1) {  // If not yet visited
                        // Start DFS for a new island
                        findArticulationPoints(grid, i, j, discoveryTime,
                                               lowestReachable, parentCell,
                                               apInfo);
                        islandCount++;
                    }
                }
            }
        }

        // Determine the minimum number of days to disconnect the grid
        if (islandCount == 0 || islandCount >= 2)
            return 0;                  // Already disconnected or no land
        if (landCells == 1) return 1;  // Only one land cell
        if (apInfo.hasArticulationPoint)
            return 1;  // An articulation point exists
        return 2;      // Need to remove any two land cells
    }

private:
    void findArticulationPoints(vector<vector<int>>& grid, int row, int col,
                                vector<vector<int>>& discoveryTime,
                                vector<vector<int>>& lowestReachable,
                                vector<vector<int>>& parentCell,
                                ArticulationPointInfo& apInfo) {
        int rows = grid.size(), cols = grid[0].size();
        discoveryTime[row][col] = apInfo.time;
        apInfo.time++;
        lowestReachable[row][col] = discoveryTime[row][col];
        int children = 0;

        // Explore all adjacent cells
        for (const auto& direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (isValidLandCell(grid, newRow, newCol)) {
                if (discoveryTime[newRow][newCol] == -1) {
                    children++;
                    parentCell[newRow][newCol] =
                        row * cols + col;  // Set parent
                    findArticulationPoints(grid, newRow, newCol, discoveryTime,
                                           lowestReachable, parentCell, apInfo);

                    // Update lowest reachable time
                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            lowestReachable[newRow][newCol]);

                    // Check for articulation point condition
                    if (lowestReachable[newRow][newCol] >=
                            discoveryTime[row][col] &&
                        parentCell[row][col] != -1) {
                        apInfo.hasArticulationPoint = true;
                    }
                } else if (newRow * cols + newCol != parentCell[row][col]) {
                    // Update lowest reachable time for back edge
                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            discoveryTime[newRow][newCol]);
                }
            }
        }

        // Root of DFS tree is an articulation point if it has more than one
        // child
        if (parentCell[row][col] == -1 && children > 1) {
            apInfo.hasArticulationPoint = true;
        }
    }

    // Check if the given cell is a valid land cell
    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for adjacent cells: right, down, left, up
    private static final int[][] DIRECTIONS = {
        { 0, 1 },
        { 1, 0 },
        { 0, -1 },
        { -1, 0 },
    };

    public int minDays(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        ArticulationPointInfo apInfo = new ArticulationPointInfo(false, 0);
        int landCells = 0, islandCount = 0;

        // Arrays to store information for each cell
        int[][] discoveryTime = new int[rows][cols]; // Time when a cell is first discovered
        int[][] lowestReachable = new int[rows][cols]; // Lowest discovery time reachable from the subtree rooted at
        // this cell
        int[][] parentCell = new int[rows][cols]; // Parent of each cell in DFS tree

        // Initialize arrays with default values
        for (int i = 0; i < rows; i++) {
            Arrays.fill(discoveryTime[i], -1);
            Arrays.fill(lowestReachable[i], -1);
            Arrays.fill(parentCell[i], -1);
        }

        // Traverse the grid to find islands and articulation points
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    landCells++;
                    if (discoveryTime[i][j] == -1) { // If not yet visited
                        // Start DFS for a new island
                        findArticulationPoints(
                            grid,
                            i,
                            j,
                            discoveryTime,
                            lowestReachable,
                            parentCell,
                            apInfo
                        );
                        islandCount++;
                    }
                }
            }
        }

        // Determine the minimum number of days to disconnect the grid
        if (islandCount == 0 || islandCount >= 2) return 0; // Already disconnected or no land
        if (landCells == 1) return 1; // Only one land cell
        if (apInfo.hasArticulationPoint) return 1; // An articulation point exists
        return 2; // Need to remove any two land cells
    }

    private void findArticulationPoints(
        int[][] grid,
        int row,
        int col,
        int[][] discoveryTime,
        int[][] lowestReachable,
        int[][] parentCell,
        ArticulationPointInfo apInfo
    ) {
        int rows = grid.length, cols = grid[0].length;
        discoveryTime[row][col] = apInfo.time;
        apInfo.time++;
        lowestReachable[row][col] = discoveryTime[row][col];
        int children = 0;

        // Explore all adjacent cells
        for (int[] direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (isValidLandCell(grid, newRow, newCol)) {
                if (discoveryTime[newRow][newCol] == -1) {
                    children++;
                    parentCell[newRow][newCol] = row * cols + col; // Set parent
                    findArticulationPoints(
                        grid,
                        newRow,
                        newCol,
                        discoveryTime,
                        lowestReachable,
                        parentCell,
                        apInfo
                    );

                    // Update lowest reachable time
                    lowestReachable[row][col] = Math.min(
                        lowestReachable[row][col],
                        lowestReachable[newRow][newCol]
                    );

                    // Check for articulation point condition
                    if (
                        lowestReachable[newRow][newCol] >=
                            discoveryTime[row][col] &&
                        parentCell[row][col] != -1
                    ) {
                        apInfo.hasArticulationPoint = true;
                    }
                } else if (newRow * cols + newCol != parentCell[row][col]) {
                    // Update lowest reachable time for back edge
                    lowestReachable[row][col] = Math.min(
                        lowestReachable[row][col],
                        discoveryTime[newRow][newCol]
                    );
                }
            }
        }

        // Root of DFS tree is an articulation point if it has more than one child
        if (parentCell[row][col] == -1 && children > 1) {
            apInfo.hasArticulationPoint = true;
        }
    }

    // Check if the given cell is a valid land cell
    private boolean isValidLandCell(int[][] grid, int row, int col) {
        int rows = grid.length, cols = grid[0].length;
        return (
            row >= 0 &&
            col >= 0 &&
            row < rows &&
            col < cols &&
            grid[row][col] == 1
        );
    }

    private class ArticulationPointInfo {

        boolean hasArticulationPoint;
        int time;

        ArticulationPointInfo(boolean hasArticulationPoint, int time) {
            this.hasArticulationPoint = hasArticulationPoint;
            this.time = time;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions for adjacent cells: right, down, left, up
    DIRECTIONS = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    def minDays(self, grid):
        rows, cols = len(grid), len(grid[0])
        ap_info = {"has_articulation_point": False, "time": 0}
        land_cells = 0
        island_count = 0

        # Arrays to store information for each cell
        discovery_time = [
            [-1] * cols for _ in range(rows)
        ]  # Time when a cell is first discovered
        lowest_reachable = [
            [-1] * cols for _ in range(rows)
        ]  # Lowest discovery time reachable from the subtree rooted at this cell
        parent_cell = [
            [-1] * cols for _ in range(rows)
        ]  # Parent of each cell in DFS tree

        def _find_articulation_points(row, col):
            discovery_time[row][col] = ap_info["time"]
            ap_info["time"] += 1
            lowest_reachable[row][col] = discovery_time[row][col]
            children = 0

            # Explore all adjacent cells
            for direction in self.DIRECTIONS:
                new_row = row + direction[0]
                new_col = col + direction[1]
                if (
                    0 <= new_row < rows
                    and 0 <= new_col < cols
                    and grid[new_row][new_col] == 1
                ):
                    if discovery_time[new_row][new_col] == -1:
                        children += 1
                        parent_cell[new_row][new_col] = (
                            row * cols + col
                        )  # Set parent
                        _find_articulation_points(new_row, new_col)

                        # Update lowest reachable time
                        lowest_reachable[row][col] = min(
                            lowest_reachable[row][col],
                            lowest_reachable[new_row][new_col],
                        )

                        # Check for articulation point condition
                        if (
                            lowest_reachable[new_row][new_col]
                            >= discovery_time[row][col]
                            and parent_cell[row][col] != -1
                        ):
                            ap_info["has_articulation_point"] = True
                    elif new_row * cols + new_col != parent_cell[row][col]:
                        # Update lowest reachable time for back edge
                        lowest_reachable[row][col] = min(
                            lowest_reachable[row][col],
                            discovery_time[new_row][new_col],
                        )

            # Root of DFS tree is an articulation point if it has more than one child
            if parent_cell[row][col] == -1 and children > 1:
                ap_info["has_articulation_point"] = True

        # Traverse the grid to find islands and articulation points
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    land_cells += 1
                    if discovery_time[i][j] == -1:  # If not yet visited
                        # Start DFS for a new island
                        _find_articulation_points(i, j)
                        island_count += 1

        # Determine the minimum number of days to disconnect the grid
        if island_count == 0 or island_count >= 2:
            return 0  # Already disconnected or no land
        if land_cells == 1:
            return 1  # Only one land cell
        if ap_info["has_articulation_point"]:
            return 1  # An articulation point exists
        return 2  # Need to remove any two land cells
```

</details>
