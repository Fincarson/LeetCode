# 407. Trapping Rain Water II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/trapping-rain-water-ii/)  
`Array` `Breadth-First Search` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 407 - Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/)

## Problem

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

### Example 1

```text
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
```

### Example 2

```text
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
```

## Constraints

- m == heightMap.length
- n == heightMap[i].length
- 1 <= m, n <= 200
- 0 <= heightMap[i][j] <= 2 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Maximum Number of Points From Grid Queries](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 407. Trapping Rain Water II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: BFS + Priority Queue | C++, Java, Python3 |

## Approach: BFS + Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Direction arrays
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};

        int numOfRows = heightMap.size();
        int numOfCols = heightMap[0].size();

        vector<vector<bool>> visited(numOfRows, vector<bool>(numOfCols, false));

        // Priority queue (min-heap) to process boundary cells in increasing
        // height order
        priority_queue<Cell> boundary;

        // Add the first and last column cells to the boundary and mark them as
        // visited
        for (int i = 0; i < numOfRows; i++) {
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][numOfCols - 1], i, numOfCols - 1));
            // Mark left and right boundary cells as visited
            visited[i][0] = visited[i][numOfCols - 1] = true;
        }

        // Add the first and last row cells to the boundary and mark them as
        // visited
        for (int i = 0; i < numOfCols; i++) {
            boundary.push(Cell(heightMap[0][i], 0, i));
            boundary.push(Cell(heightMap[numOfRows - 1][i], numOfRows - 1, i));
            // Mark top and bottom boundary cells as visited
            visited[0][i] = visited[numOfRows - 1][i] = true;
        }

        int totalWaterVolume = 0;

        while (!boundary.empty()) {
            // Pop the cell with the smallest height from the boundary
            Cell currentCell = boundary.top();
            boundary.pop();

            int currentRow = currentCell.row;
            int currentCol = currentCell.col;
            int minBoundaryHeight = currentCell.height;

            // Explore all 4 neighboring cells
            for (int direction = 0; direction < 4; direction++) {
                int neighborRow = currentRow + dRow[direction];
                int neighborCol = currentCol + dCol[direction];

                // Check if the neighbor is within the grid bounds and not yet
                // visited
                if (isValidCell(neighborRow, neighborCol, numOfRows,
                                numOfCols) &&
                    !visited[neighborRow][neighborCol]) {
                    int neighborHeight = heightMap[neighborRow][neighborCol];

                    // If the neighbor's height is less than the current
                    // boundary height, water can be trapped
                    if (neighborHeight < minBoundaryHeight) {
                        totalWaterVolume += minBoundaryHeight - neighborHeight;
                    }

                    // Push the neighbor into the boundary with updated height
                    // (to prevent water leakage)
                    boundary.push(Cell(max(neighborHeight, minBoundaryHeight),
                                       neighborRow, neighborCol));
                    visited[neighborRow][neighborCol] = true;
                }
            }
        }

        return totalWaterVolume;
    }

private:
    // Struct to store the height and coordinates of a cell in the grid
    class Cell {
    public:
        int height;
        int row;
        int col;

        // Constructor to initialize a cell
        Cell(int height, int row, int col)
            : height(height), row(row), col(col) {}

        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell& other) const {
            // Reverse comparison to simulate a min-heap
            return height >= other.height;
        }
    };

    // Helper function to check if a cell is valid (within grid bounds)
    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int trapRainWater(int[][] heightMap) {
        // Direction arrays
        int[] dRow = { 0, 0, -1, 1 };
        int[] dCol = { -1, 1, 0, 0 };

        int numOfRows = heightMap.length;
        int numOfCols = heightMap[0].length;

        boolean[][] visited = new boolean[numOfRows][numOfCols];

        // Priority queue (min-heap) to process boundary cells in increasing height order
        PriorityQueue<Cell> boundary = new PriorityQueue<>();

        // Add the first and last column cells to the boundary and mark them as visited
        for (int i = 0; i < numOfRows; i++) {
            boundary.offer(new Cell(heightMap[i][0], i, 0));
            boundary.offer(
                new Cell(heightMap[i][numOfCols - 1], i, numOfCols - 1)
            );
            // Mark left and right boundary cells as visited
            visited[i][0] = visited[i][numOfCols - 1] = true;
        }

        // Add the first and last row cells to the boundary and mark them as visited
        for (int i = 0; i < numOfCols; i++) {
            boundary.offer(new Cell(heightMap[0][i], 0, i));
            boundary.offer(
                new Cell(heightMap[numOfRows - 1][i], numOfRows - 1, i)
            );
            // Mark top and bottom boundary cells as visited
            visited[0][i] = visited[numOfRows - 1][i] = true;
        }

        // Initialize the total water volume to 0
        int totalWaterVolume = 0;

        // Process cells in the boundary (min-heap will always pop the smallest height)
        while (!boundary.isEmpty()) {
            // Pop the cell with the smallest height from the boundary
            Cell currentCell = boundary.poll();

            int currentRow = currentCell.row;
            int currentCol = currentCell.col;
            int minBoundaryHeight = currentCell.height;

            // Explore all 4 neighboring cells
            for (int direction = 0; direction < 4; direction++) {
                // Calculate the row and column of the neighbor
                int neighborRow = currentRow + dRow[direction];
                int neighborCol = currentCol + dCol[direction];

                // Check if the neighbor is within the grid bounds and not yet visited
                if (
                    isValidCell(
                        neighborRow,
                        neighborCol,
                        numOfRows,
                        numOfCols
                    ) &&
                    !visited[neighborRow][neighborCol]
                ) {
                    // Get the height of the neighbor cell
                    int neighborHeight = heightMap[neighborRow][neighborCol];

                    // If the neighbor's height is less than the current boundary height, water can be trapped
                    if (neighborHeight < minBoundaryHeight) {
                        // Add the trapped water volume
                        totalWaterVolume += minBoundaryHeight - neighborHeight;
                    }

                    // Push the neighbor into the boundary with updated height (to prevent water leakage)
                    boundary.offer(
                        new Cell(
                            Math.max(neighborHeight, minBoundaryHeight),
                            neighborRow,
                            neighborCol
                        )
                    );
                    visited[neighborRow][neighborCol] = true;
                }
            }
        }

        // Return the total amount of trapped water
        return totalWaterVolume;
    }

    // Class to store the height and coordinates of a cell in the grid
    private static class Cell implements Comparable<Cell> {

        int height;
        int row;
        int col;

        // Constructor to initialize a cell
        public Cell(int height, int row, int col) {
            this.height = height;
            this.row = row;
            this.col = col;
        }

        // Overload the compareTo method to make the priority queue a min-heap based on height
        @Override
        public int compareTo(Cell other) {
            // Min-heap comparison
            return Integer.compare(this.height, other.height);
        }
    }

    // Helper function to check if a cell is valid (within grid bounds)
    private boolean isValidCell(
        int row,
        int col,
        int numOfRows,
        int numOfCols
    ) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Class to store the height and coordinates of a cell in the grid
    class Cell:
        def __init__(self, height, row, col):
            self.height = height
            self.row = row
            self.col = col

        # Comparison method for the priority queue (min-heap)
        def __lt__(self, other):
            return self.height < other.height

    # Helper function to check if a cell is valid (within grid bounds)
    def _is_valid_cell(self, row, col, num_of_rows, num_of_cols):
        return 0 <= row < num_of_rows and 0 <= col < num_of_cols

    def trapRainWater(self, height_map):
        # Direction arrays
        d_row = [0, 0, -1, 1]
        d_col = [-1, 1, 0, 0]

        num_of_rows = len(height_map)
        num_of_cols = len(height_map[0])

        visited = [[False] * num_of_cols for _ in range(num_of_rows)]

        # Priority queue (min-heap) to process boundary cells in increasing height order
        boundary = []

        # Add the first and last column cells to the boundary and mark them as visited
        for i in range(num_of_rows):
            heapq.heappush(boundary, self.Cell(height_map[i][0], i, 0))
            heapq.heappush(
                boundary,
                self.Cell(height_map[i][num_of_cols - 1], i, num_of_cols - 1),
            )
            visited[i][0] = visited[i][num_of_cols - 1] = True

        # Add the first and last row cells to the boundary and mark them as visited
        for i in range(num_of_cols):
            heapq.heappush(boundary, self.Cell(height_map[0][i], 0, i))
            heapq.heappush(
                boundary,
                self.Cell(height_map[num_of_rows - 1][i], num_of_rows - 1, i),
            )
            visited[0][i] = visited[num_of_rows - 1][i] = True

        # Initialize the total water volume to 0
        total_water_volume = 0

        # Process cells in the boundary (min-heap will always pop the smallest height)
        while boundary:
            # Pop the cell with the smallest height from the boundary
            current_cell = heapq.heappop(boundary)

            current_row = current_cell.row
            current_col = current_cell.col
            min_boundary_height = current_cell.height

            # Explore all 4 neighboring cells
            for direction in range(4):
                # Calculate the row and column of the neighbor
                neighbor_row = current_row + d_row[direction]
                neighbor_col = current_col + d_col[direction]

                # Check if the neighbor is within the grid bounds and not yet visited
                if (
                    self._is_valid_cell(
                        neighbor_row, neighbor_col, num_of_rows, num_of_cols
                    )
                    and not visited[neighbor_row][neighbor_col]
                ):
                    # Get the height of the neighbor cell
                    neighbor_height = height_map[neighbor_row][neighbor_col]

                    # If the neighbor's height is less than the current boundary height, water can be trapped
                    if neighbor_height < min_boundary_height:
                        # Add the trapped water volume
                        total_water_volume += (
                            min_boundary_height - neighbor_height
                        )

                    # Push the neighbor into the boundary with updated height (to prevent water leakage)
                    heapq.heappush(
                        boundary,
                        self.Cell(
                            max(neighbor_height, min_boundary_height),
                            neighbor_row,
                            neighbor_col,
                        ),
                    )
                    visited[neighbor_row][neighbor_col] = True

        # Return the total amount of trapped water
        return total_water_volume
```

</details>
