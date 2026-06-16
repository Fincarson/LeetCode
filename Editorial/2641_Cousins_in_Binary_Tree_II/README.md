# 2641. Cousins in Binary Tree II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/cousins-in-binary-tree-ii/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2641 - Cousins in Binary Tree II](https://leetcode.com/problems/cousins-in-binary-tree-ii/)

## Problem

Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

### Example 1

```text
Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
```

### Example 2

```text
Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2641. Cousins in Binary Tree II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pass BFS | C++, Java, Python3 |
| Two Pass DFS | C++, Java, Python3 |
| Single BFS with Running Sum | C++, Java, Python3 |

## Approach 1: Two Pass BFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<int> levelSums;

        // First BFS: Calculate sum of nodes at each level
        while (!nodeQueue.empty()) {
            int levelSum = 0;
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                levelSum += currentNode->val;
                if (currentNode->left) nodeQueue.push(currentNode->left);
                if (currentNode->right) nodeQueue.push(currentNode->right);
            }
            levelSums.push_back(levelSum);
        }

        // Second BFS: Update each node's value to sum of its cousins
        nodeQueue.push(root);
        int levelIndex = 1;
        root->val = 0;  // Root has no cousins
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();

                int siblingSum =
                    (currentNode->left ? currentNode->left->val : 0) +
                    (currentNode->right ? currentNode->right->val : 0);

                if (currentNode->left) {
                    currentNode->left->val = levelSums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    currentNode->right->val =
                        levelSums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->right);
                }
            }
            ++levelIndex;
        }

        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) return root;

        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.offer(root);
        List<Integer> levelSums = new ArrayList<>();

        // First BFS: Calculate sum of nodes at each level
        while (!nodeQueue.isEmpty()) {
            int levelSum = 0;
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode currentNode = nodeQueue.poll();
                levelSum += currentNode.val;
                if (currentNode.left != null) nodeQueue.offer(currentNode.left);
                if (currentNode.right != null) nodeQueue.offer(
                    currentNode.right
                );
            }
            levelSums.add(levelSum);
        }

        // Second BFS: Update each node's value to sum of its cousins
        nodeQueue.offer(root);
        int levelIndex = 1;
        root.val = 0; // Root has no cousins
        while (!nodeQueue.isEmpty()) {
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode currentNode = nodeQueue.poll();

                int siblingSum =
                    (currentNode.left != null ? currentNode.left.val : 0) +
                    (currentNode.right != null ? currentNode.right.val : 0);

                if (currentNode.left != null) {
                    currentNode.left.val =
                        levelSums.get(levelIndex) - siblingSum;
                    nodeQueue.offer(currentNode.left);
                }
                if (currentNode.right != null) {
                    currentNode.right.val =
                        levelSums.get(levelIndex) - siblingSum;
                    nodeQueue.offer(currentNode.right);
                }
            }
            ++levelIndex;
        }

        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def replaceValueInTree(self, root):
        if not root:
            return root
        node_queue = deque([root])
        level_sums = []

        # First BFS: Calculate sum of nodes at each level
        while node_queue:
            level_sum = 0
            level_size = len(node_queue)
            for _ in range(level_size):
                current_node = node_queue.popleft()
                level_sum += current_node.val
                if current_node.left:
                    node_queue.append(current_node.left)
                if current_node.right:
                    node_queue.append(current_node.right)
            level_sums.append(level_sum)

        # Second BFS: Update each node's value to sum of its cousins
        node_queue.append(root)
        level_index = 1
        root.val = 0  # Root has no cousins
        while node_queue:
            level_size = len(node_queue)
            for _ in range(level_size):
                current_node = node_queue.popleft()

                sibling_sum = (
                    current_node.left.val if current_node.left else 0
                ) + (current_node.right.val if current_node.right else 0)

                if current_node.left:
                    current_node.left.val = (
                        level_sums[level_index] - sibling_sum
                    )
                    node_queue.append(current_node.left)
                if current_node.right:
                    current_node.right.val = (
                        level_sums[level_index] - sibling_sum
                    )
                    node_queue.append(current_node.right)
            level_index += 1

        return root
```

</details>

<br>

## Approach 2: Two Pass DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Array to store the sum of values at each level
    int levelSums[100000];

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculateLevelSum(root, 0);              // First pass to calculate sums
        replaceValueInTreeInternal(root, 0, 0);  // Second pass to update values
        return root;
    }

    // First DFS to calculate the sum of values at each level
    void calculateLevelSum(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }

        levelSums[level] += node->val;  // Accumulate sum at the current level
        calculateLevelSum(node->left, level + 1);   // Recur for the left child
        calculateLevelSum(node->right, level + 1);  // Recur for the right child
    }

    // Second DFS to replace each node's value with the sum of its cousins
    void replaceValueInTreeInternal(TreeNode* node, int siblingSum, int level) {
        if (node == nullptr) {
            return;
        }

        // Left child value
        int leftChildVal = node->left == nullptr ? 0 : node->left->val;
        // Right child value
        int rightChildVal = node->right == nullptr ? 0 : node->right->val;

        // For the root and its children, set value to 0
        if (level == 0 || level == 1) {
            node->val = 0;
        } else {
            // Set the node's value to the sum of its cousins
            node->val = levelSums[level] - node->val - siblingSum;
        }

        // Recur for left and right children
        replaceValueInTreeInternal(node->left, rightChildVal, level + 1);
        replaceValueInTreeInternal(node->right, leftChildVal, level + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int[] levelSums = new int[100000];

    public TreeNode replaceValueInTree(TreeNode root) {
        calculateLevelSum(root, 0);
        replaceValueInTreeInternal(root, 0, 0);
        return root;
    }

    private void calculateLevelSum(TreeNode node, int level) {
        if (node == null) {
            return;
        }

        levelSums[level] += node.val;
        calculateLevelSum(node.left, level + 1);
        calculateLevelSum(node.right, level + 1);
    }

    private void replaceValueInTreeInternal(
        TreeNode node,
        int siblingSum,
        int level
    ) {
        if (node == null) {
            return;
        }

        int leftChildVal = (node.left == null) ? 0 : node.left.val;
        int rightChildVal = (node.right == null) ? 0 : node.right.val;

        if (level == 0 || level == 1) {
            node.val = 0;
        } else {
            node.val = levelSums[level] - node.val - siblingSum;
        }

        replaceValueInTreeInternal(node.left, rightChildVal, level + 1);
        replaceValueInTreeInternal(node.right, leftChildVal, level + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.level_sums = [0] * 100000

    def replaceValueInTree(self, root):
        self._calculate_level_sum(root, 0)
        self.replace_value_in_tree_internal(root, 0, 0)
        return root

    def _calculate_level_sum(self, node, level):
        if node is None:
            return
        self.level_sums[level] += node.val
        self._calculate_level_sum(node.left, level + 1)
        self._calculate_level_sum(node.right, level + 1)

    def replace_value_in_tree_internal(self, node, sibling_sum, level):
        if node is None:
            return
        left_child_val = 0 if node.left is None else node.left.val
        right_child_val = 0 if node.right is None else node.right.val

        if level == 0 or level == 1:
            node.val = 0
        else:
            node.val = self.level_sums[level] - node.val - sibling_sum
        self.replace_value_in_tree_internal(
            node.left, right_child_val, level + 1
        )
        self.replace_value_in_tree_internal(
            node.right, left_child_val, level + 1
        )
```

</details>

<br>

## Approach 3: Single BFS with Running Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int currentLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int nextLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Update node value to cousin sum.
                currentNode->val = currentLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr) {
                    nextLevelSum +=
                        currentNode->left->val;  // Accumulate next level sum.
                    currentNode->left->val =
                        siblingSum;  // Update left child's value.
                    nodeQueue.push(
                        currentNode->left);  // Add to queue for next level.
                }
                if (currentNode->right != nullptr) {
                    nextLevelSum +=
                        currentNode->right->val;  // Accumulate next level sum.
                    currentNode->right->val =
                        siblingSum;  // Update right child's value.
                    nodeQueue.push(
                        currentNode->right);  // Add to queue for next level.
                }
            }

            currentLevelSum = nextLevelSum;  // Update current level sum
                                             // for next iteration.
        }
        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode replaceValueInTree(TreeNode root) {
        if (root == null) {
            return root;
        }

        Queue<TreeNode> nodeQueue = new LinkedList<>();
        nodeQueue.offer(root);
        int currentLevelSum = root.val;

        while (!nodeQueue.isEmpty()) {
            int levelSize = nodeQueue.size();
            int nextLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode currentNode = nodeQueue.poll();
                // Update node value to cousin sum
                currentNode.val = currentLevelSum - currentNode.val;

                // Calculate sibling sum
                int siblingSum =
                    (currentNode.left != null ? currentNode.left.val : 0) +
                    (currentNode.right != null ? currentNode.right.val : 0);

                if (currentNode.left != null) {
                    nextLevelSum += currentNode.left.val; // Accumulate next level sum
                    currentNode.left.val = siblingSum; // Update left child's value
                    nodeQueue.offer(currentNode.left); // Add to queue for next level
                }
                if (currentNode.right != null) {
                    nextLevelSum += currentNode.right.val; // Accumulate next level sum
                    currentNode.right.val = siblingSum; // Update right child's value
                    nodeQueue.offer(currentNode.right); // Add to queue for next level
                }
            }

            currentLevelSum = nextLevelSum; // Update current level sum for next iteration
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def replaceValueInTree(self, root):
        if root is None:
            return root
        node_queue = deque()
        node_queue.append(root)
        current_level_sum = root.val

        while node_queue:
            level_size = len(node_queue)
            next_level_sum = 0

            for _ in range(level_size):
                current_node = node_queue.popleft()
                # Update node value to cousin sum
                current_node.val = current_level_sum - current_node.val

                # Calculate sibling sum
                sibling_sum = (
                    0 if current_node.left is None else current_node.left.val
                ) + (
                    0 if current_node.right is None else current_node.right.val
                )

                if current_node.left is not None:
                    next_level_sum += (
                        current_node.left.val
                    )  # Accumulate next level sum
                    current_node.left.val = (
                        sibling_sum  # Update left child's value
                    )
                    node_queue.append(
                        current_node.left
                    )  # Add to queue for next level
                if current_node.right is not None:
                    next_level_sum += (
                        current_node.right.val
                    )  # Accumulate next level sum
                    current_node.right.val = (
                        sibling_sum  # Update right child's value
                    )
                    node_queue.append(
                        current_node.right
                    )  # Add to queue for next level

            # Update current level sum for next iteration
            current_level_sum = next_level_sum
        return root
```

</details>
