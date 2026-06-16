# 909. Snakes and Ladders

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/snakes-and-ladders/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 909 - Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/)

## Problem

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

- Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].

		This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
- If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
- The game ends when you reach the square n2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

- For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.

Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.

### Example 1

```text
Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
```

### Example 2

```text
Input: board = [[-1,-1],[-1,3]]
Output: 1
```

## Constraints

- n == board.length == board[i].length
- 2 <= n <= 20
- board[i][j] is either -1 or in the range [1, n2].
- The squares labeled 1 and n2 are not the starting points of any snake or ladder.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Most Profitable Path in a Tree](https://leetcode.com/problems/most-profitable-path-in-a-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 909. Snakes and Ladders

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-first search | C++, Java, Python3 |
| Dijkstra's algorithm | C++, Java, Python3 |

## Approach 1: Breadth-first search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        Pair<Integer, Integer>[] cells = new Pair[n * n + 1];
        int label = 1;
        Integer[] columns = new Integer[n];
        for (int i = 0; i < n; i++) {
            columns[i] = i;
        }
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = new Pair<>(row, column);
            }
            Collections.reverse(Arrays.asList(columns));
        }
        int[] dist = new int[n * n + 1];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new LinkedList<Integer>();
        dist[1] = 0;
        q.add(1);
        while (!q.isEmpty()) {
            int curr = q.remove();
            for (int next = curr + 1; next <= Math.min(curr + 6, n * n); next++) {
                int row = cells[next].getKey(), column = cells[next].getValue();
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.add(destination);
                }
            }
        }
        return dist[n * n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = [None] * (n**2 + 1)
        label = 1
        columns = list(range(0, n))
        for row in range(n - 1, -1, -1):
            for column in columns:
                cells[label] = (row, column)
                label += 1
            columns.reverse()
        dist = [-1] * (n * n + 1)
        q = deque([1])
        dist[1] = 0
        while q:
            curr = q.popleft()
            for next in range(curr + 1, min(curr + 6, n**2) + 1):
                row, column = cells[next]
                destination = (board[row][column] if board[row][column] != -1
                               else next)
                if dist[destination] == -1:
                    dist[destination] = dist[curr] + 1
                    q.append(destination)
        return dist[n * n]
```

</details>

<br>

## Approach 2: Dijkstra's algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[1] = 0;
        q.emplace(0, 1);
        while (!q.empty()) {
            auto [d, curr] = q.top();
            q.pop();
            if (d != dist[curr]) {
                continue;
            }
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1 || dist[curr] + 1 < dist[destination]) {
                    dist[destination] = dist[curr] + 1;
                    q.emplace(dist[destination], destination);
                }
            }
        }
        return dist[n * n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        Pair<Integer, Integer>[] cells = new Pair[n * n + 1];
        int label = 1;
        Integer[] columns = new Integer[n];
        for (int i = 0; i < n; i++) {
            columns[i] = i;
        }
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = new Pair<>(row, column);
            }
            Collections.reverse(Arrays.asList(columns));
        }
        int[] dist = new int[n * n + 1];
        Arrays.fill(dist, -1);
        class Vertex implements Comparable<Vertex> {
            int distance, label;

            public Vertex(int distance, int label) {
                this.distance = distance;
                this.label = label;
            }

            public int compareTo(Vertex v) {
                return this.distance - v.distance;
            }
        }
        PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
        dist[1] = 0;
        q.add(new Vertex(0, 1));
        while (!q.isEmpty()) {
            Vertex vertex = q.remove();
            int d = vertex.distance, curr = vertex.label;
            if (d != dist[curr]) {
                continue;
            }
            for (int next = curr + 1; next <= Math.min(curr + 6, n * n); next++) {
                int row = cells[next].getKey(), column = cells[next].getValue();
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1 || dist[curr] + 1 < dist[destination]) {
                    dist[destination] = dist[curr] + 1;
                    q.add(new Vertex(dist[destination], destination));
                }
            }
        }
        return dist[n * n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = [None] * (n**2 + 1)
        label = 1
        columns = list(range(0, n))
        for row in range(n - 1, -1, -1):
            for column in columns:
                cells[label] = (row, column)
                label += 1
            columns.reverse()
        dist = [-1] * (n * n + 1)
        dist[1] = 0
        q = [(0, 1)]
        while q:
            d, curr = heapq.heappop(q)
            if d != dist[curr]:
                continue
            for next in range(curr + 1, min(curr + 6, n**2) + 1):
                row, column = cells[next]
                destination = (board[row][column] if board[row][column] != -1
                               else next)
                if dist[destination] == -1 or dist[curr] + 1 < dist[destination]:
                    dist[destination] = dist[curr] + 1
                    heapq.heappush(q, (dist[destination], destination))
        return dist[n * n]
```

</details>
