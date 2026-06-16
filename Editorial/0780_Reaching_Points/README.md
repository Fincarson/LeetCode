# 780. Reaching Points

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/reaching-points/)  
`Math`

**Problem Link:** [LeetCode 780 - Reaching Points](https://leetcode.com/problems/reaching-points/)

## Problem

Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.

The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).

### Example 1

```text
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: true
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
```

### Example 2

```text
Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: false
```

### Example 3

```text
Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: true
```

## Constraints

- 1 <= sx, sy, tx, ty <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check if Point Is Reachable](https://leetcode.com/problems/check-if-point-is-reachable/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Determine if a Cell Is Reachable at a Given Time](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 780. Reaching Points

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Exhaustive Search [Time Limit Exceeded] | Java, Python |
| Approach #2: Dynamic Programming [Time Limit Exceeded] | Java, Python |
| Approach #3: Work Backwards (Naive Variant) [Time Limit Exceeded] | Java, Python |
| Approach #4: Work Backwards (Modulo Variant) [Accepted] | Java, Python |

## Approach #1: Exhaustive Search [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) return false;
        if (sx == tx && sy == ty) return true;
        return reachingPoints(sx+sy, sy, tx, ty) || reachingPoints(sx, sx+sy, tx, ty);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        if sx > tx or sy > ty: return False
        if sx == tx and sy == ty: return True
        return self.reachingPoints(sx+sy, sy, tx, ty) or \
               self.reachingPoints(sx, sx+sy, tx, ty)
```

</details>

<br>

## Approach #2: Dynamic Programming [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.awt.Point;

class Solution {
    Set<Point> seen;
    int tx, ty;

    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        seen = new HashSet();
        this.tx = tx;
        this.ty = ty;
        search(new Point(sx, sy));
        return seen.contains(new Point(tx, ty));
    }

    public void search(Point P) {
        if (seen.contains(P)) return;
        if (P.x > tx || P.y > ty) return;
        seen.add(P);
        search(new Point(P.x + P.y, P.y));
        search(new Point(P.x, P.x + P.y));
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        seen = set()
        def search(x, y):
            if (x, y) in seen: return
            if x > tx or y > ty: return
            seen.add((x, y))
            search(x+y, y)
            search(x, x+y)

        search(sx, sy)
        return (tx, ty) in seen
```

</details>

<br>

## Approach #3: Work Backwards (Naive Variant) [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sx == tx && sy == ty)
                return true;
            if (tx > ty) tx -= ty;
            else ty -= tx;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx >= sx and ty >= sy:
            if sx == tx and sy == ty: return True
            if tx > ty:
                tx -= ty
            else:
                ty -= tx
        return False
```

</details>

<br>

## Approach #4: Work Backwards (Modulo Variant) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == ty) break;
            if (tx > ty) {
                if (ty > sy) tx %= ty;
                else return (tx - sx) % ty == 0;
            } else {
                if (tx > sx) ty %= tx;
                else return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx >= sx and ty >= sy:
            if tx == ty:
                break
            elif tx > ty:
                if ty > sy:
                    tx %= ty
                else:
                    return (tx - sx) % ty == 0
            else:
                if tx > sx:
                    ty %= tx
                else:
                    return (ty - sy) % tx == 0

        return tx == sx and ty == sy
```

</details>
