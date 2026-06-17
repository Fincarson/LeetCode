# 1107. New Users Daily Count

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/new-users-daily-count/)  
`Database`

**Problem Link:** [LeetCode 1107 - New Users Daily Count](https://leetcode.com/problems/new-users-daily-count/)

## Problem

Table: Traffic

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| activity      | enum    |
| activity_date | date    |
+---------------+---------+
This table may have duplicate rows.
The activity column is an ENUM (category) type of ('login', 'logout', 'jobs', 'groups', 'homepage').
```

Write a solution to reports for every date within at most 90 days from today, the number of users that logged in for the first time on that date. Assume today is 2019-06-30.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Traffic table:
+---------+----------+---------------+
| user_id | activity | activity_date |
+---------+----------+---------------+
| 1       | login    | 2019-05-01    |
| 1       | homepage | 2019-05-01    |
| 1       | logout   | 2019-05-01    |
| 2       | login    | 2019-06-21    |
| 2       | logout   | 2019-06-21    |
| 3       | login    | 2019-01-01    |
| 3       | jobs     | 2019-01-01    |
| 3       | logout   | 2019-01-01    |
| 4       | login    | 2019-06-21    |
| 4       | groups   | 2019-06-21    |
| 4       | logout   | 2019-06-21    |
| 5       | login    | 2019-03-01    |
| 5       | logout   | 2019-03-01    |
| 5       | login    | 2019-06-21    |
| 5       | logout   | 2019-06-21    |
+---------+----------+---------------+
Output:
+------------+-------------+
| login_date | user_count  |
+------------+-------------+
| 2019-05-01 | 1           |
| 2019-06-21 | 2           |
+------------+-------------+
Explanation:
Note that we only care about dates with non zero user count.
The user with id 5 first logged in on 2019-03-01 so he's not counted on 2019-06-21.
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

# Editorial - 1107. New Users Daily Count

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Filtering and Counting | Pandas |
| Using Aggregate Function | SQL |
| Using the RANK() Window Function | SQL |

## Approach: Filtering and Counting

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def new_users_daily_count(traffic: pd.DataFrame) -> pd.DataFrame:

    df = traffic[traffic.activity == 'login'].drop_duplicates()

    first_login = df.groupby('user_id', as_index=False)['activity_date'].min()


    first_login = first_login[
        first_login.activity_date.between(
            pd.to_datetime("2019-06-30") - timedelta(days=90), "2019-06-30"
        )
    ]

    final = first_login.groupby("activity_date", as_index=False)["user_id"].count()

    return final.rename(
        columns={"activity_date": "login_date", "user_id": "user_count"}
    )
```

</details>

<br>

## Approach 1: Using Aggregate Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
    (
      SELECT 
          user_id, 
          MIN(activity_date) AS login_date 
      FROM 
          Traffic 
      WHERE 
          activity = 'login' 
      GROUP BY 
          user_id 
      HAVING 
          DATEDIFF(
            '2019-06-30', 
            MIN(activity_date)
          ) <= 90
    ) t0
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  login_date, 
  COUNT(DISTINCT user_id) AS user_count 
FROM 
  (
    SELECT 
      user_id, 
      MIN(activity_date) AS login_date 
    FROM 
      Traffic 
    WHERE 
      activity = 'login' 
    GROUP BY 
      user_id 
    HAVING 
      DATEDIFF(
        '2019-06-30', 
        MIN(activity_date)
      ) <= 90
  ) t0 
GROUP BY 
  login_date
```

</details>

<br>

## Approach 2: Using the RANK() Window Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
(
  SELECT 
    *, 
    RANK() OVER (
      PARTITION BY user_id 
      ORDER BY 
        activity_date ASC
    ) AS rnk 
  FROM 
    Traffic 
  WHERE 
    activity = 'login'
) t0
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  activity_date AS login_date, 
  COUNT(DISTINCT user_id) AS user_count 
FROM 
  (
    SELECT 
      *, 
      RANK() OVER (
        PARTITION BY user_id 
        ORDER BY 
          activity_date ASC
      ) AS rnk 
    FROM 
      Traffic 
    WHERE 
      activity = 'login'
  ) t0 
WHERE 
  rnk = 1 
  AND DATEDIFF('2019-06-30', activity_date) <= 90 
GROUP BY 
  activity_date
```

</details>
