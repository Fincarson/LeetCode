# 585. Investments in 2016

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/investments-in-2016/)  
`Database`

**Problem Link:** [LeetCode 585 - Investments in 2016](https://leetcode.com/problems/investments-in-2016/)

## Problem

Table: Insurance

```text
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| pid         | int   |
| tiv_2015    | float |
| tiv_2016    | float |
| lat         | float |
| lon         | float |
+-------------+-------+
pid is the primary key (column with unique values) for this table.
Each row of this table contains information about one policy where:
pid is the policyholder's policy ID.
tiv_2015 is the total investment value in 2015 and tiv_2016 is the total investment value in 2016.
lat is the latitude of the policy holder's city. It's guaranteed that lat is not NULL.
lon is the longitude of the policy holder's city. It's guaranteed that lon is not NULL.
```

Write a solution to report the sum of all total investment values in 2016 tiv_2016, for all policyholders who:

- have the same tiv_2015 value as one or more other policyholders, and
- are not located in the same city as any other policyholder (i.e., the (lat, lon) attribute pairs must be unique).

Round tiv_2016 to two decimal places.

The result format is in the following example.

### Example 1

```text
Input:
Insurance table:
+-----+----------+----------+-----+-----+
| pid | tiv_2015 | tiv_2016 | lat | lon |
+-----+----------+----------+-----+-----+
| 1   | 10       | 5        | 10  | 10  |
| 2   | 20       | 20       | 20  | 20  |
| 3   | 10       | 30       | 20  | 20  |
| 4   | 10       | 40       | 40  | 40  |
+-----+----------+----------+-----+-----+
Output:
+----------+
| tiv_2016 |
+----------+
| 45.00    |
+----------+
Explanation:
The first record in the table, like the last record, meets both of the two criteria.
The tiv_2015 value 10 is the same as the third and fourth records, and its location is unique.

The second record does not meet any of the two criteria. Its tiv_2015 is not like any other policyholders and its location is the same as the third record, which makes the third record fail, too.
So, the result is the sum of tiv_2016 of the first and last record, which is 45.
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

# Editorial - 585. Investments in 2016

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Calculating Aggregate Values Using transform() | Pandas |
| Identifying Duplicates Using duplicated() | Pandas |
| Creating Filters in Subqueries | SQL |
| Creating Filters Using Window Function | SQL |

## Approach 1: Calculating Aggregate Values Using transform()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:

   df = insurance.assign(
       tiv_2015_cnt = insurance.groupby('tiv_2015')['pid'].transform('count'),
       loc_cnt = insurance.groupby(['lat', 'lon'])['pid'].transform('count')
   )

   df = df[(df['tiv_2015_cnt'] > 1) & (df['loc_cnt'] == 1)]

   return df.agg(tiv_2016 = ('tiv_2016', 'sum')).round(2)
```

</details>

<br>

## Approach 2: Identifying Duplicates Using duplicated()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:

   df = insurance[insurance.duplicated(subset=['tiv_2015'], keep=False) & ~insurance.duplicated(subset=['lat', 'lon'], keep=False)]

   return df.agg(tiv_2016 = ('tiv_2016', 'sum')).round(2)
```

</details>

<br>

## Approach 1: Creating Filters in Subqueries

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT tiv_2015
FROM Insurance
GROUP BY tiv_2015
HAVING COUNT(DISTINCT pid) > 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT CONCAT(lat, lon) lat_lon
FROM Insurance
GROUP BY CONCAT(lat, lon)
HAVING COUNT(DISTINCT pid) = 1
```

</details>

<br>

## Approach 2: Creating Filters Using Window Function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT *,
   COUNT(*)OVER(PARTITION BY tiv_2015) AS tiv_2015_cnt,
   COUNT(*)OVER(PARTITION BY lat, lon) AS loc_cnt
FROM Insurance
```

</details>
