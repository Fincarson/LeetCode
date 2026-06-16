# 82. Remove Duplicates from Sorted List II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 82 - Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

## Problem

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

### Example 1

```text
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

### Example 2

```text
Input: head = [1,1,1,2,3]
Output: [2,3]
```

## Constraints

- The number of nodes in the list is in the range [0, 300].
- -100 <= Node.val <= 100
- The list is guaranteed to be sorted in ascending order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 82. Remove Duplicates from Sorted List II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Sentinel Head + Predecessor | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Sentinel Head + Predecessor

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // sentinel
    struct ListNode* sentinel =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    sentinel->val = 0;
    sentinel->next = head;
    // predecessor = the last node
    // before the sublist of duplicates
    struct ListNode* pred = sentinel;
    while (head != NULL) {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if (head->next != NULL && head->val == head->next->val) {
            // move till the end of duplicates sublist
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            // Skip all duplicates
            pred->next = head->next;
            // otherwise, move predecessor
        } else {
            pred = pred->next;
        }
        // move forward
        head = head->next;
    }
    return sentinel->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // sentinel
        ListNode* sentinel = new ListNode(0, head);
        // predecessor = the last node
        // before the sublist of duplicates
        ListNode* pred = sentinel;
        while (head != NULL) {
            // If it's a beginning of duplicates sublist
            // skip all duplicates
            if (head->next != NULL && head->val == head->next->val) {
                // Move till the end of duplicates sublist
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip all duplicates
                pred->next = head->next;
                // otherwise, move predecessor
            } else {
                pred = pred->next;
            }
            // move forward
            head = head->next;
        }
        return sentinel->next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        // sentinel
        ListNode sentinel = new ListNode(0, head);
        // predecessor = the last node
        // before the sublist of duplicates
        ListNode pred = sentinel;
        while (head != null) {
            // If it's a beginning of duplicates sublist
            // skip all duplicates
            if (head.next != null && head.val == head.next.val) {
                // move till the end of duplicates sublist
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }

                // Skip all duplicates
                pred.next = head.next;
                // otherwise, move predecessor
            } else {
                pred = pred.next;
            }

            // move forward
            head = head.next;
        }

        return sentinel.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func deleteDuplicates(head *ListNode) *ListNode {
    // sentinel
    sentinel := &ListNode{0, head}
    // predecessor = the last node
    // before the sublist of duplicates
    pred := sentinel
    for head != nil {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if head.Next != nil && head.Val == head.Next.Val {
            // move till the end of duplicates sublist
            for head.Next != nil && head.Val == head.Next.Val {
                head = head.Next
            }
            // Skip all duplicates
            pred.Next = head.Next
            // otherwise, move predecessor
        } else {
            pred = pred.Next
        }
        // move forward
        head = head.Next
    }
    return sentinel.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // Sentinel
        ListNode sentinel = new ListNode(0, head);

        // predecessor = the last node
        // before the sublist of duplicates
        ListNode pred = sentinel;

        while (head != null) {
            // If it's a beginning of the duplicates sublist
            // skip all duplicates
            if (head.next != null && head.val == head.next.val) {
                // Move till the end of the duplicates sublist
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }

                // Skip all duplicates
                pred.next = head.next;
                // otherwise, move predecessor
            } else {
                pred = pred.next;
            }

            // move forward
            head = head.next;
        }
        return sentinel.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deleteDuplicates = function (head) {
    // sentinel
    let sentinel = new ListNode(0, head);
    // predecessor = the last node
    // before the sublist of duplicates
    let pred = sentinel;
    while (head !== null) {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if (head.next !== null && head.val === head.next.val) {
            // move till the end of duplicates sublist
            while (head.next !== null && head.val === head.next.val) {
                head = head.next;
            }
            // Skip all duplicates
            pred.next = head.next;
            // otherwise, move predecessor
        } else {
            pred = pred.next;
        }
        // move forward
        head = head.next;
    }
    return sentinel.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # sentinel
        sentinel = ListNode(0, head)

        # predecessor = the last node
        # before the sublist of duplicates
        pred = sentinel

        while head:
            # If it's the beginning of a duplicates sublist
            # skip all duplicates
            if head.next and head.val == head.next.val:
                # move till the end of duplicates sublist
                while head.next and head.val == head.next.val:
                    head = head.next

                # Skip all duplicates
                pred.next = head.next

            # Otherwise, move predecessor
            else:
                pred = pred.next

            # move forward
            head = head.next

        return sentinel.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function deleteDuplicates(head: ListNode | null): ListNode | null {
    // sentinel
    let sentinel: ListNode = new ListNode(0, head);
    // predecessor = the last node
    // before the sublist of duplicates
    let pred: ListNode = sentinel;
    while (head !== null) {
        // If it's a beginning of duplicates sublist
        // skip all duplicates
        if (head.next !== null && head.val === head.next.val) {
            // move till the end of duplicates sublist
            while (head.next !== null && head.val === head.next.val) {
                head = head.next;
            }
            // Skip all duplicates
            pred.next = head.next;
            // otherwise, move predecessor
        } else {
            pred = pred.next;
        }
        // move forward
        head = head.next;
    }
    return sentinel.next;
}
```

</details>
