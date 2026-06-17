# 2883. Drop Missing Data

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/drop-missing-data/)  

**Problem Link:** [LeetCode 2883 - Drop Missing Data](https://leetcode.com/problems/drop-missing-data/)

## Problem

```text
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
+-------------+--------+
```

There are some rows having missing values in the name column.

Write a solution to remove the rows with missing values.

The result format is in the following example.

### Example 1

```text
Input:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 217        | None    | 19  |
| 779        | Georgia | 20  |
| 849        | Willow  | 14  |
+------------+---------+-----+
Output:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 32         | Piper   | 5   |
| 779        | Georgia | 20  |
| 849        | Willow  | 14  |
+------------+---------+-----+
Explanation:
Student with id 217 havs empty value in the name column, so it will be removed.
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

# Editorial - 2883. Drop Missing Data

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | Pandas |

## Solution

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    students.dropna(subset=['name'], inplace=True)
    return students
```

</details>
