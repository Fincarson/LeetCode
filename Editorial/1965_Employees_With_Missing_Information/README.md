# 1965. Employees With Missing Information

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/employees-with-missing-information/)  
`Database`

**Problem Link:** [LeetCode 1965 - Employees With Missing Information](https://leetcode.com/problems/employees-with-missing-information/)

## Problem

Table: Employees

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
+-------------+---------+
employee_id is the column with unique values for this table.
Each row of this table indicates the name of the employee whose ID is employee_id.
```

Table: Salaries

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| salary      | int     |
+-------------+---------+
employee_id is the column with unique values for this table.
Each row of this table indicates the salary of the employee whose ID is employee_id.
```

Write a solution to report the IDs of all the employees with missing information. The information of an employee is missing if:

- The employee's name is missing, or
- The employee's salary is missing.

Return the result table ordered by employee_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Employees table:
+-------------+----------+
| employee_id | name     |
+-------------+----------+
| 2           | Crew     |
| 4           | Haven    |
| 5           | Kristian |
+-------------+----------+
Salaries table:
+-------------+--------+
| employee_id | salary |
+-------------+--------+
| 5           | 76071  |
| 1           | 22517  |
| 4           | 63539  |
+-------------+--------+
Output:
+-------------+
| employee_id |
+-------------+
| 1           |
| 2           |
+-------------+
Explanation:
Employees 1, 2, 4, and 5 are working at this company.
The name of employee 1 is missing.
The salary of employee 2 is missing.
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

# Editorial - 1965. Employees With Missing Information

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using `XOR` ("exclusive or") | Pandas |
| Using Outer Join | Pandas |
| Simulate Full Join via Unioning a Left and Right Join | SQL |
| `UNION` with `WHERE ... NOT IN` | SQL |

## Approach 1: Using `XOR` ("exclusive or")

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:

    return pd.DataFrame(
        {"employee_id": sorted(set(employees.employee_id) ^ set(salaries.employee_id))}
    )
```

</details>

<br>

## Approach 2: Using Outer Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:
    # Merge the employees and salaries DataFrames on 'employee_id', including all records from both.
    merged_df = pd.merge(employees, salaries, on="employee_id", how="outer")

    # Identify rows with missing values in any column.
    missing_data_df = merged_df[merged_df.isna().any(axis=1)]

    # Select only the 'employee_id' column and sort the IDs.
    result_df = missing_data_df[["employee_id"]].sort_values(by="employee_id")

    return result_df
```

</details>

<br>

## Approach 1: Simulate Full Join via Unioning a Left and Right Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   WHERE T.salary IS NULL OR T.name IS NULL
```

</details>

<br>

## Approach 2: `UNION` with `WHERE ... NOT IN`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
```

</details>
