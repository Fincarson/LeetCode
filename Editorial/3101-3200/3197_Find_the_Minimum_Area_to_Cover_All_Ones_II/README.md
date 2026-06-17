# 3197. Find the Minimum Area to Cover All Ones II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/)  
`Array` `Matrix` `Enumeration`

**Problem Link:** [LeetCode 3197 - Find the Minimum Area to Cover All Ones II](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/)

## Problem

You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

Return the minimum possible sum of the area of these rectangles.

Note that the rectangles are allowed to touch.

### Example 1

### Example 2

## Constraints

- 1 <= grid.length, grid[i].length <= 30
- grid[i][j] is either 0 or 1.
- The input is generated such that there are at least three 1's in grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3197. Find the Minimum Area to Cover All Ones II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumerate | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumerate

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

int minimumSum2(int** grid, int gridSize, int* gridColSize, int u, int d, int l,
                int r) {
    int min_i = gridSize, max_i = 0;
    int min_j = gridColSize[0], max_j = 0;
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (grid[i][j] == 1) {
                min_i = min(min_i, i);
                min_j = min(min_j, j);
                max_i = max(max_i, i);
                max_j = max(max_j, j);
            }
        }
    }
    return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1)
                          : INT_MAX / 3;
}

int** rotate(int** vec, int vecSize, int* vecColSize, int* returnSize,
             int** returnColSizes) {
    int n = vecSize, m = vecColSize[0];
    *returnSize = m;
    *returnColSizes = (int*)malloc(m * sizeof(int));
    int** ret = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        ret[i] = (int*)malloc(n * sizeof(int));
        (*returnColSizes)[i] = n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret[m - j - 1][i] = vec[i][j];
        }
    }
    return ret;
}

int solve(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int res = n * m;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            res = min(
                res, minimumSum2(grid, n, gridColSize, 0, i, 0, m - 1) +
                         minimumSum2(grid, n, gridColSize, i + 1, n - 1, 0, j) +
                         minimumSum2(grid, n, gridColSize, i + 1, n - 1, j + 1,
                                     m - 1));
            res = min(
                res,
                minimumSum2(grid, n, gridColSize, 0, i, 0, j) +
                    minimumSum2(grid, n, gridColSize, 0, i, j + 1, m - 1) +
                    minimumSum2(grid, n, gridColSize, i + 1, n - 1, 0, m - 1));
        }
    }
    for (int i = 0; i + 2 < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            res = min(
                res,
                minimumSum2(grid, n, gridColSize, 0, i, 0, m - 1) +
                    minimumSum2(grid, n, gridColSize, i + 1, j, 0, m - 1) +
                    minimumSum2(grid, n, gridColSize, j + 1, n - 1, 0, m - 1));
        }
    }
    return res;
}

int minimumSum(int** grid, int gridSize, int* gridColSize) {
    int returnSize;
    int* returnColSizes;
    int** rgrid =
        rotate(grid, gridSize, gridColSize, &returnSize, &returnColSizes);
    int res = min(solve(grid, gridSize, gridColSize),
                  solve(rgrid, returnSize, returnColSizes));
    for (int i = 0; i < returnSize; i++) {
        free(rgrid[i]);
    }
    free(rgrid);
    free(returnColSizes);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int minimumSum(vector<vector<int>> &grid, int u, int d, int l, int r) {
        int min_i = grid.size(), max_i = 0;
        int min_j = grid[0].size(), max_j = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1)
                              : INT_MAX / 3;
    }

    vector<vector<int>> rotate(vector<vector<int>> &vec) {
        int n = vec.size(), m = vec[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        return ret;
    }

    int solve(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res =
                    min(res, minimumSum(grid, 0, i, 0, m - 1) +
                                 minimumSum(grid, i + 1, n - 1, 0, j) +
                                 minimumSum(grid, i + 1, n - 1, j + 1, m - 1));
                res = min(res, minimumSum(grid, 0, i, 0, j) +
                                   minimumSum(grid, 0, i, j + 1, m - 1) +
                                   minimumSum(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = min(res, minimumSum(grid, 0, i, 0, m - 1) +
                                   minimumSum(grid, i + 1, j, 0, m - 1) +
                                   minimumSum(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }

public:
    int minimumSum(vector<vector<int>> &grid) {
        auto rgrid = rotate(grid);
        return min(solve(grid), solve(rgrid));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int MinimumSum2(int[][] grid, int u, int d, int l, int r) {
        int min_i = grid.Length, max_i = 0;
        int min_j = grid[0].Length, max_j = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    min_i = Math.Min(min_i, i);
                    min_j = Math.Min(min_j, j);
                    max_i = Math.Max(max_i, i);
                    max_j = Math.Max(max_j, j);
                }
            }
        }
        return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1)
                              : int.MaxValue / 3;
    }

    private int[][] Rotate(int[][] vec) {
        int n = vec.Length, m = vec[0].Length;
        int[][] ret = new int [m][];
        for (int i = 0; i < m; i++) {
            ret[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        return ret;
    }

    private int Solve(int[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res = Math.Min(
                    res, MinimumSum2(grid, 0, i, 0, m - 1) +
                             MinimumSum2(grid, i + 1, n - 1, 0, j) +
                             MinimumSum2(grid, i + 1, n - 1, j + 1, m - 1));
                res = Math.Min(res,
                               MinimumSum2(grid, 0, i, 0, j) +
                                   MinimumSum2(grid, 0, i, j + 1, m - 1) +
                                   MinimumSum2(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = Math.Min(res,
                               MinimumSum2(grid, 0, i, 0, m - 1) +
                                   MinimumSum2(grid, i + 1, j, 0, m - 1) +
                                   MinimumSum2(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }

    public int MinimumSum(int[][] grid) {
        int[][] rgrid = Rotate(grid);
        return Math.Min(Solve(grid), Solve(rgrid));
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumSum2(grid [][]int, u, d, l, r int) int {
	min_i, max_i := len(grid), 0
	min_j, max_j := len(grid[0]), 0
	for i := u; i <= d; i++ {
		for j := l; j <= r; j++ {
			if grid[i][j] == 1 {
				min_i = min(min_i, i)
				min_j = min(min_j, j)
				max_i = max(max_i, i)
				max_j = max(max_j, j)
			}
		}
	}
	if min_i <= max_i {
		return (max_i - min_i + 1) * (max_j - min_j + 1)
	}
	return math.MaxInt32 / 3
}

func rotate(vec [][]int) [][]int {
	n, m := len(vec), len(vec[0])
	ret := make([][]int, m)
	for i := range ret {
		ret[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			ret[m-j-1][i] = vec[i][j]
		}
	}
	return ret
}

func solve(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	res := n * m
	for i := 0; i+1 < n; i++ {
		for j := 0; j+1 < m; j++ {
			res = min(res, minimumSum2(grid, 0, i, 0, m-1)+
				minimumSum2(grid, i+1, n-1, 0, j)+
				minimumSum2(grid, i+1, n-1, j+1, m-1))
			res = min(res, minimumSum2(grid, 0, i, 0, j)+
				minimumSum2(grid, 0, i, j+1, m-1)+
				minimumSum2(grid, i+1, n-1, 0, m-1))
		}
	}
	for i := 0; i+2 < n; i++ {
		for j := i + 1; j+1 < n; j++ {
			res = min(res, minimumSum2(grid, 0, i, 0, m-1)+
				minimumSum2(grid, i+1, j, 0, m-1)+
				minimumSum2(grid, j+1, n-1, 0, m-1))
		}
	}
	return res
}

func minimumSum(grid [][]int) int {
	rgrid := rotate(grid)
	return min(solve(grid), solve(rgrid))
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int minimumSum2(int[][] grid, int u, int d, int l, int r) {
        int min_i = grid.length;
        int max_i = 0;
        int min_j = grid[0].length;
        int max_j = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    min_i = Math.min(min_i, i);
                    min_j = Math.min(min_j, j);
                    max_i = Math.max(max_i, i);
                    max_j = Math.max(max_j, j);
                }
            }
        }
        return min_i <= max_i
            ? (max_i - min_i + 1) * (max_j - min_j + 1)
            : Integer.MAX_VALUE / 3;
    }

    private int[][] rotate(int[][] vec) {
        int n = vec.length;
        int m = vec[0].length;
        int[][] ret = new int[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        return ret;
    }

    private int solve(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res = Math.min(
                    res,
                    minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, j) +
                    minimumSum2(grid, i + 1, n - 1, j + 1, m - 1)
                );
                res = Math.min(
                    res,
                    minimumSum2(grid, 0, i, 0, j) +
                    minimumSum2(grid, 0, i, j + 1, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, m - 1)
                );
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = Math.min(
                    res,
                    minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, j, 0, m - 1) +
                    minimumSum2(grid, j + 1, n - 1, 0, m - 1)
                );
            }
        }
        return res;
    }

    public int minimumSum(int[][] grid) {
        int[][] rgrid = rotate(grid);
        return Math.min(solve(grid), solve(rgrid));
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumSum = function (grid) {
    const rgrid = rotate(grid);
    return Math.min(solve(grid), solve(rgrid));
};

const minimumSum2 = (grid, u, d, l, r) => {
    let min_i = grid.length,
        max_i = 0;
    let min_j = grid[0].length,
        max_j = 0;
    for (let i = u; i <= d; i++) {
        for (let j = l; j <= r; j++) {
            if (grid[i][j] === 1) {
                min_i = Math.min(min_i, i);
                min_j = Math.min(min_j, j);
                max_i = Math.max(max_i, i);
                max_j = Math.max(max_j, j);
            }
        }
    }
    return min_i <= max_i
        ? (max_i - min_i + 1) * (max_j - min_j + 1)
        : Number.MAX_SAFE_INTEGER / 3;
};

const rotate = (vec) => {
    const n = vec.length,
        m = vec[0].length;
    const ret = new Array(m).fill().map(() => new Array(n));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            ret[m - j - 1][i] = vec[i][j];
        }
    }
    return ret;
};

const solve = (grid) => {
    const n = grid.length,
        m = grid[0].length;
    let res = n * m;
    for (let i = 0; i + 1 < n; i++) {
        for (let j = 0; j + 1 < m; j++) {
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, j) +
                    minimumSum2(grid, i + 1, n - 1, j + 1, m - 1),
            );
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, j) +
                    minimumSum2(grid, 0, i, j + 1, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, m - 1),
            );
        }
    }
    for (let i = 0; i + 2 < n; i++) {
        for (let j = i + 1; j + 1 < n; j++) {
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, j, 0, m - 1) +
                    minimumSum2(grid, j + 1, n - 1, 0, m - 1),
            );
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumSum2(
        self, grid: List[List[int]], u: int, d: int, l: int, r: int
    ) -> int:
        min_i = len(grid)
        max_i = 0
        min_j = len(grid[0])
        max_j = 0

        for i in range(u, d + 1):
            for j in range(l, r + 1):
                if grid[i][j] == 1:
                    min_i = min(min_i, i)
                    min_j = min(min_j, j)
                    max_i = max(max_i, i)
                    max_j = max(max_j, j)

        return (
            (max_i - min_i + 1) * (max_j - min_j + 1)
            if min_i <= max_i
            else sys.maxsize // 3
        )

    def rotate(self, vec: List[List[int]]) -> List[List[int]]:
        n = len(vec)
        m = len(vec[0]) if n > 0 else 0
        ret = [[0] * n for _ in range(m)]

        for i in range(n):
            for j in range(m):
                ret[m - j - 1][i] = vec[i][j]

        return ret

    def solve(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0]) if n > 0 else 0
        res = n * m

        for i in range(n - 1):
            for j in range(m - 1):
                res = min(
                    res,
                    self.minimumSum2(grid, 0, i, 0, m - 1)
                    + self.minimumSum2(grid, i + 1, n - 1, 0, j)
                    + self.minimumSum2(grid, i + 1, n - 1, j + 1, m - 1),
                )

                res = min(
                    res,
                    self.minimumSum2(grid, 0, i, 0, j)
                    + self.minimumSum2(grid, 0, i, j + 1, m - 1)
                    + self.minimumSum2(grid, i + 1, n - 1, 0, m - 1),
                )

        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                res = min(
                    res,
                    self.minimumSum2(grid, 0, i, 0, m - 1)
                    + self.minimumSum2(grid, i + 1, j, 0, m - 1)
                    + self.minimumSum2(grid, j + 1, n - 1, 0, m - 1),
                )

        return res

    def minimumSum(self, grid: List[List[int]]) -> int:
        rgrid = self.rotate(grid)
        return min(self.solve(grid), self.solve(rgrid))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumSum(grid: number[][]): number {
    const rgrid = rotate(grid);
    return Math.min(solve(grid), solve(rgrid));
}

function minimumSum2(
    grid: number[][],
    u: number,
    d: number,
    l: number,
    r: number,
): number {
    let min_i = grid.length,
        max_i = 0;
    let min_j = grid[0].length,
        max_j = 0;
    for (let i = u; i <= d; i++) {
        for (let j = l; j <= r; j++) {
            if (grid[i][j] === 1) {
                min_i = Math.min(min_i, i);
                min_j = Math.min(min_j, j);
                max_i = Math.max(max_i, i);
                max_j = Math.max(max_j, j);
            }
        }
    }
    return min_i <= max_i
        ? (max_i - min_i + 1) * (max_j - min_j + 1)
        : Number.MAX_SAFE_INTEGER / 3;
}

function rotate(vec: number[][]): number[][] {
    const n = vec.length,
        m = vec[0].length;
    const ret: number[][] = new Array(m).fill(0).map(() => new Array(n));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            ret[m - j - 1][i] = vec[i][j];
        }
    }
    return ret;
}

function solve(grid: number[][]): number {
    const n = grid.length,
        m = grid[0].length;
    let res = n * m;
    for (let i = 0; i + 1 < n; i++) {
        for (let j = 0; j + 1 < m; j++) {
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, j) +
                    minimumSum2(grid, i + 1, n - 1, j + 1, m - 1),
            );
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, j) +
                    minimumSum2(grid, 0, i, j + 1, m - 1) +
                    minimumSum2(grid, i + 1, n - 1, 0, m - 1),
            );
        }
    }
    for (let i = 0; i + 2 < n; i++) {
        for (let j = i + 1; j + 1 < n; j++) {
            res = Math.min(
                res,
                minimumSum2(grid, 0, i, 0, m - 1) +
                    minimumSum2(grid, i + 1, j, 0, m - 1) +
                    minimumSum2(grid, j + 1, n - 1, 0, m - 1),
            );
        }
    }
    return res;
}
```

</details>
