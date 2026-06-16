# 1448. Count Good Nodes in Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1448 - Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

## Problem

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

### Example 1

```text
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

### Example 2

```text
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

### Example 3

```text
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

## Constraints

- The number of nodes in the binary tree is in the range [1, 10^5].
- Each node's value is between [-10^4, 10^4].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1448. Count Good Nodes in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search, Recursion | Java, Python3 |
| Depth First Search, Iterative | Java, Python3 |
| Breadth First Search | Java, Python3 |

## Approach 1: Depth First Search, Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int numGoodNodes = 0;
    
    public int goodNodes(TreeNode root) {
        dfs(root, Integer.MIN_VALUE);
        return numGoodNodes;
    }
    
    private void dfs(TreeNode node, int maxSoFar) {
        if (maxSoFar <= node.val) {
            numGoodNodes++;
        }
        
        if (node.right != null) {
            dfs(node.right, Math.max(node.val, maxSoFar));
        }

        if (node.left != null) {
            dfs(node.left, Math.max(node.val, maxSoFar));
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
	
        def dfs(node, max_so_far):
            nonlocal num_good_nodes
            if max_so_far <= node.val:
                num_good_nodes += 1
            if node.right:
                dfs(node.right, max(node.val, max_so_far))
            if node.left:
                dfs(node.left, max(node.val, max_so_far))
        
        num_good_nodes = 0
        dfs(root, float("-inf"))
        return num_good_nodes
```

</details>

<br>

## Approach 2: Depth First Search, Iterative

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Pair {
    public TreeNode node;
    public int maxSoFar;
    
    public Pair(TreeNode node, int maxSoFar) {
        this.node = node;
        this.maxSoFar = maxSoFar;
    }
}

class Solution {
    public int goodNodes(TreeNode root) {
        int numGoodNodes = 0;
        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(root, Integer.MIN_VALUE));
        
        while (stack.size() > 0) {
            Pair curr = stack.pop();
            if (curr.maxSoFar <= curr.node.val) {
                numGoodNodes++;
            }
            
            if (curr.node.left != null) {
                stack.push(new Pair(curr.node.left, Math.max(curr.node.val, curr.maxSoFar)));
            }
            
            if (curr.node.right != null) {
                stack.push(new Pair(curr.node.right, Math.max(curr.node.val, curr.maxSoFar)));
            }
        }

        return numGoodNodes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        stack = [(root, float("-inf"))]
        num_good_nodes = 0
        while stack:
            node, max_so_far = stack.pop()
            if max_so_far <= node.val:
                num_good_nodes += 1
            if node.left:
                stack.append((node.left, max(node.val, max_so_far)))
            if node.right:
                stack.append((node.right, max(node.val, max_so_far)))
        
        return num_good_nodes
```

</details>

<br>

## Approach 3: Breadth First Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Pair {
    public TreeNode node;
    public int maxSoFar;
    
    public Pair(TreeNode node, int maxSoFar) {
        this.node = node;
        this.maxSoFar = maxSoFar;
    }
}

class Solution {
    public int goodNodes(TreeNode root) {
        int numGoodNodes = 0;
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, Integer.MIN_VALUE));
        
        while (queue.size() > 0) {
            Pair curr = queue.poll();
            if (curr.maxSoFar <= curr.node.val) {
                numGoodNodes++;
            }
            
            if (curr.node.right != null) {
                queue.offer(new Pair(curr.node.right, Math.max(curr.node.val, curr.maxSoFar)));
            }

            if (curr.node.left != null) {
                queue.offer(new Pair(curr.node.left, Math.max(curr.node.val, curr.maxSoFar)));
            }
        }

        return numGoodNodes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        num_good_nodes = 0
        
        # Use collections.deque for efficient popping
        queue = deque([(root, float("-inf"))])
        while queue:
            node, max_so_far = queue.popleft()
            if max_so_far <= node.val:
                num_good_nodes += 1
            if node.right:
                queue.append((node.right, max(node.val, max_so_far)))
            if node.left:
                queue.append((node.left, max(node.val, max_so_far)))
        
        return num_good_nodes
```

</details>
