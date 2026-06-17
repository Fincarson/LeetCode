# 297. Serialize and Deserialize Binary Tree

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)  
`String` `Tree` `Depth-First Search` `Breadth-First Search` `Design` `Binary Tree`

**Problem Link:** [LeetCode 297 - Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

## Problem

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

### Example 1

```text
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

### Example 2

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 297. Serialize and Deserialize Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search (DFS) | Java, Python |

## Approach 1: Depth First Search (DFS)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/* Definition for a binary tree node. */
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class TreeNode(object):
    """ Definition of a binary tree node."""
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

</details>
