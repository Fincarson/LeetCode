# 872. Leaf-Similar Trees

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/leaf-similar-trees/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 872 - Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)

## Problem

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

### Example 1

```text
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
```

### Example 2

```text
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

## Constraints

- The number of nodes in each tree will be in the range [1, 200].
- Both of the given trees will have values in the range [0, 200].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 872. Leaf-Similar Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, JavaScript, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaves1 = new ArrayList();
        List<Integer> leaves2 = new ArrayList();
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return leaves1.equals(leaves2);
    }

    public void dfs(TreeNode node, List<Integer> leafValues) {
        if (node != null) {
            if (node.left == null && node.right == null)
                leafValues.add(node.val);
            dfs(node.left, leafValues);
            dfs(node.right, leafValues);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var leafSimilar = function(root1, root2) {
    dfs = function(node, leaves) {
        if (node != null) {
            if (node.left == null && node.right == null) {
                leaves.push(node.val);
            }
            dfs(node.left, leaves);
            dfs(node.right, leaves);
        }
    }
    let leaves1 = [];
    let leaves2 = [];
    dfs(root1, leaves1);
    dfs(root2, leaves2);

    return (leaves1.length == leaves2.length &&
            leaves1.every((v, i) => v === leaves2[i]));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def leafSimilar(self, root1, root2):
        def dfs(node):
            if node:
                if not node.left and not node.right:
                    yield node.val
                yield from dfs(node.left)
                yield from dfs(node.right)

        return list(dfs(root1)) == list(dfs(root2))
```

</details>
