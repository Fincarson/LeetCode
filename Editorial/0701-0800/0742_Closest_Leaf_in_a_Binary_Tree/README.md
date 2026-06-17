# 742. Closest Leaf in a Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/closest-leaf-in-a-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 742 - Closest Leaf in a Binary Tree](https://leetcode.com/problems/closest-leaf-in-a-binary-tree/)

## Problem

Given the root of a binary tree where every node has a unique value and a target integer k, return the value of the nearest leaf node to the target k in the tree.

Nearest to a leaf means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

### Example 1

```text
Input: root = [1,3,2], k = 1
Output: 2
Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
```

### Example 2

```text
Input: root = [1], k = 1
Output: 1
Explanation: The nearest leaf node is the root node itself.
```

### Example 3

```text
Input: root = [1,2,3,4,null,null,null,5,null,6], k = 2
Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- 1 <= Node.val <= 1000
- All the values of the tree are unique.
- There exist some node in the tree where Node.val == k.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 742. Closest Leaf in a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Convert to Graph [Accepted] | Java, Python |
| Approach #2: Annotate Closest Leaf [Accepted] | Java, Python |

## Approach #1: Convert to Graph [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findClosestLeaf(TreeNode root, int k) {
        Map<TreeNode, List<TreeNode>> graph = new HashMap();
        dfs(graph, root, null);

        Queue<TreeNode> queue = new LinkedList();
        Set<TreeNode> seen = new HashSet();

        for (TreeNode node: graph.keySet()) {
            if (node != null && node.val == k) {
                queue.add(node);
                seen.add(node);
            }
        }

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node != null) {
                if (graph.get(node).size() <= 1) {
                    return node.val;
                }
                for (TreeNode nei: graph.get(node)) {
                    if (!seen.contains(nei)) {
                        seen.add(nei);
                        queue.add(nei);
                    }
                }
            }
        }
        throw null;
    }

    public void dfs(Map<TreeNode, List<TreeNode>> graph, TreeNode node, TreeNode parent) {
        if (node != null) {
            if (!graph.containsKey(node)) {
                graph.put(node, new LinkedList<TreeNode>());
            }
            if (!graph.containsKey(parent)) {
                graph.put(parent, new LinkedList<TreeNode>());
            }
            graph.get(node).add(parent);
            graph.get(parent).add(node);
            dfs(graph, node.left, node);
            dfs(graph, node.right, node);
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findClosestLeaf(self, root, k):
        graph = collections.defaultdict(list)
        def dfs(node, par = None):
            if node:
                graph[node].append(par)
                graph[par].append(node)
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root)
        queue = collections.deque(node for node in graph
                                  if node and node.val == k)
        seen = set(queue)

        while queue:
            node = queue.popleft()
            if node:
                if len(graph[node]) <= 1:
                    return node.val
                for nei in graph[node]:
                    if nei not in seen:
                        seen.add(nei)
                        queue.append(nei)
```

</details>

<br>

## Approach #2: Annotate Closest Leaf [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<TreeNode> path;
    Map<TreeNode, LeafResult> annotation;

    public int findClosestLeaf(TreeNode root, int k) {
        path = new ArrayList();
        annotation = new HashMap();

        dfs(root, k);

        int distanceFromTarget = path.size() - 1;
        int dist = Integer.MAX_VALUE;
        TreeNode leaf = null;
        for (TreeNode node: path) {
            LeafResult lr = closestLeaf(node);
            if (lr.dist + distanceFromTarget < dist) {
                dist = lr.dist + distanceFromTarget;
                leaf = lr.node;
            }
            distanceFromTarget--;
        }
        return leaf.val;
    }

    public boolean dfs(TreeNode node, int k) {
        if (node == null) {
            return false;
        } else if (node.val == k) {
            path.add(node);
            return true;
        } else {
            path.add(node);
            boolean ans = dfs(node.left, k);
            if (ans) {
                return true;
            }
            ans = dfs(node.right, k);
            if (ans) {
                return true;
            }
            path.remove(path.size() - 1);
            return false;
        }
    }

    public LeafResult closestLeaf(TreeNode root) {
        if (root == null) {
            return new LeafResult(null, Integer.MAX_VALUE);
        } else if (root.left == null && root.right == null) {
            return new LeafResult(root, 0);
        } else if (annotation.containsKey(root)) {
            return annotation.get(root);
        } else {
            LeafResult r1 = closestLeaf(root.left);
            LeafResult r2 = closestLeaf(root.right);
            LeafResult ans = new LeafResult(r1.dist < r2.dist ? r1.node : r2.node,
                                            Math.min(r1.dist, r2.dist) + 1);
            annotation.put(root, ans);
            return ans;
        }
    }
}
class LeafResult {
    TreeNode node;
    int dist;
    LeafResult(TreeNode n, int d) {
        node = n;
        dist = d;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findClosestLeaf(self, root, k):
        annotation = {}
        def closest_leaf(root):
            if root not in annotation:
                if not root:
                    ans = float('inf'), None
                elif not root.left and not root.right:
                    ans = 0, root
                else:
                    d1, leaf1 = closest_leaf(root.left)
                    d2, leaf2 = closest_leaf(root.right)
                    ans = min(d1, d2) + 1, leaf1 if d1 < d2 else leaf2
                annotation[root] = ans
            return annotation[root]

        #Search for node.val == k
        path = []
        def dfs(node):
            if not node:
                return
            if node.val == k:
                path.append(node)
                return True
            path.append(node)
            ans1 = dfs(node.left)
            if ans1:
                return True
            ans2 = dfs(node.right)
            if ans2:
                return True
            path.pop()

        dfs(root)
        dist, leaf = float('inf'), None
        for i, node in enumerate(path):
            d0, leaf0 = closest_leaf(node)
            d0 += len(path) - 1 - i
            if d0 < dist:
                dist = d0
                leaf = leaf0

        return leaf.val
```

</details>
