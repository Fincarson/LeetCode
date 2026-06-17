# 1631. Path With Minimum Effort

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/path-with-minimum-effort/)  
`Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Union-Find` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 1631 - Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)

## Problem

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

### Example 1

```text
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

### Example 2

```text
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

### Example 3

```text
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

## Constraints

- rows == heights.length
- columns == heights[i].length
- 1 <= rows, columns <= 100
- 1 <= heights[i][j] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1631. Path With Minimum Effort

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force using Backtracking | C++, Java, Python3 |

## Approach 1: Brute Force using Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        return backtrack(0, 0, heights, heights.size(), heights[0].size(), 0);
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxSoFar = INT_MAX;

    int backtrack(int x, int y, vector<vector<int>> &heights, int row, int col,
                  int maxDifference) {
        if (x == row - 1 && y == col - 1) {
            maxSoFar = min(maxSoFar, maxDifference);
            return maxDifference;
        }
        int currentHeight = heights[x][y];
        heights[x][y] = 0;
        int minEffort = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int adjacentX = x + directions[i][0];
            int adjacentY = y + directions[i][1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                heights[adjacentX][adjacentY] != 0) {
                int currentDifference =
                    abs(heights[adjacentX][adjacentY] - currentHeight);
                int maxCurrentDifference =
                    max(maxDifference, currentDifference);
                if (maxCurrentDifference < maxSoFar) {
                    int result = backtrack(adjacentX, adjacentY, heights, row,
                                           col, maxCurrentDifference);
                    minEffort = min(minEffort, result);
                }
            }
        }
        heights[x][y] = currentHeight;
        return minEffort;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumEffortPath(int[][] heights) {
        return backtrack(0, 0, heights, heights.length, heights[0].length, 0);
    }

    int directions[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxSoFar = Integer.MAX_VALUE;

    int backtrack(int x, int y, int[][] heights, int row, int col, int maxDifference) {
        if (x == row - 1 && y == col - 1) {
            maxSoFar = Math.min(maxSoFar, maxDifference);
            return maxDifference;
        }
        int currentHeight = heights[x][y];
        heights[x][y] = 0;
        int minEffort = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int adjacentX = x + directions[i][0];
            int adjacentY = y + directions[i][1];
            if (isValidCell(adjacentX, adjacentY, row, col) && heights[adjacentX][adjacentY] != 0) {
                int currentDifference = Math.abs(heights[adjacentX][adjacentY] - currentHeight);
                int maxCurrentDifference = Math.max(maxDifference, currentDifference);
                if (maxCurrentDifference < maxSoFar) {
                    int result = backtrack(adjacentX, adjacentY, heights, row, col, maxCurrentDifference);
                    minEffort = Math.min(minEffort, result);
                }
            }
        }
        heights[x][y] = currentHeight;
        return minEffort;
    }

    boolean isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row = len(heights)
        col = len(heights[0])
        self.max_so_far = math.inf

        def dfs(x, y, max_difference):
            if x == row-1 and y == col-1:
                self.max_so_far = min(self.max_so_far, max_difference)
                return max_difference
            current_height = heights[x][y]
            heights[x][y] = 0
            min_effort = math.inf
            for dx, dy in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                adjacent_x = x + dx
                adjacent_y = y + dy
                if 0 <= adjacent_x < row and 0 <= adjacent_y < col and heights[
                        adjacent_x][adjacent_y] != 0:
                    current_difference = abs(
                        heights[adjacent_x][adjacent_y]-current_height)
                    max_current_difference = max(
                        max_difference, current_difference)
                    if max_current_difference < self.max_so_far:
                        result = dfs(adjacent_x, adjacent_y,
                                     max_current_difference)
                        min_effort = min(min_effort, result)
            heights[x][y] = current_height
            return min_effort

        return dfs(0, 0, 0)
```

</details>
