# 1731. The Number of Employees Which Report to Each Employee

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/)  
`Database`

**Problem Link:** [LeetCode 1731 - The Number of Employees Which Report to Each Employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/)

## Problem

Table: Employees

```text
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id is the column with unique values for this table.
This table contains information about the employees and the id of the manager they report to. Some employees do not report to anyone (reports_to is null).
```

For this problem, we will consider a manager an employee who has at least 1 other employee reporting to them.

Write a solution to report the ids and the names of all managers, the number of employees who report directly to them, and the average age of the reports rounded to the nearest integer.

Return the result table ordered by employee_id.

The result format is in the following example.

### Example 1

```text
Input:
Employees table:
+-------------+---------+------------+-----+
| employee_id | name    | reports_to | age |
+-------------+---------+------------+-----+
| 9           | Hercy   | null       | 43  |
| 6           | Alice   | 9          | 41  |
| 4           | Bob     | 9          | 36  |
| 2           | Winston | null       | 37  |
+-------------+---------+------------+-----+
Output:
+-------------+-------+---------------+-------------+
| employee_id | name  | reports_count | average_age |
+-------------+-------+---------------+-------------+
| 9           | Hercy | 2             | 39          |
+-------------+-------+---------------+-------------+
Explanation: Hercy has 2 people report directly to him, Alice and Bob. Their average age is (41+36)/2 = 38.5, which is 39 after rounding it to the nearest integer.
```

### Example 2

```text
Input:
Employees table:
+-------------+---------+------------+-----+
| employee_id | name    | reports_to | age |
|-------------|---------|------------|-----|
| 1           | Michael | null       | 45  |
| 2           | Alice   | 1          | 38  |
| 3           | Bob     | 1          | 42  |
| 4           | Charlie | 2          | 34  |
| 5           | David   | 2          | 40  |
| 6           | Eve     | 3          | 37  |
| 7           | Frank   | null       | 50  |
| 8           | Grace   | null       | 48  |
+-------------+---------+------------+-----+
Output:
+-------------+---------+---------------+-------------+
| employee_id | name    | reports_count | average_age |
| ----------- | ------- | ------------- | ----------- |
| 1           | Michael | 2             | 40          |
| 2           | Alice   | 2             | 37          |
| 3           | Bob     | 1             | 37          |
+-------------+---------+---------------+-------------+
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

# Editorial - 1731. The Number of Employees Which Report to Each Employee

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Aggregation-Merge Rounding Strategy | Pandas |
| Self Join | SQL |
| Correlated Sub-Query | SQL |

## Approach: Aggregation-Merge Rounding Strategy

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    # Group employees by their manager to calculate the count of reports and the average age
    by_manager = employees.groupby("reports_to", as_index=False).agg(
        reports_count=("employee_id", "size"),  # Count of reports per manager
        average_age=("age", "mean"),  # Average age of reports
    )

    # Adjust for banker's rounding by adding a very small number before rounding
    by_manager["average_age"] = (by_manager["average_age"] + 1e-12).round(0)

    # Merge the aggregated data with the original employees DataFrame to get the names of managers
    merged = by_manager.merge(
        employees[["employee_id", "name"]],
        how="left",
        left_on="reports_to",
        right_on="employee_id",
    )

    # Since the merge introduces '_x' and '_y' suffixes for overlapping column names, correct this
    # Also, directly rename columns to match expected output format without intermediate steps
    merged.rename(
        columns={
            "employee_id_y": "employee_id",  # This is the actual manager's ID
        },
        inplace=True,
    )

    # Select the columns in the order that matches the expected output
    final_output = merged[["employee_id", "name", "reports_count", "average_age"]]

    return final_output
```

</details>

<br>

## Approach 1: Self Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
FROM employees emp JOIN employees mgr ON emp.reports_to = mgr.employee_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  mgr.employee_id, 
  mgr.name, 
  COUNT(emp.employee_id) AS reports_count, 
  ROUND(AVG(emp.age)) AS average_age
```

</details>

<br>

## Approach 2: Correlated Sub-Query

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
FROM employees e GROUP BY reports_to
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  reports_to AS employee_id, 
  (
    SELECT name FROM employees e1 WHERE e.reports_to = e1.employee_id
  ) AS name,
```

</details>
