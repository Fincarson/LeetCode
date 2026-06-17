# 430. Flatten a Multilevel Doubly Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)  
`Linked List` `Depth-First Search` `Doubly-Linked List`

**Problem Link:** [LeetCode 430 - Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

## Problem

You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

### Example 1

```text
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:
```

### Example 2

```text
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:
```

### Example 3

```text
Input: head = []
Output: []
Explanation: There could be empty list in the input.
```

## Constraints

- The number of Nodes will not exceed 1000.
- 1 <= Node.val <= 105

How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

```text
1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
```

The serialization of each level is as follows:

```text
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
```

To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

```text
[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
```

Merging the serialization of each level and removing trailing nulls we obtain:

```text
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
```

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Correct a Binary Tree](https://leetcode.com/problems/correct-a-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 430. Flatten a Multilevel Doubly Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS by Recursion | Java, Python |
| DFS by Iteration | Java, Python |

## Approach 1: DFS by Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
  public Node flatten(Node head) {
    if (head == null) return head;
    // pseudo head to ensure the `prev` pointer is never none
    Node pseudoHead = new Node(0, null, head, null);

    flattenDFS(pseudoHead, head);

    // detach the pseudo head from the real head
    pseudoHead.next.prev = null;
    return pseudoHead.next;
  }
  /* return the tail of the flatten list */
  public Node flattenDFS(Node prev, Node curr) {
    if (curr == null) return prev;
    curr.prev = prev;
    prev.next = curr;

    // the curr.next would be tempered in the recursive function
    Node tempNext = curr.next;

    Node tail = flattenDFS(curr, curr.child);
    curr.child = null;

    return flattenDFS(tail, tempNext);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):

    def flatten(self, head):
        if not head:
            return head

        # pseudo head to ensure the `prev` pointer is never none
        pseudoHead = Node(None, None, head, None)
        self.flatten_dfs(pseudoHead, head)

        # detach the pseudo head from the real head
        pseudoHead.next.prev = None
        return pseudoHead.next


    def flatten_dfs(self, prev, curr):
        """ return the tail of the flatten list """
        if not curr:
            return prev

        curr.prev = prev
        prev.next = curr

        # the curr.next would be tempered in the recursive function
        tempNext = curr.next
        tail = self.flatten_dfs(curr, curr.child)
        curr.child = None
        return self.flatten_dfs(tail, tempNext)
```

</details>

<br>

## Approach 2: DFS by Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
  public Node flatten(Node head) {
    if (head == null) return head;

    Node pseudoHead = new Node(0, null, head, null);
    Node curr, prev = pseudoHead;

    Deque<Node> stack = new ArrayDeque<>();
    stack.push(head);

    while (!stack.isEmpty()) {
      curr = stack.pop();
      prev.next = curr;
      curr.prev = prev;

      if (curr.next != null) stack.push(curr.next);
      if (curr.child != null) {
        stack.push(curr.child);
        // don't forget to remove all child pointers.
        curr.child = null;
      }
      prev = curr;
    }
    // detach the pseudo node from the result
    pseudoHead.next.prev = null;
    return pseudoHead.next;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):
    def flatten(self, head):
        if not head:
            return

        pseudoHead = Node(0,None,head,None)
        prev = pseudoHead

        stack = []
        stack.append(head)

        while stack:
            curr = stack.pop()

            prev.next = curr
            curr.prev = prev

            if curr.next:
                stack.append(curr.next)
 
            if curr.child:
                stack.append(curr.child)
                # don't forget to remove all child pointers.
                curr.child = None

            prev = curr
        # detach the pseudo head node from the result.
        pseudoHead.next.prev = None
        return pseudoHead.next
```

</details>
