# 289. Game of Life

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/game-of-life/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 289 - Game of Life](https://leetcode.com/problems/game-of-life/)

## Problem

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

### Example 1

```text
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

### Example 2

```text
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

## Constraints

- m == board.length
- n == board[i].length
- 1 <= m, n <= 25
- board[i][j] is 0 or 1.

Follow up:

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 289. Game of Life

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| O(mn) Space Solution | Java, Python3 |
| O(1) Space Solution | Java, Python3 |

## Approach 1: O(mn) Space Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void gameOfLife(int[][] board) {

        // Neighbors array to find 8 neighboring cells for a given cell
        int[] neighbors = {0, 1, -1};

        int rows = board.length;
        int cols = board[0].length;

        // Create a copy of the original board
        int[][] copyBoard = new int[rows][cols];

        // Create a copy of the original board
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                copyBoard[row][col] = board[row][col];
            }
        }

        // Iterate through board cell by cell.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // For each cell count the number of live neighbors.
                int liveNeighbors = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // Check the validity of the neighboring cell.
                            // and whether it was originally a live cell.
                            // The evaluation is done against the copy, since that is never updated.
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // Rule 1 or Rule 3
                if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = 0;
                }
                // Rule 4
                if (copyBoard[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 1;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        # Neighbors array to find 8 neighboring cells for a given cell
        neighbors = [(1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1)]

        rows = len(board)
        cols = len(board[0])

        # Create a copy of the original board
        copy_board = [[board[row][col] for col in range(cols)] for row in range(rows)]

        # Iterate through board cell by cell.
        for row in range(rows):
            for col in range(cols):

                # For each cell count the number of live neighbors.
                live_neighbors = 0
                for neighbor in neighbors:

                    r = (row + neighbor[0])
                    c = (col + neighbor[1])

                    # Check the validity of the neighboring cell and if it was originally a live cell.
                    # The evaluation is done against the copy, since that is never updated.
                    if (r < rows and r >= 0) and (c < cols and c >= 0) and (copy_board[r][c] == 1):
                        live_neighbors += 1

                # Rule 1 or Rule 3        
                if copy_board[row][col] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[row][col] = 0
                # Rule 4
                if copy_board[row][col] == 0 and live_neighbors == 3:
                    board[row][col] = 1
```

</details>

<br>

## Approach 2: O(1) Space Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void gameOfLife(int[][] board) {

        // Neighbors array to find 8 neighboring cells for a given cell
        int[] neighbors = {0, 1, -1};

        int rows = board.length;
        int cols = board[0].length;

        // Iterate through board cell by cell.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // For each cell count the number of live neighbors.
                int liveNeighbors = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // Check the validity of the neighboring cell.
                            // and whether it was originally a live cell.
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (Math.abs(board[r][c]) == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // Rule 1 or Rule 3
                if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    // -1 signifies the cell is now dead but originally was live.
                    board[row][col] = -1;
                }
                // Rule 4
                if (board[row][col] == 0 && liveNeighbors == 3) {
                    // 2 signifies the cell is now live but was originally dead.
                    board[row][col] = 2;
                }
            }
        }

        // Get the final representation for the newly updated board.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # Neighbors array to find 8 neighboring cells for a given cell
        neighbors = [(1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1)]

        rows = len(board)
        cols = len(board[0])

        # Iterate through board cell by cell.
        for row in range(rows):
            for col in range(cols):

                # For each cell count the number of live neighbors.
                live_neighbors = 0
                for neighbor in neighbors:

                    # row and column of the neighboring cell
                    r = (row + neighbor[0])
                    c = (col + neighbor[1])

                    # Check the validity of the neighboring cell and if it was originally a live cell.
                    if (r < rows and r >= 0) and (c < cols and c >= 0) and abs(board[r][c]) == 1:
                        live_neighbors += 1

                # Rule 1 or Rule 3
                if board[row][col] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    # -1 signifies the cell is now dead but originally was live.
                    board[row][col] = -1
                # Rule 4
                if board[row][col] == 0 and live_neighbors == 3:
                    # 2 signifies the cell is now live but was originally dead.
                    board[row][col] = 2

        # Get the final representation for the newly updated board.
        for row in range(rows):
            for col in range(cols):
                if board[row][col] > 0:
                    board[row][col] = 1
                else:
                    board[row][col] = 0
```

</details>
