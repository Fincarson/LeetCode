# 1709. Biggest Window Between Visits

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/biggest-window-between-visits/)  
`Database`

**Problem Link:** [LeetCode 1709 - Biggest Window Between Visits](https://leetcode.com/problems/biggest-window-between-visits/)

## Problem

Table: UserVisits

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| visit_date  | date |
+-------------+------+
This table does not have a primary key, it might contain duplicate rows.
This table contains logs of the dates that users visited a certain retailer.
```

Assume today's date is '2021-1-1'.

Write a solution that will, for each user_id, find out the largest window of days between each visit and the one right after it (or today if you are considering the last visit).

Return the result table ordered by user_id.

The query result format is in the following example.

### Example 1

```text
Input:
UserVisits table:
+---------+------------+
| user_id | visit_date |
+---------+------------+
| 1       | 2020-11-28 |
| 1       | 2020-10-20 |
| 1       | 2020-12-3  |
| 2       | 2020-10-5  |
| 2       | 2020-12-9  |
| 3       | 2020-11-11 |
+---------+------------+
Output:
+---------+---------------+
| user_id | biggest_window|
+---------+---------------+
| 1       | 39            |
| 2       | 65            |
| 3       | 51            |
+---------+---------------+
Explanation:
For the first user, the windows in question are between dates:
    - 2020-10-20 and 2020-11-28 with a total of 39 days.
    - 2020-11-28 and 2020-12-3 with a total of 5 days.
    - 2020-12-3 and 2021-1-1 with a total of 29 days.
Making the biggest window the one with 39 days.
For the second user, the windows in question are between dates:
    - 2020-10-5 and 2020-12-9 with a total of 65 days.
    - 2020-12-9 and 2021-1-1 with a total of 23 days.
Making the biggest window the one with 65 days.
For the third user, the only window in question is between dates 2020-11-11 and 2021-1-1 with a total of 51 days.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Users With Two Purchases Within Seven Days](https://leetcode.com/problems/users-with-two-purchases-within-seven-days/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1709. Biggest Window Between Visits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using shift() to put two consecutive visits together. | Pandas |
| Using diff() on sorted visit dates | Pandas |
| Find Next Using LEAD() + Append Value Using IFNULL() | SQL |
| Find the Next Visit Using RANK() | SQL |

## Approach 1: Using shift() to put two consecutive visits together.

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def biggest_window(user_visits: pd.DataFrame) -> pd.DataFrame:

    user_visits.sort_values(by=['user_id', 'visit_date'], inplace=True)

    user_visits['next_visit'] = user_visits.groupby(['user_id']).shift(periods=-1, fill_value='2021-01-01')

    user_visits['window'] = (user_visits.next_visit - user_visits.visit_date).dt.days

    biggest_window = user_visits.groupby(['user_id'], as_index=False).window.max()

    return biggest_window.rename(columns = {'window': 'biggest_window'})
```

</details>

<br>

## Approach 2: Using diff() on sorted visit dates

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def biggest_window(user_visits: pd.DataFrame) -> pd.DataFrame:

    today = user_visits[['user_id']].drop_duplicates()

    today['visit_date'] = pd.to_datetime('2021-01-01')

    df = pd.concat([user_visits, today]).sort_values(by=['user_id', 'visit_date'])

    df['window'] = df.groupby('user_id').visit_date.diff().dt.days

    biggest_window = df.groupby(['user_id'], as_index=False).window.max()

    return biggest_window.rename(columns = {'window': 'biggest_window'})
```

</details>

<br>

## Approach 1: Find Next Using LEAD() + Append Value Using IFNULL()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT user_id, visit_date,
       DATEDIFF(IFNULL(LEAD(visit_date, 1)OVER(PARTITION BY user_id ORDER BY visit_date), '2021-01-01'), visit_date) AS w
FROM UserVisits
```

</details>

<br>

## Approach 2: Find the Next Visit Using RANK()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH all_dates AS (
    SELECT user_id, visit_date
    FROM UserVisits
    UNION
    SELECT user_id, '2021-01-01' AS visit_date
    FROM UserVisits)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT *, 
    RANK()OVER(PARTITION BY user_id ORDER BY visit_date) AS date_rnk
FROM all_dates
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT a.user_id, MAX(DATEDIFF(b.visit_date, a.visit_date)) AS biggest_window
FROM rnk a, rnk b
WHERE a.user_id = b.user_id
AND b.date_rnk = a.date_rnk + 1
GROUP BY a.user_id
```

</details>
