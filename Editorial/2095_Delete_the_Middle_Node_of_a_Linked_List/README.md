# 2095. Delete the Middle Node of a Linked List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 2095 - Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## Problem

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

- For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

### Example 1

```text
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.
```

### Example 2

```text
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
```

### Example 3

```text
Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
```

## Constraints

- The number of nodes in the list is in the range [1, 105].
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Reorder List](https://leetcode.com/problems/reorder-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2095. Delete the Middle Node of a Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| 2 Passes | C++, Java, JavaScript, Python |
| Fast and Slow Pointers | C++, Java, JavaScript, Python |

## Approach 1: 2 Passes

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: return None if there is only one node
        if (head -> next == nullptr)
            return nullptr;
        
        int count = 0;
        ListNode *p1 = head, *p2 = head;
        
        // First pass, count the number of nodes in the linked list using 'p1'.
        while (p1 != nullptr) {
            count++;
            p1 = p1 -> next;
        }
        
        // Get the index of the node to be deleted.
        int middleIndex = count / 2;
        
        // Second pass, let 'p2' move toward the predecessor of the middle node.
        for (int i = 0; i < middleIndex - 1; ++i)
            p2 = p2 -> next;
        
        // Delete the middle node and return 'head'.
        p2 -> next = p2 -> next -> next;
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        // Edge case: return None if there is only one node
        if (head.next == null)
            return null;
            
        int count = 0;
        ListNode p1 = head, p2 = head;
        
        // First pass, count the number of nodes in the linked list using 'p1'.
        while (p1 != null) {
            count += 1;
            p1 = p1.next;
        }
        
        // Get the index of the node to be deleted.
        int middleIndex = count / 2;
        
        // Second pass, let 'p2' move toward the predecessor of the middle node.
        for (int i = 0; i < middleIndex - 1; ++i)
            p2 = p2.next;
        
        // Delete the middle node and return 'head'.
        p2.next = p2.next.next;
        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deleteMiddle = function(head) {
    // Edge case: return None if there is only one node
    if (head.next == null)
        return null;
    
    let count = 0;
    let p1 = head, p2 = head;
    
    // First pass, count the number of nodes in the linked list using 'p1'.
    while (p1 != null) {
        count++;
        p1 = p1.next;
    }
    
    // Get the index of the node to be deleted.
    let middleIndex = Math.floor(count / 2);
    
    // Second pass, let 'p2' move toward the predecessor of the middle node.
    for (let i = 0; i < middleIndex - 1; ++i)
        p2 = p2.next;
    
    // Delete the middle node and return 'head'.
    p2.next = p2.next.next;
    return head;
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:  
        # Edge case: return None if there is only one node.
        if head.next == None:
            return None
        
        count = 0
        p1 = p2 = head
        
        # First pass, count the number of nodes in the linked list using 'p1'.
        while p1:
            count += 1
            p1 = p1.next
        
        # Get the index of the node to be deleted.
        middle_index = count // 2
        
        # Second pass, let 'p2' move toward the predecessor of the middle node.
        for _ in range(middle_index - 1):
            p2 = p2.next
        
        # Delete the middle node and return 'head'.
        p2.next = p2.next.next
        return head
```

</details>

<br>

## Approach 2: Fast and Slow Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: return nullptr if there is only one node.
        if (head -> next == nullptr)
            return nullptr;
        
        // Initialize two pointers, 'slow' and 'fast'.
        ListNode *slow = head, *fast = head -> next -> next;
        
        // Let 'fast' move forward by 2 nodes, 'slow' move forward by 1 node each step.
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // When 'fast' reaches the end, remove the next node of 'slow' and return 'head'.
        slow -> next = slow -> next -> next;
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        // Edge case: return nullptr if there is only one node.
        if (head.next == null)
            return null;
        
        // Initialize two pointers, 'slow' and 'fast'.
        ListNode slow = head, fast = head.next.next;
        
        // Let 'fast' move forward by 2 nodes, 'slow' move forward by 1 node each step.
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // When 'fast' reaches the end, remove the next node of 'slow' and return 'head'.
        slow.next = slow.next.next;
        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var deleteMiddle = function(head) {
    // Edge case: return nullptr if there is only one node.
    if (head.next == null)
        return null;
    
    // Initialize two pointers, 'slow' and 'fast'.
    let slow = head, fast = head.next.next;
    
    // Let 'fast' move forward by 2 nodes, 'slow' move forward by 1 node each step.
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    
    // When 'fast' reaches the end, remove the next node of 'slow' and return 'head'.
    slow.next = slow.next.next;
    return head;
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:   
        # Edge case: return None if there is only one node.
        if head.next == None:
            return None
        
        # Initialize two pointers, 'slow' and 'fast'.
        slow, fast = head, head.next.next
        
        # Let 'fast' move forward by 2 nodes, 'slow' move forward by 1 node each step.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # When 'fast' reaches the end, remove the next node of 'slow' and return 'head'.
        slow.next = slow.next.next
        
        # The job is done, return 'head'.
        return head
```

</details>
