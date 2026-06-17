# 141. Linked List Cycle

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/linked-list-cycle/)  
`Hash Table` `Linked List` `Two Pointers`

**Problem Link:** [LeetCode 141 - Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

## Problem

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

### Example 1

```text
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

### Example 2

```text
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```

### Example 3

```text
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

## Constraints

- The number of the nodes in the list is in the range [0, 104].
- -105 <= Node.val <= 105
- pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Happy Number](https://leetcode.com/problems/happy-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 141. Linked List Cycle

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Floyd's Cycle Finding Algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct ListNode ListNode;
bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> nodesSeen;
        ListNode *current = head;
        while (current != nullptr) {
            if (nodesSeen.find(current) != nodesSeen.end()) {
                return true;
            }
            nodesSeen.insert(current);
            current = current->next;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasCycle(ListNode head) {
        HashSet<ListNode> nodesSeen = new HashSet<ListNode>();
        ListNode current = head;
        while (current != null) {
            if (nodesSeen.Contains(current)) {
                return true;
            }

            nodesSeen.Add(current);
            current = current.next;
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasCycle(head *ListNode) bool {
    nodesSeen := make(map[*ListNode]bool)
    current := head
    for current != nil {
        if nodesSeen[current] {
            return true
        }
        nodesSeen[current] = true
        current = current.Next
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> nodesSeen = new HashSet<>();
        ListNode current = head;
        while (current != null) {
            if (nodesSeen.contains(current)) {
                return true;
            }
            nodesSeen.add(current);
            current = current.next;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasCycle = function (head) {
    let nodesSeen = new Set();
    let current = head;
    while (current != null) {
        if (nodesSeen.has(current)) {
            return true;
        }
        nodesSeen.add(current);
        current = current.next;
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        nodes_seen = set()
        current = head
        while current is not None:
            if current in nodes_seen:
                return True
            nodes_seen.add(current)
            current = current.next
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasCycle(head: ListNode | null): boolean {
    let nodesSeen = new Set();
    let current = head;
    while (current != null) {
        if (nodesSeen.has(current)) {
            return true;
        }
        nodesSeen.add(current);
        current = current.next;
    }
    return false;
}
```

</details>

<br>

## Approach 2: Floyd's Cycle Finding Algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasCycle(ListNode head) {
        if (head == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }

            slow = slow.next;
            fast = fast.next.next;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }
    slow := head
    fast := head.Next
    for slow != fast {
        if fast == nil || fast.Next == nil {
            return false
        }
        slow = slow.Next
        fast = fast.Next.Next
    }
    return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasCycle = function (head) {
    if (head === null) {
        return false;
    }
    let slow = head;
    let fast = head.next;
    while (slow !== fast) {
        if (fast === null || fast.next === null) {
            return false;
        }
        slow = slow.next;
        fast = fast.next.next;
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        slow = head
        fast = head.next
        while slow != fast:
            if fast is None or fast.next is None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasCycle(head: ListNode | null): boolean {
    if (head === null) {
        return false;
    }
    let slow: ListNode | null = head;
    let fast: ListNode | null = head.next;
    while (slow !== fast) {
        if (fast === null || fast.next === null) {
            return false;
        }
        slow = slow.next;
        fast = fast.next.next;
    }
    return true;
}
```

</details>
