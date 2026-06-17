# 3059. Find All Unique Email Domains

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-all-unique-email-domains/)  
`Database`

**Problem Link:** [LeetCode 3059 - Find All Unique Email Domains](https://leetcode.com/problems/find-all-unique-email-domains/)

## Problem

Table: Emails

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

Write a solution to find all unique email domains and count the number of individuals associated with each domain. Consider only those domains that end with .com.

Return the result table orderd by email domains in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Emails table:
+-----+-----------------------+
| id  | email                 |
+-----+-----------------------+
| 336 | hwkiy@test.edu        |
| 489 | adcmaf@outlook.com    |
| 449 | vrzmwyum@yahoo.com    |
| 95  | tof@test.edu          |
| 320 | jxhbagkpm@example.org |
| 411 | zxcf@outlook.com      |
+----+------------------------+
Output:
+--------------+-------+
| email_domain | count |
+--------------+-------+
| outlook.com  | 2     |
| yahoo.com    | 1     |
+--------------+-------+
Explanation:
- The valid domains ending with ".com" are only "outlook.com" and "yahoo.com", with respective counts of 2 and 1.
Output table is ordered by email_domains in ascending order.
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

# Editorial - 3059. Find All Unique Email Domains

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Regex Filtering | Pandas |
| Approach: Filter Utilizing `LIKE` | MySQL |

## Approach: Regex Filtering

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_unique_email_domains(emails: pd.DataFrame) -> pd.DataFrame:
    return (
        emails[emails["email"].str.endswith(".com")]
        .assign(email_domain=lambda df: df["email"].str.extract("@([^@]+)$"))
        .groupby("email_domain")["id"]
        .nunique()
        .reset_index(name="count")
        .sort_values(by="email_domain", ascending=True)
    )
```

</details>

<br>

## Approach: Filter Utilizing `LIKE`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
  SUBSTRING_INDEX(email, '@', -1) AS email_domain, 
  COUNT(DISTINCT id) AS count 
FROM 
  Emails 
WHERE 
  email LIKE '%.com' 
GROUP BY 
  email_domain 
ORDER BY 
  email_domain asc;
```

</details>
