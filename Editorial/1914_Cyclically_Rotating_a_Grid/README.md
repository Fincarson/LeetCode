# 1914. Cyclically Rotating a Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/cyclically-rotating-a-grid/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 1914 - Cyclically Rotating a Grid](https://leetcode.com/problems/cyclically-rotating-a-grid/)

## Problem

You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:

Return the matrix after applying k cyclic rotations to it.

### Example 1

```text
Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
```

### Example 2

```text
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 50
- Both m and n are even integers.
- 1 <= grid[i][j] <= 5000
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

# Editorial - 1914. Cyclically Rotating a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumerate Each Layer | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumerate Each Layer

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k,
                 int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int nlayer = fmin(m / 2, n / 2);  // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for (int layer = 0; layer < nlayer; ++layer) {
        int maxSize = 2 * (m + n - 4 * layer - 2);
        int* r = (int*)malloc(maxSize * sizeof(int));
        int* c = (int*)malloc(maxSize * sizeof(int));
        int* val = (int*)malloc(
            maxSize *
            sizeof(int));  // each element's row index, column index, and value
        int idx = 0;

        for (int i = layer; i < m - layer - 1; ++i) {  // down
            r[idx] = i;
            c[idx] = layer;
            val[idx] = grid[i][layer];
            idx++;
        }
        for (int j = layer; j < n - layer - 1; ++j) {  // right
            r[idx] = m - layer - 1;
            c[idx] = j;
            val[idx] = grid[m - layer - 1][j];
            idx++;
        }
        for (int i = m - layer - 1; i > layer; --i) {  // up
            r[idx] = i;
            c[idx] = n - layer - 1;
            val[idx] = grid[i][n - layer - 1];
            idx++;
        }
        for (int j = n - layer - 1; j > layer; --j) {  // left
            r[idx] = layer;
            c[idx] = j;
            val[idx] = grid[layer][j];
            idx++;
        }

        int total = idx;     // total number of elements in each layer
        int kk = k % total;  // equivalent number of rotations
        // find the value at each index after rotation
        for (int i = 0; i < total; ++i) {
            int pos =
                (i + total - kk) %
                total;  // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[pos];
        }

        free(r);
        free(c);
        free(val);
    }
    return grid;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int nlayer = min(m / 2, n / 2);  // level count
        // enumerate each layer counterclockwise starting from the top-left
        // corner
        for (int layer = 0; layer < nlayer; ++layer) {
            vector<int> r, c,
                val;  // each element's row index, column index, and value
            for (int i = layer; i < m - layer - 1; ++i) {  // down
                r.push_back(i);
                c.push_back(layer);
                val.push_back(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j) {  // right
                r.push_back(m - layer - 1);
                c.push_back(j);
                val.push_back(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i) {  // up
                r.push_back(i);
                c.push_back(n - layer - 1);
                val.push_back(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; --j) {  // left
                r.push_back(layer);
                c.push_back(j);
                val.push_back(grid[layer][j]);
            }
            int total = val.size();  // total number of elements in each layer
            int kk = k % total;      // equivalent number of rotations
            // find the value at each index after rotation
            for (int i = 0; i < total; ++i) {
                int idx =
                    (i + total - kk) % total;  // the index corresponding to the
                                               // value after rotation
                grid[r[i]][c[i]] = val[idx];
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
    public int[][] RotateGrid(int[][] grid, int k) {
        int m = grid.Length;
        int n = grid[0].Length;
        int nlayer = Math.Min(m / 2, n / 2);  // level count
        // enumerate each layer counterclockwise starting from the top-left
        // corner
        for (int layer = 0; layer < nlayer; ++layer) {
            List<int> r = new List<int>();
            List<int> c = new List<int>();
            List<int> val = new List<int>();  // each element's row index,
                                              // column index, and value
            for (int i = layer; i < m - layer - 1; ++i) {  // down
                r.Add(i);
                c.Add(layer);
                val.Add(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j) {  // right
                r.Add(m - layer - 1);
                c.Add(j);
                val.Add(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i) {  // up
                r.Add(i);
                c.Add(n - layer - 1);
                val.Add(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; --j) {  // left
                r.Add(layer);
                c.Add(j);
                val.Add(grid[layer][j]);
            }
            int total = val.Count;  // total number of elements in each layer
            int kk = k % total;     // equivalent number of rotations
            // find the value at each index after rotation
            for (int i = 0; i < total; ++i) {
                int idx =
                    (i + total - kk) % total;  // the index corresponding to the
                                               // value after rotation
                grid[r[i]][c[i]] = val[idx];
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
func rotateGrid(grid [][]int, k int) [][]int {
    m := len(grid)
    n := len(grid[0])
    nlayer := min(m / 2, n / 2)   // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for layer := 0; layer < nlayer; layer++ {
        r := make([]int, 0)
        c := make([]int, 0)
        val := make([]int, 0)   // each element's row index, column index, and value
        for i := layer; i < m - layer - 1; i++ {   // down
            r = append(r, i)
            c = append(c, layer)
            val = append(val, grid[i][layer])
        }
        for j := layer; j < n - layer - 1; j++ {   // right
            r = append(r, m - layer - 1)
            c = append(c, j)
            val = append(val, grid[m-layer - 1][j])
        }
        for i := m - layer - 1; i > layer; i-- {   // up
            r = append(r, i)
            c = append(c, n - layer - 1)
            val = append(val, grid[i][n - layer - 1])
        }
        for j := n - layer - 1; j > layer; j-- {   // left
            r = append(r, layer)
            c = append(c, j)
            val = append(val, grid[layer][j])
        }
        total := len(val)   // total number of elements in each layer
        kk := k % total   // equivalent number of rotations
        // find the value at each index after rotation
        for i := 0; i < total; i++ {
            idx := (i + total - kk) % total   // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[idx]
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

    public int[][] rotateGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int nlayer = Math.min(m / 2, n / 2); // level count
        // enumerate each layer counterclockwise starting from the top-left corner
        for (int layer = 0; layer < nlayer; ++layer) {
            List<Integer> r = new ArrayList<>();
            List<Integer> c = new ArrayList<>();
            List<Integer> val = new ArrayList<>(); // each element's row index, column index, and value
            for (int i = layer; i < m - layer - 1; ++i) { // down
                r.add(i);
                c.add(layer);
                val.add(grid[i][layer]);
            }
            for (int j = layer; j < n - layer - 1; ++j) { // right
                r.add(m - layer - 1);
                c.add(j);
                val.add(grid[m - layer - 1][j]);
            }
            for (int i = m - layer - 1; i > layer; --i) { // up
                r.add(i);
                c.add(n - layer - 1);
                val.add(grid[i][n - layer - 1]);
            }
            for (int j = n - layer - 1; j > layer; --j) { // left
                r.add(layer);
                c.add(j);
                val.add(grid[layer][j]);
            }
            int total = val.size(); // total number of elements in each layer
            int kk = k % total; // equivalent number of rotations
            // find the value at each index after rotation
            for (int i = 0; i < total; ++i) {
                int idx = (i + total - kk) % total; // the index corresponding to the value after rotation
                grid[r.get(i)][c.get(i)] = val.get(idx);
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
var rotateGrid = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const nlayer = Math.min(Math.floor(m / 2), Math.floor(n / 2)); // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for (let layer = 0; layer < nlayer; ++layer) {
        const r = [];
        const c = [];
        const val = []; // each element's row index, column index, and value
        for (let i = layer; i < m - layer - 1; ++i) {
            // down
            r.push(i);
            c.push(layer);
            val.push(grid[i][layer]);
        }
        for (let j = layer; j < n - layer - 1; ++j) {
            // right
            r.push(m - layer - 1);
            c.push(j);
            val.push(grid[m - layer - 1][j]);
        }
        for (let i = m - layer - 1; i > layer; --i) {
            // up
            r.push(i);
            c.push(n - layer - 1);
            val.push(grid[i][n - layer - 1]);
        }
        for (let j = n - layer - 1; j > layer; --j) {
            // left
            r.push(layer);
            c.push(j);
            val.push(grid[layer][j]);
        }
        const total = val.length; // total number of elements in each layer
        const kk = k % total; // equivalent number of rotations
        // find the value at each index after rotation
        for (let i = 0; i < total; ++i) {
            const idx = (i + total - kk) % total; // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[idx];
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
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        nlayer = min(m // 2, n // 2)  # level count
        # enumerate each layer counterclockwise starting from the top-left corner
        for layer in range(nlayer):
            r = []  # row index of each element
            c = []  # column index of each element
            val = []  # value of each element
            for i in range(layer, m - layer - 1):  # down
                r.append(i)
                c.append(layer)
                val.append(grid[i][layer])
            for j in range(layer, n - layer - 1):  # right
                r.append(m - layer - 1)
                c.append(j)
                val.append(grid[m - layer - 1][j])
            for i in range(m - layer - 1, layer, -1):  # up
                r.append(i)
                c.append(n - layer - 1)
                val.append(grid[i][n - layer - 1])
            for j in range(n - layer - 1, layer, -1):  # left
                r.append(layer)
                c.append(j)
                val.append(grid[layer][j])
            total = len(val)  # total number of elements in each layer
            kk = k % total  # equivalent number of rotations
            # find the value at each index after rotation
            for i in range(total):
                idx = (
                    i + total - kk
                ) % total  # the index corresponding to the value after rotation
                grid[r[i]][c[i]] = val[idx]
        return grid
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rotateGrid(grid: number[][], k: number): number[][] {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const nlayer: number = Math.min(Math.floor(m / 2), Math.floor(n / 2)); // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for (let layer = 0; layer < nlayer; ++layer) {
        const r: number[] = [];
        const c: number[] = [];
        const val: number[] = []; // each element's row index, column index, and value
        for (let i = layer; i < m - layer - 1; ++i) {
            // down
            r.push(i);
            c.push(layer);
            val.push(grid[i][layer]);
        }
        for (let j = layer; j < n - layer - 1; ++j) {
            // right
            r.push(m - layer - 1);
            c.push(j);
            val.push(grid[m - layer - 1][j]);
        }
        for (let i = m - layer - 1; i > layer; --i) {
            // up
            r.push(i);
            c.push(n - layer - 1);
            val.push(grid[i][n - layer - 1]);
        }
        for (let j = n - layer - 1; j > layer; --j) {
            // left
            r.push(layer);
            c.push(j);
            val.push(grid[layer][j]);
        }
        const total: number = val.length; // total number of elements in each layer
        const kk: number = k % total; // equivalent number of rotations
        // find the value at each index after rotation
        for (let i = 0; i < total; ++i) {
            const idx: number = (i + total - kk) % total; // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[idx];
        }
    }
    return grid;
}
```

</details>
