# 965. Univalued Binary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/univalued-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 965 - Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/)

## Problem

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

### Example 1

```text
Input: root = [1,1,1,1,1,null,1]
Output: true
```

### Example 2

```text
Input: root = [2,2,2,5,2]
Output: false
```

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- 0 <= Node.val < 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find All The Lonely Nodes](https://leetcode.com/problems/find-all-the-lonely-nodes/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 965. Univalued Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | Java, Python |
| Recursion | Java, Python |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<Integer> vals;
    public boolean isUnivalTree(TreeNode root) {
        vals = new ArrayList();
        dfs(root);
        for (int v: vals)
            if (v != vals.get(0))
                return false;
        return true;
    }

    public void dfs(TreeNode node) {
        if (node != null) {
            vals.add(node.val);
            dfs(node.left);
            dfs(node.right);
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isUnivalTree(self, root):
        vals = []

        def dfs(node):
            if node:
                vals.append(node.val)
                dfs(node.left)
                dfs(node.right)

        dfs(root)
        return len(set(vals)) == 1
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isUnivalTree(TreeNode root) {
        boolean left_correct = (root.left == null ||
                (root.val == root.left.val && isUnivalTree(root.left)));
        boolean right_correct = (root.right == null ||
                (root.val == root.right.val && isUnivalTree(root.right)));
        return left_correct && right_correct;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isUnivalTree(self, root):
        left_correct = (not root.left or root.val == root.left.val
                and self.isUnivalTree(root.left))
        right_correct = (not root.right or root.val == root.right.val
                and self.isUnivalTree(root.right))
        return left_correct and right_correct
```

</details>
