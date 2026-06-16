# 513. Find Bottom Left Tree Value

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-bottom-left-tree-value/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 513 - Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/)

## Problem

Given the root of a binary tree, return the leftmost value in the last row of the tree.

### Example 1

```text
Input: root = [2,1,3]
Output: 1
```

### Example 2

```text
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -231 <= Node.val <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 513. Find Bottom Left Tree Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Breadth-First Search Right to Left | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        bottomLeftValue = 0;
        dfs(root, 0);
        return bottomLeftValue;
    }

private:
    int maxDepth;
    int bottomLeftValue;

    void dfs(TreeNode* current, int depth) {
        if (current == nullptr) {
            return;
        }
        if (depth > maxDepth) {  // If true, we discovered a new level
            maxDepth = depth;
            bottomLeftValue = current->val;
        }
        dfs(current->left, depth + 1);
        dfs(current->right, depth + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int maxDepth;
    private int bottomLeftValue;

    public int findBottomLeftValue(TreeNode root) {
        maxDepth = -1;
        bottomLeftValue = 0;
        dfs(root, 0);
        return bottomLeftValue;
    }

    private void dfs(TreeNode current, int depth) {
        if (current == null) {
            return;
        }
        if (depth > maxDepth) {  // If true, we discovered a new level
            maxDepth = depth;
            bottomLeftValue = current.val;
        }
        dfs(current.left, depth + 1);
        dfs(current.right, depth + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        self.maxDepth = -1
        self.bottomLeftValue = 0
        self.dfs(root, 0)
        return self.bottomLeftValue

    def dfs(self, current: TreeNode, depth: int):
        if not current:
            return
        
        if depth > self.maxDepth:  # If true, we discovered a new level
            self.maxDepth = depth
            self.bottomLeftValue = current.val

        self.dfs(current.left, depth + 1)
        self.dfs(current.right, depth + 1)
        return
```

</details>

<br>

## Approach 2: Breadth-First Search Right to Left

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue;
        TreeNode* current = root;
        queue.push(current);

        while (!queue.empty()) {
            current = queue.front();
            queue.pop();
            if (current->right != nullptr) {
                queue.push(current->right);
            }
            if (current->left != nullptr) {
                queue.push(current->left);
            }
        }
        return current->val;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode current = root;
        queue.add(current);

        while (!queue.isEmpty()) {
            current = queue.poll();
            if (current.right != null) {
                queue.add(current.right);
            }
            if (current.left != null) {
                queue.add(current.left);
            }
        }
        return current.val;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findBottomLeftValue(self, root):
        queue = deque()
        current = root
        queue.append(current)

        while queue:
            current = queue.popleft()

            if current.right:
                queue.append(current.right)

            if current.left:
                queue.append(current.left)

        return current.val
```

</details>
