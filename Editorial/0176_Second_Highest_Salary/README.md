# 176. Second Highest Salary

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/second-highest-salary/)  
`Database`

**Problem Link:** [LeetCode 176 - Second Highest Salary](https://leetcode.com/problems/second-highest-salary/)

## Problem

Table: Employee

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an employee.
```

Write a solution to find the second highest distinct salary from the Employee table. If there is no second highest salary, return null (return None in Pandas).

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output:
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
```

### Example 2

```text
Input:
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output:
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+
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

# Editorial - 176. Second Highest Salary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting | Pandas |
| Using sub-query and `LIMIT` clause | SQL |
| Using `IFNULL` and `LIMIT` clause | SQL |

## Approach: Sorting

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. drop any duplicate salaries.
    employee = employee.drop_duplicates(["salary"])
    
    # 2. If there are less than two unique salaries, return `np.NaN`.
    if len(employee["salary"].unique()) < 2:
        return pd.DataFrame({"SecondHighestSalary": [np.NaN]})
    
    # 3. Sort the table by `salary` in descending order.
    employee = employee.sort_values("salary", ascending=False)
    
    # 4. Drop the `id` column.
    employee.drop("id", axis=1, inplace=True)
    
    # 5. Rename the `salary` column.
    employee.rename({"salary": "SecondHighestSalary"}, axis=1, inplace=True)
    
    # 6, 7. Return the second highest salary.
    return employee.head(2).tail(1)
```

</details>

<br>

## Approach 1: Using sub-query and `LIMIT` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
    Salary AS SecondHighestSalary
FROM
    Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;
```

</details>

<br>

## Approach 2: Using `IFNULL` and `LIMIT` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
```

</details>
