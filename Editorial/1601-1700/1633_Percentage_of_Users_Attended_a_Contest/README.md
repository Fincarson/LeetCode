# 1633. Percentage of Users Attended a Contest

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)  
`Database`

**Problem Link:** [LeetCode 1633 - Percentage of Users Attended a Contest](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)

## Problem

Table: Users

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| user_name   | varchar |
+-------------+---------+
user_id is the primary key (column with unique values) for this table.
Each row of this table contains the name and the id of a user.
```

Table: Register

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| contest_id  | int     |
| user_id     | int     |
+-------------+---------+
(contest_id, user_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the id of a user and the contest they registered into.
```

Write a solution to find the percentage of the users registered in each contest rounded to two decimals.

Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Users table:
+---------+-----------+
| user_id | user_name |
+---------+-----------+
| 6       | Alice     |
| 2       | Bob       |
| 7       | Alex      |
+---------+-----------+
Register table:
+------------+---------+
| contest_id | user_id |
+------------+---------+
| 215        | 6       |
| 209        | 2       |
| 208        | 2       |
| 210        | 6       |
| 208        | 6       |
| 209        | 7       |
| 209        | 6       |
| 215        | 7       |
| 208        | 7       |
| 210        | 2       |
| 207        | 2       |
| 210        | 7       |
+------------+---------+
Output:
+------------+------------+
| contest_id | percentage |
+------------+------------+
| 208        | 100.0      |
| 209        | 100.0      |
| 210        | 100.0      |
| 215        | 66.67      |
| 207        | 33.33      |
+------------+------------+
Explanation:
All the users registered in contests 208, 209, and 210. The percentage is 100% and we sort them in the answer table by contest_id in ascending order.
Alice and Alex registered in contest 215 and the percentage is ((2/3) * 100) = 66.67%
Bob registered in contest 207 and the percentage is ((1/3) * 100) = 33.33%
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Queries Quality and Percentage](https://leetcode.com/problems/queries-quality-and-percentage/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1633. Percentage of Users Attended a Contest

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Calculating User Participation Percentage Without Merging DataFrames | Pandas |
| Approach: Percentage Calculation with Aggregation | SQL |

## Approach: Calculating User Participation Percentage Without Merging DataFrames

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:
    # Calculate the total number of unique users
    total_users = users["user_id"].nunique()

    # Count the distinct user_id in each contest_id and calculate the percentage
    register_grouped = (
        register.groupby("contest_id")["user_id"]
        .nunique()
        .reset_index(name="count_unique_users")
    )

    # Calculate the percentage
    register_grouped["percentage"] = (
        register_grouped["count_unique_users"] / total_users
    ) * 100

    # Round the percentage to 2 decimal places
    register_grouped["percentage"] = register_grouped["percentage"].round(2)

    # Sort the results by percentage in descending order and then by contest_id
    register_grouped = register_grouped.sort_values(
        by=["percentage", "contest_id"], ascending=[False, True]
    )

    # Select only the contest_id and percentage columns
    final_df = register_grouped[["contest_id", "percentage"]]

    return final_df
```

</details>

<br>

## Approach: Percentage Calculation with Aggregation

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  contest_id, 
  COUNT(DISTINCT user_id) AS unique_users
FROM 
  Register
GROUP BY 
  contest_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
(SELECT COUNT(user_id) FROM Users)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
ROUND(
  COUNT(DISTINCT user_id) * 100.0 / (SELECT COUNT(user_id) FROM Users), 
  2
) AS percentage
```

</details>
