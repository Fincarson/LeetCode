# 234. Palindrome Linked List

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/palindrome-linked-list/)  
`Linked List` `Two Pointers` `Stack` `Recursion`

**Problem Link:** [LeetCode 234 - Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

## Problem

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

### Example 1

```text
Input: head = [1,2,2,1]
Output: true
```

### Example 2

```text
Input: head = [1,2]
Output: false
```

## Constraints

- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 234. Palindrome Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Copy into Array List and then Use Two Pointer Technique | Java, Python3 |
| Recursive (Advanced) | Java, Python3 |
| Reverse Second Half In-place | Java, Python3 |

## Approach 1: Copy into Array List and then Use Two Pointer Technique

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> vals = new ArrayList<>();

        // Convert LinkedList into ArrayList.
        ListNode currentNode = head;
        while (currentNode != null) {
            vals.add(currentNode.val);
            currentNode = currentNode.next;
        }

        // Use two-pointer technique to check for palindrome.
        int front = 0;
        int back = vals.size() - 1;
        while (front < back) {
            // Note that we must use ! .equals instead of !=
            // because we are comparing Integer, not int.
            if (!vals.get(front).equals(vals.get(back))) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        vals = []
        current_node = head
        while current_node is not None:
            vals.append(current_node.val)
            current_node = current_node.next
        return vals == vals[::-1]
```

</details>

<br>

## Approach 2: Recursive (Advanced)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private ListNode frontPointer;

    private boolean recursivelyCheck(ListNode currentNode) {
        if (currentNode != null) {
            if (!recursivelyCheck(currentNode.next)) return false;
            if (currentNode.val != frontPointer.val) return false;
            frontPointer = frontPointer.next;
        }
        return true;
    }

    public boolean isPalindrome(ListNode head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        self.front_pointer = head

        def recursively_check(current_node=head):
            if current_node is not None:
                if not recursively_check(current_node.next):
                    return False
                if self.front_pointer.val != current_node.val:
                    return False
                self.front_pointer = self.front_pointer.next
            return True

        return recursively_check()
```

</details>

<br>

## Approach 3: Reverse Second Half In-place

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isPalindrome(ListNode head) {

        if (head == null) return true;

        // Find the end of first half and reverse second half.
        ListNode firstHalfEnd = endOfFirstHalf(head);
        ListNode secondHalfStart = reverseList(firstHalfEnd.next);

        // Check whether or not there is a palindrome.
        ListNode p1 = head;
        ListNode p2 = secondHalfStart;
        boolean result = true;
        while (result && p2 != null) {
            if (p1.val != p2.val) result = false;
            p1 = p1.next;
            p2 = p2.next;
        }        

        // Restore the list and return the result.
        firstHalfEnd.next = reverseList(secondHalfStart);
        return result;
    }

    // Taken from https://leetcode.com/problems/reverse-linked-list/solution/
    private ListNode reverseList(ListNode head) {
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

    private ListNode endOfFirstHalf(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def isPalindrome(self, head: ListNode) -> bool:
        if head is None:
            return True

        # Find the end of first half and reverse second half.
        first_half_end = self.end_of_first_half(head)
        second_half_start = self.reverse_list(first_half_end.next)

        # Check whether or not there's a palindrome.
        result = True
        first_position = head
        second_position = second_half_start
        while result and second_position is not None:
            if first_position.val != second_position.val:
                result = False
            first_position = first_position.next
            second_position = second_position.next

        # Restore the list and return the result.
        first_half_end.next = self.reverse_list(second_half_start)
        return result    

    def end_of_first_half(self, head: ListNode) -> ListNode:
        fast = head
        slow = head
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
        return slow

    def reverse_list(self, head: ListNode) -> ListNode:
        previous = None
        current = head
        while current is not None:
            next_node = current.next
            current.next = previous
            previous = current
            current = next_node
        return previous
```

</details>
