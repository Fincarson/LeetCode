# 2463. Minimum Total Distance Traveled

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimum-total-distance-traveled/)  
`Array` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 2463 - Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/)

## Problem

There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.

The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.

All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.

Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.

Note that

- All robots move at the same speed.
- If two robots move in the same direction, they will never collide.
- If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
- If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
- If the robot moved from a position x to a position y, the distance it moved is |y - x|.

### Example 1

```text
Input: robot = [0,4,6], factory = [[2,2],[6,2]]
Output: 4
Explanation: As shown in the figure:
- The first robot at position 0 moves in the positive direction. It will be repaired at the first factory.
- The second robot at position 4 moves in the negative direction. It will be repaired at the first factory.
- The third robot at position 6 will be repaired at the second factory. It does not need to move.
The limit of the first factory is 2, and it fixed 2 robots.
The limit of the second factory is 2, and it fixed 1 robot.
The total distance is |2 - 0| + |2 - 4| + |6 - 6| = 4. It can be shown that we cannot achieve a better total distance than 4.
```

### Example 2

```text
Input: robot = [1,-1], factory = [[-2,1],[2,1]]
Output: 2
Explanation: As shown in the figure:
- The first robot at position 1 moves in the positive direction. It will be repaired at the second factory.
- The second robot at position -1 moves in the negative direction. It will be repaired at the first factory.
The limit of the first factory is 1, and it fixed 1 robot.
The limit of the second factory is 1, and it fixed 1 robot.
The total distance is |2 - 1| + |(-2) - (-1)| = 2. It can be shown that we cannot achieve a better total distance than 2.
```

## Constraints

- 1 <= robot.length, factory.length <= 100
- factory[j].length == 2
- -109 <= robot[i], positionj <= 109
- 0 <= limitj <= robot.length
- The input will be generated such that it is always possible to repair every robot.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Ways to Earn Points](https://leetcode.com/problems/number-of-ways-to-earn-points/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2463. Minimum Total Distance Traveled

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Time Limit Exceeded) | C++, Java, Python3 |
| Memoization | C++, Java, Python3 |
| Tabulation | C++, Java, Python3 |
| Space Optimized Tabulation | C++, Java, Python3 |

## Approach 1: Recursion (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        // Recursively calculate minimum total distance
        return calculateMinDistance(0, 0, robot, factoryPositions);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx,
                                   vector<int>& robot,
                                   vector<int>& factoryPositions) {
        // All robots assigned
        if (robotIdx == robot.size()) return 0;
        // No factories left to assign
        if (factoryIdx == factoryPositions.size()) return 1e12;

        // Option 1: Assign current robot to current factory
        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                           calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                                robot, factoryPositions);

        // Option 2: Skip current factory for the current robot
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                              factoryPositions);

        // Take the option with the minimum distance
        return min(assign, skip);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // Sort robots and factories by position
        Collections.sort(robot);
        Arrays.sort(factory, Comparator.comparingInt(a -> a[0]));

        // Flatten factory positions according to their capacities
        List<Integer> factoryPositions = new ArrayList<>();
        for (int[] f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.add(f[0]);
            }
        }

        // Recursively calculate minimum total distance with memoization
        return calculateMinDistance(0, 0, robot, factoryPositions);
    }

    private long calculateMinDistance(
        int robotIdx,
        int factoryIdx,
        List<Integer> robot,
        List<Integer> factoryPositions
    ) {
        // All robots assigned
        if (robotIdx == robot.size()) return 0;
        // No factories left to assign
        if (factoryIdx == factoryPositions.size()) return (long) 1e12;

        // Option 1: Assign current robot to current factory
        long assign =
            Math.abs(robot.get(robotIdx) - factoryPositions.get(factoryIdx)) +
            calculateMinDistance(
                robotIdx + 1,
                factoryIdx + 1,
                robot,
                factoryPositions
            );

        // Option 2: Skip current factory for the current robot
        long skip = calculateMinDistance(
            robotIdx,
            factoryIdx + 1,
            robot,
            factoryPositions
        );

        // Take the minimum and store in memo
        return Math.min(assign, skip);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotalDistance(self, robot, factory):
        # Sort robots and factories by position
        robot.sort()
        factory.sort()

        # Flatten factory positions according to their capacities
        factory_positions = []
        for f in factory:
            for i in range(f[1]):
                factory_positions.append(f[0])

        # Recursively calculate minimum total distance
        return self._calculate_min_distance(0, 0, robot, factory_positions)

    def _calculate_min_distance(
        self, robot_idx, factory_idx, robot, factory_positions
    ):
        # All robots assigned
        if robot_idx == len(robot):
            return 0
        # No factories left to assign
        if factory_idx == len(factory_positions):
            return 1e12

        # Option 1: Assign current robot to current factory
        assign = abs(
            robot[robot_idx] - factory_positions[factory_idx]
        ) + self._calculate_min_distance(
            robot_idx + 1, factory_idx + 1, robot, factory_positions
        )

        # Option 2: Skip current factory for the current robot
        skip = self._calculate_min_distance(
            robot_idx, factory_idx + 1, robot, factory_positions
        )

        # Take the option with the minimum distance
        return min(assign, skip)
```

</details>

<br>

## Approach 2: Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> memo(robotCount,
                                       vector<long long>(factoryCount, -1));

        // Recursively calculate minimum total distance with memoization
        return calculateMinDistance(0, 0, robot, factoryPositions, memo);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx,
                                   vector<int>& robot,
                                   vector<int>& factoryPositions,
                                   vector<vector<long long>>& memo) {
        // All robots assigned
        if (robotIdx == robot.size()) return 0;
        // No factories left to assign
        if (factoryIdx == factoryPositions.size()) return 1e12;
        // Check memo
        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];

        // Option 1: Assign current robot to current factory
        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                           calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                                robot, factoryPositions, memo);

        // Option 2: Skip current factory for the current robot
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                              factoryPositions, memo);

        return memo[robotIdx][factoryIdx] =
                   min(assign, skip);  // Take the minimum and store in memo
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // Sort robots and factories by position
        Collections.sort(robot);
        Arrays.sort(factory, Comparator.comparingInt(a -> a[0]));

        // Flatten factory positions according to their capacities
        List<Integer> factoryPositions = new ArrayList<>();
        for (int[] f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.add(f[0]);
            }
        }

        int robotCount = robot.size();
        int factoryCount = factoryPositions.size();
        long[][] memo = new long[robotCount][factoryCount];
        for (long[] row : memo) Arrays.fill(row, -1);

        // Recursively calculate minimum total distance with memoization
        return calculateMinDistance(0, 0, robot, factoryPositions, memo);
    }

    private long calculateMinDistance(
        int robotIdx,
        int factoryIdx,
        List<Integer> robot,
        List<Integer> factoryPositions,
        long[][] memo
    ) {
        // All robots assigned
        if (robotIdx == robot.size()) return 0;
        // No factories left to assign
        if (factoryIdx == factoryPositions.size()) return (long) 1e12;
        // Check memo
        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];

        // Option 1: Assign current robot to current factory
        long assign =
            Math.abs(robot.get(robotIdx) - factoryPositions.get(factoryIdx)) +
            calculateMinDistance(
                robotIdx + 1,
                factoryIdx + 1,
                robot,
                factoryPositions,
                memo
            );

        // Option 2: Skip current factory for the current robot
        long skip = calculateMinDistance(
            robotIdx,
            factoryIdx + 1,
            robot,
            factoryPositions,
            memo
        );

        // Take the minimum and store in memo
        memo[robotIdx][factoryIdx] = Math.min(assign, skip);
        return memo[robotIdx][factoryIdx];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotalDistance(
        self, robot: List[int], factory: List[List[int]]
    ) -> int:
        robot.sort()
        factory.sort(key=lambda x: x[0])
        factory_positions = []
        for f in factory:
            factory_positions.extend([f[0]] * f[1])
        robot_count = len(robot)
        factory_count = len(factory_positions)

        dp = [[None] * (factory_count + 1) for _ in range(robot_count + 1)]

        def _calculate_min_distance(robot_idx: int, factory_idx: int) -> int:
            if dp[robot_idx][factory_idx] is not None:
                return dp[robot_idx][factory_idx]
            if robot_idx == robot_count:
                dp[robot_idx][factory_idx] = 0
                return 0
            if factory_idx == factory_count:
                dp[robot_idx][factory_idx] = int(1e12)
                return int(1e12)

            assign = abs(
                robot[robot_idx] - factory_positions[factory_idx]
            ) + _calculate_min_distance(robot_idx + 1, factory_idx + 1)

            skip = _calculate_min_distance(robot_idx, factory_idx + 1)

            dp[robot_idx][factory_idx] = min(assign, skip)
            return dp[robot_idx][factory_idx]

        return _calculate_min_distance(0, 0)
```

</details>

<br>

## Approach 3: Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount + 1,
                                     vector<long long>(factoryCount + 1, 0));

        // Initialize base cases
        for (int i = 0; i < robotCount; i++)
            dp[i][factoryCount] = 1e12;  // No factories left

        // Fill DP table bottom-up
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Option 1: Assign current robot to current factory
                long long assign =
                    abs(robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];

                // Option 2: Skip current factory for the current robot
                long long skip = dp[i][j + 1];

                dp[i][j] = min(assign, skip);  // Take the minimum option
            }
        }
        // Minimum distance starting from first robot and factory
        return dp[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // Sort robots and factories by position
        Collections.sort(robot);
        Arrays.sort(factory, Comparator.comparingInt(a -> a[0]));

        // Flatten factory positions according to their capacities
        List<Integer> factoryPositions = new ArrayList<>();
        for (int[] f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.add(f[0]);
            }
        }

        int robotCount = robot.size();
        int factoryCount = factoryPositions.size();

        // Initialize dp array
        long[][] dp = new long[robotCount + 1][factoryCount + 1];

        // Initialize base cases
        for (int i = 0; i < robotCount; i++) {
            dp[i][factoryCount] = (long) 1e12; // No factories left
        }

        // Fill DP table bottom-up
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Option 1: Assign current robot to current factory
                long assign =
                    Math.abs(robot.get(i) - factoryPositions.get(j)) +
                    dp[i + 1][j + 1];

                // Option 2: Skip current factory for the current robot
                long skip = dp[i][j + 1];

                // Take the minimum option
                dp[i][j] = Math.min(assign, skip);
            }
        }

        // Minimum distance starting from first robot and factory
        return dp[0][0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotalDistance(self, robot, factory):
        # Sort robots and factories by position
        robot.sort()
        factory.sort(key=lambda x: x[0])

        # Flatten factory positions according to their capacities
        factory_positions = []
        for f in factory:
            for _ in range(f[1]):
                factory_positions.append(f[0])

        robot_count, factory_count = len(robot), len(factory_positions)
        dp = [[0] * (factory_count + 1) for _ in range(robot_count + 1)]

        # Initialize base cases
        for i in range(robot_count):
            dp[i][factory_count] = 1e12  # No factories left

        # Fill DP table bottom-up
        for i in range(robot_count - 1, -1, -1):
            for j in range(factory_count - 1, -1, -1):
                # Option 1: Assign current robot to current factory
                assign = abs(robot[i] - factory_positions[j]) + dp[i + 1][j + 1]

                # Option 2: Skip current factory for the current robot
                skip = dp[i][j + 1]

                dp[i][j] = min(assign, skip)  # Take the minimum option

        # Minimum distance starting from first robot and factory
        return dp[0][0]
```

</details>

<br>

## Approach 4: Space Optimized Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots,
                                   vector<vector<int>>& factories) {
        // Sort robots and factories by position
        sort(begin(robots), end(robots));
        sort(begin(factories), end(factories));

        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& factory : factories) {
            for (int i = 0; i < factory[1]; i++) {
                factoryPositions.push_back(factory[0]);
            }
        }

        int robotCount = robots.size(), factoryCount = factoryPositions.size();
        vector<long long> next(factoryCount + 1, 0),
            current(factoryCount + 1, 0);

        current[factoryCount] = 1e12;

        // Fill DP table using two rows for optimization
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Assign current robot to current factory
                long long assign =
                    abs(robots[i] - factoryPositions[j]) + next[j + 1];
                // Skip current factory for this robot
                long long skip = current[j + 1];
                // Take the minimum option
                current[j] = min(assign, skip);
            }
            // Move to next robot
            next = current;
        }
        // Return minimum distance starting from the first robot
        return current[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long minimumTotalDistance(List<Integer> robots, int[][] factories) {
        // Sort robots and factories by position
        Collections.sort(robots);
        Arrays.sort(factories, Comparator.comparingInt(a -> a[0]));

        // Flatten factory positions according to their capacities
        List<Integer> factoryPositions = new ArrayList<>();
        for (int[] factory : factories) {
            for (int i = 0; i < factory[1]; i++) {
                factoryPositions.add(factory[0]);
            }
        }

        int robotCount = robots.size(), factoryCount = factoryPositions.size();
        long[] next = new long[factoryCount + 1];
        long[] current = new long[factoryCount + 1];

        current[factoryCount] = (long) 1e12;

        // Fill DP table using two rows for optimization
        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                // Assign current robot to current factory
                long assign =
                    Math.abs((long) robots.get(i) - factoryPositions.get(j)) +
                    next[j + 1];
                // Skip current factory for this robot
                long skip = current[j + 1];
                // Take the minimum option
                current[j] = Math.min(assign, skip);
            }
            // Move to next robot
            System.arraycopy(current, 0, next, 0, factoryCount + 1);
        }

        // Return minimum distance starting from the first robot
        return current[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumTotalDistance(
        self, robots: List[int], factories: List[List[int]]
    ) -> int:
        # Sort robots and factories by position
        robots.sort()
        factories.sort()

        # Flatten factory positions according to their capacities
        factory_positions = []
        for factory in factories:
            for i in range(factory[1]):
                factory_positions.append(factory[0])

        robot_count = len(robots)
        factory_count = len(factory_positions)
        next_dist = [0 for _ in range(factory_count + 1)]
        current = [0 for _ in range(factory_count + 1)]

        current[factory_count] = 1e12

        # Fill DP table using two rows for optimization
        for i in range(robot_count - 1, -1, -1):
            for j in range(factory_count - 1, -1, -1):
                # Assign current robot to current factory
                assign = (
                    abs(robots[i] - factory_positions[j]) + next_dist[j + 1]
                )

                # Skip current factory for this robot
                skip = current[j + 1]
                # Take the minimum option
                current[j] = min(assign, skip)

            # Move to next robot
            next_dist = current[:]

        # Return minimum distance starting from the first robot
        return current[0]
```

</details>
