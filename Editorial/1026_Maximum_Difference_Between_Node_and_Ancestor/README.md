# 1026. Maximum Difference Between Node and Ancestor

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1026 - Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

## Problem

Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

### Example 1

```text
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

### Example 2

```text
Input: root = [1,null,2,null,0,3]
Output: 3
```

## Constraints

- The number of nodes in the tree is in the range [2, 5000].
- 0 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1026. Maximum Difference Between Node and Ancestor

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Recursion | Java, Python3 |
| Approach #2: Maximum Minus Minimum | Java, Python3 |

## Approach #1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // record the required maximum difference
    int result = 0;

    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        result = 0;
        helper(root, root.val, root.val);
        return result;
    }

    void helper(TreeNode node, int curMax, int curMin) {
        if (node == null) {
            return;
        }
        // update `result`
        int possibleResult = Math.max(Math.abs(curMax - node.val), Math.abs(curMin - node.val));
        result = Math.max(result, possibleResult);
        // update the max and min
        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);
        helper(node.left, curMax, curMin);
        helper(node.right, curMax, curMin);
        return;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 0
        # record the required maximum difference
        self.result = 0

        def helper(node, cur_max, cur_min):
            if not node:
                return
            # update `result`
            self.result = max(self.result, abs(cur_max-node.val),
                              abs(cur_min-node.val))
            # update the max and min
            cur_max = max(cur_max, node.val)
            cur_min = min(cur_min, node.val)
            helper(node.left, cur_max, cur_min)
            helper(node.right, cur_max, cur_min)

        helper(root, root.val, root.val)
        return self.result
```

</details>

<br>

## Approach #2: Maximum Minus Minimum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return helper(root, root.val, root.val);
    }

    public int helper(TreeNode node, int curMax, int curMin) {
        //If we encounter leaves, return the max-min along the path
        if (node == null) {
            return curMax - curMin;
        }
        // Otherwise, update max and min
        // and return the max of left and right subtrees
        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);
        int left = helper(node.left, curMax, curMin);
        int right = helper(node.right, curMax, curMin);
        return Math.max(left, right);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if not root:
            return 0

        def helper(node, cur_max, cur_min):
            # if encounter leaves, return the max-min along the path
            if not node:
                return cur_max - cur_min
            # else, update max and min
            # and return the max of left and right subtrees
            cur_max = max(cur_max, node.val)
            cur_min = min(cur_min, node.val)
            left = helper(node.left, cur_max, cur_min)
            right = helper(node.right, cur_max, cur_min)
            return max(left, right)

        return helper(root, root.val, root.val)
```

</details>
