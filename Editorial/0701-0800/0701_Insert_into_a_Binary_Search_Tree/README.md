# 701. Insert into a Binary Search Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/insert-into-a-binary-search-tree/)  
`Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 701 - Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

## Problem

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

### Example 1

```text
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:
```

### Example 2

```text
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
```

### Example 3

```text
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
```

## Constraints

- The number of nodes in the tree will be in the range [0, 104].
- -108 <= Node.val <= 108
- All the values Node.val are unique.
- -108 <= val <= 108
- It's guaranteed that val does not exist in the original BST.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 701. Insert into a Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python |
| Iteration | Java, Python |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public TreeNode insertIntoBST(TreeNode root, int val) {
    if (root == null) return new TreeNode(val);

    // insert into the right subtree
    if (val > root.val) root.right = insertIntoBST(root.right, val);
    // insert into the left subtree
    else root.left = insertIntoBST(root.left, val);
    return root;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        
        if val > root.val:
            # insert into the right subtree
            root.right = self.insertIntoBST(root.right, val)
        else:
            # insert into the left subtree
            root.left = self.insertIntoBST(root.left, val)
        return root
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public TreeNode insertIntoBST(TreeNode root, int val) {
    TreeNode node = root;
    while (node != null) {
      // insert into the right subtree
      if (val > node.val) {
        // insert right now
        if (node.right == null) {
          node.right = new TreeNode(val);
          return root;
        }
        else node = node.right;
      }
      // insert into the left subtree
      else {
        // insert right now
        if (node.left == null) {
          node.left = new TreeNode(val);
          return root;
        }
        else node = node.left;
      }
    }
    return new TreeNode(val);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        node = root
        while node:
            # insert into the right subtree
            if val > node.val:
                # insert right now
                if not node.right:
                    node.right = TreeNode(val)
                    return root
                else:
                    node = node.right
            # insert into the left subtree
            else:
                # insert right now
                if not node.left:
                    node.left = TreeNode(val)
                    return root
                else:
                    node = node.left
        return TreeNode(val)
```

</details>
