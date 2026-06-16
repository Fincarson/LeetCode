# 1045. Customers Who Bought All Products

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/customers-who-bought-all-products/)  
`Database`

**Problem Link:** [LeetCode 1045 - Customers Who Bought All Products](https://leetcode.com/problems/customers-who-bought-all-products/)

## Problem

Table: Customer

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| customer_id | int     |
| product_key | int     |
+-------------+---------+
This table may contain duplicates rows.
customer_id is not NULL.
product_key is a foreign key (reference column) to Product table.
```

Table: Product

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_key | int     |
+-------------+---------+
product_key is the primary key (column with unique values) for this table.
```

Write a solution to report the customer ids from the Customer table that bought all the products in the Product table.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Customer table:
+-------------+-------------+
| customer_id | product_key |
+-------------+-------------+
| 1           | 5           |
| 2           | 6           |
| 3           | 5           |
| 3           | 6           |
| 1           | 6           |
+-------------+-------------+
Product table:
+-------------+
| product_key |
+-------------+
| 5           |
| 6           |
+-------------+
Output:
+-------------+
| customer_id |
+-------------+
| 1           |
| 3           |
+-------------+
Explanation:
The customers who bought all the products (5 and 6) are customers with IDs 1 and 3.
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

# Editorial - 1045. Customers Who Bought All Products

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count how many products each customer bought | MySQL |
| Use nested subquery with Cartesian Product - Alternative | MySQL |

## Approach 1: Count how many products each customer bought

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  customer_id
FROM
  Customer
GROUP BY
  customer_id
HAVING
  COUNT(DISTINCT product_key) = (
    SELECT
      COUNT(product_key)
    FROM
      Product
  );
```

</details>

<br>

## Approach 2: Use nested subquery with Cartesian Product - Alternative

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT DISTINCT
  customer_id
FROM
  Customer
WHERE
  customer_id NOT IN (
    SELECT
      customer_id
    FROM
      (
        SELECT DISTINCT
          Customer.customer_id,
          Product.product_key
        FROM
          Customer,
          Product
      ) AS AllPossibleCases
    WHERE
      (customer_id, product_key) NOT IN (
        SELECT
          customer_id,
          product_key
        FROM
          Customer
      )
  );
```

</details>
