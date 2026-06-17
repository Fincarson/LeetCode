# 959. Regions Cut By Slashes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/regions-cut-by-slashes/)  
`Array` `Hash Table` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 959 - Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/)

## Problem

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

### Example 1

```text
Input: grid = [" /","/ "]
Output: 2
```

### Example 2

```text
Input: grid = [" /","  "]
Output: 1
```

### Example 3

```text
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
```

## Constraints

- n == grid.length == grid[i].length
- 1 <= n <= 30
- grid[i][j] is either '/', '\', or ' '.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 959. Regions Cut By Slashes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Expanded Grid | C++, Java, Python3 |
| Disjoint Set Union (Triangles) | C++, Java, Python3 |
| Disjoint Set Union (Graph) | C++, Java, Python3 |

## Approach 1: Expanded Grid

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        // Create a 3x3 matrix for each cell in the original grid
        vector<vector<int>> expandedGrid(gridSize * 3,
                                         vector<int>(gridSize * 3, 0));

        // Populate the expanded grid based on the original grid
        // 1 represents a barrier in the expanded grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;
                // Check the character in the original grid
                if (grid[i][j] == '\\') {
                    // Mark diagonal for backslash
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } else if (grid[i][j] == '/') {
                    // Mark diagonal for forward slash
                    expandedGrid[baseRow][baseCol + 2] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol] = 1;
                }
            }
        }

        int regionCount = 0;
        // Count regions using flood fill
        for (int i = 0; i < gridSize * 3; i++) {
            for (int j = 0; j < gridSize * 3; j++) {
                // If we find an unvisited cell (0), it's a new region
                if (expandedGrid[i][j] == 0) {
                    // Fill that region
                    floodFill(expandedGrid, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }

private:
    // Directions for traversal: right, left, down, up
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Flood fill algorithm to mark all cells in a region
    void floodFill(vector<vector<int>>& expandedGrid, int row, int col) {
        queue<pair<int, int>> q;
        expandedGrid[row][col] = 1;
        q.push({row, col});

        while (!q.empty()) {
            auto [currentRow, currentCol] = q.front();
            q.pop();
            // Check all four directions from the current cell
            for (const auto& direction : DIRECTIONS) {
                int newRow = direction[0] + currentRow;
                int newCol = direction[1] + currentCol;
                // If the new cell is valid and unvisited, mark it and add to
                // queue
                if (isValidCell(expandedGrid, newRow, newCol)) {
                    expandedGrid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    // Check if a cell is within bounds and unvisited
    bool isValidCell(const vector<vector<int>>& expandedGrid, int row,
                     int col) {
        int n = expandedGrid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               expandedGrid[row][col] == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for traversal: right, left, down, up
    private static final int[][] DIRECTIONS = {
        { 0, 1 },
        { 0, -1 },
        { 1, 0 },
        { -1, 0 },
    };

    public int regionsBySlashes(String[] grid) {
        int gridSize = grid.length;
        // Create a 3x3 matrix for each cell in the original grid
        int[][] expandedGrid = new int[gridSize * 3][gridSize * 3];

        // Populate the expanded grid based on the original grid
        // 1 represents a barrier in the expanded grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;
                // Check the character in the original grid
                if (grid[i].charAt(j) == '\\') {
                    // Mark diagonal for backslash
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } else if (grid[i].charAt(j) == '/') {
                    // Mark diagonal for forward slash
                    expandedGrid[baseRow][baseCol + 2] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol] = 1;
                }
            }
        }

        int regionCount = 0;
        // Count regions using flood fill
        for (int i = 0; i < gridSize * 3; i++) {
            for (int j = 0; j < gridSize * 3; j++) {
                // If we find an unvisited cell (0), it's a new region
                if (expandedGrid[i][j] == 0) {
                    // Fill that region
                    floodFill(expandedGrid, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }

    // Flood fill algorithm to mark all cells in a region
    private void floodFill(int[][] expandedGrid, int row, int col) {
        Queue<int[]> queue = new LinkedList<>();
        expandedGrid[row][col] = 1;
        queue.add(new int[] { row, col });

        while (!queue.isEmpty()) {
            int[] currentCell = queue.poll();
            // Check all four directions from the current cell
            for (int[] direction : DIRECTIONS) {
                int newRow = direction[0] + currentCell[0];
                int newCol = direction[1] + currentCell[1];
                // If the new cell is valid and unvisited, mark it and add to queue
                if (isValidCell(expandedGrid, newRow, newCol)) {
                    expandedGrid[newRow][newCol] = 1;
                    queue.add(new int[] { newRow, newCol });
                }
            }
        }
    }

    // Check if a cell is within bounds and unvisited
    private boolean isValidCell(int[][] expandedGrid, int row, int col) {
        int n = expandedGrid.length;
        return (
            row >= 0 &&
            col >= 0 &&
            row < n &&
            col < n &&
            expandedGrid[row][col] == 0
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Directions for traversal: right, left, down, up
    DIRECTIONS = [
        (0, 1),
        (0, -1),
        (1, 0),
        (-1, 0),
    ]

    def regionsBySlashes(self, grid):
        grid_size = len(grid)
        # Create a 3x3 matrix for each cell in the original grid
        expanded_grid = [[0] * (grid_size * 3) for _ in range(grid_size * 3)]

        # Populate the expanded grid based on the original grid
        # 1 represents a barrier in the expanded grid
        for i in range(grid_size):
            for j in range(grid_size):
                base_row = i * 3
                base_col = j * 3
                # Check the character in the original grid
                if grid[i][j] == "\\":
                    # Mark diagonal for backslash
                    expanded_grid[base_row][base_col] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row + 2][base_col + 2] = 1
                elif grid[i][j] == "/":
                    # Mark diagonal for forward slash
                    expanded_grid[base_row][base_col + 2] = 1
                    expanded_grid[base_row + 1][base_col + 1] = 1
                    expanded_grid[base_row + 2][base_col] = 1

        region_count = 0
        # Count regions using flood fill
        for i in range(grid_size * 3):
            for j in range(grid_size * 3):
                # If we find an unvisited cell (0), it's a new region
                if expanded_grid[i][j] == 0:
                    # Fill that region
                    self._flood_fill(expanded_grid, i, j)
                    region_count += 1

        return region_count

    # Flood fill algorithm to mark all cells in a region
    def _flood_fill(self, expanded_grid, row, col):
        queue = [(row, col)]
        expanded_grid[row][col] = 1

        while queue:
            current_cell = queue.pop(0)
            # Check all four directions from the current cell
            for direction in self.DIRECTIONS:
                new_row = direction[0] + current_cell[0]
                new_col = direction[1] + current_cell[1]
                # If the new cell is valid and unvisited, mark it and add to queue
                if self._is_valid_cell(expanded_grid, new_row, new_col):
                    expanded_grid[new_row][new_col] = 1
                    queue.append((new_row, new_col))

    # Check if a cell is within bounds and unvisited
    def _is_valid_cell(self, expanded_grid, row, col):
        n = len(expanded_grid)
        return (
            row >= 0
            and col >= 0
            and row < n
            and col < n
            and expanded_grid[row][col] == 0
        )
```

</details>

<br>

## Approach 2: Disjoint Set Union (Triangles)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        int totalTriangles = gridSize * gridSize * 4;
        vector<int> parentArray(totalTriangles, -1);

        // Initially, each small triangle is a separate region
        int regionCount = totalTriangles;

        for (int row = 0; row < gridSize; row++) {
            for (int col = 0; col < gridSize; col++) {
                // Connect with the cell above
                if (row > 0) {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row - 1, col, 2),
                        getTriangleIndex(gridSize, row, col, 0));
                }
                // Connect with the cell to the left
                if (col > 0) {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col - 1, 1),
                        getTriangleIndex(gridSize, row, col, 3));
                }

                // If not '/', connect triangles 0-1 and 2-3
                if (grid[row][col] != '/') {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 1));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 3));
                }

                // If not '\', connect triangles 0-3 and 1-2
                if (grid[row][col] != '\\') {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 3));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 1));
                }
            }
        }
        return regionCount;
    }

private:
    // Calculate the index of a triangle in the flattened array
    // Each cell is divided into 4 triangles, numbered 0 to 3 clockwise from the
    // top
    int getTriangleIndex(int gridSize, int row, int col, int triangleNum) {
        return (gridSize * row + col) * 4 + triangleNum;
    }

    // Union two triangles and return 1 if they were not already connected, 0
    // otherwise
    int unionTriangles(vector<int>& parentArray, int x, int y) {
        int parentX = findParent(parentArray, x);
        int parentY = findParent(parentArray, y);

        if (parentX != parentY) {
            parentArray[parentX] = parentY;
            return 1;  // Regions were merged, so count decreases by 1
        }

        return 0;  // Regions were already connected
    }

    // Find the parent (root) of a set
    int findParent(vector<int>& parentArray, int x) {
        if (parentArray[x] == -1) return x;

        return parentArray[x] = findParent(parentArray, parentArray[x]);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int regionsBySlashes(String[] grid) {
        int gridSize = grid.length;
        int totalTriangles = gridSize * gridSize * 4;
        int[] parentArray = new int[totalTriangles];
        Arrays.fill(parentArray, -1);

        // Initially, each small triangle is a separate region
        int regionCount = totalTriangles;

        for (int row = 0; row < gridSize; row++) {
            for (int col = 0; col < gridSize; col++) {
                // Connect with the cell above
                if (row > 0) {
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row - 1, col, 2),
                        getTriangleIndex(gridSize, row, col, 0)
                    );
                }
                // Connect with the cell to the left
                if (col > 0) {
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col - 1, 1),
                        getTriangleIndex(gridSize, row, col, 3)
                    );
                }

                // If not '/', connect triangles 0-1 and 2-3
                if (grid[row].charAt(col) != '/') {
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 1)
                    );
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 3)
                    );
                }

                // If not '\', connect triangles 0-3 and 1-2
                if (grid[row].charAt(col) != '\\') {
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 3)
                    );
                    regionCount -=
                    unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 1)
                    );
                }
            }
        }
        return regionCount;
    }

    // Calculate the index of a triangle in the flattened array
    // Each cell is divided into 4 triangles, numbered 0 to 3 clockwise from the top
    private int getTriangleIndex(
        int gridSize,
        int row,
        int col,
        int triangleNum
    ) {
        return (gridSize * row + col) * 4 + triangleNum;
    }

    // Union two triangles and return 1 if they were not already connected, 0 otherwise
    private int unionTriangles(int[] parentArray, int x, int y) {
        int parentX = findParent(parentArray, x);
        int parentY = findParent(parentArray, y);

        if (parentX != parentY) {
            parentArray[parentX] = parentY;
            return 1; // Regions were merged, so count decreases by 1
        }

        return 0; // Regions were already connected
    }

    // Find the parent (root) of a set
    private int findParent(int[] parentArray, int x) {
        if (parentArray[x] == -1) return x;

        return parentArray[x] = findParent(parentArray, parentArray[x]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_size = len(grid)
        total_triangles = grid_size * grid_size * 4
        parent_array = [-1] * total_triangles

        # Initially, each small triangle is a separate region
        region_count = total_triangles

        for row in range(grid_size):
            for col in range(grid_size):
                # Connect with the cell above
                if row > 0:
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row - 1, col, 2),
                        self._get_triangle_index(grid_size, row, col, 0),
                    )
                # Connect with the cell to the left
                if col > 0:
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row, col - 1, 1),
                        self._get_triangle_index(grid_size, row, col, 3),
                    )

                # If not '/', connect triangles 0-1 and 2-3
                if grid[row][col] != "/":
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row, col, 0),
                        self._get_triangle_index(grid_size, row, col, 1),
                    )
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row, col, 2),
                        self._get_triangle_index(grid_size, row, col, 3),
                    )

                # If not '\', connect triangles 0-3 and 1-2
                if grid[row][col] != "\\":
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row, col, 0),
                        self._get_triangle_index(grid_size, row, col, 3),
                    )
                    region_count -= self._union_triangles(
                        parent_array,
                        self._get_triangle_index(grid_size, row, col, 2),
                        self._get_triangle_index(grid_size, row, col, 1),
                    )

        return region_count

    # Calculate the index of a triangle in the flattened array
    # Each cell is divided into 4 triangles, numbered 0 to 3 clockwise from the top
    def _get_triangle_index(self, grid_size, row, col, triangle_num):
        return (grid_size * row + col) * 4 + triangle_num

    # Union two triangles and return 1 if they were not already connected, 0 otherwise
    def _union_triangles(self, parent_array, x, y):
        parent_x = self._find_parent(parent_array, x)
        parent_y = self._find_parent(parent_array, y)
        if parent_x != parent_y:
            parent_array[parent_x] = parent_y
            return 1  # Regions were merged, so count decreases by 1
        return 0  # Regions were already connected

    # Find the parent (root) of a set
    def _find_parent(self, parent_array, x):
        if parent_array[x] == -1:
            return x
        parent_array[x] = self._find_parent(parent_array, parent_array[x])
        return parent_array[x]
```

</details>

<br>

## Approach 3: Disjoint Set Union (Graph)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        int pointsPerSide = gridSize + 1;
        int totalPoints = pointsPerSide * pointsPerSide;

        // Initialize disjoint set data structure
        vector<int> parentArray(totalPoints, -1);

        // Connect border points
        for (int i = 0; i < pointsPerSide; i++) {
            for (int j = 0; j < pointsPerSide; j++) {
                if (i == 0 || j == 0 || i == pointsPerSide - 1 ||
                    j == pointsPerSide - 1) {
                    int point = i * pointsPerSide + j;
                    parentArray[point] = 0;
                }
            }
        }

        // Set the parent of the top-left corner to itself
        parentArray[0] = -1;
        int regionCount = 1;  // Start with one region (the border)

        // Process each cell in the grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                // Treat each slash as an edge connecting two points
                if (grid[i][j] == '/') {
                    int topRight = i * pointsPerSide + (j + 1);
                    int bottomLeft = (i + 1) * pointsPerSide + j;
                    regionCount +=
                        union_sets(parentArray, topRight, bottomLeft);
                } else if (grid[i][j] == '\\') {
                    int topLeft = i * pointsPerSide + j;
                    int bottomRight = (i + 1) * pointsPerSide + (j + 1);
                    regionCount +=
                        union_sets(parentArray, topLeft, bottomRight);
                }
            }
        }

        return regionCount;
    }

private:
    // Find the parent of a set
    int find(vector<int>& parentArray, int node) {
        if (parentArray[node] == -1) return node;

        return parentArray[node] = find(parentArray, parentArray[node]);
    }

    // Union two sets and return 1 if a new region is formed, 0 otherwise
    int union_sets(vector<int>& parentArray, int node1, int node2) {
        int parent1 = find(parentArray, node1);
        int parent2 = find(parentArray, node2);

        if (parent1 == parent2) {
            return 1;  // Nodes are already in the same set, new region formed
        }

        parentArray[parent2] = parent1;  // Union the sets
        return 0;                        // No new region formed
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int regionsBySlashes(String[] grid) {
        int gridSize = grid.length;
        int pointsPerSide = gridSize + 1;
        int totalPoints = pointsPerSide * pointsPerSide;

        // Initialize disjoint set data structure
        int[] parentArray = new int[totalPoints];
        Arrays.fill(parentArray, -1);

        // Connect border points
        for (int i = 0; i < pointsPerSide; i++) {
            for (int j = 0; j < pointsPerSide; j++) {
                if (
                    i == 0 ||
                    j == 0 ||
                    i == pointsPerSide - 1 ||
                    j == pointsPerSide - 1
                ) {
                    int point = i * pointsPerSide + j;
                    parentArray[point] = 0;
                }
            }
        }

        // Set the parent of the top-left corner to itself
        parentArray[0] = -1;
        int regionCount = 1; // Start with one region (the border)

        // Process each cell in the grid
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                // Treat each slash as an edge connecting two points
                if (grid[i].charAt(j) == '/') {
                    int topRight = i * pointsPerSide + (j + 1);
                    int bottomLeft = (i + 1) * pointsPerSide + j;
                    regionCount += union(parentArray, topRight, bottomLeft);
                } else if (grid[i].charAt(j) == '\\') {
                    int topLeft = i * pointsPerSide + j;
                    int bottomRight = (i + 1) * pointsPerSide + (j + 1);
                    regionCount += union(parentArray, topLeft, bottomRight);
                }
            }
        }

        return regionCount;
    }

    // Find the parent of a set
    private int find(int[] parentArray, int node) {
        if (parentArray[node] == -1) return node;

        return parentArray[node] = find(parentArray, parentArray[node]);
    }

    // Union two sets and return 1 if a new region is formed, 0 otherwise
    private int union(int[] parentArray, int node1, int node2) {
        int parent1 = find(parentArray, node1);
        int parent2 = find(parentArray, node2);

        if (parent1 == parent2) {
            return 1; // Nodes are already in the same set, new region formed
        }

        parentArray[parent2] = parent1; // Union the sets
        return 0; // No new region formed
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        grid_size = len(grid)
        points_per_side = grid_size + 1
        total_points = points_per_side * points_per_side

        # Initialize disjoint set data structure
        parent_array = [-1] * total_points

        # Connect border points
        for i in range(points_per_side):
            for j in range(points_per_side):
                if (
                    i == 0
                    or j == 0
                    or i == points_per_side - 1
                    or j == points_per_side - 1
                ):
                    point = i * points_per_side + j
                    parent_array[point] = 0

        # Set the parent of the top-left corner to itself
        parent_array[0] = -1
        region_count = 1  # Start with one region (the border)

        # Process each cell in the grid
        for i in range(grid_size):
            for j in range(grid_size):
                # Treat each slash as an edge connecting two points
                if grid[i][j] == "/":
                    top_right = i * points_per_side + (j + 1)
                    bottom_left = (i + 1) * points_per_side + j
                    region_count += self._union(
                        parent_array, top_right, bottom_left
                    )
                elif grid[i][j] == "\\":
                    top_left = i * points_per_side + j
                    bottom_right = (i + 1) * points_per_side + (j + 1)
                    region_count += self._union(
                        parent_array, top_left, bottom_right
                    )

        return region_count

    def _find(self, parent_array: List[int], node: int) -> int:
        if parent_array[node] == -1:
            return node

        parent_array[node] = self._find(parent_array, parent_array[node])
        return parent_array[node]

    def _union(self, parent_array: List[int], node1: int, node2: int) -> int:
        parent1 = self._find(parent_array, node1)
        parent2 = self._find(parent_array, node2)

        if parent1 == parent2:
            return 1  # Nodes are already in the same set, new region formed

        parent_array[parent2] = parent1  # Union the sets
        return 0  # No new region formed
```

</details>
