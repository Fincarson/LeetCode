# 931. Minimum Falling Path Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-falling-path-sum/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 931 - Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/)

## Problem

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

### Example 1

```text
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
```

### Example 2

```text
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
```

## Constraints

- n == matrix.length == matrix[i].length
- 1 <= n <= 100
- -100 <= matrix[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 931. Minimum Falling Path Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Using Depth First Search | C++, Java |
| Top Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming (Tabulation) | C++, Java |
| Space Optimized, Bottom-Up Dynamic Programming | C++, Java |

## Approach 1: Brute Force Using Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum =
                min(minFallingSum, findMinFallingPathSum(matrix, 0, startCol));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col) {
        // check if we are out of the left or right boundary of the matrix
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col);
        int middle = findMinFallingPathSum(matrix, row + 1, col + 1);
        int right = findMinFallingPathSum(matrix, row + 1, col - 1);

        return min(left, min(middle, right)) + matrix[row][col];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {

        int minFallingSum = Integer.MAX_VALUE;
        for (int startCol = 0; startCol < matrix.length; startCol++) {
            minFallingSum = Math.min(minFallingSum, findMinFallingPathSum(matrix, 0, startCol));
        }
        return minFallingSum;
    }

    public int findMinFallingPathSum(int[][] matrix, int row, int col) {
        // check if we are out of the left or right boundary of the matrix
        if (col < 0 || col == matrix.length) {
            return Integer.MAX_VALUE;
        }
        //check if we have reached the last row
        if (row == matrix.length - 1) {
            return matrix[row][col];
        }

        // calculate the minimum falling path sum starting from each possible next step
        int left = findMinFallingPathSum(matrix, row + 1, col);
        int middle = findMinFallingPathSum(matrix, row + 1, col + 1);
        int right = findMinFallingPathSum(matrix, row + 1, col - 1);

        return Math.min(left, Math.min(middle, right)) + matrix[row][col];
    }
}
```

</details>

<br>

## Approach 2: Top Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        vector<vector<optional<int>>> memo(
            matrix.size(), vector<optional<int>>(matrix.size(), nullopt));

        // start a DFS (with memoization) from each cell in the top row
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMinFallingPathSum(
                                                   matrix, 0, startCol, memo));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col,
                              vector<vector<optional<int>>>& memo) {
        // base cases
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        // check if the results are calculated before
        if (memo[row][col] != nullopt) {
            return (memo[row][col]).value_or(0);
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col - 1, memo);
        int middle = findMinFallingPathSum(matrix, row + 1, col, memo);
        int right = findMinFallingPathSum(matrix, row + 1, col + 1, memo);

        int minSum = min(left, min(middle, right)) + matrix[row][col];

        memo[row][col] = minSum;
        return minSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int minFallingSum = Integer.MAX_VALUE;
        Integer memo[][] = new Integer[matrix.length][matrix[0].length];

        // start a DFS (with memoization) from each cell in the top row
        for (int startCol = 0; startCol < matrix.length; startCol++) {
            minFallingSum = Math.min(minFallingSum,
                findMinFallingPathSum(matrix, 0, startCol, memo));
        }
        return minFallingSum;
    }

    public int findMinFallingPathSum(int[][] matrix, int row, int col, Integer[][] memo) {
        //base cases
        if (col < 0 || col == matrix.length) {
            return Integer.MAX_VALUE;
        }
        //check if we have reached the last row
        if (row == matrix.length - 1) {
            return matrix[row][col];
        }
        //check if the results are calculated before
        if (memo[row][col] != null) {
            return memo[row][col];
        }

        // calculate the minimum falling path sum starting from each possible next step
        int left = findMinFallingPathSum(matrix, row + 1, col, memo);
        int middle = findMinFallingPathSum(matrix, row + 1, col + 1, memo);
        int right = findMinFallingPathSum(matrix, row + 1, col - 1, memo);

        memo[row][col] = Math.min(left, Math.min(middle, right)) + matrix[row][col];
        return memo[row][col];
    }
}
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1,
                               vector<int>(matrix.size() + 1, 0));
        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) +
                                   matrix[row][col];
                } else if (col == matrix.size() - 1) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) +
                                   matrix[row][col];
                } else {
                    dp[row][col] =
                        min(dp[row + 1][col],
                            min(dp[row + 1][col + 1], dp[row + 1][col - 1])) +
                        matrix[row][col];
                }
            }
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[0][startCol]);
        }
        return minFallingSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int dp[][] = new int[matrix.length + 1][matrix.length + 1];
        for (int row = matrix.length - 1; row >= 0; row--) {
            for (int col = 0; col < matrix.length; col++) {
                if (col == 0) {
                    dp[row][col] =
                        Math.min(dp[row + 1][col], dp[row + 1][col + 1]) + matrix[row][col];
                } else if (col == matrix.length - 1) {
                    dp[row][col] =
                        Math.min(dp[row + 1][col], dp[row + 1][col - 1]) + matrix[row][col];
                } else {
                    dp[row][col] = Math.min(dp[row + 1][col],
                        Math.min(dp[row + 1][col + 1], dp[row + 1][col - 1])) + matrix[row][col];
                }
            }
        }
        int minFallingSum = Integer.MAX_VALUE;
        for (int startCol = 0; startCol < matrix.length; startCol++) {
            minFallingSum = Math.min(minFallingSum, dp[0][startCol]);
        }
        return minFallingSum;
    }
}
```

</details>

<br>

## Approach 4: Space Optimized, Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp(matrix.size() + 1, 0);
        for (int row = matrix.size() - 1; row >= 0; row--) {
            vector<int> currentRow(matrix.size() + 1, 0);
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    currentRow[col] =
                        min(dp[col], dp[col + 1]) + matrix[row][col];
                } else if (col == matrix.size() - 1) {
                    currentRow[col] =
                        min(dp[col], dp[col - 1]) + matrix[row][col];
                } else {
                    currentRow[col] =
                        min(dp[col], min(dp[col + 1], dp[col - 1])) +
                        matrix[row][col];
                }
            }
            dp = currentRow;
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[startCol]);
        }
        return minFallingSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int dp[] = new int[matrix.length + 1];
        for (int row = matrix.length - 1; row >= 0; row--) {
            int currentRow[] = new int[matrix.length + 1];
            for (int col = 0; col < matrix.length; col++) {
                if (col == 0) {
                    currentRow[col] =
                        Math.min(dp[col], dp[col + 1]) + matrix[row][col];
                } else if (col == matrix.length - 1) {
                    currentRow[col] =
                        Math.min(dp[col], dp[col - 1]) + matrix[row][col];
                } else {
                    currentRow[col] = Math.min(dp[col],
                        Math.min(dp[col + 1], dp[col - 1])) + matrix[row][col];
                }
            }
            dp = currentRow;
        }
        int minFallingSum = Integer.MAX_VALUE;
        for (int startCol = 0; startCol < matrix.length; startCol++) {
            minFallingSum = Math.min(minFallingSum, dp[startCol]);
        }
        return minFallingSum;
    }
}
```

</details>
