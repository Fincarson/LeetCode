# 577. Employee Bonus

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/employee-bonus/)  
`Database`

**Problem Link:** [LeetCode 577 - Employee Bonus](https://leetcode.com/problems/employee-bonus/)

## Problem

Table: Employee

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId is the column with unique values for this table.
Each row of this table indicates the name and the ID of an employee in addition to their salary and the id of their manager.
```

Table: Bonus

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId is the column of unique values for this table.
empId is a foreign key (reference column) to empId from the Employee table.
Each row of this table contains the id of an employee and their respective bonus.
```

Write a solution to report the name and bonus amount of each employee who satisfies either of the following:

- The employee has a bonus less than 1000.
- The employee did not get any bonus.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
Output:
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Combine Two Tables](https://leetcode.com/problems/combine-two-tables/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 577. Employee Bonus

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Filter and Retrieve | Pandas |
| Using `OUTER JOIN` and `WHERE` clause | SQL |

## Approach 1: Filter and Retrieve

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    # Merge Employee and Bonus tables using a left join
    result_df = pd.merge(employee, bonus, on='empId', how='left')

    # Filter rows where bonus is less than 1000 or missing
    result_df = result_df[(result_df['bonus'] < 1000) | result_df['bonus'].isnull()]

    # Select "name" and "bonus" columns
    result_df = result_df[['name', 'bonus']]

    return result_df
```

</details>

<br>

## Approach 1: Using `OUTER JOIN` and `WHERE` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus ON Employee.empid = Bonus.empid
;
```

</details>
