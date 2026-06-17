# 766. Toeplitz Matrix

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/toeplitz-matrix/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 766 - Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/)

## Problem

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

### Example 1

```text
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```

### Example 2

```text
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 20
- 0 <= matrix[i][j] <= 99

Follow up:

- What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
- What if the matrix is so large that you can only load up a partial row into the memory at once?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Word Square](https://leetcode.com/problems/valid-word-square/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 766. Toeplitz Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Group by Category | Java, Python |
| Compare With Top-Left Neighbor | Java, Python |

## Approach 1: Group by Category

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        Map<Integer, Integer> groups = new HashMap();
        for (int r = 0; r < matrix.length; ++r) {
            for (int c = 0; c < matrix[0].length; ++c) {
                if (!groups.containsKey(r-c))
                    groups.put(r-c, matrix[r][c]);
                else if (groups.get(r-c) != matrix[r][c])
                    return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        groups = {}
        for r, row in enumerate(matrix):
            for c, val in enumerate(row):
                if r-c not in groups:
                    groups[r-c] = val
                elif groups[r-c] != val:
                    return False
        return True
```

</details>

<br>

## Approach 2: Compare With Top-Left Neighbor

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int r = 0; r < matrix.length; ++r)
            for (int c = 0; c < matrix[0].length; ++c)
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        return all(r == 0 or c == 0 or matrix[r-1][c-1] == val
                   for r, row in enumerate(matrix)
                   for c, val in enumerate(row))
```

</details>
