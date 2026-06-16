# 21. Merge Two Sorted Lists

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/merge-two-sorted-lists/)  
`Linked List` `Recursion`

**Problem Link:** [LeetCode 21 - Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

## Problem

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

### Example 1

```text
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

### Example 2

```text
Input: list1 = [], list2 = []
Output: []
```

### Example 3

```text
Input: list1 = [], list2 = [0]
Output: [0]
```

## Constraints

- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sort List](https://leetcode.com/problems/sort-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Common Subsequence Between Sorted Arrays](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 21. Merge Two Sorted Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        } else if (l1.val < l2.val) {
            l1.next = MergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = MergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    } else if l1.Val < l2.Val {
        l1.Next = mergeTwoLists(l1.Next, l2)
        return l1
    } else {
        l2.Next = mergeTwoLists(l1, l2.Next)
        return l2
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        } else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function mergeTwoLists(l1, l2) {
    if (l1 === null) {
        return l2;
    } else if (l2 === null) {
        return l1;
    } else if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mergeTwoLists(self, l1, l2):
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        elif l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mergeTwoLists(
    l1: ListNode | null,
    l2: ListNode | null,
): ListNode | null {
    if (l1 === null) {
        return l2;
    } else if (l2 === null) {
        return l1;
    } else if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
}
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode prehead;
    prehead.val = -1;
    struct ListNode* prev = &prehead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == NULL ? l2 : l1;
    return prehead.next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead(-1);
        ListNode* prev = &prehead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        // At least one of l1 and l2 can still have nodes at this point, so
        // connect the non-null list to the end of the merged list.
        prev->next = l1 == nullptr ? l2 : l1;
        return prehead.next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead = new ListNode(-1);
        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }

            prev = prev.next;
        }

        // At least one of l1 and l2 can still have nodes at this point, so
        // connect the non-null list to the end of the merged list.
        prev.next = l1 == null ? l2 : l1;
        return prehead.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    prehead := &ListNode{-1, nil}
    prev := prehead
    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            prev.Next = l1
            l1 = l1.Next
        } else {
            prev.Next = l2
            l2 = l2.Next
        }
        prev = prev.Next
    }
    if l1 != nil {
        prev.Next = l1
    } else {
        prev.Next = l2
    }
    return prehead.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        // At least one of l1 and l2 can still have nodes at this point, so connect
        // the non-null list to the end of the merged list.
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function mergeTwoLists(l1, l2) {
    let prehead = new ListNode(-1);
    let prev = prehead;
    while (l1 != null && l2 != null) {
        if (l1.val <= l2.val) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        prev = prev.next;
    }
    if (l1 != null) {
        prev.next = l1;
    } else {
        prev.next = l2;
    }
    return prehead.next;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def mergeTwoLists(self, l1, l2):
        # maintain an unchanging reference to node ahead of the return node.
        prehead = ListNode(-1)

        prev = prehead
        while l1 and l2:
            if l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next

        # At least one of l1 and l2 can still have nodes at this point, so connect
        # the non-null list to the end of the merged list.
        prev.next = l1 if l1 is not None else l2

        return prehead.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mergeTwoLists(
    l1: ListNode | null,
    l2: ListNode | null,
): ListNode | null {
    let prehead: ListNode = new ListNode(-1);
    let prev: ListNode = prehead;
    while (l1 !== null && l2 !== null) {
        if (l1.val <= l2.val) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        prev = prev.next;
    }
    if (l1 !== null) {
        prev.next = l1;
    } else {
        prev.next = l2;
    }
    return prehead.next;
}
```

</details>
