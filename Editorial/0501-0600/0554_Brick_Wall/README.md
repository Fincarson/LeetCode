# 554. Brick Wall

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/brick-wall/)  
`Array` `Hash Table`

**Problem Link:** [LeetCode 554 - Brick Wall](https://leetcode.com/problems/brick-wall/)

## Problem

There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

### Example 1

```text
Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
```

### Example 2

```text
Input: wall = [[1],[1],[1]]
Output: 3
```

## Constraints

- n == wall.length
- 1 <= n <= 104
- 1 <= wall[i].length <= 104
- 1 <= sum(wall[i].length) <= 2 * 104
- sum(wall[i]) is the same for each row i.
- 1 <= wall[i][j] <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Build Sturdy Brick Wall](https://leetcode.com/problems/number-of-ways-to-build-sturdy-brick-wall/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 554. Brick Wall

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force[Time LImit Exceeded] | Java |
| Approach #3 Using HashMap [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int leastBricks(List < List < Integer >> wall) {
        int[] pos = new int[wall.size()];
        int c = 0, sum = 0, res = Integer.MAX_VALUE;
        for (int el: wall.get(0))
            sum += el;
        while (sum != 0) {
            int count = 0;
            for (int i = 0; i < wall.size(); i++) {
                List < Integer > row = wall.get(i);
                if (row.get(pos[i]) != 0)
                    count++;
                else
                    pos[i]++;
                row.set(pos[i], row.get(pos[i]) - 1);
            }
            sum--;
            res = Math.min(res, count);
        }
        return res;
    }
}
```

</details>

<br>

## Approach #2 Better Brute Force[Time LImit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int leastBricks(List < List < Integer >> wall) {
        int[] pos = new int[wall.size()];
        int sum = 0, res = Integer.MAX_VALUE;
        for (int el: wall.get(0))
            sum += el;
        while (sum != 0) {
            int count = 0, mini = Integer.MAX_VALUE;
            for (int i = 0; i < wall.size(); i++) {
                List < Integer > row = wall.get(i);
                if (row.get(pos[i]) != 0) {
                    count++;
                } else
                    pos[i]++;
                mini = Math.min(mini, row.get(pos[i]));
            }
            for (int i = 0; i < wall.size(); i++) {
                List < Integer > row = wall.get(i);
                row.set(pos[i], row.get(pos[i]) - mini);
            }
            sum -= mini;
            res = Math.min(res, count);
        }
        return res;
    }
}
```

</details>

<br>

## Approach #3 Using HashMap [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int leastBricks(List < List < Integer >> wall) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        for (List < Integer > row: wall) {
            int sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row.get(i);
                if (map.containsKey(sum))
                    map.put(sum, map.get(sum) + 1);
                else
                    map.put(sum, 1);
            }
        }
        int res = wall.size();
        for (int key: map.keySet())
            res = Math.min(res, wall.size() - map.get(key));
        return res;
    }
}
```

</details>
