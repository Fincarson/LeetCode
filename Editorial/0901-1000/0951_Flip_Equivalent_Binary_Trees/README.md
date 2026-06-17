# 951. Flip Equivalent Binary Trees

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flip-equivalent-binary-trees/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 951 - Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)

## Problem

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

### Example 1

```text
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
```

### Example 2

```text
Input: root1 = [], root2 = []
Output: true
```

### Example 3

```text
Input: root1 = [], root2 = [1]
Output: false
```

## Constraints

- The number of nodes in each tree is in the range [0, 100].
- Each tree will have unique node values in the range [0, 99].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 951. Flip Equivalent Binary Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Top-down Traversal) | C++, Java, Python3 |
| Iterative DFS (using a Stack) | C++, Java, Python3 |
| Canonical Forms | C++, Java, Python3 |

## Approach 1: Recursion (Top-down Traversal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Both trees are empty
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        // Just one of the trees is empty
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        // Corresponding values differ
        if (root1->val != root2->val) {
            return false;
        }

        // Check if corresponding subtrees are flip equivalent
        bool noSwap = flipEquiv(root1->left, root2->left) &&
                      flipEquiv(root1->right, root2->right);
        // Check if opposite subtrees are flip equivalent
        bool swap = flipEquiv(root1->left, root2->right) &&
                    flipEquiv(root1->right, root2->left);

        return swap || noSwap;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        // Both trees are empty
        if (root1 == null && root2 == null) {
            return true;
        }
        // Just one of the trees is empty
        if (root1 == null || root2 == null) {
            return false;
        }
        // Corresponding values differ
        if (root1.val != root2.val) {
            return false;
        }

        // Check if corresponding subtrees are flip equivalent
        boolean noSwap =
            flipEquiv(root1.left, root2.left) &&
            flipEquiv(root1.right, root2.right);
        // Check if opposite subtrees are flip equivalent
        boolean swap =
            flipEquiv(root1.left, root2.right) &&
            flipEquiv(root1.right, root2.left);

        return noSwap || swap;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def flipEquiv(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> bool:
        # Both trees are empty
        if not root1 and not root2:
            return True
        # Just one of the trees is empty
        if not root1 or not root2:
            return False
        # Corresponding values differ
        if root1.val != root2.val:
            return False

        # Check if corresponding subtrees are flip equivalent
        no_swap = self.flipEquiv(root1.left, root2.left) and self.flipEquiv(
            root1.right, root2.right
        )

        # Check if opposite subtrees are flip equivalent
        swap = self.flipEquiv(root1.left, root2.right) and self.flipEquiv(
            root1.right, root2.left
        )

        return no_swap or swap
```

</details>

<br>

## Approach 2: Iterative DFS (using a Stack)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Checks whether the given pair of nodes should be examined -
    // be pushed into the stack
    bool checkNodeValues(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 && node2 && node1->val == node2->val) return true;
        return false;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Initialize stack to store pairs of nodes
        stack<pair<TreeNode*, TreeNode*>> nodePairStack;
        nodePairStack.push({root1, root2});

        // While the stack is not empty:
        while (!nodePairStack.empty()) {
            auto [node1, node2] = nodePairStack.top();
            nodePairStack.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;

            // Check both configurations: no swap and swap
            if (checkNodeValues(node1->left, node2->left) &&
                checkNodeValues(node1->right, node2->right)) {
                nodePairStack.push({node1->left, node2->left});
                nodePairStack.push({node1->right, node2->right});
            } else if (checkNodeValues(node1->left, node2->right) &&
                       checkNodeValues(node1->right, node2->left)) {
                nodePairStack.push({node1->left, node2->right});
                nodePairStack.push({node1->right, node2->left});
            } else {
                return false;
            }
        }
        return true;
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Checks whether the given pair of nodes should be examined -
    // be pushed into the stack
    public boolean checkNodeValues(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) return true;
        if (
            node1 != null && node2 != null && node1.val == node2.val
        ) return true;
        return false;
    }

    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        // Initialize stack to store pairs of nodes
        Stack<TreeNode[]> nodePairStack = new Stack<>();
        nodePairStack.push(new TreeNode[] { root1, root2 });

        // While the stack is not empty:
        while (!nodePairStack.isEmpty()) {
            TreeNode[] current = nodePairStack.pop();
            TreeNode node1 = current[0];
            TreeNode node2 = current[1];

            if (node1 == null && node2 == null) continue;
            if (node1 == null || node2 == null) return false;
            if (node1.val != node2.val) return false;

            // Check both configurations: no swap and swap
            if (
                checkNodeValues(node1.left, node2.left) &&
                checkNodeValues(node1.right, node2.right)
            ) {
                nodePairStack.push(new TreeNode[] { node1.left, node2.left });
                nodePairStack.push(new TreeNode[] { node1.right, node2.right });
            } else if (
                checkNodeValues(node1.left, node2.right) &&
                checkNodeValues(node1.right, node2.left)
            ) {
                nodePairStack.push(new TreeNode[] { node1.left, node2.right });
                nodePairStack.push(new TreeNode[] { node1.right, node2.left });
            } else {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Checks whether the given pair of nodes should be examined -
    # be pushed into the stack
    def check_node_values(self, node_1: TreeNode, node_2: TreeNode) -> bool:
        if not node_1 and not node_2:
            return True
        if node_1 and node_2 and node_1.val == node_2.val:
            return True
        return False

    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        # Initialize stack to store pairs of nodes
        node_pair_stack = []
        node_pair_stack.append((root1, root2))

        # While the stack is not empty:
        while node_pair_stack:
            node_1, node_2 = node_pair_stack.pop()

            if not node_1 and not node_2:
                continue
            if not node_1 or not node_2:
                return False
            if node_1.val != node_2.val:
                return False

            # Check both configurations: no swap and swap
            if self.check_node_values(
                node_1.left, node_2.left
            ) and self.check_node_values(node_1.right, node_2.right):
                node_pair_stack.append((node_1.left, node_2.left))
                node_pair_stack.append((node_1.right, node_2.right))
            elif self.check_node_values(
                node_1.left, node_2.right
            ) and self.check_node_values(node_1.right, node_2.left):
                node_pair_stack.append((node_1.left, node_2.right))
                node_pair_stack.append((node_1.right, node_2.left))
            else:
                return False
        return True
```

</details>

<br>

## Approach 3: Canonical Forms

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void findCanonicalForm(TreeNode* root) {
        if (!root) return;

        // Post-order traversal: first bring subtrees in their canonical form
        findCanonicalForm(root->left);
        findCanonicalForm(root->right);

        if (!root->right) return;
        // Swap subtrees, so that left is non-empty
        if (!root->left) {
            root->left = root->right;
            root->right = NULL;
            return;
        }

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // Swap subtrees
        if (left->val > right->val) {
            root->left = right;
            root->right = left;
        }
    }

    bool areEquivalent(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return areEquivalent(root1->left, root2->left) &&
               areEquivalent(root1->right, root2->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        return areEquivalent(root1, root2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public void findCanonicalForm(TreeNode root) {
        if (root == null) return;

        // Post-order traversal: first bring subtrees into their canonical form
        findCanonicalForm(root.left);
        findCanonicalForm(root.right);

        if (root.right == null) return;

        // Swap subtrees, so that left is non-empty
        if (root.left == null) {
            root.left = root.right;
            root.right = null;
            return;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;
        // Swap subtrees
        if (left.val > right.val) {
            root.left = right;
            root.right = left;
        }
    }

    public boolean areEquivalent(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        if (root1.val != root2.val) return false;

        return (
            areEquivalent(root1.left, root2.left) &&
            areEquivalent(root1.right, root2.right)
        );
    }

    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        findCanonicalForm(root1);
        findCanonicalForm(root2);
        return areEquivalent(root1, root2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def find_canonical_form(self, root: TreeNode) -> None:
        if not root:
            return

        # Post-order traversal: first bring subtrees into their canonical form
        self.find_canonical_form(root.left)
        self.find_canonical_form(root.right)

        if not root.right:
            return

        # Swap subtrees, so that left is non-empty
        if not root.left:
            root.left = root.right
            root.right = None
            return
        left = root.left
        right = root.right

        # Swap subtrees
        if left.val > right.val:
            root.left, root.right = root.right, root.left

    def are_equivalent(self, root1: TreeNode, root2: TreeNode) -> bool:
        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False
        if root1.val != root2.val:
            return False
        return self.are_equivalent(
            root1.left, root2.left
        ) and self.are_equivalent(root1.right, root2.right)

    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
        self.find_canonical_form(root1)
        self.find_canonical_form(root2)
        return self.are_equivalent(root1, root2)
```

</details>
