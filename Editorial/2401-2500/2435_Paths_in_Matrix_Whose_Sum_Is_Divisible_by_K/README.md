# 2435. Paths in Matrix Whose Sum Is Divisible by K

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 2435 - Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)

## Problem

You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2
Explanation: There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
```

### Example 2

```text
Input: grid = [[0,0]], k = 5
Output: 1
Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
```

### Example 3

```text
Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
Output: 10
Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 5 * 104
- 1 <= m * n <= 5 * 104
- 0 <= grid[i][j] <= 100
- 1 <= k <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths](https://leetcode.com/problems/unique-paths/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Dungeon Game](https://leetcode.com/problems/dungeon-game/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Cherry Pickup](https://leetcode.com/problems/cherry-pickup/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check if There is a Path With Equal Number of 0's And 1's](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2435. Paths in Matrix Whose Sum Is Divisible by K

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
#define MOD 1000000007

int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];

    long long*** dp = (long long***)malloc((m + 1) * sizeof(long long**));
    for (int i = 0; i <= m; i++) {
        dp[i] = (long long**)malloc((n + 1) * sizeof(long long*));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (long long*)calloc(k, sizeof(long long));
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                dp[i][j][grid[0][0] % k] = 1;
                continue;
            }

            int value = grid[i - 1][j - 1] % k;
            for (int r = 0; r < k; r++) {
                int prevMod = (r - value + k) % k;
                dp[i][j][r] =
                    (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
            }
        }
    }

    int result = dp[m][n][0];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector(m + 1, vector(n + 1, vector<ll>(k)));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return dp[m][n][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1000000007;

    public int NumberOfPaths(int[][] grid, int k) {
        int m = grid.Length;
        int n = grid[0].Length;

        long[][][] dp = new long [m + 1][][];
        for (int i = 0; i <= m; i++) {
            dp[i] = new long [n + 1][];
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new long[k];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return (int)dp[m][n][0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfPaths(grid [][]int, k int) int {
	const MOD = 1000000007
	m, n := len(grid), len(grid[0])

	dp := make([][][]int64, m+1)
	for i := range dp {
		dp[i] = make([][]int64, n+1)
		for j := range dp[i] {
			dp[i][j] = make([]int64, k)
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if i == 1 && j == 1 {
				dp[i][j][grid[0][0]%k] = 1
				continue
			}

			value := grid[i-1][j-1] % k
			for r := 0; r < k; r++ {
				prevMod := (r - value + k) % k
				dp[i][j][r] = (dp[i-1][j][prevMod] + dp[i][j-1][prevMod]) % MOD
			}
		}
	}

	return int(dp[m][n][0])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        long[][][] dp = new long[m + 1][n + 1][k];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return (int) dp[m][n][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1e9 + 7;

var numberOfPaths = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;

    const dp = [];

    for (let i = 0; i <= m; i++) {
        dp[i] = [];
        for (let j = 0; j <= n; j++) {
            dp[i][j] = new Array(k).fill(0);

            if (i === 1 && j === 1) {
                dp[i][j][grid[0][0] % k] = 1;
                continue;
            }

            if (i >= 1 && j >= 1) {
                const value = grid[i - 1][j - 1] % k;

                for (let r = 0; r < k; r++) {
                    const prevMod = (r - value + k) % k;

                    dp[i][j][r] = dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod];
                    dp[i][j][r] %= MOD;
                }
            }
        }
    }

    return dp[m][n][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])

        dp = [[[0] * k for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if i == 1 and j == 1:
                    dp[i][j][grid[0][0] % k] = 1
                    continue

                value = grid[i - 1][j - 1] % k
                for r in range(k):
                    prev_mod = (r - value + k) % k
                    dp[i][j][r] = (
                        dp[i - 1][j][prev_mod] + dp[i][j - 1][prev_mod]
                    ) % MOD

        return dp[m][n][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1e9 + 7;

function numberOfPaths(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;

    const dp: number[][][] = [];

    for (let i = 0; i <= m; i++) {
        dp[i] = [];
        for (let j = 0; j <= n; j++) {
            dp[i][j] = new Array(k).fill(0);

            if (i === 1 && j === 1) {
                dp[i][j][grid[0][0] % k] = 1;
                continue;
            }

            if (i >= 1 && j >= 1) {
                const value = grid[i - 1][j - 1] % k;

                for (let r = 0; r < k; r++) {
                    const prevMod = (r - value + k) % k;

                    dp[i][j][r] = dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod];
                    dp[i][j][r] %= MOD;
                }
            }
        }
    }

    return dp[m][n][0];
}
```

</details>
