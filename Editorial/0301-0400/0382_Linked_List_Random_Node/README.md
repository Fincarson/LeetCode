# 382. Linked List Random Node

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/linked-list-random-node/)  
`Linked List` `Math` `Reservoir Sampling` `Randomized`

**Problem Link:** [LeetCode 382 - Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

## Problem

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

- Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
- int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

### Example 1

```text
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
```

## Constraints

- The number of nodes in the linked list will be in the range [1, 104].
- -104 <= Node.val <= 104
- At most 104 calls will be made to getRandom.

Follow up:

- What if the linked list is extremely large and its length is unknown to you?
- Could you solve this efficiently without using extra space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Random Pick Index](https://leetcode.com/problems/random-pick-index/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 382. Linked List Random Node

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Fixed-Range Sampling | Java, Python3 |
| Reservoir Sampling | Java, Python3 |

## Approach 1: Fixed-Range Sampling

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private ArrayList<Integer> range = new ArrayList<>();

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        while (head != null) {
            this.range.add(head.val);
            head = head.next;
        }
    }

    /** Returns a random node's value. */
    public int getRandom() {
        int pick = (int)(Math.random() * this.range.size());
        return this.range.get(pick);
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.range = []
        while head:
            self.range.append(head.val)
            head = head.next

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        pick = int(random.random() * len(self.range))
        return self.range[pick]
```

</details>

<br>

## Approach 2: Reservoir Sampling

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private ListNode head;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
    }

    /** Returns a random node's value. */
    public int getRandom() {
        int scope = 1, chosenValue = 0;
        ListNode curr = this.head;
        while (curr != null) {
            // decide whether to include the element in reservoir
            if (Math.random() < 1.0 / scope)
                chosenValue = curr.val;
            // move on to the next node
            scope += 1;
            curr = curr.next;
        }
        return chosenValue;
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        scope = 1
        chosen_value = 0
        curr = self.head

        while curr:
            # decide whether to include the element in reservoir
            if random.random() < 1 / scope:
                chosen_value = curr.val
            # move on to the next node
            curr = curr.next
            scope += 1
        return chosen_value
```

</details>
