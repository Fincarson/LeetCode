# 1173. Immediate Food Delivery I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/immediate-food-delivery-i/)  
`Database`

**Problem Link:** [LeetCode 1173 - Immediate Food Delivery I](https://leetcode.com/problems/immediate-food-delivery-i/)

## Problem

Table: Delivery

```text
+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id is the primary key (column with unique values) of this table.
The table holds information about food delivery to customers that make orders at some date and specify a preferred delivery date (on the same order date or after it).
```

If the customer's preferred delivery date is the same as the order date, then the order is called immediate; otherwise, it is called scheduled.

Write a solution to find the percentage of immediate orders in the table, rounded to 2 decimal places.

The result format is in the following example.

### Example 1

```text
Input:
Delivery table:
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 5           | 2019-08-02 | 2019-08-02                  |
| 3           | 1           | 2019-08-11 | 2019-08-11                  |
| 4           | 3           | 2019-08-24 | 2019-08-26                  |
| 5           | 4           | 2019-08-21 | 2019-08-22                  |
| 6           | 2           | 2019-08-11 | 2019-08-13                  |
+-------------+-------------+------------+-----------------------------+
Output:
+----------------------+
| immediate_percentage |
+----------------------+
| 33.33                |
+----------------------+
Explanation: The orders with delivery id 2 and 3 are immediate while the others are scheduled.
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

# Editorial - 1173. Immediate Food Delivery I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Selecting rows based on conditions | Pandas |

## Approach: Selecting rows based on conditions

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    is_valid = delivery['order_date'] == delivery['customer_pref_delivery_date']
    
    # Count the number of valid (immediate) orders and the number of all orders.
    valid_count = is_valid.sum()
    total_count = len(delivery)

    # Round the percentage to 2 decimal places.
    percentage = round(100 * valid_count / total_count, 2)

    df = pd.DataFrame({'immediate_percentage': [percentage]})
    return df
```

</details>
