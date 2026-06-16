# 2153. The Number of Passengers in Each Bus II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/the-number-of-passengers-in-each-bus-ii/)  
`Database`

**Problem Link:** [LeetCode 2153 - The Number of Passengers in Each Bus II](https://leetcode.com/problems/the-number-of-passengers-in-each-bus-ii/)

## Problem

Table: Buses

```text
+--------------+------+
| Column Name  | Type |
+--------------+------+
| bus_id       | int  |
| arrival_time | int  |
| capacity     | int  |
+--------------+------+
bus_id contains unique values.
Each row of this table contains information about the arrival time of a bus at the LeetCode station and its capacity (the number of empty seats it has).
No two buses will arrive at the same time and all bus capacities will be positive integers.
```

Table: Passengers

```text
+--------------+------+
| Column Name  | Type |
+--------------+------+
| passenger_id | int  |
| arrival_time | int  |
+--------------+------+
passenger_id contains unique values.
Each row of this table contains information about the arrival time of a passenger at the LeetCode station.
```

Buses and passengers arrive at the LeetCode station. If a bus arrives at the station at a time tbus and a passenger arrived at a time tpassenger where tpassenger <= tbus and the passenger did not catch any bus, the passenger will use that bus. In addition, each bus has a capacity. If at the moment the bus arrives at the station there are more passengers waiting than its capacity capacity, only capacity passengers will use the bus.

Write a solution to report the number of users that used each bus.

Return the result table ordered by bus_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Buses table:
+--------+--------------+----------+
| bus_id | arrival_time | capacity |
+--------+--------------+----------+
| 1      | 2            | 1        |
| 2      | 4            | 10       |
| 3      | 7            | 2        |
+--------+--------------+----------+
Passengers table:
+--------------+--------------+
| passenger_id | arrival_time |
+--------------+--------------+
| 11           | 1            |
| 12           | 1            |
| 13           | 5            |
| 14           | 6            |
| 15           | 7            |
+--------------+--------------+
Output:
+--------+----------------+
| bus_id | passengers_cnt |
+--------+----------------+
| 1      | 1              |
| 2      | 1              |
| 3      | 2              |
+--------+----------------+
Explanation:
- Passenger 11 arrives at time 1.
- Passenger 12 arrives at time 1.
- Bus 1 arrives at time 2 and collects passenger 11 as it has one empty seat.

- Bus 2 arrives at time 4 and collects passenger 12 as it has ten empty seats.

- Passenger 12 arrives at time 5.
- Passenger 13 arrives at time 6.
- Passenger 14 arrives at time 7.
- Bus 3 arrives at time 7 and collects passengers 12 and 13 as it has two empty seats.
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

# Editorial - 2153. The Number of Passengers in Each Bus II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sequential Bus Boarding Simulation | Pandas |
| Using Variables | SQL |
| Using Recursion | SQL |

## Approach: Sequential Bus Boarding Simulation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def number_of_passengers(buses: pd.DataFrame, passengers: pd.DataFrame) -> pd.DataFrame:
    # Sort buses by their arrival times to process in chronological order
    buses_sorted = buses.sort_values(by='arrival_time')

    # Iterate over each bus to calculate the number of passengers it can pick up
    for i, bus in buses_sorted.iterrows():
        # For the first bus, count all passengers arrived up to its arrival time
        if i == 0:
            available_passengers = passengers[passengers['arrival_time'] <= bus.arrival_time].shape[0]
        else:
            # For subsequent buses, count passengers arrived after the previous bus and before this bus
            arrived_after_previous_bus = passengers['arrival_time'] > buses_sorted.at[i - 1, 'arrival_time']
            arrived_before_current_bus = passengers['arrival_time'] <= bus.arrival_time
            available_passengers = passengers[arrived_after_previous_bus & arrived_before_current_bus].shape[0]
            available_passengers += buses_sorted.at[i - 1, 'leftover']

        # Determine how many passengers board this bus based on its capacity
        if available_passengers <= bus.capacity:
            buses_sorted.at[i, 'passengers_cnt'] = available_passengers
            buses_sorted.at[i, 'leftover'] = 0
        else:
            buses_sorted.at[i, 'passengers_cnt'] = bus.capacity
            buses_sorted.at[i, 'leftover'] = available_passengers - bus.capacity

    # Return the result with bus ID and the count of passengers picked up by each bus
    return buses_sorted[['bus_id', 'passengers_cnt']].sort_values(by='bus_id')
```

</details>

<br>

## Approach 1: Using Variables

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
    WITH OrderedBusArrivals AS (
      SELECT 
        bus_id, 
        b.arrival_time, 
        capacity, 
        COUNT(passenger_id) AS eligible_passengers 
      FROM 
        Buses b 
        LEFT JOIN Passengers p ON p.arrival_time <= b.arrival_time 
      WHERE 
        bus_id IS NOT NULL 
      GROUP BY 
        bus_id 
      ORDER BY 
        b.arrival_time
    )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
    SELECT 
      bus_id, 
      passengers_cnt 
    FROM 
      (
        SELECT 
          bus_id, 
          capacity, 
          eligible_passengers, 
          @boarded_passengers := LEAST(
            capacity, eligible_passengers - @accumulated_boarding
          ) AS passengers_cnt, 
          @accumulated_boarding := @accumulated_boarding + @boarded_passengers 
        FROM 
          OrderedBusArrivals, 
          (
            SELECT 
              @accumulated_boarding := 0, 
              @boarded_passengers := 0
          ) AS Initialization
      ) AS FinalResult 
    ORDER BY 
      bus_id;
```

</details>

<br>

## Approach 2: Using Recursion

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
    WITH RECURSIVE
    UpdatedBuses AS (
        SELECT
            B.bus_id,
            B.arrival_time,
            B.capacity,
            COALESCE(LAG(B.arrival_time) OVER (ORDER BY B.arrival_time), 0) AS previous_bus_arrival
        FROM Buses B
    ),
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
    PassengerArrivalCounts AS (
        SELECT
            B.bus_id,
            B.arrival_time,
            B.capacity,
            B.previous_bus_arrival,
            COUNT(P.passenger_id) AS new_passengers,
            ROW_NUMBER() OVER (ORDER BY B.arrival_time) AS bus_sequence_number
        FROM UpdatedBuses B
        LEFT JOIN Passengers P
            ON P.arrival_time <= B.arrival_time AND P.arrival_time > B.previous_bus_arrival
        GROUP BY B.bus_id, B.arrival_time, B.capacity
    ),
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
    BusBoardingDetails AS (
        SELECT
            bus_sequence_number,
            bus_id,
            LEAST(capacity, new_passengers) AS passengers_boarded,
            (new_passengers - LEAST(capacity, new_passengers)) AS passengers_remaining
        FROM PassengerArrivalCounts
        WHERE bus_sequence_number = 1

        UNION ALL

        SELECT
            PAC.bus_sequence_number,
            PAC.bus_id,
            LEAST(PAC.capacity, PAC.new_passengers + REC.passengers_remaining) AS passengers_boarded,
            (PAC.new_passengers + REC.passengers_remaining) - LEAST(PAC.capacity, PAC.new_passengers + REC.passengers_remaining) AS passengers_remaining
        FROM
            BusBoardingDetails REC,
            PassengerArrivalCounts PAC
        WHERE
            PAC.bus_sequence_number = REC.bus_sequence_number + 1
    )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
    SELECT
        bus_id,
        passengers_boarded AS passengers_cnt
    FROM BusBoardingDetails
    ORDER BY bus_id;
```

</details>
