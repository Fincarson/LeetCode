# 160. Intersection of Two Linked Lists

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
`Hash Table` `Linked List` `Two Pointers`

**Problem Link:** [LeetCode 160 - Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

## Problem

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

- intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
- listA - The first linked list.
- listB - The second linked list.
- skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
- skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

### Example 1

```text
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
```

### Example 2

```text
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

### Example 3

```text
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
```

## Constraints

- The number of nodes of listA is in the m.
- The number of nodes of listB is in the n.
- 1 <= m, n <= 3 * 104
- 1 <= Node.val <= 105
- 0 <= skipA <= m
- 0 <= skipB <= n
- intersectVal is 0 if listA and listB do not intersect.
- intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 160. Intersection of Two Linked Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Hash Table | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    while (headA != NULL) {
        struct ListNode* pB = headB;
        while (pB != NULL) {
            if (headA == pB) return headA;
            pB = pB->next;
        }
        headA = headA->next;
    }
    return NULL;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            ListNode *pB = headB;
            while (pB != nullptr) {
                if (headA == pB) return headA;
                pB = pB->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        while (headA != null) {
            ListNode pB = headB;
            while (pB != null) {
                if (headA == pB) return headA;
                pB = pB.next;
            }

            headA = headA.next;
        }

        return null;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    curA := headA
    for curA != nil {
        curB := headB
        for curB != nil {
            if curA == curB {
                return curA
            }
            curB = curB.Next
        }
        curA = curA.Next
    }
    return nil
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        while (headA != null) {
            ListNode pB = headB;
            while (pB != null) {
                if (headA == pB) return headA;
                pB = pB.next;
            }
            headA = headA.next;
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function getIntersectionNode(headA, headB) {
    while (headA !== null) {
        let pB = headB;
        while (pB !== null) {
            if (headA === pB) return headA;
            pB = pB.next;
        }
        headA = headA.next;
    }
    return null;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        while headA is not None:
            pB = headB
            while pB is not None:
                if headA == pB:
                    return headA
                pB = pB.next
            headA = headA.next

        return None
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getIntersectionNode(
    headA: ListNode | null,
    headB: ListNode | null,
): ListNode | null {
    while (headA !== null) {
        let pB: ListNode | null = headB;
        while (pB !== null) {
            if (headA === pB) return headA;
            pB = pB.next;
        }
        headA = headA.next;
    }
    return null;
}
```

</details>

<br>

## Approach 2: Hash Table

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    int val;
    struct ListNode* next;
    UT_hash_handle hh;
} HashTable;

struct ListNode* getIntersectionNode(struct ListNode* headA,
                                     struct ListNode* headB) {
    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    HashTable* setForB = NULL;

    // Creating HashSet for all nodes of list B
    while (tempB != NULL) {
        HashTable* s = (HashTable*)malloc(sizeof(HashTable));
        s->next = tempB;
        HASH_ADD_PTR(setForB, next, s);
        tempB = tempB->next;
    }

    // Iterate through list A. If we find any node of list A in the HashSet of
    // B, then return the node
    while (tempA != NULL) {
        HashTable* s;
        HASH_FIND_PTR(setForB, &(tempA), s);
        if (s) return tempA;
        tempA = tempA->next;
    }

    return NULL;
};
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> nodes_in_B;

        while (headB != nullptr) {
            nodes_in_B.insert(headB);
            headB = headB->next;
        }

        while (headA != nullptr) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodes_in_B.find(headA) != nodes_in_B.end()) {
                return headA;
            }
            headA = headA->next;
        }

        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> nodesInB = new HashSet<ListNode>();

        while (headB != null) {
            nodesInB.Add(headB);
            headB = headB.next;
        }

        while (headA != null) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodesInB.Contains(headA)) {
                return headA;
            }

            headA = headA.next;
        }

        return null;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    nodesInB := make(map[*ListNode]bool)

    for headB != nil {
        nodesInB[headB] = true
        headB = headB.Next
    }

    for headA != nil {
        // if we find the node pointed to by headA,
        // in our map containing nodes of B, then return the node
        if _, exist := nodesInB[headA]; exist {
            return headA
        }
        headA = headA.Next
    }

    return nil
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> nodesInB = new HashSet<ListNode>();

        while (headB != null) {
            nodesInB.add(headB);
            headB = headB.next;
        }

        while (headA != null) {
            // if we find the node pointed to by headA,
            // in our set containing nodes of B, then return the node
            if (nodesInB.contains(headA)) {
                return headA;
            }
            headA = headA.next;
        }

        return null;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getIntersectionNode = function (headA, headB) {
    let nodesInB = new Set();

    while (headB !== null) {
        nodesInB.add(headB);
        headB = headB.next;
    }

    while (headA !== null) {
        // if we find the node pointed to by headA,
        // in our set containing nodes of B, then return the node
        if (nodesInB.has(headA)) {
            return headA;
        }
        headA = headA.next;
    }

    return null;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        nodes_in_B = set()

        while headB is not None:
            nodes_in_B.add(headB)
            headB = headB.next

        while headA is not None:
            # if we find the node pointed to by headA,
            # in our set containing nodes of B, then return the node
            if headA in nodes_in_B:
                return headA
            headA = headA.next

        return None
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getIntersectionNode(headA: ListNode, headB: ListNode): ListNode {
    let nodesInB: Set<ListNode> = new Set();

    while (headB !== null) {
        nodesInB.add(headB);
        headB = headB.next;
    }

    while (headA !== null) {
        // if we find the node pointed to by headA,
        // in our set containing nodes of B, then return the node
        if (nodesInB.has(headA)) {
            return headA;
        }
        headA = headA.next;
    }

    return null;
}
```

</details>

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }

        return pA;
        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    pA := headA
    pB := headB
    for pA != pB {
        if pA != nil {
            pA = pA.Next
        } else {
            pA = headB
        }
        if pB != nil {
            pB = pB.Next
        } else {
            pB = headA
        }
    }
    return pA
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }
        return pA;
        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getIntersectionNode = function (headA, headB) {
    var pA = headA;
    var pB = headB;
    while (pA != pB) {
        pA = pA == null ? headB : pA.next;
        pB = pB == null ? headA : pB.next;
    }
    return pA;
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        pA = headA
        pB = headB

        while pA != pB:
            pA = headB if pA is None else pA.next
            pB = headA if pB is None else pB.next

        return pA
        # Note: In the case lists do not intersect, the pointers for A and B
        # will still line up in the 2nd iteration, just that here won't be
        # a common node down the list and both will reach their respective ends
        # at the same time. So pA will be NULL in that case.
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getIntersectionNode(headA: ListNode, headB: ListNode): ListNode {
    let pA = headA;
    let pB = headB;
    while (pA !== pB) {
        pA = pA === null ? headB : pA.next;
        pB = pB === null ? headA : pB.next;
    }
    return pA;
    // Note: In the case lists do not intersect, the pointers for A and B
    // will still line up in the 2nd iteration, just that here won't be
    // a common node down the list and both will reach their respective ends
    // at the same time. So pA will be NULL in that case.
}
```

</details>
