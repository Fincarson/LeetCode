# 1777. Product's Price for Each Store

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/products-price-for-each-store/)  
`Database`

**Problem Link:** [LeetCode 1777 - Product's Price for Each Store](https://leetcode.com/problems/products-price-for-each-store/)

## Problem

Table: Products

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store       | enum    |
| price       | int     |
+-------------+---------+
In SQL, (product_id, store) is the primary key for this table.
store is a category of type ('store1', 'store2', 'store3') where each represents the store this product is available at.
price is the price of the product at this store.
```

Find the price of each product in each store.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Products table:
+-------------+--------+-------+
| product_id  | store  | price |
+-------------+--------+-------+
| 0           | store1 | 95    |
| 0           | store3 | 105   |
| 0           | store2 | 100   |
| 1           | store1 | 70    |
| 1           | store3 | 80    |
+-------------+--------+-------+
Output:
+-------------+--------+--------+--------+
| product_id  | store1 | store2 | store3 |
+-------------+--------+--------+--------+
| 0           | 95     | 100    | 105    |
| 1           | 70     | null   | 80     |
+-------------+--------+--------+--------+
Explanation:
Product 0 price's are 95 for store1, 100 for store2 and, 105 for store3.
Product 1 price's are 70 for store1, 80 for store3 and, it's not sold in store2.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rearrange Products Table](https://leetcode.com/problems/rearrange-products-table/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Dynamic Pivoting of a Table](https://leetcode.com/problems/dynamic-pivoting-of-a-table/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1777. Product's Price for Each Store

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using `.pivot()` | Pandas |

## Approach 1: Using `.pivot()`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def products_price(products: pd.DataFrame) -> pd.DataFrame:
    # Approach: Utilize .pivot() to get unique stores

    # Utilizing product_id as the index, we will destructure the values 
    # as columns and have the values be the price
    df = products.pivot(index='product_id', columns='store', values='price').reset_index()

    return df
```

</details>
