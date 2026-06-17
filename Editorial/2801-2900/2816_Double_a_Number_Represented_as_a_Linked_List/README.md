# 2816. Double a Number Represented as a Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/)  
`Linked List` `Math` `Stack`

**Problem Link:** [LeetCode 2816 - Double a Number Represented as a Linked List](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/)

## Problem

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

### Example 1

```text
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
```

### Example 2

```text
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
```

## Constraints

- The number of nodes in the list is in the range [1, 104]
- 0 <= Node.val <= 9
- The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Plus One Linked List](https://leetcode.com/problems/plus-one-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2816. Double a Number Represented as a Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reversing the List | C++, Java, Python3 |
| Using Stack | C++, Java, Python3 |
| Recursion | C++, Java, Python3 |
| Two Pointers | C++, Java, Python3 |
| Single Pointer | C++, Java, Python3 |

## Approach 1: Reversing the List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Reverse the linked list
        ListNode* reversedList = reverseList(head);
        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;

        // Traverse the reversed linked list
        while (current != nullptr) {
            // Calculate the new value for the current node
            int newValue = current->val * 2 + carry;
            // Update the current node's value
            current->val = newValue % 10;
            // Update carry for the next iteration
            if (newValue > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            // Move to the next node
            previous = current;
            current = current->next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode* result = reverseList(reversedList);

        return result;
    }

    // Method to reverse the linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr, *current = node, *nextNode;

        // Traverse the original linked list
        while (current != nullptr) {
            // Store the next node
            nextNode = current->next;
            // Reverse the link
            current->next = previous;
            // Move to the next nodes
            previous = current;
            current = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return previous;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode doubleIt(ListNode head) {
        // Reverse the linked list
        ListNode reversedList = reverseList(head);
        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode current = reversedList, previous = null;

        // Traverse the reversed linked list
        while (current != null) {
            // Calculate the new value for the current node
            int newValue = current.val * 2 + carry;
            // Update the current node's value
            current.val = newValue % 10;
            // Update carry for the next iteration
            if (newValue > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            // Move to the next node
            previous = current;
            current = current.next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0) {
            ListNode extraNode = new ListNode(carry);
            previous.next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode result = reverseList(reversedList);

        return result;
    }

    // Method to reverse the linked list
    public ListNode reverseList(ListNode node) {
        ListNode previous = null, current = node, nextNode;

        // Traverse the original linked list
        while (current != null) {
            // Store the next node
            nextNode = current.next;
            // Reverse the link
            current.next = previous;
            // Move to the next nodes
            previous = current;
            current = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return previous;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doubleIt(self, head: ListNode) -> ListNode:
        # Reverse the linked list
        reversed_list = self.reverse_list(head)
        # Initialize variables to track carry and previous node
        carry = 0
        current, previous = reversed_list, None

        # Traverse the reversed linked list
        while current:
            # Calculate the new value for the current node
            new_value = current.val * 2 + carry
            # Update the current node's value
            current.val = new_value % 10
            # Update carry for the next iteration
            carry = 1 if new_value > 9 else 0
            # Move to the next node
            previous, current = current, current.next

        # If there's a carry after the loop, add an extra node
        if carry:
            previous.next = ListNode(carry)

        # Reverse the list again to get the original order
        result = self.reverse_list(reversed_list)

        return result

    # Method to reverse the linked list
    def reverse_list(self, node: ListNode) -> ListNode:
        previous, current = None, node

        # Traverse the original linked list
        while current:
            # Store the next node
            next_node = current.next
            # Reverse the link
            current.next = previous
            # Move to the next nodes
            previous, current = current, next_node

        # Previous becomes the new head of the reversed list
        return previous
```

</details>

<br>

## Approach 2: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Initialize a stack to store the values of the linked list
        stack<int> values;
        int val = 0;

        // Traverse the linked list and push its values onto the stack
        while (head != nullptr) {
            values.push(head->val);
            head = head->next;
        }

        ListNode* newTail = nullptr;

        // Iterate over the stack of values and the carryover
        while (!values.empty() || val != 0) {
            // Create a new ListNode with value 0 and the previous tail as its next node
            newTail = new ListNode(0, newTail);
            
            // Calculate the new value for the current node
            // by doubling the last digit, adding carry, and getting the remainder
            if (!values.empty()) {
                val += values.top() * 2;
                values.pop();
            }
            newTail->val = val % 10;
            val /= 10;
        }

        // Return the tail of the new linked list
        return newTail;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode doubleIt(ListNode head) {
        // Initialize a stack to store the values of the linked list
        Stack<Integer> values = new Stack<>();
        int val = 0;

        // Traverse the linked list and push its values onto the stack
        while (head != null) {
            values.push(head.val);
            head = head.next;
        }

        ListNode newTail = null;

        // Iterate over the stack of values and the carryover
        while (!values.isEmpty() || val != 0) {
            // Create a new ListNode with value 0 and the previous tail as its next node
            newTail = new ListNode(0, newTail);

            // Calculate the new value for the current node
            // by doubling the last digit, adding carry, and getting the remainder
            if (!values.isEmpty()) {
                val += values.pop() * 2;
            }
            newTail.val = val % 10;
            val /= 10;
        }

        // Return the tail of the new linked list
        return newTail;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize an empty list to store the values of the linked list
        values = []
        val = 0

        # Traverse the linked list and push its values onto the list
        while head is not None:
            values.append(head.val)
            head = head.next

        new_tail = None

        # Iterate over the list of values and the carryover
        while values or val != 0:
            # Create a new ListNode with value 0 and the previous tail as its next node
            new_tail = ListNode(0, new_tail)

            # Calculate the new value for the current node
            # by doubling the last digit, adding carry, and getting the remainder
            if values:
                val += values.pop() * 2
            new_tail.val = val % 10
            val //= 10

        # Return the tail of the new linked list
        return new_tail
```

</details>

<br>

## Approach 3: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // To compute twice the value of each node's value and propagate carry
    int twiceOfVal(ListNode* head){
        // Base case: if head is null, return 0
        if (!head) return 0;
        
        // Double the value of current node and add the result of next nodes
        int doubledValue = head->val * 2 + twiceOfVal(head->next);
        
        // Update current node's value with the units digit of the result
        head->val = doubledValue % 10;
        
        // Return the carry (tens digit of the result)
        return doubledValue / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = twiceOfVal(head);
        
        // If there's a carry, insert a new node at the beginning with the carry value
        if (carry) 
            head = new ListNode(carry, head);
        
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    // To compute twice the value of each node's value and propagate carry
    public int twiceOfVal(ListNode head) {
        // Base case: if head is null, return 0
        if (head == null) return 0;
        
        // Double the value of current node and add the result of next nodes
        int doubledValue = head.val * 2 + twiceOfVal(head.next);
        
        // Update current node's value with the units digit of the result
        head.val = doubledValue % 10;
        
        // Return the carry (tens digit of the result)
        return doubledValue / 10;
    }
    
    public ListNode doubleIt(ListNode head) {
        int carry = twiceOfVal(head);
        
        // If there's a carry, insert a new node at the beginning with the carry value
        if (carry != 0) {
            head = new ListNode(carry, head);
        }
        
        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    # To compute twice the value of each node's value and propagate carry
    def twice_of_val(self, head: Optional[ListNode]) -> int:
        # Base case: if head is None, return 0
        if not head:
            return 0
        
        # Double the value of current node and add the result of next nodes
        doubled_value = head.val * 2 + self.twice_of_val(head.next)
        
        # Update current node's value with the units digit of the result
        head.val = doubled_value % 10
        
        # Return the carry (tens digit of the result)
        return doubled_value // 10
    
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        carry = self.twice_of_val(head)
        
        # If there's a carry, insert a new node at the beginning with the carry value
        if carry:
            head = ListNode(carry, head)
        
        # Return the head of the updated linked list
        return head
```

</details>

<br>

## Approach 4: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Traverse the linked list
        while (curr != nullptr) {
            int twiceOfVal = curr->val * 2;

            // If the doubled value is less than 10
            if (twiceOfVal < 10) {
                curr->val = twiceOfVal;
            } 

            // If doubled value is 10 or greater
            else if (prev != nullptr) { // other than first node
                // Update current node's value with units digit of the doubled value
                curr->val = twiceOfVal % 10;
                // Add the carry to the previous node's value
                prev->val = prev->val + 1;
            } 
            // If it's the first node and doubled value is 10 or greater
            else { // first node
                // Create a new node with carry as value and link it to the current node
                head = new ListNode(1, curr);
                // Update current node's value with units digit of the doubled value
                curr->val = twiceOfVal % 10;
            }

            // Update prev and curr pointers
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode doubleIt(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;

        // Traverse the linked list
        while (curr != null) {
            int twiceOfVal = curr.val * 2;

            // If the doubled value is less than 10
            if (twiceOfVal < 10) {
                curr.val = twiceOfVal;
            } 
            // If doubled value is 10 or greater
            else if (prev != null) { // other than first node
                // Update current node's value with units digit of the doubled value
                curr.val = twiceOfVal % 10;
                // Add the carry to the previous node's value
                prev.val = prev.val + 1;
            } 
            // If it's the first node and doubled value is 10 or greater
            else { // first node
                // Create a new node with carry as value and link it to the current node
                head = new ListNode(1, curr);
                // Update current node's value with units digit of the doubled value
                curr.val = twiceOfVal % 10;
            }

            // Update prev and curr pointers
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doubleIt(self, head: ListNode) -> ListNode:
        curr = head
        prev = None

        # Traverse the linked list
        while curr:
            twice_of_val = curr.val * 2

            # If the doubled value is less than 10
            if twice_of_val < 10:
                curr.val = twice_of_val
            # If doubled value is 10 or greater
            elif prev:  # other than first node
                # Update current node's value with units digit of the doubled value
                curr.val = twice_of_val % 10
                # Add the carry to the previous node's value
                prev.val += 1
            else:  # first node
                # Create a new node with carry as value and link it to the current node
                head = ListNode(1, curr)
                # Update current node's value with units digit of the doubled value
                curr.val = twice_of_val % 10

            # Update prev and curr pointers
            prev = curr
            curr = curr.next

        return head
```

</details>

<br>

## Approach 5: Single Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // If the value of the head node is greater than 4, insert a new node at the beginning
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        
        // Traverse the linked list
        for (ListNode* node = head; node != nullptr; node = node->next) {
            // Double the value of the current node and update it with the units digit
            node->val = (node->val * 2) % 10;
            
            // If the current node has a next node 
            // and the next node's value is greater than 4,
            // increment the current node's value to handle carry
            if (node->next != nullptr && node->next->val > 4) {
                node->val++;
            }
        }
        
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode doubleIt(ListNode head) {
        // If the value of the head node is greater than 4, 
        // insert a new node at the beginning
        if (head.val > 4) {
            head = new ListNode(0, head);
        }
        
        // Traverse the linked list
        for (ListNode node = head; node != null; node = node.next) {
            // Double the value of the current node 
            // and update it with the units digit
            node.val = (node.val * 2) % 10;
            
            // If the current node has a next node 
            // and the next node's value is greater than 4,
            // increment the current node's value to handle carry
            if (node.next != null && node.next.val > 4) {
                node.val++;
            }
        }
        
        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def doubleIt(self, head: ListNode) -> ListNode:
        # If the value of the head node is greater than 4, 
        # insert a new node at the beginning
        if head.val > 4:
            head = ListNode(0, head)
        
        # Traverse the linked list
        node = head
        while node:
            # Double the value of the current node 
            # and update it with the units digit
            node.val = (node.val * 2) % 10
            
            # If the current node has a next node 
            # and the next node's value is greater than 4,
            # increment the current node's value to handle carry
            if node.next and node.next.val > 4:
                node.val += 1
            
            # Move to the next node
            node = node.next
        
        return head
```

</details>
