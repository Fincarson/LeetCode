# 2356. Number of Unique Subjects Taught by Each Teacher

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/)  
`Database`

**Problem Link:** [LeetCode 2356 - Number of Unique Subjects Taught by Each Teacher](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/)

## Problem

Table: Teacher

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| teacher_id  | int  |
| subject_id  | int  |
| dept_id     | int  |
+-------------+------+
(subject_id, dept_id) is the primary key (combinations of columns with unique values) of this table.
Each row in this table indicates that the teacher with teacher_id teaches the subject subject_id in the department dept_id.
```

Write a solution to calculate the number of unique subjects each teacher teaches in the university.

Return the result table in any order.

The result format is shown in the following example.

### Example 1

```text
Input:
Teacher table:
+------------+------------+---------+
| teacher_id | subject_id | dept_id |
+------------+------------+---------+
| 1          | 2          | 3       |
| 1          | 2          | 4       |
| 1          | 3          | 3       |
| 2          | 1          | 1       |
| 2          | 2          | 1       |
| 2          | 3          | 1       |
| 2          | 4          | 1       |
+------------+------------+---------+
Output:
+------------+-----+
| teacher_id | cnt |
+------------+-----+
| 1          | 2   |
| 2          | 4   |
+------------+-----+
Explanation:
Teacher 1:
  - They teach subject 2 in departments 3 and 4.
  - They teach subject 3 in department 3.
Teacher 2:
  - They teach subject 1 in department 1.
  - They teach subject 2 in department 1.
  - They teach subject 3 in department 1.
  - They teach subject 4 in department 1.
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

# Editorial - 2356. Number of Unique Subjects Taught by Each Teacher

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group By and Count Distinct | Pandas |
| Approach: Group By and Count Distinct | SQL |

## Approach: Group By and Count Distinct

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    df = teacher.groupby(["teacher_id"])["subject_id"].nunique().reset_index()
    df = df.rename({'subject_id': "cnt"}, axis=1)
    return df
```

</details>

<br>

## Approach: Group By and Count Distinct

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;
```

</details>
