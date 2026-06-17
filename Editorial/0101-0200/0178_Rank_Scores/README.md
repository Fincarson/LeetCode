# 178. Rank Scores

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/rank-scores/)  
`Database`

**Problem Link:** [LeetCode 178 - Rank Scores](https://leetcode.com/problems/rank-scores/)

## Problem

Table: Scores

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.
```

Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:

- The scores should be ranked from the highest to the lowest.
- If there is a tie between two scores, both should have the same ranking.
- After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.

Return the result table ordered by score in descending order.

The result format is in the following example.

### Example 1

```text
Input:
Scores table:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
Output:
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
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

# Editorial - 178. Rank Scores

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DENSE_RANK | Pandas |
| Using DENSE_RANK() Window Function for Ranking | SQL |
| Correlated subquery with `COUNT(DISTINCT ...)` | SQL |
| `INNER JOIN` with `COUNT(DISTINCT ...)` | SQL |

## Approach 1: DENSE_RANK

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    return scores[['score', 'rank']].sort_values('score', ascending=False)
```

</details>

<br>

## Approach 1: Using DENSE_RANK() Window Function for Ranking

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  S.score,
  DENSE_RANK() OVER (
    ORDER BY
      S.score DESC
  ) AS 'rank'
FROM
  Scores S;
```

</details>

<br>

## Approach 2: Correlated subquery with `COUNT(DISTINCT ...)`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  S1.score,
  (
    SELECT
      COUNT(DISTINCT S2.score)
    FROM
      Scores S2
    WHERE
      S2.score >= S1.score
  ) AS 'rank'
FROM
  Scores S1
ORDER BY
  S1.score DESC;
```

</details>

<br>

## Approach 3: `INNER JOIN` with `COUNT(DISTINCT ...)`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  S.score,
  COUNT(DISTINCT T.score) AS 'rank'
FROM
  Scores S
  INNER JOIN Scores T ON S.score <= T.score
GROUP BY
  S.id,
  S.score
ORDER BY
  S.score DESC;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  S.id AS S_ID,
  S.score AS S_Score,
  T.id AS T_ID,
  T.score AS T_Score
FROM
  Scores S
  INNER JOIN Scores T ON S.score <= T.score
ORDER BY
  S.id,
  T.score;
```

</details>
