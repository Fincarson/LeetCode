# 570. Managers with at Least 5 Direct Reports

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)  
`Database`

**Problem Link:** [LeetCode 570 - Managers with at Least 5 Direct Reports](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)

## Problem

Table: Employee

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
```

Write a solution to find managers with at least five direct reports.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output:
+------+
| name |
+------+
| John |
+------+
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

# Editorial - 570. Managers with at Least 5 Direct Reports

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group By and Join | Pandas |
| Approach: Group By and Join | SQL |
| `IN` Clause with Subquery | SQL |

## Approach: Group By and Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.groupby('managerId').size().reset_index(name='count')
    df = df[df['count'] >= 5]
    managers_info = pd.merge(df, employee, left_on='managerId', right_on='id', how='inner')
    return managers_info[['name']]
```

</details>

<br>

## Approach: Group By and Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    ManagerId
FROM 
    Employee
GROUP BY ManagerId
HAVING COUNT(ManagerId) >= 5
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    Name
FROM
    Employee AS t1 
JOIN
    (SELECT 
        ManagerId
    FROM 
        Employee
    GROUP BY ManagerId
    HAVING COUNT(ManagerId) >= 5) AS t2
ON 
    t1.Id = t2.ManagerId
;
```

</details>

<br>

## Approach 2: `IN` Clause with Subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    ManagerId
FROM 
    Employee
GROUP BY ManagerId
HAVING COUNT(ManagerId) >= 5
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    name
FROM
    employee
WHERE
    id IN (
        SELECT
            managerId
        FROM
            employee
        GROUP BY
            managerId
        HAVING COUNT(*) >= 5
    );
```

</details>
