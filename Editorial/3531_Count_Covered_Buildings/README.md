# 3531. Count Covered Buildings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-covered-buildings/)  
`Array` `Hash Table` `Sorting`

**Problem Link:** [LeetCode 3531 - Count Covered Buildings](https://leetcode.com/problems/count-covered-buildings/)

## Problem

You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

A building is covered if there is at least one building in all four directions: left, right, above, and below.

Return the number of covered buildings.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= n <= 105
- 1 <= buildings.length <= 105
- buildings[i] = [x, y]
- 1 <= x, y <= n
- All coordinates of buildings are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3531. Count Covered Buildings

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
int countCoveredBuildings(int n, int** buildings, int buildingsSize,
                          int* buildingsColSize) {
    int* maxRow = (int*)calloc(n + 1, sizeof(int));
    int* minRow = (int*)malloc((n + 1) * sizeof(int));
    int* maxCol = (int*)calloc(n + 1, sizeof(int));
    int* minCol = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        minRow[i] = n + 1;
        minCol[i] = n + 1;
    }

    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        maxRow[y] = fmax(maxRow[y], x);
        minRow[y] = fmin(minRow[y], x);
        maxCol[x] = fmax(maxCol[x], y);
        minCol[x] = fmin(minCol[x], y);
    }

    int res = 0;
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
            res++;
        }
    }

    free(maxRow);
    free(minRow);
    free(maxCol);
    free(minCol);

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n + 1);
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxCol(n + 1);
        vector<int> minCol(n + 1, n + 1);

        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int res = 0;
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
                y < maxCol[x]) {
                res++;
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
    public int CountCoveredBuildings(int n, int[][] buildings) {
        int[] maxRow = new int[n + 1];
        int[] minRow = new int[n + 1];
        int[] maxCol = new int[n + 1];
        int[] minCol = new int[n + 1];

        Array.Fill(minRow, n + 1);
        Array.Fill(minCol, n + 1);
        foreach (var p in buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = Math.Max(maxRow[y], x);
            minRow[y] = Math.Min(minRow[y], x);
            maxCol[x] = Math.Max(maxCol[x], y);
            minCol[x] = Math.Min(minCol[x], y);
        }

        int res = 0;
        foreach (var p in buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
                y < maxCol[x]) {
                res++;
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
func countCoveredBuildings(n int, buildings [][]int) int {
	maxRow := make([]int, n+1)
	minRow := make([]int, n+1)
	maxCol := make([]int, n+1)
	minCol := make([]int, n+1)

	for i := range minRow {
		minRow[i] = n + 1
		minCol[i] = n + 1
	}

	for _, p := range buildings {
		x, y := p[0], p[1]
		maxRow[y] = max(maxRow[y], x)
		minRow[y] = min(minRow[y], x)
		maxCol[x] = max(maxCol[x], y)
		minCol[x] = min(minCol[x], y)
	}

	res := 0
	for _, p := range buildings {
		x, y := p[0], p[1]
		if x > minRow[y] && x < maxRow[y] &&
			y > minCol[x] && y < maxCol[x] {
			res++
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

    public int countCoveredBuildings(int n, int[][] buildings) {
        int[] maxRow = new int[n + 1];
        int[] minRow = new int[n + 1];
        int[] maxCol = new int[n + 1];
        int[] minCol = new int[n + 1];

        Arrays.fill(minRow, n + 1);
        Arrays.fill(minCol, n + 1);

        for (int[] p : buildings) {
            int x = p[0];
            int y = p[1];
            maxRow[y] = Math.max(maxRow[y], x);
            minRow[y] = Math.min(minRow[y], x);
            maxCol[x] = Math.max(maxCol[x], y);
            minCol[x] = Math.min(minCol[x], y);
        }

        int res = 0;
        for (int[] p : buildings) {
            int x = p[0];
            int y = p[1];
            if (
                x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]
            ) {
                res++;
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
var countCoveredBuildings = function (n, buildings) {
    const maxRow = new Array(n + 1).fill(0);
    const minRow = new Array(n + 1).fill(n + 1);
    const maxCol = new Array(n + 1).fill(0);
    const minCol = new Array(n + 1).fill(n + 1);

    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        maxRow[y] = Math.max(maxRow[y], x);
        minRow[y] = Math.min(minRow[y], x);
        maxCol[x] = Math.max(maxCol[x], y);
        minCol[x] = Math.min(minCol[x], y);
    }

    let res = 0;
    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
            res++;
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
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        max_row = [0] * (n + 1)
        min_row = [n + 1] * (n + 1)
        max_col = [0] * (n + 1)
        min_col = [n + 1] * (n + 1)

        for p in buildings:
            x, y = p[0], p[1]
            max_row[y] = max(max_row[y], x)
            min_row[y] = min(min_row[y], x)
            max_col[x] = max(max_col[x], y)
            min_col[x] = min(min_col[x], y)

        res = 0
        for p in buildings:
            x, y = p[0], p[1]
            if (
                x > min_row[y]
                and x < max_row[y]
                and y > min_col[x]
                and y < max_col[x]
            ):
                res += 1

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countCoveredBuildings(n: number, buildings: number[][]): number {
    const maxRow: number[] = new Array(n + 1).fill(0);
    const minRow: number[] = new Array(n + 1).fill(n + 1);
    const maxCol: number[] = new Array(n + 1).fill(0);
    const minCol: number[] = new Array(n + 1).fill(n + 1);

    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        maxRow[y] = Math.max(maxRow[y], x);
        minRow[y] = Math.min(minRow[y], x);
        maxCol[x] = Math.max(maxCol[x], y);
        minCol[x] = Math.min(minCol[x], y);
    }

    let res = 0;
    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
            res++;
        }
    }

    return res;
}
```

</details>
