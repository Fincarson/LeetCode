# 971. Flip Binary Tree To Match Preorder Traversal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 971 - Flip Binary Tree To Match Preorder Traversal](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)

## Problem

You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:

Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].

### Example 1

```text
Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
```

### Example 2

```text
Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.
```

### Example 3

```text
Input: root = [1,2,3], voyage = [1,2,3]
Output: []
Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.
```

## Constraints

- The number of nodes in the tree is n.
- n == voyage.length
- 1 <= n <= 100
- 1 <= Node.val, voyage[i] <= n
- All the values in the tree are unique.
- All the values in voyage are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 971. Flip Binary Tree To Match Preorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | Java, Python |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<Integer> flipped;
    int index;
    int[] voyage;

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        flipped = new ArrayList();
        index = 0;
        this.voyage = voyage;

        dfs(root);
        if (!flipped.isEmpty() && flipped.get(0) == -1) {
            flipped.clear();
            flipped.add(-1);
        }

        return flipped;
    }

    public void dfs(TreeNode node) {
        if (node != null) {
            if (node.val != voyage[index++]) {
                flipped.clear();
                flipped.add(-1);
                return;
            }

            if (index < voyage.length && node.left != null &&
                    node.left.val != voyage[index]) {
                flipped.add(node.val);
                dfs(node.right);
                dfs(node.left);
            } else {
                dfs(node.left);
                dfs(node.right);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def flipMatchVoyage(self, root, voyage):
        self.flipped = []
        self.i = 0

        def dfs(node):
            if node:
                if node.val != voyage[self.i]:
                    self.flipped = [-1]
                    return
                self.i += 1

                if (self.i < len(voyage) and
                        node.left and node.left.val != voyage[self.i]):
                    self.flipped.append(node.val)
                    dfs(node.right)
                    dfs(node.left)
                else:
                    dfs(node.left)
                    dfs(node.right)

        dfs(root)
        if self.flipped and self.flipped[0] == -1:
            self.flipped = [-1]
        return self.flipped
```

</details>
