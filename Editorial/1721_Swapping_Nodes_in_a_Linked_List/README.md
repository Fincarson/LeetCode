# 1721. Swapping Nodes in a Linked List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)  
`Linked List` `Two Pointers`

**Problem Link:** [LeetCode 1721 - Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

## Problem

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

### Example 1

```text
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

### Example 2

```text
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

## Constraints

- The number of nodes in the list is n.
- 1 <= k <= n <= 105
- 0 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1721. Swapping Nodes in a Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Three Pass Approach | C++, Java |
| Single Pass Approach | C++, Java |

## Approach 1: Three Pass Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* currentNode = head;
        // find the length of linked list
        while (currentNode) {
            listLength++;
            currentNode = currentNode->next;
        }
        // set the front node at kth node
        ListNode* frontNode = head;
        for (int i = 1; i < k; i++) {
            frontNode = frontNode->next;
        }
        // set the end node at (listLength - k)th node
        ListNode* endNode = head;
        for (int i = 1; i <= listLength - k; i++) {
            endNode = endNode->next;
        }
        // swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int listLength = 0;
        ListNode currentNode = head;
        // find the length of linked list
        while (currentNode != null) {
            listLength++;
            currentNode = currentNode.next;
        }
        // set the front node at kth node
        ListNode frontNode = head;
        for (int i = 1; i < k; i++) {
            frontNode = frontNode.next;
        }
        //set the end node at (listLength - k)th node
        ListNode endNode = head;
        for (int i = 1; i <= listLength - k; i++) {
            endNode = endNode.next;
        }
        // swap the values of front node and end node
        int temp = frontNode.val;
        frontNode.val = endNode.val;
        endNode.val = temp;
        return head;
    }
}
```

</details>

<br>

## Approach 3: Single Pass Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* frontNode = nullptr;
        ListNode* endNode = nullptr;
        ListNode* currentNode = head;
        // set the front node and end node in single pass
        while (currentNode) {
            listLength++;
             if(endNode != NULL) {
                endNode = endNode->next;
             }
            // check if we have reached kth node
            if (listLength == k) {
                frontNode = currentNode;
                endNode = head;
            }          
            currentNode = currentNode->next;
        }
        // swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int listLength = 0;
        ListNode frontNode = null;
        ListNode endNode = null;
        ListNode currentNode = head;
        // set the front node and end node in single pass
        while (currentNode != null) {
            listLength++;
            if (endNode != null)
                endNode = endNode.next;
            // check if we have reached kth node
            if (listLength == k) {
                frontNode = currentNode;
                endNode = head;
            }
            currentNode = currentNode.next;
        }
        // swap the values of front node and end node
        int temp = frontNode.val;
        frontNode.val = endNode.val;
        endNode.val = temp;
        return head;
    }
}
```

</details>
