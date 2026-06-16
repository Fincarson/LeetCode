# 129. Sum Root to Leaf Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sum-root-to-leaf-numbers/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 129 - Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

## Problem

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

- For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

### Example 1

```text
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
```

### Example 2

```text
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- 0 <= Node.val <= 9
- The depth of the tree will not exceed 10.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum](https://leetcode.com/problems/path-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 129. Sum Root to Leaf Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Preorder Traversal. | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursive Preorder Traversal. | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Morris Preorder Traversal. | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Iterative Preorder Traversal.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    struct TreeNode* node;
    int partialSum;
} StackNode;
int sumNumbers(struct TreeNode* root) {
    if (root == NULL) return 0;
    StackNode myStack[10000] = {0};
    int top = -1;
    myStack[++top] = (StackNode){root, root->val};
    int rootToLeaf = 0;
    while (top >= 0) {
        StackNode p = myStack[top--];
        root = p.node;
        int currNumber = p.partialSum;
        if (root->left == NULL && root->right == NULL)
            rootToLeaf += currNumber;
        else {
            if (root->right != NULL)
                myStack[++top] = (StackNode){
                    root->right, currNumber * 10 + root->right->val};
            if (root->left != NULL)
                myStack[++top] =
                    (StackNode){root->left, currNumber * 10 + root->left->val};
        }
    }
    return rootToLeaf;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int rootToLeaf = 0, currNumber = 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 0));
        while (!stk.empty()) {
            pair<TreeNode*, int> p = stk.top();
            stk.pop();
            root = p.first;
            currNumber = p.second;
            if (root != nullptr) {
                currNumber = currNumber * 10 + root->val;
                // if it's a leaf, update root-to-leaf sum
                if (root->left == nullptr && root->right == nullptr) {
                    rootToLeaf += currNumber;
                } else {
                    stk.push(make_pair(root->right, currNumber));
                    stk.push(make_pair(root->left, currNumber));
                }
            }
        }
        return rootToLeaf;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        Stack<KeyValuePair<TreeNode, int>> stack =
            new Stack<KeyValuePair<TreeNode, int>>();
        stack.Push(new KeyValuePair<TreeNode, int>(root, 0));
        while (stack.Count > 0) {
            KeyValuePair<TreeNode, int> p = stack.Pop();
            root = p.Key;
            currNumber = p.Value;
            if (root != null) {
                currNumber = currNumber * 10 + root.val;
                // if it's a leaf, update root-to-leaf sum
                if (root.left == null && root.right == null) {
                    rootToLeaf += currNumber;
                } else {
                    stack.Push(new KeyValuePair<TreeNode, int>(root.right,
                                                               currNumber));
                    stack.Push(
                        new KeyValuePair<TreeNode, int>(root.left, currNumber));
                }
            }
        }

        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type item struct {
    node *TreeNode
    sum  int
}

func sumNumbers(root *TreeNode) int {
    if root == nil {
        return 0
    }
    stack := []*item{{root, root.Val}}
    rootToLeaf := 0
    for len(stack) > 0 {
        n := len(stack) - 1
        i := stack[n]
        stack = stack[:n]
        if i.node.Left == nil && i.node.Right == nil {
            rootToLeaf += i.sum
        } else {
            cur := i.sum * 10
            if i.node.Left != nil {
                stack = append(stack, &item{i.node.Left, cur + i.node.Left.Val})
            }
            if i.node.Right != nil {
                stack = append(stack, &item{i.node.Right, cur + i.node.Right.Val})
            }
        }
    }
    return rootToLeaf
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque();
        stack.push(new Pair(root, 0));

        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> p = stack.pop();
            root = p.getKey();
            currNumber = p.getValue();

            if (root != null) {
                currNumber = currNumber * 10 + root.val;
                // if it's a leaf, update root-to-leaf sum
                if (root.left == null && root.right == null) {
                    rootToLeaf += currNumber;
                } else {
                    stack.push(new Pair(root.right, currNumber));
                    stack.push(new Pair(root.left, currNumber));
                }
            }
        }
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sumNumbers = function (root) {
    let rootToLeaf = 0,
        currNumber = 0;
    const stack = [];
    stack.push([root, 0]);
    while (stack.length > 0) {
        const p = stack.pop();
        root = p[0];
        currNumber = p[1];
        if (root !== null) {
            currNumber = currNumber * 10 + root.val;
            // if it's a leaf, update root-to-leaf sum
            if (root.left === null && root.right === null) {
                rootToLeaf += currNumber;
            } else {
                stack.push([root.right, currNumber]);
                stack.push([root.left, currNumber]);
            }
        }
    }
    return rootToLeaf;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        root_to_leaf: int = 0
        stack = [(root, 0)]

        while stack:
            root, curr_number = stack.pop()
            if root is not None:
                curr_number = curr_number * 10 + root.val
                # if it's a leaf, update root-to-leaf sum
                if root.left is None and root.right is None:
                    root_to_leaf += curr_number
                else:
                    stack.append((root.right, curr_number))
                    stack.append((root.left, curr_number))

        return root_to_leaf
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumNumbers(root: TreeNode | null): number {
    let rootToLeaf = 0,
        currNumber = 0;
    const stack: Array<[TreeNode | null, number]> = [];
    stack.push([root, 0]);
    while (stack.length > 0) {
        const p = stack.pop();
        root = p![0]!;
        currNumber = p![1]!;
        if (root !== null) {
            currNumber = currNumber * 10 + root.val;
            // if it's a leaf, update root-to-leaf sum
            if (root.left === null && root.right === null) {
                rootToLeaf += currNumber;
            } else {
                stack.push([root.right, currNumber]);
                stack.push([root.left, currNumber]);
            }
        }
    }
    return rootToLeaf;
}
```

</details>

<br>

## Approach 2: Recursive Preorder Traversal.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C symbolic Node structure for the Leetcode Playground environment
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
void preorder(struct TreeNode* r, int currNumber, int* rootToLeaf) {
    if (r != NULL) {
        currNumber = currNumber * 10 + r->val;
        // if it's a leaf, update root-to-leaf sum
        if (r->left == NULL && r->right == NULL) *rootToLeaf += currNumber;
        preorder(r->left, currNumber, rootToLeaf);
        preorder(r->right, currNumber, rootToLeaf);
    }
}
int sumNumbers(struct TreeNode* root) {
    int rootToLeaf = 0;
    preorder(root, 0, &rootToLeaf);
    return rootToLeaf;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void preorder(TreeNode* r, int currNumber, int& rootToLeaf) {
        if (r != NULL) {
            currNumber = currNumber * 10 + r->val;
            // if it's a leaf, update root-to-leaf sum
            if (r->left == NULL && r->right == NULL) rootToLeaf += currNumber;
            preorder(r->left, currNumber, rootToLeaf);
            preorder(r->right, currNumber, rootToLeaf);
        }
    }
    int sumNumbers(TreeNode* root) {
        int rootToLeaf = 0;
        preorder(root, 0, rootToLeaf);
        return rootToLeaf;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    int rootToLeaf = 0;

    public void Preorder(TreeNode r, int currNumber) {
        if (r != null) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (r.left == null && r.right == null)
                rootToLeaf += currNumber;
            Preorder(r.left, currNumber);
            Preorder(r.right, currNumber);
        }
    }

    public int SumNumbers(TreeNode root) {
        Preorder(root, 0);
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumNumbers(root *TreeNode) int {
    var preorder func(r *TreeNode, currNumber int)
    rootToLeaf := 0
    preorder = func(r *TreeNode, currNumber int) {
        if r != nil {
            currNumber = currNumber*10 + r.Val
            // if it's a leaf, update root-to-leaf sum
            if r.Left == nil && r.Right == nil {
                rootToLeaf += currNumber
            }
            preorder(r.Left, currNumber)
            preorder(r.Right, currNumber)
        }
    }
    preorder(root, 0)
    return rootToLeaf
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int rootToLeaf = 0;

    public void preorder(TreeNode r, int currNumber) {
        if (r != null) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (r.left == null && r.right == null) {
                rootToLeaf += currNumber;
            }
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }

    public int sumNumbers(TreeNode root) {
        preorder(root, 0);
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sumNumbers = function (root) {
    function preorder(r, currNumber) {
        if (r) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (!r.left && !r.right) rootToLeaf += currNumber;
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }
    var rootToLeaf = 0;
    preorder(root, 0);
    return rootToLeaf;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        def preorder(r: TreeNode, curr_number: int) -> None:
            nonlocal root_to_leaf
            if r:
                curr_number = curr_number * 10 + r.val
                # if it's a leaf, update root-to-leaf sum
                if not (r.left or r.right):
                    root_to_leaf += curr_number

                preorder(r.left, curr_number)
                preorder(r.right, curr_number)

        root_to_leaf = 0
        preorder(root, 0)
        return root_to_leaf
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumNumbers(root: TreeNode | null): number {
    function preorder(r: TreeNode | null, currNumber: number) {
        if (r) {
            currNumber = currNumber * 10 + r.val;
            // if it's a leaf, update root-to-leaf sum
            if (!r.left && !r.right) rootToLeaf += currNumber;
            preorder(r.left, currNumber);
            preorder(r.right, currNumber);
        }
    }
    let rootToLeaf = 0;
    preorder(root, 0);
    return rootToLeaf;
}
```

</details>

<br>

## Approach 3: Morris Preorder Traversal.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int sumNumbers(struct TreeNode* root) {
    int root_to_leaf = 0, curr_number = 0;
    int steps;
    struct TreeNode* predecessor;
    while (root != NULL) {
        if (root->left != NULL) {
            predecessor = root->left;
            steps = 1;
            while (predecessor->right != NULL && predecessor->right != root) {
                predecessor = predecessor->right;
                ++steps;
            }
            if (predecessor->right == NULL) {
                curr_number = curr_number * 10 + root->val;
                predecessor->right = root;
                root = root->left;
            } else {
                if (predecessor->left == NULL) {
                    root_to_leaf += curr_number;
                }
                for (int i = 0; i < steps; ++i) {
                    curr_number /= 10;
                }
                predecessor->right = NULL;
                root = root->right;
            }
        } else {
            curr_number = curr_number * 10 + root->val;
            if (root->right == NULL) {
                root_to_leaf += curr_number;
            }
            root = root->right;
        }
    }
    return root_to_leaf;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int root_to_leaf = 0, curr_number = 0;
        int steps;
        TreeNode* predecessor;
        while (root != NULL) {
            if (root->left != NULL) {
                predecessor = root->left;
                steps = 1;
                while (predecessor->right != NULL &&
                       predecessor->right != root) {
                    predecessor = predecessor->right;
                    ++steps;
                }
                if (predecessor->right == NULL) {
                    curr_number = curr_number * 10 + root->val;
                    predecessor->right = root;
                    root = root->left;
                } else {
                    if (predecessor->left == NULL) {
                        root_to_leaf += curr_number;
                    }
                    for (int i = 0; i < steps; ++i) {
                        curr_number /= 10;
                    }
                    predecessor->right = NULL;
                    root = root->right;
                }
            } else {
                curr_number = curr_number * 10 + root->val;
                if (root->right == NULL) {
                    root_to_leaf += curr_number;
                }
                root = root->right;
            }
        }
        return root_to_leaf;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int SumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        int steps;
        TreeNode predecessor;
        while (root != null) {
            if (root.left != null) {
                predecessor = root.left;
                steps = 1;
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                    ++steps;
                }

                if (predecessor.right == null) {
                    currNumber = currNumber * 10 + root.val;
                    predecessor.right = root;
                    root = root.left;
                } else {
                    if (predecessor.left == null) {
                        rootToLeaf += currNumber;
                    }

                    for (int i = 0; i < steps; ++i) {
                        currNumber /= 10;
                    }

                    predecessor.right = null;
                    root = root.right;
                }
            } else {
                currNumber = currNumber * 10 + root.val;
                if (root.right == null) {
                    rootToLeaf += currNumber;
                }

                root = root.right;
            }
        }

        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sumNumbers(root *TreeNode) int {
    root_to_leaf, curr_number, steps := 0, 0, 0
    var predecessor *TreeNode
    for root != nil {
        if root.Left != nil {
            predecessor = root.Left
            steps = 1
            for predecessor.Right != nil && predecessor.Right != root {
                predecessor = predecessor.Right
                steps++
            }
            if predecessor.Right == nil {
                curr_number = curr_number*10 + root.Val
                predecessor.Right = root
                root = root.Left
            } else {
                if predecessor.Left == nil {
                    root_to_leaf += curr_number
                }
                for i := 0; i < steps; i++ {
                    curr_number /= 10
                }
                predecessor.Right = nil
                root = root.Right
            }
        } else {
            curr_number = curr_number*10 + root.Val
            if root.Right == nil {
                root_to_leaf += curr_number
            }
            root = root.Right
        }
    }
    return root_to_leaf
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumNumbers(TreeNode root) {
        int rootToLeaf = 0, currNumber = 0;
        int steps;
        TreeNode predecessor;

        while (root != null) {
            // If there is a left child,
            // then compute the predecessor.
            // If there is no link predecessor.right = root --> set it.
            // If there is a link predecessor.right = root --> break it.
            if (root.left != null) {
                // Predecessor node is one step to the left
                // and then to the right till you can.
                predecessor = root.left;
                steps = 1;
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                    ++steps;
                }

                // Set link predecessor.right = root
                // and go to explore the left subtree
                if (predecessor.right == null) {
                    currNumber = currNumber * 10 + root.val;
                    predecessor.right = root;
                    root = root.left;
                }
                // Break the link predecessor.right = root
                // Once the link is broken,
                // it's time to change subtree and go to the right
                else {
                    // If you're on the leaf, update the sum
                    if (predecessor.left == null) {
                        rootToLeaf += currNumber;
                    }
                    // This part of tree is explored, backtrack
                    for (int i = 0; i < steps; ++i) {
                        currNumber /= 10;
                    }
                    predecessor.right = null;
                    root = root.right;
                }
            }
            // If there is no left child
            // then just go right.
            else {
                currNumber = currNumber * 10 + root.val;
                // if you're on the leaf, update the sum
                if (root.right == null) {
                    rootToLeaf += currNumber;
                }
                root = root.right;
            }
        }
        return rootToLeaf;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function sumNumbers(root, partialSum = 0) {
    if (!root) {
        return 0;
    }
    partialSum = partialSum * 10 + root.val;
    if (!root.left && !root.right) {
        return partialSum;
    }
    return (
        sumNumbers(root.left, partialSum) + sumNumbers(root.right, partialSum)
    );
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        root_to_leaf = curr_number = 0

        while root:
            # If there is a left child,
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left:
                # Predecessor node is one step to the left
                # and then to the right till you can.
                predecessor = root.left
                steps = 1
                while predecessor.right and predecessor.right is not root:
                    predecessor = predecessor.right
                    steps += 1

                # Set link predecessor.right = root
                # and go to explore the left subtree
                if predecessor.right is None:
                    curr_number = curr_number * 10 + root.val
                    predecessor.right = root
                    root = root.left
                # Break the link predecessor.right = root
                # Once the link is broken,
                # it's time to change subtree and go to the right
                else:
                    # If you're on the leaf, update the sum
                    if predecessor.left is None:
                        root_to_leaf += curr_number
                    # This part of tree is explored, backtrack
                    for _ in range(steps):
                        curr_number //= 10
                    predecessor.right = None
                    root = root.right

            # If there is no left child
            # then just go right.
            else:
                curr_number = curr_number * 10 + root.val
                # if you're on the leaf, update the sum
                if root.right is None:
                    root_to_leaf += curr_number
                root = root.right

        return root_to_leaf
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sumNumbers(root: TreeNode | null, partialSum: number = 0): number {
    if (!root) {
        return 0;
    }
    partialSum = partialSum * 10 + root.val;
    if (!root.left && !root.right) {
        return partialSum;
    }
    return (
        sumNumbers(root.left, partialSum) + sumNumbers(root.right, partialSum)
    );
}
```

</details>
