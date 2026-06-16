# 1490. Clone N-ary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/clone-n-ary-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 1490 - Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree/)

## Problem

Given a root of an N-ary tree, return a deep copy (clone) of the tree.

Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.

```text
class Node {
    public int val;
    public List<Node> children;
}
```

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

## Constraints

- The depth of the n-ary tree is less than or equal to 1000.
- The total number of nodes is between [0, 104].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Clone Graph](https://leetcode.com/problems/clone-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1490. Clone N-ary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python3 |
| DFS with Iteration | Java, Python3 |
| BFS | Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node cloneTree(Node root) {
        // Base case: empty node.
        if (root == null) {
            return root;
        }

        // First, copy the node itself.
        Node nodeCopy = new Node(root.val);

        // Then, recursively clone the sub-trees.
        for (Node child : root.children) {
            nodeCopy.children.add(this.cloneTree(child));
        }

        return nodeCopy;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':

        # Base case: empty node.
        if not root:
            return root

        # First, copy the node itself.
        node_copy = Node(root.val)

        # Then, recursively clone the sub-trees.
        for child in root.children:
            node_copy.children.append(self.cloneTree(child))

        return node_copy
```

</details>

<br>

## Approach 2: DFS with Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node cloneTree(Node root) {
        if (root == null) {
            return root;
        }

        Node newRoot = new Node(root.val);
        // Here we used the ArrayDeque instead of the Queue class,
        //   which is a more efficient implementation of queue data structure.
        Deque<Node[]> stack = new ArrayDeque<>();

        // Starting point to kick off the DFS visits.
        stack.addLast(new Node[]{root, newRoot});

        while (!stack.isEmpty()) {
            Node[] nodePair = stack.pop();
            Node oldNode = nodePair[0];
            Node newNode = nodePair[1];
            for (Node childNode : oldNode.children) {
                Node newChildNode = new Node(childNode.val);

                // Make a copy for each child node.
                newNode.children.add(newChildNode);

                // Schedule a visit to copy the child nodes of each child node.
                stack.push(new Node[]{childNode, newChildNode});
            }
        }

        return newRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':

        if not root:
            return root

        new_root = Node(root.val)
        # Starting point to kick off the DFS visits.
        stack = [(root, new_root)]

        while stack:
            old_node, new_node = stack.pop()
            for child_node in old_node.children:
                new_child_node = Node(child_node.val)

                # Make a copy for each child node.
                new_node.children.append(new_child_node)

                # Schedule a visit to copy the child nodes of each child node.
                stack.append((child_node, new_child_node))

        return new_root
```

</details>

<br>

## Approach 3: BFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node cloneTree(Node root) {
        if (root == null) {
            return root;
        }

        Node newRoot = new Node(root.val);

        // Starting point to kick off the BFS visits.
        // Here we used the ArrayDeque instead of the Queue class,
        //   which is a more efficient implementation of queue data structure.
        Deque<Node[]> queue = new ArrayDeque<>();
        queue.addLast(new Node[]{root, newRoot});

        while (!queue.isEmpty()) {
            Node[] nodePair = queue.removeFirst();

            Node oldNode = nodePair[0];
            Node newNode = nodePair[1];
            for (Node childNode : oldNode.children) {
                Node newChildNode = new Node(childNode.val);

                // Make a copy for each child node.
                newNode.children.add(newChildNode);

                // Schedule a visit to copy the child nodes of each child node.
                queue.addLast(new Node[]{childNode, newChildNode});
            }
        }

        return newRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':

        if not root:
            return root

        new_root = Node(root.val)
        # Starting point to kick off the BFS visits.
        queue = deque([(root, new_root)])

        while queue:
            # Get the element from the head of the queue.
            old_node, new_node = queue.popleft()

            for child_node in old_node.children:
                new_child_node = Node(child_node.val)

                # Make a copy for each child node.
                new_node.children.append(new_child_node)

                # Schedule a visit to copy the child nodes of each child node.
                queue.append((child_node, new_child_node))

        return new_root
```

</details>
