# 1607. Sellers With No Sales

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sellers-with-no-sales/)  
`Database`

**Problem Link:** [LeetCode 1607 - Sellers With No Sales](https://leetcode.com/problems/sellers-with-no-sales/)

## Problem

Table: Customer

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id is the column with unique values for this table.
Each row of this table contains the information of each customer in the WebStore.
```

Table: Orders

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| sale_date     | date    |
| order_cost    | int     |
| customer_id   | int     |
| seller_id     | int     |
+---------------+---------+
order_id is the column with unique values for this table.
Each row of this table contains all orders made in the webstore.
sale_date is the date when the transaction was made between the customer (customer_id) and the seller (seller_id).
```

Table: Seller

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| seller_id     | int     |
| seller_name   | varchar |
+---------------+---------+
seller_id is the column with unique values for this table.
Each row of this table contains the information of each seller.
```

Write a solution to report the names of all sellers who did not make any sales in 2020.

Return the result table ordered by seller_name in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Customer table:
+--------------+---------------+
| customer_id  | customer_name |
+--------------+---------------+
| 101          | Alice         |
| 102          | Bob           |
| 103          | Charlie       |
+--------------+---------------+
Orders table:
+-------------+------------+--------------+-------------+-------------+
| order_id    | sale_date  | order_cost   | customer_id | seller_id   |
+-------------+------------+--------------+-------------+-------------+
| 1           | 2020-03-01 | 1500         | 101         | 1           |
| 2           | 2020-05-25 | 2400         | 102         | 2           |
| 3           | 2019-05-25 | 800          | 101         | 3           |
| 4           | 2020-09-13 | 1000         | 103         | 2           |
| 5           | 2019-02-11 | 700          | 101         | 2           |
+-------------+------------+--------------+-------------+-------------+
Seller table:
+-------------+-------------+
| seller_id   | seller_name |
+-------------+-------------+
| 1           | Daniel      |
| 2           | Elizabeth   |
| 3           | Frank       |
+-------------+-------------+
Output:
+-------------+
| seller_name |
+-------------+
| Frank       |
+-------------+
Explanation:
Daniel made 1 sale in March 2020.
Elizabeth made 2 sales in 2020 and 1 sale in 2019.
Frank made 1 sale in 2019 but no sales in 2020.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Customer Who Visited but Did Not Make Any Transactions](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1607. Sellers With No Sales

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Not in/Exists in the Subquery | MySQL |
| Left Join then Exclude the Matching Record. | MySQL |
| Flag Records by `HAVING` or `CASE WHEN` | MySQL, SQL |

## Approach 1: Not in/Exists in the Subquery

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    DISTINCT seller_id
FROM 
    Orders
WHERE 
    YEAR(sale_date) = 2020
```

</details>

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    seller_name
FROM 
    Seller s
WHERE 
    s.seller_id NOT IN (SELECT 
                            DISTINCT seller_id
                        FROM 
                            Orders
                        WHERE 
                            YEAR(sale_date) = 2020)
ORDER BY 1 ASC
```

</details>

<br>

## Approach 2: Left Join then Exclude the Matching Record.

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    seller_name
FROM 
    Seller a
LEFT JOIN 
    (SELECT 
        DISTINCT seller_id
    FROM 
        Orders
    WHERE 
        YEAR(sale_date) = 2020) b
ON 
    a.seller_id = b.seller_id
WHERE 
    b.seller_id IS NULL 
ORDER BY 1 ASC
```

</details>

<br>

## Approach 3: Flag Records by `HAVING` or `CASE WHEN`

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT 
    seller_name
FROM 
    Seller s
LEFT JOIN 
    Orders o
ON 
    s.seller_id = o.seller_id
GROUP BY 
    s.seller_id
HAVING 
    SUM(IFNULL(YEAR(sale_date)='2020',0)) = 0
ORDER BY 1 ASC
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    seller_name, 
    SUM(CASE WHEN YEAR(sale_date) ='2020' THEN 1 ELSE 0 END) AS flag
FROM 
    Seller s
LEFT JOIN 
    Orders o
ON 
    s.seller_id = o.seller_id
GROUP BY    
    s.seller_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    seller_name
FROM (
    SELECT 
        seller_name, 
        SUM(CASE WHEN YEAR(sale_date) ='2020' THEN 1 ELSE 0 END) AS flag
    FROM 
        Seller s
    LEFT JOIN 
        Orders o
    ON 
        s.seller_id = o.seller_id
    GROUP BY 
        s.seller_id
)t0
WHERE 
    flag=0
ORDER BY 1 ASC
```

</details>
