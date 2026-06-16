# 512. Game Play Analysis II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/game-play-analysis-ii/)  
`Database`

**Problem Link:** [LeetCode 512 - Game Play Analysis II](https://leetcode.com/problems/game-play-analysis-ii/)

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

Write a solution to report the device that is first logged in for each player.

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
+-----------+-----------+
| player_id | device_id |
+-----------+-----------+
| 1         | 2         |
| 2         | 3         |
| 3         | 1         |
+-----------+-----------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game Play Analysis I](https://leetcode.com/problems/game-play-analysis-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Game Play Analysis III](https://leetcode.com/problems/game-play-analysis-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 512. Game Play Analysis II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using `groupby` and `merge` | Pandas |
| Using `idxmin` | Pandas |
| Subquery and multi-value use of the `IN` comparison operator | SQL |
| Window functions | SQL |

## Approach 1: Using `groupby` and `merge`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Find the earliest event_date for each player
    min_event_dates = activity.groupby('player_id')['event_date'].min().reset_index()
    
    # Step 2: Merge the earliest event_dates with the original dataset to get the device_ids for those dates
    result = pd.merge(activity, min_event_dates, on=['player_id', 'event_date'])
    
    # Step 3: Keep only the required columns in the result
    result = result[['player_id', 'device_id']]
    
    # Step 4: Return the result
    return result
```

</details>

<br>

## Approach 2: Using `idxmin`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Find the index of the first login date for each player
    idx = activity.groupby('player_id')['event_date'].idxmin()
    
    # Step 2: Use the index to get the corresponding rows from the original DataFrame
    result = activity.loc[idx][['player_id', 'device_id']]

    # Step 3: Return the result
    return result
```

</details>

<br>

## Approach 1: Subquery and multi-value use of the `IN` comparison operator

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  A1.player_id,
  A1.device_id
FROM
  Activity A1
WHERE
  (A1.player_id, A1.event_date) IN (
    SELECT
      A2.player_id,
      MIN(A2.event_date)
    FROM
      Activity A2
    GROUP BY
      A2.player_id
  );
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH
  min_data AS (
    SELECT
      A.player_id,
      MIN(A.event_date) AS event_date
    FROM
      Activity A
    GROUP BY
      A.player_id
  )
SELECT
  A2.player_id,
  A2.device_id
FROM
  Activity A2
  INNER JOIN min_data M ON M.player_id = A2.player_id
  AND M.event_date = A2.event_date;
```

</details>

<br>

## Approach 2: Window functions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH
  ranked_logins AS (
    SELECT
      A.player_id,
      A.device_id,
      RANK() OVER (
        PARTITION BY
          A.player_id
        ORDER BY
          A.event_date
      ) AS rnk
    FROM
      Activity A
  )
SELECT
  RL.player_id,
  RL.device_id
FROM
  ranked_logins RL
WHERE
  RL.rnk = 1;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
  A.player_id,
  FIRST_VALUE(A.device_id) OVER (
    PARTITION BY
      A.player_id
    ORDER BY
      A.event_date
  ) AS device_id
FROM
  Activity A;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT
  A.player_id,
  LAST_VALUE(A.device_id) OVER (
    PARTITION BY
      A.player_id
    ORDER BY
      A.event_date DESC RANGE BETWEEN UNBOUNDED PRECEDING
      AND UNBOUNDED FOLLOWING
  ) AS device_id
FROM
  Activity A;
```

</details>
