# 1132. Reported Posts II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reported-posts-ii/)  
`Database`

**Problem Link:** [LeetCode 1132 - Reported Posts II](https://leetcode.com/problems/reported-posts-ii/)

## Problem

Table: Actions

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| post_id       | int     |
| action_date   | date    |
| action        | enum    |
| extra         | varchar |
+---------------+---------+
This table may have duplicate rows.
The action column is an ENUM (category) type of ('view', 'like', 'reaction', 'comment', 'report', 'share').
The extra column has optional information about the action, such as a reason for the report or a type of reaction.
```

Table: Removals

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| post_id       | int     |
| remove_date   | date    |
+---------------+---------+
post_id is the primary key (column with unique values) of this table.
Each row in this table indicates that some post was removed due to being reported or as a result of an admin review.
```

Write a solution to find the average daily percentage of posts that got removed after being reported as spam, rounded to 2 decimal places.

The result format is in the following example.

### Example 1

```text
Input:
Actions table:
+---------+---------+-------------+--------+--------+
| user_id | post_id | action_date | action | extra  |
+---------+---------+-------------+--------+--------+
| 1       | 1       | 2019-07-01  | view   | null   |
| 1       | 1       | 2019-07-01  | like   | null   |
| 1       | 1       | 2019-07-01  | share  | null   |
| 2       | 2       | 2019-07-04  | view   | null   |
| 2       | 2       | 2019-07-04  | report | spam   |
| 3       | 4       | 2019-07-04  | view   | null   |
| 3       | 4       | 2019-07-04  | report | spam   |
| 4       | 3       | 2019-07-02  | view   | null   |
| 4       | 3       | 2019-07-02  | report | spam   |
| 5       | 2       | 2019-07-03  | view   | null   |
| 5       | 2       | 2019-07-03  | report | racism |
| 5       | 5       | 2019-07-03  | view   | null   |
| 5       | 5       | 2019-07-03  | report | racism |
+---------+---------+-------------+--------+--------+
Removals table:
+---------+-------------+
| post_id | remove_date |
+---------+-------------+
| 2       | 2019-07-20  |
| 3       | 2019-07-18  |
+---------+-------------+
Output:
+-----------------------+
| average_daily_percent |
+-----------------------+
| 75.00                 |
+-----------------------+
Explanation:
The percentage for 2019-07-04 is 50% because only one post of two spam reported posts were removed.
The percentage for 2019-07-02 is 100% because one post was reported as spam and it was removed.
The other days had no spam reports so the average is (50 + 100) / 2 = 75%
Note that the output is only one number and that we do not care about the remove dates.
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

# Editorial - 1132. Reported Posts II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Calculate and Name Multiple Aggregate Values Using NamedAgg | Pandas |
| Approach: Identifying Matched Records Using CASE WHEN | SQL |

## Approach: Calculate and Name Multiple Aggregate Values Using NamedAgg

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def reported_posts(actions: pd.DataFrame, removals: pd.DataFrame) -> pd.DataFrame:

    spam = actions[actions['extra'] == 'spam'].drop_duplicates(['action_date', 'post_id'])

    removed_spam = spam.merge(removals, on='post_id', how='left')

    df = removed_spam.groupby("action_date", as_index=False).agg(
        removed_spam=('remove_date', 'count'), 
        total_spam=('remove_date', 'size')
    )
    
    df = df.assign(average_daily_percent = df['removed_spam']*100/df['total_spam'])

    avg = df.agg({'average_daily_percent': ['mean']}).round(2)

    return avg
```

</details>

<br>

## Approach: Identifying Matched Records Using CASE WHEN

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT action_date, 
    COUNT(DISTINCT CASE WHEN a.post_id = r.post_id THEN r.post_id END) / COUNT(DISTINCT a.post_id) AS daily_rate
FROM Actions a
LEFT JOIN Removals r
ON a.post_id = r.post_id
WHERE a.extra = 'spam'
GROUP BY action_date
```

</details>
