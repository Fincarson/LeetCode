# 175. Combine Two Tables

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/combine-two-tables/)  
`Database`

**Problem Link:** [LeetCode 175 - Combine Two Tables](https://leetcode.com/problems/combine-two-tables/)

## Problem

Table: Person

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+
personId is the primary key (column with unique values) for this table.
This table contains information about the ID of some persons and their first and last names.
```

Table: Address

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+
addressId is the primary key (column with unique values) for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.
```

Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Person table:
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |
+----------+----------+-----------+
Address table:
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |
+-----------+----------+---------------+------------+
Output:
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |
+-----------+----------+---------------+----------+
Explanation:
There is no address in the address table for the personId = 1 so we return null in their city and state.
addressId = 1 contains information about the address of personId = 2.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Employee Bonus](https://leetcode.com/problems/employee-bonus/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 175. Combine Two Tables

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using `merge` | Pandas |
| Using `outer join` | SQL |

## Approach 1: Using `merge`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    result = pd.merge(person, address, on='personId', how='left')
    result = result[['firstName', 'lastName', 'city', 'state']]
    return result
```

</details>

<br>

## Approach 1: Using `outer join`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId
;
```

</details>
