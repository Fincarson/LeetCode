# 596. Classes With at Least 5 Students

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/classes-with-at-least-5-students/)  
`Database`

**Problem Link:** [LeetCode 596 - Classes With at Least 5 Students](https://leetcode.com/problems/classes-with-at-least-5-students/)

## Problem

Table: Courses

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the name of a student and the class in which they are enrolled.
```

Write a solution to find all the classes that have at least five students.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Courses table:
+---------+----------+
| student | class    |
+---------+----------+
| A       | Math     |
| B       | English  |
| C       | Math     |
| D       | Biology  |
| E       | Math     |
| F       | Computer |
| G       | Math     |
| H       | Math     |
| I       | Math     |
+---------+----------+
Output:
+---------+
| class   |
+---------+
| Math    |
+---------+
Explanation:
- Math has 6 students, so we include it.
- English has 1 student, so we do not include it.
- Biology has 1 student, so we do not include it.
- Computer has 1 student, so we do not include it.
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

# Editorial - 596. Classes With at Least 5 Students

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group By | Pandas |
| Approach: Group By | SQL |
| Using `GROUP BY` and `HAVING` condition | SQL |

## Approach: Group By

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    df = courses.groupby('class').size().reset_index(name='count')

    df = df[df['count'] >= 5]

    return df[['class']]
```

</details>

<br>

## Approach: Group By

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    class, COUNT(student)
FROM
    courses
GROUP BY class
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    class
FROM
    (SELECT
        class, COUNT(student) AS num
    FROM
        courses
    GROUP BY class) AS temp_table
WHERE
    num >= 5
;
```

</details>

<br>

## Approach 2: Using `GROUP BY` and `HAVING` condition

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    class
FROM
    courses
GROUP BY class
HAVING COUNT(student) >= 5
;
```

</details>
