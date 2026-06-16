# 3546. Equal Sum Grid Partition I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/equal-sum-grid-partition-i/)  
`Array` `Matrix` `Enumeration` `Prefix Sum`

**Problem Link:** [LeetCode 3546 - Equal Sum Grid Partition I](https://leetcode.com/problems/equal-sum-grid-partition-i/)

## Problem

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

- Each of the two resulting sections formed by the cut is non-empty.
- The sum of the elements in both sections is equal.

Return true if such a partition exists; otherwise return false.

### Example 1

### Example 2

## Constraints

- 1 <= m == grid.length <= 105
- 1 <= n == grid[i].length <= 105
- 2 <= m * n <= 105
- 1 <= grid[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3546. Equal Sum Grid Partition I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| 2D Prefix Sum + Enumerating Boundary Elements | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Matrix Rotation + Row-wise Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: 2D Prefix Sum + Enumerating Boundary Elements

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    long long sum[m + 1][n + 1];
    long long total = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] =
                sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            total += grid[i][j];
        }
    }
    for (int i = 0; i < m - 1; i++) {
        if (total == sum[i + 1][n] * 2) {
            return true;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (total == sum[m][i + 1] * 2) {
            return true;
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum[m + 1][n + 1];
        long long total = 0;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] =
                    sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                total += grid[i][j];
            }
        }
        for (int i = 0; i < m - 1; i++) {
            if (total == sum[i + 1][n] * 2) {
                return true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (total == sum[m][i + 1] * 2) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        int m = grid.Length;
        int n = grid[0].Length;
        long[][] sum = new long [m + 1][];
        for (int i = 0; i <= m; i++) {
            sum[i] = new long[n + 1];
        }
        long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] =
                    sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                total += grid[i][j];
            }
        }
        for (int i = 0; i < m - 1; i++) {
            if (total == sum[i + 1][n] * 2) {
                return true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (total == sum[m][i + 1] * 2) {
                return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canPartitionGrid(grid [][]int) bool {
    m, n := len(grid), len(grid[0])
    sum := make([][]int64, m+1)
    for i := range sum {
        sum[i] = make([]int64, n+1)
    }
    var total int64 = 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + int64(grid[i][j])
            total += int64(grid[i][j])
        }
    }
    for i := 0; i < m-1; i++ {
        if total == sum[i+1][n]*2 {
            return true
        }
    }
    for i := 0; i < n-1; i++ {
        if total == sum[m][i+1]*2 {
            return true
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

    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long[][] sum = new long[m + 1][n + 1];
        long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] =
                    sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
                total += grid[i][j];
            }
        }
        for (int i = 0; i < m - 1; i++) {
            if (total == sum[i + 1][n] * 2) {
                return true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (total == sum[m][i + 1] * 2) {
                return true;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canPartitionGrid = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const sum = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    let total = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            sum[i + 1][j + 1] =
                sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            total += grid[i][j];
        }
    }
    for (let i = 0; i < m - 1; i++) {
        if (total === sum[i + 1][n] * 2) {
            return true;
        }
    }
    for (let i = 0; i < n - 1; i++) {
        if (total === sum[m][i + 1] * 2) {
            return true;
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
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        sum = [[0] * (n + 1) for _ in range(m + 1)]
        total = 0
        for i in range(m):
            for j in range(n):
                sum[i + 1][j + 1] = (
                    sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j]
                )
                total += grid[i][j]
        for i in range(m - 1):
            if total == sum[i + 1][n] * 2:
                return True
        for i in range(n - 1):
            if total == sum[m][i + 1] * 2:
                return True
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canPartitionGrid(grid: number[][]): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const sum: number[][] = Array.from({ length: m + 1 }, () =>
        Array(n + 1).fill(0),
    );
    let total = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            sum[i + 1][j + 1] =
                sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            total += grid[i][j];
        }
    }
    for (let i = 0; i < m - 1; i++) {
        if (total === sum[i + 1][n] * 2) {
            return true;
        }
    }
    for (let i = 0; i < n - 1; i++) {
        if (total === sum[m][i + 1] * 2) {
            return true;
        }
    }
    return false;
}
```

</details>

<br>

## Approach 2: Matrix Rotation + Row-wise Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** rotation(int** grid, int gridSize, int* gridColSize, int* returnSize,
               int** returnColumnSizes) {
    int m = gridSize, n = gridColSize[0];
    int** tmp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        tmp[i] = (int*)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }
    return tmp;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    long long total = 0;
    int m = gridSize, n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (int k = 0; k < 2; k++) {
        long long sum = 0;
        m = gridSize;
        n = gridColSize[0];
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 == total) {
                return true;
            }
        }
        int returnSize, *returnColumnSizes;
        grid = rotation(grid, gridSize, gridColSize, &returnSize,
                        &returnColumnSizes);
        gridSize = returnSize;
        gridColSize = returnColumnSizes;
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 2; k++) {
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.Length;
        int n = grid[0].Length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 2; k++) {
            long sum = 0;
            m = grid.Length;
            n = grid[0].Length;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
                    return true;
                }
            }
            grid = Rotation(grid);
        }
        return false;
    }

    public int[][] Rotation(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[][] tmp = new int [n][];
        for (int i = 0; i < n; i++) {
            tmp[i] = new int[m];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canPartitionGrid(grid [][]int) bool {
	var total int64 = 0
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			total += int64(grid[i][j])
		}
	}
	for k := 0; k < 2; k++ {
		var sum int64 = 0
		m, n = len(grid), len(grid[0])
		for i := 0; i < m-1; i++ {
			for j := 0; j < n; j++ {
				sum += int64(grid[i][j])
			}
			if sum*2 == total {
				return true
			}
		}
		grid = rotation(grid)
	}
	return false
}

func rotation(grid [][]int) [][]int {
	m, n := len(grid), len(grid[0])
	tmp := make([][]int, n)
	for i := range tmp {
		tmp[i] = make([]int, m)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			tmp[j][m-1-i] = grid[i][j]
		}
	}
	return tmp
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 2; k++) {
            long sum = 0;
            m = grid.length;
            n = grid[0].length;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }

    public int[][] rotation(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canPartitionGrid = function (grid) {
    let total = 0;
    let m = grid.length;
    let n = grid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (let k = 0; k < 2; k++) {
        let sum = 0;
        m = grid.length;
        n = grid[0].length;
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 === total) {
                return true;
            }
        }
        grid = rotation(grid);
    }
    return false;
};

function rotation(grid) {
    const m = grid.length,
        n = grid[0].length;
    const tmp = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                total += grid[i][j]
        for _ in range(2):
            sum_val = 0
            m = len(grid)
            n = len(grid[0])
            for i in range(m - 1):
                for j in range(n):
                    sum_val += grid[i][j]
                if sum_val * 2 == total:
                    return True
            grid = self.rotation(grid)
        return False

    def rotation(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        tmp = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                tmp[j][m - 1 - i] = grid[i][j]
        return tmp
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canPartitionGrid(grid: number[][]): boolean {
    let total = 0;
    let m = grid.length;
    let n = grid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (let k = 0; k < 2; k++) {
        let sum = 0;
        m = grid.length;
        n = grid[0].length;
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 === total) {
                return true;
            }
        }
        grid = rotation(grid);
    }
    return false;
}

function rotation(grid: number[][]): number[][] {
    const m = grid.length,
        n = grid[0].length;
    const tmp: number[][] = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}
```

</details>
