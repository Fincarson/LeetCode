# 262. Trips and Users

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/trips-and-users/)  
`Database`

**Problem Link:** [LeetCode 262 - Trips and Users](https://leetcode.com/problems/trips-and-users/)

## Problem

Table: Trips

```text
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| client_id   | int      |
| driver_id   | int      |
| city_id     | int      |
| status      | enum     |
| request_at  | varchar  |
+-------------+----------+
id is the primary key (column with unique values) for this table.
The table holds all taxi trips. Each trip has a unique id, while client_id and driver_id are foreign keys to the users_id at the Users table.
Status is an ENUM (category) type of ('completed', 'cancelled_by_driver', 'cancelled_by_client').
```

Table: Users

```text
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| users_id    | int      |
| banned      | enum     |
| role        | enum     |
+-------------+----------+
users_id is the primary key (column with unique values) for this table.
The table holds all users. Each user has a unique users_id, and role is an ENUM type of ('client', 'driver', 'partner').
banned is an ENUM (category) type of ('Yes', 'No').
```

The cancellation rate is computed by dividing the number of canceled (by client or driver) requests with unbanned users by the total number of requests with unbanned users on that day.

Write a solution to find the cancellation rate of requests with unbanned users (both client and driver must not be banned) each day between "2013-10-01" and "2013-10-03" with at least one trip. Round Cancellation Rate to two decimal points.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Trips table:
+----+-----------+-----------+---------+---------------------+------------+
| id | client_id | driver_id | city_id | status              | request_at |
+----+-----------+-----------+---------+---------------------+------------+
| 1  | 1         | 10        | 1       | completed           | 2013-10-01 |
| 2  | 2         | 11        | 1       | cancelled_by_driver | 2013-10-01 |
| 3  | 3         | 12        | 6       | completed           | 2013-10-01 |
| 4  | 4         | 13        | 6       | cancelled_by_client | 2013-10-01 |
| 5  | 1         | 10        | 1       | completed           | 2013-10-02 |
| 6  | 2         | 11        | 6       | completed           | 2013-10-02 |
| 7  | 3         | 12        | 6       | completed           | 2013-10-02 |
| 8  | 2         | 12        | 12      | completed           | 2013-10-03 |
| 9  | 3         | 10        | 12      | completed           | 2013-10-03 |
| 10 | 4         | 13        | 12      | cancelled_by_driver | 2013-10-03 |
+----+-----------+-----------+---------+---------------------+------------+
Users table:
+----------+--------+--------+
| users_id | banned | role   |
+----------+--------+--------+
| 1        | No     | client |
| 2        | Yes    | client |
| 3        | No     | client |
| 4        | No     | client |
| 10       | No     | driver |
| 11       | No     | driver |
| 12       | No     | driver |
| 13       | No     | driver |
+----------+--------+--------+
Output:
+------------+-------------------+
| Day        | Cancellation Rate |
+------------+-------------------+
| 2013-10-01 | 0.33              |
| 2013-10-02 | 0.00              |
| 2013-10-03 | 0.50              |
+------------+-------------------+
Explanation:
On 2013-10-01:
  - There were 4 requests in total, 2 of which were canceled.
  - However, the request with Id=2 was made by a banned client (User_Id=2), so it is ignored in the calculation.
  - Hence there are 3 unbanned requests in total, 1 of which was canceled.
  - The Cancellation Rate is (1 / 3) = 0.33
On 2013-10-02:
  - There were 3 requests in total, 0 of which were canceled.
  - The request with Id=6 was made by a banned client, so it is ignored.
  - Hence there are 2 unbanned requests in total, 0 of which were canceled.
  - The Cancellation Rate is (0 / 2) = 0.00
On 2013-10-03:
  - There were 3 requests in total, 1 of which was canceled.
  - The request with Id=8 was made by a banned client, so it is ignored.
  - Hence there are 2 unbanned request in total, 1 of which were canceled.
  - The Cancellation Rate is (1 / 2) = 0.50
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Hopper Company Queries I](https://leetcode.com/problems/hopper-company-queries-i/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Hopper Company Queries II](https://leetcode.com/problems/hopper-company-queries-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Hopper Company Queries III](https://leetcode.com/problems/hopper-company-queries-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 262. Trips and Users

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DataFrame Merging | Pandas |
| Utilizing Intermediate DataFrames | Pandas |
| DataFrame Transformations (Common Table Expression Equivalent) | Pandas |
| Join | SQL |
| Using Subqueries | SQL |
| Using Common Table Expression (CTE) | SQL |

## Approach 1: DataFrame Merging

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:

    # Step 1: Preliminary Check
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Prepare Data for Client Merge
    renamed_users_for_clients = users.rename(
        columns={"users_id": "client_id", "banned": "client_banned"}
    )

    # Step 3: Client Merge
    trips_with_clients = trips.merge(
        renamed_users_for_clients, on="client_id", how="left"
    )

    # Step 4: Prepare Data for Driver Merge
    renamed_users_for_drivers = users.rename(
        columns={"users_id": "driver_id", "banned": "driver_banned"}
    )

    # Step 5: Driver Merge
    full_trips = trips_with_clients.merge(
        renamed_users_for_drivers, on="driver_id", how="left"
    )

    # Step 6: Filtering
    filtered_trips = full_trips[
        (full_trips["client_banned"] == "No")
        & (full_trips["driver_banned"] == "No")
        & (full_trips["request_at"].between("2013-10-01", "2013-10-03"))
    ]

    # Step 7: Calculate Cancellation Rate
    result = filtered_trips.groupby("request_at").apply(
        lambda group: pd.Series(
            {
                "Cancellation Rate": round(
                    (group["status"] != "completed").sum() / len(group), 2
                )
            }
        )
    )

    # Step 8: Result Presentation
    if result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return result.reset_index().rename(columns={"request_at": "Day"})
```

</details>

<br>

## Approach 2: Utilizing Intermediate DataFrames

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Data Verification
    # Check if either `trips` or `users` DataFrames are empty.
    # If so, return a DataFrame with columns "Day" and "Cancellation Rate" without any data.
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Isolating Banned Users
    # Using boolean indexing on the `users` DataFrame, extract the IDs (`users_id`) of users who are banned.
    banned_users_ids = users[users["banned"] == "Yes"]["users_id"]

    # Step 3: Filtering Relevant Trip Data
    # Remove rows from `trips` DataFrame that have `client_id` or `driver_id` matching the IDs of banned users.
    # Retain rows in the `trips` DataFrame that have `request_at` dates within the range of '2013-10-01' to '2013-10-03'.
    selected_trips = trips[
        (~trips["client_id"].isin(banned_users_ids))
        & (~trips["driver_id"].isin(banned_users_ids))
        & (trips["request_at"].between("2013-10-01", "2013-10-03"))
    ]

    # Step 4: Aggregating Data
    # Group the data in the `selected_trips` DataFrame based on the `request_at` column.
    # For each group, calculate the cancellation rate by determining the ratio of non-completed trips to the total number of trips, rounding to two decimal places.
    aggregated_result = selected_trips.groupby("request_at").apply(
        lambda group: pd.Series(
            {
                "Cancellation Rate": round(
                    (group["status"] != "completed").sum() / len(group), 2
                )
            }
        )
    )

    # Step 5: Result Compilation
    # If the `aggregated_result` DataFrame isn't empty, reset its index and rename the `request_at` column to 'Date'.
    # If it's empty, return a DataFrame with columns "Date" and "Cancellation Rate" without any data.
    if aggregated_result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return aggregated_result.reset_index().rename(columns={"request_at": "Day"})
```

</details>

<br>

## Approach 3: DataFrame Transformations (Common Table Expression Equivalent)

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def trips_and_users(trips: pd.DataFrame, users: pd.DataFrame) -> pd.DataFrame:
    # Step 1: Initial Check
    if trips.empty or users.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])

    # Step 2: Date-based Filtering
    filtered_trips = trips[trips["request_at"].between("2013-10-01", "2013-10-03")]

    # Step 3: Merge with Non-Banned Clients
    trips_with_clients = filtered_trips.merge(
        users.loc[users["banned"] == "No", ["users_id"]],
        left_on="client_id",
        right_on="users_id",
        how="inner",
    )

    # Step 4: Merge with Non-Banned Drivers
    trip_status = trips_with_clients.merge(
        users.loc[users["banned"] == "No", ["users_id"]],
        left_on="driver_id",
        right_on="users_id",
        how="inner",
    )

    # Step 5: Calculate Day-wise Cancellation Rate
    result = trip_status.groupby("request_at").apply(
        lambda group: pd.Series(
            {"Cancellation Rate": round(
                 (group["status"] != "completed").sum() / len(group), 2
                 )
             }
        )
    )

    # Step 6: Format and Return the Result
    if result.empty:
        return pd.DataFrame(columns=["Day", "Cancellation Rate"])
    else:
        return result.reset_index().rename(columns={"request_at": "Day"})
```

</details>

<br>

## Approach 1: Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  request_at AS Day, 
  ROUND(
    SUM(status != 'completed') / COUNT(*), 
    2
  ) AS 'Cancellation Rate' 
FROM 
  Trips 
  LEFT JOIN Users AS Clients ON Trips.client_id = Clients.users_id 
  LEFT JOIN Users AS Drivers ON Trips.driver_id = Drivers.users_id 
WHERE 
  Clients.banned = 'No' 
  AND Drivers.banned = 'No' 
  AND request_at BETWEEN '2013-10-01' 
  AND '2013-10-03' 
GROUP BY 
  Day
```

</details>

<br>

## Approach 2: Using Subqueries

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  request_at AS Day, 
  ROUND(
    SUM(status != 'completed') / COUNT(status), 
    2
  ) AS 'Cancellation Rate' 
FROM 
  Trips 
WHERE 
  request_at BETWEEN '2013-10-01' 
  AND '2013-10-03' 
  AND driver_id NOT IN (
    SELECT 
      users_id 
    FROM 
      Users 
    WHERE 
      banned = 'Yes'
  ) 
  AND client_id NOT IN (
    SELECT 
      users_id 
    FROM 
      Users 
    WHERE 
      banned = 'Yes'
  ) 
GROUP BY 
  Day
```

</details>

<br>

## Approach 3: Using Common Table Expression (CTE)

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH TripStatus AS (
  SELECT 
    Request_at AS Day, 
    T.status != 'completed' AS cancelled 
  FROM 
    Trips T 
    JOIN Users C ON Client_Id = C.Users_Id 
    AND C.Banned = 'No' 
    JOIN Users D ON Driver_Id = D.Users_Id 
    AND D.Banned = 'No' 
  WHERE 
    Request_at BETWEEN '2013-10-01' 
    AND '2013-10-03'
) 
SELECT 
  Day, 
  ROUND(
    SUM(cancelled) / COUNT(cancelled), 
    2
  ) AS 'Cancellation Rate' 
FROM 
  TripStatus 
GROUP BY 
  Day;
```

</details>
