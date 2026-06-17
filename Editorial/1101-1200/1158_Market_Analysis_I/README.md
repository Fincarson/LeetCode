# 1158. Market Analysis I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/market-analysis-i/)  
`Database`

**Problem Link:** [LeetCode 1158 - Market Analysis I](https://leetcode.com/problems/market-analysis-i/)

## Problem

Table: Users

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
user_id is the primary key (column with unique values) of this table.
This table has the info of the users of an online shopping website where users can sell and buy items.
```

Table: Orders

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| buyer_id      | int     |
| seller_id     | int     |
+---------------+---------+
order_id is the primary key (column with unique values) of this table.
item_id is a foreign key (reference column) to the Items table.
buyer_id and seller_id are foreign keys to the Users table.
```

Table: Items

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id is the primary key (column with unique values) of this table.
```

Write a solution to find for each user, the join date and the number of orders they made as a buyer in 2019.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2018-01-01 | Lenovo         |
| 2       | 2018-02-09 | Samsung        |
| 3       | 2018-01-19 | LG             |
| 4       | 2018-05-21 | HP             |
+---------+------------+----------------+
Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2018-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2018-08-04 | 1       | 4        | 2         |
| 5        | 2018-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+
Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+
Output:
+-----------+------------+----------------+
| buyer_id  | join_date  | orders_in_2019 |
+-----------+------------+----------------+
| 1         | 2018-01-01 | 1              |
| 2         | 2018-02-09 | 2              |
| 3         | 2018-01-19 | 0              |
| 4         | 2018-05-21 | 0              |
+-----------+------------+----------------+
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

# Editorial - 1158. Market Analysis I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Right Join and GroupBy | Pandas |
| Left Join and Aggregation | SQL |

## Approach 1: Right Join and GroupBy

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python

import pandas as pd

def market_analysis(
    users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame
) -> pd.DataFrame:

    # Step 1: Filter the orders dataframe to only include orders from the year 2019.
    df = orders.query("order_date.dt.year==2019").merge(
        # Step 2: Merge the filtered orders with the users dataframe on buyer_id and user_id.
        users,
        left_on="buyer_id",
        right_on="user_id",
        how="right",
    )

    # Step 3: Group the merged dataframe by user_id and join_date, then count the number of items (orders) for each user.
    result = df.groupby(["user_id", "join_date"]).item_id.count()

    # Step 4: Format the output by resetting the index and renaming the columns for clarity.
    return result.reset_index().rename(
        columns={"user_id": "buyer_id", "item_id": "orders_in_2019"}
    )
```

</details>

<br>

## Approach 1: Left Join and Aggregation

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   LEFT JOIN Orders o ON u.user_id = o.buyer_id AND YEAR(order_date) = '2019'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  u.user_id AS buyer_id, 
  join_date, 
  COUNT(o.order_id) AS orders_in_2019 
FROM 
  Users u 
  LEFT JOIN Orders o ON u.user_id = o.buyer_id 
  AND YEAR(order_date)= '2019' 
GROUP BY 
  u.user_id 
ORDER BY 
  u.user_id
```

</details>
