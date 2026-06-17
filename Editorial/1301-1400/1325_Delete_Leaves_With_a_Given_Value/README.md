# 1325. Delete Leaves With a Given Value

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/delete-leaves-with-a-given-value/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1325 - Delete Leaves With a Given Value](https://leetcode.com/problems/delete-leaves-with-a-given-value/)

## Problem

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

### Example 1

```text
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left).
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
```

### Example 2

```text
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
```

### Example 3

```text
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
```

## Constraints

- The number of nodes in the tree is in the range [1, 3000].
- 1 <= Node.val, target <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1325. Delete Leaves With a Given Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Postorder Traversal) | C++, Java, Python3 |
| Iterative (PostOrder Traversal) | C++, Java, Python3 |

## Approach 1: Recursion (Postorder Traversal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // 1. Visit the left children
        root->left = removeLeafNodes(root->left, target);

        // 2. Visit the right children
        root->right = removeLeafNodes(root->right, target);

        // 3. check if the current node is a leaf node and its value equals
        // target.
        if (root->left == nullptr && root->right == nullptr &&
            root->val == target) {
            // Delete the node by returning a nullptr to the parent, effectively
            // disconnecting it.
            return nullptr;
        }
        // keep it untouched otherwise
        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        // Base case
        if (root == null) {
            return null;
        }

        // 1. Visit the left children
        root.left = removeLeafNodes(root.left, target);

        // 2. Visit the right children
        root.right = removeLeafNodes(root.right, target);

        // 3. Check if the current node is a leaf node and its value equals target
        if (root.left == null && root.right == null && root.val == target) {
            // Delete the node by returning null to the parent, effectively disconnecting it
            return null;
        }

        // Keep it untouched otherwise
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        # Base case
        if root is None:
            return None

        # 1. Visit the left children
        root.left = self.removeLeafNodes(root.left, target)

        # 2. Visit the right children
        root.right = self.removeLeafNodes(root.right, target)

        # 3. Check if the current node is a leaf node and its value equals target
        if root.left is None and root.right is None and root.val == target:
            # Delete the node by returning None to the parent, effectively disconnecting it
            return None

        # Keep it untouched otherwise
        return root
```

</details>

<br>

## Approach 2: Iterative (PostOrder Traversal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> stack;
        TreeNode *currentNode = root, *lastRightNode = nullptr;

        while (!stack.empty() || currentNode != nullptr) {
            // Push left nodes to the stack until reaching the leftmost node.
            while (currentNode != nullptr) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }

            // Access the top node on the stack without removing it.
            // This node is the current candidate for processing.
            currentNode = stack.top();

            // Check if the current node has an unexplored right subtree.
            // If so, shift to the right subtree unless it's the subtree we just
            // visited.
            if (currentNode->right != lastRightNode && currentNode->right) {
                currentNode = currentNode->right;
                continue;  // Continue in the while loop to push this new
                           // subtree's leftmost nodes.
            }

            // Remove the node from the stack, since we're about to process it.
            stack.pop();

            // If the node has no right subtree or the right subtree has already
            // been visited, then check if it is a leaf node with the target
            // value.
            if (currentNode->right == nullptr && currentNode->left == nullptr &&
                currentNode->val == target) {
                // If the stack is empty after popping, it means the root was a
                // target leaf node.
                if (stack.empty()) {
                    return nullptr;  // The tree becomes empty as the root
                                     // itself is removed.
                }

                // Identify the parent of the current node.
                TreeNode* parent = stack.top();

                // Disconnect the current node from its parent.
                if (parent->left == currentNode) {
                    parent->left = nullptr;  // If current node is a left child,
                                             // set the left pointer to null.
                } else {
                    parent->right =
                        nullptr;  // If current node  is a right child, set the
                                  // right pointer to null.
                }
            }

            // Mark this node as visited by setting 'lastRightNode' to
            // 'currentNode' before moving to the next iteration.
            lastRightNode = currentNode;
            // Reset 'currentNode' to null to ensure the next node from the
            // stack is processed.
            currentNode = nullptr;
        }
        return root;  // Return the modified tree.
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode currentNode = root, lastRightNode = null;

        while (!stack.isEmpty() || currentNode != null) {
            // Push left nodes to the stack until reaching the leftmost node.
            while (currentNode != null) {
                stack.push(currentNode);
                currentNode = currentNode.left;
            }

            // Access the top node on the stack without removing it.
            // This node is the current candidate for processing.
            currentNode = stack.peek();

            // Check if the current node has an unexplored right subtree.
            // If so, shift to the right subtree unless it's the subtree we just visited.
            if (
                currentNode.right != lastRightNode && currentNode.right != null
            ) {
                currentNode = currentNode.right;
                continue; // Continue in the while loop to push this new subtree's leftmost nodes.
            }

            // Remove the node from the stack, since we're about to process it.
            stack.pop();

            // If the node has no right subtree or the right subtree has already been visited,
            // then check if it is a leaf node with the target value.
            if (
                currentNode.right == null &&
                currentNode.left == null &&
                currentNode.val == target
            ) {
                // If the stack is empty after popping, it means the root was a target leaf node.
                if (stack.isEmpty()) {
                    return null; // The tree becomes empty as the root itself is removed.
                }

                // Identify the parent of the current node.
                TreeNode parent = stack.isEmpty() ? null : stack.peek();

                // Disconnect the current node from its parent.
                if (parent != null) {
                    if (parent.left == currentNode) {
                        parent.left = null; // If current is a left child, set the left pointer to null.
                    } else {
                        parent.right = null; // If current is a right child, set the right pointer to null.
                    }
                }
            }

            // Mark this node as visited by setting 'lastRightNode' to 'currentNode' before moving to the next iteration.
            lastRightNode = currentNode;
            // Reset 'currentNode' to null to ensure the next node from the stack is processed.
            currentNode = null;
        }
        return root; // Return the modified tree.
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeLeafNodes(
        self, root: Optional[TreeNode], target: int
    ) -> Optional[TreeNode]:
        if not root:
            return None

        stack = []
        current_node = root
        last_right_node = None

        while stack or current_node:
            # Push left nodes to the stack until reaching the leftmost node.
            while current_node:
                stack.append(current_node)
                current_node = current_node.left

            # Access the top node on the stack without removing it.
            # This node is the current candidate for processing.
            current_node = stack[-1]

            # Check if the current node has an unexplored right subtree.
            # If so, shift to the right subtree unless it's the subtree we just visited.
            if current_node.right and current_node.right is not last_right_node:
                current_node = current_node.right
                continue  # Continue in the while loop to push this new subtree's leftmost nodes.

            # Remove the node from the stack, since we're about to process it.
            stack.pop()

            # If the node has no right subtree or the right subtree has already been visited,
            # then check if it is a leaf node with the target value.
            if (
                not current_node.right
                and not current_node.left
                and current_node.val == target
            ):
                # If the stack is empty after popping, it means the root was a target leaf node.
                if not stack:
                    return None  # The tree becomes empty as the root itself is removed.

                # Identify the parent of the current node.
                parent = stack[-1] if stack else None

                # Disconnect the current node from its parent.
                if parent and parent.left is current_node:
                    parent.left = None  # If current is a left child, set the left pointer to null.
                elif parent and parent.right is current_node:
                    parent.right = None  # If current is a right child, set the right pointer to null.

            # Mark this node as visited by setting 'last_right_node' to 'current_node' before moving to the next iteration.
            last_right_node = current_node
            # Reset 'current_node' to None to ensure the next node from the stack is processed.
            current_node = None

        return root  # Return the modified tree
```

</details>
