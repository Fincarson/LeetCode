# 2881. Create a New Column

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/create-a-new-column/)  

**Problem Link:** [LeetCode 2881 - Create a New Column](https://leetcode.com/problems/create-a-new-column/)

## Problem

```text
DataFrame employees
+-------------+--------+
| Column Name | Type.  |
+-------------+--------+
| name        | object |
| salary      | int.   |
+-------------+--------+
```

A company plans to provide its employees with a bonus.

Write a solution to create a new column name bonus that contains the doubled values of the salary column.

The result format is in the following example.

### Example 1

```text
Input:
DataFrame employees
+---------+--------+
| name    | salary |
+---------+--------+
| Piper   | 4548   |
| Grace   | 28150  |
| Georgia | 1103   |
| Willow  | 6593   |
| Finn    | 74576  |
| Thomas  | 24433  |
+---------+--------+
Output:
+---------+--------+--------+
| name    | salary | bonus  |
+---------+--------+--------+
| Piper   | 4548   | 9096   |
| Grace   | 28150  | 56300  |
| Georgia | 1103   | 2206   |
| Willow  | 6593   | 13186  |
| Finn    | 74576  | 149152 |
| Thomas  | 24433  | 48866  |
+---------+--------+--------+
Explanation:
A new column bonus is created by doubling the value in the column salary.
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

# Editorial - 2881. Create a New Column

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

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary'] * 2
    return employees
```

</details>
