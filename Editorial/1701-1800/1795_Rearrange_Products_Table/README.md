# 1795. Rearrange Products Table

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rearrange-products-table/)  
`Database`

**Problem Link:** [LeetCode 1795 - Rearrange Products Table](https://leetcode.com/problems/rearrange-products-table/)

## Problem

Table: Products

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store1      | int     |
| store2      | int     |
| store3      | int     |
+-------------+---------+
product_id is the primary key (column with unique values) for this table.
Each row in this table indicates the product's price in 3 different stores: store1, store2, and store3.
If the product is not available in a store, the price will be null in that store's column.
```

Write a solution to rearrange the Products table so that each row has (product_id, store, price). If a product is not available in a store, do not include a row with that product_id and store combination in the result table.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Products table:
+------------+--------+--------+--------+
| product_id | store1 | store2 | store3 |
+------------+--------+--------+--------+
| 0          | 95     | 100    | 105    |
| 1          | 70     | null   | 80     |
+------------+--------+--------+--------+
Output:
+------------+--------+-------+
| product_id | store  | price |
+------------+--------+-------+
| 0          | store1 | 95    |
| 0          | store2 | 100   |
| 0          | store3 | 105   |
| 1          | store1 | 70    |
| 1          | store3 | 80    |
+------------+--------+-------+
Explanation:
Product 0 is available in all three stores with prices 95, 100, and 105 respectively.
Product 1 is available in store1 with price 70 and store3 with price 80. The product is not available in store2.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product's Price for Each Store](https://leetcode.com/problems/products-price-for-each-store/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Dynamic Unpivoting of a Table](https://leetcode.com/problems/dynamic-unpivoting-of-a-table/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1795. Rearrange Products Table

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Union Tables | Pandas |
| Pivot Table | Pandas |
| Approach: Union Tables | SQL |

## Approach 1: Union Tables

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame: 
    a = products.loc[products['store1'].notna(), ['product_id', 'store1']]
    a['store'] = "store1"
    a.rename(columns={'store1':'price'}, inplace=True)
    a = a[['product_id', 'store', 'price']]

    b = products.loc[products['store2'].notna(), ['product_id', 'store2']]
    b['store'] = "store2"
    b.rename(columns={'store2':'price'}, inplace=True)
    b = b[['product_id', 'store', 'price']]
    
    c = products.loc[products['store3'].notna(), ['product_id', 'store3']]
    c['store'] = "store3"
    c.rename(columns={'store3':'price'}, inplace=True)
    c = c[['product_id', 'store', 'price']]
      
    answer = pd.concat([a, b, c])
    return answer
```

</details>

<br>

## Approach 2: Pivot Table

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame: 
    df = products.melt(id_vars='product_id', var_name='store', value_name='price')
    df = df.dropna(axis=0)
    return df
```

</details>

<br>

## Approach: Union Tables

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT product_id, 'store1' AS store, store1 AS price 
FROM Products 
WHERE store1 IS NOT NULL
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT product_id, 'store1' AS store, store1 AS price 
FROM Products 
WHERE store1 IS NOT NULL

UNION 
SELECT product_id, 'store2' AS store, store2 AS price 
FROM Products 
WHERE store2 IS NOT NULL

UNION 
SELECT product_id, 'store3' AS store, store3 AS price 
FROM Products 
WHERE store3 IS NOT NULL
```

</details>
