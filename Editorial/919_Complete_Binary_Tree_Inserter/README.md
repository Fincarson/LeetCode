# 919. Complete Binary Tree Inserter

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/complete-binary-tree-inserter/)  
`Tree` `Breadth-First Search` `Design` `Binary Tree`

**Problem Link:** [LeetCode 919 - Complete Binary Tree Inserter](https://leetcode.com/problems/complete-binary-tree-inserter/)

## Problem

A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

- CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
- int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
- TreeNode get_root() Returns the root node of the tree.

### Example 1

```text
Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]
```

## Constraints

- The number of nodes in the tree will be in the range [1, 1000].
- 0 <= Node.val <= 5000
- root is a complete binary tree.
- 0 <= val <= 5000
- At most 104 calls will be made to insert and get_root.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 919. Complete Binary Tree Inserter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Deque | Java, Python |

## Approach 1: Deque

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class CBTInserter {
    TreeNode root;
    Deque<TreeNode> deque;
    public CBTInserter(TreeNode root) {
        this.root = root;
        deque = new LinkedList();
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);

        // BFS to populate deque
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left == null || node.right == null)
                deque.offerLast(node);
            if (node.left != null)
                queue.offer(node.left);
            if (node.right != null)
                queue.offer(node.right);
        }
    }

    public int insert(int v) {
        TreeNode node = deque.peekFirst();
        deque.offerLast(new TreeNode(v));
        if (node.left == null)
            node.left = deque.peekLast();
        else {
            node.right = deque.peekLast();
            deque.pollFirst();
        }

        return node.val;
    }

    public TreeNode get_root() {
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class CBTInserter(object):
    def __init__(self, root):
        self.deque = collections.deque()
        self.root = root
        q = collections.deque([root])
        while q:
            node = q.popleft()
            if not node.left or not node.right:
                self.deque.append(node)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

    def insert(self, v):
        node = self.deque[0]
        self.deque.append(TreeNode(v))
        if not node.left:
            node.left = self.deque[-1]
        else:
            node.right = self.deque[-1]
            self.deque.popleft()
        return node.val

    def get_root(self):
        return self.root
```

</details>
