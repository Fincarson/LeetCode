# 2415. Reverse Odd Levels of Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2415 - Reverse Odd Levels of Binary Tree](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/)

## Problem

Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

- For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].

Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

### Example 1

```text
Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation:
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
```

### Example 2

```text
Input: root = [7,13,11]
Output: [7,11,13]
Explanation:
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
```

### Example 3

```text
Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation:
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
```

## Constraints

- The number of nodes in the tree is in the range [1, 214].
- 0 <= Node.val <= 105
- root is a perfect binary tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2415. Reverse Odd Levels of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Breadth-First Search | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 0);
        return root;
    }

private:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == nullptr || rightChild == nullptr) {
            return;
        }
        // If the current level is odd, swap the values of the children.
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode reverseOddLevels(TreeNode root) {
        traverseDFS(root.left, root.right, 0);
        return root;
    }

    private void traverseDFS(
        TreeNode leftChild,
        TreeNode rightChild,
        int level
    ) {
        if (leftChild == null || rightChild == null) {
            return;
        }
        //If the current level is odd, swap the values of the children.
        if (level % 2 == 0) {
            int temp = leftChild.val;
            leftChild.val = rightChild.val;
            rightChild.val = temp;
        }

        traverseDFS(leftChild.left, rightChild.right, level + 1);
        traverseDFS(leftChild.right, rightChild.left, level + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseOddLevels(self, root) -> TreeNode:
        self.__traverse_DFS(root.left, root.right, 0)
        return root

    def __traverse_DFS(self, left_child, right_child, level):
        if left_child is None or right_child is None:
            return
        # If the current level is odd, swap the values of the children.
        if level % 2 == 0:
            temp = left_child.val
            left_child.val = right_child.val
            right_child.val = temp

        self.__traverse_DFS(left_child.left, right_child.right, level + 1)
        self.__traverse_DFS(left_child.right, right_child.left, level + 1)
```

</details>

<br>

## Approach 2: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;  // Return null if the tree is empty.
        }

        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node.
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentLevelNodes;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root;  // Return the modified tree root.
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode reverseOddLevels(TreeNode root) {
        if (root == null) {
            return null; // Return null if the tree is empty.
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root); // Start BFS with the root node.
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<TreeNode> currentLevelNodes = new ArrayList<>();

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                currentLevelNodes.add(node);

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1) {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currentLevelNodes.get(left).val;
                    currentLevelNodes.get(left).val = currentLevelNodes.get(
                        right
                    ).val;
                    currentLevelNodes.get(right).val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root; // Return the modified tree root.
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseOddLevels(self, root):
        if not root:
            return None  # Return None if the tree is empty.

        queue = [root]  # Start BFS with the root node.
        level = 0

        while queue:
            size = len(queue)
            current_level_nodes = []

            # Process all nodes at the current level.
            for _ in range(size):
                node = queue.pop(0)
                current_level_nodes.append(node)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # Reverse node values if the current level is odd.
            if level % 2 == 1:
                left, right = 0, len(current_level_nodes) - 1
                while left < right:
                    tmp = current_level_nodes[left].val
                    current_level_nodes[left].val = current_level_nodes[
                        right
                    ].val
                    current_level_nodes[right].val = tmp
                    left += 1
                    right -= 1

            level += 1

        return root  # Return the modified tree root.
```

</details>
