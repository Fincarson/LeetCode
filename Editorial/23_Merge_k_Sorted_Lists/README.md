# 23. Merge k Sorted Lists

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/merge-k-sorted-lists/)  
`Linked List` `Divide and Conquer` `Heap (Priority Queue)` `Merge Sort`

**Problem Link:** [LeetCode 23 - Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

## Problem

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

### Example 1

```text
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
```

### Example 2

```text
Input: lists = []
Output: []
```

### Example 3

```text
Input: lists = [[]]
Output: []
```

## Constraints

- k == lists.length
- 0 <= k <= 104
- 0 <= lists[i].length <= 500
- -104 <= lists[i][j] <= 104
- lists[i] is sorted in ascending order.
- The sum of lists[i].length will not exceed 104.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 23. Merge k Sorted Lists

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Optimize Approach 2 by Priority Queue | C++, Java, Python3 |
| Merge with Divide And Conquer | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int nodes[10000], nodesSize = 0;
    struct ListNode* head;
    struct ListNode* point;
    struct ListNode node = {0, NULL};
    head = &node;
    point = head;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* l = lists[i];
        while (l != NULL) {
            nodes[nodesSize++] = l->val;
            l = l->next;
        }
    }
    qsort(nodes, nodesSize, sizeof(int), compare);
    for (int i = 0; i < nodesSize; i++) {
        struct ListNode* new_node =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val = nodes[i];
        new_node->next = NULL;
        point->next = new_node;
        point = point->next;
    }
    return head->next;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// Definition for singly-linked list.
// struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        ListNode head(0);
        ListNode* point = &head;
        for (ListNode* l : lists) {
            while (l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        }
        sort(nodes.begin(), nodes.end());
        for (int x : nodes) {
            point->next = new ListNode(x);
            point = point->next;
        }
        return head.next;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        List<int> nodes = new List<int>();
        ListNode head = new ListNode(0);
        ListNode point = head;
        foreach (ListNode listNode in lists) {
            ListNode list = listNode;
            while (list != null) {
                nodes.Add(list.val);
                list = list.next;
            }
        }

        nodes.Sort();
        foreach (int val in nodes) {
            point.next = new ListNode(val);
            point = point.next;
        }

        return head.next;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func mergeKLists(lists []*ListNode) *ListNode {
    nodes := make([]int, 0, 10000)
    dummyNode := &ListNode{}
    currNode := dummyNode
    for _, l := range lists {
        for l != nil {
            nodes = append(nodes, l.Val)
            l = l.Next
        }
    }
    sort.Ints(nodes)
    for _, v := range nodes {
        currNode.Next = &ListNode{Val: v}
        currNode = currNode.Next
    }
    return dummyNode.Next
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) {
//         val = x;
//         next = null;
//     }
// }
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ArrayList<Integer> nodes = new ArrayList<>();
        ListNode head = new ListNode(0);
        ListNode point = head;
        for (ListNode l : lists) {
            while (l != null) {
                nodes.add(l.val);
                l = l.next;
            }
        }
        Collections.sort(nodes);
        for (int x : nodes) {
            point.next = new ListNode(x);
            point = point.next;
        }
        return head.next;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function mergeKLists(lists) {
    let nodes = [];
    let dummy = new ListNode(0);
    let point = dummy;
    lists.forEach((l) => {
        while (l) {
            nodes.push(l.val);
            l = l.next;
        }
    });
    nodes
        .sort((a, b) => a - b)
        .forEach((n) => {
            point.next = new ListNode(n);
            point = point.next;
        });
    return dummy.next;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(
        self, lists: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        nodes = []
        head = point = ListNode(0)
        for l in lists:
            while l:
                nodes.append(l.val)
                l = l.next

        for x in sorted(nodes):
            point.next = ListNode(x)
            point = point.next

        return head.next
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    let nodes: number[] = [];
    let dummy: ListNode = new ListNode(0);
    let point: ListNode = dummy;
    lists.forEach((l) => {
        while (l) {
            nodes.push(l.val);
            l = l.next;
        }
    });
    nodes
        .sort((a, b) => a - b)
        .forEach((n) => {
            point.next = new ListNode(n);
            point = point.next;
        });
    return dummy.next;
}
```

</details>

<br>

## Approach 3: Optimize Approach 2 by Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (auto l : lists) {
            if (l) q.push(l);
        }
        ListNode head(0);
        ListNode* point = &head;
        while (!q.empty()) {
            point->next = q.top();
            q.pop();
            point = point->next;
            if (point->next) q.push(point->next);
        }
        return head.next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = new ListNode(0);
        ListNode point = head;
        PriorityQueue<ListNode> queue = new PriorityQueue<>(
            new Comparator<ListNode>() {
                @Override
                public int compare(ListNode o1, ListNode o2) {
                    if (o1.val > o2.val) {
                        return 1;
                    } else if (o1.val == o2.val) {
                        return 0;
                    } else {
                        return -1;
                    }
                }
            }
        );
        for (ListNode node : lists) {
            if (node != null) {
                queue.add(node);
            }
        }
        while (!queue.isEmpty()) {
            point.next = queue.poll();
            point = point.next;
            if (point.next != null) {
                queue.add(point.next);
            }
        }
        return head.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class HeapNode:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        # Define comparison based on ListNode's value
        return self.node.val < other.node.val


class Solution:
    def mergeKLists(
        self, lists: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        dummy = ListNode(0)
        current = dummy
        heap = []

        # Initialize the heap
        for l in lists:
            if l:
                heapq.heappush(heap, HeapNode(l))

        # Extract the minimum node and add its next node to the heap
        while heap:
            heap_node = heapq.heappop(heap)
            node = heap_node.node
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(heap, HeapNode(node.next))

        return dummy.next
```

</details>

<br>

## Approach 5: Merge with Divide And Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size();
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2)
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            interval *= 2;
        }
        return amount > 0 ? lists[0] : NULL;
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* point = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l1;
                l1 = point->next->next;
            }
            point = point->next;
        }
        if (!l1) {
            point->next = l2;
        } else {
            point->next = l1;
        }
        return head.next;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
// Definition for singly-linked list.
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode() {}
//     ListNode(int val) { this.val = val; }
//     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int amount = lists.length;
        int interval = 1;
        while (interval < amount) {
            for (int i = 0; i < amount - interval; i += interval * 2) {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return amount > 0 ? lists[0] : null;
    }

    public ListNode merge2Lists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode point = head;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                point.next = l1;
                l1 = l1.next;
            } else {
                point.next = l2;
                l2 = l1;
                l1 = point.next.next;
            }
            point = point.next;
        }
        if (l1 == null) {
            point.next = l2;
        } else {
            point.next = l1;
        }
        return head.next;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(
        self, lists: List[Optional[ListNode]]
    ) -> Optional[ListNode]:
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2

        return lists[0] if amount > 0 else None

    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next

        if not l1:
            point.next = l2
        else:
            point.next = l1

        return head.next
```

</details>
