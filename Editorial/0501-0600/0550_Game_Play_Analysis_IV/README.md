# 550. Game Play Analysis IV

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/game-play-analysis-iv/)  
`Database`

**Problem Link:** [LeetCode 550 - Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/)

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

Write a solution to report the fraction of players that logged in again on the day after the day they first logged in, rounded to 2 decimal places. In other words, you need to determine the number of players who logged in on the day immediately following their initial login, and divide it by the number of total players.

The result format is in the following example.

### Example 1

```text
Input:
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output:
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
Explanation:
Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game Play Analysis III](https://leetcode.com/problems/game-play-analysis-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Game Play Analysis V](https://leetcode.com/problems/game-play-analysis-v/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 550. Game Play Analysis IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Date Manipulation and Conditional Aggregation | Python3, Pandas |
| Subqueries and multi-value use of the `IN` comparison operator | SQL, MySQL |
| CTEs and `INNER JOIN` | MySQL |

## Approach 1: Date Manipulation and Conditional Aggregation

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
first_login = activity.groupby('player_id')['event_date'].min().reset_index()
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
activity['day_before_event'] = activity['event_date'] - pd.to_timedelta(1, unit='D')
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
merged_df = activity.merge(first_login, on='player_id', suffixes=('_actual', '_first'))
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
consecutive_login = merged_df[merged_df['day_before_event'] == merged_df['event_date_first']]
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
fraction = round(consecutive_login['player_id'].nunique() / activity['player_id'].nunique(), 2)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
output_df = pd.DataFrame({'fraction': [fraction]})
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Find the first login date for each player
    first_login = activity.groupby('player_id')['event_date'].min().reset_index()
    
    # Step 2: Create a new column for the day before each event_date in the original DataFrame
    activity['day_before_event'] = activity['event_date'] - pd.to_timedelta(1, unit='D')
    
    # Step 3: Merge the dataframes to find rows where player logged in a day after their first login
    merged_df = activity.merge(first_login, on='player_id', suffixes=('_actual', '_first'))
    
    # Step 4: Find the rows where the actual event date matches the day after the first login date
    consecutive_login = merged_df[merged_df['day_before_event'] == merged_df['event_date_first']]
    
    # Step 5: Calculate the fraction of players that logged in again on the day after their first login
    fraction = round(consecutive_login['player_id'].nunique() / activity['player_id'].nunique(), 2)
    
    # Step 6: Create a dataframe to hold the output
    output_df = pd.DataFrame({'fraction': [fraction]})
    
    return output_df
```

</details>

<br>

## Approach 1: Subqueries and multi-value use of the `IN` comparison operator

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
(val1, val2) IN (
  SELECT
    A.player_id,
    MIN(A.event_date) AS first_login
  FROM
    Activity A
  GROUP BY
    A.player_id
)
```

</details>

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  ROUND(
    COUNT(A1.player_id)
    / (SELECT COUNT(DISTINCT A3.player_id) FROM Activity A3)
  , 2) AS fraction
FROM
  Activity A1
WHERE
  (A1.player_id, DATE_SUB(A1.event_date, INTERVAL 1 DAY)) IN (
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

<br>

## Approach 2: CTEs and `INNER JOIN`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
WITH first_logins AS (
  SELECT
    A.player_id,
    MIN(A.event_date) AS first_login
  FROM
    Activity A
  GROUP BY
    A.player_id
), consec_logins AS (
  SELECT
    COUNT(A.player_id) AS num_logins
  FROM
    first_logins F
    INNER JOIN Activity A ON F.player_id = A.player_id
    AND F.first_login = DATE_SUB(A.event_date, INTERVAL 1 DAY)
)
SELECT
  ROUND(
    (SELECT C.num_logins FROM consec_logins C)
    / (SELECT COUNT(F.player_id) FROM first_logins F)
  , 2) AS fraction;
```

</details>
