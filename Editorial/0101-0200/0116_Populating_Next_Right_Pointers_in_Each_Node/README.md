# 116. Populating Next Right Pointers in Each Node

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)  
`Linked List` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 116 - Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## Problem

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```text
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

### Example 1

```text
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

### Example 2

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 212 - 1].
- -1000 <= Node.val <= 1000

Follow-up:

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Cycle Length Queries in a Tree](https://leetcode.com/problems/cycle-length-queries-in-a-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 116. Populating Next Right Pointers in Each Node

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Level Order Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Using previously established next pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Level Order Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp =
        (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct Node* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int isEmpty(struct Queue* q) { return q->front == NULL; }

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    struct Queue* Q = createQueue();
    enqueue(Q, root);
    // Outer while loop which iterates over each level
    while (!isEmpty(Q)) {
        // Note the size of the queue
        int size = Q->size;
        // Iterate over all the nodes on the current level
        for (int i = 0; i < size; i++) {
            // Pop a node from the front of the queue
            struct Node* node = dequeue(Q);
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if (i < size - 1) {
                node->next = Q->front->node;
            }
            // Add the children, if any, to the back of
            // the queue
            if (node->left != NULL) {
                enqueue(Q, node->left);
            }
            if (node->right != NULL) {
                enqueue(Q, node->right);
            }
        }
    }
    free(Q);
    // Since the tree has now been modified, return the root node
    return root;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        // Initialize a queue data structure which contains
        // just the root of the tree
        queue<Node*> Q;
        Q.push(root);
        // Outer while loop which iterates over each level
        while (Q.size() > 0) {
            // Note the size of the queue
            int size = Q.size();
            // Iterate over all the nodes on the current level
            for (int i = 0; i < size; i++) {
                // Pop a node from the front of the queue
                Node* node = Q.front();
                Q.pop();
                // This check is important. We don't want to
                // establish any wrong connections. The queue will
                // contain nodes from 2 levels at most at any
                // point in time. This check ensures we only
                // don't establish next pointers beyond the end
                // of a level
                if (i < size - 1) {
                    node->next = Q.front();
                }
                // Add the children, if any, to the back of
                // the queue
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }
        // Since the tree has now been modified, return the root node
        return root;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public Node Connect(Node root) {
        if (root == null) {
            return root;
        }

        // Initialize a queue data structure which contains
        // just the root of the tree
        Queue<Node> Q = new Queue<Node>();
        Q.Enqueue(root);
        // Outer while loop which iterates over each level
        while (Q.Count > 0) {
            // Note the size of the queue
            int size = Q.Count;
            // Iterate over all the nodes on the current level
            for (int i = 0; i < size; i++) {
                // Pop a node from the front of the queue
                Node node = Q.Dequeue();
                // This check is important. We don't want to
                // establish any wrong connections. The queue will
                // contain nodes from 2 levels at most at any
                // point in time. This check ensures we only
                // don't establish next pointers beyond the end
                // of a level
                if (i < size - 1) {
                    node.next = Q.Peek();
                }

                // Add the children, if any, to the back of
                // the queue
                if (node.left != null) {
                    Q.Enqueue(node.left);
                }

                if (node.right != null) {
                    Q.Enqueue(node.right);
                }
            }
        }

        // Since the tree has now been modified, return the root node
        return root;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    Q := []*Node{root}
    // Outer while loop which iterates over each level
    for len(Q) > 0 {
        // Note  size of the queue
        size := len(Q)
        // Iterate over all the nodes on the current level
        for i := 0; i < size; i++ {
            // Pop a node from the front of the queue
            node := Q[0]
            Q = Q[1:]
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if i < size-1 {
                node.Next = Q[0]
            }
            // Add the children, if any, to the back of
            // the queue
            if node.Left != nil {
                Q = append(Q, node.Left)
            }
            if node.Right != nil {
                Q = append(Q, node.Right)
            }
        }
    }
    // Since the tree has now been modified, return the root node
    return root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }

        // Initialize a queue data structure which contains
        // just the root of the tree
        Queue<Node> Q = new LinkedList<Node>();
        Q.add(root);

        // Outer while loop which iterates over
        // each level
        while (Q.size() > 0) {
            // Note the size of the queue
            int size = Q.size();

            // Iterate over all the nodes on the current level
            for (int i = 0; i < size; i++) {
                // Pop a node from the front of the queue
                Node node = Q.poll();

                // This check is important. We don't want to
                // establish any wrong connections. The queue will
                // contain nodes from 2 levels at most at any
                // point in time. This check ensures we only
                // don't establish next pointers beyond the end
                // of a level
                if (i < size - 1) {
                    node.next = Q.peek();
                }

                // Add the children, if any, to the back of
                // the queue
                if (node.left != null) {
                    Q.add(node.left);
                }
                if (node.right != null) {
                    Q.add(node.right);
                }
            }
        }

        // Since the tree has now been modified, return the root node
        return root;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var connect = function (root) {
    if (root == null) {
        return root;
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    let Q = [];
    Q.push(root);
    // Outer while loop which iterates over each level
    while (Q.length > 0) {
        // Note the size of the queue
        let size = Q.length;
        // Iterate over all the nodes on the current level
        for (let i = 0; i < size; i++) {
            // Pop a node from the front of the queue
            let node = Q.shift();
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if (i < size - 1) {
                node.next = Q[0];
            }
            // Add the children, if any, to the back of
            // the queue
            if (node.left != null) {
                Q.push(node.left);
            }
            if (node.right != null) {
                Q.push(node.right);
            }
        }
    }
    // Since the tree has now been modified, return the root node
    return root;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import collections


class Solution:
    def connect(self, root: "Node") -> "Node":

        if not root:
            return root

        # Initialize a queue data structure which contains
        # just the root of the tree
        Q = collections.deque([root])

        # Outer while loop which iterates over
        # each level
        while Q:

            # Note the size of the queue
            size = len(Q)

            # Iterate over all the nodes on the current level
            for i in range(size):

                # Pop a node from the front of the queue
                node = Q.popleft()

                # This check is important. We don't want to
                # establish any wrong connections. The queue will
                # contain nodes from 2 levels at most at any
                # point in time. This check ensures we only
                # don't establish next pointers beyond the end
                # of a level
                if i < size - 1:
                    node.next = Q[0]

                # Add the children, if any, to the back of
                # the queue
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)

        # Since the tree has now been modified, return the root node
        return root
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function connect(root: Node | null): Node | null {
    if (root == null) {
        return root;
    }
    // Initialize a queue data structure which contains
    // just the root of the tree
    let Q: Node[] = [];
    Q.push(root);
    // Outer while loop which iterates over each level
    while (Q.length > 0) {
        // Note the size of the queue
        let size = Q.length;
        // Iterate over all the nodes on the current level
        for (let i = 0; i < size; i++) {
            // Pop a node from the front of the queue
            let node = Q.shift();
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if (i < size - 1) {
                node.next = Q[0];
            }
            // Add the children, if any, to the back of
            // the queue
            if (node.left != null) {
                Q.push(node.left);
            }
            if (node.right != null) {
                Q.push(node.right);
            }
        }
    }
    // Since the tree has now been modified, return the root node
    return root;
}
```

</details>

<br>

## Approach 2: Using previously established next pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    // Start with the root node. There are no next pointers
    // that need to be set up on the first level
    struct Node* leftmost = root;
    // Once we reach the final level, we are done
    while (leftmost->left != NULL) {
        // Iterate the "linked list" starting from the head
        // node and using the next pointers, establish the
        // corresponding links for the next level
        struct Node* head = leftmost;
        while (head != NULL) {
            // CONNECTION 1
            head->left->next = head->right;
            // CONNECTION 2
            if (head->next != NULL) {
                head->right->next = head->next->left;
            }
            // Progress along the list (nodes on the current level)
            head = head->next;
        }
        // Move onto the next level
        leftmost = leftmost->left;
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
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node* leftmost = root;
        // Once we reach the final level, we are done
        while (leftmost->left != nullptr) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node* head = leftmost;
            while (head != nullptr) {
                // CONNECTION 1
                head->left->next = head->right;
                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }
                // Progress along the list (nodes on the current level)
                head = head->next;
            }
            // Move onto the next level
            leftmost = leftmost->left;
        }
        return root;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public Node Connect(Node root) {
        if (root == null) {
            return root;
        }

        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node leftmost = root;
        // Once we reach the final level, we are done
        while (leftmost.left != null) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node head = leftmost;
            while (head != null) {
                // CONNECTION 1
                head.left.next = head.right;
                // CONNECTION 2
                if (head.next != null) {
                    head.right.next = head.next.left;
                }

                // Progress along the list (nodes on the current level)
                head = head.next;
            }

            // Move onto the next level
            leftmost = leftmost.left;
        }

        return root;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// An already defined Node struct is assumed.
//
//    type Node struct {
//        Val int
//        Left, Right, Next *Node
//    }
func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    // Start with the root node. There are no next pointers
    // that need to be set up on the first level
    leftmost := root
    // Once we reach the final level, we are done
    for leftmost.Left != nil {
        // Iterate the "linked list" starting from the head
        // node and using the Next pointers, establish the
        // corresponding links for the next level
        head := leftmost
        for head != nil {
            // CONNECTION 1
            head.Left.Next = head.Right
            // CONNECTION 2
            if head.Next != nil {
                head.Right.Next = head.Next.Left
            }
            // Progress along the list (nodes on the current level)
            head = head.Next
        }
        // Move onto the next level
        leftmost = leftmost.Left
    }
    return root
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }

        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node leftmost = root;

        // Once we reach the final level, we are done
        while (leftmost.left != null) {
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the
            // corresponding links for the next level
            Node head = leftmost;

            while (head != null) {
                // CONNECTION 1
                head.left.next = head.right;

                // CONNECTION 2
                if (head.next != null) {
                    head.right.next = head.next.left;
                }

                // Progress along the list (nodes on the current level)
                head = head.next;
            }

            // Move onto the next level
            leftmost = leftmost.left;
        }

        return root;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var connect = function (root) {
    if (root === null) {
        return root;
    }
    // Start with the root node. There are no next pointers
    // that need to be set up on the first level
    let leftmost = root;
    // Once we reach the final level, we are done
    while (leftmost.left !== null) {
        // Iterate the "linked list" starting from the head
        // node and using the next pointers, establish the
        // corresponding links for the next level
        let head = leftmost;
        while (head !== null) {
            // CONNECTION 1
            head.left.next = head.right;
            // CONNECTION 2
            if (head.next !== null) {
                head.right.next = head.next.left;
            }
            // Progress along the list (nodes on the current level)
            head = head.next;
        }
        // Move onto the next level
        leftmost = leftmost.left;
    }
    return root;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def connect(self, root: "Node") -> "Node":

        if not root:
            return root

        # Start with the root node. There are no next pointers
        # that need to be set up on the first level
        leftmost = root

        # Once we reach the final level, we are done
        while leftmost.left:

            # Iterate the "linked list" starting from the head
            # node and using the next pointers, establish the
            # corresponding links for the next level
            head = leftmost
            while head:

                # CONNECTION 1
                head.left.next = head.right

                # CONNECTION 2
                if head.next:
                    head.right.next = head.next.left

                # Progress along the list (nodes on the current level)
                head = head.next

            # Move onto the next level
            leftmost = leftmost.left

        return root
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
class TreeNodeWithNext {
    val: number;
    left: TreeNodeWithNext | null;
    right: TreeNodeWithNext | null;
    next: TreeNodeWithNext | null;
    constructor(
        val?: number,
        left?: TreeNodeWithNext,
        right?: TreeNodeWithNext,
        next?: TreeNodeWithNext,
    ) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
        this.next = next === undefined ? null : next;
    }
}
function connect(root: TreeNodeWithNext | null): TreeNodeWithNext | null {
    if (root == null) {
        return root;
    }
    // Start with the root node. There are no next pointers
    // that need to be set up on the first level
    let leftmost: TreeNodeWithNext | null = root;
    // Once we reach the final level, we are done
    while (leftmost!.left != null) {
        // Iterate the "linked list" starting from the head
        // node and using the next pointers, establish the
        // corresponding links for the next level
        let head: TreeNodeWithNext | null = leftmost;
        while (head != null) {
            // CONNECTION 1
            head.left!.next = head.right!;
            // CONNECTION 2
            if (head.next != null) {
                head.right!.next = head.next.left!;
            }
            // Progress along the list (nodes on the current level)
            head = head.next;
        }
        // Move onto the next level
        leftmost = leftmost!.left;
    }
    return root;
}
```

</details>
