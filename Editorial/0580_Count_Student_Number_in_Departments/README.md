# 580. Count Student Number in Departments

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-student-number-in-departments/)  
`Database`

**Problem Link:** [LeetCode 580 - Count Student Number in Departments](https://leetcode.com/problems/count-student-number-in-departments/)

## Problem

Table: Student

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| student_name | varchar |
| gender       | varchar |
| dept_id      | int     |
+--------------+---------+
student_id is the primary key (column with unique values) for this table.
dept_id is a foreign key (reference column) to dept_id in the Department tables.
Each row of this table indicates the name of a student, their gender, and the id of their department.
```

Table: Department

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| dept_id     | int     |
| dept_name   | varchar |
+-------------+---------+
dept_id is the primary key (column with unique values) for this table.
Each row of this table contains the id and the name of a department.
```

Write a solution to report the respective department name and number of students majoring in each department for all departments in the Department table (even ones with no current students).

Return the result table ordered by student_number in descending order. In case of a tie, order them by dept_name alphabetically.

The result format is in the following example.

### Example 1

```text
Input:
Student table:
+------------+--------------+--------+---------+
| student_id | student_name | gender | dept_id |
+------------+--------------+--------+---------+
| 1          | Jack         | M      | 1       |
| 2          | Jane         | F      | 1       |
| 3          | Mark         | M      | 2       |
+------------+--------------+--------+---------+
Department table:
+---------+-------------+
| dept_id | dept_name   |
+---------+-------------+
| 1       | Engineering |
| 2       | Science     |
| 3       | Law         |
+---------+-------------+
Output:
+-------------+----------------+
| dept_name   | student_number |
+-------------+----------------+
| Engineering | 2              |
| Science     | 1              |
| Law         | 0              |
+-------------+----------------+
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

# Editorial - 580. Count Student Number in Departments

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using `OUTER JOIN` and `COUNT(expression)` [Accepted] | SQL |

## Approach: Using `OUTER JOIN` and `COUNT(expression)` [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    dept_name, COUNT(*) AS student_number
FROM
    department
        LEFT OUTER JOIN
    student ON department.dept_id = student.dept_id
GROUP BY department.dept_name
ORDER BY student_number DESC , department.dept_name
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    dept_name, COUNT(student_id) AS student_number
FROM
    department
        LEFT OUTER JOIN
    student ON department.dept_id = student.dept_id
GROUP BY department.dept_name
ORDER BY student_number DESC , department.dept_name
;
```

</details>
