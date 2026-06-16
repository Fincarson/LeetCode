# 1022. Sum of Root To Leaf Binary Numbers

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1022 - Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)

## Problem

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

- For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

### Example 1

```text
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

### Example 2

```text
Input: root = [0]
Output: 0
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- Node.val is 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1022. Sum of Root To Leaf Binary Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Preorder Traversal. | Java, Python |
| Recursive Preorder Traversal. | Java, Python |
| Morris Preorder Traversal. | Java, Python |

## Approach 1: Iterative Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumRootToLeaf(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque();
        stack.push(new Pair(root, 0));

        while (!stack.isEmpty()) {
          Pair<TreeNode, Integer> p = stack.pop();
          root = p.getKey();
          currNumber = p.getValue();

          if (root != null) {
            currNumber = (currNumber << 1) | root.val;
            // if it's a leaf, update root-to-leaf sum
            if (root.left == null && root.right == null) {
              rootToLeaf += currNumber;
            } else {
              stack.push(new Pair(root.right, currNumber));
              stack.push(new Pair(root.left, currNumber));
            }
          }
        }
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        root_to_leaf = 0
        stack = [(root, 0) ]
        
        while stack:
            root, curr_number = stack.pop()
            if root is not None:
                curr_number = (curr_number << 1) | root.val
                # if it's a leaf, update root-to-leaf sum
                if root.left is None and root.right is None:
                    root_to_leaf += curr_number
                else:
                    stack.append((root.right, curr_number))
                    stack.append((root.left, curr_number))
                        
        return root_to_leaf
```

</details>

<br>

## Approach 2: Recursive Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int rootToLeaf = 0;
    
    public void preorder(TreeNode r, int currNumber) {
        if (r != null) {
            currNumber = (currNumber << 1) | r.val;
            // If it's a leaf, update the root-to-leaf sum
            if (r.left == null && r.right == null) {
            rootToLeaf += currNumber;
            }
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }

    public int sumRootToLeaf(TreeNode root) {
        preorder(root, 0);
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def preorder(r, curr_number):
            nonlocal root_to_leaf
            if r:
                curr_number = (curr_number << 1) | r.val
                # If it's a leaf, update the root-to-leaf sum
                if not (r.left or r.right):
                    root_to_leaf += curr_number
                    
                preorder(r.left, curr_number)
                preorder(r.right, curr_number) 
        
        root_to_leaf = 0
        preorder(root, 0)
        return root_to_leaf
```

</details>

<br>

## Approach 3: Morris Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumRootToLeaf(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        int steps;
        TreeNode predecessor;

        while (root != null) {
            // If there is a left child,
            // then compute the predecessor.
            // If there is no link predecessor.right = root --> set it.
            // If there is a link predecessor.right = root --> break it.
            if (root.left != null) {
                // Predecessor node is one step to the left
                // and then to the right till you can.
                predecessor = root.left;
                steps = 1;
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                    ++steps;
                }

                // Set link predecessor.right = root
                // and go to explore the left subtree
                if (predecessor.right == null) {
                    currNumber = (currNumber << 1) | root.val;
                    predecessor.right = root;
                    root = root.left;
                }
                // Break the link predecessor.right = root
                // Once the link is broken,
                // it's time to change subtree and go to the right
                else {
                    // If you're on the leaf, update the sum
                    if (predecessor.left == null) {
                        rootToLeaf += currNumber;
                    }
                    // This part of tree is explored, backtrack
                    for(int i = 0; i < steps; ++i) {
                        currNumber >>= 1;
                    }
                    predecessor.right = null;
                    root = root.right;
                }
            }
            // If there is no left child
            // then just go right.
            else {
                currNumber = (currNumber << 1) | root.val;
                // if you're on the leaf, update the sum
                if (root.right == null) {
                    rootToLeaf += currNumber;
                }
                root = root.right;
            }
        }
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        root_to_leaf = curr_number = 0
        
        while root:  
            # If there is a left child,
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left: 
                # Predecessor node is one step to the left 
                # and then to the right till you can.
                predecessor = root.left 
                steps = 1
                while predecessor.right and predecessor.right is not root: 
                    predecessor = predecessor.right 
                    steps += 1

                # Set link predecessor.right = root
                # and go to explore the left subtree
                if predecessor.right is None:
                    curr_number = (curr_number << 1) | root.val                    
                    predecessor.right = root  
                    root = root.left  
                # Break the link predecessor.right = root
                # Once the link is broken, 
                # it's time to change subtree and go to the right
                else:
                    # If you're on the leaf, update the sum
                    if predecessor.left is None:
                        root_to_leaf += curr_number
                    # This part of tree is explored, backtrack
                    for _ in range(steps):
                        curr_number >>= 1
                    predecessor.right = None
                    root = root.right 
                    
            # If there is no left child
            # then just go right.        
            else: 
                curr_number = (curr_number << 1) | root.val
                # if you're on the leaf, update the sum
                if root.right is None:
                    root_to_leaf += curr_number
                root = root.right
                        
        return root_to_leaf
```

</details>
