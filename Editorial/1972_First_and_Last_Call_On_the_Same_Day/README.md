# 1972. First and Last Call On the Same Day

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/first-and-last-call-on-the-same-day/)  
`Database`

**Problem Link:** [LeetCode 1972 - First and Last Call On the Same Day](https://leetcode.com/problems/first-and-last-call-on-the-same-day/)

## Problem

Table: Calls

```text
+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| caller_id    | int      |
| recipient_id | int      |
| call_time    | datetime |
+--------------+----------+
(caller_id, recipient_id, call_time) is the primary key (combination of columns with unique values) for this table.
Each row contains information about the time of a phone call between caller_id and recipient_id.
```

Write a solution to report the IDs of the users whose first and last calls on any day were with the same person. Calls are counted regardless of being the caller or the recipient.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Calls table:
+-----------+--------------+---------------------+
| caller_id | recipient_id | call_time           |
+-----------+--------------+---------------------+
| 8         | 4            | 2021-08-24 17:46:07 |
| 4         | 8            | 2021-08-24 19:57:13 |
| 5         | 1            | 2021-08-11 05:28:44 |
| 8         | 3            | 2021-08-17 04:04:15 |
| 11        | 3            | 2021-08-17 13:07:00 |
| 8         | 11           | 2021-08-17 22:22:22 |
+-----------+--------------+---------------------+
Output:
+---------+
| user_id |
+---------+
| 1       |
| 4       |
| 5       |
| 8       |
+---------+
Explanation:
On 2021-08-24, the first and last call of this day for user 8 was with user 4. User 8 should be included in the answer.
Similarly, user 4 on 2021-08-24 had their first and last call with user 8. User 4 should be included in the answer.
On 2021-08-11, user 1 and 5 had a call. This call was the only call for both of them on this day. Since this call is the first and last call of the day for both of them, they should both be included in the answer.
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

# Editorial - 1972. First and Last Call On the Same Day

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dual Perspective Call Analysis | Pandas |
| Approach: Dual-Ranking Unified Call Analysis | SQL |

## Approach: Dual Perspective Call Analysis

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def same_day_calls(calls: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Create a unified view of calls
    # Each call is represented twice, from both caller's and recipient's perspectives.
    unified_calls = pd.concat(
        [
            calls,
            calls.rename(
                columns={"caller_id": "recipient_id", "recipient_id": "caller_id"}
            ),
        ],
        ignore_index=True,
    )

    # Step 2: Extract the date part from call_time to identify the call day
    unified_calls["call_day"] = unified_calls["call_time"].dt.date

    # Step 3: Identify the first (earliest) and last (latest) calls of each day for each user
    # Group by call_day and caller_id, then find the index of the min/max call_time
    first_call_indices = unified_calls.groupby(["call_day", "caller_id"])[
        "call_time"
    ].idxmin()
    last_call_indices = unified_calls.groupby(["call_day", "caller_id"])[
        "call_time"
    ].idxmax()

    first_calls = unified_calls.loc[first_call_indices]
    last_calls = unified_calls.loc[last_call_indices]

    # Step 4: Merge first and last calls to find users whose first and last calls are with the same recipient
    merged_calls = first_calls.merge(
        last_calls, on=["caller_id", "recipient_id", "call_day"]
    )

    # Step 5: Prepare the final output
    # Select unique caller_id and rename to user_id
    result = (
        merged_calls[["caller_id"]]
        .rename(columns={"caller_id": "user_id"})
        .drop_duplicates()
    )

    return result
```

</details>

<br>

## Approach: Dual-Ranking Unified Call Analysis

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH UnifiedCalls AS (
  -- Include calls where the user is the caller
  SELECT 
    caller_id AS user_id, 
    call_time, 
    recipient_id AS other_participant_id 
  FROM 
    Calls 
  UNION 
    -- Include calls where the user is the recipient
  SELECT 
    recipient_id AS user_id, 
    call_time, 
    caller_id AS other_participant_id 
  FROM 
    Calls
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
RankedCalls AS (
  SELECT 
    user_id, 
    other_participant_id, 
    DATE(call_time) AS call_date, 
    -- Extracting just the date part of call_time
    DENSE_RANK() OVER (
      PARTITION BY user_id, 
      DATE(call_time) 
      ORDER BY 
        call_time ASC
    ) AS rank_earliest_call, 
    DENSE_RANK() OVER (
      PARTITION BY user_id, 
      DATE(call_time) 
      ORDER BY 
        call_time DESC
    ) AS rank_latest_call 
  FROM 
    UnifiedCalls
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT user_id 
FROM 
  RankedCalls 
WHERE 
  rank_earliest_call = 1 
  OR rank_latest_call = 1 -- Filtering for first and last calls
GROUP BY 
  user_id, 
  call_date 
HAVING 
  COUNT(DISTINCT other_participant_id) = 1;
```

</details>
