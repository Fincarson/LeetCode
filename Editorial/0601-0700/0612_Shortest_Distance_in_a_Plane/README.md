# 612. Shortest Distance in a Plane

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/shortest-distance-in-a-plane/)  
`Database`

**Problem Link:** [LeetCode 612 - Shortest Distance in a Plane](https://leetcode.com/problems/shortest-distance-in-a-plane/)

## Problem

Table: Point2D

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
+-------------+------+
(x, y) is the primary key column (combination of columns with unique values) for this table.
Each row of this table indicates the position of a point on the X-Y plane.
```

The distance between two points p1(x1, y1) and p2(x2, y2) is sqrt((x2 - x1)2 + (y2 - y1)2).

Write a solution to report the shortest distance between any two points from the Point2D table. Round the distance to two decimal points.

The result format is in the following example.

### Example 1

```text
Input:
Point2D table:
+----+----+
| x  | y  |
+----+----+
| -1 | -1 |
| 0  | 0  |
| -1 | -2 |
+----+----+
Output:
+----------+
| shortest |
+----------+
| 1.00     |
+----------+
Explanation: The shortest distance is 1.00 from point (-1, -1) to (-1, 2).
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

# Editorial - 612. Shortest Distance in a Plane

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Pairwise Euclidean Distance Calculation Using Cartesian Coordinates | Pandas |
| Vectorized Pairwise Distance Calculation Using Broadcasting | Pandas |
| Using `SQRT`, `POW()` functions and math knowledge | SQL |
| Optimize to avoid reduplicate calculations | SQL |

## Approach 1: Pairwise Euclidean Distance Calculation Using Cartesian Coordinates

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def shortest_distance(point2_d: pd.DataFrame) -> pd.DataFrame:
    df = point2_d.merge(point2_d, how='cross')
    
    # Filter df so no same points are calculated
    df = df[(df['x_x'] != df['x_y']) | (df['y_x'] != df['y_y'])]
    
    # Calculate shortest given the distance formula
    df['shortest'] = ((df['x_y'] - df['x_x']).pow(2) + (df['y_y'] - df['y_x']).pow(2)).pow(1/2)
    
    # Round each value in shortest
    df['shortest'] = df['shortest'].apply(lambda x: round(x, 2))

    # Find shortest, remove duplicates and return
    df = df[df['shortest'] == df['shortest'].min()].drop_duplicates('shortest')
    
    return df[['shortest']]
```

</details>

<br>

## Approach 2: Vectorized Pairwise Distance Calculation Using Broadcasting

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
import numpy as np

def shortest_distance(point2_d: pd.DataFrame) -> pd.DataFrame:
    # Extract x and y coordinates as numpy arrays
    x = point2_d['x'].to_numpy()
    y = point2_d['y'].to_numpy()
    
    # Compute the pairwise squared distances using broadcasting
    dx = (x[:, None] - x[None, :])**2
    dy = (y[:, None] - y[None, :])**2
    distances_squared = dx + dy
    
    # Set diagonal to infinity to avoid zero distance for a point with itself
    np.fill_diagonal(distances_squared, np.inf)
    
    # Find the minimum distance
    min_distance_squared = np.min(distances_squared)
    
    # Take square root to get the Euclidean distance
    min_distance = np.sqrt(min_distance_squared)
    
    # Create a DataFrame to hold the result
    result_df = pd.DataFrame({'shortest': [round(min_distance, 2)]})
    
    return result_df
```

</details>

<br>

## Approach 1: Using `SQRT`, `POW()` functions and math knowledge

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    p1.x,
    p1.y,
    p2.x,
    p2.y,
    SQRT((POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2))) AS distance
FROM
    point_2d p1
        JOIN
    point_2d p2 ON p1.x != p2.x OR p1.y != p2.y
;
```

</details>

<br>

## Approach 2: Optimize to avoid reduplicate calculations

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    t1.x,
    t1.y,
    t2.x,
    t2.y,
    SQRT((POW(t1.x - t2.x, 2) + POW(t1.y - t2.y, 2))) AS distance
FROM
    point_2d t1
        JOIN
    point_2d t2 ON (t1.x <= t2.x AND t1.y < t2.y)
        OR (t1.x <= t2.x AND t1.y > t2.y)
        OR (t1.x < t2.x AND t1.y = t2.y)
;
```

</details>
