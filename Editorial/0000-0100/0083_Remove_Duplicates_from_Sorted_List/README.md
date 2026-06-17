# 83. Remove Duplicates from Sorted List

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)  
`Linked List`

**Problem Link:** [LeetCode 83 - Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

## Problem

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

### Example 1

```text
Input: head = [1,1,2]
Output: [1,2]
```

### Example 2

```text
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

## Constraints

- The number of nodes in the list is in the range [0, 300].
- -100 <= Node.val <= 100
- The list is guaranteed to be sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 83. Remove Duplicates from Sorted List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Straight-Forward Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Straight-Forward Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->val == current->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->val == current->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode current = head;
        while (current != null && current.next != null) {
            if (current.next.val == current.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func deleteDuplicates(head *ListNode) *ListNode {
    current := head
    for current != nil && current.Next != nil {
        if current.Next.Val == current.Val {
            current.Next = current.Next.Next
        } else {
            current = current.Next
        }
    }
    return head
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
        while (current != null && current.next != null) {
            if (current.next.val == current.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deleteDuplicates = function (head) {
    let current = head;
    while (current !== null && current.next !== null) {
        if (current.next.val === current.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }
    return head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        current = head
        while current is not None and current.next is not None:
            if current.next.val == current.val:
                current.next = current.next.next
            else:
                current = current.next
        return head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function deleteDuplicates(head: ListNode | null): ListNode | null {
    let current = head;
    while (current !== null && current.next !== null) {
        if (current.next.val === current.val) {
            current.next = current.next.next;
        } else {
            current = current.next;
        }
    }
    return head;
}
```

</details>
