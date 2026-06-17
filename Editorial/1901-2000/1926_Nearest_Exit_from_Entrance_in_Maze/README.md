# 1926. Nearest Exit from Entrance in Maze

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1926 - Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)

## Problem

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

### Example 1

```text
Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
```

### Example 2

```text
Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
```

### Example 3

```text
Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.
```

## Constraints

- maze.length == m
- maze[i].length == n
- 1 <= m, n <= 100
- maze[i][j] is either '.' or '+'.
- entrance.length == 2
- 0 <= entrancerow < m
- 0 <= entrancecol < n
- entrance will always be an empty cell.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1926. Nearest Exit from Entrance in Maze

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Breadth First Search (BFS) | C++, Java, Python3 |

## Approach: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = int(maze.size()), cols = int(maze[0].size());
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Mark the entrance as visited since its not a exit.
        int startRow = entrance[0], startCol = entrance[1];
        maze[startRow][startCol] = '+';
        
        // Start BFS from the entrance, and use a queue `queue` to store all 
        // the cells to be visited.
        queue<array<int, 3>> queue;
        queue.push({startRow, startCol, 0});
        
        while (!queue.empty()) {
            auto [currRow, currCol, currDistance] = queue.front();
            queue.pop();
            
            // For the current cell, check its four neighbor cells.
            for (auto dir : dirs) {
                int nextRow = currRow + dir.first, nextCol = currCol + dir.second;

                // If there exists an unvisited empty neighbor:
                if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols \
                   && maze[nextRow][nextCol] == '.') {
                    
                    // If this empty cell is an exit, return distance + 1.
                    if (nextRow == 0 || nextRow == rows - 1 || nextCol == 0 || nextCol == cols - 1)
                        return currDistance + 1;
                    
                    // Otherwise, add this cell to 'queue' and mark it as visited.
                    maze[nextRow][nextCol] = '+';
                    queue.push({nextRow, nextCol, currDistance + 1});
                    
                }
            }
        }
        
        // If we finish iterating without finding an exit, return -1.
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int rows = maze.length, cols = maze[0].length;
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Mark the entrance as visited since its not a exit.
        int startRow = entrance[0], startCol = entrance[1];
        maze[startRow][startCol] = '+';
        
        // Start BFS from the entrance, and use a queue `queue` to store all 
        // the cells to be visited.
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startRow, startCol, 0});
        
        while (!queue.isEmpty()) {
            int[] currState = queue.poll();
            int currRow = currState[0], currCol = currState[1], currDistance = currState[2];

            // For the current cell, check its four neighbor cells.
            for (int[] dir : dirs) {
                int nextRow = currRow + dir[0], nextCol = currCol + dir[1];

                // If there exists an unvisited empty neighbor:
                if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols
                   && maze[nextRow][nextCol] == '.') {
                    
                    // If this empty cell is an exit, return distance + 1.
                    if (nextRow == 0 || nextRow == rows - 1 || nextCol == 0 || nextCol == cols - 1)
                        return currDistance + 1;
                    
                    // Otherwise, add this cell to 'queue' and mark it as visited.
                    maze[nextRow][nextCol] = '+';
                    queue.offer(new int[]{nextRow, nextCol, currDistance + 1});
                }  
            }
        }

        // If we finish iterating without finding an exit, return -1.
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        rows, cols = len(maze), len(maze[0])
        dirs = ((1, 0), (-1, 0), (0, 1), (0, -1))
        
        # Mark the entrance as visited since its not a exit.
        start_row, start_col = entrance
        maze[start_row][start_col] = "+"
        
        # Start BFS from the entrance, and use a queue `queue` to store all 
        # the cells to be visited.
        queue = collections.deque()
        queue.append([start_row, start_col, 0])
        
        while queue:
            curr_row, curr_col, curr_distance = queue.popleft()
            
            # For the current cell, check its four neighbor cells.
            for d in dirs:
                next_row = curr_row + d[0]
                next_col = curr_col + d[1]
                
                # If there exists an unvisited empty neighbor:
                if 0 <= next_row < rows and 0 <= next_col < cols \
                    and maze[next_row][next_col] == ".":
                    
                    # If this empty cell is an exit, return distance + 1.
                    if 0 == next_row or next_row == rows - 1 or 0 == next_col or next_col == cols - 1:
                        return curr_distance + 1
                    
                    # Otherwise, add this cell to 'queue' and mark it as visited.
                    maze[next_row][next_col] = "+"
                    queue.append([next_row, next_col, curr_distance + 1])
            
        # If we finish iterating without finding an exit, return -1.
        return -1
```

</details>
