# 783. Minimum Distance Between BST Nodes

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 783 - Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

## Problem

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

### Example 1

```text
Input: root = [4,2,6,1,3]
Output: 1
```

### Example 2

```text
Input: root = [1,0,48,null,null,12,49]
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [2, 100].
- 0 <= Node.val <= 105

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 783. Minimum Distance Between BST Nodes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| In-order Traversal with List | C++, Java |
| In-order Traversal Without List | C++, Java |

## Approach 1: In-order Traversal with List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // List to store the tree nodes in the inorder traversal.
    vector<int> inorderNodes;
    
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);
        // Store the nodes in the list.
        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        int minDistance = INT_MAX;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDistance = min(minDistance, inorderNodes[i] - inorderNodes[i - 1]);
        }
        
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // List to store the tree nodes in the inorder traversal.
    List<Integer> inorderNodes = new ArrayList<>();
    
    void inorderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }
        
        inorderTraversal(root.left);
        // Store the nodes in the list.
        inorderNodes.add(root.val);
        inorderTraversal(root.right);
    }
    
    public int minDiffInBST(TreeNode root) {
       inorderTraversal(root);
        
        int minDistance = Integer.MAX_VALUE;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDistance = Math.min(minDistance, inorderNodes.get(i) - inorderNodes.get(i-1));
        }
        
        return minDistance;
    }
};
```

</details>

<br>

## Approach 2: In-order Traversal Without List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDistance = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevValue;
        
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);

        // Find the difference with the previous value if it is there.
        if (prevValue != NULL) {
            minDistance = min(minDistance, root->val - prevValue->val);
        }
        prevValue = root;
        
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        return minDistance;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  int minDistance = Integer.MAX_VALUE;
  // Initially, it will be null.
  TreeNode prevValue;

  void inorderTraversal(TreeNode root) {
    if (root == null) {
      return;
    }

    inorderTraversal(root.left);

    // Find the difference with the previous value if it is there.
    if (prevValue != null) {
      minDistance = Math.min(minDistance, root.val - prevValue.val);
    }
    prevValue = root;

    inorderTraversal(root.right);
  }

  public int minDiffInBST(TreeNode root) {
    inorderTraversal(root);

    return minDistance;
  }
};
```

</details>
