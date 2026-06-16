# 573. Squirrel Simulation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/squirrel-simulation/)  
`Array` `Math`

**Problem Link:** [LeetCode 573 - Squirrel Simulation](https://leetcode.com/problems/squirrel-simulation/)

## Problem

You are given two integers height and width representing a garden of size height x width. You are also given:

- an array tree where tree = [treer, treec] is the position of the tree in the garden,
- an array squirrel where squirrel = [squirrelr, squirrelc] is the position of the squirrel in the garden,
- and an array nuts where nuts[i] = [nutir, nutic] is the position of the ith nut in the garden.

The squirrel can only take at most one nut at one time and can move in four directions: up, down, left, and right, to the adjacent cell.

Return the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one.

The distance is the number of moves.

### Example 1

```text
Input: height = 5, width = 7, tree = [2,2], squirrel = [4,4], nuts = [[3,0], [2,5]]
Output: 12
Explanation: The squirrel should go to the nut at [2, 5] first to achieve a minimal distance.
```

### Example 2

```text
Input: height = 1, width = 3, tree = [0,1], squirrel = [0,0], nuts = [[0,2]]
Output: 3
```

## Constraints

- 1 <= height, width <= 100
- tree.length == 2
- squirrel.length == 2
- 1 <= nuts.length <= 5000
- nuts[i].length == 2
- 0 <= treer, squirrelr, nutir <= height
- 0 <= treec, squirrelc, nutic <= width

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 573. Squirrel Simulation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simple Solution | Java |

## Approach 1: Simple Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
        int tot_dist = 0, d = Integer.MIN_VALUE;
        for (int[] nut: nuts) {
            tot_dist += (distance(nut, tree) * 2);
            d = Math.max(d, distance(nut, tree) - distance(nut, squirrel));
        }
        return tot_dist - d;
    }
    public int distance(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
}
```

</details>
