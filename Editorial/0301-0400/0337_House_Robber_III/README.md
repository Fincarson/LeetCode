# 337. House Robber III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/house-robber-iii/)  
`Dynamic Programming` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 337 - House Robber III](https://leetcode.com/problems/house-robber-iii/)

## Problem

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

### Example 1

```text
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
```

### Example 2

```text
Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 0 <= Node.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 337. House Robber III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python3 |
| Recursion with Memoization | Java, Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] helper(TreeNode node) {
        // return [rob this node, not rob this node]
        if (node == null) {
            return new int[] { 0, 0 };
        }
        int left[] = helper(node.left);
        int right[] = helper(node.right);
        // if we rob this node, we cannot rob its children
        int rob = node.val + left[1] + right[1];
        // else, we free to choose rob its children or not
        int notRob = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        return new int[] { rob, notRob };
    }

    public int rob(TreeNode root) {
        int[] answer = helper(root);
        return Math.max(answer[0], answer[1]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(node):
            # return [rob this node, not rob this node]
            if not node:
                return (0, 0)
            left = helper(node.left)
            right = helper(node.right)
            # if we rob this node, we cannot rob its children
            rob = node.val + left[1] + right[1]
            # else we could choose to either rob its children or not
            not_rob = max(left) + max(right)
            return [rob, not_rob]

        return max(helper(root))
```

</details>

<br>

## Approach 2: Recursion with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    HashMap<TreeNode, Integer> robResult = new HashMap<>();
    HashMap<TreeNode, Integer> notRobResult = new HashMap<>();

    public int helper(TreeNode node, boolean parentRobbed) {
        if (node == null) {
            return 0;
        }
        if (parentRobbed) {
            if (robResult.containsKey(node)) {
                return robResult.get(node);
            }
            int result = helper(node.left, false) + helper(node.right, false);
            robResult.put(node, result);
            return result;
        } else {
            if (notRobResult.containsKey(node)) {
                return notRobResult.get(node);
            }
            int rob = node.val + helper(node.left, true) + helper(node.right, true);
            int notRob = helper(node.left, false) + helper(node.right, false);
            int result = Math.max(rob, notRob);
            notRobResult.put(node, result);
            return result;
        }
    }

    public int rob(TreeNode root) {
        return helper(root, false);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rob(self, root: TreeNode) -> int:
        rob_saved = {}
        not_rob_saved = {}

        def helper(node, parent_robbed):
            if not node:
                return 0

            if parent_robbed:
                if node in rob_saved:
                    return rob_saved[node]
                result = helper(node.left, False) + helper(node.right, False)
                rob_saved[node] = result
                return result
            else:
                if node in not_rob_saved:
                    return not_rob_saved[node]
                rob = node.val + helper(node.left, True) + helper(node.right, True)
                not_rob = helper(node.left, False) + helper(node.right, False)
                result = max(rob, not_rob)
                not_rob_saved[node] = result
                return result

        return helper(root, False)
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // reform tree into array-based tree
        ArrayList<Integer> tree = new ArrayList<>();
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        graph.put(-1, new ArrayList<>());
        int index = -1;
        // we use two Queue to store node and index
        Queue<TreeNode> q_node = new LinkedList<>();
        q_node.add(root);
        Queue<Integer> q_index = new LinkedList<>();
        q_index.add(index);

        while (q_node.size() > 0) {
            TreeNode node = q_node.poll();
            int parentIndex = q_index.poll();
            if (node != null) {
                index++;
                tree.add(node.val);
                graph.put(index, new ArrayList<>());
                graph.get(parentIndex).add(index);
                // push new node into Queue
                q_node.add(node.left);
                q_index.add(index);
                q_node.add(node.right);
                q_index.add(index);
            }
        }

        // represent the maximum start by node i with robbing i
        int[] dpRob = new int[index + 1];

        // represent the maximum start by node i without robbing i
        int[] dpNotRob = new int[index + 1];

        for (int i = index; i >= 0; i--) {
            ArrayList<Integer> children = graph.get(i);
            if (children == null || children.size() == 0) {
                // if is leaf
                dpRob[i] = tree.get(i);
                dpNotRob[i] = 0;
            } else {
                dpRob[i] = tree.get(i);
                for (int child : children) {
                    dpRob[i] += dpNotRob[child];
                    dpNotRob[i] += Math.max(dpRob[child], dpNotRob[child]);
                }
            }
        }

        return Math.max(dpRob[0], dpNotRob[0]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
            
        # reform tree into array-based tree
        tree = []
        graph = {-1: []}
        index = -1
        q = [(root, -1)]
        while q:
            node, parent_index = q.pop(0)
            if node:
                index += 1
                tree.append(node.val)
                graph[index] = []
                graph[parent_index].append(index)
                q.append((node.left, index))
                q.append((node.right, index))

        # represent the maximum start by node i with robbing i
        dp_rob = [0] * (index+1)

        # represent the maximum start by node i without robbing i
        dp_not_rob = [0] * (index+1)

        for i in reversed(range(index+1)):
            if not graph[i]:  # if is leaf
                dp_rob[i] = tree[i]
                dp_not_rob[i] = 0
            else:
                dp_rob[i] = tree[i] + sum(dp_not_rob[child]
                                          for child in graph[i])
                dp_not_rob[i] = sum(max(dp_rob[child], dp_not_rob[child])
                                    for child in graph[i])

        return max(dp_rob[0], dp_not_rob[0])
```

</details>
