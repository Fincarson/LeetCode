# 1895. Largest Magic Square

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/largest-magic-square/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 1895 - Largest Magic Square](https://leetcode.com/problems/largest-magic-square/)

## Problem

A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

### Example 1

```text
Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
```

### Example 2

```text
Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- 1 <= grid[i][j] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Magic Squares In Grid](https://leetcode.com/problems/magic-squares-in-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1895. Largest Magic Square

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumerating Squares + Prefix Sum Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumerating Squares + Prefix Sum Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    // prefix sum of each row
    int** rowsum = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        rowsum[i] = (int*)malloc(n * sizeof(int));
        rowsum[i][0] = grid[i][0];
        for (int j = 1; j < n; ++j) {
            rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
        }
    }
    // prefix sum of each column
    int** colsum = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        colsum[i] = (int*)malloc(n * sizeof(int));
    }
    for (int j = 0; j < n; ++j) {
        colsum[0][j] = grid[0][j];
        for (int i = 1; i < m; ++i) {
            colsum[i][j] = colsum[i - 1][j] + grid[i][j];
        }
    }

    int min_edge = m < n ? m : n;
    // enumerate edge lengths from largest to smallest
    for (int edge = min_edge; edge >= 2; --edge) {
        // enumerate the top-left corner position (i,j) of the square
        for (int i = 0; i + edge <= m; ++i) {
            for (int j = 0; j + edge <= n; ++j) {
                // calculate the standard value
                int stdsum =
                    rowsum[i][j + edge - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                int check = 1;
                // check each row
                for (int ii = i + 1; ii < i + edge; ++ii) {
                    int sum = rowsum[ii][j + edge - 1] -
                              (j > 0 ? rowsum[ii][j - 1] : 0);
                    if (sum != stdsum) {
                        check = 0;
                        break;
                    }
                }
                if (!check) continue;
                // check each column
                for (int jj = j; jj < j + edge; ++jj) {
                    int sum = colsum[i + edge - 1][jj] -
                              (i > 0 ? colsum[i - 1][jj] : 0);
                    if (sum != stdsum) {
                        check = 0;
                        break;
                    }
                }
                if (!check) continue;
                // check the diagonal
                int d1 = 0, d2 = 0;
                for (int k = 0; k < edge; ++k) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + k][j + edge - 1 - k];
                }
                if (d1 == stdsum && d2 == stdsum) {
                    // release memory
                    for (int i = 0; i < m; ++i) {
                        free(rowsum[i]);
                        free(colsum[i]);
                    }
                    free(rowsum);
                    free(colsum);
                    return edge;
                }
            }
        }
    }

    // release memory
    for (int i = 0; i < m; ++i) {
        free(rowsum[i]);
        free(colsum[i]);
    }
    free(rowsum);
    free(colsum);

    return 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // prefix sum of each row
        vector<vector<int>> rowsum(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // prefix sum of each column
        vector<vector<int>> colsum(m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // enumerate edge lengths from largest to smallest
        for (int edge = min(m, n); edge >= 2; --edge) {
            // enumerate the top-left corner position (i,j) of the square
            for (int i = 0; i + edge <= m; ++i) {
                for (int j = 0; j + edge <= n; ++j) {
                    // the value for each row, column, and diagonal should be
                    // calculated (using the first row as a sample)
                    int stdsum =
                        rowsum[i][j + edge - 1] - (j ? rowsum[i][j - 1] : 0);
                    bool check = true;
                    // enumerate each row and directly compute the sum using
                    // prefix sums since we have already used the first line as
                    // a sample, we can skip the first line here.
                    for (int ii = i + 1; ii < i + edge; ++ii) {
                        if (rowsum[ii][j + edge - 1] -
                                (j ? rowsum[ii][j - 1] : 0) !=
                            stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }
                    // enumerate each column and directly calculate the sum
                    // using prefix sums
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (colsum[i + edge - 1][jj] -
                                (i ? colsum[i - 1][jj] : 0) !=
                            stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) {
                        continue;
                    }
                    // d1 and d2 represent the sums of the two diagonals
                    // respectively. here d denotes diagonal
                    int d1 = 0, d2 = 0;
                    // sum directly by traversing without using the prefix sum.
                    for (int k = 0; k < edge; ++k) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }
                    if (d1 == stdsum && d2 == stdsum) {
                        return edge;
                    }
                }
            }
        }

        return 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LargestMagicSquare(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        // prefix sum of each row
        int[][] rowsum = new int [m][];
        for (int i = 0; i < m; ++i) {
            rowsum[i] = new int[n];
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // prefix sum of each column
        int[][] colsum = new int [m][];
        for (int i = 0; i < m; ++i) {
            colsum[i] = new int[n];
        }
        for (int j = 0; j < n; ++j) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // enumerate edge lengths from largest to smallest
        for (int edge = Math.Min(m, n); edge >= 2; --edge) {
            // enumerate the top-left corner position (i,j) of the square
            for (int i = 0; i + edge <= m; ++i) {
                for (int j = 0; j + edge <= n; ++j) {
                    // calculate the standard value
                    int stdsum = rowsum[i][j + edge - 1] -
                                 (j > 0 ? rowsum[i][j - 1] : 0);
                    bool check = true;
                    // check each row
                    for (int ii = i + 1; ii < i + edge; ++ii) {
                        if (rowsum[ii][j + edge - 1] -
                                (j > 0 ? rowsum[ii][j - 1] : 0) !=
                            stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check)
                        continue;
                    // check each column
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (colsum[i + edge - 1][jj] -
                                (i > 0 ? colsum[i - 1][jj] : 0) !=
                            stdsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check)
                        continue;
                    // check the diagonal
                    int d1 = 0, d2 = 0;
                    for (int k = 0; k < edge; ++k) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }
                    if (d1 == stdsum && d2 == stdsum) {
                        return edge;
                    }
                }
            }
        }
        return 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func largestMagicSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	// prefix sum of each row
	rowsum := make([][]int, m)
	for i := 0; i < m; i++ {
		rowsum[i] = make([]int, n)
		rowsum[i][0] = grid[i][0]
		for j := 1; j < n; j++ {
			rowsum[i][j] = rowsum[i][j-1] + grid[i][j]
		}
	}
	// prefix sum of each column
	colsum := make([][]int, m)
	for i := 0; i < m; i++ {
		colsum[i] = make([]int, n)
	}
	for j := 0; j < n; j++ {
		colsum[0][j] = grid[0][j]
		for i := 1; i < m; i++ {
			colsum[i][j] = colsum[i-1][j] + grid[i][j]
		}
	}

	for edge := min(m, n); edge >= 2; edge-- {
		// enumerate the top-left corner position (i,j) of the square
		for i := 0; i+edge <= m; i++ {
			for j := 0; j+edge <= n; j++ {
				// calculate the standard value
				stdsum := rowsum[i][j+edge-1]
				if j > 0 {
					stdsum -= rowsum[i][j-1]
				}
				check := true
				// check each row
				for ii := i + 1; ii < i+edge; ii++ {
					sum := rowsum[ii][j+edge-1]
					if j > 0 {
						sum -= rowsum[ii][j-1]
					}
					if sum != stdsum {
						check = false
						break
					}
				}
				if !check {
					continue
				}
				// check each column
				for jj := j; jj < j+edge; jj++ {
					sum := colsum[i+edge-1][jj]
					if i > 0 {
						sum -= colsum[i-1][jj]
					}
					if sum != stdsum {
						check = false
						break
					}
				}
				if !check {
					continue
				}
				// check the diagonal
				d1, d2 := 0, 0
				for k := 0; k < edge; k++ {
					d1 += grid[i+k][j+k]
					d2 += grid[i+k][j+edge-1-k]
				}
				if d1 == stdsum && d2 == stdsum {
					return edge
				}
			}
		}
	}
	return 1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int largestMagicSquare(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // prefix sum of each row
        int[][] rowsum = new int[m][n];
        for (int i = 0; i < m; ++i) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // prefix sum of each column
        int[][] colsum = new int[m][n];
        for (int j = 0; j < n; ++j) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // enumerate edge lengths from largest to smallest
        for (int edge = Math.min(m, n); edge >= 2; --edge) {
            // enumerate the top-left corner position (i,j) of the square
            for (int i = 0; i + edge <= m; ++i) {
                for (int j = 0; j + edge <= n; ++j) {
                    // the value for each row, column, and diagonal should be calculated (using the first row as a sample)
                    int stdsum =
                        rowsum[i][j + edge - 1] -
                        (j > 0 ? rowsum[i][j - 1] : 0);
                    boolean check = true;
                    // enumerate each row and directly compute the sum using prefix sums
                    for (int ii = i + 1; ii < i + edge; ++ii) {
                        if (
                            rowsum[ii][j + edge - 1] -
                                (j > 0 ? rowsum[ii][j - 1] : 0) !=
                            stdsum
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    // enumerate each column and directly calculate the sum using prefix sums
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (
                            colsum[i + edge - 1][jj] -
                                (i > 0 ? colsum[i - 1][jj] : 0) !=
                            stdsum
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    // Ã¤Â¸Â¤Ã¦ÂÂ¡Ã¥Â¯Â¹Ã¨Â§â€™Ã§ÂºÂ¿Ã§Å¡â€žÃ¥â€™Å’
                    int d1 = 0;
                    int d2 = 0;
                    for (int k = 0; k < edge; ++k) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }
                    if (d1 == stdsum && d2 == stdsum) {
                        return edge;
                    }
                }
            }
        }
        return 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var largestMagicSquare = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    // prefix sum of each row
    const rowsum = Array.from({ length: m }, () => new Array(n));
    for (let i = 0; i < m; ++i) {
        rowsum[i][0] = grid[i][0];
        for (let j = 1; j < n; ++j) {
            rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
        }
    }
    // prefix sum of each column
    const colsum = Array.from({ length: m }, () => new Array(n));
    for (let j = 0; j < n; ++j) {
        colsum[0][j] = grid[0][j];
        for (let i = 1; i < m; ++i) {
            colsum[i][j] = colsum[i - 1][j] + grid[i][j];
        }
    }

    // enumerate edge lengths from largest to smallest
    for (let edge = Math.min(m, n); edge >= 2; --edge) {
        // enumerate the top-left corner position (i,j) of the square
        for (let i = 0; i + edge <= m; ++i) {
            for (let j = 0; j + edge <= n; ++j) {
                // calculate the standard value
                let stdsum =
                    rowsum[i][j + edge - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                let check = true;
                // check each row
                for (let ii = i + 1; ii < i + edge; ++ii) {
                    let sum =
                        rowsum[ii][j + edge - 1] -
                        (j > 0 ? rowsum[ii][j - 1] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check each column
                for (let jj = j; jj < j + edge; ++jj) {
                    let sum =
                        colsum[i + edge - 1][jj] -
                        (i > 0 ? colsum[i - 1][jj] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check the diagonal
                let d1 = 0,
                    d2 = 0;
                for (let k = 0; k < edge; ++k) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + k][j + edge - 1 - k];
                }
                if (d1 === stdsum && d2 === stdsum) {
                    return edge;
                }
            }
        }
    }
    return 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        # prefix sum of each row
        rowsum = [[0] * n for _ in range(m)]
        for i in range(m):
            rowsum[i][0] = grid[i][0]
            for j in range(1, n):
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j]

        # prefix sum of each column
        colsum = [[0] * n for _ in range(m)]
        for j in range(n):
            colsum[0][j] = grid[0][j]
            for i in range(1, m):
                colsum[i][j] = colsum[i - 1][j] + grid[i][j]

        # enumerate edge lengths from largest to smallest
        for edge in range(min(m, n), 1, -1):
            # enumerate the top-left corner position (i,j) of the square
            for i in range(m - edge + 1):
                for j in range(n - edge + 1):
                    # the value for each row, column, and diagonal should be calculated (using the first row as a sample)
                    stdsum = rowsum[i][j + edge - 1] - (
                        0 if j == 0 else rowsum[i][j - 1]
                    )
                    check = True
                    # enumerate each row and directly compute the sum using prefix sums
                    # since we have already used the first line as a sample, we can skip the first line here.
                    for ii in range(i + 1, i + edge):
                        if (
                            rowsum[ii][j + edge - 1]
                            - (0 if j == 0 else rowsum[ii][j - 1])
                            != stdsum
                        ):
                            check = False
                            break
                    if not check:
                        continue

                    # enumerate each column and directly calculate the sum using prefix sums
                    for jj in range(j, j + edge):
                        if (
                            colsum[i + edge - 1][jj]
                            - (0 if i == 0 else colsum[i - 1][jj])
                            != stdsum
                        ):
                            check = False
                            break
                    if not check:
                        continue

                    # d1 and d2 represent the sums of the two diagonals respectively.
                    # here d denotes diagonal
                    d1 = d2 = 0
                    # sum directly by traversing without using the prefix sum.
                    for k in range(edge):
                        d1 += grid[i + k][j + k]
                        d2 += grid[i + k][j + edge - 1 - k]
                    if d1 == stdsum and d2 == stdsum:
                        return edge

        return 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function largestMagicSquare(grid: number[][]): number {
    const m = grid.length,
        n = grid[0].length;
    // prefix sum of each row
    const rowsum: number[][] = Array.from({ length: m }, () => new Array(n));
    for (let i = 0; i < m; ++i) {
        rowsum[i][0] = grid[i][0];
        for (let j = 1; j < n; ++j) {
            rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
        }
    }
    // prefix sum of each column
    const colsum: number[][] = Array.from({ length: m }, () => new Array(n));
    for (let j = 0; j < n; ++j) {
        colsum[0][j] = grid[0][j];
        for (let i = 1; i < m; ++i) {
            colsum[i][j] = colsum[i - 1][j] + grid[i][j];
        }
    }

    // enumerate edge lengths from largest to smallest
    for (let edge = Math.min(m, n); edge >= 2; --edge) {
        // enumerate the top-left corner position (i,j) of the square
        for (let i = 0; i + edge <= m; ++i) {
            for (let j = 0; j + edge <= n; ++j) {
                // calculate the standard value
                const stdsum =
                    rowsum[i][j + edge - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                let check = true;
                // check each row
                for (let ii = i + 1; ii < i + edge; ++ii) {
                    const sum =
                        rowsum[ii][j + edge - 1] -
                        (j > 0 ? rowsum[ii][j - 1] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check each column
                for (let jj = j; jj < j + edge; ++jj) {
                    const sum =
                        colsum[i + edge - 1][jj] -
                        (i > 0 ? colsum[i - 1][jj] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check the diagonal
                let d1 = 0,
                    d2 = 0;
                for (let k = 0; k < edge; ++k) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + k][j + edge - 1 - k];
                }
                if (d1 === stdsum && d2 === stdsum) {
                    return edge;
                }
            }
        }
    }
    return 1;
}
```

</details>
