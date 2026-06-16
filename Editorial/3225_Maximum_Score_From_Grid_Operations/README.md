# 3225. Maximum Score From Grid Operations

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-score-from-grid-operations/)  
`Array` `Dynamic Programming` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 3225 - Maximum Score From Grid Operations](https://leetcode.com/problems/maximum-score-from-grid-operations/)

## Problem

You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

Return the maximum score that can be achieved after some number of operations.

### Example 1

### Example 2

## Constraints

- 1 <= n == grid.length <= 100
- n == grid[i].length
- 0 <= grid[i][j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Difference Score in a Grid](https://leetcode.com/problems/maximum-difference-score-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3225. Maximum Score From Grid Operations

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
long long maximumScore(int** grid, int gridSize, int* gridColSize) {
    int n = gridColSize[0];
    if (n == 1) {
        return 0;
    }

    long long*** dp = (long long***)malloc(n * sizeof(long long**));
    for (int i = 0; i < n; i++) {
        dp[i] = (long long**)malloc((n + 1) * sizeof(long long*));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (long long*)calloc(n + 1, sizeof(long long));
        }
    }

    long long** prevMax = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        prevMax[i] = (long long*)calloc(n + 1, sizeof(long long));
    }
    long long** prevSuffixMax =
        (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        prevSuffixMax[i] = (long long*)calloc(n + 1, sizeof(long long));
    }
    long long** colSum = (long long**)malloc(n * sizeof(long long*));
    for (int c = 0; c < n; c++) {
        colSum[c] = (long long*)calloc(n + 1, sizeof(long long));
        for (int r = 1; r <= n; r++) {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int currH = 0; currH <= n; currH++) {
            for (int prevH = 0; prevH <= n; prevH++) {
                if (currH <= prevH) {
                    long long extraScore = colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] =
                        fmax(dp[i][currH][prevH],
                             prevSuffixMax[prevH][0] + extraScore);
                } else {
                    long long extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] =
                        fmax(dp[i][currH][prevH],
                             fmax(prevSuffixMax[prevH][currH],
                                  prevMax[prevH][currH] + extraScore));
                }
            }
        }

        for (int currH = 0; currH <= n; currH++) {
            prevMax[currH][0] = dp[i][currH][0];
            for (int prevH = 1; prevH <= n; prevH++) {
                long long penalty =
                    (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH]) : 0;
                prevMax[currH][prevH] = fmax(prevMax[currH][prevH - 1],
                                             dp[i][currH][prevH] - penalty);
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for (int prevH = n - 1; prevH >= 0; prevH--) {
                prevSuffixMax[currH][prevH] =
                    fmax(prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
            }
        }
    }

    long long ans = 0;
    for (int k = 0; k <= n; k++) {
        ans = fmax(ans, fmax(dp[n - 1][n][k], dp[n - 1][0][k]));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    for (int i = 0; i <= n; i++) {
        free(prevMax[i]);
        free(prevSuffixMax[i]);
    }
    free(prevMax);
    free(prevSuffixMax);

    for (int c = 0; c < n; c++) {
        free(colSum[c]);
    }
    free(colSum);

    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
using vll = std::vector<long long>;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) {
            return 0;
        }

        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
        vector<vll> prevMax(n + 1, vll(n + 1, 0));
        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
        vector<vll> colSum(n, vll(n + 1, 0));

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    if (currH <= prevH) {
                        long long extraScore =
                            colSum[i][prevH] - colSum[i][currH];
                        dp[i][currH][prevH] =
                            std::max(dp[i][currH][prevH],
                                     prevSuffixMax[prevH][0] + extraScore);
                    } else {
                        long long extraScore =
                            colSum[i - 1][currH] - colSum[i - 1][prevH];
                        dp[i][currH][prevH] = std::max(
                            {dp[i][currH][prevH], prevSuffixMax[prevH][currH],
                             prevMax[prevH][currH] + extraScore});
                    }
                }
            }

            for (int currH = 0; currH <= n; currH++) {
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long long penalty =
                        (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH])
                                        : 0;
                    prevMax[currH][prevH] =
                        std::max(prevMax[currH][prevH - 1],
                                 dp[i][currH][prevH] - penalty);
                }

                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH][prevH] = std::max(
                        prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
                }
            }
        }

        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaximumScore(int[][] grid) {
        int n = grid[0].Length;
        if (n == 1) {
            return 0;
        }

        long[,,] dp = new long[n, n + 1, n + 1];
        long[,] prevMax = new long[n + 1, n + 1];
        long[,] prevSuffixMax = new long[n + 1, n + 1];
        long[,] colSum = new long[n, n + 1];

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c, r] = colSum[c, r - 1] + grid[r - 1][c];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    if (currH <= prevH) {
                        long extraScore = colSum[i, prevH] - colSum[i, currH];
                        dp[i, currH, prevH] =
                            Math.Max(dp[i, currH, prevH],
                                     prevSuffixMax[prevH, 0] + extraScore);
                    } else {
                        long extraScore =
                            colSum[i - 1, currH] - colSum[i - 1, prevH];
                        dp[i, currH, prevH] = Math.Max(
                            dp[i, currH, prevH],
                            Math.Max(prevSuffixMax[prevH, currH],
                                     prevMax[prevH, currH] + extraScore));
                    }
                }
            }

            for (int currH = 0; currH <= n; currH++) {
                prevMax[currH, 0] = dp[i, currH, 0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long penalty = (prevH > currH)
                                       ? (colSum[i, prevH] - colSum[i, currH])
                                       : 0;
                    prevMax[currH, prevH] =
                        Math.Max(prevMax[currH, prevH - 1],
                                 dp[i, currH, prevH] - penalty);
                }

                prevSuffixMax[currH, n] = dp[i, currH, n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH, prevH] = Math.Max(
                        prevSuffixMax[currH, prevH + 1], dp[i, currH, prevH]);
                }
            }
        }

        long ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = Math.Max(ans, Math.Max(dp[n - 1, n, k], dp[n - 1, 0, k]));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumScore(grid [][]int) int64 {
    n := len(grid[0])
    if n == 1 {
        return 0
    }

    dp := make([][][]int64, n)
    for i := range dp {
        dp[i] = make([][]int64, n+1)
        for j := range dp[i] {
            dp[i][j] = make([]int64, n+1)
        }
    }

    prevMax := make([][]int64, n+1)
    for i := range prevMax {
        prevMax[i] = make([]int64, n+1)
    }
    prevSuffixMax := make([][]int64, n+1)
    for i := range prevSuffixMax {
        prevSuffixMax[i] = make([]int64, n+1)
    }

    colSum := make([][]int64, n)
    for c := 0; c < n; c++ {
        colSum[c] = make([]int64, n+1)
        for r := 1; r <= n; r++ {
            colSum[c][r] = colSum[c][r-1] + int64(grid[r-1][c])
        }
    }

    for i := 1; i < n; i++ {
        for currH := 0; currH <= n; currH++ {
            for prevH := 0; prevH <= n; prevH++ {
                if currH <= prevH {
                    extraScore := colSum[i][prevH] - colSum[i][currH]
                    dp[i][currH][prevH] = max(dp[i][currH][prevH], prevSuffixMax[prevH][0]+extraScore)
                } else {
                    extraScore := colSum[i-1][currH] - colSum[i-1][prevH]
                    dp[i][currH][prevH] = max(dp[i][currH][prevH],
                        max(prevSuffixMax[prevH][currH], prevMax[prevH][currH]+extraScore))
                }
            }
        }

        for currH := 0; currH <= n; currH++ {
            prevMax[currH][0] = dp[i][currH][0]
            for prevH := 1; prevH <= n; prevH++ {
                var penalty int64 = 0
                if prevH > currH {
                    penalty = colSum[i][prevH] - colSum[i][currH]
                }
                prevMax[currH][prevH] = max(prevMax[currH][prevH-1], dp[i][currH][prevH]-penalty)
            }

            prevSuffixMax[currH][n] = dp[i][currH][n]
            for prevH := n - 1; prevH >= 0; prevH-- {
                prevSuffixMax[currH][prevH] = max(prevSuffixMax[currH][prevH+1], dp[i][currH][prevH])
            }
        }
    }

    var ans int64 = 0
    for k := 0; k <= n; k++ {
        ans = max(ans, max(dp[n-1][n][k], dp[n-1][0][k]))
    }

    return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maximumScore(int[][] grid) {
        int n = grid[0].length;
        if (n == 1) {
            return 0;
        }

        long[][][] dp = new long[n][n + 1][n + 1];
        long[][] prevMax = new long[n + 1][n + 1];
        long[][] prevSuffixMax = new long[n + 1][n + 1];
        long[][] colSum = new long[n][n + 1];

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    if (currH <= prevH) {
                        long extraScore = colSum[i][prevH] - colSum[i][currH];
                        dp[i][currH][prevH] = Math.max(
                            dp[i][currH][prevH],
                            prevSuffixMax[prevH][0] + extraScore
                        );
                    } else {
                        long extraScore =
                            colSum[i - 1][currH] - colSum[i - 1][prevH];
                        dp[i][currH][prevH] = Math.max(
                            dp[i][currH][prevH],
                            Math.max(
                                prevSuffixMax[prevH][currH],
                                prevMax[prevH][currH] + extraScore
                            )
                        );
                    }
                }
            }

            for (int currH = 0; currH <= n; currH++) {
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long penalty = (prevH > currH)
                        ? (colSum[i][prevH] - colSum[i][currH])
                        : 0;
                    prevMax[currH][prevH] = Math.max(
                        prevMax[currH][prevH - 1],
                        dp[i][currH][prevH] - penalty
                    );
                }

                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH][prevH] = Math.max(
                        prevSuffixMax[currH][prevH + 1],
                        dp[i][currH][prevH]
                    );
                }
            }
        }

        long ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = Math.max(ans, Math.max(dp[n - 1][n][k], dp[n - 1][0][k]));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumScore = function (grid) {
    const n = grid[0].length;
    if (n === 1) {
        return 0;
    }

    const dp = [];
    const prevMax = Array.from({ length: n + 1 }, () =>
        new Array(n + 1).fill(0),
    );
    const prevSuffixMax = Array.from({ length: n + 1 }, () =>
        new Array(n + 1).fill(0),
    );
    const colSum = Array.from({ length: n }, () => new Array(n + 1).fill(0));

    for (let c = 0; c < n; c++) {
        dp[c] = Array.from({ length: n + 1 }, () => new Array(n + 1).fill(0));

        for (let r = 1; r <= n; r++) {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for (let i = 1; i < n; i++) {
        for (let currH = 0; currH <= n; currH++) {
            for (let prevH = 0; prevH <= n; prevH++) {
                if (currH <= prevH) {
                    const extraScore = colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] = Math.max(
                        dp[i][currH][prevH],
                        prevSuffixMax[prevH][0] + extraScore,
                    );
                } else {
                    const extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] = Math.max(
                        dp[i][currH][prevH],
                        prevSuffixMax[prevH][currH],
                        prevMax[prevH][currH] + extraScore,
                    );
                }
            }
        }

        for (let currH = 0; currH <= n; currH++) {
            prevMax[currH][0] = dp[i][currH][0];
            for (let prevH = 1; prevH <= n; prevH++) {
                const penalty =
                    prevH > currH ? colSum[i][prevH] - colSum[i][currH] : 0;
                prevMax[currH][prevH] = Math.max(
                    prevMax[currH][prevH - 1],
                    dp[i][currH][prevH] - penalty,
                );
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for (let prevH = n - 1; prevH >= 0; prevH--) {
                prevSuffixMax[currH][prevH] = Math.max(
                    prevSuffixMax[currH][prevH + 1],
                    dp[i][currH][prevH],
                );
            }
        }
    }

    let ans = 0;
    for (let k = 0; k <= n; k++) {
        ans = Math.max(ans, dp[n - 1][n][k], dp[n - 1][0][k]);
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        if n == 1:
            return 0

        dp = [[[0] * (n + 1) for _ in range(n + 1)] for _ in range(n)]
        prev_max = [[0] * (n + 1) for _ in range(n + 1)]
        prev_suffix_max = [[0] * (n + 1) for _ in range(n + 1)]
        col_sum = [[0] * (n + 1) for _ in range(n)]

        for c in range(n):
            for r in range(1, n + 1):
                col_sum[c][r] = col_sum[c][r - 1] + grid[r - 1][c]

        for i in range(1, n):
            for curr_h in range(n + 1):
                for prev_h in range(n + 1):
                    if curr_h <= prev_h:
                        extra_score = col_sum[i][prev_h] - col_sum[i][curr_h]
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            prev_suffix_max[prev_h][0] + extra_score,
                        )
                    else:
                        extra_score = (
                            col_sum[i - 1][curr_h] - col_sum[i - 1][prev_h]
                        )
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            prev_suffix_max[prev_h][curr_h],
                            prev_max[prev_h][curr_h] + extra_score,
                        )

            for curr_h in range(n + 1):
                prev_max[curr_h][0] = dp[i][curr_h][0]
                for prev_h in range(1, n + 1):
                    penalty = (
                        col_sum[i][prev_h] - col_sum[i][curr_h]
                        if prev_h > curr_h
                        else 0
                    )
                    prev_max[curr_h][prev_h] = max(
                        prev_max[curr_h][prev_h - 1],
                        dp[i][curr_h][prev_h] - penalty,
                    )

                prev_suffix_max[curr_h][n] = dp[i][curr_h][n]
                for prev_h in range(n - 1, -1, -1):
                    prev_suffix_max[curr_h][prev_h] = max(
                        prev_suffix_max[curr_h][prev_h + 1],
                        dp[i][curr_h][prev_h],
                    )

        ans = 0
        for k in range(n + 1):
            ans = max(ans, dp[n - 1][n][k], dp[n - 1][0][k])

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumScore(grid: number[][]): number {
    const n = grid[0].length;
    if (n === 1) {
        return 0;
    }

    const dp: number[][][] = [];
    const prevMax = Array.from({ length: n + 1 }, () =>
        new Array<number>(n + 1).fill(0),
    );
    const prevSuffixMax = Array.from({ length: n + 1 }, () =>
        new Array<number>(n + 1).fill(0),
    );
    const colSum = Array.from({ length: n }, () =>
        new Array<number>(n + 1).fill(0),
    );

    for (let c = 0; c < n; c++) {
        dp[c] = Array.from({ length: n + 1 }, () => new Array(n + 1).fill(0));

        for (let r = 1; r <= n; r++) {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for (let i = 1; i < n; i++) {
        for (let currH = 0; currH <= n; currH++) {
            for (let prevH = 0; prevH <= n; prevH++) {
                if (currH <= prevH) {
                    const extraScore = colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] = Math.max(
                        dp[i][currH][prevH],
                        prevSuffixMax[prevH][0] + extraScore,
                    );
                } else {
                    const extraScore =
                        colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] = Math.max(
                        dp[i][currH][prevH],
                        prevSuffixMax[prevH][currH],
                        prevMax[prevH][currH] + extraScore,
                    );
                }
            }
        }

        for (let currH = 0; currH <= n; currH++) {
            prevMax[currH][0] = dp[i][currH][0];
            for (let prevH = 1; prevH <= n; prevH++) {
                const penalty =
                    prevH > currH ? colSum[i][prevH] - colSum[i][currH] : 0;
                prevMax[currH][prevH] = Math.max(
                    prevMax[currH][prevH - 1],
                    dp[i][currH][prevH] - penalty,
                );
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for (let prevH = n - 1; prevH >= 0; prevH--) {
                prevSuffixMax[currH][prevH] = Math.max(
                    prevSuffixMax[currH][prevH + 1],
                    dp[i][currH][prevH],
                );
            }
        }
    }

    let ans = 0;
    for (let k = 0; k <= n; k++) {
        ans = Math.max(ans, dp[n - 1][n][k], dp[n - 1][0][k]);
    }

    return ans;
}
```

</details>
