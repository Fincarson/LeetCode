# 100. Same Tree

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/same-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 100 - Same Tree](https://leetcode.com/problems/same-tree/)

## Problem

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

### Example 1

```text
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

### Example 2

```text
Input: p = [1,2], q = [1,null,2]
Output: false
```

### Example 3

```text
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

## Constraints

- The number of nodes in both trees is in the range [0, 100].
- -104 <= Node.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 100. Same Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // p and q are both null
    if (p == NULL && q == NULL) return true;
    // one of p and q is null
    if (q == NULL || p == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // p and q are both null
        if (!p && !q) return true;
        // one of p and q is null
        if (!q || !p) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        // p and q are both null
        if (p == null && q == null)
            return true;
        // one of p and q is null
        if (q == null || p == null)
            return false;
        if (p.val != q.val)
            return false;
        return IsSameTree(p.right, q.right) && IsSameTree(p.left, q.left);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isSameTree(p *TreeNode, q *TreeNode) bool {
    // p and q are both null
    if p == nil && q == nil {
        return true
    }
    // one of p and q is null
    if (q == nil) || (p == nil) {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    return isSameTree(p.Right, q.Right) &&
        isSameTree(p.Left, q.Left)
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // p and q are both null
        if (p == null && q == null) return true;
        // one of p and q is null
        if (q == null || p == null) return false;
        if (p.val != q.val) return false;
        return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isSameTree = function (p, q) {
    // p and q are both null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # p and q are both None
        if not p and not q:
            return True
        # one of p and q is None
        if not q or not p:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.right, q.right) and self.isSameTree(
            p.left, q.left
        )
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    // p and q are both null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
}
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Data {
    struct TreeNode *p;
    struct TreeNode *q;
};
typedef struct Node {
    struct Data data;
    struct Node *next;
} Node;
typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;
void enqueue(Queue *q, struct TreeNode *p, struct TreeNode *qVal) {
    if (!q->head) {
        q->head = q->tail = malloc(sizeof(Node));
        q->head->data.p = p;
        q->head->data.q = qVal;
        q->head->next = NULL;
    } else {
        q->tail->next = malloc(sizeof(Node));
        q->tail = q->tail->next;
        q->tail->data.p = p;
        q->tail->data.q = qVal;
        q->tail->next = NULL;
    }
}
void dequeue(Queue *q, struct TreeNode **p, struct TreeNode **qVal) {
    if (q->head) {
        Node *node = q->head;
        *p = node->data.p;
        *qVal = node->data.q;
        q->head = q->head->next;
        free(node);
    }
}
bool is_empty(Queue *q) { return q->head == NULL; }
bool check(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return true;
}
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    Queue deq = {NULL, NULL};
    ;
    enqueue(&deq, p, q);
    while (!is_empty(&deq)) {
        struct TreeNode *pVal, *qVal;
        dequeue(&deq, &pVal, &qVal);
        if (!check(pVal, qVal)) return false;
        if (pVal) {
            enqueue(&deq, pVal->left, qVal->left);
            enqueue(&deq, pVal->right, qVal->right);
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
struct Pair {
    TreeNode* p;
    TreeNode* q;
};
class Solution {
public:
    Solution() {}
    ~Solution() {}
    bool check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;  // p and q is null
        if (q == nullptr || p == nullptr)
            return false;  // one of p and q is null
        if (p->val != q->val) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<Pair> deq;
        deq.push({p, q});
        while (!deq.empty()) {
            Pair pos = deq.front();
            deq.pop();
            p = pos.p;
            q = pos.q;
            if (!check(p, q)) return false;
            if (p != nullptr) {
                if (!check(p->left, q->left)) return false;
                deq.push({p->left, q->left});
                if (!check(p->right, q->right)) return false;
                deq.push({p->right, q->right});
            }
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
    public bool IsSameTree(TreeNode p, TreeNode q) {
        Queue<(TreeNode, TreeNode)> deq = new Queue<(TreeNode, TreeNode)>();
        deq.Enqueue((p, q));
        while (deq.Count != 0) {
            (p, q) = deq.Dequeue();
            if (p == null && q == null)
                continue;
            if (q == null || p == null)
                return false;
            if (p.val != q.val)
                return false;
            deq.Enqueue((p.left, q.left));
            deq.Enqueue((p.right, q.right));
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func check(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
        return true
    }
    if p == nil || q == nil {
        return false
    }
    if p.Val != q.Val {
        return false
    }
    return true
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
    type NodePair struct {
        p *TreeNode
        q *TreeNode
    }
    deq := []NodePair{{p, q}}
    for len(deq) > 0 {
        var pair NodePair
        pair, deq = deq[0], deq[1:]
        p = pair.p
        q = pair.q
        if !check(p, q) {
            return false
        }
        if p != nil {
            deq = append(deq, NodePair{p.Left, q.Left})
            deq = append(deq, NodePair{p.Right, q.Right})
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
    public boolean check(TreeNode p, TreeNode q) {
        // p and q are null
        if (p == null && q == null) return true;
        // one of p and q is null
        if (q == null || p == null) return false;
        if (p.val != q.val) return false;
        return true;
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (!check(p, q)) return false;

        // init deques
        ArrayDeque<TreeNode> deqP = new ArrayDeque<TreeNode>();
        ArrayDeque<TreeNode> deqQ = new ArrayDeque<TreeNode>();
        deqP.addLast(p);
        deqQ.addLast(q);

        while (!deqP.isEmpty()) {
            p = deqP.removeFirst();
            q = deqQ.removeFirst();

            if (!check(p, q)) return false;
            if (p != null) {
                // in Java nulls are not allowed in Deque
                if (!check(p.left, q.left)) return false;
                if (p.left != null) {
                    deqP.addLast(p.left);
                    deqQ.addLast(q.left);
                }
                if (!check(p.right, q.right)) return false;
                if (p.right != null) {
                    deqP.addLast(p.right);
                    deqQ.addLast(q.right);
                }
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function isSameTree(p, q) {
    const check = (p, q) => {
        // p and q are both null
        if (p === null && q === null) return true;
        // one of p and q is null
        if (p === null || q === null) return false;
        if (p.val !== q.val) return false;
        return true;
    };
    const deq = [[p, q]];
    while (deq.length) {
        [p, q] = deq.shift();
        if (!check(p, q)) return false;
        if (p) {
            deq.push([p.left, q.left]);
            deq.push([p.right, q.right]);
        }
    }
    return true;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def check(p: TreeNode, q: TreeNode) -> bool:
            # if both are None
            if not p and not q:
                return True
            # one of p and q is None
            if not q or not p:
                return False
            if p.val != q.val:
                return False
            return True

        deq = deque(
            [
                (p, q),
            ]
        )
        while deq:
            p, q = deq.popleft()
            if not check(p, q):
                return False

            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))

        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    const check = (p: TreeNode | null, q: TreeNode | null): boolean => {
        if (p === null && q === null) return true;
        if (p === null || q === null) return false;
        if (p.val !== q.val) return false;
        return true;
    };
    const deq: [TreeNode | null, TreeNode | null][] = [[p, q]];
    while (deq.length) {
        [p, q] = deq.shift() as [TreeNode | null, TreeNode | null];
        if (!check(p, q)) return false;
        if (p) {
            deq.push([p.left, q?.left] as [TreeNode | null, TreeNode | null]);
            deq.push([p.right, q?.right] as [TreeNode | null, TreeNode | null]);
        }
    }
    return true;
}
```

</details>
