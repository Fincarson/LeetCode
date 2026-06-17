# 2041. Accepted Candidates From the Interviews

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/accepted-candidates-from-the-interviews/)  
`Database`

**Problem Link:** [LeetCode 2041 - Accepted Candidates From the Interviews](https://leetcode.com/problems/accepted-candidates-from-the-interviews/)

## Problem

Table: Candidates

```text
+--------------+----------+
| Column Name  | Type     |
+--------------+----------+
| candidate_id | int      |
| name         | varchar  |
| years_of_exp | int      |
| interview_id | int      |
+--------------+----------+
candidate_id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of a candidate, their number of years of experience, and their interview ID.
```

Table: Rounds

```text
+--------------+------+
| Column Name  | Type |
+--------------+------+
| interview_id | int  |
| round_id     | int  |
| score        | int  |
+--------------+------+
(interview_id, round_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the score of one round of an interview.
```

Write a solution to report the IDs of the candidates who have at least two years of experience and the sum of the score of their interview rounds is strictly greater than 15.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Candidates table:
+--------------+---------+--------------+--------------+
| candidate_id | name    | years_of_exp | interview_id |
+--------------+---------+--------------+--------------+
| 11           | Atticus | 1            | 101          |
| 9            | Ruben   | 6            | 104          |
| 6            | Aliza   | 10           | 109          |
| 8            | Alfredo | 0            | 107          |
+--------------+---------+--------------+--------------+
Rounds table:
+--------------+----------+-------+
| interview_id | round_id | score |
+--------------+----------+-------+
| 109          | 3        | 4     |
| 101          | 2        | 8     |
| 109          | 4        | 1     |
| 107          | 1        | 3     |
| 104          | 3        | 6     |
| 109          | 1        | 4     |
| 104          | 4        | 7     |
| 104          | 1        | 2     |
| 109          | 2        | 1     |
| 104          | 2        | 7     |
| 107          | 2        | 3     |
| 101          | 1        | 8     |
+--------------+----------+-------+
Output:
+--------------+
| candidate_id |
+--------------+
| 9            |
+--------------+
Explanation:
- Candidate 11: The total score is 16, and they have one year of experience. We do not include them in the result table because of their years of experience.
- Candidate 9: The total score is 22, and they have six years of experience. We include them in the result table.
- Candidate 6: The total score is 10, and they have ten years of experience. We do not include them in the result table because the score is not good enough.
- Candidate 8: The total score is 6, and they have zero years of experience. We do not include them in the result table because of their years of experience and the score.
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

# Editorial - 2041. Accepted Candidates From the Interviews

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Conditional Index, .groupby().sum(), and .merge() | Pandas |
| Approach: INNER JOIN, WHERE, and GROUP BY ... HAVING | SQL |

## Approach: Conditional Index, .groupby().sum(), and .merge()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def accepted_candidates(candidates: pd.DataFrame, rounds: pd.DataFrame) -> pd.DataFrame:
    # Approach: Conditional Index, Groupby Sum, inner merge
    # Filtering candidates who have at least two YoE
    candidates = candidates[candidates['years_of_exp'] >= 2]

    # .groupby('interview_id')['score'].sum(), filter for > 15
    rounds = rounds.groupby('interview_id')['score'].sum().reset_index(name='total_score')
    rounds = rounds[rounds['total_score'] > 15]

    # Inner merge on `interview_id`, rounds onto candidates
    result = candidates.merge(rounds, how='inner', on='interview_id')

    # Return `candidate_id`
    return result[['candidate_id']]
```

</details>

<br>

## Approach: INNER JOIN, WHERE, and GROUP BY ... HAVING

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
FROM
    Candidates AS c
INNER JOIN
    Rounds AS r
ON
    c.interview_id = r.interview_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WHERE
    c.years_of_exp >= 2
```

</details>
