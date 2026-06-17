# 114. Flatten Binary Tree to Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)  
`Linked List` `Stack` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 114 - Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## Problem

Given the root of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
- The "linked list" should be in the same order as a pre-order traversal of the binary tree.

### Example 1

```text
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
```

### Example 2

```text
Input: root = []
Output: []
```

### Example 3

```text
Input: root = [0]
Output: [0]
```

## Constraints

- The number of nodes in the tree is in the range [0, 2000].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Correct a Binary Tree](https://leetcode.com/problems/correct-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 114. Flatten Binary Tree to Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Solution using Stack | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| O(1) Iterative Solution | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* flattenTree(struct TreeNode* node) {
    // Handle the null scenario
    if (!node) {
        return NULL;
    }
    // For a leaf node, we simply return the
    // node as is.
    if (!node->left && !node->right) {
        return node;
    }
    // Recursively flatten the left subtree
    struct TreeNode* leftTail = flattenTree(node->left);
    // Recursively flatten the right subtree
    struct TreeNode* rightTail = flattenTree(node->right);
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if (leftTail) {
        leftTail->right = node->right;
        node->right = node->left;
        node->left = NULL;
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    return rightTail ? rightTail : leftTail;
}
void flatten(struct TreeNode* root) { flattenTree(root); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* flattenTree(TreeNode* node) {
        // Handle the null scenario
        if (node == NULL) {
            return NULL;
        }
        // For a leaf node, we simply return the
        // node as is.
        if (node->left == NULL && node->right == NULL) {
            return node;
        }
        // Recursively flatten the left subtree
        TreeNode* leftTail = this->flattenTree(node->left);
        // Recursively flatten the right subtree
        TreeNode* rightTail = this->flattenTree(node->right);
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != NULL) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return rightTail == NULL ? leftTail : rightTail;
    }
    void flatten(TreeNode* root) { this->flattenTree(root); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeNode FlattenTree(TreeNode node) {
        // Handle the null scenario
        if (node == null) {
            return null;
        }

        // For a leaf node, we simply return the
        // node as is.
        if (node.left == null && node.right == null) {
            return node;
        }

        // Recursively flatten the left subtree
        TreeNode leftTail = FlattenTree(node.left);
        // Recursively flatten the right subtree
        TreeNode rightTail = FlattenTree(node.right);
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != null) {
            leftTail.right = node.right;
            node.right = node.left;
            node.left = null;
        }

        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return rightTail == null ? leftTail : rightTail;
    }

    public void Flatten(TreeNode root) {
        FlattenTree(root);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/*
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flattenTree(node *TreeNode) *TreeNode {
    // Handle the null scenario
    if node == nil {
        return nil
    }
    // For a leaf node, we simply return the
    // node as is.
    if node.Left == nil && node.Right == nil {
        return node
    }
    // Recursively flatten the left subtree
    leftTail := flattenTree(node.Left)
    // Recursively flatten the right subtree
    rightTail := flattenTree(node.Right)
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if leftTail != nil {
        leftTail.Right = node.Right
        node.Right = node.Left
        node.Left = nil
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    if rightTail != nil {
        return rightTail
    } else {
        return leftTail
    }
}

func flatten(root *TreeNode) {
    flattenTree(root)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode flattenTree(TreeNode node) {
        // Handle the null scenario
        if (node == null) {
            return null;
        }

        // For a leaf node, we simply return the
        // node as is.
        if (node.left == null && node.right == null) {
            return node;
        }

        //Recursively flatten the left subtree
        TreeNode leftTail = this.flattenTree(node.left);

        // Recursively flatten the right subtree
        TreeNode rightTail = this.flattenTree(node.right);

        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != null) {
            leftTail.right = node.right;
            node.right = node.left;
            node.left = null;
        }

        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return rightTail == null ? leftTail : rightTail;
    }

    public void flatten(TreeNode root) {
        this.flattenTree(root);
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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flattenTree = function (node) {
    // Handle the null scenario
    if (node == null) {
        return null;
    }
    // For a leaf node, we simply return the
    // node as is.
    if (node.left == null && node.right == null) {
        return node;
    }
    // Recursively flatten the left subtree
    let leftTail = flattenTree(node.left);
    // Recursively flatten the right subtree
    let rightTail = flattenTree(node.right);
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if (leftTail != null) {
        leftTail.right = node.right;
        node.right = node.left;
        node.left = null;
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    return rightTail == null ? leftTail : rightTail;
};
var flatten = function (root) {
    flattenTree(root);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def flattenTree(self, node: TreeNode) -> TreeNode:

        # Handle the null scenario
        if not node:
            return None

        # For a leaf node, we simply return the
        # node as is.
        if not node.left and not node.right:
            return node

        # Recursively flatten the left subtree
        leftTail = self.flattenTree(node.left)

        # Recursively flatten the right subtree
        rightTail = self.flattenTree(node.right)

        # If there was a left subtree, we shuffle the connections
        # around so that there is nothing on the left side
        # anymore.
        if leftTail:
            leftTail.right = node.right
            node.right = node.left
            node.left = None

        # We need to return the "rightmost" node after we are
        # done wiring the new connections.
        return rightTail if rightTail else leftTail

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        self.flattenTree(root)
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
function flattenTree(node: TreeNode | null): TreeNode | null {
    // Handle the null scenario
    if (node == null) {
        return null;
    }
    // For a leaf node, we simply return the
    // node as is.
    if (node.left == null && node.right == null) {
        return node;
    }
    // Recursive flatten for the left subtree
    let leftTail = flattenTree(node.left);
    // Recursive flatten for the right subtree
    let rightTail = flattenTree(node.right);
    // If there was a left subtree, we shuffle the connections
    // around so that there is nothing on the left side
    // anymore.
    if (leftTail != null) {
        leftTail.right = node.right;
        node.right = node.left;
        node.left = null;
    }
    // We need to return the "rightmost" node after we are
    // done wiring the new connections.
    return rightTail == null ? leftTail : rightTail;
}
function flatten(root: TreeNode | null): void {
    flattenTree(root);
}
```

</details>

<br>

## Approach 2: Iterative Solution using Stack

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Pair {
    struct TreeNode* key;
    int value;
};
void flatten(struct TreeNode* root) {
    // Handle the null scenario
    if (!root) {
        return;
    }
    int START = 1, END = 2;
    struct TreeNode* tailNode = NULL;
    struct Pair stack[1000];
    int top = 0;
    stack[top].key = root;
    stack[top++].value = START;
    while (top > 0) {
        struct Pair nodeData = stack[--top];
        struct TreeNode* currentNode = nodeData.key;
        int recursionState = nodeData.value;
        // We reached a leaf node. Record this as a tail
        // node and move on.
        if (!currentNode->left && !currentNode->right) {
            tailNode = currentNode;
            continue;
        }
        // If the node is in the START state, it means we still
        // haven't processed it's left child yet.
        if (recursionState == START) {
            // If the current node has a left child, we add it
            // to the stack AFTER adding the current node again
            // to the stack with the END recursion state.
            if (currentNode->left) {
                stack[top].key = currentNode;
                stack[top++].value = END;
                stack[top].key = currentNode->left;
                stack[top++].value = START;
            } else if (currentNode->right) {
                // In case the current node didn't have a left child
                // we will add it's right child
                stack[top].key = currentNode->right;
                stack[top++].value = START;
            }
        } else {
            // If the current node is in the END recursion state,
            // that means we did process one of its children. Left
            // if it existed, else right.
            struct TreeNode* rightNode = currentNode->right;
            // If there was a left child, there must have been a leaf
            // node and so, we would have set the tailNode
            if (tailNode) {
                // Establish the proper connections.
                tailNode->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = NULL;
                rightNode = tailNode->right;
            }
            if (rightNode) {
                stack[top].key = rightNode;
                stack[top++].value = START;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        // Handle the null scenario
        if (root == NULL) {
            return;
        }
        int START = 1, END = 2;
        TreeNode* tailNode = nullptr;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, START));
        while (!stk.empty()) {
            pair<TreeNode*, int> nodeData = stk.top();
            stk.pop();
            TreeNode* currentNode = nodeData.first;
            int recursionState = nodeData.second;
            // We reached a leaf node. Record this as a tail
            // node and move on.
            if (currentNode->left == NULL && currentNode->right == NULL) {
                tailNode = currentNode;
                continue;
            }
            // If the node is in the START state, it means we still
            // haven't processed it's left child yet.
            if (recursionState == START) {
                // If the current node has a left child, we add it
                // to the stack AFTER adding the current node again
                // to the stack with the END recursion state.
                if (currentNode->left != NULL) {
                    stk.push(make_pair(currentNode, END));
                    stk.push(make_pair(currentNode->left, START));
                } else if (currentNode->right != NULL) {
                    // In case the current node didn't have a left child
                    // we will add it's right child
                    stk.push(make_pair(currentNode->right, START));
                }
            } else {
                // If the current node is in the END recursion state,
                // that means we did process one of it's children. Left
                // if it existed, else right.
                TreeNode* rightNode = currentNode->right;
                // If there was a left child, there must have been a leaf
                // node and so, we would have set the tailNode
                if (tailNode != NULL) {
                    // Establish the proper connections.
                    tailNode->right = currentNode->right;
                    currentNode->right = currentNode->left;
                    currentNode->left = NULL;
                    rightNode = tailNode->right;
                }
                if (rightNode != NULL) {
                    stk.push(make_pair(rightNode, START));
                }
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private (TreeNode, int) GetPair(TreeNode n, int v) {
        return (n, v);
    }

    public void Flatten(TreeNode root) {
        if (root == null) {
            return;
        }

        int START = 1, END = 2;
        TreeNode tail = null;
        Stack<(TreeNode, int)> stack = new Stack<(TreeNode, int)>();
        stack.Push(GetPair(root, START));
        while (stack.Count > 0) {
            var nodeData = stack.Pop();
            TreeNode node = nodeData.Item1;
            int state = nodeData.Item2;
            if (node.left == null && node.right == null) {
                tail = node;
                continue;
            }

            if (state == START) {
                if (node.left != null) {
                    stack.Push(GetPair(node, END));
                    stack.Push(GetPair(node.left, START));
                } else if (node.right != null) {
                    stack.Push(GetPair(node.right, START));
                }
            } else {
                TreeNode rightNode = node.right;
                if (tail != null) {
                    tail.right = node.right;
                    node.right = node.left;
                    node.left = null;
                    rightNode = tail.right;
                }

                if (rightNode != null) {
                    stack.Push(GetPair(rightNode, START));
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func flatten(root *TreeNode) {
    if root == nil {
        return
    }
    tailNode := new(TreeNode)
    START, END := 1, 2
    stack := [][]interface{}{{root, START}}
    for len(stack) > 0 {
        nodeData := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        node := nodeData[0].(*TreeNode)
        state := nodeData[1].(int)
        if node.Left == nil && node.Right == nil {
            tailNode = node
            continue
        }
        if state == START {
            if node.Left != nil {
                stack = append(stack, []interface{}{node, END})
                stack = append(stack, []interface{}{node.Left, START})
            } else if node.Right != nil {
                stack = append(stack, []interface{}{node.Right, START})
            }
        } else {
            rightNode := node.Right
            if tailNode != nil {
                tailNode.Right = node.Right
                node.Right = node.Left
                node.Left = nil
                rightNode = tailNode.Right
            }
            if rightNode != nil {
                stack = append(stack, []interface{}{rightNode, START})
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Pair<K, V> {
    K key;
    V value;

    Pair(K a, V b) {
        this.key = a;
        this.value = b;
    }

    public K getKey() {
        return this.key;
    }

    public V getValue() {
        return this.value;
    }
}

class Solution {
    public void flatten(TreeNode root) {
        // Handle the null scenario
        if (root == null) {
            return;
        }

        int START = 1, END = 2;

        TreeNode tailNode = null;
        Stack<Pair<TreeNode, Integer>> stack = new Stack<
            Pair<TreeNode, Integer>
        >();
        stack.push(new Pair<TreeNode, Integer>(root, START));

        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> nodeData = stack.pop();
            TreeNode currentNode = nodeData.getKey();
            int recursionState = nodeData.getValue();

            // We reached a leaf node. Record this as a tail
            // node and move on.
            if (currentNode.left == null && currentNode.right == null) {
                tailNode = currentNode;
                continue;
            }

            // If the node is in the START state, it means we still
            // haven't processed it's left child yet.
            if (recursionState == START) {
                // If the current node has a left child, we add it
                // to the stack AFTER adding the current node again
                // to the stack with the END recursion state.
                if (currentNode.left != null) {
                    stack.push(new Pair<TreeNode, Integer>(currentNode, END));
                    stack.push(
                        new Pair<TreeNode, Integer>(currentNode.left, START)
                    );
                } else if (currentNode.right != null) {
                    // In case the current node didn't have a left child
                    // we will add it's right child
                    stack.push(
                        new Pair<TreeNode, Integer>(currentNode.right, START)
                    );
                }
            } else {
                // If the current node is in the END recursion state,
                // that means we did process one of it's children. Left
                // if it existed, else right.
                TreeNode rightNode = currentNode.right;

                // If there was a left child, there must have been a leaf
                // node and so, we would have set the tailNode
                if (tailNode != null) {
                    // Establish the proper connections.
                    tailNode.right = currentNode.right;
                    currentNode.right = currentNode.left;
                    currentNode.left = null;
                    rightNode = tailNode.right;
                }

                if (rightNode != null) {
                    stack.push(new Pair<TreeNode, Integer>(rightNode, START));
                }
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var flatten = function (root) {
    if (root === null) {
        return;
    }
    let tailNode = null;
    const START = 1,
        END = 2;
    let stack = [[root, START]];
    while (stack.length > 0) {
        let nodeData = stack.pop();
        let currentNode = nodeData[0];
        let recursionState = nodeData[1];
        if (currentNode.left === null && currentNode.right === null) {
            tailNode = currentNode;
            continue;
        }
        if (recursionState === START) {
            if (currentNode.left !== null) {
                stack.push([currentNode, END]);
                stack.push([currentNode.left, START]);
            } else if (currentNode.right !== null) {
                stack.push([currentNode.right, START]);
            }
        } else {
            let rightNode = currentNode.right;
            if (tailNode !== null) {
                tailNode.right = currentNode.right;
                currentNode.right = currentNode.left;
                currentNode.left = null;
                rightNode = tailNode.right;
            }
            if (rightNode !== null) {
                stack.push([rightNode, START]);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import collections


class Solution:

    def flatten(self, root: Optional[TreeNode]) -> None:

        # Handle the null scenario
        if not root:
            return None

        START, END = 1, 2

        tailNode = None
        stack = collections.deque([(root, START)])

        while stack:

            currentNode, recursionState = stack.pop()

            # We reached a leaf node. Record this as a tail
            # node and move on.
            if not currentNode.left and not currentNode.right:
                tailNode = currentNode
                continue

            # If the node is in the START state, it means we still
            # haven't processed it's left child yet.
            if recursionState == START:

                # If the current node has a left child, we add it
                # to the stack AFTER adding the current node again
                # to the stack with the END recursion state.
                if currentNode.left:
                    stack.append((currentNode, END))
                    stack.append((currentNode.left, START))
                elif currentNode.right:

                    # In case the current node didn't have a left child
                    # we will add it's right child
                    stack.append((currentNode.right, START))
            else:
                # If the current node is in the END recursion state,
                # that means we did process one of it's children. Left
                # if it existed, else right.
                rightNode = currentNode.right

                # If there was a left child, there must have been a leaf
                # node and so, we would have set the tailNode
                if tailNode:

                    # Establish the proper connections.
                    tailNode.right = currentNode.right
                    currentNode.right = currentNode.left
                    currentNode.left = None
                    rightNode = tailNode.right

                if rightNode:
                    stack.append((rightNode, START))
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function flatten(root: TreeNode | null): void {
    if (root === null) {
        return;
    }
    let tailNode: TreeNode | null = null;
    const START = 1,
        END = 2;
    let stack: Array<[TreeNode, number]> = [[root, START]];
    while (stack.length > 0) {
        let nodeData = stack.pop() as [TreeNode, number];
        let currentNode = nodeData[0];
        let recursionState = nodeData[1];
        if (currentNode.left === null && currentNode.right === null) {
            tailNode = currentNode;
            continue;
        }
        if (recursionState === START) {
            if (currentNode.left !== null) {
                stack.push([currentNode, END]);
                stack.push([currentNode.left, START]);
            } else if (currentNode.right !== null) {
                stack.push([currentNode.right, START]);
            }
        } else {
            let rightNode = currentNode.right;
            if (tailNode !== null) {
                tailNode.right = currentNode.right;
                currentNode.right = currentNode.left;
                currentNode.left = null;
                rightNode = tailNode.right;
            }
            if (rightNode !== null) {
                stack.push([rightNode, START]);
            }
        }
    }
}
```

</details>

<br>

## Approach 3: O(1) Iterative Solution

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct TreeNode* flatten(struct TreeNode* root) {
    // Handle the null scenario
    if (!root) return NULL;
    struct TreeNode* node = root;
    while (node != NULL) {
        // If the node has a left child
        if (node->left != NULL) {
            // Find the rightmost node
            struct TreeNode* rightmost = node->left;
            while (rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            // rewire the connections
            rightmost->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        // move on to the right side of the tree
        node = node->right;
    }
    return root;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        // Handle the null scenario
        if (!root) {
            return;
        }
        TreeNode* node = root;
        while (node != nullptr) {
            // If the node has a left child
            if (node->left != nullptr) {
                // Find the rightmost node
                TreeNode* rightmost = node->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                // rewire the connections
                rightmost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            // move on to the right side of the tree
            node = node->right;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Flatten(TreeNode root) {
        // Handle the null scenario
        if (root == null)
            return;
        TreeNode node = root;
        while (node != null) {
            // If the node has a left child
            if (node.left != null) {
                // Find the rightmost node
                TreeNode rightmost = node.left;
                while (rightmost.right != null) {
                    rightmost = rightmost.right;
                }

                // rewire the connections
                rightmost.right = node.right;
                node.right = node.left;
                node.left = null;
            }

            // move on to the right side of the tree
            node = node.right;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func flatten(root *TreeNode) {
    // Handle the null scenario
    if root == nil {
        return
    }
    node := root
    for node != nil {
        // If the node has a left child
        if node.Left != nil {
            // Find the rightmost node
            rightmost := node.Left
            for rightmost.Right != nil {
                rightmost = rightmost.Right
            }
            // rewire the connections
            rightmost.Right = node.Right
            node.Right = node.Left
            node.Left = nil
        }
        // move on to the right side of the tree
        node = node.Right
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void flatten(TreeNode root) {
        // Handle the null scenario
        if (root == null) {
            return;
        }

        TreeNode node = root;

        while (node != null) {
            // If the node has a left child
            if (node.left != null) {
                // Find the rightmost node
                TreeNode rightmost = node.left;
                while (rightmost.right != null) {
                    rightmost = rightmost.right;
                }

                // rewire the connections
                rightmost.right = node.right;
                node.right = node.left;
                node.left = null;
            }

            // move on to the right side of the tree
            node = node.right;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var flatten = function (root) {
    // Handle the null scenario
    if (!root) {
        return;
    }
    let node = root;
    while (node != null) {
        // If the node has a left child
        if (node.left != null) {
            // Find the rightmost node
            let rightmost = node.left;
            while (rightmost.right != null) {
                rightmost = rightmost.right;
            }
            // rewire the connections
            rightmost.right = node.right;
            node.right = node.left;
            node.left = null;
        }
        // move on to the right side of the tree
        node = node.right;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def flatten(self, root: TreeNode) -> None:
        # Handle the null scenario
        if not root:
            return None

        node = root
        while node:

            # If the node has a left child
            if node.left:

                # Find the rightmost node
                rightmost = node.left
                while rightmost.right:
                    rightmost = rightmost.right

                # rewire the connections
                rightmost.right = node.right
                node.right = node.left
                node.left = None

            # move on to the right side of the tree
            node = node.right
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function flatten(root: TreeNode): void {
    // Handle the null scenario
    if (!root) return;
    let node: TreeNode | null = root;
    while (node != null) {
        // If the node has a left child
        if (node.left != null) {
            // Find the rightmost node
            let rightmost: TreeNode | null = node.left;
            while (rightmost.right != null) {
                rightmost = rightmost.right;
            }
            // rewire the connections
            rightmost.right = node.right;
            node.right = node.left;
            node.left = null;
        }
        // move on to the right side of the tree
        node = node.right;
    }
}
```

</details>
