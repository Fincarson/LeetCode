# 143. Reorder List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reorder-list/)  
`Linked List` `Two Pointers` `Stack` `Recursion`

**Problem Link:** [LeetCode 143 - Reorder List](https://leetcode.com/problems/reorder-list/)

## Problem

You are given the head of a singly linked-list. The list can be represented as:

```text
L0 → L1 → … → Ln - 1 → Ln
```

Reorder the list to be on the following form:

```text
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

### Example 1

```text
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

### Example 2

```text
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```

## Constraints

- The number of nodes in the list is in the range [1, 5 * 104].
- 1 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 143. Reorder List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Reverse the Second Part of the List and Merge Two Sorted Lists | Java, Python3 |

## Approach 1: Reverse the Second Part of the List and Merge Two Sorted Lists

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
// find the middle of linked list [Problem 876]
// in 1->2->3->4->5->6 find 4 
ListNode slow = head, fast = head;
while (fast != null && fast.next != null) {
  slow = slow.next;
  fast = fast.next.next;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# find the middle of linked list [Problem 876]
# in 1->2->3->4->5->6 find 4
slow = fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
```

</details>
