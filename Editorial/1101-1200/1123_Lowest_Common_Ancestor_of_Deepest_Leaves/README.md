# 1123. Lowest Common Ancestor of Deepest Leaves

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1123 - Lowest Common Ancestor of Deepest Leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)

## Problem

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

- The node of a binary tree is a leaf if and only if it has no children
- The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
- The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

### Example 1

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
```

### Example 2

```text
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
```

### Example 3

```text
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
```

## Constraints

- The number of nodes in the tree will be in the range [1, 1000].
- 0 <= Node.val <= 1000
- The values of the nodes in the tree are unique.

Note: This question is the same as 865: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lowest Common Ancestor of a Binary Tree IV](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1123. Lowest Common Ancestor of Deepest Leaves

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Pair {
    struct TreeNode *node;
    int depth;
};

struct Pair dfs(struct TreeNode *root) {
    if (root == NULL) {
        return (struct Pair){NULL, 0};
    }

    struct Pair left = dfs(root->left);
    struct Pair right = dfs(root->right);

    if (left.depth > right.depth) {
        return (struct Pair){left.node, left.depth + 1};
    }
    if (left.depth < right.depth) {
        return (struct Pair){right.node, right.depth + 1};
    }
    return (struct Pair){root, left.depth + 1};
}

struct TreeNode *lcaDeepestLeaves(struct TreeNode *root) {
    return dfs(root).node;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) {
            return {nullptr, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        return {root, left.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).first; }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        return dfs(root).Item1;
    }

    private Tuple<TreeNode, int> dfs(TreeNode root) {
        if (root == null) {
            return new Tuple<TreeNode, int>(null, 0);
        }

        Tuple<TreeNode, int> left = dfs(root.left);
        Tuple<TreeNode, int> right = dfs(root.right);

        if (left.Item2 > right.Item2) {
            return new Tuple<TreeNode, int>(left.Item1, left.Item2 + 1);
        }
        if (left.Item2 < right.Item2) {
            return new Tuple<TreeNode, int>(right.Item1, right.Item2 + 1);
        }
        return new Tuple<TreeNode, int>(root, left.Item2 + 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	_, lca := dfs(root)
	return lca
}

func dfs(root *TreeNode) (int, *TreeNode) {
	if root == nil {
		return 0, nil
	}

	leftDepth, leftLCA := dfs(root.Left)
	rightDepth, rightLCA := dfs(root.Right)

	if leftDepth > rightDepth {
		return leftDepth + 1, leftLCA
	}
	if leftDepth < rightDepth {
		return rightDepth + 1, rightLCA
	}
	return leftDepth + 1, root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(null, 0);
        }

        Pair<TreeNode, Integer> left = dfs(root.left);
        Pair<TreeNode, Integer> right = dfs(root.right);

        if (left.getValue() > right.getValue()) {
            return new Pair<>(left.getKey(), left.getValue() + 1);
        }
        if (left.getValue() < right.getValue()) {
            return new Pair<>(right.getKey(), right.getValue() + 1);
        }
        return new Pair<>(root, left.getValue() + 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lcaDeepestLeaves = function (root) {
    return dfs(root)[1];
};

function dfs(root) {
    if (!root) {
        return [0, null];
    }

    let left = dfs(root.left);
    let right = dfs(root.right);

    if (left[0] > right[0]) {
        return [left[0] + 1, left[1]];
    }
    if (left[0] < right[0]) {
        return [right[0] + 1, right[1]];
    }
    return [left[0] + 1, root];
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if not root:
                return 0, None

            left = dfs(root.left)
            right = dfs(root.right)

            if left[0] > right[0]:
                return left[0] + 1, left[1]
            if left[0] < right[0]:
                return right[0] + 1, right[1]
            return left[0] + 1, root

        return dfs(root)[1]
```

</details>
