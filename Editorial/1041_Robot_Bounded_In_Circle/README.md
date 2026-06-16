# 1041. Robot Bounded In Circle

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/robot-bounded-in-circle/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 1041 - Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)

## Problem

On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

- The north direction is the positive direction of the y-axis.
- The south direction is the negative direction of the y-axis.
- The east direction is the positive direction of the x-axis.
- The west direction is the negative direction of the x-axis.

The robot can receive one of three instructions:

- "G": go straight 1 unit.
- "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
- "R": turn 90 degrees to the right (i.e., clockwise direction).

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

### Example 1

```text
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.
```

### Example 2

```text
Input: instructions = "GG"
Output: false
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
Based on that, we return false.
```

### Example 3

```text
Input: instructions = "GL"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
"G": move one step. Position: (-1, 1). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
"G": move one step. Position: (-1, 0). Direction: South.
"L": turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
"G": move one step. Position: (0, 0). Direction: East.
"L": turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (-1, 1) --> (-1, 0) --> (0, 0).
Based on that, we return true.
```

## Constraints

- 1 <= instructions.length <= 100
- instructions[i] is 'G', 'L' or, 'R'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1041. Robot Bounded In Circle

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One Pass | Java, Python3 |

## Approach 1: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        // north = 0, east = 1, south = 2, west = 3
        int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // Initial position is in the center
        int x = 0, y = 0;
        // facing north
        int idx = 0;
        
        for (char i : instructions.toCharArray()) {
            if (i == 'L')
                idx = (idx + 3) % 4;
            else if (i == 'R')
                idx = (idx + 1) % 4;
            else {
                x += directions[idx][0];
                y += directions[idx][1];   
            }    
        }
        
        // after one cycle:
        // robot returns into initial position
        // or robot doesn't face north
        return (x == 0 && y == 0) || (idx != 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        # north = 0, east = 1, south = 2, west = 3
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        # Initial position is in the center
        x = y = 0
        # facing north
        idx = 0
        
        for i in instructions:
            if i == "L":
                idx = (idx + 3) % 4
            elif i == "R":
                idx = (idx + 1) % 4
            else:
                x += directions[idx][0]
                y += directions[idx][1]
        
        # after one cycle:
        # robot returns into initial position
        # or robot doesn't face north
        return (x == 0 and y == 0) or idx != 0
```

</details>
