# 1148. Article Views I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/article-views-i/)  
`Database`

**Problem Link:** [LeetCode 1148 - Article Views I](https://leetcode.com/problems/article-views-i/)

## Problem

Table: Views

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key (column with unique values) for this table, the table may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date.
Note that equal author_id and viewer_id indicate the same person.
```

Write a solution to find all the authors that viewed at least one of their own articles.

Return the result table sorted by id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
Output:
+------+
| id   |
+------+
| 4    |
| 7    |
+------+
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

# Editorial - 1148. Article Views I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Selecting rows based on conditions | Pandas |
| Approach: Selecting rows based on conditions | SQL |

## Approach: Selecting rows based on conditions

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views[views['author_id'] == views['viewer_id']]

    df.drop_duplicates(subset=['author_id'], inplace=True)
    df.sort_values(by=['author_id'], inplace=True)
    df.rename(columns={'author_id':'id'}, inplace=True)

    df = df[['id']]

    return df
```

</details>

<br>

## Approach: Selecting rows based on conditions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    DISTINCT author_id 
FROM 
    Views 
WHERE 
    author_id = viewer_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    DISTINCT author_id AS id 
FROM 
    Views 
WHERE 
    author_id = viewer_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    DISTINCT author_id AS id 
FROM 
    Views 
WHERE 
    author_id = viewer_id 
ORDER BY 
    id
```

</details>
