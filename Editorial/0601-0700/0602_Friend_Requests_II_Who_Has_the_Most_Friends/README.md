# 602. Friend Requests II: Who Has the Most Friends

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/)  
`Database`

**Problem Link:** [LeetCode 602 - Friend Requests II: Who Has the Most Friends](https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/)

## Problem

Table: RequestAccepted

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| requester_id   | int     |
| accepter_id    | int     |
| accept_date    | date    |
+----------------+---------+
(requester_id, accepter_id) is the primary key (combination of columns with unique values) for this table.
This table contains the ID of the user who sent the request, the ID of the user who received the request, and the date when the request was accepted.
```

Write a solution to find the people who have the most friends and the most friends number.

The test cases are generated so that only one person has the most friends.

The result format is in the following example.

### Example 1

```text
Input:
RequestAccepted table:
+--------------+-------------+-------------+
| requester_id | accepter_id | accept_date |
+--------------+-------------+-------------+
| 1            | 2           | 2016/06/03  |
| 1            | 3           | 2016/06/08  |
| 2            | 3           | 2016/06/08  |
| 3            | 4           | 2016/06/09  |
+--------------+-------------+-------------+
Output:
+----+-----+
| id | num |
+----+-----+
| 3  | 3   |
+----+-----+
Explanation:
The person with id 3 is a friend of people 1, 2, and 4, so he has three friends in total, which is the most number than any others.
```

Follow up: In the real world, multiple people could have the same most number of friends. Could you find all these people in this case?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 602. Friend Requests II: Who Has the Most Friends

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Combining DataFrames Using concat() and Finding the Top Values Using sort_values() and head() | Pandas |
| Combining Tables Using UNION ALL and Finding the Top Values Using ORDER BY + LIMIT | SQL |
| Combining Tables Using UNION ALL and Finding Top Values Using RANK() | SQL |

## Approach: Combining DataFrames Using concat() and Finding the Top Values Using sort_values() and head()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:
    
    values = pd.concat([request_accepted["requester_id"], request_accepted["accepter_id"]]).to_frame('id')

    df = values.groupby('id', as_index=False).agg(num=('id', 'count')).sort_values('num', ascending=False).head(1)

    return df
```

</details>

<br>

## Approach 1: Combining Tables Using UNION ALL and Finding the Top Values Using ORDER BY + LIMIT

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH all_ids AS (
   SELECT requester_id AS id 
   FROM RequestAccepted
   UNION ALL
   SELECT accepter_id AS id
   FROM RequestAccepted)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT id, 
   COUNT(id) AS num
FROM all_ids
GROUP BY id
ORDER BY COUNT(id) DESC
LIMIT 1
```

</details>

<br>

## Approach 2: Combining Tables Using UNION ALL and Finding Top Values Using RANK()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH all_ids AS (
   SELECT requester_id AS id 
   FROM RequestAccepted
   UNION ALL
   SELECT accepter_id AS id
   FROM RequestAccepted)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   (
   SELECT id, 
      COUNT(id) AS num, 
      RANK () OVER(ORDER BY COUNT(id) DESC) AS rnk
   FROM all_ids
   GROUP BY id
   )t0
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT id, num
FROM 
   (
   SELECT id, 
      COUNT(id) AS num, 
      RANK () OVER(ORDER BY COUNT(id) DESC) AS rnk
   FROM all_ids
   GROUP BY id
   )t0
WHERE rnk=1
```

</details>
