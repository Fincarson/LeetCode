# 112. Path Sum

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/path-sum/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 112 - Path Sum](https://leetcode.com/problems/path-sum/)

## Problem

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

### Example 1

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

### Example 2

```text
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

### Example 3

```text
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

## Constraints

- The number of nodes in the tree is in the range [0, 5000].
- -1000 <= Node.val <= 1000
- -1000 <= targetSum <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Path Sum IV](https://leetcode.com/problems/path-sum-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 112. Path Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterations | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
    sum -= root->val;
    if (!root->left && !root->right)  // if reach a leaf
        return sum == 0;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right)  // if reach a leaf
            return sum == 0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;
        sum -= root.val;
        if ((root.left == null) && (root.right == null))  // if reach a leaf
            return sum == 0;
        return HasPathSum(root.left, sum) || HasPathSum(root.right, sum);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }
    sum -= root.Val
    if root.Left == nil && root.Right == nil { // if reach a leaf
        return sum == 0
    }
    return hasPathSum(root.Left, sum) || hasPathSum(root.Right, sum)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;

        sum -= root.val;
        if ((root.left == null) && (root.right == null)) return (sum == 0);
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasPathSum = function (root, sum) {
    if (!root) return false;
    sum -= root.val;
    if (!root.left && !root.right)
        // if reach a leaf
        return sum == 0;
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False

        sum -= root.val
        if not root.left and not root.right:  # if reach a leaf
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(
            root.right, sum
        )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasPathSum(root: TreeNode | null, sum: number): boolean {
    if (root === null) return false;
    sum -= root.val;
    if (root.left === null && root.right === null)
        // if reach a leaf
        return sum === 0;
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
}
```

</details>

<br>

## Approach 2: Iterations

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool hasPathSum(struct TreeNode *root, int sum) {
    struct TreeNode *node_stack[1000];
    int sum_stack[1000];
    int stack_size = 0;
    if (root == NULL) return false;
    node_stack[stack_size] = root;
    sum_stack[stack_size++] = sum - root->val;
    while (stack_size > 0) {
        struct TreeNode *node = node_stack[--stack_size];
        sum = sum_stack[stack_size];
        if (node->left == NULL && node->right == NULL && sum == 0) return true;
        if (node->right != NULL) {
            node_stack[stack_size] = node->right;
            sum_stack[stack_size++] = sum - node->right->val;
        }
        if (node->left != NULL) {
            node_stack[stack_size] = node->left;
            sum_stack[stack_size++] = sum - node->left->val;
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        std::stack<TreeNode*> node_stack;
        std::stack<int> sum_stack;
        node_stack.push(root);
        sum_stack.push(sum - root->val);
        TreeNode* node;
        int curr_sum;
        while (!node_stack.empty()) {
            node = node_stack.top();
            node_stack.pop();
            curr_sum = sum_stack.top();
            sum_stack.pop();
            if ((node->right == NULL) && (node->left == NULL) &&
                (curr_sum == 0))
                return true;
            if (node->right != NULL) {
                node_stack.push(node->right);
                sum_stack.push(curr_sum - node->right->val);
            }
            if (node->left != NULL) {
                node_stack.push(node->left);
                sum_stack.push(curr_sum - node->left->val);
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasPathSum(TreeNode root, int sum) {
        if (root == null)
            return false;
        Stack<TreeNode> nodeStack = new Stack<TreeNode>();
        Stack<int> sumStack = new Stack<int>();
        nodeStack.Push(root);
        sumStack.Push(sum - root.val);
        while (nodeStack.Count > 0) {
            TreeNode node = nodeStack.Pop();
            int currSum = sumStack.Pop();
            if (node.left == null && node.right == null && currSum == 0)
                return true;
            if (node.left != null) {
                nodeStack.Push(node.left);
                sumStack.Push(currSum - node.left.val);
            }

            if (node.right != null) {
                nodeStack.Push(node.right);
                sumStack.Push(currSum - node.right.val);
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasPathSum(root *TreeNode, sum int) bool {
    if root == nil {
        return false
    }
    nodeStack := []*TreeNode{}
    sumStack := []int{}
    nodeStack = append(nodeStack, root)
    sumStack = append(sumStack, sum-root.Val)
    for len(nodeStack) > 0 {
        lastIdx := len(nodeStack) - 1
        currentNode := nodeStack[lastIdx]
        nodeStack = nodeStack[:lastIdx]
        currSum := sumStack[lastIdx]
        sumStack = sumStack[:lastIdx]
        if currentNode.Left == nil && currentNode.Right == nil && currSum == 0 {
            return true
        }
        if currentNode.Right != nil {
            nodeStack = append(nodeStack, currentNode.Right)
            sumStack = append(sumStack, currSum-currentNode.Right.Val)
        }
        if currentNode.Left != nil {
            nodeStack = append(nodeStack, currentNode.Left)
            sumStack = append(sumStack, currSum-currentNode.Left.Val)
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;

        LinkedList<TreeNode> node_stack = new LinkedList();
        LinkedList<Integer> sum_stack = new LinkedList();
        node_stack.add(root);
        sum_stack.add(sum - root.val);

        TreeNode node;
        int curr_sum;
        while (!node_stack.isEmpty()) {
            node = node_stack.pollLast();
            curr_sum = sum_stack.pollLast();
            if (
                (node.right == null) && (node.left == null) && (curr_sum == 0)
            ) return true;

            if (node.right != null) {
                node_stack.add(node.right);
                sum_stack.add(curr_sum - node.right.val);
            }
            if (node.left != null) {
                node_stack.add(node.left);
                sum_stack.add(curr_sum - node.left.val);
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasPathSum = function (root, sum) {
    if (!root) return false;
    let nodeStack = [];
    let sumStack = [];
    nodeStack.push(root);
    sumStack.push(sum - root.val);
    while (nodeStack.length > 0) {
        let currentNode = nodeStack.pop();
        let currSum = sumStack.pop();
        if (!currentNode.left && !currentNode.right && currSum === 0)
            return true;
        if (currentNode.right) {
            nodeStack.push(currentNode.right);
            sumStack.push(currSum - currentNode.right.val);
        }
        if (currentNode.left) {
            nodeStack.push(currentNode.left);
            sumStack.push(currSum - currentNode.left.val);
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False

        de = [
            (root, sum - root.val),
        ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasPathSum(root: TreeNode | null, sum: number): boolean {
    if (!root) return false;
    let nodeStack: TreeNode[] = [];
    let sumStack: number[] = [];
    nodeStack.push(root);
    sumStack.push(sum - root.val);
    while (nodeStack.length > 0) {
        let currentNode = nodeStack.pop();
        let currSum = sumStack.pop();
        if (!currentNode!.left && !currentNode!.right && currSum === 0)
            return true;
        if (currentNode!.right) {
            nodeStack.push(currentNode!.right);
            sumStack.push(currSum! - currentNode!.right.val);
        }
        if (currentNode!.left) {
            nodeStack.push(currentNode!.left);
            sumStack.push(currSum! - currentNode!.left.val);
        }
    }
    return false;
}
```

</details>
