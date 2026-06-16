# 304. Range Sum Query 2D - Immutable

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/range-sum-query-2d-immutable/)  
`Array` `Design` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 304 - Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)

## Problem

Given a 2D matrix matrix, handle multiple queries of the following type:

- Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:

- NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
- int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

You must design an algorithm where sumRegion works on O(1) time complexity.

### Example 1

```text
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 200
- -104 <= matrix[i][j] <= 104
- 0 <= row1 <= row2 < m
- 0 <= col1 <= col2 < n
- At most 104 calls will be made to sumRegion.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the Grid of Region Average](https://leetcode.com/problems/find-the-grid-of-region-average/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 304. Range Sum Query 2D - Immutable

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | Java |
| Caching Rows | Java |
| Caching Smarter | Java |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class NumMatrix {
    private int[][] data;

    public NumMatrix(int[][] matrix) {
        data = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            for (int c = col1; c <= col2; c++) {
                sum += data[r][c];
            }
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 3: Caching Rows

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class NumMatrix {
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        dp = new int[matrix.length][matrix[0].length + 1];
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                dp[r][c + 1] = dp[r][c] + matrix[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            sum += dp[row][col2 + 1] - dp[row][col1];
        }
        return sum;
    }
}
```

</details>

<br>

## Approach 4: Caching Smarter

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class NumMatrix {
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        dp = new int[matrix.length + 1][matrix[0].length + 1];
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
}
```

</details>
