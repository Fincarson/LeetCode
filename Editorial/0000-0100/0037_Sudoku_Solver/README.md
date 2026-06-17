# 37. Sudoku Solver

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sudoku-solver/)  
`Array` `Hash Table` `Backtracking` `Matrix`

**Problem Link:** [LeetCode 37 - Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

## Problem

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

The '.' character indicates empty cells.

### Example 1

```text
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
```

## Constraints

- board.length == 9
- board[i].length == 9
- board[i][j] is a digit or '.'.
- It is guaranteed that the input board has only one solution.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 37. Sudoku Solver

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define N 9
#define n 3

int **rows;
int **columns;
int **boxes;
char **board;
bool sudoku_solved;

bool could_place(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
}

void place_number(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;
    board[row][col] = (char)(d + '0');
}

void remove_number(int d, int row, int col) {
    int idx = (row / n) * n + col / n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;
    board[row][col] = '.';
}

void backtrack(int row, int col);

void place_next_numbers(int row, int col) {
    if ((col == N - 1) && (row == N - 1)) {
        sudoku_solved = true;
    } else {
        if (col == N - 1)
            backtrack(row + 1, 0);
        else
            backtrack(row, col + 1);
    }
}

void backtrack(int row, int col) {
    if (board[row][col] == '.') {
        for (int d = 1; d <= 9; d++) {
            if (could_place(d, row, col)) {
                place_number(d, row, col);
                place_next_numbers(row, col);
                if (!sudoku_solved) remove_number(d, row, col);
            }
        }
    } else {
        place_next_numbers(row, col);
    }
}

void solveSudoku(char **boardInput, int boardSize, int *boardColSize) {
    board = boardInput;
    rows = malloc(N * sizeof(int *));
    columns = malloc(N * sizeof(int *));
    boxes = malloc(N * sizeof(int *));
    sudoku_solved = false;

    for (int i = 0; i < N; i++) {
        rows[i] = calloc(10, sizeof(int));
        columns[i] = calloc(10, sizeof(int));
        boxes[i] = calloc(10, sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char num = board[i][j];
            if (num != '.') {
                int d = num - '0';
                place_number(d, i, j);
            }
        }
    }
    backtrack(0, 0);

    for (int i = 0; i < N; i++) {
        free(rows[i]);
        free(columns[i]);
        free(boxes[i]);
    }
    free(rows);
    free(columns);
    free(boxes);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // box size
    int n = 3;
    // row size
    int N = n * n;
    int **rows;
    int **columns;
    int **boxes;
    vector<vector<char>> board;
    bool sudoku_solved = false;

public:
    bool could_place(int d, int row, int col) {
        /*
        Check if one could place a number d in (row, col) cell
        */
        int idx = (row / n) * n + col / n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }
    void place_number(int d, int row, int col) {
        /*
        Place a number d in (row, col) cell
        */
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d + '0');
    }
    void remove_number(int d, int row, int col) {
        /*
        Remove a number that didn't lead to a solution
        */
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }
    void place_next_numbers(int row, int col) {
        /*
        Call backtrack function in recursion
        to continue to place numbers
        till the moment we have a solution
        */
        // If we're in the last cell
        //  that means we have the solution
        if ((col == N - 1) && (row == N - 1)) {
            sudoku_solved = true;
        }
        // if not yet
        else {
            // If we're at the end of the row
            //  go to the next row
            if (col == N - 1) backtrack(row + 1, 0);
            // go to the next column
            else
                backtrack(row, col + 1);
        }
    }
    void backtrack(int row, int col) {
        /*
        Backtracking
        */
        // If the cell is empty
        if (board[row][col] == '.') {
            // iterate over all numbers from 1 to 9
            for (int d = 1; d < 10; d++) {
                if (could_place(d, row, col)) {
                    place_number(d, row, col);
                    place_next_numbers(row, col);
                    // If sudoku is solved, there is no need to backtrack
                    // since the single unique solution is promised
                    if (!sudoku_solved) remove_number(d, row, col);
                }
            }
        } else
            place_next_numbers(row, col);
    }
    void solveSudoku(vector<vector<char>> &board) {
        this->board = board;
        rows = new int *[N];
        columns = new int *[N];
        boxes = new int *[N];
        for (int i = 0; i < N; i++) {
            rows[i] = new int[N + 1]();
            columns[i] = new int[N + 1]();
            boxes[i] = new int[N + 1]();
        }
        // init rows, columns, and boxes
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = num - '0';
                    place_number(d, i, j);
                }
            }
        }
        backtrack(0, 0);
        board = this->board;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    // box size
    int n;

    // row size
    int N;
    int[][] rows;
    int[][] columns;
    int[][] boxes;
    char[][] board;
    bool sudokuSolved = false;

    public Solution() {
        n = 3;
        N = n * n;
        rows = new int [N][];
        columns = new int [N][];
        boxes = new int [N][];
        for (int k = 0; k < N; k++) {
            rows[k] = new int[N + 1];
            columns[k] = new int[N + 1];
            boxes[k] = new int[N + 1];
        }
    }

    public bool CouldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }

    public void PlaceNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d + '0');
    }

    public void RemoveNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }

    public void PlaceNextNumbers(int row, int col) {
        if ((col == N - 1) && (row == N - 1)) {
            sudokuSolved = true;
        } else {
            if (col == N - 1)
                Backtrack(row + 1, 0);
            else
                Backtrack(row, col + 1);
        }
    }

    public void Backtrack(int row, int col) {
        if (board[row][col] == '.') {
            for (int d = 1; d < 10; d++) {
                if (CouldPlace(d, row, col)) {
                    PlaceNumber(d, row, col);
                    PlaceNextNumbers(row, col);
                    if (!sudokuSolved)
                        RemoveNumber(d, row, col);
                }
            }
        } else
            PlaceNextNumbers(row, col);
    }

    public void SolveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = (int)char.GetNumericValue(num);
                    PlaceNumber(d, i, j);
                }
            }
        }

        Backtrack(0, 0);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Solution struct {
    N                    int
    n                    int
    rows, columns, boxes [][]int
    board                [][]byte
    sudokuSolved         bool
}

func Constructor() Solution {
    n := 3
    N := n * n
    rows := make([][]int, N)
    columns := make([][]int, N)
    boxes := make([][]int, N)
    for i := range rows {
        rows[i] = make([]int, N+1)
        columns[i] = make([]int, N+1)
        boxes[i] = make([]int, N+1)
    }
    return Solution{
        N:            N,
        n:            n,
        rows:         rows,
        columns:      columns,
        boxes:        boxes,
        sudokuSolved: false,
    }
}

func (this *Solution) couldPlace(d, row, col int) bool {
    idx := (row/this.n)*this.n + col/this.n
    return this.rows[row][d]+this.columns[col][d]+this.boxes[idx][d] == 0
}

func (this *Solution) placeNumber(d, row, col int) {
    idx := (row/this.n)*this.n + col/this.n
    this.rows[row][d]++
    this.columns[col][d]++
    this.boxes[idx][d]++
    this.board[row][col] = byte(d) + '0'
}

func (this *Solution) removeNumber(d, row, col int) {
    idx := (row/this.n)*this.n + col/this.n
    this.rows[row][d]--
    this.columns[col][d]--
    this.boxes[idx][d]--
    this.board[row][col] = '.'
}

func (this *Solution) placeNextNumbers(row, col int) {
    if (col == this.N-1) && (row == this.N-1) {
        this.sudokuSolved = true
    } else {
        if col == this.N-1 {
            this.backTrack(row+1, 0)
        } else {
            this.backTrack(row, col+1)
        }
    }
}

func (this *Solution) backTrack(row, col int) {
    if this.board[row][col] == '.' {
        for d := 1; d < 10; d++ {
            if this.couldPlace(d, row, col) {
                this.placeNumber(d, row, col)
                this.placeNextNumbers(row, col)
                if !this.sudokuSolved {
                    this.removeNumber(d, row, col)
                }
            }
        }
    } else {
        this.placeNextNumbers(row, col)
    }
}

func solveSudoku(board [][]byte) {
    s := Constructor()
    s.board = board
    for i := 0; i < s.N; i++ {
        for j := 0; j < s.N; j++ {
            num := board[i][j]
            if num != '.' {
                d := int(num - '0')
                s.placeNumber(d, i, j)
            }
        }
    }
    s.backTrack(0, 0)
    board = s.board
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // box size
    int n = 3;
    // row size
    int N = n * n;

    int[][] rows = new int[N][N + 1];
    int[][] columns = new int[N][N + 1];
    int[][] boxes = new int[N][N + 1];

    char[][] board;

    boolean sudokuSolved = false;

    public boolean couldPlace(int d, int row, int col) {
        /*
    Check if one could place a number d in (row, col) cell
    */
        int idx = (row / n) * n + col / n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }

    public void placeNumber(int d, int row, int col) {
        /*
    Place a number d in (row, col) cell
    */
        int idx = (row / n) * n + col / n;

        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char) (d + '0');
    }

    public void removeNumber(int d, int row, int col) {
        /*
    Remove a number that didn't lead to a solution
    */
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }

    public void placeNextNumbers(int row, int col) {
        /*
    Call backtrack function in recursion
    to continue to place numbers
    till the moment we have a solution
    */
        //If we're in the last cell
        // that means we have the solution
        if ((col == N - 1) && (row == N - 1)) {
            sudokuSolved = true;
        }
        // if not yet
        else {
            //If we're at the end of the row
            // go to the next row
            if (col == N - 1) backtrack(row + 1, 0);
            // go to the next column
            else backtrack(row, col + 1);
        }
    }

    public void backtrack(int row, int col) {
        /*
    Backtracking
    */
        //If the cell is empty
        if (board[row][col] == '.') {
            // iterate over all numbers from 1 to 9
            for (int d = 1; d < 10; d++) {
                if (couldPlace(d, row, col)) {
                    placeNumber(d, row, col);
                    placeNextNumbers(row, col);
                    // If sudoku is solved, there is no need to backtrack
                    // since the single unique solution is promised
                    if (!sudokuSolved) removeNumber(d, row, col);
                }
            }
        } else placeNextNumbers(row, col);
    }

    public void solveSudoku(char[][] board) {
        this.board = board;

        // init rows, columns, and boxes
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = Character.getNumericValue(num);
                    placeNumber(d, i, j);
                }
            }
        }
        backtrack(0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var solveSudoku = function (board) {
    let N = 9;
    let rows = Array.from({ length: N }, () => new Map());
    let columns = Array.from({ length: N }, () => new Map());
    let boxes = Array.from({ length: N }, () => new Map());
    let sudoku_solved = false;
    function box_index(row, col) {
        return Math.floor(row / 3) * 3 + Math.floor(col / 3);
    }
    function could_place(d, row, col) {
        let res = !(
            rows[row].has(String(d)) ||
            columns[col].has(String(d)) ||
            boxes[box_index(row, col)].has(String(d))
        );
        return res;
    }
    function place_number(d, row, col) {
        rows[row].set(
            String(d),
            rows[row].has(String(d)) ? rows[row].get(String(d)) + 1 : 1,
        );
        columns[col].set(
            String(d),
            columns[col].has(String(d)) ? columns[col].get(String(d)) + 1 : 1,
        );
        boxes[box_index(row, col)].set(
            String(d),
            boxes[box_index(row, col)].has(String(d))
                ? boxes[box_index(row, col)].get(String(d)) + 1
                : 1,
        );
        board[row][col] = String(d);
    }
    function remove_number(d, row, col) {
        rows[row].delete(String(d), rows[row].get(String(d)) - 1);
        columns[col].delete(String(d), columns[col].get(String(d)) - 1);
        boxes[box_index(row, col)].delete(
            String(d),
            boxes[box_index(row, col)].get(String(d)) - 1,
        );
        board[row][col] = ".";
    }
    function place_next_numbers(row, col) {
        if (col === N - 1 && row === N - 1) sudoku_solved = true;
        else {
            if (col === N - 1) backtrack(row + 1, 0);
            else backtrack(row, col + 1);
        }
    }
    function backtrack(row = 0, col = 0) {
        if (board[row][col] === ".") {
            for (let d = 1; d < 10; d++) {
                if (could_place(d, row, col)) {
                    place_number(d, row, col);
                    place_next_numbers(row, col);
                    if (!sudoku_solved) remove_number(d, row, col);
                }
            }
        } else place_next_numbers(row, col);
    }
    for (let i = 0; i < N; ++i)
        for (let j = 0; j < N; ++j)
            if (board[i][j] !== ".") place_number(parseInt(board[i][j]), i, j);
    backtrack();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict


class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """

        def could_place(d, row, col):
            """
            Check if one could place a number d in (row, col) cell
            """
            return not (
                d in rows[row]
                or d in columns[col]
                or d in boxes[box_index(row, col)]
            )

        def place_number(d, row, col):
            """
            Place a number d in (row, col) cell
            """
            rows[row][d] += 1
            columns[col][d] += 1
            boxes[box_index(row, col)][d] += 1
            board[row][col] = str(d)

        def remove_number(d, row, col):
            """
            Remove a number that didn't lead to a solution
            """
            rows[row][d] -= 1
            columns[col][d] -= 1
            boxes[box_index(row, col)][d] -= 1
            if rows[row][d] == 0:
                del rows[row][d]
            if columns[col][d] == 0:
                del columns[col][d]
            if boxes[box_index(row, col)][d] == 0:
                del boxes[box_index(row, col)][d]
            board[row][col] = "."

        def place_next_numbers(row, col):
            """
            Call backtrack function in recursion to continue to place numbers
            till the moment we have a solution
            """
            if col == N - 1 and row == N - 1:
                sudoku_solved[0] = True
            else:
                if col == N - 1:
                    backtrack(row + 1, 0)
                else:
                    backtrack(row, col + 1)

        def backtrack(row=0, col=0):
            """
            Backtracking
            """
            if board[row][col] == ".":
                for d in range(1, 10):
                    if could_place(d, row, col):
                        place_number(d, row, col)
                        place_next_numbers(row, col)
                        if sudoku_solved[0]:
                            return
                        remove_number(d, row, col)
            else:
                place_next_numbers(row, col)

        n = 3
        N = n * n
        box_index = lambda row, col: (row // n) * n + col // n

        rows = [defaultdict(int) for _ in range(N)]
        columns = [defaultdict(int) for _ in range(N)]
        boxes = [defaultdict(int) for _ in range(N)]
        for i in range(N):
            for j in range(N):
                if board[i][j] != ".":
                    d = int(board[i][j])
                    place_number(d, i, j)

        sudoku_solved = [False]
        backtrack()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solveSudoku(board: string[][]): void {
    let n: number = 3;
    let N: number = n * n;
    let boxIndex = (row: number, col: number): number =>
        Math.floor(row / n) * n + Math.floor(col / n);
    let rows: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    let columns: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    let boxes: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            if (board[i][j] !== ".") {
                let d: number = Number(board[i][j]);
                placeNumber(d, i, j, rows, columns, boxes, boxIndex, board);
            }
        }
    }
    solve(board, 0, 0, rows, columns, boxes, boxIndex);
}
function solve(
    board: string[][],
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
): boolean {
    if (col === board[row].length) {
        row++;
        col = 0;
    }
    if (row === board.length) {
        return true;
    }
    if (board[row][col] !== ".") {
        return solve(board, row, col + 1, rows, columns, boxes, boxIndex);
    }
    for (let num = 1; num <= 9; num++) {
        let digit = num.toString();
        if (couldPlace(num, row, col, rows, columns, boxes, boxIndex)) {
            placeNumber(num, row, col, rows, columns, boxes, boxIndex, board);
            if (solve(board, row, col + 1, rows, columns, boxes, boxIndex)) {
                return true;
            }
            removeNumber(num, row, col, rows, columns, boxes, boxIndex, board);
        }
    }
    return false;
}
function couldPlace(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
): boolean {
    let res: boolean = !(
        rows[row].has(d) ||
        columns[col].has(d) ||
        boxes[boxIndex(row, col)].has(d)
    );
    return res;
}
function placeNumber(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
    board: string[][],
): void {
    rows[row].set(d, (rows[row].get(d) || 0) + 1);
    columns[col].set(d, (columns[col].get(d) || 0) + 1);
    boxes[boxIndex(row, col)].set(
        d,
        (boxes[boxIndex(row, col)].get(d) || 0) + 1,
    );
    board[row][col] = String(d);
}
function removeNumber(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
    board: string[][],
): void {
    rows[row].delete(d);
    columns[col].delete(d);
    boxes[boxIndex(row, col)].delete(d);
    board[row][col] = ".";
}
```

</details>
