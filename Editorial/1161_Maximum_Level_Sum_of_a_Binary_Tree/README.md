# 1161. Maximum Level Sum of a Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1161 - Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

## Problem

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

### Example 1

```text
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

### Example 2

```text
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Cousins in Binary Tree II](https://leetcode.com/problems/cousins-in-binary-tree-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1161. Maximum Level Sum of a Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search | C++, Java, Python3 |
| Depth First Search | C++, Java, Python3 |

## Approach 1: Breadth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = 0, level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int sumAtCurrentLevel = 0;
            // Iterate over all the nodes in the current level.
            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode* node = q.front();
                q.pop();
                sumAtCurrentLevel += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (maxSum < sumAtCurrentLevel) {
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLevelSum(TreeNode root) {
        int maxSum = Integer.MIN_VALUE;
        int ans = 0, level = 0;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            level++;
            int sumAtCurrentLevel = 0;
            // Iterate over all the nodes in the current level.
            for (int sz = q.size(); sz > 0; --sz) {
                TreeNode node = q.poll();
                sumAtCurrentLevel += node.val;

                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }

            if (maxSum < sumAtCurrentLevel) {
                maxSum = sumAtCurrentLevel;
                ans = level;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        max_sum, ans, level = float('-inf'), 0, 0

        q = collections.deque()
        q.append(root)

        while q:
            level += 1
            sum_at_current_level = 0
            # Iterate over all the nodes in the current level.
            for _ in range(len(q)):
                node = q.popleft()
                sum_at_current_level += node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            if max_sum < sum_at_current_level:
                max_sum, ans = sum_at_current_level, level
           
        return ans
```

</details>

<br>

## Approach 2: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& sumOfNodesAtLevel) {
        if (node == nullptr) {
            return;
        }

        if (sumOfNodesAtLevel.size() == level) {
            sumOfNodesAtLevel.push_back(node->val);
        } else {
            sumOfNodesAtLevel[level] += node->val;
        }

        dfs(node->left, level + 1, sumOfNodesAtLevel);
        dfs(node->right, level + 1, sumOfNodesAtLevel);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sumOfNodesAtLevel;
        dfs(root, 0, sumOfNodesAtLevel);

        int maxSum = INT_MIN;
        int ans = 0;

        for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
            if (maxSum < sumOfNodesAtLevel[i]) {
                maxSum = sumOfNodesAtLevel[i];
                ans = i + 1;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void dfs(TreeNode node, int level, List<Integer> sumOfNodesAtLevel) {
        if (node == null) {
            return;
        }

        if (sumOfNodesAtLevel.size() == level) {
            sumOfNodesAtLevel.add(node.val);
        } else {
            sumOfNodesAtLevel.set(level, sumOfNodesAtLevel.get(level) + node.val);
        }

        dfs(node.left, level + 1, sumOfNodesAtLevel);
        dfs(node.right, level + 1, sumOfNodesAtLevel);
    }

    public int maxLevelSum(TreeNode root) {
        List<Integer> sumOfNodesAtLevel = new ArrayList<>();
        dfs(root, 0, sumOfNodesAtLevel);

        int maxSum = Integer.MIN_VALUE;
        int ans = 0;

        for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
            if (maxSum < sumOfNodesAtLevel.get(i)) {
                maxSum = sumOfNodesAtLevel.get(i);
                ans = i + 1;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def dfs(
        self, node: Optional[TreeNode], level: int, sum_of_nodes_at_level: List[int]
    ) -> None:
        if node is None:
            return

        if len(sum_of_nodes_at_level) == level:
            sum_of_nodes_at_level.append(node.val)
        else:
            sum_of_nodes_at_level[level] += node.val

        self.dfs(node.left, level + 1, sum_of_nodes_at_level)
        self.dfs(node.right, level + 1, sum_of_nodes_at_level)

    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        sum_of_nodes_at_level = []
        self.dfs(root, 0, sum_of_nodes_at_level)

        max_sum = float("-inf")
        ans = 0

        for i in range(len(sum_of_nodes_at_level)):
            if max_sum < sum_of_nodes_at_level[i]:
                max_sum = sum_of_nodes_at_level[i]
                ans = i + 1

        return ans
```

</details>
