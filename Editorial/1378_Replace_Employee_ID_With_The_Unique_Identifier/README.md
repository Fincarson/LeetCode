# 1378. Replace Employee ID With The Unique Identifier

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/)  
`Database`

**Problem Link:** [LeetCode 1378 - Replace Employee ID With The Unique Identifier](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/)

## Problem

Table: Employees

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the id and the name of an employee in a company.
```

Table: EmployeeUNI

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| unique_id     | int     |
+---------------+---------+
(id, unique_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the id and the corresponding unique id of an employee in the company.
```

Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employees table:
+----+----------+
| id | name     |
+----+----------+
| 1  | Alice    |
| 7  | Bob      |
| 11 | Meir     |
| 90 | Winston  |
| 3  | Jonathan |
+----+----------+
EmployeeUNI table:
+----+-----------+
| id | unique_id |
+----+-----------+
| 3  | 1         |
| 11 | 2         |
| 90 | 3         |
+----+-----------+
Output:
+-----------+----------+
| unique_id | name     |
+-----------+----------+
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
+-----------+----------+
Explanation:
Alice and Bob do not have a unique ID, We will show null instead.
The unique ID of Meir is 2.
The unique ID of Winston is 3.
The unique ID of Jonathan is 1.
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

# Editorial - 1378. Replace Employee ID With The Unique Identifier

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Left Join on ID | Pandas |
| Approach: Left Join on ID | SQL |

## Approach: Left Join on ID

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    employee_name_uni = pd.merge(employees, employee_uni, on='id', how='left')
    answer = employee_name_uni[['unique_id', 'name']]

    return answer
```

</details>

<br>

## Approach: Left Join on ID

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    * 
FROM
    Employees 
LEFT JOIN 
    EmployeeUNI 
ON 
    Employees.id = EmployeeUNI.id;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    EmployeeUNI.unique_id, Employees.name
FROM 
    Employees
LEFT JOIN 
    EmployeeUNI 
ON 
    Employees.id = EmployeeUNI.id;
```

</details>
