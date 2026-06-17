# 257. Binary Tree Paths

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/binary-tree-paths/)  
`String` `Backtracking` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 257 - Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

## Problem

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

### Example 1

```text
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```

### Example 2

```text
Input: root = [1]
Output: ["1"]
```

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 257. Binary Tree Paths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python |
| Iterations | Java, Python |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public void construct_paths(TreeNode root, String path, LinkedList<String> paths) {
    if (root != null) {
      path += Integer.toString(root.val);
      if ((root.left == null) && (root.right == null))  // if reach a leaf
        paths.add(path);  // update paths
      else {
        path += "->";  // extend the current path
        construct_paths(root.left, path, paths);
        construct_paths(root.right, path, paths);
      }
    }
  }

  public List<String> binaryTreePaths(TreeNode root) {
    LinkedList<String> paths = new LinkedList();
    construct_paths(root, "", paths);
    return paths;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def construct_paths(root, path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:  # if reach a leaf
                    paths.append(path)  # update paths  
                else:
                    path += '->'  # extend the current path
                    construct_paths(root.left, path)
                    construct_paths(root.right, path)

        paths = []
        construct_paths(root, '')
        return paths
```

</details>

<br>

## Approach 2: Iterations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<String> binaryTreePaths(TreeNode root) {
    LinkedList<String> paths = new LinkedList();
    if (root == null)
      return paths;

    LinkedList<TreeNode> node_stack = new LinkedList();
    LinkedList<String> path_stack = new LinkedList();
    node_stack.add(root);
    path_stack.add(Integer.toString(root.val));
    TreeNode node;
    String path;

    while ( !node_stack.isEmpty() ) {
      node = node_stack.pollLast();
      path = path_stack.pollLast();
      if ((node.left == null) && (node.right == null))
        paths.add(path);
      if (node.left != null) {
        node_stack.add(node.left);
        path_stack.add(path + "->" + Integer.toString(node.left.val));
      }
      if (node.right != null) {
        node_stack.add(node.right);
        path_stack.add(path + "->" + Integer.toString(node.right.val));
      }
    }
    return paths;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        
        paths = []
        stack = [(root, str(root.val))]

        while stack:
            node, path = stack.pop()
            if not node.left and not node.right:
                paths.append(path)
            if node.left:
                stack.append((node.left, path + '->' + str(node.left.val)))
            if node.right:
                stack.append((node.right, path + '->' + str(node.right.val)))
        
        return paths
```

</details>
