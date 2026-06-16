# 147. Insertion Sort List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/insertion-sort-list/)  
`Linked List` `Sorting`

**Problem Link:** [LeetCode 147 - Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)

## Problem

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

### Example 1

```text
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

### Example 2

```text
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

## Constraints

- The number of nodes in the list is in the range [1, 5000].
- -5000 <= Node.val <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort List](https://leetcode.com/problems/sort-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 147. Insertion Sort List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Insertion Sort | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Insertion Sort

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        // At each iteration, we insert an element into the resulting list.
        struct ListNode* prev = dummy;
        // find the position to insert the current node
        while (prev->next != NULL && prev->next->val <= curr->val) {
            prev = prev->next;
        }
        struct ListNode* next = curr->next;
        // insert the current node to the new list
        curr->next = prev->next;
        prev->next = curr;
        // moving on to the next iteration
        curr = next;
    }
    return dummy->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        while (curr != NULL) {
            // At each iteration, we insert an element into the resulting list.
            ListNode* prev = dummy;
            // find the position to insert the current node
            while (prev->next != NULL && prev->next->val <= curr->val) {
                prev = prev->next;
            }
            ListNode* next = curr->next;
            // insert the current node to the new list
            curr->next = prev->next;
            prev->next = curr;
            // moving on to the next iteration
            curr = next;
        }
        return dummy->next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode InsertionSortList(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode curr = head;
        while (curr != null) {
            // At each iteration, we insert an element into the resulting list.
            ListNode prev = dummy;
            // find the position to insert the current node
            while (prev.next != null && prev.next.val <= curr.val) {
                prev = prev.next;
            }

            ListNode next = curr.next;
            // insert the current node to the new list
            curr.next = prev.next;
            prev.next = curr;
            // moving on to the next iteration
            curr = next;
        }

        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func insertionSortList(head *ListNode) *ListNode {
    dummy := &ListNode{}
    curr := head
    for curr != nil {
        // At each iteration, we insert an element into the resulting list.
        prev := dummy
        // find the position to insert the current node
        for prev.Next != nil && prev.Next.Val <= curr.Val {
            prev = prev.Next
        }
        next := curr.Next
        // insert the current node to the new list
        curr.Next = prev.Next
        prev.Next = curr
        // moving on to the next iteration
        curr = next
    }
    return dummy.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode curr = head;

        while (curr != null) {
            // At each iteration, we insert an element into the resulting list.
            ListNode prev = dummy;

            // find the position to insert the current node
            while (prev.next != null && prev.next.val <= curr.val) {
                prev = prev.next;
            }

            ListNode next = curr.next;
            // insert the current node to the new list
            curr.next = prev.next;
            prev.next = curr;

            // moving on to the next iteration
            curr = next;
        }

        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var insertionSortList = function (head) {
    let dummy = new ListNode();
    let curr = head;
    while (curr !== null) {
        // At each iteration, we insert an element into the resulting list.
        let prev = dummy;
        // find the position to insert the current node
        while (prev.next !== null && prev.next.val <= curr.val) {
            prev = prev.next;
        }
        let next = curr.next;
        // insert the current node to the new list
        curr.next = prev.next;
        prev.next = curr;
        // moving on to the next iteration
        curr = next;
    }
    return dummy.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode()
        curr = head

        while curr:
            # At each iteration, we insert an element into the resulting list.
            prev = dummy

            # find the position to insert the current node
            while prev.next and prev.next.val <= curr.val:
                prev = prev.next

            next = curr.next
            # insert the current node to the new list
            curr.next = prev.next
            prev.next = curr

            # moving on to the next iteration
            curr = next

        return dummy.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function insertionSortList(head: ListNode | null): ListNode | null {
    let dummy = new ListNode();
    let curr = head;
    while (curr !== null) {
        // At each iteration, we insert an element into the resulting list.
        let prev = dummy;
        // find the position to insert the current node
        while (prev.next !== null && prev.next.val <= curr.val) {
            prev = prev.next;
        }
        let next = curr.next;
        // insert the current node to the new list
        curr.next = prev.next;
        prev.next = curr;
        // moving on to the next iteration
        curr = next;
    }
    return dummy.next;
}
```

</details>
