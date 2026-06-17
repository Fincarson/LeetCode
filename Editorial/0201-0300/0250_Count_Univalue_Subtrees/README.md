# 250. Count Univalue Subtrees

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-univalue-subtrees/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 250 - Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/)

## Problem

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

### Example 1

```text
Input: root = [5,1,5,5,5,null,5]
Output: 4
```

### Example 2

```text
Input: root = []
Output: 0
```

### Example 3

```text
Input: root = [5,5,5,5,5,null,5]
Output: 6
```

## Constraints

- The number of the node in the tree will be in the range [0, 1000].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 250. Count Univalue Subtrees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| Depth First Search Without Using The Global Variable | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int count = 0;

    bool dfs(TreeNode* node) {
        if (node == nullptr) {
            return true;
        }

        bool isLeftUniValue = dfs(node->left);
        bool isRightUniValue = dfs(node->right);

        // If both the children form uni-value subtrees, we compare the value of
        // chidren's node with the node value.
        if (isLeftUniValue && isRightUniValue) {
            if (node->left != nullptr && node->left->val != node->val) {
                return false;
            }
            if (node->right != nullptr && node->right->val != node->val) {
                return false;
            }
            count++;
            return true;
        }
        // Else if any of the child does not form a uni-value subtree, the subtree
        // rooted at node cannot be a uni-value subtree.
        return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;

    public boolean dfs(TreeNode node) {
        if (node == null) {
            return true;
        }

        boolean left = dfs(node.left);
        boolean right = dfs(node.right);

        // If both the children form uni-value subtrees, we compare the value of
        // chidren's node with the node value.
        if (left && right) {
            if (node.left != null && node.left.val != node.val) {
                return false;
            }
            if (node.right != null && node.right.val != node.val) {
                return false;
            }
            count++;
            return true;
        }
        // Else if any of the child does not form a uni-value subtree, the subtree
        // rooted at node cannot be a uni-value subtree.
        return false;
    }

    public int countUnivalSubtrees(TreeNode root) {
        dfs(root);
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        self.count = 0

        def dfs(node):
            if node is None:
                return True

            isLeftUniValue = dfs(node.left)
            isRightUniValue = dfs(node.right)

            # If both the children form uni-value subtrees, we compare the value of
            # chidrens node with the node value.
            if isLeftUniValue and isRightUniValue:
                if node.left and node.val != node.left.val:
                    return False
                if node.right and node.val != node.right.val:
                    return False
    
                self.count += 1
                return True
            # Else if any of the child does not form a uni-value subtree, the subtree
            # rooted at node cannot be a uni-value subtree.
            return False
        
        dfs(root)
        return self.count
```

</details>

<br>

## Approach 2: Depth First Search Without Using The Global Variable

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    pair<bool, int> dfs(TreeNode* node) {
        if (!node) {
            return {true, 0};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);
        bool isLeftUniValue = left.first;
        bool isRightUniValue = right.first;
        int count = left.second + right.second;

        // If both the children form uni-value subtrees, we compare the value of
        // chidrens node with the node value.
        if (isLeftUniValue && isRightUniValue) {
            if (node->left && node->val != node->left->val) {
                return {false, count};
            }
            if (node->right && node->val != node->right->val) {
                return {false, count};
            }
            return {true, count + 1};
        }
        // Else if any of the child does not form a uni-value subtree, the subtree
        // rooted at node cannot be a uni-value subtree.
        return {false, count};
    }

    int countUnivalSubtrees(TreeNode* root) {
        return dfs(root).second;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Pair<Boolean, Integer> dfs(TreeNode node) {
        if (node == null) {
            return new Pair<>(true, 0);
        }
        
        Pair<Boolean, Integer> left = dfs(node.left);
        Pair<Boolean, Integer> right = dfs(node.right);
        boolean isLeftUniValue = left.getKey();
        boolean isRightUniValue = right.getKey();
        int count = left.getValue() + right.getValue();
        
        // If both the children form uni-value subtrees, we compare the value of
        // chidrens node with the node value.
        if (isLeftUniValue && isRightUniValue) {
            if (node.left != null && node.val != node.left.val) {
                return new Pair<>(false, count);
            }
            if (node.right != null && node.val != node.right.val) {
                return new Pair<>(false, count);
            }
            count++;
            return new Pair<>(true, count);
        }
        // Else if any of the child does not form a uni-value subtree, the subtree
        // rooted at node cannot be a uni-value subtree.
        return new Pair<>(false, count);
    }
    
    public int countUnivalSubtrees(TreeNode root) {
        return dfs(root).getValue();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if node is None:
                return True, 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            isLeftUniValue = left[0]
            isRightUniValue = right[0]
            count = left[1] + right[1]
            # If both the children form uni-value subtrees, we compare the value of
            # chidrens node with the node value.
            if isLeftUniValue and isRightUniValue:
                if node.left and node.val != node.left.val:
                    return False, count
                if node.right and node.val != node.right.val:
                    return False, count

                return True, count + 1
            # Else if any of the child does not form a uni-value subtree, the subtree
            # rooted at node cannot be a uni-value subtree.
            return False, count
        
        return dfs(root)[1]
```

</details>
