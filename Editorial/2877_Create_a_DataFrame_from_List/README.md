# 2877. Create a DataFrame from List

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/create-a-dataframe-from-list/)  

**Problem Link:** [LeetCode 2877 - Create a DataFrame from List](https://leetcode.com/problems/create-a-dataframe-from-list/)

## Problem

Write a solution to create a DataFrame from a 2D list called student_data. This 2D list contains the IDs and ages of some students.

The DataFrame should have two columns, student_id and age, and be in the same order as the original 2D list.

The result format is in the following example.

### Example 1

```text
Input:
student_data:
[
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]
Output:
+------------+-----+
| student_id | age |
+------------+-----+
| 1          | 15  |
| 2          | 11  |
| 3          | 11  |
| 4          | 20  |
+------------+-----+
Explanation:
A DataFrame was created on top of student_data, with two columns named student_id and age.
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

# Editorial - 2877. Create a DataFrame from List

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

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    column_names = ["student_id", "age"]
    result_dataframe = pd.DataFrame(student_data, columns=column_names)
    return result_dataframe
```

</details>
