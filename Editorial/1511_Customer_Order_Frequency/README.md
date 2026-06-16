# 1511. Customer Order Frequency

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/customer-order-frequency/)  
`Database`

**Problem Link:** [LeetCode 1511 - Customer Order Frequency](https://leetcode.com/problems/customer-order-frequency/)

## Problem

Table: Customers

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
| country       | varchar |
+---------------+---------+
customer_id is the column with unique values for this table.
This table contains information about the customers in the company.
```

Table: Product

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| description   | varchar |
| price         | int     |
+---------------+---------+
product_id is the column with unique values for this table.
This table contains information on the products in the company.
price is the product cost.
```

Table: Orders

```text
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| product_id    | int     |
| order_date    | date    |
| quantity      | int     |
+---------------+---------+
order_id is the column with unique values for this table.
This table contains information on customer orders.
customer_id is the id of the customer who bought "quantity" products with id "product_id".
Order_date is the date in format ('YYYY-MM-DD') when the order was shipped.
```

Write a solution to report the customer_id and customer_name of customers who have spent at least $100 in each month of June and July 2020.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Customers table:
+--------------+-----------+-------------+
| customer_id  | name      | country     |
+--------------+-----------+-------------+
| 1            | Winston   | USA         |
| 2            | Jonathan  | Peru        |
| 3            | Moustafa  | Egypt       |
+--------------+-----------+-------------+
Product table:
+--------------+-------------+-------------+
| product_id   | description | price       |
+--------------+-------------+-------------+
| 10           | LC Phone    | 300         |
| 20           | LC T-Shirt  | 10          |
| 30           | LC Book     | 45          |
| 40           | LC Keychain | 2           |
+--------------+-------------+-------------+
Orders table:
+--------------+-------------+-------------+-------------+-----------+
| order_id     | customer_id | product_id  | order_date  | quantity  |
+--------------+-------------+-------------+-------------+-----------+
| 1            | 1           | 10          | 2020-06-10  | 1         |
| 2            | 1           | 20          | 2020-07-01  | 1         |
| 3            | 1           | 30          | 2020-07-08  | 2         |
| 4            | 2           | 10          | 2020-06-15  | 2         |
| 5            | 2           | 40          | 2020-07-01  | 10        |
| 6            | 3           | 20          | 2020-06-24  | 2         |
| 7            | 3           | 30          | 2020-06-25  | 2         |
| 9            | 3           | 30          | 2020-05-08  | 3         |
+--------------+-------------+-------------+-------------+-----------+
Output:
+--------------+------------+
| customer_id  | name       |
+--------------+------------+
| 1            | Winston    |
+--------------+------------+
Explanation:
Winston spent $300 (300 * 1) in June and $100 ( 10 * 1 + 45 * 2) in July 2020.
Jonathan spent $600 (300 * 2) in June and $20 ( 2 * 10) in July 2020.
Moustafa spent $110 (10 * 2 + 45 * 2) in June and $0 in July 2020.
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

# Editorial - 1511. Customer Order Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group by `customer_id` and filter by spending sum | Pandas |

## Approach: Group by `customer_id` and filter by spending sum

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def customer_order_frequency(
    customers: pd.DataFrame, product: pd.DataFrame, orders: pd.DataFrame
) -> pd.DataFrame:

    # Merge and filter for year 2020
    merged_df = pd.merge(
        pd.merge(orders, customers, on="customer_id"), product, on="product_id"
    )
    merged_df["order_date"] = pd.to_datetime(merged_df["order_date"])
    merged_df = merged_df[merged_df["order_date"].dt.year == 2020]

    # Group by customer_id and calculate monthly sums
    grouped = merged_df.groupby(["customer_id", merged_df["order_date"].dt.month])
    monthly_sums = grouped.apply(lambda x: (x["quantity"] * x["price"]).sum()).unstack()

    # Filter for customers meeting criteria in both June (6) and July (7)
    valid_customers = monthly_sums[
        (monthly_sums[6] >= 100) & (monthly_sums[7] >= 100)
    ].index

    # Final DataFrame with customer details
    result = customers[customers["customer_id"].isin(valid_customers)]

    return result[["customer_id", "name"]]
```

</details>
