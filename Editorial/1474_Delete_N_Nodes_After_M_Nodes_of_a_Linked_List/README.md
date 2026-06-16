# 1474. Delete N Nodes After M Nodes of a Linked List

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)  
`Linked List`

**Problem Link:** [LeetCode 1474 - Delete N Nodes After M Nodes of a Linked List](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)

## Problem

You are given the head of a linked list and two integers m and n.

Traverse the linked list and remove some nodes in the following way:

- Start with the head as the current node.
- Keep the first m nodes starting with the current node.
- Remove the next n nodes
- Keep repeating steps 2 and 3 until you reach the end of the list.

Return the head of the modified list after removing the mentioned nodes.

### Example 1

```text
Input: head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
Output: [1,2,6,7,11,12]
Explanation: Keep the first (m = 2) nodes starting from the head of the linked List  (1 ->2) show in black nodes.
Delete the next (n = 3) nodes (3 -> 4 -> 5) show in read nodes.
Continue with the same procedure until reaching the tail of the Linked List.
Head of the linked list after removing nodes is returned.
```

### Example 2

```text
Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
Output: [1,5,9]
Explanation: Head of linked list after removing nodes is returned.
```

## Constraints

- The number of nodes in the list is in the range [1, 104].
- 1 <= Node.val <= 106
- 1 <= m, n <= 1000

Follow up: Could you solve this problem by modifying the list in-place?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Remove Zero Sum Consecutive Nodes from Linked List](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1474. Delete N Nodes After M Nodes of a Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Traverse Linked List and Delete In Place | C++, Java |

## Approach 1: Traverse Linked List and Delete In Place

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* currentNode = head;
        ListNode* lastMNode = head;
        while (currentNode != nullptr) {
            // initialize mCount to m and nCount to n
            int mCount = m, nCount = n;
            // traverse m nodes
            while (currentNode != nullptr && mCount != 0) {
                lastMNode = currentNode;
                currentNode = currentNode->next;
                mCount--;
            }
            // traverse n nodes
            while (currentNode != nullptr && nCount != 0) {
                currentNode = currentNode->next;
                nCount--;
            }
            // delete n nodes
            lastMNode->next = currentNode;
        }
        return head;    
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode deleteNodes(ListNode head, int m, int n) {
        ListNode currentNode = head;
        ListNode lastMNode = head;
        while (currentNode != null) {
            // initialize mCount to m and nCount to n
            int mCount = m, nCount = n;
            // traverse m nodes
            while (currentNode != null && mCount != 0) {
                lastMNode = currentNode;
                currentNode = currentNode.next;
                mCount--;
            }
            // traverse n nodes
            while (currentNode != null && nCount != 0) {
                currentNode = currentNode.next;
                nCount--;
            }
            // delete n nodes
            lastMNode.next = currentNode;
        }
        return head;
    }
}
```

</details>
