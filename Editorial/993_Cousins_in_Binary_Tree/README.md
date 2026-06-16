# 993. Cousins in Binary Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/cousins-in-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 993 - Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/)

## Problem

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

### Example 1

```text
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

### Example 2

```text
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

### Example 3

```text
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

## Constraints

- The number of nodes in the tree is in the range [2, 100].
- 1 <= Node.val <= 100
- Each node has a unique value.
- x != y
- x and y are exist in the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Cousins in Binary Tree II](https://leetcode.com/problems/cousins-in-binary-tree-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 993. Cousins in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search with Branch Pruning | Java, Python3 |
| Breadth First Search with Early Stopping | Java, Python3 |

## Approach 1: Depth First Search with Branch Pruning

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    // To save the depth of the first node.
    int recordedDepth = -1;
    boolean isCousin = false;

    private boolean dfs(TreeNode node, int depth, int x, int y) {

        if (node == null) {
            return false;
        }

        // Don't go beyond the depth restricted by the first node found.
        if (this.recordedDepth != -1 && depth > this.recordedDepth) {
            return false;
        }

        if (node.val == x || node.val == y) {
            if (this.recordedDepth == -1) {
                // Save depth for the first node found.
                this.recordedDepth = depth;
            }
            // Return true, if the second node is found at the same depth.
            return this.recordedDepth == depth;
        }

        boolean left = dfs(node.left, depth + 1, x, y);
        boolean right = dfs(node.right, depth + 1, x, y);

        // this.recordedDepth != depth + 1 would ensure node x and y are not
        // immediate child nodes, otherwise they would become siblings.
        if (left && right && this.recordedDepth != depth + 1) {
            this.isCousin = true;
        }
        return left || right;
    }
    public boolean isCousins(TreeNode root, int x, int y) {

        // Recurse the tree to find x and y
        dfs(root, 0, x, y);
        return this.isCousin;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __init__(self):
        # To save the depth of the first node.
        self.recorded_depth = None
        self.is_cousin = False

    def dfs(self, node, depth, x, y):
        if node is None:
            return False

        # Don't go beyond the depth restricted by the first node found.
        if self.recorded_depth and depth > self.recorded_depth:
            return False

        if node.val == x or node.val == y:
            if self.recorded_depth is None:
                # Save depth for the first node.
                self.recorded_depth = depth
            # Return true, if the second node is found at the same depth.
            return self.recorded_depth == depth

        left = self.dfs(node.left, depth+1, x, y)
        right = self.dfs(node.right, depth+1, x, y)

        # self.recorded_depth != depth + 1 would ensure node x and y are not
        # immediate child nodes, otherwise they would become siblings.
        if left and right and self.recorded_depth != depth + 1:
            self.is_cousin = True

        return left or right

    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:

        # Recurse the tree to find x and y
        self.dfs(root, 0, x, y)
        return self.is_cousin
```

</details>

<br>

## Approach 2: Breadth First Search with Early Stopping

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    public boolean isCousins(TreeNode root, int x, int y) {

        // Queue for BFS
        Queue <TreeNode> queue = new LinkedList <> ();
        queue.add(root);

        while (!queue.isEmpty()) {
            boolean siblings = false;
            boolean cousins = false;

            int nodesAtDepth = queue.size();

            for (int i = 0; i < nodesAtDepth; i++) {
                // FIFO
                TreeNode node = queue.remove();

                // Encountered the marker.
                // Siblings should be set to false as we are crossing the boundary.
                if (node == null) {
                    siblings = false;
                } else {
                    if (node.val == x || node.val == y) {
                        // Set both the siblings and cousins flag to true
                        // for a potential first sibling/cousin found.
                        if (!cousins) {
                            siblings = cousins = true;
                        } else {
                            // If the siblings flag is still true this means we are still
                            // within the siblings boundary and hence the nodes are not cousins.
                            return !siblings;
                        }
                    }

                    if (node.left != null) queue.add(node.left);
                    if (node.right != null) queue.add(node.right);
                    // Adding the null marker for the siblings
                    queue.add(null);
                }
            }
            // After the end of a level if `cousins` is set to true
            // This means we found only one node at this level
            if (cousins) return false;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:

    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:

        # Queue for BFS
        queue = collections.deque([root])

        while queue:

            siblings = False
            cousins = False
            nodes_at_depth = len(queue)
            for _ in range(nodes_at_depth):

                # FIFO
                node = queue.popleft()  

                # Encountered the marker.
                # Siblings should be set to false as we are crossing the boundary.
                if node is None:
                    siblings = False
                else:
                    if node.val == x or node.val == y:
                        # Set both the siblings and cousins flag to true
                        # for a potential first sibling/cousin found.
                        if not cousins:
                            siblings, cousins = True, True
                        else:
                            # If the siblings flag is still true this means we are still
                            # within the siblings boundary and hence the nodes are not cousins.
                            return not siblings

                    queue.append(node.left) if node.left else None
                    queue.append(node.right) if node.right else None
                    # Adding the null marker for the siblings
                    queue.append(None)
            # After the end of a level if `cousins` is set to true
            # This means we found only one node at this level
            if cousins:
                return False

        return False
```

</details>
