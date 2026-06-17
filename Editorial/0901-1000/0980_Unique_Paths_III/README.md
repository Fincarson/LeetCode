# 980. Unique Paths III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/unique-paths-iii/)  
`Array` `Backtracking` `Bit Manipulation` `Matrix`

**Problem Link:** [LeetCode 980 - Unique Paths III](https://leetcode.com/problems/unique-paths-iii/)

## Problem

You are given an m x n integer array grid where grid[i][j] could be:

- 1 representing the starting square. There is exactly one starting square.
- 2 representing the ending square. There is exactly one ending square.
- 0 representing empty squares we can walk over.
- -1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

### Example 1

```text
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

### Example 2

```text
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
```

### Example 3

```text
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 20
- 1 <= m * n <= 20
- -1 <= grid[i][j] <= 2
- There is exactly one starting cell and one ending cell.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Word Search II](https://leetcode.com/problems/word-search-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 980. Unique Paths III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int rows, cols;
    int[][] grid;
    int path_count;

    protected void backtrack(int row, int col, int remain) {
        // base case for the termination of backtracking
        if (this.grid[row][col] == 2 && remain == 1) {
            // reach the destination
            this.path_count += 1;
            return;
        }

        // mark the square as visited. case: 0, 1, 2
        int temp = grid[row][col];
        grid[row][col] = -4;
        remain -= 1; // we now have one less square to visit

        // explore the 4 potential directions around
        int[] row_offsets = {0, 0, 1, -1};
        int[] col_offsets = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int next_row = row + row_offsets[i];
            int next_col = col + col_offsets[i];

            if (0 > next_row || next_row >= this.rows ||
                0 > next_col || next_col >= this.cols)
                // invalid coordinate
                continue;

            if (grid[next_row][next_col] < 0)
                // either obstacle or visited square
                continue;

            backtrack(next_row, next_col, remain);
        }

        // unmark the square after the visit
        grid[row][col] = temp;
    }

    public int uniquePathsIII(int[][] grid) {
        int non_obstacles = 0, start_row = 0, start_col = 0;

        this.rows = grid.length;
        this.cols = grid[0].length;

        // step 1). initialize the conditions for backtracking
        //   i.e. initial state and final state
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col) {
                int cell = grid[row][col];
                if (cell >= 0)
                    non_obstacles += 1;
                if (cell == 1) {
                    start_row = row;
                    start_col = col;
                }
            }

        this.path_count = 0;
        this.grid = grid;

        // kick-off the backtracking
        backtrack(start_row, start_col, non_obstacles);

        return this.path_count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        # step 1). initialize the conditions for backtracking
        #   i.e. initial state and final state
        non_obstacles = 0
        start_row, start_col = 0, 0
        for row in range(0, rows):
            for col in range(0, cols):
                cell = grid[row][col] 
                if  cell >= 0:
                    non_obstacles += 1
                if cell == 1:
                    start_row, start_col = row, col

        # count of paths as the final result
        path_count = 0

        # step 2). backtrack on the grid
        def backtrack(row, col, remain):
            # we need to modify this external variable
            nonlocal path_count

            # base case for the termination of backtracking
            if grid[row][col] == 2 and remain == 1:
                # reach the destination
                path_count += 1
                return

            # mark the square as visited. case: 0, 1, 2 
            temp = grid[row][col] 
            grid[row][col] = -4
            remain -= 1   # we now have one less square to visit

            # explore the 4 potential directions around
            for ro, co in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                next_row, next_col = row + ro, col + co

                if not (0 <= next_row < rows and 0 <= next_col < cols):
                    # invalid coordinate
                    continue
                if grid[next_row][next_col] < 0:
                    # either obstacle or visited square
                    continue

                backtrack(next_row, next_col, remain)

            # unmark the square after the visit
            grid[row][col] = temp

        backtrack(start_row, start_col, non_obstacles)

        return path_count
```

</details>
