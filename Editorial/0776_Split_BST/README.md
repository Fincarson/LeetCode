# 776. Split BST

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/split-bst/)  
`Tree` `Binary Search Tree` `Recursion` `Binary Tree`

**Problem Link:** [LeetCode 776 - Split BST](https://leetcode.com/problems/split-bst/)

## Problem

Given the root of a binary search tree (BST) and an integer target, split the tree into two subtrees where the first subtree has nodes that are all smaller or equal to the target value, while the second subtree has all nodes that are greater than the target value. It is not necessarily the case that the tree contains a node with the value target.

Additionally, most of the structure of the original tree should remain. Formally, for any child c with parent p in the original tree, if they are both in the same subtree after the split, then node c should still have the parent p.

Return an array of the two roots of the two subtrees in order.

### Example 1

```text
Input: root = [4,2,6,1,3,5,7], target = 2
Output: [[2,1],[4,3,6,null,null,5,7]]
```

### Example 2

```text
Input: root = [1], target = 1
Output: [[1],[]]
```

## Constraints

- The number of nodes in the tree is in the range [1, 50].
- 0 <= Node.val, target <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 776. Split BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Traversal (DFS) | C++, Java, Python3 |
| Iterative Traversal | C++, Java, Python3 |
| Iterative Approach with Dummy Heads | C++, Java, Python3 |

## Approach 1: Recursive Traversal (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Base case: if root is null, return an array with two null elements
        if (!root) {
            return {nullptr, nullptr};
        }

        // If root's value is greater than target,
        // recursively split left subtree
        if (root->val > target) {
            auto left = splitBST(root->left, target);
            // Attach the right part of the split to root's left subtree
            root->left = left[1];
            return {left[0], root};
        } else {
            // Otherwise, recursively split right subtree
            auto right = splitBST(root->right, target);
            // Attach the left part of the split to root's right subtree
            root->right = right[0];
            return {root, right[1]};
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode[] splitBST(TreeNode root, int target) {
        // Base case: if root is null, return an array with two null elements
        if (root == null) {
            return new TreeNode[2];
        }

        // If root's value is greater than target, recursively split left subtree
        if (root.val > target) {
            TreeNode[] left = splitBST(root.left, target);
            // Attach the right part of the split to root's left subtree
            root.left = left[1];
            return new TreeNode[] { left[0], root };
        } else {
            // Otherwise, recursively split right subtree
            TreeNode[] right = splitBST(root.right, target);
            // Attach the left part of the split to root's right subtree
            root.right = right[0];
            return new TreeNode[] { root, right[1] };
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitBST(
        self, root: Optional[TreeNode], target: int
    ) -> List[Optional[TreeNode]]:
        # Base case: if root is None, return two None values

        if not root:
            return [None, None]

        # If root's value is greater than target,
        # recursively split left subtree
        if root.val > target:
            left = self.splitBST(root.left, target)

            # Attach the right part of the split to root's left subtree
            root.left = left[1]
            return [left[0], root]

        # Otherwise, recursively split right subtree
        else:
            right = self.splitBST(root.right, target)
            # Attach the left part of the split to root's right subtree
            root.right = right[0]
            return [root, right[1]]
```

</details>

<br>

## Approach 2: Iterative Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Initialize an array to store the two split trees
        vector<TreeNode*> ans(2, nullptr);

        // If the root is null, return the empty array
        if (!root) {
            return ans;
        }

        // Stack to traverse the tree and find the split point
        stack<TreeNode*> stack;

        // Find the node with the value closest to the target
        while (root) {
            stack.push(root);
            if (root->val > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        // Process nodes in reverse order from the stack to perform the split
        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            if (curr->val > target) {
                // Assign current node's left child to the subtree
                // containing nodes greater than the target
                curr->left = ans[1];
                // current node becomes the new root of this subtree
                ans[1] = curr;
            } else {
                // Assign current node's right child to the subtree
                // containing nodes smaller than the target
                curr->right = ans[0];
                // current node becomes the new root of this subtree
                ans[0] = curr;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode[] splitBST(TreeNode root, int target) {
        // Array to store the two split trees
        TreeNode[] ans = new TreeNode[2];

        // If the root is null, return the empty array
        if (root == null) {
            return ans;
        }

        // Stack to traverse the tree and find the split point
        Stack<TreeNode> stack = new Stack<>();

        // Find the node with the value closest to the target
        while (root != null) {
            stack.push(root);
            if (root.val > target) {
                root = root.left;
            } else {
                root = root.right;
            }
        }

        // Process nodes in reverse order from the stack to perform the split
        while (!stack.isEmpty()) {
            TreeNode curr = stack.pop();
            if (curr.val > target) {
                // Assign current node's left child to the subtree
                // containing nodes greater than the target
                curr.left = ans[1];
                // current node becomes the new root of this subtree
                ans[1] = curr;
            } else {
                // Assign current node's right child to the subtree
                // containing nodes smaller than the target
                curr.right = ans[0];
                // current node becomes the new root of this subtree
                ans[0] = curr;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitBST(
        self, root: Optional[TreeNode], target: int
    ) -> List[Optional[TreeNode]]:

        # List to store the two split trees
        ans = [None, None]

        # If root is None, return the empty list
        if not root:
            return ans
        # Stack to traverse the tree and find the split point
        stack = []
        # Find the node with the value closest to the target
        while root:
            stack.append(root)
            if root.val > target:
                root = root.left
            else:
                root = root.right
        # Process nodes in reverse order from the stack to perform the split
        while stack:
            curr = stack.pop()
            if curr.val > target:
                # Assign current node's left child to the subtree
                # containing nodes greater than the target
                curr.left = ans[1]
                # current node becomes the new root of this subtree
                ans[1] = curr
            else:
                # Assign current node's right child to the subtree
                # containing nodes smaller than the target
                curr.right = ans[0]
                # current node becomes the new root of this subtree
                ans[0] = curr
        return ans
```

</details>

<br>

## Approach 3: Iterative Approach with Dummy Heads

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Create dummy nodes to hold the split tree parts
        TreeNode* dummySm = new TreeNode(0);
        TreeNode* curSm = dummySm;
        TreeNode* dummyLg = new TreeNode(0);
        TreeNode* curLg = dummyLg;

        // Start traversal from the root
        TreeNode* current = root;
        TreeNode* nextNode = nullptr;

        while (current != nullptr) {
            if (current->val <= target) {
                // Attach the current node to the tree
                // with values less than or equal to the target
                curSm->right = current;
                curSm = current;

                // Move to the right subtree
                nextNode = current->right;

                // Clear the right pointer of current node
                curSm->right = nullptr;

                current = nextNode;
            } else {
                // Attach the current node to the tree
                // with values greather to the target
                curLg->left = current;
                curLg = current;

                // Move to the left subtree
                nextNode = current->left;

                // Clear the left pointer of current node
                curLg->left = nullptr;

                current = nextNode;
            }
        }

        // Return the split parts as a vector
        return {dummySm->right, dummyLg->left};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public static TreeNode[] splitBST(TreeNode root, int target) {
        // Create dummy nodes to hold the split tree parts
        TreeNode dummySm = new TreeNode(0);
        TreeNode curSm = dummySm;
        TreeNode dummyLg = new TreeNode(0);
        TreeNode curLg = dummyLg;

        // Start traversal from the root
        TreeNode current = root;
        TreeNode nextNode;

        while (current != null) {
            if (current.val <= target) {
                // Attach the current node to the tree
                // with values less than or equal to the target
                curSm.right = current;
                curSm = current;

                // Move to the right subtree
                nextNode = current.right;

                // Clear the right pointer of current node
                curSm.right = null;

                current = nextNode;
            } else {
                // Attach the current node to the tree
                // with values greather to the target
                curLg.left = current;
                curLg = current;

                // Move to the left subtree
                nextNode = current.left;

                // Clear the left pointer of current node
                curLg.left = null;

                current = nextNode;
            }
        }

        // Return the split parts as an array
        return new TreeNode[] { dummySm.right, dummyLg.left };
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitBST(self, root: TreeNode, target: int) -> list[TreeNode]:
        # Create dummy nodes to hold the split tree parts
        dummy_sm = TreeNode(0)
        cur_sm = dummy_sm
        dummy_lg = TreeNode(0)
        cur_lg = dummy_lg

        # Start traversal from the root
        current = root
        next_node = None

        while current is not None:
            if current.val <= target:
                # Attach the current node to the tree
                # with values less than or equal to the target
                cur_sm.right = current
                cur_sm = current

                # Move to the right subtree
                next_node = current.right

                # Clear the right pointer of current node
                cur_sm.right = None

                current = next_node
            else:
                # Attach the current node to the tree
                # with values greather to the target
                cur_lg.left = current
                cur_lg = current

                # Move to the left subtree
                next_node = current.left

                # Clear the left pointer of current node
                cur_lg.left = None

                current = next_node

        # Return the split parts as a list
        return [dummy_sm.right, dummy_lg.left]
```

</details>
