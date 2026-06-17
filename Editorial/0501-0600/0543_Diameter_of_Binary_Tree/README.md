# 543. Diameter of Binary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/diameter-of-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 543 - Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

## Problem

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

### Example 1

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

### Example 2

```text
Input: root = [1,2]
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 543. Diameter of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-first Search | C++, Java, Python3 |

## Approach 1: Depth-first Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int diameter;

    int longestPath(TreeNode* node) {
        if (node == nullptr) return -1;

        // Recursively find the longest path in both left and right children
        int leftPath = longestPath(node->left);
        int rightPath = longestPath(node->right);

        // Update the diameter if leftPath + rightPath + 2 is greater
        diameter = std::max(diameter, leftPath + rightPath + 2);

        // Return the longest one between leftPath and rightPath + 1
        return std::max(leftPath, rightPath) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int diameter;
    public int diameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
    private int longestPath(TreeNode node){
        if(node == null) return -1;
        // recursively find the longest path in
        // both left child and right child
        int leftPath = longestPath(node.left);
        int rightPath = longestPath(node.right);

        // update the diameter if left_path plus right_path is larger
        diameter = Math.max(diameter, leftPath + rightPath + 2);

        // return the longest one between left_path and right_path;
        // remember to add 1 for the path connecting the node and its parent
        return Math.max(leftPath, rightPath) + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        diameter = 0

        def longest_path(node):
            if not node:
                return -1
            nonlocal diameter
            # recursively find the longest path in
            # both left child and right child
            left_path = longest_path(node.left)
            right_path = longest_path(node.right)

            # update the diameter if left_path plus right_path is larger
            diameter = max(diameter, left_path + right_path + 2)

            # return the longest one between left_path and right_path;
            # remember to add 1 for the path connecting the node and its parent
            return max(left_path, right_path) + 1

        longest_path(root)
        return diameter
```

</details>
