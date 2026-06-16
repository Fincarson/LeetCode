# 1372. Longest ZigZag Path in a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)  
`Dynamic Programming` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1372 - Longest ZigZag Path in a Binary Tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)

## Problem

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

- Choose any node in the binary tree and a direction (right or left).
- If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
- Change the direction from right to left or from left to right.
- Repeat the second and third steps until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

### Example 1

```text
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
```

### Example 2

```text
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
```

### Example 3

```text
Input: root = [1]
Output: 0
```

## Constraints

- The number of nodes in the tree is in the range [1, 5 * 104].
- 1 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1372. Longest ZigZag Path in a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth First Search | C++, Java, Python3 |

## Approach: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pathLength = 0;
    void dfs(TreeNode* node, bool goLeft, int steps) {
        if (node == nullptr) {
            return;
        }
        pathLength = max(pathLength, steps);
        if (goLeft) {
            dfs(node->left, false, steps + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->left, false, 1);
            dfs(node->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        return pathLength;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int pathLength = 0;
    private void dfs(TreeNode node, boolean goLeft, int steps) {
        if (node == null) {
            return;
        }
        pathLength = Math.max(pathLength, steps);
        if (goLeft) {
            dfs(node.left, false, steps + 1);
            dfs(node.right, true, 1);
        } else {
            dfs(node.left, false, 1);
            dfs(node.right, true, steps + 1);
        }
    }

    public int longestZigZag(TreeNode root) {
        dfs(root, true, 0);
        return pathLength;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.pathLength = 0
        
        def dfs(node, goLeft, steps):
            if node:
                self.pathLength = max(self.pathLength, steps)
                if goLeft:
                    dfs(node.left, False, steps + 1)
                    dfs(node.right, True, 1)
                else:
                    dfs(node.left, False, 1)
                    dfs(node.right, True, steps + 1)
        
        dfs(root, True, 0)
        return self.pathLength
```

</details>
