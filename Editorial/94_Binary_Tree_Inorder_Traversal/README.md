# 94. Binary Tree Inorder Traversal

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/binary-tree-inorder-traversal/)  
`Stack` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 94 - Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

## Problem

Given the root of a binary tree, return the inorder traversal of its nodes' values.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 94. Binary Tree Inorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach | C++, Go, Java, JavaScript, Python3, TypeScript |
| Iterating method using Stack | C++, Go, Java, JavaScript, Python3, TypeScript |
| Morris Traversal | C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res) {
        if (root != NULL) {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
};
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
func inorderTraversal(root *TreeNode) []int {
    res := make([]int, 0)
    helper(root, &res)
    return res
}

func helper(root *TreeNode, res *[]int) {
    if root != nil {
        helper(root.Left, res)
        *res = append(*res, root.Val)
        helper(root.Right, res)
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        helper(root, res);
        return res;
    }

    public void helper(TreeNode root, List<Integer> res) {
        if (root != null) {
            helper(root.left, res);
            res.add(root.val);
            helper(root.right, res);
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let res = [];
    helper(root, res);
    return res;
};
var helper = function (root, res) {
    if (root !== null) {
        helper(root.left, res);
        res.push(root.val);
        helper(root.right, res);
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root):
        res = []
        self.helper(root, res)
        return res

    def helper(self, root, res):
        if root is not None:
            self.helper(root.left, res)
            res.append(root.val)
            self.helper(root.right, res)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inorderTraversal(root: TreeNode | null): number[] {
    let res: number[] = [];
    helper(root, res);
    return res;
}
function helper(root: TreeNode | null, res: number[]) {
    if (root !== null) {
        helper(root.left, res);
        res.push(root.val);
        helper(root.right, res);
    }
}
```

</details>

<br>

## Approach 2: Iterating method using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (curr != NULL || !stack.empty()) {
            while (curr != NULL) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};
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
func inorderTraversal(root *TreeNode) []int {
    var res []int
    var stack []*TreeNode
    curr := root
    for curr != nil || len(stack) != 0 {
        for curr != nil {
            stack = append(stack, curr)
            curr = curr.Left
        }
        curr = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        res = append(res, curr.Val)
        curr = curr.Right
    }
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let res = [];
    let stack = [];
    let curr = root;
    while (curr !== null || stack.length !== 0) {
        while (curr !== null) {
            stack.push(curr);
            curr = curr.left;
        }
        curr = stack.pop();
        res.push(curr.val);
        curr = curr.right;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inorderTraversal(root: TreeNode | null): number[] {
    let res: number[] = [];
    let stack: (TreeNode | null)[] = [];
    let curr: TreeNode | null = root;
    while (curr !== null || stack.length !== 0) {
        while (curr !== null) {
            stack.push(curr);
            curr = curr.left;
        }
        curr = stack.pop()!;
        res.push(curr.val);
        curr = curr.right;
    }
    return res;
}
```

</details>

<br>

## Approach 3: Morris Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                res.push_back(curr->val);
                curr = curr->right;  // move to next right node
            } else {
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {  // find rightmost
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    // establish a link back to the current node
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // restore the tree structure
                    pre->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
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

func inorderTraversal(root *TreeNode) []int {
    res := []int{}
    curr := root
    var pre *TreeNode
    for curr != nil {
        if curr.Left == nil {
            res = append(res, curr.Val)
            curr = curr.Right // move to next right node
        } else { // has a left subtree
            pre = curr.Left
            for pre.Right != nil && pre.Right != curr { // find rightmost
                pre = pre.Right
            }
            if pre.Right == nil { // if the rightmost node's right child is nil
                pre.Right = curr // put current after the pre node
                curr = curr.Left // move curr to the top of the new tree
            } else { // the rightmost node's right child is not null
                pre.Right = nil             // restore the tree
                res = append(res, curr.Val) // add current value to the result list
                curr = curr.Right           // move current node to the right
            }
        }
    }
    return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;

        while (curr != null) {
            if (curr.left == null) {
                res.add(curr.val);
                curr = curr.right; // move to next right node
            } else { // has a left subtree
                pre = curr.left;
                // Find the rightmost node in the left subtree, or the node that already points to curr
                while (pre.right != null && pre.right != curr) {
                    pre = pre.right;
                }
                
                if (pre.right == null) { 
                    // Establish a temporary thread back to the current node
                    pre.right = curr;
                    curr = curr.left;
                } else { 
                    // The thread already exists, which means we've returned to curr after visiting left subtree
                    pre.right = null; // Restore the tree
                    res.add(curr.val); // Add the current node to result
                    curr = curr.right; // Move to the right subtree
                }
            }
        }
        
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    let res = [];
    let curr = root;
    let pre;

    while (curr != null) {
        if (curr.left == null) {
            res.push(curr.val);
            curr = curr.right; // move to next right node
        } else {
            pre = curr.left;
            while (pre.right != null && pre.right != curr) { // find rightmost
                pre = pre.right;
            }

            if (pre.right == null) {
                // establish a link back to the current node
                pre.right = curr;
                curr = curr.left;
            } else {
                // restore the tree structure
                pre.right = null;
                res.push(curr.val);
                curr = curr.right;
            }
        }
    }

    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        curr = root

        while curr is not None:
            if curr.left is None:
                res.append(curr.val)
                curr = curr.right  # move to next right node
            else:
                pre = curr.left
                while pre.right is not None and pre.right != curr:  # find rightmost
                    pre = pre.right

                if pre.right is None:
                    # establish a link back to the current node
                    pre.right = curr
                    curr = curr.left
                else:
                    # restore the tree structure
                    pre.right = None
                    res.append(curr.val)
                    curr = curr.right

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inorderTraversal(root: TreeNode | null): number[] {
    let res: number[] = [];
    let curr = root;
    let pre;

    while (curr != null) {
        if (curr.left == null) {
            res.push(curr.val);
            curr = curr.right; // move to next right node
        } else {
            pre = curr.left;
            while (pre.right != null && pre.right !== curr) { // find rightmost
                pre = pre.right;
            }

            if (pre.right === null) {
                // establish a link back to the current node
                pre.right = curr;
                curr = curr.left;
            } else {
                // restore the tree structure
                pre.right = null;
                res.push(curr.val);
                curr = curr.right;
            }
        }
    }

    return res;
}
```

</details>
