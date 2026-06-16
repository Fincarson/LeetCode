# 584. Find Customer Referee

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-customer-referee/)  
`Database`

**Problem Link:** [LeetCode 584 - Find Customer Referee](https://leetcode.com/problems/find-customer-referee/)

## Problem

Table: Customer

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
```

Find the names of the customer that are either:

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output:
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
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

# Editorial - 584. Find Customer Referee

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using `<>`(`!=`) and `IS NULL` [Accepted] | SQL, MySQL |

## Approach: Using `<>`(`!=`) and `IS NULL` [Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT name FROM customer WHERE referee_Id <> 2;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;
```

</details>

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT name FROM customer WHERE referee_id = NULL OR referee_id <> 2;
```

</details>
