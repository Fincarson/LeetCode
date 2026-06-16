# 92. Reverse Linked List II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reverse-linked-list-ii/)  
`Linked List`

**Problem Link:** [LeetCode 92 - Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)

## Problem

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

### Example 1

```text
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

### Example 2

```text
Input: head = [5], left = 1, right = 1
Output: [5]
```

## Constraints

- The number of nodes in the list is n.
- 1 <= n <= 500
- -500 <= Node.val <= 500
- 1 <= left <= right <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 92. Reverse Linked List II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Link Reversal. | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
struct ListNode* leftNode;
bool stop;
void recurseAndReverse(struct ListNode* right, int m, int n) {
    // base case. Don't proceed any further
    if (n == 1) {
        return;
    }
    right = right->next;
    if (m > 1) {
        leftNode = leftNode->next;
    }
    recurseAndReverse(right, m - 1, n - 1);
    if (leftNode == right || right->next == leftNode) {
        stop = true;
    }
    if (!stop) {
        int t = leftNode->val;
        leftNode->val = right->val;
        right->val = t;
        leftNode = leftNode->next;
    }
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    leftNode = head;
    stop = false;
    recurseAndReverse(head, m, n);
    return head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* left = nullptr;
    bool stop = false;
    void recurseAndReverse(ListNode* right, int m, int n) {
        if (n == 1) return;
        right = right->next;
        if (m > 1) this->left = this->left->next;
        recurseAndReverse(right, m - 1, n - 1);
        if (this->left == right || right->next == this->left) stop = true;
        if (!stop) {
            int t = this->left->val;
            this->left->val = right->val;
            right->val = t;
            this->left = this->left->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        this->left = head;
        recurseAndReverse(head, m, n);
        return head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private ListNode left = null;
    private bool stop = false;

    public void recurseAndReverse(ListNode right, int m, int n) {
        if (n == 1)
            return;
        right = right.next;
        if (m > 1)
            this.left = this.left.next;
        this.recurseAndReverse(right, m - 1, n - 1);
        if (this.left == right || right.next == this.left)
            this.stop = true;
        if (!this.stop) {
            int tmp = this.left.val;
            this.left.val = right.val;
            right.val = tmp;
            this.left = this.left.next;
        }
    }

    public ListNode ReverseBetween(ListNode head, int m, int n) {
        stop = false;
        left = head;
        recurseAndReverse(head, m, n);
        return head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Solution struct {
    stop bool
    left *ListNode
}

func (s *Solution) recurseAndReverse(right *ListNode, m int, n int) {
    if n == 1 {
        return
    }
    right = right.Next
    if m > 1 {
        s.left = s.left.Next
    }
    s.recurseAndReverse(right, m-1, n-1)
    if s.left == right || right.Next == s.left {
        s.stop = true
    }
    if !s.stop {
        t := s.left.Val
        s.left.Val = right.Val
        right.Val = t
        s.left = s.left.Next
    }
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
    sol := &Solution{left: head, stop: false}
    sol.recurseAndReverse(head, m, n)
    return head
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Object level variables since we need the changes
    // to persist across recursive calls and Java is pass by value.
    private boolean stop;
    private ListNode left;

    public void recurseAndReverse(ListNode right, int m, int n) {
        // base case. Don't proceed any further
        if (n == 1) {
            return;
        }

        // Keep moving the right pointer one step forward until (n == 1)
        right = right.next;

        // Keep moving left pointer to the right until we reach the proper node
        // from where the reversal is to start.
        if (m > 1) {
            this.left = this.left.next;
        }

        // Recurse with m and n reduced.
        this.recurseAndReverse(right, m - 1, n - 1);

        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if (this.left == right || right.next == this.left) {
            this.stop = true;
        }

        // Until the boolean stop is false, swap data between the two pointers
        if (!this.stop) {
            int t = this.left.val;
            this.left.val = right.val;
            right.val = t;

            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            this.left = this.left.next;
        }
    }

    public ListNode reverseBetween(ListNode head, int m, int n) {
        this.left = head;
        this.stop = false;
        this.recurseAndReverse(head, m, n);
        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseBetween = function (head, m, n) {
    let left = head,
        stop = false;
    const recurseAndReverse = (right, m, n) => {
        if (n == 1) return;
        right = right.next;
        if (m > 1) left = left.next;
        recurseAndReverse(right, m - 1, n - 1);
        if (left == right || right.next == left) stop = true;
        if (!stop) {
            [left.val, right.val] = [right.val, left.val];
            left = left.next;
        }
    };
    recurseAndReverse(head, m, n);
    return head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], m: int, n: int
    ) -> Optional[ListNode]:
        if not head:
            return None

        left, right = head, head
        stop = False

        def recurseAndReverse(right, m, n):
            nonlocal left, stop

            # base case. Don't proceed any further
            if n == 1:
                return

            # Keep moving the right pointer one step forward until (n == 1)
            right = right.next

            # Keep moving left pointer to the right until we reach the proper node
            # from where the reversal is to start.
            if m > 1:
                left = left.next

            # Recurse with m and n reduced.
            recurseAndReverse(right, m - 1, n - 1)

            # In case both the pointers cross each other or become equal, we
            # stop i.e. don't swap data any further. We are done reversing at this
            # point.
            if left == right or right.next == left:
                stop = True

            # Until the boolean stop is false, swap data between the two pointers
            if not stop:
                left.val, right.val = right.val, left.val

                # Move left one step to the right.
                # The right pointer moves one step back via backtracking.
                left = left.next

        recurseAndReverse(right, m, n)
        return head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseBetween(
    head: ListNode | null,
    m: number,
    n: number,
): ListNode | null {
    if (head == null) return null;
    let left: ListNode = head,
        stop: boolean = false;
    const recurseAndReverse = (
        right: ListNode | null,
        m: number,
        n: number,
    ) => {
        if (right == null || n == 1) return;
        right = right.next;
        if (m > 1) left = left.next;
        recurseAndReverse(right, m - 1, n - 1);
        if (left === right || (right && right.next === left)) stop = true;
        if (!stop) {
            let tmp = left.val;
            left.val = right.val;
            right.val = tmp;
            left = left.next;
        }
    };
    recurseAndReverse(head, m, n);
    return head;
}
```

</details>

<br>

## Approach 2: Iterative Link Reversal.

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *cur = head, *prev = NULL;
    while (m > 1) {
        prev = cur;
        cur = cur->next;
        m--;
        n--;
    }
    struct ListNode *con = prev, *tail = cur;
    struct ListNode *third = NULL;
    while (n > 0) {
        third = cur->next;
        cur->next = prev;
        prev = cur;
        cur = third;
        n--;
    }
    if (con)
        con->next = prev;
    else
        head = prev;
    tail->next = cur;
    return head;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *cur = head, *prev = NULL;
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }
        ListNode *con = prev, *tail = cur;
        ListNode* third = NULL;
        while (n > 0) {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            n--;
        }
        if (con != NULL) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = cur;
        return head;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode ReverseBetween(ListNode head, int m, int n) {
        // Empty list
        if (head == null) {
            return null;
        }

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode cur = head, prev = null;
        while (m > 1) {
            prev = cur;
            cur = cur.next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode con = prev, tail = cur;
        // Iteratively reverse the nodes until n becomes 0.
        ListNode third = null;
        while (n > 0) {
            third = cur.next;
            cur.next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        // Adjust the final connections as explained in the algorithm
        if (con != null) {
            con.next = prev;
        } else {
            head = prev;
        }

        tail.next = cur;
        return head;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    if head == nil {
        return nil
    }
    var cur, prev *ListNode = head, nil
    for ; m > 1; m, n = m-1, n-1 {
        prev = cur
        cur = cur.Next
    }
    var con, tail *ListNode = prev, cur
    var third *ListNode = nil
    for ; n > 0; n-- {
        third = cur.Next
        cur.Next = prev
        prev = cur
        cur = third
    }
    if con != nil {
        con.Next = prev
    } else {
        head = prev
    }
    tail.Next = cur
    return head
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // Empty list
        if (head == null) {
            return null;
        }

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode cur = head, prev = null;
        while (m > 1) {
            prev = cur;
            cur = cur.next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode con = prev, tail = cur;

        // Iteratively reverse the nodes until n becomes 0.
        ListNode third = null;
        while (n > 0) {
            third = cur.next;
            cur.next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        // Adjust the final connections as explained in the algorithm
        if (con != null) {
            con.next = prev;
        } else {
            head = prev;
        }

        tail.next = cur;
        return head;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var reverseBetween = function (head, m, n) {
    if (head === null) {
        return null;
    }
    let cur = head,
        prev = null;
    while (m > 1) {
        prev = cur;
        cur = cur.next;
        m--;
        n--;
    }
    let con = prev,
        tail = cur;
    let third = null;
    while (n > 0) {
        third = cur.next;
        cur.next = prev;
        prev = cur;
        cur = third;
        n--;
    }
    if (con !== null) {
        con.next = prev;
    } else {
        head = prev;
    }
    tail.next = cur;
    return head;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseBetween(
        self, head: Optional[ListNode], m: int, n: int
    ) -> Optional[ListNode]:
        # Empty list
        if not head:
            return None

        # Move the two pointers until they reach the proper starting point
        # in the list.
        cur, prev = head, None
        while m > 1:
            prev = cur
            cur = cur.next
            m, n = m - 1, n - 1

        # The two pointers that will fix the final connections.
        tail, con = cur, prev

        # Iteratively reverse the nodes until n becomes 0.
        while n:
            third = cur.next
            cur.next = prev
            prev = cur
            cur = third
            n -= 1

        # Adjust the final connections as explained in the algorithm
        if con:
            con.next = prev
        else:
            head = prev
        tail.next = cur
        return head
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function reverseBetween(
    head: ListNode | null,
    m: number,
    n: number,
): ListNode | null {
    if (head === null) {
        return null;
    }
    let cur = head,
        prev = null;
    while (m > 1) {
        prev = cur;
        cur = cur.next!;
        m--;
        n--;
    }
    let con = prev,
        tail = cur;
    let third = null;
    while (n > 0) {
        third = cur.next;
        cur.next = prev;
        prev = cur;
        cur = third!;
        n--;
    }
    if (con !== null) {
        con.next = prev;
    } else {
        head = prev;
    }
    tail.next = cur;
    return head;
}
```

</details>
