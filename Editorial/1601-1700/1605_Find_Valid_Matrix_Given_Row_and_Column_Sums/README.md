# 1605. Find Valid Matrix Given Row and Column Sums

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)  
`Array` `Greedy` `Matrix`

**Problem Link:** [LeetCode 1605 - Find Valid Matrix Given Row and Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)

## Problem

You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

### Example 1

```text
Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation:
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
```

### Example 2

```text
Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]
```

## Constraints

- 1 <= rowSum.length, colSum.length <= 500
- 0 <= rowSum[i], colSum[i] <= 108
- sum(rowSum) == sum(colSum)

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reconstruct a 2-Row Binary Matrix](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1605. Find Valid Matrix Given Row and Column Sums

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C++, Java, Python3 |
| Space Optimized Greedy | C++, Java, Python3 |
| Time + Space Optimized Greedy | C++, Java, Python3 |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<int> currRowSum(N, 0);
        vector<int> currColSum(M, 0);

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] =
                    min(rowSum[i] - currRowSum[i], colSum[j] - currColSum[j]);

                currRowSum[i] += origMatrix[i][j];
                currColSum[j] += origMatrix[i][j];
            }
        }
        return origMatrix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int N = rowSum.length;
        int M = colSum.length;

        int[] currRowSum = new int[N];
        int[] currColSum = new int[M];

        int[][] origMatrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] = Math.min(
                    rowSum[i] - currRowSum[i],
                    colSum[j] - currColSum[j]
                );

                currRowSum[i] += origMatrix[i][j];
                currColSum[j] += origMatrix[i][j];
            }
        }
        return origMatrix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def restoreMatrix(self, rowSum, colSum):
        N = len(rowSum)
        M = len(colSum)

        curr_row_sum = [0] * N
        curr_col_sum = [0] * M

        orig_matrix = [[0] * M for _ in range(N)]
        for i in range(N):
            for j in range(M):
                orig_matrix[i][j] = min(
                    rowSum[i] - curr_row_sum[i], colSum[j] - curr_col_sum[j]
                )

                curr_row_sum[i] += orig_matrix[i][j]
                curr_col_sum[j] += orig_matrix[i][j]

        return orig_matrix
```

</details>

<br>

## Approach 2: Space Optimized Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= origMatrix[i][j];
                colSum[j] -= origMatrix[i][j];
            }
        }

        return origMatrix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int N = rowSum.length;
        int M = colSum.length;

        int[][] origMatrix = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] = Math.min(rowSum[i], colSum[j]);

                rowSum[i] -= origMatrix[i][j];
                colSum[j] -= origMatrix[i][j];
            }
        }

        return origMatrix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def restoreMatrix(self, rowSum, colSum):
        N = len(rowSum)
        M = len(colSum)

        orig_matrix = [[0] * M for _ in range(N)]
        for i in range(N):
            for j in range(M):
                orig_matrix[i][j] = min(rowSum[i], colSum[j])

                rowSum[i] -= orig_matrix[i][j]
                colSum[j] -= orig_matrix[i][j]

        return orig_matrix
```

</details>

<br>

## Approach 3: Time + Space Optimized Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        int i = 0, j = 0;

        while (i < N && j < M) {
            origMatrix[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= origMatrix[i][j];
            colSum[j] -= origMatrix[i][j];

            rowSum[i] == 0 ? i++ : j++;
        }
        return origMatrix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int N = rowSum.length;
        int M = colSum.length;

        int[][] origMatrix = new int[N][M];
        int i = 0, j = 0;

        while (i < N && j < M) {
            origMatrix[i][j] = Math.min(rowSum[i], colSum[j]);

            rowSum[i] -= origMatrix[i][j];
            colSum[j] -= origMatrix[i][j];

            if (rowSum[i] == 0) {
                i++;
            } else {
                j++;
            }
        }

        return origMatrix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def restoreMatrix(self, rowSum, colSum):
        N = len(rowSum)
        M = len(colSum)

        orig_matrix = [[0] * M for _ in range(N)]
        i, j = 0, 0

        while i < N and j < M:
            orig_matrix[i][j] = min(rowSum[i], colSum[j])

            rowSum[i] -= orig_matrix[i][j]
            colSum[j] -= orig_matrix[i][j]

            if rowSum[i] == 0:
                i += 1
            else:
                j += 1

        return orig_matrix
```

</details>
