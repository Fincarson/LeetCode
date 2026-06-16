# 2884. Modify Columns

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/modify-columns/)  

**Problem Link:** [LeetCode 2884 - Modify Columns](https://leetcode.com/problems/modify-columns/)

## Problem

```text
DataFrame employees
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| salary      | int    |
+-------------+--------+
```

A company intends to give its employees a pay rise.

Write a solution to modify the salary column by multiplying each salary by 2.

The result format is in the following example.

### Example 1

```text
Input:
DataFrame employees
+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 19666  |
| Piper   | 74754  |
| Mia     | 62509  |
| Ulysses | 54866  |
+---------+--------+
Output:
+---------+--------+
| name    | salary |
+---------+--------+
| Jack    | 39332  |
| Piper   | 149508 |
| Mia     | 125018 |
| Ulysses | 109732 |
+---------+--------+
Explanation:
Every salary has been doubled.
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

# Editorial - 2884. Modify Columns

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

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] = employees['salary'] * 2
    return employees
```

</details>
