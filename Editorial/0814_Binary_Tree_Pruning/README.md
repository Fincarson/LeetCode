# 814. Binary Tree Pruning

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-pruning/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 814 - Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)

## Problem

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

### Example 1

```text
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

### Example 2

```text
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

### Example 3

```text
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

## Constraints

- The number of nodes in the tree is in the range [1, 200].
- Node.val is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 814. Binary Tree Pruning

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Recursion [Accepted] | Java, Python3 |

## Approach #1: Recursion [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        return containsOne(root) ? root : null;
    }

    public boolean containsOne(TreeNode node) {
        if (node == null) return false;
        
        // Check if any node in the left subtree contains a 1.
        boolean leftContainsOne = containsOne(node.left);
        
        // Check if any node in the right subtree contains a 1.
        boolean rightContainsOne = containsOne(node.right);

        // If the left subtree does not contain a 1, prune the subtree.
        if (!leftContainsOne) node.left = null;
        
        // If the right subtree does not contain a 1, prune the subtree.
        if (!rightContainsOne) node.right = null;
        
        // Return true if the current node, its left or right subtree contains a 1.
        return node.val == 1 || leftContainsOne || rightContainsOne;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        
        def contains_one(node: TreeNode) -> bool:
            if not node: 
                return False
            
            # Check if any node in the left subtree contains a 1.
            left_contains_one = contains_one(node.left)
            
            # Check if any node in the right subtree contains a 1.
            right_contains_one = contains_one(node.right)
            
            # If the left subtree does not contain a 1, prune the subtree.
            if not left_contains_one: 
                node.left = None
                
            # If the right subtree does not contain a 1, prune the subtree.
            if not right_contains_one: 
                node.right = None
            
            # Return True if the current node or its left or right subtree contains a 1.
            return node.val or left_contains_one or right_contains_one

        # Return the pruned tree if the tree contains a 1, otherwise return None.
        return root if contains_one(root) else None
```

</details>
