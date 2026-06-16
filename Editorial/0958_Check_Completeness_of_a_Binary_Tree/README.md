# 958. Check Completeness of a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 958 - Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

## Problem

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

### Example 1

```text
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
```

### Example 2

```text
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- 1 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 958. Check Completeness of a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java |
| Depth First Search | C++, Java |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool nullNodeFound = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                nullNodeFound = true;
            } else {
                if (nullNodeFound) {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) {
            return true;
        }

        boolean nullNodeFound = false;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode node = q.poll();

            if (node == null) {
                nullNodeFound = true;
            } else {
                if (nullNodeFound) {
                    return false;
                }
                q.offer(node.left);
                q.offer(node.right);
            }
        }
        return true;
    }
}
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* node, int index, int n) {
        if (node == nullptr) {
            return true;
        }
        // If index assigned to current node is greater or equal to the number of nodes
        // in tree, then the given tree is not a complete binary tree.
        if (index >= n) {
            return false;
        }
        // Recursively move to left and right subtrees.
        return dfs(node->left, 2 * index + 1, n) &&
               dfs(node->right, 2 * index + 2, n);
    }

    bool isCompleteTree(TreeNode* root) {
        return dfs(root, 0, countNodes(root));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public boolean dfs(TreeNode node, int index, int n) {
        if (node == null) {
            return true;
        }
        // If index assigned to current node is greater or equal to the number of nodes
        // in tree, then the given tree is not a complete binary tree.
        if (index >= n) {
            return false;
        }
        // Recursively move to left and right subtrees.
        return dfs(node.left, 2 * index + 1, n) &&
                dfs(node.right, 2 * index + 2, n);
    }

    public boolean isCompleteTree(TreeNode root) {
        return dfs(root, 0, countNodes(root));
    }
}
```

</details>
