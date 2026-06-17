# 369. Plus One Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/plus-one-linked-list/)  
`Linked List` `Math`

**Problem Link:** [LeetCode 369 - Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list/)

## Problem

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

### Example 1

```text
Input: head = [1,2,3]
Output: [1,2,4]
```

### Example 2

```text
Input: head = [0]
Output: [1]
```

## Constraints

- The number of nodes in the linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- The number represented by the linked list does not contain leading zeros except for the zero itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Plus One](https://leetcode.com/problems/plus-one/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Double a Number Represented as a Linked List](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 369. Plus One Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sentinel Head + Textbook Addition. | C++, Java, Python3 |

## Approach 1: Sentinel Head + Textbook Addition.

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        // sentinel head
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* notNine = sentinel;

        // find the rightmost not-nine digit
        while (head != nullptr) {
            if (head->val != 9) notNine = head;
            head = head->next;
        }
        // increase this rightmost not-nine digit by 1
        notNine->val++;
        notNine = notNine->next;
        // set all the following nines to zeros
        while (notNine != nullptr) {
            notNine->val = 0;
            notNine = notNine->next;
        }

        delete notNine;
        return sentinel->val != 0 ? sentinel : sentinel->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode plusOne(ListNode head) {
        // sentinel head
        ListNode sentinel = new ListNode(0);
        sentinel.next = head;
        ListNode notNine = sentinel;

        // find the rightmost not-nine digit
        while (head != null) {
            if (head.val != 9) {
                notNine = head;
            }
            head = head.next;
        }

        // increase this rightmost not-nine digit by 1
        notNine.val++;
        notNine = notNine.next;

        // set all the following nines to zeros
        while (notNine != null) {
            notNine.val = 0;
            notNine = notNine.next;
        }

    return sentinel.val != 0 ? sentinel : sentinel.next;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        # sentinel head
        sentinel = ListNode(0)
        sentinel.next = head
        not_nine = sentinel

        # find the rightmost not-nine digit
        while head:
            if head.val != 9:
                not_nine = head
            head = head.next

        # increase this rightmost not-nine digit by 1
        not_nine.val += 1
        not_nine = not_nine.next

        # set all the following nines to zeros
        while not_nine:
            not_nine.val = 0
            not_nine = not_nine.next

        return sentinel if sentinel.val else sentinel.next
```

</details>
