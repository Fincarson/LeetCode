# 1083. Sales Analysis II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sales-analysis-ii/)  
`Database`

**Problem Link:** [LeetCode 1083 - Sales Analysis II](https://leetcode.com/problems/sales-analysis-ii/)

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
This table might have repeated rows.
product_id is a foreign key (reference column) to the Product table.
buyer_id is never NULL.
sale_date is never NULL.
Each row of this table contains some information about one sale.
```

Write a solution to report the buyers who have bought S8 but not iPhone. Note that S8 and iPhone are products presented in the Product table.

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
| 2         | 1          | 3        | 2019-06-02 | 1        | 800   |
| 3         | 3          | 3        | 2019-05-13 | 2        | 2800  |
+-----------+------------+----------+------------+----------+-------+
Output:
+-------------+
| buyer_id    |
+-------------+
| 1           |
+-------------+
Explanation: The buyer with id 1 bought an S8 but did not buy an iPhone. The buyer with id 3 bought both.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sales Analysis I](https://leetcode.com/problems/sales-analysis-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sales Analysis III](https://leetcode.com/problems/sales-analysis-iii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1083. Sales Analysis II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using 'isin()' (IN) and '~' (NOT IN) | Pandas |
| Using Lambda to Score Each Buyer | Pandas |
| NOT IN/EXIST in the subquery | SQL |
| LEFT JOIN and NULL Ids From the Right Table | SQL |
| Using CASE WHEN or GROUP_CONCAT to Score Each Buyer | SQL |

## Approach 1: Using 'isin()' (IN) and '~' (NOT IN)

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:

sales_and_product = sales.merge(product, on = 'product_id')

iphone_sales = sales_and_product[sales_and_product['product_name'] == 'iPhone']

s8_sales = sales_and_product[sales_and_product['product_name'] == 'S8']

df = s8_sales[~s8_sales.buyer_id.isin(iphone_sales['buyer_id'])]

return df[['buyer_id']].drop_duplicates()
```

</details>

<br>

## Approach 2: Using Lambda to Score Each Buyer

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
Ã¢â‚¬â€¹
def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:

product_and_sales = product.merge(sales, on = 'product_id')

buyer_score = product_and_sales.groupby('buyer_id').agg(s8_sum = ('product_name', lambda x:(x == 'S8').sum()), iphone_sum = ('product_name', lambda x:(x == 'iPhone').sum())).reset_index()

df = buyer_score[(buyer_score['s8_sum'] > 0)&(buyer_score['iphone_sum'] == 0)]

return df[['buyer_id']]
```

</details>

<br>

## Approach 1: NOT IN/EXIST in the subquery

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'iPhone'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'S8'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'S8'
AND s.buyer_id NOT IN
(
    SELECT DISTINCT buyer_id
    FROM Sales s
    JOIN Product p
    ON s.product_id = p.product_id
    AND p.product_name = 'iPhone'
    )
```

</details>

<br>

## Approach 2: LEFT JOIN and NULL Ids From the Right Table

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'iPhone'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'S8'
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'S8'
LEFT JOIN
    (
    SELECT DISTINCT buyer_id
    FROM Sales s
    JOIN Product p
    ON s.product_id = p.product_id
    AND p.product_name = 'iPhone'
    )a
ON s.buyer_id = a.buyer_id
WHERE a.buyer_id IS NULL
```

</details>

<br>

## Approach 3: Using CASE WHEN or GROUP_CONCAT to Score Each Buyer

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
GROUP BY s.buyer_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
GROUP BY s.buyer_id
HAVING SUM(CASE WHEN p.product_name = 'iPhone' THEN 1 ELSE 0 END) = 0
AND SUM(CASE WHEN p.product_name = 'S8' THEN 1 ELSE 0 END) > 0
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
GROUP BY s.buyer_id
HAVING GROUP_CONCAT(p.product_name) LIKE '%S8%'
AND GROUP_CONCAT(p.product_name) NOT LIKE '%iPhone%'
```

</details>
