# 1102. Path With Maximum Minimum Value

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/path-with-maximum-minimum-value/)  
`Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Union-Find` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 1102 - Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value/)

## Problem

Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) moving in the 4 cardinal directions.

The score of a path is the minimum value in that path.

- For example, the score of the path 8 Ã¢â€ â€™ 4 Ã¢â€ â€™ 5 Ã¢â€ â€™ 9 is 4.

### Example 1

```text
Input: grid = [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: The path with the maximum score is highlighted in yellow.
```

### Example 2

```text
Input: grid = [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
```

### Example 3

```text
Input: grid = [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- 0 <= grid[i][j] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1102. Path With Maximum Minimum Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration + BFS | C++, Java, Python3 |
| Binary Search + Breadth First Search (BFS) | C++, Java, Python3 |
| Binary Search + Depth First Search (DFS) | C++, Java, Python3 |
| BFS + PriorityQueue | C++, Java, Python3 |
| Union Find | C++, Java, Python3 |

## Approach 1: Iteration + BFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int curScore = min(grid[0][0], grid[R - 1][C - 1]);

        // Start with "curScore", check if we can find a path having score
        // equals "curScore". If so, return curScore as the maximum score,
        // otherwise, decrease curScore by 1 and repeat these steps.
        while (curScore >= 0) {
            if (pathExists(grid, curScore)) {
                return curScore;
            } else {
                curScore = curScore - 1;
            }
        }
        return -1;
    }

    // Check if we can find a path of score equals curScore.
    bool pathExists(vector<vector<int>>& grid, int curScore) {
        int R = grid.size(), C = grid[0].size();
        // Maintain the visited status of each cell. Initialize the status of
        // all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        visited[0][0] = true;
        deque<pair<int, int>> dq({{0, 0}});

        auto push = [&](int row, int col) {
            if (row == -1 || col == -1 || row == R || col == C ||
                visited[row][col] || grid[row][col] < curScore)
                return;
            dq.push_back({row, col});
            visited[row][col] = true;
        };

        // While we still have cells of value larger than or equal to curScore.
        while (!dq.empty()) {
            int curRow = dq.front().first, curCol = dq.front().second;
            dq.pop_front();

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) {
                return true;
            }

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to curScore. If so, we put this neighbor to
            // the deque and mark it as visited
            push(curRow + 1, curCol);
            push(curRow - 1, curCol);
            push(curRow, curCol + 1);
            push(curRow, curCol - 1);
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

    // 4 directions to a cell's possible neighbors.
    public int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        int curScore = Math.min(grid[0][0], grid[R - 1][C - 1]);

        // Start with curScore, check if we can find a path having value equals curScore.
        // If so, return curScore as the maximum score, otherwise, decrease curScore
        // by 1 and repeat these steps.
        while (curScore >= 0) {
            if (pathExists(grid, curScore)) {
                return curScore;
            } else {
                curScore = curScore - 1;
            }
        }
        return -1;
    }

    // Check if we can find a path of score equals curScore.
    private boolean pathExists(int[][] grid, int curScore) {
        int R = grid.length, C = grid[0].length;

        // Maintain the visited status of each cell. Initalize the status of
        // all the cells as false (unvisited).
        boolean[][] visited = new boolean[R][C];
        visited[0][0] = true;

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        Queue<int[]> deque = new LinkedList<>();
        deque.offer(new int[] { 0, 0 });

        // While we still have cells of value larger than or equal to curScore.
        while (!deque.isEmpty()) {
            int[] curGrid = deque.poll();
            int curRow = curGrid[0];
            int curCol = curGrid[1];

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) {
                return true;
            }

            for (int[] dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];

                // Check if the current cell has any unvisited neighbors with value larger
                // than or equal to curScore.
                if (
                    0 <= newRow &&
                    newRow < R &&
                    0 <= newCol &&
                    newCol < C &&
                    visited[newRow][newCol] == false &&
                    grid[newRow][newCol] >= curScore
                ) {
                    // If so, we put this neighbor to the deque and mark it as visited.
                    visited[newRow][newCol] = true;
                    deque.offer(new int[] { newRow, newCol });
                }
            }
        }

        // If we empty the deque and still haven't reach the bottom-right cell, return false.
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Check if we can find a path of score equals val.
        def path_exists(cur_score):

            # Maintain the visited status of each cell. Initalize the status of
            # all the cells as false (unvisited).
            visited = [[False] * C for _ in range(R)]
            visited[0][0] = True

            # Put the starting cell grid[0][0] in the deque and mark it as visited.
            dq = collections.deque([(0, 0)])

            # While we still have cells of value larger than or equal to val.
            while dq:
                cur_row, cur_col = dq.popleft()

                # If the current cell is the bottom-right cell, return true.
                if cur_row == R - 1 and cur_col == C - 1:
                    return True
                for d_row, d_col in dirs:
                    new_row = cur_row + d_row
                    new_col = cur_col + d_col

                    # Make sure (new_row, new_col) is on the grid.
                    if not (0 <= new_row < R and 0 <= new_col < C):
                        continue

                    # Check if the current cell has any unvisited neighbors
                    # with value greater than or equal to cur_score.
                    if (
                        grid[new_row][new_col] >= cur_score
                        and not visited[new_row][new_col]
                    ):
                        # If so, we put this neighbor to the deque and mark it as visited
                        visited[new_row][new_col] = True
                        dq.append((new_row, new_col))
            return False

        cur_score = min(grid[0][0], grid[R - 1][C - 1])

        # Start with "cur_score", check if we can find a path of score equals cur_score.
        # If so, return cur_score as the maximum score, otherwise, decrease cur_score
        # by 1 and repeat these steps.
        while cur_score >= 0:
            if path_exists(cur_score):
                return cur_score
            else:
                cur_score -= 1
```

</details>

<br>

## Approach 2: Binary Search + Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int left = 0, right = min(grid[0][0], grid[R - 1][C - 1]);
        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (left + right + 1) / 2;

            // Check if we can find a path of score equals middle, and cut the
            // search space by half.
            if (pathExists(grid, middle)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target
        // value, that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value equals val.
    bool pathExists(vector<vector<int>>& grid, int val) {
        int R = grid.size(), C = grid[0].size();

        // Maintain the visited status of each cell. Initialize the status of
        // all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        visited[0][0] = true;
        deque<pair<int, int>> dq({{0, 0}});

        auto push = [&](int row, int col) {
            if (row == -1 || col == -1 || row == R || col == C ||
                visited[row][col] || grid[row][col] < val)
                return;
            dq.push_back({row, col});
            visited[row][col] = true;
        };

        // While we still have cells of value larger than or equal to val.
        while (!dq.empty()) {
            int curRow = dq.front().first, curCol = dq.front().second;
            dq.pop_front();

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) return true;

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to val. If so, we put this neighbor to the
            // deque and mark it as visited
            push(curRow + 1, curCol);
            push(curRow - 1, curCol);
            push(curRow, curCol + 1);
            push(curRow, curCol - 1);
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

    // 4 directions to a cell's possible neighbors.
    public int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        int left = 0, right = Math.min(grid[0][0], grid[R - 1][C - 1]);

        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (right + left + 1) / 2;

            // Check if we can find a path of value equals middle, and cut
            // the search space by half.
            if (pathExists(grid, middle)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value equals val.
    private boolean pathExists(int[][] grid, int val) {
        int R = grid.length, C = grid[0].length;

        // Maintain the visited status of each cell. Initialize the status of
        // all the cells as false (unvisited).
        boolean[][] visited = new boolean[R][C];

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        Queue<int[]> deque = new LinkedList<>();
        deque.offer(new int[] { 0, 0 });
        visited[0][0] = true;

        // While we still have cells of value larger than or equal to val.
        while (!deque.isEmpty()) {
            int[] curGrid = deque.poll();
            int curRow = curGrid[0];
            int curCol = curGrid[1];

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) {
                return true;
            }
            for (int[] dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];

                // Check if the current cell has any unvisited neighbors with value larger
                // than or equal to val.
                if (
                    0 <= newRow &&
                    newRow < R &&
                    0 <= newCol &&
                    newCol < C &&
                    visited[newRow][newCol] == false &&
                    grid[newRow][newCol] >= val
                ) {
                    // If so, we put this neighbor to the deque and mark it as visited.
                    visited[newRow][newCol] = true;
                    deque.offer(new int[] { newRow, newCol });
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
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])
        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Check if we can find a path of value = cur_score.
        def path_exists(cur_score):
            dq = collections.deque()
            visited = [[False] * C for _ in range(R)]

            # Put the starting cell grid[0][0] in the deque and mark it as visited.
            visited[0][0] = True
            dq.append((0, 0))

            # While we still have cells of value larger than or equal to val.
            while dq:
                cur_row, cur_col = dq.popleft()

                # If the current cell is the bottom-right cell, return true.
                if cur_row == R - 1 and cur_col == C - 1:
                    return True
                for d_row, d_col in dirs:
                    new_row = cur_row + d_row
                    new_col = cur_col + d_col

                    # Make sure (new_row, new_col) is on the grid.
                    if not (0 <= new_row < R and 0 <= new_col < C):
                        continue

                    # Check if the current cell has any unvisited neighbors
                    # with value greater than or equal to cur_score.
                    if (
                        grid[new_row][new_col] >= cur_score
                        and not visited[new_row][new_col]
                    ):
                        # If so, we put this neighbor to the deque and mark it as visited.
                        visited[new_row][new_col] = True
                        dq.append((new_row, new_col))
            return False

        left = 0
        right = min(grid[0][0], grid[-1][-1])

        while left < right:
            # Get the middle value between left and right boundaries.
            middle = (left + right + 1) // 2

            # Check if we can find a path with value = middle, and cut
            # the search space by half.
            if path_exists(middle):
                left = middle
            else:
                right = middle - 1

        # Once the left and right boundaries coincide, we find the target value,
        # that is, the maximum value of a path.
        return left
```

</details>

<br>

## Approach 3: Binary Search + Depth First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int R, C;
    bool visited[101][101];

    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();

        // Initialize the two boundaries of the search space.
        int left = 0, right = min(grid[0][0], grid[R - 1][C - 1]);

        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (left + right + 1) >> 1;
            memset(visited, false, sizeof(visited));

            // Check if we can find a path having value equals middle, and cut
            // the search space by half.
            if (pathExists(grid, middle, 0, 0)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target
        // value, that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value = val.
    int pathExists(vector<vector<int>>& grid, int val, int curRow, int curCol) {
        // If we reach the bottom-right cell, return true.
        if (curRow == R - 1 && curCol == C - 1) return true;

        // Mark the current cell as visited.
        visited[curRow][curCol] = true;
        for (vector<int> dir : dirs) {
            int newRow = curRow + dir[0];
            int newCol = curCol + dir[1];

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to val.
            if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C &&
                !visited[newRow][newCol] && grid[newRow][newCol] >= val) {
                // If so, we continue search on this neighbor.
                if (pathExists(grid, val, newRow, newCol)) return true;
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

    private int R, C;

    // 4 directions to a cell's possible neighbors.
    private int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        R = grid.length;
        C = grid[0].length;
        int left = 0, right = Math.min(grid[0][0], grid[R - 1][C - 1]);
        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (right + left + 1) / 2;
            boolean[][] visited = new boolean[R][C];

            // Check if we can find a path with value = middle, and cut
            // the search space by half.
            if (pathExists(grid, middle, visited, 0, 0)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value = val.
    private boolean pathExists(
        int[][] grid,
        int val,
        boolean[][] visited,
        int curRow,
        int curCol
    ) {
        // If we reach the bottom-right cell, return true.
        if (curRow == R - 1 && curCol == C - 1) return true;

        // Mark the current cell as visited.
        visited[curRow][curCol] = true;
        for (int[] dir : dirs) {
            int newRow = curRow + dir[0];
            int newCol = curCol + dir[1];

            // Check if the current cell has any unvisited neighbors with value larger
            // than or equal to val.
            if (
                newRow >= 0 &&
                newRow < R &&
                newCol >= 0 &&
                newCol < C &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] >= val
            ) {
                // If so, we continue search on this neighbor.
                if (pathExists(grid, val, visited, newRow, newCol)) return true;
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
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Check if we can find a path of value = val.
        def path_exists(val):
            visited = [[False] * C for _ in range(R)]

            def dfs(cur_row, cur_col):
                # If we reach the bottom-right cell, return true.
                if cur_row == R - 1 and cur_col == C - 1:
                    return True

                # Mark the current cell as visited.
                visited[cur_row][cur_col] = True
                for d_row, d_col in dirs:
                    new_row = cur_row + d_row
                    new_col = cur_col + d_col

                    # Make sure (new_row, new_col) is on the grid and has not been visited.
                    if (
                        not (0 <= new_row < R and 0 <= new_col < C)
                        or visited[new_row][new_col]
                    ):
                        continue

                    # Check if the current cell has any unvisited neighbors
                    # with value greater than or equal to val.
                    if grid[new_row][new_col] >= val and dfs(new_row, new_col):
                        # If so, we continue search on this neighbor.
                        return True
                return False

            return dfs(0, 0)

        left = 0
        right = min(grid[0][0], grid[-1][-1])

        while left < right:
            # Get the middle value between left and right boundaries.
            middle = (left + right + 1) // 2

            # Check if we can find a path with value = middle, and cut
            # the search space by half.
            if path_exists(middle):
                left = middle
            else:
                right = middle - 1

        # Once the left and right boundaries coincide, we find the target value,
        # that is, the maximum value of a path.
        return left
```

</details>

<br>

## Approach 4: BFS + PriorityQueue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();

        // 4 directions to a cell's possible neighbors.
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Put the top-left cell to the priority queue and mark it as true
        // (visited).
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Initalize the status of all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C));

        // Mark the top-left cell as visited.
        visited[0][0] = true;
        int ans = grid[0][0];

        // While the priority queue is not empty.
        while (!pq.empty()) {
            // Pop the cell with the largest value.
            int curRow = pq.top().second.first;
            int curCol = pq.top().second.second;
            int curVal = pq.top().first;
            pq.pop();

            // Update the minimum value we have visited so far.
            ans = min(ans, curVal);

            // If we reach the bottom-right cell, stop the iteration.
            if (curRow == R - 1 && curCol == C - 1) {
                break;
            }

            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];

                // Check if the current cell has any unvisited neighbors.
                if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C &&
                    !visited[newRow][newCol]) {
                    // If so, we put this neighbor to the priority queue
                    // and mark it as true (visited).
                    pq.push({grid[newRow][newCol], {newRow, newCol}});
                    visited[newRow][newCol] = true;
                }
            }
        }

        // Return the minimum value we have seen, which is the value of this
        // path.
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int R, C;

    // 4 directions to a cell's possible neighbors.
    private int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        R = grid.length;
        C = grid[0].length;
        Queue<int[]> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(grid[b[0]][b[1]], grid[a[0]][a[1]])
        );

        // Initalize the status of all the cells as false (unvisited).
        boolean[][] visited = new boolean[R][C];

        // Put the top-left cell to the priority queue
        // and mark it as true (visited).
        pq.offer(new int[] { 0, 0 });
        visited[0][0] = true;

        int ans = grid[0][0];

        // While the priority queue is not empty.
        while (!pq.isEmpty()) {
            // Pop the cell with the largest value.
            int[] curGrid = pq.poll();
            int curRow = curGrid[0], curCol = curGrid[1];

            // Update the minimum value we have visited so far.
            ans = Math.min(ans, grid[curRow][curCol]);

            // If we reach the bottom-right cell, stop the iteration.
            if (curRow == R - 1 && curCol == C - 1) {
                break;
            }
            for (int[] dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];

                // Check if the current cell has any unvisited neighbors.
                if (
                    newRow >= 0 &&
                    newRow < R &&
                    newCol >= 0 &&
                    newCol < C &&
                    !visited[newRow][newCol]
                ) {
                    // If so, we put this neighbor to the priority queue
                    // and mark it as true (visited).
                    pq.offer(new int[] { newRow, newCol });
                    visited[newRow][newCol] = true;
                }
            }
        }

        // Return the minimum value we have seen,
        // which is the value of this path.
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        heap = []
        ans = grid[0][0]

        # Initalize the status of all the cells as 0 (unvisited).
        visited = [[False] * C for _ in range(R)]

        # Put the top-left cell to the priority queue and mark it as True (visited).
        # Notice that we save the negative number of cell's value, thus we can always
        # pop out the cell with the maximum value using a min-heap data structure.
        heapq.heappush(heap, (-grid[0][0], 0, 0))
        visited[0][0] = True

        # While the priority queue is not empty.
        while heap:
            # Pop the cell with the largest value.
            cur_val, cur_row, cur_col = heapq.heappop(heap)

            # Update the minimum value we have visited so far.
            ans = min(ans, grid[cur_row][cur_col])

            # If we reach the bottom-right cell, stop the iteration.
            if cur_row == R - 1 and cur_col == C - 1:
                break
            for d_row, d_col in dirs:
                new_row = cur_row + d_row
                new_col = cur_col + d_col

                # Check if the current cell has any unvisited neighbors.
                if (
                    0 <= new_row < R
                    and 0 <= new_col < C
                    and not visited[new_row][new_col]
                ):
                    # If so, we put this neighbor to the priority queue
                    # and mark it as True (visited).
                    heapq.heappush(
                        heap, (-grid[new_row][new_col], new_row, new_col)
                    )
                    visited[new_row][new_col] = True

        # Return the minimum value we have seen, which is the value of this path.
        return ans
```

</details>

<br>

## Approach 5: Union Find

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    // uf for recording all the roots.
    vector<int> uf;
    vector<int> rank;

    // Find the root of x.
    int find(int x) {
        if (x != uf[x]) {
            uf[x] = find(uf[x]);
        }
        return uf[x];
    }

    // union the roots of x and y.
    void uni(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                uf[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                uf[rootX] = rootY;
            } else {
                uf[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();

        // Sort all the cells by their values.
        vector<vector<int>> vals;

        // 4 directions to a cell's possible neighbors.
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Intialize the rank of all the cells.
        rank = vector<int>(R * C, 1);

        // Root of all the R * C cells
        uf = vector<int>(R * C, 0);

        // Initalize the status of all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C));

        // Intialize the root of all the cells.
        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                uf[row * C + col] = row * C + col;
                vals.push_back({grid[row][col], row, col});
            }
        }

        // Sort all the cells by values from the largest to the smallest.
        sort(vals.begin(), vals.end(), greater<vector<int>>());

        // Iteration over the sorted cells.
        for (vector<int>& curGrid : vals) {
            int curRow = curGrid[1], curCol = curGrid[2];
            int curPos = curRow * C + curCol;

            // Mark the current cell as visited.
            visited[curRow][curCol] = true;
            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];
                int newPos = newRow * C + newCol;

                // Check if the current cell has any unvisited neighbors
                // with value larger than or equal to val.
                if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C &&
                    visited[newRow][newCol]) {
                    // If so, we connect the current cell with this neighbor.
                    uni(curPos, newPos);
                }
            }

            // Check if the top-left cell is connected with the bottom-right
            // cell.
            if (find(0) == find(R * C - 1)) {
                // If so, return the value of the current cell.
                return grid[curRow][curCol];
            }
        }
        return 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class UF {

    // root for recording all the roots.
    private int[] root;
    private int[] rank;

    public UF(int R, int C) {
        rank = new int[R * C];
        root = new int[R * C];
        for (int i = 0; i < root.length; ++i) root[i] = i;
    }

    // Find the root of x.
    public int find(int x) {
        if (x != root[x]) root[x] = find(root[x]);
        return root[x];
    }

    // union the roots of x and y.
    public void union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
}

class Solution {

    // 4 directions to a cell's possible neighbors.
    private int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        int R = grid.length, C = grid[0].length;

        // Sort all the cells by their values.
        List<int[]> vals = new ArrayList<>();

        // Intialize the root of all the cells and mark
        // all the cells as false (unvisited).
        boolean[][] visited = new boolean[R][C];

        // Root of all the R * C cells
        UF uf = new UF(R, C);

        // Intialize the root of all the cells.
        for (int row = 0; row < R; ++row) for (
            int col = 0;
            col < C;
            ++col
        ) vals.add(new int[] { row, col });

        // Sort all the cells by values from large to small.
        Collections.sort(vals, (gridA, gridB) -> {
            return grid[gridB[0]][gridB[1]] - grid[gridA[0]][gridA[1]];
        });

        // Iteration over the sorted cells.
        for (int[] curGrid : vals) {
            int curRow = curGrid[0], curCol = curGrid[1];
            int curPos = curRow * C + curCol;

            // Mark the current cell as visited.
            visited[curRow][curCol] = true;
            for (int[] dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];
                int newPos = newRow * C + newCol;

                // Check if the current cell has any unvisited neighbors
                // with value larger than or equal to val.
                if (
                    newRow >= 0 &&
                    newRow < R &&
                    newCol >= 0 &&
                    newCol < C &&
                    visited[newRow][newCol] == true
                ) {
                    // If so, we connect the current cell with this neighbor.
                    uf.union(curPos, newPos);
                }
            }

            // Check if the top-left cell is connected with the bottom-right cell.
            if (uf.find(0) == uf.find(R * C - 1)) {
                // If so, return the value of the current cell.
                return grid[curRow][curCol];
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
class Solution:
    def maximumMinimumPath(self, grid: List[List[int]]) -> int:
        # Find the root of x.
        def find(x):
            if x != root[x]:
                root[x] = find(root[x])
            return root[x]

        # Union the roots of x and y.
        def union(x, y):
            root_x = find(x)
            root_y = find(y)
            if root_x != root_y:
                if rank[root_x] > rank[root_y]:
                    root[root_y] = root_x
                elif rank[root_x] < rank[root_y]:
                    root[root_x] = root_y
                else:
                    root[root_y] = root_x
                    rank[root_x] += 1

        R = len(grid)
        C = len(grid[0])

        # 4 directions to a cell's possible neighbors.
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        # Intialize the rank of all the cells.
        rank = [1] * (R * C)

        # Intialize the root of all the cells.
        root = list(range(R * C))

        # Mark all the cells as false (unvisited).
        visited = [[False] * C for _ in range(R)]

        # Sort all the cells by values from large to small.
        vals = [(row, col) for row in range(R) for col in range(C)]
        vals.sort(key=lambda x: grid[x[0]][x[1]], reverse=True)

        # Iteration over the sorted cells.
        for cur_row, cur_col in vals:
            cur_pos = cur_row * C + cur_col

            # Mark the current cell as true (visited).
            visited[cur_row][cur_col] = True
            for d_row, d_col in dirs:
                new_row = cur_row + d_row
                new_col = cur_col + d_col
                new_pos = new_row * C + new_col

                # Check if the current cell has any unvisited neighbors with value larger
                # than or equal to val.
                if (
                    0 <= new_row < R
                    and 0 <= new_col < C
                    and visited[new_row][new_col]
                ):
                    # If so, we connect the current cell with this neighbor.
                    union(cur_pos, new_pos)

            # Check if the top-left cell is connected with the bottom-right cell.
            if find(0) == find(R * C - 1):
                # If so, return the value of the current cell.
                return grid[cur_row][cur_col]
        return -1
```

</details>
