# 1260. Shift 2D Grid

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/shift-2d-grid/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 1260 - Shift 2D Grid](https://leetcode.com/problems/shift-2d-grid/)

## Problem

Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

- Element at grid[i][j] moves to grid[i][j + 1].
- Element at grid[i][n - 1] moves to grid[i + 1][0].
- Element at grid[m - 1][n - 1] moves to grid[0][0].

Return the 2D grid after applying shift operation k times.

### Example 1

```text
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
```

### Example 2

```text
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
```

### Example 3

```text
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m <= 50
- 1 <= n <= 50
- -1000 <= grid[i][j] <= 1000
- 0 <= k <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1260. Shift 2D Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | Java, Python |
| Simulation, Recycling Same Array | Java, Python |
| Using Modulo Arithmetic | Java, Python |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        // Repeat the transform k times.
        for (;k > 0; k--) {
            // We'll write the transform into a new 2D array.
            int[][] newGrid = new int[grid.length][grid[0].length];

            // Case #1: Move everything not in the last column.
            for (int row = 0; row < grid.length; row++) {
                for (int col = 0; col < grid[0].length - 1; col++) {
                    newGrid[row][col + 1] = grid[row][col];
                }
            }

            // Case #2: Move everything in last column, but not last row.
            for (int row = 0; row < grid.length - 1; row++) {
                newGrid[row + 1][0] = grid[row][grid[0].length - 1];
            }

            // Case #3: Move the bottom right.
            newGrid[0][0] = grid[grid.length - 1][grid[0].length - 1];

            // Update grid to be the transformed grid.
            grid = newGrid;
        }

        // Copy the grid into a list for returning.
        List<List<Integer>> result = new ArrayList<>();
        for (int[] row : grid) {
            List<Integer> listRow = new ArrayList<>();
            result.add(listRow);
            for (int v : row) listRow.add(v);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:

    num_rows, num_cols = len(grid), len(grid[0])

    for _ in range(k):
        # Create a new grid to copy into.
        new_grid = [[0] * num_cols for _ in range(num_rows)]

        # Case 1: Move everything not in the last column.
        for row in range(num_rows):
            for col in range(num_cols - 1):
                new_grid[row][col + 1] = grid[row][col]

        # Case 2: Move everything in last column, but not last row.
        for row in range(num_rows - 1):
             new_grid[row + 1][0] = grid[row][num_cols - 1]

        # Case 3: Move the bottom right.
        new_grid[0][0] = grid[num_rows - 1][num_cols - 1]

        grid = new_grid

    return grid
```

</details>

<br>

## Approach 2: Simulation, Recycling Same Array

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        // Repeat the transform k times.
        for (;k > 0; k--) {

            int previous = grid[grid.length - 1][grid[0].length - 1];
            for (int row = 0; row < grid.length; row++) {
                for (int col = 0; col < grid[0].length; col++) {
                    int temp = grid[row][col];
                    grid[row][col] = previous;
                    previous = temp;
                }
            }
        }

        // Copy the grid into a list for returning.
        List<List<Integer>> result = new ArrayList<>();
        for (int[] row : grid) {
            List<Integer> listRow = new ArrayList<>();
            result.add(listRow);
            for (int v : row) listRow.add(v);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:

        num_rows, num_cols = len(grid), len(grid[0])

        for _ in range(k):

            previous = grid[-1][-1]
            for row in range(num_rows):
                for col in range(num_cols):
                    temp = grid[row][col]
                    grid[row][col] = previous
                    previous = temp
        return grid
```

</details>

<br>

## Approach 3: Using Modulo Arithmetic

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        int numCols = grid[0].length;
        int numRows = grid.length;

        // Setup the 2d list.
        List<List<Integer>> newGrid = new ArrayList<>();
        for (int row = 0; row < numRows; row++) {
            List<Integer> newRow = new ArrayList<>();
            newGrid.add(newRow);
            for (int col = 0; col < numCols; col++) {
                newRow.add(0);
            }
        }

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int newCol = (col + k) % numCols;
                int wrapAroundCount = (col + k) / numCols;
                int newRow = (row + wrapAroundCount) % numRows;
                newGrid.get(newRow).set(newCol, grid[row][col]);
            }
        }

        return newGrid;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
    new_grid = [[0] * len(grid[0]) for _ in range(len(grid))]
    num_rows = len(grid)
    num_cols = len(grid[0])
    for row in range(num_rows):
        for col in range(num_cols):
            new_col = (col + k) % num_cols
            wrap_around_count = (col + k) // num_cols
            new_row = (row + wrap_around_count) % num_rows
            new_grid[new_row][new_col] = grid[row][col]
    return new_grid
```

</details>
