# 836. Rectangle Overlap

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rectangle-overlap/)  
`Math` `Geometry`

**Problem Link:** [LeetCode 836 - Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

## Problem

An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

### Example 1

```text
Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
```

### Example 2

```text
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
```

### Example 3

```text
Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false
```

## Constraints

- rec1.length == 4
- rec2.length == 4
- -109 <= rec1[i], rec2[i] <= 109
- rec1 and rec2 represent a valid rectangle with a non-zero area.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rectangle Area](https://leetcode.com/problems/rectangle-area/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 836. Rectangle Overlap

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Check Position [Accepted] | Java, Python |
| Approach #2: Check Area [Accepted] | Java, Python |

## Approach #1: Check Position [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // check if either rectangle is actually a line
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            // the line cannot have positive overlap
            return false;
        }

        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        # check if either rectangle is actually a line
        if (rec1[0] == rec1[2] or rec1[1] == rec1[3] or \
            rec2[0] == rec2[2] or rec2[1] == rec2[3]):
            # the line cannot have positive overlap
            return False

        return not (rec1[2] <= rec2[0] or  # left
                    rec1[3] <= rec2[1] or  # bottom
                    rec1[0] >= rec2[2] or  # right
                    rec1[1] >= rec2[3])    # top
```

</details>

<br>

## Approach #2: Check Area [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return (Math.min(rec1[2], rec2[2]) > Math.max(rec1[0], rec2[0]) && // width > 0
                Math.min(rec1[3], rec2[3]) > Math.max(rec1[1], rec2[1]));  // height > 0
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        def intersect(p_left, p_right, q_left, q_right):
            return min(p_right, q_right) > max(p_left, q_left)
        return (intersect(rec1[0], rec1[2], rec2[0], rec2[2]) and # width > 0
                intersect(rec1[1], rec1[3], rec2[1], rec2[3]))    # height > 0
```

</details>
