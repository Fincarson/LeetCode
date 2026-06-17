# 619. Biggest Single Number

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/biggest-single-number/)  
`Database`

**Problem Link:** [LeetCode 619 - Biggest Single Number](https://leetcode.com/problems/biggest-single-number/)

## Problem

Table: MyNumbers

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
This table may contain duplicates (In other words, there is no primary key for this table in SQL).
Each row of this table contains an integer.
```

A single number is a number that appeared only once in the MyNumbers table.

Find the largest single number. If there is no single number, report null.

The result format is in the following example.

### Example 1

```text
Input:
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
Output:
+-----+
| num |
+-----+
| 6   |
+-----+
Explanation: The single numbers are 1, 4, 5, and 6.
Since 6 is the largest single number, we return it.
```

### Example 2

```text
Input:
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 7   |
| 7   |
| 3   |
| 3   |
| 3   |
+-----+
Output:
+------+
| num  |
+------+
| null |
+------+
Explanation: There are no single numbers in the input table so we return null.
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

# Editorial - 619. Biggest Single Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Filter and Max | Pandas |
| Using **subquery** and `MAX()` function [Accepted] | SQL |

## Approach 1: Filter and Max

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    # 1. Filter numbers that appear only once
    unique_numbers = my_numbers.groupby('num').filter(lambda x: len(x) == 1)
    
    # 2. Find the maximum of those numbers
    max_value = unique_numbers['num'].max()
    
    return pd.DataFrame({'num': [max_value]})
```

</details>

<br>

## Approach 1: Using **subquery** and `MAX()` function [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    num
FROM
    MyNumbers
GROUP BY num
HAVING COUNT(num) = 1;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    MAX(num) AS num
FROM
    (SELECT
        num
    FROM
        MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1) AS t;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    MAX(num) AS num
FROM
    (SELECT
        num
    FROM
        MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1) AS t;
```

</details>
