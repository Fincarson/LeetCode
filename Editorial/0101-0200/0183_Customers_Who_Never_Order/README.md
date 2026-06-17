# 183. Customers Who Never Order

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/customers-who-never-order/)  
`Database`

**Problem Link:** [LeetCode 183 - Customers Who Never Order](https://leetcode.com/problems/customers-who-never-order/)

## Problem

Table: Customers

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID and name of a customer.
```

Table: Orders

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
customerId is a foreign key (reference columns) of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
```

Write a solution to find all customers who never order anything.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Output:
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+
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

# Editorial - 183. Customers Who Never Order

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Filtering Data with Exclusion Criteria | Python3, Pandas |
| Left Join on `customers` | Pandas |
| Filtering Data with Exclusion Criteria | SQL |
| Left Join on `customers` | SQL |

## Approach 1: Filtering Data with Exclusion Criteria

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
# Select the rows which `id` is not present in orders['customerId'].
df = customers[~customers['id'].isin(orders['customerId'])]
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
# Build a dataframe that only contains the column `name` 
# and rename the column `name` as `Customers`.
df = df[['name']].rename(columns={'name': 'Customers'})
```

</details>

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the rows which `id` is not present in orders['customerId'].
    df = customers[~customers['id'].isin(orders['customerId'])]

    # Build a dataframe that only contains the column `name` 
    # and rename the column `name` as `Customers`.
    df = df[['name']].rename(columns={'name': 'Customers'})
    return df
```

</details>

<br>

## Approach 2: Left Join on `customers`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def customers_who_never_order(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = customers.merge(orders, left_on='id', right_on='customerId', how='left')
    df = df[df['customerId'].isna()]
    df = df[['name']].rename(columns={'name': 'Customers'})
    return df
```

</details>

<br>

## Approach 1: Filtering Data with Exclusion Criteria

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
select *
from customers
where customers.id not in
(
    select customerid from orders
);
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);
```

</details>

<br>

## Approach 2: Left Join on `customers`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT * 
FROM Customers c
LEFT JOIN Orders o
ON c.Id = o.CustomerId
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT * 
FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT name AS 'Customers'
FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL
```

</details>
