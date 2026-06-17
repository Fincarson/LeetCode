# 618. Students Report By Geography

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/students-report-by-geography/)  
`Database`

**Problem Link:** [LeetCode 618 - Students Report By Geography](https://leetcode.com/problems/students-report-by-geography/)

## Problem

Table: Student

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
+-------------+---------+
This table may contain duplicate rows.
Each row of this table indicates the name of a student and the continent they came from.
```

A school has students from Asia, Europe, and America.

Write a solution to pivot the continent column in the Student table so that each name is sorted alphabetically and displayed underneath its corresponding continent. The output headers should be America, Asia, and Europe, respectively.

The test cases are generated so that the student number from America is not less than either Asia or Europe.

The result format is in the following example.

### Example 1

```text
Input:
Student table:
+--------+-----------+
| name   | continent |
+--------+-----------+
| Jane   | America   |
| Pascal | Europe    |
| Xi     | Asia      |
| Jack   | America   |
+--------+-----------+
Output:
+---------+------+--------+
| America | Asia | Europe |
+---------+------+--------+
| Jack    | Xi   | Pascal |
| Jane    | null | null   |
+---------+------+--------+
```

Follow up: If it is unknown which continent has the most students, could you write a solution to generate the student report?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 618. Students Report By Geography

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using "session variables" and `join` [Accepted] | SQL |

## Approach: Using "session variables" and `join` [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    row_id, America
FROM
    (SELECT @am:=0) t,
    (SELECT 
        @am:=@am + 1 AS row_id, name AS America
    FROM
        student
    WHERE
        continent = 'America'
    ORDER BY America) AS t2
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    America, Asia, Europe
FROM
    (SELECT @as:=0, @am:=0, @eu:=0) t,
    (SELECT 
        @as:=@as + 1 AS asid, name AS Asia
    FROM
        student
    WHERE
        continent = 'Asia'
    ORDER BY Asia) AS t1
        RIGHT JOIN
    (SELECT 
        @am:=@am + 1 AS amid, name AS America
    FROM
        student
    WHERE
        continent = 'America'
    ORDER BY America) AS t2 ON asid = amid
        LEFT JOIN
    (SELECT 
        @eu:=@eu + 1 AS euid, name AS Europe
    FROM
        student
    WHERE
        continent = 'Europe'
    ORDER BY Europe) AS t3 ON amid = euid
;
```

</details>
