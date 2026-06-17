# 1091. Shortest Path in Binary Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/shortest-path-in-binary-matrix/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1091 - Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

## Problem

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

- All the visited cells of the path are 0.
- All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

### Example 1

```text
Input: grid = [[0,1],[1,0]]
Output: 2
```

### Example 2

```text
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
```

### Example 3

```text
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
```

## Constraints

- n == grid.length
- n == grid[i].length
- 1 <= n <= 100
- grid[i][j] is 0 or 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1091. Shortest Path in Binary Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-first Search (BFS), Overwriting Input | Java, Python3 |
| Breadth-first Search (Without Overwriting the Input) | Java, Python3 |
| A* (Advanced) | Java, Python3 |

## Approach 1: Breadth-first Search (BFS), Overwriting Input

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    private static final int[][] directions = 
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }
        
        // Set up the BFS.
        Queue<int[]> queue = new ArrayDeque<>();
        grid[0][0] = 1;
        queue.add(new int[]{0, 0});
        
        // Carry out the BFS
        while (!queue.isEmpty()) {
            int[] cell = queue.remove();
            int row = cell[0];
            int col = cell[1];
            int distance = grid[row][col];
            if (row == grid.length - 1 && col == grid[0].length - 1) {
                return distance;
            }
            for (int[] neighbour : getNeighbours(row, col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];
                queue.add(new int[]{neighbourRow, neighbourCol});
                grid[neighbourRow][neighbourCol] = distance + 1;
            }
        }
        
        // The target was unreachable.
        return -1;
    }
    
    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length 
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;    
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours; 
    }
    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        # Helper function to find the neighbors of a given cell.
        def get_neighbours(row, col):
            for row_difference, col_difference in directions:
                new_row = row + row_difference
                new_col = col + col_difference
                if not(0 <= new_row <= max_row and 0 <= new_col <= max_col):
                    continue
                if grid[new_row][new_col] != 0:
                    continue
                yield (new_row, new_col)
        
        # Check that the first and last cells are open. 
        if grid[0][0] != 0 or grid[max_row][max_col] != 0:
            return -1
        
        # Set up the BFS.
        queue = deque()
        queue.append((0, 0))
        grid[0][0] = 1 
        
        # Carry out the BFS.
        while queue:
            row, col = queue.popleft()
            distance = grid[row][col]
            if (row, col) == (max_row, max_col):
                return distance
            for neighbour_row, neighbour_col in get_neighbours(row, col):
                grid[neighbour_row][neighbour_col] = distance + 1
                queue.append((neighbour_row, neighbour_col))
        
        # There was no path.
        return -1
```

</details>

<br>

## Approach 2: Breadth-first Search (Without Overwriting the Input)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    private static final int[][] directions = 
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }
        
        // Set up the BFS.
        Queue<int[]> queue = new ArrayDeque<>();
        queue.add(new int[]{0, 0, 1}); // Put distance on the queue
        boolean[][] visited = new boolean[grid.length][grid[0].length]; // Used as visited set.
        visited[0][0] = true;
        
        // Carry out the BFS
        while (!queue.isEmpty()) {
            int[] cell = queue.remove();
            int row = cell[0];
            int col = cell[1];
            int distance = cell[2];
            // Check if this is the target cell.
            if (row == grid.length - 1 && col == grid[0].length - 1) {
                return distance;
            }
            for (int[] neighbour : getNeighbours(row, col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];
                if (visited[neighbourRow][neighbourCol]) {
                    continue;
                }
                visited[neighbourRow][neighbourCol] = true;
                queue.add(new int[]{neighbourRow, neighbourCol, distance + 1});
            }
        }
        
        // The target was unreachable.
        return -1;  
    }
    
    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length 
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;    
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours; 
    }
    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        # Helper function to find the neighbors of a given cell.
        def get_neighbours(row, col):
            for row_difference, col_difference in directions:
                new_row = row + row_difference
                new_col = col + col_difference
                if not(0 <= new_row <= max_row and 0 <= new_col <= max_col):
                    continue
                if grid[new_row][new_col] != 0:
                    continue
                yield (new_row, new_col)
        
        # Check that the first and last cells are open. 
        if grid[0][0] != 0 or grid[max_row][max_col] != 0:
            return -1
        
        # Set up the BFS.
        queue = deque([(0, 0, 1)])
        visited = {(0, 0)}
        
        # Do the BFS.
        while queue:
            row, col, distance = queue.popleft()
            if (row, col) == (max_row, max_col):
                return distance
            for neighbour in get_neighbours(row, col):
                if neighbour in visited:
                    continue
                visited.add(neighbour)
                # Note that the * splits neighbour into its values.
                queue.append((*neighbour, distance + 1))
                
        # There was no path.
        return -1
```

</details>

<br>

## Approach 3: A* (Advanced)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    // Candidate represents a possible option for travelling to the cell
    // at (row, col).
    class Candidate {
        
        public int row;
        public int col;
        public int distanceSoFar;
        public int totalEstimate;
        
        public Candidate(int row, int col, int distanceSoFar, int totalEstimate) {
            this.row = row;
            this.col = col;
            this.distanceSoFar = distanceSoFar;
            this.totalEstimate = totalEstimate;
        }
    }
    
    
    private static final int[][] directions = 
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }
        
        // Set up the A* search.
        Queue<Candidate> pq = new PriorityQueue<>((a,b) -> a.totalEstimate - b.totalEstimate);
        pq.add(new Candidate(0, 0, 1, estimate(0, 0, grid)));
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        
        // Carry out the A* search.
        while (!pq.isEmpty()) {
            
            Candidate best = pq.remove();
            
            // Is this for the target cell?
            if (best.row == grid.length - 1 && best.col == grid[0].length - 1) {
                return best.distanceSoFar;
            }
            
            // Have we already found the best path to this cell?
            if (visited[best.row][best.col]) {
                continue;
            }
            
            visited[best.row][best.col] = true;
            
            for (int[] neighbour : getNeighbours(best.row, best.col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];
                
                // This check isn't necessary for correctness, but it greatly
                // improves performance.
                if (visited[neighbourRow][neighbourCol]) {
                    continue;
                }
                
                // Otherwise, we need to create a Candidate object for the option
                // of going to neighbor through the current cell.
                int newDistance = best.distanceSoFar + 1;
                int totalEstimate = newDistance + estimate(neighbourRow, neighbourCol, grid);
                Candidate candidate = 
                    new Candidate(neighbourRow, neighbourCol, newDistance, totalEstimate);
                pq.add(candidate);
            }   
        }
        // The target was unreachable.
        return -1;  
    }
    
    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length 
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;    
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours; 
    }
    
    // Get the best case estimate of how much further it is to the bottom-right cell.
    private int estimate(int row, int col, int[][] grid) {
        int remainingRows = grid.length - row - 1;
        int remainingCols = grid[0].length - col - 1;
        return Math.max(remainingRows, remainingCols);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        directions = [
            (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        # Helper function to find the neighbors of a given cell.
        def get_neighbours(row, col):
            for row_difference, col_difference in directions:
                new_row = row + row_difference
                new_col = col + col_difference
                if not(0 <= new_row <= max_row and 0 <= new_col <= max_col):
                    continue
                if grid[new_row][new_col] != 0:
                    continue
                yield (new_row, new_col)
        
        # Helper function for the A* heuristic.
        def best_case_estimate(row, col):
            return max(max_row - row, max_col - col)
            
        # Check that the first and last cells are open. 
        if grid[0][0] or grid[max_row][max_col]:
            return -1
        
        # Set up the A* search.
        visited = set()
        # Entries on the priority queue are of the form
        # (total distance estimate, distance so far, (cell row, cell col))
        priority_queue = [(1 + best_case_estimate(0, 0), 1, (0, 0))]
        while priority_queue:
            estimate, distance, cell = heapq.heappop(priority_queue)
            if cell in visited:
                continue
            if cell == (max_row, max_col):
                return distance
            visited.add(cell)
            for neighbour in get_neighbours(*cell):
                # The check here isn't necessary for correctness, but it
                # leads to a substantial performance gain.
                if neighbour in visited:
                    continue
                estimate = best_case_estimate(*neighbour) + distance + 1
                entry = (estimate, distance + 1, neighbour)
                heapq.heappush(priority_queue, entry)
        
        # There was no path.
        return -1
```

</details>
