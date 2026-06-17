# 1594. Maximum Non Negative Product in a Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 1594 - Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)

## Problem

You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.

### Example 1

```text
Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
Output: -1
Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
```

### Example 2

```text
Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
```

### Example 3

```text
Input: grid = [[1,3],[0,-4]]
Output: 0
Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 15
- -4 <= grid[i][j] <= 4

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1594. Maximum Non Negative Product in a Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    long long** maxgt = (long long**)malloc(m * sizeof(long long*));
    long long** minlt = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        maxgt[i] = (long long*)malloc(n * sizeof(long long));
        minlt[i] = (long long*)malloc(n * sizeof(long long));
    }

    maxgt[0][0] = minlt[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
    }
    for (int i = 1; i < m; i++) {
        maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] >= 0) {
                maxgt[i][j] =
                    fmax(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    fmin(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
            } else {
                maxgt[i][j] =
                    fmin(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    fmax(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
            }
        }
    }

    long long result = maxgt[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(maxgt[i]);
        free(minlt[i]);
    }
    free(maxgt);
    free(minlt);

    if (result < 0) {
        return -1;
    } else {
        return result % MOD;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1000000000 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxgt(m, vector<long long>(n));
        vector<vector<long long>> minlt(m, vector<long long>(n));

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxgt[i][j] =
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                } else {
                    maxgt[i][j] =
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                }
            }
        }
        if (maxgt[m - 1][n - 1] < 0) {
            return -1;
        } else {
            return maxgt[m - 1][n - 1] % mod;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxProductPath(int[][] grid) {
        const int MOD = 1000000007;
        int m = grid.Length, n = grid[0].Length;
        long[,] maxgt = new long[m, n];
        long[,] minlt = new long[m, n];

        maxgt[0, 0] = minlt[0, 0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0, i] = minlt[0, i] = maxgt[0, i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i, 0] = minlt[i, 0] = maxgt[i - 1, 0] * grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    long maxPrev = Math.Max(maxgt[i, j - 1], maxgt[i - 1, j]);
                    long minPrev = Math.Min(minlt[i, j - 1], minlt[i - 1, j]);
                    maxgt[i, j] = maxPrev * grid[i][j];
                    minlt[i, j] = minPrev * grid[i][j];
                } else {
                    long maxPrev = Math.Max(maxgt[i, j - 1], maxgt[i - 1, j]);
                    long minPrev = Math.Min(minlt[i, j - 1], minlt[i - 1, j]);
                    maxgt[i, j] = minPrev * grid[i][j];
                    minlt[i, j] = maxPrev * grid[i][j];
                }
            }
        }

        if (maxgt[m - 1, n - 1] < 0) {
            return -1;
        } else {
            return (int)(maxgt[m - 1, n - 1] % MOD);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxProductPath(grid [][]int) int {
	const MOD = 1000000007
	m, n := len(grid), len(grid[0])

	maxgt := make([][]int64, m)
	minlt := make([][]int64, m)
	for i := range maxgt {
		maxgt[i] = make([]int64, n)
		minlt[i] = make([]int64, n)
	}

	maxgt[0][0] = int64(grid[0][0])
	minlt[0][0] = int64(grid[0][0])
	for i := 1; i < n; i++ {
		maxgt[0][i] = maxgt[0][i-1] * int64(grid[0][i])
		minlt[0][i] = maxgt[0][i]
	}
	for i := 1; i < m; i++ {
		maxgt[i][0] = maxgt[i-1][0] * int64(grid[i][0])
		minlt[i][0] = maxgt[i][0]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if grid[i][j] >= 0 {
				maxPrev := max(maxgt[i][j-1], maxgt[i-1][j])
				minPrev := min(minlt[i][j-1], minlt[i-1][j])
				maxgt[i][j] = maxPrev * int64(grid[i][j])
				minlt[i][j] = minPrev * int64(grid[i][j])
			} else {
				maxPrev := max(maxgt[i][j-1], maxgt[i-1][j])
				minPrev := min(minlt[i][j-1], minlt[i-1][j])
				maxgt[i][j] = minPrev * int64(grid[i][j])
				minlt[i][j] = maxPrev * int64(grid[i][j])
			}
		}
	}

	if maxgt[m-1][n-1] < 0 {
		return -1
	}
	return int(maxgt[m-1][n-1] % MOD)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxProductPath(int[][] grid) {
        final int MOD = 1000000000 + 7;
        int m = grid.length;
        int n = grid[0].length;
        long[][] maxgt = new long[m][n];
        long[][] minlt = new long[m][n];

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxgt[i][j] =
                        Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                } else {
                    maxgt[i][j] =
                        Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                }
            }
        }
        if (maxgt[m - 1][n - 1] < 0) {
            return -1;
        } else {
            return (int) (maxgt[m - 1][n - 1] % MOD);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxProductPath = function (grid) {
    const MOD = 1000000007;
    const m = grid.length,
        n = grid[0].length;
    const maxgt = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const minlt = new Array(m).fill(0).map(() => new Array(n).fill(0));

    maxgt[0][0] = minlt[0][0] = grid[0][0];
    for (let i = 1; i < n; i++) {
        maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
    }
    for (let i = 1; i < m; i++) {
        maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (grid[i][j] >= 0) {
                maxgt[i][j] =
                    Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
            } else {
                maxgt[i][j] =
                    Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
            }
        }
    }

    if (maxgt[m - 1][n - 1] < 0) {
        return -1;
    } else {
        return maxgt[m - 1][n - 1] % MOD;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        mod = 10**9 + 7
        m, n = len(grid), len(grid[0])
        maxgt = [[0] * n for _ in range(m)]
        minlt = [[0] * n for _ in range(m)]

        maxgt[0][0] = minlt[0][0] = grid[0][0]
        for i in range(1, n):
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i]
        for i in range(1, m):
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0]

        for i in range(1, m):
            for j in range(1, n):
                if grid[i][j] >= 0:
                    maxgt[i][j] = (
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j]
                    )
                    minlt[i][j] = (
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j]
                    )
                else:
                    maxgt[i][j] = (
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j]
                    )
                    minlt[i][j] = (
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j]
                    )

        if maxgt[m - 1][n - 1] < 0:
            return -1
        return maxgt[m - 1][n - 1] % mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxProductPath(grid: number[][]): number {
    const MOD = 1000000007;
    const m = grid.length,
        n = grid[0].length;

    const maxgt: number[][] = new Array(m)
        .fill(0)
        .map(() => new Array(n).fill(0));
    const minlt: number[][] = new Array(m)
        .fill(0)
        .map(() => new Array(n).fill(0));

    maxgt[0][0] = minlt[0][0] = grid[0][0];
    for (let i = 1; i < n; i++) {
        maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
    }
    for (let i = 1; i < m; i++) {
        maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (grid[i][j] >= 0) {
                maxgt[i][j] =
                    Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
            } else {
                maxgt[i][j] =
                    Math.min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    Math.max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
            }
        }
    }

    if (maxgt[m - 1][n - 1] < 0) {
        return -1;
    } else {
        return maxgt[m - 1][n - 1] % MOD;
    }
}
```

</details>
