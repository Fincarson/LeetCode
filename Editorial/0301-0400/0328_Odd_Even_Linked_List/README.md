# 328. Odd Even Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/odd-even-linked-list/)  
`Linked List`

**Problem Link:** [LeetCode 328 - Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

## Problem

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

### Example 1

```text
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

### Example 2

```text
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

## Constraints

- The number of nodes in the linked list is in the range [0, 104].
- -106 <= Node.val <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Transform Array by Parity](https://leetcode.com/problems/transform-array-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 328. Odd Even Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | Java |

## Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode odd = head, even = head.next, evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}
```

</details>
