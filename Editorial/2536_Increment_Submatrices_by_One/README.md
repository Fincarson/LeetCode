# 2536. Increment Submatrices by One

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/increment-submatrices-by-one/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 2536 - Increment Submatrices by One](https://leetcode.com/problems/increment-submatrices-by-one/)

## Problem

You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

- Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.

Return the matrix mat after performing every query.

### Example 1

```text
Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
Output: [[1,1,0],[1,2,1],[0,1,1]]
Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
```

### Example 2

```text
Input: n = 2, queries = [[0,0,1,1]]
Output: [[1,1],[1,1]]
Explanation: The diagram above shows the initial matrix and the matrix after the first query.
- In the first query we add 1 to every element in the matrix.
```

## Constraints

- 1 <= n <= 500
- 1 <= queries.length <= 104
- 0 <= row1i <= row2i < n
- 0 <= col1i <= col2i < n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Positions on Street With Required Brightness](https://leetcode.com/problems/count-positions-on-street-with-required-brightness/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2536. Increment Submatrices by One

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: 2D Difference + Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: 2D Difference + Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** rangeAddQueries(int n, int** queries, int queriesSize,
                      int* queriesColSize, int* returnSize,
                      int** returnColumnSizes) {
    int diff[n + 1][n + 1] = {};
    for (int k = 0; k < queriesSize; k++) {
        int row1 = queries[k][0], col1 = queries[k][1], row2 = queries[k][2],
            col2 = queries[k][3];
        diff[row1][col1] += 1;
        diff[row2 + 1][col1] -= 1;
        diff[row1][col2 + 1] -= 1;
        diff[row2 + 1][col2 + 1] += 1;
    }

    int** mat = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x1 = (i == 0) ? 0 : mat[i - 1][j];
            int x2 = (j == 0) ? 0 : mat[i][j - 1];
            int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
            mat[i][j] = diff[i][j] + x1 + x2 - x3;
        }
    }
    return mat;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector diff(n + 1, vector<int>(n + 1));
        for (const auto& query : queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }
        vector mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] RangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int [n + 1][];
        for (int i = 0; i <= n; i++) {
            diff[i] = new int[n + 1];
        }

        foreach (var q in queries) {
            int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }

        int[][] mat = new int [n][];
        for (int i = 0; i < n; i++) {
            mat[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func rangeAddQueries(n int, queries [][]int) [][]int {
	diff := make([][]int, n+1)
	for i := range diff {
		diff[i] = make([]int, n+1)
	}

	for _, q := range queries {
		row1, col1, row2, col2 := q[0], q[1], q[2], q[3]
		diff[row1][col1] += 1
		diff[row2+1][col1] -= 1
		diff[row1][col2+1] -= 1
		diff[row2+1][col2+1] += 1
	}

	mat := make([][]int, n)
	for i := range mat {
		mat[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			x1 := 0
			if i > 0 {
				x1 = mat[i-1][j]
			}
			x2 := 0
			if j > 0 {
				x2 = mat[i][j-1]
			}
			x3 := 0
			if i > 0 && j > 0 {
				x3 = mat[i-1][j-1]
			}
			mat[i][j] = diff[i][j] + x1 + x2 - x3
		}
	}
	return mat
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int[n + 1][n + 1];
        for (int[] q : queries) {
            int row1 = q[0];
            int col1 = q[1];
            int row2 = q[2];
            int col2 = q[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }

        int[][] mat = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var rangeAddQueries = function (n, queries) {
    let diff = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    for (let [row1, col1, row2, col2] of queries) {
        diff[row1][col1] += 1;
        diff[row2 + 1][col1] -= 1;
        diff[row1][col2 + 1] -= 1;
        diff[row2 + 1][col2 + 1] += 1;
    }

    let mat = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let x1 = i === 0 ? 0 : mat[i - 1][j];
            let x2 = j === 0 ? 0 : mat[i][j - 1];
            let x3 = i === 0 || j === 0 ? 0 : mat[i - 1][j - 1];
            mat[i][j] = diff[i][j] + x1 + x2 - x3;
        }
    }
    return mat;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rangeAddQueries(
        self, n: int, queries: List[List[int]]
    ) -> List[List[int]]:
        diff = [[0] * (n + 1) for _ in range(n + 1)]
        for row1, col1, row2, col2 in queries:
            diff[row1][col1] += 1
            diff[row2 + 1][col1] -= 1
            diff[row1][col2 + 1] -= 1
            diff[row2 + 1][col2 + 1] += 1

        mat = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                x1 = 0 if i == 0 else mat[i - 1][j]
                x2 = 0 if j == 0 else mat[i][j - 1]
                x3 = 0 if i == 0 or j == 0 else mat[i - 1][j - 1]
                mat[i][j] = diff[i][j] + x1 + x2 - x3
        return mat
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rangeAddQueries(n: number, queries: number[][]): number[][] {
    let diff: number[][] = Array.from({ length: n + 1 }, () =>
        Array(n + 1).fill(0),
    );
    for (let [row1, col1, row2, col2] of queries) {
        diff[row1][col1] += 1;
        diff[row2 + 1][col1] -= 1;
        diff[row1][col2 + 1] -= 1;
        diff[row2 + 1][col2 + 1] += 1;
    }

    let mat: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let x1 = i === 0 ? 0 : mat[i - 1][j];
            let x2 = j === 0 ? 0 : mat[i][j - 1];
            let x3 = i === 0 || j === 0 ? 0 : mat[i - 1][j - 1];
            mat[i][j] = diff[i][j] + x1 + x2 - x3;
        }
    }
    return mat;
}
```

</details>
