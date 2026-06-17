# 404. Sum of Left Leaves

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sum-of-left-leaves/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 404 - Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)

## Problem

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

### Example 2

```text
Input: root = [1]
Output: 0
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 404. Sum of Left Leaves

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Tree Traversal (Pre-order) | Java, Python |
| Recursive Tree Traversal (Pre-order) | Java, Python3 |
| Morris Tree Traversal (Pre-order) | C, Java, Python |

## Approach 1: Iterative Tree Traversal (Pre-order)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution { 
    
  private boolean isLeaf(TreeNode node) {
    return node != null && node.left == null && node.right == null;
  }

  public int sumOfLeftLeaves(TreeNode root) {

    if (root == null) {
      return 0;
    }

    int total = 0;
    Deque<TreeNode> stack = new ArrayDeque<>();
    stack.push(root);

    while (!stack.isEmpty()) {
      TreeNode subRoot = stack.pop();
      // Check if the left node is a leaf node.
      if (isLeaf(subRoot.left)) {
        total += subRoot.left.val;
      }
      // If the right node exists, put it on the stack.
      if (subRoot.right != null) {    
        stack.push(subRoot.right);
      }
      // If the left node exists, put it on the stack.
      if (subRoot.left != null) {
        stack.push(subRoot.left);
      }
    }

    return total;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        
        if root is None: 
            return 0

        def is_leaf(node):
            return node is not None and node.left is None and node.right is None

        stack = [root]
        total = 0
        while stack:
            sub_root = stack.pop()
            # Check if the left node is a leaf node.
            if is_leaf(sub_root.left):
                total += sub_root.left.val
            # If the right node exists, put it on the stack.
            if sub_root.right is not None:
                stack.append(sub_root.right)
            # If the left node exists, put it on the stack.
            if sub_root.left is not None:
                stack.append(sub_root.left)

        return total
```

</details>

<br>

## Approach 2: Recursive Tree Traversal (Pre-order)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution { 
    
  public int sumOfLeftLeaves(TreeNode root) {
    if (root == null) {
      return 0;
    }
    return processSubtree(root, false);
  }
    
  private int processSubtree(TreeNode subtree, boolean isLeft) {
        
    // Base case: This is a leaf node.
    if (subtree.left == null && subtree.right == null) {
      return isLeft ? subtree.val : 0;
    }
        
    // Recursive case: We need to add and return the results of the
    // left and right subtrees.
    int total = 0;
    if (subtree.left != null) {
      total += processSubtree(subtree.left, true);
    }
    if (subtree.right != null) {
      total += processSubtree(subtree.right, false);
    }
    return total;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        
        # An empty root is one of the test cases!
        if root is None:
            return 0

        def process_subtree(subtree, is_left):
            
            # Base case: This is a leaf node.
            if subtree.left is None and subtree.right is None:
                return subtree.val if is_left else 0
            
            # Recursive case: We need to add and return the results of the 
            # left and right subtrees.
            total = 0
            if subtree.left:
                total += process_subtree(subtree.left, True)
            if subtree.right:
                total += process_subtree(subtree.right, False)
            return total
        
        # Call the recursive function on the root node to start the process.
        # We need to be careful of the case that the root is empty.
        return process_subtree(root, False)
```

</details>

<br>

## Approach 3: Morris Tree Traversal (Pre-order)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Code by kamanelf (https://leetcode.com/kamanelf/)
// https://leetcode.com/problems/sum-of-left-leaves/discuss/124147/C-solution-with-Morris-Traversal
int sumOfLeftLeaves(struct TreeNode* root) {
  int sum = 0;
  while (root) {
    if (!root->left) {
      root = root->right;
    } else {
      struct TreeNode* pre = root->left;
      if (pre->left == NULL && pre->right == NULL) sum += pre->val;
      while (pre->right && pre->right != root) pre = pre->right;
      if (!pre->right) {
        pre->right = root;
        root = root->left;
      } else {
        pre->right = NULL;
        root = root->right;
      }
    }
  }
  return sum;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int sumOfLeftLeaves(TreeNode root) {
    int totalSum = 0;
    TreeNode currentNode = root;
    while (currentNode != null) {
      // If there is no left child, we can simply explore the right subtree
      // without needing to worry about keeping track of currentNode's other
      // child.
      if (currentNode.left == null) {
        currentNode = currentNode.right;
      } else {
        TreeNode previous = currentNode.left;
        // Check if this left node is a leaf node.
        if (previous.left == null && previous.right == null) {
          totalSum += previous.val;
        }
        // Find the inorder predecessor for currentNode.
        while (previous.right != null && !previous.right.equals(currentNode)) {
          previous = previous.right;
        }
        // We've not yet visited the inorder predecessor. This means that we 
        // still need to explore currentNode's left subtree. Before doing this,
        // we will put a link back so that we can get back to the right subtree
        // when we need to.
        if (previous.right == null) {
          previous.right = currentNode;
          currentNode = currentNode.left;
        }
        // We have already visited the inorder predecessor. This means that we
        // need to remove the link we added, and then move onto the right
        // subtree and explore it.
        else {
          previous.right = null;
          currentNode = currentNode.right;
        }
      }
    }
    return totalSum;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    
    def sumOfLeftLeaves(self, root):
        total_sum = 0
        current_node = root
        while current_node is not None:
            # If there is no left child, we can simply explore the right subtree
            # without needing to worry about keeping track of currentNode's other
            # child.
            if current_node.left is None: 
                current_node = current_node.right 
            else: 
                previous = current_node.left 
                # Check if this left node is a leaf node.
                if previous.left is None and previous.right is None:
                    total_sum += previous.val
                # Find the inorder predecessor for currentNode.
                while previous.right is not None and previous.right is not current_node:
                    previous = previous.right
                # We've not yet visited the inorder predecessor. This means that we 
                # still need to explore currentNode's left subtree. Before doing this,
                # we will put a link back so that we can get back to the right subtree
                # when we need to.
                if previous.right is None:
                    previous.right = current_node  
                    current_node = current_node.left  
                # We have already visited the inorder predecessor. This means that we
                # need to remove the link we added, and then move onto the right
                # subtree and explore it.
                else:
                    previous.right = None
                    current_node = current_node.right
        return total_sum
```

</details>
