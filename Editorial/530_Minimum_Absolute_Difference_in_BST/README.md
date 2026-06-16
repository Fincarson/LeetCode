# 530. Minimum Absolute Difference in BST

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 530 - Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

## Problem

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

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

- The number of nodes in the tree is in the range [2, 104].
- 0 <= Node.val <= 105

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [K-diff Pairs in an Array](https://leetcode.com/problems/k-diff-pairs-in-an-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 530. Minimum Absolute Difference in BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search | C++, Java, Python3 |
| In-order Traversal Using List | C++, Java, Python3 |
| In-order Traversal Without List | C++, Java, Python3 |

## Approach 1: Depth First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // List to store the node values.
    vector<int> nodeValues;

    void dfs(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        nodeValues.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);

        sort(nodeValues.begin(), nodeValues.end());
        int minDifference = INT_MAX;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < nodeValues.size(); i++) {
            minDifference = min(minDifference, nodeValues[i] - nodeValues[i - 1]);
        }

        return minDifference;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // List to store the node values.
    List<Integer> nodeValues = new ArrayList<>();

    void dfs(TreeNode node) {
        if (node == null) {
            return;
        }

        nodeValues.add(node.val);
        dfs(node.left);
        dfs(node.right);
    }

    int getMinimumDifference(TreeNode root) {
        dfs(root);

        Collections.sort(nodeValues);
        int minDifference = Integer.MAX_VALUE;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < nodeValues.size(); i++) {
            minDifference = Math.min(minDifference, nodeValues.get(i) - nodeValues.get(i - 1));
        }

        return minDifference;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        nodeValues = []

        def dfs(node):
            if node is None:
                return
            nodeValues.append(node.val)
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)

        nodeValues.sort()
        minDifference = 1e9
        for i in range(1, len(nodeValues)):
            minDifference = min(minDifference, nodeValues[i] - nodeValues[i-1])

        return minDifference
```

</details>

<br>

## Approach 2: In-order Traversal Using List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // List to store the tree nodes in the inorder traversal.
    vector<int> inorderNodes;

    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversal(node->left);
        // Store the nodes in the list.
        inorderNodes.push_back(node->val);
        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);

        int minDifference = INT_MAX;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDifference = min(minDifference, inorderNodes[i] - inorderNodes[i - 1]);
        }

        return minDifference;
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
    
    void inorderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }
        
        inorderTraversal(node.left);
        // Store the nodes in the list.
        inorderNodes.add(node.val);
        inorderTraversal(node.right);
    }
    
    int getMinimumDifference(TreeNode root) {
       inorderTraversal(root);
        
        int minDifference = Integer.MAX_VALUE;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDifference = Math.min(minDifference, inorderNodes.get(i) - inorderNodes.get(i-1));
        }
        
        return minDifference;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        inorderNodes = []

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            inorderNodes.append(node.val)
            inorder(node.right)
        
        inorder(root)
        minDifference = 1e9
        for i in range(1, len(inorderNodes)):
            minDifference = min(minDifference, inorderNodes[i] - inorderNodes[i-1])

        return minDifference
```

</details>

<br>

## Approach 3: In-order Traversal Without List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDifference = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevNode;
        
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        inorderTraversal(node->left);
        // Find the difference with the previous value if it is there.
        if (prevNode != NULL) {
            minDifference = min(minDifference, node->val - prevNode->val);
        }
        prevNode = node;
        inorderTraversal(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDifference;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int minDifference = Integer.MAX_VALUE;
    // Initially, it will be null.
    TreeNode prevNode;

    void inorderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }

        inorderTraversal(node.left);
        // Find the difference with the previous value if it is there.
        if (prevNode != null) {
            minDifference = Math.min(minDifference, node.val - prevNode.val);
        }
        prevNode = node;
        inorderTraversal(node.right);
    }

    int getMinimumDifference(TreeNode root) {
        inorderTraversal(root);
        return minDifference;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.minDistance = 1e9
        # Initially, it will be null.
        self.prevNode = None

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            # Find the difference with the previous value if it is there.
            if self.prevNode is not None:
                self.minDistance = min(self.minDistance, node.val - self.prevNode)
            self.prevNode = node.val
            inorder(node.right)

        inorder(root)
        return self.minDistance
```

</details>
