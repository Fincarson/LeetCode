# 1197. Minimum Knight Moves

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-knight-moves/)  
`Breadth-First Search`

**Problem Link:** [LeetCode 1197 - Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/)

## Problem

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.

### Example 1

```text
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
```

### Example 2

```text
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
```

## Constraints

- -300 <= x, y <= 300
- 0 <= |x| + |y| <= 300

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check Knight Tour Configuration](https://leetcode.com/problems/check-knight-tour-configuration/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1197. Minimum Knight Moves

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS (Breadth-First Search) | Java, Python3 |
| Bidirectional BFS | Java, Python3 |
| DFS (Depth-First Search) with Memoization | Java, Python3 |

## Approach 1: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        int[][] offsets = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // - Rather than using the inefficient HashSet, we use the bitmap
        //     otherwise we would run out of time for the test cases.
        // - We create a bitmap that is sufficient to cover all the possible
        //     inputs, according to the description of the problem.
        boolean[][] visited = new boolean[607][607];

        Deque<int[]> queue = new LinkedList<>();
        queue.addLast(new int[]{0, 0});
        int steps = 0;

        while (queue.size() > 0) {
            int currLevelSize = queue.size();
            // iterate through the current level
            for (int i = 0; i < currLevelSize; i++) {
                int[] curr = queue.removeFirst();
                if (curr[0] == x && curr[1] == y) {
                    return steps;
                }

                for (int[] offset : offsets) {
                    int[] next = new int[]{curr[0] + offset[0], curr[1] + offset[1]};
                    // align the coordinate to the bitmap
                    if (!visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        queue.addLast(next);
                    }
                }
            }
            steps++;
        }
        // move on to the next level
        return steps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        # the offsets in the eight directions
        offsets = [(1, 2), (2, 1), (2, -1), (1, -2),
                   (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

        def bfs(x, y):
            visited = set()
            queue = deque([(0, 0)])
            steps = 0

            while queue:
                curr_level_cnt = len(queue)
                # iterate through the current level
                for i in range(curr_level_cnt):
                    curr_x, curr_y = queue.popleft()
                    if (curr_x, curr_y) == (x, y):
                        return steps

                    for offset_x, offset_y in offsets:
                        next_x, next_y = curr_x + offset_x, curr_y + offset_y
                        if (next_x, next_y) not in visited:
                            visited.add((next_x, next_y))
                            queue.append((next_x, next_y))

                # move on to the next level
                steps += 1

        return bfs(x, y)
```

</details>

<br>

## Approach 2: Bidirectional BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        int[][] offsets = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // data structures needed to move from the origin point
        Deque<int[]> originQueue = new LinkedList<>();
        originQueue.addLast(new int[]{0, 0, 0});
        Map<String, Integer> originDistance = new HashMap<>();
        originDistance.put("0,0", 0);

        // data structures needed to move from the target point
        Deque<int[]> targetQueue = new LinkedList<>();
        targetQueue.addLast(new int[]{x, y, 0});
        Map<String, Integer> targetDistance = new HashMap<>();
        targetDistance.put(x + "," + y, 0);

        while (true) {
            // check if we reach the circle of target
            int[] origin = originQueue.removeFirst();
            String originXY = origin[0] + "," + origin[1];
            if (targetDistance.containsKey(originXY)) {
                return origin[2] + targetDistance.get(originXY);
            }

            // check if we reach the circle of origin
            int[] target = targetQueue.removeFirst();
            String targetXY = target[0] + "," + target[1];
            if (originDistance.containsKey(targetXY)) {
                return target[2] + originDistance.get(targetXY);
            }

            for (int[] offset : offsets) {
                // expand the circle of origin
                int[] nextOrigin = new int[]{origin[0] + offset[0], origin[1] + offset[1]};
                String nextOriginXY = nextOrigin[0] + "," + nextOrigin[1];
                if (!originDistance.containsKey(nextOriginXY)) {
                    originQueue.addLast(new int[]{nextOrigin[0], nextOrigin[1], origin[2] + 1});
                    originDistance.put(nextOriginXY, origin[2] + 1);
                }

                // expand the circle of target
                int[] nextTarget = new int[]{target[0] + offset[0], target[1] + offset[1]};
                String nextTargetXY = nextTarget[0] + "," + nextTarget[1];
                if (!targetDistance.containsKey(nextTargetXY)) {
                    targetQueue.addLast(new int[]{nextTarget[0], nextTarget[1], target[2] + 1});
                    targetDistance.put(nextTargetXY, target[2] + 1);
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        # the offsets in the eight directions
        offsets = [(1, 2), (2, 1), (2, -1), (1, -2),
                   (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

        # data structures needed to move from the origin point
        origin_queue = deque([(0, 0, 0)])
        origin_distance = {(0, 0): 0}

        # data structures needed to move from the target point
        target_queue = deque([(x, y, 0)])
        target_distance = {(x, y): 0}

        while True:
            # check if we reach the circle of target
            origin_x, origin_y, origin_steps = origin_queue.popleft()
            if (origin_x, origin_y) in target_distance:
                return origin_steps + target_distance[(origin_x, origin_y)]

            # check if we reach the circle of origin
            target_x, target_y, target_steps = target_queue.popleft()
            if (target_x, target_y) in origin_distance:
                return target_steps + origin_distance[(target_x, target_y)]

            for offset_x, offset_y in offsets:
                # expand the circle of origin
                next_origin_x, next_origin_y = origin_x + offset_x, origin_y + offset_y
                if (next_origin_x, next_origin_y) not in origin_distance:
                    origin_queue.append((next_origin_x, next_origin_y, origin_steps + 1))
                    origin_distance[(next_origin_x, next_origin_y)] = origin_steps + 1

                # expand the circle of target
                next_target_x, next_target_y = target_x + offset_x, target_y + offset_y
                if (next_target_x, next_target_y) not in target_distance:
                    target_queue.append((next_target_x, next_target_y, target_steps + 1))
                    target_distance[(next_target_x, next_target_y)] = target_steps + 1
```

</details>

<br>

## Approach 3: DFS (Depth-First Search) with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Map<String, Integer> memo = new HashMap<>();

    private int dfs(int x, int y) {
        String key = x + "," + y;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        if (x + y == 0) {
            return 0;
        } else if (x + y == 2) {
            return 2;
        } else {
            Integer ret = Math.min(dfs(Math.abs(x - 1), Math.abs(y - 2)),
                    dfs(Math.abs(x - 2), Math.abs(y - 1))) + 1;
            memo.put(key, ret);
            return ret;
        }
    }

    public int minKnightMoves(int x, int y) {
        return dfs(Math.abs(x), Math.abs(y));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:

        @lru_cache(maxsize=None)
        def dfs(x, y):
            if x + y == 0:
                # base case: (0, 0)
                return 0
            elif x + y == 2:
                # base case: (1, 1), (0, 2), (2, 0)
                return 2
            else:
                return min(dfs(abs(x - 1), abs(y - 2)), dfs(abs(x - 2), abs(y - 1))) + 1

        return dfs(abs(x), abs(y))
```

</details>
