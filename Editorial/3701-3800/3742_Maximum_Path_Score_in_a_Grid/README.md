# 3742. Maximum Path Score in a Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-path-score-in-a-grid/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 3742 - Maximum Path Score in a Grid](https://leetcode.com/problems/maximum-path-score-in-a-grid/)

## Problem

You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

Each cell contributes a specific score and incurs an associated cost, according to their cell values:

- 0: adds 0 to your score and costs 0.
- 1: adds 1 to your score and costs 1.
- 2: adds 2 to your score and costs 1. Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹

Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

### Example 1

### Example 2

## Constraints

- 1 <= m, n <= 200
- 0 <= k <= 103Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹
- Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹grid[0][0] == 0
- 0 <= grid[i][j] <= 2

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3742. Maximum Path Score in a Grid

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
int maxPathScore(int** grid, int m, int* gridColSize, int k) {
    int n = gridColSize[0];

    int*** dp = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc((k + 1) * sizeof(int));
            for (int c = 0; c <= k; c++) {
                dp[i][j][c] = INT_MIN;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int c = 0; c <= k; c++) {
                if (dp[i][j][c] == INT_MIN) continue;

                if (i + 1 < m) {
                    int val = grid[i + 1][j];
                    int cost = val == 0 ? 0 : 1;
                    if (c + cost <= k) {
                        int* target = &dp[i + 1][j][c + cost];
                        if (*target < dp[i][j][c] + val)
                            *target = dp[i][j][c] + val;
                    }
                }

                if (j + 1 < n) {
                    int val = grid[i][j + 1];
                    int cost = val == 0 ? 0 : 1;
                    if (c + cost <= k) {
                        int* target = &dp[i][j + 1][c + cost];
                        if (*target < dp[i][j][c] + val)
                            *target = dp[i][j][c] + val;
                    }
                }
            }
        }
    }

    int ans = INT_MIN;
    for (int c = 0; c <= k; c++) {
        if (dp[m - 1][n - 1][c] > ans) ans = dp[m - 1][n - 1][c];
    }

    return ans < 0 ? -1 : ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == INT_MIN) continue;
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] =
                                max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] =
                                max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxPathScore(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;

        int[,,] dp = new int[m, n, k + 1];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int c = 0; c <= k; c++) dp[i, j, c] = int.MinValue;

        dp[0, 0, 0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i, j, c] == int.MinValue)
                        continue;

                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = val == 0 ? 0 : 1;
                        if (c + cost <= k) {
                            dp[i + 1, j, c + cost] = Math.Max(
                                dp[i + 1, j, c + cost], dp[i, j, c] + val);
                        }
                    }

                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = val == 0 ? 0 : 1;
                        if (c + cost <= k) {
                            dp[i, j + 1, c + cost] = Math.Max(
                                dp[i, j + 1, c + cost], dp[i, j, c] + val);
                        }
                    }
                }
            }
        }

        int ans = int.MinValue;
        for (int c = 0; c <= k; c++) {
            ans = Math.Max(ans, dp[m - 1, n - 1, c]);
        }

        return ans < 0 ? -1 : ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxPathScore(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])

	const INF = math.MinInt32

	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, k+1)
			for c := range dp[i][j] {
				dp[i][j][c] = INF
			}
		}
	}

	dp[0][0][0] = 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for c := 0; c <= k; c++ {
				if dp[i][j][c] == INF {
					continue
				}

				if i+1 < m {
					val := grid[i+1][j]
					cost := 0
					if val != 0 {
						cost = 1
					}
					if c+cost <= k {
						if dp[i+1][j][c+cost] < dp[i][j][c]+val {
							dp[i+1][j][c+cost] = dp[i][j][c] + val
						}
					}
				}

				if j+1 < n {
					val := grid[i][j+1]
					cost := 0
					if val != 0 {
						cost = 1
					}
					if c+cost <= k {
						if dp[i][j+1][c+cost] < dp[i][j][c]+val {
							dp[i][j+1][c+cost] = dp[i][j][c] + val
						}
					}
				}
			}
		}
	}

	ans := INF
	for c := 0; c <= k; c++ {
		if dp[m-1][n-1][c] > ans {
			ans = dp[m-1][n-1][c]
		}
	}

	if ans < 0 {
		return -1
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][][] dp = new int[m][n][k + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(dp[i][j], Integer.MIN_VALUE);
            }
        }

        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == Integer.MIN_VALUE) continue;

                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] = Math.max(
                                dp[i + 1][j][c + cost],
                                dp[i][j][c] + val
                            );
                        }
                    }

                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] = Math.max(
                                dp[i][j + 1][c + cost],
                                dp[i][j][c] + val
                            );
                        }
                    }
                }
            }
        }

        int ans = Integer.MIN_VALUE;
        for (int c = 0; c <= k; c++) {
            ans = Math.max(ans, dp[m - 1][n - 1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxPathScore = function (grid, k) {
    const m = grid.length,
        n = grid[0].length;

    const INF = -Infinity;
    const dp = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(k + 1).fill(INF)),
    );

    dp[0][0][0] = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let c = 0; c <= k; c++) {
                if (dp[i][j][c] === INF) continue;

                if (i + 1 < m) {
                    const val = grid[i + 1][j];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i + 1][j][c + cost] = Math.max(
                            dp[i + 1][j][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }

                if (j + 1 < n) {
                    const val = grid[i][j + 1];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i][j + 1][c + cost] = Math.max(
                            dp[i][j + 1][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }
            }
        }
    }

    let ans = Math.max(...dp[m - 1][n - 1]);
    return ans < 0 ? -1 : ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPathScore(self, grid, k):
        m, n = len(grid), len(grid[0])

        INF = float("-inf")
        dp = [[[INF] * (k + 1) for _ in range(n)] for _ in range(m)]
        dp[0][0][0] = 0

        for i in range(m):
            for j in range(n):
                for c in range(k + 1):
                    if dp[i][j][c] == INF:
                        continue

                    if i + 1 < m:
                        val = grid[i + 1][j]
                        cost = 0 if val == 0 else 1
                        if c + cost <= k:
                            dp[i + 1][j][c + cost] = max(
                                dp[i + 1][j][c + cost], dp[i][j][c] + val
                            )

                    if j + 1 < n:
                        val = grid[i][j + 1]
                        cost = 0 if val == 0 else 1
                        if c + cost <= k:
                            dp[i][j + 1][c + cost] = max(
                                dp[i][j + 1][c + cost], dp[i][j][c] + val
                            )

        ans = max(dp[m - 1][n - 1])
        return -1 if ans < 0 else ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxPathScore(grid: number[][], k: number): number {
    const m = grid.length,
        n = grid[0].length;

    const INF = -Infinity;
    const dp: number[][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(k + 1).fill(INF)),
    );

    dp[0][0][0] = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (let c = 0; c <= k; c++) {
                if (dp[i][j][c] === INF) continue;

                if (i + 1 < m) {
                    const val = grid[i + 1][j];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i + 1][j][c + cost] = Math.max(
                            dp[i + 1][j][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }

                if (j + 1 < n) {
                    const val = grid[i][j + 1];
                    const cost = val === 0 ? 0 : 1;
                    if (c + cost <= k) {
                        dp[i][j + 1][c + cost] = Math.max(
                            dp[i][j + 1][c + cost],
                            dp[i][j][c] + val,
                        );
                    }
                }
            }
        }
    }

    const ans = Math.max(...dp[m - 1][n - 1]);
    return ans < 0 ? -1 : ans;
}
```

</details>
