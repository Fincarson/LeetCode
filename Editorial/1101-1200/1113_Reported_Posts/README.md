# 1113. Reported Posts

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reported-posts/)  
`Database`

**Problem Link:** [LeetCode 1113 - Reported Posts](https://leetcode.com/problems/reported-posts/)

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

Write a solution to report the number of posts reported yesterday for each report reason. Assume today is 2019-07-05.

Return the result table in any order.

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
| 2       | 4       | 2019-07-04  | view   | null   |
| 2       | 4       | 2019-07-04  | report | spam   |
| 3       | 4       | 2019-07-04  | view   | null   |
| 3       | 4       | 2019-07-04  | report | spam   |
| 4       | 3       | 2019-07-02  | view   | null   |
| 4       | 3       | 2019-07-02  | report | spam   |
| 5       | 2       | 2019-07-04  | view   | null   |
| 5       | 2       | 2019-07-04  | report | racism |
| 5       | 5       | 2019-07-04  | view   | null   |
| 5       | 5       | 2019-07-04  | report | racism |
+---------+---------+-------------+--------+--------+
Output:
+---------------+--------------+
| report_reason | report_count |
+---------------+--------------+
| spam          | 1            |
| racism        | 2            |
+---------------+--------------+
Explanation: Note that we only care about report reasons with non-zero number of reports.
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

# Editorial - 1113. Reported Posts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using groupby() | Pandas |
| Use GROUP BY Clause | SQL |

## Approach 1: Using groupby()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python

import pandas as pd

def reported_posts(actions: pd.DataFrame) -> pd.DataFrame:
    # Filter the 'actions' table to include only actions on the specified date (July 4, 2019).
    actions = actions[actions['action_date'] == '2019-07-04']
    
    # Filter further to include only 'report' actions.
    actions = actions[actions['action'] == 'report']

    # Group the filtered data by the 'extra' column (report reasons) and count the unique 'post_id's.
    report_counts = actions.groupby('extra')['post_id'].nunique().reset_index()
    
    # Rename the columns for clarity.
    report_counts = report_counts.rename(columns={
        'extra': 'report_reason',
        'post_id': 'report_count'
    })

    return report_counts
```

</details>

<br>

## Approach 1: Use GROUP BY Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql

SELECT
    extra AS report_reason,
    COUNT(DISTINCT post_id) AS report_count
FROM Actions
WHERE action_date = '2019-07-04' AND 
      action = 'report'
GROUP BY report_reason;
```

</details>
