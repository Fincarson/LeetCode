# 700. Search in a Binary Search Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/search-in-a-binary-search-tree/)  
`Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 700 - Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

## Problem

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

### Example 1

```text
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

### Example 2

```text
Input: root = [4,2,7,1,3], val = 5
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [1, 5000].
- 1 <= Node.val <= 107
- root is a binary search tree.
- 1 <= val <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 700. Search in a Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python |
| Iteration | Java, Python |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public TreeNode searchBST(TreeNode root, int val) {
    if (root == null || val == root.val) return root;

    return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or val == root.val:
            return root
        
        return self.searchBST(root.left, val) if val < root.val \
            else self.searchBST(root.right, val)
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public TreeNode searchBST(TreeNode root, int val) {
    while (root != null && val != root.val)
      root = val < root.val ? root.left : root.right;
    return root;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        while root is not None and root.val != val:
            root = root.left if val < root.val else root.right
        return root
```

</details>
