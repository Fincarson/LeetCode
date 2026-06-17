# 1120. Maximum Average Subtree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-average-subtree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1120 - Maximum Average Subtree](https://leetcode.com/problems/maximum-average-subtree/)

## Problem

Given the root of a binary tree, return the maximum average value of a subtree of that tree. Answers within 10-5 of the actual answer will be accepted.

A subtree of a tree is any node of that tree plus all its descendants.

The average value of a tree is the sum of its values, divided by the number of nodes.

### Example 1

```text
Input: root = [5,6,1]
Output: 6.00000
Explanation:
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
```

### Example 2

```text
Input: root = [0,null,1]
Output: 1.00000
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 0 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Nodes Equal to Sum of Descendants](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Nodes Equal to Average of Subtree](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1120. Maximum Average Subtree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Postorder Traversal | C++, Java |

## Approach 1: Postorder Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        return maxAverage(root).maxAverage;
    }

private:
    struct State {
        // count of nodes in the subtree
        int nodeCount;

        // sum of values in the subtree
        int valueSum;

        // max average found in the subtree
        double maxAverage;
    };

    State maxAverage(TreeNode* root) {
        if (!root) return {0, 0, 0};

        // postorder traversal, solve for both child nodes first.
        State left = maxAverage(root->left);
        State right = maxAverage(root->right);

        // now find nodeCount, valueSum and maxAverage for current node `root`
        int nodeCount = left.nodeCount + right.nodeCount + 1;
        int sum = left.valueSum + right.valueSum + root->val;
        double maxAverage = max(
                (1.0 * (sum)) / nodeCount, // average for current node
                max(right.maxAverage, left.maxAverage) // max average from child nodes
        );

        return {nodeCount, sum, maxAverage};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // for each node in the tree, we will maintain three values
    class State {
        // count of nodes in the subtree
        int nodeCount;

        // sum of values in the subtree
        int valueSum;

        // max average found in the subtree
        double maxAverage;

        State(int nodes, int sum, double maxAverage) {
            this.nodeCount = nodes;
            this.valueSum = sum;
            this.maxAverage = maxAverage;
        }
    }

    public double maximumAverageSubtree(TreeNode root) {
        return maxAverage(root).maxAverage;
    }

    State maxAverage(TreeNode root) {
        if (root == null) {
            return new State(0, 0, 0);
        }

        // postorder traversal, solve for both child nodes first.
        State left = maxAverage(root.left);
        State right = maxAverage(root.right);

        // now find nodeCount, valueSum and maxAverage for current node `root`
        int nodeCount = left.nodeCount + right.nodeCount + 1;
        int sum = left.valueSum + right.valueSum + root.val;
        double maxAverage = Math.max(
                (1.0 * (sum)) / nodeCount, // average for current node
                Math.max(right.maxAverage, left.maxAverage) // max average from child nodes
        );

        return new State(nodeCount, sum, maxAverage);
    }
}
```

</details>
