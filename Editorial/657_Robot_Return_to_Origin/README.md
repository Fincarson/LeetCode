# 657. Robot Return to Origin

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/robot-return-to-origin/)  
`String` `Simulation`

**Problem Link:** [LeetCode 657 - Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/)

## Problem

There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

### Example 1

```text
Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
```

### Example 2

```text
Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
```

## Constraints

- 1 <= moves.length <= 2 * 104
- moves only contains the characters 'U', 'D', 'L' and 'R'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Execution of All Suffix Instructions Staying in a Grid](https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Furthest Point From Origin](https://leetcode.com/problems/furthest-point-from-origin/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 657. Robot Return to Origin

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Simulation [Accepted] | Java, Python |

## Approach #1: Simulation [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for (char move: moves.toCharArray()) {
            if (move == 'U') y--;
            else if (move == 'D') y++;
            else if (move == 'L') x--;
            else if (move == 'R') x++;
        }
        return x == 0 && y == 0;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def judgeCircle(self, moves):
        x = y = 0
        for move in moves:
            if move == 'U': y -= 1
            elif move == 'D': y += 1
            elif move == 'L': x -= 1
            elif move == 'R': x += 1

        return x == y == 0
```

</details>
