# 613. Shortest Distance in a Line

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/shortest-distance-in-a-line/)  
`Database`

**Problem Link:** [LeetCode 613 - Shortest Distance in a Line](https://leetcode.com/problems/shortest-distance-in-a-line/)

## Problem

Table: Point

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
+-------------+------+
In SQL, x is the primary key column for this table.
Each row of this table indicates the position of a point on the X-axis.
```

Find the shortest distance between any two points from the Point table.

The result format is in the following example.

### Example 1

```text
Input:
Point table:
+----+
| x  |
+----+
| -1 |
| 0  |
| 2  |
+----+
Output:
+----------+
| shortest |
+----------+
| 1        |
+----------+
Explanation: The shortest distance is between points -1 and 0 which is |(-1) - 0| = 1.
```

Follow up: How could you optimize your solution if the Point table is ordered in ascending order?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 613. Shortest Distance in a Line

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using `ABS()` and `MIN()` functions [Accepted] | SQL |

## Approach: Using `ABS()` and `MIN()` functions [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    p1.x, p2.x, ABS(p1.x - p2.x) AS distance
FROM
    point p1
        JOIN
    point p2 ON p1.x != p2.x
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    MIN(ABS(p1.x - p2.x)) AS shortest
FROM
    point p1
        JOIN
    point p2 ON p1.x != p2.x
;
```

</details>
