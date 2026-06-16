# 111. Minimum Depth of Binary Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/minimum-depth-of-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 111 - Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

## Problem

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

### Example 2

```text
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
```

## Constraints

- The number of nodes in the tree is in the range [0, 105].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 111. Minimum Depth of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Breadth-First Search (BFS) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int dfs(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    // If only one of child is non-null, then go into that recursion.
    if (!root->left) {
        return 1 + dfs(root->right);
    } else if (!root->right) {
        return 1 + dfs(root->left);
    }
    // Both children are non-null, hence call for both children.
    int left_depth = dfs(root->left);
    int right_depth = dfs(root->right);
    return 1 + (left_depth < right_depth ? left_depth : right_depth);
}
int minDepth(struct TreeNode* root) { return dfs(root); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // If only one of child is non-null, then go into that recursion.
        if (!root->left) {
            return 1 + dfs(root->right);
        } else if (!root->right) {
            return 1 + dfs(root->left);
        }

        // Both children are non-null, hence call for both children.
        return 1 + min(dfs(root->left), dfs(root->right));
    }

    int minDepth(TreeNode* root) { return dfs(root); }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    private int Dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // If only one of child is non-null, then go into that recursion.
        if (root.left == null) {
            return 1 + Dfs(root.right);
        } else if (root.right == null) {
            return 1 + Dfs(root.left);
        }

        // Both children are non-null, hence call for both children.
        return 1 + Math.Min(Dfs(root.left), Dfs(root.right));
    }

    public int MinDepth(TreeNode root) {
        return Dfs(root);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func minDepth(root *TreeNode) int {
    var dfs func(root *TreeNode) int
    // Define the depth-first search
    dfs = func(root *TreeNode) int {
        if root == nil {
            return 0
        }
        // If only one of child is non-null, then go into that recursion.
        if root.Left == nil {
            return 1 + dfs(root.Right)
        } else if root.Right == nil {
            return 1 + dfs(root.Left)
        }
        // Both children are non-null, hence call for both children.
        leftDepth := dfs(root.Left)
        rightDepth := dfs(root.Right)
        if leftDepth < rightDepth {
            return 1 + leftDepth
        } else {
            return 1 + rightDepth
        }
    }
    return dfs(root)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // If only one of child is non-null, then go into that recursion.
        if (root.left == null) {
            return 1 + dfs(root.right);
        } else if (root.right == null) {
            return 1 + dfs(root.left);
        }

        // Both children are non-null, hence call for both children.
        return 1 + Math.min(dfs(root.left), dfs(root.right));
    }

    public int minDepth(TreeNode root) {
        return dfs(root);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var minDepth = function (root) {
    // Define the depth-first search
    function dfs(root) {
        if (root === null) {
            return 0;
        }
        // If only one of child is non-null, then go into that recursion.
        if (root.left === null) {
            return 1 + dfs(root.right);
        } else if (root.right === null) {
            return 1 + dfs(root.left);
        }
        // Both children are non-null, hence call for both children.
        return 1 + Math.min(dfs(root.left), dfs(root.right));
    }
    return dfs(root);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def minDepth(self, root):
        # Define the depth-first search
        def dfs(root):
            if root is None:
                return 0
            # If only one of child is non-null, then go into that recursion.
            if root.left is None:
                return 1 + dfs(root.right)
            elif root.right is None:
                return 1 + dfs(root.left)
            # Both children are non-null, hence call for both children.
            return 1 + min(dfs(root.left), dfs(root.right))

        return dfs(root)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function minDepth(root: TreeNode | null): number {
    // Define the depth-first search
    function dfs(root: TreeNode | null): number {
        if (root === null) {
            return 0;
        }
        // If only one of child is non-null, then go into that recursion.
        if (root.left === null) {
            return 1 + dfs(root.right);
        } else if (root.right === null) {
            return 1 + dfs(root.left);
        }
        // Both children are non-null, hence call for both children.
        return 1 + Math.min(dfs(root.left), dfs(root.right));
    }
    return dfs(root);
}
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};
struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
    int size;
};
void queuePush(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* newNode = malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (!q->head) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}
struct TreeNode* queuePop(struct Queue* q) {
    struct QueueNode* temp = q->head;
    struct TreeNode* node = temp->node;
    q->head = temp->next;
    if (!q->head) {
        q->tail = NULL;
    }
    free(temp);
    q->size--;
    return node;
}
bool queueIsEmpty(struct Queue* q) { return q->size == 0; }
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    struct Queue q = {0};
    queuePush(&q, root);
    int depth = 1;
    while (!queueIsEmpty(&q)) {
        int qSize = q.size;
        for (int i = 0; i < qSize; i++) {
            struct TreeNode* node = queuePop(&q);
            // The first leaf node would be at minimum depth, hence return it.
            if (!node->left && !node->right) {
                return depth;
            }
            if (node->left) {
                queuePush(&q, node->left);
            }
            if (node->right) {
                queuePush(&q, node->right);
            }
        }
        depth++;
    }
    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int qSize = q.size();

            while (qSize--) {
                TreeNode* node = q.front();
                q.pop();
                // Since we added nodes without checking null, we need to skip
                // them here.
                if (!node) {
                    continue;
                }

                // The first leaf would be at minimum depth, hence return it.
                if (!node->left && !node->right) {
                    return depth;
                }

                q.push({node->left});
                q.push({node->right});
            }

            depth++;
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        int depth = 1;
        while (q.Count != 0) {
            int qSize = q.Count;
            for (int i = 0; i < qSize; i++) {
                TreeNode node = q.Dequeue();
                // Since we added nodes without checking null, we need to skip
                // them here.
                if (node == null) {
                    continue;
                }

                // The first leaf would be at minimum depth, hence return it.
                if (node.left == null && node.right == null) {
                    return depth;
                }

                q.Enqueue(node.left);
                q.Enqueue(node.right);
            }

            depth++;
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang does not have a built-in queue, we have to emulate it using a slice.
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    var q []*TreeNode
    q = append(q, root)
    depth := 1
    for len(q) != 0 {
        qSize := len(q)
        for i := 0; i < qSize; i++ {
            node := q[0]
            q = q[1:]
            // Since we added nodes without checking null, we need to skip them here.
            if node == nil {
                continue
            }
            // The first leaf would be at minimum depth, hence return it.
            if node.Left == nil && node.Right == nil {
                return depth
            }
            q = append(q, node.Left)
            q = append(q, node.Right)
        }
        depth++
    }
    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int depth = 1;

        while (q.isEmpty() == false) {
            int qSize = q.size();

            while (qSize > 0) {
                qSize--;

                TreeNode node = q.remove();
                // Since we added nodes without checking null, we need to skip them here.
                if (node == null) {
                    continue;
                }

                // The first leaf would be at minimum depth, hence return it.
                if (node.left == null && node.right == null) {
                    return depth;
                }

                q.add(node.left);
                q.add(node.right);
            }
            depth++;
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minDepth = function (root) {
    if (!root) {
        return 0;
    }
    let q = [root];
    let depth = 1;
    while (q.length) {
        let qSize = q.length;
        for (let i = 0; i < qSize; i++) {
            let node = q.shift();
            // Since we added nodes without checking null, we need to skip them here.
            if (!node) {
                continue;
            }
            // The first leaf would be at minimum depth, hence return it.
            if (!node.left && !node.right) {
                return depth;
            }
            q.push(node.left);
            q.push(node.right);
        }
        depth++;
    }
    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = collections.deque([root])
        depth = 1
        while q:
            qSize = len(q)
            for _ in range(qSize):
                node = q.popleft()
                # Since we added nodes without checking null, we need to skip them here.
                if not node:
                    continue
                # The first leaf would be at minimum depth, hence return it.
                if not node.left and not node.right:
                    return depth
                q.append(node.left)
                q.append(node.right)
            depth += 1
        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minDepth(root: TreeNode | null): number {
    if (!root) {
        return 0;
    }
    let q: (TreeNode | null)[] = [root];
    let depth: number = 1;
    while (q.length) {
        let qSize: number = q.length;
        for (let i = 0; i < qSize; i++) {
            let node: TreeNode | null = q.shift()!;
            // Since we added nodes without checking null, we need to skip them here.
            if (!node) {
                continue;
            }
            // The first leaf would be at minimum depth, hence return it.
            if (node.left === null && node.right === null) {
                return depth;
            }
            q.push(node.left);
            q.push(node.right);
        }
        depth++;
    }
    return -1;
}
```

</details>
