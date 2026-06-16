# 1527. Patients With a Condition

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/patients-with-a-condition/)  
`Database`

**Problem Link:** [LeetCode 1527 - Patients With a Condition](https://leetcode.com/problems/patients-with-a-condition/)

## Problem

Table: Patients

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key (column with unique values) for this table.
'conditions' contains 0 or more code separated by spaces.
This table contains information of the patients in the hospital.
```

Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Patients table:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel       | YFEV COUGH   |
| 2          | Alice        |              |
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
| 5          | Alain        | DIAB201      |
+------------+--------------+--------------+
Output:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
+------------+--------------+--------------+
Explanation: Bob and George both have a condition that starts with DIAB1.
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

# Editorial - 1527. Patients With a Condition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Regular Expression Word Boundaries or Spaces | Pandas |
| Without Using Regular Expressions | Pandas |
| Without Using Regular Expressions |  |

## Approach 1: Using Regular Expression Word Boundaries or Spaces

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    return patients[patients["conditions"].str.contains(r"(^|\s)DIAB1", regex=True)]
```

</details>

<br>

## Approach 2: Without Using Regular Expressions

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    return patients[patients["conditions"].str.startswith("DIAB1") | patients["conditions"].str.contains(" DIAB1", regex=False)]
```

</details>

<br>

## Approach 2: Without Using Regular Expressions

### Implementation
