# 1660. Correct a Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/correct-a-binary-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1660 - Correct a Binary Tree](https://leetcode.com/problems/correct-a-binary-tree/)

## Problem

You have a binary tree with a small defect. There is exactly one invalid node where its right child incorrectly points to another node at the same depth but to the invalid node's right.

Given the root of the binary tree with this defect, root, return the root of the binary tree after removing this invalid node and every node underneath it (minus the node it incorrectly points to).

Custom testing:

The test input is read as 3 lines:

- TreeNode root
- int fromNode (not available to correctBinaryTree)
- int toNode (not available to correctBinaryTree)

After the binary tree rooted at root is parsed, the TreeNode with value of fromNode will have its right child pointer pointing to the TreeNode with a value of toNode. Then, root is passed to correctBinaryTree.

### Example 1

```text
Input: root = [1,2,3], fromNode = 2, toNode = 3
Output: [1,null,3]
Explanation: The node with value 2 is invalid, so remove it.
```

### Example 2

```text
Input: root = [8,3,1,7,null,9,4,2,null,null,null,5,6], fromNode = 7, toNode = 4
Output: [8,3,1,null,null,9,4,null,null,5,6]
Explanation: The node with value 7 is invalid, so remove it and the node underneath it, node 2.
```

## Constraints

- The number of nodes in the tree is in the range [3, 104].
- -109 <= Node.val <= 109
- All Node.val are unique.
- fromNode != toNode
- fromNode and toNode will exist in the tree and will be on the same depth.
- toNode is to the right of fromNode.
- fromNode.right is null in the initial tree from the test data.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1660. Correct a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search | C++, C#, Java, JavaScript, Python3 |
| Depth First Search | C++, C#, Java, JavaScript, Python3 |

## Approach 1: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        // Queue for BFS. Every element stores [node, parent]
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        // Traverse Level by Level
        while (!q.empty()) {
            // Nodes in the current level
            int n = q.size();

            // Hash Set to store nodes of the current level
            unordered_set<TreeNode*> visited;

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                auto [node, parent] = q.front();
                q.pop();
                
                // If node.right is already visited, then the node is defective
                if (visited.count(node->right)) {
                    // Replace the child of the node's parent with null and return the root
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    return root;
                }

                // Add node to visited
                visited.insert(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add the right child first, so that we can explore right to left
                if (node->right) {
                    q.push({node->right, node});
                }
                if (node->left) {
                    q.push({node->left, node});
                }
            }
        }

        // For the sake of compilation
        return root;  
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public TreeNode CorrectBinaryTree(TreeNode root) {
        // Queue for BFS. Every element stores [node, parent]
        Queue<(TreeNode, TreeNode)> q = new Queue<(TreeNode, TreeNode)>();
        q.Enqueue((root, null));

        // Traverse Level by Level
        while (q.Count > 0) {
            // Nodes in the current level
            int n = q.Count;

            // Hash Set to store nodes of the current level
            HashSet<TreeNode> visited = new HashSet<TreeNode>();

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                (TreeNode node, TreeNode parent) = q.Dequeue();
                
                // If node.right is already visited, then node is defective
                if (visited.Contains(node.right)) {
                    // Replace the child of node's parent with null and return the root
                    if (parent.left == node) {
                        parent.left = null;
                    } else {
                        parent.right = null;
                    }
                    return root;
                }

                // Add node to visited
                visited.Add(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add the right child first, so that we can explore right to left
                if (node.right != null) {
                    q.Enqueue((node.right, node));
                }
                if (node.left != null) {
                    q.Enqueue((node.left, node));
                }
            }
        }

        // For the sake of compilation
        return root;
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode correctBinaryTree(TreeNode root) {
        // Queue for BFS. Every element stores [node, parent]
        Queue<TreeNode[]> queue = new LinkedList<>();
        queue.add(new TreeNode[]{root, null});

        // Traverse Level by Level
        while (!queue.isEmpty()) {
            // Nodes in the current level
            int n = queue.size();

            // Hash Set to store nodes of the current level
            Set<TreeNode> visited = new HashSet<>();

            // Traverse all nodes in the current level
            for (int i = 0; i < n; i++) {
                // Pop the node and its parent from the queue
                TreeNode[] temp = queue.poll();
                TreeNode node = temp[0], parent = temp[1];

                // If node.right is already visited, then node is defective
                if (visited.contains(node.right)) {
                    // Replace the child of node's parent with null and return root
                    if (parent.left == node) {
                        parent.left = null;
                    } else {
                        parent.right = null;
                    }
                    return root;
                }

                // Add node to visited
                visited.add(node);

                // Add child in queue for traversal in next level
                // They won't get popped in this level because of "n"
                // Add right child first, so that we can explore right to left
                if (node.right != null) {
                    queue.add(new TreeNode[]{node.right, node});
                }
                if (node.left != null) {
                    queue.add(new TreeNode[]{node.left, node});
                }
            }
        }

        // For the sake of compilation
        return root;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var correctBinaryTree = function(root) {
    // Queue for BFS. Every element stores [node, parent]
    const queue = [[root, null]];

    // Traverse Level by Level
    while (queue.length) {
        // Nodes in the current level
        const n = queue.length;

        // Hash Set to store nodes of the current level
        const visited = new Set();

        // Traverse all nodes in the current level
        for (let i = 0; i < n; i++) {
            // Pop the node and its parent from the queue
            const [node, parent] = queue.shift();

            // If node.right is already visited, then node is defective
            if (visited.has(node.right)) {
                // Replace the child of node's parent with null and return root
                if (parent.left === node) {
                    parent.left = null;
                } else {
                    parent.right = null;
                }
                return root;
            }

            // Add node to visited
            visited.add(node);

            // Add child in queue for traversal in next level
            // They won't get popped in this level because of "n"
            // Add right child first, so that we can explore right to left
            if (node.right) {
                queue.push([node.right, node]);
            }
            if (node.left) {
                queue.push([node.left, node]);
            }
        }
    }

    // For the sake of compilation
    return root;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        # Queue for BFS. Every element stores [node, parent]
        queue = deque([[root, None]])

        # Traverse Level by Level
        while queue:
            # Nodes in the current level
            n = len(queue)

            # Hash Set to store nodes of the current level
            visited = set()

            # Traverse all nodes in the current level
            for _ in range(n):
                # Pop the node from the queue
                node, parent = queue.popleft()

                # If node.right is already visited, then the node is defective
                if node.right in visited:
                    # Replace the child of the node's parent with null and return the root
                    if parent.left == node:
                        parent.left = None
                    else:
                        parent.right = None
                    return root

                # Add node to visited
                visited.add(node)

                # Add child in queue for traversal in next level
                # They won't get popped in this level because of "n"
                # Add the right child first, so that we can explore right to left
                if node.right:
                    queue.append([node.right, node])
                if node.left:
                    queue.append([node.left, node])
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
    // Hash Set to store node value of the rightmost branch
    unordered_set<int> visited;

    // Do Reverse Postorder Traversal. Assume input "root" as recursive parameter "node"
    TreeNode* correctBinaryTree(TreeNode* root) {
        // If Empty Node, return
        if (root == nullptr) {
            return nullptr;
        }

        // If node.right is already visited, then the node is defective
        // No need to build tree rooted at "node". Replace it with null
        if (root->right != nullptr && visited.count(root->right->val)) {
            return nullptr;
        }

        // Add this node's value to visited
        visited.insert(root->val);

        // Recursively build tree rooted at "node"
        // Build the right subtree first, so that we can explore right to left
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);

        // Return root of built tree
        return root;       
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public TreeNode CorrectBinaryTree(TreeNode root) {
        // Hash Set to store node value of the rightmost branch
        HashSet<int> visited = new HashSet<int>();

        // Do Reverse Postorder Traversal. Assume input "root" as recursive parameter "node"
        TreeNode correctBinaryTree(TreeNode node) {
            // If Empty Node, return
            if (node == null) {
                return null;
            }

            // If node.right is already visited, then the node is defective
            // No need to build tree rooted at "node". Replace it with null
            if (node.right != null && visited.Contains(node.right.val)) {
                return null;
            }

            // Add this node's value to the visited
            visited.Add(node.val);

            // Recursively build tree rooted at "node"
            // Build the right subtree first, so that we can explore right to left
            node.right = correctBinaryTree(node.right);
            node.left = correctBinaryTree(node.left);

            // Return root of built tree
            return node;       
        }

        // Build entire tree
        return correctBinaryTree(root);
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Hash Set to store node value of the rightmost branch
    Set<Integer> visited = new HashSet<>();

    // Do Reverse Postorder Traversal. Assume input "root" as recursive parameter "node"
    public TreeNode correctBinaryTree(TreeNode root) {
        // If Empty Node, return
        if (root == null) {
            return null;
        }

        // If node.right is already visited, then the node is defective
        // No need to build tree rooted at "node". Replace it with null
        if (root.right != null && visited.contains(root.right.val)) {
            return null;
        }

        // Add this node's value to the visited
        visited.add(root.val);

        // Recursively build tree rooted at "node"
        // Build right subtree first, so that we can explore right to left
        root.right = correctBinaryTree(root.right);
        root.left = correctBinaryTree(root.left);

        // Return root of built tree
        return root;       
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var correctBinaryTree = function(root) {
    // Hash Set to store node value of rightmost branch
    const visited = new Set();

    // Do Reverse Postorder Traversal. 
    const buildCorrectTree = (node) => {
        // If Empty Node, return
        if (node === null) {
            return null;
        }

        // If node.right is already visited, then the node is defective
        // No need to build tree rooted at "node". Replace it with null
        if (node.right !== null && visited.has(node.right.val)) {
            return null;
        }

        // Add this node's value to the visited
        visited.add(node.val);

        // Recursively build tree rooted at "node"
        // Build the right subtree first, so that we can explore the right to left
        node.right = buildCorrectTree(node.right);
        node.left = buildCorrectTree(node.left);

        // Return root of built tree
        return node;       
    }

    // Build entire tree
    return buildCorrectTree(root);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        # Hash Set to store node value of the rightmost branch
        visited = set()

        # Do Reverse Postorder Traversal
        def build_correct_tree(node):
            # If Empty Node, return
            if node is None:
                return None

            # If node.right is already visited, then the node is defective
            # No need to build tree rooted at "node". Replace it with None
            if node.right and node.right.val in visited:
                return None
            
            # Add this node's value to the visited
            visited.add(node.val)

            # Recursively build tree rooted at "node"
            # Build the right subtree first, so that we can explore the right to left
            node.right = build_correct_tree(node.right)
            node.left = build_correct_tree(node.left)

            # Return the root of the built tree
            return node
        
        # Build entire tree
        return build_correct_tree(root)
```

</details>
