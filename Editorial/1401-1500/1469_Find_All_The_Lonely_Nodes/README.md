# 1469. Find All The Lonely Nodes

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-all-the-lonely-nodes/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1469 - Find All The Lonely Nodes](https://leetcode.com/problems/find-all-the-lonely-nodes/)

## Problem

In a binary tree, a lonely node is a node that is the only child of its parent node. The root of the tree is not lonely because it does not have a parent node.

Given the root of a binary tree, return an array containing the values of all lonely nodes in the tree. Return the list in any order.

### Example 1

```text
Input: root = [1,2,3,null,4]
Output: [4]
Explanation: Light blue node is the only lonely node.
Node 1 is the root and is not lonely.
Nodes 2 and 3 have the same parent and are not lonely.
```

### Example 2

```text
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
Output: [6,2]
Explanation: Light blue nodes are lonely nodes.
Please remember that order doesn't matter, [2,6] is also an acceptable answer.
```

### Example 3

```text
Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
Output: [77,55,33,66,44,22]
Explanation: Nodes 99 and 88 share the same parent. Node 11 is the root.
All other nodes are lonely.
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- 1 <= Node.val <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Tilt](https://leetcode.com/problems/binary-tree-tilt/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1469. Find All The Lonely Nodes

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
    void DFS(TreeNode* root, bool isLonely, vector<int>& ans) {
        if (!root) {
            return;
        }
        
        if (isLonely) {
            ans.push_back(root->val);
        }
        
        DFS(root->left, root->right == NULL, ans);
        DFS(root->right, root->left == NULL, ans);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        DFS(root, false, ans);
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    void DFS(TreeNode root, boolean isLonely, List<Integer> ans) {
        if (root == null) {
            return;
        }
        
        if (isLonely) {
            ans.add(root.val);
        }
        
        DFS(root.left, root.right == null, ans);
        DFS(root.right, root.left == null, ans);
    }
    
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        DFS(root, false, ans);

        return ans;
    }
}
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});

        while (!q.empty()) {
            pair<TreeNode*, bool> qFront = q.front();
            q.pop();
            
            TreeNode* currNode = qFront.first;
            bool isLonely = qFront.second;

            if (isLonely) {
                ans.push_back(currNode->val);
            }
            
            if (currNode->right) {
                q.push({currNode->right, currNode->left == NULL});
            }

            if (currNode->left) {
                q.push({currNode->left, currNode->right == NULL});
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
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        
        Queue<Pair<TreeNode, Boolean>> q = new LinkedList<>();
        q.add(new Pair(root, false));

        while (!q.isEmpty()) {
            Pair<TreeNode, Boolean> qFront = q.remove();
            
            TreeNode currNode = qFront.getKey();
            Boolean isLonely = qFront.getValue();

            if (isLonely) {
                ans.add(currNode.val);
            }
            
            if (currNode.right != null) {
                q.add(new Pair(currNode.right, currNode.left == null));
            }

            if (currNode.left != null) {
                q.add(new Pair(currNode.left, currNode.right == null));
            }
        }
        
        return ans;
    }
}
```

</details>
