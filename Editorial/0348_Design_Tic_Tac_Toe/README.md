# 348. Design Tic-Tac-Toe

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/design-tic-tac-toe/)  
`Array` `Hash Table` `Design` `Matrix` `Simulation`

**Problem Link:** [LeetCode 348 - Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/)

## Problem

Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

Implement the TicTacToe class:

- TicTacToe(int n) Initializes the object the size of the board n.
- int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. The move is guaranteed to be a valid move, and the two players alternate in making moves. Return

		0 if there is no winner after the move,
		1 if player 1 is the winner after the move, or
		2 if player 2 is the winner after the move.

### Example 1

```text
Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
```

## Constraints

- 2 <= n <= 100
- player is 1 or 2.
- 0 <= row, col < n
- (row, col) are unique for each different call to move.
- At most n2 calls will be made to move.

Follow-up: Could you do better than O(n2) per move() operation?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Tic-Tac-Toe State](https://leetcode.com/problems/valid-tic-tac-toe-state/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 348. Design Tic-Tac-Toe

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Optimized Brute Force | C++, Java |
| Optimised Approach | C++, Java |

## Approach 1: Optimized Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class TicTacToe {
public:
    vector<vector<int>> board;
    int n;

    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0));
        this->n = n;
    }

    int move(int row, int col, int player) {
        board[row][col] = player;
        if (checkCol(col, player) ||
            checkRow(row, player) ||
            (row == col && checkDiagonal(player)) ||
            (row == n - col - 1 && checkAntiDiagonal(player))) {
            return player;
        }
        // No one wins
        return 0;
    }

    bool checkDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][row] != player) return false;
        }
        return true;
    }

    bool checkAntiDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][n - row - 1] != player) return false;
        }
        return true;
    }

    bool checkCol(int col, int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][col] != player) return false;
        }
        return true;
    }

    bool checkRow(int row, int player) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TicTacToe {

    private int[][] board;
    private int n;

    public TicTacToe(int n) {
        board = new int[n][n];
        this.n = n;
    }

    public int move(int row, int col, int player) {
        board[row][col] = player;
        // check if the player wins
        if ((checkRow(row, player)) ||
            (checkColumn(col, player)) ||
            (row == col && checkDiagonal(player)) ||
            (col == n - row - 1 && checkAntiDiagonal(player))) {
            return player;
        }
        // No one wins
        return 0;
    }

    private boolean checkDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][row] != player) {
                return false;
            }
        }
        return true;
    }

    private boolean checkAntiDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][n - row - 1] != player) {
                return false;
            }
        }
        return true;
    }

    private boolean checkColumn(int col, int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][col] != player) {
                return false;
            }
        }
        return true;
    }

    private boolean checkRow(int row, int player) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] != player) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<br>

## Approach 2: Optimised Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;

    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }

    int move(int row, int col, int player) {
        int currentPlayer = (player == 1) ? 1 : -1;
        // update currentPlayer in rows and cols arrays
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        // update diagonal
        if (row == col) {
            diagonal += currentPlayer;
        }
        // update anti diagonal
        if (col == (cols.size() - row - 1)) {
            antiDiagonal += currentPlayer;
        }
        int n = rows.size();
        // check if the current player wins
        if (abs(rows[row]) == n ||
            abs(cols[col]) == n ||
            abs(diagonal) == n ||
            abs(antiDiagonal) == n) {
            return player;
        }
        // No one wins
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class TicTacToe {
    int[] rows;
    int[] cols;
    int diagonal;
    int antiDiagonal;

    public TicTacToe(int n) {
        rows = new int[n];
        cols = new int[n];
    }

    public int move(int row, int col, int player) {
        int currentPlayer = (player == 1) ? 1 : -1;
        // update currentPlayer in rows and cols arrays
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        // update diagonal
        if (row == col) {
            diagonal += currentPlayer;
        }
        //update anti diagonal
        if (col == (cols.length - row - 1)) {
            antiDiagonal += currentPlayer;
        }
        int n = rows.length;
        // check if the current player wins
        if (Math.abs(rows[row]) == n ||
                Math.abs(cols[col]) == n ||
                Math.abs(diagonal) == n ||
                Math.abs(antiDiagonal) == n) {
            return player;
        }
        // No one wins
        return 0;
    }
}
```

</details>
