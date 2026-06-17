# 1669. Merge In Between Linked Lists

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/merge-in-between-linked-lists/)  
`Linked List`

**Problem Link:** [LeetCode 1669 - Merge In Between Linked Lists](https://leetcode.com/problems/merge-in-between-linked-lists/)

## Problem

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:

Build the result list and return its head.

### Example 1

```text
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
```

### Example 2

```text
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
```

## Constraints

- 3 <= list1.length <= 104
- 1 <= a <= b < list1.length - 1
- 1 <= list2.length <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1669. Merge In Between Linked Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Merge Values in Array | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Merge Values in Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    vector<int> mergeArray;
    
    // Add list1 node values before `a` to the array.
    int index = 0;
    ListNode* current1 = list1;
    while (index < a) {
        mergeArray.push_back(current1->val);
        current1 = current1->next;
        index++;
    }

    // Add list2 node values to the array
    ListNode* current2 = list2;
    while (current2 != nullptr) {
        mergeArray.push_back(current2->val);
        current2 = current2->next;
    }

    // Find node b + 1
    while (index < b + 1) {
        current1 = current1->next;
        index++;
    }

    // Add list1 node values after `b` to the array.
    while (current1 != nullptr) {
        mergeArray.push_back(current1->val);
        current1 = current1->next;
    }

    // Build a linked list with the result by iterating over the array
    // in reverse order and inserting new nodes to the front of the list
    ListNode* resultList = nullptr;
    for (int i = mergeArray.size() - 1; i >= 0; i--) { 
        ListNode* newNode = new ListNode(mergeArray[i], resultList);
        resultList = newNode;
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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        List<Integer> mergeArray = new ArrayList<>();
        
        // Add list1 node values before `a` to the array.
        int index = 0;
        ListNode current1 = list1;
        while (index < a) {
            mergeArray.add(current1.val);
            current1 = current1.next;
            index++;
        }

        // Add list2 node values to the array
        ListNode current2 = list2;
        while (current2 != null) {
            mergeArray.add(current2.val);
            current2 = current2.next;
        }

        // Find node b + 1
        while (index < b + 1) {
            current1 = current1.next;
            index++;
        }

        // Add list1 node values after `b` to the array.
        while (current1 != null) {
            mergeArray.add(current1.val);
            current1 = current1.next;
        }

        // Build a linked list with the result by iterating over the array
        // in reverse order and inserting new nodes to the front of the list
        ListNode resultList = null;
        for (int i = mergeArray.size() - 1; i >= 0; i--) {
            ListNode newNode = new ListNode(mergeArray.get(i), resultList);
            resultList = newNode;
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
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        merge_array = []
        
        # Add list1 node values before `a` to the array.
        index = 0
        current1 = list1
        while index < a:
            merge_array.append(current1.val)
            current1 = current1.next
            index += 1

        # Add list2 node values to the array
        current2 = list2
        while current2 is not None:
            merge_array.append(current2.val)
            current2 = current2.next

        # Find node b + 1
        while index < b + 1:
            current1 = current1.next
            index += 1

        # Add list1 node values after `b` to the array.
        while current1 is not None:
            merge_array.append(current1.val)
            current1 = current1.next

        # Build a linked list with the result by iterating over the array
        # in reverse order and inserting new nodes to the front of the list
        result_list = None
        for i in range(len(merge_array)):
            new_node = ListNode(merge_array.pop(), result_list)
            result_list = new_node
        return result_list
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = nullptr;
        ListNode* end = list1;

        // Set start to node a - 1 and end to node b
        for (int index = 0; index < b; index++) {
            if (index == a - 1) {
                start = end;
            }
            end = end->next;
        }
        // Connect the start node to list2
        start->next = list2;

        // Find the tail of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        // Set the tail of list2 to end.next
        tail->next = end->next;
        end->next =  nullptr;

        return list1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode start = null;
        ListNode end = list1;

        // Set start to node a - 1 and end to node b
        for (int index = 0; index < b; index++) {
            if (index == a - 1) {
                start = end;
            }
            end = end.next;
        }
        // Connect the start node to list2
        start.next = list2;

        // Find the tail of list2
        while (list2.next != null) {
            list2 = list2.next;
        }
        // Set the tail of list2 to end.next
        list2.next = end.next;
        end.next = null;
        
        return list1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        start = ListNode()
        end = list1

        # Set start to node a - 1 and end to node b
        for index in range (b):
            if index == a - 1:
                start = end
            end = end.next

        # Connect the start node to list2
        start.next = list2

        # Find the tail of list2
        while (list2.next is not None):
            list2 = list2.next
        # Set the tail of list2 to end.next
        list2.next = end.next
        end.next = None
        
        return list1
```

</details>
