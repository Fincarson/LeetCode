# 861. Score After Flipping Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/score-after-flipping-matrix/)  
`Array` `Greedy` `Bit Manipulation` `Matrix`

**Problem Link:** [LeetCode 861 - Score After Flipping Matrix](https://leetcode.com/problems/score-after-flipping-matrix/)

## Problem

You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

### Example 1

```text
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
```

### Example 2

```text
Input: grid = [[0]]
Output: 1
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 20
- grid[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove All Ones With Row and Column Flips](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 861. Score After Flipping Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Way (Modifying Input) | C++, Java, Python3 |
| Greedy Way (Without Modifying Input) | C++, Java, Python3 |

## Approach 1: Greedy Way (Modifying Input)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Set first column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                // Flip row
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Optimize columns except first column
        for (int j = 1; j < n; j++) {
            int countZero = 0;
            // Count zeros
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) {
                    countZero++;
                }
            }
            // Flip the column if there are more zeros for better score
            if (countZero > m - countZero) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculate the final score considering bit positions
        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Left shift bit by place value of column to find column
                // contribution
                int columnScore = grid[i][j] << (n - j - 1);
                // Add contribution to score
                score += columnScore;
            }
        }

        // return final result
        return score;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int matrixScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Set first column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                // Flip row
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Optimize columns except first column
        for (int j = 1; j < n; j++) {
            int countZero = 0;
            // Count zeros
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) {
                    countZero++;
                }
            }
            // Flip the column if there are more zeros for better score
            if (countZero > m - countZero) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculate the final score considering bit positions
        int score = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Left shift bit by place value of column to find column contribution
                int columnScore = grid[i][j] << (n - j - 1);
                // Add contribution to score
                score += columnScore;
            }
        }

        // return final result
        return score;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        # Set first column
        for i in range(m):
            if grid[i][0] == 0:
                # Flip row
                for j in range(n):
                    grid[i][j] = 1 - grid[i][j]  # Bitwise XOR for flip

        # Optimize columns except first column
        for j in range(1, n):
            count_zero = 0
            # Count zeros
            for i in range(m):
                if grid[i][j] == 0:
                    count_zero += 1
            # Flip the column if more zeros for better score
            if count_zero > m - count_zero:
                for i in range(m):
                    grid[i][j] ^= 1  # Bitwise XOR for flip

        # Calculate the final score considering bit positions
        score = 0
        for i in range(m):
            for j in range(n):
                # Left shift bit by place value of column to find column contribution
                columnScore = grid[i][j] << (n - j - 1)
                # Add contribution to score
                score += columnScore

        # Return final result
        return score
```

</details>

<br>

## Approach 2: Greedy Way (Without Modifying Input)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Set score to summation of first column
        int score = (1 << (n - 1)) * m;

        // Loop over all other columns
        for (int j = 1; j < n; j++) {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) {
                // Count elements matching first in row
                if (grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }
            // Calculate score based on the number of same bits in a column
            countSameBits = max(countSameBits, m - countSameBits);
            // Calculate the score contribution for the current column
            int columnScore = (1 << (n - j - 1)) * countSameBits;
            // Add contribution to score
            score += columnScore;
        }

        return score;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int matrixScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // Set score to summation of first column
        int score = (1 << (n - 1)) * m;

        // Loop over all other columns
        for (int j = 1; j < n; j++) {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) {
                // Count elements matching first in row
                if (grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }
            // Calculate score based on the number of same bits in a column
            countSameBits = Math.max(countSameBits, m - countSameBits);
            // Calculate the score contribution for the current column
            int columnScore = (1 << (n - j - 1)) * countSameBits;
            // Add contribution to score
            score += columnScore;
        }

        return score;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        # Set score to summation of first column
        score = (1 << (n - 1)) * m

        # Loop over all other columns
        for j in range(1, n):
            count_same_bits = 0
            for i in range(m):
                # Count elements matching first in row
                if grid[i][j] == grid[i][0]:
                    count_same_bits += 1

            # Calculate score based on the number of same bits in a column
            count_same_bits = max(count_same_bits, m - count_same_bits)
            # Calculate the score contribution for the current column
            column_score = (1 << (n - j - 1)) * count_same_bits
            # Add contribution to score
            score += column_score

        return score
```

</details>
