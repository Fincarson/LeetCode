# 222. Count Complete Tree Nodes

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-complete-tree-nodes/)  
`Binary Search` `Bit Manipulation` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 222 - Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)

## Problem

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

### Example 1

```text
Input: root = [1,2,3,4,5,6]
Output: 6
```

### Example 2

```text
Input: root = []
Output: 0
```

### Example 3

```text
Input: root = [1]
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [0, 5 * 104].
- 0 <= Node.val <= 5 * 104
- The tree is guaranteed to be complete.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 222. Count Complete Tree Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Time | Java, Python3 |
| Binary search | Java, Python3 |

## Approach 1: Linear Time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int countNodes(TreeNode root) {
    return root != null ? 1 + countNodes(root.right) + countNodes(root.left) : 0;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        return 1 + self.countNodes(root.right) + self.countNodes(root.left) if root else 0
```

</details>

<br>

## Approach 2: Binary search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  // Return tree depth in O(d) time.
  public int computeDepth(TreeNode node) {
    int d = 0;
    while (node.left != null) {
      node = node.left;
      ++d;
    }
    return d;
  }

  // Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
  // Return True if last level node idx exists. 
  // Binary search with O(d) complexity.
  public boolean exists(int idx, int d, TreeNode node) {
    int left = 0, right = (int)Math.pow(2, d) - 1;
    int pivot;
    for(int i = 0; i < d; ++i) {
      pivot = left + (right - left) / 2;
      if (idx <= pivot) {
        node = node.left;
        right = pivot;
      }
      else {
        node = node.right;
        left = pivot + 1;
      }
    }
    return node != null;
  }

  public int countNodes(TreeNode root) {
    // if the tree is empty
    if (root == null) return 0;

    int d = computeDepth(root);
    // if the tree contains 1 node
    if (d == 0) return 1;

    // Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
    // Perform binary search to check how many nodes exist.
    int left = 1, right = (int)Math.pow(2, d) - 1;
    int pivot;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (exists(pivot, d, root)) left = pivot + 1;
      else right = pivot - 1;
    }

    // The tree contains 2**d - 1 nodes on the first (d - 1) levels
    // and left nodes on the last level.
    return (int)Math.pow(2, d) - 1 + left;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def compute_depth(self, node: TreeNode) -> int:
        """
        Return tree depth in O(d) time.
        """
        d = 0
        while node.left:
            node = node.left
            d += 1
        return d

    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        Return True if last level node idx exists. 
        Binary search with O(d) complexity.
        """
        left, right = 0, 2**d - 1
        for _ in range(d):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
        
    def countNodes(self, root: TreeNode) -> int:
        # if the tree is empty
        if not root:
            return 0
        
        d = self.compute_depth(root)
        # if the tree contains 1 node
        if d == 0:
            return 1
        
        # Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        # Perform binary search to check how many nodes exist.
        left, right = 1, 2**d - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        # The tree contains 2**d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2**d - 1) + left
```

</details>
