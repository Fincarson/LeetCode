# 615. Average Salary: Departments VS Company

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/average-salary-departments-vs-company/)  
`Database`

**Problem Link:** [LeetCode 615 - Average Salary: Departments VS Company](https://leetcode.com/problems/average-salary-departments-vs-company/)

## Problem

Table: Salary

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| employee_id | int  |
| amount      | int  |
| pay_date    | date |
+-------------+------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the salary of an employee in one month.
employee_id is a foreign key (reference column) from the Employee table.
```

Table: Employee

```text
+---------------+------+
| Column Name   | Type |
+---------------+------+
| employee_id   | int  |
| department_id | int  |
+---------------+------+
In SQL, employee_id is the primary key column for this table.
Each row of this table indicates the department of an employee.
```

Find the comparison result (higher/lower/same) of the average salary of employees in a department to the company's average salary.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Salary table:
+----+-------------+--------+------------+
| id | employee_id | amount | pay_date   |
+----+-------------+--------+------------+
| 1  | 1           | 9000   | 2017/03/31 |
| 2  | 2           | 6000   | 2017/03/31 |
| 3  | 3           | 10000  | 2017/03/31 |
| 4  | 1           | 7000   | 2017/02/28 |
| 5  | 2           | 6000   | 2017/02/28 |
| 6  | 3           | 8000   | 2017/02/28 |
+----+-------------+--------+------------+
Employee table:
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 2             |
| 3           | 2             |
+-------------+---------------+
Output:
+-----------+---------------+------------+
| pay_month | department_id | comparison |
+-----------+---------------+------------+
| 2017-02   | 1             | same       |
| 2017-03   | 1             | higher     |
| 2017-02   | 2             | same       |
| 2017-03   | 2             | lower      |
+-----------+---------------+------------+
Explanation:
In March, the company's average salary is (9000+6000+10000)/3 = 8333.33...
The average salary for department '1' is 9000, which is the salary of employee_id '1' since there is only one employee in this department. So the comparison result is 'higher' since 9000 > 8333.33 obviously.
The average salary of department '2' is (6000 + 10000)/2 = 8000, which is the average of employee_id '2' and '3'. So the comparison result is 'lower' since 8000 < 8333.33.

With he same formula for the average salary comparison in February, the result is 'same' since both the department '1' and '2' have the same average salary with the company, which is 7000.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Countries You Can Safely Invest In](https://leetcode.com/problems/countries-you-can-safely-invest-in/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 615. Average Salary: Departments VS Company

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Monthly Departmental Salary Comparison with Company Average | Pandas |
| Approach: Using `avg()` and `case...when...` | SQL |

## Approach: Monthly Departmental Salary Comparison with Company Average

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def average_salary(salary: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    salary["pay_month"] = salary["pay_date"].dt.strftime("%Y-%m")
    df = salary.merge(employee, on="employee_id")
    df["comp_avg"] = df.groupby(["pay_month"])["amount"].transform("mean")
    df["dep_avg"] = df.groupby(["pay_month", "department_id"])["amount"].transform(
        "mean"
    )
    df["comparison"] = df.apply(
        lambda row: "lower" if row["dep_avg"] < row["comp_avg"] 
            else ("higher" if row["dep_avg"] > row["comp_avg"] else "same"),
        axis=1
    )
    return df[["pay_month", "department_id", "comparison"]].drop_duplicates()
```

</details>

<br>

## Approach: Using `avg()` and `case...when...`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  AVG(amount) AS company_avg, 
  DATE_FORMAT(pay_date, '%Y-%m') AS pay_month 
FROM 
  salary 
GROUP BY 
  DATE_FORMAT(pay_date, '%Y-%m');
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  department_id, 
  AVG(amount) AS department_avg, 
  DATE_FORMAT(pay_date, '%Y-%m') AS pay_month 
FROM 
  salary 
  JOIN employee ON salary.employee_id = employee.employee_id 
GROUP BY 
  department_id, 
  pay_month;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  department_salary.pay_month, 
  department_id, 
  CASE 
    WHEN department_avg > company_avg THEN 'higher' 
    WHEN department_avg < company_avg THEN 'lower' 
    ELSE 'same' 
  END AS comparison 
FROM 
  (
    SELECT 
      department_id, 
      AVG(amount) AS department_avg, 
      DATE_FORMAT(pay_date, '%Y-%m') AS pay_month 
    FROM 
      salary 
      JOIN employee ON salary.employee_id = employee.employee_id 
    GROUP BY 
      department_id, 
      pay_month
  ) AS department_salary 
  JOIN (
    SELECT 
      AVG(amount) AS company_avg, 
      DATE_FORMAT(pay_date, '%Y-%m') AS pay_month 
    FROM 
      salary 
    GROUP BY 
      DATE_FORMAT(pay_date, '%Y-%m')
  ) AS company_salary ON department_salary.pay_month = company_salary.pay_month;
```

</details>
