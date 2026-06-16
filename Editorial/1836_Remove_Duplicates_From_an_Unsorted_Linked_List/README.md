# 1836. Remove Duplicates From an Unsorted Linked List

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/)  
`Hash Table` `Linked List`

**Problem Link:** [LeetCode 1836 - Remove Duplicates From an Unsorted Linked List](https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/)

## Problem

Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that have any of those values.

Return the linked list after the deletions.

### Example 1

```text
Input: head = [1,2,3,2]
Output: [1,3]
Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3].
```

### Example 2

```text
Input: head = [2,1,1,2]
Output: []
Explanation: 2 and 1 both appear twice. All the elements should be deleted.
```

### Example 3

```text
Input: head = [3,2,2,1,3,2,4]
Output: [1,4]
Explanation: 3 appears twice and 2 appears three times. After deleting all 3's and 2's, we are left with [1,4].
```

## Constraints

- The number of nodes in the list is in the range [1, 105]
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1836. Remove Duplicates From an Unsorted Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Two Pass + Hash Map | C++, Java, Python3 |
| Recursive + Hash Map | C++, Java, Python3 |

## Approach 1: Iterative Two Pass + Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        unordered_map<int, int> frequency;
        ListNode *temp = head, *current = dummy->next, *prev = dummy;

        // Count occurrences of each value in the linked list.
        while (temp) {
            frequency[temp->val]++;
            temp = temp->next;
        }

        // Traverse the list and remove nodes with values that appear more than
        // once.
        while (current) {
            if (frequency[current->val] > 1) {
                // Delete current node from the list
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }
        return dummy->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        ListNode dummy = new ListNode(-1, head);
        Map<Integer, Integer> frequency = new HashMap<Integer, Integer>();
        ListNode temp = head, current = dummy.next, prev = dummy;

        // Count occurrences of each value in the linked list.
        while (temp != null) {
            frequency.put(temp.val, frequency.getOrDefault(temp.val, 0) + 1);
            temp = temp.next;
        }

        // Traverse the list and remove nodes with values that appear more than
        // once.
        while (current != null) {
            if (frequency.get(current.val) > 1) {
                // Delete current node from the list
                prev.next = current.next;
            } else {
                prev = current;
            }
            current = current.next;
        }
        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1, head)
        frequency = {}
        temp = head
        current = dummy.next
        prev = dummy

        # Count occurrences of each value in the linked list.
        while temp:
            if temp.val in frequency:
                frequency[temp.val] += 1
            else:
                frequency[temp.val] = 1
            temp = temp.next

        # Traverse the list and remove nodes with values that appear more than
        # once.
        while current:
            if frequency[current.val] > 1:
                # Delete current node from the list
                prev.next = current.next
            else:
                prev = current
            current = current.next
        return dummy.next
```

</details>

<br>

## Approach 2: Recursive + Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> frequency;
        countFrequencies(head, frequency);
        return deleteDuplicatesUnsortedHelper(head, frequency);
    }

private:
    // Count the frequency of each value in the list
    void countFrequencies(ListNode* head, unordered_map<int, int>& frequency) {
        ListNode* current = head;
        while (current != nullptr) {
            ++frequency[current->val];
            current = current->next;
        }
    }

    // Recursively delete duplicates based on the frequency map
    ListNode* deleteDuplicatesUnsortedHelper(
        ListNode* head, unordered_map<int, int>& frequency) {
        if (!head) {
            return nullptr;
        }

        // Recursive call for the next node
        ListNode* updatedNextNode =
            deleteDuplicatesUnsortedHelper(head->next, frequency);
        head->next = updatedNextNode;

        // If the current node is a duplicate, return the updated next node
        if (frequency[head->val] > 1) {
            return updatedNextNode;
        }

        // Otherwise, return the current node
        return head;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public ListNode deleteDuplicatesUnsorted(ListNode head) {
        HashMap<Integer, Integer> frequency = new HashMap<>();
        countFrequencies(head, frequency);
        return deleteDuplicatesUnsortedHelper(head, frequency);
    }

    // Count the frequency of each value in the list
    private void countFrequencies(
        ListNode head,
        HashMap<Integer, Integer> frequency
    ) {
        ListNode current = head;
        while (current != null) {
            frequency.put(
                current.val,
                frequency.getOrDefault(current.val, 0) + 1
            );
            current = current.next;
        }
    }

    // Recursively delete duplicates based on the frequency map
    private ListNode deleteDuplicatesUnsortedHelper(
        ListNode head,
        HashMap<Integer, Integer> frequency
    ) {
        if (head == null) {
            return null;
        }

        // Recursive call for the next node
        ListNode updatedNextNode = deleteDuplicatesUnsortedHelper(
            head.next,
            frequency
        );
        head.next = updatedNextNode;

        // If the current node is a duplicate, return the updated next node
        if (frequency.get(head.val) > 1) {
            return updatedNextNode;
        }

        // Otherwise, return the current node
        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        frequency = {}
        self.count_frequencies(head, frequency)
        return self.delete_duplicates_unsorted_helper(head, frequency)

    # Count the frequency of each value in the list
    def count_frequencies(self, head: ListNode, frequency: dict):
        current = head
        while current is not None:
            frequency[current.val] = frequency.get(current.val, 0) + 1
            current = current.next

    # Recursively delete duplicates based on the frequency map
    def delete_duplicates_unsorted_helper(
        self, head: ListNode, frequency: dict
    ) -> ListNode:
        if head is None:
            return None

        # Recursive call for the next node
        updated_next_node = self.delete_duplicates_unsorted_helper(
            head.next, frequency
        )
        head.next = updated_next_node

        # If the current node is a duplicate, return the updated next node
        if frequency[head.val] > 1:
            return updated_next_node

        # Otherwise, return the current node
        return head
```

</details>
