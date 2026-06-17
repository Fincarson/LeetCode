# 725. Split Linked List in Parts

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/split-linked-list-in-parts/)  
`Linked List`

**Problem Link:** [LeetCode 725 - Split Linked List in Parts](https://leetcode.com/problems/split-linked-list-in-parts/)

## Problem

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

### Example 1

```text
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
```

### Example 2

```text
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
```

## Constraints

- The number of nodes in the list is in the range [0, 1000].
- 0 <= Node.val <= 1000
- 1 <= k <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Rotate List](https://leetcode.com/problems/rotate-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Split a Circular Linked List](https://leetcode.com/problems/split-a-circular-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 725. Split Linked List in Parts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Create New Parts | C++, Java, Python3 |
| Modify Linked List | C++, Java, Python3 |

## Approach 1: Create New Parts

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        int size = 0;
        ListNode* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }

        int splitSize = size / k;
        int numRemainingParts = size % k;

        current = head;
        for (int i = 0; i < k; i++) {
            ListNode newPart(0);
            ListNode* tail = &newPart;

            int currentSize = splitSize;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentSize++;
            }
            for (int j = 0; j < currentSize; j++) {
                tail->next = new ListNode(current->val);
                tail = tail->next;
                current = current->next;
            }
            ans[i] = newPart.next;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];

        // get total size of linked list
        int size = 0;
        ListNode current = head;
        while (current != null) {
            size++;
            current = current.next;
        }

        // minimum size for the k parts
        int splitSize = size / k;

        // Remaining nodes after splitting the k parts evenly.
        // These will be distributed to the first (size % k) nodes
        int numRemainingParts = size % k;

        current = head;
        for (int i = 0; i < k; i++) {
            // create the i-th part
            ListNode newPart = new ListNode(0);
            ListNode tail = newPart;

            int currentSize = splitSize;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentSize++;
            }
            int j = 0;
            while (j < currentSize) {
                tail.next = new ListNode(current.val);
                tail = tail.next;
                j++;
                current = current.next;
            }
            ans[i] = newPart.next;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitListToParts(
        self, head: Optional[ListNode], k: int
    ) -> List[Optional[ListNode]]:
        ans = [None] * k

        size = 0
        current = head
        while current is not None:
            size += 1
            current = current.next

        split_size = size // k
        num_remaining_parts = size % k

        current = head
        for i in range(k):
            new_part = ListNode(0)
            tail = new_part

            current_size = split_size
            if num_remaining_parts > 0:
                num_remaining_parts -= 1
                current_size += 1
            for j in range(current_size):
                tail.next = ListNode(current.val)
                tail = tail.next
                current = current.next
            ans[i] = new_part.next

        return ans
```

</details>

<br>

## Approach 2: Modify Linked List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);

        // get total size of linked list
        int size = 0;
        ListNode* current = head;
        while (current != nullptr) {
            size++;
            current = current->next;
        }

        // minimum size for the k parts
        int splitSize = size / k;

        // Remaining nodes after splitting the k parts evenly.
        // These will be distributed to the first (size % k) nodes
        int numRemainingParts = size % k;

        current = head;
        ListNode* prev = current;
        for (int i = 0; i < k; i++) {
            // create the i-th part
            ListNode* newPart = current;
            // calculate size of i-th part
            int currentSize = splitSize;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentSize++;
            }

            // traverse to end of new part
            int j = 0;
            while (j < currentSize) {
                prev = current;
                if (current != nullptr) {
                    current = current->next;
                }
                j++;
            }

            // cut off the rest of linked list
            if (prev != nullptr) {
                prev->next = nullptr;
            }

            ans[i] = newPart;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];

        // get total size of linked list
        int size = 0;
        ListNode current = head;
        while (current != null) {
            size++;
            current = current.next;
        }

        // minimum size for the k parts
        int splitSize = size / k;

        // Remaining nodes after splitting the k parts evenly.
        // These will be distributed to the first (size % k) nodes
        int numRemainingParts = size % k;

        current = head;
        ListNode prev = current;
        for (int i = 0; i < k; i++) {
            // create the i-th part
            ListNode newPart = current;
            // calculate size of i-th part
            int currentSize = splitSize;
            if (numRemainingParts > 0) {
                numRemainingParts--;
                currentSize++;
            }

            // traverse to end of new part
            int j = 0;
            while (j < currentSize) {
                prev = current;
                current = current.next;
                j++;
            }
            // cut off the rest of linked list
            if (prev != null) {
                prev.next = null;
            }

            ans[i] = newPart;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def splitListToParts(
        self, head: Optional[ListNode], k: int
    ) -> List[Optional[ListNode]]:
        ans = [None] * k

        # get total size of linked list
        size = 0
        current = head
        while current is not None:
            size += 1
            current = current.next

        # minimum size for the k parts
        split_size = size // k

        # Remaining nodes after splitting the k parts evenly.
        # These will be distributed to the first (size % k) nodes
        num_remaining_parts = size % k

        current = head
        prev = current
        for i in range(k):
            # create the i-th part
            new_part = current
            # calculate size of i-th part
            current_size = split_size
            if num_remaining_parts > 0:
                num_remaining_parts -= 1
                current_size += 1

            # traverse to end of new part
            j = 0
            while j < current_size:
                prev = current
                if current is not None:
                    current = current.next
                j += 1

            # cut off the rest of linked list
            if prev is not None:
                prev.next = None

            ans[i] = new_part

        return ans
```

</details>
