# 19. Remove Nth Node From End of List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 19 - Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## Problem

Given the head of a linked list, remove the nth node from the end of the list and return its head.

### Example 1

```text
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

### Example 2

```text
Input: head = [1], n = 1
Output: []
```

### Example 3

```text
Input: head = [1,2], n = 1
Output: [1]
```

## Constraints

- The number of nodes in the list is sz.
- 1 <= sz <= 30
- 0 <= Node.val <= 100
- 1 <= n <= sz

Follow up: Could you do this in one pass?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Delete N Nodes After M Nodes of a Linked List](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 19. Remove Nth Node From End of List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two pass algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One pass algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two pass algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    int length = 0;
    struct ListNode* first = head;
    while (first != NULL) {
        length++;
        first = first->next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first->next;
    }
    first->next = first->next->next;
    return dummy->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        ListNode* first = head;
        while (first != NULL) {
            length++;
            first = first->next;
        }
        length -= n;
        first = dummy;
        while (length > 0) {
            length--;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int length = 0;
        ListNode first = head;
        while (first != null) {
            length++;
            first = first.next;
        }

        length -= n;
        first = dummy;
        while (length > 0) {
            length--;
            first = first.next;
        }

        first.next = first.next.next;
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{}
    dummy.Next = head
    length := 0
    first := head
    for first != nil {
        length++
        first = first.Next
    }
    length -= n
    first = dummy
    for length > 0 {
        length--
        first = first.Next
    }
    first.Next = first.Next.Next
    return dummy.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int length = 0;
        ListNode first = head;
        while (first != null) {
            length++;
            first = first.next;
        }
        length -= n;
        first = dummy;
        while (length > 0) {
            length--;
            first = first.next;
        }
        first.next = first.next.next;
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var removeNthFromEnd = function (head, n) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let length = 0;
    let first = head;
    while (first !== null) {
        length++;
        first = first.next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first.next;
    }
    first.next = first.next.next;
    return dummy.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        length = 0
        first = head
        while first is not None:
            length += 1
            first = first.next
        length -= n
        first = dummy
        while length > 0:
            length -= 1
            first = first.next
        first.next = first.next.next
        return dummy.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    let dummy: ListNode | null = new ListNode(0);
    dummy.next = head;
    let length = 0;
    let first = head;
    while (first !== null) {
        length++;
        first = first.next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first.next;
    }
    first.next = first.next.next;
    return dummy.next;
}
```

</details>

<br>

## Approach 2: One pass algorithm

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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;
    // Advances first pointer so that the gap between first and second is n
    // nodes apart
    for (int i = 1; i <= n + 1; i++) first = first->next;
    // Move first to the end, maintaining the gap
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy.next;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        // Advances first pointer so that the gap between first and second is n
        // nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        // Move first to the end, maintaining the gap
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
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
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        // Advances first pointer so that the gap between first and second is n
        // nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first.next;
        }

        // Move first to the end, maintaining the gap
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        second.next = second.next.next;
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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{0, head}
    first := dummy
    second := dummy
    // Advances first pointer so that the gap between first and second is n nodes apart
    for i := 1; i <= n+1; i++ {
        first = first.Next
    }
    // Move first to the end, maintaining the gap
    for first != nil {
        first = first.Next
        second = second.Next
    }
    second.Next = second.Next.Next
    return dummy.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first.next;
        }
        // Move first to the end, maintaining the gap
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function removeNthFromEnd(head, n) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let first = dummy;
    let second = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (let i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first !== null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummy.next;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
        # Advances first pointer so that the gap between first and second is n nodes apart
        for i in range(n + 1):
            first = first.next
        # Move first to the end, maintaining the gap
        while first is not None:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummy.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    let dummy = new ListNode(0);
    dummy.next = head;
    let first: ListNode | null = dummy;
    let second: ListNode | null = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (let i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first !== null) {
        first = first.next;
        second = second.next;
    }
    if (second.next) {
        second.next = second.next.next;
    }
    return dummy.next;
}
```

</details>
