# 883. Projection Area of 3D Shapes

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/projection-area-of-3d-shapes/)  
`Array` `Math` `Geometry` `Matrix`

**Problem Link:** [LeetCode 883 - Projection Area of 3D Shapes](https://leetcode.com/problems/projection-area-of-3d-shapes/)

## Problem

You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).

We view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.

### Example 1

```text
Input: grid = [[1,2],[3,4]]
Output: 17
Explanation: Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
```

### Example 2

```text
Input: grid = [[2]]
Output: 5
```

### Example 3

```text
Input: grid = [[1,0],[0,2]]
Output: 8
```

## Constraints

- n == grid.length == grid[i].length
- 1 <= n <= 50
- 0 <= grid[i][j] <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 883. Projection Area of 3D Shapes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Mathematical | C++, Java, Python |

## Approach 1: Mathematical

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = 0;

        for (int i = 0; i < N;  ++i) {
            int bestRow = 0;  // largest of grid[i][j]
            int bestCol = 0;  // largest of grid[j][i]
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) ans++;  // top shadow
                bestRow = max(bestRow, grid[i][j]);
                bestCol = max(bestCol, grid[j][i]);
            }
            ans += bestRow + bestCol;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int projectionArea(int[][] grid) {
        int N = grid.length;
        int ans = 0;

        for (int i = 0; i < N;  ++i) {
            int bestRow = 0;  // largest of grid[i][j]
            int bestCol = 0;  // largest of grid[j][i]
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) ans++;  // top shadow
                bestRow = Math.max(bestRow, grid[i][j]);
                bestCol = Math.max(bestCol, grid[j][i]);
            }
            ans += bestRow + bestCol;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def projectionArea(self, grid):
        N = len(grid)
        ans = 0

        for i in xrange(N):
            best_row = 0  # max of grid[i][j]
            best_col = 0  # max of grid[j][i]
            for j in xrange(N):
                if grid[i][j]: ans += 1  # top shadow
                best_row = max(best_row, grid[i][j])
                best_col = max(best_col, grid[j][i])

            ans += best_row + best_col

        return ans

        """ Alternative solution:
        ans = sum(map(max, grid))
        ans += sum(map(max, zip(*grid)))
        ans += sum(v > 0 for row in grid for v in row)
        """
```

</details>
