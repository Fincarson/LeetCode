# 2373. Largest Local Values in a Matrix

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/largest-local-values-in-a-matrix/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 2373 - Largest Local Values in a Matrix](https://leetcode.com/problems/largest-local-values-in-a-matrix/)

## Problem

You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

- maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.

In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.

### Example 1

```text
Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
Explanation: The diagram above shows the original matrix and the generated matrix.
Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
```

### Example 2

```text
Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
Output: [[2,2,2],[2,2,2],[2,2,2]]
Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
```

## Constraints

- n == grid.length == grid[i].length
- 3 <= n <= 100
- 1 <= grid[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2373. Largest Local Values in a Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Return the maximum values in the 3 x 3 matrix with top-left as (x, y).
    int findMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        
        return maxElement;
    }
public: 
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        
        vector<vector<int>> maxLocal(N - 2, vector<int>(N - 2, 0));
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 2; j++) {
                maxLocal[i][j] = findMax(grid, i, j);
            }
        }
        
        return maxLocal;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Return the maximum values in the 3 x 3 matrix with top-left as (x, y).
    private int findMax(int[][] grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = Math.max(maxElement, grid[i][j]);
            }
        }
        
        return maxElement;
    }
    
    public int[][] largestLocal(int[][] grid) {
        int N = grid.length;
        
        int[][] maxLocal = new int[N - 2][N - 2];
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 2; j++) {
                maxLocal[i][j] = findMax(grid, i, j);
            }
        }
        
        return maxLocal;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Return the maximum values in the 3 x 3 matrix with top-left as (x, y).
    def find_max(self, grid, x, y):
        max_element = 0
        for i in range(x, x + 3):
            for j in range(y, y + 3):
                max_element = max(max_element, grid[i][j])
        
        return max_element

    def largestLocal(self, grid):
        N = len(grid)
        
        max_local = [[0] * (N - 2) for _ in range(N - 2)]
        for i in range(N - 2):
            for j in range(N - 2):
                max_local[i][j] = self.find_max(grid, i, j)
        
        return max_local
```

</details>
