# 574. Winning Candidate

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/winning-candidate/)  
`Database`

**Problem Link:** [LeetCode 574 - Winning Candidate](https://leetcode.com/problems/winning-candidate/)

## Problem

Table: Candidate

```text
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
+-------------+----------+
id is the column with unique values for this table.
Each row of this table contains information about the id and the name of a candidate.
```

Table: Vote

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| candidateId | int  |
+-------------+------+
id is an auto-increment primary key (column with unique values).
candidateId is a foreign key (reference column) to id from the Candidate table.
Each row of this table determines the candidate who got the ith vote in the elections.
```

Write a solution to report the name of the winning candidate (i.e., the candidate who got the largest number of votes).

The test cases are generated so that exactly one candidate wins the elections.

The result format is in the following example.

### Example 1

```text
Input:
Candidate table:
+----+------+
| id | name |
+----+------+
| 1  | A    |
| 2  | B    |
| 3  | C    |
| 4  | D    |
| 5  | E    |
+----+------+
Vote table:
+----+-------------+
| id | candidateId |
+----+-------------+
| 1  | 2           |
| 2  | 4           |
| 3  | 3           |
| 4  | 2           |
| 5  | 5           |
+----+-------------+
Output:
+------+
| name |
+------+
| B    |
+------+
Explanation:
Candidate B has 2 votes. Candidates C, D, and E have 1 vote each.
The winner is candidate B.
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

# Editorial - 574. Winning Candidate

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group and Aggregate for Maximum |  |
| Approach: Group and Find the Maximum using the `ORDER BY` Clause | SQL |

## Approach: Group and Aggregate for Maximum

### Implementation

<br>

## Approach: Group and Find the Maximum using the `ORDER BY` Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  c.name 
FROM 
  Candidate AS c 
  JOIN (
    SELECT 
      candidateId, 
      COUNT(*) AS vote_count 
    FROM 
      Vote 
    GROUP BY 
      candidateId 
    ORDER BY 
      COUNT(*) DESC 
    LIMIT 
      1
  ) AS v 
  ON c.id = v.candidateId;
```

</details>
