# 1398. Customers Who Bought Products A and B but Not C

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/customers-who-bought-products-a-and-b-but-not-c/)  
`Database`

**Problem Link:** [LeetCode 1398 - Customers Who Bought Products A and B but Not C](https://leetcode.com/problems/customers-who-bought-products-a-and-b-but-not-c/)

## Problem

Table: Customers

```text
+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| customer_id         | int     |
| customer_name       | varchar |
+---------------------+---------+
customer_id is the column with unique values for this table.
customer_name is the name of the customer.
```

Table: Orders

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| product_name  | varchar |
+---------------+---------+
order_id is the column with unique values for this table.
customer_id is the id of the customer who bought the product "product_name".
```

Write a solution to report the customer_id and customer_name of customers who bought products "A", "B" but did not buy the product "C" since we want to recommend them to purchase this product.

Return the result table ordered by customer_id.

The result format is in the following example.

### Example 1

```text
Input:
Customers table:
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 1           | Daniel        |
| 2           | Diana         |
| 3           | Elizabeth     |
| 4           | Jhon          |
+-------------+---------------+
Orders table:
+------------+--------------+---------------+
| order_id   | customer_id  | product_name  |
+------------+--------------+---------------+
| 10         |     1        |     A         |
| 20         |     1        |     B         |
| 30         |     1        |     D         |
| 40         |     1        |     C         |
| 50         |     2        |     A         |
| 60         |     3        |     A         |
| 70         |     3        |     B         |
| 80         |     3        |     D         |
| 90         |     4        |     C         |
+------------+--------------+---------------+
Output:
+-------------+---------------+
| customer_id | customer_name |
+-------------+---------------+
| 3           | Elizabeth     |
+-------------+---------------+
Explanation: Only the customer_id with id 3 bought the product A and B but not the product C.
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

# Editorial - 1398. Customers Who Bought Products A and B but Not C

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Use Three `isin` Operations | Python3, Pandas |
| Filter with custom function and `isin` | Python3, Pandas |
| Group By then Use Having Clause | SQL |

## Approach 1: Use Three `isin` Operations

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
buyA = orders.loc[orders['product_name'] == 'A', 'customer_id']
buyB = orders.loc[orders['product_name'] == 'B', 'customer_id']
buyC = orders.loc[orders['product_name'] == 'C', 'customer_id']
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
condA = customers['customer_id'].isin(buyA)
condB = customers['customer_id'].isin(buyB)
condC = ~customers['customer_id'].isin(buyC)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
df = customers[condA & condB & condC]
return df.sort_values(by = 'customer_id')
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    buyA = orders.loc[orders['product_name'] == 'A', 'customer_id']
    buyB = orders.loc[orders['product_name'] == 'B', 'customer_id']
    buyC = orders.loc[orders['product_name'] == 'C', 'customer_id']

    condA = customers['customer_id'].isin(buyA)
    condB = customers['customer_id'].isin(buyB)
    condC = ~customers['customer_id'].isin(buyC)
    df = customers[condA & condB & condC]
    return df.sort_values(by = 'customer_id')
```

</details>

<br>

## Approach 2: Filter with custom function and `isin`

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
def valid(subdf):
    purchased = set(subdf['product_name'])
    return  'A' in purchased and \
            'B' in purchased and \
            'C' not in purchased

df = orders.groupby('customer_id').filter(valid)
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
cond = customers['customer_id'].isin(df['customer_id'])
return customers[cond].sort_values(by = 'customer_id')
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    def valid(subdf):
        purchased = set(subdf['product_name'])
        return  'A' in purchased and \
                'B' in purchased and \
                'C' not in purchased

    df = orders.groupby('customer_id').filter(valid)

    cond = customers['customer_id'].isin(df['customer_id'])
    return customers[cond].sort_values(by = 'customer_id')
```

</details>

<br>

## Approach 1: Group By then Use Having Clause

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT c.customer_id, customer_name
FROM customers c
LEFT JOIN orders o ON c.customer_id = o.customer_id
GROUP BY c.customer_id
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT c.customer_id, customer_name
FROM customers c
LEFT JOIN orders o ON c.customer_id = o.customer_id
GROUP BY c.customer_id
HAVING SUM(product_name='A') > 0
    AND SUM(product_name='B') > 0
    AND SUM(product_name='C') = 0
ORDER BY c.customer_id;
```

</details>
