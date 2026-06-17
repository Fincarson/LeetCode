# 499. The Maze III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/the-maze-iii/)  
`Array` `String` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Matrix` `Shortest Path`

**Problem Link:** [LeetCode 499 - The Maze III](https://leetcode.com/problems/the-maze-iii/)

## Problem

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction (must be different from last chosen direction). There is also a hole in this maze. The ball will drop into the hole if it rolls onto the hole.

Given the m x n maze, the ball's position ball and the hole's position hole, where ball = [ballrow, ballcol] and hole = [holerow, holecol], return a string instructions of all the instructions that the ball should follow to drop in the hole with the shortest distance possible. If there are multiple valid instructions, return the lexicographically minimum one. If the ball can't drop in the hole, return "impossible".

If there is a way for the ball to drop in the hole, the answer instructions should contain the characters 'u' (i.e., up), 'd' (i.e., down), 'l' (i.e., left), and 'r' (i.e., right).

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).

### Example 1

```text
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [0,1]
Output: "lul"
Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
```

### Example 2

```text
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [3,0]
Output: "impossible"
Explanation: The ball cannot reach the hole.
```

### Example 3

```text
Input: maze = [[0,0,0,0,0,0,0],[0,0,1,0,0,1,0],[0,0,0,0,1,0,0],[0,0,0,0,0,0,1]], ball = [0,4], hole = [3,5]
Output: "dldr"
```

## Constraints

- m == maze.length
- n == maze[i].length
- 1 <= m, n <= 100
- maze[i][j] is 0 or 1.
- ball.length == 2
- hole.length == 2
- 0 <= ballrow, holerow <= m
- 0 <= ballcol, holecol <= n
- Both the ball and the hole exist in an empty space, and they will not be in the same position initially.
- The maze contains at least 2 empty spaces.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Maze](https://leetcode.com/problems/the-maze/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [The Maze II](https://leetcode.com/problems/the-maze-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 499. The Maze III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dijkstra's | Java, Python3 |

## Approach: Dijkstra's

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class State {
    int row;
    int col;
    int dist;
    String path;
    
    public State(int row, int col, int dist, String path) {
        this.row = row;
        this.col = col;
        this.dist = dist;
        this.path = path;
    }
}

class Solution {
    int[][] directions = new int[][]{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    String[] textDirections = new String[]{"l", "u", "r", "d"};
    int m;
    int n;
    
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        m = maze.length;
        n = maze[0].length;
        
        PriorityQueue<State> heap = new PriorityQueue<>((a, b) -> {
            int distA = a.dist;
            int distB = b.dist;
            
            if (distA == distB) {
                return a.path.compareTo(b.path);
            }
            
            return distA - distB;
        });
        
        boolean[][] seen = new boolean[m][n];
        heap.add(new State(ball[0], ball[1], 0, ""));
        
        while (!heap.isEmpty()) {
            State curr = heap.remove();
            int row = curr.row;
            int col = curr.col;
            
            if (seen[row][col]) {
                continue;
            }
            
            if (row == hole[0] && col == hole[1]) {
                return curr.path;
            }
            
            seen[row][col] = true;
            
            for (State nextState: getNeighbors(row, col, maze, hole)) {
                int nextRow = nextState.row;
                int nextCol = nextState.col;
                int nextDist = nextState.dist;
                String nextChar = nextState.path;
                heap.add(new State(nextRow, nextCol, curr.dist + nextDist, curr.path + nextChar));
            }
        }
        
        return "impossible";
    }
    
    private boolean valid(int row, int col, int[][] maze) {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return false;
        }

        return maze[row][col] == 0;
    }
    
    private List<State> getNeighbors(int row, int col, int[][] maze, int[] hole) {
        List<State> neighbors = new ArrayList<>();
        
        for (int i = 0; i < 4; i++) {
            int dy = directions[i][0];
            int dx = directions[i][1];
            String direction = textDirections[i];
            
            int currRow = row;
            int currCol = col;
            int dist = 0;
            
            while (valid(currRow + dy, currCol + dx, maze)) {
                currRow += dy;
                currCol += dx;
                dist++;
                if (currRow == hole[0] && currCol == hole[1]) {
                    break;
                }
            }
            
            neighbors.add(new State(currRow, currCol, dist, direction));
        }
        
        return neighbors;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        def valid(row, col):
            return 0 <= row < m and 0 <= col < n and maze[row][col] == 0
        
        def get_neighbors(row, col):
            directions = [(0, -1, 'l'), (-1, 0, 'u'), (0, 1, 'r'), (1, 0, 'd')]
            neighbors = []
            
            for dy, dx, direction in directions:
                curr_row = row
                curr_col = col
                dist = 0
                
                while valid(curr_row + dy, curr_col + dx):
                    curr_row += dy
                    curr_col += dx
                    dist += 1
                    if [curr_row, curr_col] == hole:
                        break
                    
                neighbors.append((curr_row, curr_col, dist, direction))
                
            return neighbors

        m = len(maze)
        n = len(maze[0])
        heap = [(0, "", ball[0], ball[1])]
        seen = set()
        
        while heap:
            curr_dist, path, row, col = heappop(heap)
            
            if (row, col) in seen:
                continue
            
            if [row, col] == hole:
                return path
            
            seen.add((row, col))
            
            for next_row, next_col, dist, direction in get_neighbors(row, col):
                heappush(heap, (curr_dist + dist, path + direction, next_row, next_col))

        return "impossible"
```

</details>
