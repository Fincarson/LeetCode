# 608. Tree Node

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/tree-node/)  
`Database`

**Problem Link:** [LeetCode 608 - Tree Node](https://leetcode.com/problems/tree-node/)

## Problem

Table: Tree

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| p_id        | int  |
+-------------+------+
id is the column with unique values for this table.
Each row of this table contains information about the id of a node and the id of its parent node in a tree.
The given structure is always a valid tree.
```

Each node in the tree can be one of three types:

- "Leaf": if the node is a leaf node.
- "Root": if the node is the root of the tree.
- "Inner": If the node is neither a leaf node nor a root node.

Write a solution to report the type of each node in the tree.

Return the result table in any order.

The result format is in the following example.

### Example 1

```text
Input:
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
Output:
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
+----+-------+
Explanation:
Node 1 is the root node because its parent node is null and it has child nodes 2 and 3.
Node 2 is an inner node because it has parent node 1 and child node 4 and 5.
Nodes 3, 4, and 5 are leaf nodes because they have parent nodes and they do not have child nodes.
```

### Example 2

```text
Input:
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
+----+------+
Output:
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
+----+-------+
Explanation: If there is only one node on the tree, you only need to output its root attributes.
```

Note: This question is the same as  3054: Binary Tree Nodes.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 608. Tree Node

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Conditional assignment combined with concatenation. | Pandas |
| Row-wise Classification | Pandas |
| Using numpy `where` | Pandas |
| Using `UNION` | SQL |
| Using flow control statement `CASE` | SQL |
| Using `IF` function | SQL |

## Approach 1: Conditional assignment combined with concatenation.

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    # Find the root node(s)
    root = tree.loc[tree['p_id'].isna(), ['id']]
    root['type'] = 'Root'
    
    # Find the leaf nodes
    leaf = tree.loc[
        ~tree['id'].isin(tree.loc[tree['p_id'].notna(), 'p_id']) & 
        tree['p_id'].notna(), 
        ['id']
    ]
    leaf['type'] = 'Leaf'
    
    # Find the inner nodes
    inner = tree.loc[
        tree['id'].isin(tree.loc[tree['p_id'].notna(), 'p_id']) & 
        tree['p_id'].notna(), 
        ['id']
    ]
    inner['type'] = 'Inner'
    
    # Concatenate the DataFrames and sort by 'id'
    result = pd.concat([root, leaf, inner]).sort_values(by='id')
    
    return result
```

</details>

<br>

## Approach 2: Row-wise Classification

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    # Get the ID of the root node
    root_id = tree.loc[tree['p_id'].isnull(), 'id'].values[0]

    # Get the list of IDs that are parents (to find inner nodes later)
    parent_ids = tree['p_id'].dropna().unique()

    # Define a function to apply to each row to determine the type
    def get_type(row):
        if row['id'] == root_id:
            return 'Root'
        elif row['id'] in parent_ids:
            return 'Inner'
        else:
            return 'Leaf'

    # Apply the function to each row
    tree['type'] = tree.apply(get_type, axis=1)
    
    # Create a new DataFrame with the required columns and sort it by 'id'
    result = tree[['id', 'type']].sort_values(by='id')
    
    return result
```

</details>

<br>

## Approach 3: Using numpy `where`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
import numpy as np

def tree_node(tree: pd.DataFrame) -> pd.DataFrame:
    tree["type"] = np.where(
        tree["p_id"].isna(),
        "Root",
        np.where(
            tree["id"].isin(tree["p_id"].unique()) & tree["p_id"].notna(),
            "Inner",
            "Leaf",
        ),
    )
    return tree[["id", "type"]]
```

</details>

<br>

## Approach 1: Using `UNION`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    id, 'Root' AS Type
FROM
    tree
WHERE
    p_id IS NULL
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    id, 'Leaf' AS Type
FROM
    tree
WHERE
    id NOT IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    id, 'Inner' AS Type
FROM
    tree
WHERE
    id IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
```

</details>

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    id, 'Root' AS Type
FROM
    tree
WHERE
    p_id IS NULL

UNION

SELECT
    id, 'Leaf' AS Type
FROM
    tree
WHERE
    id NOT IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL

UNION

SELECT
    id, 'Inner' AS Type
FROM
    tree
WHERE
    id IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
ORDER BY id;
```

</details>

<br>

## Approach 2: Using flow control statement `CASE`

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    id AS `Id`,
    CASE
        WHEN tree.id = (SELECT atree.id FROM tree atree WHERE atree.p_id IS NULL)
          THEN 'Root'
        WHEN tree.id IN (SELECT atree.p_id FROM tree atree)
          THEN 'Inner'
        ELSE 'Leaf'
    END AS Type
FROM
    tree
ORDER BY `Id`
;
```

</details>

<br>

## Approach 3: Using `IF` function

### Implementation

<details>
<summary><strong>SQL</strong></summary>

```sql
SELECT
    atree.id,
    IF(ISNULL(atree.p_id),
        'Root',
        IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM
 Ã‚Â  Ã‚Â tree atree
ORDER BY atree.id
```

</details>
