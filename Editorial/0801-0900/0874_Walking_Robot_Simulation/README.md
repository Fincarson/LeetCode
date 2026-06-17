# 874. Walking Robot Simulation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/walking-robot-simulation/)  
`Array` `Hash Table` `Simulation`

**Problem Link:** [LeetCode 874 - Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/)

## Problem

A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

- -2: Turn left 90 degrees.
- -1: Turn right 90 degrees.
- 1 <= k <= 9: Move forward k units, one unit at a time.

Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

Note:

- There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
- North means +Y direction.
- East means +X direction.
- South means -Y direction.
- West means -X direction.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= commands.length <= 104
- commands[i] is either -2, -1, or an integer in the range [1, 9].
- 0 <= obstacles.length <= 104
- -3 * 104 <= xi, yi <= 3 * 104
- The answer is guaranteed to be less than 231.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 874. Walking Robot Simulation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    static const long long HASH_MULTIPLIER =
        60013;  // Slightly larger than 2 * max coordinate value

    // Hash function to convert (x, y) coordinates to a unique integer value
    long long hashCoordinates(long long x, long long y) {
        return x + HASH_MULTIPLIER * y;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles in an unordered_set for efficient lookup
        unordered_set<long long> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }

        // Define direction vectors: North, East, South, West
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currentPosition = {0, 0};
        int maxDistanceSquared = 0;
        int currentDirection = 0;  // 0: North, 1: East, 2: South, 3: West

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // Move forward
            vector<int> direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared =
                max(maxDistanceSquared,
                    currentPosition[0] * currentPosition[0] +
                        currentPosition[1] * currentPosition[1]);
        }

        return maxDistanceSquared;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final long HASH_MULTIPLIER = 60013; // Slightly larger than 2 * max coordinate value

    public int robotSim(int[] commands, int[][] obstacles) {
        // Store obstacles in an HashSet for efficient lookup
        Set<Long> obstacleSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obstacleSet.add(hashCoordinates(obstacle[0], obstacle[1]));
        }

        // Define direction vectors: North, East, South, West
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        int[] currentPosition = { 0, 0 };
        int maxDistanceSquared = 0;
        int currentDirection = 0; // 0: North, 1: East, 2: South, 3: West

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                currentDirection = (currentDirection + 1) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                currentDirection = (currentDirection + 3) % 4;
                continue;
            }

            // Move forward
            int[] direction = directions[currentDirection];
            for (int step = 0; step < command; step++) {
                int nextX = currentPosition[0] + direction[0];
                int nextY = currentPosition[1] + direction[1];
                if (obstacleSet.contains(hashCoordinates(nextX, nextY))) {
                    break;
                }
                currentPosition[0] = nextX;
                currentPosition[1] = nextY;
            }

            maxDistanceSquared = Math.max(
                maxDistanceSquared,
                currentPosition[0] * currentPosition[0] +
                currentPosition[1] * currentPosition[1]
            );
        }

        return maxDistanceSquared;
    }

    // Hash function to convert (x, y) coordinates to a unique integer value
    private long hashCoordinates(long x, long y) {
        return x + HASH_MULTIPLIER * y;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.HASH_MULTIPLIER = (
            60013  # Slightly larger than 2 * max coordinate value
        )

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        # Store obstacles in an set for efficient lookup
        obstacle_set = {self._hash_coordinates(x, y) for x, y in obstacles}

        # Define direction vectors: North, East, South, West
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        x, y = 0, 0
        max_distance_squared = 0
        current_direction = 0  # 0: North, 1: East, 2: South, 3: West

        for command in commands:
            if command == -1:  # Turn right
                current_direction = (current_direction + 1) % 4
                continue

            if command == -2:  # Turn left
                current_direction = (current_direction + 3) % 4
                continue

            # Move forward
            dx, dy = directions[current_direction]
            for _ in range(command):
                next_x, next_y = x + dx, y + dy
                if self._hash_coordinates(next_x, next_y) in obstacle_set:
                    break
                x, y = next_x, next_y

            max_distance_squared = max(max_distance_squared, x * x + y * y)

        return max_distance_squared

    # Hash function to convert (x, y) coordinates to a unique integer value
    def _hash_coordinates(self, x: int, y: int) -> int:
        return x + self.HASH_MULTIPLIER * y
```

</details>
