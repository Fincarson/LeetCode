# 1355. Activity Participants

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/activity-participants/)  
`Database`

**Problem Link:** [LeetCode 1355 - Activity Participants](https://leetcode.com/problems/activity-participants/)

## Problem

Table: Friends

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
| activity      | varchar |
+---------------+---------+
id is the id of the friend and the primary key for this table in SQL.
name is the name of the friend.
activity is the name of the activity which the friend takes part in.
```

Table: Activities

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| name          | varchar |
+---------------+---------+
In SQL, id is the primary key for this table.
name is the name of the activity.
```

Find the names of all the activities with neither the maximum nor the minimum number of participants.

Each activity in the Activities table is performed by any person in the table Friends.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Friends table:
+------+--------------+---------------+
| id   | name         | activity      |
+------+--------------+---------------+
| 1    | Jonathan D.  | Eating        |
| 2    | Jade W.      | Singing       |
| 3    | Victor J.    | Singing       |
| 4    | Elvis Q.     | Eating        |
| 5    | Daniel A.    | Eating        |
| 6    | Bob B.       | Horse Riding  |
+------+--------------+---------------+
Activities table:
+------+--------------+
| id   | name         |
+------+--------------+
| 1    | Eating       |
| 2    | Singing      |
| 3    | Horse Riding |
+------+--------------+
Output:
+--------------+
| activity     |
+--------------+
| Singing      |
+--------------+
Explanation:
Eating activity is performed by 3 friends, maximum number of participants, (Jonathan D. , Elvis Q. and Daniel A.)
Horse Riding activity is performed by 1 friend, minimum number of participants, (Bob B.)
Singing is performed by 2 friends (Victor J. and Jade W.)
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

# Editorial - 1355. Activity Participants

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| NOT IN Using '~' and 'isin()' | Pandas |
| Remove Matching Records Using LEFT JOIN Only | Pandas |
| NOT IN/EXISTS​ | SQL |
| Using RANK() to Identify the Maximum and Minimum​ | SQL |
| Remove the Matching Records Using LEFT JOIN | SQL |

## Approach 1: NOT IN Using '~' and 'isin()'

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def activity_participants(friends: pd.DataFrame, activities: pd.DataFrame) -> pd.DataFrame:
    df = friends.groupby('activity', as_index=False)['id'].count()
    
    max_min = df.agg({'id': ['max', 'min']})
    
    df = df[~df['id'].isin(max_min['id'])][['activity']]
    
    return df
```

</details>

<br>

## Approach 2: Remove Matching Records Using LEFT JOIN Only

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def activity_participants(friends: pd.DataFrame, activities: pd.DataFrame) -> pd.DataFrame:
    df = friends.groupby('activity', as_index=False)['id'].count()
    
    max_min = df.agg({'id': ['max', 'min']})
    
    df = df.merge(max_min, on='id', how='left', indicator=True)
    
    df2= df[df['_merge']=='left_only'][['activity']]
   
    return df2
```

</details>

<br>

## Approach 1: NOT IN/EXISTS​

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH user_by_activity AS
    (
    SELECT activity, COUNT(DISTINCT id) AS user_cnts
    FROM Friends
    GROUP BY activity
    )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT activity
FROM user_by_activity
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT activity
FROM user_by_activity
WHERE user_cnts NOT IN (SELECT MAX(user_cnts) FROM user_by_activity)
AND user_cnts NOT IN (SELECT MIN(user_cnts) FROM user_by_activity)
```

</details>

<br>

## Approach 2: Using RANK() to Identify the Maximum and Minimum​

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT activity, 
    RANK () OVER (ORDER BY(COUNT(id))) AS rank_asc,
    RANK () OVER (ORDER BY(COUNT(id))DESC) AS rank_desc
FROM Friends
GROUP BY activity
```

</details>

<br>

## Approach 3: Remove the Matching Records Using LEFT JOIN

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH user_by_activity AS 
    (
    SELECT activity, COUNT(DISTINCT id) AS user_cnts
    FROM Friends
    GROUP BY activity
    )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT MAX(user_cnts) AS user_cnts 
FROM user_by_activity
UNION
SELECT MIN(user_cnts) AS user_cnts 
FROM user_by_activity
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT activity
FROM user_by_activity u
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT activity
FROM user_by_activity u
LEFT JOIN 
    (SELECT MAX(user_cnts) AS user_cnts 
    FROM user_by_activity
    UNION
    SELECT MIN(user_cnts) AS user_cnts 
    FROM user_by_activity
    )m
ON u.user_cnts = m.user_cnts
WHERE m.user_cnts IS NULL
```

</details>
