# 148. Sort List

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sort-list/)  
`Linked List` `Two Pointers` `Divide and Conquer` `Sorting` `Merge Sort`

**Problem Link:** [LeetCode 148 - Sort List](https://leetcode.com/problems/sort-list/)

## Problem

Given the head of a linked list, return the list after sorting it in ascending order.

### Example 1

```text
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

### Example 2

```text
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

### Example 3

```text
Input: head = []
Output: []
```

## Constraints

- The number of nodes in the list is in the range [0, 5 * 104].
- -105 <= Node.val <= 105

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sort Colors](https://leetcode.com/problems/sort-colors/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sort Linked List Already Sorted Using Absolute Values](https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 148. Sort List

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Top Down Merge Sort | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Bottom Up Merge Sort | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Top Down Merge Sort

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* getMid(struct ListNode* head);
struct ListNode* merge(struct ListNode* list1, struct ListNode* list2);

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* mid = getMid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    return merge(left, right);
}

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummyHead;
    struct ListNode* ptr = &dummyHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = list1 ? list1 : list2;
    return dummyHead.next;
}

struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* midPrev = NULL;
    while (head && head->next) {
        midPrev = (midPrev == NULL) ? head : midPrev->next;
        head = head->next->next;
    }
    struct ListNode* mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1)
            ptr->next = list1;
        else
            ptr->next = list2;

        return dummyHead.next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode mid = GetMid(head);
        ListNode left = SortList(head);
        ListNode right = SortList(mid);
        return Merge(left, right);
    }

    private ListNode Merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode(0);
        ListNode tail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }

            tail = tail.next;
        }

        tail.next = list1 != null ? list1 : list2;
        return dummyHead.next;
    }

    private ListNode GetMid(ListNode head) {
        ListNode midPrev = null;
        while (head != null && head.next != null) {
            midPrev = midPrev == null ? head : midPrev.next;
            head = head.next.next;
        }

        ListNode mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    mid := getMid(head)
    left := sortList(head)
    right := sortList(mid)
    return merge(left, right)
}

func merge(list1, list2 *ListNode) *ListNode {
    dummyHead := &ListNode{}
    tail := dummyHead
    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            tail.Next = list1
            list1 = list1.Next
        } else {
            tail.Next = list2
            list2 = list2.Next
        }
        tail = tail.Next
    }
    if list1 != nil {
        tail.Next = list1
    } else {
        tail.Next = list2
    }
    return dummyHead.Next
}

func getMid(head *ListNode) *ListNode {
    midPrev := (*ListNode)(nil)
    for head != nil && head.Next != nil {
        if midPrev == nil {
            midPrev = head
        } else {
            midPrev = midPrev.Next
        }
        head = head.Next.Next
    }
    mid := midPrev.Next
    midPrev.Next = nil
    return mid
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode mid = getMid(head);
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        return merge(left, right);
    }

    ListNode merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode tail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
                tail = tail.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
                tail = tail.next;
            }
        }
        tail.next = (list1 != null) ? list1 : list2;
        return dummyHead.next;
    }

    ListNode getMid(ListNode head) {
        ListNode midPrev = null;
        while (head != null && head.next != null) {
            midPrev = (midPrev == null) ? head : midPrev.next;
            head = head.next.next;
        }
        ListNode mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortList = function (head) {
    if (!head || !head.next) return head;

    let mid = getMid(head);
    let left = sortList(head);
    let right = sortList(mid);
    return merge(left, right);

    function merge(list1, list2) {
        let dummyHead = new ListNode();
        let tail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }
        tail.next = list1 ? list1 : list2;
        return dummyHead.next;
    }

    function getMid(head) {
        let midPrev = null;
        while (head && head.next) {
            midPrev = midPrev === null ? head : midPrev.next;
            head = head.next.next;
        }
        let mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # If the head or the entire list is none, return the head
        if not head or not head.next:
            return head
        # Get the middle node
        mid = self.getMid(head)
        # Split the list to left and right and sort them
        left = self.sortList(head)
        right = self.sortList(mid)
        # Merge the sorted lists
        return self.merge(left, right)

    def merge(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        tail = dummyHead
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if list1 else list2
        return dummyHead.next

    def getMid(self, head: Optional[ListNode]) -> Optional[ListNode]:
        midPrev = None
        while head and head.next:
            midPrev = head if not midPrev else midPrev.next
            head = head.next.next
        mid = midPrev.next
        midPrev.next = None
        return mid
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortList(head: ListNode | null): ListNode | null {
    if (!head || !head.next) return head;

    let mid = getMid(head);
    let left = sortList(head);
    let right = sortList(mid);
    return merge(left, right);

    function merge(
        list1: ListNode | null,
        list2: ListNode | null,
    ): ListNode | null {
        let dummyHead = new ListNode(0, null);
        let tail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
            } else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }
        tail.next = list1 ? list1 : list2;
        return dummyHead.next;
    }

    function getMid(head: ListNode | null): ListNode | null {
        let midPrev = null;
        while (head && head.next) {
            midPrev = midPrev === null ? head : midPrev.next;
            head = head.next.next;
        }
        let mid = midPrev.next;
        midPrev.next = null;
        return mid;
    }
}
```

</details>

<br>

## Approach 2: Bottom Up Merge Sort

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct ListNode ListNode;

// Function to count the number of nodes in the linked list.
int getCount(ListNode *head) {
    int cnt = 0;
    ListNode *ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}

// Function to split the list into two parts.
ListNode *split(ListNode *start, int size, ListNode **nextSubList) {
    ListNode *midPrev = start;
    ListNode *end = start->next;
    // Use fast and slow approach to find middle and end of second linked list
    for (int index = 1; index < size && (midPrev->next != NULL ||
                                         (end != NULL && end->next != NULL));
         index++) {
        if (end != NULL && end->next != NULL) {
            end = (end->next->next != NULL) ? end->next->next : end->next;
        }
        if (midPrev->next != NULL) {
            midPrev = midPrev->next;
        }
    }
    ListNode *mid = midPrev->next;
    midPrev->next = NULL;
    *nextSubList = end != NULL ? end->next : NULL;
    if (end != NULL) end->next = NULL;
    // Return the start of second linked list
    return mid;
}

// Function to merge two linked lists.
void merge(ListNode **tailRef, ListNode *list1, ListNode *list2) {
    ListNode dummyHead;
    ListNode *newTail = &dummyHead;
    dummyHead.next = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            newTail->next = list1;
            list1 = list1->next;
        } else {
            newTail->next = list2;
            list2 = list2->next;
        }
        newTail = newTail->next;
    }
    newTail->next = (list1 != NULL) ? list1 : list2;
    // Traverse till the end of merged list to get the newTail
    while (newTail->next != NULL) {
        newTail = newTail->next;
    }
    // Link the old tail with the head of merged list
    (*tailRef)->next = dummyHead.next;
    // Update the old tail to the new tail of merged list
    *tailRef = newTail;
}

struct ListNode *sortList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    int n = getCount(head);
    ListNode *start = head;
    ListNode dummyHead;
    dummyHead.next = NULL;
    ListNode *tail, *nextSubList;

    for (int size = 1; size < n; size *= 2) {
        tail = &dummyHead;
        while (start != NULL) {
            if (start->next == NULL) {
                tail->next = start;
                break;
            }
            ListNode *mid = split(start, size, &nextSubList);
            merge(&tail, start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* tail = new ListNode();
    ListNode* nextSubList = new ListNode();

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int n = getCount(head);
        ListNode* start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        // use fast and slow approach to find middle and end of second linked
        // list
        for (int index = 1; index < size && (midPrev->next || end->next);
             index++) {
            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next) {
                midPrev = midPrev->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private ListNode tail;
    private ListNode nextSubList;

    // Sorts the linked list using merge sort
    public ListNode SortList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        int n = GetCount(head);
        ListNode start = head;
        ListNode dummyHead = new ListNode();
        for (int size = 1; size < n; size *= 2) {
            tail = dummyHead;
            while (start != null) {
                if (start.next == null) {
                    tail.next = start;
                    break;
                }

                ListNode mid = Split(start, size);
                Merge(start, mid);
                start = nextSubList;
            }

            start = dummyHead.next;
        }

        return dummyHead.next;
    }

    // Splits the list into two and returns the middle node
    private ListNode Split(ListNode start, int size) {
        ListNode midPrev = start;
        ListNode end = start.next;
        // Use fast and slow approach to find middle and end of second linked
        // list
        for (int index = 1; index < size && (midPrev.next != null ||
                                             (end != null && end.next != null));
             index++) {
            if (end != null && end.next != null) {
                end = (end.next.next != null) ? end.next.next : end.next;
            }

            if (midPrev.next != null) {
                midPrev = midPrev.next;
            }
        }

        ListNode mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end != null ? end.next : null;
        if (end != null)
            end.next = null;
        // Return the start of second linked list
        return mid;
    }

    // Merges two sorted lists
    private void Merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode newTail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
                newTail = newTail.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
                newTail = newTail.next;
            }
        }

        newTail.next = (list1 != null) ? list1 : list2;
        // Traverse till the end of merged list to get the newTail
        while (newTail.next != null) {
            newTail = newTail.next;
        }

        // Link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // Update the old tail to the new tail of merged list
        tail = newTail;
    }

    // Counts the number of nodes in the list
    private int GetCount(ListNode head) {
        int cnt = 0;
        ListNode ptr = head;
        while (ptr != null) {
            ptr = ptr.next;
            cnt++;
        }

        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
var (
    tail        *ListNode
    nextSubList *ListNode
)

func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    n := getCount(head)
    start := head
    dummyHead := &ListNode{}
    for size := 1; size < n; size = size * 2 {
        tail = dummyHead
        for start != nil {
            if start.Next == nil {
                tail.Next = start
                break
            }
            mid := split(start, size)
            merge(start, mid)
            start = nextSubList
        }
        start = dummyHead.Next
    }
    return dummyHead.Next
}

func split(start *ListNode, size int) *ListNode {
    midPrev := start
    end := start.Next
    for index := 1; index < size && (midPrev.Next != nil || end.Next != nil); index++ {
        if end.Next != nil {
            if end.Next.Next != nil {
                end = end.Next.Next
            } else {
                end = end.Next
            }
        }
        if midPrev.Next != nil {
            midPrev = midPrev.Next
        }
    }
    mid := midPrev.Next
    nextSubList = end.Next
    midPrev.Next = nil
    if end != nil {
        end.Next = nil
    }
    return mid
}

func merge(list1 *ListNode, list2 *ListNode) {
    dummyHead := &ListNode{}
    newTail := dummyHead
    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            newTail.Next = list1
            list1 = list1.Next
        } else {
            newTail.Next = list2
            list2 = list2.Next
        }
        newTail = newTail.Next
    }
    if list1 != nil {
        newTail.Next = list1
    } else {
        newTail.Next = list2
    }
    for newTail.Next != nil {
        newTail = newTail.Next
    }
    tail.Next = dummyHead.Next
    tail = newTail
}

func getCount(head *ListNode) int {
    cnt := 0
    ptr := head
    for ptr != nil {
        ptr = ptr.Next
        cnt++
    }
    return cnt
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    ListNode tail = new ListNode();
    ListNode nextSubList = new ListNode();

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        int n = getCount(head);
        ListNode start = head;
        ListNode dummyHead = new ListNode();
        for (int size = 1; size < n; size = size * 2) {
            tail = dummyHead;
            while (start != null) {
                if (start.next == null) {
                    tail.next = start;
                    break;
                }
                ListNode mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode split(ListNode start, int size) {
        ListNode midPrev = start;
        ListNode end = start.next;
        //use fast and slow approach to find middle and end of second linked list
        for (
            int index = 1;
            index < size && (midPrev.next != null || end.next != null);
            index++
        ) {
            if (end.next != null) {
                end = (end.next.next != null) ? end.next.next : end.next;
            }
            if (midPrev.next != null) {
                midPrev = midPrev.next;
            }
        }
        ListNode mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode list1, ListNode list2) {
        ListNode dummyHead = new ListNode();
        ListNode newTail = dummyHead;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
                newTail = newTail.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
                newTail = newTail.next;
            }
        }
        newTail.next = (list1 != null) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next != null) {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode head) {
        int cnt = 0;
        ListNode ptr = head;
        while (ptr != null) {
            ptr = ptr.next;
            cnt++;
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var sortList = function (head) {
    if (!head || !head.next) return head;

    function getCount(head) {
        let cnt = 0,
            ptr = head;
        while (ptr) {
            ptr = ptr.next;
            cnt++;
        }
        return cnt;
    }

    function split(start, size) {
        let midPrev = start;
        let end = start.next;
        // use fast and slow approach to find middle and end of second linked list
        for (
            let index = 1;
            index < size && (midPrev.next || end.next);
            index++
        ) {
            if (end.next) {
                end = end.next.next ? end.next.next : end.next;
            }
            if (midPrev.next) {
                midPrev = midPrev.next;
            }
        }
        const mid = midPrev.next;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    function merge(list1, list2) {
        let dummyHead = new ListNode();
        let newTail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
            }
            newTail = newTail.next;
        }
        newTail.next = list1 || list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next) {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

    let n = getCount(head);
    let start = head;
    let dummyHead = new ListNode();
    let tail, nextSubList;

    for (let size = 1; size < n; size *= 2) {
        tail = dummyHead;
        while (start) {
            if (!start.next) {
                tail.next = start;
                break;
            }
            let mid = split(start, size);
            merge(start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        n = self.getCount(head)
        start = head
        dummyHead = ListNode()
        size = 1
        while size < n:
            self.tail = dummyHead
            while start is not None:
                if start.next is None:
                    self.tail.next = start
                    break
                mid = self.split(start, size)
                self.merge(start, mid)
                start = self.nextSubList
            start = dummyHead.next
            size *= 2
        return dummyHead.next

    def split(self, start, size):
        midPrev = start
        end = start.next
        # Use fast and slow approach to find middle and end of second linked list
        for index in range(1, size):
            if end and end.next:
                end = end.next.next
            else:
                if end:
                    end = end.next
            if midPrev.next:
                midPrev = midPrev.next
        mid = midPrev.next
        midPrev.next = None
        self.nextSubList = end.next if end else None
        if end:
            end.next = None
        # Return the start of second linked list
        return mid

    def merge(self, list1, list2):
        dummyHead = ListNode()
        newTail = dummyHead
        while list1 and list2:
            if list1.val < list2.val:
                newTail.next = list1
                list1 = list1.next
            else:
                newTail.next = list2
                list2 = list2.next
            newTail = newTail.next
        newTail.next = list1 if list1 else list2
        # Traverse till the end of merged list to get the newTail
        while newTail.next:
            newTail = newTail.next
        # Link the old tail with the head of merged list
        self.tail.next = dummyHead.next
        # Update the old tail to the new tail of merged list
        self.tail = newTail

    def getCount(self, head):
        cnt = 0
        ptr = head
        while ptr:
            ptr = ptr.next
            cnt += 1
        return cnt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortList(head: ListNode | null): ListNode | null {
    if (!head || !head.next) return head;

    function getCount(head: ListNode): number {
        let cnt = 0,
            ptr: ListNode | null = head;
        while (ptr) {
            ptr = ptr.next;
            cnt++;
        }
        return cnt;
    }

    function split(start: ListNode, size: number): ListNode {
        let midPrev = start;
        let end = start.next!;
        // use fast and slow approach to find middle and end of second linked list
        for (
            let index = 1;
            index < size && (midPrev.next || end.next);
            index++
        ) {
            if (end.next) {
                end = end.next.next ? end.next.next : end.next;
            }
            if (midPrev.next) {
                midPrev = midPrev.next;
            }
        }
        const mid = midPrev.next!;
        midPrev.next = null;
        nextSubList = end.next;
        end.next = null;
        // return the start of second linked list
        return mid;
    }

    function merge(list1: ListNode | null, list2: ListNode | null): void {
        let dummyHead = new ListNode();
        let newTail = dummyHead;
        while (list1 && list2) {
            if (list1.val < list2.val) {
                newTail.next = list1;
                list1 = list1.next;
            } else {
                newTail.next = list2;
                list2 = list2.next;
            }
            newTail = newTail.next;
        }
        newTail.next = list1 || list2;
        // traverse till the end of merged list to get the newTail
        while (newTail.next) {
            newTail = newTail.next;
        }
        // link the old tail with the head of merged list
        tail.next = dummyHead.next;
        // update the old tail to the new tail of merged list
        tail = newTail;
    }

    let n = getCount(head);
    let start = head;
    let dummyHead = new ListNode();
    let tail: ListNode, nextSubList: ListNode | null;

    for (let size = 1; size < n; size *= 2) {
        tail = dummyHead;
        while (start) {
            if (!start.next) {
                tail.next = start;
                break;
            }
            let mid = split(start, size);
            merge(start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
}
```

</details>
