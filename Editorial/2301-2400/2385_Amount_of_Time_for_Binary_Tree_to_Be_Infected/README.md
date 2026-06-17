# 2385. Amount of Time for Binary Tree to Be Infected

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2385 - Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)

## Problem

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

- The node is currently uninfected.
- The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

### Example 1

```text
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
```

### Example 2

```text
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 105
- Each node has a unique value.
- A node with a value of start exists in the tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Infection Sequences](https://leetcode.com/problems/count-the-number-of-infection-sequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2385. Amount of Time for Binary Tree to Be Infected

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Convert to Graph and Breadth-First Search | C++, Java, Python3 |
| One-Pass Depth-First Search | C++, Java, Python3 |

## Approach 1: Convert to Graph and Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
    if (current == nullptr) {
        return;
    } 
    if (map.find(current->val) == map.end()) {
        map[current->val] = unordered_set<int>();
    }
    unordered_set<int>& adjacentList = map[current->val];
    if (parent != 0) {
        adjacentList.insert(parent);
    } 
    if (current->left != nullptr) {
        adjacentList.insert(current->left->val);
    } 
    if (current->right != nullptr) {
        adjacentList.insert(current->right->val);
    }
    convert(current->left, current->val, map);
    convert(current->right, current->val, map);
    }
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public void convert(TreeNode current, int parent, Map<Integer, Set<Integer>> map){
    if (current == null) {
        return;
    } 
    if (!map.containsKey(current.val)) {
        map.put(current.val, new HashSet<>());
    } 
    Set<Integer> adjacentList = map.get(current.val);
    if (parent != 0) {
        adjacentList.add(parent);
    } 
    if (current.left != null) {
        adjacentList.add(current.left.val);
    } 
    if (current.right != null) {
        adjacentList.add(current.right.val);
    } 
    convert(current.left, current.val, map);
    convert(current.right, current.val, map);
    }
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def convert(
    self, current: TreeNode, parent: int, tree_map: Dict[int, Set[int]]
):
    if current is None:
        return
    if current.val not in tree_map:
        tree_map[current.val] = set()
    adjacent_list = tree_map[current.val]
    if parent != 0:
        adjacent_list.add(parent)
    if current.left:
        adjacent_list.add(current.left.val)
    if current.right:
        adjacent_list.add(current.right.val)
    self.convert(current.left, current.val, tree_map)
    self.convert(current.right, current.val, tree_map)
```

</details>

<br>

## Approach 2: One-Pass Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    int traverse(TreeNode* root, int start) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        } else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private int maxDistance = 0;

    public int amountOfTime(TreeNode root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    public int traverse(TreeNode root, int start) {
        int depth = 0;
        if (root == null) {
            return depth;
        }

        int leftDepth = traverse(root.left, start);
        int rightDepth = traverse(root.right, start);

        if (root.val == start) {
            maxDistance = Math.max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = Math.max(leftDepth, rightDepth) + 1;
        } else {
            int distance = Math.abs(leftDepth) + Math.abs(rightDepth);
            maxDistance = Math.max(maxDistance, distance);
            depth = Math.min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_distance = 0

    def amountOfTime(self, root, start):
        self.traverse(root, start)
        return self.max_distance

    def traverse(self, root, start):
        depth = 0
        if root is None:
            return depth

        left_depth = self.traverse(root.left, start)
        right_depth = self.traverse(root.right, start)

        if root.val == start:
            self.max_distance = max(left_depth, right_depth)
            depth = -1
        elif left_depth >= 0 and right_depth >= 0:
            depth = max(left_depth, right_depth) + 1
        else:
            distance = abs(left_depth) + abs(right_depth)
            self.max_distance = max(self.max_distance, distance)
            depth = min(left_depth, right_depth) - 1

        return depth
```

</details>
