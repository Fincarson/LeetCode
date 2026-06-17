# 36. Valid Sudoku

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/valid-sudoku/)  
`Array` `Hash Table` `Matrix`

**Problem Link:** [LeetCode 36 - Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

## Problem

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Note:

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

### Example 1

```text
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

### Example 2

```text
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

## Constraints

- board.length == 9
- board[i].length == 9
- board[i][j] is a digit 1-9 or '.'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 36. Valid Sudoku

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Array of Fixed Length | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bitmasking | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define N 9
bool inHashTable(int* hashTable, int val) {
    if (hashTable[val - 1] == 1) {
        return true;
    }
    return false;
}
void insertHashTable(int* hashTable, int val) { hashTable[val - 1]++; }
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int *rows[N], *cols[N], *boxes[N];
    // Initialize hash tables
    for (int i = 0; i < N; i++) {
        rows[i] = (int*)calloc(9, sizeof(int));
        cols[i] = (int*)calloc(9, sizeof(int));
        boxes[i] = (int*)calloc(9, sizeof(int));
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == '.') {
                continue;
            }
            int val = board[r][c] - '0';
            // Check the row
            if (inHashTable(rows[r], val)) {
                return false;
            }
            insertHashTable(rows[r], val);
            // Check the column
            if (inHashTable(cols[c], val)) {
                return false;
            }
            insertHashTable(cols[c], val);
            // Check the box
            int idx = (r / 3) * 3 + c / 3;
            if (inHashTable(boxes[idx], val)) {
                return false;
            }
            insertHashTable(boxes[idx], val);
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use hash set to record the status
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                // Check if the position is filled with number
                if (val == '.') {
                    continue;
                }
                // Check the row
                if (rows[r].find(val) != rows[r].end()) {
                    return false;
                }
                rows[r].insert(val);
                // Check the column
                if (cols[c].find(val) != cols[c].end()) {
                    return false;
                }
                cols[c].insert(val);
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx].find(val) != boxes[idx].end()) {
                    return false;
                }
                boxes[idx].insert(val);
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int N = 9;
        // Use hash set to record the status
        HashSet<char>[] rows = new HashSet<char>[N];
        HashSet<char>[] cols = new HashSet<char>[N];
        HashSet<char>[] boxes = new HashSet<char>[N];
        for (int r = 0; r < N; r++) {
            rows[r] = new HashSet<char>();
            cols[r] = new HashSet<char>();
            boxes[r] = new HashSet<char>();
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                // Check if the position is filled with number
                if (val == '.') {
                    continue;
                }

                // Check the row
                if (rows[r].Contains(val)) {
                    return false;
                }

                rows[r].Add(val);
                // Check the column
                if (cols[c].Contains(val)) {
                    return false;
                }

                cols[c].Add(val);
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx].Contains(val)) {
                    return false;
                }

                boxes[idx].Add(val);
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValidSudoku(board [][]byte) bool {
    N := 9
    // Use hash set to record the status
    rows := make([]map[byte]bool, N)
    cols := make([]map[byte]bool, N)
    boxes := make([]map[byte]bool, N)
    for i := 0; i < N; i++ {
        rows[i] = make(map[byte]bool)
        cols[i] = make(map[byte]bool)
        boxes[i] = make(map[byte]bool)
    }
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            val := board[r][c]
            // Check if the position is filled with number
            if val == '.' {
                continue
            }
            // Check the row
            if rows[r][val] {
                return false
            }
            rows[r][val] = true
            // Check the column
            if cols[c][val] {
                return false
            }
            cols[c][val] = true
            // Check the box
            idx := (r/3)*3 + c/3
            if boxes[idx][val] {
                return false
            }
            boxes[idx][val] = true
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N = 9;

        // Use hash set to record the status
        HashSet<Character>[] rows = new HashSet[N];
        HashSet<Character>[] cols = new HashSet[N];
        HashSet<Character>[] boxes = new HashSet[N];
        for (int r = 0; r < N; r++) {
            rows[r] = new HashSet<Character>();
            cols[r] = new HashSet<Character>();
            boxes[r] = new HashSet<Character>();
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];

                // Check if the position is filled with number
                if (val == '.') {
                    continue;
                }

                // Check the row
                if (rows[r].contains(val)) {
                    return false;
                }
                rows[r].add(val);

                // Check the column
                if (cols[c].contains(val)) {
                    return false;
                }
                cols[c].add(val);

                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx].contains(val)) {
                    return false;
                }
                boxes[idx].add(val);
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidSudoku = function (board) {
    let N = 9;
    // Use hash set to record the status
    let rows = new Array(N).fill().map(() => new Set());
    let cols = new Array(N).fill().map(() => new Set());
    let boxes = new Array(N).fill().map(() => new Set());
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            let val = board[r][c];
            // Check if the position is filled with number
            if (val == ".") {
                continue;
            }
            // Check the row
            if (rows[r].has(val)) {
                return false;
            }
            rows[r].add(val);
            // Check the column
            if (cols[c].has(val)) {
                return false;
            }
            cols[c].add(val);
            // Check the box
            let idx = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx].has(val)) {
                return false;
            }
            boxes[idx].add(val);
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        N = 9

        # Use hash set to record the status
        rows = [set() for _ in range(N)]
        cols = [set() for _ in range(N)]
        boxes = [set() for _ in range(N)]

        for r in range(N):
            for c in range(N):
                val = board[r][c]
                # Check if the position is filled with number
                if val == ".":
                    continue

                # Check the row
                if val in rows[r]:
                    return False
                rows[r].add(val)

                # Check the column
                if val in cols[c]:
                    return False
                cols[c].add(val)

                # Check the box
                idx = (r // 3) * 3 + c // 3
                if val in boxes[idx]:
                    return False
                boxes[idx].add(val)

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidSudoku(board: string[][]): boolean {
    let N = 9;
    // Use hash set to record the status
    let rows: Set<string>[] = new Array(N).fill(null).map(() => new Set());
    let cols: Set<string>[] = new Array(N).fill(null).map(() => new Set());
    let boxes: Set<string>[] = new Array(N).fill(null).map(() => new Set());
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            let val = board[r][c];
            // Check if the position is filled with number
            if (val == ".") {
                continue;
            }
            // Check the row
            if (rows[r].has(val)) {
                return false;
            }
            rows[r].add(val);
            // Check the column
            if (cols[c].has(val)) {
                return false;
            }
            cols[c].add(val);
            // Check the box
            let idx = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx].has(val)) {
                return false;
            }
            boxes[idx].add(val);
        }
    }
    return true;
}
```

</details>

<br>

## Approach 2: Array of Fixed Length

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int N = 9;
    int rows[N][N];
    memset(rows, 0, sizeof(rows));
    int cols[N][N];
    memset(cols, 0, sizeof(cols));
    int boxes[N][N];
    memset(boxes, 0, sizeof(boxes));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == '.') {
                continue;
            }
            int pos = board[r][c] - '1';
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            int idx = (r / 3) * 3 + c / 3;
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use vectors to record the status
        vector<vector<int>> rows(N, vector<int>(N, 0));
        vector<vector<int>> cols(N, vector<int>(N, 0));
        vector<vector<int>> boxes(N, vector<int>(N, 0));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int pos = board[r][c] - '1';
                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }
                rows[r][pos] = 1;
                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }
                cols[c][pos] = 1;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }
                boxes[idx][pos] = 1;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int N = 9;
        // Use an array to record the status
        int[][] rows = new int [N][];
        int[][] cols = new int [N][];
        int[][] boxes = new int [N][];
        for (int i = 0; i < N; i++) {
            rows[i] = new int[N];
            cols[i] = new int[N];
            boxes[i] = new int[N];
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }

                int pos = board[r][c] - '1';
                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }

                rows[r][pos] = 1;
                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }

                cols[c][pos] = 1;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }

                boxes[idx][pos] = 1;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValidSudoku(board [][]byte) bool {
    var N int = 9
    var rows [9][9]int
    var cols [9][9]int
    var boxes [9][9]int
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            if board[r][c] == '.' {
                continue
            }
            pos := int(board[r][c] - '1')
            if rows[r][pos] == 1 {
                return false
            }
            rows[r][pos] = 1
            if cols[c][pos] == 1 {
                return false
            }
            cols[c][pos] = 1
            idx := (r/3)*3 + c/3
            if boxes[idx][pos] == 1 {
                return false
            }
            boxes[idx][pos] = 1
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N = 9;

        // Use an array to record the status
        int[][] rows = new int[N][N];
        int[][] cols = new int[N][N];
        int[][] boxes = new int[N][N];

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int pos = board[r][c] - '1';

                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }
                rows[r][pos] = 1;

                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }
                cols[c][pos] = 1;

                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }
                boxes[idx][pos] = 1;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidSudoku = function (board) {
    var N = 9;
    var rows = Array.from(Array(N), () => new Array(N).fill(0));
    var cols = Array.from(Array(N), () => new Array(N).fill(0));
    var boxes = Array.from(Array(N), () => new Array(N).fill(0));
    for (var r = 0; r < N; r++) {
        for (var c = 0; c < N; c++) {
            if (board[r][c] == ".") {
                continue;
            }
            var pos = board[r][c].charCodeAt(0) - "1".charCodeAt(0);
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            var idx = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        N = 9

        # Use an array to record the status
        rows = [[0] * N for _ in range(N)]
        cols = [[0] * N for _ in range(N)]
        boxes = [[0] * N for _ in range(N)]

        for r in range(N):
            for c in range(N):
                # Check if the position is filled with number
                if board[r][c] == ".":
                    continue

                pos = int(board[r][c]) - 1

                # Check the row
                if rows[r][pos] == 1:
                    return False
                rows[r][pos] = 1

                # Check the column
                if cols[c][pos] == 1:
                    return False
                cols[c][pos] = 1

                # Check the box
                idx = (r // 3) * 3 + c // 3
                if boxes[idx][pos] == 1:
                    return False
                boxes[idx][pos] = 1

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidSudoku(board: string[][]): boolean {
    let N = 9;
    let rows: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    let cols: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    let boxes: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            if (board[r][c] == ".") {
                continue;
            }
            let pos: number = parseInt(board[r][c]) - 1;
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            let idx: number = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
}
```

</details>

<br>

## Approach 3: Bitmasking

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int N = 9;
    // Use binary number to check previous occurrence
    unsigned int rows[9] = {0};
    unsigned int cols[9] = {0};
    unsigned int boxes[9] = {0};
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // Check if the position is filled with number
            if (board[r][c] == '.') {
                continue;
            }
            int val = board[r][c] - '0';
            unsigned int pos = 1 << (val - 1);
            // Check the row
            if (rows[r] & pos) {
                return false;
            }
            rows[r] |= pos;
            // Check the column
            if (cols[c] & pos) {
                return false;
            }
            cols[c] |= pos;
            // Check the box
            int idx = (r / 3) * 3 + c / 3;
            if (boxes[idx] & pos) {
                return false;
            }
            boxes[idx] |= pos;
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        // Use a binary number to record previous occurrence
        int rows[N] = {0};
        int cols[N] = {0};
        int boxes[N] = {0};
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);
                // Check the row
                if ((rows[r] & pos) > 0) {
                    return false;
                }
                rows[r] |= pos;
                // Check the column
                if ((cols[c] & pos) > 0) {
                    return false;
                }
                cols[c] |= pos;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) {
                    return false;
                }
                boxes[idx] |= pos;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int N = 9;
        // Use a binary number to record previous occurrence
        int[] rows = new int[N];
        int[] cols = new int[N];
        int[] boxes = new int[N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }

                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);
                // Check the row
                if ((rows[r] & pos) > 0) {
                    return false;
                }

                rows[r] |= pos;
                // Check the column
                if ((cols[c] & pos) > 0) {
                    return false;
                }

                cols[c] |= pos;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) {
                    return false;
                }

                boxes[idx] |= pos;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isValidSudoku(board [][]byte) bool {
    N := 9
    // Use binary number to check previous occurrence
    var rows [9]int
    var cols [9]int
    var boxes [9]int
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            // Check if the position is filled with number
            if board[r][c] == '.' {
                continue
            }
            val := int(board[r][c] - '0')
            pos := 1 << (val - 1)
            // Check the row
            if rows[r]&pos != 0 {
                return false
            }
            rows[r] |= pos
            // Check the column
            if cols[c]&pos != 0 {
                return false
            }
            cols[c] |= pos
            // Check the box
            idx := (r/3)*3 + c/3
            if boxes[idx]&pos != 0 {
                return false
            }
            boxes[idx] |= pos
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N = 9;

        // Use a binary number to record previous occurrence
        int[] rows = new int[N];
        int[] cols = new int[N];
        int[] boxes = new int[N];

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);

                // Check the row
                if ((rows[r] & pos) > 0) {
                    return false;
                }
                rows[r] |= pos;

                // Check the column
                if ((cols[c] & pos) > 0) {
                    return false;
                }
                cols[c] |= pos;

                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) {
                    return false;
                }
                boxes[idx] |= pos;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidSudoku = function (board) {
    let N = 9;
    // Use a binary number to record previous occurrence
    let rows = Array(N).fill(0);
    let cols = Array(N).fill(0);
    let boxes = Array(N).fill(0);
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            // Check if the position is filled with number
            if (board[r][c] === ".") {
                continue;
            }
            let pos = 1 << (Number(board[r][c]) - 1);
            // Check the row
            if (rows[r] & pos) {
                return false;
            }
            rows[r] |= pos;
            // Check the column
            if (cols[c] & pos) {
                return false;
            }
            cols[c] |= pos;
            // Check the box
            let idx = parseInt(r / 3) * 3 + parseInt(c / 3);
            if (boxes[idx] & pos) {
                return false;
            }
            boxes[idx] |= pos;
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        N = 9
        # Use binary number to check previous occurrence
        rows = [0] * N
        cols = [0] * N
        boxes = [0] * N

        for r in range(N):
            for c in range(N):
                # Check if the position is filled with number
                if board[r][c] == ".":
                    continue

                pos = int(board[r][c]) - 1

                # Check the row
                if rows[r] & (1 << pos):
                    return False
                rows[r] |= 1 << pos

                # Check the column
                if cols[c] & (1 << pos):
                    return False
                cols[c] |= 1 << pos

                # Check the box
                idx = (r // 3) * 3 + c // 3
                if boxes[idx] & (1 << pos):
                    return False
                boxes[idx] |= 1 << pos

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidSudoku(board: string[][]): boolean {
    let N = 9;
    // Use binary number to record previous occurrence
    let rows = Array(N).fill(0);
    let cols = Array(N).fill(0);
    let boxes = Array(N).fill(0);
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            // Check if the position is filled with number
            if (board[r][c] === ".") {
                continue;
            }
            let pos = 1 << (Number(board[r][c]) - 1);
            // Check the row
            if (rows[r] & pos) {
                return false;
            }
            rows[r] |= pos;
            // Check the column
            if (cols[c] & pos) {
                return false;
            }
            cols[c] |= pos;
            // Check the box
            let idx = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx] & pos) {
                return false;
            }
            boxes[idx] |= pos;
        }
    }
    return true;
}
```

</details>
