# 2. Add Two Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/add-two-numbers/)  
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
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Strings](https://leetcode.com/problems/add-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Double a Number Represented as a Linked List](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2. Add Two Numbers

## Overview

Each linked list stores the number in reverse order, so the head node is the ones digit.

That means we can add the lists from left to right exactly like grade-school addition:

1. Add the current digit from `l1`.
2. Add the current digit from `l2`.
3. Add the carry from the previous position.
4. Store `sum % 10` in the result.
5. Carry `sum / 10` into the next position.

There are three useful ways to implement this idea:

| Approach | Time | Space | Idea |
|---|:---:|:---:|---|
| Iterative Dummy Head | `O(max(m, n))` | `O(max(m, n))` | Build a new linked list using a dummy head. |
| Recursive Addition | `O(max(m, n))` | `O(max(m, n))` | Let each recursive call produce one digit. |
| In-Place Addition | `O(max(m, n))` | `O(1)` auxiliary | Reuse nodes from the input lists when mutation is allowed. |

## Approach 1: Iterative Dummy Head

### Intuition

The dummy head gives us a stable node before the result list. Every new digit can be appended to `current.next`, so we never need special logic for the first result node.

The loop must continue while either list still has digits or a final carry remains.

### Algorithm

1. Create a dummy head node and set `current` to it.
2. Set `carry = 0`.
3. While `l1`, `l2`, or `carry` exists:
   - Start `total` with `carry`.
   - Add `l1.val` if `l1` exists, then move `l1`.
   - Add `l2.val` if `l2` exists, then move `l2`.
   - Create a new node with `total % 10`.
   - Update `carry = total / 10`.
4. Return `dummy.next`.

### Complexity

- Time complexity: `O(max(m, n))`
- Space complexity: `O(max(m, n))` for the returned list, with `O(1)` auxiliary space.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* current = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int total = carry;

        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        carry = total / 10;
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = total % 10;
        current->next = NULL;
    }

    return dummy.next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            carry = total / 10;
            current->next = new ListNode(total % 10);
            current = current->next;
        }

        return dummy.next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int total = carry;

            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            carry = total / 10;
            current.next = new ListNode(total % 10);
            current = current.next;
        }

        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    current := dummy
    carry := 0

    for l1 != nil || l2 != nil || carry != 0 {
        total := carry

        if l1 != nil {
            total += l1.Val
            l1 = l1.Next
        }

        if l2 != nil {
            total += l2.Val
            l2 = l2.Next
        }

        carry = total / 10
        current.Next = &ListNode{Val: total % 10}
        current = current.Next
    }

    return dummy.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int total = carry;

            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            carry = total / 10;
            current.next = new ListNode(total % 10);
            current = current.next;
        }

        return dummy.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var addTwoNumbers = function(l1, l2) {
    const dummy = new ListNode(0);
    let current = dummy;
    let carry = 0;

    while (l1 || l2 || carry) {
        let total = carry;

        if (l1) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2) {
            total += l2.val;
            l2 = l2.next;
        }

        carry = Math.floor(total / 10);
        current.next = new ListNode(total % 10);
        current = current.next;
    }

    return dummy.next;
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
        dummy = ListNode(0)
        current = dummy
        carry = 0

        while l1 or l2 or carry:
            total = carry

            if l1:
                total += l1.val
                l1 = l1.next

            if l2:
                total += l2.val
                l2 = l2.next

            carry = total // 10
            current.next = ListNode(total % 10)
            current = current.next

        return dummy.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    const dummy = new ListNode(0);
    let current = dummy;
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        let total = carry;

        if (l1 !== null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 !== null) {
            total += l2.val;
            l2 = l2.next;
        }

        carry = Math.floor(total / 10);
        current.next = new ListNode(total % 10);
        current = current.next;
    }

    return dummy.next;
}
```

</details>

## Approach 2: Recursive Addition

### Intuition

Every digit position depends only on three things: the current node from `l1`, the current node from `l2`, and the carry.

That makes the problem naturally recursive. A helper function creates the current digit, then asks the next recursive call to build the rest of the list.

### Algorithm

1. If both nodes are empty and `carry == 0`, return `null`.
2. Add the current values and carry.
3. Create a node with `total % 10`.
4. Recursively assign `node.next` using the next nodes and `total / 10`.
5. Return the node.

### Complexity

- Time complexity: `O(max(m, n))`
- Space complexity: `O(max(m, n))` for recursion stack and the returned list.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2, int carry) {
    if (!l1 && !l2 && carry == 0) {
        return NULL;
    }

    int total = carry;
    if (l1) {
        total += l1->val;
        l1 = l1->next;
    }

    if (l2) {
        total += l2->val;
        l2 = l2->next;
    }

    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = total % 10;
    node->next = addLists(l1, l2, total / 10);
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addLists(l1, l2, 0);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int total = carry;
        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        ListNode* node = new ListNode(total % 10);
        node->next = add(l1, l2, total / 10);
        return node;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        return Add(l1, l2, 0);
    }

    private ListNode Add(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
        }

        int total = carry;
        if (l1 != null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 != null) {
            total += l2.val;
            l2 = l2.next;
        }

        ListNode node = new ListNode(total % 10);
        node.next = Add(l1, l2, total / 10);
        return node;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return add(l1, l2, 0)
}

func add(l1 *ListNode, l2 *ListNode, carry int) *ListNode {
    if l1 == nil && l2 == nil && carry == 0 {
        return nil
    }

    total := carry
    if l1 != nil {
        total += l1.Val
        l1 = l1.Next
    }

    if l2 != nil {
        total += l2.Val
        l2 = l2.Next
    }

    return &ListNode{
        Val:  total % 10,
        Next: add(l1, l2, total/10),
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return add(l1, l2, 0);
    }

    private ListNode add(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) {
            return null;
        }

        int total = carry;
        if (l1 != null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 != null) {
            total += l2.val;
            l2 = l2.next;
        }

        ListNode node = new ListNode(total % 10);
        node.next = add(l1, l2, total / 10);
        return node;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var addTwoNumbers = function(l1, l2) {
    const add = (node1, node2, carry) => {
        if (!node1 && !node2 && carry === 0) {
            return null;
        }

        let total = carry;
        let next1 = null;
        let next2 = null;

        if (node1) {
            total += node1.val;
            next1 = node1.next;
        }

        if (node2) {
            total += node2.val;
            next2 = node2.next;
        }

        const node = new ListNode(total % 10);
        node.next = add(next1, next2, Math.floor(total / 10));
        return node;
    };

    return add(l1, l2, 0);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addTwoNumbers(
        self,
        l1: Optional[ListNode],
        l2: Optional[ListNode],
        carry: int = 0,
    ) -> Optional[ListNode]:
        if not l1 and not l2 and carry == 0:
            return None

        total = carry
        next_l1 = None
        next_l2 = None

        if l1:
            total += l1.val
            next_l1 = l1.next

        if l2:
            total += l2.val
            next_l2 = l2.next

        node = ListNode(total % 10)
        node.next = self.addTwoNumbers(next_l1, next_l2, total // 10)
        return node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    function add(
        node1: ListNode | null,
        node2: ListNode | null,
        carry: number
    ): ListNode | null {
        if (node1 === null && node2 === null && carry === 0) {
            return null;
        }

        let total = carry;
        let next1: ListNode | null = null;
        let next2: ListNode | null = null;

        if (node1 !== null) {
            total += node1.val;
            next1 = node1.next;
        }

        if (node2 !== null) {
            total += node2.val;
            next2 = node2.next;
        }

        const node = new ListNode(total % 10);
        node.next = add(next1, next2, Math.floor(total / 10));
        return node;
    }

    return add(l1, l2, 0);
}
```

</details>

## Approach 3: In-Place Addition

### Intuition

If mutating the input lists is allowed, we can reuse the existing nodes instead of allocating a full new result list.

The result starts with `l1` if it exists, otherwise `l2`. As we add digits, we overwrite the current node's value. When the current reused chain ends but another input list still has nodes, we connect to that remaining chain and continue. Only a final carry may require allocating one extra node.

This saves auxiliary space, but it is less clean than the dummy-head version and modifies the inputs.

### Algorithm

1. Let `head` be `l1` if possible, otherwise `l2`.
2. Walk through both lists while tracking `current`, `previous`, and `carry`.
3. If no current result node exists but a carry remains, allocate one.
4. Write `total % 10` into the current result node.
5. Move to the next reusable node, connecting the remaining list if needed.
6. Return `head`.

### Complexity

- Time complexity: `O(max(m, n))`
- Space complexity: `O(1)` auxiliary space. A single extra node may be allocated for the final carry.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = l1 ? l1 : l2;
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        if (!current) {
            current = malloc(sizeof(struct ListNode));
            current->val = 0;
            current->next = NULL;
            previous->next = current;
        }

        int total = carry;
        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        current->val = total % 10;
        carry = total / 10;
        previous = current;

        if (current->next) {
            current = current->next;
        } else if (l1) {
            current->next = l1;
            current = current->next;
        } else if (l2) {
            current->next = l2;
            current = current->next;
        } else {
            current = NULL;
        }
    }

    return head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1 ? l1 : l2;
        ListNode* current = head;
        ListNode* previous = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            if (!current) {
                current = new ListNode(0);
                previous->next = current;
            }

            int total = carry;
            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            current->val = total % 10;
            carry = total / 10;
            previous = current;

            if (current->next) {
                current = current->next;
            } else if (l1) {
                current->next = l1;
                current = current->next;
            } else if (l2) {
                current->next = l2;
                current = current->next;
            } else {
                current = nullptr;
            }
        }

        return head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1 ?? l2;
        ListNode current = head;
        ListNode previous = null;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            if (current == null) {
                current = new ListNode(0);
                previous.next = current;
            }

            int total = carry;
            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            current.val = total % 10;
            carry = total / 10;
            previous = current;

            if (current.next != null) {
                current = current.next;
            } else if (l1 != null) {
                current.next = l1;
                current = current.next;
            } else if (l2 != null) {
                current.next = l2;
                current = current.next;
            } else {
                current = null;
            }
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head := l1
    if head == nil {
        head = l2
    }

    current := head
    var previous *ListNode
    carry := 0

    for l1 != nil || l2 != nil || carry != 0 {
        if current == nil {
            current = &ListNode{}
            previous.Next = current
        }

        total := carry
        if l1 != nil {
            total += l1.Val
            l1 = l1.Next
        }

        if l2 != nil {
            total += l2.Val
            l2 = l2.Next
        }

        current.Val = total % 10
        carry = total / 10
        previous = current

        if current.Next != nil {
            current = current.Next
        } else if l1 != nil {
            current.Next = l1
            current = current.Next
        } else if l2 != nil {
            current.Next = l2
            current = current.Next
        } else {
            current = nil
        }
    }

    return head
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1 != null ? l1 : l2;
        ListNode current = head;
        ListNode previous = null;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            if (current == null) {
                current = new ListNode(0);
                previous.next = current;
            }

            int total = carry;
            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }

            current.val = total % 10;
            carry = total / 10;
            previous = current;

            if (current.next != null) {
                current = current.next;
            } else if (l1 != null) {
                current.next = l1;
                current = current.next;
            } else if (l2 != null) {
                current.next = l2;
                current = current.next;
            } else {
                current = null;
            }
        }

        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var addTwoNumbers = function(l1, l2) {
    const head = l1 || l2;
    let current = head;
    let previous = null;
    let carry = 0;

    while (l1 || l2 || carry) {
        if (!current) {
            current = new ListNode(0);
            previous.next = current;
        }

        let total = carry;
        if (l1) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2) {
            total += l2.val;
            l2 = l2.next;
        }

        current.val = total % 10;
        carry = Math.floor(total / 10);
        previous = current;

        if (current.next) {
            current = current.next;
        } else if (l1) {
            current.next = l1;
            current = current.next;
        } else if (l2) {
            current.next = l2;
            current = current.next;
        } else {
            current = null;
        }
    }

    return head;
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
        head = l1 or l2
        current = head
        previous = None
        carry = 0

        while l1 or l2 or carry:
            if current is None:
                current = ListNode(0)
                previous.next = current

            total = carry
            if l1:
                total += l1.val
                l1 = l1.next

            if l2:
                total += l2.val
                l2 = l2.next

            current.val = total % 10
            carry = total // 10
            previous = current

            if current.next:
                current = current.next
            elif l1:
                current.next = l1
                current = current.next
            elif l2:
                current.next = l2
                current = current.next
            else:
                current = None

        return head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function addTwoNumbers(
    l1: ListNode | null,
    l2: ListNode | null
): ListNode | null {
    const head = l1 ?? l2;
    let current = head;
    let previous: ListNode | null = null;
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        if (current === null) {
            current = new ListNode(0);
            previous!.next = current;
        }

        let total = carry;
        if (l1 !== null) {
            total += l1.val;
            l1 = l1.next;
        }

        if (l2 !== null) {
            total += l2.val;
            l2 = l2.next;
        }

        current.val = total % 10;
        carry = Math.floor(total / 10);
        previous = current;

        if (current.next !== null) {
            current = current.next;
        } else if (l1 !== null) {
            current.next = l1;
            current = current.next;
        } else if (l2 !== null) {
            current.next = l2;
            current = current.next;
        } else {
            current = null;
        }
    }

    return head;
}
```

</details>
