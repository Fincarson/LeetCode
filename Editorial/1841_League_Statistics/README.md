# 1841. League Statistics

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/league-statistics/)  
`Database`

**Problem Link:** [LeetCode 1841 - League Statistics](https://leetcode.com/problems/league-statistics/)

## Problem

Table: Teams

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| team_id        | int     |
| team_name      | varchar |
+----------------+---------+
team_id is the column with unique values for this table.
Each row contains information about one team in the league.
```

Table: Matches

```text
+-----------------+---------+
| Column Name     | Type    |
+-----------------+---------+
| home_team_id    | int     |
| away_team_id    | int     |
| home_team_goals | int     |
| away_team_goals | int     |
+-----------------+---------+
(home_team_id, away_team_id) is the primary key (combination of columns with unique values) for this table.
Each row contains information about one match.
home_team_goals is the number of goals scored by the home team.
away_team_goals is the number of goals scored by the away team.
The winner of the match is the team with the higher number of goals.
```

Write a solution to report the statistics of the league. The statistics should be built using the played matches where the winning team gets three points and the losing team gets no points. If a match ends with a draw, both teams get one point.

Each row of the result table should contain:

- team_name - The name of the team in the Teams table.
- matches_played - The number of matches played as either a home or away team.
- points - The total points the team has so far.
- goal_for - The total number of goals scored by the team across all matches.
- goal_against - The total number of goals scored by opponent teams against this team across all matches.
- goal_diff - The result of goal_for - goal_against.

Return the result table ordered by points in descending order. If two or more teams have the same points, order them by goal_diff in descending order. If there is still a tie, order them by team_name in lexicographical order.

The result format is in the following example.

### Example 1

```text
Input:
Teams table:
+---------+-----------+
| team_id | team_name |
+---------+-----------+
| 1       | Ajax      |
| 4       | Dortmund  |
| 6       | Arsenal   |
+---------+-----------+
Matches table:
+--------------+--------------+-----------------+-----------------+
| home_team_id | away_team_id | home_team_goals | away_team_goals |
+--------------+--------------+-----------------+-----------------+
| 1            | 4            | 0               | 1               |
| 1            | 6            | 3               | 3               |
| 4            | 1            | 5               | 2               |
| 6            | 1            | 0               | 0               |
+--------------+--------------+-----------------+-----------------+
Output:
+-----------+----------------+--------+----------+--------------+-----------+
| team_name | matches_played | points | goal_for | goal_against | goal_diff |
+-----------+----------------+--------+----------+--------------+-----------+
| Dortmund  | 2              | 6      | 6        | 2            | 4         |
| Arsenal   | 2              | 2      | 3        | 3            | 0         |
| Ajax      | 4              | 2      | 5        | 9            | -4        |
+-----------+----------------+--------+----------+--------------+-----------+
Explanation:
Ajax (team_id=1) played 4 matches: 2 losses and 2 draws. Total points = 0 + 0 + 1 + 1 = 2.
Dortmund (team_id=4) played 2 matches: 2 wins. Total points = 3 + 3 = 6.
Arsenal (team_id=6) played 2 matches: 2 draws. Total points = 1 + 1 = 2.
Dortmund is the first team in the table. Ajax and Arsenal have the same points, but since Arsenal has a higher goal_diff than Ajax, Arsenal comes before Ajax in the table.
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

# Editorial - 1841. League Statistics

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: DataFrame Manipulation | Pandas |
| Approach: Aggregate Ranking |  |

## Approach: DataFrame Manipulation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def league_statistics(teams: pd.DataFrame, matches: pd.DataFrame) -> pd.DataFrame:
    # Merging the teams with matches twice for home and away
    home_matches = pd.merge(matches, teams, left_on="home_team_id", right_on="team_id")
    away_matches = pd.merge(matches, teams, left_on="away_team_id", right_on="team_id")

    # Calculating points, goals for, and goals against for home and away matches
    home_matches["points"] = home_matches.apply(
        lambda x: 3
        if x["home_team_goals"] > x["away_team_goals"]
        else (1 if x["home_team_goals"] == x["away_team_goals"] else 0),
        axis=1,
    )
    home_matches["goal_for"] = home_matches["home_team_goals"]
    home_matches["goal_against"] = home_matches["away_team_goals"]

    away_matches["points"] = away_matches.apply(
        lambda x: 3
        if x["away_team_goals"] > x["home_team_goals"]
        else (1 if x["home_team_goals"] == x["away_team_goals"] else 0),
        axis=1,
    )
    away_matches["goal_for"] = away_matches["away_team_goals"]
    away_matches["goal_against"] = away_matches["home_team_goals"]

    # Concatenating the home and away results
    total_matches = pd.concat([home_matches, away_matches])

    # Grouping by team and calculating aggregates
    result = (
        total_matches.groupby("team_name")
        .agg(
            {
                "team_id": "count",
                "points": "sum",
                "goal_for": "sum",
                "goal_against": "sum",
            }
        )
        .rename(columns={"team_id": "matches_played"})
    )

    # Calculating goal difference
    result["goal_diff"] = result["goal_for"] - result["goal_against"]

    # Sorting the result
    result = result.sort_values(
        by=["points", "goal_diff", "team_name"], ascending=[False, False, True]
    )

    return result.reset_index()
```

</details>

<br>

## Approach: Aggregate Ranking

### Implementation
