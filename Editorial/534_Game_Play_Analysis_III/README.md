# 534. Game Play Analysis III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/game-play-analysis-iii/)  
`Database`

**Problem Link:** [LeetCode 534 - Game Play Analysis III](https://leetcode.com/problems/game-play-analysis-iii/)

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
(player_id, event_date) is the primary key (column with unique values) of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.
```

Write a solution to report for each player and date, how many games played so far by the player. That is, the total number of games played by the player until that date. Check the example for clarity.

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
| 1         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output:
+-----------+------------+---------------------+
| player_id | event_date | games_played_so_far |
+-----------+------------+---------------------+
| 1         | 2016-03-01 | 5                   |
| 1         | 2016-05-02 | 11                  |
| 1         | 2017-06-25 | 12                  |
| 3         | 2016-03-02 | 0                   |
| 3         | 2018-07-03 | 5                   |
+-----------+------------+---------------------+
Explanation:
For the player with id 1, 5 + 6 = 11 games played by 2016-05-02, and 5 + 6 + 1 = 12 games played by 2017-06-25.
For the player with id 3, 0 + 5 = 5 games played by 2018-07-03.
Note that for each player we only care about the days when the player logged in.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Game Play Analysis II](https://leetcode.com/problems/game-play-analysis-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 534. Game Play Analysis III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Window Functions - Using `groupby` and `cumsum` | Pandas |
| Self-Join and Aggregation | Pandas |
| Non-equi self join |  |

## Approach 1: Window Functions - Using `groupby` and `cumsum`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Sort the DataFrame based on the event date
    # It ensures that we are considering the events in chronological order before calculating the cumulative sum
    activity.sort_values('event_date', inplace=True)
    
    # Step 2: Group the data by 'player_id' and within each group, calculate the cumulative sum of 'games_played'
    # The groupby function creates separate groups for each player, and the cumsum function calculates the cumulative sum of games played in each group
    activity['games_played_so_far'] = activity.groupby('player_id')['games_played'].cumsum()
    
    # Step 3: Select only the necessary columns for the final result
    # Here we are creating a new dataframe that consists only of the 'player_id', 'event_date', and 'games_played_so_far' columns
    result = activity[['player_id', 'event_date', 'games_played_so_far']]
    
    # Step 4: Return the resulting DataFrame
    # Finally, we return the resulting dataframe which contains the cumulative sum of games played by each player till each event date
    return result
```

</details>

<br>

## Approach 2: Self-Join and Aggregation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Perform a self-join on the 'player_id' column to create a merged dataframe.
    # This operation will pair each row with every other row that has the same player_id, 
    # creating a dataframe that contains all possible pairs of event dates for each player.
    merged_df = activity.merge(activity, on='player_id', suffixes=('', '_other'))
    
    # Step 2: Filter the merged dataframe to retain only the rows where the event_date from 
    # the "other" part is less than or equal to the event_date from the current row. This ensures 
    # that for each pair of rows in the merged dataframe, we only consider the historical data up 
    # to the current date.
    merged_df = merged_df[merged_df['event_date_other'] <= merged_df['event_date']]
    
    # Step 3: Group the filtered dataframe by 'player_id' and 'event_date', and for each group, 
    # sum the 'games_played' values from the "other" part. This calculates the cumulative sum of 
    # games played by a player up to each event date.
    result = (
        merged_df
        .groupby(['player_id', 'event_date'])
        .agg(games_played_so_far=('games_played_other', 'sum'))
        .reset_index()
    )
    
    # Step 4: Return the resulting dataframe which contains the 'player_id', 'event_date', and 
    # the calculated cumulative sum of games played up to each date.
    return result
```

</details>

<br>

## Approach 2: Non-equi self join

### Implementation
