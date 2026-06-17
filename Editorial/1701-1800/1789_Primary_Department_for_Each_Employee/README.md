# 1789. Primary Department for Each Employee

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/primary-department-for-each-employee/)  
`Database`

**Problem Link:** [LeetCode 1789 - Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/)

## Problem

Table: Employee

```text
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
(employee_id, department_id) is the primary key (combination of columns with unique values) for this table.
employee_id is the id of the employee.
department_id is the id of the department to which the employee belongs.
primary_flag is an ENUM (category) of type ('Y', 'N'). If the flag is 'Y', the department is the primary department for the employee. If the flag is 'N', the department is not the primary.
```

Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is 'N'.

Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
Output:
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
Explanation:
- The Primary department for employee 1 is 1.
- The Primary department for employee 2 is 1.
- The Primary department for employee 3 is 3.
- The Primary department for employee 4 is 3.
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

# Editorial - 1789. Primary Department for Each Employee

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Conditional Filtering and Aggregation-based Union | Python3, Pandas |
| Group-based Transform and Conditional Filtering | Pandas |
| `UNION` | SQL |
| Window Function (`COUNT`) | SQL |

## Approach 1: Conditional Filtering and Aggregation-based Union

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
 filtered_by_flag = employee[employee['primary_flag'] == 'Y'][['employee_id', 'department_id']]
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
unique_employees = employee.groupby('employee_id').filter(lambda x: len(x) == 1)[['employee_id', 'department_id']]
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
result = pd.concat([filtered_by_flag, unique_employees]).drop_duplicates().reset_index(drop=True)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
return result
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. Employees with primary_flag set to 'Y'
    filtered_by_flag = employee[employee['primary_flag'] == 'Y'][['employee_id', 'department_id']]

    # 2. Employees that appear exactly once in the Employee table
    unique_employees = employee.groupby('employee_id').filter(lambda x: len(x) == 1)[['employee_id', 'department_id']]

    # 3. Combine both DataFrames using concat and drop duplicates
    result = pd.concat([filtered_by_flag, unique_employees]).drop_duplicates().reset_index(drop=True)
    
    #4. Return result
    return result
```

</details>

<br>

## Approach 2: Group-based Transform and Conditional Filtering

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. Calculate EmployeeCount as the number of rows for each employee_id
    employee["EmployeeCount"] = employee.groupby("employee_id")[
        "employee_id"
    ].transform("size")

    # 2. Filter based on the EmployeeCount or primary_flag
    result = employee[
        (employee["EmployeeCount"] == 1) | (employee["primary_flag"] == "Y")
    ][["employee_id", "department_id"]]

    # 3. Return result
    return result
```

</details>

<br>

## Approach 1: `UNION`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
WHERE 
  primary_flag = 'Y'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
GROUP BY 
  employee_id 
HAVING 
  COUNT(employee_id) = 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
WHERE 
  primary_flag = 'Y' 
UNION 
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
GROUP BY 
  employee_id 
HAVING 
  COUNT(employee_id) = 1;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
-- Retrieving employees with primary_flag set to 'Y'
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
WHERE 
  primary_flag = 'Y' 
UNION 
-- Retrieving employees that appear exactly once in the Employee table
SELECT 
  employee_id, 
  department_id 
FROM 
  Employee 
GROUP BY 
  employee_id 
HAVING 
  COUNT(employee_id) = 1;
```

</details>

<br>

## Approach 2: Window Function (`COUNT`)

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  *, 
  COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount 
FROM 
  Employee
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  employee_id, 
  department_id 
FROM 
  EmployeePartition
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE 
  EmployeeCount = 1 
  OR primary_flag = 'Y'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  employee_id, 
  department_id 
FROM 
  (
    SELECT 
      *, 
      COUNT(employee_id) OVER(PARTITION BY employee_id) AS EmployeeCount
    FROM 
      Employee
  ) EmployeePartition 
WHERE 
  EmployeeCount = 1 
  OR primary_flag = 'Y';
```

</details>
