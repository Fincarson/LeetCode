# 2886. Change Data Type

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/change-data-type/)  

**Problem Link:** [LeetCode 2886 - Change Data Type](https://leetcode.com/problems/change-data-type/)

## Problem

```text
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| student_id  | int    |
| name        | object |
| age         | int    |
| grade       | float  |
+-------------+--------+
```

Write a solution to correct the errors:

The grade column is stored as floats, convert it to integers.

The result format is in the following example.

```text
Example 1:
Input:
DataFrame students:
+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73.0  |
| 2          | Kate | 15  | 87.0  |
+------------+------+-----+-------+
Output:
+------------+------+-----+-------+
| student_id | name | age | grade |
+------------+------+-----+-------+
| 1          | Ava  | 6   | 73    |
| 2          | Kate | 15  | 87    |
+------------+------+-----+-------+
Explanation:
The data types of the column grade is converted to int.
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

# Editorial - 2886. Change Data Type

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

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students = students.astype({'grade': int})
    return students
```

</details>
