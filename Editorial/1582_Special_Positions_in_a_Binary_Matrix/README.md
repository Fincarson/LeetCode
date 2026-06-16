# 1582. Special Positions in a Binary Matrix

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 1582 - Special Positions in a Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)

## Problem

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

### Example 1

```text
Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
```

### Example 2

```text
Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 100
- mat[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1582. Special Positions in a Binary Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Precompute the Number of Ones in each Row and Column | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                bool good = true;
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }
                
                if (good) {
                    ans++;
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
    public int numSpecial(int[][] mat) {
        int ans = 0;
        int m = mat.length;
        int n = mat[0].length;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                boolean good = true;
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }
                
                if (good) {
                    ans++;
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
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0
        m = len(mat)
        n = len(mat[0])
        
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 0:
                    continue
                    
                good = True
                for r in range(m):
                    if r != row and mat[r][col] == 1:
                        good = False
                        break
                
                for c in range(n):
                    if c != col and mat[row][c] == 1:
                        good = False
                        break
                
                if good:
                    ans += 1
        
        return ans
```

</details>

<br>

## Approach 2: Precompute the Number of Ones in each Row and Column

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        
        int ans = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        ans++;
                    }
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
    public int numSpecial(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        
        int ans = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        ans++;
                    }
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
    def numSpecial(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        row_count = [0] * m
        col_count = [0] * n
        
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 1:
                    row_count[row] += 1
                    col_count[col] += 1
        
        ans = 0
        for row in range(m):
            for col in range(n):
                if mat[row][col] == 1:
                    if row_count[row] == 1 and col_count[col] == 1:
                        ans += 1

        return ans
```

</details>
