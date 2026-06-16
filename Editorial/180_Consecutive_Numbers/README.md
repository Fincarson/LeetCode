# 180. Consecutive Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/consecutive-numbers/)  
`Database`

**Problem Link:** [LeetCode 180 - Consecutive Numbers](https://leetcode.com/problems/consecutive-numbers/)

## Problem

Table: Logs

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column starting from 1.
```

Find all numbers that appear at least three times consecutively.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output:
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
Explanation: 1 is the only number that appears consecutively for at least three times.
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

# Editorial - 180. Consecutive Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using `DISTINCT` and `WHERE` clause [Accepted] | SQL |

## Approach: Using `DISTINCT` and `WHERE` clause [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT *
FROM
    Logs l1,
    Logs l2,
    Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
    l1.Num AS ConsecutiveNums
FROM
    Logs l1,
    Logs l2,
    Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num
;
```

</details>
