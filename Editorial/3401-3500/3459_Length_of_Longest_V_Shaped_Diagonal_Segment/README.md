# 3459. Length of Longest V-Shaped Diagonal Segment

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/)  
`Array` `Dynamic Programming` `Memoization` `Matrix`

**Problem Link:** [LeetCode 3459 - Length of Longest V-Shaped Diagonal Segment](https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/)

## Problem

You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

A V-shaped diagonal segment is defined as:

- The segment starts with 1.
- The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
- The segment:

		Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
		Continues the sequence in the same diagonal direction.
		Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.

Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- n == grid.length
- m == grid[i].length
- 1 <= n, m <= 500
- grid[i][j] is either 0, 1 or 2.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3459. Length of Longest V-Shaped Diagonal Segment

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Memoization Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Memoization Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX_N 500

const int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int memo[MAX_N][MAX_N][4][2][3];

int dfs(int cx, int cy, int direction, int turn, int target, int** grid, int m,
        int n) {
    int nx = cx + dirs[direction][0];
    int ny = cy + dirs[direction][1];
    /* If it goes beyond the boundary or the next node's value is not the target
     * value, then return */
    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
        return 0;
    }
    if (memo[nx][ny][direction][turn][2 - target] != -1) {
        return memo[nx][ny][direction][turn][2 - target];
    }
    /* Continue walking in the original direction. */
    int maxStep = dfs(nx, ny, direction, turn, 2 - target, grid, m, n);
    if (turn) {
        /* Clockwise rotate 90 degrees turn */
        maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, 0, 2 - target,
                                    grid, m, n));
    }
    memo[nx][ny][direction][turn][2 - target] = maxStep + 1;
    return maxStep + 1;
}

int lenOfVDiagonal(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    memset(memo, -1, sizeof(memo));

    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                for (int direction = 0; direction < 4; direction++) {
                    res = fmax(res, dfs(i, j, direction, 1, 2, grid, m, n) + 1);
                }
            }
        }
    }

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));

        function<int(int, int, int, bool, int)> dfs =
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];
            /* If it goes beyond the boundary or the next node's value is not
             * the target value, then return */
            if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                grid[nx][ny] != target) {
                return 0;
            }
            if (memo[nx][ny][direction][turn] != -1) {
                return memo[nx][ny][direction][turn];
            }

            /* Continue walking in the original direction. */
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);
            if (turn) {
                /* Clockwise rotate 90 degrees turn */
                maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,
                                            2 - target));
            }
            memo[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
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
    private readonly int[][] DIRS =
        new int[][] { new int[] { 1, 1 }, new int[] { 1, -1 },
                      new int[] { -1, -1 }, new int[] { -1, 1 } };
    private int[,,,] memo;
    private int[][] grid;
    private int m, n;

    public int LenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        m = grid.Length;
        n = grid[0].Length;
        memo = new int[m, n, 4, 2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 2; l++) {
                        memo[i, j, k, l] = -1;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; direction++) {
                        res = Math.Max(res, Dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }

    private int Dfs(int cx, int cy, int direction, bool turn, int target) {
        int nx = cx + DIRS[direction][0];
        int ny = cy + DIRS[direction][1];
        /* If it goes beyond the boundary or the next node's value is not the
         * target value, then return */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        int turnInt = turn ? 1 : 0;
        if (memo[nx, ny, direction, turnInt] != -1) {
            return memo[nx, ny, direction, turnInt];
        }

        /* Continue walking in the original direction. */
        int maxStep = Dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* Clockwise rotate 90 degrees turn */
            maxStep = Math.Max(
                maxStep, Dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
        }
        memo[nx, ny, direction, turnInt] = maxStep + 1;
        return maxStep + 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lenOfVDiagonal(grid [][]int) int {
    dirs := [4][2]int{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}
    m, n := len(grid), len(grid[0])
    memo := make([][][4][2]int, m)
    for i := range memo {
        memo[i] = make([][4][2]int, n)
        for j := range memo[i] {
            for k := range memo[i][j] {
                for l := range memo[i][j][k] {
                    memo[i][j][k][l] = -1
                }
            }
        }
    }

    var dfs func(cx, cy, direction int, turn bool, target int) int
    dfs = func(cx, cy, direction int, turn bool, target int) int {
        nx, ny := cx+dirs[direction][0], cy+dirs[direction][1]
        /* If it goes beyond the boundary or the next node's value is not the target value, then return */
        if nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target {
            return 0
        }

        turnInt := 0
        if turn {
            turnInt = 1
        }
        if memo[nx][ny][direction][turnInt] != -1 {
            return memo[nx][ny][direction][turnInt]
        }

        /* Continue walking in the original direction. */
        maxStep := dfs(nx, ny, direction, turn, 2-target)
        if turn {
            /* Clockwise rotate 90 degrees turn */
            maxStep = max(maxStep, dfs(nx, ny, (direction+1)%4, false, 2-target))
        }
        memo[nx][ny][direction][turnInt] = maxStep + 1
        return maxStep + 1
    }

    res := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 1 {
                for direction := 0; direction < 4; direction++ {
                    res = max(res, dfs(i, j, direction, true, 2)+1)
                }
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

    private static final int[][] DIRS = {
        { 1, 1 },
        { 1, -1 },
        { -1, -1 },
        { -1, 1 },
    };
    private int[][][][] memo;
    private int[][] grid;
    private int m, n;

    public int lenOfVDiagonal(int[][] grid) {
        this.grid = grid;
        this.m = grid.length;
        this.n = grid[0].length;
        this.memo = new int[m][n][4][2];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    Arrays.fill(memo[i][j][k], -1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; direction++) {
                        res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }

    private int dfs(int cx, int cy, int direction, boolean turn, int target) {
        int nx = cx + DIRS[direction][0];
        int ny = cy + DIRS[direction][1];
        /* If it goes beyond the boundary or the next node's value is not the target value, then return */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        int turnInt = turn ? 1 : 0;
        if (memo[nx][ny][direction][turnInt] != -1) {
            return memo[nx][ny][direction][turnInt];
        }

        /* Continue walking in the original direction. */
        int maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* Clockwise rotate 90 degrees turn */
            maxStep = Math.max(
                maxStep,
                dfs(nx, ny, (direction + 1) % 4, false, 2 - target)
            );
        }
        memo[nx][ny][direction][turnInt] = maxStep + 1;
        return maxStep + 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lenOfVDiagonal = function (grid) {
    const DIRS = [
        [1, 1],
        [1, -1],
        [-1, -1],
        [-1, 1],
    ];
    const m = grid.length,
        n = grid[0].length;
    const memo = new Array(m * n * 8).fill(-1);

    function dfs(cx, cy, direction, turn, target) {
        const nx = cx + DIRS[direction][0];
        const ny = cy + DIRS[direction][1];
        /* If it goes beyond the boundary or the next node's value is not the target
         * value, then return */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }

        const turnInt = turn ? 1 : 0;
        const index = nx * n * 8 + ny * 8 + direction * 2 + turnInt;
        if (memo[index] !== -1) {
            return memo[index];
        }

        /* Continue walking in the original direction. */
        let maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* Clockwise rotate 90 degrees turn */
            maxStep = Math.max(
                maxStep,
                dfs(nx, ny, (direction + 1) % 4, false, 2 - target),
            );
        }
        memo[index] = maxStep + 1;
        return maxStep + 1;
    }

    let res = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                for (let direction = 0; direction < 4; direction++) {
                    res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                }
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
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        DIRS = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
        m, n = len(grid), len(grid[0])

        @cache
        def dfs(cx, cy, direction, turn, target):
            nx, ny = cx + DIRS[direction][0], cy + DIRS[direction][1]
            # If it goes beyond the boundary or the next node's value is not the target value, then return
            if nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != target:
                return 0
            turn_int = 1 if turn else 0
            # Continue walking in the original direction.
            max_step = dfs(nx, ny, direction, turn, 2 - target)
            if turn:
                # Clockwise rotate 90 degrees turn
                max_step = max(
                    max_step,
                    dfs(nx, ny, (direction + 1) % 4, False, 2 - target),
                )
            return max_step + 1

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for direction in range(4):
                        res = max(res, dfs(i, j, direction, True, 2) + 1)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lenOfVDiagonal(grid: number[][]): number {
    const DIRS = [
        [1, 1],
        [1, -1],
        [-1, -1],
        [-1, 1],
    ];
    const m = grid.length,
        n = grid[0].length;
    const memo: number[] = new Array(m * n * 8).fill(-1);

    function dfs(
        cx: number,
        cy: number,
        direction: number,
        turn: boolean,
        target: number,
    ): number {
        const nx = cx + DIRS[direction][0];
        const ny = cy + DIRS[direction][1];
        /* If it goes beyond the boundary or the next node's value is not the target
         * value, then return */
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] !== target) {
            return 0;
        }

        const turnInt = turn ? 1 : 0;
        const index = nx * n * 8 + ny * 8 + direction * 2 + turnInt;
        if (memo[index] !== -1) {
            return memo[index];
        }

        /* Continue walking in the original direction. */
        let maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            /* Clockwise rotate 90 degrees turn */
            maxStep = Math.max(
                maxStep,
                dfs(nx, ny, (direction + 1) % 4, false, 2 - target),
            );
        }
        memo[index] = maxStep + 1;
        return maxStep + 1;
    }

    let res = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                for (let direction = 0; direction < 4; direction++) {
                    res = Math.max(res, dfs(i, j, direction, true, 2) + 1);
                }
            }
        }
    }
    return res;
}
```

</details>
