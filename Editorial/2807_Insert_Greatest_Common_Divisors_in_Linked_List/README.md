# 2807. Insert Greatest Common Divisors in Linked List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/)  
`Linked List` `Math` `Number Theory`

**Problem Link:** [LeetCode 2807 - Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/)

## Problem

Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

### Example 1

```text
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
```

### Example 2

```text
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
```

## Constraints

- The number of nodes in the list is in the range [1, 5000].
- 1 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2807. Insert Greatest Common Divisors in Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list contains only one node, return the head as no insertion
        // is needed
        if (head->next == nullptr) return head;

        // Initialize pointers to traverse the list
        ListNode* node1 = head;
        ListNode* node2 = head->next;

        // Traverse the linked list
        while (node2 != nullptr) {
            int gcdValue = calculateGCD(node1->val, node2->val);
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insert the GCD node between node1 and node2
            node1->next = gcdNode;
            gcdNode->next = node2;

            // Move to the next pair of nodes
            node1 = node2;
            node2 = node2->next;
        }

        return head;
    }

private:
    // Helper method to calculate the greatest common divisor using the
    // Euclidean algorithm
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        // If the list contains only one node, return the head as no insertion is needed
        if (head.next == null) return head;

        // Initialize pointers to traverse the list
        ListNode node1 = head;
        ListNode node2 = head.next;

        // Traverse the linked list
        while (node2 != null) {
            int gcdValue = calculateGCD(node1.val, node2.val);
            ListNode gcdNode = new ListNode(gcdValue);

            // Insert the GCD node between node1 and node2
            node1.next = gcdNode;
            gcdNode.next = node2;

            // Move to the next pair of nodes
            node1 = node2;
            node2 = node2.next;
        }

        return head;
    }

    // Helper method to calculate the greatest common divisor using the Euclidean algorithm
    private int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def insertGreatestCommonDivisors(
        self, head: Optional[ListNode]
    ) -> Optional[ListNode]:
        # Helper method to calculate the greatest common divisor using the Euclidean algorithm
        def _calculate_gcd(a, b):
            while b != 0:
                a, b = b, a % b
            return a

        # If the list contains only one node, return the head as no insertion is needed
        if not head.next:
            return head

        # Initialize pointers to traverse the list
        node1 = head
        node2 = head.next

        # Traverse the linked list
        while node2:
            gcd_value = _calculate_gcd(node1.val, node2.val)
            gcd_node = ListNode(gcd_value)

            # Insert the GCD node between node1 and node2
            node1.next = gcd_node
            gcd_node.next = node2

            # Move to the next pair of nodes
            node1 = node2
            node2 = node2.next

        return head
```

</details>
