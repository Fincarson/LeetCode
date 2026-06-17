# 1302. Deepest Leaves Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/deepest-leaves-sum/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1302 - Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)

## Problem

### Example 1

```text
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

### Example 2

```text
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1302. Deepest Leaves Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative DFS Preorder Traversal. | Java, Python3 |
| Iterative BFS Traversal. | Java, Python3 |
| Optimized Iterative BFS Traversal. | Java, Python3 |

## Approach 1: Iterative DFS Preorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int deepestLeavesSum(TreeNode root) {
    int deepestSum = 0, depth = 0, currDepth;
    Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque();
    stack.push(new Pair(root, 0));

    while (!stack.isEmpty()) {
      Pair<TreeNode, Integer> p = stack.pop();
      root = p.getKey();
      currDepth = p.getValue();

      if (root.left == null && root.right == null) {
        // if this leaf is the deepest one seen so far
        if (depth < currDepth) {
          deepestSum = root.val;      // start new sum
          depth = currDepth;          // note new depth    
        } else if (depth == currDepth) {
          // if there were already leaves at this depth
          deepestSum += root.val;     // update existing sum    
        }
      } else {
        if (root.right != null) {
          stack.push(new Pair(root.right, currDepth + 1));
        }
        if (root.left != null) {
          stack.push(new Pair(root.left, currDepth + 1));
        }
      }
    }
    return deepestSum;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        deepest_sum = depth = 0
        stack = [(root, 0) ]
        
        while stack:
            node, curr_depth = stack.pop()
            if node.left is None and node.right is None:
                # if this leaf is the deepest one seen so far
                if depth < curr_depth:
                    deepest_sum = node.val      # start new sum
                    depth = curr_depth          # note new depth
                # if there were already leaves at this depth
                elif depth == curr_depth:
                    deepest_sum += node.val     # update existing sum
                    
            else:
                if node.right:
                    stack.append((node.right, curr_depth + 1))
                if node.left:
                    stack.append((node.left, curr_depth + 1))
                        
        return deepest_sum
```

</details>

<br>

## Approach 2: Iterative BFS Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int deepestLeavesSum(TreeNode root) {
    int deepestSum = 0, depth = 0, currDepth;
    Deque<Pair<TreeNode, Integer>> queue = new ArrayDeque();
    queue.offer(new Pair(root, 0));

    while (!queue.isEmpty()) {
      Pair<TreeNode, Integer> p = queue.poll();
      root = p.getKey();
      currDepth = p.getValue();

      if (root.left == null && root.right == null) {
        // if this leaf is the deepest one seen so far
        if (depth < currDepth) {
          deepestSum = root.val;      // start new sum
          depth = currDepth;          // note new depth    
        } else if (depth == currDepth) {
          // if there were already leaves at this depth
          deepestSum += root.val;     // update existing sum    
        }
      } else {
        if (root.left != null) {
          queue.offer(new Pair(root.left, currDepth + 1));
        }
        if (root.right != null) {
          queue.offer(new Pair(root.right, currDepth + 1));
        }
      }
    }
    return deepestSum;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        deepest_sum = depth = 0
        queue = deque([(root, 0),])

        while queue:
            node, curr_depth = queue.popleft()
            if node.left is None and node.right is None:
                # if this leaf is the deepest one seen so far
                if depth < curr_depth:
                    deepest_sum = node.val      # start new sum
                    depth = curr_depth          # note new depth
                # if there were already leaves at this depth
                elif depth == curr_depth:
                    deepest_sum += node.val     # update existing sum    
            else:
                if node.left:
                    queue.append((node.left, curr_depth + 1))
                if node.right:
                    queue.append((node.right, curr_depth + 1))
                        
        return deepest_sum
```

</details>

<br>

## Approach 3: Optimized Iterative BFS Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int deepestLeavesSum(TreeNode root) {
    ArrayDeque<TreeNode>  nextLevel = new ArrayDeque(),
                          currLevel = new ArrayDeque();
    nextLevel.offer(root);

    while (!nextLevel.isEmpty()) {
      // prepare for the next level
      currLevel = nextLevel.clone();
      nextLevel.clear();

      for (TreeNode node: currLevel) {
        // add child nodes of the current level
        // in the queue for the next level
        if (node.left != null) {
          nextLevel.offer(node.left);
        }
        if (node.right != null) {
          nextLevel.offer(node.right);
        }
      }
    }
    int deepestSum = 0;
    for (TreeNode node: currLevel) {
      deepestSum += node.val;
    }
    return deepestSum;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        next_level = deque([root,])
        
        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()
            
            for node in curr_level:
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
        
        return sum([node.val for node in curr_level])
```

</details>
