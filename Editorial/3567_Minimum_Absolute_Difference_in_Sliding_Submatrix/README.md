# 3567. Minimum Absolute Difference in Sliding Submatrix

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/)  
`Array` `Sorting` `Matrix`

**Problem Link:** [LeetCode 3567 - Minimum Absolute Difference in Sliding Submatrix](https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/)

## Problem

You are given an m x n integer matrix grid and an integer k.

For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.

Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.

Note: If all elements in the submatrix have the same value, the answer will be 0.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= m == grid.length <= 30
- 1 <= n == grid[i].length <= 30
- -105 <= grid[i][j] <= 105
- 1 <= k <= min(m, n)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3567. Minimum Absolute Difference in Sliding Submatrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sorting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** minAbsDiff(int** grid, int m, int* gridColSize, int k, int* returnSize,
                 int** returnColumnSizes) {
    int n = gridColSize[0];
    int rows = m - k + 1, cols = n - k + 1;
    int** res = (int**)malloc(rows * sizeof(int*));
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        res[i] = (int*)calloc(cols, sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }
    int size = k * k;
    int* kgrid = (int*)malloc(size * sizeof(int));
    for (int i = 0; i + k <= m; i++) {
        for (int j = 0; j + k <= n; j++) {
            int idx = 0;
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    kgrid[idx++] = grid[x][y];
                }
            }
            int kmin = INT_MAX;
            qsort(kgrid, size, sizeof(int), cmp);
            for (int t = 1; t < size; t++) {
                if (kgrid[t] == kgrid[t - 1]) {
                    continue;
                }
                kmin = fmin(kmin, kgrid[t] - kgrid[t - 1]);
            }
            if (kmin != INT_MAX) {
                res[i][j] = kmin;
            }
        }
    }
    free(kgrid);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> kgrid;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.push_back(grid[x][y]);
                    }
                }
                int kmin = INT_MAX;
                sort(kgrid.begin(), kgrid.end());
                for (int t = 1; t < kgrid.size(); t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != INT_MAX) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] MinAbsDiff(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int[][] res = new int [m - k + 1][];
        for (int i = 0; i < m - k + 1; i++) {
            res[i] = new int[n - k + 1];
        }
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                List<int> kgrid = new List<int>();
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.Add(grid[x][y]);
                    }
                }
                int kmin = int.MaxValue;
                kgrid.Sort();
                for (int t = 1; t < kgrid.Count; t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = Math.Min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != int.MaxValue) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minAbsDiff(grid [][]int, k int) [][]int {
	m, n := len(grid), len(grid[0])
	res := make([][]int, m-k+1)
	for i := range res {
		res[i] = make([]int, n-k+1)
	}
	for i := 0; i+k <= m; i++ {
		for j := 0; j+k <= n; j++ {
			kgrid := []int{}
			for x := i; x < i+k; x++ {
				for y := j; y < j+k; y++ {
					kgrid = append(kgrid, grid[x][y])
				}
			}
			kmin := math.MaxInt
			sort.Ints(kgrid)
			for t := 1; t < len(kgrid); t++ {
				if kgrid[t] == kgrid[t-1] {
					continue
				}
				kmin = min(kmin, kgrid[t]-kgrid[t-1])
			}
			if kmin != math.MaxInt {
				res[i][j] = kmin
			}
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] res = new int[m - k + 1][n - k + 1];
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                List<Integer> kgrid = new ArrayList<>();
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.add(grid[x][y]);
                    }
                }
                int kmin = Integer.MAX_VALUE;
                Collections.sort(kgrid);
                for (int t = 1; t < kgrid.size(); t++) {
                    if (kgrid.get(t).equals(kgrid.get(t - 1))) {
                        continue;
                    }
                    kmin = Math.min(kmin, kgrid.get(t) - kgrid.get(t - 1));
                }
                if (kmin != Integer.MAX_VALUE) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minAbsDiff = function (grid, k) {
    const m = grid.length,
        n = grid[0].length;
    const res = Array.from({ length: m - k + 1 }, () =>
        Array(n - k + 1).fill(0),
    );
    for (let i = 0; i + k <= m; i++) {
        for (let j = 0; j + k <= n; j++) {
            let kgrid = [];
            for (let x = i; x < i + k; x++) {
                for (let y = j; y < j + k; y++) {
                    kgrid.push(grid[x][y]);
                }
            }
            let kmin = Number.MAX_SAFE_INTEGER;
            kgrid.sort((a, b) => a - b);
            for (let t = 1; t < kgrid.length; t++) {
                if (kgrid[t] === kgrid[t - 1]) {
                    continue;
                }
                kmin = Math.min(kmin, kgrid[t] - kgrid[t - 1]);
            }
            if (kmin !== Number.MAX_SAFE_INTEGER) {
                res[i][j] = kmin;
            }
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
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        res = [[0] * (n - k + 1) for _ in range(m - k + 1)]
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                kgrid = []
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        kgrid.append(grid[x][y])
                kmin = float("inf")
                kgrid.sort()
                for t in range(1, len(kgrid)):
                    if kgrid[t] == kgrid[t - 1]:
                        continue
                    kmin = min(kmin, kgrid[t] - kgrid[t - 1])
                if kmin != float("inf"):
                    res[i][j] = kmin
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minAbsDiff(grid: number[][], k: number): number[][] {
    const m = grid.length,
        n = grid[0].length;
    const res: number[][] = Array.from({ length: m - k + 1 }, () =>
        Array(n - k + 1).fill(0),
    );
    for (let i = 0; i + k <= m; i++) {
        for (let j = 0; j + k <= n; j++) {
            let kgrid: number[] = [];
            for (let x = i; x < i + k; x++) {
                for (let y = j; y < j + k; y++) {
                    kgrid.push(grid[x][y]);
                }
            }
            let kmin = Number.MAX_SAFE_INTEGER;
            kgrid.sort((a, b) => a - b);
            for (let t = 1; t < kgrid.length; t++) {
                if (kgrid[t] === kgrid[t - 1]) {
                    continue;
                }
                kmin = Math.min(kmin, kgrid[t] - kgrid[t - 1]);
            }
            if (kmin !== Number.MAX_SAFE_INTEGER) {
                res[i][j] = kmin;
            }
        }
    }
    return res;
}
```

</details>
