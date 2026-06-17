# 1549. The Most Recent Orders for Each Product

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/the-most-recent-orders-for-each-product/)  
`Database`

**Problem Link:** [LeetCode 1549 - The Most Recent Orders for Each Product](https://leetcode.com/problems/the-most-recent-orders-for-each-product/)

## Problem

Table: Customers

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id is the column with unique values for this table.
This table contains information about the customers.
```

Table: Orders

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| product_id    | int     |
+---------------+---------+
order_id is the column with unique values for this table.
This table contains information about the orders made by customer_id.
There will be no product ordered by the same user more than once in one day.
```

Table: Products

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id is the column with unique values for this table.
This table contains information about the Products.
```

Write a solution to find the most recent order(s) of each product.

Return the result table ordered by product_name in ascending order and in case of a tie by the product_id in ascending order. If there still a tie, order them by order_id in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Customers table:
+-------------+-----------+
| customer_id | name      |
+-------------+-----------+
| 1           | Winston   |
| 2           | Jonathan  |
| 3           | Annabelle |
| 4           | Marwan    |
| 5           | Khaled    |
+-------------+-----------+
Orders table:
+----------+------------+-------------+------------+
| order_id | order_date | customer_id | product_id |
+----------+------------+-------------+------------+
| 1        | 2020-07-31 | 1           | 1          |
| 2        | 2020-07-30 | 2           | 2          |
| 3        | 2020-08-29 | 3           | 3          |
| 4        | 2020-07-29 | 4           | 1          |
| 5        | 2020-06-10 | 1           | 2          |
| 6        | 2020-08-01 | 2           | 1          |
| 7        | 2020-08-01 | 3           | 1          |
| 8        | 2020-08-03 | 1           | 2          |
| 9        | 2020-08-07 | 2           | 3          |
| 10       | 2020-07-15 | 1           | 2          |
+----------+------------+-------------+------------+
Products table:
+------------+--------------+-------+
| product_id | product_name | price |
+------------+--------------+-------+
| 1          | keyboard     | 120   |
| 2          | mouse        | 80    |
| 3          | screen       | 600   |
| 4          | hard disk    | 450   |
+------------+--------------+-------+
Output:
+--------------+------------+----------+------------+
| product_name | product_id | order_id | order_date |
+--------------+------------+----------+------------+
| keyboard     | 1          | 6        | 2020-08-01 |
| keyboard     | 1          | 7        | 2020-08-01 |
| mouse        | 2          | 8        | 2020-08-03 |
| screen       | 3          | 3        | 2020-08-29 |
+--------------+------------+----------+------------+
Explanation:
keyboard's most recent order is in 2020-08-01, it was ordered two times this day.
mouse's most recent order is in 2020-08-03, it was ordered only once this day.
screen's most recent order is in 2020-08-29, it was ordered only once this day.
The hard disk was never ordered and we do not include it in the result table.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Most Recent Three Orders](https://leetcode.com/problems/the-most-recent-three-orders/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [The Most Frequently Ordered Products for Each Customer](https://leetcode.com/problems/the-most-frequently-ordered-products-for-each-customer/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1549. The Most Recent Orders for Each Product

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using max() to Find the Most Recent Order First | Pandas |
| Filtering Rows by Maximum Value Using Lambda Function | Pandas |
| Using MAX() to Find the Most Recent Order | SQL |
| Using RANK() to Find the Most Recent Order | SQL |

## Approach 1: Using max() to Find the Most Recent Order First

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def most_recent_orders(customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:

    df = orders.groupby(['product_id'], as_index=False).order_date.max()

    df = df.merge(orders, on=['product_id', 'order_date'])

    df = df.merge(products, on='product_id')

    return df[['product_name', 'product_id', 'order_id', 'order_date']].sort_values(['product_name', 'product_id', 'order_id'])
```

</details>

<br>

## Approach 2: Filtering Rows by Maximum Value Using Lambda Function

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def most_recent_orders(customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:

    df = orders.merge(products, on='product_id').reset_index()

    df = df.groupby('product_id').apply(lambda x:x[x.order_date == x.order_date.max()]).reset_index(drop=True)

    return df[['product_name', 'product_id', 'order_id', 'order_date']].sort_values(['product_name', 'product_id', 'order_id'])
```

</details>

<br>

## Approach 1: Using MAX() to Find the Most Recent Order

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    DISTINCT product_id, 
    MAX(order_date) AS order_date
FROM Orders
GROUP BY 1
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    DISTINCT p.product_name,
    p.product_id,
    o.order_id,
    o.order_date
FROM 
    Products p 
JOIN 
    Orders o
ON 
    p.product_id = o.product_id
```

</details>

<br>

## Approach 2: Using RANK() to Find the Most Recent Order

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    order_id, 
    order_date, 
    product_id,
    RANK() OVER (PARTITION BY product_id ORDER BY order_date DESC) AS rnk
FROM 
    Orders
```

</details>
