# 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1379 - Find a Corresponding Node of a Binary Tree in a Clone of That Tree](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)

## Problem

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

### Example 1

```text
Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.
```

### Example 2

```text
Input: tree = [7], target =  7
Output: 7
```

### Example 3

```text
Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- The values of the nodes of the tree are unique.
- target node is a node from the original tree and is not null.

Follow up: Could you solve the problem if repeated values on the tree are allowed?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS: Recursive Inorder Traversal. | Java, Python3 |
| DFS: Iterative Inorder Traversal. | Java, Python3 |
| BFS: Iterative Traversal. | Java, Python3 |

## Approach 1: DFS: Recursive Inorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    TreeNode ans, target;
    
    public void inorder(TreeNode o, TreeNode c) {
        if (o != null) {
            inorder(o.left, c.left);
            if (o == target) {
                ans = c;    
            }
            inorder(o.right, c.right);    
        }
    }
    
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        this.target = target;
        inorder(original, cloned);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def inorder(o: TreeNode, c: TreeNode):
            if o:
                inorder(o.left, c.left)
                if o is target:
                    self.ans = c
                inorder(o.right, c.right)
                
        inorder(original, cloned)
        return self.ans
```

</details>

<br>

## Approach 2: DFS: Iterative Inorder Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        Deque<TreeNode> stack_o = new ArrayDeque();
        Deque<TreeNode> stack_c = new ArrayDeque();
        TreeNode node_o = original, node_c = cloned;

        while (!stack_o.isEmpty() || node_o != null) {
            while (node_o != null) {
                stack_o.add(node_o);
                stack_c.add(node_c);

                node_o = node_o.left;
                node_c = node_c.left;
            }
            node_o = stack_o.removeLast();
            node_c = stack_c.removeLast();
            if (node_o == target) {
                return node_c;
            }
            node_o = node_o.right;
            node_c = node_c.right;
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        stack_o, stack_c = [], []
        node_o, node_c = original, cloned
        
        while stack_o or node_c:
            while node_o:
                stack_o.append(node_o)
                stack_c.append(node_c)
                
                node_o = node_o.left
                node_c = node_c.left
                
            node_o = stack_o.pop()
            node_c = stack_c.pop()
            
            if node_o is target:
                return node_c
            
            node_o = node_o.right
            node_c = node_c.right
```

</details>

<br>

## Approach 3: BFS: Iterative Traversal.

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        Deque<TreeNode> queue_o = new ArrayDeque();
        queue_o.offer(original);
        
        Deque<TreeNode> queue_c = new ArrayDeque();
        queue_c.offer(cloned);

        while (!queue_o.isEmpty()) {
            TreeNode node_o = queue_o.poll();
            TreeNode node_c = queue_c.poll();
            
            if (node_o == target) {
                return node_c;   
            }
            
            if (node_o.left != null) {
                queue_o.offer(node_o.left);
                queue_c.offer(node_c.left);
            }
            if (node_o.right != null) {
                queue_o.offer(node_o.right);
                queue_c.offer(node_c.right);
            }
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        queue_o = deque([original,])
        queue_c = deque([cloned,])

        while queue_o:
            node_o = queue_o.popleft()
            node_c = queue_c.popleft()
            
            if node_o is target:
                return node_c

            if node_o:
                queue_o.append(node_o.left)
                queue_o.append(node_o.right)
                
                queue_c.append(node_c.left)
                queue_c.append(node_c.right)
```

</details>
