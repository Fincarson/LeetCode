# 73. Set Matrix Zeroes

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/set-matrix-zeroes/)  
`Array` `Hash Table` `Matrix`

**Problem Link:** [LeetCode 73 - Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

## Problem

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

### Example 1

```text
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

### Example 2

```text
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## Constraints

- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -231 <= matrix[i][j] <= 231 - 1

Follow up:

- A straightforward solution using O(mn) space is probably a bad idea.
- A simple improvement uses O(m + n) space, but still not the best solution.
- Could you devise a constant space solution?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game of Life](https://leetcode.com/problems/game-of-life/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Number of Laser Beams in a Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Remove Adjacent Ones in Matrix](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Remove All Ones With Row and Column Flips II](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 73. Set Matrix Zeroes

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Additional Memory Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| O(1) Space, Efficient Solution | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Additional Memory Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int R = matrixSize;
    int C = *matrixColSize;
    int rows[R], cols[C];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    // Essentially, we mark the rows and columns that are to be made zero
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets,
    // update the elements
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (rows[i] == 1 || cols[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        set<int> rows;
        set<int> cols;
        // Essentially, we mark the rows and columns that are to be made zero
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        // Iterate over the array once again and using the rows and cols sets,
        // update the elements.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                    matrix[i][j] = 0;
                }
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
    public void SetZeroes(int[][] matrix) {
        int R = matrix.Length;
        int C = matrix[0].Length;
        HashSet<int> rows = new HashSet<int>();
        HashSet<int> cols = new HashSet<int>();
        // Essentially, we mark the rows and columns that are to be made zero
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 0) {
                    rows.Add(i);
                    cols.Add(j);
                }
            }
        }

        // Iterate over the array once again and using the rows and cols sets,
        // update the elements.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rows.Contains(i) || cols.Contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func setZeroes(matrix [][]int) {
    rows := make(map[int]bool)
    cols := make(map[int]bool)
    // Essentially, we mark the rows and columns that are to be made zero
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if matrix[i][j] == 0 {
                rows[i] = true
                cols[j] = true
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets, update the elements
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if rows[i] || cols[j] {
                matrix[i][j] = 0
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int R = matrix.length;
        int C = matrix[0].length;
        Set<Integer> rows = new HashSet<Integer>();
        Set<Integer> cols = new HashSet<Integer>();

        // Essentially, we mark the rows and columns that are to be made zero
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 0) {
                    rows.add(i);
                    cols.add(j);
                }
            }
        }

        // Iterate over the array once again and using the rows and cols sets, update the elements.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rows.contains(i) || cols.contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var setZeroes = function (matrix) {
    const rows = new Set();
    const cols = new Set();
    // Essentially, we mark the rows and columns that are to be made zero
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] == 0) {
                rows.add(i);
                cols.add(j);
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets, update the elements
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (rows.has(i) || cols.has(j)) {
                matrix[i][j] = 0;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def setZeroes(self, matrix: List[List[int]]) -> None:
        R = len(matrix)
        C = len(matrix[0])
        rows, cols = set(), set()

        # Essentially, we mark the rows and columns that are to be made zero
        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)

        # Iterate over the array once again and using the rows and cols sets, update the elements
        for i in range(R):
            for j in range(C):
                if i in rows or j in cols:
                    matrix[i][j] = 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function setZeroes(matrix: number[][]): void {
    const rows = new Set<number>();
    const cols = new Set<number>();
    // Essentially, we mark the rows and columns that are to be made zero
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === 0) {
                rows.add(i);
                cols.add(j);
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets, update the elements
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (rows.has(i) || cols.has(j)) {
                matrix[i][j] = 0;
            }
        }
    }
}
```

</details>

<br>

## Approach 2: O(1) Space, Efficient Solution

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    _Bool isCol = 0;
    int R = matrixSize;
    int C = matrixColSize[0];
    for (int i = 0; i < R; i++) {
        if (matrix[i][0] == 0) {
            isCol = 1;
        }
        for (int j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int j = 0; j < C; j++) {
            matrix[0][j] = 0;
        }
    }
    if (isCol) {
        for (int i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();
        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
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
    public void SetZeroes(int[][] matrix) {
        bool isCol = false;
        int R = matrix.Length;
        int C = matrix[0].Length;
        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }

        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func setZeroes(matrix [][]int) {
    isCol := false
    R := len(matrix)
    C := len(matrix[0])
    for i := 0; i < R; i++ {
        if matrix[i][0] == 0 {
            isCol = true
        }
        for j := 1; j < C; j++ {
            if matrix[i][j] == 0 {
                matrix[0][j] = 0
                matrix[i][0] = 0
            }
        }
    }
    for i := 1; i < R; i++ {
        for j := 1; j < C; j++ {
            if matrix[i][0] == 0 || matrix[0][j] == 0 {
                matrix[i][j] = 0
            }
        }
    }
    if matrix[0][0] == 0 {
        for j := 0; j < C; j++ {
            matrix[0][j] = 0
        }
    }
    if isCol {
        for i := 0; i < R; i++ {
            matrix[i][0] = 0
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        Boolean isCol = false;
        int R = matrix.length;
        int C = matrix[0].length;

        for (int i = 0; i < R; i++) {
            // Since first cell for both first row and first column is the same i.e. matrix[0][0]
            // We can use an additional variable for either the first row/column.
            // For this solution we are using an additional variable for the first column
            // and using matrix[0][0] for the first row.
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j = 1; j < C; j++) {
                // If an element is zero, we set the first element of the corresponding row and column to 0
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Iterate over the array once again and using the first row and first column, update the elements.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var setZeroes = function (matrix) {
    let isCol = false;
    let R = matrix.length;
    let C = matrix[0].length;
    for (let i = 0; i < R; i++) {
        if (matrix[i][0] == 0) {
            isCol = true;
        }
        for (let j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (let j = 0; j < C; j++) {
            matrix[0][j] = 0;
        }
    }
    if (isCol) {
        for (let i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def setZeroes(self, matrix: List[List[int]]) -> None:
        is_col = False
        R = len(matrix)
        C = len(matrix[0])
        for i in range(R):
            # Since first cell for both first row and first column is the same i.e. matrix[0][0]
            # We can use an additional variable for either the first row/column.
            # For this solution we are using an additional variable for the first column
            # and using matrix[0][0] for the first row.
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                # If an element is zero, we set the first element of the corresponding row and column to 0
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        # Iterate over the array once again and using the first row and first column, update the elements.
        for i in range(1, R):
            for j in range(1, C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0

        # See if the first row needs to be set to zero as well
        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0

        # See if the first column needs to be set to zero as well
        if is_col:
            for i in range(R):
                matrix[i][0] = 0
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function setZeroes(matrix: number[][]): void {
    let isCol = false;
    const R = matrix.length;
    const C = matrix[0].length;
    for (let i = 0; i < R; i++) {
        if (matrix[i][0] == 0) {
            isCol = true;
        }
        for (let j = 1; j < C; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (let j = 0; j < C; j++) {
            matrix[0][j] = 0;
        }
    }
    if (isCol) {
        for (let i = 0; i < R; i++) {
            matrix[i][0] = 0;
        }
    }
}
```

</details>
