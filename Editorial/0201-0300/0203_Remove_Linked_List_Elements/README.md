# 203. Remove Linked List Elements

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/remove-linked-list-elements/)  
`Linked List` `Recursion`

**Problem Link:** [LeetCode 203 - Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

## Problem

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

### Example 1

```text
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

### Example 2

```text
Input: head = [], val = 1
Output: []
```

### Example 3

```text
Input: head = [7,7,7,7], val = 7
Output: []
```

## Constraints

- The number of nodes in the list is in the range [0, 104].
- 1 <= Node.val <= 50
- 0 <= val <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Element](https://leetcode.com/problems/remove-element/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Convert Doubly Linked List to Array I](https://leetcode.com/problems/convert-doubly-linked-list-to-array-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Convert Doubly Linked List to Array II](https://leetcode.com/problems/convert-doubly-linked-list-to-array-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 203. Remove Linked List Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sentinel Node | C++, Java, Python3 |

## Approach 1: Sentinel Node

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public ListNode removeElements(ListNode head, int val) {
    ListNode sentinel = new ListNode(0);
    sentinel.next = head;

    ListNode prev = sentinel, curr = head;
    while (curr != null) {
      if (curr.val == val) prev.next = curr.next;
      else prev = curr;
      curr = curr.next;
    }
    return sentinel.next;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        
        prev, curr = sentinel, head
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next
        
        return sentinel.next
```

</details>
