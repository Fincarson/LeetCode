# 3195. Find the Minimum Area to Cover All Ones I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 3195 - Find the Minimum Area to Cover All Ones I](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/)

## Problem

You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

### Example 1

### Example 2

## Constraints

- 1 <= grid.length, grid[i].length <= 1000
- grid[i][j] is either 0 or 1.
- The input is generated such that there is at least one 1 in grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3195. Find the Minimum Area to Cover All Ones I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int min_i = n, max_i = 0;
    int min_j = m, max_j = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                if (i < min_i) {
                    min_i = i;
                }
                if (i > max_i) {
                    max_i = i;
                }
                if (j < min_j) {
                    min_j = j;
                }
                if (j > max_j) {
                    max_j = j;
                }
            }
        }
    }
    return (max_i - min_i + 1) * (max_j - min_j + 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_i = n, max_i = 0;
        int min_j = m, max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinimumArea(int[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        int min_i = n, max_i = 0;
        int min_j = m, max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    min_i = Math.Min(min_i, i);
                    max_i = Math.Max(max_i, i);
                    min_j = Math.Min(min_j, j);
                    max_j = Math.Max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minimumArea(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	min_i, max_i := n, 0
	min_j, max_j := m, 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				min_i = min(min_i, i)
				max_i = max(max_i, i)
				min_j = min(min_j, j)
				max_j = max(max_j, j)
			}
		}
	}
	return (max_i - min_i + 1) * (max_j - min_j + 1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minimumArea(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int min_i = n;
        int max_i = 0;
        int min_j = m;
        int max_j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    min_i = Math.min(min_i, i);
                    max_i = Math.max(max_i, i);
                    min_j = Math.min(min_j, j);
                    max_j = Math.max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minimumArea = function (grid) {
    const n = grid.length,
        m = grid[0].length;
    let min_i = n,
        max_i = 0;
    let min_j = m,
        max_j = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 1) {
                min_i = Math.min(min_i, i);
                max_i = Math.max(max_i, i);
                min_j = Math.min(min_j, j);
                max_j = Math.max(max_j, j);
            }
        }
    }
    return (max_i - min_i + 1) * (max_j - min_j + 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        min_i, max_i = n, 0
        min_j, max_j = m, 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    min_i = min(min_i, i)
                    max_i = max(max_i, i)
                    min_j = min(min_j, j)
                    max_j = max(max_j, j)

        return (max_i - min_i + 1) * (max_j - min_j + 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minimumArea(grid: number[][]): number {
    const n = grid.length,
        m = grid[0].length;
    let min_i = n,
        max_i = 0;
    let min_j = m,
        max_j = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (grid[i][j] === 1) {
                min_i = Math.min(min_i, i);
                max_i = Math.max(max_i, i);
                min_j = Math.min(min_j, j);
                max_j = Math.max(max_j, j);
            }
        }
    }
    return (max_i - min_i + 1) * (max_j - min_j + 1);
}
```

</details>
