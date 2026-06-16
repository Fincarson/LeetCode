# 101. Symmetric Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/symmetric-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 101 - Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

## Problem

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

### Example 1

```text
Input: root = [1,2,2,3,4,4,3]
Output: true
```

### Example 2

```text
Input: root = [1,2,2,null,3,null,3]
Output: false
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 101. Symmetric Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isMirror(struct TreeNode* t1, struct TreeNode* t2);
bool isSymmetric(struct TreeNode* root) { return isMirror(root, root); }
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
           isMirror(t1->left, t2->right);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) { return isMirror(root, root); }
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
               isMirror(t1->left, t2->right);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsSymmetric(TreeNode root) {
        return IsMirror(root, root);
    }

    public bool IsMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null)
            return true;
        if (t1 == null || t2 == null)
            return false;
        return (t1.val == t2.val) && IsMirror(t1.right, t2.left) &&
               IsMirror(t1.left, t2.right);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isSymmetric(root *TreeNode) bool {
    return isMirror(root, root)
}

func isMirror(t1 *TreeNode, t2 *TreeNode) bool {
    if t1 == nil && t2 == nil {
        return true
    }
    if t1 == nil || t2 == nil {
        return false
    }
    return (t1.Val == t2.Val) && isMirror(t1.Right, t2.Left) &&
        isMirror(t1.Left, t2.Right)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (
            (t1.val == t2.val) &&
            isMirror(t1.right, t2.left) &&
            isMirror(t1.left, t2.right)
        );
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isSymmetric = function (root) {
    return isMirror(root, root);
};
var isMirror = function (t1, t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (
        t1.val === t2.val &&
        isMirror(t1.right, t2.left) &&
        isMirror(t1.left, t2.right)
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSymmetric(self, root):
        return self.isMirror(root, root)

    def isMirror(self, t1, t2):
        if t1 is None and t2 is None:
            return True
        if t1 is None or t2 is None:
            return False
        return (
            (t1.val == t2.val)
            and self.isMirror(t1.right, t2.left)
            and self.isMirror(t1.left, t2.right)
        )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isSymmetric(root: TreeNode | null): boolean {
    return isMirror(root, root);
}
function isMirror(t1: TreeNode | null, t2: TreeNode | null): boolean {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (
        t1.val === t2.val &&
        isMirror(t1.right, t2.left) &&
        isMirror(t1.left, t2.right)
    );
}
```

</details>

<br>

## Approach 2: Iterative

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
bool isSymmetric(struct TreeNode* root) {
    struct TreeNode* q[3030];
    int head = 0;
    int tail = 0;
    q[head++] = root;
    q[head++] = root;
    while (head != tail) {
        struct TreeNode* t1 = q[tail++];
        struct TreeNode* t2 = q[tail++];
        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;
        if (t1->val != t2->val) return false;
        q[head++] = t1->left;
        q[head++] = t2->right;
        q[head++] = t1->right;
        q[head++] = t2->left;
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL) continue;
            if (t1 == NULL || t2 == NULL) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public bool IsSymmetric(TreeNode root) {
        Queue<TreeNode> q = new Queue<TreeNode>();
        q.Enqueue(root);
        q.Enqueue(root);
        while (q.Count != 0) {
            TreeNode t1 = q.Dequeue();
            TreeNode t2 = q.Dequeue();
            if (t1 == null && t2 == null)
                continue;
            if (t1 == null || t2 == null)
                return false;
            if (t1.val != t2.val)
                return false;
            q.Enqueue(t1.left);
            q.Enqueue(t2.right);
            q.Enqueue(t1.right);
            q.Enqueue(t2.left);
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func isSymmetric(root *TreeNode) bool {
    q := []*TreeNode{root, root}
    for len(q) > 0 {
        t1 := q[0]
        t2 := q[1]
        q = q[2:]
        if t1 == nil && t2 == nil {
            continue
        }
        if t1 == nil || t2 == nil {
            return false
        }
        if t1.Val != t2.Val {
            return false
        }
        q = append(q, t1.Left, t2.Right, t1.Right, t2.Left)
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode t1 = q.poll();
            TreeNode t2 = q.poll();
            if (t1 == null && t2 == null) continue;
            if (t1 == null || t2 == null) return false;
            if (t1.val != t2.val) return false;
            q.add(t1.left);
            q.add(t2.right);
            q.add(t1.right);
            q.add(t2.left);
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var isSymmetric = function (root) {
    let q = [root, root];
    while (q.length > 0) {
        let t1 = q.shift();
        let t2 = q.shift();
        if (t1 === null && t2 === null) {
            continue;
        }
        if (t1 === null || t2 === null) {
            return false;
        }
        if (t1.val !== t2.val) {
            return false;
        }
        q.push(t1.left, t2.right, t1.right, t2.left);
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque

class Solution:
    def isSymmetric(self, root):
        q = deque([root, root])
        while q:
            t1 = q.popleft()
            t2 = q.popleft()
            if t1 is None and t2 is None:
                continue
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function isSymmetric(root: TreeNode | null): boolean {
    let q: Array<TreeNode | null> = [root, root];
    while (q.length !== 0) {
        let t1: TreeNode | null = q.shift();
        let t2: TreeNode | null = q.shift();
        if (t1 === null && t2 === null) {
            continue;
        }
        if (t1 === null || t2 === null) {
            return false;
        }
        if (t1.val !== t2.val) {
            return false;
        }
        q.push(t1.left, t2.right, t1.right, t2.left);
    }
    return true;
}
```

</details>
