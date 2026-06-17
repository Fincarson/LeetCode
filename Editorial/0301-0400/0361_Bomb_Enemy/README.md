# 361. Bomb Enemy

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/bomb-enemy/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 361 - Bomb Enemy](https://leetcode.com/problems/bomb-enemy/)

## Problem

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

### Example 1

```text
Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
```

### Example 2

```text
Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 500
- grid[i][j] is either 'W', 'E', or '0'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Stamping the Grid](https://leetcode.com/problems/stamping-the-grid/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Unguarded Cells in the Grid](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Trailing Zeros in a Cornered Path](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 361. Bomb Enemy

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-force Enumeration | Java, Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Brute-force Enumeration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        if (grid.length == 0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;

        int maxCount = 0;

        for (int row = 0; row < rows; ++ row) {
            for (int col = 0; col < cols; ++ col) {
                if (grid[row][col] == '0') {
                    int hits = this.killEnemies(row, col, grid);
                    maxCount = Math.max(maxCount, hits);
                }
            }
        }

        return maxCount;
    }

    /**
     * return the number of enemies we kill, starting from the given empty cell.
     */
    private int killEnemies(int row, int col, char[][] grid) {
        int enemyCount = 0;
        // look to the left side of the cell
        for (int c = col - 1; c >= 0; --c) {
            if (grid[row][c] == 'W')
                break;
            else if (grid[row][c] == 'E')
                enemyCount += 1;
        }

        // look to the right side of the cell
        for (int c = col + 1; c < grid[0].length; ++c) {
            if (grid[row][c] == 'W')
                break;
            else if (grid[row][c] == 'E')
                enemyCount += 1;
        }

        // look to the up side of the cell
        for (int r = row - 1; r >= 0; --r) {
            if (grid[r][col] == 'W')
                break;
            else if (grid[r][col] == 'E')
                enemyCount += 1;
        }

        // look to the down side of the cell
        for (int r = row + 1; r < grid.length; ++r) {
            if (grid[r][col] == 'W')
                break;
            else if (grid[r][col] == 'E')
                enemyCount += 1;
        }

        return enemyCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0

        rows, cols = len(grid), len(grid[0])

        def killEnemies(row, col):
            enemy_count = 0
            row_ranges = [range(row - 1, -1, -1), range(row + 1, rows, 1)]
            for row_range in row_ranges:
                for r in row_range:
                    if grid[r][col] == 'W':
                        break
                    elif grid[r][col] == 'E':
                        enemy_count += 1

            col_ranges = [range(col - 1, -1, -1), range(col + 1, cols, 1)]
            for col_range in col_ranges:
                for c in col_range:
                    if grid[row][c] == 'W':
                        break
                    elif grid[row][c] == 'E':
                        enemy_count += 1

            return enemy_count

        max_count = 0
        for row in range(0, rows):
            for col in range(0, cols):
                if grid[row][col] == '0':
                    max_count = max(max_count, killEnemies(row, col))

        return max_count
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        if (grid.length == 0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;

        int maxCount = 0, rowHits = 0;
        int[] colHits = new int[cols];

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // reset the hits on the row, if necessary.
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowHits = 0;
                    for (int k = col; k < cols; ++k) {
                        if (grid[row][k] == 'W')
                            // stop the scan when we hit the wall.
                            break;
                        else if (grid[row][k] == 'E')
                            rowHits += 1;
                    }
                }

                // reset the hits on the column, if necessary.
                if (row == 0 || grid[row - 1][col] == 'W') {
                    colHits[col] = 0;
                    for (int k = row; k < rows; ++k) {
                        if (grid[k][col] == 'W')
                            break;
                        else if (grid[k][col] == 'E')
                            colHits[col] += 1;
                    }
                }

                // run the calculation for the empty cell.
                if (grid[row][col] == '0') {
                    maxCount = Math.max(maxCount, rowHits + colHits[col]);
                }
            }
        }

        return maxCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0

        rows, cols = len(grid), len(grid[0])

        max_count = 0
        row_hits = 0
        col_hits = [0] * cols

        for row in range(0, rows):
            for col in range(0, cols):
                # reset the hits on the row, if necessary.
                if col == 0 or grid[row][col - 1] == 'W':
                    row_hits = 0
                    for k in range(col, cols):
                        if grid[row][k] == 'W':
                            # stop the scan when we hit the wall.
                            break
                        elif grid[row][k] == 'E':
                            row_hits += 1

                # reset the hits on the col, if necessary.
                if row == 0 or grid[row - 1][col] == 'W':
                    col_hits[col] = 0
                    for k in range(row, rows):
                        if grid[k][col] == 'W':
                            break
                        elif grid[k][col] == 'E':
                            col_hits[col] += 1

                # count the hits for each empty cell.
                if grid[row][col] == '0':
                    total_hits = row_hits + col_hits[col]
                    max_count = max(max_count, total_hits)

        return max_count
```

</details>
