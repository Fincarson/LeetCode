# 1074. Number of Submatrices That Sum to Target

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)  
`Array` `Hash Table` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 1074 - Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)

## Problem

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

### Example 1

```text
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
```

### Example 2

```text
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
```

### Example 3

```text
Input: matrix = [[904]], target = 0
Output: 0
```

## Constraints

- 1 <= matrix.length <= 100
- 1 <= matrix[0].length <= 100
- -1000 <= matrix[i][j] <= 1000
- -10^8 <= target <= 10^8

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Disconnect Path in a Binary Matrix by at Most One Flip](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1074. Number of Submatrices That Sum to Target

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Number of Subarrays that Sum to Target: Horizontal 1D Prefix Sum | Java, Python3 |
| Number of Subarrays that Sum to Target: Vertical 1D Prefix Sum | Java, Python3 |

## Approach 1: Number of Subarrays that Sum to Target: Horizontal 1D Prefix Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int numSubmatrixSumTarget(int[][] matrix, int target) {
    int r = matrix.length, c = matrix[0].length;

    // compute 2D prefix sum
    int[][] ps = new int[r + 1][c + 1];
    for (int i = 1; i < r + 1; ++i) {
      for (int j = 1; j < c + 1; ++j) {
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }

    int count = 0, currSum;
    Map<Integer, Integer> h = new HashMap();
    // reduce 2D problem to 1D one
    // by fixing two rows r1 and r2 and 
    // computing 1D prefix sum for all matrices using [r1..r2] rows
    for (int r1 = 1; r1 < r + 1; ++r1) {
      for (int r2 = r1; r2 < r + 1; ++r2) {
        h.clear();
        h.put(0, 1);
        for (int col = 1; col < c + 1; ++col) {
          // current 1D prefix sum
          currSum = ps[r2][col] - ps[r1 - 1][col];

          // add subarrays which sum up to (currSum - target)
          count += h.getOrDefault(currSum - target, 0);

          // save current prefix sum
          h.put(currSum, h.getOrDefault(currSum, 0) + 1);
        }
      }
    }

    return count;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        r, c = len(matrix), len(matrix[0])
        
        # compute 2D prefix sum
        ps = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1]
        
        count = 0
        # reduce 2D problem to 1D one
        # by fixing two rows r1 and r2 and 
        # computing 1D prefix sum for all matrices using [r1..r2] rows
        for r1 in range(1, r + 1):
            for r2 in range(r1, r + 1):
                h = defaultdict(int)
                h[0] = 1
                
                for col in range(1, c + 1):
                    # current 1D prefix sum  
                    curr_sum = ps[r2][col] - ps[r1 - 1][col]
                    
                    # add subarrays which sum up to (curr_sum - target)
                    count += h[curr_sum - target]
                    
                    # save current prefix sum
                    h[curr_sum] += 1
                    
        return count
```

</details>

<br>

## Approach 2: Number of Subarrays that Sum to Target: Vertical 1D Prefix Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int numSubmatrixSumTarget(int[][] matrix, int target) {
    int r = matrix.length, c = matrix[0].length;

    // compute 2D prefix sum
    int[][] ps = new int[r + 1][c + 1];
    for (int i = 1; i < r + 1; ++i) {
      for (int j = 1; j < c + 1; ++j) {
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }

    int count = 0, currSum;
    Map<Integer, Integer> h = new HashMap();
    // reduce 2D problem to 1D one
    // by fixing two columns c1 and c2 and 
    // computing 1D prefix sum for all matrices using [c1..c2] columns
    for (int c1 = 1; c1 < c + 1; ++c1) {
      for (int c2 = c1; c2 < c + 1; ++c2) {
        h.clear();
        h.put(0, 1);
        for (int row = 1; row < r + 1; ++row) {
          // current 1D prefix sum 
          currSum = ps[row][c2] - ps[row][c1 - 1];

          // add subarrays which sum up to (currSum - target)
          count += h.getOrDefault(currSum - target, 0);

          // save current prefix sum
          h.put(currSum, h.getOrDefault(currSum, 0) + 1);
        }
      }
    }

    return count;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import defaultdict
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        r, c = len(matrix), len(matrix[0])
        
        # compute 2D prefix sum
        ps = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1]
        
        count = 0
        # reduce 2D problem to 1D one
        # by fixing two columns c1 and c2 and 
        # computing 1D prefix sum for all matrices using [c1..c2] columns
        for c1 in range(1, c + 1):
            for c2 in range(c1, c + 1):
                h = defaultdict(int)
                h[0] = 1
                
                for row in range(1, r + 1):
                    # current 1D prefix sum 
                    curr_sum = ps[row][c2] - ps[row][c1 - 1]
                    
                    # add subarrays which sum up to (curr_sum - target)
                    count += h[curr_sum - target]
                    
                    # save current prefix sum
                    h[curr_sum] += 1
                    
        return count
```

</details>
