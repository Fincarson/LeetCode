# 144. Binary Tree Preorder Traversal

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/binary-tree-preorder-traversal/)  
`Stack` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 144 - Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

## Problem

Given the root of a binary tree, return the preorder traversal of its nodes' values.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Verify Preorder Sequence in Binary Search Tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Kth Largest Sum in a Binary Tree](https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 144. Binary Tree Preorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterations | Java, Python3 |
| Morris traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Iterations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/* Definition for a binary tree node. */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TreeNode(object):
    """Definition of a binary tree node."""

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

</details>

<br>

## Approach 2: Morris traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* output = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode* node = root;
    while (node != NULL) {
        if (node->left == NULL) {
            output[(*returnSize)++] = node->val;
            node = node->right;
        } else {
            struct TreeNode* predecessor = node->left;
            while (predecessor->right != NULL && predecessor->right != node) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                output[(*returnSize)++] = node->val;
                predecessor->right = node;
                node = node->left;
            } else {
                predecessor->right = NULL;
                node = node->right;
            }
        }
    }
    return output;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->left == nullptr) {
                output.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* predecessor = node->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    output.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = nullptr;
                    node = node->right;
                }
            }
        }
        return output;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<int> PreorderTraversal(TreeNode root) {
        List<int> output = new List<int>();
        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                output.Add(node.val);
                node = node.right;
            } else {
                TreeNode predecessor = node.left;
                while ((predecessor.right != null) &&
                       (predecessor.right != node)) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {
                    output.Add(node.val);
                    predecessor.right = node;
                    node = node.left;
                } else {
                    predecessor.right = null;
                    node = node.right;
                }
            }
        }

        return output;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func preorderTraversal(root *TreeNode) []int {
    var output []int
    node := root
    for node != nil {
        if node.Left == nil {
            output = append(output, node.Val)
            node = node.Right
        } else {
            predecessor := node.Left
            for predecessor.Right != nil && predecessor.Right != node {
                predecessor = predecessor.Right
            }
            if predecessor.Right == nil {
                output = append(output, node.Val)
                predecessor.Right = node
                node = node.Left
            } else {
                predecessor.Right = nil
                node = node.Right
            }
        }
    }
    return output
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        LinkedList<Integer> output = new LinkedList<>();

        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                output.add(node.val);
                node = node.right;
            } else {
                TreeNode predecessor = node.left;
                while (
                    (predecessor.right != null) && (predecessor.right != node)
                ) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {
                    output.add(node.val);
                    predecessor.right = node;
                    node = node.left;
                } else {
                    predecessor.right = null;
                    node = node.right;
                }
            }
        }
        return output;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var preorderTraversal = function (root) {
    let output = [];
    let node = root;
    while (node) {
        if (!node.left) {
            output.push(node.val);
            node = node.right;
        } else {
            let predecessor = node.left;
            while (predecessor.right && predecessor.right != node) {
                predecessor = predecessor.right;
            }
            if (!predecessor.right) {
                output.push(node.val);
                predecessor.right = node;
                node = node.left;
            } else {
                predecessor.right = null;
                node = node.right;
            }
        }
    }
    return output;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        node, output = root, []
        while node:
            if not node.left:
                output.append(node.val)
                node = node.right
            else:
                predecessor = node.left

                while predecessor.right and predecessor.right is not node:
                    predecessor = predecessor.right

                if not predecessor.right:
                    output.append(node.val)
                    predecessor.right = node
                    node = node.left
                else:
                    predecessor.right = None
                    node = node.right

        return output
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function preorderTraversal(root: TreeNode | null): number[] {
    let output: number[] = [];
    let node: TreeNode | null = root;
    while (node) {
        if (!node.left) {
            output.push(node.val);
            node = node.right;
        } else {
            let predecessor: TreeNode | null = node.left;
            while (predecessor?.right && predecessor.right != node) {
                predecessor = predecessor.right;
            }
            if (!predecessor?.right) {
                output.push(node.val);
                if (predecessor) predecessor.right = node;
                node = node.left;
            } else {
                if (predecessor) predecessor.right = null;
                node = node.right;
            }
        }
    }
    return output;
}
```

</details>
