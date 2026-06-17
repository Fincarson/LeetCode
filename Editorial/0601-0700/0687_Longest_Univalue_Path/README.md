# 687. Longest Univalue Path

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-univalue-path/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 687 - Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/)

## Problem

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

### Example 1

```text
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).
```

### Example 2

```text
Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- -1000 <= Node.val <= 1000
- The depth of the tree will not exceed 1000.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Univalue Subtrees](https://leetcode.com/problems/count-univalue-subtrees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 687. Longest Univalue Path

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int ans;

    // Returns the length of the longest path (number of nodes) under the root
    // that have the value same as the root. The path could either be
    // on the left or right child of the root. The length includes the root as well.
    int solve(TreeNode* root, int parent) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, root->val);
        int right = solve(root->right, root->val);
        
        //The longest univalue path will cover nodes on both sides of the root.
        ans = max(ans, left + right);

        // The number of nodes will be zero if the root value isn't equal to the root.
        // Otherwise return the max of left and right nodes plus one for the root itself.
        return root->val == parent ? max(left, right) + 1 : 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        // Use -1 for the parent value for the tree root node.
        solve(root, -1);
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// Returns the length of the longest path (number of nodes) under the root
// that have the value same as the root. The path could either be
// on the left or right child of the root. The length includes the root as well.
class Solution {
    int ans;

    int solve(TreeNode root, int parent) {
        if (root == null) {
            return 0;
        }

        //The longest univalue path will cover nodes on both sides of the root.
        int left = solve(root.left, root.val);
        int right = solve(root.right, root.val);

        //The longest univalue path will cover nodes on both sides of the root.
        ans = Math.max(ans, left + right);

        // The number of nodes will be zero if the root value isn't equal to the root.
        // Otherwise return the max of left and right nodes plus one for the root itself.
        return root.val == parent ? Math.max(left, right) + 1 : 0;
    }

    public int longestUnivaluePath(TreeNode root) {
        // Use -1 for the parent value for the tree root node.
        solve(root, -1);

        return ans;
    }
}
```

</details>
