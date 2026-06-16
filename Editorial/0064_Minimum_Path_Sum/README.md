# 64. Minimum Path Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-path-sum/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 64 - Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

## Problem

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

### Example 1

```text
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

### Example 2

```text
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 200
- 0 <= grid[i][j] <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths](https://leetcode.com/problems/unique-paths/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Dungeon Game](https://leetcode.com/problems/dungeon-game/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Cherry Pickup](https://leetcode.com/problems/cherry-pickup/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Check if There is a Path With Equal Number of 0's And 1's](https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Cost of a Path With Special Roads](https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 64. Minimum Path Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming 2D | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming 1D | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming (Without Extra Space) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int calculate(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i == gridSize || j == gridColSize[0]) return INT_MAX;
    if (i == gridSize - 1 && j == gridColSize[0] - 1) return grid[i][j];
    return grid[i][j] + fmin(calculate(grid, gridSize, gridColSize, i + 1, j),
                             calculate(grid, gridSize, gridColSize, i, j + 1));
}
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    return calculate(grid, gridSize, gridColSize, 0, 0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calculate(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || j == grid[0].size()) return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        return grid[i][j] +
               min(calculate(grid, i + 1, j), calculate(grid, i, j + 1));
    }
    int minPathSum(vector<vector<int>>& grid) { return calculate(grid, 0, 0); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int Calculate(int[][] grid, int i, int j) {
        if (i == grid.Length || j == grid[0].Length)
            return int.MaxValue;
        if (i == grid.Length - 1 && j == grid[0].Length - 1)
            return grid[i][j];
        return grid[i][j] +
               Math.Min(Calculate(grid, i + 1, j), Calculate(grid, i, j + 1));
    }

    public int MinPathSum(int[][] grid) {
        return Calculate(grid, 0, 0);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func calculate(grid [][]int, i int, j int) int {
    if i == len(grid) || j == len(grid[0]) {
        return int(^uint(0) >> 1)
    }
    if i == len(grid)-1 && j == len(grid[0])-1 {
        return grid[i][j]
    }
    return grid[i][j] + min(calculate(grid, i+1, j), calculate(grid, i, j+1))
}

func minPathSum(grid [][]int) int {
    return calculate(grid, 0, 0)
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int calculate(int[][] grid, int i, int j) {
        if (i == grid.length || j == grid[0].length) return Integer.MAX_VALUE;
        if (i == grid.length - 1 && j == grid[0].length - 1) return grid[i][j];
        return (
            grid[i][j] +
            Math.min(calculate(grid, i + 1, j), calculate(grid, i, j + 1))
        );
    }

    public int minPathSum(int[][] grid) {
        return calculate(grid, 0, 0);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var calculate = function (grid, i, j) {
    if (i == grid.length || j == grid[0].length) return Number.MAX_SAFE_INTEGER;
    if (i == grid.length - 1 && j == grid[0].length - 1) return grid[i][j];
    return (
        grid[i][j] +
        Math.min(calculate(grid, i + 1, j), calculate(grid, i, j + 1))
    );
};
var minPathSum = function (grid) {
    return calculate(grid, 0, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def calculate(self, grid: List[List[int]], i: int, j: int) -> int:
        if i == len(grid) or j == len(grid[0]):
            return float("inf")
        if i == len(grid) - 1 and j == len(grid[0]) - 1:
            return grid[i][j]
        return grid[i][j] + min(
            self.calculate(grid, i + 1, j), self.calculate(grid, i, j + 1)
        )

    def minPathSum(self, grid: List[List[int]]) -> int:
        return self.calculate(grid, 0, 0)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function calculate(grid: number[][], i: number, j: number): number {
    if (i == grid.length || j == grid[0].length) return Number.MAX_SAFE_INTEGER;
    if (i == grid.length - 1 && j == grid[0].length - 1) return grid[i][j];
    return (
        grid[i][j] +
        Math.min(calculate(grid, i + 1, j), calculate(grid, i, j + 1))
    );
}
function minPathSum(grid: number[][]): number {
    return calculate(grid, 0, 0);
}
```

</details>

<br>

## Approach 2: Dynamic Programming 2D

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;
    int dp[m][n];
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j != n - 1)
                dp[i][j] = grid[i][j] + dp[i][j + 1];
            else if (j == n - 1 && i != m - 1)
                dp[i][j] = grid[i][j] + dp[i + 1][j];
            else if (j != n - 1 && i != m - 1)
                dp[i][j] =
                    grid[i][j] +
                    (dp[i + 1][j] < dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1]);
            else
                dp[i][j] = grid[i][j];
        }
    }
    return dp[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j != n - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if (j == n - 1 && i != m - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if (j != n - 1 && i != m - 1)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinPathSum(int[][] grid) {
        int[][] dp = new int [grid.Length][];
        for (int i = 0; i < grid.Length; i++) dp[i] = new int[grid[0].Length];
        for (int i = grid.Length - 1; i >= 0; i--) {
            for (int j = grid[0].Length - 1; j >= 0; j--) {
                if (i == grid.Length - 1 && j != grid[0].Length - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if (j == grid[0].Length - 1 && i != grid.Length - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if (j != grid[0].Length - 1 && i != grid.Length - 1)
                    dp[i][j] =
                        grid[i][j] + Math.Min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }

        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
    }
    for i := m - 1; i >= 0; i-- {
        for j := n - 1; j >= 0; j-- {
            if i == m-1 && j != n-1 {
                dp[i][j] = grid[i][j] + dp[i][j+1]
            } else if j == n-1 && i != m-1 {
                dp[i][j] = grid[i][j] + dp[i+1][j]
            } else if j != n-1 && i != m-1 {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1])
            } else {
                dp[i][j] = grid[i][j]
            }
        }
    }
    return dp[0][0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {
                if (i == grid.length - 1 && j != grid[0].length - 1) dp[i][j] =
                    grid[i][j] + dp[i][j + 1];
                else if (
                    j == grid[0].length - 1 && i != grid.length - 1
                ) dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if (
                    j != grid[0].length - 1 && i != grid.length - 1
                ) dp[i][j] = grid[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1]);
                else dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minPathSum = function (grid) {
    let dp = new Array(grid.length)
        .fill()
        .map(() => new Array(grid[0].length).fill(0));
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i === grid.length - 1 && j !== grid[0].length - 1)
                dp[i][j] = grid[i][j] + dp[i][j + 1];
            else if (j === grid[0].length - 1 && i !== grid.length - 1)
                dp[i][j] = grid[i][j] + dp[i + 1][j];
            else if (j !== grid[0].length - 1 && i !== grid.length - 1)
                dp[i][j] = grid[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1]);
            else dp[i][j] = grid[i][j];
        }
    }
    return dp[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minPathSum(self, grid):
        m = len(grid)
        n = len(grid[0])
        dp = [[0] * n for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j != n - 1:
                    dp[i][j] = grid[i][j] + dp[i][j + 1]
                elif j == n - 1 and i != m - 1:
                    dp[i][j] = grid[i][j] + dp[i + 1][j]
                elif j != n - 1 and i != m - 1:
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1])
                else:
                    dp[i][j] = grid[i][j]
        return dp[0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minPathSum(grid: number[][]): number {
    let dp: number[][] = new Array(grid.length)
        .fill(0)
        .map((_) => new Array(grid[0].length).fill(0));
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i === grid.length - 1 && j !== grid[0].length - 1)
                dp[i][j] = grid[i][j] + dp[i][j + 1];
            else if (j === grid[0].length - 1 && i !== grid.length - 1)
                dp[i][j] = grid[i][j] + dp[i + 1][j];
            else if (j !== grid[0].length - 1 && i !== grid.length - 1)
                dp[i][j] = grid[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1]);
            else dp[i][j] = grid[i][j];
        }
    }
    return dp[0][0];
}
```

</details>

<br>

## Approach 3: Dynamic Programming 1D

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minPathSum(int** grid, int gridRowSize, int* gridColSizes) {
    int* dp = (int*)malloc(sizeof(int) * gridColSizes[0]);
    for (int i = gridRowSize - 1; i >= 0; i--) {
        for (int j = gridColSizes[0] - 1; j >= 0; j--) {
            if (i == gridRowSize - 1 && j != gridColSizes[0] - 1)
                dp[j] = grid[i][j] + dp[j + 1];
            else if (j == gridColSizes[0] - 1 && i != gridRowSize - 1)
                dp[j] = grid[i][j] + dp[j];
            else if (j != gridColSizes[0] - 1 && i != gridRowSize - 1)
                dp[j] = grid[i][j] + (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]);
            else
                dp[j] = grid[i][j];
        }
    }
    int result = dp[0];
    free(dp);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if (j == grid[0].size() - 1 && i != grid.size() - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if (i != grid.size() - 1 && j != grid[0].size() - 1)
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinPathSum(int[][] grid) {
        int[] dp = new int[grid[0].Length];
        for (int i = grid.Length - 1; i >= 0; i--) {
            for (int j = grid[0].Length - 1; j >= 0; j--) {
                if (i == grid.Length - 1 && j != grid[0].Length - 1)
                    dp[j] = grid[i][j] + dp[j + 1];
                else if (j == grid[0].Length - 1 && i != grid.Length - 1)
                    dp[j] = grid[i][j] + dp[j];
                else if (i != grid.Length - 1 && j != grid[0].Length - 1)
                    dp[j] = grid[i][j] + Math.Min(dp[j], dp[j + 1]);
                else
                    dp[j] = grid[i][j];
            }
        }

        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minPathSum(grid [][]int) int {
    dp := make([]int, len(grid[0]))
    for i := len(grid) - 1; i >= 0; i-- {
        for j := len(grid[0]) - 1; j >= 0; j-- {
            if i == len(grid)-1 && j != len(grid[0])-1 {
                dp[j] = grid[i][j] + dp[j+1]
            } else if j == len(grid[0])-1 && i != len(grid)-1 {
                dp[j] = grid[i][j] + dp[j]
            } else if i != len(grid)-1 && j != len(grid[0])-1 {
                dp[j] = grid[i][j] + min(dp[j], dp[j+1])
            } else {
                dp[j] = grid[i][j]
            }
        }
    }
    return dp[0]
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minPathSum(int[][] grid) {
        int[] dp = new int[grid[0].length];
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {
                if (i == grid.length - 1 && j != grid[0].length - 1) dp[j] =
                    grid[i][j] + dp[j + 1];
                else if (
                    j == grid[0].length - 1 && i != grid.length - 1
                ) dp[j] = grid[i][j] + dp[j];
                else if (
                    j != grid[0].length - 1 && i != grid.length - 1
                ) dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
                else dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minPathSum = function (grid) {
    let dp = new Array(grid[0].length).fill(0);
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i == grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + dp[j + 1];
            else if (j == grid[0].length - 1 && i != grid.length - 1)
                dp[j] = grid[i][j] + dp[j];
            else if (i != grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
            else dp[j] = grid[i][j];
        }
    }
    return dp[0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [0 for _ in range(len(grid[0]))]
        for i in range(len(grid) - 1, -1, -1):
            for j in range(len(grid[0]) - 1, -1, -1):
                if i == len(grid) - 1 and j != len(grid[0]) - 1:
                    dp[j] = grid[i][j] + dp[j + 1]
                elif j == len(grid[0]) - 1 and i != len(grid) - 1:
                    dp[j] = grid[i][j] + dp[j]
                elif i != len(grid) - 1 and j != len(grid[0]) - 1:
                    dp[j] = grid[i][j] + min(dp[j], dp[j + 1])
                else:
                    dp[j] = grid[i][j]
        return dp[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minPathSum(grid: number[][]): number {
    let dp: number[] = new Array(grid[0].length).fill(0);
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i == grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + dp[j + 1];
            else if (j == grid[0].length - 1 && i != grid.length - 1)
                dp[j] = grid[i][j] + dp[j];
            else if (i != grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
            else dp[j] = grid[i][j];
        }
    }
    return dp[0];
}
```

</details>

<br>

## Approach 4: Dynamic Programming (Without Extra Space)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C solution
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = gridColSize[0] - 1; j >= 0; j--) {
            if (i == gridSize - 1 && j != gridColSize[0] - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j == gridColSize[0] - 1 && i != gridSize - 1)
                grid[i][j] += grid[i + 1][j];
            else if (j != gridColSize[0] - 1 && i != gridSize - 1)
                grid[i][j] += grid[i + 1][j] < grid[i][j + 1] ? grid[i + 1][j]
                                                              : grid[i][j + 1];
        }
    }
    return grid[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++ solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i == grid.size() - 1 && j != grid[0].size() - 1)
                    grid[i][j] += grid[i][j + 1];
                else if (j == grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] += grid[i + 1][j];
                else if (j != grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C# solution

public class Solution {
    public int MinPathSum(int[][] grid) {
        for (int i = grid.Length - 1; i >= 0; i--) {
            for (int j = grid[0].Length - 1; j >= 0; j--) {
                if (i == grid.Length - 1 && j != grid[0].Length - 1)
                    grid[i][j] += grid[i][j + 1];
                else if (j == grid[0].Length - 1 && i != grid.Length - 1)
                    grid[i][j] += grid[i + 1][j];
                else if (j != grid[0].Length - 1 && i != grid.Length - 1)
                    grid[i][j] += Math.Min(grid[i + 1][j], grid[i][j + 1]);
            }
        }

        return grid[0][0];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang solution
func minPathSum(grid [][]int) int {
    for i := len(grid) - 1; i >= 0; i-- {
        for j := len(grid[0]) - 1; j >= 0; j-- {
            if i == len(grid)-1 && j != len(grid[0])-1 {
                grid[i][j] += grid[i][j+1]
            } else if j == len(grid[0])-1 && i != len(grid)-1 {
                grid[i][j] += grid[i+1][j]
            } else if j != len(grid[0])-1 && i != len(grid)-1 {
                grid[i][j] += min(grid[i+1][j], grid[i][j+1])
            }
        }
    }
    return grid[0][0]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minPathSum(int[][] grid) {
        for (int i = grid.length - 1; i >= 0; i--) {
            for (int j = grid[0].length - 1; j >= 0; j--) {
                if (
                    i == grid.length - 1 && j != grid[0].length - 1
                ) grid[i][j] = grid[i][j] + grid[i][j + 1];
                else if (
                    j == grid[0].length - 1 && i != grid.length - 1
                ) grid[i][j] = grid[i][j] + grid[i + 1][j];
                else if (
                    j != grid[0].length - 1 && i != grid.length - 1
                ) grid[i][j] = grid[i][j] +
                Math.min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript solution
var minPathSum = function (grid) {
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i === grid.length - 1 && j !== grid[0].length - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j === grid[0].length - 1 && i !== grid.length - 1)
                grid[i][j] += grid[i + 1][j];
            else if (j !== grid[0].length - 1 && i !== grid.length - 1)
                grid[i][j] += Math.min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python solution
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        for i in reversed(range(len(grid))):
            for j in reversed(range(len(grid[0]))):
                if i == len(grid) - 1 and j != len(grid[0]) - 1:
                    grid[i][j] += grid[i][j + 1]
                elif j == len(grid[0]) - 1 and i != len(grid) - 1:
                    grid[i][j] += grid[i + 1][j]
                elif j != len(grid[0]) - 1 and i != len(grid) - 1:
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1])
        return grid[0][0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript solution
function minPathSum(grid: number[][]): number {
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i === grid.length - 1 && j !== grid[0].length - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j === grid[0].length - 1 && i !== grid.length - 1)
                grid[i][j] += grid[i + 1][j];
            else if (j !== grid[0].length - 1 && i !== grid.length - 1)
                grid[i][j] += Math.min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
}
```

</details>
