# 1068. Product Sales Analysis I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/product-sales-analysis-i/)  
`Database`

**Problem Link:** [LeetCode 1068 - Product Sales Analysis I](https://leetcode.com/problems/product-sales-analysis-i/)

## Problem

Table: Sales

```text
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) is the primary key (combination of columns with unique values) of this table.
product_id is a foreign key (reference column) to Product table.
Each row of this table shows a sale on the product product_id in a certain year.
Note that the price is per unit.
```

Table: Product

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| product_id   | int     |
| product_name | varchar |
+--------------+---------+
product_id is the primary key (column with unique values) of this table.
Each row of this table indicates the product name of each product.
```

Write a solution to report the product_name, year, and price for each sale_id in the Sales table.

Return the resulting table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Sales table:
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
Product table:
+------------+--------------+
| product_id | product_name |
+------------+--------------+
| 100        | Nokia        |
| 200        | Apple        |
| 300        | Samsung      |
+------------+--------------+
Output:
+--------------+-------+-------+
| product_name | year  | price |
+--------------+-------+-------+
| Nokia        | 2008  | 5000  |
| Nokia        | 2009  | 5000  |
| Apple        | 2011  | 9000  |
+--------------+-------+-------+
Explanation:
From sale_id = 1, we can conclude that Nokia was sold for 5000 in the year 2008.
From sale_id = 2, we can conclude that Nokia was sold for 5000 in the year 2009.
From sale_id = 7, we can conclude that Apple was sold for 9000 in the year 2011.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product Sales Analysis II](https://leetcode.com/problems/product-sales-analysis-ii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Product Sales Analysis IV](https://leetcode.com/problems/product-sales-analysis-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Product Sales Analysis V](https://leetcode.com/problems/product-sales-analysis-v/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1068. Product Sales Analysis I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Inner Join | Pandas |
| Approach: Inner Join | SQL |

## Approach: Inner Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    sales_and_product = sales.merge(
        product,
        on=["product_id"]
        )
    df = sales_and_product[['product_name', 'year', 'price']]

    return df
```

</details>

<br>

## Approach: Inner Join

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    p.product_name, s.year, s.price
FROM 
    Sales s
JOIN 
    Product p
ON
    s.product_id = p.product_id
```

</details>
