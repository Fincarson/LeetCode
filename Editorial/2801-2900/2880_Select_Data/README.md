# 2880. Select Data

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/select-data/)  

**Problem Link:** [LeetCode 2880 - Select Data](https://leetcode.com/problems/select-data/)

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

Write a solution to select the name and age of the student with student_id = 101.

The result format is in the following example.

```text
Example 1:
Input:
+------------+---------+-----+
| student_id | name    | age |
+------------+---------+-----+
| 101        | Ulysses | 13  |
| 53         | William | 10  |
| 128        | Henry   | 6   |
| 3          | Henry   | 11  |
+------------+---------+-----+
Output:
+---------+-----+
| name    | age |
+---------+-----+
| Ulysses | 13  |
+---------+-----+
Explanation:
Student Ulysses has student_id = 101, we select the name and age.
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

# Editorial - 2880. Select Data

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

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students.loc[students["student_id"] == 101, ["name", "age"]]
```

</details>
