# 2487. Remove Nodes From Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-nodes-from-linked-list/)  
`Linked List` `Stack` `Recursion` `Monotonic Stack`

**Problem Link:** [LeetCode 2487 - Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/)

## Problem

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

### Example 1

```text
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
```

### Example 2

```text
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
```

## Constraints

- The number of the nodes in the given list is in the range [1, 105].
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2487. Remove Nodes From Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Recursion | C++, Java, Python3 |
| Reverse Twice | C++, Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;

        // Add nodes to the stack
        while (current != nullptr) {
            stack.push(current);
            current = current->next;
        }

        current = stack.top();
        stack.pop();
        int maximum = current->val;
        ListNode* resultList = new ListNode(maximum);

        // Remove nodes from the stack and add to result
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            // Current should not be added to the result
            if (current->val < maximum) {
                continue;
            }
            // Add new node with current's value to front of the result
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maximum = current->val;
            }
        }

        return resultList;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode removeNodes(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode current = head;

        // Add nodes to the stack
        while (current != null) {
            stack.push(current);
            current = current.next;
        }

        current = stack.pop();
        int maximum = current.val;
        ListNode resultList = new ListNode(maximum);

        // Remove nodes from the stack and add to result
        while (!stack.isEmpty()) {
            current = stack.pop();
            // Current should not be added to the result
            if (current.val < maximum) {
                continue;
            }
            // Add new node with current's value to front of the result
            else {
                ListNode newNode = new ListNode(current.val);
                newNode.next = resultList;
                resultList = newNode;
                maximum = current.val;
            }
        }

        return resultList;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        stack = []
        current = head

        # Add nodes to the stack
        while current:
            stack.append(current)
            current = current.next

        current = stack.pop()
        maximum = current.val
        result_list = ListNode(maximum)

        # Remove nodes from the stack and add to result
        while stack:
            current = stack.pop()
            # Current should not be added to the result
            if current.val < maximum:
                continue
            # Add new node with current's value to front of the result
            else:
                new_node = ListNode(current.val)
                new_node.next = result_list
                result_list = new_node
                maximum = current.val

        return result_list
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Base case, reached end of the list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursive call
        ListNode* nextNode = removeNodes(head->next);

        // If the next node has greater value than head delete the head
        // Return next node, which removes the current head and makes next the new head
        if (head->val < nextNode->val) {
            delete head;
            return nextNode;
        }

        // Keep the head
        head->next = nextNode;
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
 class Solution {   
    public ListNode removeNodes(ListNode head) {
        // Base case, reached end of the list
        if (head == null || head.next == null) {
            return head;
        }

        // Recursive call
        ListNode nextNode = removeNodes(head.next);

        // If the next node has greater value than head, delete the head
        // Return next node, which removes the current head and makes next the new head
        if (head.val < nextNode.val) {
            return nextNode;
        }

        // Keep the head
        head.next = nextNode;
        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case, reached end of the list
        if head is None or head.next is None:
            return head

        # Recursive call
        next_node = self.removeNodes(head.next)
        
        # If the next node has greater value than head, delete the head
        # Return next node, which removes the current head and 
        # makes next the new head
        if head.val < next_node.val:
            return next_node
     
        # Keep the head
        head.next = next_node
        return head
```

</details>

<br>

## Approach 3: Reverse Twice

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextTemp = nullptr;

        // Set each node's next pointer to the previous node
        while (current != nullptr) {
            nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        // Reverse the original linked list
        head = reverseList(head);

        int maximum = 0;
        ListNode* prev = nullptr;
        ListNode* current = head;

        // Traverse the list deleting nodes
        while (current != nullptr) {
            maximum = max(maximum, current->val);

            // Delete nodes that are smaller than maximum
            if (current->val < maximum) {
                // Delete current by skipping
                prev->next = current->next;
                ListNode* deleted = current;
                current = current->next;
                deleted->next = nullptr;
            }

            // Current does not need to be deleted
            else {
                prev = current;
                current = current->next;
            }
        }
        
        // Reverse and return the modified linked list
        return reverseList(head);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        ListNode nextTemp = null;

        // Set each node's next pointer to the previous node
        while (current != null) {
            nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }

    public ListNode removeNodes(ListNode head) {
        // Reverse the original linked list
        head = reverseList(head);

        int maximum = 0;
        ListNode prev = null;
        ListNode current = head;

        // Traverse the list deleting nodes
        while (current != null) {
            maximum = Math.max(maximum, current.val);

            // Delete nodes that are smaller than maximum
            if (current.val < maximum) {
                // Delete current by skipping
                prev.next = current.next;
                ListNode deleted = current;
                current = current.next;
                deleted.next = null;
            }

            // Current does not need to be deleted
            else {
                prev = current;
                current = current.next;
            }
        }
        
        // Reverse and return the modified linked list
        return reverseList(head);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverse_list(self, head):
        prev = None
        current = head
        next_temp = None

        # Set each node's next pointer to the previous node
        while current:
            next_temp = current.next
            current.next = prev
            prev = current
            current = next_temp
        
        return prev

    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Reverse the original linked list
        head = self.reverse_list(head)

        maximum = 0
        prev = None
        current = head

        # Traverse the list deleting nodes
        while current:
            maximum = max(maximum, current.val)

            # Delete nodes that are smaller than maximum
            if current.val < maximum:
                # Delete current by skipping
                prev.next = current.next
                deleted = current
                current = current.next
                deleted.next = None

            # Current does not need to be deleted
            else:
                prev = current
                current = current.next
        
        # Reverse and return the modified linked list
        return self.reverse_list(head)
```

</details>
