# 1757. Recyclable and Low Fat Products

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/recyclable-and-low-fat-products/)  
`Database`

**Problem Link:** [LeetCode 1757 - Recyclable and Low Fat Products](https://leetcode.com/problems/recyclable-and-low-fat-products/)

## Problem

Table: Products

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product_id is the primary key (column with unique values) for this table.
low_fats is an ENUM (category) of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM (category) of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
```

Write a solution to find the ids of products that are both low fat and recyclable.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
Output:
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation: Only products 1 and 3 are both low fat and recyclable.
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

# Editorial - 1757. Recyclable and Low Fat Products

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Selecting rows based on conditions | Pandas |
| Approach: Selecting rows based on conditions | SQL |

## Approach: Selecting rows based on conditions

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y')]

    df = df[['product_id']]
    
    return df
```

</details>

<br>

## Approach: Selecting rows based on conditions

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    product_id
FROM
    Products
WHERE
    low_fats = 'Y' AND recyclable = 'Y'
```

</details>
