# 1082. Sales Analysis I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sales-analysis-i/)  
`Database`

**Problem Link:** [LeetCode 1082 - Sales Analysis I](https://leetcode.com/problems/sales-analysis-i/)

## Problem

Table: Product

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
| unit_price   | int     |
+--------------+---------+
product_id is the primary key (column with unique values) of this table.
Each row of this table indicates the name and the price of each product.
```

Table: Sales

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| seller_id   | int     |
| product_id  | int     |
| buyer_id    | int     |
| sale_date   | date    |
| quantity    | int     |
| price       | int     |
+-------------+---------+
This table can have repeated rows.
product_id is a foreign key (reference column) to the Product table.
Each row of this table contains some information about one sale.
```

Write a solution that reports the best seller by total sales price, If there is a tie, report them all.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Product table:
+------------+--------------+------------+
| product_id | product_name | unit_price |
+------------+--------------+------------+
| 1          | S8           | 1000       |
| 2          | G4           | 800        |
| 3          | iPhone       | 1400       |
+------------+--------------+------------+
Sales table:
+-----------+------------+----------+------------+----------+-------+
| seller_id | product_id | buyer_id | sale_date  | quantity | price |
+-----------+------------+----------+------------+----------+-------+
| 1         | 1          | 1        | 2019-01-21 | 2        | 2000  |
| 1         | 2          | 2        | 2019-02-17 | 1        | 800   |
| 2         | 2          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 4        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
Output:
+-------------+
| seller_id   |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Both sellers with id 1 and 3 sold products with the most total price of 2800.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sales Analysis II](https://leetcode.com/problems/sales-analysis-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1082. Sales Analysis I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Max Sales Filtering with Aggregation | Pandas |
| Max Sales Filtering with Aggregation | SQL |

## Approach 1: Max Sales Filtering with Aggregation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    # Calculate total sales price for each seller
    aggregated_sales = sales.groupby("seller_id").agg({"price": "sum"})

    # Filter the sellers with maximum total sales price
    best_sellers = aggregated_sales[
        aggregated_sales["price"] == aggregated_sales["price"].max()
    ].reset_index()

    return best_sellers[["seller_id"]]
```

</details>

<br>

## Approach 1: Max Sales Filtering with Aggregation

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH aggregated_sales AS (
  SELECT 
    seller_id, 
    SUM(price) AS total_price 
  FROM 
    Sales 
  GROUP BY 
    seller_id
)
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  MAX(total_price) 
FROM 
  aggregated_sales
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  seller_id 
FROM 
  aggregated_sales 
WHERE 
  total_price = (
    SELECT 
      MAX(total_price) 
    FROM 
      aggregated_sales
  );
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
WITH aggregated_sales AS (
  SELECT 
    seller_id, 
    SUM(price) AS total_price 
  FROM 
    Sales 
  GROUP BY 
    seller_id
) 
SELECT 
  seller_id 
FROM 
  aggregated_sales 
WHERE 
  total_price = (
    SELECT 
      MAX(total_price) 
    FROM 
      aggregated_sales
  );
```

</details>
