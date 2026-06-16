# 835. Image Overlap

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/image-overlap/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 835 - Image Overlap](https://leetcode.com/problems/image-overlap/)

## Problem

You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

### Example 1

```text
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).
```

### Example 2

```text
Input: img1 = [[1]], img2 = [[1]]
Output: 1
```

### Example 3

```text
Input: img1 = [[0]], img2 = [[0]]
Output: 0
```

## Constraints

- n == img1.length == img1[i].length
- n == img2.length == img2[i].length
- 1 <= n <= 30
- img1[i][j] is either 0 or 1.
- img2[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 835. Image Overlap

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Shift and Count | Java, Python3 |
| Linear Transformation | Java, Python3 |
| Imagine Convolution | Java, Python3 |

## Approach 1: Shift and Count

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    /**
     *  Shift the matrix M in up-left and up-right directions 
     *    and count the ones in the overlapping zone.
     */
    protected int shiftAndCount(int xShift, int yShift, int[][] M, int[][] R) {
        int leftShiftCount = 0, rightShiftCount = 0;
        int rRow = 0;
        // count the cells of ones in the overlapping zone.
        for (int mRow = yShift; mRow < M.length; ++mRow) {
            int rCol = 0;
            for (int mCol = xShift; mCol < M.length; ++mCol) {
                if (M[mRow][mCol] == 1 && M[mRow][mCol] == R[rRow][rCol])
                    leftShiftCount += 1;
                if (M[mRow][rCol] == 1 && M[mRow][rCol] == R[rRow][mCol])
                    rightShiftCount += 1;
                rCol += 1;
            }
            rRow += 1;
        }
        return Math.max(leftShiftCount, rightShiftCount);
    }

    public int largestOverlap(int[][] A, int[][] B) {
        int maxOverlaps = 0;

        for (int yShift = 0; yShift < A.length; ++yShift)
            for (int xShift = 0; xShift < A.length; ++xShift) {
                // move the matrix A to the up-right and up-left directions.
                maxOverlaps = Math.max(maxOverlaps, shiftAndCount(xShift, yShift, A, B));
                // move the matrix B to the up-right and up-left directions, which is equivalent to moving A to the down-right and down-left directions 
                maxOverlaps = Math.max(maxOverlaps, shiftAndCount(xShift, yShift, B, A));
            }

        return maxOverlaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:

        dim = len(A)

        def shift_and_count(x_shift, y_shift, M, R):
            """ 
                Shift the matrix M in up-left and up-right directions 
                  and count the ones in the overlapping zone.
                M: matrix to be moved
                R: matrix for reference

                moving one matrix up is equivalent to
                moving the other matrix down
            """
            left_shift_count, right_shift_count = 0, 0
            for r_row, m_row in enumerate(range(y_shift, dim)):
                for r_col, m_col in enumerate(range(x_shift, dim)):
                    if M[m_row][m_col] == 1 and M[m_row][m_col] == R[r_row][r_col]:
                        left_shift_count += 1
                    if M[m_row][r_col] == 1 and M[m_row][r_col] == R[r_row][m_col]:
                        right_shift_count += 1

            return max(left_shift_count, right_shift_count)

        max_overlaps = 0
        # move one of the matrice up and left and vice versa.
        # (equivalent to move the other matrix down and right)
        for y_shift in range(0, dim):
            for x_shift in range(0, dim):
                # move the matrix A to the up-right and up-left directions
                max_overlaps = max(max_overlaps, shift_and_count(x_shift, y_shift, A, B))
                # move the matrix B to the up-right and up-left directions
                #  which is equivalent to moving A to the down-right and down-left directions 
                max_overlaps = max(max_overlaps, shift_and_count(x_shift, y_shift, B, A))

        return max_overlaps
```

</details>

<br>

## Approach 2: Linear Transformation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    protected List<Pair<Integer, Integer>> non_zero_cells(int[][] M) {
        List<Pair<Integer, Integer>> ret = new ArrayList<>();
        for (int row = 0; row < M.length; ++row)
            for (int col = 0; col < M.length; ++col)
                if (M[row][col] == 1)
                    ret.add(new Pair<>(row, col));
        return ret;
    }

    public int largestOverlap(int[][] A, int[][] B) {

        List<Pair<Integer, Integer>> A_ones = non_zero_cells(A);
        List<Pair<Integer, Integer>> B_ones = non_zero_cells(B);

        int maxOverlaps = 0;
        HashMap<Pair<Integer, Integer>, Integer> groupCount = new HashMap<>();

        for (Pair<Integer, Integer> a : A_ones)
            for (Pair<Integer, Integer> b : B_ones) {
                Pair<Integer, Integer> vec =
                    new Pair<>(b.getKey() - a.getKey(), b.getValue() - a.getValue());

                if (groupCount.containsKey(vec)) {
                    groupCount.put(vec, groupCount.get(vec) + 1);
                } else {
                    groupCount.put(vec, 1);
                }
                maxOverlaps = Math.max(maxOverlaps, groupCount.get(vec));
            }

        return maxOverlaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:

        dim = len(A)

        def non_zero_cells(M):
            ret = []
            for x in range(dim):
                for y in range(dim):
                    if M[x][y] == 1:
                        ret.append((x, y))
            return ret

        transformation_count = defaultdict(int)
        max_overlaps = 0

        A_ones = non_zero_cells(A)
        B_ones = non_zero_cells(B)

        for (x_a, y_a) in A_ones:
            for (x_b, y_b) in B_ones:
                vec = (x_b - x_a, y_b - y_a)
                transformation_count[vec] += 1
                max_overlaps = max(max_overlaps, transformation_count[vec])

        return max_overlaps
```

</details>

<br>

## Approach 3: Imagine Convolution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    protected int convolute(int[][] A, int[][] kernel, int xShift, int yShift) {
        int result = 0;
        for (int row = 0; row < A.length; ++row)
            for (int col = 0; col < A.length; ++col)
                result += A[row][col] * kernel[row + yShift][col + xShift];
        return result;
    }

    public int largestOverlap(int[][] A, int[][] B) {

        int N = A.length;
        int[][] B_padded = new int[3 * N - 2][3 * N - 2];
        for (int row = 0; row < N; ++row)
            for (int col = 0; col < N; ++col)
                B_padded[row + N - 1][col + N - 1] = B[row][col];

        int maxOverlaps = 0;
        for (int xShift = 0; xShift < 2 * N - 1; ++xShift)
            for (int yShift = 0; yShift < 2 * N - 1; ++yShift) {
                maxOverlaps = Math.max(maxOverlaps,
                    convolute(A, B_padded, xShift, yShift));
            }

        return maxOverlaps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:

        import numpy as np
        A = np.array(A)
        B = np.array(B)

        dim = len(A)
        # extend the matrix to a wider range for the later kernel extraction.
        B_padded = np.pad(B, dim-1, mode='constant', constant_values=(0, 0))

        max_overlaps = 0
        for x_shift in range(dim*2 - 1):
            for y_shift in range(dim* 2 - 1):
                # extract a kernel from the padded matrix
                kernel = B_padded[x_shift:x_shift+dim, y_shift:y_shift+dim]
                # convolution between A and kernel
                non_zeros = np.sum(A * kernel)
                max_overlaps = max(max_overlaps, non_zeros)

        return max_overlaps
```

</details>
