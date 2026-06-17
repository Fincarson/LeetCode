# 184. Department Highest Salary

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/department-highest-salary/)  
`Database`

**Problem Link:** [LeetCode 184 - Department Highest Salary](https://leetcode.com/problems/department-highest-salary/)

## Problem

Table: Employee

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key (column with unique values) for this table.
departmentId is a foreign key (reference columns) of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
```

Table: Department

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table. It is guaranteed that department name is not NULL.
Each row of this table indicates the ID of a department and its name.
```

Write a solution to find employees who have the highest salary in each of the departments.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
Department table:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
Output:
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
| IT         | Max      | 90000  |
+------------+----------+--------+
Explanation: Max and Jim both have the highest salary in the IT department and Henry has the highest salary in the Sales department.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Highest Grade For Each Student](https://leetcode.com/problems/highest-grade-for-each-student/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 184. Department Highest Salary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Left Join | Pandas |
| Approach: `Left Join` and `WHERE` Clause | SQL |

## Approach: Left Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    # Merge tables and rename
    df = employee.merge(department, left_on='departmentId', right_on='id', how='left')
    df.rename(columns={'name_x': 'Employee', 'name_y': 'Department', 'salary': 'Salary'}, inplace=True)
    
    # Select employees whose salary is equal to the department highest salary
    max_salary = df.groupby('Department')['Salary'].transform('max')
    df = df[df['Salary'] == max_salary]
    
    return df[['Department', 'Employee', 'Salary']]
```

</details>

<br>

## Approach: `Left Join` and `WHERE` Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    DepartmentId, MAX(Salary)
FROM
    Employee
GROUP BY DepartmentId;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
    )
;
```

</details>
