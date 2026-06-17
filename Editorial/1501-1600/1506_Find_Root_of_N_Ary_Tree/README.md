# 1506. Find Root of N-Ary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-root-of-n-ary-tree/)  
`Hash Table` `Bit Manipulation` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 1506 - Find Root of N-Ary Tree](https://leetcode.com/problems/find-root-of-n-ary-tree/)

## Problem

You are given all the nodes of an N-ary tree as an array of Node objects, where each node has a unique value.

Return the root of the N-ary tree.

Custom testing:

An N-ary tree can be serialized as represented in its level order traversal where each group of children is separated by the null value (see examples).

For example, the above tree is serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

The testing will be done in the following way:

### Example 1

```text
Input: tree = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]
Explanation: The tree from the input data is shown above.
The driver code creates the tree and gives findRoot the Node objects in an arbitrary order.
For example, the passed array could be [Node(5),Node(4),Node(3),Node(6),Node(2),Node(1)] or [Node(2),Node(6),Node(1),Node(3),Node(5),Node(4)].
The findRoot function should return the root Node(1), and the driver code will serialize it and compare with the input data.
The input data and serialized Node(1) are the same, so the test passes.
```

### Example 2

```text
Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
```

## Constraints

- The total number of nodes is between [1, 5 * 104].
- Each node has a unique value.

Follow up:

- Could you solve this problem in constant space complexity with a linear time algorithm?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Move Sub-Tree of N-Ary Tree](https://leetcode.com/problems/move-sub-tree-of-n-ary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1506. Find Root of N-Ary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DÃƒÂ©jÃƒÂ -Vu (_O(N)_ Space) | Java, Python3 |
| YOLO (You Only Look Once) | Java, Python3 |

## Approach 1: DÃƒÂ©jÃƒÂ -Vu (_O(N)_ Space)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node findRoot(List<Node> tree) {
        // set that contains all the child nodes.
        HashSet<Integer> seen = new HashSet<Integer>();

        // add all the child nodes into the set
        for (Node node : tree) {
            for (Node child : node.children)
                // we could either add the value or the node itself.
                seen.add(child.val);
        }

        Node root = null;
        // find the node that is not in the child node set.
        for (Node node : tree) {
            if (!seen.contains(node.val)) {
                root = node;
                break;
            }
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""
class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        # set that contains all the child nodes.
        seen = set()

        # add all the child nodes into the set
        for node in tree:
            for child in node.children:
                # we could either add the value or the node itself.
                seen.add(child.val)

        # find the node that is not in the child node set.
        for node in tree:
            if node.val not in seen:
                return node
```

</details>

<br>

## Approach 2: YOLO (You Only Look Once)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node findRoot(List<Node> tree) {

        Integer valueSum = 0;

        for (Node node : tree) {
            // the value is added as a parent node
            valueSum += node.val;
            for (Node child : node.children)
                // the value is deducted as a child node.
                valueSum -= child.val;
        }

        Node root = null;
        // the value of the root node is `valueSum`
        for (Node node : tree) {
            if (node.val == valueSum) {
                root = node;
                break;
            }
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        value_sum = 0

        for node in tree:
            # the value is added as a parent node
            value_sum += node.val
            for child in node.children:
                # the value is deducted as a child node.
                value_sum -= child.val

        # the value of the root node is `value_sum`
        for node in tree:
            if node.val == value_sum:
                return node
```

</details>
