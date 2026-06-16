# 1290. Convert Binary Number in a Linked List to Integer

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)  
`Linked List` `Math`

**Problem Link:** [LeetCode 1290 - Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

## Problem

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

### Example 1

```text
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
```

### Example 2

```text
Input: head = [0]
Output: 0
```

## Constraints

- The Linked List is not empty.
- Number of nodes will not exceed 30.
- Each node's value is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1290. Convert Binary Number in a Linked List to Integer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Representation | Java, Python3 |
| Bit Manipulation | Java, Python3 |

## Approach 1: Binary Representation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getDecimalValue(ListNode head) {
        int num = head.val;
        while (head.next != null) {
            num = num * 2 + head.next.val;
            head = head.next;    
        }
        return num;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = num * 2 + head.next.val
            head = head.next
        return num
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getDecimalValue(ListNode head) {
        int num = head.val;
        while (head.next != null) {
            num = (num << 1) | head.next.val;
            head = head.next;    
        }
        return num;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = (num << 1) | head.next.val
            head = head.next
        return num
```

</details>
