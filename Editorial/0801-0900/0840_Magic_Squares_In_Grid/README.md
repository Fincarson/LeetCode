# 840. Magic Squares In Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/magic-squares-in-grid/)  
`Array` `Hash Table` `Math` `Matrix`

**Problem Link:** [LeetCode 840 - Magic Squares In Grid](https://leetcode.com/problems/magic-squares-in-grid/)

## Problem

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

### Example 1

```text
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation:
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
```

### Example 2

```text
Input: grid = [[8]]
Output: 0
```

## Constraints

- row == grid.length
- col == grid[i].length
- 1 <= row, col <= 10
- 0 <= grid[i][j] <= 15

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Largest Magic Square](https://leetcode.com/problems/largest-magic-square/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 840. Magic Squares In Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Manual Scan | C++, Java, Python3 |
| Check Unique Properties of Magic Square | C++, Java, Python3 |

## Approach 1: Manual Scan

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        bool seen[10] = {false};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9) return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }

        // Check if diagonal sums are the same
        int diagonal1 =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 =
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        if (diagonal1 != diagonal2) return false;

        // Check if all row sums are the same as the diagonal sums
        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
                   grid[row + 1][col + 2];
        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
                   grid[row + 2][col + 2];

        if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1)) {
            return false;
        }

        // Check if all column sums are the same as the diagonal sums
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
                   grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
                   grid[row + 2][col + 2];

        if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1)) {
            return false;
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

    public int numMagicSquaresInside(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private boolean isMagicSquare(int[][] grid, int row, int col) {
        boolean[] seen = new boolean[10];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9) return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }

        // check if diagonal sums are same value
        int diagonal1 =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 =
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        if (diagonal1 != diagonal2) return false;

        // check if all row sums share the same value as the diagonal sums
        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 =
            grid[row + 1][col] +
            grid[row + 1][col + 1] +
            grid[row + 1][col + 2];
        int row3 =
            grid[row + 2][col] +
            grid[row + 2][col + 1] +
            grid[row + 2][col + 2];

        if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1)) {
            return false;
        }

        // check if all column sums share same value as the diagonal sums
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 =
            grid[row][col + 1] +
            grid[row + 1][col + 1] +
            grid[row + 2][col + 1];
        int col3 =
            grid[row][col + 2] +
            grid[row + 1][col + 2] +
            grid[row + 2][col + 2];

        if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal2)) {
            return false;
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
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        ans = 0
        m = len(grid)
        n = len(grid[0])
        for row in range(m - 2):
            for col in range(n - 2):
                if self._isMagicSquare(grid, row, col):
                    ans += 1
        return ans

    def _isMagicSquare(self, grid, row, col):
        seen = [False] * 10
        for i in range(3):
            for j in range(3):
                num = grid[row + i][col + j]
                if num < 1 or num > 9:
                    return False
                if seen[num]:
                    return False
                seen[num] = True

        # Check if diagonal sums are the same
        diagonal1 = (
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
        )
        diagonal2 = (
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]
        )

        if diagonal1 != diagonal2:
            return False

        # Check if all row sums are the same as the diagonal sums
        row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
        row2 = (
            grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2]
        )
        row3 = (
            grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2]
        )

        if not (row1 == diagonal1 and row2 == diagonal1 and row3 == diagonal1):
            return False

        # Check if all column sums are the same as the diagonal sums
        col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col]
        col2 = (
            grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1]
        )
        col3 = (
            grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]
        )

        if not (col1 == diagonal1 and col2 == diagonal1 and col3 == diagonal1):
            return False

        return True
```

</details>

<br>

## Approach 2: Check Unique Properties of Magic Square

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // The sequences are each repeated twice to account for
        // the different possible starting points of the sequence
        // in the magic square
        string sequence = "2943816729438167";
        string sequenceReversed = "7618349276183492";

        string border = "";
        // Flattened indices for bordering elements of 3x3 grid
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string(num);
        }

        // Make sure the sequence starts at one of the corners
        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
                (sequence.find(border) != string::npos ||
                 sequenceReversed.find(border) != string::npos));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numMagicSquaresInside(int[][] grid) {
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private boolean isMagicSquare(int[][] grid, int row, int col) {
        // The sequences are each repeated twice to account for
        // the different possible starting points of the sequence
        // in the magic square
        String sequence = "2943816729438167";
        String sequenceReversed = "7618349276183492";

        StringBuilder border = new StringBuilder();
        // Flattened indices for bordering elements of 3x3 grid
        int[] borderIndices = new int[] { 0, 1, 2, 5, 8, 7, 6, 3 };
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border.append(num);
        }

        String borderConverted = border.toString();

        // Make sure the sequence starts at one of the corners
        return (
            grid[row][col] % 2 == 0 &&
            (sequence.contains(borderConverted) ||
                sequenceReversed.contains(borderConverted)) &&
            grid[row + 1][col + 1] == 5
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        ans = 0
        m = len(grid)
        n = len(grid[0])
        for row in range(m - 2):
            for col in range(n - 2):
                if self._isMagicSquare(grid, row, col):
                    ans += 1
        return ans

    def _isMagicSquare(self, grid, row, col):
        # The sequences are each repeated twice to account for
        # the different possible starting points of the sequence
        # in the magic square
        sequence = "2943816729438167"
        sequenceReversed = "7618349276183492"

        border = []
        # Flattened indices for bordering elements of 3x3 grid
        borderIndices = [0, 1, 2, 5, 8, 7, 6, 3]
        for i in borderIndices:
            num = grid[row + i // 3][col + (i % 3)]
            border.append(str(num))

        borderConverted = "".join(border)

        # Make sure the sequence starts at one of the corners
        return (
            grid[row][col] % 2 == 0
            and (
                sequence.find(borderConverted) != -1
                or sequenceReversed.find(borderConverted) != -1
            )
            and grid[row + 1][col + 1] == 5
        )
```

</details>
