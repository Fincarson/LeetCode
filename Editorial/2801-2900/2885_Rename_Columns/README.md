# 2885. Rename Columns

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rename-columns/)  

**Problem Link:** [LeetCode 2885 - Rename Columns](https://leetcode.com/problems/rename-columns/)

## Problem

```text
DataFrame students
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| id          | int    |
| first       | object |
| last        | object |
| age         | int    |
+-------------+--------+
```

Write a solution to rename the columns as follows:

- id to student_id
- first to first_name
- last to last_name
- age to age_in_years

The result format is in the following example.

```text
Example 1:
Input:
+----+---------+----------+-----+
| id | first   | last     | age |
+----+---------+----------+-----+
| 1  | Mason   | King     | 6   |
| 2  | Ava     | Wright   | 7   |
| 3  | Taylor  | Hall     | 16  |
| 4  | Georgia | Thompson | 18  |
| 5  | Thomas  | Moore    | 10  |
+----+---------+----------+-----+
Output:
+------------+------------+-----------+--------------+
| student_id | first_name | last_name | age_in_years |
+------------+------------+-----------+--------------+
| 1          | Mason      | King      | 6            |
| 2          | Ava        | Wright    | 7            |
| 3          | Taylor     | Hall      | 16           |
| 4          | Georgia    | Thompson  | 18           |
| 5          | Thomas     | Moore     | 10           |
+------------+------------+-----------+--------------+
Explanation:
The column names are changed accordingly.
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

# Editorial - 2885. Rename Columns

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

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students = students.rename(
        columns={
            "id": "student_id",
            "first": "first_name",
            "last": "last_name",
            "age": "age_in_years",
        }
    )
    return students
```

</details>
