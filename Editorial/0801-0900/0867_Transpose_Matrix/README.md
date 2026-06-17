# 867. Transpose Matrix

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/transpose-matrix/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 867 - Transpose Matrix](https://leetcode.com/problems/transpose-matrix/)

## Problem

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

### Example 1

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
```

### Example 2

```text
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- -109 <= matrix[i][j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 867. Transpose Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Copy Directly | Java, Python3 |

## Approach 1: Copy Directly

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] transpose(int[][] A) {
        int R = A.length, C = A[0].length;
        int[][] ans = new int[C][R];
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                ans[c][r] = A[r][c];
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
    def transpose(self, A: List[List[int]]) -> List[List[int]] :
        R, C = len(A), len(A[0])
        ans = [[None] * R for _ in range(C)]
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                ans[c][r] = val
        return ans

        #Alternative Solution:
        #return list(zip(*A))
```

</details>
