# 1635. Hopper Company Queries I

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/hopper-company-queries-i/)  
`Database`

**Problem Link:** [LeetCode 1635 - Hopper Company Queries I](https://leetcode.com/problems/hopper-company-queries-i/)

## Problem

Table: Drivers

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| driver_id   | int     |
| join_date   | date    |
+-------------+---------+
driver_id is the primary key (column with unique values) for this table.
Each row of this table contains the driver's ID and the date they joined the Hopper company.
```

Table: Rides

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| ride_id      | int     |
| user_id      | int     |
| requested_at | date    |
+--------------+---------+
ride_id is the primary key (column with unique values) for this table.
Each row of this table contains the ID of a ride, the user's ID that requested it, and the day they requested it.
There may be some ride requests in this table that were not accepted.
```

Table: AcceptedRides

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| ride_id       | int     |
| driver_id     | int     |
| ride_distance | int     |
| ride_duration | int     |
+---------------+---------+
ride_id is the primary key (column with unique values) for this table.
Each row of this table contains some information about an accepted ride.
It is guaranteed that each accepted ride exists in the Rides table.
```

Write a solution to report the following statistics for each month of 2020:

- The number of drivers currently with the Hopper company by the end of the month (active_drivers).
- The number of accepted rides in that month (accepted_rides).

Return the result table ordered by month in ascending order, where month is the month's number (January is 1, February is 2, etc.).

The result format is in the following example.

### Example 1

```text
Input:
Drivers table:
+-----------+------------+
| driver_id | join_date  |
+-----------+------------+
| 10        | 2019-12-10 |
| 8         | 2020-1-13  |
| 5         | 2020-2-16  |
| 7         | 2020-3-8   |
| 4         | 2020-5-17  |
| 1         | 2020-10-24 |
| 6         | 2021-1-5   |
+-----------+------------+
Rides table:
+---------+---------+--------------+
| ride_id | user_id | requested_at |
+---------+---------+--------------+
| 6       | 75      | 2019-12-9    |
| 1       | 54      | 2020-2-9     |
| 10      | 63      | 2020-3-4     |
| 19      | 39      | 2020-4-6     |
| 3       | 41      | 2020-6-3     |
| 13      | 52      | 2020-6-22    |
| 7       | 69      | 2020-7-16    |
| 17      | 70      | 2020-8-25    |
| 20      | 81      | 2020-11-2    |
| 5       | 57      | 2020-11-9    |
| 2       | 42      | 2020-12-9    |
| 11      | 68      | 2021-1-11    |
| 15      | 32      | 2021-1-17    |
| 12      | 11      | 2021-1-19    |
| 14      | 18      | 2021-1-27    |
+---------+---------+--------------+
AcceptedRides table:
+---------+-----------+---------------+---------------+
| ride_id | driver_id | ride_distance | ride_duration |
+---------+-----------+---------------+---------------+
| 10      | 10        | 63            | 38            |
| 13      | 10        | 73            | 96            |
| 7       | 8         | 100           | 28            |
| 17      | 7         | 119           | 68            |
| 20      | 1         | 121           | 92            |
| 5       | 7         | 42            | 101           |
| 2       | 4         | 6             | 38            |
| 11      | 8         | 37            | 43            |
| 15      | 8         | 108           | 82            |
| 12      | 8         | 38            | 34            |
| 14      | 1         | 90            | 74            |
+---------+-----------+---------------+---------------+
Output:
+-------+----------------+----------------+
| month | active_drivers | accepted_rides |
+-------+----------------+----------------+
| 1     | 2              | 0              |
| 2     | 3              | 0              |
| 3     | 4              | 1              |
| 4     | 4              | 0              |
| 5     | 5              | 0              |
| 6     | 5              | 1              |
| 7     | 5              | 1              |
| 8     | 5              | 1              |
| 9     | 5              | 0              |
| 10    | 6              | 0              |
| 11    | 6              | 2              |
| 12    | 6              | 1              |
+-------+----------------+----------------+
Explanation:
By the end of January --> two active drivers (10, 8) and no accepted rides.
By the end of February --> three active drivers (10, 8, 5) and no accepted rides.
By the end of March --> four active drivers (10, 8, 5, 7) and one accepted ride (10).
By the end of April --> four active drivers (10, 8, 5, 7) and no accepted rides.
By the end of May --> five active drivers (10, 8, 5, 7, 4) and no accepted rides.
By the end of June --> five active drivers (10, 8, 5, 7, 4) and one accepted ride (13).
By the end of July --> five active drivers (10, 8, 5, 7, 4) and one accepted ride (7).
By the end of August --> five active drivers (10, 8, 5, 7, 4) and one accepted ride (17).
By the end of September --> five active drivers (10, 8, 5, 7, 4) and no accepted rides.
By the end of October --> six active drivers (10, 8, 5, 7, 4, 1) and no accepted rides.
By the end of November --> six active drivers (10, 8, 5, 7, 4, 1) and two accepted rides (20, 5).
By the end of December --> six active drivers (10, 8, 5, 7, 4, 1) and one accepted ride (2).
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Trips and Users](https://leetcode.com/problems/trips-and-users/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Hopper Company Queries II](https://leetcode.com/problems/hopper-company-queries-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Hopper Company Queries III](https://leetcode.com/problems/hopper-company-queries-iii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Times a Driver Was a Passenger](https://leetcode.com/problems/number-of-times-a-driver-was-a-passenger/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1635. Hopper Company Queries I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Conditional Joins with Sub DataFrames | Pandas |
| Approach: LEFT JOIN with CTEs | SQL |

## Approach: Conditional Joins with Sub DataFrames

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def hopper_company(drivers: pd.DataFrame, rides: pd.DataFrame, accepted_rides: pd.DataFrame) -> pd.DataFrame:
    # Approach: Subquery Constraint Tables, Left Join on months after
    # months list for series creation
    months = pd.DataFrame([num + 1 for num in range(12)], columns=["month"])

    # convert join_date to datetime
    drivers['join_date'] = pd.to_datetime(drivers['join_date'])

    # driver table - calculate active drivers that joined in 2020 or before
    driver = drivers[drivers['join_date'] < '2021-01-01']

    # utilize .apply() lambda function
    # -> if year is 2020 -> return 1, else return month
    driver['join_date'] = driver['join_date'].apply(lambda x: 1 if x.year != 2020 else x.month)

    # grab count of each active driver per month
    driver_count = driver.groupby('join_date').size().reset_index(name='active_drivers')

    # join driver with months to create driver_count, aggregate over months
    driver_months = months.merge(driver_count, how='left', left_on='month', right_on='join_date').fillna(0)
    driver_months['active_drivers'] = driver_months['active_drivers'].cumsum()
    
    # join rides with accepted rides -> left join rides
    all_rides = accepted_rides.merge(rides, how='left', on='ride_id')

    # convert requested_at to type datetime
    all_rides['requested_at'] = pd.to_datetime(all_rides['requested_at'])

    # filter for requested year in 2020 and driver_id is currently a driver
    all_rides = all_rides[(all_rides['requested_at'] > '2019-12-31') & (all_rides['requested_at'] < '2021-01-01')]
    all_rides = all_rides[all_rides['driver_id'].isin(driver['driver_id'])]

    # convert requested_at back to string & convert to month only using apply()
    all_rides['requested_at'] = all_rides['requested_at'].apply(lambda x: 1 if x.year != 2020 else x.month)

    # create accepted_rides by left joining driver months & all rides
    accepted_rides = driver_months.merge(all_rides, how='left', left_on='month', right_on='requested_at')

    # gather count of accepted rides by month
    accepted_rides = accepted_rides.groupby('month')['requested_at'].count().reset_index(name='accepted_rides')
  
    # merge result with accepted_rides - RIGHT JOIN
    result = driver_months.merge(accepted_rides, how='right', on='month')

    # grab necessary columns, clear NaNs, apply as int
    result = result[['month', 'active_drivers', 'accepted_rides']].fillna(0).astype(int)
    
    return result
```

</details>

<br>

## Approach: LEFT JOIN with CTEs

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH RECURSIVE Months AS (
    SELECT 
        1 AS month
    UNION ALL
    SELECT 
        month + 1
    FROM 
        Months
    WHERE 
        month < 12
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
Driver AS (
    SELECT 
        driver_id, 
	    (CASE WHEN YEAR(join_date) = 2019 THEN '1' ELSE MONTH(join_date) END) AS month
	FROM 
        Drivers 
	WHERE 
        YEAR(join_date) <= 2020
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
Ride AS (
    SELECT 
        MONTH(requested_at) AS month, 
        a.ride_id
    FROM 
        AcceptedRides AS a 
    INNER JOIN 
        Rides r
    ON 
        r.ride_id = a.ride_id
    WHERE 
        YEAR(requested_at) = 2020
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    m.month, 
    COUNT(DISTINCT d.driver_id) AS active_drivers,
    COUNT(DISTINCT r.ride_id) AS accepted_rides 
FROM
    Months AS m
LEFT JOIN
    Driver AS d
ON 
    d.month <= m.month
LEFT JOIN
    Ride AS r
ON 
    m.month = r.month
GROUP BY 
    m.month 
ORDER BY 
    m.month
```

</details>
