# 1907. Count Salary Categories

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-salary-categories/)  
`Database`

**Problem Link:** [LeetCode 1907 - Count Salary Categories](https://leetcode.com/problems/count-salary-categories/)

## Problem

Table: Accounts

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key (column with unique values) for this table.
Each row contains information about the monthly income for one bank account.
```

Write a solution to calculate the number of bank accounts for each salary category. The salary categories are:

- "Low Salary": All the salaries strictly less than $20000.
- "Average Salary": All the salaries in the inclusive range [$20000, $50000].
- "High Salary": All the salaries strictly greater than $50000.

The result table must contain all three categories. If there are no accounts in a category, return 0.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
Output:
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
Explanation:
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Create a Session Bar Chart](https://leetcode.com/problems/create-a-session-bar-chart/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1907. Count Salary Categories

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Filter rows | Pandas |

## Approach: Filter rows

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    low_count = (accounts['income'] < 20000).sum()
    average_count = ((accounts['income'] >= 20000) & (accounts['income'] <= 50000)).sum()
    high_count = (accounts['income'] > 50000).sum()

    ans = pd.DataFrame({
        'category': ['Low Salary', 'Average Salary', 'High Salary'],
        'accounts_count': [low_count, average_count, high_count]
    })

    return ans
```

</details>
