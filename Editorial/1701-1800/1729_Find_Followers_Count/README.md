# 1729. Find Followers Count

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-followers-count/)  
`Database`

**Problem Link:** [LeetCode 1729 - Find Followers Count](https://leetcode.com/problems/find-followers-count/)

## Problem

Table: Followers

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key (combination of columns with unique values) for this table.
This table contains the IDs of a user and a follower in a social media app where the follower follows the user.
```

Write a solution that will, for each user, return the number of followers.

Return the result table ordered by user_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Followers table:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
Output:
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
Explanation:
The followers of 0 are {1}
The followers of 1 are {0}
The followers of 2 are {0,1}
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

# Editorial - 1729. Find Followers Count

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: `COUNT` and `GROUP BY` | SQL |

## Approach: `COUNT` and `GROUP BY`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT user_id, COUNT(user_id) AS followers_count
FROM followers
GROUP BY user_id
ORDER BY user_id ASC;
```

</details>
