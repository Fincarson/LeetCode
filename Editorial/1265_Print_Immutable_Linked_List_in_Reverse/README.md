# 1265. Print Immutable Linked List in Reverse

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/print-immutable-linked-list-in-reverse/)  
`Linked List` `Two Pointers` `Stack` `Recursion`

**Problem Link:** [LeetCode 1265 - Print Immutable Linked List in Reverse](https://leetcode.com/problems/print-immutable-linked-list-in-reverse/)

## Problem

You are given an immutable linked list, print out all values of each node in reverse with the help of the following interface:

- ImmutableListNode: An interface of immutable linked list, you are given the head of the list.

You need to use the following functions to access the linked list (you can't access the ImmutableListNode directly):

- ImmutableListNode.printValue(): Print value of the current node.
- ImmutableListNode.getNext(): Return the next node.

The input is only given to initialize the linked list internally. You must solve this problem without modifying the linked list. In other words, you must operate the linked list using only the mentioned APIs.

### Example 1

```text
Input: head = [1,2,3,4]
Output: [4,3,2,1]
```

### Example 2

```text
Input: head = [0,-4,-1,3,-5]
Output: [-5,3,-1,-4,0]
```

### Example 3

```text
Input: head = [-2,0,6,4,4,-6]
Output: [-6,4,4,6,0,-2]
```

## Constraints

- The length of the linked list is between [1, 1000].
- The value of each node in the linked list is between [-1000, 1000].

Follow up:

Could you solve this problem in:

- Constant space complexity?
- Linear time complexity and less than linear space complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1265. Print Immutable Linked List in Reverse

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python3 |
| Using Stack | C++, Java, Python3 |
| Square Root Decomposition | C++, Java, Python3 |
| Divide and Conquer | C++, Java, Python3 |
| Constant Space | C++, Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head != NULL) {
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        if (head != null) {
            printLinkedListInReverse(head.getNext());
            head.printValue();
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        if head is not None:
            self.printLinkedListInReverse(head.getNext())
            head.printValue()
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
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode*> s;
        while (head) {
            s.push(head);
            head = head->getNext();
        }

        while (!s.empty()) {
            ImmutableListNode* node = s.top();
            s.pop();
            node->printValue();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        Stack<ImmutableListNode> stack = new Stack<>();
        while (head != null) {
            stack.push(head);
            head = head.getNext();
        }

        while (!stack.empty()) {
            ImmutableListNode node = stack.pop();
            node.printValue();
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        stack = []
        while head:
            stack.append(head)
            head = head.getNext()

        while stack:
            node = stack.pop()
            node.printValue()
```

</details>

<br>

## Approach 3: Square Root Decomposition

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void printLinkedListInReverseRecursively(ImmutableListNode* head, int size) {
        if (size && head) {
            printLinkedListInReverseRecursively(head->getNext(), size - 1);
            head->printValue();
        }
    }

    int getLinkedListSize(ImmutableListNode* head) {
        int size = 0;
        while (head) {
            size += 1;
            head = head->getNext();
        }
        return size;
    }

    void printLinkedListInReverse(ImmutableListNode* head) {
        int linkedListSize = getLinkedListSize(head);
        int blockSize = ceil(sqrt(linkedListSize));

        stack<ImmutableListNode*> blocks;
        ImmutableListNode* curr = head;
        for (int i = 0; i < linkedListSize; i++) {
            if (i % blockSize == 0) {
                blocks.push(curr);
            }
            curr = curr->getNext();
        }

        while (!blocks.empty()) {
            printLinkedListInReverseRecursively(blocks.top(), blockSize);
            blocks.pop();
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void printLinkedListInReverseRecursively(ImmutableListNode head, int size) {
        if (size > 0 && head != null) {
            printLinkedListInReverseRecursively(head.getNext(), size - 1);
            head.printValue();
        }
    }

    private int getLinkedListSize(ImmutableListNode head) {
        int size = 0;
        while (head != null) {
            size += 1;
            head = head.getNext();
        }
        return size;
    }

    public void printLinkedListInReverse(ImmutableListNode head) {
        int linkedListSize = getLinkedListSize(head);
        int blockSize = (int) Math.ceil(Math.sqrt(linkedListSize));

        Stack<ImmutableListNode> blocks = new Stack<>();
        ImmutableListNode curr = head;
        for (int i = 0; i < linkedListSize; i++) {
            if (i % blockSize == 0) {
                blocks.push(curr);
            }
            curr = curr.getNext();
        }

        while (!blocks.empty()) {
            printLinkedListInReverseRecursively(blocks.pop(), blockSize);
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def printLinkedListInReverseRecursively(self, head: 'ImmutableListNode', size: int) -> None:
        if size > 0 and head is not None:
            self.printLinkedListInReverseRecursively(head.getNext(), size - 1)
            head.printValue()

    def getLinkedListSize(self, head: 'ImmutableListNode') -> int:
        size = 0
        while head is not None:
            size += 1
            head = head.getNext()
        return size

    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        linked_list_size = self.getLinkedListSize(head)
        block_size = math.ceil(math.sqrt(linked_list_size))

        blocks = []
        curr = head
        for i in range(linked_list_size):
            if i % block_size == 0:
                blocks.append(curr)
            curr = curr.getNext()

        while blocks:
            self.printLinkedListInReverseRecursively(blocks.pop(), block_size)
```

</details>

<br>

## Approach 4: Divide and Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void helper(ImmutableListNode* start, ImmutableListNode* end) {
        if (start == NULL || start == end) {
            return;
        }
        if (start->getNext() == end) {
            start->printValue();
            return;
        }

        ImmutableListNode* slow = start;
        ImmutableListNode* fast = start;

        while (fast != end && fast->getNext() != end) {
            slow = slow->getNext();
            fast = fast->getNext()->getNext();
        }

        helper(slow, end);
        helper(start, slow);
    }

    void printLinkedListInReverse(ImmutableListNode* head) {
        helper(head, NULL);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private void helper(ImmutableListNode start, ImmutableListNode end) {
        if (start == null || start == end) {
            return;
        }
        if (start.getNext() == end) {
            start.printValue();
            return;
        }

        ImmutableListNode slow = start;
        ImmutableListNode fast = start;

        while (fast != end && fast.getNext() != end) {
            slow = slow.getNext();
            fast = fast.getNext().getNext();
        }

        helper(slow, end);
        helper(start, slow);
    }

    public void printLinkedListInReverse(ImmutableListNode head) {
        helper(head, null);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def helper(self, start: 'ImmutableListNode', end: 'ImmutableListNode') -> None:
        if start is None or start == end:
            return
        if start.getNext() == end:
            start.printValue()
            return

        slow = start
        fast = start

        while fast != end and fast.getNext() != end:
            slow = slow.getNext()
            fast = fast.getNext().getNext()

        self.helper(slow, end)
        self.helper(start, slow)

    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        self.helper(head, None)
```

</details>

<br>

## Approach 5: Constant Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode* curr;
        ImmutableListNode* end = NULL;

        while (head != end) {
            curr = head;
            while (curr->getNext() != end) {
                curr = curr->getNext();
            }
            curr->printValue();
            end = curr;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        ImmutableListNode curr;
        ImmutableListNode end = null;

        while (head != end) {
            curr = head;
            while (curr.getNext() != end) {
                curr = curr.getNext();
            }
            curr.printValue();
            end = curr;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        end = None

        while head != end:
            curr = head
            while curr.getNext() != end:
                curr = curr.getNext()
            curr.printValue()
            end = curr
```

</details>
