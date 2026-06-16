# 2004. The Number of Seniors and Juniors to Join the Company

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/the-number-of-seniors-and-juniors-to-join-the-company/)  
`Database`

**Problem Link:** [LeetCode 2004 - The Number of Seniors and Juniors to Join the Company](https://leetcode.com/problems/the-number-of-seniors-and-juniors-to-join-the-company/)

## Problem

Table: Candidates

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| employee_id | int  |
| experience  | enum |
| salary      | int  |
+-------------+------+
employee_id is the column with unique values for this table.
experience is an ENUM (category) type of values ('Senior', 'Junior').
Each row of this table indicates the id of a candidate, their monthly salary, and their experience.
```

A company wants to hire new employees. The budget of the company for the salaries is $70000. The company's criteria for hiring are:

Write a solution to find the number of seniors and juniors hired under the mentioned criteria.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 10000  |
| 9           | Junior     | 10000  |
| 2           | Senior     | 20000  |
| 11          | Senior     | 20000  |
| 13          | Senior     | 50000  |
| 4           | Junior     | 40000  |
+-------------+------------+--------+
Output:
+------------+---------------------+
| experience | accepted_candidates |
+------------+---------------------+
| Senior     | 2                   |
| Junior     | 2                   |
+------------+---------------------+
Explanation:
We can hire 2 seniors with IDs (2, 11). Since the budget is $70000 and the sum of their salaries is $40000, we still have $30000 but they are not enough to hire the senior candidate with ID 13.
We can hire 2 juniors with IDs (1, 9). Since the remaining budget is $30000 and the sum of their salaries is $20000, we still have $10000 but they are not enough to hire the junior candidate with ID 4.
```

### Example 2

```text
Input:
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 10000  |
| 9           | Junior     | 10000  |
| 2           | Senior     | 80000  |
| 11          | Senior     | 80000  |
| 13          | Senior     | 80000  |
| 4           | Junior     | 40000  |
+-------------+------------+--------+
Output:
+------------+---------------------+
| experience | accepted_candidates |
+------------+---------------------+
| Senior     | 0                   |
| Junior     | 3                   |
+------------+---------------------+
Explanation:
We cannot hire any seniors with the current budget as we need at least $80000 to hire one senior.
We can hire all three juniors with the remaining budget.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Last Person to Fit in the Bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [The Number of Seniors and Juniors to Join the Company II](https://leetcode.com/problems/the-number-of-seniors-and-juniors-to-join-the-company-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2004. The Number of Seniors and Juniors to Join the Company

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Cumulative Salary-Based Hiring Strategy | Pandas |
| Approach: Tiered Cumulative Salary Allocation Strategy | SQL |

## Approach: Cumulative Salary-Based Hiring Strategy

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_seniors_and_juniors(candidates: pd.DataFrame) -> pd.DataFrame:
    # Constants
    BUDGET = 70000

    # Separate seniors and juniors and sort by salary
    seniors = candidates[candidates["experience"] == "Senior"].sort_values(by="salary")
    juniors = candidates[candidates["experience"] == "Junior"].sort_values(by="salary")

    # Calculate cumulative salaries
    seniors["cumulative_salary"] = seniors["salary"].cumsum()
    juniors["cumulative_salary"] = juniors["salary"].cumsum()

    # Determine how many seniors can be hired
    seniors_hired = seniors[seniors["cumulative_salary"] <= BUDGET]
    remaining_budget = BUDGET - seniors_hired["salary"].sum()

    # Determine how many juniors can be hired with the remaining budget
    juniors_hired = juniors[juniors["cumulative_salary"] <= remaining_budget]

    # Prepare the result
    result = pd.DataFrame(
        {
            "experience": ["Senior", "Junior"],
            "accepted_candidates": [len(seniors_hired), len(juniors_hired)],
        }
    )

    return result
```

</details>

<br>

## Approach: Tiered Cumulative Salary Allocation Strategy

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   WITH SeniorCandidates AS (
       SELECT *,
              SUM(salary) OVER (ORDER BY salary) AS cumulative_salary
       FROM Candidates
       WHERE experience = 'Senior'
   ),
   JuniorCandidates AS (
       SELECT *,
              SUM(salary) OVER (ORDER BY salary) AS cumulative_salary
       FROM Candidates
       WHERE experience = 'Junior'
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   WITH HiredSeniors AS (
       SELECT COUNT(*) AS count
       FROM SeniorCandidates
       WHERE cumulative_salary <= 70000
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   WITH RemainingBudget AS (
       SELECT 70000 - COALESCE((SELECT cumulative_salary FROM SeniorCandidates WHERE cumulative_salary <= 70000 ORDER BY cumulative_salary DESC LIMIT 1), 0) AS budget
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   WITH HiredJuniors AS (
       SELECT COUNT(*) AS count
       FROM JuniorCandidates, RemainingBudget
       WHERE JuniorCandidates.cumulative_salary <= RemainingBudget.budget
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT 'Senior' AS experience, (SELECT count FROM HiredSeniors) AS accepted_candidates
   UNION
   SELECT 'Junior' AS experience, (SELECT count FROM HiredJuniors) AS accepted_candidates;
```

</details>
