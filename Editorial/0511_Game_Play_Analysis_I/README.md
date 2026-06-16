# 511. Game Play Analysis I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/game-play-analysis-i/)  
`Database`

**Problem Link:** [LeetCode 511 - Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/)

## Problem

Table: Activity

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key (combination of columns with unique values) of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.
```

Write a solution to find the first login date for each player.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output:
+-----------+-------------+
| player_id | first_login |
+-----------+-------------+
| 1         | 2016-03-01  |
| 2         | 2017-06-25  |
| 3         | 2016-03-02  |
+-----------+-------------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game Play Analysis II](https://leetcode.com/problems/game-play-analysis-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 511. Game Play Analysis I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Grouping and Extracting the Minimum | Python3, Pandas |
| Grouping and Extracting the Minimum | SQL |
| Window functions | SQL |

## Approach 1: Grouping and Extracting the Minimum

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
df = activity.groupby('player_id')['event_date'].min().reset_index()
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    df = activity.groupby('player_id')['event_date'].min().reset_index()

    return df.rename(columns = {'event_date':'first_login'})
```

</details>

<br>

## Approach 1: Grouping and Extracting the Minimum

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  A.player_id
FROM
  Activity A
GROUP BY
  A.player_id;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  A.player_id,
  MIN(A.event_date) AS first_login
FROM
  Activity A
GROUP BY
  A.player_id;
```

</details>

<br>

## Approach 2: Window functions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
  A.player_id,
  FIRST_VALUE(A.event_date) OVER (
    PARTITION BY
      A.player_id
    ORDER BY
      A.event_date
  ) AS first_login
FROM
  Activity A;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
  A.player_id,
  LAST_VALUE(A.event_date) OVER (
    PARTITION BY
      A.player_id
    ORDER BY
      A.event_date DESC RANGE BETWEEN UNBOUNDED PRECEDING
      AND UNBOUNDED FOLLOWING
  ) AS first_login
FROM
  Activity A;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  X.player_id,
  X.event_date AS first_login
FROM
  (
    SELECT
      A.player_id,
      A.event_date,
      RANK() OVER (
        PARTITION BY
          A.player_id
        ORDER BY
          A.event_date
      ) AS rnk
    FROM
      Activity A
  ) X
WHERE
  X.rnk = 1;
```

</details>
