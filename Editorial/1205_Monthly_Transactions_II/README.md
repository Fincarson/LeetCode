# 1205. Monthly Transactions II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/monthly-transactions-ii/)  
`Database`

**Problem Link:** [LeetCode 1205 - Monthly Transactions II](https://leetcode.com/problems/monthly-transactions-ii/)

## Problem

Table: Transactions

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| id             | int     |
| country        | varchar |
| state          | enum    |
| amount         | int     |
| trans_date     | date    |
+----------------+---------+
id is the column of unique values of this table.
The table has information about incoming transactions.
The state column is an ENUM (category) of type ["approved", "declined"].
```

Table: Chargebacks

```text
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| trans_id       | int     |
| trans_date     | date    |
+----------------+---------+
Chargebacks contains basic information regarding incoming chargebacks from some transactions placed in Transactions table.
trans_id is a foreign key (reference column) to the id column of Transactions table.
Each chargeback corresponds to a transaction made previously even if they were not approved.
```

Write a solution to find for each month and country: the number of approved transactions and their total amount, the number of chargebacks, and their total amount.

Note: In your solution, given the month and country, ignore rows with all zeros.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Transactions table:
+-----+---------+----------+--------+------------+
| id  | country | state    | amount | trans_date |
+-----+---------+----------+--------+------------+
| 101 | US      | approved | 1000   | 2019-05-18 |
| 102 | US      | declined | 2000   | 2019-05-19 |
| 103 | US      | approved | 3000   | 2019-06-10 |
| 104 | US      | declined | 4000   | 2019-06-13 |
| 105 | US      | approved | 5000   | 2019-06-15 |
+-----+---------+----------+--------+------------+
Chargebacks table:
+----------+------------+
| trans_id | trans_date |
+----------+------------+
| 102      | 2019-05-29 |
| 101      | 2019-06-30 |
| 105      | 2019-09-18 |
+----------+------------+
Output:
+---------+---------+----------------+-----------------+------------------+-------------------+
| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
+---------+---------+----------------+-----------------+------------------+-------------------+
| 2019-05 | US      | 1              | 1000            | 1                | 2000              |
| 2019-06 | US      | 2              | 8000            | 1                | 1000              |
| 2019-09 | US      | 0              | 0               | 1                | 5000              |
+---------+---------+----------------+-----------------+------------------+-------------------+
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Monthly Transactions I](https://leetcode.com/problems/monthly-transactions-i/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1205. Monthly Transactions II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Outer Join | Pandas |
| Approach: Combining Two Tables Using UNION ALL | SQL |

## Approach: Outer Join

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
​
def monthly_transactions(transactions: pd.DataFrame, chargebacks: pd.DataFrame) -> pd.DataFrame:

    df = transactions.merge(chargebacks, left_on='id', right_on='trans_id', how='left')

    df['month_chargeback'] = df['trans_date_y'].dt.strftime('%Y-%m')

    df['month_transaction'] = df['trans_date_x'].dt.strftime('%Y-%m')

    df1 = df[df['state'] == 'approved'].groupby(
        ['month_transaction', 'country'], as_index=False
        ).agg(
            approved_count=('amount', 'count'),
            approved_amount=('amount', 'sum')
        ).rename(columns={'month_transaction': 'month'})

    df2 = df.groupby(
        ["month_chargeback", "country"], as_index=False
        ).agg(
            chargeback_count=('amount', 'count'), 
            chargeback_amount=('amount', 'sum')
        ).rename(columns={'month_chargeback': 'month'})
        
    df3 = df1.merge(df2, how='outer', on=['month', 'country']).fillna(0)

    return df3
```

</details>

<br>

## Approach: Combining Two Tables Using UNION ALL

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
This step returns the monthly totals of approved transactions. 

| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
| ------- | ------- | -------------- | --------------- | ---------------- | ----------------- |
| 2019-05 | US      | 1              | 1000            | 0                | 0                 |
| 2019-06 | US      | 2              | 8000            | 0                | 0    

Now we can combine the previous output using the function `UNION ALL`. We can put all previous steps in either a CTE or a subquery. From the below output, we can see that there are duplicates in months. 

| month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
| ------- | ------- | -------------- | --------------- | ---------------- | ----------------- |
| 2019-05 | US      | 0              | 0               | 1                | 2000              |
| 2019-06 | US      | 0              | 0               | 1                | 1000              |
| 2019-09 | US      | 0              | 0               | 1                | 5000              |
| 2019-05 | US      | 1              | 1000            | 0                | 0                 |
| 2019-06 | US      | 2              | 8000            | 0                | 0                 |

Therefore, the last step is to get the monthly totals again for all calculations at the month and country level in the main query. 

<!-- h4 for sections -->
#### Implementation
```

</details>
