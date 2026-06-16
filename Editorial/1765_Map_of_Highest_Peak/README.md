# 1765. Map of Highest Peak

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/map-of-highest-peak/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1765 - Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak/)

## Problem

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

- If isWater[i][j] == 0, cell (i, j) is a land cell.
- If isWater[i][j] == 1, cell (i, j) is a water cell.

You must assign each cell a height in a way that follows these rules:

- The height of each cell must be non-negative.
- If the cell is a water cell, its height must be 0.
- Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

### Example 1

```text
Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
```

### Example 2

```text
Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
```

## Constraints

- m == isWater.length
- n == isWater[i].length
- 1 <= m, n <= 1000
- isWater[i][j] is 0 or 1.
- There is at least one water cell.

Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1765. Map of Highest Peak

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |

## Approach 1: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1,
                     -1};  // Horizontal movement: right, left, down, up
        int dy[4] = {1, -1, 0, 0};  // Vertical movement corresponding to dx

        int rows = isWater.size();
        int columns = isWater[0].size();

        // Initialize the height matrix with -1 (unprocessed cells)
        vector<vector<int>> cellHeights(rows, vector<int>(columns, -1));

        queue<pair<int, int>> cellQueue;

        // Add all water cells to the queue and set their height to 0
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (isWater[x][y]) {
                    cellQueue.push({x, y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        // Initial height for land cells adjacent to water
        int heightOfNextLayer = 1;

        while (!cellQueue.empty()) {
            int layerSize = cellQueue.size();

            // Iterate through all cells in the current layer
            for (int i = 0; i < layerSize; i++) {
                pair<int, int> currentCell = cellQueue.front();
                cellQueue.pop();

                // Check all four possible directions for neighboring cells
                for (int d = 0; d < 4; d++) {
                    pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                   currentCell.second + dy[d]};

                    // Check if the neighbor is valid and unprocessed
                    if (isValidCell(neighborCell, rows, columns) &&
                        cellHeights[neighborCell.first][neighborCell.second] ==
                            -1) {
                        cellHeights[neighborCell.first][neighborCell.second] =
                            heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }
            heightOfNextLayer++;  // Increment height for the next layer
        }

        return cellHeights;
    }

private:
    // Function to check if a cell is within the grid boundaries
    bool isValidCell(pair<int, int> cell, int rows, int columns) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
               cell.second < columns;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] highestPeak(int[][] isWater) {
        int[] dx = { 0, 0, 1, -1 }; // Horizontal movement: right, left, down, up
        int[] dy = { 1, -1, 0, 0 }; // Vertical movement corresponding to dx

        int rows = isWater.length;
        int columns = isWater[0].length;

        // Initialize the height matrix with -1 (unprocessed cells)
        int[][] cellHeights = new int[rows][columns];
        for (int[] row : cellHeights) {
            Arrays.fill(row, -1);
        }

        // Queue to perform breadth-first search
        Queue<int[]> cellQueue = new LinkedList<>();

        // Add all water cells to the queue and set their height to 0
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (isWater[x][y] == 1) {
                    cellQueue.add(new int[] { x, y });
                    cellHeights[x][y] = 0;
                }
            }
        }

        int heightOfNextLayer = 1; // Initial height for land cells adjacent to water

        // Perform BFS
        while (!cellQueue.isEmpty()) {
            int layerSize = cellQueue.size();

            // Iterate through all cells in the current layer
            for (int i = 0; i < layerSize; i++) {
                int[] currentCell = cellQueue.poll();

                // Check all four possible directions for neighboring cells
                for (int d = 0; d < 4; d++) {
                    int neighborX = currentCell[0] + dx[d];
                    int neighborY = currentCell[1] + dy[d];

                    // Check if the neighbor is valid and unprocessed
                    if (
                        isValidCell(neighborX, neighborY, rows, columns) &&
                        cellHeights[neighborX][neighborY] == -1
                    ) {
                        cellHeights[neighborX][neighborY] = heightOfNextLayer;
                        cellQueue.add(new int[] { neighborX, neighborY });
                    }
                }
            }
            heightOfNextLayer++; // Increment height for the next layer
        }

        return cellHeights;
    }

    // Function to check if a cell is within the grid boundaries
    private boolean isValidCell(int x, int y, int rows, int columns) {
        return x >= 0 && y >= 0 && x < rows && y < columns;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def highestPeak(self, is_water):
        dx = [0, 0, 1, -1]  # Horizontal movement: right, left, down, up
        dy = [1, -1, 0, 0]  # Vertical movement corresponding to dx

        rows = len(is_water)
        columns = len(is_water[0])

        # Initialize the height matrix with -1 (unprocessed cells)
        cell_heights = [[-1 for _ in range(columns)] for _ in range(rows)]

        # Queue to perform breadth-first search
        cell_queue = deque()

        # Add all water cells to the queue and set their height to 0
        for x in range(rows):
            for y in range(columns):
                if is_water[x][y] == 1:
                    cell_queue.append((x, y))
                    cell_heights[x][y] = 0

        # Initial height for land cells adjacent to water
        height_of_next_layer = 1

        # Perform BFS
        while cell_queue:
            layer_size = len(cell_queue)

            # Iterate through all cells in the current layer
            for _ in range(layer_size):
                current_cell = cell_queue.popleft()

                # Check all four possible directions for neighboring cells
                for d in range(4):
                    neighbor_x = current_cell[0] + dx[d]
                    neighbor_y = current_cell[1] + dy[d]

                    # Check if the neighbor is valid and unprocessed
                    if (
                        self._is_valid_cell(
                            neighbor_x, neighbor_y, rows, columns
                        )
                        and cell_heights[neighbor_x][neighbor_y] == -1
                    ):
                        cell_heights[neighbor_x][
                            neighbor_y
                        ] = height_of_next_layer
                        cell_queue.append((neighbor_x, neighbor_y))

            height_of_next_layer += 1  # Increment height for the next layer

        return cell_heights

    def _is_valid_cell(self, x, y, rows, columns):
        """Check if a cell is within the grid boundaries."""
        return 0 <= x < rows and 0 <= y < columns
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int columns = isWater[0].size();
        // Large value to represent uninitialized heights
        const int INF = rows * columns;

        // Initialize the cellHeights matrix with INF (unprocessed cells)
        vector<vector<int>> cellHeights(rows, vector<int>(columns, INF));

        // Set the height of water cells to 0
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (isWater[row][col]) {
                    cellHeights[row][col] = 0;  // Water cells have height 0
                }
            }
        }

        // Forward pass: updating heights based on top and left neighbors
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                // Initialize minimum neighbor distance
                int minNeighborDistance = INF;

                // Check the cell above
                int neighborRow = row - 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Check the cell to the left
                neighborRow = row;
                neighborCol = col - 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Set the current cell's height as the minimum of its neighbors
                // + 1
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        // Backward pass: updating heights based on bottom and right neighbors
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                // Initialize minimum neighbor distance
                int minNeighborDistance = INF;

                // Check the cell below
                int neighborRow = row + 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Check the cell to the right
                neighborRow = row;
                neighborCol = col + 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance =
                        min(minNeighborDistance,
                            cellHeights[neighborRow][neighborCol]);
                }

                // Set the current cell's height as the minimum of its neighbors
                // + 1
                cellHeights[row][col] =
                    min(cellHeights[row][col], minNeighborDistance + 1);
            }
        }

        return cellHeights;  // Return the calculated cell heights
    }

private:
    // Function to check if a cell is within grid bounds
    bool isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int[][] highestPeak(int[][] isWater) {
        int rows = isWater.length;
        int columns = isWater[0].length;
        final int INF = rows * columns; // Large value to represent uninitialized heights

        // Initialize the cellHeights matrix with INF (unprocessed cells)
        int[][] cellHeights = new int[rows][columns];
        for (int[] row : cellHeights) {
            Arrays.fill(row, INF);
        }

        // Set the height of water cells to 0
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (isWater[row][col] == 1) {
                    cellHeights[row][col] = 0; // Water cells have height 0
                }
            }
        }

        // Forward pass: updating heights based on top and left neighbors
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                int minNeighborDistance = INF; // Initialize minimum neighbor distance

                // Check the cell above
                int neighborRow = row - 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance = Math.min(
                        minNeighborDistance,
                        cellHeights[neighborRow][neighborCol]
                    );
                }

                // Check the cell to the left
                neighborRow = row;
                neighborCol = col - 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance = Math.min(
                        minNeighborDistance,
                        cellHeights[neighborRow][neighborCol]
                    );
                }

                // Set the current cell's height as the minimum of its neighbors + 1
                cellHeights[row][col] = Math.min(
                    cellHeights[row][col],
                    minNeighborDistance + 1
                );
            }
        }

        // Backward pass: updating heights based on bottom and right neighbors
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                int minNeighborDistance = INF; // Initialize minimum neighbor distance

                // Check the cell below
                int neighborRow = row + 1;
                int neighborCol = col;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance = Math.min(
                        minNeighborDistance,
                        cellHeights[neighborRow][neighborCol]
                    );
                }

                // Check the cell to the right
                neighborRow = row;
                neighborCol = col + 1;
                if (isValidCell(neighborRow, neighborCol, rows, columns)) {
                    minNeighborDistance = Math.min(
                        minNeighborDistance,
                        cellHeights[neighborRow][neighborCol]
                    );
                }

                // Set the current cell's height as the minimum of its neighbors + 1
                cellHeights[row][col] = Math.min(
                    cellHeights[row][col],
                    minNeighborDistance + 1
                );
            }
        }

        return cellHeights; // Return the calculated cell heights
    }

    // Function to check if a cell is within grid bounds
    private boolean isValidCell(int row, int col, int rows, int columns) {
        return row >= 0 && col >= 0 && row < rows && col < columns;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def highestPeak(self, is_water: List[List[int]]) -> List[List[int]]:
        rows = len(is_water)
        columns = len(is_water[0])
        INF = rows * columns  # Large value to represent uninitialized heights

        # Initialize the cellHeights matrix with INF (unprocessed cells)
        cell_heights = [[INF] * columns for _ in range(rows)]

        # Set the height of water cells to 0
        for row in range(rows):
            for col in range(columns):
                if is_water[row][col] == 1:
                    cell_heights[row][col] = 0  # Water cells have height 0

        # Forward pass: updating heights based on top and left neighbors
        for row in range(rows):
            for col in range(columns):
                # Initialize minimum neighbor distance
                min_neighbor_distance = INF

                # Check the cell above
                neighbor_row = row - 1
                neighbor_col = col
                if self.is_valid_cell(
                    neighbor_row, neighbor_col, rows, columns
                ):
                    min_neighbor_distance = min(
                        min_neighbor_distance,
                        cell_heights[neighbor_row][neighbor_col],
                    )

                # Check the cell to the left
                neighbor_row = row
                neighbor_col = col - 1
                if self.is_valid_cell(
                    neighbor_row, neighbor_col, rows, columns
                ):
                    min_neighbor_distance = min(
                        min_neighbor_distance,
                        cell_heights[neighbor_row][neighbor_col],
                    )

                # Set the current cell's height as the minimum of its neighbors + 1
                cell_heights[row][col] = min(
                    cell_heights[row][col], min_neighbor_distance + 1
                )

        # Backward pass: updating heights based on bottom and right neighbors
        for row in range(rows - 1, -1, -1):
            for col in range(columns - 1, -1, -1):
                # Initialize minimum neighbor distance
                min_neighbor_distance = INF

                # Check the cell below
                neighbor_row = row + 1
                neighbor_col = col
                if self.is_valid_cell(
                    neighbor_row, neighbor_col, rows, columns
                ):
                    min_neighbor_distance = min(
                        min_neighbor_distance,
                        cell_heights[neighbor_row][neighbor_col],
                    )

                # Check the cell to the right
                neighbor_row = row
                neighbor_col = col + 1
                if self.is_valid_cell(
                    neighbor_row, neighbor_col, rows, columns
                ):
                    min_neighbor_distance = min(
                        min_neighbor_distance,
                        cell_heights[neighbor_row][neighbor_col],
                    )

                # Set the current cell's height as the minimum of its neighbors + 1
                cell_heights[row][col] = min(
                    cell_heights[row][col], min_neighbor_distance + 1
                )

        return cell_heights  # Return the calculated cell heights

    # Function to check if a cell is within grid bounds
    def is_valid_cell(
        self, row: int, col: int, rows: int, columns: int
    ) -> bool:
        return 0 <= row < rows and 0 <= col < columns
```

</details>
