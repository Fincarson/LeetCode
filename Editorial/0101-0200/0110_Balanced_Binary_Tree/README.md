# 110. Balanced Binary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/balanced-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 110 - Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

## Problem

Given a binary tree, determine if it is height-balanced.

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: true
```

### Example 2

```text
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

### Example 3

```text
Input: root = []
Output: true
```

## Constraints

- The number of nodes in the tree is in the range [0, 5000].
- -104 <= Node.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [K-th Largest Perfect Subtree Size in Binary Tree](https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check Balanced String](https://leetcode.com/problems/check-balanced-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 110. Balanced Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bottom-up recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Top-down recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Compute the tree's height via recursion
int height(struct TreeNode* root) {
    // An empty tree has height -1
    if (root == NULL) {
        return -1;
    }
    return 1 + fmax(height(root->left), height(root->right));
}
bool isBalanced(struct TreeNode* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
        return true;
    }
    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
           isBalanced(root->left) && isBalanced(root->right);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Recursively obtain the height of a tree. An empty tree has -1 height
    int height(TreeNode* root) {
        // An empty tree has height -1
        if (root == NULL) {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode* root) {
        // An empty tree satisfies the definition of a balanced tree
        if (root == NULL) {
            return true;
        }

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return abs(height(root->left) - height(root->right)) < 2 &&
               isBalanced(root->left) && isBalanced(root->right);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    // Compute the tree's height via recursion
    private int Height(TreeNode root) {
        // An empty tree has height -1
        if (root == null) {
            return -1;
        }

        return 1 + Math.Max(Height(root.left), Height(root.right));
    }

    public bool IsBalanced(TreeNode root) {
        // An empty tree satisfies the definition of a balanced tree
        if (root == null) {
            return true;
        }

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return Math.Abs(Height(root.left) - Height(root.right)) < 2 &&
               IsBalanced(root.left) && IsBalanced(root.right);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Compute the tree's height via recursion
func height(root *TreeNode) int {
    // An empty tree has height -1
    if root == nil {
        return -1
    }
    return 1 + max(height(root.Left), height(root.Right))
}

func isBalanced(root *TreeNode) bool {
    // An empty tree satisfies the definition of a balanced tree
    if root == nil {
        return true
    }
    // Check if subtrees have height within 1. If they do, check if the subtrees are balanced
    return abs(height(root.Left)-height(root.Right)) < 2 &&
        isBalanced(root.Left) &&
        isBalanced(root.Right)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Recursively obtain the height of a tree. An empty tree has -1 height
    private int height(TreeNode root) {
        // An empty tree has height -1
        if (root == null) {
            return -1;
        }
        return 1 + Math.max(height(root.left), height(root.right));
    }

    public boolean isBalanced(TreeNode root) {
        // An empty tree satisfies the definition of a balanced tree
        if (root == null) {
            return true;
        }

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return (
            Math.abs(height(root.left) - height(root.right)) < 2 &&
            isBalanced(root.left) &&
            isBalanced(root.right)
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Compute the tree's height via recursion
var height = function (root) {
    // An empty tree has height -1
    if (root == null) {
        return -1;
    }
    return 1 + Math.max(height(root.left), height(root.right));
};
var isBalanced = function (root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == null) {
        return true;
    }
    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return (
        Math.abs(height(root.left) - height(root.right)) < 2 &&
        isBalanced(root.left) &&
        isBalanced(root.right)
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Compute the tree's height via recursion
    def height(self, root: TreeNode) -> int:
        # An empty tree has height -1
        if not root:
            return -1
        return 1 + max(self.height(root.left), self.height(root.right))

    def isBalanced(self, root: TreeNode) -> bool:
        # An empty tree satisfies the definition of a balanced tree
        if not root:
            return True

        # Check if subtrees have height within 1. If they do, check if the
        # subtrees are balanced
        return (
            abs(self.height(root.left) - self.height(root.right)) < 2
            and self.isBalanced(root.left)
            and self.isBalanced(root.right)
        )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Compute the tree's height via recursion
function height(root: TreeNode | null): number {
    // An empty tree has height -1
    if (!root) {
        return -1;
    }
    return 1 + Math.max(height(root.left), height(root.right));
}
function isBalanced(root: TreeNode | null): boolean {
    // An empty tree satisfies the definition of a balanced tree
    if (!root) {
        return true;
    }
    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return (
        Math.abs(height(root.left) - height(root.right)) < 2 &&
        isBalanced(root.left) &&
        isBalanced(root.right)
    );
}
```

</details>

<br>

## Approach 2: Bottom-up recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int height;
    bool balanced;
} TreeInfo;
// Returns whether the tree at root is balanced, along with the tree's height.
TreeInfo isBalancedTreeHelper(struct TreeNode* root) {
    TreeInfo info;
    // An empty tree is both balanced and has a height -1.
    if (root == NULL) {
        info.height = -1;
        info.balanced = true;
        return info;
    }
    TreeInfo left = isBalancedTreeHelper(root->left);
    if (!left.balanced) {
        info.height = -1;
        info.balanced = false;
        return info;
    }
    TreeInfo right = isBalancedTreeHelper(root->right);
    if (!right.balanced) {
        info.height = -1;
        info.balanced = false;
        return info;
    }
    // The obtained height from recursive calls can also determine
    // that the current node is balanced.
    if (abs(left.height - right.height) < 2) {
        info.height =
            (left.height > right.height ? left.height : right.height) + 1;
        info.balanced = true;
        return info;
    }
    info.height = -1;
    info.balanced = false;
    return info;
}
bool isBalanced(struct TreeNode* root) {
    return isBalancedTreeHelper(root).balanced;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Return whether or not the tree at root is balanced while also storing
    // the tree's height in a reference variable.
    bool isBalancedTreeHelper(TreeNode* root, int& height) {
        // An empty tree is balanced and has height = -1
        if (root == NULL) {
            height = -1;
            return true;
        }

        // Check subtrees to see if they are balanced. If they are, check if the
        // current node is also balanced using the heights obtained from the
        // recursive calls.
        int left, right;
        if (isBalancedTreeHelper(root->left, left) &&
            isBalancedTreeHelper(root->right, right) && abs(left - right) < 2) {
            // Store the current tree's height
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedTreeHelper(root, height);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// Utility class to store information from recursive calls

public class TreeInfo {
    public int Height { get; }
    public bool Balanced { get; }

    public TreeInfo(int height, bool balanced) {
        this.Height = height;
        this.Balanced = balanced;
    }
}

public class Solution {
    // Returns whether the tree at root is balanced, along with the tree's
    // height.
    private TreeInfo IsBalancedTreeHelper(TreeNode root) {
        // An empty tree is both balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }

        // Checks whether the subtrees are balanced or not.
        var left = IsBalancedTreeHelper(root.left);
        if (!left.Balanced) {
            return new TreeInfo(-1, false);
        }

        var right = IsBalancedTreeHelper(root.right);
        if (!right.Balanced) {
            return new TreeInfo(-1, false);
        }

        // The obtained height from recursive calls can also determine
        // that the current node is balanced.
        if (Math.Abs(left.Height - right.Height) < 2) {
            return new TreeInfo(Math.Max(left.Height, right.Height) + 1, true);
        }

        return new TreeInfo(-1, false);
    }

    public bool IsBalanced(TreeNode root) {
        return IsBalancedTreeHelper(root).Balanced;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TreeInfo struct {
    height   int
    balanced bool
}

func abs(a int) int {
    if a < 0 {
        return -1 * a
    }
    return a
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Returns whether the tree at root is balanced, along with the tree's height.
func isBalancedTreeHelper(root *TreeNode) TreeInfo {
    if root == nil {
        return TreeInfo{-1, true}
    }
    left := isBalancedTreeHelper(root.Left)
    if !left.balanced {
        return TreeInfo{-1, false}
    }
    right := isBalancedTreeHelper(root.Right)
    if !right.balanced {
        return TreeInfo{-1, false}
    }
    if abs(left.height-right.height) < 2 {
        return TreeInfo{max(left.height, right.height) + 1, true}
    }
    return TreeInfo{-1, false}
}

func isBalanced(root *TreeNode) bool {
    return isBalancedTreeHelper(root).balanced
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// Utility class to store information from recursive calls
final class TreeInfo {
    public final int height;
    public final boolean balanced;

    public TreeInfo(int height, boolean balanced) {
        this.height = height;
        this.balanced = balanced;
    }
}

class Solution {
    // Return whether or not the tree at root is balanced while also storing
    // the tree's height in a reference variable.
    private TreeInfo isBalancedTreeHelper(TreeNode root) {
        // An empty tree is balanced and has height = -1
        if (root == null) {
            return new TreeInfo(-1, true);
        }

        // Check subtrees to see if they are balanced.
        TreeInfo left = isBalancedTreeHelper(root.left);
        if (!left.balanced) {
            return new TreeInfo(-1, false);
        }
        TreeInfo right = isBalancedTreeHelper(root.right);
        if (!right.balanced) {
            return new TreeInfo(-1, false);
        }

        // Use the height obtained from the recursive calls to
        // determine if the current node is also balanced.
        if (Math.abs(left.height - right.height) < 2) {
            return new TreeInfo(Math.max(left.height, right.height) + 1, true);
        }
        return new TreeInfo(-1, false);
    }

    public boolean isBalanced(TreeNode root) {
        return isBalancedTreeHelper(root).balanced;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// Utility class to store information from recursive calls
class TreeInfo {
    constructor(height, balanced) {
        this.height = height;
        this.balanced = balanced;
    }
}
var isBalanced = function (root) {
    // Returns whether the tree at root is balanced, along with the tree's height.
    function isBalancedTreeHelper(root) {
        // An empty tree is balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }
        // Checks whether the subtrees are balanced or not.
        const left = isBalancedTreeHelper(root.left);
        if (!left.balanced) {
            return new TreeInfo(-1, false);
        }
        const right = isBalancedTreeHelper(root.right);
        if (!right.balanced) {
            return new TreeInfo(-1, false);
        }
        // The height obtained from the recursive calls is used to determine
        // whether the current node is balanced.
        if (Math.abs(left.height - right.height) < 2) {
            return new TreeInfo(Math.max(left.height, right.height) + 1, true);
        }
        return new TreeInfo(-1, false);
    }
    return isBalancedTreeHelper(root).balanced;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # Return whether or not the tree at root is balanced while also returning
    # the tree's height
    def isBalancedHelper(self, root: TreeNode) -> (bool, int):
        # An empty tree is balanced and has height -1
        if not root:
            return True, -1

        # Check subtrees to see if they are balanced.
        leftIsBalanced, leftHeight = self.isBalancedHelper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced, rightHeight = self.isBalancedHelper(root.right)
        if not rightIsBalanced:
            return False, 0

        # If the subtrees are balanced, check if the current tree is balanced
        # using their height
        return (abs(leftHeight - rightHeight) < 2), 1 + max(
            leftHeight, rightHeight
        )

    def isBalanced(self, root: TreeNode) -> bool:
        return self.isBalancedHelper(root)[0]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// Utility class to store information from recursive calls
class TreeInfo {
    constructor(
        public height: number,
        public balanced: boolean,
    ) {}
}
function isBalanced(root: TreeNode | null): boolean {
    // Returns whether the tree at root is balanced, along with the tree's height.
    function isBalancedTreeHelper(root: TreeNode | null): TreeInfo {
        // An empty tree is both balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }
        // Checks whether the subtrees are balanced or not.
        const left = isBalancedTreeHelper(root.left);
        if (!left.balanced) {
            return new TreeInfo(-1, false);
        }
        const right = isBalancedTreeHelper(root.right);
        if (!right.balanced) {
            return new TreeInfo(-1, false);
        }
        // The obtained height from recursive calls can also determine
        // that the current node is balanced.
        if (Math.abs(left.height - right.height) < 2) {
            return new TreeInfo(Math.max(left.height, right.height) + 1, true);
        }
        return new TreeInfo(-1, false);
    }
    return isBalancedTreeHelper(root).balanced;
}
```

</details>
