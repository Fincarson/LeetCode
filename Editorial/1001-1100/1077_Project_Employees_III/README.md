# 1077. Project Employees III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/project-employees-iii/)  
`Database`

**Problem Link:** [LeetCode 1077 - Project Employees III](https://leetcode.com/problems/project-employees-iii/)

## Problem

Table: Project

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key (combination of columns with unique values) of this table.
employee_id is a foreign key (reference column) to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
```

Table: Employee

```text
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id is the primary key (column with unique values) of this table.
Each row of this table contains information about one employee.
```

Write a solution to report the most experienced employees in each project. In case of a tie, report all employees with the maximum number of experience years.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Project table:
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+
Employee table:
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 3                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+
Output:
+-------------+---------------+
| project_id  | employee_id   |
+-------------+---------------+
| 1           | 1             |
| 1           | 3             |
| 2           | 1             |
+-------------+---------------+
Explanation: Both employees with id 1 and 3 have the most experience among the employees of the first project. For the second project, the employee with id 1 has the most experience.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Project Employees II](https://leetcode.com/problems/project-employees-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1077. Project Employees III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using max() and then merge to filter | Pandas |
| Using Window Functions | SQL |

## Approach: Using max() and then merge to filter

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def project_employees(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:

    project_and_employee = project.merge(employee, on = 'employee_id')

    only_max = project_and_employee.groupby(['project_id'], as_index = False)['experience_years'].max()

    df = project_and_employee.merge(only_max, on = ['project_id', 'experience_years'])[['project_id', 'employee_id']]

    return df
```

</details>

<br>

## Approach 2: Using Window Functions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT p.project_id, 
       p.employee_id, 
       RANK()OVER(PARTITION BY project_id ORDER BY experience_years DESC) AS rnk
FROM Project p
JOIN Employee e
ON p.employee_id = e.employee_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT project_id, employee_id
FROM (
    SELECT p.project_id, 
           p.employee_id, 
           RANK()OVER(PARTITION BY project_id ORDER BY experience_years DESC) AS rnk
    FROM Project p
    JOIN Employee e
    ON p.employee_id = e.employee_id
)a
WHERE rnk = 1
```

</details>
