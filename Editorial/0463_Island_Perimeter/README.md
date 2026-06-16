# 463. Island Perimeter

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/island-perimeter/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 463 - Island Perimeter](https://leetcode.com/problems/island-perimeter/)

## Problem

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

### Example 1

```text
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

### Example 2

```text
Input: grid = [[1]]
Output: 4
```

### Example 3

```text
Input: grid = [[1,0]]
Output: 4
```

## Constraints

- row == grid.length
- col == grid[i].length
- 1 <= row, col <= 100
- grid[i][j] is 0 or 1.
- There is exactly one island in grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Flood Fill](https://leetcode.com/problems/flood-fill/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Coloring A Border](https://leetcode.com/problems/coloring-a-border/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 463. Island Perimeter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simple Counting | Java, Python3 |
| Better Counting | Java, Python3 |

## Approach 1: Simple Counting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
   public int islandPerimeter(int[][] grid) {
        
        int rows = grid.length;
        int cols = grid[0].length;
        
        int up, down, left, right;
        int result = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    if (r == 0) { up = 0; }
                    else { up = grid[r-1][c]; }
                     
                    if (c == 0) { left = 0; } 
                    else { left = grid[r][c-1]; }
                        
                    if (r == rows-1) { down = 0; }
                    else { down = grid[r+1][c]; }
                        
                    if (c == cols-1) { right = 0; }
                    else { right = grid[r][c+1]; }
                        
                    result += 4-(up+left+right+down);
                }
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        cols = len(grid[0])
        
        result = 0
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    if r == 0:
                        up = 0
                    else:
                        up = grid[r-1][c]
                    if c == 0:
                        left = 0
                    else:
                        left = grid[r][c-1]
                    if r == rows-1:
                        down = 0
                    else:
                        down = grid[r+1][c]
                    if c == cols-1:
                        right = 0
                    else:
                        right = grid[r][c+1]
                        
                    result += 4-(up+left+right+down)
                
        return result
```

</details>

<br>

## Approach 2: Better Counting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        
        int result = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    result += 4;
                    
                    if (r > 0 && grid[r-1][c] == 1) {
                        result -= 2;
                    }
                    
                    if (c > 0 && grid[r][c-1] == 1) {
                        result -= 2;
                    }
                }
            }
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        
        result = 0
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    result += 4
                    
                    if r > 0 and grid[r-1][c] == 1:
                        result -= 2
                        
                    if c > 0 and grid[r][c-1] == 1:
                        result -= 2
        
        return result
```

</details>
