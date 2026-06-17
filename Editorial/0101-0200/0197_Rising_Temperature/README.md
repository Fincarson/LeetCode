# 197. Rising Temperature

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rising-temperature/)  
`Database`

**Problem Link:** [LeetCode 197 - Rising Temperature](https://leetcode.com/problems/rising-temperature/)

## Problem

Table: Weather

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the column with unique values for this table.
There are no different rows with the same recordDate.
This table contains information about the temperature on a certain day.
```

Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday).

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output:
+----+
| id |
+----+
| 2  |
| 4  |
+----+
Explanation:
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).
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

# Editorial - 197. Rising Temperature

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Shifted Dataframe Merge on Record Date | Pandas |
| Shift Function with Precise Date Match | Pandas |
| Using `JOIN` and `DATEDIFF()` | SQL |
| Using `LAG()` Function | SQL |
| Using Subquery | SQL |
| Using Cartesian Product and `WHERE` Clause | SQL |

## Approach 1: Shifted Dataframe Merge on Record Date

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    # Ensure the 'recordDate' column is a datetime type
    weather['recordDate'] = pd.to_datetime(weather['recordDate'])
    
    # Create a copy of the weather DataFrame with a 1 day shift 
    weather_shifted = weather.copy()
    weather_shifted['recordDate'] = weather_shifted['recordDate'] + pd.to_timedelta(1, unit='D')
    
    # Merging the DataFrames on the 'recordDate' column to find consecutive dates
    merged_df = pd.merge(weather, weather_shifted, on='recordDate', suffixes=('_today', '_yesterday'))
    
    # Finding rows where the temperature is greater on the current day compared to the previous day
    result = merged_df[merged_df['temperature_today'] > merged_df['temperature_yesterday']][['id_today']].rename(columns={'id_today': 'Id'})
    
    return result
```

</details>

<br>

## Approach 2: Shift Function with Precise Date Match

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    # Ensure the 'recordDate' column is a datetime type
    weather['recordDate'] = pd.to_datetime(weather['recordDate'])
    
    # Sorting the DataFrame by 'recordDate' to ensure the shift operation works correctly
    weather.sort_values('recordDate', inplace=True)
    
    # Creating new columns for the previous day's temperature and record date
    weather['PreviousTemperature'] = weather['temperature'].shift(1)
    weather['PreviousRecordDate'] = weather['recordDate'].shift(1)
    
    # Filtering the DataFrame to find rows where the temperature is higher 
    # than the previous day and the date is exactly one day more than the previous record date
    result = weather[
        (weather['temperature'] > weather['PreviousTemperature']) & 
        (weather['recordDate'] == weather['PreviousRecordDate'] + pd.Timedelta(days=1))
    ][['id']].rename(columns={'id': 'Id'})
    
    return result
```

</details>

<br>

## Approach 1: Using `JOIN` and `DATEDIFF()`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    w1.id
FROM 
    Weather w1
JOIN 
    Weather w2
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE 
    w1.temperature > w2.temperature;
```

</details>

<br>

## Approach 2: Using `LAG()` Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH PreviousWeatherData AS
(
    SELECT 
        id,
        recordDate,
        temperature, 
        LAG(temperature, 1) OVER (ORDER BY recordDate) AS PreviousTemperature,
        LAG(recordDate, 1) OVER (ORDER BY recordDate) AS PreviousRecordDate
    FROM 
        Weather
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    id 
FROM 
    PreviousWeatherData
WHERE 
    temperature > PreviousTemperature
AND 
    recordDate = DATE_ADD(PreviousRecordDate, INTERVAL 1 DAY);
```

</details>

<br>

## Approach 3: Using Subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
        SELECT 
            w2.temperature
        FROM 
            Weather w2
        WHERE 
            w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    w1.id
FROM 
    Weather w1
WHERE 
    w1.temperature > (
        -- ... (inner subquery)
    );
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    w1.id
```

</details>

<br>

## Approach 4: Using Cartesian Product and `WHERE` Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
FROM 
    Weather w1, Weather w2
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE 
    DATEDIFF(w2.recordDate, w1.recordDate) = 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    w2.id
```

</details>
