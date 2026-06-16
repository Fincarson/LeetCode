# 1873. Calculate Special Bonus

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/calculate-special-bonus/)  
`Database`

**Problem Link:** [LeetCode 1873 - Calculate Special Bonus](https://leetcode.com/problems/calculate-special-bonus/)

## Problem

Table: Employees

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id is the primary key (column with unique values) for this table.
Each row of this table indicates the employee ID, employee name, and salary.
```

Write a solution to calculate the bonus of each employee. The bonus of an employee is 100% of their salary if the ID of the employee is an odd number and the employee's name does not start with the character 'M'. The bonus of an employee is 0 otherwise.

Return the result table ordered by employee_id.

The result format is in the following example.

### Example 1

```text
Input:
Employees table:
+-------------+---------+--------+
| employee_id | name    | salary |
+-------------+---------+--------+
| 2           | Meir    | 3000   |
| 3           | Michael | 3800   |
| 7           | Addilyn | 7400   |
| 8           | Juan    | 6100   |
| 9           | Kannon  | 7700   |
+-------------+---------+--------+
Output:
+-------------+-------+
| employee_id | bonus |
+-------------+-------+
| 2           | 0     |
| 3           | 0     |
| 7           | 7400  |
| 8           | 0     |
| 9           | 7700  |
+-------------+-------+
Explanation:
The employees with IDs 2 and 8 get 0 bonus because they have an even employee_id.
The employee with ID 3 gets 0 bonus because their name starts with 'M'.
The rest of the employees get a 100% bonus.
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

# Editorial - 1873. Calculate Special Bonus

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: If-Else Conditional Statement | Pandas |
| Approach: If Statement | SQL |

## Approach: If-Else Conditional Statement

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(
        lambda x: x['salary'] if x['employee_id'] % 2 and not x['name'].startswith('M') else 0, 
        axis=1
    )

    df = employees[['employee_id', 'bonus']].sort_values('employee_id')
    return df
```

</details>

<br>

## Approach: If Statement

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    employee_id,
    IF(employee_id % 2 = 1 AND name NOT REGEXP '^M', salary, 0) AS bonus 
FROM 
    employees 
ORDER BY 
    employee_id
```

</details>
