# 1069. Product Sales Analysis II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/product-sales-analysis-ii/)  
`Database`

**Problem Link:** [LeetCode 1069 - Product Sales Analysis II](https://leetcode.com/problems/product-sales-analysis-ii/)

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

Write a solution that reports the total quantity sold for every product id.

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
+--------------+----------------+
| product_id   | total_quantity |
+--------------+----------------+
| 100          | 22             |
| 200          | 15             |
+--------------+----------------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product Sales Analysis I](https://leetcode.com/problems/product-sales-analysis-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Product Sales Analysis III](https://leetcode.com/problems/product-sales-analysis-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Product Sales Analysis IV](https://leetcode.com/problems/product-sales-analysis-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Product Sales Analysis V](https://leetcode.com/problems/product-sales-analysis-v/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1069. Product Sales Analysis II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Get Aggregated Sum by Using groupby and sum() | Pandas |
| Approach: Get Aggregated Sum by Using GROUP BY and SUM() | SQL |

## Approach: Get Aggregated Sum by Using groupby and sum()

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:

    pd = sales.groupby(['product_id'], as_index = False)['quantity'].sum().rename(columns = {'quantity': 'total_quantity'})

    return pd
```

</details>

<br>

## Approach: Get Aggregated Sum by Using GROUP BY and SUM()

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT product_id,
       SUM(quantity) AS total_quantity
FROM Sales
GROUP BY product_id
```

</details>
