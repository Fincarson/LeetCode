# 3053. Classifying Triangles by Lengths

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/classifying-triangles-by-lengths/)  
`Database`

**Problem Link:** [LeetCode 3053 - Classifying Triangles by Lengths](https://leetcode.com/problems/classifying-triangles-by-lengths/)

## Problem

Table: Triangles

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| A           | int  |
| B           | int  |
| C           | int  |
+-------------+------+
(A, B, C) is the primary key for this table.
Each row include the lengths of each of a triangle's three sides.
```

Write a query to find the type of triangle. Output one of the following for each row:

- Equilateral: It's a triangle with 3 sides of equal length.
- Isosceles: It's a triangle with 2 sides of equal length.
- Scalene: It's a triangle with 3 sides of differing lengths.
- Not A Triangle: The given values of A, B, and C don't form a triangle.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Triangles table:
+----+----+----+
| A  | B  | C  |
+----+----+----+
| 20 | 20 | 23 |
| 20 | 20 | 20 |
| 20 | 21 | 22 |
| 13 | 14 | 30 |
+----+----+----+
Output:
+----------------+
| triangle_type  |
+----------------+
| Isosceles      |
| Equilateral    |
| Scalene        |
| Not A Triangle |
+----------------+
Explanation:
- Values in the first row from an Isosceles triangle, because A = B.
- Values in the second row from an Equilateral triangle, because A = B = C.
- Values in the third row from an Scalene triangle, because A != B != C.
- Values in the fourth row cannot form a triangle, because the combined value of sides A and B is not larger than that of side C.
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

# Editorial - 3053. Classifying Triangles by Lengths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Utilizing `loc` | Pandas |
| Approach: Utilizing `CASE` | MySQL |

## Approach: Utilizing `loc`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def type_of_triangle(triangles: pd.DataFrame) -> pd.DataFrame:
    triangles["triangle_type"] = "Scalene"

    triangles.loc[
        (triangles["A"] == triangles["B"]) & (triangles["A"] == triangles["C"]),
        "triangle_type",
    ] = "Equilateral"

    triangles.loc[
        (
            (triangles["A"] == triangles["B"])
            | (triangles["A"] == triangles["C"])
            | (triangles["C"] == triangles["B"])
        )
        & (triangles["triangle_type"] != "Equilateral"),
        "triangle_type",
    ] = "Isosceles"

    triangles.loc[
        (triangles["A"] >= triangles["B"] + triangles["C"])
        | (triangles["B"] >= triangles["A"] + triangles["C"])
        | (triangles["C"] >= triangles["B"] + triangles["A"]),
        "triangle_type",
    ] = "Not A Triangle"

    return triangles[["triangle_type"]]
```

</details>

<br>

## Approach: Utilizing `CASE`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  CASE
    WHEN A + B <= C OR A + C <= B OR B + C <= A THEN 'Not A Triangle'
    WHEN A = B AND B = C THEN 'Equilateral'
    WHEN A = B OR A = C OR B = C THEN 'Isosceles'
    ELSE 'Scalene'
  END AS triangle_type
FROM Triangles;
```

</details>
