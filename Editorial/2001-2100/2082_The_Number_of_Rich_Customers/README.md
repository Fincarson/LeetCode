# 2082. The Number of Rich Customers

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/the-number-of-rich-customers/)  
`Database`

**Problem Link:** [LeetCode 2082 - The Number of Rich Customers](https://leetcode.com/problems/the-number-of-rich-customers/)

## Problem

Table: Store

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| bill_id     | int  |
| customer_id | int  |
| amount      | int  |
+-------------+------+
bill_id is the primary key (column with unique values) for this table.
Each row contains information about the amount of one bill and the customer associated with it.
```

Write a solution to report the number of customers who had at least one bill with an amount strictly greater than 500.

The result format is in the following example.

### Example 1

```text
Input:
Store table:
+---------+-------------+--------+
| bill_id | customer_id | amount |
+---------+-------------+--------+
| 6       | 1           | 549    |
| 8       | 1           | 834    |
| 4       | 2           | 394    |
| 11      | 3           | 657    |
| 13      | 3           | 257    |
+---------+-------------+--------+
Output:
+------------+
| rich_count |
+------------+
| 2          |
+------------+
Explanation:
Customer 1 has two bills with amounts strictly greater than 500.
Customer 2 does not have any bills with an amount strictly greater than 500.
Customer 3 has one bill with an amount strictly greater than 500.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [The Winner University](https://leetcode.com/problems/the-winner-university/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2082. The Number of Rich Customers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Counting Unique Values | Pandas |
| Approach: Counting Unique Values | SQL |

## Approach: Counting Unique Values

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_rich_customers(store: pd.DataFrame) -> pd.DataFrame:
    rich_customers = store[store['amount'] > 500]
    
    count = rich_customers['customer_id'].nunique()

    answer = pd.DataFrame({'rich_count':[count]})

    return answer
```

</details>

<br>

## Approach: Counting Unique Values

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    COUNT(DISTINCT customer_id) AS rich_count 
FROM 
    Store 
WHERE 
    amount > 500
```

</details>
