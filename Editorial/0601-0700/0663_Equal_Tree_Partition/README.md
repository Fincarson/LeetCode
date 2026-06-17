# 663. Equal Tree Partition

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/equal-tree-partition/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 663 - Equal Tree Partition](https://leetcode.com/problems/equal-tree-partition/)

## Problem

Given the root of a binary tree, return true if you can partition the tree into two trees with equal sums of values after removing exactly one edge on the original tree.

### Example 1

```text
Input: root = [5,10,10,null,null,2,3]
Output: true
```

### Example 2

```text
Input: root = [1,2,10,null,null,2,20]
Output: false
Explanation: You cannot split the tree into two trees with equal sums after removing exactly one edge on the tree.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Create Components With Same Value](https://leetcode.com/problems/create-components-with-same-value/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 663. Equal Tree Partition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Depth-First Search [Accepted] | Java, Python |

## Approach #1: Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Stack<Integer> seen;
    public boolean checkEqualTree(TreeNode root) {
        seen = new Stack();
        int total = sum(root);
        seen.pop();
        if (total % 2 == 0) {
            for (int s: seen) {
                if (s == total / 2) {
                    return true;
                }
            }
        }
        return false;
    }

    public int sum(TreeNode node) {
        if (node == null) {
            return 0; 
        }
        seen.push(sum(node.left) + sum(node.right) + node.val);
        return seen.peek();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def checkEqualTree(self, root):
        seen = []

        def sum_(node):
            if not node:
                return 0
            seen.append(sum_(node.left) + sum_(node.right) + node.val)
            return seen[-1]

        total = sum_(root)
        seen.pop()
        return total / 2.0 in seen
```

</details>
