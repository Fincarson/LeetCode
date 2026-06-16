# 177. Nth Highest Salary

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/nth-highest-salary/)  
`Database`

**Problem Link:** [LeetCode 177 - Nth Highest Salary](https://leetcode.com/problems/nth-highest-salary/)

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

Write a solution to find the nth highest distinct salary from the Employee table. If there are less than n distinct salaries, return null.

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
n = 2
Output:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
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
n = 2
Output:
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| null                   |
+------------------------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Number of Users That Are Eligible for Discount](https://leetcode.com/problems/the-number-of-users-that-are-eligible-for-discount/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 177. Nth Highest Salary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Rank-Based Filtering | Pandas |
| Approach: Sort and Limit | SQL |

## Approach: Rank-Based Filtering

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    
    dist = employee.drop_duplicates(subset='salary')
    dist['rnk'] = dist['salary'].rank(method='dense', ascending=False)
    ans = dist[dist.rnk == N][['salary']]
    if not len(ans):
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
    ans = ans.rename(columns={'salary':f'getNthHighestSalary({N})'})
    return ans
```

</details>

<br>

## Approach: Sort and Limit

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT; 
    SET M = N-1; 
  RETURN (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT M, 1
  );
END
```

</details>
