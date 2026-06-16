# 1149. Article Views II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/article-views-ii/)  
`Database`

**Problem Link:** [LeetCode 1149 - Article Views II](https://leetcode.com/problems/article-views-ii/)

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
This table may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date.
Note that equal author_id and viewer_id indicate the same person.
```

Write a solution to find all the people who viewed more than one article on the same date.

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
| 3          | 4         | 5         | 2019-08-01 |
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
| 5    |
| 6    |
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

# Editorial - 1149. Article Views II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Groupby with Filter | Python3, Pandas |
| Self-Join | Python3, Pandas |
| Groupby with Having | SQL |
| Self-Join | SQL |

## Approach 1: Groupby with Filter

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
grouped = views.groupby(["viewer_id", "view_date"])
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
aggregated = grouped.agg({"article_id": "nunique"})
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
filtered = aggregated[aggregated["article_id"] > 1].reset_index()
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
distinct_viewers = filtered["viewer_id"].drop_duplicates()
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
final_result = (
    distinct_viewers
    .sort_values()
    .to_frame(name="id")
    .reset_index(drop=True)
)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Group by viewer_id and view_date, then count unique articles
    grouped = views.groupby(["viewer_id", "view_date"]).agg({"article_id": "nunique"})

    # Filter out entries with unique article counts less than or equal to 1
    result = grouped[grouped["article_id"] > 1].reset_index()

    # Extract and sort the viewer IDs, drop duplicates and return as a DataFrame
    final_result = (
        result["viewer_id"]
        .sort_values()
        .drop_duplicates()
        .to_frame(name="id")
        .reset_index(drop=True)
    )

    return final_result
```

</details>

<br>

## Approach 2: Self-Join

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
merged_views = views.merge(views, on=["viewer_id", "view_date"])
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
distinct_articles = merged_views[
    (merged_views["article_id_x"] < merged_views["article_id_y"])
]
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
distinct_viewer_ids = distinct_articles[["viewer_id"]].drop_duplicates()
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
final_result = distinct_viewer_ids.sort_values("viewer_id").rename(columns={"viewer_id": "id"}).reset_index(drop=True)
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Self join on viewer_id and view_date, but ensure different articles
    merged_views = views.merge(views, on=["viewer_id", "view_date"])
    distinct_articles = merged_views[
        merged_views["article_id_x"] < merged_views["article_id_y"]
    ]

    # Extract unique viewer IDs who viewed more than one article on the same date
    result = (
        distinct_articles[["viewer_id"]]
        .drop_duplicates()
        .rename(columns={"viewer_id": "id"})
    )

    return result.sort_values("id").reset_index(drop=True)
```

</details>

<br>

## Approach 1: Groupby with Having

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  viewer_id, 
  view_date, 
  ARRAY_AGG(article_id) as articles 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  viewer_id, 
  view_date, 
  COUNT(DISTINCT article_id) as article_count 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  viewer_id, 
  view_date, 
  COUNT(DISTINCT article_id) as article_count 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date 
HAVING 
  COUNT(DISTINCT article_id) > 1;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT viewer_id as id 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date 
HAVING 
  COUNT(DISTINCT article_id) > 1;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT viewer_id as id 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date 
HAVING 
  COUNT(DISTINCT article_id) > 1 
ORDER BY 
  viewer_id;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT viewer_id as id 
FROM 
  Views 
GROUP BY 
  viewer_id, 
  view_date 
HAVING 
  COUNT(DISTINCT article_id) > 1 
ORDER BY 
  viewer_id;
```

</details>

<br>

## Approach 2: Self-Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  v1.article_id AS article_id_1, 
  v2.article_id AS article_id_2, 
  v1.viewer_id, 
  v1.view_date 
FROM 
  Views v1 
  JOIN Views v2 ON v1.viewer_id = v2.viewer_id 
  AND v1.view_date = v2.view_date
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  v1.article_id AS article_id_1, 
  v2.article_id AS article_id_2, 
  v1.viewer_id, 
  v1.view_date 
FROM 
  Views v1 
  JOIN Views v2 ON v1.viewer_id = v2.viewer_id 
  AND v1.view_date = v2.view_date 
  AND v1.article_id < v2.article_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT v1.viewer_id 
FROM 
  Views v1 
  JOIN Views v2 ON v1.viewer_id = v2.viewer_id 
  AND v1.view_date = v2.view_date 
  AND v1.article_id < v2.article_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT v1.viewer_id AS id 
FROM 
  Views v1 
  JOIN Views v2 ON v1.viewer_id = v2.viewer_id 
  AND v1.view_date = v2.view_date 
  AND v1.article_id < v2.article_id 
ORDER BY 
  v1.viewer_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  DISTINCT v1.viewer_id AS id 
FROM 
  Views v1 
  JOIN Views v2 ON v1.viewer_id = v2.viewer_id 
  AND v1.view_date = v2.view_date 
  AND v1.article_id < v2.article_id 
ORDER BY 
  v1.viewer_id;
```

</details>
