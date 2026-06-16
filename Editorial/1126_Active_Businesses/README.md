# 1126. Active Businesses

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/active-businesses/)  
`Database`

**Problem Link:** [LeetCode 1126 - Active Businesses](https://leetcode.com/problems/active-businesses/)

## Problem

Table: Events

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| business_id   | int     |
| event_type    | varchar |
| occurrences   | int     |
+---------------+---------+
(business_id, event_type) is the primary key (combination of columns with unique values) of this table.
Each row in the table logs the info that an event of some type occurred at some business for a number of times.
```

The average activity for a particular event_type is the average occurrences across all companies that have this event.

An active business is a business that has more than one event_type such that their occurrences is strictly greater than the average activity for that event.

Write a solution to find all active businesses.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Events table:
+-------------+------------+-------------+
| business_id | event_type | occurrences |
+-------------+------------+-------------+
| 1           | reviews    | 7           |
| 3           | reviews    | 3           |
| 1           | ads        | 11          |
| 2           | ads        | 7           |
| 3           | ads        | 6           |
| 1           | page views | 3           |
| 2           | page views | 12          |
+-------------+------------+-------------+
Output:
+-------------+
| business_id |
+-------------+
| 1           |
+-------------+
Explanation:
The average activity for each event can be calculated as follows:
- 'reviews': (7+3)/2 = 5
- 'ads': (11+7+6)/3 = 8
- 'page views': (3+12)/2 = 7.5
The business with id=1 has 7 'reviews' events (more than 5) and 11 'ads' events (more than 8), so it is an active business.
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

# Editorial - 1126. Active Businesses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Comparing After Merge | Pandas |
| Comparing Using Lambda | Pandas |
| Using the Aggregate Function | SQL |
| Using the Window Function | SQL |

## Approach 1: Comparing After Merge

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def active_businesses(events: pd.DataFrame) -> pd.DataFrame:

    avg = events.groupby('event_type', as_index=False)['occurrences'].mean()

    df = events.merge(avg, on='event_type')

    df = df[df.occurrences_x - df.occurrences_y > 0]

    active_business = df.groupby('business_id', as_index=False)['event_type'].count()

    return active_business[active_business.event_type > 1][['business_id']]
```

</details>

<br>

## Approach 2: Comparing Using Lambda

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python

import pandas as pd

def active_businesses(events: pd.DataFrame) -> pd.DataFrame:

    df = events.groupby('event_type', as_index=False).apply(lambda x: x[x['occurrences'] > x['occurrences'].mean()])

    df = df.groupby('business_id', as_index=False).filter(lambda x: x['business_id'].count() > 1)

    return df[['business_id']].drop_duplicates()
```

</details>

<br>

## Approach 1: Using the Aggregate Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
(
  SELECT 
    event_type, 
    AVG(occurrences) AS avg 
  FROM 
    Events 
  GROUP BY 
    event_type
) t0
```

</details>

<br>

## Approach 2: Using the Window Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
(
  SELECT 
    business_id, 
    event_type, 
    occurrences, 
    AVG(occurrences) OVER (PARTITION BY event_type) AS avg 
  FROM 
    Events
) t0
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  business_id 
FROM 
  (
    SELECT 
      business_id, 
      event_type, 
      occurrences, 
      AVG(occurrences) OVER (PARTITION BY event_type) AS avg 
    FROM 
      Events
  ) t0 
WHERE 
  occurrences > avg 
GROUP BY 
  business_id 
HAVING 
  COUNT(*) > 1
```

</details>
