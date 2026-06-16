# 662. Maximum Width of Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-width-of-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 662 - Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

## Problem

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

### Example 1

```text
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
```

### Example 2

```text
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
```

### Example 3

```text
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```

## Constraints

- The number of nodes in the tree is in the range [1, 3000].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 662. Maximum Width of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS Traversal | Java, Python3 |
| DFS Traversal | Java, Python3 |

## Approach 1: BFS Traversal

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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;

        // The queue of elements [(node, col_index)]
        LinkedList<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        Integer maxWidth = 0;

        queue.addLast(new Pair<>(root, 0));
        while (queue.size() > 0) {
            Pair<TreeNode, Integer> head = queue.getFirst();

            // Iterate through the current level
            Integer currLevelSize = queue.size();
            Pair<TreeNode, Integer> elem = null;
            for (int i = 0; i < currLevelSize; ++i) {
                elem = queue.removeFirst();
                TreeNode node = elem.getKey();
                if (node.left != null)
                    queue.addLast(new Pair<>(node.left, 2 * elem.getValue()));
                if (node.right != null)
                    queue.addLast(new Pair<>(node.right, 2 * elem.getValue() + 1));
            }

            // Calculate the length of the current level,
            // by comparing the first and last col_index.
            maxWidth = Math.max(maxWidth, elem.getValue() - head.getValue() + 1);
        }

        return maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0

        max_width = 0

        # The queue of elements [(node, col_index)]
        queue = deque()
        queue.append((root, 0))

        while queue:
            level_length = len(queue)
            _, level_head_index = queue[0]

            # Iterate through the current level
            for _ in range(level_length):
                node, col_index = queue.popleft()

                # Prepare for the next level
                if node.left:
                    queue.append((node.left, 2 * col_index))
                if node.right:
                    queue.append((node.right, 2 * col_index + 1))

            # Calculate the length of the current level,
            # by comparing the first and last col_index.
            max_width = max(max_width, col_index - level_head_index + 1)

        return max_width
```

</details>

<br>

## Approach 2: DFS Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Integer maxWidth = 0;
    private HashMap<Integer, Integer> firstColIndexTable;

    protected void DFS(TreeNode node, Integer depth, Integer colIndex) {
        if (node == null)
            return;
        // Initialize the value, for the first seen colIndex per level
        if (!firstColIndexTable.containsKey(depth)) {
            firstColIndexTable.put(depth, colIndex);
        }
        Integer firstColIndex = firstColIndexTable.get(depth);

        maxWidth = Math.max(this.maxWidth, colIndex - firstColIndex + 1);

        // Preorder DFS. Note: it is important to put the priority on the left child
        DFS(node.left, depth + 1, 2 * colIndex);
        DFS(node.right, depth + 1, 2 * colIndex + 1);
    }

    public int widthOfBinaryTree(TreeNode root) {
        // The table contains the first col_index for each level
        this.firstColIndexTable = new HashMap<Integer, Integer>();

        // Start with depth = 0, and colIndex = 0
        DFS(root, 0, 0);

        return this.maxWidth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:

        # The table contains the first col_index for each level
        first_col_index_table = {}
        max_width = 0

        def DFS(node, depth, col_index):
            nonlocal max_width
            if node is None:
                return
            # If the entry is empty, set the value
            if depth not in first_col_index_table:
                first_col_index_table[depth] = col_index

            max_width = max(max_width, col_index - first_col_index_table[depth] + 1)

            # Preorder DFS, with the priority on the left child
            DFS(node.left, depth+1, 2*col_index)
            DFS(node.right, depth+1, 2*col_index + 1)

        DFS(root, 0, 0)

        return max_width
```

</details>
