# 206. Reverse Linked List

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/reverse-linked-list/)  
`Linked List` `Recursion`

**Problem Link:** [LeetCode 206 - Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## Problem

Given the head of a singly linked list, reverse the list, and return the reversed list.

### Example 1

```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

### Example 2

```text
Input: head = [1,2]
Output: [2,1]
```

### Example 3

```text
Input: head = []
Output: []
```

## Constraints

- The number of nodes in the list is the range [0, 5000].
- -5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Tree Upside Down](https://leetcode.com/problems/binary-tree-upside-down/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Reverse Nodes in Even Length Groups](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 206. Reverse Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative | C++, Java, Python3 |
| Recursive | C++, Java, Python3 |

## Approach 1: Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp
            
        return prev
```

</details>

<br>

## Approach 2: Recursive

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode p = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return p;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if (not head) or (not head.next):
            return head
        
        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p
```

</details>
