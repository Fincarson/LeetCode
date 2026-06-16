# 1254. Number of Closed Islands

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-closed-islands/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 1254 - Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)

## Problem

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

### Example 1

```text
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

### Example 2

```text
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
```

### Example 3

```text
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
```

## Constraints

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1254. Number of Closed Islands

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;   // row nnumber
            y = q.front().second;  // column number
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                } else if (grid[r][c] == 0 && !visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }

        return isClosed;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visit = new boolean[m][n];
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    public boolean bfs(int x, int y, int m, int n, int[][] grid, boolean[][] visit) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visit[x][y] = true;
        boolean isClosed = true;

        int[] dirx = {0, 1, 0, -1};
        int[] diry = {-1, 0, 1, 0};

        while (!q.isEmpty()) {
            int[] temp = q.poll();
            x = temp[0];
            y = temp[1];

            for (int i = 0; i < 4; i++) {
                int r = x +dirx[i];
                int c = y +diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    // (x, y) is a boundary cell.
                    isClosed = false;
                } else if (grid[r][c] == 0 && !visit[r][c]) {
                    q.offer(new int[]{r, c});
                    visit[r][c] = true;
                }
            }
        }

        return isClosed;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visit = [[False] * n for _ in range(m)]
        count = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and not visit[i][j] and self.bfs(i, j, m, n, grid, visit):
                    count += 1
                    
        return count

    def bfs(self, x: int, y: int, m: int, n: int, grid: List[List[int]], visit: List[List[bool]]) -> bool:
        q = deque([(x, y)])
        visit[x][y] = True
        is_closed = True

        dirx = [0, 1, 0, -1]
        diry = [-1, 0, 1, 0]

        while q:
            x, y = q.popleft()

            for i in range(4):
                r, c = x + dirx[i], y + diry[i]
                if r < 0 or r >= m or c < 0 or c >= n:
                    # (x, y) is a boundary cell.
                    is_closed = False
                elif grid[r][c] == 0 and not visit[r][c]:
                    q.append((r, c))
                    visit[r][c] = True

        return is_closed
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1 || visit[x][y]) {
            return true;
        }

        visit[x][y] = true;
        bool isClosed = true;
        vector<int> dirx {0, 1, 0, -1};
        vector<int> diry {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i];
            int c = y + diry[i];
            if (!dfs(r, c, m, n, grid, visit)) {
                isClosed = false;
            }
        }

        return isClosed;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visit = new boolean[m][n];
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit)) {
                    count++;
                }
            }
        }
        return count;
    }

    public boolean dfs(int x, int y, int m, int n, int[][] grid, boolean[][] visit) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1 || visit[x][y]) {
            return true;
        }

        visit[x][y] = true;
        bool isClosed = true;
        int[] dirx = {0, 1, 0, -1};
        int[] diry = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i];
            int c = y + diry[i];
            if (!dfs(r, c, m, n, grid, visit)) {
                isClosed = false;
            }
        }

        return isClosed;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visit = [[False] * n for _ in range(m)]
        count = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and not visit[i][j] and self.dfs(i, j, m, n, grid, visit):
                    count += 1
        return count

    def dfs(self, x: int, y: int, m: int, n: int, grid: List[List[int]], visit: List[List[bool]]) -> bool:
        if x < 0 or x >= m or y < 0 or y >= n:
            return False
        if grid[x][y] == 1 or visit[x][y]:
            return True

        visit[x][y] = True
        is_closed = True
        dirx = [0, 1, 0, -1]
        diry = [-1, 0, 1, 0]

        for i in range(4):
            r = x + dirx[i]
            c = y + diry[i]
            if not self.dfs(r, c, m, n, grid, visit):
                is_closed = False

        return is_closed
```

</details>
