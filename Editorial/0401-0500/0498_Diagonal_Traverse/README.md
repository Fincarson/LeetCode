# 498. Diagonal Traverse

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/diagonal-traverse/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 498 - Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/)

## Problem

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

### Example 1

```text
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
```

### Example 2

```text
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 104
- 1 <= m * n <= 104
- -105 <= mat[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Decode the Slanted Ciphertext](https://leetcode.com/problems/decode-the-slanted-ciphertext/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 498. Diagonal Traverse

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Diagonal Iteration and Reversal | Java, Python |
| Simulation | Java, Python |

## Approach 1: Diagonal Iteration and Reversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        
        // Check for empty matrices
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        
        // Variables to track the size of the matrix
        int N = matrix.length;
        int M = matrix[0].length;
        
        // The two arrays as explained in the algorithm
        int[] result = new int[N*M];
        int k = 0;
        ArrayList<Integer> intermediate = new ArrayList<Integer>();
        
        // We have to go over all the elements in the first
        // row and the last column to cover all possible diagonals
        for (int d = 0; d < N + M - 1; d++) {
            
            // Clear the intermediate array every time we start
            // to process another diagonal
            intermediate.clear();
            
            // We need to figure out the "head" of this diagonal
            // The elements in the first row and the last column
            // are the respective heads.
            int r = d < M ? 0 : d - M + 1;
            int c = d < M ? d : M - 1;
            
            // Iterate until one of the indices goes out of scope
            // Take note of the index math to go down the diagonal
            while (r < N && c > -1) {
                
                intermediate.add(matrix[r][c]);
                ++r;
                --c;
            }
                
            // Reverse even numbered diagonals. The
            // article says we have to reverse odd 
            // numbered articles but here, the numbering
            // is starting from 0 :P
            if (d % 2 == 0) {
                Collections.reverse(intermediate);
            }
            
            for (int i = 0; i < intermediate.size(); i++) {
                result[k++] = intermediate.get(i);
            }
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        
        # Check for empty matrices
        if not matrix or not matrix[0]:
            return []
        
        # Variables to track the size of the matrix
        N, M = len(matrix), len(matrix[0])
        
        # The two arrays as explained in the algorithm
        result, intermediate = [], []
        
        # We have to go over all the elements in the first
        # row and the last column to cover all possible diagonals
        for d in range(N + M - 1):
            
            # Clear the intermediate array everytime we start
            # to process another diagonal
            intermediate.clear()
            
            # We need to figure out the "head" of this diagonal
            # The elements in the first row and the last column
            # are the respective heads.
            r, c = 0 if d < M else d - M + 1, d if d < M else M - 1
            
            # Iterate until one of the indices goes out of scope
            # Take note of the index math to go down the diagonal
            while r < N and c > -1:
                intermediate.append(matrix[r][c])
                r += 1
                c -= 1
            
            # Reverse even numbered diagonals. The
            # article says we have to reverse odd 
            # numbered articles but here, the numbering
            # is starting from 0 :P
            if d % 2 == 0:
                result.extend(intermediate[::-1])
            else:
                result.extend(intermediate)
        return result
```

</details>

<br>

## Approach 2: Simulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        
        // Check for empty matrices
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        
        // Variables to track the size of the matrix
        int N = matrix.length;
        int M = matrix[0].length;
        
        // Incides that will help us progress through 
        // the matrix, one element at a time.
        int row = 0, column = 0;
        
        // As explained in the article, this is the variable
        // that helps us keep track of what direction we are
        // processing the current diaonal
        int direction = 1;
        
         // The final result array
        int[] result = new int[N*M];
        int r = 0;
        
        // The uber while loop which will help us iterate over all
        // the elements in the array.
        while (row < N && column < M) {
            
            // First and foremost, add the current element to 
            // the result matrix. 
            result[r++] = matrix[row][column];
            
            // Move along in the current diagonal depending upon
            // the current direction.[i, j] -> [i - 1, j + 1] if 
            // going up and [i, j] -> [i + 1][j - 1] if going down.
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_column = column + (direction == 1 ? 1 : -1);
            
            // Checking if the next element in the diagonal is within the
            // bounds of the matrix or not. If it's not within the bounds,
            // we have to find the next head. 
            if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                
                // If the current diagonal was going in the upwards
                // direction.
                if (direction == 1) {
                    
                    // For an upwards going diagonal having [i, j] as its tail
                    // If [i, j + 1] is within bounds, then it becomes
                    // the next head. Otherwise, the element directly below
                    // i.e. the element [i + 1, j] becomes the next head
                    row += (column == M - 1 ? 1 : 0) ;
                    column += (column < M - 1 ? 1 : 0);
                        
                } else {
                    
                    // For a downwards going diagonal having [i, j] as its tail
                    // if [i + 1, j] is within bounds, then it becomes
                    // the next head. Otherwise, the element directly below
                    // i.e. the element [i, j + 1] becomes the next head
                    column += (row == N - 1 ? 1 : 0);
                    row += (row < N - 1 ? 1 : 0);
                }
                    
                // Flip the direction
                direction = 1 - direction;        
                        
            } else {
                
                row = new_row;
                column = new_column;
            }
        }
        return result;      
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        
        # Check for an empty matrix
        if not matrix or not matrix[0]:
            return []
        
        # The dimensions of the matrix
        N, M = len(matrix), len(matrix[0])
        
        # Incides that will help us progress through 
        # the matrix, one element at a time.
        row, column = 0, 0
        
        # As explained in the article, this is the variable
        # that helps us keep track of what direction we are
        # processing the current diaonal
        direction = 1
        
        # Final result array that will contain all the elements
        # of the matrix
        result = []
        
        # The uber while loop which will help us iterate over all
        # the elements in the array.
        while row < N and column < M:
            
            # First and foremost, add the current element to 
            # the result matrix. 
            result.append(matrix[row][column])
            
            # Move along in the current diagonal depending upon
            # the current direction.[i, j] -> [i - 1, j + 1] if 
            # going up and [i, j] -> [i + 1][j - 1] if going down.
            new_row = row + (-1 if direction == 1 else 1)
            new_column = column + (1 if direction == 1 else -1)
            
            # Checking if the next element in the diagonal is within the
            # bounds of the matrix or not. If it's not within the bounds,
            # we have to find the next head. 
            if new_row < 0 or new_row == N or new_column < 0 or new_column == M:
                
                # If the current diagonal was going in the upwards
                # direction.
                if direction:
                    
                    # For an upwards going diagonal having [i, j] as its tail
                    # If [i, j + 1] is within bounds, then it becomes
                    # the next head. Otherwise, the element directly below
                    # i.e. the element [i + 1, j] becomes the next head
                    row += (column == M - 1)
                    column += (column < M - 1)
                else:
                    
                    # For a downwards going diagonal having [i, j] as its tail
                    # if [i + 1, j] is within bounds, then it becomes
                    # the next head. Otherwise, the element directly below
                    # i.e. the element [i, j + 1] becomes the next head
                    column += (row == N - 1)
                    row += (row < N - 1)
                    
                # Flip the direction
                direction = 1 - direction        
            else:
                row = new_row
                column = new_column
                        
        return result
```

</details>
