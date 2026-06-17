# 626. Exchange Seats

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/exchange-seats/)  
`Database`

**Problem Link:** [LeetCode 626 - Exchange Seats](https://leetcode.com/problems/exchange-seats/)

## Problem

Table: Seat

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
The ID sequence always starts from 1 and increments continuously.
```

Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.

Return the result table ordered by id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
Output:
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
Explanation:
Note that if the number of students is odd, there is no need to change the last one's seat.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 626. Exchange Seats

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach I: Using flow control statement `CASE` [Accepted] | SQL |
| Approach II: Using bit manipulation and `COALESCE()` [Accepted] | SQL |

## Approach I: Using flow control statement `CASE` [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    COUNT(*) AS counts
FROM
    seat
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    (CASE
        WHEN MOD(id, 2) != 0 AND counts != id THEN id + 1
        WHEN MOD(id, 2) != 0 AND counts = id THEN id
        ELSE id - 1
    END) AS id,
    student
FROM
    seat,
    (SELECT
        COUNT(*) AS counts
    FROM
        seat) AS seat_counts
ORDER BY id ASC;
```

</details>

<br>

## Approach II: Using bit manipulation and `COALESCE()` [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT id, (id+1)^1-1, student FROM seat;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    *
FROM
    seat s1
        LEFT JOIN
    seat s2 ON (s1.id+1)^1-1 = s2.id
ORDER BY s1.id;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    s1.id, COALESCE(s2.student, s1.student) AS student
FROM
    seat s1
        LEFT JOIN
    seat s2 ON ((s1.id + 1) ^ 1) - 1 = s2.id
ORDER BY s1.id;
```

</details>
