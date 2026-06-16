# 1164. Product Price at a Given Date

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/product-price-at-a-given-date/)  
`Database`

**Problem Link:** [LeetCode 1164 - Product Price at a Given Date](https://leetcode.com/problems/product-price-at-a-given-date/)

## Problem

Table: Products

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key (combination of columns with unique values) of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
```

Initially, all products have price 10.

Write a solution to find the prices of all products on the date 2019-08-16.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output:
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+
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

# Editorial - 1164. Product Price at a Given Date

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide cases by using `UNION ALL` | MySQL |
| Divide cases by using `LEFT JOIN` | MySQL |
| Use the window function | MySQL |

## Approach 1: Divide cases by using `UNION ALL`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  product_id,
  10 AS price
FROM
  Products
GROUP BY
  product_id
HAVING
  MIN(change_date) > '2019-08-16'
UNION ALL
SELECT
  product_id,
  new_price AS price
FROM
  Products
WHERE
  (product_id, change_date) IN (
    SELECT
      product_id,
      MAX(change_date)
    FROM
      Products
    WHERE
      change_date <= '2019-08-16'
    GROUP BY
      product_id
  )
```

</details>

<br>

## Approach 2: Divide cases by using `LEFT JOIN`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  UniqueProductId.product_id,
  IFNULL (LastChangedPrice.new_price, 10) AS price
FROM
  (
    SELECT DISTINCT
      product_id
    FROM
      Products
  ) AS UniqueProductIds
  LEFT JOIN (
    SELECT
      Products.product_id,
      new_price
    FROM
      Products
      JOIN (
        SELECT
          product_id,
          MAX(change_date) AS change_date
        FROM
          Products
        WHERE
          change_date <= "2019-08-16"
        GROUP BY
          product_id
      ) AS LastChangedDate USING (product_id, change_date)
    GROUP BY
      product_id
  ) AS LastChangedPrice USING (product_id)
```

</details>

<br>

## Approach 3: Use the window function

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  product_id,
  IFNULL (price, 10) AS price
FROM
  (
    SELECT DISTINCT
      product_id
    FROM
      Products
  ) AS UniqueProducts
  LEFT JOIN (
    SELECT DISTINCT
      product_id,
      FIRST_VALUE (new_price) OVER (
        PARTITION BY
          product_id
        ORDER BY
          change_date DESC
      ) AS price
    FROM
      Products
    WHERE
      change_date <= '2019-08-16'
  ) AS LastChangedPrice USING (product_id);
```

</details>
