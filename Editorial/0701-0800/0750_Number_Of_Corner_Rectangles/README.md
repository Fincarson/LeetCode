# 750. Number Of Corner Rectangles

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-corner-rectangles/)  
`Array` `Math` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 750 - Number Of Corner Rectangles](https://leetcode.com/problems/number-of-corner-rectangles/)

## Problem

Given an m x n integer matrix grid where each entry is only 0 or 1, return the number of corner rectangles.

A corner rectangle is four distinct 1's on the grid that forms an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1's used must be distinct.

### Example 1

```text
Input: grid = [[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
```

### Example 2

```text
Input: grid = [[1,1,1],[1,1,1],[1,1,1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
```

### Example 3

```text
Input: grid = [[1,1,1,1]]
Output: 0
Explanation: Rectangles must have four distinct corners.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 200
- grid[i][j] is either 0 or 1.
- The number of 1's in the grid is in the range [1, 6000].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 750. Number Of Corner Rectangles

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Count Corners [Accepted] | Java, Python |
| Approach #2: Heavy and Light Rows [Accepted] | Java, Python |

## Approach #1: Count Corners [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countCornerRectangles(int[][] grid) {
        Map<Integer, Integer> count = new HashMap();
        int ans = 0;
        for (int[] row: grid) {
            for (int c1 = 0; c1 < row.length; ++c1) if (row[c1] == 1) {
                for (int c2 = c1+1; c2 < row.length; ++c2) if (row[c2] == 1) {
                    int pos = c1 * 200 + c2;
                    int c = count.getOrDefault(pos, 0);
                    ans += c;
                    count.put(pos, c+1);
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def countCornerRectangles(self, grid):
        count = collections.Counter()
        ans = 0
        for row in grid:
            for c1, v1 in enumerate(row):
                if v1:
                    for c2 in xrange(c1+1, len(row)):
                        if row[c2]:
                            ans += count[c1, c2]
                            count[c1, c2] += 1
        return ans
```

</details>

<br>

## Approach #2: Heavy and Light Rows [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countCornerRectangles(int[][] grid) {
        List<List<Integer>> rows = new ArrayList();
        int N = 0;
        for (int r = 0; r < grid.length; ++r) {
            rows.add(new ArrayList());
            for (int c = 0; c < grid[r].length; ++c)
                if (grid[r][c] == 1) {
                    rows.get(r).add(c);
                    N++;
                }
        }

        int sqrtN = (int) Math.sqrt(N);
        int ans = 0;
        Map<Integer, Integer> count = new HashMap();

        for (int r = 0; r < grid.length; ++r) {
            if (rows.get(r).size() >= sqrtN) {
                Set<Integer> target = new HashSet(rows.get(r));

                for (int r2 = 0; r2 < grid.length; ++r2) {
                    if (r2 <= r && rows.get(r2).size() >= sqrt) {
                        continue;
                    }
                    int found = 0;
                    for (int c2: rows.get(r2)) {
                        if (target.contains(c2)) {
                            found++;
                        }
                    }
                    ans += found * (found - 1) / 2;
                }
            } else {
                for (int i1 = 0; i1 < rows.get(r).size(); ++i1) {
                    int c1 = rows.get(r).get(i1);
                    for (int i2 = i1 + 1; i2 < rows.get(r).size(); ++i2) {
                        int c2 = rows.get(r).get(i2);
                        int ct = count.getOrDefault(200*c1 + c2, 0);
                        ans += ct;
                        count.put(200*c1 + c2, ct + 1);
                    }
                }
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def countCornerRectangles(self, grid):
        rows = [[c for c, val in enumerate(row) if val]
                for row in grid]
        N = sum(len(row) for row in grid)
        SQRTN = int(N**.5)

        ans = 0
        count = collections.Counter()
        for r, row in enumerate(rows):
            if len(row) >= SQRTN:
                target = set(row)
                for r2, row2 in enumerate(rows):
                    if r2 <= r and len(row2) >= SQRTN:
                        continue
                    found = sum(1 for c2 in row2 if c2 in target)
                    ans += found * (found - 1) / 2
            else:
                for pair in itertools.combinations(row, 2):
                    ans += count[pair]
                    count[pair] += 1

        return ans
```

</details>
