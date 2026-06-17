# 2849. Determine if a Cell Is Reachable at a Given Time

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/)  
`Math`

**Problem Link:** [LeetCode 2849 - Determine if a Cell Is Reachable at a Given Time](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/)

## Problem

You are given four integers sx, sy, fx, fy, and a non-negative integer t.

In an infinite 2D grid, you start at the cell (sx, sy). Each second, you must move to any of its adjacent cells.

Return true if you can reach cell (fx, fy) after exactly t seconds, or false otherwise.

A cell's adjacent cells are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.

### Example 1

```text
Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
Output: true
Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above.
```

### Example 2

```text
Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
Output: false
Explanation: Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.
```

## Constraints

- 1 <= sx, sy, fx, fy <= 109
- 0 <= t <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reaching Points](https://leetcode.com/problems/reaching-points/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2849. Determine if a Cell Is Reachable at a Given Time

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Math | C, C++, Java, JavaScript, Python3 |

## Approach: Math

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t){
    int width = abs(sx - fx);
    int height = abs(sy - fy);
    if (width == 0 && height == 0 && t == 1) {
        return false;
    }
    return t >= (width > height ? width : height);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = abs(sx - fx);
        int height = abs(sy - fy);
        if (width == 0 && height == 0 && t == 1) {
            return false;
        }
        return t >= max(width, height);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int width = Math.abs(sx - fx);
        int height = Math.abs(sy - fy);
        if (width == 0 && height == 0 && t == 1) {
            return false;
        }
        return t >= Math.max(width, height);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    var width = Math.abs(sx - fx);
    var height = Math.abs(sy - fy);
    if (width === 0 && height === 0 && t === 1) {
        return false;
    }
    return t >= Math.max(width, height);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        width = abs(sx - fx)
        height = abs(sy - fy)
        if width == 0 and height == 0 and t == 1:
            return False
        return t >= max(width, height)
```

</details>
