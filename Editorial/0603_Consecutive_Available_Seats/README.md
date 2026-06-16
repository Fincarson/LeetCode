# 603. Consecutive Available Seats

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/consecutive-available-seats/)  
`Database`

**Problem Link:** [LeetCode 603 - Consecutive Available Seats](https://leetcode.com/problems/consecutive-available-seats/)

## Problem

Table: Cinema

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
seat_id is an auto-increment column for this table.
Each row of this table indicates whether the ith seat is free or not. 1 means free while 0 means occupied.
```

Find all the consecutive available seats in the cinema.

Return the result table ordered by seat_id in ascending order.

The test cases are generated so that more than two seats are consecutively available.

The result format is in the following example.

### Example 1

```text
Input:
Cinema table:
+---------+------+
| seat_id | free |
+---------+------+
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
+---------+------+
Output:
+---------+
| seat_id |
+---------+
| 3       |
| 4       |
| 5       |
+---------+
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

# Editorial - 603. Consecutive Available Seats

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using self `join` and `abs()`[Accepted] | SQL |

## Approach: Using self `join` and `abs()`[Accepted]

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
select a.seat_id, a.free, b.seat_id, b.free
from cinema a join cinema b;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
select a.seat_id, a.free, b.seat_id, b.free
from cinema a join cinema b
  on abs(a.seat_id - b.seat_id) = 1
  and a.free = true and b.free = true;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
select distinct a.seat_id
from cinema a join cinema b
  on abs(a.seat_id - b.seat_id) = 1
  and a.free = true and b.free = true
order by a.seat_id
;
```

</details>
