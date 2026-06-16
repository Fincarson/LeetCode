# 2812. Find the Safest Path in a Grid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)  
`Array` `Binary Search` `Breadth-First Search` `Union-Find` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 2812 - Find the Safest Path in a Grid](https://leetcode.com/problems/find-the-safest-path-in-a-grid/)

## Problem

You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

- A cell containing a thief if grid[r][c] = 1
- An empty cell if grid[r][c] = 0

You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

### Example 1

```text
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
```

### Example 2

```text
Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
```

### Example 3

```text
Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.
```

## Constraints

- 1 <= grid.length == n <= 400
- grid[i].length == n
- grid[i][j] is either 0 or 1.
- There is at least one thief in the grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2812. Find the Safest Path in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search + Binary Search | C++, Java, Python3 |
| BFS + Greedy | C++, Java, Python3 |

## Approach 1: Breadth-First Search + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> multiSourceQueue;
        // Mark thieves as 0 and empty cells as -1, and push thieves to the
        // queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // Push thief coordinates to the queue
                    multiSourceQueue.push({i, j});
                    // Mark thief cell with 0
                    grid[i][j] = 0;
                } else {
                    // Mark empty cell with -1
                    grid[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                // Check neighboring cells
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        // Update safeness factor and push to the queue
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        // Binary search for maximum safeness factor
        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Set end as the maximum safeness factor possible
                end = max(end, grid[i][j]);
            }
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(grid, mid)) {
                // Store valid safeness and search for larger ones
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return res;
    }

private:

    // Directions for moving to neighboring cells: right, left, down, up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Check if a given cell lies within the grid
    bool isValidCell(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    // Check if a path exists with given minimum safeness value
    bool isValidSafeness(vector<vector<int>>& grid, int minSafeness) {
        int n = grid.size();

        // Check if the source and destination cells satisfy minimum safeness
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        queue<pair<int, int>> traversalQueue;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        traversalQueue.push({0, 0});
        visited[0][0] = true;

        // Breadth-first search to find a valid path
        while (!traversalQueue.empty()) {
            auto curr = traversalQueue.front();
            traversalQueue.pop();
            if (curr.first == n - 1 && curr.second == n - 1) {
                return true; // Valid path found
            }
            // Check neighboring cells
            for (auto& d : dir) {
                int di = curr.first + d[0];
                int dj = curr.second + d[1];
                // Check if the neighboring cell is valid and unvisited
                if (isValidCell(grid, di, dj) && !visited[di][dj] &&
                    grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.push({di, dj});
                }
            }
        }

        return false; // No valid path found
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for moving to neighboring cells: right, left, down, up
    final int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] mat = new int[n][n];
        Queue<int[]> multiSourceQueue = new LinkedList<>();

        // To make modifications and navigation easier, the grid is converted into a 2-d array.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    // Push thief coordinates to the queue
                    multiSourceQueue.add(new int[]{i, j});
                    // Mark thief cell with 0
                    mat[i][j] = 0;
                } else {
                    // Mark empty cell with -1
                    mat[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.isEmpty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                int[] curr = multiSourceQueue.poll();
                // Check neighboring cells
                for (int[] d : dir) {
                    int di = curr[0] + d[0];
                    int dj = curr[1] + d[1];
                    int val = mat[curr[0]][curr[1]];
                    // Check if the neighboring cell is valid and unvisited
                    if (isValidCell(mat, di, dj) && mat[di][dj] == -1) {
                        // Update safeness factor and push to the queue
                        mat[di][dj] = val + 1;
                        multiSourceQueue.add(new int[]{di, dj});
                    }
                }
            }
        }

        // Binary search for maximum safeness factor
        int start = 0;
        int end = 0;
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Set end as the maximum safeness factor possible
                end = Math.max(end, mat[i][j]);
            }
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidSafeness(mat, mid)) {
                // Store valid safeness and search for larger ones 
                res = mid; 
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }

    // Check if a path exists with given minimum safeness value
    private boolean isValidSafeness(int[][] grid, int minSafeness) {
        int n = grid.length;

        // Check if the source and destination cells satisfy minimum safeness
        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        Queue<int[]> traversalQueue = new LinkedList<>();
        traversalQueue.add(new int[]{0, 0});
        boolean[][] visited = new boolean[n][n];
        visited[0][0] = true;

        // Breadth-first search to find a valid path
        while (!traversalQueue.isEmpty()) {
            int[] curr = traversalQueue.poll();
            if (curr[0] == n - 1 && curr[1] == n - 1) {
                return true; // Valid path found
            }
            // Check neighboring cells
            for (int[] d : dir) {
                int di = curr[0] + d[0];
                int dj = curr[1] + d[1];
                // Check if the neighboring cell is valid, unvisited and satisfying minimum safeness
                if (isValidCell(grid, di, dj) && !visited[di][dj] && grid[di][dj] >= minSafeness) {
                    visited[di][dj] = true;
                    traversalQueue.add(new int[]{di, dj});
                }
            }
        }

        return false; // No valid path found
    }

    // Check if a given cell lies within the grid
    private boolean isValidCell(int[][] mat, int i, int j) {
        int n = mat.length;
        return i >= 0 && j >= 0 && i < n && j < n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Directions for moving to neighboring cells: right, left, down, up
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        multi_source_queue = deque()
        # Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    # Push thief coordinates to the queue
                    multi_source_queue.append((i, j))
                    # Mark thief cell with 0
                    grid[i][j] = 0
                else:
                    # Mark empty cell with -1
                    grid[i][j] = -1

        # Calculate safeness factor for each cell using BFS
        while multi_source_queue:
            size = len(multi_source_queue)
            while size > 0:
                curr = multi_source_queue.popleft()
                # Check neighboring cells
                for d in self.dir:
                    di, dj = curr[0] + d[0], curr[1] + d[1]
                    val = grid[curr[0]][curr[1]]
                    # Check if the cell is valid and unvisited
                    if self.isValidCell(grid, di, dj) and grid[di][dj] == -1:
                        # Update safeness factor and push to the queue
                        grid[di][dj] = val + 1
                        multi_source_queue.append((di, dj))
                size -= 1

        # Binary search for maximum safeness factor
        start, end, res = 0, 0, -1
        for i in range(n):
            for j in range(n):
                # Set end as the maximum safeness factor possible
                end = max(end, grid[i][j])

        while start <= end:
            mid = start + (end - start) // 2
            if self.isValidSafeness(grid, mid):
                # Store valid safeness and search for larger ones
                res = mid
                start = mid + 1
            else:
                end = mid - 1

        return res
    
    # Check if a given cell lies within the grid
    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

    # Check if a path exists with given minimum safeness value
    def isValidSafeness(self, grid, min_safeness) -> bool:
        n = len(grid)

        # Check if the source and destination cells satisfy minimum safeness
        if grid[0][0] < min_safeness or grid[n - 1][n - 1] < min_safeness:
            return False

        traversal_queue = deque([(0, 0)])
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        # Breadth-first search to find a valid path
        while traversal_queue:
            curr = traversal_queue.popleft()
            if curr[0] == n - 1 and curr[1] == n - 1:
                return True  # Valid path found

            # Check neighboring cells
            for d in self.dir:
                di, dj = curr[0] + d[0], curr[1] + d[1]
                # Check if the neighboring cell is valid and unvisited
                if self.isValidCell(grid, di, dj) and not visited[di][dj] and grid[di][dj] >= min_safeness:
                    visited[di][dj] = True
                    traversal_queue.append((di, dj))

        return False  # No valid path found
```

</details>

<br>

## Approach 2: BFS + Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSourceQueue;

        // Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                // Check neighboring cells
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    // Check if the neighboring cell is valid and unvisited
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        // Priority queue to prioritize cells with higher safeness factor
        priority_queue<vector<int>> pq;
        // Push starting cell to the priority queue
        pq.push(vector<int>{grid[0][0], 0, 0}); // [maximum_safeness_till_now, x-coordinate, y-coordinate]
        grid[0][0] = -1; // Mark the source cell as visited

        // BFS to find the path with maximum safeness factor
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            // If reached the destination, return safeness factor
            if (curr[1] == n - 1 && curr[2] == n - 1) {
                return curr[0];
            }

            // Explore neighboring cells
            for (auto& d : dir) {
                int di = d[0] + curr[1];
                int dj = d[1] + curr[2];
                if (isValidCell(grid, di, dj) && grid[di][dj] != -1) {
                    // Update safeness factor for the path and mark the cell as visited
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }

        return -1; // No valid path found
    }

private:

    // Directions for moving to neighboring cells: right, left, down, up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Check if a given cell lies within the grid
    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for moving to neighboring cells: right, left, down, up
    final int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] mat = new int[n][n];
        Queue<int[]> multiSourceQueue = new LinkedList<>();

        // To make modifications and navigation easier, the grid is converted into a 2-d array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    // Push thief coordinates to the queue
                    multiSourceQueue.add(new int[] {i, j});
                    // Mark thief cell with 0
                    mat[i][j] = 0;
                } else {
                    // Mark empty cell with -1
                    mat[i][j] = -1;
                }
            }
        }

        // Calculate safeness factor for each cell using BFS
        while (!multiSourceQueue.isEmpty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                int[] curr = multiSourceQueue.poll();
                // Check neighboring cells
                for (int[] d : dir) {
                    int di = curr[0] + d[0];
                    int dj = curr[1] + d[1];
                    int val = mat[curr[0]][curr[1]];
                    // Check if the neighboring cell is valid and unvisited
                    if (isValidCell(mat, di, dj) && mat[di][dj] == -1) {
                        // Update safeness factor and push to the queue
                        mat[di][dj] = val + 1;
                        multiSourceQueue.add(new int[] {di, dj});
                    }
                }
            }
        }

        // Priority queue to prioritize cells with higher safeness factor
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[2] - a[2]);
        // Push starting cell to the priority queue
        pq.add(new int[] {0, 0, mat[0][0]}); // [x-coordinate, y-coordinate, maximum_safeness_till_now]
        mat[0][0] = -1; // Mark the source cell as visited

        // BFS to find the path with maximum safeness factor
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            // If reached the destination, return safeness factor
            if (curr[0] == n - 1 && curr[1] == n - 1) {
                return curr[2];
            }
            // Explore neighboring cells
            for (int[] d : dir) {
                int di = d[0] + curr[0];
                int dj = d[1] + curr[1];
                if (isValidCell(mat, di, dj) && mat[di][dj] != -1) {
                    // Update safeness factor for the path and mark the cell as visited
                    pq.add(new int[] {di, dj, Math.min(curr[2], mat[di][dj])});
                    mat[di][dj] = -1;
                }
            }
        }

        return -1; // No valid path found
    }

    // Check if a given cell lies within the grid
    private boolean isValidCell(int[][] mat, int i, int j) {
        int n = mat.length;
        return i >= 0 && j >= 0 && i < n && j < n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Directions for moving to neighboring cells: right, left, down, up
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        multi_source_queue = deque()
        # Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    # Push thief coordinates to the queue
                    multi_source_queue.append((i, j))
                    # Mark thief cell with 0
                    grid[i][j] = 0
                else:
                    # Mark empty cell with -1
                    grid[i][j] = -1

        # Calculate safeness factor for each cell using BFS
        while multi_source_queue:
            size = len(multi_source_queue)
            while size > 0:
                curr = multi_source_queue.popleft()
                # Check neighboring cells
                for d in self.dir:
                    di, dj = curr[0] + d[0], curr[1] + d[1]
                    val = grid[curr[0]][curr[1]]
                    # Check if the cell is valid and unvisited
                    if self.isValidCell(grid, di, dj) and grid[di][dj] == -1:
                        # Update safeness factor and push to the queue
                        grid[di][dj] = val + 1
                        multi_source_queue.append((di, dj))
                size -= 1
        
        # Priority queue to prioritize cells with higher safeness factor
        pq = [[-grid[0][0], 0, 0]] # [maximum_safeness_till_now, x-coordinate, y-coordinate]
        grid[0][0] = -1 # Mark the source cell as visited

        # BFS to find the path with maximum safeness factor
        while pq:
            safeness, i, j = heapq.heappop(pq)
            
            # If reached the destination, return safeness factor
            if i == n - 1 and j == n - 1:
                return -safeness
            
            # Check neighboring cells
            for d in self.dir:
                di, dj = i + d[0], j + d[1]
                # Check if the neighboring cell is valid and unvisited
                if self.isValidCell(grid, di, dj) and grid[di][dj] != -1:
                    heapq.heappush(pq, [-min(-safeness, grid[di][dj]), di, dj])
                    grid[di][dj] = -1

        return -1
    
    # Check if a given cell lies within the grid
    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n
```

</details>
