# 569. Median Employee Salary

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/median-employee-salary/)  
`Database`

**Problem Link:** [LeetCode 569 - Median Employee Salary](https://leetcode.com/problems/median-employee-salary/)

## Problem

Table: Employee

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| company      | varchar |
| salary       | int     |
+--------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the company and the salary of one employee.
```

Write a solution to find the rows that contain the median salary of each company. While calculating the median, when you sort the salaries of the company, break the ties by id.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Employee table:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 1  | A       | 2341   |
| 2  | A       | 341    |
| 3  | A       | 15     |
| 4  | A       | 15314  |
| 5  | A       | 451    |
| 6  | A       | 513    |
| 7  | B       | 15     |
| 8  | B       | 13     |
| 9  | B       | 1154   |
| 10 | B       | 1345   |
| 11 | B       | 1221   |
| 12 | B       | 234    |
| 13 | C       | 2345   |
| 14 | C       | 2645   |
| 15 | C       | 2645   |
| 16 | C       | 2652   |
| 17 | C       | 65     |
+----+---------+--------+
Output:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 5  | A       | 451    |
| 6  | A       | 513    |
| 12 | B       | 234    |
| 9  | B       | 1154   |
| 14 | C       | 2645   |
+----+---------+--------+
Explanation:
For company A, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 3  | A       | 15     |
| 2  | A       | 341    |
| 5  | A       | 451    | <-- median
| 6  | A       | 513    | <-- median
| 1  | A       | 2341   |
| 4  | A       | 15314  |
+----+---------+--------+
For company B, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 8  | B       | 13     |
| 7  | B       | 15     |
| 12 | B       | 234    | <-- median
| 11 | B       | 1221   | <-- median
| 9  | B       | 1154   |
| 10 | B       | 1345   |
+----+---------+--------+
For company C, the rows sorted are as follows:
+----+---------+--------+
| id | company | salary |
+----+---------+--------+
| 17 | C       | 65     |
| 13 | C       | 2345   |
| 14 | C       | 2645   | <-- median
| 15 | C       | 2645   |
| 16 | C       | 2652   |
+----+---------+--------+
```

Follow up: Could you solve it without using any built-in or window functions?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Median Given Frequency of Numbers](https://leetcode.com/problems/find-median-given-frequency-of-numbers/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 569. Median Employee Salary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Finding Median Using rank() | Pandas |
| Finding Median Using len() and ':' for slicing | Pandas |
| Approach: Finding Median Using RANK() | SQL |

## Approach 1: Finding Median Using rank()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def median_employee_salary(employee: pd.DataFrame) -> pd.DataFrame:

    employee['rank'] = pd.to_numeric(employee.sort_values(['salary','id']).groupby('company').cumcount() + 1)

    df = employee.groupby('company', as_index=False)['id'].count().rename(columns={'id': 'cnt'})

    df2 = df.merge(employee, on='company')

    df2 = df2.loc[(df2['rank'] >= df2['cnt'] / 2) & (df2['rank'] <= df2['cnt'] / 2 + 1)]

    return df2[['id', 'company', 'salary']]
```

</details>

<br>

## Approach 2: Finding Median Using len() and ':' for slicing

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
def median_employee_salary(employee: pd.DataFrame) -> pd.DataFrame:

    df = employee.sort_values(['salary', 'id']).groupby('company').apply(lambda x: x.iloc[(len(x) - 1) // 2 : len(x) // 2 + 1])

    return df
```

</details>

<br>

## Approach: Finding Median Using RANK()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH add_rank AS
    (SELECT id, company, salary,
        ROW_NUMBER()OVER(PARTITION BY company ORDER BY salary) AS rnk
    FROM Employee)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
 add_count AS
    (SELECT company, COUNT(DISTINCT id) AS cnt
    FROM Employee
    GROUP BY company)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT a.id, a.company, a.salary
FROM add_rank a
JOIN add_count b
ON a.company = b.company
AND a.rnk BETWEEN b.cnt / 2 AND b.cnt / 2 + 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH add_rank AS
    (SELECT id, company, salary,
        ROW_NUMBER()OVER(PARTITION BY company ORDER BY salary) AS rnk
    FROM Employee)
, add_count AS
    (SELECT company, COUNT(DISTINCT id) AS cnt
    FROM Employee
    GROUP BY company)
SELECT a.id, a.company, a.salary
FROM add_rank a
JOIN add_count b
ON a.company = b.company
AND a.rnk BETWEEN b.cnt / 2 AND b.cnt / 2 + 1
```

</details>
