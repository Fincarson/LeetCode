# 1572. Matrix Diagonal Sum

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/matrix-diagonal-sum/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 1572 - Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

## Problem

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

### Example 1

```text
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
```

### Example 2

```text
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

### Example 3

```text
Input: mat = [[5]]
Output: 5
```

## Constraints

- n == mat.length == mat[i].length
- 1 <= n <= 100
- 1 <= mat[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Check if Matrix Is X-Matrix](https://leetcode.com/problems/check-if-matrix-is-x-matrix/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1572. Matrix Diagonal Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Iterating over Diagonal Elements | C++, Java, Python3 |

## Approach: Iterating over Diagonal Elements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Add elements from primary diagonal.
            ans += mat[i][i];
            // Addd elements from secondary diagonal.
            ans += mat[n - 1 - i][i];
        }
        // If n is odd, subtract the middle element as its added twice.
        if (n % 2 != 0) {
            ans -= mat[n / 2][n / 2];
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
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Add elements from primary diagonal.
            ans += mat[i][i];
            // Add elements from secondary diagonal.
            ans += mat[n - 1 - i][i];
        }
        // If n is odd, subtract the middle element as its added twice.
        if (n % 2 != 0) {
            ans -= mat[n / 2][n / 2];
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
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        ans = 0

        for i in range(n):
            # Add elements from primary diagonal.
            ans += mat[i][i]
            # Add elements from secondary diagonal.
            ans += mat[n - 1 - i][i]
        # If n is odd, subtract the middle element as its added twice.
        if n % 2 != 0:
             ans -= mat[n // 2][n // 2]
        
        return ans
```

</details>
