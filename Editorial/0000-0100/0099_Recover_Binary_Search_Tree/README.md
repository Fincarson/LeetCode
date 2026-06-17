# 99. Recover Binary Search Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/recover-binary-search-tree/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 99 - Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

## Problem

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

### Example 1

```text
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```

### Example 2

```text
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
```

## Constraints

- The number of nodes in the tree is in the range [2, 1000].
- -231 <= Node.val <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 99. Recover Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort an Almost Sorted Array Where Two Elements Are Swapped | Java, Python3 |
| Iterative Inorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursive Inorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Morris Inorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sort an Almost Sorted Array Where Two Elements Are Swapped

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public void inorder(TreeNode root, List<Integer> nums) {
    if (root == null) return;
    inorder(root.left, nums);
    nums.add(root.val);
    inorder(root.right, nums);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def inorder(r: TreeNode) -> List[int]:
    return inorder(r.left) + [r.val] + inorder(r.right) if r else []
```

</details>

<br>

## Approach 2: Iterative Inorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void recoverTree(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    struct TreeNode* x = NULL;
    struct TreeNode* y = NULL;
    struct TreeNode* pred = NULL;
    struct TreeNode* node;
    int top = -1;
    while (top >= 0 || root != NULL) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        node = stack[top--];
        if (pred != NULL && node->val < pred->val) {
            y = node;
            if (x == NULL)
                x = pred;
            else
                break;
        }
        pred = node;
        root = node->right;
    }
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode *x = NULL, *y = NULL, *pred = NULL;
        while (!stack.empty() || root != NULL) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (pred != NULL && root->val < pred->val) {
                y = root;
                if (x == NULL)
                    x = pred;
                else
                    break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Swap(ref TreeNode a, ref TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void RecoverTree(TreeNode root) {
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode x = null, y = null, pred = null;
        while (stack.Count != 0 || root != null) {
            while (root != null) {
                stack.Push(root);
                root = root.left;
            }

            root = stack.Pop();
            if (pred != null && root.val < pred.val) {
                y = root;
                if (x == null)
                    x = pred;
                else
                    break;
            }

            pred = root;
            root = root.right;
        }

        Swap(ref x, ref y);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func recoverTree(root *TreeNode) {
    stack := []*TreeNode{}
    var x, y, pred *TreeNode
    for len(stack) > 0 || root != nil {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        root = stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if pred != nil && root.Val < pred.Val {
            y = root
            if x == nil {
                x = pred
            } else {
                break
            }
        }
        pred = root
        root = root.Right
    }
    x.Val, y.Val = y.Val, x.Val
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void swap(TreeNode a, TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void recoverTree(TreeNode root) {
        Deque<TreeNode> stack = new ArrayDeque();
        TreeNode x = null, y = null, pred = null;

        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.add(root);
                root = root.left;
            }
            root = stack.removeLast();
            if (pred != null && root.val < pred.val) {
                y = root;
                if (x == null) x = pred;
                else break;
            }
            pred = root;
            root = root.right;
        }

        swap(x, y);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var recoverTree = function (root) {
    let stack = [],
        x = null,
        y = null,
        pred = null,
        node;
    while (stack.length > 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        node = stack.pop();
        if (pred !== null && node.val < pred.val) {
            y = node;
            if (x === null) x = pred;
            else break;
        }
        pred = node;
        root = node.right;
    }
    [x.val, y.val] = [y.val, x.val];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        stack = []
        x = y = pred = None

        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pred and root.val < pred.val:
                y = root
                if x is None:
                    x = pred
                else:
                    break
            pred = root
            root = root.right

        x.val, y.val = y.val, x.val
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function recoverTree(root: TreeNode | null): void {
    let stack: (TreeNode | null)[] = [],
        x = null,
        y = null,
        pred = null,
        node;
    while (stack.length > 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }
        node = stack.pop();
        if (pred !== null && node.val < pred.val) {
            y = node;
            if (x === null) x = pred;
            else break;
        }
        pred = node;
        root = node.right;
    }
    [x.val, y.val] = [y.val, x.val];
}
```

</details>

<br>

## Approach 3: Recursive Inorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void findTwoSwapped(struct TreeNode *root, struct TreeNode **pred,
                    struct TreeNode **x, struct TreeNode **y) {
    if (root == NULL) return;
    findTwoSwapped(root->left, pred, x, y);
    if (*pred != NULL && root->val < (*pred)->val) {
        *y = root;
        if (*x == NULL)
            *x = *pred;
        else
            return;
    }
    *pred = root;
    findTwoSwapped(root->right, pred, x, y);
}
void recoverTree(struct TreeNode *root) {
    struct TreeNode *pred = NULL, *x = NULL, *y = NULL;
    findTwoSwapped(root, &pred, &x, &y);
    // Swap x and y values
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* x = nullptr;     // first node
    TreeNode* y = nullptr;     // second node
    TreeNode* pred = nullptr;  // predecessor node
    void findTwoSwapped(TreeNode* root) {
        if (root == nullptr) return;
        findTwoSwapped(root->left);
        if (pred != nullptr && root->val < pred->val) {
            y = root;
            if (x == nullptr)
                x = pred;
            else
                return;
        }
        pred = root;
        findTwoSwapped(root->right);
    }
    void recoverTree(TreeNode* root) {
        findTwoSwapped(root);
        swap(x->val, y->val);  // C++ standard swap function
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private TreeNode x = null, y = null, pred = null;

    private void FindTwoSwapped(TreeNode root) {
        if (root == null)
            return;
        FindTwoSwapped(root.left);
        if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null)
                x = pred;
            else
                return;
        }

        pred = root;
        FindTwoSwapped(root.right);
    }

    public void RecoverTree(TreeNode root) {
        FindTwoSwapped(root);
        int tmp = x.val;
        x.val = y.val;
        y.val = tmp;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func recoverTree(root *TreeNode) {
    var x, y, pred *TreeNode
    findTwoSwapped(root, &x, &y, &pred)
    // Swap x and y values
    x.Val, y.Val = y.Val, x.Val
}

func findTwoSwapped(root *TreeNode, x, y, pred **TreeNode) {
    if root == nil {
        return
    }
    findTwoSwapped(root.Left, x, y, pred)
    if *pred != nil && root.Val < (*pred).Val {
        *y = root
        if *x == nil {
            *x = *pred
        } else {
            return
        }
    }
    *pred = root
    findTwoSwapped(root.Right, x, y, pred)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    TreeNode x = null, y = null, pred = null;

    public void swap(TreeNode a, TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void findTwoSwapped(TreeNode root) {
        if (root == null) return;
        findTwoSwapped(root.left);
        if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null) x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }

    public void recoverTree(TreeNode root) {
        findTwoSwapped(root);
        swap(x, y);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var recoverTree = function (root) {
    // first node
    let x = null;
    // second node
    let y = null;
    // predecessor node
    let pred = null;
    function findTwoSwapped(root) {
        if (root === null) return;
        findTwoSwapped(root.left);
        if (pred !== null && root.val < pred.val) {
            y = root;
            if (x === null) x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }
    findTwoSwapped(root);
    // Swap x and y values
    [x.val, y.val] = [y.val, x.val];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        def find_two_swapped(root: TreeNode):
            nonlocal x, y, pred
            if root is None:
                return

            find_two_swapped(root.left)
            if pred and root.val < pred.val:
                y = root
                # The first swap occurence
                if x is None:
                    x = pred
                # The second swap occurence
                else:
                    return
            pred = root
            find_two_swapped(root.right)

        x = y = pred = None
        find_two_swapped(root)
        x.val, y.val = y.val, x.val
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function recoverTree(root: TreeNode | null): void {
    // first node
    let x: TreeNode | null = null;
    // second node
    let y: TreeNode | null = null;
    // predecessor node
    let pred: TreeNode | null = null;
    function findTwoSwapped(root: TreeNode | null): void {
        if (root === null) return;
        findTwoSwapped(root.left);
        if (pred !== null && root.val < pred.val) {
            y = root;
            if (x === null) x = pred;
            else return;
        }
        pred = root;
        findTwoSwapped(root.right);
    }
    findTwoSwapped(root);
    // Swap x and y values
    [x.val, y.val] = [y.val, x.val];
}
```

</details>

<br>

## Approach 4: Morris Inorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct TreeNode TreeNode;
void swap(TreeNode* a, TreeNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
void recoverTree(TreeNode* root) {
    TreeNode* x = NULL;
    TreeNode* y = NULL;
    TreeNode* pred = NULL;
    TreeNode* predecessor = NULL;
    while (root != NULL) {
        if (root->left != NULL) {
            predecessor = root->left;
            while (predecessor->right != NULL && predecessor->right != root) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = root;
                root = root->left;
            } else {
                if (pred != NULL && root->val < pred->val) {
                    y = root;
                    if (x == NULL) x = pred;
                }
                pred = root;
                predecessor->right = NULL;
                root = root->right;
            }
        } else {
            if (pred != NULL && root->val < pred->val) {
                y = root;
                if (x == NULL) x = pred;
            }
            pred = root;
            root = root->right;
        }
    }
    swap(x, y);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void swap(TreeNode* a, TreeNode* b) {
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
    void recoverTree(TreeNode* root) {
        // predecessor is a Morris predecessor.
        // In the 'loop' cases it could be equal to the node itself predecessor
        // == root. pred is a 'true' predecessor, the previous node in the
        // inorder traversal.
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr,
                 *predecessor = nullptr;
        while (root != nullptr) {
            // If there is a left child
            // then compute the predecessor.
            // If there is no link predecessor->right = root --> set it.
            // If there is a link predecessor->right = root --> break it.
            if (root->left != nullptr) {
                // Predecessor node is one step left
                // and then right till you can.
                predecessor = root->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != root)
                    predecessor = predecessor->right;
                // Set the link predecessor->right = root
                // and go to explore left subtree
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // Break the link predecessor->right = root
                // link is broken : time to change subtree and go right
                else {
                    // Check for the swapped nodes
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) x = pred;
                    }
                    pred = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // If there is no left child
            // then just go right.
            else {
                // Check for the swapped nodes
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) x = pred;
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x, y);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Swap(TreeNode a, TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void RecoverTree(TreeNode root) {
        // predecessor is a Morris predecessor.
        // In the 'loop' cases it could be equal to the node itself predecessor
        // == root. pred is a 'true' predecessor, the previous node in the
        // inorder traversal.
        TreeNode x = null, y = null, pred = null, predecessor = null;
        while (root != null) {
            // If there is a left child
            // then compute the predecessor.
            // If there is no link predecessor.right = root --> set it.
            // If there is a link predecessor.right = root --> break it.
            if (root.left != null) {
                // Predecessor node is one step left
                // and then right till you can.
                predecessor = root.left;
                while (predecessor.right != null && predecessor.right != root)
                    predecessor = predecessor.right;
                // Set the link predecessor.right = root
                // and go to explore left subtree
                if (predecessor.right == null) {
                    predecessor.right = root;
                    root = root.left;
                }
                // Break the link predecessor.right = root
                // link is broken : time to change subtree and go right
                else {
                    // Check for the swapped nodes
                    if (pred != null && root.val < pred.val) {
                        y = root;
                        if (x == null)
                            x = pred;
                    }

                    pred = root;
                    predecessor.right = null;
                    root = root.right;
                }
            }
            // If there is no left child
            // then just go right.
            else {
                // Check for the swapped nodes
                if (pred != null && root.val < pred.val) {
                    y = root;
                    if (x == null)
                        x = pred;
                }

                pred = root;
                root = root.right;
            }
        }

        Swap(x, y);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func swap(a *TreeNode, b *TreeNode) {
    a.Val, b.Val = b.Val, a.Val
}

func recoverTree(root *TreeNode) {
    var x, y, pred, predecessor *TreeNode
    for root != nil {
        if root.Left != nil {
            predecessor = root.Left
            for predecessor.Right != nil && predecessor.Right != root {
                predecessor = predecessor.Right
            }
            if predecessor.Right == nil {
                predecessor.Right = root
                root = root.Left
            } else {
                if pred != nil && root.Val < pred.Val {
                    y = root
                    if x == nil {
                        x = pred
                    }
                }
                pred = root
                predecessor.Right = nil
                root = root.Right
            }
        } else {
            if pred != nil && root.Val < pred.Val {
                y = root
                if x == nil {
                    x = pred
                }
            }
            pred = root
            root = root.Right
        }
    }
    swap(x, y)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void swap(TreeNode a, TreeNode b) {
        int tmp = a.val;
        a.val = b.val;
        b.val = tmp;
    }

    public void recoverTree(TreeNode root) {
        // predecessor is a Morris predecessor.
        // In the 'loop' cases it could be equal to the node itself predecessor == root.
        // pred is a 'true' predecessor,
        // the previous node in the inorder traversal.
        TreeNode x = null, y = null, pred = null, predecessor = null;

        while (root != null) {
            // If there is a left child
            // then compute the predecessor.
            // If there is no link predecessor.right = root --> set it.
            // If there is a link predecessor.right = root --> break it.
            if (root.left != null) {
                // Predecessor node is one step left
                // and then right till you can.
                predecessor = root.left;
                while (
                    predecessor.right != null && predecessor.right != root
                ) predecessor = predecessor.right;

                // Set the link predecessor.right = root
                // and go to explore left subtree
                if (predecessor.right == null) {
                    predecessor.right = root;
                    root = root.left;
                }
                // Break the link predecessor.right = root
                // link is broken : time to change subtree and go right
                else {
                    // Check for the swapped nodes
                    if (pred != null && root.val < pred.val) {
                        y = root;
                        if (x == null) x = pred;
                    }
                    pred = root;

                    predecessor.right = null;
                    root = root.right;
                }
            }
            // If there is no left child
            // then just go right.
            else {
                // Check for the swapped nodes
                if (pred != null && root.val < pred.val) {
                    y = root;
                    if (x == null) x = pred;
                }
                pred = root;

                root = root.right;
            }
        }
        swap(x, y);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var recoverTree = function (root) {
    // predecessor is a Morris predecessor.
    // In the 'loop' cases it could be equal to the node itself predecessor == root.
    // pred is a 'true' predecessor,
    // the previous node in the inorder traversal.
    var x = null,
        y = null,
        pred = null,
        predecessor = null;
    while (root !== null) {
        // If there is a left child
        // then compute the predecessor.
        // If there is no link predecessor.right = root --> set it.
        // If there is a link predecessor.right = root --> break it.
        if (root.left !== null) {
            // Predecessor node is one step left
            // and then right till you can.
            predecessor = root.left;
            while (predecessor.right !== null && predecessor.right !== root)
                predecessor = predecessor.right;
            // Set the link predecessor.right = root
            // and go to explore left subtree
            if (predecessor.right === null) {
                predecessor.right = root;
                root = root.left;
            }
            // Break the link predecessor.right = root
            // link is broken : time to change subtree and go right
            else {
                // Check for the swapped nodes
                if (pred !== null && root.val < pred.val) {
                    y = root;
                    if (x === null) x = pred;
                }
                pred = root;
                predecessor.right = null;
                root = root.right;
            }
        }
        // If there is no left child
        // then just go right.
        else {
            // Check for the swapped nodes
            if (pred !== null && root.val < pred.val) {
                y = root;
                if (x === null) x = pred;
            }
            pred = root;
            root = root.right;
        }
    }
    var tmp = x.val;
    x.val = y.val;
    y.val = tmp;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        # The predecessor is a Morris predecessor.
        # In the 'loop' cases it could be equal to the node itself predecessor == root.
        # pred is a 'true' predecessor,
        # the previous node in the inorder traversal.
        x = y = predecessor = pred = None

        while root:
            # If there is a left child
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left:
                # Predecessor node is one step left
                # and then right till you can.
                predecessor = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right

                # Set the link predecessor.right = root
                # and go to explore left subtree
                if predecessor.right is None:
                    predecessor.right = root
                    root = root.left
                # Break the link predecessor.right = root
                # link is broken : time to change subtree and go right
                else:
                    # check for the swapped nodes
                    if pred and root.val < pred.val:
                        y = root
                        if x is None:
                            x = pred
                    pred = root

                    predecessor.right = None
                    root = root.right
            # If there is no left child
            # then just go right.
            else:
                # Check for the swapped nodes
                if pred and root.val < pred.val:
                    y = root
                    if x is None:
                        x = pred
                pred = root

                root = root.right

        x.val, y.val = y.val, x.val
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function recoverTree(root: TreeNode | null): void {
    // predecessor is a Morris predecessor.
    // In the 'loop' cases it could be equal to the node itself predecessor == root.
    // pred is a 'true' predecessor,
    // the previous node in the inorder traversal.
    let x: TreeNode | null = null,
        y: TreeNode | null = null,
        pred: TreeNode | null = null,
        predecessor: TreeNode | null = null;
    while (root !== null) {
        // If there is a left child
        // then compute the predecessor.
        // If there is no link predecessor.right = root --> set it.
        // If there is a link predecessor.right = root --> break it.
        if (root.left !== null) {
            // Predecessor node is one step left
            // and then right till you can.
            predecessor = root.left;
            while (predecessor.right !== null && predecessor.right !== root)
                predecessor = predecessor.right;
            // Set the link predecessor.right = root
            // and go to explore left subtree
            if (predecessor.right === null) {
                predecessor.right = root;
                root = root.left;
            }
            // Break the link predecessor.right = root
            // link is broken : time to change subtree and go right
            else {
                // Check for the swapped nodes
                if (pred !== null && root.val < pred.val) {
                    y = root;
                    if (x === null) x = pred;
                }
                pred = root;
                predecessor.right = null;
                root = root.right;
            }
        }
        // If there is no left child
        // then just go right.
        else {
            // Check for the swapped nodes
            if (pred !== null && root.val < pred.val) {
                y = root;
                if (x === null) x = pred;
            }
            pred = root;
            root = root.right;
        }
    }
    let tmp = x.val;
    x.val = y.val;
    y.val = tmp;
}
```

</details>
