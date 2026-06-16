# 3070. Count Submatrices with Top-Left Element and Sum Less Than k

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 3070 - Count Submatrices with Top-Left Element and Sum Less Than k](https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/)

## Problem

You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

### Example 1

```text
Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
```

### Example 2

```text
Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= n, m <= 1000
- 0 <= grid[i][j] <= 1000
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3070. Count Submatrices with Top-Left Element and Sum Less Than k

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: 2D Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: 2D Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = *gridColSize;
    int* cols = (int*)calloc(n, sizeof(int));
    int res = 0;

    for (int i = 0; i < m; i++) {
        int rows = 0;
        for (int j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
            }
        }
    }

    free(cols);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> cols(n);
        int res = 0;
        for (int i = 0; i < m; i++) {
            int rows = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
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
    public int CountSubmatrices(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int[] cols = new int[n];
        int res = 0;

        for (int i = 0; i < m; i++) {
            int rows = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
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
func countSubmatrices(grid [][]int, k int) int {
	m := len(grid)
	n := len(grid[0])
	cols := make([]int, n)
	res := 0

	for i := 0; i < m; i++ {
		rows := 0
		for j := 0; j < n; j++ {
			cols[j] += grid[i][j]
			rows += cols[j]
			if rows <= k {
				res++
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

    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[] cols = new int[n];
        int res = 0;

        for (int i = 0; i < m; i++) {
            int rows = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
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
var countSubmatrices = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const cols = new Array(n).fill(0);
    let res = 0;

    for (let i = 0; i < m; i++) {
        let rows = 0;
        for (let j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
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
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        cols = [0] * n
        res = 0

        for i in range(m):
            row_sum = 0
            for j in range(n):
                cols[j] += grid[i][j]
                row_sum += cols[j]
                if row_sum <= k:
                    res += 1

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countSubmatrices(grid: number[][], k: number): number {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const cols: number[] = new Array(n).fill(0);
    let res: number = 0;

    for (let i = 0; i < m; i++) {
        let rows: number = 0;
        for (let j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
            }
        }
    }

    return res;
}
```

</details>
