# 595. Big Countries

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/big-countries/)  
`Database`

**Problem Link:** [LeetCode 595 - Big Countries](https://leetcode.com/problems/big-countries/)

## Problem

Table: World

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | bigint  |
+-------------+---------+
name is the primary key (column with unique values) for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.
```

A country is big if:

- it has an area of at least three million (i.e., 3000000 km2), or
- it has a population of at least twenty-five million (i.e., 25000000).

Write a solution to find the name, population, and area of the big countries.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
Output:
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+
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

# Editorial - 595. Big Countries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Filtering rows | Pandas |
| Approach: Filtering rows using `WHERE` | SQL |

## Approach: Filtering rows

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
    return df[['name', 'population', 'area']]
```

</details>

<br>

## Approach: Filtering rows using `WHERE`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    * 
FROM 
    world 
WHERE 
    area >= 3000000 
    OR population >= 25000000
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    name, population, area
FROM
    world
WHERE
    area >= 3000000 OR population >= 25000000
;
```

</details>
