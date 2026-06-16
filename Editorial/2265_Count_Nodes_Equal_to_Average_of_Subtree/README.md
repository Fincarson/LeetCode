# 2265. Count Nodes Equal to Average of Subtree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2265 - Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/)

## Problem

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

- The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
- A subtree of root is a tree consisting of root and all of its descendants.

### Example 1

```text
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation:
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.
```

### Example 2

```text
Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- 0 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Average Subtree](https://leetcode.com/problems/maximum-average-subtree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Insufficient Nodes in Root to Leaf Paths](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Nodes Equal to Sum of Descendants](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2265. Count Nodes Equal to Average of Subtree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth First Search (DFS) | C++, Java |

## Approach: Depth First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int count = 0;
    
    pair<int, int> postOrder(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        
        // First iterate over left and right subtrees.
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        
        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        // Check if the average of the subtree is equal to the node value.
        if (root->val == nodeSum / (nodeCount)) {
            count++;
        }
        
        // Return the sum of nodes and the count in the subtree.
        return {nodeSum, nodeCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;
    
    Pair<Integer, Integer> postOrder(TreeNode root) {
        if (root == null) {
            return new Pair(0, 0);
        }
        
        // First iterate over left and right subtrees.
        Pair<Integer, Integer> left = postOrder(root.left);
        Pair<Integer, Integer> right = postOrder(root.right);
        
        int nodeSum = left.getKey() + right.getKey() + root.val;
        int nodeCount = left.getValue() + right.getValue() + 1;

        // Check if the average of the subtree is equal to the node value.
        if (root.val == nodeSum / (nodeCount)) {
            count++;
        }
        
        // Return the sum of nodes and the count in the subtree.
        return new Pair(nodeSum, nodeCount);
    }
    
    public int averageOfSubtree(TreeNode root) {
        postOrder(root);
        return count;
    }
}
```

</details>
