# 1275. Find Winner on a Tic Tac Toe Game

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)  
`Array` `Hash Table` `Matrix` `Simulation`

**Problem Link:** [LeetCode 1275 - Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)

## Problem

Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

- Players take turns placing characters into empty squares ' '.
- The first player A always places 'X' characters, while the second player B always places 'O' characters.
- 'X' and 'O' characters are always placed into empty squares, never on filled ones.
- The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
- The game also ends if all squares are non-empty.
- No more moves can be played if the game is over.

Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

### Example 1

```text
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
```

### Example 2

```text
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
```

### Example 3

```text
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
```

## Constraints

- 1 <= moves.length <= 9
- moves[i].length == 2
- 0 <= rowi, coli <= 2
- There are no repeated elements on moves.
- moves follow the rules of tic tac toe.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Categorize Box According to Criteria](https://leetcode.com/problems/categorize-box-according-to-criteria/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1275. Find Winner on a Tic Tac Toe Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Record Each Move | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:

    // Initialize the board, n = 3 in this problem.
    int n = 3;
    vector<vector<int>> board;

public:
    string tictactoe(vector<vector<int>>& moves) {        
        board.assign(n, vector<int>(n, 0));
        int player = 1;

        // For each move
        for (vector<int> move : moves) {
            int row = move[0];
            int col = move[1];

            // Mark the current move with the current playrer's id.
            board[row][col] = player;

            // If any of the winning conditions is met, return the current player's id.
            if (checkRow(row, player) || checkCol(col, player) || 
                (row == col && checkDiagonal(player)) ||
                (row + col == n - 1 && checkAntiDiagonal(player))) {
                return player == 1 ? "A" : "B";
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }

        // If all moves are completed and there is still no result, we shall check if 
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == 3 * 3 ? "Draw" : "Pending";
    }
    
    // Check if any of 4 winning conditions to see if the current player has won.
    bool checkRow(int row, int player) {
        for (int col = 0; col < n; ++col) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
    
    bool checkCol(int col, int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
        
    bool checkDiagonal(int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][row] != player) return false;
        }
        return true;
    }
        
    bool checkAntiDiagonal(int player) {
        for (int row = 0; row < n; ++row) {
            if (board[row][n - 1 - row] != player) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Initialize the board, n = 3 in this problem.
    private int[][] board;
    private int n = 3;
    
    public String tictactoe(int[][] moves) {
        board = new int[n][n];
        int player = 1;
        
        // For each move
        for (int[] move : moves){
            int row = move[0], col = move[1];

            // Mark the current move with the current playrer's id.
            board[row][col] = player;

            // If any of the winning conditions is met, return the current player's id.
            if (checkRow(row, player) ||
                checkCol(col, player) ||
                (row == col && checkDiagonal(player)) ||
                (row + col == n - 1 && checkAntiDiagonal(player))){
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;       
        }

        // If all moves are completed and there is still no result, we shall check if 
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.length == n * n ? "Draw" : "Pending";   
    }

    // Check if any of 4 winning conditions to see if the current player has won.
    private boolean checkRow(int row, int player){
        for (int col = 0; col < n; ++col){
            if (board[row][col] != player) return false;
        }
        return true;
    }
    
    private boolean checkCol(int col, int player){
        for (int row = 0; row < n; ++row){
            if (board[row][col] != player) return false;
        }
        return true;
    }
    
    private boolean checkDiagonal(int player){
        for (int row = 0; row < n; ++row){
            if (board[row][row] != player) return false;
        }
        return true;
    }
    
    private boolean checkAntiDiagonal(int player){
        for (int row = 0; row < n; ++row){
            if (board[row][n - 1 - row] != player) return false;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:

        # Initialize the board, n = 3 in this problem.
        n = 3
        board = [[0] * n for _ in range(n)]
        
        # Check if any of 4 winning conditions to see if the current player has won.
        def checkRow(row, player_id):
            for col in range(n):
                if board[row][col] != player_id:
                    return False
            return True
        
        def checkCol(col, player_id):
            for row in range(n):
                if board[row][col] != player_id:
                    return False
            return True
        
        def checkDiagonal(player_id):
            for row in range(n):
                if board[row][row] != player_id:
                    return False
            return True
        
        def checkAntiDiagonal(player_id):
            for row in range(n):
                if board[row][n - 1 - row] != player_id:
                    return False
            return True
        
        # Start with player_1.
        player = 1

        for move in moves:
            row, col = move
            board[row][col] = player
            
            # If any of the winning conditions is met, return the current player's id.
            if checkRow(row, player) or checkCol(col, player) or \
            (row == col and checkDiagonal(player)) or \
            (row + col == n - 1 and checkAntiDiagonal(player)):
                return 'A' if player == 1 else 'B'
            
            # If no one wins so far, change to the other player alternatively. 
            # That is from 1 to -1, from -1 to 1.
            player *= -1
            
        # If all moves are completed and there is still no result, we shall check if
        # the grid is full or not. If so, the game ends with draw, otherwise pending.    
        return "Draw" if len(moves) == n * n else "Pending"
```

</details>

<br>

## Approach 2: Record Each Move

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        vector<int> rows(n), cols(n);
        int diag = 0;
        int anti_diag = 0;
        
        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;
        
        for (vector<int> move : moves) {

            // Get the row number and column number for this move.
            int row = move[0];
            int col = move[1];
            
            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;
            
            // If this move is placed on diagonal or anti-diagonal, 
            // we shall update the relative value as well.
            if (row == col) {
                diag += player;
            }
            if (row + col == n - 1) {
                anti_diag += player;
            }
            
            // Check if this move meets any of the winning conditions.
            if (abs(rows[row]) == n || abs(cols[col]) == n || 
                abs(diag) == n || abs(anti_diag) == n) {
                return player == 1 ? "A" : "B";
            }
            
            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }
            
        // If all moves are completed and there is still no result, we shall check if
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String tictactoe(int[][] moves) {

        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        int[] rows = new int[n], cols = new int[n];
        int diag = 0, anti_diag = 0;
        
        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;
        
        for (int[] move : moves){

            // Get the row number and column number for this move.
            int row = move[0], col = move[1];
            
            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;
            
            // If this move is placed on diagonal or anti-diagonal, 
            // we shall update the relative value as well.
            if (row == col){
                diag += player;
            }
            if (row + col == n - 1){
                anti_diag += player;
            }
            
            // Check if this move meets any of the winning conditions.
            if (Math.abs(rows[row]) == n || Math.abs(cols[col]) == n || 
                Math.abs(diag) == n || Math.abs(anti_diag) == n){
                return player == 1 ? "A" : "B";
            }
            
            // If no one wins so far, change to the other player alternatively. 
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }
        
        // If all moves are completed and there is still no result, we shall check if 
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.length == n * n ? "Draw" : "Pending";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:

        # n stands for the size of the board, n = 3 for the current game.
        n = 3

        # use rows and cols to record the value on each row and each column.
        # diag1 and diag2 to record value on diagonal or anti-diagonal.
        rows, cols = [0] * n, [0] * n
        diag = anti_diag = 0
        
        # Two players having value of 1 and -1, player_1 with value = 1 places first.
        player = 1
        
        for row, col in moves:
            
            # Update the row value and column value.
            rows[row] += player
            cols[col] += player
            
            # If this move is placed on diagonal or anti-diagonal, 
            # we shall update the relative value as well.
            if row == col:            
                diag += player
            if row + col == n - 1:
                anti_diag += player
                
            # check if this move meets any of the winning conditions.
            if any(abs(line) == n for line in (rows[row], cols[col], diag, anti_diag)):
                return "A" if player == 1 else "B"
        
            # If no one wins so far, change to the other player alternatively. 
            # That is from 1 to -1, from -1 to 1.
            player *= -1
            
        # If all moves are completed and there is still no result, we shall check if 
        # the grid is full or not. If so, the game ends with draw, otherwise pending.
        return "Draw" if len(moves) == n * n else "Pending"
```

</details>
