# 117. Populating Next Right Pointers in Each Node II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)  
`Linked List` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 117 - Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

## Problem

Given a binary tree

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
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

### Example 2

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 6000].
- -100 <= Node.val <= 100

Follow-up:

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 117. Populating Next Right Pointers in Each Node II

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
    // Outer while loop which iterates over
    // each level
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
        std::queue<Node*> Q;
        Q.push(root);
        // Outer while loop which iterates over
        // each level
        while (!Q.empty()) {
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
                // Dequeue a node from the front of the queue
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
    Q := list.New()
    Q.PushBack(root)
    // Outer while loop which iterates over
    // each level
    for Q.Len() > 0 {
        // Note the size of the queue
        size := Q.Len()
        // Iterate over all the nodes on the current level
        for i := 0; i < size; i++ {
            // Pop a node from the front of the queue
            front := Q.Front()
            node := front.Value.(*Node)
            Q.Remove(front)
            // This check is important. We don't want to
            // establish any wrong connections. The queue will
            // contain nodes from 2 levels at most at any
            // point in time. This check ensures we only
            // don't establish next pointers beyond the end
            // of a level
            if i < size-1 {
                node.Next = Q.Front().Value.(*Node)
            }
            // Add the children, if any, to the back of
            // the queue
            if node.Left != nil {
                Q.PushBack(node.Left)
            }
            if node.Right != nil {
                Q.PushBack(node.Right)
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
    // Special case: If root is nil then return nil
    if (!root) return root;
    // Initialize a Queue with the root
    const Q = [];
    Q.push(root);
    // Loop while the Queue is not empty
    while (Q.length > 0) {
        const size = Q.length;
        // Iterate over all the nodes currently in the Queue
        for (let i = 0; i < size; i++) {
            // Remove the first node from the Queue
            const node = Q.shift();
            // If this is not the last node in the level, point next to the next node
            if (i < size - 1) {
                node.next = Q[0];
            }
            // Add the left and right children (if they exist) to the Queue
            if (node.left) Q.push(node.left);
            if (node.right) Q.push(node.right);
        }
    }
    // Return the root
    return root;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def connect(self, root: Optional["Node"]) -> Optional["Node"]:

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
    if (!root) return root;
    // Initialize a Queue with the root
    const Q: Node[] = [];
    Q.push(root);
    // Loop while the Queue is not empty
    while (Q.length > 0) {
        const size = Q.length;
        // Iterate over all the nodes currently in the Queue
        for (let i = 0; i < size; i++) {
            // Remove the first node from the Queue
            const node: Node | undefined = Q.shift();
            // If this is not the last node in the level, point next to the next node
            if (i < size - 1) {
                if (node) node.next = Q[0];
            }
            // Add the left and right children (if they exist) to the Queue
            if (node?.left) Q.push(node?.left);
            if (node?.right) Q.push(node?.right);
        }
    }
    // Return the root
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
void processChild(struct Node* childNode, struct Node** prev,
                  struct Node** leftmost) {
    if (childNode) {
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if (*prev) {
            (*prev)->next = childNode;
        } else {
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            *leftmost = childNode;
        }
        *prev = childNode;
    }
}
struct Node* connect(struct Node* root) {
    if (!root) {
        return root;
    }
    // The root node is the only node on the first level
    // and hence its the leftmost node for that level
    struct Node* leftmost = root;
    // We have no idea about the structure of the tree,
    // so, we keep going until we do find the last level.
    // the nodes on the last level won't have any children
    while (leftmost) {
        // "prev" tracks the latest node on the "next" level
        // while "curr" tracks the latest node on the current
        // level.
        struct Node* prev = NULL;
        struct Node* curr = leftmost;
        // We reset this so that we can re-assign it to the leftmost
        // node of the next level. Also, if there isn't one, this
        // would help break us out of the outermost loop.
        leftmost = NULL;
        // Iterate on the nodes in the current level using
        // the next pointers already established.
        while (curr) {
            // Process both the children and update the prev
            // and leftmost pointers as necessary.
            processChild(curr->left, &prev, &leftmost);
            processChild(curr->right, &prev, &leftmost);
            // Move onto the next node.
            curr = curr->next;
        }
    }
    return root;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    Node* prev = NULL;
    Node* leftmost = NULL;
    void processChild(Node* childNode) {
        if (childNode) {
            // If the "prev" pointer is alread set i.e. if we
            // already found atleast one node on the next level,
            // setup its next pointer
            if (prev) {
                prev->next = childNode;
            } else {
                // Else it means this child node is the first node
                // we have encountered on the next level, so, we
                // set the leftmost pointer
                leftmost = childNode;
            }
            prev = childNode;
        }
    }

public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        leftmost = root;
        // Variable to keep track of leading node on the "current" level
        Node* curr = leftmost;
        // We have no idea about the structure of the tree,
        // so, we keep going until we do find the last level.
        // the nodes on the last level won't have any children
        while (leftmost) {
            // "prev" tracks the latest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            prev = NULL;
            curr = leftmost;
            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this
            // would help break us out of the outermost loop.
            leftmost = NULL;
            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr) {
                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                processChild(curr->left);
                processChild(curr->right);
                // Move onto the next node.
                curr = curr->next;
            }
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
    Node prev;
    Node leftmost;

    public void ProcessChild(Node childNode) {
        if (childNode != null) {
            // If the "prev" pointer is alread set i.e. if we
            // already found atleast one node on the next level,
            // setup its next pointer
            if (this.prev != null) {
                this.prev.next = childNode;
            } else {
                // Else it means this child node is the first node
                // we have encountered on the next level, so, we
                // set the leftmost pointer
                this.leftmost = childNode;
            }

            this.prev = childNode;
        }
    }

    public Node Connect(Node root) {
        if (root == null) {
            return root;
        }

        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        this.leftmost = root;
        // Variable to keep track of leading node on the "current" level
        Node curr = leftmost;
        // We have no idea about the structure of the tree,
        // so, we keep going until we do find the last level.
        // the nodes on the last level won't have any children
        while (this.leftmost != null) {
            // "prev" tracks the latest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            this.prev = null;
            curr = this.leftmost;
            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this
            // would help break us out of the outermost loop.
            this.leftmost = null;
            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr != null) {
                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                this.ProcessChild(curr.left);
                this.ProcessChild(curr.right);
                // Move onto the next node.
                curr = curr.next;
            }
        }

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
    // The root node is the only node on the first level
    // and hence its the leftmost node for that level
    leftmost := root
    var prev *Node = nil
    var curr *Node = nil
    // We have no idea about the structure of the tree,
    // so, we keep going until we do find the last level.
    // The nodes on the last level won't have any children
    for leftmost != nil {
        // "prev" tracks the latest node on the "next" level
        // while "curr" tracks the latest node on the current
        // level.
        prev = nil
        curr = leftmost
        // We reset this so that we can re-assign it to the leftmost
        // node of the next level. Also, if there isn't one, this
        // would help break us out of the outermost loop.
        leftmost = nil
        // Iterate on the nodes in the current level using
        // the next pointers already established.
        for curr != nil {
            // Process both the children and update the prev
            // and leftmost pointers as necessary.
            prev, leftmost = processChild(curr.Left, prev, leftmost)
            prev, leftmost = processChild(curr.Right, prev, leftmost)
            // Move onto the next node.
            curr = curr.Next
        }
    }
    return root
}

func processChild(childNode *Node, prev *Node, leftmost *Node) (*Node, *Node) {
    if childNode != nil {
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if prev != nil {
            prev.Next = childNode
        } else {
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            leftmost = childNode
        }
        prev = childNode
    }
    return prev, leftmost
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Node prev, leftmost;

    public void processChild(Node childNode) {
        if (childNode != null) {
            // If the "prev" pointer is alread set i.e. if we
            // already found atleast one node on the next level,
            // setup its next pointer
            if (this.prev != null) {
                this.prev.next = childNode;
            } else {
                // Else it means this child node is the first node
                // we have encountered on the next level, so, we
                // set the leftmost pointer
                this.leftmost = childNode;
            }

            this.prev = childNode;
        }
    }

    public Node connect(Node root) {
        if (root == null) {
            return root;
        }

        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        this.leftmost = root;

        // Variable to keep track of leading node on the "current" level
        Node curr = leftmost;

        // We have no idea about the structure of the tree,
        // so, we keep going until we do find the last level.
        // the nodes on the last level won't have any children
        while (this.leftmost != null) {
            // "prev" tracks the latest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            this.prev = null;
            curr = this.leftmost;

            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this
            // would help break us out of the outermost loop.
            this.leftmost = null;

            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr != null) {
                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                this.processChild(curr.left);
                this.processChild(curr.right);

                // Move onto the next node.
                curr = curr.next;
            }
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
    if (!root) {
        return root;
    }
    let leftmost = root;
    let prev = null;
    let curr = null;
    while (leftmost) {
        prev = null;
        curr = leftmost;
        leftmost = null;
        while (curr) {
            let res = processChild(curr.left, prev, leftmost);
            prev = res[0];
            leftmost = res[1];
            res = processChild(curr.right, prev, leftmost);
            prev = res[0];
            leftmost = res[1];
            curr = curr.next;
        }
    }
    return root;
};
var processChild = function (childNode, prev, leftmost) {
    if (childNode) {
        if (prev) {
            prev.next = childNode;
        } else {
            leftmost = childNode;
        }
        prev = childNode;
    }
    return [prev, leftmost];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def processChild(self, childNode, prev, leftmost):
        if childNode:

            # If the "prev" pointer is alread set i.e. if we
            # already found atleast one node on the next level,
            # setup its next pointer
            if prev:
                prev.next = childNode
            else:
                # Else it means this child node is the first node
                # we have encountered on the next level, so, we
                # set the leftmost pointer
                leftmost = childNode
            prev = childNode
        return prev, leftmost

    def connect(self, root: Optional["Node"]) -> Optional["Node"]:

        if not root:
            return root

        # The root node is the only node on the first level
        # and hence its the leftmost node for that level
        leftmost = root

        # We have no idea about the structure of the tree,
        # so, we keep going until we do find the last level.
        # The nodes on the last level won't have any children
        while leftmost:

            # "prev" tracks the latest node on the "next" level
            # while "curr" tracks the latest node on the current
            # level.
            prev, curr = None, leftmost

            # We reset this so that we can re-assign it to the leftmost
            # node of the next level. Also, if there isn't one, this
            # would help break us out of the outermost loop.
            leftmost = None

            # Iterate on the nodes in the current level using
            # the next pointers already established.
            while curr:

                # Process both the children and update the prev
                # and leftmost pointers as necessary.
                prev, leftmost = self.processChild(curr.left, prev, leftmost)
                prev, leftmost = self.processChild(curr.right, prev, leftmost)

                # Move onto the next node.
                curr = curr.next

        return root
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function connect(root: Node | null): Node | null {
    if (root === null) {
        return root;
    }
    // The root node is the only node on the first level
    // and hence its the leftmost node for that level
    let leftmost: Node | null = root;
    let prev: Node | null = null;
    let curr: Node | null = null;
    // We have no idea about the structure of the tree,
    // so, we keep going until we do find the last level.
    // The nodes on the last level won't have any children
    while (leftmost) {
        // "prev" tracks the latest node on the "next" level
        // while "curr" tracks the latest node on the current
        // level.
        prev = null;
        curr = leftmost;
        // We reset this so that we can re-assign it to the leftmost
        // node of the next level. Also, if there isn't one, this
        // would help break us out of the outermost loop.
        leftmost = null;
        // Iterate on the nodes in the current level using
        // the next pointers already established.
        while (curr) {
            // Process both the children and update the prev
            // and leftmost pointers as necessary.
            [prev, leftmost] = processChild(curr.left, prev, leftmost);
            [prev, leftmost] = processChild(curr.right, prev, leftmost);
            // Move onto the next node.
            curr = curr.next;
        }
    }
    return root;
}
function processChild(
    childNode: Node | null,
    prev: Node | null,
    leftmost: Node | null,
): [Node | null, Node | null] {
    if (childNode) {
        // If the "prev" pointer is alread set i.e. if we
        // already found atleast one node on the next level,
        // setup its next pointer
        if (prev) {
            prev.next = childNode;
        } else {
            // Else it means this child node is the first node
            // we have encountered on the next level, so, we
            // set the leftmost pointer
            leftmost = childNode;
        }
        prev = childNode;
    }
    return [prev, leftmost];
}
```

</details>
