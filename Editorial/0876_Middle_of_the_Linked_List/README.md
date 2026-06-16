# 876. Middle of the Linked List

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/middle-of-the-linked-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 876 - Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

## Problem

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

### Example 1

```text
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

### Example 2

```text
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

## Constraints

- The number of nodes in the list is in the range [1, 100].
- 1 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 876. Middle of the Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Output to Array | C++, Java, JavaScript, Python3 |
| Fast and Slow Pointer | C++, Java, JavaScript, Python3 |

## Approach 1: Output to Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode[] A = new ListNode[100];
        int t = 0;
        while (head != null) {
            A[t++] = head;
            head = head.next;
        }
        return A[t / 2];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var middleNode = function(head) {
    let A = [head];
    while (A[A.length - 1].next != null)
        A.push(A[A.length - 1].next);
    return A[Math.trunc(A.length / 2)];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        arr = [head]
        while arr[-1].next:
            arr.append(arr[-1].next)
        return arr[len(arr) // 2]
```

</details>

<br>

## Approach 2: Fast and Slow Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var middleNode = function(head) {
    slow = fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def middleNode(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```

</details>
