# 62. Unique Paths

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/unique-paths/)  
`Math` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 62 - Unique Paths](https://leetcode.com/problems/unique-paths/)

## Problem

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

### Example 1

```text
Input: m = 3, n = 7
Output: 28
```

### Example 2

```text
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

## Constraints

- 1 <= m, n <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Dungeon Game](https://leetcode.com/problems/dungeon-game/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 62. Unique Paths

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Math (Python3 only) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int uniquePaths(int m, int n) {
    int** arr;
    arr = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) arr[i] = malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 1;
        }
    }
    for (int col = 1; col < m; ++col) {
        for (int row = 1; row < n; ++row) {
            arr[col][row] = arr[col - 1][row] + arr[col][row - 1];
        }
    }
    return arr[m - 1][n - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> d(m, vector<int>(n, 1));
        for (int col = 1; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }
        return d[m - 1][n - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int UniquePaths(int m, int n) {
        int[][] d = new int [m][];
        for (int i = 0; i < m; ++i) {
            d[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                d[i][j] = 1;
            }
        }

        for (int col = 1; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }

        return d[m - 1][n - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func uniquePaths(m int, n int) int {
    d := make([][]int, m)
    for i := range d {
        d[i] = make([]int, n)
        for j := range d[i] {
            d[i][j] = 1
        }
    }
    for col := 1; col < m; col++ {
        for row := 1; row < n; row++ {
            d[col][row] = d[col-1][row] + d[col][row-1]
        }
    }
    return d[m-1][n-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] d = new int[m][n];

        for (int[] arr : d) {
            Arrays.fill(arr, 1);
        }
        for (int col = 1; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                d[col][row] = d[col - 1][row] + d[col][row - 1];
            }
        }
        return d[m - 1][n - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var uniquePaths = function (m, n) {
    let d = new Array(m).fill(0).map(() => new Array(n).fill(1));
    for (let col = 1; col < m; ++col) {
        for (let row = 1; row < n; ++row) {
            d[col][row] = d[col - 1][row] + d[col][row - 1];
        }
    }
    return d[m - 1][n - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = [[1] * n for _ in range(m)]

        for col in range(1, m):
            for row in range(1, n):
                d[col][row] = d[col - 1][row] + d[col][row - 1]

        return d[m - 1][n - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function uniquePaths(m: number, n: number): number {
    let d = new Array(m).fill(0).map(() => new Array(n).fill(1));
    for (let col = 1; col < m; ++col) {
        for (let row = 1; row < n; ++row) {
            d[col][row] = d[col - 1][row] + d[col][row - 1];
        }
    }
    return d[m - 1][n - 1];
}
```

</details>

<br>

## Approach 2: Math (Python3 only)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int UniquePaths(int m, int n) {
        long totalPlaces = m + n - 2;
        long minPlaces = Math.Min(m - 1, n - 1);
        long result = 1;
        for (int i = 0; i < minPlaces; i++) {
            result = result * (totalPlaces - i) / (i + 1);
        }

        return (int)result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func uniquePaths(m int, n int) int {
    dp := [100][100]int{}
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if i == 0 || j == 0 {
                dp[i][j] = 1
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
    }
    return dp[m-1][n-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int uniquePaths(int m, int n) {
        long answer = 1;
        for (int i = n; i < (m + n - 1); i++) {
            answer *= i;
            answer /= (i - n + 1);
        }
        return (int) answer;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var uniquePaths = function (m, n) {
    return factorial(m + n - 2) / factorial(n - 1) / factorial(m - 1);
};
function factorial(n) {
    let res = 1;
    for (let i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from math import factorial


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return factorial(m + n - 2) // factorial(n - 1) // factorial(m - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function uniquePaths(m: number, n: number): number {
    return factorial(m + n - 2) / factorial(n - 1) / factorial(m - 1);
}
function factorial(n: number): number {
    let res = 1;
    for (let i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}
```

</details>
