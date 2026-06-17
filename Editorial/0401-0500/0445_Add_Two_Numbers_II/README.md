# 445. Add Two Numbers II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/add-two-numbers-ii/)  
`Linked List` `Math` `Stack`

**Problem Link:** [LeetCode 445 - Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

## Problem

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Example 1

```text
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

### Example 2

```text
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
```

### Example 3

```text
Input: l1 = [0], l2 = [0]
Output: [0]
```

## Constraints

- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

Follow up: Could you solve it without reversing the input lists?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 445. Add Two Numbers II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reverse Given Linked Lists | C++, Java, Python3 |
| Stack | C++, Java, Python3 |

## Approach 1: Reverse Given Linked Lists

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp;
        while (head) {
            // Keep the next node.
             temp = head->next;
            // reverse the link
            head->next = prev;
            // Update the previous node and the current node.
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);

        int totalSum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();
        while (r1 || r2) {
            if (r1) {
                totalSum += r1->val;
                r1 = r1->next;
            }
            if (r2) {
                totalSum += r2->val;
                r2 = r2->next;
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* head = new ListNode(carry);
            head->next = ans;
            ans = head;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null, temp;
        while (head != null) {
            // Keep the next node
            temp = head.next;
            // Reverse the link
            head.next = prev;
            // Update the previous node and the current node.
            prev = head;
            head = temp;    
        }    
        return prev;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode r1 = reverseList(l1);
        ListNode r2 = reverseList(l2);
        
        int totalSum = 0, carry = 0;
        ListNode ans = new ListNode();
        while (r1 != null || r2 != null) {
            if (r1 != null) {
                totalSum += r1.val;
                r1 = r1.next;
            }
            if (r2 != null) {
                totalSum += r2.val;
                r2 = r2.next;
            }
            
            ans.val = totalSum % 10;
            carry = totalSum / 10;
            ListNode head = new ListNode(carry);
            head.next = ans;
            ans = head;
            totalSum = carry;
        }

        return carry == 0 ? ans.next: ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        temp = None
        while head:
            # Keep the next node
            temp = head.next
            # Reverse the link
            head.next = prev
            # Update the previous node and the current node.
            prev = head
            head = temp
        return prev

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        r1 = self.reverseList(l1)
        r2 = self.reverseList(l2)

        total_sum = 0
        carry = 0
        ans = ListNode()
        while r1 or r2:
            if r1:
                total_sum += r1.val
                r1 = r1.next
            if r2:
                total_sum += r2.val
                r2 = r2.next

            ans.val = total_sum % 10
            carry = total_sum // 10
            head = ListNode(carry)
            head.next = ans
            ans = head
            total_sum = carry

        return ans.next if carry == 0 else ans
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }

            ans->val = totalSum % 10;
            carry = totalSum / 10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = ans;
            ans = newNode;
            totalSum = carry;
        }

        return carry == 0 ? ans->next : ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        
        while(l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        };
        while(l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }
        
        int totalSum = 0, carry = 0;
        ListNode ans = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.pop();
            }
            if (!s2.empty()) {
                totalSum += s2.pop();
            }
            
            ans.val = totalSum % 10;
            carry = totalSum / 10;
            ListNode head = new ListNode(carry);
            head.next = ans;
            ans = head;
            totalSum = carry;
        }

        return carry == 0 ? ans.next: ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1 = []
        s2 = []

        while l1:
            s1.append(l1.val)
            l1 = l1.next
        while l2:
            s2.append(l2.val)
            l2 = l2.next

        total_sum = 0
        carry = 0
        ans = ListNode()
        while s1 or s2:
            if s1:
                total_sum += s1.pop()
            if s2:
                total_sum += s2.pop()

            ans.val = total_sum % 10
            carry = total_sum // 10
            head = ListNode(carry)
            head.next = ans
            ans = head
            total_sum = carry

        return ans.next if carry == 0 else ans
```

</details>
