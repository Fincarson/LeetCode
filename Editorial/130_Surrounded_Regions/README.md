# 130. Surrounded Regions

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/surrounded-regions/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 130 - Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)

## Problem

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

- Connect: A cell is connected to adjacent cells horizontally or vertically.
- Region: To form a region connect every 'O' cell.
- Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

### Example 1

### Example 2

## Constraints

- m == board.length
- n == board[i].length
- 1 <= m, n <= 200
- board[i][j] is 'X' or 'O'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Walls and Gates](https://leetcode.com/problems/walls-and-gates/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 130. Surrounded Regions

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS (Depth-First Search) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| BFS (Breadth-First Search) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: DFS (Depth-First Search)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int* data;
    int top;
    int max;
} pairStack;
pairStack* createStack(int max) {
    pairStack* stack = calloc(1, sizeof(pairStack));
    stack->data = calloc(max, sizeof(int));
    stack->max = max;
    return stack;
}
void pushStack(pairStack* s, int a) {
    if (s->top >= s->max) return;
    s->data[s->top++] = a;
}
int popStack(pairStack* s) {
    if (s->top <= 0) return -1;
    return s->data[--s->top];
}
void dfs(char** board, int ROWS, int COLS, int row, int col) {
    if (board[row][col] != 'O') return;
    pairStack* stack = createStack(ROWS * COLS * 2);
    pushStack(stack, row);
    pushStack(stack, col);
    while (stack->top != 0) {
        col = popStack(stack);
        row = popStack(stack);
        if (board[row][col] == 'O') {
            board[row][col] = 'E';
            if (col + 1 < COLS) {
                pushStack(stack, row);
                pushStack(stack, col + 1);
            }
            if (row + 1 < ROWS) {
                pushStack(stack, row + 1);
                pushStack(stack, col);
            }
            if (col > 0) {
                pushStack(stack, row);
                pushStack(stack, col - 1);
            }
            if (row > 0) {
                pushStack(stack, row - 1);
                pushStack(stack, col);
            }
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || *boardColSize == 0) return;
    int ROWS = boardSize, COLS = *boardColSize;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                dfs(board, ROWS, COLS, i, j);
        }
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'E')
                board[i][j] = 'O';
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1)
                    DFS(board, i, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }

private:
    int ROWS, COLS;
    void DFS(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = 'E';
        if (j < COLS - 1) DFS(board, i, j + 1);
        if (i < ROWS - 1) DFS(board, i + 1, j);
        if (j > 0) DFS(board, i, j - 1);
        if (i > 0) DFS(board, i - 1, j);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Solve(char[][] board) {
        if (board == null || board.Length == 0) {
            return;
        }

        this.ROWS = board.Length;
        this.COLS = board[0].Length;
        List<int[]> borders = new List<int[]>();
        // Step 1). construct the list of border cells to iterate over
        for (int r = 0; r < this.ROWS; ++r) {
            borders.Add(new int[] { r, 0 });
            borders.Add(new int[] { r, this.COLS - 1 });
        }

        for (int c = 0; c < this.COLS; ++c) {
            borders.Add(new int[] { 0, c });
            borders.Add(new int[] { this.ROWS - 1, c });
        }

        // Step 2). mark the escaped cells
        foreach (var pair in borders) {
            this.DFS(board, pair[0], pair[1]);
        }

        // Step 3). flip the cells to their correct final states
        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }

    int ROWS, COLS;

    protected void DFS(char[][] board, int row, int col) {
        if (board[row][col] != 'O')
            return;
        board[row][col] = 'E';
        if (col < this.COLS - 1)
            DFS(board, row, col + 1);
        if (row < this.ROWS - 1)
            DFS(board, row + 1, col);
        if (col > 0)
            DFS(board, row, col - 1);
        if (row > 0)
            DFS(board, row - 1, col);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func solve(board [][]byte) {
    if board == nil || len(board) == 0 {
        return
    }
    ROWS := len(board)
    COLS := len(board[0])
    borders := [][]int{}
    for r := 0; r < ROWS; r++ {
        borders = append(borders, []int{r, 0})
        borders = append(borders, []int{r, COLS - 1})
    }
    for c := 0; c < COLS; c++ {
        borders = append(borders, []int{0, c})
        borders = append(borders, []int{ROWS - 1, c})
    }
    var DFS func([][]byte, int, int)
    DFS = func(board [][]byte, row int, col int) {
        if board[row][col] != 'O' {
            return
        }
        board[row][col] = 'E'
        if col < COLS-1 {
            DFS(board, row, col+1)
        }
        if row < ROWS-1 {
            DFS(board, row+1, col)
        }
        if col > 0 {
            DFS(board, row, col-1)
        }
        if row > 0 {
            DFS(board, row-1, col)
        }
    }
    for _, pair := range borders {
        DFS(board, pair[0], pair[1])
    }
    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            if board[r][c] == 'O' {
                board[r][c] = 'X'
            }
            if board[r][c] == 'E' {
                board[r][c] = 'O'
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    protected Integer ROWS = 0;
    protected Integer COLS = 0;

    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        this.ROWS = board.length;
        this.COLS = board[0].length;

        List<Pair<Integer, Integer>> borders = new LinkedList<
            Pair<Integer, Integer>
        >();
        // Step 1). construct the list of border cells
        for (int r = 0; r < this.ROWS; ++r) {
            borders.add(new Pair(r, 0));
            borders.add(new Pair(r, this.COLS - 1));
        }
        for (int c = 0; c < this.COLS; ++c) {
            borders.add(new Pair(0, c));
            borders.add(new Pair(this.ROWS - 1, c));
        }

        // Step 2). mark the escaped cells
        for (Pair<Integer, Integer> pair : borders) {
            this.DFS(board, pair.first, pair.second);
        }

        // Step 3). flip the cells to their correct final states
        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'E') board[r][c] = 'O';
            }
        }
    }

    protected void DFS(char[][] board, int row, int col) {
        if (board[row][col] != 'O') return;

        board[row][col] = 'E';
        if (col < this.COLS - 1) this.DFS(board, row, col + 1);
        if (row < this.ROWS - 1) this.DFS(board, row + 1, col);
        if (col > 0) this.DFS(board, row, col - 1);
        if (row > 0) this.DFS(board, row - 1, col);
    }
}

class Pair<U, V> {
    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var solve = function (board) {
    if (board == null || board.length == 0) {
        return;
    }
    let ROWS = board.length;
    let COLS = board[0].length;
    let borders = [];
    for (let r = 0; r < ROWS; ++r) {
        borders.push([r, 0]);
        borders.push([r, COLS - 1]);
    }
    for (let c = 0; c < COLS; ++c) {
        borders.push([0, c]);
        borders.push([ROWS - 1, c]);
    }
    borders.forEach((pair) => {
        dfs(board, pair[0], pair[1]);
    });
    for (let r = 0; r < ROWS; ++r) {
        for (let c = 0; c < COLS; ++c) {
            if (board[r][c] == "O") board[r][c] = "X";
            if (board[r][c] == "E") board[r][c] = "O";
        }
    }
    function dfs(board, row, col) {
        if (board[row][col] != "O") return;
        board[row][col] = "E";
        if (col < COLS - 1) dfs(board, row, col + 1);
        if (row < ROWS - 1) dfs(board, row + 1, col);
        if (col > 0) dfs(board, row, col - 1);
        if (row > 0) dfs(board, row - 1, col);
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def solve(self, board: List[List[str]]) -> None:
        if not board or not board[0]:
            return

        self.ROWS = len(board)
        self.COLS = len(board[0])

        # Step 1). retrieve all border cells
        from itertools import product

        borders = list(product(range(self.ROWS), [0, self.COLS - 1])) + list(
            product([0, self.ROWS - 1], range(self.COLS))
        )

        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            self.DFS(board, row, col)

        # Step 3). flip the captured cells ('O'->'X') and the escaped one ('E'->'O')
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"  # captured
                elif board[r][c] == "E":
                    board[r][c] = "O"  # escaped

    def DFS(self, board: List[List[str]], row: int, col: int) -> None:
        if board[row][col] != "O":
            return
        board[row][col] = "E"
        if col < self.COLS - 1:
            self.DFS(board, row, col + 1)
        if row < self.ROWS - 1:
            self.DFS(board, row + 1, col)
        if col > 0:
            self.DFS(board, row, col - 1)
        if row > 0:
            self.DFS(board, row - 1, col)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function solve(board: string[][]): void {
    if (board == null || board.length == 0) {
        return;
    }
    let ROWS = board.length;
    let COLS = board[0].length;
    let borders = [];
    for (let r = 0; r < ROWS; ++r) {
        borders.push([r, 0]);
        borders.push([r, COLS - 1]);
    }
    for (let c = 0; c < COLS; ++c) {
        borders.push([0, c]);
        borders.push([ROWS - 1, c]);
    }
    borders.forEach((pair) => {
        dfs(board, pair[0], pair[1]);
    });
    for (let r = 0; r < ROWS; ++r) {
        for (let c = 0; c < COLS; ++c) {
            if (board[r][c] == "O") board[r][c] = "X";
            if (board[r][c] == "E") board[r][c] = "O";
        }
    }
    function dfs(board: string[][], row: number, col: number): void {
        if (board[row][col] != "O") return;
        board[row][col] = "E";
        if (col < COLS - 1) dfs(board, row, col + 1);
        if (row < ROWS - 1) dfs(board, row + 1, col);
        if (col > 0) dfs(board, row, col - 1);
        if (row > 0) dfs(board, row - 1, col);
    }
}
```

</details>

<br>

## Approach 2: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void solve(char** board, int boardSize, int* boardColSize) {
    if (!board || !board[0]) {
        return;
    }
    const int ROWS = boardSize;
    const int COLS = boardColSize[0];
    for (int r = 0; r < ROWS; ++r) {
        BFS(board, ROWS, COLS, r, 0);
        BFS(board, ROWS, COLS, r, COLS - 1);
    }
    for (int c = 0; c < COLS; ++c) {
        BFS(board, ROWS, COLS, 0, c);
        BFS(board, ROWS, COLS, ROWS - 1, c);
    }
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (board[r][c] == 'O') board[r][c] = 'X';
            if (board[r][c] == 'E') board[r][c] = 'O';
        }
    }
}
void BFS(char** board, int ROWS, int COLS, int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS ||
        board[row][col] != 'O')
        return;
    board[row][col] = 'E';
    BFS(board, ROWS, COLS, row + 1, col);
    BFS(board, ROWS, COLS, row - 1, col);
    BFS(board, ROWS, COLS, row, col + 1);
    BFS(board, ROWS, COLS, row, col - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int ROWS;
    int COLS;
    void BFS(vector<vector<char>>& board, int row, int col) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (q.size() > 0) {
            auto front = q.front();
            int row = front.first, col = front.second;
            q.pop();
            if (board[row][col] != 'O') continue;
            board[row][col] = 'E';
            if (col < COLS - 1) q.push(make_pair(row, col + 1));
            if (row < ROWS - 1) q.push(make_pair(row + 1, col));
            if (col > 0) q.push(make_pair(row, col - 1));
            if (row > 0) q.push(make_pair(row - 1, col));
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int numRows = board.size();
        if (numRows == 0) return;
        int numCols = board[0].size();
        this->ROWS = numRows;
        this->COLS = numCols;
        vector<pair<int, int>> border;
        for (int r = 0; r < this->ROWS; ++r) {
            border.push_back(make_pair(r, 0));
            border.push_back(make_pair(r, this->COLS - 1));
        }
        for (int c = 0; c < this->COLS; ++c) {
            border.push_back(make_pair(0, c));
            border.push_back(make_pair(this->ROWS - 1, c));
        }
        for (pair<int, int> border_pair : border)
            this->BFS(board, border_pair.first, border_pair.second);
        for (int r = 0; r < this->ROWS; ++r) {
            for (int c = 0; c < this->COLS; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'E') board[r][c] = 'O';
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int ROWS;
    private int COLS;

    public void Solve(char[][] board) {
        if (board == null || board.Length == 0) {
            return;
        }

        this.ROWS = board.Length;
        this.COLS = board[0].Length;
        List<Pair<int, int>> borders = new List<Pair<int, int>>();
        for (int r = 0; r < this.ROWS; ++r) {
            borders.Add(new Pair<int, int>(r, 0));
            borders.Add(new Pair<int, int>(r, this.COLS - 1));
        }

        for (int c = 0; c < this.COLS; ++c) {
            borders.Add(new Pair<int, int>(0, c));
            borders.Add(new Pair<int, int>(this.ROWS - 1, c));
        }

        foreach (Pair<int, int> pair in borders) {
            this.BFS(board, pair.first, pair.second);
        }

        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }

    protected void BFS(char[][] board, int r, int c) {
        Queue<Pair<int, int>> queue = new Queue<Pair<int, int>>();
        queue.Enqueue(new Pair<int, int>(r, c));
        while (queue.Count > 0) {
            Pair<int, int> pair = queue.Dequeue();
            int row = pair.first, col = pair.second;
            if (board[row][col] != 'O')
                continue;
            board[row][col] = 'E';
            if (col < this.COLS - 1)
                queue.Enqueue(new Pair<int, int>(row, col + 1));
            if (row < this.ROWS - 1)
                queue.Enqueue(new Pair<int, int>(row + 1, col));
            if (col > 0)
                queue.Enqueue(new Pair<int, int>(row, col - 1));
            if (row > 0)
                queue.Enqueue(new Pair<int, int>(row - 1, col));
        }
    }
}

public class Pair<T1, T2> {
    public T1 first;
    public T2 second;

    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type pair struct {
    first  int
    second int
}

func solve(board [][]byte) {
    if len(board) == 0 || len(board[0]) == 0 {
        return
    }
    ROWS := len(board)
    COLS := len(board[0])
    border := make([]pair, 0)
    for r := 0; r < ROWS; r++ {
        border = append(border, pair{r, 0})
        border = append(border, pair{r, COLS - 1})
    }
    for c := 0; c < COLS; c++ {
        border = append(border, pair{0, c})
        border = append(border, pair{ROWS - 1, c})
    }
    for _, pair := range border {
        BFS(board, pair.first, pair.second, ROWS, COLS)
    }
    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            if board[r][c] == 'O' {
                board[r][c] = 'X'
            }
            if board[r][c] == 'E' {
                board[r][c] = 'O'
            }
        }
    }
}

func BFS(board [][]byte, row int, col int, ROWS int, COLS int) {
    queue := make([]pair, 0)
    queue = append(queue, pair{row, col})
    for len(queue) != 0 {
        top := queue[0]
        queue = queue[1:]
        row = top.first
        col = top.second
        if board[row][col] != 'O' {
            continue
        }
        board[row][col] = 'E'
        if col < COLS-1 {
            queue = append(queue, pair{row, col + 1})
        }
        if row < ROWS-1 {
            queue = append(queue, pair{row + 1, col})
        }
        if col > 0 {
            queue = append(queue, pair{row, col - 1})
        }
        if row > 0 {
            queue = append(queue, pair{row - 1, col})
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    protected Integer ROWS = 0;
    protected Integer COLS = 0;

    public void solve(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        this.ROWS = board.length;
        this.COLS = board[0].length;

        List<Pair<Integer, Integer>> borders = new LinkedList<
            Pair<Integer, Integer>
        >();
        // Step 1). construct the list of border cells
        for (int r = 0; r < this.ROWS; ++r) {
            borders.add(new Pair(r, 0));
            borders.add(new Pair(r, this.COLS - 1));
        }
        for (int c = 0; c < this.COLS; ++c) {
            borders.add(new Pair(0, c));
            borders.add(new Pair(this.ROWS - 1, c));
        }

        // Step 2). mark the escaped cells
        for (Pair<Integer, Integer> pair : borders) {
            this.BFS(board, pair.first, pair.second);
        }

        // Step 3). flip the cells to their correct final states
        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'E') board[r][c] = 'O';
            }
        }
    }

    protected void BFS(char[][] board, int r, int c) {
        LinkedList<Pair<Integer, Integer>> queue = new LinkedList<
            Pair<Integer, Integer>
        >();
        queue.offer(new Pair<>(r, c));

        while (!queue.isEmpty()) {
            Pair<Integer, Integer> pair = queue.pollFirst();
            int row = pair.first, col = pair.second;
            if (board[row][col] != 'O') continue;

            board[row][col] = 'E';
            if (col < this.COLS - 1) queue.offer(new Pair<>(row, col + 1));
            if (row < this.ROWS - 1) queue.offer(new Pair<>(row + 1, col));
            if (col > 0) queue.offer(new Pair<>(row, col - 1));
            if (row > 0) queue.offer(new Pair<>(row - 1, col));
        }
    }
}

class Pair<U, V> {
    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var solve = function (board) {
    if (!board || !board[0]) {
        return;
    }
    const ROWS = board.length;
    const COLS = board[0].length;
    let borders = Array.from({ length: ROWS }, (v, k) => k)
        .map((v) => [
            [v, 0],
            [v, COLS - 1],
        ])
        .concat(
            Array.from({ length: COLS }, (v, k) => k).map((v) => [
                [0, v],
                [ROWS - 1, v],
            ]),
        )
        .flat();
    borders.forEach((pos) => BFS(board, pos[0], pos[1], ROWS, COLS));
    for (let r = 0; r < ROWS; ++r) {
        for (let c = 0; c < COLS; ++c) {
            if (board[r][c] == "O") board[r][c] = "X";
            if (board[r][c] == "E") board[r][c] = "O";
        }
    }
};
const BFS = function (board, row, col, ROWS, COLS) {
    let queue = [[row, col]];
    while (queue.length) {
        let [row, col] = queue.shift();
        if (board[row][col] !== "O") {
            continue;
        }
        board[row][col] = "E"; // Mark this cell as escaped
        if (col < COLS - 1) queue.push([row, col + 1]);
        if (row < ROWS - 1) queue.push([row + 1, col]);
        if (col > 0) queue.push([row, col - 1]);
        if (row > 0) queue.push([row - 1, col]);
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def solve(self, board: List[List[str]]) -> None:
        if not board or not board[0]:
            return

        self.ROWS = len(board)
        self.COLS = len(board[0])

        # Step 1). retrieve all border cells
        from itertools import product

        borders = list(product(range(self.ROWS), [0, self.COLS - 1])) + list(
            product([0, self.ROWS - 1], range(self.COLS))
        )

        # Step 2). mark the "escaped" cells, with any placeholder, e.g. 'E'
        for row, col in borders:
            self.BFS(board, row, col)

        # Step 3). flip the captured cells ('O'->'X') and the escaped one ('E'->'O')
        for r in range(self.ROWS):
            for c in range(self.COLS):
                if board[r][c] == "O":
                    board[r][c] = "X"  # captured
                elif board[r][c] == "E":
                    board[r][c] = "O"  # escaped

    def BFS(self, board: List[List[str]], row: int, col: int) -> None:
        from collections import deque

        queue = deque([(row, col)])
        while queue:
            (row, col) = queue.popleft()
            if board[row][col] != "O":
                continue
            # mark this cell as escaped
            board[row][col] = "E"
            # check its neighbor cells
            if col < self.COLS - 1:
                queue.append((row, col + 1))
            if row < self.ROWS - 1:
                queue.append((row + 1, col))
            if col > 0:
                queue.append((row, col - 1))
            if row > 0:
                queue.append((row - 1, col))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
var solve = function (board: Array<Array<string>>): void {
    if (!board || !board[0]) {
        return;
    }
    const ROWS: number = board.length;
    const COLS: number = board[0].length;
    let borders: number[][] = Array.from({ length: ROWS }, (v, i) => i)
        .map((i) => [
            [i, 0],
            [i, COLS - 1],
        ])
        .concat(
            Array.from({ length: COLS }, (v, i) => i).map((i) => [
                [0, i],
                [ROWS - 1, i],
            ]),
        )
        .flat();
    borders.forEach(([row, col]) => BFS(board, row, col, ROWS, COLS));
    for (let row = 0; row < ROWS; ++row)
        for (let col = 0; col < COLS; ++col) {
            if (board[row][col] == "O") board[row][col] = "X";
            if (board[row][col] == "E") board[row][col] = "O";
        }
};
var BFS = function (
    board: Array<Array<string>>,
    row: number,
    col: number,
    ROWS: number,
    COLS: number,
): void {
    let queue: number[][] = [[row, col]];
    while (queue.length) {
        let [row, col] = queue.shift() as number[];
        if (board[row][col] !== "O") {
            continue;
        }
        board[row][col] = "E"; // Mark this cell as escaped
        if (col < COLS - 1) queue.push([row, col + 1]);
        if (row < ROWS - 1) queue.push([row + 1, col]);
        if (col > 0) queue.push([row, col - 1]);
        if (row > 0) queue.push([row - 1, col]);
    }
};
```

</details>
