# 181. Employees Earning More Than Their Managers

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/employees-earning-more-than-their-managers/)  
`Database`

**Problem Link:** [LeetCode 181 - Employees Earning More Than Their Managers](https://leetcode.com/problems/employees-earning-more-than-their-managers/)

## Problem

Table: Employee

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.
```

Write a solution to find the employees who earn more than their managers.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
Output:
+----------+
| Employee |
+----------+
| Joe      |
+----------+
Explanation: Joe is the only employee who earns more than his manager.
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

# Editorial - 181. Employees Earning More Than Their Managers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Self-Merge with an Inner Join | Pandas |
| Using `WHERE` clause | SQL |
| Using `JOIN` clause | SQL |

## Approach 1: Self-Merge with an Inner Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(employee, left_on = 'managerId', right_on = 'id',
            suffixes = ['_e', '_m'], how = 'inner')

    df = df.loc[df['salary_e'] > df['salary_m'] , ['name_e']]
    return df.rename(columns = {'name_e':'Employee'})
```

</details>

<br>

## Approach 1: Using `WHERE` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT *
FROM Employee AS a, Employee AS b
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    *
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
        AND a.Salary > b.Salary
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    a.Name AS 'Employee'
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
        AND a.Salary > b.Salary
;
```

</details>

<br>

## Approach 2: Using `JOIN` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
;
```

</details>
