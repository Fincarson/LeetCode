# 1740. Find Distance in a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-distance-in-a-binary-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1740 - Find Distance in a Binary Tree](https://leetcode.com/problems/find-distance-in-a-binary-tree/)

## Problem

Given the root of a binary tree and two integers p and q, return the distance between the nodes of value p and value q in the tree.

The distance between two nodes is the number of edges on the path from one to the other.

### Example 1

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
Output: 3
Explanation: There are 3 edges between 5 and 0: 5-3-1-0.
```

### Example 2

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
Output: 2
Explanation: There are 2 edges between 5 and 7: 5-2-7.
```

### Example 3

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
Output: 0
Explanation: The distance between a node and itself is 0.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 0 <= Node.val <= 109
- All Node.val are unique.
- p and q are values in the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Step-By-Step Directions From a Binary Tree Node to Another](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1740. Find Distance in a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Lowest Common Ancestor and Depth-First Search) | C++, Java, Python3 |
| Lowest Common Ancestor and Breadth-First Search | C++, Java, Python3 |
| One pass (Based on Lowest Common Ancestor) | C++, Java, Python3 |

## Approach 1: Brute Force (Lowest Common Ancestor and Depth-First Search)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // Find the lowest common ancestor of p and q.
        TreeNode* lca = findLCA(root, p, q);
        return depth(lca, p) + depth(lca, q);
    }

private:
    // Function to find the LCA of the given nodes.
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (root == nullptr or root->val == p or root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left != nullptr and right != nullptr) {
            return root;
        }
        return (left != nullptr) ? left : right;
    }

    // Function to find the depth of the node with respect to LCA.
    int depth(TreeNode* root, int target, int currentDepth = 0) {
        // Node not found
        if (root == NULL) {
            return -1;
        }
        if (root->val == target) {
            return currentDepth;
        }

        // Check left subtree
        int leftDepth = depth(root->left, target, currentDepth + 1);
        if (leftDepth != -1) {
            return leftDepth;
        }

        // If not in left subtree, it is guaranteed to be in right subtree
        return depth(root->right, target, currentDepth + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findDistance(TreeNode root, int p, int q) {
        // Find the lowest common ancestor of p and q.
        TreeNode lca = findLCA(root, p, q);
        return depth(lca, p) + depth(lca, q);
    }

    // Function to find the LCA of the given nodes.
    private TreeNode findLCA(TreeNode root, int p, int q) {
        if (root == null || root.val == p || root.val == q) {
            return root;
        }
        TreeNode left = findLCA(root.left, p, q);
        TreeNode right = findLCA(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        return left != null ? left : right;
    }

    // Function to find the depth of the node with respect to LCA.
    private int depth(TreeNode root, int target) {
        return depth(root, target, 0);
    }

    private int depth(TreeNode root, int target, int currentDepth) {
        // Node not found
        if (root == null) {
            return -1;
        }
        if (root.val == target) {
            return currentDepth;
        }

        // Check left subtree
        int leftDepth = depth(root.left, target, currentDepth + 1);
        if (leftDepth != -1) {
            return leftDepth;
        }

        // If not in left subtree, it is guaranteed to be in right subtree
        return depth(root.right, target, currentDepth + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDistance(self, root, p, q):
        # Find the lowest common ancestor of p and q.
        lca = self.__find_LCA(root, p, q)
        return self.__depth(lca, p) + self.__depth(lca, q)

    # Function to find the LCA of the given nodes.
    def __find_LCA(self, root, p, q):
        if root is None or root.val == p or root.val == q:
            return root
        left = self.__find_LCA(root.left, p, q)
        right = self.__find_LCA(root.right, p, q)
        if left is not None and right is not None:
            return root
        return left if left is not None else right

    # Function to find the depth of the node with respect to LCA.
    def __depth(self, root, target, current_depth=0):
        # Node not found
        if root is None:
            return -1
        if root.val == target:
            return current_depth

        # Check left subtree
        left_depth = self.__depth(root.left, target, current_depth + 1)
        if left_depth != -1:
            return left_depth

        # If not in left subtree, it is guaranteed to be in right subtree
        return self.__depth(root.right, target, current_depth + 1)
```

</details>

<br>

## Approach 2: Lowest Common Ancestor and Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // Find the lowest common ancestor of p and q.
        TreeNode* lca = findLCA(root, p, q);

        // Start the BFS process with lca as the root.
        queue<TreeNode*> bfs;
        bfs.push(lca);
        int distance = 0, depth = 0;
        bool foundp = 0, foundq = 0;
        while (!bfs.empty() or (foundp == 0 and foundq == 0)) {
            int size = bfs.size();

            // Traverse all nodes at the height level.
            while (size--) {
                TreeNode* front = bfs.front();
                bfs.pop();
                // Add the current height to the distance if p or q is found.
                if (front->val == p) {
                    distance += depth;
                    foundp = 1;
                }
                if (front->val == q) {
                    distance += depth;
                    foundq = 1;
                }
                // Add the children to the queue. These will be traversed in the
                // next height level.
                if (front->left != nullptr) {
                    bfs.push(front->left);
                }
                if (front->right != nullptr) {
                    bfs.push(front->right);
                }
            }
            depth++;
        }

        return distance;
    }

private:
    // Function to find the lca of two nodes recursively.
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (root == nullptr or root->val == p or root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left != nullptr and right != nullptr) {
            return root;
        }
        return (left != nullptr) ? left : right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findDistance(TreeNode root, int p, int q) {
        TreeNode lca = findLCA(root, p, q);
        if (lca == null) {
            return -1;
        }

        Queue<TreeNode> bfs = new LinkedList<>();
        bfs.add(lca);
        int distance = 0, depth = 0;
        boolean foundp = false, foundq = false;

        while ((bfs.size() > 0) & ((foundp == false) | (foundq == false))) {
            int size = bfs.size();

            for (int i = 0; i < size; ++i) {
                TreeNode front = bfs.poll();
                if (front.val == p) {
                    distance += depth;
                    foundp = true;
                }
                if (front.val == q) {
                    distance += depth;
                    foundq = true;
                }
                if (front.left != null) {
                    bfs.add(front.left);
                }
                if (front.right != null) {
                    bfs.add(front.right);
                }
            }
            depth++;
        }

        return distance;
    }

    private TreeNode findLCA(TreeNode root, int p, int q) {
        if (root == null) {
            return null;
        }
        if ((root.val == p) | (root.val == q)) {
            return root;
        }

        TreeNode left = findLCA(root.left, p, q);
        TreeNode right = findLCA(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }
        return (left != null) ? left : right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDistance(self, root, p, q):
        lca = self._find_LCA(root, p, q)
        bfs = deque([lca])
        distance = 0
        depth = 0
        foundp = False
        foundq = False
        while bfs and (not foundp or not foundq):
            size = len(bfs)
            for i in range(size):
                node = bfs.popleft()  # Dequeue the node
                if node.val == p:
                    distance += depth
                    foundp = True
                if node.val == q:
                    distance += depth
                    foundq = True
                if node.left:
                    bfs.append(node.left)  # Enqueue left child
                if node.right:
                    bfs.append(node.right)  # Enqueue right child
            depth += 1
        return distance

    def _find_LCA(self, root, p, q):
        if root is None or root.val == p or root.val == q:
            return root
        left = self._find_LCA(root.left, p, q)
        right = self._find_LCA(root.right, p, q)
        if left and right:
            return root
        return left if left else right
```

</details>

<br>

## Approach 3: One pass (Based on Lowest Common Ancestor)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        return distance(root, p, q, 0);
    }

private:
    // Helper function
    int distance(TreeNode* root, int p, int q, int depth) {
        if (root == nullptr or p == q) {
            return 0;
        }

        // If either p or q is found, calculate the retDistance as the maximum
        // of depth and retDistance value for left and right subtrees.
        if (root->val == p || root->val == q) {
            int left = distance(root->left, p, q, 1);
            int right = distance(root->right, p, q, 1);

            return (left > 0 || right > 0) ? max(left, right) : depth;
        }
        // Otherwise, calculate the retDistance as sum of retDistance of left
        // and right subtree.
        int left = distance(root->left, p, q, depth + 1);
        int right = distance(root->right, p, q, depth + 1);
        int retDistance = left + right;

        // If current node is the LCA, subtract twice of depth.
        if (left != 0 && right != 0) {
            retDistance -= 2 * depth;
        }

        return retDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int findDistance(TreeNode root, int p, int q) {
        return distance(root, p, q, 0);
    }

    // Helper function
    private int distance(TreeNode root, int p, int q, int depth) {
        if (root == null || p == q) {
            return 0;
        }

        // If either p or q is found, calculate the retDistance as the maximum
        // of depth and retDistance value for left and right subtrees.
        if (root.val == p || root.val == q) {
            int left = distance(root.left, p, q, 1);
            int right = distance(root.right, p, q, 1);

            return (left > 0 || right > 0) ? Math.max(left, right) : depth;
        }

        // Otherwise, calculate the retDistance as sum of retDistance of left
        // and right subtree.
        int left = distance(root.left, p, q, depth + 1);
        int right = distance(root.right, p, q, depth + 1);
        int retDistance = left + right;

        // If current node is the LCA, subtract twice of depth.
        if (left != 0 && right != 0) {
            retDistance -= 2 * depth;
        }

        return retDistance;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findDistance(self, root, p, q):
        return self.__distance(root, p, q, 0)

    # Private helper function
    def __distance(self, root, p, q, depth):
        if root is None or p == q:
            return 0

        # If either p or q is found, calculate the ret_distance as the maximum
        # of depth and ret_distance value for left and right subtrees.
        if root.val == p or root.val == q:
            left = self.__distance(root.left, p, q, 1)
            right = self.__distance(root.right, p, q, 1)

            return max(left, right) if left > 0 or right > 0 else depth

        # Otherwise, calculate the ret_distance as sum of ret_distance of left
        # and right subtree.
        left = self.__distance(root.left, p, q, depth + 1)
        right = self.__distance(root.right, p, q, depth + 1)
        ret_distance = left + right

        # If current node is the LCA, subtract twice of depth.
        if left != 0 and right != 0:
            ret_distance -= 2 * depth

        return ret_distance
```

</details>
