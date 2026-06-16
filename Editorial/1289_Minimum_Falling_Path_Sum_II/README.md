# 1289. Minimum Falling Path Sum II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-falling-path-sum-ii/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 1289 - Minimum Falling Path Sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/)

## Problem

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

### Example 1

```text
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
```

### Example 2

```text
Input: grid = [[7]]
Output: 7
```

## Constraints

- n == grid.length == grid[i].length
- 1 <= n <= 200
- -99 <= grid[i][j] <= 99

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1289. Minimum Falling Path Sum II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming. Save Minimum and Second Minimum | C++, Java, Python3 |
| Space-Optimized Bottom-Up Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Initialize a hash map to cache the result of each sub-problem
        map<pair<int, int>, int> memo;

        // We can select any element from the first row. We will select
        // the element which leads to minimum sum.
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, optimal(0, col, grid, memo));
        }

        // Return the minimum sum
        return answer;
    }

    // The optimal(row, col) function returns the minimum sum of a
    // falling path with non-zero shifts, starting from grid[row][col]
    int optimal(int row, int col, vector<vector<int>>& grid, map<pair<int, int>, int>& memo) {
        // If the last row, then return the value of the cell itself
        if (row == grid.size() - 1) {
            return grid[row][col];
        }

        // If the result of this sub-problem is already cached
        if (memo.find({row, col}) != memo.end()) {
            return memo[{row, col}];
        }

        // Select grid[row][col], and move on to next row. For next
        // row, choose the cell that leads to the minimum sum
        int nextMinimum = INT_MAX;
        for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) {
            if (nextRowCol != col) {
                nextMinimum = min(nextMinimum, optimal(row + 1, nextRowCol, grid, memo));
            }
        }

        // Minimum cost from this cell
        memo[{row, col}] = grid[row][col] + nextMinimum;
        return memo[{row, col}];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Initialize a hash map to cache the result of each sub-problem
    Map<Pair<Integer, Integer>, Integer> memo = new HashMap<>();

    public int minFallingPathSum(int[][] grid) {
        // We can select any element from the first row. We will select
        // the element which leads to minimum sum.
        int answer = Integer.MAX_VALUE;
        for (int col = 0; col < grid.length; col++) {
            answer = Math.min(answer, optimal(0, col, grid));
        }

        // Return the minimum sum
        return answer;
    }

    // The optimal(row, col) function returns the minimum sum of a
    // falling path with non-zero shifts, starting from grid[row][col]
    int optimal(int row, int col, int[][] grid) {
        // If the last row, then return the value of the cell itself
        if (row == grid.length - 1) {
            return grid[row][col];
        }

        // If the result of this sub-problem is already cached
        if (memo.containsKey(new Pair<>(row, col))) {
            return memo.get(new Pair<>(row, col));
        }

        // Select grid[row][col], and move on to next row. For next
        // row, choose the cell that leads to the minimum sum
        int nextMinimum = Integer.MAX_VALUE;
        for (int nextRowCol = 0; nextRowCol < grid.length; nextRowCol++) {
            if (nextRowCol != col) {
                nextMinimum = Math.min(nextMinimum, optimal(row + 1, nextRowCol, grid));
            }
        }

        // Minimum cost from this cell
        memo.put(new Pair<>(row, col), grid[row][col] + nextMinimum);
        return memo.get(new Pair<>(row, col));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        # Save the size of the square grid
        n = len(grid)

        # Initialize a hash map to cache the result of each sub-problem
        memo = {}
        
        # The optimal(row, col) function returns the minimum sum of a 
        # falling path with non-zero shifts, starting from grid[row][col]
        def optimal(row, col):
            # If the last row, then return the value of the cell itself
            if row == n - 1:
                return grid[row][col]

            # If the result of this sub-problem is already cached
            if (row, col) in memo:
                return memo[(row, col)]

            # Select grid[row][col], and move on to next row. For next
            # row, choose the cell that leads to the minimum sum
            next_minimum = inf
            for next_row_col in range(n):
                if next_row_col != col:
                    next_minimum = min(next_minimum, optimal(row + 1, next_row_col))

            # Minimum cost from this cell
            memo[(row, col)] = grid[row][col] + next_minimum
            return memo[(row, col)]
        
        # We can select any element from the first row. We will select
        # the element which leads to minimum sum.
        answer = inf
        for col in range(n):
            answer = min(answer, optimal(0, col))
        
        # Return the minimum sum
        return answer
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Initialize a two-dimensional array to cache the result of each sub-problem
        vector<vector<int>> memo(grid.size(), vector<int>(grid.size(), INT_MAX));

        // Fill the base case
        for (int col = 0; col < grid.size(); col++) {
            memo[grid.size() - 1][col] = grid[grid.size() - 1][col];
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) {
            for (int col = 0; col < grid.size(); col++) {
                // Select minimum from valid cells of next row
                int nextMinimum = INT_MAX;
                for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) {
                    if (nextRowCol != col) {
                        nextMinimum = min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }

                // Minimum cost from this cell
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }

        // Find the minimum from the first row
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, memo[0][col]);
        }

        // Return the answer
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] grid) {
        // Initialize a two-dimensional array to cache the result of each sub-problem
        int[][] memo = new int[grid.length][grid.length];

        // Fill the base case
        for (int col = 0; col < grid.length; col++) {
            memo[grid.length - 1][col] = grid[grid.length - 1][col];
        }

        // Fill the recursive cases
        for (int row = grid.length - 2; row >= 0; row--) {
            for (int col = 0; col < grid.length; col++) {
                // Select minimum from valid cells of next row
                int nextMinimum = Integer.MAX_VALUE;
                for (int nextRowCol = 0; nextRowCol < grid.length; nextRowCol++) {
                    if (nextRowCol != col) {
                        nextMinimum = Math.min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }

                // Minimum cost from this cell
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }

        // Find the minimum from the first row
        int answer = Integer.MAX_VALUE;
        for (int col = 0; col < grid.length; col++) {
            answer = Math.min(answer, memo[0][col]);
        }

        // Return the answer
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        # Save the size of the square grid
        n = len(grid)

        # Initialize a two-dimensional array to cache the result of each sub-problem
        memo = [[inf] * n for _ in range(n)]

        # Fill the base case
        for col in range(n):
            memo[n - 1][col] = grid[n - 1][col]

        # Fill the recursive cases
        for row in range(n - 2, -1, -1):
            for col in range(n):
                # Select minimum from valid cells of the next row
                next_minimum = inf
                for next_row_col in range(n):
                    if next_row_col != col:
                        next_minimum = min(next_minimum, memo[row + 1][next_row_col])

                # Minimum cost from this cell
                memo[row][col] = grid[row][col] + next_minimum
        
        # Find the minimum from the first row
        answer = inf
        for col in range(n):
            answer = min(answer, memo[0][col])
        
        # Return the answer
        return answer
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming. Save Minimum and Second Minimum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Initialize a two-dimensional array to cache the result of each sub-problem
        vector<vector<int>> memo(grid.size(), vector<int>(grid.size(), INT_MAX));

        // Minimum and Second Minimum Column Index
        int nextMin1C = -1;
        int nextMin2C = -1;

        // Base Case. Fill and save the minimum and second minimum column index
        for (int col = 0; col < grid.size(); col++) {
            memo[grid.size() - 1][col] = grid[grid.size() - 1][col];
            if (nextMin1C == -1 || memo[grid.size() - 1][col] <= memo[grid.size() - 1][nextMin1C]) {
                nextMin2C = nextMin1C;
                nextMin1C = col;
            } else if (nextMin2C == -1 || memo[grid.size() - 1][col] <= memo[grid.size() - 1][nextMin2C]) {
                nextMin2C = col;
            }
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) {
            // Minimum and Second Minimum Column Index of the current row
            int min1C = -1;
            int min2C = -1;

            for (int col = 0; col < grid.size(); col++) {
                // Select minimum from valid cells of the next row
                if (col != nextMin1C) {
                    memo[row][col] = grid[row][col] + memo[row + 1][nextMin1C];
                } else {
                    memo[row][col] = grid[row][col] + memo[row + 1][nextMin2C];
                }

                // Save minimum and second minimum column index
                if (min1C == -1 || memo[row][col] <= memo[row][min1C]) {
                    min2C = min1C;
                    min1C = col;
                } else if (min2C == -1 || memo[row][col] <= memo[row][min2C]) {
                    min2C = col;
                }
            }

            // Change of row. Update nextMin1C and nextMin2C
            nextMin1C = min1C;
            nextMin2C = min2C;
        }

        // Return the minimum from the first row
        return memo[0][nextMin1C];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] grid) {
        // Initialize a two-dimensional array to cache the result of each sub-problem
        int[][] memo = new int[grid.length][grid.length];

        // Minimum and Second Minimum Column Index
        int nextMin1C = -1;
        int nextMin2C = -1;

        // Base Case. Fill and save the minimum and second minimum column index
        for (int col = 0; col < grid.length; col++) {
            memo[grid.length - 1][col] = grid[grid.length - 1][col];
            if (nextMin1C == -1 || memo[grid.length - 1][col] <= memo[grid.length - 1][nextMin1C]) {
                nextMin2C = nextMin1C;
                nextMin1C = col;
            } else if (nextMin2C == -1 || memo[grid.length - 1][col] <= memo[grid.length - 1][nextMin2C]) {
                nextMin2C = col;
            }
        }

        // Fill the recursive cases
        for (int row = grid.length - 2; row >= 0; row--) {
            // Minimum and Second Minimum Column Index of the current row
            int min1C = -1;
            int min2C = -1;

            for (int col = 0; col < grid.length; col++) {
                // Select minimum from valid cells of the next row
                if (col != nextMin1C) {
                    memo[row][col] = grid[row][col] + memo[row + 1][nextMin1C];
                } else {
                    memo[row][col] = grid[row][col] + memo[row + 1][nextMin2C];
                }

                // Save minimum and second minimum column index
                if (min1C == -1 || memo[row][col] <= memo[row][min1C]) {
                    min2C = min1C;
                    min1C = col;
                } else if (min2C == -1 || memo[row][col] <= memo[row][min2C]) {
                    min2C = col;
                }
            }

            // Change of row. Update nextMin1C and nextMin2C
            nextMin1C = min1C;
            nextMin2C = min2C;
        }

        // Return the minimum from the first row
        return memo[0][nextMin1C];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        # Save the size of the square grid
        n = len(grid)

        # Initialize a two-dimensional array to cache the result of each sub-problem
        memo = [[inf] * n for _ in range(n)]

        # Minimum and Second Minimum Column Index
        next_min1_c = None
        next_min2_c = None
        
        # Base Case. Fill and save the minimum and second minimum column index
        for col in range(n):
            memo[n - 1][col] = grid[n - 1][col]
            if next_min1_c is None or memo[n - 1][col] <= memo[n - 1][next_min1_c]:
                next_min2_c = next_min1_c
                next_min1_c = col
            elif next_min2_c is None or memo[n - 1][col] <= memo[n - 1][next_min2_c]:
                next_min2_c = col
            
        # Fill the recursive cases
        for row in range(n - 2, -1, -1):
            # Minimum and Second Minimum Column Index of the current row
            min1_c = None
            min2_c = None

            for col in range(n):
                # Select minimum from valid cells of the next row
                if col != next_min1_c:
                    memo[row][col] = grid[row][col] + memo[row + 1][next_min1_c]
                else:
                    memo[row][col] = grid[row][col] + memo[row + 1][next_min2_c]
                
                # Save minimum and second minimum column index
                if min1_c is None or memo[row][col] <= memo[row][min1_c]:
                    min2_c = min1_c
                    min1_c = col
                elif min2_c is None or memo[row][col] <= memo[row][min2_c]:
                    min2_c = col
            
            # Change of row. Update next_min1_c and next_min2_c
            next_min1_c = min1_c
            next_min2_c = min2_c
        
        # Return the minimum from the first row
        return memo[0][next_min1_c]
```

</details>

<br>

## Approach 4: Space-Optimized Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Minimum and Second Minimum Column Index
        int nextMin1C = -1;
        int nextMin2C = -1;

        // Minimum and Second Minimum Value
        int nextMin1 = -1;
        int nextMin2 = -1;

        // Find the minimum and second minimum from the last row
        for (int col = 0; col < grid.size(); col++) {
            if (nextMin1 == -1 || grid[grid.size() - 1][col] <= nextMin1) {
                nextMin2 = nextMin1;
                nextMin2C = nextMin1C;
                nextMin1 = grid[grid.size() - 1][col];
                nextMin1C = col;
            } else if (nextMin2 == -1 || grid[grid.size() - 1][col] <= nextMin2) {
                nextMin2 = grid[grid.size() - 1][col];
                nextMin2C = col;
            }
        }

        // Fill the recursive cases
        for (int row = grid.size() - 2; row >= 0; row--) {
            // Minimum and Second Minimum Column Index of the current row
            int min1C = -1;
            int min2C = -1;

            // Minimum and Second Minimum Value of current row
            int min1 = -1;
            int min2 = -1;

            for (int col = 0; col < grid.size(); col++) {
                // Select minimum from valid cells of the next row
                int value;
                if (col != nextMin1C) {
                    value = grid[row][col] + nextMin1;
                } else {
                    value = grid[row][col] + nextMin2;
                }

                // Save minimum and second minimum
                if (min1 == -1 || value <= min1) {
                    min2 = min1;
                    min2C = min1C;
                    min1 = value;
                    min1C = col;
                } else if (min2 == -1 || value <= min2) {
                    min2 = value;
                    min2C = col;
                }
            }

            // Change of row. Update nextMin1C, nextMin2C, nextMin1, nextMin2
            nextMin1C = min1C;
            nextMin2C = min2C;
            nextMin1 = min1;
            nextMin2 = min2;
        }

        // Return the minimum from the first row
        return nextMin1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFallingPathSum(int[][] grid) {
        // Minimum and Second Minimum Column Index
        int nextMin1C = -1;
        int nextMin2C = -1;

        // Minimum and Second Minimum Value
        int nextMin1 = -1;
        int nextMin2 = -1;

        // Find the minimum and second minimum from the last row
        for (int col = 0; col < grid.length; col++) {
            if (nextMin1 == -1 || grid[grid.length - 1][col] <= nextMin1) {
                nextMin2 = nextMin1;
                nextMin2C = nextMin1C;
                nextMin1 = grid[grid.length - 1][col];
                nextMin1C = col;
            } else if (nextMin2 == -1 || grid[grid.length - 1][col] <= nextMin2) {
                nextMin2 = grid[grid.length - 1][col];
                nextMin2C = col;
            }
        }

        // Fill the recursive cases
        for (int row = grid.length - 2; row >= 0; row--) {
            // Minimum and Second Minimum Column Index of the current row
            int min1C = -1;
            int min2C = -1;

            // Minimum and Second Minimum Value of current row
            int min1 = -1;
            int min2 = -1;

            for (int col = 0; col < grid.length; col++) {
                // Select minimum from valid cells of the next row
                int value;
                if (col != nextMin1C) {
                    value = grid[row][col] + nextMin1;
                } else {
                    value = grid[row][col] + nextMin2;
                }

                // Save minimum and second minimum
                if (min1 == -1 || value <= min1) {
                    min2 = min1;
                    min2C = min1C;
                    min1 = value;
                    min1C = col;
                } else if (min2 == -1 || value <= min2) {
                    min2 = value;
                    min2C = col;
                }
            }

            // Change of row. Update nextMin1C, nextMin2C, nextMin1, nextMin2
            nextMin1C = min1C;
            nextMin2C = min2C;
            nextMin1 = min1;
            nextMin2 = min2;
        }
        
        // Return the minimum from the first row
        return nextMin1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        # Save the size of the square grid
        n = len(grid)

        # Minimum and Second Minimum Column Index
        next_min1_c = None
        next_min2_c = None

        # Minimum and Second Minimum Value
        next_min1 = None
        next_min2 = None
        
        # Find the minimum and second minimum from the last row
        for col in range(n):
            if next_min1 is None or grid[n - 1][col] <= next_min1:
                next_min2 = next_min1
                next_min2_c = next_min1_c
                next_min1 = grid[n - 1][col]
                next_min1_c = col
            elif next_min2 is None or grid[n - 1][col] <= next_min2:
                next_min2 = grid[n - 1][col]
                next_min2_c = col
        
        # Fill the recursive cases
        for row in range(n - 2, -1, -1):
            # Minimum and Second Minimum Column Index of the current row
            min1_c = None
            min2_c = None

            # Minimum and Second Minimum Value of the current row
            min1 = None
            min2 = None

            for col in range(n):
                # Select minimum from valid cells of the next row
                if col != next_min1_c:
                    value = grid[row][col] + next_min1
                else:
                    value = grid[row][col] + next_min2
                
                # Save minimum and second minimum 
                if min1 is None or value <= min1:
                    min2 = min1
                    min2_c = min1_c
                    min1 = value
                    min1_c = col
                elif min2 is None or value <= min2:
                    min2 = value
                    min2_c = col
            
            # Change of row. Update next_min1_c, next_min2_c, next_min1, next_min2
            next_min1_c = min1_c
            next_min2_c = min2_c
            next_min1 = min1
            next_min2 = min2
        
        # Return the minimum from the first row
        return next_min1
```

</details>
