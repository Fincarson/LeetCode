# 98. Validate Binary Search Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/validate-binary-search-tree/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 98 - Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

## Problem

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

### Example 1

```text
Input: root = [2,1,3]
Output: true
```

### Example 2

```text
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -231 <= Node.val <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 98. Validate Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Traversal with Valid Range | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Traversal with Valid Range | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursive Inorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Inorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive Traversal with Valid Range

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool validate(struct TreeNode* root, struct TreeNode* low,
              struct TreeNode* high) {
    // Empty trees are valid BSTs.
    if (root == NULL) {
        return true;
    }
    // The current node's value must be between low and high.
    if ((low != NULL && root->val <= low->val) ||
        (high != NULL && root->val >= high->val)) {
        return false;
    }
    // The left and right subtree must also be valid.
    return validate(root->right, root, high) && validate(root->left, low, root);
}
bool isValidBST(struct TreeNode* root) { return validate(root, NULL, NULL); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) { return validate(root, nullptr, nullptr); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool Validate(TreeNode root, int? low, int? high) {
        // Empty trees are valid BSTs.
        if (root == null) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low.HasValue && root.val <= low.Value) ||
            (high.HasValue && root.val >= high.Value)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return Validate(root.right, root.val, high) &&
               Validate(root.left, low, root.val);
    }

    public bool IsValidBST(TreeNode root) {
        return Validate(root, null, null);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func validate(root *TreeNode, low *int, high *int) bool {
    // Empty trees are valid BSTs.
    if root == nil {
        return true
    }
    // The current node's value must be between low and high.
    if (low != nil && root.Val <= *low) || (high != nil && root.Val >= *high) {
        return false
    }
    // The left and right subtree must also be valid.
    return validate(root.Right, &root.Val, high) &&
        validate(root.Left, low, &root.Val)
}

func isValidBST(root *TreeNode) bool {
    return validate(root, nil, nil)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validate(TreeNode root, Integer low, Integer high) {
        // Empty trees are valid BSTs.
        if (root == null) {
            return true;
        }

        // The current node's value must be between low and high.
        if (
            (low != null && root.val <= low) ||
            (high != null && root.val >= high)
        ) {
            return false;
        }

        // The left and right subtree must also be valid.
        return (
            validate(root.right, root.val, high) &&
            validate(root.left, low, root.val)
        );
    }

    public boolean isValidBST(TreeNode root) {
        return validate(root, null, null);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidBST = function (root, low = null, high = null) {
    // Empty trees are valid BSTs.
    if (!root) return true;
    // The current node's value must be between low and high.
    if ((low != null && root.val <= low) || (high != null && root.val >= high))
        return false;
    // The left and right subtree must also be valid.
    return (
        isValidBST(root.right, root.val, high) &&
        isValidBST(root.left, low, root.val)
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def validate(node, low=-math.inf, high=math.inf):
            # Empty trees are valid BSTs.
            if not node:
                return True

            # The current node's value must be between low and high.
            if node.val <= low or node.val >= high:
                return False

            # The left and right subtree must also be valid.
            return validate(node.right, node.val, high) and validate(
                node.left, low, node.val
            )

        return validate(root)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidBST(
    root: TreeNode | null,
    low: number | null = null,
    high: number | null = null,
): boolean {
    // Empty trees are valid BSTs.
    if (root === null) return true;
    // The current node's value must be between low and high.
    if (
        (low !== null && root.val <= low) ||
        (high !== null && root.val >= high)
    )
        return false;
    // The left and right subtree must also be valid.
    return (
        isValidBST(root.right, root.val, high) &&
        isValidBST(root.left, low, root.val)
    );
}
```

</details>

<br>

## Approach 2: Iterative Traversal with Valid Range

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    struct TreeNode* node;
    long low;
    long high;
} StackNode;
void update(struct TreeNode* root, long low, long high, StackNode* stack,
            int* top) {
    if (root == NULL) return;
    stack[++(*top)] = (StackNode){root, low, high};
}
bool isValidBST(struct TreeNode* root) {
    StackNode stack[10000];
    int top = -1;
    long lower = LONG_MIN, upper = LONG_MAX;
    update(root, lower, upper, stack, &top);
    while (top >= 0) {
        StackNode tmp = stack[top--];
        root = tmp.node;
        if (root == NULL) continue;
        long val = root->val;
        if (val <= tmp.low || val >= tmp.high) return false;
        update(root->right, val, tmp.high, stack, &top);
        update(root->left, tmp.low, val, stack, &top);
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    stack<TreeNode*> stk, lower_limits, upper_limits;

public:
    void update(TreeNode* root, TreeNode* low, TreeNode* high) {
        stk.push(root);
        lower_limits.push(low);
        upper_limits.push(high);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        update(root, low, high);

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            low = lower_limits.top();
            lower_limits.pop();
            high = upper_limits.top();
            upper_limits.pop();

            if (root == nullptr) {
                continue;
            }

            TreeNode* val_node = root;
            if (low != nullptr and val_node->val <= low->val) {
                return false;
            }
            if (high != nullptr and val_node->val >= high->val) {
                return false;
            }
            update(root->right, val_node, high);
            update(root->left, low, val_node);
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    private Stack<int?> lowerLimits = new Stack<int?>();
    private Stack<int?> upperLimits = new Stack<int?>();

    public void Update(TreeNode root, int? low, int? high) {
        stack.Push(root);
        lowerLimits.Push(low);
        upperLimits.Push(high);
    }

    public bool IsValidBST(TreeNode root) {
        int? low = null, high = null;
        Update(root, low, high);
        while (stack.Count > 0) {
            root = stack.Pop();
            low = lowerLimits.Pop();
            high = upperLimits.Pop();
            if (root == null)
                continue;
            int val = root.val;
            if (low != null && val <= low) {
                return false;
            }

            if (high != null && val >= high) {
                return false;
            }

            Update(root.right, val, high);
            Update(root.left, low, val);
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TreeCheck struct {
    Node  *TreeNode
    Lower int
    Upper int
}

func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    stack := []TreeCheck{
        {
            Node:  root,
            Lower: math.MinInt64,
            Upper: math.MaxInt64,
        },
    }
    for len(stack) > 0 {
        node := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if node.Node.Val <= node.Lower || node.Node.Val >= node.Upper {
            return false
        }
        if node.Node.Right != nil {
            stack = append(stack, TreeCheck{
                Node:  node.Node.Right,
                Lower: node.Node.Val,
                Upper: node.Upper,
            })
        }
        if node.Node.Left != nil {
            stack = append(stack, TreeCheck{
                Node:  node.Node.Left,
                Lower: node.Lower,
                Upper: node.Node.Val,
            })
        }
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private Deque<TreeNode> stack = new LinkedList();
    private Deque<Integer> upperLimits = new LinkedList();
    private Deque<Integer> lowerLimits = new LinkedList();

    public void update(TreeNode root, Integer low, Integer high) {
        stack.add(root);
        lowerLimits.add(low);
        upperLimits.add(high);
    }

    public boolean isValidBST(TreeNode root) {
        Integer low = null, high = null, val;
        update(root, low, high);

        while (!stack.isEmpty()) {
            root = stack.poll();
            low = lowerLimits.poll();
            high = upperLimits.poll();

            if (root == null) continue;
            val = root.val;
            if (low != null && val <= low) {
                return false;
            }
            if (high != null && val >= high) {
                return false;
            }
            update(root.right, val, high);
            update(root.left, low, val);
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidBST = function (root) {
    const stack = [],
        lowerLimits = [],
        upperLimits = [];
    function update(node, low, high) {
        stack.push(node);
        lowerLimits.push(low);
        upperLimits.push(high);
    }
    update(root, null, null);
    while (stack.length) {
        node = stack.pop();
        let low = lowerLimits.pop();
        let high = upperLimits.pop();
        if (node === null) continue;
        let val = node.val;
        if (low !== null && val <= low) {
            return false;
        }
        if (high !== null && val >= high) {
            return false;
        }
        update(node.right, val, high);
        update(node.left, low, val);
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True

        stack = [(root, -math.inf, math.inf)]
        while stack:
            root, lower, upper = stack.pop()
            if not root:
                continue
            val = root.val
            if val <= lower or val >= upper:
                return False
            stack.append((root.right, val, upper))
            stack.append((root.left, lower, val))
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidBST(root: TreeNode | null): boolean {
    const stack: (TreeNode | null)[] = [],
        lowerLimits: (number | null)[] = [],
        upperLimits: (number | null)[] = [];
    function update(
        node: TreeNode | null,
        low: number | null,
        high: number | null,
    ) {
        stack.push(node);
        lowerLimits.push(low);
        upperLimits.push(high);
    }
    update(root, null, null);
    while (stack.length > 0) {
        let node = stack.pop()!;
        let low = lowerLimits.pop();
        let high = upperLimits.pop();
        if (node === null) continue;
        let val = node.val;
        if (low !== null && val <= low) {
            return false;
        }
        if (high !== null && val >= high) {
            return false;
        }
        update(node.right, val, high);
        update(node.left, low, val);
    }
    return true;
}
```

</details>

<br>

## Approach 3: Recursive Inorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TreeNode* prev = NULL;
bool inorder(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (!inorder(root->left)) {
        return false;
    }
    if (prev != NULL && root->val <= prev->val) {
        return false;
    }
    prev = root;
    return inorder(root->right);
}
bool isValidBST(struct TreeNode* root) {
    prev = NULL;
    return inorder(root);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    TreeNode* prev = nullptr;

public:
    bool isValidBST(TreeNode* root) { return inorder(root); }

    bool inorder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private int? prev;

    public bool IsValidBST(TreeNode root) {
        prev = null;
        return inorder(root);
    }

    private bool inorder(TreeNode root) {
        if (root == null) {
            return true;
        }

        if (!inorder(root.left)) {
            return false;
        }

        if (prev != null && root.val <= prev) {
            return false;
        }

        prev = root.val;
        return inorder(root.right);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var prev *TreeNode

func inorder(root *TreeNode) bool {
    if root == nil {
        return true
    }
    if !inorder(root.Left) {
        return false
    }
    if prev != nil && root.Val <= prev.Val {
        return false
    }
    prev = root
    return inorder(root.Right)
}

func isValidBST(root *TreeNode) bool {
    prev = nil
    return inorder(root)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // We use Integer instead of int as it supports a null value.
    private Integer prev;

    public boolean isValidBST(TreeNode root) {
        prev = null;
        return inorder(root);
    }

    private boolean inorder(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!inorder(root.left)) {
            return false;
        }
        if (prev != null && root.val <= prev) {
            return false;
        }
        prev = root.val;
        return inorder(root.right);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidBST = function (root) {
    let prev = -Infinity;
    function inorder(node) {
        if (!node) {
            return true;
        }
        if (!inorder(node.left)) {
            return false;
        }
        if (node.val <= prev) {
            return false;
        }
        prev = node.val;
        return inorder(node.right);
    }
    return inorder(root);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:

        def inorder(root):
            if not root:
                return True
            if not inorder(root.left):
                return False
            if root.val <= self.prev:
                return False
            self.prev = root.val
            return inorder(root.right)

        self.prev = -math.inf
        return inorder(root)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidBST(root: TreeNode | null): boolean {
    let prev: number | null = null;
    function inorder(node: TreeNode | null): boolean {
        if (!node) {
            return true;
        }
        if (!inorder(node.left)) {
            return false;
        }
        if (prev !== null && node.val <= prev) {
            return false;
        }
        prev = node.val;
        return inorder(node.right);
    }
    return inorder(root);
}
```

</details>

<br>

## Approach 4: Iterative Inorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[1000];
    struct TreeNode* prev = NULL;
    int top = -1;
    while (root != NULL || top >= 0) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        if (prev != NULL && root->val <= prev->val) {
            return false;
        }
        prev = root;
        root = root->right;
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;

        while (!stk.empty() or root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();

            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (prev != nullptr and root->val <= prev->val) {
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode prev = null;
        while (stack.Count > 0 || root != null) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }

            root = stack.Pop();
            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (prev != null && root.val <= prev.val) {
                return false;
            }

            prev = root;
            root = root.right;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    stack := make([]*TreeNode, 0)
    var prev *TreeNode = nil
    for len(stack) > 0 || root != nil {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        // If next element in inorder traversal
        // is smaller than the previous one
        // that's not BST.
        if prev != nil && root.Val <= prev.Val {
            return false
        }
        prev = root
        root = root.Right
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isValidBST(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        Integer prev = null;

        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();

            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (prev != null && root.val <= prev) {
                return false;
            }
            prev = root.val;
            root = root.right;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isValidBST = function (root) {
    let stack = [];
    let prev = null;
    while (stack.length !== 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        root = stack.pop();
        // If next element in inorder traversal
        // is smaller than the previous one
        // that's not BST.
        if (prev !== null && root.val <= prev) {
            return false;
        }
        prev = root.val;
        root = root.right;
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack, prev = [], -math.inf

        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()

            # If next element in inorder traversal
            # is smaller than the previous one
            # that's not BST.
            if root.val <= prev:
                return False
            prev = root.val
            root = root.right

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isValidBST(root: TreeNode | null): boolean {
    let stack: (TreeNode | null)[] = [];
    let prev: number | null = null;
    while (stack.length !== 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        root = stack.pop();
        // If next element in inorder traversal
        // is smaller than the previous one
        // that's not BST.
        if (prev !== null && root.val <= prev) {
            return false;
        }
        prev = root.val;
        root = root.right;
    }
    return true;
}
```

</details>
