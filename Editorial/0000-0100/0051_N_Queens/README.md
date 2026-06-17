# 51. N-Queens

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/n-queens/)  
`Array` `Backtracking`

**Problem Link:** [LeetCode 51 - N-Queens](https://leetcode.com/problems/n-queens/)

## Problem

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

### Example 1

```text
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```

### Example 2

```text
Input: n = 1
Output: [["Q"]]
```

## Constraints

- 1 <= n <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [N-Queens II](https://leetcode.com/problems/n-queens-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Grid Illumination](https://leetcode.com/problems/grid-illumination/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 51. N-Queens

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* diagonal;
int* antiDiagonal;
int* cols;
char*** result;
char** board;
int size;
void backtrack(int n, int row) {
    if (row == n) {
        char** current = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; ++i) {
            char* currRow = (char*)calloc(n + 1, sizeof(char));
            memcpy(currRow, board[i], n);
            currRow[n] = '\0';
            current[i] = currRow;
        }
        result[size++] = current;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (cols[i] || diagonal[i - row + n - 1] || antiDiagonal[i + row])
            continue;
        cols[i] = diagonal[i - row + n - 1] = antiDiagonal[i + row] = 1;
        board[row][i] = 'Q';
        backtrack(n, row + 1);
        board[row][i] = '.';
        cols[i] = diagonal[i - row + n - 1] = antiDiagonal[i + row] = 0;
    }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    size = 0;
    if (n < 1) {
        *returnSize = 0;
        return 0;
    }
    result = (char***)malloc(n * n * n * sizeof(char**));
    diagonal = (int*)calloc(2 * n - 1, sizeof(int));
    antiDiagonal = (int*)calloc(2 * n - 1, sizeof(int));
    cols = (int*)calloc(n, sizeof(int));
    board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i) {
        board[i] = (char*)calloc(n + 1, sizeof(char));
        memset(board[i], '.', n);
    }
    backtrack(n, 0);
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int size;
    vector<vector<string>> solutions;
    // Making use of a helper function to get the
    // solutions in the correct output format
    vector<string> createBoard(vector<vector<char>> state) {
        vector<string> board;
        for (int row = 0; row < size; ++row) {
            string current_row(state[row].begin(), state[row].end());
            board.push_back(current_row);
        }
        return board;
    }
    void backtrack(int row, unordered_set<int> diagonals,
                   unordered_set<int> antiDiagonals, unordered_set<int> cols,
                   vector<vector<char>> state) {
        // Base case - N queens have been placed
        if (row == size) {
            solutions.push_back(createBoard(state));
            return;
        }
        for (int col = 0; col < size; ++col) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.count(col) || diagonals.count(currDiagonal) ||
                antiDiagonals.count(currAntiDiagonal)) {
                continue;
            }
            // "Add" the queen to the board
            cols.insert(col);
            diagonals.insert(currDiagonal);
            antiDiagonals.insert(currAntiDiagonal);
            state[row][col] = 'Q';
            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(col);
            diagonals.erase(currDiagonal);
            antiDiagonals.erase(currAntiDiagonal);
            state[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<vector<char>> emptyBoard(size, vector<char>(size, '.'));
        backtrack(0, unordered_set<int>(), unordered_set<int>(),
                  unordered_set<int>(), emptyBoard);
        return solutions;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int size;
    private List<IList<string>> solutions = new List<IList<string>>();

    public IList<IList<string>> SolveNQueens(int n) {
        size = n;
        char[][] emptyBoard = new char [size][];
        for (int i = 0; i < n; i++) {
            emptyBoard[i] = new char[size];
            for (int j = 0; j < n; j++) {
                emptyBoard[i][j] = '.';
            }
        }

        Backtrack(0, new HashSet<int>(), new HashSet<int>(), new HashSet<int>(),
                  emptyBoard);
        return solutions;
    }

    // Making use of a helper function to get the
    // solutions in the correct output format
    private List<string> CreateBoard(char[][] state) {
        List<string> board = new List<string>();
        for (int row = 0; row < size; row++) {
            string current_row = new string(state[row]);
            board.Add(current_row);
        }

        return board;
    }

    private void Backtrack(int row, HashSet<int> diagonals,
                           HashSet<int> antiDiagonals, HashSet<int> cols,
                           char[][] state) {
        // Base case - N queens have been placed
        if (row == size) {
            solutions.Add(CreateBoard(state));
            return;
        }

        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.Contains(col) || diagonals.Contains(currDiagonal) ||
                antiDiagonals.Contains(currAntiDiagonal)) {
                continue;
            }

            // "Add" the queen to the board
            cols.Add(col);
            diagonals.Add(currDiagonal);
            antiDiagonals.Add(currAntiDiagonal);
            state[row][col] = 'Q';
            // Move on to the next row with the updated board state
            Backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.Remove(col);
            diagonals.Remove(currDiagonal);
            antiDiagonals.Remove(currAntiDiagonal);
            state[row][col] = '.';
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func solveNQueens(n int) [][]string {
    solutions := make([][]string, 0)
    emptyBoard := make([][]rune, n)
    for i := range emptyBoard {
        emptyBoard[i] = make([]rune, n)
        for j := range emptyBoard[i] {
            emptyBoard[i][j] = '.'
        }
    }
    hasElement := func(set map[int]bool, value int) bool {
        _, ok := set[value]
        return ok
    }
    addElement := func(set map[int]bool, value int) {
        set[value] = true
    }
    removeElement := func(set map[int]bool, value int) {
        delete(set, value)
    }
    // Making use of a helper function to get the
    // solutions in the correct output format
    createBoard := func(state [][]rune) []string {
        board := make([]string, len(state))
        for row := range state {
            board[row] = string(state[row])
        }
        return board
    }
    var backtrack func(row int, diagonals, antiDiagonals, cols map[int]bool, state [][]rune)
    backtrack = func(row int, diagonals, antiDiagonals, cols map[int]bool, state [][]rune) {
        // Base case - N queens have been placed
        if row == n {
            solutions = append(solutions, createBoard(state))
            return
        }
        for col := 0; col < n; col++ {
            currDiagonal := row - col
            currAntiDiagonal := row + col
            // If the queen is not placeable
            if hasElement(cols, col) || hasElement(diagonals, currDiagonal) ||
                hasElement(antiDiagonals, currAntiDiagonal) {
                continue
            }
            // "Add" the queen to the board
            addElement(cols, col)
            addElement(diagonals, currDiagonal)
            addElement(antiDiagonals, currAntiDiagonal)
            state[row][col] = 'Q'
            // Move on to the next row with the updated board state
            backtrack(row+1, diagonals, antiDiagonals, cols, state)
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            removeElement(cols, col)
            removeElement(diagonals, currDiagonal)
            removeElement(antiDiagonals, currAntiDiagonal)
            state[row][col] = '.'
        }
    }
    backtrack(
        0,
        make(map[int]bool),
        make(map[int]bool),
        make(map[int]bool),
        emptyBoard,
    )
    return solutions
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int size;
    private List<List<String>> solutions = new ArrayList<List<String>>();

    public List<List<String>> solveNQueens(int n) {
        size = n;
        char emptyBoard[][] = new char[size][size];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                emptyBoard[i][j] = '.';
            }
        }

        backtrack(
            0,
            new HashSet<>(),
            new HashSet<>(),
            new HashSet<>(),
            emptyBoard
        );
        return solutions;
    }

    // Making use of a helper function to get the
    // solutions in the correct output format
    private List<String> createBoard(char[][] state) {
        List<String> board = new ArrayList<String>();
        for (int row = 0; row < size; row++) {
            String current_row = new String(state[row]);
            board.add(current_row);
        }

        return board;
    }

    private void backtrack(
        int row,
        Set<Integer> diagonals,
        Set<Integer> antiDiagonals,
        Set<Integer> cols,
        char[][] state
    ) {
        // Base case - N queens have been placed
        if (row == size) {
            solutions.add(createBoard(state));
            return;
        }

        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.contains(col) ||
                diagonals.contains(currDiagonal) ||
                antiDiagonals.contains(currAntiDiagonal)
            ) {
                continue;
            }

            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            state[row][col] = 'Q';

            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);

            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.remove(col);
            diagonals.remove(currDiagonal);
            antiDiagonals.remove(currAntiDiagonal);
            state[row][col] = '.';
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var solveNQueens = function (n) {
    const solutions = [];
    const emptyBoard = Array.from({ length: n }, () => Array(n).fill("."));
    // Making use of a helper function to get the
    // solutions in the correct output format
    const createBoard = (state) => {
        const board = [];
        for (let row = 0; row < n; row++) {
            board.push(state[row].join(""));
        }
        return board;
    };
    const backtrack = (row, diagonals, antiDiagonals, cols, state) => {
        // Base case - N queens have been placed
        if (row === n) {
            solutions.push(createBoard(state));
            return;
        }
        for (let col = 0; col < n; col++) {
            const currDiagonal = row - col;
            const currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(currDiagonal) ||
                antiDiagonals.has(currAntiDiagonal)
            ) {
                continue;
            }
            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            state[row][col] = "Q";
            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.delete(col);
            diagonals.delete(currDiagonal);
            antiDiagonals.delete(currAntiDiagonal);
            state[row][col] = ".";
        }
    };
    backtrack(0, new Set(), new Set(), new Set(), emptyBoard);
    return solutions;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def solveNQueens(self, n):
        # Making use of a helper function to get the
        # solutions in the correct output format
        def create_board(state):
            board = []
            for row in state:
                board.append("".join(row))
            return board

        def backtrack(row, diagonals, anti_diagonals, cols, state):
            # Base case - N queens have been placed
            if row == n:
                ans.append(create_board(state))
                return

            for col in range(n):
                curr_diagonal = row - col
                curr_anti_diagonal = row + col
                # If the queen is not placeable
                if (
                    col in cols
                    or curr_diagonal in diagonals
                    or curr_anti_diagonal in anti_diagonals
                ):
                    continue

                # "Add" the queen to the board
                cols.add(col)
                diagonals.add(curr_diagonal)
                anti_diagonals.add(curr_anti_diagonal)
                state[row][col] = "Q"

                # Move on to the next row with the updated board state
                backtrack(row + 1, diagonals, anti_diagonals, cols, state)

                # "Remove" the queen from the board since we have already
                # explored all valid paths using the above function call
                cols.remove(col)
                diagonals.remove(curr_diagonal)
                anti_diagonals.remove(curr_anti_diagonal)
                state[row][col] = "."

        ans = []
        empty_board = [["."] * n for _ in range(n)]
        backtrack(0, set(), set(), set(), empty_board)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solveNQueens(n: number): string[][] {
    const solutions: string[][] = [];
    const emptyBoard: string[][] = Array.from({ length: n }, () =>
        Array(n).fill("."),
    );
    // Making use of a helper function to get the
    // solutions in the correct output format
    const createBoard = (state: string[][]): string[] => {
        const board: string[] = [];
        for (let row = 0; row < n; row++) {
            board.push(state[row].join(""));
        }
        return board;
    };
    const backtrack = (
        row: number,
        diagonals: Set<number>,
        antiDiagonals: Set<number>,
        cols: Set<number>,
        state: string[][],
    ) => {
        // Base case - N queens have been placed
        if (row === n) {
            solutions.push(createBoard(state));
            return;
        }
        for (let col = 0; col < n; col++) {
            const currDiagonal: number = row - col;
            const currAntiDiagonal: number = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(currDiagonal) ||
                antiDiagonals.has(currAntiDiagonal)
            ) {
                continue;
            }
            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            state[row][col] = "Q";
            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.delete(col);
            diagonals.delete(currDiagonal);
            antiDiagonals.delete(currAntiDiagonal);
            state[row][col] = ".";
        }
    };
    backtrack(0, new Set(), new Set(), new Set(), emptyBoard);
    return solutions;
}
```

</details>
