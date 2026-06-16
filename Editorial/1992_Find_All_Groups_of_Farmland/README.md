# 1992. Find All Groups of Farmland

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-all-groups-of-farmland/)  
`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1992 - Find All Groups of Farmland](https://leetcode.com/problems/find-all-groups-of-farmland/)

## Problem

You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

### Example 1

```text
Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
```

### Example 2

```text
Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
```

### Example 3

```text
Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.
```

## Constraints

- m == land.length
- n == land[i].length
- 1 <= m, n <= 300
- land consists of only 0's and 1's.
- Groups of farmland are rectangular in shape.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Sub Islands](https://leetcode.com/problems/count-sub-islands/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1992. Find All Groups of Farmland

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Breadth-First Search | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        for (int row1 = 0; row1 < land.size(); row1++) {
            for (int col1 = 0; col1 < land[0].size(); col1++) {
                if (land[row1][col1] && !visited[row1][col1]) {
                    int row2 = 0, col2 = 0;
                    DFS(land, visited, row1, col1, row2, col2);
                    ans.push_back({row1, col1, row2, col2});
                }
            }
        }
        
        return ans;
    }

private:
    // The four directions in which traversal will be done.
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // Returns true if the coordinate is within the boundary of the matrix.
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    void DFS(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, int& row2,
        int& col2) {
        visited[x][y] = true;
        // Maximum x and y for the bottom right cell.
        row2 = max(row2, x); col2 = max(col2, y);
        
        for (auto dir : dirs) {
            // Neighbor cell coordinates.
            int newX = x + dir[0], newY = y + dir[1];
            // If the neighbor is within the matrix and is a farmland cell and is not visited yet.
            if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                    && land[newX][newY]) {
                DFS(land, visited, newX, newY, row2, col2);
            }
        }
    }    
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // The four directions in which traversal will be done.
    int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    // Global variables with 0 value initially.
    int row2, col2;
    
    // Returns true if the coordinate is within the boundary of the matrix.
    private boolean isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    private void DFS(int[][] land, boolean[][] visited, int x, int y) {
        visited[x][y] = true;
        // Maximum x and y for the bottom right cell.
        row2 = Math.max(row2, x); col2 = Math.max(col2, y);
        
        for (int[] dir : dirs) {
            // Neighbor cell coordinates.
            int newX = x + dir[0], newY = y + dir[1];

            // If the neighbor is within the matrix and is a farmland cell and is not visited yet.
            if (isWithinFarm(newX, newY, land.length, land[0].length) && !visited[newX][newY]
                    && land[newX][newY] == 1) {
                DFS(land, visited, newX, newY);
            }
        }
    }
    
    public int[][] findFarmland(int[][] land) {
        boolean[][] visited = new boolean[land.length][land[0].length];
        List<int[]> ans = new ArrayList<>();

        for (int row1 = 0; row1 < land.length; row1++) {
            for (int col1 = 0; col1 < land[0].length; col1++) {
                if (land[row1][col1] == 1 && !visited[row1][col1]) {
                     row2 = 0; col2 = 0;

                    DFS(land, visited, row1, col1);
                    
                    int[] arr = new int[] {row1, col1, row2, col2};
                    ans.add(arr);
                }
            }
        }
        
        return ans.stream().toArray(int[][] :: new);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # The four directions in which traversal will be done.
        self.dirs = [(-1, 0), (0, -1), (0, 1), (1, 0)]
        # Global variables with 0 value initially.
        self.row2, self.col2 = 0, 0

    # Returns true if the coordinate is within the boundary of the matrix.
    def is_within_farm(self, x: int, y: int, n: int, m: int) -> bool:
        return 0 <= x < n and 0 <= y < m

    def dfs(self, land: List[List[int]], visited: List[List[bool]], x: int, y: int):
        visited[x][y] = True
        # Maximum x and y for the bottom-right cell.
        self.row2 = max(self.row2, x)
        self.col2 = max(self.col2, y)

        for dir in self.dirs:
            # Neighbor cell coordinates.
            new_x, new_y = x + dir[0], y + dir[1]

            # If the neighbor is within the matrix and is a farmland cell and is not visited yet.
            if (
                self.is_within_farm(new_x, new_y, len(land), len(land[0]))
                and not visited[new_x][new_y]
                and land[new_x][new_y] == 1
            ):
                self.dfs(land, visited, new_x, new_y)

    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        visited = [[False] * len(land[0]) for _ in range(len(land))]
        ans = []

        for row1 in range(len(land)):
            for col1 in range(len(land[0])):
                if land[row1][col1] == 1 and not visited[row1][col1]:
                    self.row2, self.col2 = 0, 0

                    self.dfs(land, visited, row1, col1)

                    ans.append([row1, col1, self.row2, self.col2])

        return ans
```

</details>

<br>

## Approach 2: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        
        for (int row1 = 0; row1 < land.size(); row1++) {
            for (int col1 = 0; col1 < land[0].size(); col1++) {
                if (land[row1][col1] && !visited[row1][col1]) {
                    queue<pair<int, int>> q;
                    q.push({row1, col1});
                    visited[row1][col1] = true;
                    
                    pair<int, int> last = BFS(q, land, visited, row1, col1);
                    ans.push_back({row1, col1, last.first, last.second});
                }
            }
        }
        
        return ans;
    }
private:    
    // The four directions in which traversal will be done.
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // Returns true if the coordinate is within the boundary of the matrix.
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    pair<int, int> BFS(queue<pair<int, int>> q, vector<vector<int>>& land,
        vector<vector<bool>>& visited, int x, int y) {
        pair<int, int> curr;
        
        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            
            for (auto dir : dirs) {
                // Neighbor cell coordinates.
                int newX = x + dir[0], newY = y + dir[1];

                // If the neighbor is within the matrix and is a farmland cell and not visited yet.
                if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                        && land[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        
        return curr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // The four directions in which traversal will be done.
    int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // Returns true if the coordinate is within the boundary of the matrix.
    private boolean isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    private Pair<Integer, Integer> BFS(Queue<Pair<Integer, Integer>> q, int[][] land,
        boolean[][] visited) {
        Pair<Integer, Integer> curr = new Pair<Integer, Integer>(0, 0);

        while (!q.isEmpty()) {
            curr = q.remove();

            int x = curr.getKey();
            int y = curr.getValue();

            for (int[] dir : dirs) {
                // Neighbor cell coordinates.
                int newX = x + dir[0], newY = y + dir[1];

                // If the neighbor is within the matrix and is a farmland cell and not visited yet.
                if (isWithinFarm(newX, newY, land.length, land[0].length) && !visited[newX][newY]
                        && land[newX][newY] == 1) {
                    visited[newX][newY] = true;
                    q.add(new Pair(newX, newY));
                }
            }
        }

        return curr;
    }

    public int[][] findFarmland(int[][] land) {
        boolean[][] visited = new boolean[land.length][land[0].length];
        List<int[]> ans = new ArrayList<>();


        for (int row1 = 0; row1 < land.length; row1++) {
            for (int col1 = 0; col1 < land[0].length; col1++) {
                if (land[row1][col1] == 1 && !visited[row1][col1]) {
                    Queue<Pair<Integer, Integer>> q = new LinkedList<>();

                    q.add(new Pair(row1, col1));
                    visited[row1][col1] = true;

                    Pair<Integer, Integer> last = BFS(q, land, visited);

                    int[] arr = new int[] {row1, col1, last.getKey(), last.getValue()};
                    ans.add(arr);
                }
            }
        }

        return ans.stream().toArray(int[][] :: new);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # The four directions in which traversal will be done.
    dirs = [(-1, 0), (0, -1), (0, 1), (1, 0)]

    # Returns true if the coordinate is within the boundary of the matrix.
    def is_within_farm(self, x: int, y: int, n: int, m: int) -> bool:
        return 0 <= x < n and 0 <= y < m

    def bfs(self, q: deque, land: List[List[int]], visited: List[List[bool]]) -> tuple:
        curr = (0, 0)

        while q:
            curr = q.popleft()
            x, y = curr

            for dir in self.dirs:
                # Neighbor cell coordinates.
                new_x, new_y = x + dir[0], y + dir[1]

                # If the neighbor is within the matrix, is a farmland cell, and is not visited yet.
                if self.is_within_farm(new_x, new_y, len(land), len(land[0])) and not visited[new_x][new_y] and land[new_x][new_y] == 1:
                    visited[new_x][new_y] = True
                    q.append((new_x, new_y))

        return curr

    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        visited = [[False] * len(land[0]) for _ in range(len(land))]
        ans = []

        for row1 in range(len(land)):
            for col1 in range(len(land[0])):
                if land[row1][col1] == 1 and not visited[row1][col1]:
                    q = deque([(row1, col1)])
                    visited[row1][col1] = True

                    last = self.bfs(q, land, visited)

                    ans.append([row1, col1, last[0], last[1]])

        return ans
```

</details>

<br>

## Approach 3: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int M = land.size(), N = land[0].size();
        vector<vector<int>> res;
        
        for (int row1 = 0; row1 < M; row1++) {
            for (int col1 = 0; col1 < N; col1++) {
                if (land[row1][col1]) {
                    int x = row1, y = col1;
                    
                    for (x = row1; x < M && land[x][col1]; x++) {
                        for (y = col1; y < N && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }

                    res.push_back({row1, col1, x - 1, y - 1});
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[][] findFarmland(int[][] land) {
        int N = land.length, M = land[0].length;
        List<int[]> ans = new ArrayList<>();

        for (int row1 = 0; row1 < N; row1++) {
            for (int col1 = 0; col1 < M; col1++) {
                if (land[row1][col1] == 1) {
                    int x = row1, y = col1;

                    for (x = row1; x < N && land[x][col1] == 1; x++) {
                        for (y = col1; y < M && land[x][y] == 1; y++) {
                            land[x][y] = 0;
                        }
                    }

                    int[] arr = new int[] {row1, col1, x - 1, y - 1};
                    ans.add(arr);
                }
            }
        }
        return ans.stream().toArray(int[][] :: new);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        res = []
        
        for row1 in range(m):
            for col1 in range(n):
                if land[row1][col1]:
                    x, y = row1, col1
                    
                    while x < m and land[x][col1]:
                        y = col1
                        while y < n and land[x][y]:
                            land[x][y] = 0
                            y += 1
                        x += 1
                    
                    res.append([row1, col1, x - 1, y - 1])
        
        return res
```

</details>
