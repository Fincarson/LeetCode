# 138. Copy List with Random Pointer

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/copy-list-with-random-pointer/)  
`Hash Table` `Linked List`

**Problem Link:** [LeetCode 138 - Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

## Problem

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

- val: an integer representing Node.val
- random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

### Example 1

```text
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

### Example 2

```text
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

### Example 3

```text
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

## Constraints

- 0 <= n <= 1000
- -104 <= Node.val <= 104
- Node.random is null or is pointing to some node in the linked list.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Clone Graph](https://leetcode.com/problems/clone-graph/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone Binary Tree With Random Pointer](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Clone N-ary Tree](https://leetcode.com/problems/clone-n-ary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 138. Copy List with Random Pointer

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative with $$O(N)$$ Space | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative with $$O(1)$$ Space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
    public:
        int val;
        Node* next;
        Node* random;
        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
};
*/
class Solution {
private:
    // HashMap which holds old nodes as keys and new nodes as its values.
    unordered_map<Node*, Node*> visitedHash;

public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        // If we have already processed the current node, then we simply return
        // the cloned version of it.
        if (this->visitedHash.find(head) != this->visitedHash.end()) {
            return this->visitedHash[head];
        }
        // Create a new node with the value same as old node. (i.e. copy the
        // node)
        Node* node = new Node(head->val, NULL, NULL);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this
        // would help us avoid them.
        this->visitedHash[head] = node;
        // Recursively copy the remaining linked list starting once from the
        // next pointer and then from the random pointer. Thus we have two
        // independent recursive calls. Finally we update the next and random
        // pointers for the new node created.
        node->next = this->copyRandomList(head->next);
        node->random = this->copyRandomList(head->random);
        return node;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    public Node(int _val, Node _next, Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
}
*/

public class Solution {
    // Dictionary which holds old nodes as keys and new nodes as its values.
    private Dictionary<Node, Node> visitedHash = new Dictionary<Node, Node>();

    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // If we have already processed the current node, then we simply return
        // the cloned version of it.
        if (this.visitedHash.ContainsKey(head)) {
            return this.visitedHash[head];
        }

        // Create a new node with the value same as old node. (i.e., copy the
        // node)
        Node node = new Node(head.val, null, null);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this
        // would help us avoid them.
        this.visitedHash[head] = node;
        // Recursively copy the remaining linked list starting once from the
        // next pointer and then from the random pointer. Thus we have two
        // independent recursive calls. Finally we update the next and random
        // pointers for the new node created.
        node.next = this.CopyRandomList(head.next);
        node.random = this.CopyRandomList(head.random);
        return node;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/*
    type Node struct {
        Val int
        Next *Node
        Random *Node
    }
*/
func copyRandomList(head *Node) *Node {
    // HashMap which holds old nodes as keys and new nodes as its values.
    visitedHash := map[*Node]*Node{}
    // A recursive function to copy the node.
    var cloneNode func(node *Node) *Node
    cloneNode = func(node *Node) *Node {
        if node == nil {
            return nil
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if _, ok := visitedHash[node]; ok {
            return visitedHash[node]
        }
        // Create a new node
        // with the value same as old node.
        newNode := &Node{Val: node.Val}
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid them.
        visitedHash[node] = newNode
        // Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        newNode.Next = cloneNode(node.Next)
        newNode.Random = cloneNode(node.Random)
        return newNode
    }
    return cloneNode(head)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
public class Solution {
    // HashMap which holds old nodes as keys and new nodes as its values.
    HashMap<Node, Node> visitedHash = new HashMap<Node, Node>();

    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // If we have already processed the current node, then we simply return the cloned version of
        // it.
        if (this.visitedHash.containsKey(head)) {
            return this.visitedHash.get(head);
        }

        // Create a new node with the value same as old node. (i.e. copy the node)
        Node node = new Node(head.val, null, null);

        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid
        // them.
        this.visitedHash.put(head, node);

        // Recursively copy the remaining linked list starting once from the next pointer and then from
        // the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        node.next = this.copyRandomList(head.next);
        node.random = this.copyRandomList(head.random);

        return node;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/*
 * Definition for a node.
 * function Node(val, next, random) {
 *  	  this.val = val;
 *     this.next = next;
 *     this.random = random;
 * };
 */
var copyRandomList = function (head) {
    // HashMap which holds old nodes as keys and new nodes as its values.
    let visitedHash = new Map();
    let cloneNode = function (node) {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visitedHash.has(node)) {
            return visitedHash.get(node);
        }
        // Create a new node
        // with the value same as old node.
        let newNode = new Node(node.val, null, null);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid them.
        visitedHash.set(node, newNode);
        // Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        newNode.next = cloneNode(node.next);
        newNode.random = cloneNode(node.random);
        return newNode;
    };
    return cloneNode(head);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Dictionary which holds old nodes as keys and new nodes as its values.
        self.visitedHash = {}

    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":

        if head == None:
            return None

        # If we have already processed the current node, then we simply return the cloned version of it.
        if head in self.visitedHash:
            return self.visitedHash[head]

        # create a new node
        # with the value same as old node.
        node = Node(head.val, None, None)

        # Save this value in the hash map. This is needed since there might be
        # loops during traversal due to randomness of random pointers and this would help us avoid them.
        self.visitedHash[head] = node

        # Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        # Thus we have two independent recursive calls.
        # Finally we update the next and random pointers for the new node created.
        node.next = self.copyRandomList(head.next)
        node.random = self.copyRandomList(head.random)

        return node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     next: Node | null
 *     random: Node | null
 *     constructor(val?: number, next?: Node, random?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: Node | null): Node | null {
    // HashMap which holds old nodes as keys and new nodes as its values.
    let visitedHash: Map<Node, Node> = new Map();

    // Helper function to clone a node
    const cloneNode = function (node: Node | null): Node | null {
        if (node === null) {
            return null;
        }
        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visitedHash.has(node)) {
            return visitedHash.get(node)!;
        }
        // Create a new node
        // with the value same as old node.
        let newNode: Node = new Node(node.val, null, null);
        // Save this value in the hash map. This is needed since there might be
        // loops during traversal due to randomness of random pointers and this would help us avoid them.
        visitedHash.set(node, newNode);

        // Recursively copy the remaining linked list starting once from the next pointer and then from the random pointer.
        // Thus we have two independent recursive calls.
        // Finally we update the next and random pointers for the new node created.
        newNode.next = cloneNode(node.next);
        newNode.random = cloneNode(node.random);
        return newNode;
    };

    return cloneNode(head);
}
```

</details>

<br>

## Approach 2: Iterative with $$O(N)$$ Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/*
// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
  Node(int _val, Node* _next, Node* _random)
      : val{_val}, next{_next}, random{_random} {};
};
*/
class Solution {
private:
    // Visited dictionary to hold old node reference as key and new node
    // reference as the value
    unordered_map<Node*, Node*> visited;

public:
    Node* getClonedNode(Node* node) {
        // If node exists then
        if (node) {
            // Check if its in the visited map
            if (visited.find(node) != visited.end()) {
                // If its in the visited map then return the new node reference
                // from the map
                return visited[node];
            } else {
                // Otherwise create a new node, save the reference in the
                // visited map and return it.
                visited[node] = new Node(node->val, NULL, NULL);
                return visited[node];
            }
        }
        return NULL;
    }
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* oldNode = head;
        // Creating the new head node.
        Node* newNode = new Node(oldNode->val);
        this->visited[oldNode] = newNode;
        // Iterate on the linked list until all nodes are cloned.
        while (oldNode != NULL) {
            // Get the clones of the nodes referenced by random and next
            // pointers.
            newNode->random = this->getClonedNode(oldNode->random);
            newNode->next = this->getClonedNode(oldNode->next);
            // Move one step ahead in the linked list.
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return this->visited[head];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    public Node(int _val, Node _next, Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

public class Solution {
    private Dictionary<Node, Node> visited = new Dictionary<Node, Node>();

    public Node GetClonedNode(Node node) {
        if (node != null) {
            if (visited.ContainsKey(node)) {
                return visited[node];
            } else {
                visited[node] = new Node(node.val, null, null);
                return visited[node];
            }
        }

        return null;
    }

    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node oldNode = head;
        Node newNode = new Node(oldNode.val, null, null);
        visited[oldNode] = newNode;
        while (oldNode != null) {
            newNode.random = this.GetClonedNode(oldNode.random);
            newNode.next = this.GetClonedNode(oldNode.next);
            oldNode = oldNode.next;
            newNode = newNode.next;
        }

        return visited[head];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/*
// Definition for a Node.

    type Node struct {
        Val    int
        Next   *Node
        Random *Node
    }
*/
func copyRandomList(head *Node) *Node {
    // Creating a visited map to hold old node reference as key and new node reference as the value
    visited := make(map[*Node]*Node)
    getClonedNode := func(node *Node) *Node {
        // If node exists then
        if node != nil {
            // Check if it's in the visited map
            if _, ok := visited[node]; ok {
                // If it's in the visited map then return the new node reference from the map
                return visited[node]
            } else {
                // Otherwise create a new node, save the reference in the visited map and return it.
                newNode := &Node{Val: node.Val}
                visited[node] = newNode
                return newNode
            }
        }
        return nil
    }
    if head == nil {
        return nil
    }
    oldNode := head
    // Creating the new head node.
    newNode := &Node{Val: oldNode.Val}
    visited[oldNode] = newNode
    // Iterate on the linked list until all nodes are cloned.
    for oldNode != nil {
        // Get the clones of the nodes referenced by random and next pointers.
        newNode.Random = getClonedNode(oldNode.Random)
        newNode.Next = getClonedNode(oldNode.Next)
        // Move one step ahead in the linked list.
        oldNode = oldNode.Next
        newNode = newNode.Next
    }
    return visited[head]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
public class Solution {
    // Visited dictionary to hold old node reference as "key" and new node reference as the "value"
    HashMap<Node, Node> visited = new HashMap<Node, Node>();

    public Node getClonedNode(Node node) {
        // If the node exists then
        if (node != null) {
            // Check if the node is in the visited dictionary
            if (this.visited.containsKey(node)) {
                // If its in the visited dictionary then return the new node reference from the dictionary
                return this.visited.get(node);
            } else {
                // Otherwise create a new node, add to the dictionary and return it
                this.visited.put(node, new Node(node.val, null, null));
                return this.visited.get(node);
            }
        }
        return null;
    }

    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        Node oldNode = head;

        // Creating the new head node.
        Node newNode = new Node(oldNode.val);
        this.visited.put(oldNode, newNode);

        // Iterate on the linked list until all nodes are cloned.
        while (oldNode != null) {
            // Get the clones of the nodes referenced by random and next pointers.
            newNode.random = this.getClonedNode(oldNode.random);
            newNode.next = this.getClonedNode(oldNode.next);

            // Move one step ahead in the linked list.
            oldNode = oldNode.next;
            newNode = newNode.next;
        }
        return this.visited.get(head);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/*
// Definition for a Node.
function Node(val, next, random) {
   this.val = val;
   this.next = next;
   this.random = random;
};
*/
var copyRandomList = function (head) {
    // Creating a visited dictionary to hold old node reference as key and new node reference as the value
    var visited = new Map();
    function getClonedNode(node) {
        // If node exists then
        if (node) {
            // Check if its in the visited map
            if (visited.has(node)) {
                // If its in the visited map then return the new node reference from the map
                return visited.get(node);
            } else {
                // Otherwise create a new node, save the reference in the visited map and return it.
                var newNode = new Node(node.val, null, null);
                visited.set(node, newNode);
                return newNode;
            }
        }
        return null;
    }
    if (head == null) {
        return null;
    }
    var oldNode = head;
    // Creating the new head node.
    var newNode = new Node(oldNode.val);
    visited.set(oldNode, newNode);
    // Iterate on the linked list until all nodes are cloned.
    while (oldNode != null) {
        // Get the clones of the nodes referenced by random and next pointers.
        newNode.random = getClonedNode(oldNode.random);
        newNode.next = getClonedNode(oldNode.next);
        // Move one step ahead in the linked list.
        oldNode = oldNode.next;
        newNode = newNode.next;
    }
    return visited.get(head);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # Creating a visited dictionary to hold old node reference as "key" and new node reference as the "value"
        self.visited = {}

    def getClonedNode(self, node):
        # If node exists then
        if node:
            # Check if its in the visited dictionary
            if node in self.visited:
                # If its in the visited dictionary then return the new node reference from the dictionary
                return self.visited[node]
            else:
                # Otherwise create a new node, save the reference in the visited dictionary and return it.
                self.visited[node] = Node(node.val, None, None)
                return self.visited[node]
        return None

    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":

        if not head:
            return head

        old_node = head
        # Creating the new head node.
        new_node = Node(old_node.val, None, None)
        self.visited[old_node] = new_node

        # Iterate on the linked list until all nodes are cloned.
        while old_node != None:

            # Get the clones of the nodes referenced by random and next pointers.
            new_node.random = self.getClonedNode(old_node.random)
            new_node.next = self.getClonedNode(old_node.next)

            # Move one step ahead in the linked list.
            old_node = old_node.next
            new_node = new_node.next

        return self.visited[head]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/*
// Definition for a Node.
function Node(val: number, next: any, random: any) {
   this.val = val;
   this.next = next;
   this.random = random;
};
*/
function copyRandomList(head: any) {
    // Creating a visited dictionary to hold old node reference as key and new node reference as the value
    let visited = new Map();
    function getClonedNode(node: any) {
        // If node exists then
        if (node) {
            // Check if its in the visited map
            if (visited.has(node)) {
                // If its in the visited map then return the new node reference from the map
                return visited.get(node);
            } else {
                // Otherwise create a new node, save the reference in the visited map and return it.
                let newNode = new Node(node.val, null, null);
                visited.set(node, newNode);
                return newNode;
            }
        }
        return null;
    }
    if (head == null) {
        return null;
    }
    let oldNode = head;
    // Creating the new head node.
    let newNode = new Node(oldNode.val);
    visited.set(oldNode, newNode);
    // Iterate on the linked list until all nodes are cloned.
    while (oldNode != null) {
        // Get the clones of the nodes referenced by random and next pointers.
        newNode.random = getClonedNode(oldNode.random);
        newNode.next = getClonedNode(oldNode.next);
        // Move one step ahead in the linked list.
        oldNode = oldNode.next;
        newNode = newNode.next;
    }
    return visited.get(head);
}
```

</details>

<br>

## Approach 3: Iterative with $$O(1)$$ Space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Node* nodeConstructor(int val, struct Node* next, struct Node* random) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = next;
    newNode->random = random;
    return newNode;
}
struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return NULL;
    }
    // Creating a new weaved list of original and copied nodes.
    struct Node* ptr = head;
    while (ptr != NULL) {
        // Cloned node
        struct Node* newNode = nodeConstructor(ptr->val, NULL, NULL);
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }
    ptr = head;
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random
    // pointers, to assign references to random pointers for cloned nodes.
    while (ptr != NULL) {
        ptr->next->random = (ptr->random != NULL) ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }
    // Unweave the linked list to get back the original linked list and the
    // cloned list. i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
    // A'->B'->C'
    struct Node* ptr_old_list = head;        // A->B->C
    struct Node* ptr_new_list = head->next;  // A'->B'->C'
    struct Node* head_old = head->next;
    while (ptr_old_list != NULL) {
        ptr_old_list->next = ptr_old_list->next->next;
        ptr_new_list->next =
            (ptr_new_list->next != NULL) ? ptr_new_list->next->next : NULL;
        ptr_old_list = ptr_old_list->next;
        ptr_new_list = ptr_new_list->next;
    }
    return head_old;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // Creating a new weaved list of original and copied nodes.
        Node* ptr = head;
        while (ptr != nullptr) {
            // Cloned node
            Node* newNode = new Node(ptr->val, nullptr, nullptr);
            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr = head;
        // Now link the random pointers of the new nodes created.
        // Iterate the newly created list and use the original nodes' random
        // pointers, to assign references to random pointers for cloned nodes.
        while (ptr != nullptr) {
            ptr->next->random =
                (ptr->random != nullptr) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        // Unweave the linked list to get back the original linked list and the
        // cloned list. i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
        // A'->B'->C'
        Node* ptr_old_list = head;        // A->B->C
        Node* ptr_new_list = head->next;  // A'->B'->C'
        Node* head_old = head->next;
        while (ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            ptr_new_list->next = (ptr_new_list->next != nullptr)
                                     ? ptr_new_list->next->next
                                     : nullptr;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_old;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;

    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // Creating a new weaved list of original and copied nodes.
        Node ptr = head;
        while (ptr != null) {
            // Cloned node
            Node newNode = new Node(ptr.val);

            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            newNode.next = ptr.next;
            ptr.next = newNode;
            ptr = newNode.next;
        }

        ptr = head;

        // Now link the random pointers of the new nodes created.
        // Iterate the newly created list and use the original nodes' random
        // pointers, to assign references to random pointers for cloned nodes.
        while (ptr != null) {
            ptr.next.random = (ptr.random != null) ? ptr.random.next : null;
            ptr = ptr.next.next;
        }

        // Unweave the linked list to get back the original linked list and the
        // cloned list. i.e. A->A'->B->B'->C->C' would be broken to A->B->C and
        // A'->B'->C'
        Node ptr_old_list = head;       // A->B->C
        Node ptr_new_list = head.next;  // A'->B'->C'
        Node head_old = head.next;
        while (ptr_old_list != null) {
            ptr_old_list.next = ptr_old_list.next.next;
            ptr_new_list.next =
                (ptr_new_list.next != null) ? ptr_new_list.next.next : null;
            ptr_old_list = ptr_old_list.next;
            ptr_new_list = ptr_new_list.next;
        }

        return head_old;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func copyRandomList(head *Node) *Node {
    if head == nil {
        return nil
    }
    // Creating a new weaved list of original and copied nodes.
    ptr := head
    for ptr != nil {
        // Cloned node
        newNode := &Node{ptr.Val, nil, nil}
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode.Next = ptr.Next
        ptr.Next = newNode
        ptr = newNode.Next
    }
    ptr = head
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random pointers,
    // to assign references to random pointers for cloned nodes.
    for ptr != nil {
        if ptr.Random != nil {
            ptr.Next.Random = ptr.Random.Next
        } else {
            ptr.Next.Random = nil
        }
        ptr = ptr.Next.Next
    }
    // Unweave the linked list to get back the original linked list and the cloned list.
    // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
    ptrOldList := head      // A->B->C
    ptrNewList := head.Next // A'->B'->C'
    headOld := head.Next
    for ptrOldList != nil {
        ptrOldList.Next = ptrOldList.Next.Next
        if ptrNewList.Next != nil {
            ptrNewList.Next = ptrNewList.Next.Next
        } else {
            ptrNewList.Next = nil
        }
        ptrOldList = ptrOldList.Next
        ptrNewList = ptrNewList.Next
    }
    return headOld
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
public class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }

        // Creating a new weaved list of original and copied nodes.
        Node ptr = head;
        while (ptr != null) {
            // Cloned node
            Node newNode = new Node(ptr.val);

            // Inserting the cloned node just next to the original node.
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            newNode.next = ptr.next;
            ptr.next = newNode;
            ptr = newNode.next;
        }

        ptr = head;

        // Now link the random pointers of the new nodes created.
        // Iterate the newly created list and use the original nodes' random pointers,
        // to assign references to random pointers for cloned nodes.
        while (ptr != null) {
            ptr.next.random = (ptr.random != null) ? ptr.random.next : null;
            ptr = ptr.next.next;
        }

        // Unweave the linked list to get back the original linked list and the cloned list.
        // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
        Node ptr_old_list = head; // A->B->C
        Node ptr_new_list = head.next; // A'->B'->C'
        Node head_new = head.next;
        while (ptr_old_list != null) {
            ptr_old_list.next = ptr_old_list.next.next;
            ptr_new_list.next = (ptr_new_list.next != null)
                ? ptr_new_list.next.next
                : null;
            ptr_old_list = ptr_old_list.next;
            ptr_new_list = ptr_new_list.next;
        }
        return head_new;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var copyRandomList = function (head) {
    if (head === null) {
        return null;
    }
    // Creating a new weaved list of original and copied nodes.
    let ptr = head;
    while (ptr !== null) {
        // Cloned node
        let newNode = new Node(ptr.val, null, null);
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode.next = ptr.next;
        ptr.next = newNode;
        ptr = newNode.next;
    }
    ptr = head;
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random pointers,
    // to assign references to random pointers for cloned nodes.
    while (ptr !== null) {
        ptr.next.random = ptr.random !== null ? ptr.random.next : null;
        ptr = ptr.next.next;
    }
    // Unweave the linked list to get back the original linked list and the cloned list.
    // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
    var ptr_old_list = head; // A->B->C
    var ptr_new_list = head.next; // A'->B'->C'
    var head_old = head.next;
    while (ptr_old_list !== null) {
        ptr_old_list.next = ptr_old_list.next.next;
        ptr_new_list.next =
            ptr_new_list.next !== null ? ptr_new_list.next.next : null;
        ptr_old_list = ptr_old_list.next;
        ptr_new_list = ptr_new_list.next;
    }
    return head_old;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return head

        # Creating a new weaved list of original and copied nodes.
        ptr = head
        while ptr:

            # Cloned node
            new_node = Node(ptr.val, None, None)

            # Inserting the cloned node just next to the original node.
            # If A->B->C is the original linked list,
            # Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
            new_node.next = ptr.next
            ptr.next = new_node
            ptr = new_node.next

        ptr = head

        # Now link the random pointers of the new nodes created.
        # Iterate the newly created list and use the original nodes random pointers,
        # to assign references to random pointers for cloned nodes.
        while ptr:
            ptr.next.random = ptr.random.next if ptr.random else None
            ptr = ptr.next.next

        # Unweave the linked list to get back the original linked list and the cloned list.
        # i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
        ptr_old_list = head  # A->B->C
        ptr_new_list = head.next  # A'->B'->C'
        head_new = head.next
        while ptr_old_list:
            ptr_old_list.next = ptr_old_list.next.next
            ptr_new_list.next = (
                ptr_new_list.next.next if ptr_new_list.next else None
            )
            ptr_old_list = ptr_old_list.next
            ptr_new_list = ptr_new_list.next
        return head_new
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function copyRandomList(head: Node): Node {
    if (head === null) {
        return null;
    }
    // Creating a new weaved list of original and copied nodes.
    let ptr = head;
    while (ptr !== null) {
        // Cloned node
        let newNode = new Node(ptr.val, null, null);
        // Inserting the cloned node just next to the original node.
        // If A->B->C is the original linked list,
        // Linked list after weaving cloned nodes would be A->A'->B->B'->C->C'
        newNode.next = ptr.next;
        ptr.next = newNode;
        ptr = newNode.next;
    }
    ptr = head;
    // Now link the random pointers of the new nodes created.
    // Iterate the newly created list and use the original nodes' random pointers,
    // to assign references to random pointers for cloned nodes.
    while (ptr !== null) {
        ptr.next.random = ptr.random !== null ? ptr.random.next : null;
        ptr = ptr.next.next;
    }
    // Unweave the linked list to get back the original linked list and the cloned list.
    // i.e. A->A'->B->B'->C->C' would be broken to A->B->C and A'->B'->C'
    var ptr_old_list = head; // A->B->C
    var ptr_new_list = head.next; // A'->B'->C'
    var head_old = head.next;
    while (ptr_old_list !== null) {
        ptr_old_list.next = ptr_old_list.next.next;
        ptr_new_list.next =
            ptr_new_list.next !== null ? ptr_new_list.next.next : null;
        ptr_old_list = ptr_old_list.next;
        ptr_new_list = ptr_new_list.next;
    }
    return head_old;
}
```

</details>
