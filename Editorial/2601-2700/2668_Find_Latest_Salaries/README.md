# 2668. Find Latest Salaries

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-latest-salaries/)  
`Database`

**Problem Link:** [LeetCode 2668 - Find Latest Salaries](https://leetcode.com/problems/find-latest-salaries/)

## Problem

Table: Salary

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| emp_id        | int     |
| firstname     | varchar |
| lastname      | varchar |
| salary        | varchar |
| department_id | varchar |
+---------------+---------+
(emp_id, salary) is the primary key (combination of columns with unique values) for this table.
Each row contains employees details and their yearly salaries, however, some of the records are old and contain outdated salary information.
```

Write a solution to find the current salary of each employee assuming that salaries increase each year. Output their emp_id, firstname, lastname, salary, and department_id.

Return the result table ordered by emp_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Salary table:
+--------+-----------+----------+--------+---------------+
| emp_id | firstname | lastname | salary | department_id |
+--------+-----------+----------+--------+---------------+
| 1      | Todd      | Wilson   | 110000 | D1006         |
| 1      | Todd      | Wilson   | 106119 | D1006         |
| 2      | Justin    | Simon    | 128922 | D1005         |
| 2      | Justin    | Simon    | 130000 | D1005         |
| 3      | Kelly     | Rosario  | 42689  | D1002         |
| 4      | Patricia  | Powell   | 162825 | D1004         |
| 4      | Patricia  | Powell   | 170000 | D1004         |
| 5      | Sherry    | Golden   | 44101  | D1002         |
| 6      | Natasha   | Swanson  | 79632  | D1005         |
| 6      | Natasha   | Swanson  | 90000  | D1005         |
+--------+-----------+----------+--------+---------------+
Output:
+--------+-----------+----------+--------+---------------+
| emp_id | firstname | lastname | salary | department_id |
+--------+-----------+----------+--------+---------------+
| 1      | Todd      | Wilson   | 110000 | D1006         |
| 2      | Justin    | Simon    | 130000 | D1005         |
| 3      | Kelly     | Rosario  | 42689  | D1002         |
| 4      | Patricia  | Powell   | 170000 | D1004         |
| 5      | Sherry    | Golden   | 44101  | D1002         |
| 6      | Natasha   | Swanson  | 90000  | D1005         |
+--------+-----------+----------+--------+---------------+

Explanation:
- emp_id 1 has two records with a salary of 110000, 106119 out of these 110000 is an updated salary (Assuming salary is increasing each year)
- emp_id 2 has two records with a salary of 128922, 130000 out of these 130000 is an updated salary.
- emp_id 3 has only one salary record so that is already an updated salary.
- emp_id 4 has two records with a salary of 162825, 170000 out of these 170000 is an updated salary.
- emp_id 5 has only one salary record so that is already an updated salary.
- emp_id 6 has two records with a salary of 79632, 90000 out of these 90000 is an updated salary.
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

# Editorial - 2668. Find Latest Salaries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sort and Drop Duplicates | Pandas |
| Approach: Group By and use MAX function | MySQL |

## Approach: Sort and Drop Duplicates

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
def find_latest_salaries(salary: pd.DataFrame) -> pd.DataFrame:
    df = salary.sort_values(by = 'salary', ascending = False)
    df = df.drop_duplicates(subset = 'emp_id')
    return df.sort_values(by = 'emp_id')
```

</details>

<br>

## Approach: Group By and use MAX function

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql

###### PostgreSQL
```

</details>
