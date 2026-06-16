# 285. Inorder Successor in BST

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/inorder-successor-in-bst/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 285 - Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/)

## Problem

Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

### Example 1

```text
Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
```

### Example 2

```text
Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105
- All Nodes will have unique values.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Inorder Successor in BST II](https://leetcode.com/problems/inorder-successor-in-bst-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 285. Inorder Successor in BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Without using BST properties | Java, Python3 |
| Using BST properties | Java, Python3 |

## Approach 1: Without using BST properties

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    private TreeNode previous;
    private TreeNode inorderSuccessorNode;
    
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        
        // Case 1: We simply need to find the leftmost node in the subtree rooted at p.right.
        if (p.right != null) {
            
            TreeNode leftmost = p.right;
            
            while (leftmost.left != null) {
                leftmost = leftmost.left;
            }
            
            this.inorderSuccessorNode = leftmost;
        } else {
            
            // Case 2: We need to perform the standard in order to traversal and keep track of the previous node.
            this.inorderCase2(root, p);
        }
        
        return this.inorderSuccessorNode;
    }
    
    private void inorderCase2(TreeNode node, TreeNode p) {
        
        if (node == null) {
            return;
        }
        
        // Recurse on the left side
        this.inorderCase2(node.left, p);
        
        // Check if previous is the inorder predecessor of node
        if (this.previous == p && this.inorderSuccessorNode == null) {
            this.inorderSuccessorNode = node;
            return;
        }
        
        // Keeping previous up-to-date for further recursions
        this.previous = node;
        
        // Recurse on the right side
        this.inorderCase2(node.right, p);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    
    previous = None
    inorder_successor_node = None
    
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        
        self.previous, self.inorder_successor_node = None, None
        
        # Case 1: We simply need to find the leftmost node in the subtree rooted at p.right.
        if p.right:
            leftmost = p.right
            while leftmost.left:
                leftmost = leftmost.left
                
            self.inorder_successor_node = leftmost
        
        # Case 2: We need to perform the standard in order traversal and keep track of the previous node.
        else:
            self.inorderCase2(root, p)
        
        return self.inorder_successor_node
        
        
    def inorderCase2(self, node: 'TreeNode', p: 'TreeNode'):
        
        if not node:
            return
        
        # Recurse on the left side
        self.inorderCase2(node.left, p)
        
        # Check if the previous is the inorder predecessor of node
        if self.previous == p and not self.inorder_successor_node:
            self.inorder_successor_node = node
            return
        
        # Keeping previous up-to-date for further recursions
        self.previous = node
        
        # Recurse on the right side
        self.inorderCase2(node.right, p)
```

</details>

<br>

## Approach 2: Using BST properties

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        
        TreeNode successor = null;
        
        while (root != null) {
            
            if (p.val >= root.val) {
                root = root.right;
            } else {
                successor = root;
                root = root.left;
            }
        }
        
        return successor;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        
        successor = None
        
        while root:
            
            if p.val >= root.val:
                root = root.right
            else:
                successor = root
                root = root.left
                
        return successor
```

</details>
