# 366. Find Leaves of Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-leaves-of-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 366 - Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/)

## Problem

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

- Collect all the leaf nodes.
- Remove all the leaf nodes.
- Repeat until the tree is empty.

### Example 1

```text
Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
```

### Example 2

```text
Input: root = [1]
Output: [[1]]
```

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 366. Find Leaves of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS (Depth-First Search) with sorting | C++, Java |
| DFS (Depth-First Search) without sorting | C++, Java |

## Approach 1: DFS (Depth-First Search) with sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) return -1;
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // collect the pair -> (height, val)
        this->pairs.push_back({currHeight, root->val});
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->pairs.clear();
        
        getHeight(root);
        
        // sort all the (height, val) pairs
        sort(this->pairs.begin(), this->pairs.end());
        
        int n = this->pairs.size(), height = 0, i = 0;
        vector<vector<int>> solution;
        while (i < n) {
            vector<int> nums;
            while (i < n && this->pairs[i].first == height) {
                nums.push_back(this->pairs[i].second);
                i++;
            }
            solution.push_back(nums);
            height++;
        }
        return solution;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private List<Pair<Integer, Integer>> pairs;
    
    private int getHeight(TreeNode root) {
        
        // return -1 for null nodes
        if (root == null) return -1;
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = Math.max(leftHeight, rightHeight) + 1;

        // collect the pair -> (height, val)
        this.pairs.add(new Pair<Integer, Integer>(currHeight, root.val));

        // return the height of the current node
        return currHeight;
    }
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        this.pairs = new ArrayList<>();
        
        getHeight(root);
        
        // sort all the (height, val) pairs
        Collections.sort(this.pairs, Comparator.comparing(p -> p.getKey()));
        
        int n = this.pairs.size(), height = 0, i = 0;

        List<List<Integer>> solution = new ArrayList<>();
        
        while (i < n) {
            List<Integer> nums = new ArrayList<>();
            while (i < n && this.pairs.get(i).getKey() == height) {
                nums.add(this.pairs.get(i).getValue());
                i++;
            }
            solution.add(nums);
            height++;
        }
        return solution;
    }
}
```

</details>

<br>

## Approach 2: DFS (Depth-First Search) without sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:

    vector<vector<int>> solution;

public:
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) {
            return -1;
        }

        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // create space for node located at `currHeight` if not already exists
        if (this->solution.size() == currHeight) {
            this->solution.push_back({});
        }

        // insert the value at the correct position in the solution array
        this->solution[currHeight].push_back(root->val);
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->solution.clear();
        
        getHeight(root);
        
        return this->solution;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    private List<List<Integer>> solution;
    
    private int getHeight(TreeNode root) {
        
        // return -1 for null nodes
        if (root == null) {
            return -1;
        }
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        
        int currHeight = Math.max(leftHeight, rightHeight) + 1;
        
        if (this.solution.size() == currHeight) {
            this.solution.add(new ArrayList<>());
        }
        
        this.solution.get(currHeight).add(root.val);
        
        return currHeight;
    }
    
    public List<List<Integer>> findLeaves(TreeNode root) {
        this.solution = new ArrayList<>();
        
        getHeight(root);
        
        return this.solution;
    }
}
```

</details>
