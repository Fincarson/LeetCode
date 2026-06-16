# 1194. Tournament Winners

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/tournament-winners/)  
`Database`

**Problem Link:** [LeetCode 1194 - Tournament Winners](https://leetcode.com/problems/tournament-winners/)

## Problem

Table: Players

```text
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| player_id   | int   |
| group_id    | int   |
+-------------+-------+
player_id is the primary key (column with unique values) of this table.
Each row of this table indicates the group of each player.
```

Table: Matches

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| match_id      | int     |
| first_player  | int     |
| second_player | int     |
| first_score   | int     |
| second_score  | int     |
+---------------+---------+
match_id is the primary key (column with unique values) of this table.
Each row is a record of a match, first_player and second_player contain the player_id of each match.
first_score and second_score contain the number of points of the first_player and second_player respectively.
You may assume that, in each match, players belong to the same group.
```

The winner in each group is the player who scored the maximum total points within the group. In the case of a tie, the lowest player_id wins.

Write a solution to find the winner in each group.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Players table:
+-----------+------------+
| player_id | group_id   |
+-----------+------------+
| 15        | 1          |
| 25        | 1          |
| 30        | 1          |
| 45        | 1          |
| 10        | 2          |
| 35        | 2          |
| 50        | 2          |
| 20        | 3          |
| 40        | 3          |
+-----------+------------+
Matches table:
+------------+--------------+---------------+-------------+--------------+
| match_id   | first_player | second_player | first_score | second_score |
+------------+--------------+---------------+-------------+--------------+
| 1          | 15           | 45            | 3           | 0            |
| 2          | 30           | 25            | 1           | 2            |
| 3          | 30           | 15            | 2           | 0            |
| 4          | 40           | 20            | 5           | 2            |
| 5          | 35           | 50            | 1           | 1            |
+------------+--------------+---------------+-------------+--------------+
Output:
+-----------+------------+
| group_id  | player_id  |
+-----------+------------+
| 1         | 15         |
| 2         | 35         |
| 3         | 40         |
+-----------+------------+
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

# Editorial - 1194. Tournament Winners

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Aggregated Score Ranking Method | Pandas |
| Approach: Grouped Window Ranking Method | SQL |

## Approach: Aggregated Score Ranking Method

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def tournament_winners(
    players_df: pd.DataFrame, matches_df: pd.DataFrame
) -> pd.DataFrame:
    # Aggregate scores for each player when they are the first player
    scores_as_first_player = matches_df.groupby("first_player")["first_score"].sum()

    # Aggregate scores for each player when they are the second player
    scores_as_second_player = matches_df.groupby("second_player")["second_score"].sum()

    # Combine the scores from both roles (first and second player)
    total_scores = scores_as_first_player.add(
        scores_as_second_player, fill_value=0
    ).reset_index(name="total_score")

    # Merge the total scores with the players DataFrame
    players_with_scores = players_df.merge(
        total_scores, left_on="player_id", right_on="index"
    )

    # Sort by total score (descending) and player_id (ascending) for tie-breaking
    players_with_scores.sort_values(
        ["total_score", "player_id"], ascending=[False, True], inplace=True
    )

    # Select the top player from each group
    winners = players_with_scores.groupby("group_id").head(1)[["group_id", "player_id"]]

    return winners
```

</details>

<br>

## Approach: Grouped Window Ranking Method

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   WITH PlayerScores AS (
       SELECT first_player AS player_id, first_score AS score 
       FROM matches 
       UNION ALL 
       SELECT second_player AS player_id, second_score AS    score 
       FROM matches
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   TotalScores AS (
       SELECT player_id, SUM(score) AS total_score 
       FROM PlayerScores 
       GROUP BY player_id
   )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT DISTINCT group_id, 
       FIRST_VALUE(TotalScores.player_id) OVER (
           PARTITION BY group_id 
           ORDER BY total_score DESC, TotalScores.player_id
       ) AS player_id
   FROM TotalScores 
   LEFT JOIN players ON TotalScores.player_id = players.player_id
```

</details>
