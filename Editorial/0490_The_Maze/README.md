# 490. The Maze

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/the-maze/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 490 - The Maze](https://leetcode.com/problems/the-maze/)

## Problem

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

### Example 1

```text
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

### Example 2

```text
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
```

### Example 3

```text
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
```

## Constraints

- m == maze.length
- n == maze[i].length
- 1 <= m, n <= 100
- maze[i][j] is 0 or 1.
- start.length == 2
- destination.length == 2
- 0 <= startrow, destinationrow < m
- 0 <= startcol, destinationcol < n
- Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
- The maze contains at least 2 empty spaces.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Maze III](https://leetcode.com/problems/the-maze-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [The Maze II](https://leetcode.com/problems/the-maze-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 490. The Maze

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| Breadth First Search | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool dfs(int m, int n, vector<vector<int>>& maze, vector<int> curr, vector<int>& destination,
             vector<vector<bool>>& visit) {
        if (visit[curr[0]][curr[1]]) {
            return false;
        }
        if (curr[0] == destination[0] && curr[1] == destination[1]) {
            return true;
        }

        visit[curr[0]][curr[1]] = true;
        vector<int> dirX{0, 1, 0, -1};
        vector<int> dirY{-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = curr[0], c = curr[1];
            // Move the ball in the chosen direction until it can.
            while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                r += dirX[i];
                c += dirY[i];
            }
            // Revert the last move to get the cell to which the ball rolls. 
            if (dfs(m, n, maze, {r - dirX[i], c - dirY[i]}, destination, visit)) {
                return true;
            }
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        return dfs(m, n, maze, start, destination, visit);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean dfs(int m, int n, int[][] maze, int[] curr, int[] destination,
                boolean[][] visit) {
        if (visit[curr[0]][curr[1]]) {
            return false;
        }
        if (curr[0] == destination[0] && curr[1] == destination[1]) {
            return true;
        }

        visit[curr[0]][curr[1]] = true;
        int[] dirX = {0, 1, 0, -1};
        int[] dirY = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = curr[0], c = curr[1];
            // Move the ball in the chosen direction until it can.
            while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                r += dirX[i];
                c += dirY[i];
            }
            // Revert the last move to get the cell to which the ball rolls.
            if (dfs(m, n, maze, new int[]{r - dirX[i], c - dirY[i]}, destination, visit)) {
                return true;
            }
        }
        return false;
    }

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length;
        int n = maze[0].length;
        boolean[][] visit = new boolean[m][n];
        return dfs(m, n, maze, start, destination, visit);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dfs(self, m, n, maze, curr, destination, visit):
        if visit[curr[0]][curr[1]]:
            return False
        if curr[0] == destination[0] and curr[1] == destination[1]:
            return True

        visit[curr[0]][curr[1]] = True
        dirX = [0, 1, 0, -1]
        dirY = [-1, 0, 1, 0]

        for i in range(4):
            r = curr[0]
            c = curr[1]
            # Move the ball in the chosen direction until it can.
            while r >= 0 and r < m and c >= 0 and c < n and maze[r][c] == 0:
                r += dirX[i]
                c += dirY[i]
            # Revert the last move to get the cell to which the ball rolls.
            if self.dfs(m, n, maze, [r - dirX[i], c - dirY[i]], destination, visit):
                return True
        return False

    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m = len(maze)
        n = len(maze[0])
        visit = [[False] * n for _ in range(m)]
        return self.dfs(m, n, maze, start, destination, visit)
```

</details>

<br>

## Approach 2: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<int> dirX{0, 1, 0, -1};
        vector<int> dirY{-1, 0, 1, 0};

        queue<vector<int>> q;
        q.push(start);
        visit[start[0]][start[1]] = true;

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (curr[0] == destination[0] && curr[1] == destination[1]) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int r = curr[0];
                int c = curr[1];
                // Move the ball in the chosen direction until it can.
                while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                    r += dirX[i];
                    c += dirY[i];
                }
                // Revert the last move to get the cell to which the ball rolls.
                r -= dirX[i];
                c -= dirY[i];
                if (!visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int m = maze.length;
        int n = maze[0].length;
        boolean[][] visit = new boolean[m][n];
        int[] dirX = {0, 1, 0, -1};
        int[] dirY = {-1, 0, 1, 0};

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(start);
        visit[start[0]][start[1]] = true;

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            if (curr[0] == destination[0] && curr[1] == destination[1]) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int r = curr[0];
                int c = curr[1];
                // Move the ball in the chosen direction until it can.
                while (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0) {
                    r += dirX[i];
                    c += dirY[i];
                }
                // Revert the last move to get the cell to which the ball rolls.
                r -= dirX[i];
                c -= dirY[i];
                if (!visit[r][c]) {
                    queue.offer(new int[]{r, c});
                    visit[r][c] = true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m = len(maze)
        n = len(maze[0])
        visit = [[False] * n for _ in range(m)]
        queue = deque()
        
        queue.append(start)
        visit[start[0]][start[1]] = True
        dirX = [0, 1, 0, -1]
        dirY = [-1, 0, 1, 0]

        while queue:
            curr = queue.popleft()
            if curr[0] == destination[0] and curr[1] == destination[1]:
                return True

            for i in range(4):
                r = curr[0]
                c = curr[1]
                # Move the ball in the chosen direction until it can.
                while r >= 0 and r < m and c >= 0 and c < n and maze[r][c] == 0:
                    r += dirX[i]
                    c += dirY[i]
                # Revert the last move to get the cell to which the ball rolls.
                r -= dirX[i]
                c -= dirY[i]
                if not visit[r][c]:
                    queue.append([r, c])
                    visit[r][c] = True
        return False
```

</details>
