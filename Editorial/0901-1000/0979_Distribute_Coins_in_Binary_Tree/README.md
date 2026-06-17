# 979. Distribute Coins in Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/distribute-coins-in-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 979 - Distribute Coins in Binary Tree](https://leetcode.com/problems/distribute-coins-in-binary-tree/)

## Problem

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

### Example 1

```text
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
```

### Example 2

```text
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
```

## Constraints

- The number of nodes in the tree is n.
- 1 <= n <= 100
- 0 <= Node.val <= n
- The sum of all Node.val is n.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 979. Distribute Coins in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }

private:
    int moves;
    int dfs(TreeNode* current) {
        if (current == nullptr) return 0;

        // Calculate the coins each subtree has available to exchange
        int leftCoins = dfs(current->left);
        int rightCoins = dfs(current->right);

        // Add the total number of exchanges to moves
        moves += abs(leftCoins) + abs(rightCoins);

        // The number of coins current has available to exchange
        return (current->val - 1) + leftCoins + rightCoins;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int moves;

    public int distributeCoins(TreeNode root) {
        moves = 0;
        dfs(root);
        return moves;
    }

    private int dfs(TreeNode current) {
        if (current == null) return 0;

        // Calculate the coins each subtree has available to exchange
        int leftCoins = dfs(current.left);
        int rightCoins = dfs(current.right);

        // Add the total number of exchanges to moves
        moves += Math.abs(leftCoins) + Math.abs(rightCoins);

        // The number of coins current has available to exchange
        return (current.val - 1) + leftCoins + rightCoins;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.moves = 0

        def dfs(current):
            if current == None:
                return 0

            # Calculate the coins each subtree has available to exchange
            left_coins = dfs(current.left)
            right_coins = dfs(current.right)

            # Add the total number of exchanges to moves
            self.moves += abs(left_coins) + abs(right_coins)

            # The number of coins current has available to exchange
            return (current.val - 1) + left_coins + right_coins

        dfs(root)

        return self.moves
```

</details>
