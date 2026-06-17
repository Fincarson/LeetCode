# 1522. Diameter of N-Ary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/diameter-of-n-ary-tree/)  
`Tree` `Depth-First Search`

**Problem Link:** [LeetCode 1522 - Diameter of N-Ary Tree](https://leetcode.com/problems/diameter-of-n-ary-tree/)

## Problem

Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

(Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Explanation: Diameter is shown in red color.
```

### Example 2

```text
Input: root = [1,null,2,null,3,4,null,5,null,6]
Output: 4
```

### Example 3

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 7
```

## Constraints

- The depth of the n-ary tree is less than or equal to 1000.
- The total number of nodes is between [1, 104].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1522. Diameter of N-Ary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Distance with Height | Java, Python3 |
| Distance with Depth | Java, Python3 |

## Approach 1: Distance with Height

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    protected int diameter = 0;

    /**
     * return the height of the node
     */
    protected int height(Node node) {
        if (node.children.size() == 0)
            return 0;

        // select the top two largest heights
        int maxHeight1 = 0, maxHeight2 = 0;
        for (Node child : node.children) {
            int parentHeight = height(child) + 1;
            if (parentHeight > maxHeight1) {
                maxHeight2 = maxHeight1;
                maxHeight1 = parentHeight;
            } else if (parentHeight > maxHeight2) {
                maxHeight2 = parentHeight;
            }
            // calculate the distance between the two farthest leaves nodes.
            int distance = maxHeight1 + maxHeight2;
            this.diameter = Math.max(this.diameter, distance);
        }

        return maxHeight1;
    }

    public int diameter(Node root) {
        this.diameter = 0;
        height(root);
        return diameter;
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
    def diameter(self, root: 'Node') -> int:
        diameter = 0

        def height(node):
            """ return the height of the node """
            nonlocal diameter

            if len(node.children) == 0:
                return 0

            # select the top two heights
            max_height_1, max_height_2 = 0, 0
            for child in node.children:
                parent_height = height(child) + 1
                if parent_height > max_height_1:
                    max_height_1, max_height_2 = parent_height, max_height_1
                elif parent_height > max_height_2:
                    max_height_2 = parent_height

            # calculate the distance between the two farthest leaves nodes.
            distance = max_height_1 + max_height_2
            diameter = max(diameter, distance)

            return max_height_1

        height(root)
        return diameter
```

</details>

<br>

## Approach 2: Distance with Depth

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    protected int diameter = 0;

    /**
     * return the maximum depth of leaves nodes descending from the given node
     */
    protected int maxDepth(Node node, int currDepth) {
        if (node.children.size() == 0)
            return currDepth;

        // select the top two largest depths
        int maxDepth1 = currDepth, maxDepth2 = 0;
        for (Node child : node.children) {
            int depth = maxDepth(child, currDepth + 1);
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
            // calculate the distance between the two farthest leaves nodes.
            int distance = maxDepth1 + maxDepth2 - 2 * currDepth;
            this.diameter = Math.max(this.diameter, distance);
        }

        return maxDepth1;
    }

    public int diameter(Node root) {
        this.diameter = 0;
        maxDepth(root, 0);
        return diameter;
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
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """
        diameter = 0

        def maxDepth(node, curr_depth):
            """ return the maximum depth of leaves nodes
                 descending from the current node
            """
            nonlocal diameter

            if len(node.children) == 0:
                return curr_depth
            
            # select the top 2 depths from its children
            max_depth_1, max_depth_2 = curr_depth, 0
            for child in node.children:
                depth = maxDepth(child, curr_depth+1)
                if depth > max_depth_1:
                    max_depth_1, max_depth_2 = depth, max_depth_1
                elif depth > max_depth_2:
                    max_depth_2 = depth

            # calculate the distance between the two farthest leaves nodes
            distance = max_depth_1 + max_depth_2 - 2 * curr_depth
            diameter = max(diameter, distance)

            return max_depth_1

        maxDepth(root, 0)
        return diameter
```

</details>
