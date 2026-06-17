# 1587. Bank Account Summary II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/bank-account-summary-ii/)  
`Database`

**Problem Link:** [LeetCode 1587 - Bank Account Summary II](https://leetcode.com/problems/bank-account-summary-ii/)

## Problem

Table: Users

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| account      | int     |
| name         | varchar |
+--------------+---------+
account is the primary key (column with unique values) for this table.
Each row of this table contains the account number of each user in the bank.
There will be no two users having the same name in the table.
```

Table: Transactions

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| trans_id      | int     |
| account       | int     |
| amount        | int     |
| transacted_on | date    |
+---------------+---------+
trans_id is the primary key (column with unique values) for this table.
Each row of this table contains all changes made to all accounts.
amount is positive if the user received money and negative if they transferred money.
All accounts start with a balance of 0.
```

Write a solution to report the name and balance of users with a balance higher than 10000. The balance of an account is equal to the sum of the amounts of all transactions involving that account.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Users table:
+------------+--------------+
| account    | name         |
+------------+--------------+
| 900001     | Alice        |
| 900002     | Bob          |
| 900003     | Charlie      |
+------------+--------------+
Transactions table:
+------------+------------+------------+---------------+
| trans_id   | account    | amount     | transacted_on |
+------------+------------+------------+---------------+
| 1          | 900001     | 7000       |  2020-08-01   |
| 2          | 900001     | 7000       |  2020-09-01   |
| 3          | 900001     | -3000      |  2020-09-02   |
| 4          | 900002     | 1000       |  2020-09-12   |
| 5          | 900003     | 6000       |  2020-08-07   |
| 6          | 900003     | 6000       |  2020-09-07   |
| 7          | 900003     | -4000      |  2020-09-11   |
+------------+------------+------------+---------------+
Output:
+------------+------------+
| name       | balance    |
+------------+------------+
| Alice      | 11000      |
+------------+------------+
Explanation:
Alice's balance is (7000 + 7000 - 3000) = 11000.
Bob's balance is 1000.
Charlie's balance is (6000 + 6000 - 4000) = 8000.
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

# Editorial - 1587. Bank Account Summary II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| First Calculate Then JOIN | MySQL |
| Use JOIN and Calculate At Same Time | MySQL |

## Approach 1: First Calculate Then JOIN

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    account, SUM(amount) as balance
FROM 
    Transactions
GROUP BY 1
HAVING 
    balance>10000
```

</details>

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    DISTINCT a.name, b.balance
FROM 
    Users a
JOIN (
    SELECT 
        account, SUM(amount) as balance
    FROM 
        Transactions
    GROUP BY 1
    HAVING balance>10000) b
ON 
    a.account = b.account
```

</details>

<br>

## Approach 2: Use JOIN and Calculate At Same Time

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    u.name, SUM(t.amount) AS balance
FROM 
    Users u
JOIN 
    Transactions t
ON 
    u.account = t.account
GROUP BY u.account
HAVING 
    balance > 10000
```

</details>
