# 1277. Count Square Submatrices with All Ones

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 1277 - Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

## Problem

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

### Example 1

```text
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

### Example 2

```text
Input: matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
There are 6 squares of side 1.
There is 1 square of side 2.
Total number of squares = 6 + 1 = 7.
```

## Constraints

- 1 <= arr.length <= 300
- 1 <= arr[0].length <= 300
- 0 <= arr[i][j] <= 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Fertile Pyramids in a Land](https://leetcode.com/problems/count-fertile-pyramids-in-a-land/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1277. Count Square Submatrices with All Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-up Approach | C++, Java, Python3 |
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Bottom-up Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countSquares(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int[][] dp = new int[row + 1][col + 1];
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        Math.min(
                            Math.min(dp[i][j + 1], dp[i + 1][j]),
                            dp[i][j]
                        ) +
                        1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        ans = 0
        for i in range(row):
            for j in range(col):
                if matrix[i][j]:
                    dp[i + 1][j + 1] = (
                        min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1
                    )
                    ans += dp[i + 1][j + 1]
        return ans
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // If the cell lies outside the grid, return 0.
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        // If we have already visited this cell, return the memoized value.
        if (dp[i][j] != -1) return dp[i][j];

        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, grid, dp);
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, grid, dp);
        // Find the answer for the cell below the current cell.
        int below = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + min(right, min(diagonal, below));
    }

    int countSquares(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += solve(i, j, grid, dp);
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int solve(int i, int j, int[][] grid, int[][] dp) {
        // If the cell lies outside the grid, return 0.
        if (i >= grid.length || j >= grid[0].length) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }

        // If we have already visited this cell, return the memoized value.
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, grid, dp);
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, grid, dp);
        // Find the answer for the cell below the current cell.
        int below = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + Math.min(right, Math.min(diagonal, below));
    }

    public int countSquares(int[][] grid) {
        int ans = 0;
        int[][] dp = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                Arrays.fill(dp[i], -1);
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                ans += solve(i, j, grid, dp);
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def solve(self, i, j, grid, dp):
        # If the cell lies outside the grid, return 0.
        if i >= len(grid) or j >= len(grid[0]):
            return 0
        if grid[i][j] == 0:
            return 0
        # If we have already visited this cell, return the memoized value.
        if dp[i][j] != -1:
            return dp[i][j]
        # Find the answer for the cell to the right of the current cell.
        right = self.solve(i, j + 1, grid, dp)
        # Find the answer for the cell to the diagonal of the current cell.
        diagonal = self.solve(i + 1, j + 1, grid, dp)
        # Find the answer for the cell below the current cell.
        below = self.solve(i + 1, j, grid, dp)
        dp[i][j] = 1 + min(right, min(diagonal, below))
        return dp[i][j]

    def countSquares(self, matrix: List[List[int]]) -> int:
        ans = 0
        dp = [[-1 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                ans += self.solve(i, j, matrix, dp)
        return ans
```

</details>

<br>

## Approach 3: Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), result = 0, prev = 0;
        vector<int> dp(col + 1, 0);

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    int temp = dp[j];
                    dp[j] = 1 + min(prev, min(dp[j - 1], dp[j]));
                    prev = temp;
                    result += dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countSquares(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length, result = 0, prev = 0;
        int[] dp = new int[col + 1];

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    int temp = dp[j];
                    dp[j] = 1 + Math.min(prev, Math.min(dp[j - 1], dp[j]));
                    prev = temp;
                    result += dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row, col, result, prev = len(matrix), len(matrix[0]), 0, 0
        dp = [0 for _ in range(col + 1)]

        for i in range(1, row + 1):
            for j in range(1, col + 1):
                if matrix[i - 1][j - 1] == 1:
                    temp = dp[j]
                    dp[j] = 1 + min(prev, min(dp[j - 1], dp[j]))
                    prev = temp
                    result += dp[j]
                else:
                    dp[j] = 0

        return result
```

</details>
