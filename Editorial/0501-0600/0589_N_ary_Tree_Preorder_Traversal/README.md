# 589. N-ary Tree Preorder Traversal

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)  
`Stack` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 589 - N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

## Problem

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- 0 <= Node.val <= 104
- The height of the n-ary tree is less than or equal to 1000.

Follow up: Recursive solution is trivial, could you do it iteratively?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 589. N-ary Tree Preorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterations | Java, Python |

## Approach 1: Iterations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// Definition for a Node.
class Node {
  public int val;
  public List<Node> children;

  public Node() {}

  public Node(int _val,List<Node> _children) {
    val = _val;
    children = _children;
  }
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
```

</details>
