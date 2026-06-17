# 3217. Delete Nodes From Linked List Present in Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/)  
`Array` `Hash Table` `Linked List`

**Problem Link:** [LeetCode 3217 - Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/)

## Problem

You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- All elements in nums are unique.
- The number of nodes in the given list is in the range [1, 105].
- 1 <= Node.val <= 105
- The input is generated such that there is at least one node in the linked list that has a value not present in nums.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Remove Nodes From Linked List](https://leetcode.com/problems/remove-nodes-from-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3217. Delete Nodes From Linked List Present in Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Set | C++, Java, Python3 |

## Approach: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Build a set of values to remove for O(1) membership checks
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Step 2: Skip leading nodes that must be removed (do NOT delete here)
        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            head = head->next;
        }

        // Step 3: If all nodes were removed
        if (head == nullptr) {
            return nullptr;
        }

        // Step 4: Walk the list and unlink nodes whose values are in the set
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.count(current->next->val) > 0) {
                // Unlink the next node; do not delete it (harness will free)
                current->next = current->next->next;
            } else {
                current = current->next;
            }
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

    public ListNode modifiedList(int[] nums, ListNode head) {
        // Create a HashSet for efficient lookup of values in nums
        Set<Integer> valuesToRemove = new HashSet<>();
        for (int num : nums) {
            valuesToRemove.add(num);
        }

        // Handle the case where the head node needs to be removed
        while (head != null && valuesToRemove.contains(head.val)) {
            head = head.next;
        }

        // If the list is empty after removing head nodes, return null
        if (head == null) {
            return null;
        }

        // Iterate through the list, removing nodes with values in the set
        ListNode current = head;
        while (current.next != null) {
            if (valuesToRemove.contains(current.next.val)) {
                // Skip the next node by updating the pointer
                current.next = current.next.next;
            } else {
                // Move to the next node
                current = current.next;
            }
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def modifiedList(
        self, nums: List[int], head: Optional[ListNode]
    ) -> Optional[ListNode]:
        # Create a set for efficient lookup of values in nums
        values_to_remove = set(nums)

        # Handle the case where the head node needs to be removed
        while head and head.val in values_to_remove:
            head = head.next

        # If the list is empty after removing head nodes, return None
        if not head:
            return None

        # Iterate through the list, removing nodes with values in the set
        current = head
        while current.next:
            if current.next.val in values_to_remove:
                # Skip the next node by updating the pointer
                current.next = current.next.next
            else:
                # Move to the next node
                current = current.next

        return head
```

</details>
