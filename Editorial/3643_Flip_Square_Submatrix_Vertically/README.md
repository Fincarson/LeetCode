# 3643. Flip Square Submatrix Vertically

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/flip-square-submatrix-vertically/)  
`Array` `Two Pointers` `Matrix`

**Problem Link:** [LeetCode 3643 - Flip Square Submatrix Vertically](https://leetcode.com/problems/flip-square-submatrix-vertically/)

## Problem

You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.

### Example 1

### Example 2

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- 1 <= grid[i][j] <= 100
- 0 <= x < m
- 0 <= y < n
- 1 <= k <= min(m - x, n - y)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3643. Flip Square Submatrix Vertically

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y,
                       int k, int* returnSize, int** returnColumnSizes) {
    for (int i0 = x, i1 = x + k - 1; i0 < i1; ++i0, --i1) {
        for (int j = y; j < y + k; ++j) {
            int temp = grid[i0][j];
            grid[i0][j] = grid[i1][j];
            grid[i1][j] = temp;
        }
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int i0 = x, i1 = x + k - 1; i0 < i1; ++i0, --i1) {
            for (int j = y; j < y + k; ++j) {
                swap(grid[i0][j], grid[i1][j]);
            }
        }
        return grid;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ReverseSubmatrix(int[][] grid, int x, int y, int k) {
        for (int i0 = x, i1 = x + k - 1; i0 < i1; i0++, i1--) {
            for (int j = y; j < y + k; j++) {
                int temp = grid[i0][j];
                grid[i0][j] = grid[i1][j];
                grid[i1][j] = temp;
            }
        }
        return grid;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
	for i0, i1 := x, x+k-1; i0 < i1; i0, i1 = i0+1, i1-1 {
		for j := y; j < y+k; j++ {
			grid[i0][j], grid[i1][j] = grid[i1][j], grid[i0][j]
		}
	}
	return grid
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        for (int i0 = x, i1 = x + k - 1; i0 < i1; i0++, i1--) {
            for (int j = y; j < y + k; j++) {
                int temp = grid[i0][j];
                grid[i0][j] = grid[i1][j];
                grid[i1][j] = temp;
            }
        }
        return grid;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseSubmatrix = function (grid, x, y, k) {
    for (let i0 = x, i1 = x + k - 1; i0 < i1; i0++, i1--) {
        for (let j = y; j < y + k; j++) {
            [grid[i0][j], grid[i1][j]] = [grid[i1][j], grid[i0][j]];
        }
    }
    return grid;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        i0, i1 = x, x + k - 1
        while i0 < i1:
            for j in range(y, y + k):
                grid[i0][j], grid[i1][j] = grid[i1][j], grid[i0][j]
            i0, i1 = i0 + 1, i1 - 1
        return grid
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseSubmatrix(
    grid: number[][],
    x: number,
    y: number,
    k: number,
): number[][] {
    for (let i0 = x, i1 = x + k - 1; i0 < i1; i0++, i1--) {
        for (let j = y; j < y + k; j++) {
            [grid[i0][j], grid[i1][j]] = [grid[i1][j], grid[i0][j]];
        }
    }
    return grid;
}
```

</details>
