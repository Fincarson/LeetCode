# 1112. Highest Grade For Each Student

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/highest-grade-for-each-student/)  
`Database`

**Problem Link:** [LeetCode 1112 - Highest Grade For Each Student](https://leetcode.com/problems/highest-grade-for-each-student/)

## Problem

Table: Enrollments

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| course_id     | int     |
| grade         | int     |
+---------------+---------+
(student_id, course_id) is the primary key (combination of columns with unique values) of this table.
grade is never NULL.
```

Write a solution to find the highest grade with its corresponding course for each student. In case of a tie, you should find the course with the smallest course_id.

Return the result table ordered by student_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Enrollments table:
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 2          | 2         | 95    |
| 2          | 3         | 95    |
| 1          | 1         | 90    |
| 1          | 2         | 99    |
| 3          | 1         | 80    |
| 3          | 2         | 75    |
| 3          | 3         | 82    |
+------------+-----------+-------+
Output:
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 1          | 2         | 99    |
| 2          | 2         | 95    |
| 3          | 3         | 82    |
+------------+-----------+-------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Department Highest Salary](https://leetcode.com/problems/department-highest-salary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1112. Highest Grade For Each Student

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prioritized Ranking with Grouping | Python3, Pandas |
| Max Grade Extraction with Join | Python3, Pandas |
| Transform & Filter with Aggregation | Python3, Pandas |
| Window Function | SQL |
| Aggregation & Self-Join | SQL |
| Subquery with Aggregation | SQL |

## Approach 1: Prioritized Ranking with Grouping

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
sorted_df = enrollments.sort_values(
    by=["student_id", "grade", "course_id"], ascending=[True, False, True]
)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
result = sorted_df.groupby("student_id").head(1).reset_index(drop=True)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    sorted_df = enrollments.sort_values(
        by=["student_id", "grade", "course_id"], ascending=[True, False, True]
    )
    result = sorted_df.groupby("student_id").head(1).reset_index(drop=True)
    return result
```

</details>

<br>

## Approach 2: Max Grade Extraction with Join

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
max_grades = enrollments.groupby("student_id")["grade"].max().reset_index()
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
merged = pd.merge(enrollments, max_grades, on=["student_id", "grade"])
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
result = (
    merged.groupby("student_id")
    .apply(lambda x: x.nsmallest(1, "course_id"))
    .reset_index(drop=True)
)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd


def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    max_grades = enrollments.groupby("student_id")["grade"].max().reset_index()
    merged = pd.merge(enrollments, max_grades, on=["student_id", "grade"])
    result = (
        merged.groupby("student_id")
        .apply(lambda x: x.nsmallest(1, "course_id"))
        .reset_index(drop=True)
    )
    return result[["student_id", "course_id", "grade"]]
```

</details>

<br>

## Approach 3: Transform & Filter with Aggregation

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
max_grades = enrollments.groupby("student_id")["grade"].transform("max")
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
filtered = enrollments[enrollments["grade"] == max_grades]
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
result = (
    filtered.groupby("student_id")
    .apply(lambda group: group.nsmallest(1, "course_id"))
    .reset_index(drop=True)
)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd


def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    max_grades = enrollments.groupby("student_id")["grade"].transform("max")
    filtered = enrollments[enrollments["grade"] == max_grades]
    result = (
        filtered.groupby("student_id")
        .apply(lambda group: group.nsmallest(1, "course_id"))
        .reset_index(drop=True)
    )
    return result[["student_id", "course_id", "grade"]]
```

</details>

<br>

## Approach 1: Window Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  student_id, 
  course_id, 
  grade 
FROM 
  (
    SELECT 
      student_id, 
      course_id, 
      grade, 
      DENSE_RANK() OVER (
        PARTITION BY student_id 
        ORDER BY 
          grade DESC, 
          course_id ASC
      ) AS rnk 
    FROM 
      Enrollments
  ) AS ranked 
WHERE 
  rnk = 1 
ORDER BY 
  student_id;
```

</details>

<br>

## Approach 2: Aggregation & Self-Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  e1.student_id, 
  MIN(e1.course_id) AS course_id, 
  e1.grade 
FROM 
  Enrollments e1 
  JOIN (
    SELECT 
      student_id, 
      MAX(grade) AS max_grade 
    FROM 
      Enrollments 
    GROUP BY 
      student_id
  ) e2 ON e1.student_id = e2.student_id 
  AND e1.grade = e2.max_grade 
GROUP BY 
  e1.student_id, 
  e1.grade 
ORDER BY 
  e1.student_id;
```

</details>

<br>

## Approach 3: Subquery with Aggregation

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  student_id, 
  MIN(course_id) AS course_id, 
  grade 
FROM 
  Enrollments 
WHERE 
  (student_id, grade) IN (
    SELECT 
      student_id, 
      MAX(grade) 
    FROM 
      Enrollments 
    GROUP BY 
      student_id
  ) 
GROUP BY 
  student_id, 
  grade 
ORDER BY 
  student_id;
```

</details>
