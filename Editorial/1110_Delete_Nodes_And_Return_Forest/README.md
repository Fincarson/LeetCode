# 1110. Delete Nodes And Return Forest

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/delete-nodes-and-return-forest/)  
`Array` `Hash Table` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1110 - Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest/)

## Problem

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

### Example 1

```text
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
```

### Example 2

```text
Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
```

## Constraints

- The number of nodes in the given tree is at most 1000.
- Each node has a distinct value between 1 and 1000.
- to_delete.length <= 1000
- to_delete contains distinct values between 1 and 1000.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1110. Delete Nodes And Return Forest

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Postorder Traversal) | C++, Java, Python3 |
| BFS Forest Formation | C++, Java, Python3 |

## Approach 1: Recursion (Postorder Traversal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = processNode(root, toDeleteSet, forest);

        // If the root is not deleted, add it to the forest
        if (root) {
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet,
                          vector<TreeNode*>& forest) {
        if (!node) {
            return nullptr;
        }

        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        // Node Evaluation: Check if the current node needs to be deleted
        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            // If the node has left or right children, add them to the forest
            if (node->left) {
                forest.push_back(node->left);
            }
            if (node->right) {
                forest.push_back(node->right);
            }
            // Delete the current node and return null to its parent
            delete node;
            return nullptr;
        }

        return node;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> toDeleteSet = new HashSet<>();
        for (int val : to_delete) {
            toDeleteSet.add(val);
        }
        List<TreeNode> forest = new ArrayList<>();

        root = processNode(root, toDeleteSet, forest);

        // If the root is not deleted, add it to the forest
        if (root != null) {
            forest.add(root);
        }

        return forest;
    }

    private TreeNode processNode(
        TreeNode node,
        Set<Integer> toDeleteSet,
        List<TreeNode> forest
    ) {
        if (node == null) {
            return null;
        }

        node.left = processNode(node.left, toDeleteSet, forest);
        node.right = processNode(node.right, toDeleteSet, forest);

        // Node Evaluation: Check if the current node needs to be deleted
        if (toDeleteSet.contains(node.val)) {
            // If the node has left or right children, add them to the forest
            if (node.left != null) {
                forest.add(node.left);
            }
            if (node.right != null) {
                forest.add(node.right);
            }
            // Return null to its parent to delete the current node
            return null;
        }

        return node;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        to_delete_set = set(to_delete)
        forest = []

        root = self._process_node(root, to_delete_set, forest)

        # If the root is not deleted, add it to the forest
        if root:
            forest.append(root)

        return forest

    def _process_node(
        self, node: TreeNode, to_delete_set: Set[int], forest: List[TreeNode]
    ) -> TreeNode:
        if not node:
            return None

        node.left = self._process_node(node.left, to_delete_set, forest)
        node.right = self._process_node(node.right, to_delete_set, forest)

        # Node Evaluation: Check if the current node needs to be deleted
        if node.val in to_delete_set:
            # If the node has left or right children, add them to the forest
            if node.left:
                forest.append(node.left)
            if node.right:
                forest.append(node.right)
            # Delete the current node by returning None to its parent
            return None

        return node
```

</details>

<br>

## Approach 2: BFS Forest Formation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) {
            return {};
        }

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode->left) {
                nodesQueue.push(currentNode->left);
                // Disconnect the left child if it needs to be deleted
                if (toDeleteSet.find(currentNode->left->val) !=
                    toDeleteSet.end()) {
                    currentNode->left = nullptr;
                }
            }

            if (currentNode->right) {
                nodesQueue.push(currentNode->right);
                // Disconnect the right child if it needs to be deleted
                if (toDeleteSet.find(currentNode->right->val) !=
                    toDeleteSet.end()) {
                    currentNode->right = nullptr;
                }
            }

            // If the current node needs to be deleted, add its non-null
            // children to the forest
            if (toDeleteSet.find(currentNode->val) != toDeleteSet.end()) {
                if (currentNode->left) {
                    forest.push_back(currentNode->left);
                }
                if (currentNode->right) {
                    forest.push_back(currentNode->right);
                }
            }
        }

        // Ensure the root is added to the forest if it is not to be deleted
        if (toDeleteSet.find(root->val) == toDeleteSet.end()) {
            forest.push_back(root);
        }

        return forest;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        if (root == null) {
            return new ArrayList<>();
        }

        Set<Integer> toDeleteSet = new HashSet<>();
        for (int val : to_delete) {
            toDeleteSet.add(val);
        }

        List<TreeNode> forest = new ArrayList<>();

        Queue<TreeNode> nodesQueue = new LinkedList<>();
        nodesQueue.add(root);

        while (!nodesQueue.isEmpty()) {
            TreeNode currentNode = nodesQueue.poll();

            if (currentNode.left != null) {
                nodesQueue.add(currentNode.left);
                // Disconnect the left child if it needs to be deleted
                if (toDeleteSet.contains(currentNode.left.val)) {
                    currentNode.left = null;
                }
            }

            if (currentNode.right != null) {
                nodesQueue.add(currentNode.right);
                // Disconnect the right child if it needs to be deleted
                if (toDeleteSet.contains(currentNode.right.val)) {
                    currentNode.right = null;
                }
            }

            // If the current node needs to be deleted, add its non-null children to the forest
            if (toDeleteSet.contains(currentNode.val)) {
                if (currentNode.left != null) {
                    forest.add(currentNode.left);
                }
                if (currentNode.right != null) {
                    forest.add(currentNode.right);
                }
            }
        }

        // Ensure the root is added to the forest if it is not to be deleted
        if (!toDeleteSet.contains(root.val)) {
            forest.add(root);
        }

        return forest;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        if not root:
            return []

        to_delete_set = set(to_delete)
        forest = []

        nodes_queue = deque([root])

        while nodes_queue:
            current_node = nodes_queue.popleft()

            if current_node.left:
                nodes_queue.append(current_node.left)
                # Disconnect the left child if it needs to be deleted
                if current_node.left.val in to_delete_set:
                    current_node.left = None

            if current_node.right:
                nodes_queue.append(current_node.right)
                # Disconnect the right child if it needs to be deleted
                if current_node.right.val in to_delete_set:
                    current_node.right = None

            # If the current node needs to be deleted, add its non-null children to the forest
            if current_node.val in to_delete_set:
                if current_node.left:
                    forest.append(current_node.left)
                if current_node.right:
                    forest.append(current_node.right)

        # Ensure the root is added to the forest if it is not to be deleted
        if root.val not in to_delete_set:
            forest.append(root)

        return forest
```

</details>
