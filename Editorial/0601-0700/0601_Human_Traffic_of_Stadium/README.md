# 601. Human Traffic of Stadium

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/human-traffic-of-stadium/)  
`Database`

**Problem Link:** [LeetCode 601 - Human Traffic of Stadium](https://leetcode.com/problems/human-traffic-of-stadium/)

## Problem

Table: Stadium

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| visit_date    | date    |
| people        | int     |
+---------------+---------+
visit_date is the column with unique values for this table.
Each row of this table contains the visit date and visit id to the stadium with the number of people during the visit.
As the id increases, the date increases as well.
```

Write a solution to display the records with three or more rows with consecutive id's, and the number of people is greater than or equal to 100 for each.

Return the result table ordered by visit_date in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Stadium table:
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+
Output:
+------+------------+-----------+
| id   | visit_date | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-09 | 188       |
+------+------------+-----------+
Explanation:
The four rows with ids 5, 6, 7, and 8 have consecutive ids and each of them has >= 100 people attended. Note that row 8 was included even though the visit_date was not the next day after row 7.
The rows with ids 2 and 3 are not included because we need at least three consecutive ids.
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

# Editorial - 601. Human Traffic of Stadium

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Examine Previous Rows Using shift() and diff() | Pandas |
| Finding the Islands | Pandas |
| Using Self-Join | SQL |
| Using Window Functions | SQL |
| Finding the Islands | SQL |

## Approach 1: Examine Previous Rows Using shift() and diff()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:

    df = stadium[stadium['people'] >= 100]
    
    df['flag'] = ((df['id'].diff() == 1) & (df['id'].diff().shift(1) == 1))
    
    df = df[(df['flag'] == True)| (df['flag'].shift(-1) == True) | (df['flag'].shift(-2) == True)]
    
    rreturn df.loc[:, df.columns != 'flag'].sort_values(by='visit_date')
```

</details>

<br>

## Approach 2: Finding the Islands

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:

    stadium = stadium[stadium['people'] >= 100]

    stadium['rnk'] = range(len(stadium))

    stadium['island'] = stadium.id - stadium.rnk

    stadium['island_cnt'] = stadium.groupby(['island'], as_index=False).id.transform('count')

    return stadium[stadium['island_cnt'] >= 3][['id', 'visit_date', 'people']].sort_values(by='visit_date')
```

</details>

<br>

## Approach 1: Using Self-Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    *
FROM 
    stadium AS a, stadium AS b, stadium AS c
WHERE
    a.people >= 100 AND b.people >= 100 AND c.people >= 100
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE (a.id - b.id = 1 AND b.id - c.id = 1)
```

</details>

<br>

## Approach 2: Using Window Functions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH base AS (
        SELECT *,
            LEAD(id, 1) OVER(ORDER BY id) AS next_id,
            LEAD(id, 2) OVER(ORDER BY id) AS second_next_id,
            LAG(id, 1) OVER(ORDER BY id) AS last_id,
            LAG(id, 2) OVER(ORDER BY id) AS second_last_id
        FROM stadium
        WHERE people >= 100 
        )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE (next_id - id = 1 AND id - last_id = 1)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT id, visit_date, people
FROM base 
WHERE (next_id - id = 1 AND id - last_id = 1)
    OR (second_next_id - next_id = 1 AND next_id - id = 1)
    OR (id - last_id = 1 AND last_id - second_last_id = 1)
ORDER BY visit_date
```

</details>

<br>

## Approach 3: Finding the Islands

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT id, visit_date, people, RANK()OVER(ORDER BY id) AS rnk
FROM Stadium
WHERE people >= 100
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH stadium_with_rnk AS
(
    SELECT id, visit_date, people, rnk, (id - rnk) AS island
    FROM (
        SELECT id, visit_date, people, RANK() OVER(ORDER BY id) AS rnk
        FROM Stadium
        WHERE people >= 100) AS t0
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT island 
FROM stadium_with_rnk
GROUP BY island
HAVING COUNT(*) >= 3
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT id, visit_date, people 
FROM stadium_with_rnk
WHERE island IN (SELECT island 
                 FROM stadium_with_rnk 
                 GROUP BY island 
                 HAVING COUNT(*) >= 3)
ORDER BY visit_date
```

</details>
