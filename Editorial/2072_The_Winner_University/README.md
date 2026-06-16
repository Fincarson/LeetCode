# 2072. The Winner University

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/the-winner-university/)  
`Database`

**Problem Link:** [LeetCode 2072 - The Winner University](https://leetcode.com/problems/the-winner-university/)

## Problem

Table: NewYork

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| student_id  | int  |
| score       | int  |
+-------------+------+
In SQL, student_id is the primary key for this table.
Each row contains information about the score of one student from New York University in an exam.
```

Table: California

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| student_id  | int  |
| score       | int  |
+-------------+------+
In SQL, student_id is the primary key for this table.
Each row contains information about the score of one student from California University in an exam.
```

There is a competition between New York University and California University. The competition is held between the same number of students from both universities. The university that has more excellent students wins the competition. If the two universities have the same number of excellent students, the competition ends in a draw.

An excellent student is a student that scored 90% or more in the exam.

Return:

- "New York University" if New York University wins the competition.
- "California University" if California University wins the competition.
- "No Winner" if the competition ends in a draw.

The result format is in the following example.

### Example 1

```text
Input:
NewYork table:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 90    |
| 2          | 87    |
+------------+-------+
California table:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 89    |
| 3          | 88    |
+------------+-------+
Output:
+---------------------+
| winner              |
+---------------------+
| New York University |
+---------------------+
Explanation:
New York University has 1 excellent student, and California University has 0 excellent students.
```

### Example 2

```text
Input:
NewYork table:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 89    |
| 2          | 88    |
+------------+-------+
California table:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 90    |
| 3          | 87    |
+------------+-------+
Output:
+-----------------------+
| winner                |
+-----------------------+
| California University |
+-----------------------+
Explanation:
New York University has 0 excellent students, and California University has 1 excellent student.
```

### Example 3

```text
Input:
NewYork table:
+------------+-------+
| student_id | score |
+------------+-------+
| 1          | 89    |
| 2          | 90    |
+------------+-------+
California table:
+------------+-------+
| student_id | score |
+------------+-------+
| 2          | 87    |
| 3          | 99    |
+------------+-------+
Output:
+-----------+
| winner    |
+-----------+
| No Winner |
+-----------+
Explanation:
Both New York University and California University have 1 excellent student.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Number of Rich Customers](https://leetcode.com/problems/the-number-of-rich-customers/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2072. The Winner University

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: DataFrame Filtering and Analysis | Pandas |

## Approach: DataFrame Filtering and Analysis

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_winner(new_york: pd.DataFrame, california: pd.DataFrame) -> pd.DataFrame:
    # Counting the number of excellent students from each university
    ny_excellent_count = new_york[new_york["score"] >= 90].shape[0]
    ca_excellent_count = california[california["score"] >= 90].shape[0]

    # Comparing the counts to determine the winner
    if ny_excellent_count > ca_excellent_count:
        winner = "New York University"
    elif ny_excellent_count < ca_excellent_count:
        winner = "California University"
    else:
        winner = "No Winner"

    # Returning the result as a DataFrame
    return pd.DataFrame({"winner": [winner]})
```

</details>
