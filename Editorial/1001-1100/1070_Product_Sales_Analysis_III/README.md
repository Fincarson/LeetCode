# 1070. Product Sales Analysis III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/product-sales-analysis-iii/)  
`Database`

**Problem Link:** [LeetCode 1070 - Product Sales Analysis III](https://leetcode.com/problems/product-sales-analysis-iii/)

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
Each row records a sale of a product in a given year.
A product may have multiple sales entries in the same year.
Note that the per-unit price.
```

Write a solution to find all sales that occurred in the first year each product was sold.

- For each product_id, identify the earliest year it appears in the Sales table.
- Return all sales entries for that product in that year.

Return a table with the following columns: product_id, first_year, quantity, and price.
Return the result in any order.

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

Output:
+------------+------------+----------+-------+
| product_id | first_year | quantity | price |
+------------+------------+----------+-------+
| 100        | 2008       | 10       | 5000  |
| 200        | 2011       | 15       | 9000  |
+------------+------------+----------+-------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product Sales Analysis II](https://leetcode.com/problems/product-sales-analysis-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Product Sales Analysis IV](https://leetcode.com/problems/product-sales-analysis-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Product Sales Analysis V](https://leetcode.com/problems/product-sales-analysis-v/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1070. Product Sales Analysis III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group-Merge-Filter | Pandas |
| Approach: Filtering from Minimum Value Subquery | SQL |

## Approach: Group-Merge-Filter

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
  df = sales.groupby('product_id', as_index=False)['year'].min()
  return sales.merge(df, on='product_id', how='inner')\
    .query('year_x == year_y')\
    .rename(columns={'year_x': 'first_year'})\
    [['product_id', 'first_year', 'quantity', 'price']]
```

</details>

<br>

## Approach: Filtering from Minimum Value Subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT 
     product_id, 
     MIN(year) AS year 
   FROM 
     Sales 
   GROUP BY 
     product_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
   SELECT 
     product_id, 
     year AS first_year, 
     quantity, 
     price 
   FROM 
     Sales 
   WHERE 
     (product_id, year) IN (subquery)
```

</details>
