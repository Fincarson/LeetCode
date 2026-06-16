# 2906. Construct Product Matrix

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-product-matrix/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 2906 - Construct Product Matrix](https://leetcode.com/problems/construct-product-matrix/)

## Problem

Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:

- Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.

Return the product matrix of grid.

### Example 1

```text
Input: grid = [[1,2],[3,4]]
Output: [[24,12],[8,6]]
Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
So the answer is [[24,12],[8,6]].
```

### Example 2

```text
Input: grid = [[12345],[2],[1]]
Output: [[2],[0],[0]]
Explanation: p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0. So p[0][1] = 0.
p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0. So p[0][2] = 0.
So the answer is [[2],[0],[0]].
```

## Constraints

- 1 <= n == grid.length <= 105
- 1 <= m == grid[i].length <= 105
- 2 <= n * m <= 105
- 1 <= grid[i][j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2906. Construct Product Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Suffix Product | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Suffix Product

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize,
                             int* returnSize, int** returnColumnSizes) {
    const int MOD = 12345;
    int n = gridSize, m = gridColSize[0];

    int** p = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    *returnSize = n;

    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            p[i][j] = suffix % MOD;
            suffix = (suffix * grid[i][j]) % MOD;
        }
    }

    long long prefix = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = (p[i][j] * prefix) % MOD;
            prefix = (prefix * grid[i][j]) % MOD;
        }
    }

    return p;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));

        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        }

        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = p[i][j] * prefix % MOD;
                prefix = prefix * grid[i][j] % MOD;
            }
        }

        return p;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] ConstructProductMatrix(int[][] grid) {
        const int MOD = 12345;
        int n = grid.Length, m = grid[0].Length;
        int[][] p = new int [n][];

        for (int i = 0; i < n; i++) {
            p[i] = new int[m];
        }
        long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (int)suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        }

        long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = (int)((long)p[i][j] * prefix % MOD);
                prefix = prefix * grid[i][j] % MOD;
            }
        }

        return p;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func constructProductMatrix(grid [][]int) [][]int {
	const MOD = 12345
	n, m := len(grid), len(grid[0])
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, m)
	}

	suffix := int64(1)
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			p[i][j] = int(suffix)
			suffix = (suffix * int64(grid[i][j])) % MOD
		}
	}

	prefix := int64(1)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			p[i][j] = int((int64(p[i][j]) * prefix) % MOD)
			prefix = (prefix * int64(grid[i][j])) % MOD
		}
	}

	return p
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] constructProductMatrix(int[][] grid) {
        final int MOD = 12345;
        int n = grid.length;
        int m = grid[0].length;
        int[][] p = new int[n][m];

        long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (int) suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = (int) (((long) p[i][j] * prefix) % MOD);
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return p;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var constructProductMatrix = function (grid) {
    const MOD = 12345;
    const n = grid.length,
        m = grid[0].length;
    const p = Array.from({ length: n }, () => new Array(m).fill(0));

    let suffix = 1;
    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            p[i][j] = suffix;
            suffix = (suffix * grid[i][j]) % MOD;
        }
    }

    let prefix = 1;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            p[i][j] = (p[i][j] * prefix) % MOD;
            prefix = (prefix * grid[i][j]) % MOD;
        }
    }

    return p;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        MOD = 12345
        n, m = len(grid), len(grid[0])
        p = [[0] * m for _ in range(n)]

        suffix = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                p[i][j] = suffix
                suffix = (suffix * grid[i][j]) % MOD

        prefix = 1
        for i in range(n):
            for j in range(m):
                p[i][j] = (p[i][j] * prefix) % MOD
                prefix = (prefix * grid[i][j]) % MOD

        return p
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function constructProductMatrix(grid: number[][]): number[][] {
    const MOD: number = 12345;
    const n: number = grid.length,
        m: number = grid[0].length;
    const p: number[][] = Array.from({ length: n }, () => new Array(m).fill(0));

    let suffix: number = 1;
    for (let i = n - 1; i >= 0; i--) {
        for (let j = m - 1; j >= 0; j--) {
            p[i][j] = suffix;
            suffix = (suffix * grid[i][j]) % MOD;
        }
    }

    let prefix: number = 1;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            p[i][j] = (p[i][j] * prefix) % MOD;
            prefix = (prefix * grid[i][j]) % MOD;
        }
    }

    return p;
}
```

</details>
