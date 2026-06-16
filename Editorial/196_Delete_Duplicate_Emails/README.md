# 196. Delete Duplicate Emails

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/delete-duplicate-emails/)  
`Database`

**Problem Link:** [LeetCode 196 - Delete Duplicate Emails](https://leetcode.com/problems/delete-duplicate-emails/)

## Problem

Table: Person

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
```

Write a solution to delete all duplicate emails, keeping only one unique email with the smallest id.

For SQL users, please note that you are supposed to write a DELETE statement and not a SELECT one.

For Pandas users, please note that you are supposed to modify Person in place.

After running your script, the answer shown is the Person table. The driver will first compile and run your piece of code and then show the Person table. The final order of the Person table does not matter.

The result format is in the following example.

### Example 1

```text
Input:
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
Explanation: john@example.com is repeated two times. We keep the row with the smallest Id = 1.
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

# Editorial - 196. Delete Duplicate Emails

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Grouping | Pandas |
| Approach: Using `DELETE` and `WHERE` clause | SQL |

## Approach: Grouping

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    min_id = person.groupby('email')['id'].transform('min')
    removed_person = person[person['id'] != min_id] 
    person.drop(removed_person.index, inplace=True)
    return
```

</details>

<br>

## Approach: Using `DELETE` and `WHERE` clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT p1.*
FROM person p1,
    person p2
WHERE
    p1.Email = p2.Email
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT p1.*
FROM person p1,
    person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
DELETE p1 FROM person p1,
    person p2
WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id
```

</details>
