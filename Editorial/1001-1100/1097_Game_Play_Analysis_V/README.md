# 1097. Game Play Analysis V

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/game-play-analysis-v/)  
`Database`

**Problem Link:** [LeetCode 1097 - Game Play Analysis V](https://leetcode.com/problems/game-play-analysis-v/)

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

The install date of a player is the first login day of that player.

We define day one retention of some date x to be the number of players whose install date is x and they logged back in on the day right after x, divided by the number of players whose install date is x, rounded to 2 decimal places.

Write a solution to report for each install date, the number of players that installed the game on that day, and the day one retention.

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
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-01 | 0            |
| 3         | 4         | 2016-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output:
+------------+----------+----------------+
| install_dt | installs | Day1_retention |
+------------+----------+----------------+
| 2016-03-01 | 2        | 0.50           |
| 2017-06-25 | 1        | 0.00           |
+------------+----------+----------------+
Explanation:
Player 1 and 3 installed the game on 2016-03-01 but only player 1 logged back in on 2016-03-02 so the day 1 retention of 2016-03-01 is 1 / 2 = 0.50
Player 2 installed the game on 2017-06-25 but didn't log back in on 2017-06-26 so the day 1 retention of 2017-06-25 is 0 / 1 = 0.00
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1097. Game Play Analysis V

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Data Aggregation and Transformation | Pandas |
| Approach: CTEs, indicator variable, and `LEFT JOIN` | MySQL |

## Approach: Data Aggregation and Transformation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def custom_round(x, decimals=2):
    offset = 10 ** decimals
    return int(x * offset + 0.5) / offset

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:

    # Find the minimum event_date for each player, which is the install date
    install_dates = activity.groupby("player_id")["event_date"].min().reset_index()
    install_dates.columns = ["player_id", "install_dt"]

    # Merge the original DataFrame with the install dates to find the next day's activity
    next_day_activity = pd.merge(
        install_dates, activity, on="player_id"
    )
    next_day_activity = next_day_activity[
        next_day_activity["event_date"]
        == next_day_activity["install_dt"] + pd.Timedelta(days=1)
    ]

    # Group by install date and calculate installs and Day 1 Retention
    result = install_dates.groupby("install_dt").size().reset_index(name="installs")
    day1_retention = (
        next_day_activity.groupby("install_dt")
        .size()
        .reset_index(name="next_day_count")
    )

    result = pd.merge(result, day1_retention, on="install_dt", how="left")
    result["next_day_count"].fillna(0, inplace=True)

    # Using the custom round function
    result["Day1_retention"] = result["next_day_count"] / result["installs"]
    result["Day1_retention"] = result["Day1_retention"].apply(
        lambda x: custom_round(x, 2)
    )

    # Keep only the columns install_dt, installs, and Day1_retention
    result = result[["install_dt", "installs", "Day1_retention"]]

    return result
```

</details>

<br>

## Approach: CTEs, indicator variable, and `LEFT JOIN`

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
), consec_login_info AS (
  SELECT
    F.player_id,
    (CASE
      WHEN A.player_id IS NULL THEN 0
      ELSE 1
    END) AS logged_in_consecutively,
    F.first_login
  FROM
    first_logins F
    LEFT JOIN Activity A ON F.player_id = A.player_id
    AND F.first_login = DATE_SUB(A.event_date, INTERVAL 1 DAY)
)
SELECT
  C.first_login AS install_dt,
  COUNT(C.player_id) AS installs,
  ROUND(
    SUM(C.logged_in_consecutively)
    / COUNT(C.player_id)
  , 2) AS Day1_Retention
FROM
  consec_login_info C
GROUP BY
  C.first_login;
```

</details>

<details>
<summary><strong>MySQL</strong></summary>

```sql
+-----------+-------------------------+-------------+
| player_id | logged_in_consecutively | first_login |
+-----------+-------------------------+-------------+
|         1 |                       1 | 2016-03-01  |
|         2 |                       0 | 2017-06-25  |
|         3 |                       0 | 2016-03-01  |
+-----------+-------------------------+-------------+
```

</details>
