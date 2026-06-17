# 1050. Actors and Directors Who Cooperated At Least Three Times

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/)  
`Database`

**Problem Link:** [LeetCode 1050 - Actors and Directors Who Cooperated At Least Three Times](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/)

## Problem

Table: ActorDirector

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key (column with unique values) for this table.
```

Write a solution to find all the pairs (actor_id, director_id) where the actor has cooperated with the director at least three times.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
Output:
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
Explanation: The only pair is (1, 1) where they cooperated exactly 3 times.
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

# Editorial - 1050. Actors and Directors Who Cooperated At Least Three Times

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group By and Count | Pandas |
| Approach: Group By and Count | SQL |

## Approach: Group By and Count

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    cnts = actor_director.groupby(['actor_id', 'director_id']).size().reset_index(name='counts')
    return cnts[cnts['counts'] >= 3][['actor_id', 'director_id']]
```

</details>

<br>

## Approach: Group By and Count

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(timestamp) >= 3;
```

</details>
