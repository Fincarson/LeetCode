# 79. Word Search

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/word-search/)  
`Array` `String` `Backtracking` `Depth-First Search` `Matrix`

**Problem Link:** [LeetCode 79 - Word Search](https://leetcode.com/problems/word-search/)

## Problem

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Example 1

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

### Example 2

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

### Example 3

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

## Constraints

- m == board.length
- n = board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Search II](https://leetcode.com/problems/word-search-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 79. Word Search

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
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int ROWS = boardSize;
    int COLS = *boardColSize;
    bool backtrack(int row, int col, char* suffix) {
        /* Step 1). check the bottom case. */
        if (strlen(suffix) == 0) return true;
        /* Step 2). Check the boundaries. */
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != suffix[0])
            return false;
        /* Step 3). explore the neighbors in DFS */
        bool ret = false;
        // mark the path before the next exploration
        board[row][col] = '#';
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int d = 0; d < 4; ++d) {
            ret = backtrack(row + directions[d][0], col + directions[d][1],
                            suffix + 1);
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = suffix[0];
        return ret;
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (backtrack(row, col, word)) return true;
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    vector<vector<char>> board;
    int ROWS;
    int COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        ROWS = board.size();
        COLS = board[0].size();
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                if (backtrack(row, col, word, 0)) return true;
        return false;
    }

protected:
    bool backtrack(int row, int col, const string& word, int index) {
        /* Step 1). check the bottom case. */
        if (index >= word.length()) return true;
        /* Step 2). Check the boundaries. */
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != word[index])
            return false;
        /* Step 3). explore the neighbors in DFS */
        bool ret = false;
        // mark the path before the next exploration
        board[row][col] = '#';
        int rowOffsets[4] = {0, 1, 0, -1};
        int colOffsets[4] = {1, 0, -1, 0};
        for (int d = 0; d < 4; ++d) {
            ret = backtrack(row + rowOffsets[d], col + colOffsets[d], word,
                            index + 1);
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = word[index];
        return ret;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private char[][] board;
    private int rows;
    private int cols;

    public bool Exist(char[][] board, string word) {
        this.board = board;
        this.rows = board.Length;
        this.cols = board[0].Length;

        for (int row = 0; row < this.rows; row++) {
            for (int col = 0; col < this.cols; col++) {
                if (Backtrack(row, col, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private bool Backtrack(int row, int col, string word, int index) {
        // Step 1: Check if the last character matches
        if (index >= word.Length) {
            return true;
        }

        // Step 2: Check boundaries
        if (row < 0 || row == this.rows || col < 0 || col == this.cols ||
            this.board[row][col] != word[index]) {
            return false;
        }

        // Step 3: Explore the neighbors in DFS
        bool ret = false;
        // Mark the path before the next exploration
        char temp = this.board[row][col];
        this.board[row][col] = '#';

        int[] rowOffsets = { 0, 1, 0, -1 };
        int[] colOffsets = { 1, 0, -1, 0 };
        for (int d = 0; d < 4; d++) {
            ret = Backtrack(row + rowOffsets[d], col + colOffsets[d], word,
                            index + 1);
            if (ret)
                break;
        }

        // Step 4: Clean up and return false
        this.board[row][col] = temp;
        return ret;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func exist(board [][]byte, word string) bool {
    rows := len(board)
    if rows == 0 {
        return false
    }
    cols := len(board[0])

    var backtrack func(row int, col int, index int) bool
    backtrack = func(row int, col int, index int) bool {
        /* Step 1). check the bottom case. */
        if index == len(word) {
            return true
        }
        /* Step 2). Check the boundaries. */
        if row < 0 || row >= rows || col < 0 || col >= cols ||
            board[row][col] != word[index] {
            return false
        }

        /* Step 3). explore the neighbors in DFS */
        ret := false
        temp := board[row][col]
        // mark the path before the next exploration
        board[row][col] = '#'
        rowOffsets := []int{0, 1, 0, -1}
        colOffsets := []int{1, 0, -1, 0}

        for d := 0; d < 4; d++ {
            ret = backtrack(row+rowOffsets[d], col+colOffsets[d], index+1)
            if ret {
                break
            }
        }

        // Unmark the cell as visited
        board[row][col] = temp
        return ret
    }

    for row := 0; row < rows; row++ {
        for col := 0; col < cols; col++ {
            if board[row][col] == word[0] && backtrack(row, col, 0) {
                return true
            }
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private char[][] board;
    private int ROWS;
    private int COLS;

    public boolean exist(char[][] board, String word) {
        this.board = board;
        this.ROWS = board.length;
        this.COLS = board[0].length;

        for (int row = 0; row < this.ROWS; ++row) for (
            int col = 0;
            col < this.COLS;
            ++col
        ) if (this.backtrack(row, col, word, 0)) return true;
        return false;
    }

    protected boolean backtrack(int row, int col, String word, int index) {
        /* Step 1). check the bottom case. */
        if (index >= word.length()) return true;

        /* Step 2). Check the boundaries. */
        if (
            row < 0 ||
            row == this.ROWS ||
            col < 0 ||
            col == this.COLS ||
            this.board[row][col] != word.charAt(index)
        ) return false;

        /* Step 3). explore the neighbors in DFS */
        boolean ret = false;
        // mark the path before the next exploration
        this.board[row][col] = '#';

        int[] rowOffsets = { 0, 1, 0, -1 };
        int[] colOffsets = { 1, 0, -1, 0 };
        for (int d = 0; d < 4; ++d) {
            ret = this.backtrack(
                    row + rowOffsets[d],
                    col + colOffsets[d],
                    word,
                    index + 1
                );
            if (ret) break;
        }

        /* Step 4). clean up and return the result. */
        this.board[row][col] = word.charAt(index);
        return ret;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var exist = function (board, word) {
    const ROWS = board.length;
    const COLS = board[0].length;
    const backtrack = function (row, col, suffix) {
        /* Step 1). check the bottom case. */
        if (suffix.length == 0) return true;
        /* Step 2). Check the boundaries. */
        if (
            row < 0 ||
            row == ROWS ||
            col < 0 ||
            col == COLS ||
            board[row][col] != suffix.charAt(0)
        )
            return false;
        /* Step 3). explore the neighbors in DFS */
        let ret = false;
        // mark the path before the next exploration
        board[row][col] = "#";
        const directions = [
            [0, 1],
            [1, 0],
            [0, -1],
            [-1, 0],
        ];
        for (let [rowOffset, colOffset] of directions) {
            ret = backtrack(row + rowOffset, col + colOffset, suffix.slice(1));
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = suffix.charAt(0);
        return ret;
    };

    for (let row = 0; row < ROWS; ++row) {
        for (let col = 0; col < COLS; ++col) {
            if (backtrack(row, col, word)) return true;
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.ROWS = len(board)
        self.COLS = len(board[0])
        self.board = board

        for row in range(self.ROWS):
            for col in range(self.COLS):
                if self.backtrack(row, col, word):
                    return True

        # no match found after all exploration
        return False

    def backtrack(self, row: int, col: int, suffix: str) -> bool:
        # bottom case: we find match for each letter in the word
        if len(suffix) == 0:
            return True

        # Check the current status, before jumping into backtracking
        if (
            row < 0
            or row == self.ROWS
            or col < 0
            or col == self.COLS
            or self.board[row][col] != suffix[0]
        ):
            return False

        ret = False
        # mark the choice before exploring further.
        self.board[row][col] = "#"
        # explore the 4 neighbor directions
        for rowOffset, colOffset in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ret = self.backtrack(row + rowOffset, col + colOffset, suffix[1:])
            # break instead of return directly to do some cleanup afterwards
            if ret:
                break

        # revert the change, a clean slate and no side-effect
        self.board[row][col] = suffix[0]

        # Tried all directions, and did not find any match
        return ret
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function exist(board: string[][], word: string): boolean {
    const ROWS = board.length;
    const COLS = board[0].length;
    function backtrack(row: number, col: number, suffix: string): boolean {
        /* Step 1). check the bottom case. */
        if (suffix.length == 0) return true;
        /* Step 2). Check the boundaries. */
        if (
            row < 0 ||
            row == ROWS ||
            col < 0 ||
            col == COLS ||
            board[row][col] != suffix.charAt(0)
        )
            return false;
        /* Step 3). explore the neighbors in DFS */
        let ret = false;
        // mark the path before the next exploration
        const temp = board[row][col];
        board[row][col] = "#";
        const directions = [
            [0, 1],
            [1, 0],
            [0, -1],
            [-1, 0],
        ];
        for (let [rowOffset, colOffset] of directions) {
            ret = backtrack(row + rowOffset, col + colOffset, suffix.slice(1));
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = temp;
        return ret;
    }

    for (let row = 0; row < ROWS; ++row) {
        for (let col = 0; col < COLS; ++col) {
            if (backtrack(row, col, word)) return true;
        }
    }
    return false;
}
```

</details>
