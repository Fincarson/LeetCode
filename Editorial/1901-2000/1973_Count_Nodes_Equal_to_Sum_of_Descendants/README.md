# 1973. Count Nodes Equal to Sum of Descendants

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1973 - Count Nodes Equal to Sum of Descendants](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/)

## Problem

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the sum of the values of its descendants.

A descendant of a node x is any node that is on the path from node x to some leaf node. The sum is considered to be 0 if the node has no descendants.

### Example 1

```text
Input: root = [10,3,4,2,1]
Output: 2
Explanation:
For the node with value 10: The sum of its descendants is 3+4+2+1 = 10.
For the node with value 3: The sum of its descendants is 2+1 = 3.
```

### Example 2

```text
Input: root = [2,3,null,2,null]
Output: 0
Explanation:
No node has a value that is equal to the sum of its descendants.
```

### Example 3

```text
Input: root = [0]
Output: 1
For the node with value 0: The sum of its descendants is 0 since it has no descendants.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 0 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Average Subtree](https://leetcode.com/problems/maximum-average-subtree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1973. Count Nodes Equal to Sum of Descendants

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Depth-First Search with Postorder Traversal | C++, Java |

## Approach: Depth-First Search with Postorder Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int count;
    
    long countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        long left = countNodes(root->left);
        long right = countNodes(root->right);
        
        if (root->val == left + right) {
            count++;
        }
        
        return left + right + root->val;
    }
    
    int equalToDescendants(TreeNode* root) {
        countNodes(root);
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count;
    
    private long countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        long left = countNodes(root.left);
        long right = countNodes(root.right);
        
        if (root.val == left + right) {
            count++;
        }
        
        return left + right + root.val;
    }
    
    public int equalToDescendants(TreeNode root) {
        countNodes(root);
        return count;
    }
}
```

</details>
