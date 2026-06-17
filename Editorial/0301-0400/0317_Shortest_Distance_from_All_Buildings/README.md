# 317. Shortest Distance from All Buildings

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/shortest-distance-from-all-buildings/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 317 - Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/)

## Problem

You are given an m x n grid grid of values 0, 1, or 2, where:

- each 0 marks an empty land that you can pass by freely,
- each 1 marks a building that you cannot pass through, and
- each 2 marks an obstacle that you cannot pass through.

You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

### Example 1

```text
Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.
```

### Example 2

```text
Input: grid = [[1,0]]
Output: 1
```

### Example 3

```text
Input: grid = [[1]]
Output: -1
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- grid[i][j] is either 0, 1, or 2.
- There will be at least one building in the grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Walls and Gates](https://leetcode.com/problems/walls-and-gates/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Best Meeting Point](https://leetcode.com/problems/best-meeting-point/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 317. Shortest Distance from All Buildings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS from Empty Land to All Houses | C++, Java, JavaScript |
| BFS from Houses to Empty Land | C++, Java, JavaScript |
| BFS from Houses to Empty Land (Optimized) | C++, Java, JavaScript |

## Approach 1: BFS from Empty Land to All Houses

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouses) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        int distanceSum = 0;
        int housesReached = 0;

        // Queue to do a bfs, starting from (r,c) cell
        queue<pair<int, int>> q;
        q.push({ row, col });

        // Keep track of visited cells
        vector<vector<bool>> vis(rows, vector<bool> (cols, false));
        vis[row][col] = true;

        int steps = 0;

        while (!q.empty() && housesReached != totalHouses) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();

                row = curr.first;
                col = curr.second;

                // If this cell is a house, then add the distance from the source to this cell
                // and we go past from this cell.
                if (grid[row][col] == 1) {
                    distanceSum += steps;
                    housesReached++;
                    continue;
                }

                // This cell was an empty cell, hence traverse the next cells which is not a blockage.
                for (auto& dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                            vis[nextRow][nextCol] = true;
                            q.push({nextRow, nextCol});
                        }
                    }
                }
            }
            
            // After traversing one level cells, increment the steps by 1 to reach to next level.
            steps++;
        }

        // If we did not reach all houses, then any cell visited also cannot reach all houses.
        // Set all cells visted to 2 so we do not check them again and return INT_MAX.
        if (housesReached != totalHouses) {
            for (row = 0; row < rows; row++) {
                for (col = 0; col < cols; col++) {
                    if (grid[row][col] == 0 && vis[row][col]) {
                        grid[row][col] = 2;
                    }
                }
            }
            return INT_MAX;
        }
        // If we have reached all houses then return the total distance calculated.
        return distanceSum;
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();
        int totalHouses = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) { 
                    totalHouses++;
                }
            }
        }

        // Find the min distance sum for each empty cell.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    minDistance = min(minDistance, bfs(grid, row, col, totalHouses));
                }
            }
        }

        // If it is impossible to reach all houses from any empty cell, then return -1.
        if (minDistance == INT_MAX) {
            return -1;
        }
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int bfs(int[][] grid, int row, int col, int totalHouses) {
        // Next four directions.
        int dirs[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.length;
        int cols = grid[0].length;
        int distanceSum = 0;
        int housesReached = 0;
        
        // Queue to do a bfs, starting from (row, col) cell.
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{ row, col });
        
        // Keep track of visited cells.
        boolean[][] vis = new boolean[rows][cols];
        vis[row][col] = true;

        int steps = 0;
        while (!q.isEmpty() && housesReached != totalHouses) {
            for (int i = q.size(); i > 0; --i) {
                int[] curr = q.poll();
                row = curr[0];
                col = curr[1];
                
                // If this cell is a house, then add the distance from source to this cell
                // and we go past from this cell.
                if (grid[row][col] == 1) {
                    distanceSum += steps;
                    housesReached++;
                    continue;
                }
                
                // This cell was empty cell, hence traverse the next cells which is not a blockage.
                for (int[] dir : dirs) {
                    int nextRow = row + dir[0]; 
                    int nextCol = col + dir[1];
                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                            vis[nextRow][nextCol] = true;
                            q.offer(new int[]{ nextRow, nextCol });
                        }
                    }
                }
            }
            
            // After traversing one level of cells, increment the steps by 1 to reach to next level.
            steps++;
        }

        // If we did not reach all houses, then any cell visited also cannot reach all houses.
        // Set all cells visted to 2 so we do not check them again and return MAX_VALUE.
        if (housesReached != totalHouses) {
            for (row = 0; row < rows; row++) {
                for (col = 0; col < cols; col++) {
                    if (grid[row][col] == 0 && vis[row][col]) {
                        grid[row][col] = 2;
                    }
                }
            }
            return Integer.MAX_VALUE;
        }
        
        // If we have reached all houses then return the total distance calculated.
        return distanceSum;
    }
    
    public int shortestDistance(int[][] grid) {
        int minDistance = Integer.MAX_VALUE;
        int rows = grid.length; 
        int cols = grid[0].length;
        int totalHouses = 0;
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    totalHouses++;
                }
            }
        }
        
        // Find the min distance sum for each empty cell.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    minDistance = Math.min(minDistance, bfs(grid, row, col, totalHouses));
                }
            }
        }
        
        // If it is impossible to reach all houses from any empty cell, then return -1.
        if (minDistance == Integer.MAX_VALUE) {
            return -1;
        }
        
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Next four directions.
let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

// BFS function to do bfs starting from (row, col).
let bfs = (grid, row, col, totalHouses) => {
    let rows = grid.length;
    let cols = grid[0].length;
    let distanceSum = 0;
    let housesReached = 0;
    
    // Use a queue to do a bfs, starting from cell located at (row, col).
    let queue = [[ row, col ]];
    
    // Keep track of visited cells.
    let vis = new Array(rows).fill(false).map(() => new Array(cols).fill(false));
    vis[row][col] = true;
    
    let steps = 0;
    
    while (queue.length && housesReached != totalHouses) {
        // Record the cells that we will explore in the next level
        let next_queue = [];
        for (let i = 0; i < queue.length; i++) {
            let curr = queue[i];
            row = curr[0];
            col = curr[1];
            
            // If this cell is a house, then add the distance from source to this cell
            // and we go past from this cell.
            if (grid[row][col] == 1) {
                distanceSum += steps;
                housesReached++;
                continue;
            }
            
            // This cell was empty cell, hence traverse the next cells which is not a blockage.
            dirs.forEach((dir) => {
                let nextRow = row + dir[0];
                let nextCol = col + dir[1];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                        vis[nextRow][nextCol] = true;
                        next_queue.push([nextRow, nextCol]);
                    }
                }
            });
        }
        
        // Set the queue equal to the next level queue.
        queue = next_queue;
        // After traversing one level cells, increment the steps by 1 to reach to next level.
        steps++;
    }
    
    // If we did not reach all houses, then any cell visited also cannot reach all houses.
    // Set all cells visted to 2 so we do not check them again and return MAX_VALUE.
    if (housesReached != totalHouses) {
        for (let row = 0; row < rows; row++) {
            for (let col = 0; col < cols; col++) {
                if (grid[row][col] == 0 && vis[row][col]) {
                    grid[row][col] = 2;
                }
            }
        }
        return Number.MAX_VALUE;
    }
    
    // If we have reached all houses then return the total distance calculated.
    return distanceSum;
};

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;
    let totalHouses = 0;
    
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 1) {
                totalHouses++;
            }
        }
    }
    
    // Find the min distance sum for each empty cell.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 0) {
                minDistance = Math.min(minDistance, bfs(grid, row, col, totalHouses));
            }
        }
    }
    
    // If it is impossible to reach all houses from any empty cell, then return -1.
    if (minDistance == Number.MAX_VALUE) {
        return -1;
    }
    return minDistance;
};
```

</details>

<br>

## Approach 2: BFS from Houses to Empty Land

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& distances, int row, int col) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size(), cols = grid[0].size();
        
        // Queue to do a bfs, starting from each cell located at (r,c).
        queue<pair<int, int>> q;
        q.push({ row, col });
        
        // Keep track of visited cells.
        vector<vector<bool>> vis (rows, vector<bool>(cols, false));
        vis[row][col] = true;
        
        int steps = 0;
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();
                row = curr.first;
                col = curr.second;
                
                // If we reached an empty cell, then add the distance
                // and increment the count of houses reached at this cell.
                if (grid[row][col] == 0) {
                    distances[row][col][0] += steps;
                    distances[row][col][1] += 1;
                }
                
                // Traverse the next cells which is not a blockage.
                for (auto& dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];
                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] == 0) {
                            vis[nextRow][nextCol] = true;
                            q.push({ nextRow, nextCol });
                        }
                    }
                }
            }
            
            // After traversing one level cells, increment the steps by 1.
            steps++;
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();
        int totalHouses = 0;
        
        // Store { total_dist, houses_count } for each cell.
        vector<vector<vector<int>>> distances (rows, vector<vector<int>> (cols, {0, 0}));
        
        // Count houses and start bfs from each house.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    totalHouses++;
                    bfs(grid, distances, row, col);
                }
            }
        }
        
        // Check all empty lands with houses count equal to total houses and find the min ans.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (distances[row][col][1] == totalHouses) {
                    minDistance = min(minDistance, distances[row][col][0]);
                }
            }
        }
        
        // If we haven't found a valid cell return -1.
        if (minDistance == INT_MAX) {
            return -1;
        }
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void bfs(int[][] grid, int[][][] distances, int row, int col) {
        int dirs[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.length;
        int cols = grid[0].length;

        // Use a queue to do a bfs, starting from each cell located at (row, col).
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{ row, col });

        // Keep track of visited cells.
        boolean[][] vis = new boolean[rows][cols];
        vis[row][col] = true;

        int steps = 0;

        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                int[] curr = q.poll();
                row = curr[0];
                col = curr[1];

                // If we reached an empty cell, then add the distance
                // and increment the count of houses reached at this cell.
                if (grid[row][col] == 0) {
                    distances[row][col][0] += steps;
                    distances[row][col][1] += 1;
                }

                // Traverse the next cells which is not a blockage.
                for (int[] dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] == 0) {
                            vis[nextRow][nextCol] = true;
                            q.offer(new int[]{ nextRow, nextCol });
                        }
                    }
                }
            }

            // After traversing one level cells, increment the steps by 1.
            steps++;
        }
    }

    public int shortestDistance(int[][] grid) {
        int minDistance = Integer.MAX_VALUE;
        int rows = grid.length;
        int cols = grid[0].length;
        int totalHouses = 0;

        // Store { total_dist, houses_count } for each cell.
        int[][][] distances = new int[rows][cols][2];

        // Count houses and start bfs from each house.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    totalHouses++;
                    bfs(grid, distances, row, col);
                }
            }
        }

        // Check all empty lands with houses count equal to total houses and find the min ans.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (distances[row][col][1] == totalHouses) {
                    minDistance = Math.min(minDistance, distances[row][col][0]);
                }
            }
        }

        // If we haven't found a valid cell return -1.
        if (minDistance == Integer.MAX_VALUE) {
            return -1;
        }
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

let bfs = function (grid, distances, row, col) {
    let rows = grid.length;
    let cols = grid[0].length;

    // Use a queue to do a BFS, starting from cell at (row, col).
    let queue = [[ row, col ]];

    // Keep track of visited cells
    let vis = new Array(rows).fill(false).map(() => new Array(cols).fill(false));
    vis[row][col] = true;

    let steps = 0;

    while (queue.length) {
        // Record the cells that we will explore in the next level
        let next_queue = [];

        for (let i = 0; i < queue.length; i++) {
            let curr = queue[i];

            row = curr[0];
            col = curr[1];

            // If we reached an empty cell, then add the distance
            // and increment the count of houses reached at this cell.
            if (grid[row][col] == 0) {
                distances[row][col][0] += steps;
                distances[row][col][1]++;
            }

            // Traverse the next cells which is not a blockage.
            dirs.forEach((dir) => {
                let nextRow = row + dir[0];
                let nextCol = col + dir[1];

                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] == 0) {
                        vis[nextRow][nextCol] = true;
                        next_queue.push([nextRow, nextCol]);
                    }
                }
            });
        }
        
        // Set the queue equal to the next level queue.
        queue = next_queue;
        // After traversing one level cells, increment the steps by 1 to reach to next level.
        steps++;
    }
};

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;
    let totalHouses = 0;

    // Store { total_dist, houses_count } for each cell.
    let distances = new Array(rows).fill(0).map(() => new Array(cols).fill(0).map(() => new Array(2).fill(0)));

    // Count houses and start BFS from each house.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 1) {
                totalHouses++;
                bfs(grid, distances, row, col);
            }
        }
    }

    // Check all empty lands with houses count equal to total houses and find the min ans.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (distances[row][col][1] == totalHouses) {
                minDistance = Math.min(minDistance, distances[row][col][0]);
            }
        }
    }

    // If we haven't found a valid cell return -1.
    if (minDistance == Number.MAX_VALUE) {
        return -1;
    }
    return minDistance;
};
```

</details>

<br>

## Approach 3: BFS from Houses to Empty Land (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Total Mtrix to store total distance sum for each empty cell.
        vector<vector<int>> total(rows, vector<int> (cols, 0));

        int emptyLandValue = 0;
        int minDist = INT_MAX;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // Start a bfs from each house.
                if (grid[row][col] == 1) {
                    minDist = INT_MAX;

                    // Use a queue to perform a BFS, starting from the cell located at (row, col).
                    queue<pair<int, int>> q;
                    q.push({ row, col });
                    
                    int steps = 0;

                    while (!q.empty()) {
                        steps++;

                        for (int level = q.size(); level > 0; --level) {
                            auto curr = q.front();
                            q.pop();

                            for (auto& dir : dirs) {
                                int nextRow = curr.first + dir[0];
                                int nextCol = curr.second + dir[1];

                                // For each cell with the value equal to empty land value
                                // add distance and decrement the cell value by 1.
                                if (nextRow >= 0 && nextRow < rows &&
                                    nextCol >= 0 && nextCol < cols &&
                                    grid[nextRow][nextCol] == emptyLandValue) {
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;

                                    q.push({ nextRow, nextCol });
                                    minDist = min(minDist, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }

                    // Decrement empty land value to be searched in next iteration.
                    emptyLandValue--;
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int shortestDistance(int[][] grid) {
        // Next four directions.
        int dirs[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.length;
        int cols = grid[0].length;
        
        // Total Mtrix to store total distance sum for each empty cell.
        int[][] total = new int[rows][cols];

        int emptyLandValue = 0;
        int minDist = Integer.MAX_VALUE;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // Start a BFS from each house.
                if (grid[row][col] == 1) {
                    minDist = Integer.MAX_VALUE;

                    // Use a queue to perform a BFS, starting from the cell at (r, c).
                    Queue<int[]> q = new LinkedList<>();
                    q.offer(new int[]{ row, col });

                    int steps = 0;

                    while (!q.isEmpty()) {
                        steps++;

                        for (int level = q.size(); level > 0; --level) {
                            int[] curr = q.poll();

                            for (int[] dir : dirs) {
                                int nextRow = curr[0] + dir[0];
                                int nextCol = curr[1] + dir[1];

                                // For each cell with the value equal to empty land value
                                // add distance and decrement the cell value by 1.
                                if (nextRow >= 0 && nextRow < rows &&
                                    nextCol >= 0 && nextCol < cols &&
                                    grid[nextRow][nextCol] == emptyLandValue) {
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;

                                    q.offer(new int[]{ nextRow, nextCol });
                                    minDist = Math.min(minDist, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }

                    // Decrement empty land value to be searched in next iteration.
                    emptyLandValue--;
                }
            }
        }

        return minDist == Integer.MAX_VALUE ? -1 : minDist;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Next four directions.
let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

// Queue Implementation using Linked List.
class Node {
    constructor(row, col) {
        this.row = row;
        this.col = col;
        this.prev = null;
        this.next = null;
    }
}

class QueueClass {
    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    length() {
        return this.length;
    }

    push(row, col) {
        const newNode = new Node(row, col);

        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
        } 
        else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }

        this.length++;
    }

    pop() {
        if (this.head == null) return null;

        // Get the popped node.
        const popped = this.head;

        // Save newHead to a variable (could be null).
        const newHead = this.head.next;

        // If newHead is not null.
        if (newHead) {
            newHead.prev = null;
            this.head.next = null;
        } 
        
        else {
            // Change tail in case newHead is null.
            this.tail = null;
        }

        // Assign new tail (could be null).
        this.head = newHead;

        // Decrement length.
        this.length--;
        return popped;
    }
    
    empty() {
        return this.length == 0;
    }
}

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;

    // Total Mtrix to store total distance sum for each empty cell.
    let total = new Array(rows).fill(0).map(() => new Array(cols).fill(0));

    let emptyLandValue = 0;
    let minDist = Number.MAX_VALUE;

    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            
            // Start a BFS from each house.
            if (grid[row][col] == 1) {
                minDist = Number.MAX_VALUE;

                // Use a queue to perform a BFS, starting from the cell located at (row, col).
                let q = new QueueClass();
                q.push(row, col);

                let steps = 0;

                while (!q.empty()) {
                    steps++;

                    for (let level = q.length; level > 0; --level) {
                        let curr = q.pop();

                        dirs.forEach((dir) => {
                            let nextRow = curr.row + dir[0];
                            let nextCol = curr.col + dir[1];

                            // For each cell with the value equal to empty land value
                            // add distance and decrement the cell value by 1.
                            if (nextRow >= 0 && nextRow < rows &&
                                nextCol >= 0 && nextCol < cols &&
                                grid[nextRow][nextCol] == emptyLandValue) {
                                grid[nextRow][nextCol]--;
                                total[nextRow][nextCol] += steps;

                                q.push(nextRow, nextCol);
                                minDist = Math.min(minDist, total[nextRow][nextCol]);
                            }
                        });
                    }
                }

                // Decrement empty land value to be searched in next iteration.
                emptyLandValue--;
            }
        }
    }

    return minDist == Number.MAX_VALUE ? -1 : minDist;
};
```

</details>
