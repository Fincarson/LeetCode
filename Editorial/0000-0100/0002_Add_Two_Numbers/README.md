# 2. Add Two Numbers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/add-two-numbers/)  
`Linked List` `Math` `Recursion`

**Problem Link:** [LeetCode 2 - Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Problem

You are given two non-empty linked lists, `l1` and `l2`, representing two non-negative integers.

The digits are stored in reverse order, and each node contains one digit. Add the two numbers and return the sum as a linked list in the same reverse-order format.

The input numbers do not contain leading zeroes, except for the number `0` itself.

## Examples

### Example 1

```text
Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
Output: [7, 0, 8]
Explanation: 342 + 465 = 807.
```

### Example 2

```text
Input: l1 = [0], l2 = [0]
Output: [0]
```

### Example 3

```text
Input: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
Output: [8, 9, 9, 9, 0, 0, 0, 1]
```

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- Each linked list represents a number without leading zeroes, except for the number `0`.

## Follow-Up

Can you solve the problem without converting the linked lists into integers?

## Hints

<details>
<summary><strong>Hint 1</strong></summary>

The lists store digits from least significant to most significant, so you can add from the head forward just like grade-school addition.

</details>

<details>
<summary><strong>Hint 2</strong></summary>

At every step, add the two current digits plus a `carry` from the previous step.

</details>

<details>
<summary><strong>Hint 3</strong></summary>

A dummy head node makes it easier to append result nodes without handling the first node as a special case.

</details>

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add Strings](https://leetcode.com/problems/add-strings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Double a Number Represented as a Linked List](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2. Add Two Numbers

## Overview

The official editorial solves this with elementary grade-school addition.

Because the digits are stored in reverse order, the head nodes are the least significant digits. Walk through both lists together, keep a carry, and append one result digit at a time.

| Approach | Time | Space | Idea |
|---|:---:|:---:|---|
| Elementary Math | `O(max(m, n))` | `O(max(m, n))` | Simulate digit-by-digit addition with a carry. |

## Approach 1: Elementary Math

### Intuition

Add the two current digits and the carry, write the ones digit to the result, and carry the tens digit into the next step.

### Algorithm

1. Create a dummy head for the result list.
2. Initialize `carry = 0`.
3. Continue while either list has nodes or `carry` is nonzero.
4. Read the current digit from each list, using `0` if a list is finished.
5. Append `sum % 10` and update `carry = sum / 10`.

### Complexity

- Time complexity: `O(max(m, n))`
- Space complexity: `O(max(m, n))`

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* curr = dummyHead;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum % 10;
        curr->next->next = NULL;
        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    struct ListNode* result = dummyHead->next;
    free(dummyHead);  // Free the memory allocated for dummyHead
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;  // Freeing the memory allocated for dummyHead
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }

        return dummyHead.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummyHead := &ListNode{Val: 0}
    curr := dummyHead
    carry := 0
    for l1 != nil || l2 != nil || carry != 0 {
        x := 0
        if l1 != nil {
            x = l1.Val
        }
        y := 0
        if l2 != nil {
            y = l2.Val
        }
        sum := carry + x + y
        carry = sum / 10
        curr.Next = &ListNode{Val: sum % 10}
        curr = curr.Next
        if l1 != nil {
            l1 = l1.Next
        }
        if l2 != nil {
            l2 = l2.Next
        }
    }
    return dummyHead.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Add Two Numbers (Java improved)
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return dummyHead.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var addTwoNumbers = function (l1, l2) {
    let dummyHead = new ListNode(0);
    let curr = dummyHead;
    let carry = 0;
    while (l1 !== null || l2 !== null || carry !== 0) {
        let x = l1 !== null ? l1.val : 0;
        let y = l2 !== null ? l2.val : 0;
        let sum = carry + x + y;
        carry = Math.floor(sum / 10);
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }
    return dummyHead.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        curr = dummyHead
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0
            columnSum = l1Val + l2Val + carry
            carry = columnSum // 10
            newNode = ListNode(columnSum % 10)
            curr.next = newNode
            curr = newNode
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummyHead.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null,
): ListNode | null {
    let dummyHead = new ListNode(0);
    let curr = dummyHead;
    let carry = 0;
    while (l1 !== null || l2 !== null || carry !== 0) {
        let x = l1 !== null ? l1.val : 0;
        let y = l2 !== null ? l2.val : 0;
        let sum = carry + x + y;
        carry = Math.floor(sum / 10);
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }
    return dummyHead.next;
}
```

</details>
