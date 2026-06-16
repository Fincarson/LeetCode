# 1970. Last Day Where You Can Still Cross

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/last-day-where-you-can-still-cross/)  
`Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 1970 - Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/)

## Problem

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

### Example 1

```text
Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
```

### Example 2

```text
Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
```

### Example 3

```text
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
```

## Constraints

- 2 <= row, col <= 2 * 104
- 4 <= row * col <= 2 * 104
- cells.length == row * col
- 1 <= ri <= row
- 1 <= ci <= col
- All the values of cells are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bricks Falling When Hit](https://leetcode.com/problems/bricks-falling-when-hit/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Escape the Spreading Fire](https://leetcode.com/problems/escape-the-spreading-fire/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1970. Last Day Where You Can Still Cross

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search + Breadth-First Search | Java, Python3 |
| Binary Search + Depth-First Search | Java, Python3 |
| Disjoint Set Union (on land cells) | Java, Python3 |
| Disjoint Set Union (on water cells) | Java, Python3 |

## Approach 1: Binary Search + Breadth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public boolean canCross(int row, int col, int[][] cells, int day) {
        int[][] grid = new int[row][col];
        Queue<int[]> queue = new LinkedList<>();
        
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                queue.offer(new int[]{0, i});
                grid[0][i] = -1;
            }
        }

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int r = cur[0], c = cur[1];
            if (r == row - 1) {
                return true;
            }
            
            for (int[] dir : directions) {
                int newRow = r + dir[0];
                int newCol = c + dir[1];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = -1;
                    queue.offer(new int[]{newRow, newCol});
                }
            }
        }
        
        return false;
    }
    
    public int latestDayToCross(int row, int col, int[][] cells) {
        int left = 1;
        int right = row * col;
        
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canCross(self, row, col, cells, day):
        grid = [[0] * col for _ in range(row)]
        queue = collections.deque()
        
        for r, c in cells[:day]:
            grid[r - 1][c - 1] = 1
            
        for i in range(col):
            if not grid[0][i]:
                queue.append((0, i))
                grid[0][i] = -1

        while queue:
            r, c = queue.popleft()
            if r == row - 1:
                return True
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                new_row, new_col = r + dr, c + dc
                if 0 <= new_row < row and 0 <= new_col < col and grid[new_row][new_col] == 0:
                    grid[new_row][new_col] = -1
                    queue.append((new_row, new_col))
                    
        return False
    
    
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        left, right = 1, row * col
        
        while left < right:
            mid = right - (right - left) // 2
            if self.canCross(row, col, cells, mid):
                left = mid
            else:
                right = mid - 1
                
        return left
```

</details>

<br>

## Approach 2: Binary Search + Depth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public boolean canCross(int row, int col, int[][] cells, int day) {
        int[][] grid = new int[row][col];
        for (int i = 0; i < day; ++i) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
        
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        for (int i = 0; i < col; ++i) {
            if (grid[0][i] == 0 && dfs(grid, 0, i, row, col)) {
                return true;
            }
        }
        return false;
        
    }

    private boolean dfs(int[][] grid, int r, int c, int row, int col) {
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != 0) {
            return false;
        }
        if (r == row - 1) {
            return true;
        }
        grid[r][c] = -1;
        for (int[] dir : directions) {
            int newR = r + dir[0], newC = c + dir[1];
            if (dfs(grid, newR, newC, row, col)) {
                return true;
            }
        }
        return false;
    }

    public int latestDayToCross(int row, int col, int[][] cells) {
        int left = 1, right = row * col;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canCross(self, row, col, cells, day):
        grid = [[0] * col for _ in range(row)]
        
        for r, c in cells[:day]:
            grid[r - 1][c - 1] = 1
            
        def dfs(r, c):
            if r < 0 or r >= row or c < 0 or c >= col or grid[r][c] != 0:
                return False
            if r == row - 1:
                return True
            grid[r][c] = -1
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                if dfs(r + dr, c + dc):
                    return True
            return False
        
        for i in range(col):
            if grid[0][i] == 0 and dfs(0, i):
                return True

        return False
    
    
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        left, right = 1, row * col
        
        while left < right:
            mid = right - (right - left) // 2
            if self.canCross(row, col, cells, mid):
                left = mid
            else:
                right = mid - 1
                
        return left
```

</details>

<br>

## Approach 3: Disjoint Set Union (on land cells)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class DSU {
    int[] root, size;
    
    public DSU(int n) {
        root = new int[n];
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
        size = new int[n];
        Arrays.fill(size, 1);
    }
    
    public int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        
        if (size[rootX] > size[rootY]) {
            int tmp = rootX;
            rootX = rootY;
            rootY = tmp;
        }
        root[rootX] = rootY;
        size[rootY] += size[rootX];
    }
}

class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        DSU dsu = new DSU(row * col + 2);
        int[][] grid = new int[row][col];
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = cells.length - 1; i >= 0; i--) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
            int index1 = r * col + c + 1;
            for (int[] d : directions) {
                int newR = r + d[0], newC = c + d[1];
                int index2 = newR * col + newC + 1;
                if (newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1) {
                    dsu.union(index1, index2);
                }
            }
            if (r == 0) {
                dsu.union(0, index1);
            }
            if (r == row - 1) {
                dsu.union(row * col + 1, index1);
            }
            if (dsu.find(0) == dsu.find(row * col + 1)) {
                return i;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DSU:
    def __init__(self, n):
        self.root = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return
        
        if self.size[root_x] > self.size[root_y]:
            root_x, root_y = root_y, root_x
        self.root[root_x] = root_y
        self.size[root_y] += self.size[root_x]

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        dsu = DSU(row * col + 2)
        grid = [[1] * col for _ in range(row)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        for i in range(len(cells) - 1, -1, -1):
            r, c = cells[i][0] - 1, cells[i][1] - 1
            grid[r][c] = 0
            index_1 = r * col + c + 1
            for dr, dc in directions:
                new_r, new_c = r + dr, c + dc
                index_2 = new_r * col + new_c + 1
                if 0 <= new_r < row and 0 <= new_c < col and grid[new_r][new_c] == 0:
                    dsu.union(index_1, index_2)
                    
            if r == 0:
                dsu.union(0, index_1)
            if r == row - 1:
                dsu.union(row * col + 1, index_1)
            if dsu.find(0) == dsu.find(row * col + 1):
                return i
```

</details>

<br>

## Approach 4: Disjoint Set Union (on water cells)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class DSU {
    int[] root, size;
    
    public DSU(int n) {
        root = new int[n];
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
        size = new int[n];
        Arrays.fill(size, 1);
    }
    
    public int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        
        if (size[rootX] > size[rootY]) {
            int tmp = rootX;
            rootX = rootY;
            rootY = tmp;
        }
        root[rootX] = rootY;
        size[rootY] += size[rootX];
    }
}

class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        DSU dsu = new DSU(row * col + 2);
        int[][] grid = new int[row][col];
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        for (int i = 0; i < row * col; ++i) {
            int r = cells[i][0] - 1, c = cells[i][1] - 1;
            grid[r][c] = 1;
            int index1 = r * col + c + 1;
            for (int[] d : directions) {
                int newR = r + d[0], newC = c + d[1];
                int index2 = newR * col + newC + 1;
                if (newR >= 0 && newR < row && newC >= 0 && newC < col && grid[newR][newC] == 1) {
                    dsu.union(index1, index2);
                }
            }
            if (c == 0) {
                dsu.union(0, index1);
            }
            if (c == col - 1) {
                dsu.union(row * col + 1, index1);
            }
            if (dsu.find(0) == dsu.find(row * col + 1)) {
                return i;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DSU:
    def __init__(self, n):
        self.root = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return
        
        if self.size[root_x] > self.size[root_y]:
            root_x, root_y = root_y, root_x
        self.root[root_x] = root_y
        self.size[root_y] += self.size[root_x]

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        dsu = DSU(row * col + 2)
        grid = [[0] * col for _ in range(row)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]

        for i in range(row * col):
            r, c = cells[i][0] - 1, cells[i][1] - 1
            grid[r][c] = 1
            index_1 = r * col + c + 1
            for dr, dc in directions:
                new_r, new_c = r + dr, c + dc
                index_2 = new_r * col + new_c + 1
                if 0 <= new_r < row and 0 <= new_c < col and grid[new_r][new_c] == 1:
                    dsu.union(index_1, index_2)
                    
            if c == 0:
                dsu.union(0, index_1)
            if c == col - 1:
                dsu.union(row * col + 1, index_1)
            if dsu.find(0) == dsu.find(row * col + 1):
                return i
```

</details>
