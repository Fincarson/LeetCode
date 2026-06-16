# 789. Escape The Ghosts

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/escape-the-ghosts/)  
`Array` `Math`

**Problem Link:** [LeetCode 789 - Escape The Ghosts](https://leetcode.com/problems/escape-the-ghosts/)

## Problem

You are playing a simplified PAC-MAN game on an infinite 2-D grid. You start at the point [0, 0], and you are given a destination point target = [xtarget, ytarget] that you are trying to get to. There are several ghosts on the map with their starting positions given as a 2D array ghosts, where ghosts[i] = [xi, yi] represents the starting position of the ith ghost. All inputs are integral coordinates.

Each turn, you and all the ghosts may independently choose to either move 1 unit in any of the four cardinal directions: north, east, south, or west, or stay still. All actions happen simultaneously.

You escape if and only if you can reach the target before any ghost reaches you. If you reach any square (including the target) at the same time as a ghost, it does not count as an escape.

Return true if it is possible to escape regardless of how the ghosts move, otherwise return false.

### Example 1

```text
Input: ghosts = [[1,0],[0,3]], target = [0,1]
Output: true
Explanation: You can reach the destination (0, 1) after 1 turn, while the ghosts located at (1, 0) and (0, 3) cannot catch up with you.
```

### Example 2

```text
Input: ghosts = [[1,0]], target = [2,0]
Output: false
Explanation: You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
```

### Example 3

```text
Input: ghosts = [[2,0]], target = [1,0]
Output: false
Explanation: The ghost can reach the target at the same time as you.
```

## Constraints

- 1 <= ghosts.length <= 100
- ghosts[i].length == 2
- -104 <= xi, yi <= 104
- There can be multiple ghosts in the same location.
- target.length == 2
- -104 <= xtarget, ytarget <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Cat and Mouse II](https://leetcode.com/problems/cat-and-mouse-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 789. Escape The Ghosts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Taxicab Distance [Accepted] | Java, Python |

## Approach #1: Taxicab Distance [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int[] source = new int[]{0, 0};
        for (int[] ghost: ghosts)
            if (taxi(ghost, target) <= taxi(source, target))
                return false;
        return true;
    }

    public int taxi(int[] P, int[] Q) {
        return Math.abs(P[0] - Q[0]) + Math.abs(P[1] - Q[1]);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def escapeGhosts(self, ghosts, target):
        def taxi(P, Q):
            return abs(P[0] - Q[0]) + abs(P[1] - Q[1])

        return all(taxi([0, 0], target) < taxi(ghost, target)
                   for ghost in ghosts)
```

</details>
