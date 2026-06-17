# 2701. Consecutive Transactions with Increasing Amounts

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/consecutive-transactions-with-increasing-amounts/)  
`Database`

**Problem Link:** [LeetCode 2701 - Consecutive Transactions with Increasing Amounts](https://leetcode.com/problems/consecutive-transactions-with-increasing-amounts/)

## Problem

Table: Transactions

```text
+------------------+------+
| Column Name      | Type |
+------------------+------+
| transaction_id   | int  |
| customer_id      | int  |
| transaction_date | date |
| amount           | int  |
+------------------+------+
transaction_id is the primary key of this table.
Each row contains information about transactions that includes unique (customer_id, transaction_date) along with the corresponding customer_id and amount.
```

Write an SQL query to find the customers who have made consecutive transactions with increasing amount for at least three consecutive days. Include the customer_id, start date of the consecutive transactions period and the end date of the consecutive transactions period. There can be multiple consecutive transactions by a customer.

Return the result table ordered by customer_id, consecutive_start, consecutive_end in ascending order.

The query result format is in the following example.

### Example 1

```text
Input:
Transactions table:
+----------------+-------------+------------------+--------+
| transaction_id | customer_id | transaction_date | amount |
+----------------+-------------+------------------+--------+
| 1              | 101         | 2023-05-01       | 100    |
| 2              | 101         | 2023-05-02       | 150    |
| 3              | 101         | 2023-05-03       | 200    |
| 4              | 102         | 2023-05-01       | 50     |
| 5              | 102         | 2023-05-03       | 100    |
| 6              | 102         | 2023-05-04       | 200    |
| 7              | 105         | 2023-05-01       | 100    |
| 8              | 105         | 2023-05-02       | 150    |
| 9              | 105         | 2023-05-03       | 200    |
| 10             | 105         | 2023-05-04       | 300    |
| 11             | 105         | 2023-05-12       | 250    |
| 12             | 105         | 2023-05-13       | 260    |
| 13             | 105         | 2023-05-14       | 270    |
+----------------+-------------+------------------+--------+
Output:
+-------------+-------------------+-----------------+
| customer_id | consecutive_start | consecutive_end |
+-------------+-------------------+-----------------+
| 101         |  2023-05-01       | 2023-05-03      |
| 105         |  2023-05-01       | 2023-05-04      |
| 105         |  2023-05-12       | 2023-05-14      |
+-------------+-------------------+-----------------+
Explanation:
- customer_id 101 has made consecutive transactions with increasing amounts from May 1st, 2023, to May 3rd, 2023
- customer_id 102 does not have any consecutive transactions for at least 3 days.
- customer_id 105 has two sets of consecutive transactions: from May 1st, 2023, to May 4th, 2023, and from May 12th, 2023, to May 14th, 2023.
customer_id is sorted in ascending order.
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

# Editorial - 2701. Consecutive Transactions with Increasing Amounts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Consecutive Increase Grouping Method | Pandas |

## Approach: Consecutive Increase Grouping Method

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def consecutive_increasing_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    # Sort transactions by customer_id and transaction_date, then reset index
    transactions_sorted = (
        transactions.sort_values(["customer_id", "transaction_date"])
        .reset_index()
    )

    # Create a group identifier for consecutive days ('day_group')
    # Subtracting the transaction date from a fixed date to get the number of days since that date
    # and then subtracting the row index to form groups of consecutive days
    transactions_sorted["day_group"] = (
        transactions_sorted["transaction_date"] - pd.to_datetime("2023-01-01")
    ).dt.days - transactions_sorted.index

    # Create a group identifier for increasing transaction amounts ('amount_group')
    # Formed by cumulatively summing where the transaction amount is not greater than the previous amount
    transactions_sorted["amount_group"] = (
        (transactions_sorted.amount <= transactions_sorted.amount.shift(1))
        .cumsum()
        .fillna(0)
    )

    # Group by customer_id, day_group, and amount_group and perform aggregations
    grouped_transactions = (
        transactions_sorted.groupby(["customer_id", "day_group", "amount_group"])
        .agg(
            count=("index", "count"),
            consecutive_start=("transaction_date", "min"),
            consecutive_end=("transaction_date", "max"),
        )
        .reset_index()
    )

    # Filter groups with at least three consecutive increasing transactions and select relevant columns
    result = grouped_transactions.query("count > 2")[
        ["customer_id", "consecutive_start", "consecutive_end"]
    ]

    return result
```

</details>
