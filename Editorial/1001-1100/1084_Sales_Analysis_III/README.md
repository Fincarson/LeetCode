# 1084. Sales Analysis III

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sales-analysis-iii/)  
`Database`

**Problem Link:** [LeetCode 1084 - Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/)

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
This table can have duplicate rows.
product_id is a foreign key (reference column) to the Product table.
Each row of this table contains some information about one sale.
```

Write a solution to report the products that were only sold in the first quarter of 2019. That is, between 2019-01-01 and 2019-03-31 inclusive.

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
+-------------+--------------+
| product_id  | product_name |
+-------------+--------------+
| 1           | S8           |
+-------------+--------------+
Explanation:
The product with id 1 was only sold in the spring of 2019.
The product with id 2 was sold in the spring of 2019 but was also sold after the spring of 2019.
The product with id 3 was sold after spring 2019.
We return only product 1 as it is the product that was only sold in the spring of 2019.
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

# Editorial - 1084. Sales Analysis III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Filter `sales` and Merge with `product` | Pandas |
| Group By and Use Having Clause | SQL |

## Approach 1: Filter `sales` and Merge with `product`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    start_time = pd.to_datetime('2019-01-01')
    end_time = pd.to_datetime('2019-03-31')
    df = sales.groupby('product_id').filter(lambda x:
        min(x['sale_date']) >= start_time and max(x['sale_date']) <= end_time
    )
    df = df.drop_duplicates(subset = 'product_id')
    df = df.merge(product, left_on = 'product_id', right_on = 'product_id')
    return df[['product_id', 'product_name']]
```

</details>

<br>

## Approach 1: Group By and Use Having Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT p.product_id, p.product_name
FROM Sales s
LEFT JOIN Product p ON p.product_id = s.product_id
GROUP BY p.product_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT p.product_id, p.product_name
FROM Sales s
LEFT JOIN Product p ON p.product_id = s.product_id
GROUP BY p.product_id
HAVING MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31';
```

</details>
