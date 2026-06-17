# 1644. Lowest Common Ancestor of a Binary Tree II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1644 - Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)

## Problem

Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)". A descendant of a node x is a node y that is on the path from node x to some leaf node.

### Example 1

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

### Example 2

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.
```

### Example 3

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -109 <= Node.val <= 109
- All Node.val are unique.
- p != q

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1644. Lowest Common Ancestor of a Binary Tree II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search - Modify LCA Solution | C++, Java, Python3 |
| Depth First Search - 2/3 Conditions | C++, Java, Python3 |

## Approach 1: Depth First Search - Modify LCA Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (node == NULL || node == p || node == q) return node;
    TreeNode* left = LCA(node->left, p, q);
    TreeNode* right = LCA(node->right, p, q);
    if (left && right)
        return node;
    else if (left)
        return left;
    else
        return right;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
private TreeNode LCA(TreeNode node, TreeNode p, TreeNode q) {
    if (node == null || node == p || node == q) return node;
    TreeNode left = LCA(node.left, p, q);
    TreeNode right = LCA(node.right, p, q);
    if (left != null && right != null) return node;
    else if (left != null) return left;
    else return right;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def LCA(node, p, q):
    if node is None or node == p or node == q:
        return node
    left = LCA(node.left, p, q)
    right = LCA(node.right, p, q)
    if left and right:
        return node
    elif left:
        return left
    else:
        return right
```

</details>

<br>

## Approach 2: Depth First Search - 2/3 Conditions

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool nodesFound = false;

        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) {
            // Base case: If the node is null, return null
            if (!node) return node;

            // Recursively search the left and right subtrees
            TreeNode* left = dfs(node->left);
            TreeNode* right = dfs(node->right);

            // Check conditions for current node being part of the solution
            int conditions = 0;
            if (node == p || node == q) conditions++;
            if (left != NULL) conditions++;
            if (right != NULL) conditions++;
            if (conditions == 2)
                nodesFound = true;  // Mark that both nodes are found

            // Determine if current node is the lowest common ancestor
            if ((left && right) || (node == p) || (node == q)) return node;

            // Return the non-null child, if any
            return left ? left : right;
        };

        // Start DFS traversal to find the lowest common ancestor
        TreeNode* ans = dfs(root);
        // Return the result only if both nodes are found
        return nodesFound ? ans : NULL;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    boolean nodesFound = false;

    public TreeNode lowestCommonAncestor(
        TreeNode root,
        TreeNode p,
        TreeNode q
    ) {
        // Start DFS traversal to find the lowest common ancestor
        TreeNode ans = dfs(root, p, q);
        // Return the result only if both nodes are found
        return nodesFound ? ans : null;
    }

    private TreeNode dfs(TreeNode node, TreeNode p, TreeNode q) {
        // Base case: If the node is null, return null
        if (node == null) return null;

        // Recursively search the left and right subtrees
        TreeNode left = dfs(node.left, p, q);
        TreeNode right = dfs(node.right, p, q);

        // Check conditions for current node being part of the solution
        int conditions = 0;
        if (node == p || node == q) conditions++;
        if (left != null) conditions++;
        if (right != null) conditions++;
        if (conditions == 2) nodesFound = true; // Mark that both nodes are found

        // Determine if current node is the lowest common ancestor
        if (
            (left != null && right != null) || node == p || node == q
        ) return node;

        // Return the non-null child, if any
        return left != null ? left : right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        self.nodes_found = False

        def dfs(node):
            # Base case: If the node is null, return None
            if not node:
                return node
            # Recursively search the left and right subtrees
            left, right = dfs(node.left), dfs(node.right)

            # Check conditions for current node being part of the solution
            conditions = 0
            if node in (p, q):
                conditions += 1
            if left:
                conditions += 1
            if right:
                conditions += 1
            if conditions == 2:
                self.nodes_found = True  # Mark that both nodes are found
            # Determine if current node is the lowest common ancestor
            if (left and right) or node in (p, q):
                return node
            # Return the non-null child, if any
            return left or right

        # Start DFS traversal to find the lowest common ancestor
        ans = dfs(root)
        # Return the result only if both nodes are found
        return ans if self.nodes_found else None
```

</details>
