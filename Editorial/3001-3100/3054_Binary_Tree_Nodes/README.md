# 3054. Binary Tree Nodes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-nodes/)  
`Database`

**Problem Link:** [LeetCode 3054 - Binary Tree Nodes](https://leetcode.com/problems/binary-tree-nodes/)

## Problem

Table: Tree

```text
+-------------+------+
| Column Name | Type |
+-------------+------+
| N           | int  |
| P           | int  |
+-------------+------+
N is the column of unique values for this table.
Each row includes N and P, where N represents the value of a node in Binary Tree, and P is the parent of N.
```

Write a solution to find the node type of the Binary Tree. Output one of the following for each node:

- Root: if the node is the root node.
- Leaf: if the node is the leaf node.
- Inner: if the node is neither root nor leaf node.

Return the result table ordered by node value in ascending order.

The result format is in the following example.

### Example 1

```text
Input:
Tree table:
+---+------+
| N | P    |
+---+------+
| 1 | 2    |
| 3 | 2    |
| 6 | 8    |
| 9 | 8    |
| 2 | 5    |
| 8 | 5    |
| 5 | null |
+---+------+
Output:
+---+-------+
| N | Type  |
+---+-------+
| 1 | Leaf  |
| 2 | Inner |
| 3 | Leaf  |
| 5 | Root  |
| 6 | Leaf  |
| 8 | Inner |
| 9 | Leaf  |
+---+-------+
Explanation:
- Node 5 is the root node since it has no parent node.
- Nodes 1, 3, 6, and 9 are leaf nodes because they don't have any child nodes.
- Nodes 2, and 8 are inner nodes as they serve as parents to some of the nodes in the structure.
```

Note: This question is the same as  608: Tree Node.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3054. Binary Tree Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Utilizing `loc` | Pandas |
| Utilizing Numpy `where` | Pandas |
| Approach: Utlizing `CASE` Statements | MySQL |

## Approach 1: Utilizing `loc`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python

import pandas as pd

def binary_tree_nodes(tree: pd.DataFrame) -> pd.DataFrame:
    tree["Type"] = "Inner"
    tree.loc[~tree.N.isin(tree.P), "Type"] = "Leaf"
    tree.loc[tree.P.isnull(), "Type"] = "Root"
    return tree[["N", "Type"]].sort_values("N")
```

</details>

<br>

## Approach 2: Utilizing Numpy `where`

### Implementation

<details>
<summary><strong>Pandas</strong></summary>

```python
import pandas as pd
import numpy as np

def binary_tree_nodes(tree: pd.DataFrame) -> pd.DataFrame:
    # Check if each node is a parent (Inner) or not
    tree["Type"] = np.where(
        tree["P"].isnull(), "Root", np.where(tree["N"].isin(tree["P"]), "Inner", "Leaf")
    )

    # Sort the DataFrame by the 'N' column
    return tree.sort_values("N")[["N", "Type"]]
```

</details>

<br>

## Approach: Utlizing `CASE` Statements

### Implementation

<details>
<summary><strong>MySQL</strong></summary>

```sql
SELECT
  N,
  CASE
    WHEN P IS NULL THEN
      "Root"
    WHEN N IN (
      SELECT 
        P 
      FROM 
        Tree
    ) THEN
      "Inner"
    ELSE
      "Leaf"
    END as Type
FROM 
  Tree
ORDER BY 
  N;
```

</details>
