# 2738. Count Occurrences in Text

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-occurrences-in-text/)  
`Database`

**Problem Link:** [LeetCode 2738 - Count Occurrences in Text](https://leetcode.com/problems/count-occurrences-in-text/)

## Problem

Table: Files

```text
+-------------+---------+
| Column Name | Type    |
+-- ----------+---------+
| file_name   | varchar |
| content     | text    |
+-------------+---------+
file_name is the column with unique values of this table.
Each row contains file_name and the content of that file.
```

Write a solution to find the number of files that have at least one occurrence of the words 'bull' and 'bear' as a standalone word, respectively, disregarding any instances where it appears without space on either side (e.g. 'bullet', 'bears', 'bull.', or 'bear' at the beginning or end of a sentence will not be considered)

Return the word 'bull' and 'bear' along with the corresponding number of occurrences in any order.

The result format is in the following example.

### Example 1

```text
Input:
Files table:
+------------+----------------------------------------------------------------------------------+
| file_name  | content                                                                         |
+------------+----------------------------------------------------------------------------------+
| draft1.txt | The stock exchange predicts a bull market which would make many investors happy. |
| draft2.txt | The stock exchange predicts a bull market which would make many investors happy, |
|            | but analysts warn of possibility of too much optimism and that in fact we are    |
|            | awaiting a bear market.                                                          |
| draft3.txt | The stock exchange predicts a bull market which would make many investors happy, |
|            | but analysts warn of possibility of too much optimism and that in fact we are    |
|            | awaiting a bear market. As always predicting the future market is an uncertain   |
|            | game and all investors should follow their instincts and best practices.         |
+------------+----------------------------------------------------------------------------------+
Output:
+------+-------+
| word | count |
+------+-------+
| bull | 3     |
| bear | 2     |
+------+-------+
Explanation:
- The word "bull" appears 1 time in "draft1.txt", 1 time in "draft2.txt", and 1 time in "draft3.txt". Therefore, the total number of occurrences for the word "bull" is 3.
- The word "bear" appears 1 time in "draft2.txt", and 1 time in "draft3.txt". Therefore, the total number of occurrences for the word "bear" is 2.
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

# Editorial - 2738. Count Occurrences in Text

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Distinct File Name Count Using Regex With Whitespace Matching | Pandas |
| Total Occurrence Count Using String Matching with Spaces | Pandas |
| Distinct File Name Count Using `REGEXP` Operator | SQL |
| Distinct File Name Count Using `LIKE` Operator | SQL |

## Approach 1: Distinct File Name Count Using Regex With Whitespace Matching

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_occurrences(files: pd.DataFrame) -> pd.DataFrame:
    bull_count = files[
        files["content"].str.contains(r"(\s+bull\s+)", regex=True, case=False)
    ]["file_name"].nunique()
    bear_count = files[
        files["content"].str.contains(r"(\s+bear\s+)", regex=True, case=False)
    ]["file_name"].nunique()

    data = {"word": ["bull", "bear"], "count": [bull_count, bear_count]}

    result_df = pd.DataFrame(data)

    return result_df
```

</details>

<br>

## Approach 2: Total Occurrence Count Using String Matching with Spaces

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def count_occurrences(files: pd.DataFrame) -> pd.DataFrame:
    bull_count = files["content"].str.contains(" bull ", case=False).sum()
    bear_count = files["content"].str.contains(" bear ", case=False).sum()

    data = {"word": ["bull", "bear"], "count": [bull_count, bear_count]}

    result_df = pd.DataFrame(data)

    return result_df
```

</details>

<br>

## Approach 1: Distinct File Name Count Using `REGEXP` Operator

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  'bull' AS word, 
  SUM(
    CASE WHEN content REGEXP '( bull )' THEN 1 ELSE 0 END
  ) AS count 
FROM 
  Files
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
UNION 
SELECT 
  'bear' AS word, 
  SUM(
    CASE WHEN content REGEXP '( bear )' THEN 1 ELSE 0 END
  ) AS count 
FROM 
  Files
```

</details>

<br>

## Approach 2: Distinct File Name Count Using `LIKE` Operator

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT 
  'bull' AS word, 
  SUM(content LIKE '% bull %') AS count 
FROM 
  Files
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
UNION ALL 
SELECT 
  'bear' AS word, 
  SUM(content LIKE '% bear %') AS count 
FROM 
  Files
```

</details>
