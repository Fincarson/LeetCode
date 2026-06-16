# 109. Convert Sorted List to Binary Search Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)  
`Linked List` `Divide and Conquer` `Tree` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 109 - Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## Problem

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

### Example 1

```text
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
```

### Example 2

```text
Input: head = []
Output: []
```

## Constraints

- The number of nodes in head is in the range [0, 2 * 104].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Create Binary Tree From Descriptions](https://leetcode.com/problems/create-binary-tree-from-descriptions/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 109. Convert Sorted List to Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion + Conversion to Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Inorder Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct ListNode* FindMiddle(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL) prev->next = NULL;
    return slow;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* mid = FindMiddle(head);
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = mid->val;
    if (head == mid) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    return node;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddleElement(ListNode* head) {
        // The pointer used to disconnect the left half from the mid node.
        ListNode* prevPtr = nullptr;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        // Iterate until fastPr doesn't reach the end of the linked list.
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        // Handling the case when slowPtr was equal to head.
        if (prevPtr != nullptr) {
            prevPtr->next = nullptr;
        }
        return slowPtr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // If the head doesn't exist, then the linked list is empty
        if (head == nullptr) {
            return nullptr;
        }
        // Find the middle element for the list.
        ListNode* mid = this->findMiddleElement(head);
        // The mid becomes the root of the BST.
        TreeNode* node = new TreeNode(mid->val);
        // Base case when there is just one element in the linked list
        if (head == mid) {
            return node;
        }
        // Recursively form balanced BSTs using the left and right halves of the
        // original list.
        node->left = this->sortedListToBST(head);
        node->right = this->sortedListToBST(mid->next);
        return node;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 *
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode SortedListToBST(ListNode head) {
        if (head == null)
            return null;
        ListNode mid = FindMiddleElement(head);
        TreeNode node = new TreeNode(mid.val);
        if (head == mid)
            return node;
        node.left = this.SortedListToBST(head);
        node.right = this.SortedListToBST(mid.next);
        return node;
    }

    private ListNode FindMiddleElement(ListNode head) {
        ListNode prevPtr = null;
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        while (fastPtr != null && fastPtr.next != null) {
            prevPtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }

        if (prevPtr != null)
            prevPtr.next = null;
        return slowPtr;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 *
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    mid := findMiddleElement(head)
    node := &TreeNode{
        Val: mid.Val,
    }
    if head == mid {
        return node
    }
    node.Left = sortedListToBST(head)
    node.Right = sortedListToBST(mid.Next)
    return node
}

func findMiddleElement(head *ListNode) *ListNode {
    var prevPtr *ListNode = nil
    slowPtr := head
    fastPtr := head
    for fastPtr != nil && fastPtr.Next != nil {
        prevPtr = slowPtr
        slowPtr = slowPtr.Next
        fastPtr = fastPtr.Next.Next
    }
    if prevPtr != nil {
        prevPtr.Next = nil
    }
    return slowPtr
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private ListNode findMiddleElement(ListNode head) {
        // The pointer used to disconnect the left half from the mid node.
        ListNode prevPtr = null;
        ListNode slowPtr = head;
        ListNode fastPtr = head;

        // Iterate until fastPr doesn't reach the end of the linked list.
        while (fastPtr != null && fastPtr.next != null) {
            prevPtr = slowPtr;
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
        }

        // Handling the case when slowPtr was equal to head.
        if (prevPtr != null) {
            prevPtr.next = null;
        }

        return slowPtr;
    }

    public TreeNode sortedListToBST(ListNode head) {
        // If the head doesn't exist, then the linked list is empty
        if (head == null) {
            return null;
        }

        // Find the middle element for the list.
        ListNode mid = this.findMiddleElement(head);

        // The mid becomes the root of the BST.
        TreeNode node = new TreeNode(mid.val);

        // Base case when there is just one element in the linked list
        if (head == mid) {
            return node;
        }

        // Recursively form balanced BSTs using the left and right halves of the original list.
        node.left = this.sortedListToBST(head);
        node.right = this.sortedListToBST(mid.next);
        return node;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 *
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var sortedListToBST = function (head) {
    if (!head) return null;
    var mid = findMiddleElement(head);
    var node = new TreeNode(mid.val);
    if (head === mid) return node;
    node.left = sortedListToBST(head);
    node.right = sortedListToBST(mid.next);
    return node;
};
var findMiddleElement = function (head) {
    var prevPtr = null;
    var slowPtr = head;
    var fastPtr = head;
    while (fastPtr && fastPtr.next) {
        prevPtr = slowPtr;
        slowPtr = slowPtr.next;
        fastPtr = fastPtr.next.next;
    }
    if (prevPtr != null) prevPtr.next = null;
    return slowPtr;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x: int):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x: int):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def findMiddle(self, head: ListNode) -> ListNode:

        # The pointer used to disconnect the left half from the mid node.
        prevPtr = None
        slowPtr = head
        fastPtr = head

        # Iterate until fastPr doesn't reach the end of the linked list.
        while fastPtr and fastPtr.next:
            prevPtr = slowPtr
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next

        # Handling the case when slowPtr was equal to head.
        if prevPtr:
            prevPtr.next = None

        return slowPtr

    def sortedListToBST(self, head: ListNode) -> TreeNode:

        # If the head doesn't exist, then the linked list is empty
        if not head:
            return None

        # Find the middle element for the list.
        mid = self.findMiddle(head)

        # The mid becomes the root of the BST.
        node = TreeNode(mid.val)

        # Base case when there is just one element in the linked list
        if head == mid:
            return node

        # Recursively form balanced BSTs using the left and right halves of the original list.
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(mid.next)
        return node
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for singly-linked list.
 * class ListNode { constructor(public val: number, public next: ListNode | null = null) { } }
 *
 * Definition for a binary tree node.
 * class TreeNode { constructor(public val: number, public left: TreeNode | null = null, public right: TreeNode | null = null) { } }
 */
function sortedListToBST(head: ListNode | null): TreeNode | null {
    if (!head) {
        return null;
    }
    const mid = findMiddleElement(head);
    const node: TreeNode = new TreeNode(mid.val);
    if (head === mid) {
        return node;
    }
    node.left = sortedListToBST(head);
    node.right = sortedListToBST(mid.next);
    return node;
}
function findMiddleElement(head: ListNode | null): ListNode | null {
    let prevPtr: ListNode | null = null;
    let slowPtr: ListNode | null = head;
    let fastPtr: ListNode | null = head;
    while (fastPtr !== null && fastPtr.next !== null) {
        prevPtr = slowPtr;
        slowPtr = slowPtr !== null ? slowPtr.next : null;
        fastPtr =
            fastPtr !== null && fastPtr.next !== null
                ? fastPtr.next.next
                : null;
    }
    if (prevPtr !== null) {
        prevPtr.next = null;
    }
    return slowPtr;
}
```

</details>

<br>

## Approach 2: Recursion + Conversion to Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };
//
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
int* mapListToValues(struct ListNode* head, int* size) {
    int* values = NULL;
    *size = 0;
    while (head != NULL) {
        values = (int*)realloc(values, (*size + 1) * sizeof(int));
        values[(*size)++] = head->val;
        head = head->next;
    }
    return values;
}
struct TreeNode* convertListToBST(int* values, int left, int right) {
    // Invalid case
    if (left > right) {
        return NULL;
    }
    // Middle element forms the root.
    int mid = (left + right) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = values[mid];
    // Base case for when there is only one element left in the array
    if (left == right) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    // Recursively form BST on the two halves
    node->left = convertListToBST(values, left, mid - 1);
    node->right = convertListToBST(values, mid + 1, right);
    return node;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size;
    int* values = mapListToValues(head, &size);
    return convertListToBST(values, 0, size - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
private:
    vector<int> values;
    void mapListToValues(ListNode* head) {
        while (head != nullptr) {
            this->values.push_back(head->val);
            head = head->next;
        }
    }
    TreeNode* convertListToBST(int left, int right) {
        // Invalid case
        if (left > right) {
            return nullptr;
        }
        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(this->values[mid]);
        // Base case for when there is only one element left in the array
        if (left == right) {
            return node;
        }
        // Recursively form BST on the two halves
        node->left = this->convertListToBST(left, mid - 1);
        node->right = this->convertListToBST(mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Form an array out of the given linked list and then
        // use the array to form the BST.
        this->mapListToValues(head);
        // Convert the array to
        return this->convertListToBST(0, this->values.size() - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private List<int> values = new List<int>();

    private void MapListToValues(ListNode head) {
        while (head != null) {
            this.values.Add(head.val);
            head = head.next;
        }
    }

    private TreeNode ConvertListToBST(int left, int right) {
        // Invalid case
        if (left > right) {
            return null;
        }

        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(this.values[mid]);
        // Base case for when there is only one element left in the array
        if (left == right) {
            return node;
        }

        // Recursively form BST on the two halves
        node.left = this.ConvertListToBST(left, mid - 1);
        node.right = this.ConvertListToBST(mid + 1, right);
        return node;
    }

    public TreeNode SortedListToBST(ListNode head) {
        // Form an array out of the given linked list and then
        // use the array to form the BST.
        this.MapListToValues(head);
        // Convert the array to
        return this.ConvertListToBST(0, this.values.Count - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func sortedListToBST(head *ListNode) *TreeNode {
    // Convert the given linked list to an array
    values := []int{}
    for head != nil {
        values = append(values, head.Val)
        head = head.Next
    }
    var convertListToBST func(int, int) *TreeNode
    convertListToBST = func(l int, r int) *TreeNode {
        // Invalid case
        if l > r {
            return nil
        }
        // Middle element forms the root.
        mid := (l + r) / 2
        node := &TreeNode{Val: values[mid]}
        // Base case for when there is only one element left in the array
        if l == r {
            return node
        }
        // Recursively form BST on the two halves
        node.Left = convertListToBST(l, mid-1)
        node.Right = convertListToBST(mid+1, r)
        return node
    }
    return convertListToBST(0, len(values)-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private List<Integer> values;

    public Solution() {
        this.values = new ArrayList<Integer>();
    }

    private void mapListToValues(ListNode head) {
        while (head != null) {
            this.values.add(head.val);
            head = head.next;
        }
    }

    private TreeNode convertListToBST(int left, int right) {
        // Invalid case
        if (left > right) {
            return null;
        }

        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(this.values.get(mid));

        // Base case for when there is only one element left in the array
        if (left == right) {
            return node;
        }

        // Recursively form BST on the two halves
        node.left = convertListToBST(left, mid - 1);
        node.right = convertListToBST(mid + 1, right);
        return node;
    }

    public TreeNode sortedListToBST(ListNode head) {
        // Form an array out of the given linked list and then
        // use the array to form the BST.
        this.mapListToValues(head);

        // Convert the array to
        return convertListToBST(0, this.values.size() - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function sortedListToBST(head) {
    // Convert the given linked list to an array
    let values = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }
    function convertListToBST(l, r) {
        // Invalid case
        if (l > r) {
            return null;
        }
        // Middle element forms the root.
        let mid = Math.floor((l + r) / 2);
        // Base case for when there is only one element left in the array
        let node = new TreeNode(values[mid]);
        if (l == r) {
            return node;
        }
        // Recursively form BST on the two halves
        node.left = convertListToBST(l, mid - 1);
        node.right = convertListToBST(mid + 1, r);
        return node;
    }
    // Form a BST out of the given array and then return the root of the newly formed BST
    return convertListToBST(0, values.length - 1);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # Convert the given linked list to an array
    def mapListToValues(self, head: ListNode) -> list:
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        return vals

    def sortedListToBST(self, head: ListNode) -> TreeNode:

        # Form an array out of the given linked list and then
        # use the array to form the BST.
        values = self.mapListToValues(head)

        # l and r represent the start and end of the given array
        def convertListToBST(l: int, r: int) -> TreeNode:

            # Invalid case
            if l > r:
                return None

            # Middle element forms the root.
            mid = (l + r) // 2
            node = TreeNode(values[mid])

            # Base case for when there is only one element left in the array
            if l == r:
                return node

            # Recursively form BST on the two halves
            node.left = convertListToBST(l, mid - 1)
            node.right = convertListToBST(mid + 1, r)
            return node

        return convertListToBST(0, len(values) - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function sortedListToBST(head: ListNode): TreeNode | null {
    // Convert the given linked list to an array
    let values: number[] = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }
    function convertListToBST(l: number, r: number): TreeNode | null {
        // Invalid case
        if (l > r) {
            return null;
        }
        // Middle element forms the root.
        let mid = Math.floor((l + r) / 2);
        let node = new TreeNode(values[mid]);
        // Base case for when there is only one element left in the array
        if (l == r) {
            return node;
        }
        // Recursively form BST on the two halves
        node.left = convertListToBST(l, mid - 1);
        node.right = convertListToBST(mid + 1, r);
        return node;
    }
    return convertListToBST(0, values.length - 1);
}
```

</details>

<br>

## Approach 3: Inorder Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* head;
int findSize(struct ListNode* head) {
    struct ListNode* ptr = head;
    int c = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        c += 1;
    }
    return c;
}
struct TreeNode* convertListToBST(int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    struct TreeNode* left = convertListToBST(l, mid - 1);
    if (head == NULL) return NULL;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = head->val;
    node->left = left;
    head = head->next;
    node->right = convertListToBST(mid + 1, r);
    return node;
}
struct TreeNode* sortedListToBST(struct ListNode* h) {
    head = h;
    int size = findSize(head);
    return convertListToBST(0, size - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head;
    int findSize(ListNode* head) {
        ListNode* ptr = head;
        int c = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            c += 1;
        }
        return c;
    }
    TreeNode* convertListToBST(int l, int r) {
        // Invalid case
        if (l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;
        // First step of simulated inorder traversal. Recursively form
        // the left half
        TreeNode* left = this->convertListToBST(l, mid - 1);
        // Once left half is traversed, process the current node
        TreeNode* node = new TreeNode(this->head->val);
        node->left = left;
        // Maintain the invariance mentioned in the algorithm
        this->head = this->head->next;
        // Recurse on the right hand side and form BST out of them
        node->right = this->convertListToBST(mid + 1, r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // Get the size of the linked list first
        int size = this->findSize(head);
        this->head = head;
        // Form the BST now that we know the size
        return convertListToBST(0, size - 1);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 *
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private ListNode head;

    private int findSize(ListNode head) {
        ListNode ptr = head;
        int c = 0;
        while (ptr != null) {
            ptr = ptr.next;
            c += 1;
        }

        return c;
    }

    private TreeNode convertListToBST(int l, int r) {
        if (l > r)
            return null;
        int mid = (l + r) / 2;
        TreeNode left = this.convertListToBST(l, mid - 1);
        TreeNode node = new TreeNode(this.head.val);
        node.left = left;
        this.head = this.head.next;
        node.right = this.convertListToBST(mid + 1, r);
        return node;
    }

    public TreeNode SortedListToBST(ListNode head) {
        int size = this.findSize(head);
        this.head = head;
        return convertListToBST(0, size - 1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 *
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var head *ListNode

func findSize(head *ListNode) int {
    ptr := head
    c := 0
    for ptr != nil {
        ptr = ptr.Next
        c += 1
    }
    return c
}

func convertListToBST(l int, r int) *TreeNode {
    if l > r {
        return nil
    }
    mid := (l + r) / 2
    left := convertListToBST(l, mid-1)
    var node *TreeNode
    if head != nil {
        node = &TreeNode{Val: head.Val}
        node.Left = left
        head = head.Next
        node.Right = convertListToBST(mid+1, r)
    }
    return node
}

func sortedListToBST(headParam *ListNode) *TreeNode {
    size := findSize(headParam)
    head = headParam
    return convertListToBST(0, size-1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode(int x) { val = x; } }
 */
class Solution {
    private ListNode head;

    private int findSize(ListNode head) {
        ListNode ptr = head;
        int c = 0;
        while (ptr != null) {
            ptr = ptr.next;
            c += 1;
        }
        return c;
    }

    private TreeNode convertListToBST(int l, int r) {
        // Invalid case
        if (l > r) {
            return null;
        }

        int mid = (l + r) / 2;

        // First step of simulated inorder traversal. Recursively form
        // the left half
        TreeNode left = this.convertListToBST(l, mid - 1);

        // Once left half is traversed, process the current node
        TreeNode node = new TreeNode(this.head.val);
        node.left = left;

        // Maintain the invariance mentioned in the algorithm
        this.head = this.head.next;

        // Recurse on the right hand side and form BST out of them
        node.right = this.convertListToBST(mid + 1, r);
        return node;
    }

    public TreeNode sortedListToBST(ListNode head) {
        // Get the size of the linked list first
        int size = this.findSize(head);

        this.head = head;

        // Form the BST now that we know the size
        return convertListToBST(0, size - 1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var sortedListToBST = function (head) {
    var findSize = function (head) {
        let ptr = head,
            c = 0;
        while (ptr !== null) {
            ptr = ptr.next;
            c += 1;
        }
        return c;
    };
    var convertListToBST = function (l, r) {
        if (l > r) return null;
        let mid = Math.floor((l + r) / 2);
        let left = convertListToBST(l, mid - 1);
        let node = new TreeNode(head.val);
        node.left = left;
        head = head.next;
        node.right = convertListToBST(mid + 1, r);
        return node;
    };
    let size = findSize(head);
    return convertListToBST(0, size - 1);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    def findSize(self, head: ListNode) -> int:
        ptr = head
        c = 0
        while ptr:
            ptr = ptr.next
            c += 1
        return c

    def sortedListToBST(self, head: ListNode) -> TreeNode:

        # Get the size of the linked list first
        size = self.findSize(head)

        # Recursively form a BST out of linked list from l --> r
        def convert(l: int, r: int) -> TreeNode:
            nonlocal head

            # Invalid case
            if l > r:
                return None

            mid = (l + r) // 2

            # First step of simulated inorder traversal. Recursively form
            # the left half
            left = convert(l, mid - 1)

            # Once left half is traversed, process the current node
            node = TreeNode(head.val)
            node.left = left

            # Maintain the invariance mentioned in the algorithm
            head = head.next

            # Recurse on the right hand side and form BST out of them
            node.right = convert(mid + 1, r)
            return node

        return convert(0, size - 1)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 *
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */
function sortedListToBST(head: ListNode | null): TreeNode | null {
    let currentNode = head;
    let findSize = function (head: ListNode | null): number {
        let ptr = head,
            c = 0;
        while (ptr) {
            ptr = ptr.next;
            c++;
        }
        return c;
    };
    let convert = function (l: number, r: number): TreeNode | null {
        if (l > r) return null;
        let mid = Math.floor((l + r) / 2);
        let left = convert(l, mid - 1);
        let node = new TreeNode(currentNode.val);
        node.left = left;
        currentNode = currentNode.next;
        node.right = convert(mid + 1, r);
        return node;
    };
    let size = findSize(head);
    return convert(0, size - 1);
}
```

</details>
