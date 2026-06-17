# 221. Maximal Square

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximal-square/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 221 - Maximal Square](https://leetcode.com/problems/maximal-square/)

## Problem

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

### Example 1

```text
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

### Example 2

```text
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

### Example 3

```text
Input: matrix = [["0"]]
Output: 0
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 300
- matrix[i][j] is '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Artifacts That Can Be Extracted](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Stamping the Grid](https://leetcode.com/problems/stamping-the-grid/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 221. Maximal Square

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Dynamic Programming | C++, Java, Python3 |
| Better Dynamic Programming | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    bool flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    boolean flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0]) if rows else 0
        maxsqlen = 0
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == "1":
                    sqlen = 1
                    flag = True
                    while sqlen + i < rows and sqlen + j < cols and flag:
                        for k in range(j, sqlen + j + 1):
                            if matrix[i + sqlen][k] == "0":
                                flag = False
                                break
                        for k in range(i, sqlen + i + 1):
                            if matrix[k][j + sqlen] == "0":
                                flag = False
                                break
                        if flag:
                            sqlen += 1
                    if maxsqlen < sqlen:
                        maxsqlen = sqlen
        return maxsqlen * maxsqlen
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int maxsqlen = 0;
        // for convenience, we add an extra all zero column and row
        // outside of the actual dp table, to simpify the transition
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] =
                        min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) +
                        1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxsqlen = 0;
        // for convenience, we add an extra all zero column and row
        // outside of the actual dp table, to simpify the transition
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = Math.min(
                        Math.min(dp[i][j - 1], dp[i - 1][j]),
                        dp[i - 1][j - 1]
                    ) +
                    1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximalSquare(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0]) if rows else 0
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        maxsqlen = 0
        # for convenience, we add an extra all zero column and row
        # outside of the actual dp table, to simpify the transition
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if matrix[i - 1][j - 1] == "1":
                    dp[i][j] = (
                        min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1])
                        + 1
                    )
                    maxsqlen = max(maxsqlen, dp[i][j])
        return maxsqlen * maxsqlen
```

</details>

<br>

## Approach 3: Better Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        vector<int> dp(cols + 1, 0);
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[] dp = new int[cols + 1];
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(Math.min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximalSquare(self, matrix):
        rows = len(matrix)
        cols = len(matrix[0]) if rows > 0 else 0
        dp = [0] * (cols + 1)
        maxsqlen = 0
        prev = 0
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                temp = dp[j]
                if matrix[i - 1][j - 1] == "1":
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1
                    maxsqlen = max(maxsqlen, dp[j])
                else:
                    dp[j] = 0
                prev = temp
        return maxsqlen * maxsqlen
```

</details>
