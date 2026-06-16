# 1661. Average Time of Process per Machine

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/average-time-of-process-per-machine/)  
`Database`

**Problem Link:** [LeetCode 1661 - Average Time of Process per Machine](https://leetcode.com/problems/average-time-of-process-per-machine/)

## Problem

Table: Activity

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| machine_id     | int     |
| process_id     | int     |
| activity_type  | enum    |
| timestamp      | float   |
+----------------+---------+
The table shows the user activities for a factory website.
(machine_id, process_id, activity_type) is the primary key (combination of columns with unique values) of this table.
machine_id is the ID of a machine.
process_id is the ID of a process running on the machine with ID machine_id.
activity_type is an ENUM (category) of type ('start', 'end').
timestamp is a float representing the current time in seconds.
'start' means the machine starts the process at the given timestamp and 'end' means the machine ends the process at the given timestamp.
The 'start' timestamp will always be before the 'end' timestamp for every (machine_id, process_id) pair.
It is guaranteed that each (machine_id, process_id) pair has a 'start' and 'end' timestamp.
```

There is a factory website that has several machines each running the same number of processes. Write a solution to find the average time each machine takes to complete a process.

The time to complete a process is the 'end' timestamp minus the 'start' timestamp. The average time is calculated by the total time to complete every process on the machine divided by the number of processes that were run.

The resulting table should have the machine_id along with the average time as processing_time, which should be rounded to 3 decimal places.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Activity table:
+------------+------------+---------------+-----------+
| machine_id | process_id | activity_type | timestamp |
+------------+------------+---------------+-----------+
| 0          | 0          | start         | 0.712     |
| 0          | 0          | end           | 1.520     |
| 0          | 1          | start         | 3.140     |
| 0          | 1          | end           | 4.120     |
| 1          | 0          | start         | 0.550     |
| 1          | 0          | end           | 1.550     |
| 1          | 1          | start         | 0.430     |
| 1          | 1          | end           | 1.420     |
| 2          | 0          | start         | 4.100     |
| 2          | 0          | end           | 4.512     |
| 2          | 1          | start         | 2.500     |
| 2          | 1          | end           | 5.000     |
+------------+------------+---------------+-----------+
Output:
+------------+-----------------+
| machine_id | processing_time |
+------------+-----------------+
| 0          | 0.894           |
| 1          | 0.995           |
| 2          | 1.456           |
+------------+-----------------+
Explanation:
There are 3 machines running 2 processes each.
Machine 0's average time is ((1.520 - 0.712) + (4.120 - 3.140)) / 2 = 0.894
Machine 1's average time is ((1.550 - 0.550) + (1.420 - 0.430)) / 2 = 0.995
Machine 2's average time is ((4.512 - 4.100) + (5.000 - 2.500)) / 2 = 1.456
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

# Editorial - 1661. Average Time of Process per Machine

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Update Values with lambda and then Calculate | Pandas |
| Split One Column Into Two and then Calculate | Pandas |
| Transform Values with CASE WHEN and then Calculate | SQL |
| Calling the original Table twice and Calculate as two columns | SQL |

## Approach 1: Update Values with lambda and then Calculate

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:

    activity['timestamp'] = activity.apply(lambda x: x.timestamp * -1 if x.activity_type == 'start' else x.timestamp, axis=1)

    sum_machine_process = activity.groupby(['machine_id', 'process_id'], as_index=False)['timestamp'].sum()

    mean_machine = sum_machine_process.groupby(['machine_id'], as_index=False)['timestamp'].mean().round(3).rename(columns = {'timestamp': 'processing_time'})
    
    return mean_machine
```

</details>

<br>

## Approach 2: Split One Column Into Two and then Calculate

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    
    start_df = activity[activity['activity_type'] == 'start']
    
    end_df = activity[activity['activity_type'] == 'end']
    
    merge_df = end_df.merge(start_df, on = ['machine_id', 'process_id'])
    
    df = merge_df.assign(processing_time = merge_df['timestamp_x'] - merge_df['timestamp_y']).groupby(['machine_id'], as_index=False)['processing_time'].mean().round(3)

    return df
```

</details>

<br>

## Approach 1: Transform Values with CASE WHEN and then Calculate

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0/(SELECT COUNT(DISTINCT process_id))
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0/(SELECT COUNT(DISTINCT process_id)),3) AS processing_time
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    machine_id,
    ROUND(SUM(CASE WHEN activity_type='start' THEN timestamp*-1 ELSE timestamp END)*1.0
    / (SELECT COUNT(DISTINCT process_id)),3) AS processing_time
FROM 
    Activity
GROUP BY machine_id
```

</details>

<br>

## Approach 2: Calling the original Table twice and Calculate as two columns

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT *
FROM Activity a, 
     Activity b
WHERE 
    a.machine_id = b.machine_id
AND 
    a.process_id = b.process_id
AND 
    a.activity_type = 'start'
AND 
    b.activity_type = 'end'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT (b.timestamp - a.timestamp) AS processing_time
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT a.machine_id, 
       ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT a.machine_id, 
       ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
FROM Activity a, 
     Activity b
WHERE 
    a.machine_id = b.machine_id
AND 
    a.process_id = b.process_id
AND 
    a.activity_type = 'start'
AND 
    b.activity_type = 'end'
GROUP BY machine_id
```

</details>
