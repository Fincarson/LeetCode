# 1843. Suspicious Bank Accounts

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/suspicious-bank-accounts/)  
`Database`

**Problem Link:** [LeetCode 1843 - Suspicious Bank Accounts](https://leetcode.com/problems/suspicious-bank-accounts/)

## Problem

Table: Accounts

```text
+----------------+------+
| Column Name    | Type |
+----------------+------+
| account_id     | int  |
| max_income     | int  |
+----------------+------+
account_id is the column with unique values for this table.
Each row contains information about the maximum monthly income for one bank account.
```

Table: Transactions

```text
+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| transaction_id | int      |
| account_id     | int      |
| type           | ENUM     |
| amount         | int      |
| day            | datetime |
+----------------+----------+
transaction_id is the column with unique values for this table.
Each row contains information about one transaction.
type is ENUM (category) type of ('Creditor','Debtor') where 'Creditor' means the user deposited money into their account and 'Debtor' means the user withdrew money from their account.
amount is the amount of money deposited/withdrawn during the transaction.
```

A bank account is suspicious if the total income exceeds the max_income for this account for two or more consecutive months. The total income of an account in some month is the sum of all its deposits in that month (i.e., transactions of the type 'Creditor').

Write a solution to report the IDs of all suspicious bank accounts.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Accounts table:
+------------+------------+
| account_id | max_income |
+------------+------------+
| 3          | 21000      |
| 4          | 10400      |
+------------+------------+
Transactions table:
+----------------+------------+----------+--------+---------------------+
| transaction_id | account_id | type     | amount | day                 |
+----------------+------------+----------+--------+---------------------+
| 2              | 3          | Creditor | 107100 | 2021-06-02 11:38:14 |
| 4              | 4          | Creditor | 10400  | 2021-06-20 12:39:18 |
| 11             | 4          | Debtor   | 58800  | 2021-07-23 12:41:55 |
| 1              | 4          | Creditor | 49300  | 2021-05-03 16:11:04 |
| 15             | 3          | Debtor   | 75500  | 2021-05-23 14:40:20 |
| 10             | 3          | Creditor | 102100 | 2021-06-15 10:37:16 |
| 14             | 4          | Creditor | 56300  | 2021-07-21 12:12:25 |
| 19             | 4          | Debtor   | 101100 | 2021-05-09 15:21:49 |
| 8              | 3          | Creditor | 64900  | 2021-07-26 15:09:56 |
| 7              | 3          | Creditor | 90900  | 2021-06-14 11:23:07 |
+----------------+------------+----------+--------+---------------------+
Output:
+------------+
| account_id |
+------------+
| 3          |
+------------+
Explanation:
For account 3:
- In 6-2021, the user had an income of 107100 + 102100 + 90900 = 300100.
- In 7-2021, the user had an income of 64900.
We can see that the income exceeded the max income of 21000 for two consecutive months, so we include 3 in the result table.

For account 4:
- In 5-2021, the user had an income of 49300.
- In 6-2021, the user had an income of 10400.
- In 7-2021, the user had an income of 56300.
We can see that the income exceeded the max income in May and July, but not in June. Since the account did not exceed the max income for two consecutive months, we do not include it in the result table.
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

# Editorial - 1843. Suspicious Bank Accounts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sequential Filtering and Aggregation | Pandas |
| Approach: CTE and `PERIOD_DIFF` | SQL |

## Approach: Sequential Filtering and Aggregation

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def suspicious_bank_accounts(
    accounts: pd.DataFrame, transactions: pd.DataFrame
) -> pd.DataFrame:
    # Assign a new column 'month' representing the transaction month in 'YYYY-MM' format
    monthly_transactions = transactions.assign(
        month=transactions["day"].dt.to_period("M")
    )

    # Filter for 'Creditor' type transactions
    creditor_transactions = monthly_transactions.query("type == 'Creditor'")

    # Calculate the previous month for each transaction
    creditor_transactions = creditor_transactions.assign(
        prev_month=(transactions["day"] - pd.DateOffset(months=1)).dt.to_period("M")
    )

    # Group by account_id, previous month, and current month, and sum the transaction amounts
    monthly_income = creditor_transactions.groupby(
        ["account_id", "prev_month", "month"], as_index=False
    )["amount"].sum()

    # Merge with the accounts dataframe to compare with max_income
    merged_data = monthly_income.merge(accounts, on="account_id")

    # Filter out rows where the monthly income exceeds the max_income
    over_max_income = merged_data.query("amount > max_income")

    # Merge data with itself to find accounts with excessive income for two consecutive months
    suspicious_accounts = over_max_income.merge(
        over_max_income,
        left_on=["account_id", "prev_month"],
        right_on=["account_id", "month"],
    )

    # Return unique account_ids of suspicious accounts
    return suspicious_accounts[["account_id"]].drop_duplicates()
```

</details>

<br>

## Approach: CTE and `PERIOD_DIFF`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
      WITH MonthlyIncome AS (
        SELECT 
          t.account_id, 
          DATE_FORMAT(t.day, '%Y%m') AS income_month, 
          SUM(t.amount) AS monthly_income,
          a.max_income
        FROM 
          Transactions t 
          LEFT JOIN Accounts a ON a.account_id = t.account_id
        WHERE 
          t.type = 'Creditor'
        GROUP BY 
          t.account_id, income_month 
        HAVING 
          SUM(t.amount) > a.max_income
      )
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
      SELECT 
        Income1.account_id 
      FROM 
        MonthlyIncome Income1, 
        MonthlyIncome Income2 
      WHERE 
        Income1.account_id = Income2.account_id
        AND PERIOD_DIFF(Income1.income_month, Income2.income_month) = 1
      GROUP BY 
        Income1.account_id 
      ORDER BY 
        Income1.account_id;
```

</details>
