# 1905. Count Sub Islands

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-sub-islands/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 1905 - Count Sub Islands](https://leetcode.com/problems/count-sub-islands/)

## Problem

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

### Example 1

```text
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
```

### Example 2

```text
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
```

## Constraints

- m == grid1.length == grid2.length
- n == grid1[i].length == grid2[i].length
- 1 <= m, n <= 500
- grid1[i][j] and grid2[i][j] are either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find All Groups of Farmland](https://leetcode.com/problems/find-all-groups-of-farmland/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1905. Count Sub Islands

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Depth-First Search | C++, Java, Python3 |
| Union-Find | C++, Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Directions in which we can traverse inside the grids.
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

public:
    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check this island is a sub-island in 'grid1'.
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1,
                     vector<vector<int>>& grid2,
                     vector<vector<bool>>& visited) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        int isSubIsland = true;

        queue<pair<int, int>> pendingCells;
        // Push the starting cell in the queue and mark it as visited.
        pendingCells.push({x, y});
        visited[x][y] = true;

        // Traverse on all cells using the breadth-first search method.
        while (!pendingCells.empty()) {
            int currX = pendingCells.front().first;
            int currY = pendingCells.front().second;
            pendingCells.pop();

            // If the current position cell is not a land cell in 'grid1',
            // then the current island can't be a sub-island.
            if (!isCellLand(currX, currY, grid1)) {
                isSubIsland = false;
            }

            for (auto& direction : directions) {
                int nextX = currX + direction[0];
                int nextY = currY + direction[1];
                // If the next cell is inside 'grid2', is never visited and
                // is a land cell, then we traverse to the next cell.
                if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                    nextY < totalCols && !visited[nextX][nextY] &&
                    isCellLand(nextX, nextY, grid2)) {
                    // Push the next cell in the queue and mark it as visited.
                    pendingCells.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int subIslandCounts = 0;

        // Iterate on each cell in 'grid2'
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                // If cell at the position (x, y) in the 'grid2' is not visited,
                // is a land cell in 'grid2', and the island
                // starting from this cell is a sub-island in 'grid1', then we
                // increment the count of sub-islands.
                if (!visited[x][y] && isCellLand(x, y, grid2) &&
                    isSubIsland(x, y, grid1, grid2, visited)) {
                    subIslandCounts += 1;
                }
            }
        }
        // Return total count of sub-islands.
        return subIslandCounts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions in which we can traverse inside the grids.
    private final int[][] directions = {
        { 0, 1 },
        { 1, 0 },
        { 0, -1 },
        { -1, 0 },
    };

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    private boolean isCellLand(int x, int y, int[][] grid) {
        return grid[x][y] == 1;
    }

    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check this island is a sub-island in 'grid1'.
    private boolean isSubIsland(
        int x,
        int y,
        int[][] grid1,
        int[][] grid2,
        boolean[][] visited
    ) {
        int totalRows = grid2.length;
        int totalCols = grid2[0].length;

        boolean isSubIsland = true;

        Queue<int[]> pendingCells = new LinkedList<>();
        // Push the starting cell in the queue and mark it as visited.
        pendingCells.offer(new int[] { x, y });
        visited[x][y] = true;

        // Traverse on all cells using the breadth-first search method.
        while (!pendingCells.isEmpty()) {
            int[] curr = pendingCells.poll();
            int currX = curr[0];
            int currY = curr[1];

            // If the current position cell is not a land cell in 'grid1',
            // then the current island can't be a sub-island.
            if (!isCellLand(currX, currY, grid1)) {
                isSubIsland = false;
            }

            for (int[] direction : directions) {
                int nextX = currX + direction[0];
                int nextY = currY + direction[1];
                // If the next cell is inside 'grid2', is never visited and
                // is a land cell, then we traverse to the next cell.
                if (
                    nextX >= 0 &&
                    nextY >= 0 &&
                    nextX < totalRows &&
                    nextY < totalCols &&
                    !visited[nextX][nextY] &&
                    isCellLand(nextX, nextY, grid2)
                ) {
                    // Push the next cell in the queue and mark it as visited.
                    pendingCells.offer(new int[] { nextX, nextY });
                    visited[nextX][nextY] = true;
                }
            }
        }

        return isSubIsland;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int totalRows = grid2.length;
        int totalCols = grid2[0].length;

        boolean[][] visited = new boolean[totalRows][totalCols];
        int subIslandCounts = 0;

        // Iterate on each cell in 'grid2'
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                // If cell at the position (x, y) in the 'grid2' is not visited,
                // is a land cell in 'grid2', and the island
                // starting from this cell is a sub-island in 'grid1', then we
                // increment the count of sub-islands.
                if (
                    !visited[x][y] &&
                    isCellLand(x, y, grid2) &&
                    isSubIsland(x, y, grid1, grid2, visited)
                ) {
                    subIslandCounts += 1;
                }
            }
        }
        // Return total count of sub-islands.
        return subIslandCounts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions in which we can traverse inside the grids.
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x, y, grid):
        return grid[x][y] == 1

    # Traverse all cells of island starting at position (x, y) in 'grid2',
    # and check this island is a sub-island in 'grid1'.
    def is_sub_island(self, x, y, grid1, grid2, visited):
        total_rows = len(grid2)
        total_cols = len(grid2[0])

        is_sub_island = True

        pending_cells = deque()
        # Push the starting cell in the queue and mark it as visited.
        pending_cells.append((x, y))
        visited[x][y] = True

        # Traverse on all cells using the breadth-first search method.
        while pending_cells:
            curr_x, curr_y = pending_cells.popleft()

            # If the current position cell is not a land cell in 'grid1',
            # then the current island can't be a sub-island.
            if not self.is_cell_land(curr_x, curr_y, grid1):
                is_sub_island = False

            for direction in self.directions:
                next_x = curr_x + direction[0]
                next_y = curr_y + direction[1]
                # If the next cell is inside 'grid2', is never visited and
                # is a land cell, then we traverse to the next cell.
                if (
                    0 <= next_x < total_rows
                    and 0 <= next_y < total_cols
                    and not visited[next_x][next_y]
                    and self.is_cell_land(next_x, next_y, grid2)
                ):
                    # Push the next cell in the queue and mark it as visited.
                    pending_cells.append((next_x, next_y))
                    visited[next_x][next_y] = True
        return is_sub_island

    def countSubIslands(
        self, grid1: List[List[int]], grid2: List[List[int]]
    ) -> int:
        total_rows = len(grid2)
        total_cols = len(grid2[0])

        visited = [[False] * total_cols for _ in range(total_rows)]
        sub_island_counts = 0

        # Iterate on each cell in 'grid2'
        for x in range(total_rows):
            for y in range(total_cols):
                # If cell at the position (x, y) in the 'grid2' is not visited,
                # is a land cell in 'grid2', and the island
                # starting from this cell is a sub-island in 'grid1', then we
                # increment the count of sub-islands.
                if (
                    not visited[x][y]
                    and self.is_cell_land(x, y, grid2)
                    and self.is_sub_island(x, y, grid1, grid2, visited)
                ):
                    sub_island_counts += 1

        # Return total count of sub-islands.
        return sub_island_counts
```

</details>

<br>

## Approach 2: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Directions in which we can traverse inside the grids.
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check this island is a sub-island in 'grid1'.
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1,
                     vector<vector<int>>& grid2,
                     vector<vector<bool>>& visited) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();
        // Traverse on all cells using the depth-first search method.
        bool isSubIsLand = true;

        // If the current cell is not a land cell in 'grid1', then the current
        // island can't be a sub-island.
        if (!isCellLand(x, y, grid1)) {
            isSubIsLand = false;
        }

        // Traverse on all adjacent cells.
        for (auto& direction : directions) {
            int nextX = x + direction[0];
            int nextY = y + direction[1];
            // If the next cell is inside the 'grid2', is never visited and is a
            // land cell, then we traverse to the next cell.
            if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                nextY < totalCols && !visited[nextX][nextY] &&
                isCellLand(nextX, nextY, grid2)) {
                // Push the next cell in the recursive stack and mark it as
                // visited.
                visited[nextX][nextY] = true;
                bool nextCellIsPartOfSubIsland =
                    isSubIsland(nextX, nextY, grid1, grid2, visited);
                isSubIsLand = isSubIsLand && nextCellIsPartOfSubIsland;
            }
        }
        return isSubIsLand;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int subIslandCounts = 0;

        // Iterate on each cell in 'grid2'
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                // If cell at the position (x, y) in the 'grid2' is not visited,
                // is a land cell in 'grid2',
                // and the island starting from this cell is a sub-island in
                // 'grid1', then we increment the count of sub-islands.
                if (!visited[x][y] && isCellLand(x, y, grid2)) {
                    visited[x][y] = true;
                    if (isSubIsland(x, y, grid1, grid2, visited)) {
                        subIslandCounts += 1;
                    }
                }
            }
        }
        // Return total count of sub-islands.
        return subIslandCounts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions in which we can traverse inside the grids.
    private final int[][] directions = {
        { 0, 1 },
        { 1, 0 },
        { 0, -1 },
        { -1, 0 },
    };

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    private boolean isCellLand(int x, int y, int[][] grid) {
        return grid[x][y] == 1;
    }

    // Traverse all cells of island starting at position (x, y) in 'grid2',
    // and check if this island is a sub-island in 'grid1'.
    private boolean isSubIsland(
        int x,
        int y,
        int[][] grid1,
        int[][] grid2,
        boolean[][] visited
    ) {
        int totalRows = grid2.length;
        int totalCols = grid2[0].length;
        // Traverse on all cells using the depth-first search method.
        boolean isSubIsland = true;

        // If the current cell is not a land cell in 'grid1', then the current island can't be a sub-island.
        if (!isCellLand(x, y, grid1)) {
            isSubIsland = false;
        }

        // Traverse on all adjacent cells.
        for (int[] direction : directions) {
            int nextX = x + direction[0];
            int nextY = y + direction[1];
            // If the next cell is inside 'grid2', is not visited, and is a land cell,
            // then we traverse to the next cell.
            if (
                nextX >= 0 &&
                nextY >= 0 &&
                nextX < totalRows &&
                nextY < totalCols &&
                !visited[nextX][nextY] &&
                isCellLand(nextX, nextY, grid2)
            ) {
                // Mark the next cell as visited.
                visited[nextX][nextY] = true;
                boolean nextCellIsPartOfSubIsland = isSubIsland(
                    nextX,
                    nextY,
                    grid1,
                    grid2,
                    visited
                );
                isSubIsland = isSubIsland && nextCellIsPartOfSubIsland;
            }
        }
        return isSubIsland;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int totalRows = grid2.length;
        int totalCols = grid2[0].length;

        boolean[][] visited = new boolean[totalRows][totalCols];
        int subIslandCounts = 0;

        // Iterate over each cell in 'grid2'.
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                // If the cell at position (x, y) in 'grid2' is not visited,
                // is a land cell in 'grid2', and the island starting from this cell is a sub-island in 'grid1',
                // then increment the count of sub-islands.
                if (!visited[x][y] && isCellLand(x, y, grid2)) {
                    visited[x][y] = true;
                    if (isSubIsland(x, y, grid1, grid2, visited)) {
                        subIslandCounts += 1;
                    }
                }
            }
        }
        // Return total count of sub-islands.
        return subIslandCounts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions in which we can traverse inside the grids.
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x, y, grid):
        return grid[x][y] == 1

    # Traverse all cells of island starting at position (x, y) in 'grid2',
    # and check if this island is a sub-island in 'grid1'.
    def is_sub_island(self, x, y, grid1, grid2, visited):
        total_rows = len(grid2)
        total_cols = len(grid2[0])
        # Traverse on all cells using the depth-first search method.
        is_sub_island = True

        # If the current cell is not a land cell in 'grid1', then the current island can't be a sub-island.
        if not self.is_cell_land(x, y, grid1):
            is_sub_island = False

        # Traverse on all adjacent cells.
        for direction in self.directions:
            next_x = x + direction[0]
            next_y = y + direction[1]
            # If the next cell is inside 'grid2', is not visited, and is a land cell,
            # then we traverse to the next cell.
            if (
                0 <= next_x < total_rows
                and 0 <= next_y < total_cols
                and not visited[next_x][next_y]
                and self.is_cell_land(next_x, next_y, grid2)
            ):
                # Mark the next cell as visited.
                visited[next_x][next_y] = True
                next_cell_is_part_of_sub_island = self.is_sub_island(
                    next_x, next_y, grid1, grid2, visited
                )
                is_sub_island = (
                    is_sub_island and next_cell_is_part_of_sub_island
                )
        return is_sub_island

    def countSubIslands(
        self, grid1: List[List[int]], grid2: List[List[int]]
    ) -> int:
        total_rows = len(grid2)
        total_cols = len(grid2[0])

        visited = [[False] * total_cols for _ in range(total_rows)]
        sub_island_counts = 0

        # Iterate over each cell in 'grid2'.
        for x in range(total_rows):
            for y in range(total_cols):
                # If the cell at position (x, y) in 'grid2' is not visited,
                # is a land cell in 'grid2', and the island starting from this cell is a sub-island in 'grid1',
                # then increment the count of sub-islands.
                if not visited[x][y] and self.is_cell_land(x, y, grid2):
                    visited[x][y] = True
                    if self.is_sub_island(x, y, grid1, grid2, visited):
                        sub_island_counts += 1

        # Return total count of sub-islands.
        return sub_island_counts
```

</details>

<br>

## Approach 3: Union-Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // Directions in which we can traverse inside the grids.
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

    // Union-Find class.
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;

        // Itialize union-find object with 'n' elements.
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        // Find the root of element 'u', using the path-compression technique.
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        // Union two components of elements 'u' and 'v' respectively on the
        // basis of their ranks.
        void unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    };

    // Helper method to convert (x, y) position to 1-dimensional index.
    int convertToIndex(int x, int y, int totalCols) {
        return x * totalCols + y;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();
        UnionFind uf(totalRows * totalCols);

        // Traverse on each land cell of 'grid2'.
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    // Union adjacent land cells with the current land cell.
                    for (auto& direction : directions) {
                        int nextX = x + direction[0], nextY = y + direction[1];
                        if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                            nextY < totalCols &&
                            isCellLand(nextX, nextY, grid2)) {
                            uf.unionSets(
                                convertToIndex(x, y, totalCols),
                                convertToIndex(nextX, nextY, totalCols));
                        }
                    }
                }
            }
        }

        // Traverse on 'grid2' land cells and mark that cell's root not a
        // sub-island if land cell not present at the respective position in
        // 'grid1'.
        vector<bool> isSubIsland(totalRows * totalCols, true);
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2) && !isCellLand(x, y, grid1)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    isSubIsland[root] = false;
                }
            }
        }

        // Count all the sub-islands.
        int subIslandCounts = 0;
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    if (isSubIsland[root]) {
                        subIslandCounts++;
                        // One cell can be the root of multiple land cells, so
                        // to avoid counting the same island multiple times and
                        // mark it as false.
                        isSubIsland[root] = false;
                    }
                }
            }
        }

        return subIslandCounts;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions in which we can traverse inside the grids.
    private final int[][] directions = {
        { 0, 1 },
        { 1, 0 },
        { 0, -1 },
        { -1, 0 },
    };

    // Helper method to check if the cell at the position (x, y) in the 'grid'
    // is a land cell.
    private boolean isCellLand(int x, int y, int[][] grid) {
        return grid[x][y] == 1;
    }

    // Union-Find class.
    class UnionFind {

        private final int[] parent;
        private final int[] rank;

        // Initialize union-find object with 'n' elements.
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // Find the root of element 'u', using the path-compression technique.
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        // Union two components of elements 'u' and 'v' respectively based on
        // their ranks.
        void unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }
    }

    // Helper method to convert (x, y) position to a 1-dimensional index.
    private int convertToIndex(int x, int y, int totalCols) {
        return x * totalCols + y;
    }

    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int totalRows = grid2.length;
        int totalCols = grid2[0].length;
        UnionFind uf = new UnionFind(totalRows * totalCols);

        // Traverse each land cell of 'grid2'.
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    // Union adjacent land cells with the current land cell.
                    for (int[] direction : directions) {
                        int nextX = x + direction[0];
                        int nextY = y + direction[1];
                        if (
                            nextX >= 0 &&
                            nextY >= 0 &&
                            nextX < totalRows &&
                            nextY < totalCols &&
                            isCellLand(nextX, nextY, grid2)
                        ) {
                            uf.unionSets(
                                convertToIndex(x, y, totalCols),
                                convertToIndex(nextX, nextY, totalCols)
                            );
                        }
                    }
                }
            }
        }

        // Traverse 'grid2' land cells and mark that cell's root as not a sub-island
        // if the land cell is not present at the respective position in 'grid1'.
        boolean[] isSubIsland = new boolean[totalRows * totalCols];
        for (int i = 0; i < isSubIsland.length; i++) {
            isSubIsland[i] = true;
        }
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2) && !isCellLand(x, y, grid1)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    isSubIsland[root] = false;
                }
            }
        }

        // Count all the sub-islands.
        int subIslandCounts = 0;
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (isCellLand(x, y, grid2)) {
                    int root = uf.find(convertToIndex(x, y, totalCols));
                    if (isSubIsland[root]) {
                        subIslandCounts++;
                        // One cell can be the root of multiple land cells, so to
                        // avoid counting the same island multiple times, mark it as false.
                        isSubIsland[root] = false;
                    }
                }
            }
        }

        return subIslandCounts;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Directions in which we can traverse inside the grids.
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    # Helper method to check if the cell at the position (x, y) in the 'grid'
    # is a land cell.
    def is_cell_land(self, x, y, grid):
        return grid[x][y] == 1

    # Union-Find class.
    class UnionFind:
        def __init__(self, n):
            self.parent = list(range(n))
            self.rank = [0] * n

        # Find the root of element 'u', using the path-compression technique.
        def find(self, u):
            if self.parent[u] != u:
                self.parent[u] = self.find(self.parent[u])
            return self.parent[u]

        # Union two components of elements 'u' and 'v' respectively based on their ranks.
        def union_sets(self, u, v):
            root_u = self.find(u)
            root_v = self.find(v)
            if root_u != root_v:
                if self.rank[root_u] > self.rank[root_v]:
                    self.parent[root_v] = root_u
                elif self.rank[root_u] < self.rank[root_v]:
                    self.parent[root_u] = root_v
                else:
                    self.parent[root_v] = root_u
                    self.rank[root_u] += 1

    # Helper method to convert (x, y) position to a 1-dimensional index.
    def convert_to_index(self, x, y, total_cols):
        return x * total_cols + y

    def countSubIslands(
        self, grid1: List[List[int]], grid2: List[List[int]]
    ) -> int:
        total_rows = len(grid2)
        total_cols = len(grid2[0])
        uf = self.UnionFind(total_rows * total_cols)

        # Traverse each land cell of 'grid2'.
        for x in range(total_rows):
            for y in range(total_cols):
                if self.is_cell_land(x, y, grid2):
                    # Union adjacent land cells with the current land cell.
                    for direction in self.directions:
                        next_x = x + direction[0]
                        next_y = y + direction[1]
                        if (
                            0 <= next_x < total_rows
                            and 0 <= next_y < total_cols
                            and self.is_cell_land(next_x, next_y, grid2)
                        ):
                            uf.union_sets(
                                self.convert_to_index(x, y, total_cols),
                                self.convert_to_index(
                                    next_x, next_y, total_cols
                                ),
                            )

        # Traverse 'grid2' land cells and mark that cell's root as not a sub-island
        # if the land cell is not present at the respective position in 'grid1'.
        is_sub_island = [True] * (total_rows * total_cols)
        for x in range(total_rows):
            for y in range(total_cols):
                if self.is_cell_land(x, y, grid2) and not self.is_cell_land(
                    x, y, grid1
                ):
                    root = uf.find(self.convert_to_index(x, y, total_cols))
                    is_sub_island[root] = False

        # Count all the sub-islands.
        sub_island_counts = 0
        for x in range(total_rows):
            for y in range(total_cols):
                if self.is_cell_land(x, y, grid2):
                    root = uf.find(self.convert_to_index(x, y, total_cols))
                    if is_sub_island[root]:
                        sub_island_counts += 1
                        # One cell can be the root of multiple land cells, so to
                        # avoid counting the same island multiple times, mark it as false.
                        is_sub_island[root] = False

        return sub_island_counts
```

</details>
