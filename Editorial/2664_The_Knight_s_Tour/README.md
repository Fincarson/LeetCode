# 2664. The Knight’s Tour

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/the-knights-tour/)  
`Array` `Backtracking` `Matrix`

**Problem Link:** [LeetCode 2664 - The Knight’s Tour](https://leetcode.com/problems/the-knights-tour/)

## Problem

Given two positive integers m and n which are the height and width of a 0-indexed 2D-array board, a pair of positive integers (r, c) which is the starting position of the knight on the board.

Your task is to find an order of movements for the knight, in a manner that every cell of the board gets visited exactly once (the starting cell is considered visited and you shouldn't visit it again).

Return the array board in which the cells' values show the order of visiting the cell starting from 0 (the initial place of the knight).

Note that a knight can move from cell (r1, c1) to cell (r2, c2) if 0 <= r2 <= m - 1 and 0 <= c2 <= n - 1 and min(abs(r1 - r2), abs(c1 - c2)) = 1 and max(abs(r1 - r2), abs(c1 - c2)) = 2.

### Example 1

```text
Input: m = 1, n = 1, r = 0, c = 0
Output: [[0]]
Explanation: There is only 1 cell and the knight is initially on it so there is only a 0 inside the 1x1 grid.
```

### Example 2

```text
Input: m = 3, n = 4, r = 0, c = 0
Output: [[0,3,6,9],[11,8,1,4],[2,5,10,7]]
Explanation: By the following order of movements we can visit the entire board.
(0,0)->(1,2)->(2,0)->(0,1)->(1,3)->(2,1)->(0,2)->(2,3)->(1,1)->(0,3)->(2,2)->(1,0)
```

## Constraints

- 1 <= m, n <= 5
- 0 <= r <= m - 1
- 0 <= c <= n - 1
- The inputs will be generated such that there exists at least one possible order of movements with the given condition

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2664. The Knight’s Tour

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Warnsdorff’s Rule | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> chessboard(m, vector<int>(n, 0));

        chessboard[r][c] = -1;

        // Start the recursive solving process
        solveKnightsTour(m, n, r, c, chessboard, 1);

        chessboard[r][c] = 0;

        return chessboard;
    }

private:
    bool solveKnightsTour(int rows, int cols, int currentRow, int currentCol,
                          vector<vector<int>>& chessboard, int moveCount) {
        // Base case: if all cells have been visited, we've found a solution
        if (moveCount == rows * cols) {
            return true;
        }

        // Try all possible knight moves
        for (int newRow = 0; newRow < rows; newRow++) {
            for (int newCol = 0; newCol < cols; newCol++) {
                // Check if the move is valid
                if (!isValidMove(chessboard, currentRow, currentCol, newRow,
                                 newCol)) {
                    continue;
                }

                chessboard[newRow][newCol] = moveCount;

                // Recursively try to solve from this new position
                if (solveKnightsTour(rows, cols, newRow, newCol, chessboard,
                                     moveCount + 1)) {
                    return true;
                }

                // If the move doesn't lead to a solution, backtrack
                chessboard[newRow][newCol] = 0;
            }
        }

        // If no solution is found from the current position
        return false;
    }

    bool isValidMove(const vector<vector<int>>& chessboard, int fromRow,
                     int fromCol, int toRow, int toCol) {
        return toRow >= 0 && toCol >= 0 && toRow < chessboard.size() &&
               toCol < chessboard[0].size() &&
               min(abs(fromRow - toRow), abs(fromCol - toCol)) == 1 &&
               max(abs(fromRow - toRow), abs(fromCol - toCol)) == 2 &&
               chessboard[toRow][toCol] == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] tourOfKnight(int m, int n, int r, int c) {
        int[][] chessboard = new int[m][n];

        chessboard[r][c] = -1;

        // Start the recursive solving process
        solveKnightsTour(m, n, r, c, chessboard, 1);

        chessboard[r][c] = 0;

        return chessboard;
    }

    private boolean solveKnightsTour(
        int rows,
        int cols,
        int currentRow,
        int currentCol,
        int[][] chessboard,
        int moveCount
    ) {
        // Base case: if all cells have been visited, we've found a solution
        if (moveCount == rows * cols) {
            return true;
        }

        // Try all possible knight moves
        for (int newRow = 0; newRow < rows; newRow++) {
            for (int newCol = 0; newCol < cols; newCol++) {
                // Check if the move is valid
                if (
                    !isValidMove(
                        chessboard,
                        currentRow,
                        currentCol,
                        newRow,
                        newCol
                    )
                ) {
                    continue;
                }

                chessboard[newRow][newCol] = moveCount;

                // Recursively try to solve from this new position
                if (
                    solveKnightsTour(
                        rows,
                        cols,
                        newRow,
                        newCol,
                        chessboard,
                        moveCount + 1
                    )
                ) {
                    return true;
                }

                // If the move doesn't lead to a solution, backtrack
                chessboard[newRow][newCol] = 0;
            }
        }

        // If no solution is found from the current position
        return false;
    }

    private boolean isValidMove(
        int[][] chessboard,
        int fromRow,
        int fromCol,
        int toRow,
        int toCol
    ) {
        return (
            toRow >= 0 &&
            toCol >= 0 &&
            toRow < chessboard.length &&
            toCol < chessboard[0].length &&
            Math.min(Math.abs(fromRow - toRow), Math.abs(fromCol - toCol)) ==
            1 &&
            Math.max(Math.abs(fromRow - toRow), Math.abs(fromCol - toCol)) ==
            2 &&
            chessboard[toRow][toCol] == 0
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tourOfKnight(self, m, n, r, c):
        # Precompute possible knight moves
        moves = [
            (2, 1),
            (2, -1),
            (-2, 1),
            (-2, -1),
            (1, 2),
            (1, -2),
            (-1, 2),
            (-1, -2),
        ]

        def _is_valid_move(to_row, to_col):
            return (
                0 <= to_row < m
                and 0 <= to_col < n
                and chessboard[to_row][to_col] == 0
            )

        def _solve_knights_tour(current_row, current_col, move_count):
            # Base case: if all cells have been visited, we've found a solution
            if move_count == m * n:
                return True

            # Try all possible knight moves
            for move_r, move_c in moves:
                new_row, new_col = current_row + move_r, current_col + move_c
                # Check if the move is valid
                if _is_valid_move(new_row, new_col):
                    chessboard[new_row][new_col] = move_count

                    # Recursively try to solve from this new position
                    if _solve_knights_tour(new_row, new_col, move_count + 1):
                        return True

                    # If the move doesn't lead to a solution, backtrack
                    chessboard[new_row][new_col] = 0

            # If no solution is found from the current position
            return False

        chessboard = [[0] * n for _ in range(m)]

        chessboard[r][c] = -1

        # Start the recursive solving process
        _solve_knights_tour(r, c, 1)

        chessboard[r][c] = 0

        return chessboard
```

</details>

<br>

## Approach 2: Warnsdorff’s Rule

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> chessboard(m, vector<int>(n, 0));
        chessboard[r][c] = -1;

        solveKnightsTour(m, n, r, c, chessboard, 1);

        // Reset starting position to 0
        chessboard[r][c] = 0;
        return chessboard;
    }

private:
    // Possible knight moves: (row, column) pairs
    int knightMoves[8][2] = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1},
                             {1, -2},  {2, -1},  {1, 2},  {2, 1}};

    bool solveKnightsTour(int rows, int cols, int currentRow, int currentCol,
                          vector<vector<int>>& chessboard, int moveCount) {
        // Base case: if all cells are visited, we've found a solution
        if (moveCount == rows * cols) return true;

        // Get and sort possible next moves based on Warnsdorff's rule
        vector<pair<int, int>> nextMoves =
            getNextMovesWarnsdorff(chessboard, currentRow, currentCol);

        // Try each possible move
        for (auto& move : nextMoves) {
            int nextRow = currentRow + knightMoves[move.second][0];
            int nextCol = currentCol + knightMoves[move.second][1];

            if (!isValidMove(chessboard, nextRow, nextCol)) continue;

            chessboard[nextRow][nextCol] = moveCount;

            // Recursively try to solve from this new position
            if (solveKnightsTour(rows, cols, nextRow, nextCol, chessboard,
                                 moveCount + 1)) {
                return true;
            }

            // If the move doesn't lead to a solution, backtrack
            chessboard[nextRow][nextCol] = 0;
        }

        return false;  // No solution found from this position
    }

    // Implement Warnsdorff's rule: prefer moves with fewer onward moves
    vector<pair<int, int>> getNextMovesWarnsdorff(
        vector<vector<int>>& chessboard, int row, int col) {
        vector<pair<int, int>> nextMoves;
        for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
            int nextRow = row + knightMoves[moveIndex][0];
            int nextCol = col + knightMoves[moveIndex][1];
            int accessibilityScore =
                countAccessibleMoves(chessboard, nextRow, nextCol);
            nextMoves.push_back({accessibilityScore, moveIndex});
        }
        // Sort moves based on accessibility (fewer accessible squares first)
        sort(nextMoves.begin(), nextMoves.end());
        return nextMoves;
    }

    int countAccessibleMoves(vector<vector<int>>& chessboard, int row,
                             int col) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int nextRow = row + knightMoves[i][0];
            int nextCol = col + knightMoves[i][1];
            if (isValidMove(chessboard, nextRow, nextCol)) count++;
        }
        return count;
    }

    bool isValidMove(vector<vector<int>>& chessboard, int row, int col) {
        return row >= 0 && col >= 0 && row < chessboard.size() &&
               col < chessboard[0].size() && chessboard[row][col] == 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Possible knight moves: (row, column) pairs
    int[][] knightMoves = {
        { -1, -2 },
        { -2, -1 },
        { -1, 2 },
        { -2, 1 },
        { 1, -2 },
        { 2, -1 },
        { 1, 2 },
        { 2, 1 },
    };

    public int[][] tourOfKnight(int m, int n, int r, int c) {
        int[][] chessboard = new int[m][n];
        chessboard[r][c] = -1;

        solveKnightsTour(m, n, r, c, chessboard, 1);

        // Reset starting position to 0
        chessboard[r][c] = 0;
        return chessboard;
    }

    private boolean solveKnightsTour(
        int rows,
        int cols,
        int currentRow,
        int currentCol,
        int[][] chessboard,
        int moveCount
    ) {
        // Base case: if all cells are visited, we've found a solution
        if (moveCount == rows * cols) return true;

        // Get and sort possible next moves based on Warnsdorff's rule
        List<int[]> nextMoves = getNextMovesWarnsdorff(
            chessboard,
            currentRow,
            currentCol
        );

        // Try each possible move
        for (int[] move : nextMoves) {
            int nextRow = currentRow + knightMoves[move[1]][0];
            int nextCol = currentCol + knightMoves[move[1]][1];

            if (!isValidMove(chessboard, nextRow, nextCol)) continue;

            chessboard[nextRow][nextCol] = moveCount;

            // Recursively try to solve from this new position
            if (
                solveKnightsTour(
                    rows,
                    cols,
                    nextRow,
                    nextCol,
                    chessboard,
                    moveCount + 1
                )
            ) {
                return true;
            }

            // If the move doesn't lead to a solution, backtrack
            chessboard[nextRow][nextCol] = 0;
        }

        return false; // No solution found from this position
    }

    // Implement Warnsdorff's rule: prefer moves with fewer onward moves
    private List<int[]> getNextMovesWarnsdorff(
        int[][] chessboard,
        int row,
        int col
    ) {
        List<int[]> nextMoves = new ArrayList<>();
        for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
            int nextRow = row + knightMoves[moveIndex][0];
            int nextCol = col + knightMoves[moveIndex][1];
            int accessibilityScore = countAccessibleMoves(
                chessboard,
                nextRow,
                nextCol
            );
            nextMoves.add(new int[] { accessibilityScore, moveIndex });
        }
        // Sort moves based on accessibility (fewer accessible squares first)
        Collections.sort(nextMoves, (a, b) -> a[0] - b[0]);
        return nextMoves;
    }

    private int countAccessibleMoves(int[][] chessboard, int row, int col) {
        int count = 0;
        for (int[] move : knightMoves) {
            int nextRow = row + move[0];
            int nextCol = col + move[1];
            if (isValidMove(chessboard, nextRow, nextCol)) count++;
        }
        return count;
    }

    private boolean isValidMove(int[][] chessboard, int row, int col) {
        return (
            row >= 0 &&
            col >= 0 &&
            row < chessboard.length &&
            col < chessboard[0].length &&
            chessboard[row][col] == 0
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tourOfKnight(self, m, n, r, c):
        # Possible knight moves: (row, column) pairs
        knight_moves = [
            (-1, -2),
            (-2, -1),
            (-1, 2),
            (-2, 1),
            (1, -2),
            (2, -1),
            (1, 2),
            (2, 1),
        ]
        chessboard = [[0] * n for _ in range(m)]

        chessboard[r][c] = -1

        def _solve_knights_tour(current_row, current_col, move_count):
            # Base case: if all cells have been visited, we've found a solution
            if move_count == m * n:
                return True

            # Get and sort possible next moves based on Warnsdorff's rule
            next_moves = _get_next_moves_warnsdorff(current_row, current_col)

            # Try each possible move
            for _, move_index in next_moves:
                next_row, next_col = (
                    current_row + knight_moves[move_index][0],
                    current_col + knight_moves[move_index][1],
                )

                # Check if the move is valid
                if not _is_valid_move(next_row, next_col):
                    continue

                # Mark the move as visited
                chessboard[next_row][next_col] = move_count

                # Recursively try to solve from this new position
                if _solve_knights_tour(next_row, next_col, move_count + 1):
                    return True

                # If the move doesn't lead to a solution, backtrack
                chessboard[next_row][next_col] = 0

            return False  # No solution found from this position

        # Implement Warnsdorff's rule: prefer moves with fewer onward moves
        def _get_next_moves_warnsdorff(row, col):
            next_moves = []
            for idx in range(8):
                next_row, next_col = (
                    row + knight_moves[idx][0],
                    col + knight_moves[idx][1],
                )
                accessibility_score = sum(
                    _is_valid_move(next_row + move[0], next_col + move[1])
                    for move in knight_moves
                )
                next_moves.append((accessibility_score, idx))

            # Sort moves based on accessibility (fewer accessible squares first)
            return sorted(next_moves)

        # Check if the move is valid
        def _is_valid_move(row, col):
            return 0 <= row < m and 0 <= col < n and chessboard[row][col] == 0

        _solve_knights_tour(r, c, 1)

        # Reset the starting position to 0
        chessboard[r][c] = 0

        return chessboard
```

</details>
