# 1667. Fix Names in a Table

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/fix-names-in-a-table/)  
`Database`

**Problem Link:** [LeetCode 1667 - Fix Names in a Table](https://leetcode.com/problems/fix-names-in-a-table/)

## Problem

Table: Users

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| name           | varchar |
+----------------+---------+
user_id is the primary key (column with unique values) for this table.
This table contains the ID and the name of the user. The name consists of only lowercase and uppercase characters.
```

Write a solution to fix the names so that only the first character is uppercase and the rest are lowercase.

Return the result table ordered by user_id.

The result format is in the following example.

### Example 1

```text
Input:
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
Output:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+
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

# Editorial - 1667. Fix Names in a Table

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Separating the first character from the rest | Pandas |
| Using .capitalize() str method | Pandas |
| Separating the first character from the rest | SQL |

## Approach 1: Separating the first character from the rest

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users["name"] = users["name"].str[0].str.upper() + users["name"].str[1:].str.lower()
    return users.sort_values("user_id")
```

</details>

<br>

## Approach 2: Using .capitalize() str method

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users["name"] = users["name"].str.capitalize()
    return users.sort_values("user_id")
```

</details>

<br>

## Approach 1: Separating the first character from the rest

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT user_id, CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;
```

</details>
