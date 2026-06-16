# 61. Rotate List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/rotate-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 61 - Rotate List](https://leetcode.com/problems/rotate-list/)

## Problem

Given the head of a linked list, rotate the list to the right by k places.

### Example 1

```text
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

### Example 2

```text
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

## Constraints

- The number of nodes in the list is in the range [0, 500].
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rotate Array](https://leetcode.com/problems/rotate-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 61. Rotate List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
|  | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1:

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* rotateRight(struct ListNode* head, int k) {
    // base cases
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    // close the linked list into the ring
    struct ListNode* old_tail = head;
    int n;
    for (n = 1; old_tail->next != NULL; n++) old_tail = old_tail->next;
    old_tail->next = head;
    // find new tail : (n - k % n - 1)th node
    // and new head : (n - k % n)th node
    struct ListNode* new_tail = head;
    for (int i = 0; i < n - k % n - 1; i++) new_tail = new_tail->next;
    struct ListNode* new_head = new_tail->next;
    // break the ring
    new_tail->next = NULL;
    return new_head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // base cases
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        // close the linked list into the ring
        ListNode* old_tail = head;
        int n;
        for (n = 1; old_tail->next != NULL; n++) old_tail = old_tail->next;
        old_tail->next = head;
        // find new tail : (n - k % n - 1)th node
        // and new head : (n - k % n)th node
        ListNode* new_tail = head;
        for (int i = 0; i < n - k % n - 1; i++) new_tail = new_tail->next;
        ListNode* new_head = new_tail->next;
        // break the ring
        new_tail->next = NULL;
        return new_head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        // base cases
        if (head == null)
            return null;
        if (head.next == null)
            return head;
        // close the linked list into the ring
        ListNode old_tail = head;
        int n;
        for (n = 1; old_tail.next != null; n++) old_tail = old_tail.next;
        old_tail.next = head;
        // find new tail : (n - k % n - 1)th node
        // and new head : (n - k % n)th node
        ListNode new_tail = head;
        for (int i = 0; i < n - k % n - 1; i++) new_tail = new_tail.next;
        ListNode new_head = new_tail.next;
        // break the ring
        new_tail.next = null;
        return new_head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func rotateRight(head *ListNode, k int) *ListNode {
    // base cases
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return head
    }
    // close the linked list into the ring
    old_tail := head
    n := 1
    for old_tail.Next != nil {
        n++
        old_tail = old_tail.Next
    }
    old_tail.Next = head
    // find new tail : (n - k % n - 1)th node
    // and new head : (n - k % n)th node
    new_tail := head
    for i := 1; i < n-k%n; i++ {
        new_tail = new_tail.Next
    }
    new_head := new_tail.Next
    // break the ring
    new_tail.Next = nil
    return new_head
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        // base cases
        if (head == null) return null;
        if (head.next == null) return head;

        // close the linked list into the ring
        ListNode old_tail = head;
        int n;
        for (n = 1; old_tail.next != null; n++) old_tail = old_tail.next;
        old_tail.next = head;

        // find new tail : (n - k % n - 1)th node
        // and new head : (n - k % n)th node
        ListNode new_tail = head;
        for (int i = 0; i < n - (k % n) - 1; i++) new_tail = new_tail.next;
        ListNode new_head = new_tail.next;

        // break the ring
        new_tail.next = null;

        return new_head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var rotateRight = function (head, k) {
    // base cases
    if (head == null) return null;
    if (head.next == null) return head;
    // close the linked list into the ring
    let old_tail = head;
    let n;
    for (n = 1; old_tail.next != null; n++) old_tail = old_tail.next;
    old_tail.next = head;
    // find new tail : (n - k % n - 1)th node
    // and new head : (n - k % n)th node
    let new_tail = head;
    for (let i = 0; i < n - (k % n) - 1; i++) new_tail = new_tail.next;
    let new_head = new_tail.next;
    // break the ring
    new_tail.next = null;
    return new_head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateRight(
        self, head: Optional[ListNode], k: int
    ) -> Optional[ListNode]:
        # base cases
        if not head:
            return None
        if not head.next:
            return head

        # close the linked list into the ring
        old_tail = head
        n = 1
        while old_tail.next:
            old_tail = old_tail.next
            n += 1
        old_tail.next = head

        # find new tail : (n - k % n - 1)th node
        # and new head : (n - k % n)th node
        new_tail = head
        for i in range(n - k % n - 1):
            new_tail = new_tail.next
        new_head = new_tail.next

        # break the ring
        new_tail.next = None

        return new_head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function rotateRight(head: ListNode | null, k: number): ListNode | null {
    // base cases
    if (head == null) return null;
    if (head.next == null) return head;
    // close the linked list into the ring
    let old_tail = head;
    let n;
    for (n = 1; old_tail.next != null; n++) old_tail = old_tail.next;
    old_tail.next = head;
    // find new tail : (n - k % n - 1)th node
    // and new head : (n - k % n)th node
    let new_tail = head;
    for (let i = 0; i < n - (k % n) - 1; i++) new_tail = new_tail.next;
    let new_head = new_tail.next;
    // break the ring
    new_tail.next = null;
    return new_head;
}
```

</details>
