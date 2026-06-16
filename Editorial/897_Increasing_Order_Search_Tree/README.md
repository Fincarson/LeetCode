# 897. Increasing Order Search Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/increasing-order-search-tree/)  
`Stack` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 897 - Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)

## Problem

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

### Example 1

```text
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```

### Example 2

```text
Input: root = [5,1,7]
Output: [1,null,5,null,7]
```

## Constraints

- The number of nodes in the given tree will be in the range [1, 100].
- 0 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 897. Increasing Order Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| In-Order Traversal | Java, Python3 |
| Traversal with Relinking | Java, Python |

## Approach 1: In-Order Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public TreeNode increasingBST(TreeNode root) {
        List<Integer> vals = new ArrayList();
        inorder(root, vals);
        TreeNode ans = new TreeNode(0), cur = ans;
        for (int v: vals) {
            cur.right = new TreeNode(v);
            cur = cur.right;
        }
        return ans.right;
    }

    public void inorder(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        inorder(node.left, vals);
        vals.add(node.val);
        inorder(node.right, vals);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def increasingBST(self, root):
        def inorder(node):
            if node:
                yield from inorder(node.left)
                yield node.val
                yield from inorder(node.right)

        ans = cur = TreeNode(None)
        for v in inorder(root):
            cur.right = TreeNode(v)
            cur = cur.right
        return ans.right
```

</details>

<br>

## Approach 2: Traversal with Relinking

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    TreeNode cur;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode ans = new TreeNode(0);
        cur = ans;
        inorder(root);
        return ans.right;
    }

    public void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        node.left = null;
        cur.right = node;
        cur = node;
        inorder(node.right);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def increasingBST(self, root):
        def inorder(node):
            if node:
                inorder(node.left)
                node.left = None
                self.cur.right = node
                self.cur = node
                inorder(node.right)

        ans = self.cur = TreeNode(None)
        inorder(root)
        return ans.right
```

</details>
