# 2658. Maximum Number of Fish in a Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 2658 - Maximum Number of Fish in a Grid](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/)

## Problem

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

- A land cell if grid[r][c] = 0, or
- A water cell containing grid[r][c] fish, if grid[r][c] > 0.

A fisher can start at any water cell (r, c) and can do the following operations any number of times:

- Catch all the fish at cell (r, c), or
- Move to any adjacent water cell.

Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

### Example 1

```text
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
```

### Example 2

```text
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- 0 <= grid[i][j] <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2658. Maximum Number of Fish in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Breadth-First Search | C++, Java, Python3 |
| Union Find Algorithm | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Helper function to count the number of fishes in a connected component
    int calculateFishes(vector<vector<int>>& grid,
                        vector<vector<bool>>& visited, int row, int col) {
        // Check boundary conditions, water cells, or already visited cells
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Accumulate the fish count from the current cell and its neighbors
        return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
               calculateFishes(grid, visited, row, col - 1) +
               calculateFishes(grid, visited, row + 1, col) +
               calculateFishes(grid, visited, row - 1, col);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxFishCount = 0;

        // A 2D vector to track visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Iterate through all cells in the grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Start a DFS for unvisited land cells (fish available)
                if (grid[row][col] > 0 && !visited[row][col]) {
                    maxFishCount = max(
                        maxFishCount, calculateFishes(grid, visited, row, col));
                }
            }
        }

        // Return the maximum fish count found
        return maxFishCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to count the number of fishes in a connected component
    private int calculateFishes(
        int[][] grid,
        boolean[][] visited,
        int row,
        int col
    ) {
        // Check boundary conditions, water cells, or already visited cells
        if (
            row < 0 ||
            row >= grid.length ||
            col < 0 ||
            col >= grid[0].length ||
            grid[row][col] == 0 ||
            visited[row][col]
        ) {
            return 0;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Accumulate the fish count from the current cell and its neighbors
        return (
            grid[row][col] +
            calculateFishes(grid, visited, row, col + 1) +
            calculateFishes(grid, visited, row, col - 1) +
            calculateFishes(grid, visited, row + 1, col) +
            calculateFishes(grid, visited, row - 1, col)
        );
    }

    public int findMaxFish(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int maxFishCount = 0;

        // A 2D array to track visited cells
        boolean[][] visited = new boolean[rows][cols];

        // Iterate through all cells in the grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Start a DFS for unvisited land cells (fish available)
                if (grid[row][col] > 0 && !visited[row][col]) {
                    maxFishCount = Math.max(
                        maxFishCount,
                        calculateFishes(grid, visited, row, col)
                    );
                }
            }
        }

        // Return the maximum fish count found
        return maxFishCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Helper function to count the number of fishes in a connected component
    def calculate_fishes(self, grid, visited, row, col):
        # Check boundary conditions, water cells, or already visited cells
        if (
            row < 0
            or row >= len(grid)
            or col < 0
            or col >= len(grid[0])
            or grid[row][col] == 0
            or visited[row][col]
        ):
            return 0

        # Mark the current cell as visited
        visited[row][col] = True

        # Accumulate the fish count from the current cell and its neighbors
        return (
            grid[row][col]
            + self.calculate_fishes(grid, visited, row, col + 1)
            + self.calculate_fishes(grid, visited, row, col - 1)
            + self.calculate_fishes(grid, visited, row + 1, col)
            + self.calculate_fishes(grid, visited, row - 1, col)
        )

    def findMaxFish(self, grid):
        rows, cols = len(grid), len(grid[0])
        max_fish_count = 0

        # A 2D list to track visited cells
        visited = [[False] * cols for _ in range(rows)]

        # Iterate through all cells in the grid
        for row in range(rows):
            for col in range(cols):
                # Start a DFS for unvisited land cells (fish available)
                if grid[row][col] > 0 and not visited[row][col]:
                    max_fish_count = max(
                        max_fish_count,
                        self.calculate_fishes(grid, visited, row, col),
                    )

        # Return the maximum fish count found
        return max_fish_count
```

</details>

<br>

## Approach 2: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Function to perform BFS and count fishes in the connected component
    int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                    int row, int col) {
        int numRows = grid.size(), numCols = grid[0].size(), fishCount = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        // Directions for exploring up, down, left, right
        vector<int> rowDirections = {0, 0, 1, -1};
        vector<int> colDirections = {1, -1, 0, 0};

        // BFS traversal
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            fishCount += grid[row][col];

            // Exploring all four directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowDirections[i];
                int newCol = col + colDirections[i];
                if (0 <= newRow && newRow < numRows && 0 <= newCol &&
                    newCol < numCols && grid[newRow][newCol] &&
                    !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        return fishCount;
    }

public:
    // Function to find the maximum number of fishes
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols));

        // Iterating through the entire grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    result = max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Function to perform BFS and count fishes in the connected component
    private int countFishes(
        int[][] grid,
        boolean[][] visited,
        int row,
        int col
    ) {
        int numRows = grid.length, numCols = grid[0].length, fishCount = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { row, col });
        visited[row][col] = true;

        // Directions for exploring up, down, left, right
        int[] rowDirections = { 0, 0, 1, -1 };
        int[] colDirections = { 1, -1, 0, 0 };

        // BFS traversal
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            row = cell[0];
            col = cell[1];
            fishCount += grid[row][col];

            // Exploring all four directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + rowDirections[i];
                int newCol = col + colDirections[i];
                if (
                    0 <= newRow &&
                    newRow < numRows &&
                    0 <= newCol &&
                    newCol < numCols &&
                    grid[newRow][newCol] != 0 &&
                    !visited[newRow][newCol]
                ) {
                    q.add(new int[] { newRow, newCol });
                    visited[newRow][newCol] = true;
                }
            }
        }
        return fishCount;
    }

    // Function to find the maximum number of fishes
    public int findMaxFish(int[][] grid) {
        int numRows = grid.length, numCols = grid[0].length, result = 0;
        boolean[][] visited = new boolean[numRows][numCols];

        // Iterating through the entire grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    result = Math.max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Function to perform BFS and count fishes in the connected component
    def count_fishes(self, grid, visited, row, col):
        num_rows = len(grid)
        num_cols = len(grid[0])
        fish_count = 0
        q = [(row, col)]
        visited[row][col] = True

        # Directions for exploring up, down, left, right
        row_directions = [0, 0, 1, -1]
        col_directions = [1, -1, 0, 0]

        # BFS traversal
        while q:
            row, col = q.pop(0)
            fish_count += grid[row][col]

            # Exploring all four directions
            for i in range(4):
                new_row = row + row_directions[i]
                new_col = col + col_directions[i]
                if (
                    0 <= new_row < num_rows
                    and 0 <= new_col < num_cols
                    and grid[new_row][new_col]
                    and not visited[new_row][new_col]
                ):
                    q.append((new_row, new_col))
                    visited[new_row][new_col] = True

        return fish_count

    # Function to find the maximum number of fishes
    def findMaxFish(self, grid):
        num_rows = len(grid)
        num_cols = len(grid[0])
        result = 0
        visited = [[False] * num_cols for _ in range(num_rows)]

        # Iterating through the entire grid
        for i in range(num_rows):
            for j in range(num_cols):
                if grid[i][j] and not visited[i][j]:
                    result = max(result, self.count_fishes(grid, visited, i, j))

        return result
```

</details>

<br>

## Approach 3: Union Find Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Helper function to find the root of a component
    int findParent(vector<int>& parent, int cellIndex) {
        if (parent[cellIndex] == cellIndex) {
            return cellIndex;
        }
        return parent[cellIndex] =
                   findParent(parent, parent[cellIndex]);  // Path compression
    }

    // Helper function to union two components
    void unionComponents(vector<int>& parent, vector<int>& componentSize,
                         vector<int>& totalFish, int cellIndex1,
                         int cellIndex2) {
        int root1 = findParent(parent, cellIndex1);
        int root2 = findParent(parent, cellIndex2);

        if (root1 != root2) {
            // Union by size to optimize tree height
            if (componentSize[root1] < componentSize[root2]) {
                swap(root1, root2);
            }
            parent[root2] = root1;
            componentSize[root1] += componentSize[root2];
            totalFish[root1] += totalFish[root2];
        }
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rowCount = grid.size(), columnCount = grid[0].size();
        int totalCells = rowCount * columnCount;

        // Initialize Union-Find structures
        vector<int> parent(totalCells);
        vector<int> componentSize(totalCells, 1);
        vector<int> totalFish(totalCells);

        // Set initial parent and fish count for each cell
        iota(parent.begin(), parent.end(), 0);
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                int cellIndex = row * columnCount + column;
                totalFish[cellIndex] = grid[row][column];
            }
        }

        // Direction vectors for neighbors (right, left, down, up)
        vector<int> deltaRow{0, 0, 1, -1}, deltaColumn{1, -1, 0, 0};

        // Merge connected components
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (grid[row][column] >
                    0) {  // Process only water cells with fish
                    int cellIndex = row * columnCount + column;
                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = row + deltaRow[direction];
                        int neighborColumn = column + deltaColumn[direction];
                        if (neighborRow >= 0 && neighborRow < rowCount &&
                            neighborColumn >= 0 &&
                            neighborColumn < columnCount &&
                            grid[neighborRow][neighborColumn] > 0) {
                            int neighborIndex =
                                neighborRow * columnCount + neighborColumn;
                            unionComponents(parent, componentSize, totalFish,
                                            cellIndex, neighborIndex);
                        }
                    }
                }
            }
        }

        // Find the maximum fish in any component
        int maxFish = 0;
        for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
            if (findParent(parent, cellIndex) ==
                cellIndex) {  // Check if cellIndex is a root
                maxFish = max(maxFish, totalFish[cellIndex]);
            }
        }
        return maxFish;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Helper function to find the root of a component
    private int findParent(int[] parent, int cellIndex) {
        if (parent[cellIndex] == cellIndex) {
            return cellIndex;
        }
        return parent[cellIndex] = findParent(parent, parent[cellIndex]); // Path compression
    }

    // Helper function to union two components
    private void unionComponents(
        int[] parent,
        int[] componentSize,
        int[] totalFish,
        int cellIndex1,
        int cellIndex2
    ) {
        int root1 = findParent(parent, cellIndex1);
        int root2 = findParent(parent, cellIndex2);

        if (root1 != root2) {
            // Union by size to optimize tree height
            if (componentSize[root1] < componentSize[root2]) {
                int temp = root1;
                root1 = root2;
                root2 = temp;
            }
            parent[root2] = root1;
            componentSize[root1] += componentSize[root2];
            totalFish[root1] += totalFish[root2];
        }
    }

    public int findMaxFish(int[][] grid) {
        int rowCount = grid.length, columnCount = grid[0].length;
        int totalCells = rowCount * columnCount;

        // Initialize Union-Find structures
        int[] parent = new int[totalCells];
        int[] componentSize = new int[totalCells];
        int[] totalFish = new int[totalCells];

        for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
            parent[cellIndex] = cellIndex; // Set initial parent for each cell
            componentSize[cellIndex] = 1; // Set initial size for each cell component
        }

        // Set initial fish count for each cell
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                int cellIndex = row * columnCount + column;
                totalFish[cellIndex] = grid[row][column];
            }
        }

        // Direction vectors for neighbors (right, left, down, up)
        int[] deltaRow = { 0, 0, 1, -1 }, deltaColumn = { 1, -1, 0, 0 };

        // Merge connected components
        for (int row = 0; row < rowCount; row++) {
            for (int column = 0; column < columnCount; column++) {
                if (grid[row][column] > 0) { // Process only water cells with fish
                    int cellIndex = row * columnCount + column;
                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = row + deltaRow[direction];
                        int neighborColumn = column + deltaColumn[direction];
                        if (
                            neighborRow >= 0 &&
                            neighborRow < rowCount &&
                            neighborColumn >= 0 &&
                            neighborColumn < columnCount &&
                            grid[neighborRow][neighborColumn] > 0
                        ) {
                            int neighborIndex =
                                neighborRow * columnCount + neighborColumn;
                            unionComponents(
                                parent,
                                componentSize,
                                totalFish,
                                cellIndex,
                                neighborIndex
                            );
                        }
                    }
                }
            }
        }

        // Find the maximum fish in any component
        int maxFish = 0;
        for (int cellIndex = 0; cellIndex < totalCells; cellIndex++) {
            if (findParent(parent, cellIndex) == cellIndex) { // Check if cellIndex is a root
                maxFish = Math.max(maxFish, totalFish[cellIndex]);
            }
        }
        return maxFish;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMaxFish(self, grid):
        def find_parent(cell_index):  # Find the root of a component
            if parent[cell_index] != cell_index:
                parent[cell_index] = find_parent(
                    parent[cell_index]
                )  # Path compression
            return parent[cell_index]

        def union_components(cell_index1, cell_index2):  # Union two components
            root1 = find_parent(cell_index1)
            root2 = find_parent(cell_index2)
            if root1 != root2:
                # Union by size to optimize tree height
                if component_size[root1] < component_size[root2]:
                    root1, root2 = root2, root1
                parent[root2] = root1
                component_size[root1] += component_size[root2]
                total_fish[root1] += total_fish[root2]

        row_count, column_count = len(grid), len(grid[0])
        total_cells = row_count * column_count

        # Initialize Union-Find structures
        parent = list(range(total_cells))
        component_size = [1] * total_cells
        total_fish = [0] * total_cells

        # Set initial fish count for each cell
        for row in range(row_count):
            for column in range(column_count):
                cell_index = row * column_count + column
                total_fish[cell_index] = grid[row][column]

        # Direction vectors for neighbors (right, left, down, up)
        delta_row = [0, 0, 1, -1]
        delta_column = [1, -1, 0, 0]

        # Merge connected components
        for row in range(row_count):
            for column in range(column_count):
                if grid[row][column] > 0:  # Process only water cells with fish
                    cell_index = row * column_count + column
                    for direction in range(4):
                        neighbor_row = row + delta_row[direction]
                        neighbor_column = column + delta_column[direction]
                        if (
                            0 <= neighbor_row < row_count
                            and 0 <= neighbor_column < column_count
                            and grid[neighbor_row][neighbor_column] > 0
                        ):
                            neighbor_index = (
                                neighbor_row * column_count + neighbor_column
                            )
                            union_components(cell_index, neighbor_index)

        # Find the maximum fish in any component
        max_fish = 0
        for cell_index in range(total_cells):
            if (
                find_parent(cell_index) == cell_index
            ):  # Check if `cell_index` is a root
                max_fish = max(max_fish, total_fish[cell_index])

        return max_fish
```

</details>
