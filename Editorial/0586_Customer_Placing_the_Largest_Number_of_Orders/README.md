# 586. Customer Placing the Largest Number of Orders

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/)  
`Database`

**Problem Link:** [LeetCode 586 - Customer Placing the Largest Number of Orders](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/)

## Problem

Table: Orders

```text
+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key (column with unique values) for this table.
This table contains information about the order ID and the customer ID.
```

Write a solution to find the customer_number for the customer who has placed the largest number of orders.

The test cases are generated so that exactly one customer will have placed more orders than any other customer.

The result format is in the following example.

### Example 1

```text
Input:
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output:
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
Explanation:
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order.
So the result is customer_number 3.
```

Follow up: What if more than one customer has the largest number of orders, can you find all the customer_number in this case?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 586. Customer Placing the Largest Number of Orders

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Group By | Pandas |
| Approach: Group By | SQL |

## Approach: Group By

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    # If orders is empty, return an empty DataFrame.
    if orders.empty:
        return pd.DataFrame({'customer_number': []})

    df = orders.groupby('customer_number').size().reset_index(name='count')
    df.sort_values(by='count', ascending = False, inplace=True)
    return df[['customer_number']][0:1]
```

</details>

<br>

## Approach: Group By

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    customer_number, COUNT(*)
FROM
    orders
GROUP BY customer_number
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1
;
```

</details>
