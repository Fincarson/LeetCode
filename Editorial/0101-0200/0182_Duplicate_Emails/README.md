# 182. Duplicate Emails

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/duplicate-emails/)  
`Database`

**Problem Link:** [LeetCode 182 - Duplicate Emails](https://leetcode.com/problems/duplicate-emails/)

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

Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
Output:
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Explanation: a@b.com is repeated two times.
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

# Editorial - 182. Duplicate Emails

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Frequency-based Filtering for Duplicates | Pandas |
| Group-Filter-Deduplicate | Pandas |
| Using `GROUP BY` and Subquery | SQL |
| Using `GROUP BY` and `HAVING` condition | SQL |

## Approach 1: Frequency-based Filtering for Duplicates

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:   
  # Group by 'Email' and count occurrences
  email_counts = person.groupby('email').size().reset_index(name='num')
  
  # Filter for emails that occur more than once
  duplicated_emails_df = email_counts[email_counts['num'] > 1][['email']]
  
  return duplicated_emails_df
```

</details>

<br>

## Approach 2: Group-Filter-Deduplicate

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
  duplicated_emails_df = person.groupby('email').filter(lambda x: len(x) > 1)[['email']].drop_duplicates()
  
  return duplicated_emails_df
```

</details>

<br>

## Approach 1: Using `GROUP BY` and Subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
select Email, count(Email) as num
from Person
group by Email;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
select Email from
(
  select Email, count(Email) as num
  from Person
  group by Email
) as statistic
where num > 1
;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
select Email from
(
  select Email, count(Email) as num
  from Person
  group by Email
) as statistic
where num > 1
;
```

</details>

<br>

## Approach 2: Using `GROUP BY` and `HAVING` condition

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
select Email
from Person
group by Email
having count(Email) > 1;
```

</details>
