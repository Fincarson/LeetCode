# 1571. Warehouse Manager

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/warehouse-manager/)  
`Database`

**Problem Link:** [LeetCode 1571 - Warehouse Manager](https://leetcode.com/problems/warehouse-manager/)

## Problem

Table: Warehouse

```text
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| name         | varchar |
| product_id   | int     |
| units        | int     |
+--------------+---------+
(name, product_id) is the primary key (combination of columns with unique values) for this table.
Each row of this table contains the information of the products in each warehouse.
```

Table: Products

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| Width         | int     |
| Length        | int     |
| Height        | int     |
+---------------+---------+
product_id is the primary key (column with unique values) for this table.
Each row of this table contains information about the product dimensions (Width, Lenght, and Height) in feets of each product.
```

Write a solution to report the number of cubic feet of volume the inventory occupies in each warehouse.

Return the result table in any order.

The query result format is in the following example.

### Example 1

```text
Input:
Warehouse table:
+------------+--------------+-------------+
| name       | product_id   | units       |
+------------+--------------+-------------+
| LCHouse1   | 1            | 1           |
| LCHouse1   | 2            | 10          |
| LCHouse1   | 3            | 5           |
| LCHouse2   | 1            | 2           |
| LCHouse2   | 2            | 2           |
| LCHouse3   | 4            | 1           |
+------------+--------------+-------------+
Products table:
+------------+--------------+------------+----------+-----------+
| product_id | product_name | Width      | Length   | Height    |
+------------+--------------+------------+----------+-----------+
| 1          | LC-TV        | 5          | 50       | 40        |
| 2          | LC-KeyChain  | 5          | 5        | 5         |
| 3          | LC-Phone     | 2          | 10       | 10        |
| 4          | LC-T-Shirt   | 4          | 10       | 20        |
+------------+--------------+------------+----------+-----------+
Output:
+----------------+------------+
| warehouse_name | volume     |
+----------------+------------+
| LCHouse1       | 12250      |
| LCHouse2       | 20250      |
| LCHouse3       | 800        |
+----------------+------------+
Explanation:
Volume of product_id = 1 (LC-TV), 5x50x40 = 10000
Volume of product_id = 2 (LC-KeyChain), 5x5x5 = 125
Volume of product_id = 3 (LC-Phone), 2x10x10 = 200
Volume of product_id = 4 (LC-T-Shirt), 4x10x20 = 800
LCHouse1: 1 unit of LC-TV + 10 units of LC-KeyChain + 5 units of LC-Phone.
          Total volume: 1*10000 + 10*125  + 5*200 = 12250 cubic feet
LCHouse2: 2 units of LC-TV + 2 units of LC-KeyChain.
          Total volume: 2*10000 + 2*125 = 20250 cubic feet
LCHouse3: 1 unit of LC-T-Shirt.
          Total volume: 1*800 = 800 cubic feet.
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

# Editorial - 1571. Warehouse Manager

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Left Join and Aggregation | Pandas |
| Approach: Left Join and Aggregation | SQL |

## Approach: Left Join and Aggregation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
def warehouse_manager(warehouse: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:
    products['cubic_ft'] = products['Width'] * products['Height'] * products['Length']
    warehouse = warehouse.merge(
        products[['product_id', 'cubic_ft']], 
        how='left', 
        on='product_id'
        )
    warehouse['volume'] = warehouse['units'] * warehouse['cubic_ft']
    df = warehouse.groupby('name')['volume'].sum().reset_index(name="volume")

    # Rename 'name' to 'warehouse_name'
    df = df.rename(columns={'name':'warehouse_name'})
    
    return df
```

</details>

<br>

## Approach: Left Join and Aggregation

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    p.product_id, 
    p.width * p.length * p.height AS volume
FROM 
    Products p;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    *
FROM 
    Warehouse w
LEFT JOIN (
    SELECT 
        p.product_id, 
        p.width * p.length * p.height AS cubic_ft
    FROM 
        Products p
) AS sub
ON w.product_id = sub.product_id;
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    w.name AS warehouse_name, 
    sum(w.units * sub.cubic_ft) AS volume
FROM 
    Warehouse w
LEFT JOIN (
    SELECT 
        p.product_id, 
        p.width * p.length * p.height AS cubic_ft
    FROM Products p
) AS sub
ON w.product_id = sub.product_id
GROUP BY warehouse_name;
```

</details>
