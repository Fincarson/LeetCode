# 24. Swap Nodes in Pairs

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/swap-nodes-in-pairs/)  
`Linked List` `Recursion`

**Problem Link:** [LeetCode 24 - Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

## Problem

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- The number of nodes in the list is in the range [0, 100].
- 0 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 24. Swap Nodes in Pairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursive Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list has no node or has only one node left.
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    // Nodes to be swapped
    struct ListNode* firstNode = head;
    struct ListNode* secondNode = head->next;
    // Swapping
    firstNode->next = swapPairs(secondNode->next);
    secondNode->next = firstNode;
    // Now the head is the second node
    return secondNode;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the list has no node or has only one node left.
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        // Nodes to be swapped
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        // Swapping
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
        // Now the head is the second node
        return secondNode;
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
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        // If the list has no node or has only one node left.
        if ((head == null) || (head.next == null)) {
            return head;
        }

        // Nodes to be swapped
        ListNode firstNode = head;
        ListNode secondNode = head.next;
        // Swapping
        firstNode.next = SwapPairs(secondNode.next);
        secondNode.next = firstNode;
        // Now the head is the second node
        return secondNode;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    // If the list has no node or has only one node left.
    if head == nil || head.Next == nil {
        return head
    }
    // Nodes to be swapped
    firstNode := head
    secondNode := head.Next
    // Swapping
    firstNode.Next = swapPairs(secondNode.Next)
    secondNode.Next = firstNode
    // Now the head is the second node
    return secondNode
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        // If the list has no node or has only one node left.
        if ((head == null) || (head.next == null)) {
            return head;
        }

        // Nodes to be swapped
        ListNode firstNode = head;
        ListNode secondNode = head.next;

        // Swapping
        firstNode.next = swapPairs(secondNode.next);
        secondNode.next = firstNode;

        // Now the head is the second node
        return secondNode;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var swapPairs = function (head) {
    // If the list has no node or has only one node left.
    if (head === null || head.next === null) {
        return head;
    }
    // Nodes to be swapped
    let firstNode = head;
    let secondNode = head.next;
    // Swapping
    firstNode.next = swapPairs(secondNode.next);
    secondNode.next = firstNode;
    // Now the head is the second node
    return secondNode;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """

        # If the list has no node or has only one node left.
        if not head or not head.next:
            return head

        # Nodes to be swapped
        first_node = head
        second_node = head.next

        # Swapping
        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node

        # Now the head is the second node
        return second_node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function swapPairs(head: ListNode | null): ListNode | null {
    // If the list has no node or has only one node left.
    if (head == null || head.next == null) {
        return head;
    }
    // Nodes to be swapped
    let firstNode: ListNode | null = head;
    let secondNode: ListNode | null = head.next;
    // Swapping
    firstNode.next = swapPairs(secondNode.next);
    secondNode.next = firstNode;
    // Now the head is the second node
    return secondNode;
}
```

</details>

<br>

## Approach 2: Iterative Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode* prevNode = dummy;
    while (head != NULL && head->next != NULL) {
        struct ListNode* firstNode = head;
        struct ListNode* secondNode = head->next;
        prevNode->next = secondNode;
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        prevNode = firstNode;
        head = firstNode->next;
    }
    return dummy->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as the prevNode for the head node
        // of the list and hence stores pointer to the head node.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevNode = dummy;
        while ((head != nullptr) && (head->next != nullptr)) {
            // Nodes to be swapped
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;
            // Swapping
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode->next;  // jump
        }
        // Return the new head node.
        return dummy->next;
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
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        // Dummy node acts as the prevNode for the head node
        // of the list and hence stores pointer to the head node.
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode prevNode = dummy;
        while ((head != null) && (head.next != null)) {
            // Nodes to be swapped
            ListNode firstNode = head;
            ListNode secondNode = head.next;
            // Swapping
            prevNode.next = secondNode;
            firstNode.next = secondNode.next;
            secondNode.next = firstNode;
            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode.next;  // jump
        }

        // Return the new head node.
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    // Dummy node acts as the prevNode for the head node
    // of the list and hence stores pointer to the head node.
    dummy := &ListNode{-1, nil}
    dummy.Next = head
    prevNode := dummy
    for head != nil && head.Next != nil {
        // Nodes to be swapped
        firstNode := head
        secondNode := head.Next
        // Swapping
        prevNode.Next = secondNode
        firstNode.Next = secondNode.Next
        secondNode.Next = firstNode
        // Reinitializing the head and prevNode for next swap
        prevNode = firstNode
        head = firstNode.Next // jump
    }
    // Return the new head node.
    return dummy.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        // Dummy node acts as the prevNode for the head node
        // of the list and hence stores pointer to the head node.
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode prevNode = dummy;

        while ((head != null) && (head.next != null)) {
            // Nodes to be swapped
            ListNode firstNode = head;
            ListNode secondNode = head.next;

            // Swapping
            prevNode.next = secondNode;
            firstNode.next = secondNode.next;
            secondNode.next = firstNode;

            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode.next; // jump
        }

        // Return the new head node.
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var swapPairs = function (head) {
    let dummy = new ListNode(-1);
    dummy.next = head;
    let prevNode = dummy;
    while (head !== null && head.next !== null) {
        let firstNode = head;
        let secondNode = head.next;
        prevNode.next = secondNode;
        firstNode.next = secondNode.next;
        secondNode.next = firstNode;
        prevNode = firstNode;
        head = firstNode.next;
    }
    return dummy.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # Dummy node acts as the prevNode for the head node
        # of the list and hence stores pointer to the head node.
        dummy = ListNode(-1)
        dummy.next = head

        prev_node = dummy

        while head and head.next:

            # Nodes to be swapped
            first_node = head
            second_node = head.next

            # Swapping
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node

            # Reinitializing the head and prev_node for next swap
            prev_node = first_node
            head = first_node.next

        # Return the new head node.
        return dummy.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function swapPairs(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(-1);
    dummy.next = head;
    let prevNode = dummy;
    while (head && head.next) {
        const firstNode = head;
        const secondNode = head.next;
        prevNode.next = secondNode;
        firstNode.next = secondNode.next;
        secondNode.next = firstNode;
        prevNode = firstNode;
        head = firstNode.next;
    }
    return dummy.next;
}
```

</details>
