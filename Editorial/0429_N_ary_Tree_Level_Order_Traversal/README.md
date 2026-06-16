# 429. N-ary Tree Level Order Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)  
`Tree` `Breadth-First Search`

**Problem Link:** [LeetCode 429 - N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

## Problem

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
```

## Constraints

- The height of the n-ary tree is less than or equal to 1000
- The total number of nodes is between [0, 104]

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 429. N-ary Tree Level Order Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-first Search using a Queue | Java, Python3 |
| Simplified Breadth-first Search | Java, Python3 |
| Recursion | Java, Python3 |

## Approach 1: Breadth-first Search using a Queue

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// This code is a modified version of the code posted by
// #zzzliu on the discussion forums.
class Solution {

    public List<List<Integer>> levelOrder(Node root) {      
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                level.add(node.val);
                queue.addAll(node.children);
            }
            result.add(level);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrder(self, root: Optional['Node']) -> List[List[int]]:
        if root is None:
            return []
        result = []
        queue = collections.deque([root])
        while queue:
            level = []
            for _ in range(len(queue)):
                node = queue.popleft()
                level.append(node.val)
                queue.extend(node.children)
            result.append(level)
        return result
```

</details>

<br>

## Approach 2: Simplified Breadth-first Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// This code is a modified version of the code posted by
// #zzzliu on the discussion forums.
class Solution {

    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        List<Node> previousLayer = Arrays.asList(root);

        while (!previousLayer.isEmpty()) {
            List<Node> currentLayer = new ArrayList<>();
            List<Integer> previousVals = new ArrayList<>();
            for (Node node : previousLayer) {
                previousVals.add(node.val);
                currentLayer.addAll(node.children);
            }
            result.add(previousVals);
            previousLayer = currentLayer;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrder(self, root: Optional['Node']) -> List[List[int]]:
        if root is None:
            return []        

        result = []
        previous_layer = [root]

        while previous_layer:
            current_layer = []
            result.append([])
            for node in previous_layer:
                result[-1].append(node.val)
                current_layer.extend(node.children)
            previous_layer = current_layer
        return result
```

</details>

<br>

## Approach 3: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        if (root != null) traverseNode(root, 0);
        return result;
    }

    private void traverseNode(Node node, int level) {
        if (result.size() <= level) {
            result.add(new ArrayList<>());
        }
        result.get(level).add(node.val);
        for (Node child : node.children) {
            traverseNode(child, level + 1);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrder(self, root: Optional['Node']) -> List[List[int]]:

        def traverse_node(node, level):
            if len(result) == level:
                result.append([])
            result[level].append(node.val)
            for child in node.children:
                traverse_node(child, level + 1)

        result = []

        if root is not None:
            traverse_node(root, 0)
        return result
```

</details>
