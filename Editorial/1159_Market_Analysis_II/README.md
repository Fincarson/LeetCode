# 1159. Market Analysis II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/market-analysis-ii/)  
`Database`

**Problem Link:** [LeetCode 1159 - Market Analysis II](https://leetcode.com/problems/market-analysis-ii/)

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

Write a solution to find for each user whether the brand of the second item (by date) they sold is their favorite brand. If a user sold less than two items, report the answer for that user as no. It is guaranteed that no seller sells more than one item in a day.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2019-01-01 | Lenovo         |
| 2       | 2019-02-09 | Samsung        |
| 3       | 2019-01-19 | LG             |
| 4       | 2019-05-21 | HP             |
+---------+------------+----------------+
Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2019-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2019-08-04 | 1       | 4        | 2         |
| 5        | 2019-08-04 | 1       | 3        | 4         |
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
+-----------+--------------------+
| seller_id | 2nd_item_fav_brand |
+-----------+--------------------+
| 1         | no                 |
| 2         | yes                |
| 3         | yes                |
| 4         | no                 |
+-----------+--------------------+
Explanation:
The answer for the user with id 1 is no because they sold nothing.
The answer for the users with id 2 and 3 is yes because the brands of their second sold items are their favorite brands.
The answer for the user with id 4 is no because the brand of their second sold item is not their favorite brand.
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

# Editorial - 1159. Market Analysis II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: rank() First and Build the Condition Using np.where() | Pandas |
| Approach: Using Window Function to Rank | SQL |

## Approach: rank() First and Build the Condition Using np.where()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def market_analysis(users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:

    orders["rank"] = orders.groupby("seller_id")["order_date"].rank()

    orders_and_items = orders.merge(items, on = 'item_id')
    
    second_item = orders_and_items[orders_and_items['rank'] == 2]

    users_and_second_item = users.merge(second_item, left_on = 'user_id', right_on = 'seller_id', how = 'left')

    users_and_second_item['2nd_item_fav_brand'] = (users_and_second_item['favorite_brand'] == users_and_second_item['item_brand']).apply(lambda x: 'yes' if x else 'no')

    final_output = users_and_second_item[['user_id', '2nd_item_fav_brand']].rename(columns= {'user_id': 'seller_id'})

    return final_output
```

</details>

<br>

## Approach: Using Window Function to Rank

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT seller_id, 
       item_id,
       RANK() OVER (PARTITION BY seller_id ORDER BY order_date ASC) AS rnk
FROM Orders
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT a.seller_id, a.item_id, i.item_brand
FROM (
    SELECT seller_id, 
           item_id,
           RANK() OVER (PARTITION BY seller_id ORDER BY order_date ASC) AS rnk
    FROM Orders) a
JOIN Items i
ON a.item_id = i.item_id
WHERE a.rnk = 2
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT u.user_id AS seller_id, 
       CASE WHEN u.favorite_brand = b.item_brand THEN 'yes' ELSE 'no' END AS 2nd_item_fav_brand
FROM Users u
LEFT JOIN(
    SELECT a.seller_id, a.item_id, i.item_brand
    FROM (
        SELECT seller_id, 
               item_id,
               RANK() OVER (PARTITION BY seller_id ORDER BY order_date ASC) AS rnk
        FROM Orders) a
    JOIN Items i
    ON a.item_id = i.item_id
    WHERE a.rnk = 2) b
ON u.user_id = b.seller_id
```

</details>
