# 994. Rotting Oranges

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/rotting-oranges/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 994 - Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

## Problem

You are given an m x n grid where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

### Example 1

```text
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

### Example 2

```text
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

### Example 3

```text
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- grid[i][j] is 0, 1, or 2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Walls and Gates](https://leetcode.com/problems/walls-and-gates/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Escape the Spreading Fire](https://leetcode.com/problems/escape-the-spreading-fire/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 994. Rotting Oranges

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | Java, Python3 |
| In-place BFS | Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Pair<Integer, Integer>> queue = new ArrayDeque();

        // Step 1). build the initial set of rotten oranges
        int freshOranges = 0;
        int ROWS = grid.length, COLS = grid[0].length;

        for (int r = 0; r < ROWS; ++r)
            for (int c = 0; c < COLS; ++c)
                if (grid[r][c] == 2)
                    queue.offer(new Pair(r, c));
                else if (grid[r][c] == 1)
                    freshOranges++;

        // Mark the round / level, _i.e_ the ticker of timestamp
        queue.offer(new Pair(-1, -1));

        // Step 2). start the rotting process via BFS
        int minutesElapsed = -1;
        int[][] directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!queue.isEmpty()) {
            Pair<Integer, Integer> p = queue.poll();
            int row = p.getKey();
            int col = p.getValue();
            if (row == -1) {
                // We finish one round of processing
                minutesElapsed++;
                // to avoid the endless loop
                if (!queue.isEmpty())
                    queue.offer(new Pair(-1, -1));
            } else {
                // this is a rotten orange
                // then it would contaminate its neighbors
                for (int[] d : directions) {
                    int neighborRow = row + d[0];
                    int neighborCol = col + d[1];
                    if (neighborRow >= 0 && neighborRow < ROWS && 
                        neighborCol >= 0 && neighborCol < COLS) {
                        if (grid[neighborRow][neighborCol] == 1) {
                            // this orange would be contaminated
                            grid[neighborRow][neighborCol] = 2;
                            freshOranges--;
                            // this orange would then contaminate other oranges
                            queue.offer(new Pair(neighborRow, neighborCol));
                        }
                    }
                }
            }
        }

        // return elapsed minutes if no fresh orange left
        return freshOranges == 0 ? minutesElapsed : -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()

        # Step 1). build the initial set of rotten oranges
        fresh_oranges = 0
        ROWS, COLS = len(grid), len(grid[0])
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh_oranges += 1

        # Mark the round / level, _i.e_ the ticker of timestamp
        queue.append((-1, -1))

        # Step 2). start the rotting process via BFS
        minutes_elapsed = -1
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        while queue:
            row, col = queue.popleft()
            if row == -1:
                # We finish one round of processing
                minutes_elapsed += 1
                if queue:  # to avoid the endless loop
                    queue.append((-1, -1))
            else:
                # this is a rotten orange
                # then it would contaminate its neighbors
                for d in directions:
                    neighbor_row, neighbor_col = row + d[0], col + d[1]
                    if ROWS > neighbor_row >= 0 and COLS > neighbor_col >= 0:
                        if grid[neighbor_row][neighbor_col] == 1:
                            # this orange would be contaminated
                            grid[neighbor_row][neighbor_col] = 2
                            fresh_oranges -= 1
                            # this orange would then contaminate other oranges
                            queue.append((neighbor_row, neighbor_col))

        # return elapsed minutes if no fresh orange left
        return minutes_elapsed if fresh_oranges == 0 else -1
```

</details>

<br>

## Approach 2: In-place BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // run the rotting process, by marking the rotten oranges with the timestamp
    public boolean runRottingProcess(int timestamp, int[][] grid, int ROWS, int COLS) {
        int[][] directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        // flag to indicate if the rotting process should be continued
        boolean toBeContinued = false;
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                if (grid[row][col] == timestamp)
                    // current contaminated cell
                    for (int[] d : directions) {
                        int nRow = row + d[0], nCol = col + d[1];
                        if (nRow >= 0 && nRow < ROWS && nCol >= 0 && nCol < COLS)
                            if (grid[nRow][nCol] == 1) {
                                // this fresh orange would be contaminated next
                                grid[nRow][nCol] = timestamp + 1;
                                toBeContinued = true;
                            }
                    }
        return toBeContinued;
    }

    public int orangesRotting(int[][] grid) {
        int ROWS = grid.length, COLS = grid[0].length;
        int timestamp = 2;
        while (runRottingProcess(timestamp, grid, ROWS, COLS))
            timestamp++;

        // end of process, to check if there are still fresh oranges left
        for (int[] row : grid)
            for (int cell : row)
                // still got a fresh orange left
                if (cell == 1)
                    return -1;


        // return elapsed minutes if no fresh orange left
        return timestamp - 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        # run the rotting process, by marking the rotten oranges with the timestamp
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        def runRottingProcess(timestamp):
            # flag to indicate if the rotting process should be continued
            to_be_continued = False
            for row in range(ROWS):
                for col in range(COLS):
                    if grid[row][col] == timestamp:
                        # current contaminated cell
                        for d in directions:
                            n_row, n_col = row + d[0], col + d[1]
                            if ROWS > n_row >= 0 and COLS > n_col >= 0:
                                if grid[n_row][n_col] == 1:
                                    # this fresh orange would be contaminated next
                                    grid[n_row][n_col] = timestamp + 1
                                    to_be_continued = True
            return to_be_continued

        timestamp = 2
        while runRottingProcess(timestamp):
            timestamp += 1
        # end of process, to check if there are still fresh oranges left
        for row in grid:
            for cell in row:
                if cell == 1:  # still got a fresh orange left
                    return -1
        # return elapsed minutes if no fresh orange left
        return timestamp - 2
```

</details>
