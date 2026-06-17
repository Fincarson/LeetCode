# 426. Convert Binary Search Tree to Sorted Doubly Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)  
`Linked List` `Stack` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree` `Doubly-Linked List`

**Problem Link:** [LeetCode 426 - Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)

## Problem

Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

### Example 1

```text
Input: root = [4,2,5,1,3]

Output: [1,2,3,4,5]

Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.
```

### Example 2

```text
Input: root = [2,1,3]
Output: [1,2,3]
```

## Constraints

- The number of nodes in the tree is in the range [0, 2000].
- -1000 <= Node.val <= 1000
- All the values of the tree are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 426. Convert Binary Search Tree to Sorted Doubly Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);

      // node 
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;

      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);

    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  // the smallest (first) and the largest (last) nodes
  Node first = null;
  Node last = null;

  public void helper(Node node) {
    if (node != null) {
      // left
      helper(node.left);

      // node 
      if (last != null) {
        // link the previous node (last)
        // with the current one (node)
        last.right = node;
        node.left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;

      // right
      helper(node.right);
    }
  }

  public Node treeToDoublyList(Node root) {
    if (root == null) return null;

    helper(root);

    // close DLL
    last.right = first;
    first.left = last;
    return first;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def helper(node):
            """
            Performs standard inorder traversal:
            left -> node -> right
            and links all nodes into DLL
            """
            nonlocal last, first
            if node:
                # left
                helper(node.left)

                # node 
                if last:
                    # link the previous node (last)
                    # with the current one (node)
                    last.right = node
                    node.left = last
                else:
                    # keep the smallest node
                    # to close DLL later on
                    first = node        
                last = node

                # right
                helper(node.right)
        
        if not root:
            return None
        
        # the smallest (first) and the largest (last) nodes
        first, last = None, None
        helper(root)

        # close DLL
        last.right = first
        first.left = last
        return first
```

</details>
