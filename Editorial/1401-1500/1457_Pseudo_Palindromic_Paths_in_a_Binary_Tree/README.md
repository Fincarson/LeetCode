# 1457. Pseudo-Palindromic Paths in a Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)  
`Bit Manipulation` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1457 - Pseudo-Palindromic Paths in a Binary Tree](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)

## Problem

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

### Example 1

```text
Input: root = [2,3,1,3,1,null,1]
Output: 2
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

### Example 2

```text
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
```

### Example 3

```text
Input: root = [9]
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1457. Pseudo-Palindromic Paths in a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Preorder Traversal. | Java, Python3 |
| Recursive Preorder Traversal. | Java, Python3 |

## Approach 1: Iterative Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int pseudoPalindromicPaths (TreeNode root) {
        int count = 0, path = 0;
        
        Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque();
        stack.push(new Pair(root, 0));
        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> p = stack.pop();
            TreeNode node = p.getKey();
            path = p.getValue();

            if (node != null) {
                // compute occurrence of each digit 
                // in the corresponding register
                path = path ^ (1 << node.val);
                // if it's a leaf check if the path is pseudo-palindromic
                if (node.left == null && node.right == null) {
                    // check if at most one digit has an odd frequency
                    if ((path & (path - 1)) == 0) {
                        ++count;
                    }
                } else {
                    stack.push(new Pair(node.right, path));
                    stack.push(new Pair(node.left, path));
                }
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        count = 0
        
        stack = [(root, 0) ]
        while stack:
            node, path = stack.pop()
            if node is not None:
                # compute occurences of each digit 
                # in the corresponding register
                path = path ^ (1 << node.val)
                # if it's a leaf, check if the path is pseudo-palindromic
                if node.left is None and node.right is None:
                    # check if at most one digit has an odd frequency
                    if path & (path - 1) == 0:
                        count += 1
                else:
                    stack.append((node.right, path))
                    stack.append((node.left, path))
        
        return count
```

</details>

<br>

## Approach 2: Recursive Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;
        
    public void preorder(TreeNode node, int path) {
        if (node != null) {
            // compute occurences of each digit 
            // in the corresponding register
            path = path ^ (1 << node.val);
            // if it's a leaf check if the path is pseudo-palindromic
            if (node.left == null && node.right == null) {
                // check if at most one digit has an odd frequency
                if ((path & (path - 1)) == 0) {
                    ++count;
                }
            }
            preorder(node.left, path);
            preorder(node.right, path) ;
        }
    }

    public int pseudoPalindromicPaths (TreeNode root) {
        preorder(root, 0);
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        def preorder(node, path):
            nonlocal count
            if node:
                # compute occurences of each digit 
                # in the corresponding register
                path = path ^ (1 << node.val)
                # if it's a leaf, check if the path is pseudo-palindromic
                if node.left is None and node.right is None:
                    # check if at most one digit has an odd frequency
                    if path & (path - 1) == 0:
                        count += 1
                else:                    
                    preorder(node.left, path)
                    preorder(node.right, path) 
        
        count = 0
        preorder(root, 0)
        return count
```

</details>
