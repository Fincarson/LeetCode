# 3062. Winner of the Linked List Game

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/winner-of-the-linked-list-game/)  
`Linked List`

**Problem Link:** [LeetCode 3062 - Winner of the Linked List Game](https://leetcode.com/problems/winner-of-the-linked-list-game/)

## Problem

You are given the head of a linked list of even length containing integers.

Each odd-indexed node contains an odd integer and each even-indexed node contains an even integer.

We call each even-indexed node and its next node a pair, e.g., the nodes with indices 0 and 1 are a pair, the nodes with indices 2 and 3 are a pair, and so on.

For every pair, we compare the values of the nodes in the pair:

- If the odd-indexed node is higher, the "Odd" team gets a point.
- If the even-indexed node is higher, the "Even" team gets a point.

Return the name of the team with the higher points, if the points are equal, return "Tie".

### Example 1

### Example 2

### Example 3

## Constraints

- The number of nodes in the list is in the range [2, 100].
- The number of nodes in the list is even.
- 1 <= Node.val <= 100
- The value of each odd-indexed node is odd.
- The value of each even-indexed node is even.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3062. Winner of the Linked List Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Two Pointer | C++, Java, Python3 |
| Point Difference | C++, Java, Python3 |

## Approach: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string gameResult(ListNode* head) {
        ListNode* even = head;
        int evenPoints = 0;
        int oddPoints = 0;

        // Traverse through the linked list assigning points
        while (even != nullptr) {
            ListNode* odd = even->next;
            if (even->val > odd->val) {
                evenPoints += 1;
            } else {
                oddPoints += 1;
            }
            even = odd->next;
        }

        // Return the winning team
        if (oddPoints > evenPoints) {
            return "Odd";
        } else if (oddPoints < evenPoints) {
            return "Even";
        } else {
            return "Tie";
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String gameResult(ListNode head) {
        ListNode even = head;
        int evenPoints = 0;
        int oddPoints = 0;

        // Traverse through the linked list assigning points
        while (even != null) {
            ListNode odd = even.next;
            if (even.val > odd.val) {
                evenPoints += 1;
            } else {
                oddPoints += 1;
            }
            even = odd.next;
        }

        // Return the winning team
        if (oddPoints > evenPoints) {
            return "Odd";
        } else if (oddPoints < evenPoints) {
            return "Even";
        } else {
            return "Tie";
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        even = head
        even_points = 0
        odd_points = 0

        # Traverse through the linked list assigning points
        while even is not None:
            odd = even.next
            if even.val > odd.val:
                even_points += 1
            else:
                odd_points += 1
            even = odd.next
            
        # Return the winning team
        if odd_points > even_points:
            return "Odd"
        elif odd_points < even_points:
            return "Even"
        else:
            return "Tie"
```

</details>

<br>

## Approach 2: Point Difference

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string gameResult(ListNode* head) {
        ListNode* currentNode = head;
        int pointDifference = 0;

        while (currentNode != nullptr) {
            // Update the point difference based on the comparison of current and next nodes
            if (currentNode->next != nullptr) {
                pointDifference += (currentNode->val > currentNode->next->val) ? 1 : -1;
            }
            
            // Move two steps ahead in the linked list to the next even node
            currentNode = currentNode->next->next;
        }

        // Determine the winner based on the final score difference
        if (pointDifference < 0)
            return "Odd";
        else if (pointDifference > 0)
            return "Even";
        else
            return "Tie";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String gameResult(ListNode head) {
        ListNode currentNode = head;
        int pointDifference = 0;

        while (currentNode != null) {
            // Update the point difference based on the comparison of current and next nodes
            if (currentNode.next != null) {
                pointDifference += (currentNode.val > currentNode.next.val) ? 1 : -1;
            }
            
            // Move two steps ahead in the linked list to the next even node
            currentNode = currentNode.next.next;
        }

        // Determine the winner based on the final score difference
        if (pointDifference < 0)
            return "Odd";
        else if (pointDifference > 0)
            return "Even";
        else
            return "Tie";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        current_node, point_difference = head, 0

        while current_node:
            # Update the point difference based on the comparison of current and next nodes
            point_difference += (current_node.val > current_node.next.val) - (current_node.val < current_node.next.val)
            
            # Move two steps ahead in the linked list to the next even node
            current_node = current_node.next.next

        # Determine the winner based on the final score difference
        if point_difference < 0:
            return "Odd"
        elif point_difference > 0:
            return "Even"
        else:
            return "Tie"
```

</details>
