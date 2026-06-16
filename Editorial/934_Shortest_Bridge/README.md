# 934. Shortest Bridge

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shortest-bridge/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 934 - Shortest Bridge](https://leetcode.com/problems/shortest-bridge/)

## Problem

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

### Example 1

```text
Input: grid = [[0,1],[1,0]]
Output: 1
```

### Example 2

```text
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
```

### Example 3

```text
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
```

## Constraints

- n == grid.length == grid[i].length
- 2 <= n <= 100
- grid[i][j] is either 0 or 1.
- There are exactly two islands in grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Operations to Make X and Y Equal](https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 934. Shortest Bridge

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First-Search + Breadth-First-Search | C++, Java, Python3 |
| Breadth-First-Search | C++, Java, Python3 |

## Approach 1: Depth-First-Search + Breadth-First-Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    std::vector<std::pair<int, int>> bfsQueue;

    void dfs(std::vector<std::vector<int>>& grid, int x, int y, int n) {
        grid[x][y] = 2;
        bfsQueue.push_back(std::make_pair(x, y));
        for (auto& pair : std::vector<std::pair<int, int>>{
                 {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
            int curX = pair.first, curY = pair.second;
            if (0 <= curX && curX < n && 0 <= curY && curY < n &&
                grid[curX][curY] == 1) {
                dfs(grid, curX, curY, n);
            }
        }
    }

public:
    int shortestBridge(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
            if (firstX != -1) {
                break;
            }
        }

        dfs(grid, firstX, firstY, n);

        int distance = 0;
        while (!bfsQueue.empty()) {
            std::vector<std::pair<int, int>> newBfs;
            for (auto& pair : bfsQueue) {
                int x = pair.first, y = pair.second;
                for (auto& nextPair : std::vector<std::pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = nextPair.first, curY = nextPair.second;
                    if (0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back(std::make_pair(curX, curY));
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            bfsQueue.swap(newBfs);
            distance++;
        }

        return distance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<int[]> bfsQueue;

    // Recursively check the neighboring land cell of current cell grid[x][y] and add all
    // land cells of island A to bfsQueue.
    private void dfs(int[][] grid, int x, int y, int n) {
        grid[x][y] = 2;
        bfsQueue.add(new int[] { x, y });
        for (int[] pair : new int[][] {
            { x + 1, y },
            { x - 1, y },
            { x, y + 1 },
            { x, y - 1 },
        }) {
            int curX = pair[0], curY = pair[1];
            if (
                0 <= curX &&
                curX < n &&
                0 <= curY &&
                curY < n &&
                grid[curX][curY] == 1
            ) {
                dfs(grid, curX, curY, n);
            }
        }
    }

    // Find any land cell, and we treat it as a cell of island A.
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int firstX = -1, firstY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }

        // Add all land cells of island A to bfsQueue.
        bfsQueue = new ArrayList<>();
        dfs(grid, firstX, firstY, n);

        int distance = 0;
        while (!bfsQueue.isEmpty()) {
            List<int[]> newBfs = new ArrayList<>();
            for (int[] pair : bfsQueue) {
                int x = pair[0], y = pair[1];
                for (int[] nextPair : new int[][] {
                    { x + 1, y },
                    { x - 1, y },
                    { x, y + 1 },
                    { x, y - 1 },
                }) {
                    int curX = nextPair[0], curY = nextPair[1];
                    if (0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.add(nextPair);
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B, we will
            // start the next round on all water cells that are 1 cell further away from
            // island A and increment the distance by 1.
            bfsQueue = newBfs;
            distance++;
        }

        return distance;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        first_x, first_y = -1, -1
        # Find any land cell, and we treat it as a cell of island A.
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    first_x, first_y = i, j
                    break

        # Recursively check the neighboring land cell of current cell grid[x][y] and add all
        # land cells of island A to bfs_queue.
        def dfs(x, y):
            grid[x][y] = 2
            bfs_queue.append((x, y))
            for cur_x, cur_y in [
                (x + 1, y),
                (x - 1, y),
                (x, y + 1),
                (x, y - 1),
            ]:
                if (
                    0 <= cur_x < n
                    and 0 <= cur_y < n
                    and grid[cur_x][cur_y] == 1
                ):
                    dfs(cur_x, cur_y)

        # Add all land cells of island A to bfs_queue.
        bfs_queue = []
        dfs(first_x, first_y)

        distance = 0
        while bfs_queue:
            new_bfs = []
            for x, y in bfs_queue:
                for cur_x, cur_y in [
                    (x + 1, y),
                    (x - 1, y),
                    (x, y + 1),
                    (x, y - 1),
                ]:
                    if 0 <= cur_x < n and 0 <= cur_y < n:
                        if grid[cur_x][cur_y] == 1:
                            return distance
                        elif grid[cur_x][cur_y] == 0:
                            new_bfs.append((cur_x, cur_y))
                            grid[cur_x][cur_y] = -1

            # Once we finish one round without finding land cells of island B, we will
            # start the next round on all water cells that are 1 cell further away from
            # island A and increment the distance by 1.
            bfs_queue = new_bfs
            distance += 1

        return distance
```

</details>

<br>

## Approach 2: Breadth-First-Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;

        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }

        // bfsQue for BFS on land cells of island A; secondBfsQue for BFS on
        // water cells.
        vector<pair<int, int>> bfsQue, secondBfsQue;
        bfsQue.push_back(make_pair(firstX, firstY));
        secondBfsQue.push_back(make_pair(firstX, firstY));
        grid[firstX][firstY] = 2;

        // BFS for all land cells of island A and add them to secondBfsQue.
        while (!bfsQue.empty()) {
            vector<pair<int, int>> newBfs;
            for (pair<int, int> cell : bfsQue) {
                int x = cell.first;
                int y = cell.second;
                for (auto next : vector<pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = next.first;
                    int curY = next.second;
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n &&
                        grid[curX][curY] == 1) {
                        newBfs.push_back(make_pair(curX, curY));
                        secondBfsQue.push_back(make_pair(curX, curY));
                        grid[curX][curY] = 2;
                    }
                }
            }
            bfsQue = newBfs;
        }

        int distance = 0;
        while (!secondBfsQue.empty()) {
            vector<pair<int, int>> newBfs;
            for (pair<int, int> cell : secondBfsQue) {
                int x = cell.first;
                int y = cell.second;
                for (auto next : vector<pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = next.first;
                    int curY = next.second;
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.push_back(make_pair(curX, curY));
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B,
            // we will start the next round on all water cells that are 1 cell
            // further away from island A and increment the distance by 1.
            secondBfsQue = newBfs;
            distance++;
        }
        return distance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int firstX = -1, firstY = -1;

        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }

        // bfsQueue for BFS on land cells of island A; secondBfsQueue for BFS on water cells.
        List<int[]> bfsQueue = new ArrayList<>();
        List<int[]> secondBfsQueue = new ArrayList<>();
        bfsQueue.add(new int[] { firstX, firstY });
        secondBfsQueue.add(new int[] { firstX, firstY });
        grid[firstX][firstY] = 2;

        // BFS for all land cells of island A and add them to secondBfsQueue.
        while (!bfsQueue.isEmpty()) {
            List<int[]> newBfs = new ArrayList<>();
            for (int[] cell : bfsQueue) {
                int x = cell[0];
                int y = cell[1];
                for (int[] next : new int[][] {
                    { x + 1, y },
                    { x - 1, y },
                    { x, y + 1 },
                    { x, y - 1 },
                }) {
                    int curX = next[0];
                    int curY = next[1];
                    if (
                        curX >= 0 &&
                        curX < n &&
                        curY >= 0 &&
                        curY < n &&
                        grid[curX][curY] == 1
                    ) {
                        newBfs.add(new int[] { curX, curY });
                        secondBfsQueue.add(new int[] { curX, curY });
                        grid[curX][curY] = 2;
                    }
                }
            }
            bfsQueue = newBfs;
        }

        int distance = 0;
        while (!secondBfsQueue.isEmpty()) {
            List<int[]> newBfs = new ArrayList<>();
            for (int[] cell : secondBfsQueue) {
                int x = cell[0];
                int y = cell[1];
                for (int[] next : new int[][] {
                    { x + 1, y },
                    { x - 1, y },
                    { x, y + 1 },
                    { x, y - 1 },
                }) {
                    int curX = next[0];
                    int curY = next[1];
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            newBfs.add(new int[] { curX, curY });
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B, we will
            // start the next round on all water cells that are 1 cell further away from
            // island A and increment the distance by 1.
            secondBfsQueue = newBfs;
            distance++;
        }
        return distance;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        first_x, first_y = -1, -1
        
        # Find any land cell, and we treat it as a cell of island A.
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    first_x, first_y = i, j
                    break
        
        # bfsQueue for BFS on land cells of island A; secondBfsQueue for BFS on water cells.
        bfs_queue = [(first_x, first_y)]
        second_bfs_queue = [(first_x, first_y)]
        grid[first_x][first_y] = 2
        
        # BFS for all land cells of island A and add them to second_bfs_queue.
        while bfs_queue:
            new_bfs = []
            for x, y in bfs_queue:
                for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                    if 0 <= cur_x < n and 0 <= cur_y < n and grid[cur_x][cur_y] == 1:
                        new_bfs.append((cur_x, cur_y))
                        second_bfs_queue.append((cur_x, cur_y))
                        grid[cur_x][cur_y] = 2
            bfs_queue = new_bfs

        distance = 0
        while second_bfs_queue:
            new_bfs = []
            for x, y in second_bfs_queue:
                for cur_x, cur_y in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                    if 0 <= cur_x < n and 0 <= cur_y < n:
                        if grid[cur_x][cur_y] == 1:
                            return distance
                        elif grid[cur_x][cur_y] == 0:
                            new_bfs.append((cur_x, cur_y))
                            grid[cur_x][cur_y] = -1

            # Once we finish one round without finding land cells of island B, we will
            # start the next round on all water cells that are 1 cell further away from
            # island A and increment the distance by 1.
            second_bfs_queue = new_bfs
            distance += 1

        return distance
```

</details>
