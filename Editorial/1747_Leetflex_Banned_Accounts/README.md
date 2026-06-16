# 1747. Leetflex Banned Accounts

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/leetflex-banned-accounts/)  
`Database`

**Problem Link:** [LeetCode 1747 - Leetflex Banned Accounts](https://leetcode.com/problems/leetflex-banned-accounts/)

## Problem

Table: LogInfo

```text
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| account_id  | int      |
| ip_address  | int      |
| login       | datetime |
| logout      | datetime |
+-------------+----------+
This table may contain duplicate rows.
The table contains information about the login and logout dates of Leetflex accounts. It also contains the IP address from which the account was logged in and out.
It is guaranteed that the logout time is after the login time.
```

Write a solution to find the account_id of the accounts that should be banned from Leetflex. An account should be banned if it was logged in at some moment from two different IP addresses.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
LogInfo table:
+------------+------------+---------------------+---------------------+
| account_id | ip_address | login               | logout              |
+------------+------------+---------------------+---------------------+
| 1          | 1          | 2021-02-01 09:00:00 | 2021-02-01 09:30:00 |
| 1          | 2          | 2021-02-01 08:00:00 | 2021-02-01 11:30:00 |
| 2          | 6          | 2021-02-01 20:30:00 | 2021-02-01 22:00:00 |
| 2          | 7          | 2021-02-02 20:30:00 | 2021-02-02 22:00:00 |
| 3          | 9          | 2021-02-01 16:00:00 | 2021-02-01 16:59:59 |
| 3          | 13         | 2021-02-01 17:00:00 | 2021-02-01 17:59:59 |
| 4          | 10         | 2021-02-01 16:00:00 | 2021-02-01 17:00:00 |
| 4          | 11         | 2021-02-01 17:00:00 | 2021-02-01 17:59:59 |
+------------+------------+---------------------+---------------------+
Output:
+------------+
| account_id |
+------------+
| 1          |
| 4          |
+------------+
Explanation:
Account ID 1 --> The account was active from "2021-02-01 09:00:00" to "2021-02-01 09:30:00" with two different IP addresses (1 and 2). It should be banned.
Account ID 2 --> The account was active from two different addresses (6, 7) but in two different times.
Account ID 3 --> The account was active from two different addresses (9, 13) on the same day but they do not intersect at any moment.
Account ID 4 --> The account was active from "2021-02-01 17:00:00" to "2021-02-01 17:00:00" with two different IP addresses (10 and 11). It should be banned.
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

# Editorial - 1747. Leetflex Banned Accounts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Merge (cross) & Conditional Index | Pandas |
| Using `CROSS JOIN` and `DISTINCT` | SQL |

## Approach 1: Merge (cross) & Conditional Index

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def leetflex_banned_accnts(log_info: pd.DataFrame) -> pd.DataFrame:
    # Approach: .merge(cross) and filter
    df = log_info.merge(log_info, how="cross")

    # Filter rows that have same account_id, different ip_address, and overlapped logged in times.
    df = df[df['account_id_x'] == df['account_id_y']]
    df = df[df['ip_address_x'] != df['ip_address_y']]
    df = df[(df['login_x'] <= df['logout_y']) & (df['login_y'] <= df['logout_x'])]
    
    # Drop duplicates on account_id
    df = df.drop_duplicates('account_id_x')

    # Rename output column
    df = df.rename(columns={'account_id_x': 'account_id'})

    return df[['account_id']]
```

</details>

<br>

## Approach 1: Using `CROSS JOIN` and `DISTINCT`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
  DISTINCT l1.account_id
FROM
  LogInfo l1
CROSS JOIN
  LogInfo l2
WHERE
  l1.account_id = l2.account_id AND
  l1.ip_address != l2.ip_address AND
  l1.login <= l2.logout AND l2.login <= l1.logout
```

</details>
