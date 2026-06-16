# 1293. Shortest Path in a Grid with Obstacles Elimination

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)  
`Array` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1293 - Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

## Problem

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

### Example 1

```text
Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
```

### Example 2

```text
Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 40
- 1 <= k <= m * n
- grid[i][j] is either 0 or 1.
- grid[0][0] == grid[m - 1][n - 1] == 0

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find a Safe Walk Through a Grid](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1293. Shortest Path in a Grid with Obstacles Elimination

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS (Breadth-First Search) | Java, Python3 |
| A* (A Star) Algorithm | Java, Python3 |

## Approach 1: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class StepState {
    /**
     * data object to keep the state info for each step:
     * <steps, row, col, remaining_eliminations>
     */
    public int steps, row, col, k;

    public StepState(int steps, int row, int col, int k) {
        this.steps = steps;
        this.row = row;
        this.col = col;
        this.k = k;
    }

    @Override
    public int hashCode() {
        // needed when we put objects into any container class
        return (this.row + 1) * (this.col + 1) * this.k;
    }

    @Override
    public boolean equals(Object other) {
        /**
         * only (row, col, k) matters as the state info
         */
        if (!(other instanceof StepState)) {
            return false;
        }
        StepState newState = (StepState) other;
        return (this.row == newState.row) && (this.col == newState.col) && (this.k == newState.k);
    }

    @Override
    public String toString() {
        return String.format("%d %d %d", this.row, this.col, this.k);
    }
}

class Solution {
    public int shortestPath(int[][] grid, int k) {
        int rows = grid.length, cols = grid[0].length;
        int[] target = {rows - 1, cols - 1};

        // if we have sufficient quotas to eliminate the obstacles in the worst case,
        // then the shortest distance is the Manhattan distance.
        if (k >= rows + cols - 2) {
            return rows + cols - 2;
        }

        Deque<StepState> queue = new LinkedList<>();
        HashSet<StepState> seen = new HashSet<>();

        // (steps, row, col, remaining quota to eliminate obstacles)
        StepState start = new StepState(0, 0, 0, k);
        queue.addLast(start);
        seen.add(start);

        while (!queue.isEmpty()) {
            StepState curr = queue.pollFirst();

            // we reach the target here
            if (target[0] == curr.row && target[1] == curr.col) {
                return curr.steps;
            }

            int[] nextSteps = {curr.row, curr.col + 1, curr.row + 1, curr.col,
                    curr.row, curr.col - 1, curr.row - 1, curr.col};

            // explore the four directions in the next step
            for (int i = 0; i < nextSteps.length; i += 2) {
                int nextRow = nextSteps[i];
                int nextCol = nextSteps[i + 1];

                // out of the boundary of grid
                if (0 > nextRow || nextRow == rows || 0 > nextCol || nextCol == cols) {
                    continue;
                }

                int nextElimination = curr.k - grid[nextRow][nextCol];
                StepState newState = new StepState(curr.steps + 1, nextRow, nextCol, nextElimination);

                // add the next move in the queue if it qualifies.
                if (nextElimination >= 0 && !seen.contains(newState)) {
                    seen.add(newState);
                    queue.addLast(newState);
                }
            }
        }

        // did not reach the target
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        rows, cols = len(grid), len(grid[0])
        target = (rows - 1, cols - 1)

        # if we have sufficient quotas to eliminate the obstacles in the worst case,
        # then the shortest distance is the Manhattan distance
        if k >= rows + cols - 2:
            return rows + cols - 2

        # (row, col, remaining quota to eliminate obstacles)
        state = (0, 0, k)
        # (steps, state)
        queue = deque([(0, state)])
        seen = set([state])

        while queue:
            steps, (row, col, k) = queue.popleft()

            # we reach the target here
            if (row, col) == target:
                return steps

            # explore the four directions in the next step
            for new_row, new_col in [(row, col + 1), (row + 1, col), (row, col - 1), (row - 1, col)]:
                # if (new_row, new_col) is within the grid boundaries
                if (0 <= new_row < rows) and (0 <= new_col < cols):
                    new_eliminations = k - grid[new_row][new_col]
                    new_state = (new_row, new_col, new_eliminations)
                    # add the next move in the queue if it qualifies
                    if new_eliminations >= 0 and new_state not in seen:
                        seen.add(new_state)
                        queue.append((steps + 1, new_state))

        # did not reach the target
        return -1
```

</details>

<br>

## Approach 2: A* (A Star) Algorithm

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class StepState implements Comparable {
    /**
     * state info for each step:
     * <estimation, steps, row, col, remaining_eliminations>
     */
    public int estimation, steps, row, col, k;
    private int[] target;

    public StepState(int steps, int row, int col, int k, int[] target) {
        this.steps = steps;
        this.row = row;
        this.col = col;
        this.k = k;

        this.target = target;
        int manhattanDistance = target[0] - row + target[1] - col;
        // h(n) = manhattan distance,  g(n) = 0
        // estimation = h(n) + g(n)
        this.estimation = manhattanDistance + steps;
    }

    @Override
    public int hashCode() {
        return (this.row + 1) * (this.col + 1) * this.k;
    }

    @Override
    public int compareTo(Object o) {
        // order the elements solely based on the 'estimation' value
        StepState other = (StepState) o;
        return this.estimation - other.estimation;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof StepState)) {
            return false;
        }
        StepState newState = (StepState) o;
        return (this.row == newState.row) && (this.col == newState.col) && (this.k == newState.k);
    }

    @Override
    public String toString() {
        return String.format("(%d %d %d %d %d)",
                this.estimation, this.steps, this.row, this.col, this.k);
    }
}

class Solution {

    public int shortestPath(int[][] grid, int k) {
        int rows = grid.length, cols = grid[0].length;
        int[] target = {rows - 1, cols - 1};

        PriorityQueue<StepState> queue = new PriorityQueue<>();
        HashSet<StepState> seen = new HashSet<>();

        // (steps, row, col, remaining quota to eliminate obstacles)
        StepState start = new StepState(0, 0, 0, k, target);
        queue.offer(start);
        seen.add(start);

        while (!queue.isEmpty()) {
            StepState curr = queue.poll();

            // we can reach the target in the shortest path (manhattan distance),
            //   even if the remaining steps are all obstacles
            int remainMinDistance = curr.estimation - curr.steps;
            if (remainMinDistance <= curr.k) {
                return curr.estimation;
            }

            int[] nextSteps = {curr.row, curr.col + 1, curr.row + 1, curr.col,
                    curr.row, curr.col - 1, curr.row - 1, curr.col};

            // explore the four directions in the next step
            for (int i = 0; i < nextSteps.length; i += 2) {
                int nextRow = nextSteps[i];
                int nextCol = nextSteps[i + 1];

                // out of the boundary of grid
                if (0 > nextRow || nextRow == rows || 0 > nextCol || nextCol == cols) {
                    continue;
                }

                int nextElimination = curr.k - grid[nextRow][nextCol];
                StepState newState = new StepState(
                        curr.steps + 1, nextRow, nextCol, nextElimination, target);

                // add the next move in the queue if it qualifies.
                if (nextElimination >= 0 && !seen.contains(newState)) {
                    seen.add(newState);
                    queue.offer(newState);
                }
            }
        }

        // did not reach the target
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:

        rows, cols = len(grid), len(grid[0])
        target = (rows - 1, cols - 1)

        def manhattan_distance(row, col):
            return target[0] - row + target[1] - col

        # (row, col, remaining_elimination)
        state = (0, 0, k)

        # (estimation, steps, state)
        # h(n) = manhattan distance,  g(n) = 0
        queue = [(manhattan_distance(0, 0), 0, state)]
        seen = set([state])

        while queue:
            estimation, steps, (row, col, remain_eliminations) = heapq.heappop(queue)

            # we can reach the target in the shortest path (manhattan distance),
            #   even if the remaining steps are all obstacles
            remain_min_distance = estimation - steps
            if remain_min_distance <= remain_eliminations:
                return estimation

            # explore the four directions in the next step
            for new_row, new_col in [(row, col + 1), (row + 1, col), (row, col - 1), (row - 1, col)]:
                # if (new_row, new_col) is within the grid boundaries
                if (0 <= new_row < rows) and (0 <= new_col < cols):
                    new_eliminations = remain_eliminations - grid[new_row][new_col]
                    new_state = (new_row, new_col, new_eliminations)

                    # if the next direction is worth exploring
                    if new_eliminations >= 0 and new_state not in seen:
                        seen.add(new_state)
                        new_estimation = manhattan_distance(new_row, new_col) + steps + 1
                        heapq.heappush(queue, (new_estimation, steps + 1, new_state))

        # did not reach the target
        return -1
```

</details>
