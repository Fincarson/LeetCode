# 708. Insert into a Sorted Circular Linked List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)  
`Linked List`

**Problem Link:** [LeetCode 708 - Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)

## Problem

Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node.

### Example 1

```text
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.
```

### Example 2

```text
Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). We create a new single circular list and return the reference to that single node.
```

### Example 3

```text
Input: head = [1], insertVal = 0
Output: [1,0]
```

## Constraints

- The number of nodes in the list is in the range [0, 5 * 104].
- -106 <= Node.val, insertVal <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 708. Insert into a Sorted Circular Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two-Pointers Iteration | Java, Python |

## Approach 1: Two-Pointers Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public Node insert(Node head, int insertVal) {
    if (head == null) {
      Node newNode = new Node(insertVal, null);
      newNode.next = newNode;
      return newNode;
    }

    Node prev = head;
    Node curr = head.next;
    boolean toInsert = false;

    do {
      if (prev.val <= insertVal && insertVal <= curr.val) {
        // Case 1).
        toInsert = true;
      } else if (prev.val > curr.val) {
        // Case 2).
        if (insertVal >= prev.val || insertVal <= curr.val)
          toInsert = true;
      }

      if (toInsert) {
        prev.next = new Node(insertVal, curr);
        return head;
      }

      prev = curr;
      curr = curr.next;
    } while (prev != head);

    // Case 3).
    prev.next = new Node(insertVal, curr);
    return head;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':

        if head == None:
            newNode = Node(insertVal, None)
            newNode.next = newNode
            return newNode
 
        prev, curr = head, head.next
        toInsert = False

        while True:
            
            if prev.val <= insertVal <= curr.val:
                # Case #1.
                toInsert = True
            elif prev.val > curr.val:
                # Case #2. where we locate the tail element
                # 'prev' points to the tail, i.e. the largest element!
                if insertVal >= prev.val or insertVal <= curr.val:
                    toInsert = True

            if toInsert:
                prev.next = Node(insertVal, curr)
                # mission accomplished
                return head

            prev, curr = curr, curr.next
            # loop condition
            if prev == head:
                break
        # Case #3.
        # did not insert the node in the loop
        prev.next = Node(insertVal, curr)
        return head
```

</details>
