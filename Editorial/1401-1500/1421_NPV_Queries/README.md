# 1421. NPV Queries

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/npv-queries/)  
`Database`

**Problem Link:** [LeetCode 1421 - NPV Queries](https://leetcode.com/problems/npv-queries/)

## Problem

Table: NPV

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| year          | int     |
| npv           | int     |
+---------------+---------+
(id, year) is the primary key (combination of columns with unique values) of this table.
The table has information about the id and the year of each inventory and the corresponding net present value.
```

Table: Queries

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| year          | int     |
+---------------+---------+
(id, year) is the primary key (combination of columns with unique values) of this table.
The table has information about the id and the year of each inventory query.
```

Write a solution to find the npv of each query of the Queries table.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
NPV table:
+------+--------+--------+
| id   | year   | npv    |
+------+--------+--------+
| 1    | 2018   | 100    |
| 7    | 2020   | 30     |
| 13   | 2019   | 40     |
| 1    | 2019   | 113    |
| 2    | 2008   | 121    |
| 3    | 2009   | 12     |
| 11   | 2020   | 99     |
| 7    | 2019   | 0      |
+------+--------+--------+
Queries table:
+------+--------+
| id   | year   |
+------+--------+
| 1    | 2019   |
| 2    | 2008   |
| 3    | 2009   |
| 7    | 2018   |
| 7    | 2019   |
| 7    | 2020   |
| 13   | 2019   |
+------+--------+
Output:
+------+--------+--------+
| id   | year   | npv    |
+------+--------+--------+
| 1    | 2019   | 113    |
| 2    | 2008   | 121    |
| 3    | 2009   | 12     |
| 7    | 2018   | 0      |
| 7    | 2019   | 0      |
| 7    | 2020   | 30     |
| 13   | 2019   | 40     |
+------+--------+--------+
Explanation:
The npv value of (7, 2018) is not present in the NPV table, we consider it 0.
The npv values of all other queries can be found in the NPV table.
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

# Editorial - 1421. NPV Queries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Merging DataFrames | Pandas |
| JOIN with a fallback to DEFAULT | SQL |

## Approach 1: Merging DataFrames

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def npv_queries(npv: pd.DataFrame, queries: pd.DataFrame) -> pd.DataFrame:
    result = pd.merge(queries, npv, on=['id', 'year'], how='left')
    result['npv'].fillna(0, inplace=True)
    return result
```

</details>

<br>

## Approach 1: JOIN with a fallback to DEFAULT

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT Q.id,
       Q.year,
       N.npv
FROM Queries Q
LEFT JOIN NPV N ON Q.id = N.id AND Q.year = N.year;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  Q.id, 
  Q.year, 
  COALESCE(N.npv, 0) AS npv 
FROM 
  Queries Q 
  LEFT JOIN NPV N ON Q.id = N.id 
  AND Q.year = N.year;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  Q.id, 
  Q.year, 
  IFNULL(N.npv, 0) AS npv 
FROM 
  Queries Q 
  LEFT JOIN NPV N ON Q.id = N.id 
  AND Q.year = N.year;
```

</details>
