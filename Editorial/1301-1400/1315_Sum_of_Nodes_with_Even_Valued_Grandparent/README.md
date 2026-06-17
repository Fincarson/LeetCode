# 1315. Sum of Nodes with Even-Valued Grandparent

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1315 - Sum of Nodes with Even-Valued Grandparent](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)

## Problem

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

### Example 1

```text
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
```

### Example 2

```text
Input: root = [1]
Output: 0
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1315. Sum of Nodes with Even-Valued Grandparent

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java |
| Breadth-First Search (BFS) | C++, Java |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int solve(TreeNode* root, int parent, int gParent) {
        if (!root) {
            return 0;
        }
        
        // Iterate over the child with updated values of parent and grandparent.
        return solve(root->left, root->val, parent) 
                + solve(root->right, root->val, parent)
                + (gParent % 2 ? 0 : root->val);
    }

    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, -1, -1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int solve(TreeNode root, int parent, int gParent) {
        if (root == null) {
            return 0;
        }
        
        // Iterate over the child with updated values of parent and grandparent.
        return solve(root.left, root.val, parent) 
                + solve(root.right, root.val, parent)
                + (gParent % 2 != 0 ? 0 : root.val);
    }

    public int sumEvenGrandparent(TreeNode root) {
        return solve(root, -1, -1);
    }
}
```

</details>

<br>

## Approach 2:  Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findVal(TreeNode* root) {
        return root ? root->val : 0;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // If the node value is even, then Check the four grandchildren
            // And add the value.
            if (curr->val % 2 == 0) {
                if (curr->left) {
                    sum += findVal(curr->left->left) + findVal(curr->left->right);
                }
                if (curr->right) {
                    sum += findVal(curr->right->left) + findVal(curr->right->right);
                }
            }
            
            // Add the non-null child of the current node.
            if (curr->left) 
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        
        return sum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int findVal(TreeNode root) {
        return root == null ? 0 : root.val;
    }
    
    public int sumEvenGrandparent(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        
        int sum = 0;
        while (!q.isEmpty()) {
            TreeNode curr = q.remove();
            
            // If the node value is even, then Check the four grandchildren
            // And add the value.
            if (curr.val % 2 == 0) {
                if (curr.left != null) {
                    sum += findVal(curr.left.left) + findVal(curr.left.right);
                }
                if (curr.right != null) {
                    sum += findVal(curr.right.left) + findVal(curr.right.right);
                }
            }
            
            // Add the non-null child of the current node.
            if (curr.left != null) 
                q.add(curr.left);
            if (curr.right != null)
                q.add(curr.right);
        }
        
        return sum;
    }
}
```

</details>
