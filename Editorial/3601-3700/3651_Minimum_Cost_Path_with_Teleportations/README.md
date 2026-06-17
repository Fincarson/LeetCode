# 3651. Minimum Cost Path with Teleportations

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-path-with-teleportations/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 3651 - Minimum Cost Path with Teleportations](https://leetcode.com/problems/minimum-cost-path-with-teleportations/)

## Problem

You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottomÃ¢â‚¬Âright cell (m - 1, n - 1).

There are two types of moves available:

- Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
- Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.

Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).

### Example 1

### Example 2

## Constraints

- 2 <= m, n <= 80
- m == grid.length
- n == grid[i].length
- 0 <= grid[i][j] <= 104
- 0 <= k <= 10

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3651. Minimum Cost Path with Teleportations

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
static int** gridPtr = NULL;

static int cmp(const void* a, const void* b) {
    int* pa = (int*)a;
    int* pb = (int*)b;
    return gridPtr[pa[0]][pa[1]] - gridPtr[pb[0]][pb[1]];
}

int minCost(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize, n = gridColSize[0];
    gridPtr = grid;
    int points[m * n][2], idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            points[idx][0] = i, points[idx++][1] = j;
        }
    }
    qsort(points, m * n, sizeof(points[0]), cmp);
    int costs[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            costs[i][j] = INT_MAX;
        }
    }
    for (int t = 0; t <= k; t++) {
        int minCost = INT_MAX;
        for (int i = 0, j = 0; i < m * n; i++) {
            minCost = fmin(minCost, costs[points[i][0]][points[i][1]]);
            if (i + 1 < m * n && grid[points[i][0]][points[i][1]] ==
                                     grid[points[i + 1][0]][points[i + 1][1]]) {
                continue;
            }
            for (int r = j; r <= i; r++) {
                costs[points[r][0]][points[r][1]] = minCost;
            }
            j = i + 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    costs[i][j] = 0;
                    continue;
                }
                if (i != m - 1) {
                    costs[i][j] =
                        fmin(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                }
                if (j != n - 1) {
                    costs[i][j] =
                        fmin(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                }
            }
        }
    }
    return costs[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
             [&](const auto& p1, const auto& p2) -> bool {
                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
             });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost =
                    min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] ==
                        grid[points[i + 1].first][points[i + 1].second]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] =
                            min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] =
                            min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinCost(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        var points = new List<(int, int)>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.Add((i, j));
            }
        }
        points.Sort((p1, p2) => grid[p1.Item1][p1.Item2].CompareTo(
                        grid[p2.Item1][p2.Item2]));
        int[,] costs = new int[m, n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                costs[i, j] = int.MaxValue;
            }
        }
        for (int t = 0; t <= k; t++) {
            int minCost = int.MaxValue;
            for (int i = 0, j = 0; i < points.Count; i++) {
                minCost =
                    Math.Min(minCost, costs[points[i].Item1, points[i].Item2]);
                if (i + 1 < points.Count &&
                    grid[points[i].Item1][points[i].Item2] ==
                        grid[points[i + 1].Item1][points[i + 1].Item2]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].Item1, points[r].Item2] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i, j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i, j] = Math.Min(
                            costs[i, j], costs[i + 1, j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i, j] = Math.Min(
                            costs[i, j], costs[i, j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0, 0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minCost(grid [][]int, k int) int {
    m, n := len(grid), len(grid[0])
    type point struct{ x, y int }
    points := make([]point, 0, m * n)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            points = append(points, point{ i, j })
        }
    }
    sort.Slice(points, func(i, j int) bool {
        return grid[points[i].x][points[i].y] < grid[points[j].x][points[j].y]
    })
    costs := make([][]int, m)
    for i := range costs {
        costs[i] = make([]int, n)
        for j := range costs[i] {
            costs[i][j] = math.MaxInt
        }
    }
    for t := 0; t <= k; t++ {
        minCost := math.MaxInt
        for i, j := 0, 0; i < len(points); i++ {
            minCost = min(minCost, costs[points[i].x][points[i].y])
            if i + 1 < len(points) && grid[points[i].x][points[i].y] == grid[points[i + 1].x][points[i + 1].y] {
                continue
            }
            for r := j; r <= i; r++ {
                costs[points[r].x][points[r].y] = minCost
            }
            j = i + 1
        }
        for i := m - 1; i >= 0; i-- {
            for j := n - 1; j >= 0; j-- {
                if i == m - 1 && j == n - 1 {
                    costs[i][j] = 0
                    continue
                }
                if i != m - 1 {
                    costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j])
                }
                if j != n - 1 {
                    costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1])
                }
            }
        }
    }
    return costs[0][0]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minCost(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        List<int[]> points = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.add(new int[] { i, j });
            }
        }
        points.sort(Comparator.comparingInt(p -> grid[p[0]][p[1]]));
        int[][] costs = new int[m][n];
        for (int[] row : costs) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        for (int t = 0; t <= k; t++) {
            int minCost = Integer.MAX_VALUE;
            for (int i = 0, j = 0; i < points.size(); i++) {
                minCost = Math.min(
                    minCost,
                    costs[points.get(i)[0]][points.get(i)[1]]
                );
                if (
                    i + 1 < points.size() &&
                    grid[points.get(i)[0]][points.get(i)[1]] ==
                    grid[points.get(i + 1)[0]][points.get(i + 1)[1]]
                ) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points.get(r)[0]][points.get(r)[1]] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] = Math.min(
                            costs[i][j],
                            costs[i + 1][j] + grid[i + 1][j]
                        );
                    }
                    if (j != n - 1) {
                        costs[i][j] = Math.min(
                            costs[i][j],
                            costs[i][j + 1] + grid[i][j + 1]
                        );
                    }
                }
            }
        }
        return costs[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function minCost(grid, k) {
    const m = grid.length,
        n = grid[0].length;
    const points = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            points.push([i, j]);
        }
    }
    points.sort((a, b) => grid[a[0]][a[1]] - grid[b[0]][b[1]]);
    const costs = Array.from({ length: m }, () =>
        Array(n).fill(Number.MAX_SAFE_INTEGER),
    );
    for (let t = 0; t <= k; t++) {
        let minCost = Number.MAX_SAFE_INTEGER;
        for (let i = 0, j = 0; i < points.length; i++) {
            minCost = Math.min(minCost, costs[points[i][0]][points[i][1]]);
            if (
                i + 1 < points.length &&
                grid[points[i][0]][points[i][1]] ===
                    grid[points[i + 1][0]][points[i + 1][1]]
            ) {
                continue;
            }
            for (let r = j; r <= i; r++) {
                costs[points[r][0]][points[r][1]] = minCost;
            }
            j = i + 1;
        }
        for (let i = m - 1; i >= 0; i--) {
            for (let j = n - 1; j >= 0; j--) {
                if (i === m - 1 && j === n - 1) {
                    costs[i][j] = 0;
                    continue;
                }
                if (i !== m - 1) {
                    costs[i][j] = Math.min(
                        costs[i][j],
                        costs[i + 1][j] + grid[i + 1][j],
                    );
                }
                if (j !== n - 1) {
                    costs[i][j] = Math.min(
                        costs[i][j],
                        costs[i][j + 1] + grid[i][j + 1],
                    );
                }
            }
        }
    }
    return costs[0][0];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, grid: list[list[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        points = [(i, j) for i in range(m) for j in range(n)]
        points.sort(key=lambda p: grid[p[0]][p[1]])
        costs = [[float("inf")] * n for _ in range(m)]
        for t in range(k + 1):
            minCost = float("inf")
            j = 0
            for i in range(len(points)):
                minCost = min(minCost, costs[points[i][0]][points[i][1]])
                if (
                    i + 1 < len(points)
                    and grid[points[i][0]][points[i][1]]
                    == grid[points[i + 1][0]][points[i + 1][1]]
                ):
                    i += 1
                    continue
                for r in range(j, i + 1):
                    costs[points[r][0]][points[r][1]] = minCost
                j = i + 1
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    if i == m - 1 and j == n - 1:
                        costs[i][j] = 0
                        continue
                    if i != m - 1:
                        costs[i][j] = min(
                            costs[i][j], costs[i + 1][j] + grid[i + 1][j]
                        )
                    if j != n - 1:
                        costs[i][j] = min(
                            costs[i][j], costs[i][j + 1] + grid[i][j + 1]
                        )
        return costs[0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minCost(grid: number[][], k: number): number {
    const m = grid.length,
        n = grid[0].length;
    const points: [number, number][] = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            points.push([i, j]);
        }
    }
    points.sort((a, b) => grid[a[0]][a[1]] - grid[b[0]][b[1]]);
    const costs = Array.from({ length: m }, () =>
        Array(n).fill(Number.MAX_SAFE_INTEGER),
    );
    for (let t = 0; t <= k; t++) {
        let minCost = Number.MAX_SAFE_INTEGER;
        for (let i = 0, j = 0; i < points.length; i++) {
            minCost = Math.min(minCost, costs[points[i][0]][points[i][1]]);
            if (
                i + 1 < points.length &&
                grid[points[i][0]][points[i][1]] ===
                    grid[points[i + 1][0]][points[i + 1][1]]
            ) {
                continue;
            }
            for (let r = j; r <= i; r++) {
                costs[points[r][0]][points[r][1]] = minCost;
            }
            j = i + 1;
        }
        for (let i = m - 1; i >= 0; i--) {
            for (let j = n - 1; j >= 0; j--) {
                if (i === m - 1 && j === n - 1) {
                    costs[i][j] = 0;
                    continue;
                }
                if (i !== m - 1) {
                    costs[i][j] = Math.min(
                        costs[i][j],
                        costs[i + 1][j] + grid[i + 1][j],
                    );
                }
                if (j !== n - 1) {
                    costs[i][j] = Math.min(
                        costs[i][j],
                        costs[i][j + 1] + grid[i][j + 1],
                    );
                }
            }
        }
    }
    return costs[0][0];
}
```

</details>
