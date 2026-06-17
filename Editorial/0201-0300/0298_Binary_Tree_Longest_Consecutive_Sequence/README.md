# 298. Binary Tree Longest Consecutive Sequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 298 - Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

## Problem

Given the root of a binary tree, return the length of the longest consecutive sequence path.

A consecutive sequence path is a path where the values increase by one along the path.

Note that the path can start at any node in the tree, and you cannot go from a node to its parent in the path.

### Example 1

```text
Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
```

### Example 2

```text
Input: root = [2,null,3,2,null,1]
Output: 2
Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
```

## Constraints

- The number of nodes in the tree is in the range [1, 3 * 104].
- -3 * 104 <= Node.val <= 3 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Tree Longest Consecutive Sequence II](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check if an Array Is Consecutive](https://leetcode.com/problems/check-if-an-array-is-consecutive/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 298. Binary Tree Longest Consecutive Sequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 (Top Down Depth-first Search) [Accepted] | Java |
| Approach #2 (Bottom Up Depth-first Search) [Accepted] | Java |

## Approach #1 (Top Down Depth-first Search) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int maxLength = 0;
public int longestConsecutive(TreeNode root) {
    dfs(root, null, 0);
    return maxLength;
}

private void dfs(TreeNode p, TreeNode parent, int length) {
    if (p == null) return;
    length = (parent != null && p.val == parent.val + 1) ? length + 1 : 1;
    maxLength = Math.max(maxLength, length);
    dfs(p.left, p, length);
    dfs(p.right, p, length);
}
```

</details>

<br>

## Approach #2 (Bottom Up Depth-first Search) [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
private int maxLength = 0;
public int longestConsecutive(TreeNode root) {
    dfs(root);
    return maxLength;
}

private int dfs(TreeNode p) {
    if (p == null) return 0;
    int L = dfs(p.left) + 1;
    int R = dfs(p.right) + 1;
    if (p.left != null && p.val + 1 != p.left.val) {
        L = 1;
    }
    if (p.right != null && p.val + 1 != p.right.val) {
        R = 1;
    }
    int length = Math.max(L, R);
    maxLength = Math.max(maxLength, length);
    return length;
}
```

</details>
