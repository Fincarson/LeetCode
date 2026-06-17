# 2887. Fill Missing Data

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/fill-missing-data/)  

**Problem Link:** [LeetCode 2887 - Fill Missing Data](https://leetcode.com/problems/fill-missing-data/)

## Problem

```text
DataFrame products
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| name        | object |
| quantity    | int    |
| price       | int    |
+-------------+--------+
```

Write a solution to fill in the missing value as 0 in the quantity column.

The result format is in the following example.

```text
Example 1:
Input:+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | None     | 135   |
| WirelessEarbuds | None     | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Output:
+-----------------+----------+-------+
| name            | quantity | price |
+-----------------+----------+-------+
| Wristwatch      | 0        | 135   |
| WirelessEarbuds | 0        | 821   |
| GolfClubs       | 779      | 9319  |
| Printer         | 849      | 3051  |
+-----------------+----------+-------+
Explanation:
The quantity for Wristwatch and WirelessEarbuds are filled by 0.
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

# Editorial - 2887. Fill Missing Data

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | Pandas |

## Solution

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'].fillna(0, inplace=True)
    return products
```

</details>
