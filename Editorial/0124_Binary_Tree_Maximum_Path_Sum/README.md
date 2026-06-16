# 124. Binary Tree Maximum Path Sum

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)  
`Dynamic Programming` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 124 - Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## Problem

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

### Example 1

```text
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
```

### Example 2

```text
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```

## Constraints

- The number of nodes in the tree is in the range [1, 3 * 104].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum](https://leetcode.com/problems/path-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Path Sum IV](https://leetcode.com/problems/path-sum-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Difference Between Maximum and Minimum Price Sum](https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 124. Binary Tree Maximum Path Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Post Order DFS | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Post Order DFS

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int max(int a, int b) { return (a > b) ? a : b; }
int gainFromSubtree(struct TreeNode* root, int* maxSum) {
    if (root == NULL) return 0;
    int gainFromLeft = max(0, gainFromSubtree(root->left, maxSum));
    int gainFromRight = max(0, gainFromSubtree(root->right, maxSum));
    *maxSum = max(*maxSum, gainFromLeft + gainFromRight + root->val);
    return max(gainFromLeft + root->val, gainFromRight + root->val);
}
int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    gainFromSubtree(root, &maxSum);
    return maxSum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);
        return maxSum;
    }

private:
    int maxSum;
    // post order traversal of subtree rooted at `root`
    int gainFromSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // add the path sum from left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        // This is the reason we use `max` here.
        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        // add the path sum from right subtree. 0 if negative
        int gainFromRight = max(gainFromSubtree(root->right), 0);
        // if left or right path sum are negative, they are counted
        // as 0, so this statement takes care of all four scenarios
        maxSum = max(maxSum, gainFromLeft + gainFromRight + root->val);
        // return the max sum for a path starting at the root of subtree
        return max(gainFromLeft + root->val, gainFromRight + root->val);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int maxSum = int.MinValue;

    public int MaxPathSum(TreeNode root) {
        GainFromSubtree(root);
        return maxSum;
    }

    // post order traversal of subtree rooted at `root`
    private int GainFromSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // add the path sum from left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        // This is the reason we use `Math.Max` here.
        int gainFromLeft = Math.Max(GainFromSubtree(root.left), 0);
        // add the path sum from right subtree. 0 if negative
        int gainFromRight = Math.Max(GainFromSubtree(root.right), 0);
        maxSum = Math.Max(maxSum, gainFromLeft + gainFromRight + root.val);
        // return the max sum for a path starting at the root of subtree
        return Math.Max(gainFromLeft + root.val, gainFromRight + root.val);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func gainFromSubtree(root *TreeNode, maxSum *int) int {
    if root == nil {
        return 0
    }
    gainFromLeft := max(gainFromSubtree(root.Left, maxSum), 0)
    gainFromRight := max(gainFromSubtree(root.Right, maxSum), 0)
    *maxSum = max(*maxSum, gainFromLeft+gainFromRight+root.Val)
    return max(gainFromLeft+root.Val, gainFromRight+root.Val)
}

func maxPathSum(root *TreeNode) int {
    maxSum := math.MinInt32
    gainFromSubtree(root, &maxSum)
    return maxSum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        gainFromSubtree(root);
        return maxSum;
    }

    private int maxSum;

    // post order traversal of subtree rooted at `root`
    private int gainFromSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // add the path sum from left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        // This is the reason we use `Math.max` here.
        int gainFromLeft = Math.max(gainFromSubtree(root.left), 0);

        // add the path sum from right subtree. 0 if negative
        int gainFromRight = Math.max(gainFromSubtree(root.right), 0);

        // if left or right path sum are negative, they are counted
        // as 0, so this statement takes care of all four scenarios
        maxSum = Math.max(maxSum, gainFromLeft + gainFromRight + root.val);

        // return the max sum for a path starting at the root of subtree
        return Math.max(gainFromLeft + root.val, gainFromRight + root.val);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function maxPathSum(root) {
    let maxPath = -Infinity;

    // post order traversal of subtree rooted at `node`
    function gainFromSubtree(node) {
        if (!node) {
            return 0;
        }
        // add the path sum from left subtree and the current root
        let gainFromLeft = Math.max(gainFromSubtree(node.left), 0);

        // add the path sum from right subtree and the current root
        let gainFromRight = Math.max(gainFromSubtree(node.right), 0);

        // if left or right path sum are negative, they are counted
        // as 0, so this statement takes care of all four scenarios
        maxPath = Math.max(maxPath, gainFromLeft + gainFromRight + node.val);

        // return the max sum for a path starting at the root of subtree
        return Math.max(gainFromLeft + node.val, gainFromRight + node.val);
    }
    gainFromSubtree(root);
    return maxPath;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxPath = -float("inf")

        # post order traversal of subtree rooted at `node`
        def gainFromSubtree(node: Optional[TreeNode]) -> int:
            nonlocal maxPath

            if not node:
                return 0

            # add the gain from the left subtree. Note that if the
            # gain is negative, we can ignore it, or count it as 0.
            # This is the reason we use `max` here.
            gainFromLeft = max(gainFromSubtree(node.left), 0)

            # add the gain / path sum from right subtree. 0 if negative
            gainFromRight = max(gainFromSubtree(node.right), 0)

            # if left or right gain are negative, they are counted
            # as 0, so this statement takes care of all four scenarios
            maxPath = max(maxPath, gainFromLeft + gainFromRight + node.val)

            # return the max sum for a path starting at the root of subtree
            return max(gainFromLeft + node.val, gainFromRight + node.val)

        gainFromSubtree(root)
        return maxPath
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function gainFromSubtree(node, maxPath) {
    if (!node) {
        return 0;
    }
    let gainFromLeft = Math.max(gainFromSubtree(node.left, maxPath), 0);
    let gainFromRight = Math.max(gainFromSubtree(node.right, maxPath), 0);
    maxPath[0] = Math.max(maxPath[0], gainFromLeft + gainFromRight + node.val);
    return Math.max(gainFromLeft + node.val, gainFromRight + node.val);
}
function maxPathSum(root) {
    let maxPath = [-Infinity];
    gainFromSubtree(root, maxPath);
    return maxPath[0];
}
```

</details>
