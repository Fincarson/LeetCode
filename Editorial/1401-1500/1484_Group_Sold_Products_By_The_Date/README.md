# 1484. Group Sold Products By The Date

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/group-sold-products-by-the-date/)  
`Database`

**Problem Link:** [LeetCode 1484 - Group Sold Products By The Date](https://leetcode.com/problems/group-sold-products-by-the-date/)

## Problem

Table Activities:

```text
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key (column with unique values) for this table. It may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.
```

Write a solution to find for each date the number of different products sold and their names.

The sold products names for each date should be sorted lexicographically.

Return the result table ordered by sell_date.

The result format is in the following example.

### Example 1

```text
Input:
Activities table:
+------------+------------+
| sell_date  | product     |
+------------+------------+
| 2020-05-30 | Headphone  |
| 2020-06-01 | Pencil     |
| 2020-06-02 | Mask       |
| 2020-05-30 | Basketball |
| 2020-06-01 | Bible      |
| 2020-06-02 | Mask       |
| 2020-05-30 | T-Shirt    |
+------------+------------+
Output:
+------------+----------+------------------------------+
| sell_date  | num_sold | products                     |
+------------+----------+------------------------------+
| 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
| 2020-06-01 | 2        | Bible,Pencil                 |
| 2020-06-02 | 1        | Mask                         |
+------------+----------+------------------------------+
Explanation:
For 2020-05-30, Sold items were (Headphone, Basketball, T-shirt), we sort them lexicographically and separate them by a comma.
For 2020-06-01, Sold items were (Pencil, Bible), we sort them lexicographically and separate them by a comma.
For 2020-06-02, the Sold item is (Mask), we just return it.
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Finding the Topic of Each Post](https://leetcode.com/problems/finding-the-topic-of-each-post/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1484. Group Sold Products By The Date

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Grouping and aggregation of strings | Pandas |
| Approach: Grouping and aggregation of strings | SQL |

## Approach: Grouping and aggregation of strings

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    groups = activities.groupby('sell_date')
    
    stats = groups.agg(
        num_sold=('product', 'nunique'), 
        products=('product', lambda x: ','.join(sorted(set(x))))
        ).reset_index()

    stats.sort_values('sell_date', inplace=True)

    return stats
```

</details>

<br>

## Approach: Grouping and aggregation of strings

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
    sell_date,
    COUNT(DISTINCT(product)) AS num_sold, 
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM 
    Activities
GROUP BY 
    sell_date
ORDER BY 
    sell_date ASC
```

</details>
