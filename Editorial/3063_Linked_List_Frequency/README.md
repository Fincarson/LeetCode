# 3063. Linked List Frequency

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/linked-list-frequency/)  
`Hash Table` `Linked List` `Counting`

**Problem Link:** [LeetCode 3063 - Linked List Frequency](https://leetcode.com/problems/linked-list-frequency/)

## Problem

Given the head of a linked list containing k distinct elements, return the head to a linked list of length k containing the frequency of each distinct element in the given linked list in any order.

### Example 1

### Example 2

### Example 3

## Constraints

- The number of nodes in the list is in the range [1, 105].
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3063. Linked List Frequency

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Frequencies | C++, Java, Python3 |
| Hash Table | C++, Java, Python3 |

## Approach 1: Count Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        const int maxValue = 100000; // Maximum element value 
        vector<int> frequencies(maxValue, 0);
        ListNode* current = head;

        // Find the frequency of each element
        while (current != nullptr) {
            frequencies[current->val - 1]++;
            current = current->next;
        }

        ListNode* freqHead = new ListNode(0);
        current = freqHead;

        // Create a linked list of the frequencies of the elements
        for (int i = 0; i < maxValue; i++) {
            if (frequencies[i] > 0) {
                current->next = new ListNode(frequencies[i]);
                current = current->next;
            }
        }
        return freqHead->next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode frequenciesOfElements(ListNode head) {
        int maxValue = 100000; // Maximum element value 
        int[] frequencies = new int[maxValue];
        ListNode current = head;

        // Find the frequency of each element
        while (current != null) {
            frequencies[current.val - 1]++;
            current = current.next;
        }

        ListNode freqHead = new ListNode(0);
        current = freqHead;

        // Create a linked list of the frequencies of the elements
        for (int i = 0; i < maxValue; i++) {
            if (frequencies[i] > 0) {
                current.next = new ListNode(frequencies[i]);
                current = current.next;
            }
        }
        return freqHead.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        max_value = 100000 # Maximum element value 
        frequencies = [0] * max_value
        current = head

        # Find the frequency of each element
        while current is not None:
            frequencies[current.val - 1] += 1
            current = current.next

        freq_head = ListNode(0)
        current = freq_head

        # Create a linked list of the frequencies of the elements
        for i in range(0, max_value):
            if frequencies[i] > 0:
                current.next = ListNode(frequencies[i])
                current = current.next

        return freq_head.next
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, ListNode*> frequencies;
        ListNode* current = head;
        ListNode* freqHead = nullptr;

        // Process the linked list, storing
        // frequency ListNodes in the hashtable 
        while (current != nullptr) {
            // Increment frequency of existing element
            if (frequencies.find(current->val) != frequencies.end()) {
                ListNode* frequencyNode = frequencies[current->val];
                frequencyNode->val += 1;
            // New element, create hashtable entry with frequency node
            } else {
                ListNode* newFrequencyNode = new ListNode(1, freqHead);
                frequencies[current->val] = newFrequencyNode;
                freqHead = newFrequencyNode;
            }
            current = current->next;
        }
        return freqHead;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode frequenciesOfElements(ListNode head) {
        Map<Integer, ListNode> frequencies = new HashMap<>();
        ListNode current = head;
        ListNode freqHead = null;

        // Process the linked list, storing
        // frequency ListNodes in the hashtable 
        while (current != null) {
            // Increment frequency of existing element
            if (frequencies.containsKey(current.val)) {
                ListNode frequencyNode = frequencies.get(current.val);
                frequencyNode.val += 1;
            // New element, create hashtable entry with frequency node
            } else {
                ListNode newFrequencyNode = new ListNode(1, freqHead);
                frequencies.put(current.val, newFrequencyNode);
                freqHead = newFrequencyNode;
            }
            current = current.next;
        }
        return freqHead;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        frequencies = {}
        current = head
        freq_head = None

        # Process the linked list, storing
        # frequency ListNodes in the hashtable 
        while current is not None:
            # Existing element, increment frequency 
            if current.val in frequencies:
                frequency_node = frequencies[current.val]
                frequency_node.val += 1

            # New element, create hashtable entry with frequency node
            else:
                new_frequency_node = ListNode(1, freq_head)
                frequencies[current.val] = new_frequency_node
                freq_head = new_frequency_node
            current = current.next

        return freq_head
```

</details>
