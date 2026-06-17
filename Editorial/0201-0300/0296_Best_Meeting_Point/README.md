# 296. Best Meeting Point

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/best-meeting-point/)  
`Array` `Math` `Sorting` `Matrix`

**Problem Link:** [LeetCode 296 - Best Meeting Point](https://leetcode.com/problems/best-meeting-point/)

## Problem

Given an m x n binary grid grid where each 1 marks the home of one friend, return the minimal total travel distance.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

### Example 1

```text
Input: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 6
Explanation: Given three friends living at (0,0), (0,4), and (2,2).
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
So return 6.
```

### Example 2

```text
Input: grid = [[1,1]]
Output: 1
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 200
- grid[i][j] is either 0 or 1.
- There will be at least two friends in the grid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 296. Best Meeting Point

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Breadth-first Search) [Time Limit Exceeded] | Java |
| Approach #2 (Manhattan Distance Formula) [Time Limit Exceeded] | Java |
| Approach #3 (Sorting) [Accepted] | Java |
| Approach #4 (Collect Coordinates in Sorted Order) [Accepted] | Java |

## Approach #1 (Breadth-first Search) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public int minTotalDistance(int[][] grid) {
    int minDistance = Integer.MAX_VALUE;
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            int distance = search(grid, row, col);
            minDistance = Math.min(distance, minDistance);
        }
    }
    return minDistance;
}

private int search(int[][] grid, int row, int col) {
    Queue<Point> q = new LinkedList<>();
    int m = grid.length;
    int n = grid[0].length;
    boolean[][] visited = new boolean[m][n];
    q.add(new Point(row, col, 0));
    int totalDistance = 0;
    while (!q.isEmpty()) {
        Point point = q.poll();
        int r = point.row;
        int c = point.col;
        int d = point.distance;
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c]) {
            continue;
        }
        if (grid[r][c] == 1) {
            totalDistance += d;
        }
        visited[r][c] = true;
        q.add(new Point(r + 1, c, d + 1));
        q.add(new Point(r - 1, c, d + 1));
        q.add(new Point(r, c + 1, d + 1));
        q.add(new Point(r, c - 1, d + 1));
    }
    return totalDistance;
}

public class Point {
    int row;
    int col;
    int distance;
    public Point(int row, int col, int distance) {
        this.row = row;
        this.col = col;
        this.distance = distance;
    }
}
```

</details>

<br>

## Approach #2 (Manhattan Distance Formula) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public int minTotalDistance(int[][] grid) {
    List<Point> points = getAllPoints(grid);
    int minDistance = Integer.MAX_VALUE;
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            int distance = calculateDistance(points, row, col);
            minDistance = Math.min(distance, minDistance);
        }
    }
    return minDistance;
}

private int calculateDistance(List<Point> points, int row, int col) {
    int distance = 0;
    for (Point point : points) {
        distance += Math.abs(point.row - row) + Math.abs(point.col - col);
    }
    return distance;
}

private List<Point> getAllPoints(int[][] grid) {
    List<Point> points = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                points.add(new Point(row, col));
            }
        }
    }
    return points;
}

public class Point {
    int row;
    int col;
    public Point(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
```

</details>

<br>

## Approach #3 (Sorting) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int minTotalDistance(int[][] grid) {
    List<Integer> rows = new ArrayList<>();
    List<Integer> cols = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                rows.add(row);
                cols.add(col);
            }
        }
    }
    int row = rows.get(rows.size() / 2);
    Collections.sort(cols);
    int col = cols.get(cols.size() / 2);
    return minDistance1D(rows, row) + minDistance1D(cols, col);
}

private int minDistance1D(List<Integer> points, int origin) {
    int distance = 0;
    for (int point : points) {
        distance += Math.abs(point - origin);
    }
    return distance;
}
```

</details>

<br>

## Approach #4 (Collect Coordinates in Sorted Order) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int minTotalDistance(int[][] grid) {
    List<Integer> rows = collectRows(grid);
    List<Integer> cols = collectCols(grid);
    int row = rows.get(rows.size() / 2);
    int col = cols.get(cols.size() / 2);
    return minDistance1D(rows, row) + minDistance1D(cols, col);
}

private int minDistance1D(List<Integer> points, int origin) {
    int distance = 0;
    for (int point : points) {
        distance += Math.abs(point - origin);
    }
    return distance;
}

private List<Integer> collectRows(int[][] grid) {
    List<Integer> rows = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                rows.add(row);
            }
        }
    }
    return rows;
}

private List<Integer> collectCols(int[][] grid) {
    List<Integer> cols = new ArrayList<>();
    for (int col = 0; col < grid[0].length; col++) {
        for (int row = 0; row < grid.length; row++) {
            if (grid[row][col] == 1) {
                cols.add(col);
            }
        }
    }
    return cols;
}
```

</details>
