# 236. Lowest Common Ancestor of a Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 236 - Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

## Problem

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: Ã¢â‚¬Å“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).Ã¢â‚¬Â

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
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

### Example 3

```text
Input: root = [1,2], p = 1, q = 2
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [2, 105].
- -109 <= Node.val <= 109
- All Node.val are unique.
- p != q
- p and q will exist in the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Smallest Common Region](https://leetcode.com/problems/smallest-common-region/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree II](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree III](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Cycle Length Queries in a Tree](https://leetcode.com/problems/cycle-length-queries-in-a-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 236. Lowest Common Ancestor of a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach | Java, Python3 |
| Iterative using parent pointers | Java, Python3 |
| Iterative without parent pointers | Java, Python3 |

## Approach 1: Recursive Approach

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private TreeNode ans;

    public Solution() {
        // Variable to store LCA node.
        this.ans = null;
    }

    private boolean recurseTree(TreeNode currentNode, TreeNode p, TreeNode q) {

        // If reached the end of a branch, return false.
        if (currentNode == null) {
            return false;
        }

        // Left Recursion. If left recursion returns true, set left = 1 else 0
        int left = this.recurseTree(currentNode.left, p, q) ? 1 : 0;

        // Right Recursion
        int right = this.recurseTree(currentNode.right, p, q) ? 1 : 0;

        // If the current node is one of p or q
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;


        // If any two of the flags left, right or mid become True
        if (mid + left + right >= 2) {
            this.ans = currentNode;
        }

        // Return true if any one of the three bool values is True.
        return (mid + left + right > 0);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Traverse the tree
        this.recurseTree(root, p, q);
        return this.ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def __init__(self):
        # Variable to store LCA node.
        self.ans = None

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def recurse_tree(current_node: TreeNode) -> bool:

            # If reached the end of a branch, return False.
            if not current_node:
                return False

            # Left Recursion
            left = recurse_tree(current_node.left)

            # Right Recursion
            right = recurse_tree(current_node.right)

            # If the current node is one of p or q
            mid = current_node == p or current_node == q

            # If any two of the three flags left, right or mid become True.
            if mid + left + right >= 2:
                self.ans = current_node

            # Return True if either of the three bool values is True.
            return mid or left or right

        # Traverse the tree
        recurse_tree(root)
        return self.ans
```

</details>

<br>

## Approach 2: Iterative using parent pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        // Stack for tree traversal
        Deque<TreeNode> stack = new ArrayDeque<>();

        // HashMap for parent pointers
        Map<TreeNode, TreeNode> parent = new HashMap<>();

        parent.put(root, null);
        stack.push(root);

        // Iterate until we find both the nodes p and q
        while (!parent.containsKey(p) || !parent.containsKey(q)) {

            TreeNode node = stack.pop();

            // While traversing the tree, keep saving the parent pointers.
            if (node.left != null) {
                parent.put(node.left, node);
                stack.push(node.left);
            }
            if (node.right != null) {
                parent.put(node.right, node);
                stack.push(node.right);
            }
        }

        // Ancestors set() for node p.
        Set<TreeNode> ancestors = new HashSet<>();

        // Process all ancestors for node p using parent pointers.
        while (p != null) {
            ancestors.add(p);
            p = parent.get(p);
        }

        // The first ancestor of q which appears in
        // p's ancestor set() is their lowest common ancestor.
        while (!ancestors.contains(q))
            q = parent.get(q);
        return q;
    }

}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:

        # Stack for tree traversal
        stack = [root]

        # Dictionary for parent pointers
        parent = {root: None}

        # Iterate until we find both the nodes p and q
        while p not in parent or q not in parent:

            node = stack.pop()

            # While traversing the tree, keep saving the parent pointers.
            if node.left:
                parent[node.left] = node
                stack.append(node.left)
            if node.right:
                parent[node.right] = node
                stack.append(node.right)

        # Ancestors set() for node p.
        ancestors = set()

        # Process all ancestors for node p using parent pointers.
        while p:
            ancestors.add(p)
            p = parent[p]

        # The first ancestor of q which appears in
        # p's ancestor set() is their lowest common ancestor.
        while q not in ancestors:
            q = parent[q]
        return q
```

</details>

<br>

## Approach 3: Iterative without parent pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Three static flags to keep track of post-order traversal.

    // Both left and right traversal pending for a node.
    // Indicates the nodes children are yet to be traversed.
    private static int BOTH_PENDING = 2;

    // Left traversal done.
    private static int LEFT_DONE = 1;

    // Both left and right traversal done for a node.
    // Indicates the node can be popped off the stack.
    private static int BOTH_DONE = 0;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        Stack<Pair<TreeNode, Integer>> stack = new Stack<Pair<TreeNode, Integer>>();

        // Initialize the stack with the root node.
        stack.push(new Pair<TreeNode, Integer>(root, Solution.BOTH_PENDING));

        // This flag is set when either one of p or q is found.
        boolean one_node_found = false;

        // This is used to keep track of the LCA.
        TreeNode LCA = null;

        // Child node
        TreeNode child_node = null;

        // We do a post order traversal of the binary tree using stack
        while (!stack.isEmpty()) {

            Pair<TreeNode, Integer> top = stack.peek();
            TreeNode parent_node = top.getKey();
            int parent_state = top.getValue();

            // If the parent_state is not equal to BOTH_DONE,
            // this means the parent_node can't be popped off yet.
            if (parent_state != Solution.BOTH_DONE) {

                // If both child traversals are pending
                if (parent_state == Solution.BOTH_PENDING) {

                    // Check if the current parent_node is either p or q.
                    if (parent_node == p || parent_node == q) {

                        // If one_node_found was set already, this means we have found
                        // both the nodes.
                        if (one_node_found) {
                            return LCA;
                        } else {
                            // Otherwise, set one_node_found to True,
                            // to mark one of p and q is found.
                            one_node_found = true;

                            // Save the current top element of stack as the LCA.
                            LCA = stack.peek().getKey();
                        }
                    }

                    // If both pending, traverse the left child first
                    child_node = parent_node.left;
                } else {
                    // traverse right child
                    child_node = parent_node.right;
                }

                // Update the node state at the top of the stack
                // Since we have visited one more child.
                stack.pop();
                stack.push(new Pair<TreeNode, Integer>(parent_node, parent_state - 1));

                // Add the child node to the stack for traversal.
                if (child_node != null) {
                    stack.push(new Pair<TreeNode, Integer>(child_node, Solution.BOTH_PENDING));
                }
            } else {

                // If the parent_state of the node is both done,
                // the top node could be popped off the stack.
                // Update the LCA node to be the next top node.
                if (LCA == stack.pop().getKey() && one_node_found) {
                    LCA = stack.peek().getKey();
                }

            }
        }

        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    # Three static flags to keep track of post-order traversal.

    # Both left and right traversal pending for a node.
    # Indicates the nodes children are yet to be traversed.
    BOTH_PENDING = 2
    # Left traversal done.
    LEFT_DONE = 1
    # Both left and right traversal done for a node.
    # Indicates the node can be popped off the stack.
    BOTH_DONE = 0

    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:

        # Initialize the stack with the root node.
        stack = [(root, Solution.BOTH_PENDING)]

        # This flag is set when either one of p or q is found.
        one_node_found = False

        # This is used to keep track of LCA index.
        LCA_index = -1

        # We do a post order traversal of the binary tree using stack
        while stack:

            parent_node, parent_state = stack[-1]

            # If the parent_state is not equal to BOTH_DONE,
            # this means the parent_node can't be popped of yet.
            if parent_state != Solution.BOTH_DONE:

                # If both child traversals are pending
                if parent_state == Solution.BOTH_PENDING:

                    # Check if the current parent_node is either p or q.
                    if parent_node == p or parent_node == q:

                        # If one_node_found is set already, this means we have found both the nodes.
                        if one_node_found:
                            return stack[LCA_index][0]
                        else:
                            # Otherwise, set one_node_found to True,
                            # to mark one of p and q is found.
                            one_node_found = True

                            # Save the current top index of stack as the LCA_index.
                            LCA_index = len(stack) - 1

                    # If both pending, traverse the left child first
                    child_node = parent_node.left
                else:
                    # traverse right child
                    child_node = parent_node.right

                # Update the node state at the top of the stack
                # Since we have visited one more child.
                stack.pop()
                stack.append((parent_node, parent_state - 1))

                # Add the child node to the stack for traversal.
                if child_node:
                    stack.append((child_node, Solution.BOTH_PENDING))
            else:

                # If the parent_state of the node is both done,
                # the top node could be popped off the stack.

                # i.e. If LCA_index is equal to length of stack. Then we decrease LCA_index by 1.
                if one_node_found and LCA_index == len(stack) - 1:
                    LCA_index -= 1
                stack.pop()

        return None
```

</details>
