# 86. Partition List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/partition-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 86 - Partition List](https://leetcode.com/problems/partition-list/)

## Problem

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

### Example 1

```text
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

### Example 2

```text
Input: head = [2,1], x = 2
Output: [1,2]
```

## Constraints

- The number of nodes in the list is in the range [0, 200].
- -100 <= Node.val <= 100
- -200 <= x <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Partition Array According to Given Pivot](https://leetcode.com/problems/partition-array-according-to-given-pivot/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 86. Partition List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointer Approach | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointer Approach

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* before_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    before_head->next = NULL;
    struct ListNode* before = before_head;
    struct ListNode* after_head =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    after_head->next = NULL;
    struct ListNode* after = after_head;
    while (head != NULL) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = after_head->next;
    return before_head->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head;
        while (head != NULL) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_head->next;
        return before_head->next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode Partition(ListNode head, int x) {
        ListNode before_head = new ListNode(0);
        ListNode before = before_head;
        ListNode after_head = new ListNode(0);
        ListNode after = after_head;
        while (head != null) {
            if (head.val < x) {
                before.next = head;
                before = before.next;
            } else {
                after.next = head;
                after = after.next;
            }

            head = head.next;
        }

        after.next = null;
        before.next = after_head.next;
        return before_head.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func partition(head *ListNode, x int) *ListNode {
    before_head := &ListNode{0, nil}
    before := before_head
    after_head := &ListNode{0, nil}
    after := after_head
    for head != nil {
        if head.Val < x {
            before.Next = head
            before = before.Next
        } else {
            after.Next = head
            after = after.Next
        }
        head = head.Next
    }
    after.Next = nil
    before.Next = after_head.Next
    return before_head.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode partition(ListNode head, int x) {
        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two lists.
        // All of these are initialized with the dummy nodes created.
        ListNode before_head = new ListNode(0);
        ListNode before = before_head;
        ListNode after_head = new ListNode(0);
        ListNode after = after_head;

        while (head != null) {
            // If the original list node is lesser than the given x,
            // assign it to the before list.
            if (head.val < x) {
                before.next = head;
                before = before.next;
            } else {
                // If the original list node is greater or equal to the given x,
                // assign it to the after list.
                after.next = head;
                after = after.next;
            }

            // move ahead in the original list
            head = head.next;
        }

        // Last node of "after" list would also be ending node of the reformed list
        after.next = null;

        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before.next = after_head.next;

        return before_head.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var partition = function (head, x) {
    var before_head = new ListNode(0);
    var before = before_head;
    var after_head = new ListNode(0);
    var after = after_head;
    while (head != null) {
        if (head.val < x) {
            before.next = head;
            before = before.next;
        } else {
            after.next = head;
            after = after.next;
        }
        head = head.next;
    }
    after.next = null;
    before.next = after_head.next;
    return before_head.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def partition(self, head: ListNode, x: int) -> ListNode:

        # before and after are the two pointers used to create two list
        # before_head and after_head are used to save the heads of the two lists.
        # All of these are initialized with the dummy nodes created.
        before = before_head = ListNode(0)
        after = after_head = ListNode(0)

        while head:
            # If the original list node is lesser than the given x,
            # assign it to the before list.
            if head.val < x:
                before.next = head
                before = before.next
            else:
                # If the original list node is greater or equal to the given x,
                # assign it to the after list.
                after.next = head
                after = after.next

            # move ahead in the original list
            head = head.next

        # Last node of "after" list would also be ending node of the reformed list
        after.next = None
        # Once all the nodes are correctly assigned to the two lists,
        # combine them to form a single list which would be returned.
        before.next = after_head.next

        return before_head.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function partition(head: ListNode | null, x: number): ListNode | null {
    let before_head: ListNode = new ListNode(0);
    let before: ListNode = before_head;
    let after_head: ListNode = new ListNode(0);
    let after: ListNode = after_head;
    while (head !== null) {
        if (head.val < x) {
            before.next = head;
            before = before.next;
        } else {
            after.next = head;
            after = after.next;
        }
        head = head.next;
    }
    after.next = null;
    before.next = after_head.next;
    return before_head.next;
}
```

</details>
