# 3060. User Activities within Time Bounds

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/user-activities-within-time-bounds/)  
`Database`

**Problem Link:** [LeetCode 3060 - User Activities within Time Bounds](https://leetcode.com/problems/user-activities-within-time-bounds/)

## Problem

Table: Sessions

```text
+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| user_id       | int      |
| session_start | datetime |
| session_end   | datetime |
| session_id    | int      |
| session_type  | enum     |
+---------------+----------+
session_id is column of unique values for this table.
session_type is an ENUM (category) type of (Viewer, Streamer).
This table contains user id, session start, session end, session id and session type.
```

Write a solution to find the the users who have had at least two session of the same type (either 'Viewer' or 'Streamer') with a maximum gap of 12 hours between sessions.

Return the result table ordered by user_id in ascending order.

The result format is in the following example.

Example:

```text
Input:
Sessions table:
+---------+---------------------+---------------------+------------+--------------+
| user_id | session_start       | session_end         | session_id | session_type |
+---------+---------------------+---------------------+------------+--------------+
| 101     | 2023-11-01 08:00:00 | 2023-11-01 09:00:00 | 1          | Viewer       |
| 101     | 2023-11-01 10:00:00 | 2023-11-01 11:00:00 | 2          | Streamer     |
| 102     | 2023-11-01 13:00:00 | 2023-11-01 14:00:00 | 3          | Viewer       |
| 102     | 2023-11-01 15:00:00 | 2023-11-01 16:00:00 | 4          | Viewer       |
| 101     | 2023-11-02 09:00:00 | 2023-11-02 10:00:00 | 5          | Viewer       |
| 102     | 2023-11-02 12:00:00 | 2023-11-02 13:00:00 | 6          | Streamer     |
| 101     | 2023-11-02 13:00:00 | 2023-11-02 14:00:00 | 7          | Streamer     |
| 102     | 2023-11-02 16:00:00 | 2023-11-02 17:00:00 | 8          | Viewer       |
| 103     | 2023-11-01 08:00:00 | 2023-11-01 09:00:00 | 9          | Viewer       |
| 103     | 2023-11-02 20:00:00 | 2023-11-02 23:00:00 | 10         | Viewer       |
| 103     | 2023-11-03 09:00:00 | 2023-11-03 10:00:00 | 11         | Viewer       |
+---------+---------------------+---------------------+------------+--------------+
Output:
+---------+
| user_id |
+---------+
| 102     |
| 103     |
+---------+
Explanation:
- User ID 101 will not be included in the final output as they do not have any two sessions of the same session type.
- User ID 102 will be included in the final output as they had two viewer sessions with session IDs 3 and 4, respectively, and the time gap between them was less than 12 hours.
- User ID 103 participated in two viewer sessions with a gap of less than 12 hours between them, identified by session IDs 10 and 11. Therefore, user 103 will be included in the final output.
Output table is ordered by user_id in increasing order.
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

# Editorial - 3060. User Activities within Time Bounds

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting and Filtering | Pandas |
| Approach: Window Functions | MySQL |

## Approach: Sorting and Filtering

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def user_activities(sessions: pd.DataFrame) -> pd.DataFrame:
    df = sessions.sort_values(
        ["user_id", "session_type", "session_start", "session_end"]
    )
    df = df.loc[
        (df["user_id"] == df["user_id"].shift(-1))
        & (df["session_type"] == df["session_type"].shift(-1))
        & (
            df["session_end"]
            >= df["session_start"].shift(-1) - pd.Timedelta(12, unit="H")
        )
    ]
    return df[["user_id"]].drop_duplicates()
```

</details>

<br>

## Approach: Window Functions

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
  DISTINCT a.user_id 
FROM 
  (
    SELECT 
      s1.user_id, 
      s1.session_type, 
      s1.session_end, 
      LEAD(s1.session_start) OVER(
        PARTITION BY s1.user_id, 
        s1.session_type 
        ORDER BY 
          s1.session_start
      ) AS next_session_start 
    FROM 
      Sessions s1
  ) a 
WHERE 
  a.next_session_start IS NOT NULL 
  AND TIMESTAMPDIFF(
    HOUR, a.session_end, a.next_session_start
  ) <= 12;
```

</details>
