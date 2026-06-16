# 610. Triangle Judgement

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/triangle-judgement/)  
`Database`

**Problem Link:** [LeetCode 610 - Triangle Judgement](https://leetcode.com/problems/triangle-judgement/)

## Problem

Table: Triangle

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
```

Report for every three line segments whether they can form a triangle.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
Output:
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+
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

# Editorial - 610. Triangle Judgement

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: DataFrame Row-Wise Application of the Triangle Inequality Theorem | Pandas |
| Approach: Using `case...when...` | SQL |

## Approach: DataFrame Row-Wise Application of the Triangle Inequality Theorem

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def triangle_judgement(triangle: pd.DataFrame) -> pd.DataFrame:

    # Define a function to check if three sides can form a triangle
    def is_triangle(row):
        return (
            "Yes"
            if (row["x"] + row["y"] > row["z"])
            and (row["y"] + row["z"] > row["x"])
            and (row["z"] + row["x"] > row["y"])
            else "No"
        )

    # Apply the function to each row in the DataFrame
    triangle["triangle"] = triangle.apply(is_triangle, axis=1)

    # Return the updated DataFrame
    return triangle
```

</details>

<br>

## Approach: Using `case...when...`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    x,
    y,
    z,
    CASE
        WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
        ELSE 'No'
    END AS 'triangle'
FROM
    triangle
;
```

</details>
