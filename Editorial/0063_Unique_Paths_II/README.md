# 63. Unique Paths II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/unique-paths-ii/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 63 - Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

## Problem

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

### Example 1

```text
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

### Example 2

```text
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

## Constraints

- m == obstacleGrid.length
- n == obstacleGrid[i].length
- 1 <= m, n <= 100
- obstacleGrid[i][j] is 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Unique Paths](https://leetcode.com/problems/unique-paths/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 63. Unique Paths II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                             int* obstacleGridColSize) {
    int R = obstacleGridSize;
    int C = *obstacleGridColSize;
    // If the starting cell has an obstacle, then simply return as there would
    // be no paths to the destination.
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1;
    // Filling the values for the first column
    for (int i = 1; i < R; i++) {
        obstacleGrid[i][0] =
            (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
    }
    // Filling the values for the first row
    for (int i = 1; i < C; i++) {
        obstacleGrid[0][i] =
            (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
    }
    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (obstacleGrid[i][j] == 0) {
                obstacleGrid[i][j] =
                    obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            } else {
                obstacleGrid[i][j] = 0;
            }
        }
    }
    // Return value stored in rightmost bottommost cell. That is the
    // destination.
    return obstacleGrid[R - 1][C - 1];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        // If the starting cell has an obstacle, then simply return as there
        // would be no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;
        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] =
                (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1
                                                                         : 0;
        }
        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] =
                (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1
                                                                         : 0;
        }
        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] =
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        // Return value stored in rightmost bottommost cell. That is the
        // destination.
        return obstacleGrid[R - 1][C - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int UniquePathsWithObstacles(int[][] obstacleGrid) {
        int R = obstacleGrid.Length;
        int C = obstacleGrid[0].Length;
        // If the starting cell has an obstacle, then simply return as there
        // would be no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;
        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] =
                (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1
                                                                         : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] =
                (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1
                                                                         : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] =
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the
        // destination.
        return obstacleGrid[R - 1][C - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    R := len(obstacleGrid)
    C := len(obstacleGrid[0])
    // If the starting cell has an obstacle, then simply return as there would be
    // no paths to the destination.
    if obstacleGrid[0][0] == 1 {
        return 0
    }
    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1
    // Filling the values for the first column
    for i := 1; i < R; i++ {
        if obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1 {
            obstacleGrid[i][0] = 1
        } else {
            obstacleGrid[i][0] = 0
        }
    }
    // Filling the values for the first row
    for i := 1; i < C; i++ {
        if obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1 {
            obstacleGrid[0][i] = 1
        } else {
            obstacleGrid[0][i] = 0
        }
    }
    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for i := 1; i < R; i++ {
        for j := 1; j < C; j++ {
            if obstacleGrid[i][j] == 0 {
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
            } else {
                obstacleGrid[i][j] = 0
            }
        }
    }
    // Return value stored in rightmost bottommost cell. That is the destination.
    return obstacleGrid[R-1][C-1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int R = obstacleGrid.length;
        int C = obstacleGrid[0].length;

        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 &&
                    obstacleGrid[i - 1][0] == 1)
                ? 1
                : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 &&
                    obstacleGrid[0][i - 1] == 1)
                ? 1
                : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] +
                    obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[R - 1][C - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var uniquePathsWithObstacles = function (obstacleGrid) {
    let R = obstacleGrid.length;
    let C = obstacleGrid[0].length;
    // If the starting cell has an obstacle, then simply return as there would be
    // no paths to the destination.
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1;
    // Filling the values for the first column
    for (let i = 1; i < R; i++) {
        obstacleGrid[i][0] =
            obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1 ? 1 : 0;
    }
    // Filling the values for the first row
    for (let i = 1; i < C; i++) {
        obstacleGrid[0][i] =
            obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1 ? 1 : 0;
    }
    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            if (obstacleGrid[i][j] == 0) {
                obstacleGrid[i][j] =
                    obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            } else {
                obstacleGrid[i][j] = 0;
            }
        }
    }
    // Return value stored in rightmost bottommost cell. That is the destination.
    return obstacleGrid[R - 1][C - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        # If the starting cell has an obstacle, then simply return as there would be
        # no paths to the destination.
        if obstacleGrid[0][0] == 1:
            return 0

        # Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1

        # Filling the values for the first column
        for i in range(1, m):
            obstacleGrid[i][0] = int(
                obstacleGrid[i][0] == 0 and obstacleGrid[i - 1][0] == 1
            )

        # Filling the values for the first row
        for j in range(1, n):
            obstacleGrid[0][j] = int(
                obstacleGrid[0][j] == 0 and obstacleGrid[0][j - 1] == 1
            )

        # Starting from cell(1,1) fill up the values
        # No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        # i.e. From above and left.
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] = (
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
                    )
                else:
                    obstacleGrid[i][j] = 0

        # Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[m - 1][n - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    let R = obstacleGrid.length;
    let C = obstacleGrid[0].length;
    // If the starting cell has an obstacle, then simply return as there would be
    // no paths to the destination.
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1;
    // Filling the values for the first column
    for (let i = 1; i < R; i++) {
        obstacleGrid[i][0] =
            obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1 ? 1 : 0;
    }
    // Filling the values for the first row
    for (let i = 1; i < C; i++) {
        obstacleGrid[0][i] =
            obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1 ? 1 : 0;
    }
    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for (let i = 1; i < R; i++) {
        for (let j = 1; j < C; j++) {
            if (obstacleGrid[i][j] == 0) {
                obstacleGrid[i][j] =
                    obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            } else {
                obstacleGrid[i][j] = 0;
            }
        }
    }
    // Return value stored in rightmost bottommost cell. That is the destination.
    return obstacleGrid[R - 1][C - 1];
}
```

</details>
