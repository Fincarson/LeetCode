# 314. Binary Tree Vertical Order Traversal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Sorting` `Binary Tree`

**Problem Link:** [LeetCode 314 - Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)

## Problem

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
```

### Example 2

```text
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
```

### Example 3

```text
Input: root = [1,2,3,4,10,9,11,null,5,null,null,null,null,null,null,null,6]
Output: [[4],[2,5],[1,10,9,6],[3],[11]]
```

## Constraints

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 314. Binary Tree Vertical Order Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | Java, Python3 |
| BFS without Sorting | Java, Python3 |
| Depth-First Search (DFS) | Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public List<List<Integer>> verticalOrder(TreeNode root) {
    List<List<Integer>> output = new ArrayList();
    if (root == null) {
      return output;
    }

    Map<Integer, ArrayList> columnTable = new HashMap();
    Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque();
    int column = 0;
    queue.offer(new Pair(root, column));

    while (!queue.isEmpty()) {
      Pair<TreeNode, Integer> p = queue.poll();
      root = p.getKey();
      column = p.getValue();

      if (root != null) {
        if (!columnTable.containsKey(column)) {
          columnTable.put(column, new ArrayList<Integer>());
        }
        columnTable.get(column).add(root.val);

        queue.offer(new Pair(root.left, column - 1));
        queue.offer(new Pair(root.right, column + 1));
      }
    }

    List<Integer> sortedKeys = new ArrayList<Integer>(columnTable.keySet());
    Collections.sort(sortedKeys);
    for(int k : sortedKeys) {
      output.add(columnTable.get(k));
    }

    return output;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        columnTable = defaultdict(list)
        queue = deque([(root, 0)])

        while queue:
            node, column = queue.popleft()

            if node is not None:
                columnTable[column].append(node.val)
                
                queue.append((node.left, column - 1))
                queue.append((node.right, column + 1))
                        
        return [columnTable[x] for x in sorted(columnTable.keys())]
```

</details>

<br>

## Approach 2: BFS without Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public List<List<Integer>> verticalOrder(TreeNode root) {
    List<List<Integer>> output = new ArrayList();
    if (root == null) {
      return output;
    }

    Map<Integer, ArrayList> columnTable = new HashMap();
    // Pair of node and its column offset
    Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque();
    int column = 0;
    queue.offer(new Pair(root, column));

    int minColumn = 0, maxColumn = 0;

    while (!queue.isEmpty()) {
      Pair<TreeNode, Integer> p = queue.poll();
      root = p.getKey();
      column = p.getValue();

      if (root != null) {
        if (!columnTable.containsKey(column)) {
          columnTable.put(column, new ArrayList<Integer>());
        }
        columnTable.get(column).add(root.val);
        minColumn = Math.min(minColumn, column);
        maxColumn = Math.max(maxColumn, column);

        queue.offer(new Pair(root.left, column - 1));
        queue.offer(new Pair(root.right, column + 1));
      }
    }

    for(int i = minColumn; i < maxColumn + 1; ++i) {
      output.add(columnTable.get(i));
    }

    return output;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0
        queue = deque([(root, 0)])

        while queue:
            node, column = queue.popleft()

            if node is not None:
                columnTable[column].append(node.val)
                min_column = min(min_column, column)
                max_column = max(max_column, column)

                queue.append((node.left, column - 1))
                queue.append((node.right, column + 1))

        return [columnTable[x] for x in range(min_column, max_column + 1)]
```

</details>

<br>

## Approach 3: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  Map<Integer, ArrayList<Pair<Integer, Integer>>> columnTable = new HashMap();
  int minColumn = 0, maxColumn = 0;

  private void DFS(TreeNode node, Integer row, Integer column) {
    if (node == null)
      return;

    if (!columnTable.containsKey(column)) {
      this.columnTable.put(column, new ArrayList<Pair<Integer, Integer>>());
    }

    this.columnTable.get(column).add(new Pair<Integer, Integer>(row, node.val));
    this.minColumn = Math.min(minColumn, column);
    this.maxColumn = Math.max(maxColumn, column);
    // preorder DFS traversal
    this.DFS(node.left, row + 1, column - 1);
    this.DFS(node.right, row + 1, column + 1);
  }

  public List<List<Integer>> verticalOrder(TreeNode root) {
    List<List<Integer>> output = new ArrayList();
    if (root == null) {
      return output;
    }

    this.DFS(root, 0, 0);

    // Retrieve the resuts, by ordering by column and sorting by row
    for (int i = minColumn; i < maxColumn + 1; ++i) {

      Collections.sort(columnTable.get(i), new Comparator<Pair<Integer, Integer>>() {
        @Override
        public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
          return p1.getKey() - p2.getKey();
        }
      });

      List<Integer> sortedColumn = new ArrayList();
      for (Pair<Integer, Integer> p : columnTable.get(i)) {
        sortedColumn.add(p.getValue());
      }
      output.add(sortedColumn);
    }

    return output;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0

        def DFS(node, row, column):
            if node is not None:
                nonlocal min_column, max_column
                columnTable[column].append((row, node.val))
                min_column = min(min_column, column)
                max_column = max(max_column, column)

                # preorder DFS
                DFS(node.left, row + 1, column - 1)
                DFS(node.right, row + 1, column + 1)

        DFS(root, 0, 0)

        # order by column and sort by row
        ret = []
        for col in range(min_column, max_column + 1):
            columnTable[col].sort(key=lambda x:x[0])
            colVals = [val for row, val in columnTable[col]]
            ret.append(colVals)

        return ret
```

</details>
