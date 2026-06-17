# 559. Maximum Depth of N-ary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search`

**Problem Link:** [LeetCode 559 - Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)

## Problem

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
```

## Constraints

- The total number of nodes is in the range [0, 104].
- The depth of the n-ary tree is less than or equal to 1000.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Good Nodes](https://leetcode.com/problems/count-the-number-of-good-nodes/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 559. Maximum Depth of N-ary Tree

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
  public int maxDepth(Node root) {
    if (root == null) {
      return 0;
    } else if (root.children.isEmpty()) {
      return 1;  
    } else {
      List<Integer> heights = new LinkedList<>();
      for (Node item : root.children) {
        heights.add(maxDepth(item)); 
      }
      return Collections.max(heights) + 1;
    }
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if root is None: 
            return 0 
        elif root.children == []:
            return 1
        else: 
            height = [self.maxDepth(c) for c in root.children]
            return max(height) + 1
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int maxDepth(Node root) {
    Queue<Pair<Node, Integer>> stack = new LinkedList<>();
    if (root != null) {
      stack.add(new Pair(root, 1));
    }

    int depth = 0;
    while (!stack.isEmpty()) {
      Pair<Node, Integer> current = stack.poll();
      root = current.getKey();
      int current_depth = current.getValue();
      if (root != null) {
        depth = Math.max(depth, current_depth);
        for (Node c : root.children) {
          stack.add(new Pair(c, current_depth + 1));    
        }
      }
    }
    return depth;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """ 
        stack = []
        if root is not None:
            stack.append((1, root))
        
        depth = 0
        while stack != []:
            current_depth, root = stack.pop()
            if root is not None:
                depth = max(depth, current_depth)
                for c in root.children:
                    stack.append((current_depth + 1, c))
                
        return depth
```

</details>
