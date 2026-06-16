# 1428. Leftmost Column with at Least a One

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)  
`Array` `Binary Search` `Matrix` `Interactive`

**Problem Link:** [LeetCode 1428 - Leftmost Column with at Least a One](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)

## Problem

A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

- BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
- BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes, the input will be the entire binary matrix mat. You will not have access to the binary matrix directly.

### Example 1

```text
Input: mat = [[0,0],[1,1]]
Output: 0
```

### Example 2

```text
Input: mat = [[0,0],[0,1]]
Output: 1
```

### Example 3

```text
Input: mat = [[0,0],[0,0]]
Output: -1
```

## Constraints

- rows == mat.length
- cols == mat[i].length
- 1 <= rows, cols <= 100
- mat[i][j] is either 0 or 1.
- mat[i] is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1428. Leftmost Column with at Least a One

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Search Each Row | Java, Python3 |
| Binary Search Each Row | Java, Python3 |
| Start at Top Right, Move Only Left and Down | Java, Python3 |

## Approach 1: Linear Search Each Row

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);
        int smallestIndex = cols;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (binaryMatrix.get(row, col) == 1) {
                    smallestIndex = Math.min(smallestIndex, col);
                    break;
                }
            }
        }
        return smallestIndex == cols ? -1 : smallestIndex;    
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        smallest_index = cols
        # Go through each of the rows.
        for row in range(rows):
            # Linear seach for the first 1 in this row.
            for col in range(cols):
                if binaryMatrix.get(row, col) == 1:
                    smallest_index = min(smallest_index, col)
                    break
        # If we found an index, we should return it. Otherwise, return -1.
        return -1 if smallest_index == cols else smallest_index
```

</details>

<br>

## Approach 2: Binary Search Each Row

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);
        int smallestIndex = cols;
        for (int row = 0; row < rows; row++) {
            // Binary Search for the first 1 in the row.
            int lo = 0;
            int hi = cols - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (binaryMatrix.get(row, mid) == 0) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            // If the last element in the search space is a 1, then this row
            // contained a 1.
            if (binaryMatrix.get(row, lo) == 1) {
                smallestIndex = Math.min(smallestIndex, lo);
            }
        }
        // If smallest_index is still set to cols, then there were no 1's in 
        // the grid. 
        return smallestIndex == cols ? -1 : smallestIndex;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        smallest_index = cols
        for row in range(rows):
            # Binary Search for the first 1 in the row.
            lo = 0
            hi = cols - 1
            while lo < hi:
                mid = (lo + hi) // 2
                if binaryMatrix.get(row, mid) == 0:
                    lo = mid + 1
                else:
                    hi = mid
            # If the last element in the search space is a 1, then this row
            # contained a 1.
            if binaryMatrix.get(row, lo) == 1:
                smallest_index = min(smallest_index, lo)
        # If smallest_index is still set to cols, then there were no 1's in 
        # the grid. 
        return -1 if smallest_index == cols else smallest_index
```

</details>

<br>

## Approach 3: Start at Top Right, Move Only Left and Down

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);

        // Set pointers to the top-right corner.
        int currentRow = 0;
        int currentCol = cols - 1;
    
        // Repeat the search until it goes off the grid.
        while (currentRow < rows && currentCol >= 0) {
            if (binaryMatrix.get(currentRow, currentCol) == 0) {
                currentRow++;
            } else {
                currentCol--; 
            }
        }
    
        // If we never left the last column, this is because it was all 0's.
        return (currentCol == cols - 1) ? -1 : currentCol + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        
        rows, cols = binaryMatrix.dimensions()
        
        # Set pointers to the top-right corner.
        current_row = 0
        current_col = cols - 1
        
        # Repeat the search until it goes off the grid.
        while current_row < rows and current_col >= 0:
            if binaryMatrix.get(current_row, current_col) == 0:
                current_row += 1
            else:
                current_col -= 1
        
        # If we never left the last column, it must have been all 0's.
        return current_col + 1 if current_col != cols - 1 else -1
```

</details>
