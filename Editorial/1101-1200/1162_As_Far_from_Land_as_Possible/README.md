# 1162. As Far from Land as Possible

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/as-far-from-land-as-possible/)  
`Array` `Dynamic Programming` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1162 - As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)

## Problem

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

### Example 1

```text
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
```

### Example 2

```text
Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
```

## Constraints

- n == grid.length
- n == grid[i].length
- 1 <= n <= 100
- grid[i][j] is 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [K Highest Ranked Items Within a Price Range](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Manhattan Distance After K Changes](https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1162. As Far from Land as Possible

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java |
| Dynamic-Programming | C++, Java |
| Space-Optimized Dynamic-Programming | C++, Java |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Four directions: Up, Down, Left and Right.
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        // A copy matrix of the grid to mark water cells as land once visited.
        int visited[grid.size()][grid[0].size()];
        
        // Insert all the land cells in the queue.
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Copy grid to the visited matrix.
                visited[i][j] = grid[i][j];
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        int distance = -1;
        while (!q.empty()) {
            int qSize = q.size();
            
            // Iterate over all the current cells in the queue.
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                
                // From the current land cell, traverse to all the four directions
                // and check if it is a water cell. If yes, convert it to land
                // and add it to the queue.
                for (pair<int, int> dir : direction) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {
                        // Marking as 1 to avoid re-iterating it.
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            
            // After each iteration of queue elements, increment distance 
            // as we covered 1 unit distance from all cells in every direction.
            distance++;
        }
        
        // If the distance is 0, there is no water cell.
        return distance == 0 ? -1 : distance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Four directions: Up, Down, Left and Right.
    int[][] direction = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int maxDistance(int[][] grid) {
        // A copy matrix of the grid to mark water cells as land once visited.
        int[][] visited = new int[grid.length][grid[0].length];

        // Insert all the land cells in the queue.
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // Copy grid to the visited matrix.
                visited[i][j] = grid[i][j];
                if (grid[i][j] == 1) {
                    q.offer(new Pair(i, j));
                }
            }
        }

        int distance = -1;
        while (!q.isEmpty()) {
            int qSize = q.size();

            // Iterate over all the current cells in the queue.
            while (qSize-- > 0) {
                Pair<Integer, Integer> landCell = q.poll();

                // From the current land cell, traverse to all the four directions
                // and check if it is a water cell. If yes, convert it to land
                // and add it to the queue.
                for (int[] dir : direction) {
                    int x = landCell.getKey() + dir[0];
                    int y = landCell.getValue() + dir[1];

                    if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && visited[x][y] == 0) {
                        // Marking as 1 to avoid re-iterating it.
                        visited[x][y] = 1;
                        q.offer(new Pair(x, y));
                    }
                }
            }

            // After each iteration of queue elements, increment distance 
            // as we covered 1 unit distance from all cells in every direction.
            distance++;
        }

        // If the distance is 0, there is no water cell.
        return distance == 0 ? -1 : distance;
    }
}
```

</details>

<br>

## Approach 2: Dynamic-Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;
        
        vector<vector<int>> dist(rows, vector<int> (cols, MAX_DISTANCE));
        
        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Distance of land cells will be 0.
                if (grid[i][j]) {
                    dist[i][j] = 0;
                } else {
                    // Check left and top cell distances if they exist and update the current cell distance.
                    dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                
                ans = max(ans, dist[i][j]);
            }
        }
        
        // If ans is 0, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int rows = grid.length;
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].length;
        
        // Maximum manhattan distance possible + 1.
        final int MAX_DISTANCE = rows + cols + 1;

        int[][] dist = new int[rows][cols];
        for (int[] arr : dist)
            Arrays.fill(arr, MAX_DISTANCE);

        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Distance of land cells will be 0.
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                } else {
                    // Check left and top cell distances if they exist and update the current cell distance.
                    dist[i][j] = Math.min(dist[i][j], Math.min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                               j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for the bottom and right neighbours.
        int ans = Integer.MIN_VALUE;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                dist[i][j] = Math.min(dist[i][j], Math.min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                           j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                
                ans = Math.max(ans, dist[i][j]);
            }
        }

        // If ans is 0, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};
```

</details>

<br>

## Approach 3: Space-Optimized Dynamic-Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:    
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].size();

        // Maximum manhattan distance possible + 1.
        const int MAX_DISTANCE = rows + cols + 1;
        
        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    // Distance of land cells will be 0.
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = MAX_DISTANCE;
                    // Check left and top cell distances if they exist and update the current cell distance.
                    grid[i][j] = min(grid[i][j], min(i > 0 ? grid[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? grid[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for right and bottom neighbours.
        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                grid[i][j] = min(grid[i][j], min(i < rows - 1 ? grid[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? grid[i][j + 1] + 1 : MAX_DISTANCE));
                ans = max(ans, grid[i][j]);
            }
        }
        
        // If ans is 1, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int rows = grid.length;
        // Although it's a square matrix, using different variable for readability.
        int cols = grid[0].length;
        
        // Maximum manhattan distance possible + 1.
        final int MAX_DISTANCE = rows + cols + 1;

        // First pass: check for left and top neighbours
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // Distance of land cells will be 0.
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = MAX_DISTANCE;
                    // Check left and top cell distances if they exist and update the current cell distance.
                    grid[i][j] = Math.min(grid[i][j], Math.min(i > 0 ? grid[i - 1][j] + 1 : MAX_DISTANCE,
                                                               j > 0 ? grid[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        // Second pass: check for the bottom and right neighbours.
        int ans = Integer.MIN_VALUE;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                // Check the right and bottom cell distances if they exist and update the current cell distance.
                grid[i][j] = Math.min(grid[i][j], Math.min(i < rows - 1 ? grid[i + 1][j] + 1 : MAX_DISTANCE,
                                                           j < cols - 1 ? grid[i][j + 1] + 1 : MAX_DISTANCE));
                
                ans = Math.max(ans, grid[i][j]);
            }
        }

        // If ans is 1, it means there is no water cell,
        // If ans is MAX_DISTANCE, it implies no land cell.
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};
```

</details>
