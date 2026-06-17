# 2130. Maximum Twin Sum of a Linked List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)  
`Linked List` `Two Pointers` `Stack`

**Problem Link:** [LeetCode 2130 - Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

## Problem

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

- For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.

The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

### Example 1

```text
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.
```

### Example 2

```text
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
```

### Example 3

```text
Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
```

## Constraints

- The number of nodes in the list is an even integer in the range [2, 105].
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2130. Maximum Twin Sum of a Linked List

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using List Of Integers | C++, Java, Python |
| Using Stack | C++, Java, Python |
| Reverse Second Half In Place | C++, Java, Python |

## Approach 1: Using List Of Integers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* current = head;
        vector<int> values;

        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        int i = 0, j = values.size() - 1;
        int maximumSum = 0;
        while (i < j) {
            maximumSum = max(maximumSum, values[i] + values[j]);
            i++;
            j--;
        }

        return maximumSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int pairSum(ListNode head) {
        ListNode current = head;
        List<Integer> values = new ArrayList<>();

        while (current != null) {
            values.add(current.val);
            current = current.next;
        }

        int i = 0, j = values.size() - 1;
        int maximumSum = 0;
        while (i < j) {
            maximumSum = Math.max(maximumSum, values.get(i) + values.get(j));
            i++;
            j--;
        }

        return maximumSum;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def pairSum(self, head):
        current = head
        values = []

        while current:
            values.append(current.val)
            current = current.next
        
        i = 0
        j = len(values) - 1
        maximumSum = 0
        while(i < j):
            maximumSum = max(maximumSum, values[i] + values[j])
            i = i + 1
            j = j - 1
        
        return maximumSum
```

</details>

<br>

## Approach 2: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* current = head;
        stack<int> st;

        while (current) {
            st.push(current->val);
            current = current->next;
        }

        current = head;
        int size = st.size(), count = 1;
        int maximumSum = 0;
        while (count <= size / 2) {
            maximumSum = max(maximumSum, current->val + st.top());
            current = current->next;
            st.pop();
            count++;
        }

        return maximumSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int pairSum(ListNode head) {
        ListNode current = head;
        Stack<Integer> st = new Stack<Integer>();

        while (current != null) {
            st.push(current.val);
            current = current.next;
        }

        current = head;
        int size = st.size(), count = 1;
        int maximumSum = 0;
        while (count <= size / 2) {
            maximumSum = Math.max(maximumSum, current.val + st.peek());
            current = current.next;
            st.pop();
            count++;
        }

        return maximumSum;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def pairSum(self, head):
        current = head
        st = []
        maximumSum = 0

        while current:
            st.append(current.val)
            current = current.next

        current = head
        size = len(st)
        count = 1
        maximumSum = 0
        while count <= size/2:
            maximumSum = max(maximumSum, current.val + st.pop())
            current = current.next
            count = count + 1

        return maximumSum
```

</details>

<br>

## Approach 3: Reverse Second Half In Place

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Get middle of the linked list.
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse second half of the linked list.
        ListNode *nextNode, *prev = NULL;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maximumSum = 0;
        ListNode* start = head;
        while (prev) {
            maximumSum = max(maximumSum, start->val + prev->val);
            prev = prev->next;
            start = start->next;
        }

        return maximumSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        // Get middle of the linked list.
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }

        // Reverse second half of the linked list.
        ListNode nextNode, prev = null;
        while (slow != null) {
            nextNode = slow.next;
            slow.next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode start = head;
        int maximumSum = 0;
        while (prev != null) {
            maximumSum = Math.max(maximumSum, start.val + prev.val);
            prev = prev.next;
            start = start.next;
        }

        return maximumSum;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def pairSum(self, head):
        slow, fast = head, head
        maximumSum = 0

        # Get middle of the linked list.
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        # Reverse second half of the linked list.
        curr, prev = slow, None
        while curr:       
            curr.next, prev, curr = prev, curr, curr.next
        
        start = head
        while prev:
            maximumSum = max(maximumSum, start.val + prev.val)
            prev = prev.next
            start = start.next

        return maximumSum
```

</details>
