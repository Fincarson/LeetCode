# 59. Spiral Matrix II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/spiral-matrix-ii/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 59 - Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

## Problem

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

### Example 1

```text
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

### Example 2

```text
Input: n = 1
Output: [[1]]
```

## Constraints

- 1 <= n <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 59. Spiral Matrix II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Traverse Layer by Layer in Spiral Form | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Optimized spiral traversal | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Traverse Layer by Layer in Spiral Form

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(n * sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int cnt = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
        // direction 1 - traverse from left to right
        for (int ptr = layer; ptr < n - layer; ptr++) {
            result[layer][ptr] = cnt++;
        }
        // direction 2 - traverse from top to bottom
        for (int ptr = layer + 1; ptr < n - layer; ptr++) {
            result[ptr][n - layer - 1] = cnt++;
        }
        // direction 3 - traverse from right to left
        for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
            result[n - layer - 1][ptr] = cnt++;
        }
        // direction 4 - traverse from bottom to top
        for (int ptr = n - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] result = new int [n][];
        for (int i = 0; i < n; i++) result[i] = new int[n];
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++)
                result[layer][ptr] = cnt++;
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++)
                result[ptr][n - layer - 1] = cnt++;
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--)
                result[n - layer - 1][ptr] = cnt++;
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--)
                result[ptr][layer] = cnt++;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateMatrix(n int) [][]int {
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
    }
    cnt := 1
    for layer := 0; layer < (n+1)/2; layer++ {
        // direction 1 - traverse from left to right
        for ptr := layer; ptr < n-layer; ptr++ {
            result[layer][ptr] = cnt
            cnt++
        }
        // direction 2 - traverse from top to bottom
        for ptr := layer + 1; ptr < n-layer; ptr++ {
            result[ptr][n-layer-1] = cnt
            cnt++
        }
        // direction 3 - traverse from right to left
        for ptr := n - layer - 2; ptr >= layer; ptr-- {
            result[n-layer-1][ptr] = cnt
            cnt++
        }
        // direction 4 - traverse from bottom to top
        for ptr := n - layer - 2; ptr > layer; ptr-- {
            result[ptr][layer] = cnt
            cnt++
        }
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[n - layer - 1][n - ptr - 1] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = layer + 1; ptr < n - layer - 1; ptr++) {
                result[n - ptr - 1][layer] = cnt++;
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generateMatrix = function (n) {
    let result = Array.from({ length: n }, () => Array(n).fill(0));
    let cnt = 1;
    for (let layer = 0; layer < Math.floor((n + 1) / 2); layer++) {
        // direction 1 - traverse from left to right
        for (let ptr = layer; ptr < n - layer; ptr++) {
            result[layer][ptr] = cnt++;
        }
        // direction 2 - traverse from top to bottom
        for (let ptr = layer + 1; ptr < n - layer; ptr++) {
            result[ptr][n - layer - 1] = cnt++;
        }
        // direction 3 - traverse from right to left
        for (let ptr = n - layer - 2; ptr >= layer; ptr--) {
            result[n - layer - 1][ptr] = cnt++;
        }
        // direction 4 - traverse from bottom to top
        for (let ptr = n - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        result = [[0] * n for _ in range(n)]
        cnt = 1
        for layer in range((n + 1) // 2):
            # direction 1 - traverse from left to right
            for ptr in range(layer, n - layer):
                result[layer][ptr] = cnt
                cnt += 1
            # direction 2 - traverse from top to bottom
            for ptr in range(layer + 1, n - layer):
                result[ptr][n - layer - 1] = cnt
                cnt += 1
            # direction 3 - traverse from right to left
            for ptr in range(n - layer - 2, layer - 1, -1):
                result[n - layer - 1][ptr] = cnt
                cnt += 1
            # direction 4 - traverse from bottom to top
            for ptr in range(n - layer - 2, layer, -1):
                result[ptr][layer] = cnt
                cnt += 1
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateMatrix(n: number): number[][] {
    let result = Array.from({ length: n }, () => Array(n).fill(0));
    let cnt = 1;
    for (let layer = 0; layer < Math.floor((n + 1) / 2); layer++) {
        // direction 1 - traverse from left to right
        for (let ptr = layer; ptr < n - layer; ptr++) {
            result[layer][ptr] = cnt++;
        }
        // direction 2 - traverse from top to bottom
        for (let ptr = layer + 1; ptr < n - layer; ptr++) {
            result[ptr][n - layer - 1] = cnt++;
        }
        // direction 3 - traverse from right to left
        for (let ptr = n - layer - 2; ptr >= layer; ptr--) {
            result[n - layer - 1][ptr] = cnt++;
        }
        // direction 4 - traverse from bottom to top
        for (let ptr = n - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
}
```

</details>

<br>

## Approach 2: Optimized spiral traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int floorMod(int x, int y) { return ((x % y) + y) % y; }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);
            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] res = new int [n][];
        for (int i = 0; i < n; i++) res[i] = new int[n];
        int[][] helpers =
            new int [4][] { new int[2] { 0, 1 }, new int[2] { 1, 0 },
                            new int[2] { 0, -1 }, new int[2] { -1, 0 } };
        int val = 1, d = 0, row = 0, col = 0;
        while (val <= n * n) {
            res[row][col] = val++;
            int r = (row + helpers[d][0] + n) % n;
            int c = (col + helpers[d][1] + n) % n;
            if (res[r][c] != 0)
                d = (d + 1) % 4;
            row += helpers[d][0];
            col += helpers[d][1];
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func generateMatrix(n int) [][]int {
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
    }
    dirs := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    d := 0
    row := 0
    col := 0
    cnt := 1
    for cnt <= n*n {
        result[row][col] = cnt
        cnt++
        newRow := (row + dirs[d][0] + n) % n
        newCol := (col + dirs[d][1] + n) % n
        // change direction if next cell is non zero
        if result[newRow][newCol] != 0 {
            d = (d + 1) % 4
        }
        row += dirs[d][0]
        col += dirs[d][1]
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int cnt = 1;
        int dir[][] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = Math.floorMod(row + dir[d][0], n);
            int c = Math.floorMod(col + dir[d][1], n);

            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;

            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var generateMatrix = function (n) {
    const result = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const dirs = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    let d = 0;
    let row = 0;
    let col = 0;
    let cnt = 1;
    while (cnt <= n * n) {
        result[row][col] = cnt++;
        let newRow = (row + (dirs[d][0] % n) + n) % n;
        let newCol = (col + (dirs[d][1] % n) + n) % n;
        //change direction if next cell is non zero
        if (result[newRow][newCol] != 0) d = (d + 1) % 4;
        row += dirs[d][0];
        col += dirs[d][1];
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        # Converting 2D space to 1D vector
        def idx_convert_1D_2D(idx):
            return idx // n, idx % n

        # Checking for out of bound condition
        def is_out_of_bound(row, col):
            return row < 0 or row >= n or col < 0 or col >= n

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        result = [[0] * n for _ in range(n)]
        cur_dir_idx = 0
        row, col = 0, 0
        for i in range(1, n * n + 1):
            result[row][col] = i
            dx, dy = dirs[cur_dir_idx]
            if (
                is_out_of_bound(row + dx, col + dy)
                or result[row + dx][col + dy] > 0
            ):
                cur_dir_idx = (cur_dir_idx + 1) % 4  # change directions
            dx, dy = dirs[cur_dir_idx]
            row, col = row + dx, col + dy
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function generateMatrix(n: number): number[][] {
    let result: number[][] = Array.from(Array(n), () => new Array(n).fill(0));
    let dirs = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    let d = 0;
    let row = 0;
    let col = 0;
    let cnt = 1;
    while (cnt <= n * n) {
        result[row][col] = cnt++;
        let newRow = (row + (dirs[d][0] % n) + n) % n;
        let newCol = (col + (dirs[d][1] % n) + n) % n;
        //change direction if next cell is non zero
        if (result[newRow][newCol] != 0) d = (d + 1) % 4;
        row += dirs[d][0];
        col += dirs[d][1];
    }
    return result;
}
```

</details>
