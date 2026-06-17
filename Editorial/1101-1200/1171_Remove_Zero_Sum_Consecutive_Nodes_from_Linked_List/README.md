# 1171. Remove Zero Sum Consecutive Nodes from Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)  
`Hash Table` `Linked List`

**Problem Link:** [LeetCode 1171 - Remove Zero Sum Consecutive Nodes from Linked List](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

## Problem

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of ListNode objects.)

### Example 1

```text
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```

### Example 2

```text
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
```

### Example 3

```text
Input: head = [1,2,3,-3,-2]
Output: [1]
```

## Constraints

- The given linked list will contain between 1 and 1000 nodes.
- Each node in the linked list has -1000 <= node.val <= 1000.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Delete N Nodes After M Nodes of a Linked List](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1171. Remove Zero Sum Consecutive Nodes from Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum for Each Consecutive Sequence | C++, Java, Python3 |
| Prefix Sum Hash Table | C++, Java, Python3 |

## Approach 1: Prefix Sum for Each Consecutive Sequence

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* start = front;

        while (start != nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while (end != nullptr) {
                // Add end's value to the prefix sum
                prefixSum += end->val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    start->next = end->next;
                }
                end = end->next;
            }

            start = start->next;
        }
        return front->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode front = new ListNode(0, head);
        ListNode start = front;

        while (start != null) {
            int prefixSum = 0;
            ListNode end = start.next;

            while (end != null) {
                // Add end's value to the prefix sum
                prefixSum += end.val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    start.next = end.next;
                }
                end = end.next;
            }

            start = start.next;
        }
        return front.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        start = front

        while start is not None:
            prefix_sum = 0
            end = start.next

            while end is not None:
                # Add end's value to the prefix sum
                prefix_sum += end.val
                # Delete zero sum consecutive sequence 
                # by setting node before sequence to node after
                if prefix_sum == 0:
                    start.next = end.next
                end = end.next

            start = start.next

        return front.next
```

</details>

<br>

## Approach 2: Prefix Sum Hash Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        prefixSumToNode[0] = front;

        // Calculate the prefix sum for each node and add to the hashmap
        // Duplicate prefix sum values will be replaced
        while (current != nullptr) {
            prefixSum += current->val;
            prefixSumToNode[prefixSum] = current;
            current = current->next;
        }

        // Reset prefix sum and current
        prefixSum = 0;
        current = front;

        // Delete zero sum consecutive sequences 
        // by setting node before sequence to node after
        while (current != nullptr) {
            prefixSum += current->val;
            current->next = prefixSumToNode[prefixSum]->next;
            current = current->next;
        }
        return front->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode front = new ListNode(0, head);
        ListNode current = front;
        int prefixSum = 0;
        Map<Integer, ListNode> prefixSumToNode = new HashMap<>();
        prefixSumToNode.put(0, front);

        // Calculate the prefix sum for each node and add to the hashmap
        // Duplicate prefix sum values will be replaced
        while (current != null) {
            prefixSum += current.val;
            prefixSumToNode.put(prefixSum, current);
            current = current.next;
        }

        // Reset prefix sum and current
        prefixSum = 0;
        current = front;

        // Delete zero sum consecutive sequences 
        // by setting node before sequence to node after
        while (current != null) {
            prefixSum += current.val;
            current.next = prefixSumToNode.get(prefixSum).next;
            current = current.next;
        }
        return front.next; 
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        current = front
        prefix_sum = 0
        prefix_sum_to_node = {0: front}

        # Calculate the prefix sum for each node and add to the hashmap
        # Duplicate prefix sum values will be replaced
        while current is not None:
            prefix_sum += current.val
            prefix_sum_to_node[prefix_sum] = current
            current = current.next

        # Reset prefix sum and current
        prefix_sum = 0
        current = front

        # Delete zero sum consecutive sequences 
        # by setting node before sequence to node after
        while current is not None:
            prefix_sum += current.val
            current.next = prefix_sum_to_node[prefix_sum].next
            current = current.next

        return front.next
```

</details>
