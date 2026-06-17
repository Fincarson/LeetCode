# 286. Walls and Gates

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/walls-and-gates/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 286 - Walls and Gates](https://leetcode.com/problems/walls-and-gates/)

## Problem

You are given an m x n grid rooms initialized with these three possible values.

- -1 A wall or an obstacle.
- 0 A gate.
- INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

### Example 1

```text
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
```

### Example 2

```text
Input: rooms = [[-1]]
Output: [[-1]]
```

## Constraints

- m == rooms.length
- n == rooms[i].length
- 1 <= m, n <= 250
- rooms[i][j] is -1, 0, or 231 - 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Surrounded Regions](https://leetcode.com/problems/surrounded-regions/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Islands](https://leetcode.com/problems/number-of-islands/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Houses at a Certain Distance I](https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Houses at a Certain Distance II](https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 286. Walls and Gates

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Brute Force) [Time Limit Exceeded] | Java |
| Approach #2 (Breadth-first Search) [Accepted] | Java |

## Approach #1 (Brute Force) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private static final int EMPTY = Integer.MAX_VALUE;
private static final int GATE = 0;
private static final int WALL = -1;
private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
);

public void wallsAndGates(int[][] rooms) {
    if (rooms.length == 0) return;
    for (int row = 0; row < rooms.length; row++) {
        for (int col = 0; col < rooms[0].length; col++) {
            if (rooms[row][col] == EMPTY) {
                rooms[row][col] = distanceToNearestGate(rooms, row, col);
            }
        }
    }
}

private int distanceToNearestGate(int[][] rooms, int startRow, int startCol) {
    int m = rooms.length;
    int n = rooms[0].length;
    int[][] distance = new int[m][n];
    Queue<int[]> q = new LinkedList<>();
    q.add(new int[] { startRow, startCol });
    while (!q.isEmpty()) {
        int[] point = q.poll();
        int row = point[0];
        int col = point[1];
        for (int[] direction : DIRECTIONS) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] == WALL
                    || distance[r][c] != 0) {
                continue;
            }
            distance[r][c] = distance[row][col] + 1;
            if (rooms[r][c] == GATE) {
                return distance[r][c];
            }
            q.add(new int[] { r, c });
        }
    }
    return Integer.MAX_VALUE;
}
```

</details>

<br>

## Approach #2 (Breadth-first Search) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private static final int EMPTY = Integer.MAX_VALUE;
private static final int GATE = 0;
private static final List<int[]> DIRECTIONS = Arrays.asList(
        new int[] { 1,  0},
        new int[] {-1,  0},
        new int[] { 0,  1},
        new int[] { 0, -1}
);

public void wallsAndGates(int[][] rooms) {
    int m = rooms.length;
    if (m == 0) return;
    int n = rooms[0].length;
    Queue<int[]> q = new LinkedList<>();
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (rooms[row][col] == GATE) {
                q.add(new int[] { row, col });
            }
        }
    }
    while (!q.isEmpty()) {
        int[] point = q.poll();
        int row = point[0];
        int col = point[1];
        for (int[] direction : DIRECTIONS) {
            int r = row + direction[0];
            int c = col + direction[1];
            if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY) {
                continue;
            }
            rooms[r][c] = rooms[row][col] + 1;
            q.add(new int[] { r, c });
        }
    }
}
```

</details>
