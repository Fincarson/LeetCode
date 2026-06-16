# 25. Reverse Nodes in k-Group

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/reverse-nodes-in-k-group/)  
`Linked List` `Recursion`

**Problem Link:** [LeetCode 25 - Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Problem

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

### Example 1

```text
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

### Example 2

```text
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

## Constraints

- The number of nodes in the list is n.
- 1 <= k <= n <= 5000
- 0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Reverse Nodes in Even Length Groups](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 25. Reverse Nodes in k-Group

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative O(1) space | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

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
struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    struct ListNode* new_head = NULL;
    struct ListNode* ptr = head;
    while (k > 0) {
        struct ListNode* next_node = ptr->next;
        ptr->next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int count = 0;
    struct ListNode* ptr = head;
    while (count < k && ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    if (count == k) {
        struct ListNode* reversedHead = reverseLinkedList(head, k);
        head->next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* ptr = head;
        while (k > 0) {
            ListNode* next_node = ptr->next;
            ptr->next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;
        while (count < k && ptr != nullptr) {
            ptr = ptr->next;
            count++;
        }
        if (count == k) {
            ListNode* reversedHead = this->reverseLinkedList(head, k);
            head->next = this->reverseKGroup(ptr, k);
            return reversedHead;
        }
        return head;
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
    public ListNode ReverseLinkedList(ListNode head, int k) {
        ListNode new_head = null;
        ListNode ptr = head;
        while (k > 0) {
            ListNode next_node = ptr.next;
            ptr.next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }

        return new_head;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode ptr = head;
        while (count < k && ptr != null) {
            ptr = ptr.next;
            count++;
        }

        if (count == k) {
            ListNode reversedHead = this.ReverseLinkedList(head, k);
            head.next = this.ReverseKGroup(ptr, k);
            return reversedHead;
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseLinkedList(head *ListNode, k int) *ListNode {
    var newHead *ListNode = nil
    ptr := head
    for k > 0 {
        nextNode := ptr.Next
        ptr.Next = newHead
        newHead = ptr
        ptr = nextNode
        k--
    }
    return newHead
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    count := 0
    ptr := head
    for count < k && ptr != nil {
        ptr = ptr.Next
        count++
    }
    if count == k {
        reversedHead := reverseLinkedList(head, k)
        head.Next = reverseKGroup(ptr, k)
        return reversedHead
    }
    return head
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
    public ListNode reverseLinkedList(ListNode head, int k) {
        // Reverse k nodes of the given linked list.
        // This function assumes that the list contains
        // atleast k nodes.
        ListNode new_head = null;
        ListNode ptr = head;

        while (k > 0) {
            // Keep track of the next node to process in the
            // original list
            ListNode next_node = ptr.next;

            // Insert the node pointed to by "ptr"
            // at the beginning of the reversed list
            ptr.next = new_head;
            new_head = ptr;

            // Move on to the next node
            ptr = next_node;

            // Decrement the count of nodes to be reversed by 1
            k--;
        }

        // Return the head of the reversed list
        return new_head;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode ptr = head;

        // First, see if there are atleast k nodes
        // left in the linked list.
        while (count < k && ptr != null) {
            ptr = ptr.next;
            count++;
        }

        // If we have k nodes, then we reverse them
        if (count == k) {
            // Reverse the first k nodes of the list and
            // get the reversed list's head.
            ListNode reversedHead = this.reverseLinkedList(head, k);

            // Now recurse on the remaining linked list. Since
            // our recursion returns the head of the overall processed
            // list, we use that and the "original" head of the "k" nodes
            // to re-wire the connections.
            head.next = this.reverseKGroup(ptr, k);
            return reversedHead;
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseLinkedList = function (head, k) {
    let new_head = null;
    let ptr = head;
    while (k > 0) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
};
var reverseKGroup = function (head, k) {
    let count = 0;
    let ptr = head;
    while (count < k && ptr != null) {
        ptr = ptr.next;
        count++;
    }
    if (count == k) {
        let reversedHead = reverseLinkedList(head, k);
        head.next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def reverseLinkedList(self, head, k):

        # Reverse k nodes of the given linked list.
        # This function assumes that the list contains
        # atleast k nodes.
        new_head, ptr = None, head
        while k:

            # Keep track of the next node to process in the
            # original list
            next_node = ptr.next

            # Insert the node pointed to by "ptr"
            # at the beginning of the reversed list
            ptr.next = new_head
            new_head = ptr

            # Move on to the next node
            ptr = next_node

            # Decrement the count of nodes to be reversed by 1
            k -= 1

        # Return the head of the reversed list
        return new_head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        count = 0
        ptr = head

        # First, see if there are atleast k nodes
        # left in the linked list.
        while count < k and ptr:
            ptr = ptr.next
            count += 1

        # If we have k nodes, then we reverse them
        if count == k:

            # Reverse the first k nodes of the list and
            # get the reversed list's head.
            reversedHead = self.reverseLinkedList(head, k)

            # Now recurse on the remaining linked list. Since
            # our recursion returns the head of the overall processed
            # list, we use that and the "original" head of the "k" nodes
            # to re-wire the connections.
            head.next = self.reverseKGroup(ptr, k)
            return reversedHead
        return head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseLinkedList(head: ListNode | null, k: number): ListNode | null {
    let new_head: ListNode | null = null;
    let ptr: ListNode | null = head;
    while (k > 0 && ptr != null) {
        let next_node: ListNode | null = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    let count: number = 0;
    let ptr: ListNode | null = head;
    while (count < k && ptr != null) {
        ptr = ptr.next;
        count++;
    }
    if (count == k) {
        let reversedHead: ListNode | null = reverseLinkedList(head, k);
        if (head) head.next = reverseKGroup(ptr, k);
        return reversedHead;
    }
    return head;
}
```

</details>

<br>

## Approach 2: Iterative O(1) space

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    // Reverse k nodes of the given linked list.
    // This function assumes that the list contains
    // at least k nodes.
    struct ListNode* new_head = NULL;
    struct ListNode* ptr = head;
    while (k > 0) {
        // Keep track of the next node to process in the
        // original list
        struct ListNode* next_node = ptr->next;
        // Insert the node pointed to by "ptr"
        // at the beginning of the reversed list
        ptr->next = new_head;
        new_head = ptr;
        // Move on to the next node
        ptr = next_node;
        // Decrement the count of nodes to be reversed by 1
        k--;
    }
    // Return the head of the reversed list
    return new_head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* ptr = head;
    struct ListNode* ktail = NULL;
    // Head of the final, modified linked list
    struct ListNode* new_head = NULL;
    // Keep going until there are nodes in the list
    while (ptr != NULL) {
        int count = 0;
        // Start counting nodes from the head
        ptr = head;
        // Find the head of the next k nodes
        while (count < k && ptr != NULL) {
            ptr = ptr->next;
            count += 1;
        }
        // If we counted k nodes, reverse them
        if (count == k) {
            // Reverse k nodes and get the new head
            struct ListNode* revHead = reverseLinkedList(head, k);
            // new_head is the head of the final linked list
            if (new_head == NULL) new_head = revHead;
            // ktail is the tail of the previous block of
            // reversed k nodes
            if (ktail != NULL) ktail->next = revHead;
            ktail = head;
            head = ptr;
        }
    }
    // attach the final, possibly un-reversed portion
    if (ktail != NULL) ktail->next = head;
    return new_head == NULL ? head : new_head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* ptr = head;
        while (k > 0) {
            ListNode* next_node = ptr->next;
            ptr->next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = nullptr;
        ListNode* new_head = nullptr;
        while (ptr != nullptr) {
            int count = 0;
            ptr = head;
            while (count < k && ptr != nullptr) {
                ptr = ptr->next;
                count++;
            }
            if (count == k) {
                ListNode* revHead = this->reverseLinkedList(head, k);
                if (new_head == nullptr) new_head = revHead;
                if (ktail != nullptr) ktail->next = revHead;
                ktail = head;
                head = ptr;
            }
        }
        if (ktail != nullptr) ktail->next = head;
        return new_head == nullptr ? head : new_head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode ReverseLinkedList(ListNode head, int k) {
        ListNode newHead = null;
        ListNode ptr = head;
        while (k > 0) {
            ListNode nextNode = ptr.next;
            ptr.next = newHead;
            newHead = ptr;
            ptr = nextNode;
            k--;
        }

        return newHead;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {
        ListNode ptr = head;
        ListNode ktail = null;
        ListNode newHead = null;
        while (ptr != null) {
            int count = 0;
            ptr = head;
            while (count < k && ptr != null) {
                ptr = ptr.next;
                count += 1;
            }

            if (count == k) {
                ListNode revHead = this.ReverseLinkedList(head, k);
                if (newHead == null) {
                    newHead = revHead;
                }

                if (ktail != null) {
                    ktail.next = revHead;
                }

                ktail = head;
                head = ptr;
            }
        }

        if (ktail != null) {
            ktail.next = head;
        }

        return newHead == null ? head : newHead;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseLinkedList(head *ListNode, k int) *ListNode {
    var newHead, ptr *ListNode = nil, head
    for k > 0 {
        nextNode := ptr.Next
        ptr.Next = newHead
        newHead = ptr
        ptr = nextNode
        k--
    }
    return newHead
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    ptr, ktail := head, &ListNode{}
    var newHead *ListNode = nil
    for ptr != nil {
        count := 0
        ptr = head
        for count < k && ptr != nil {
            ptr = ptr.Next
            count++
        }
        if count == k {
            revHead := reverseLinkedList(head, k)
            if newHead == nil {
                newHead = revHead
            }
            if ktail != nil {
                ktail.Next = revHead
            }
            ktail = head
            head = ptr
        }
    }
    if ktail != nil {
        ktail.Next = head
    }
    if newHead == nil {
        return head
    } else {
        return newHead
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode reverseLinkedList(ListNode head, int k) {
        // Reverse k nodes of the given linked list.
        // This function assumes that the list contains
        // atleast k nodes.
        ListNode new_head = null;
        ListNode ptr = head;

        while (k > 0) {
            // Keep track of the next node to process in the
            // original list
            ListNode next_node = ptr.next;

            // Insert the node pointed to by "ptr"
            // at the beginning of the reversed list
            ptr.next = new_head;
            new_head = ptr;

            // Move on to the next node
            ptr = next_node;

            // Decrement the count of nodes to be reversed by 1
            k--;
        }

        // Return the head of the reversed list
        return new_head;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode ptr = head;
        ListNode ktail = null;

        // Head of the final, moified linked list
        ListNode new_head = null;

        // Keep going until there are nodes in the list
        while (ptr != null) {
            int count = 0;

            // Start counting nodes from the head
            ptr = head;

            // Find the head of the next k nodes
            while (count < k && ptr != null) {
                ptr = ptr.next;
                count += 1;
            }

            // If we counted k nodes, reverse them
            if (count == k) {
                // Reverse k nodes and get the new head
                ListNode revHead = this.reverseLinkedList(head, k);

                // new_head is the head of the final linked list
                if (new_head == null) new_head = revHead;

                // ktail is the tail of the previous block of
                // reversed k nodes
                if (ktail != null) ktail.next = revHead;

                ktail = head;
                head = ptr;
            }
        }

        // attach the final, possibly un-reversed portion
        if (ktail != null) ktail.next = head;

        return new_head == null ? head : new_head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseLinkedList = function (head, k) {
    let new_head = null;
    let ptr = head;
    while (k > 0) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
};
var reverseKGroup = function (head, k) {
    let ptr = head;
    let ktail = null;
    let new_head = null;
    while (ptr !== null) {
        let count = 0;
        ptr = head;
        while (count < k && ptr !== null) {
            ptr = ptr.next;
            count++;
        }
        if (count === k) {
            let revHead = reverseLinkedList(head, k);
            if (new_head === null) new_head = revHead;
            if (ktail !== null) ktail.next = revHead;
            ktail = head;
            head = ptr;
        }
    }
    if (ktail !== null) ktail.next = head;
    return new_head === null ? head : new_head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def reverseLinkedList(self, head, k):

        # Reverse k nodes of the given linked list.
        # This function assumes that the list contains
        # atleast k nodes.
        new_head, ptr = None, head
        while k:

            # Keep track of the next node to process in the
            # original list
            next_node = ptr.next

            # Insert the node pointed to by "ptr"
            # at the beginning of the reversed list
            ptr.next = new_head
            new_head = ptr

            # Move on to the next node
            ptr = next_node

            # Decrement the count of nodes to be reversed by 1
            k -= 1

        # Return the head of the reversed list
        return new_head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        ptr = head
        ktail = None

        # Head of the final, moified linked list
        new_head = None

        # Keep going until there are nodes in the list
        while ptr:
            count = 0

            # Start counting nodes from the head
            ptr = head

            # Find the head of the next k nodes
            while count < k and ptr:
                ptr = ptr.next
                count += 1

            # If we counted k nodes, reverse them
            if count == k:

                # Reverse k nodes and get the new head
                revHead = self.reverseLinkedList(head, k)

                # new_head is the head of the final linked list
                if not new_head:
                    new_head = revHead

                # ktail is the tail of the previous block of
                # reversed k nodes
                if ktail:
                    ktail.next = revHead

                ktail = head
                head = ptr

        # attach the final, possibly un-reversed portion
        if ktail:
            ktail.next = head

        return new_head if new_head else head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseLinkedList(head: ListNode | null, k: number): ListNode | null {
    let new_head = null;
    let ptr = head;
    while (k > 0 && ptr != null) {
        let next_node = ptr.next;
        ptr.next = new_head;
        new_head = ptr;
        ptr = next_node;
        k--;
    }
    return new_head;
}
function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    let ptr = head;
    let ktail = null;
    let new_head = null;
    while (ptr != null) {
        let count = 0;
        let temp_ptr = ptr;
        while (count < k && temp_ptr != null) {
            temp_ptr = temp_ptr.next;
            count += 1;
        }
        if (count == k) {
            let revHead = reverseLinkedList(ptr, k);
            if (new_head == null) new_head = revHead;
            if (ktail != null) ktail.next = revHead;
            ktail = ptr;
            ptr = temp_ptr;
        } else {
            if (ktail != null) {
                ktail.next = ptr;
            }
            break;
        }
    }
    return new_head == null ? head : new_head;
}
```

</details>
