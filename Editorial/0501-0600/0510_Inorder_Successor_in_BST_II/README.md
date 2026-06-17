# 510. Inorder Successor in BST II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/inorder-successor-in-bst-ii/)  
`Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 510 - Inorder Successor in BST II](https://leetcode.com/problems/inorder-successor-in-bst-ii/)

## Problem

Given a node in a binary search tree, return the in-order successor of that node in the BST. If that node has no in-order successor, return null.

The successor of a node is the node with the smallest key greater than node.val.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node. Below is the definition for Node:

```text
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

### Example 1

```text
Input: tree = [2,1,3], node = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type.
```

### Example 2

```text
Input: tree = [5,3,6,2,4,null,null,1], node = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105
- All Nodes will have unique values.

Follow up: Could you solve it without looking up any of the node's values?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 510. Inorder Successor in BST II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration | C++, Java, Python |

## Approach 1: Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // the successor is somewhere lower in the right subtree
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;   
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public Node inorderSuccessor(Node x) {
    // the successor is somewhere lower in the right subtree
    if (x.right != null) {
      x = x.right;
      while (x.left != null) x = x.left;
      return x;
    }

    // the successor is somewhere upper in the tree
    while (x.parent != null && x == x.parent.right) x = x.parent;
    return x.parent;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        # the successor is somewhere lower in the right subtree
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        
        # the successor is somewhere upper in the tree
        while node.parent and node == node.parent.right:
            node = node.parent
        return node.parent
```

</details>
