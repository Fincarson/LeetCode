# 142. Linked List Cycle II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/linked-list-cycle-ii/)  
`Hash Table` `Linked List` `Two Pointers`

**Problem Link:** [LeetCode 142 - Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

## Problem

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

### Example 1

```text
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

### Example 2

```text
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

### Example 3

```text
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

## Constraints

- The number of the nodes in the list is in the range [0, 104].
- -105 <= Node.val <= 105
- pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 142. Linked List Cycle II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Floyd's Tortoise and Hare Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// use uthash.h header for C to have hash (set) functionality
// Definition for ListNode in C:
// typedef struct ListNode {
//     int val;
//     struct ListNode* next;
//     UT_hash_handle hh;
// } ListNode;
typedef struct HashNode {
    struct ListNode* node;
    UT_hash_handle hh;
} HashNode;
struct ListNode* detectCycle(struct ListNode* head) {
    // Initialize an empty hash set
    HashNode* nodesSeen = NULL;
    // Start from the head of the linked list
    struct ListNode* node = head;
    while (node != NULL) {
        // If the current node is in nodesSeen, we have a cycle
        HashNode* s;
        HASH_FIND_PTR(nodesSeen, &node, s);
        if (s != NULL) {
            return s->node;
        } else {
            // Add this node to nodesSeen and move to the next node
            HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
            new_node->node = node;
            HASH_ADD_PTR(nodesSeen, node, new_node);
            node = node->next;
        }
    }
    // If we reach a null node, there is no cycle
    return NULL;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Initialize an empty hash set
        unordered_set<ListNode*> nodesSeen;

        // Start from the head of the linked list
        ListNode* node = head;
        while (node != nullptr) {
            // If the current node is in nodesSeen, we have a cycle
            if (nodesSeen.find(node) != nodesSeen.end()) {
                return node;
            } else {
                // Add this node to nodesSeen and move to the next node
                nodesSeen.insert(node);
                node = node->next;
            }
        }

        // If we reach a null node, there is no cycle
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        // Initialize an empty hash set
        HashSet<ListNode> nodesSeen = new HashSet<ListNode>();
        // Start from the head of the linked list
        ListNode node = head;
        while (node != null) {
            // If the current node is in nodesSeen, we have a cycle
            if (nodesSeen.Contains(node)) {
                return node;
            } else {
                // Add this node to nodesSeen and move to the next node
                nodesSeen.Add(node);
                node = node.next;
            }
        }

        // If we reach a null node, there is no cycle
        return null;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/*
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    // Initialize an empty hash set
    nodesSeen := make(map[*ListNode]bool)
    // Start from the head of the linked list
    node := head
    for node != nil {
        // If the current node is in nodesSeen, we have a cycle
        if _, ok := nodesSeen[node]; ok {
            return node
        } else {
            // Add this node to nodesSeen and move to the next node
            nodesSeen[node] = true
            node = node.Next
        }
    }
    // If we reach a null node, there is no cycle
    return nil
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        // Initialize an empty hash set
        HashSet<ListNode> nodesSeen = new HashSet<>();

        // Start from the head of the linked list
        ListNode node = head;
        while (node != null) {
            // If the current node is in nodesSeen, we have a cycle
            if (nodesSeen.contains(node)) {
                return node;
            } else {
                // Add this node to nodesSeen and move to the next node
                nodesSeen.add(node);
                node = node.next;
            }
        }

        // If we reach a null node, there is no cycle
        return null;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
var detectCycle = function (head) {
    // Initialize an empty hash set
    let nodesSeen = new Set();
    // Start from the head of the linked list
    let node = head;
    while (node !== null) {
        // If the current node is in nodesSeen, we have a cycle
        if (nodesSeen.has(node)) {
            return node;
        } else {
            // Add this node to nodesSeen and move to the next node
            nodesSeen.add(node);
            node = node.next;
        }
    }
    // If we reach a null node, there is no cycle
    return null;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize an empty hash set
        nodes_seen = set()

        # Start from the head of the linked list
        node = head
        while node is not None:
            # If the current node is in nodes_seen, we have a cycle
            if node in nodes_seen:
                return node
            else:
                # Add this node to nodes_seen and move to the next node
                nodes_seen.add(node)
                node = node.next

        # If we reach a null node, there is no cycle
        return None
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function detectCycle(head: ListNode | null): ListNode | null {
    // Initialize an empty hash set
    let nodesSeen = new Set<ListNode | null>();
    // Start from the head of the linked list
    let node: ListNode | null = head;
    while (node !== null) {
        // If the current node is in nodesSeen, we have a cycle
        if (nodesSeen.has(node)) {
            return node;
        } else {
            // Add this node to nodesSeen and move to the next node
            nodesSeen.add(node);
            node = node.next;
        }
    }
    // If we reach a null node, there is no cycle
    return null;
}
```

</details>

<br>

## Approach 2: Floyd's Tortoise and Hare Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode *detectCycle(struct ListNode *head) {
    // Initialize tortoise and hare pointers
    struct ListNode *tortoise = head;
    struct ListNode *hare = head;
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    // Move tortoise one step and hare two steps
    do {
        tortoise = tortoise->next;
        hare = hare->next->next;
    } while (hare != NULL && hare->next != NULL && tortoise != hare);
    // Check if there is no cycle
    if (hare == NULL || hare->next == NULL) {
        return NULL;
    }
    // Reset the hare pointer to the head
    hare = head;
    // Move both pointers one step until they meet again
    while (tortoise != hare) {
        tortoise = tortoise->next;
        hare = hare->next;
    }
    // Return the node where the cycle begins
    return tortoise;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Initialize tortoise and hare pointers
        ListNode* tortoise = head;
        ListNode* hare = head;

        // Move tortoise one step and hare two steps
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;

            // Check if the hare meets the tortoise
            if (tortoise == hare) {
                break;
            }
        }

        // Check if there is no cycle
        if (!hare || !hare->next) {
            return nullptr;
        }

        // Reset either the hare pointer to the head
        hare = head;

        // Move both pointers one step until they meet again
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        // Return the node where the cycle begins
        return tortoise;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        // Initialize tortoise and hare pointers
        ListNode tortoise = head;
        ListNode hare = head;
        // Move tortoise one step and hare two steps
        while (hare != null && hare.next != null) {
            tortoise = tortoise.next;
            hare = hare.next.next;
            // Check if the hare meets the tortoise
            if (tortoise == hare) {
                break;
            }
        }

        // Check if there is no cycle
        if (hare == null || hare.next == null) {
            return null;
        }

        // Reset either tortoise or hare pointer to the head
        hare = head;
        // Move both pointers one step until they meet again
        while (tortoise != hare) {
            tortoise = tortoise.next;
            hare = hare.next;
        }

        // Return the node where the cycle begins
        return tortoise;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func detectCycle(head *ListNode) *ListNode {
    // Initialize tortoise and hare pointers
    tortoise, hare := head, head
    // Move tortoise one step and hare two steps
    for hare != nil && hare.Next != nil {
        tortoise = tortoise.Next
        hare = hare.Next.Next
        // Check if the hare meets the tortoise
        if tortoise == hare {
            break
        }
    }
    // Check if there is no cycle
    if hare == nil || hare.Next == nil {
        return nil
    }
    // Reset either the hare pointer to the head
    hare = head
    // Move both pointers one step until they meet again
    for tortoise != hare {
        tortoise = tortoise.Next
        hare = hare.Next
    }
    // Return the node where the cycle begins
    return tortoise
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        // Initialize tortoise and hare pointers
        ListNode tortoise = head;
        ListNode hare = head;

        // Move tortoise one step and hare two steps
        while (hare != null && hare.next != null) {
            tortoise = tortoise.next;
            hare = hare.next.next;

            // Check if the hare meets the tortoise
            if (tortoise == hare) {
                break;
            }
        }

        // Check if there is no cycle
        if (hare == null || hare.next == null) {
            return null;
        }

        // Reset either tortoise or hare pointer to the head
        hare = head;

        // Move both pointers one step until they meet again
        while (tortoise != hare) {
            tortoise = tortoise.next;
            hare = hare.next;
        }

        // Return the node where the cycle begins
        return tortoise;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var detectCycle = function (head) {
    // Initialize tortoise and hare pointers
    let tortoise = head;
    let hare = head;
    // Move tortoise one step and hare two steps
    while (hare && hare.next) {
        tortoise = tortoise.next;
        hare = hare.next.next;
        // Check if the hare meets the tortoise
        if (tortoise === hare) {
            break;
        }
    }
    // Check if there is no cycle
    if (!hare || !hare.next) {
        return null;
    }
    // Reset either the hare pointer to the head
    hare = head;
    // Move both pointers one step until they meet again
    while (tortoise !== hare) {
        tortoise = tortoise.next;
        hare = hare.next;
    }
    // Return the node where the cycle begins
    return tortoise;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize tortoise and hare pointers
        tortoise = head
        hare = head

        # Move tortoise one step and hare two steps
        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next

            # Check if the hare meets the tortoise
            if tortoise == hare:
                break

        # Check if there is no cycle
        if not hare or not hare.next:
            return None

        # Reset either tortoise or hare pointer to the head
        hare = head

        # Move both pointers one step until they meet again
        while tortoise != hare:
            tortoise = tortoise.next
            hare = hare.next

        # Return the node where the cycle begins
        return tortoise
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function detectCycle(head: ListNode): ListNode {
    // Initialize tortoise and hare pointers
    let tortoise = head;
    let hare = head;
    // Move tortoise one step and hare two steps
    while (hare && hare.next) {
        tortoise = tortoise.next;
        hare = hare.next.next;
        // Check if the hare meets the tortoise
        if (tortoise == hare) {
            break;
        }
    }
    // Check if there is no cycle
    if (!hare || !hare.next) {
        return null;
    }
    // Reset either the hare pointer to the head
    hare = head;
    // Move both pointers one step until they meet again
    while (tortoise != hare) {
        tortoise = tortoise.next;
        hare = hare.next;
    }
    // Return the node where the cycle begins
    return tortoise;
}
```

</details>
