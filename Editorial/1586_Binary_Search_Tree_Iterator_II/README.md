# 1586. Binary Search Tree Iterator II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-search-tree-iterator-ii/)  
`Stack` `Tree` `Design` `Binary Search Tree` `Binary Tree` `Iterator`

**Problem Link:** [LeetCode 1586 - Binary Search Tree Iterator II](https://leetcode.com/problems/binary-search-tree-iterator-ii/)

## Problem

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

- BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
- int next() Moves the pointer to the right, then returns the number at the pointer.
- boolean hasPrev() Returns true if there exists a number in the traversal to the left of the pointer, otherwise returns false.
- int prev() Moves the pointer to the left, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() and prev() calls will always be valid. That is, there will be at least a next/previous number in the in-order traversal when next()/prev() is called.

### Example 1

```text
Input
["BSTIterator", "next", "next", "prev", "next", "hasNext", "next", "next", "next", "hasNext", "hasPrev", "prev", "prev"]
[[[7, 3, 15, null, null, 9, 20]], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null], [null]]
Output
[null, 3, 7, 3, 7, true, 9, 15, 20, false, true, 15, 9]

Explanation
// The underlined element is where the pointer currently is.
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]); // state is   [3, 7, 9, 15, 20]
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 3
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 7
bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 3
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 7
bSTIterator.hasNext(); // return true
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 9
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 15
bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 20
bSTIterator.hasNext(); // return false
bSTIterator.hasPrev(); // return true
bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 15
bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 9
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 0 <= Node.val <= 106
- At most 105 calls will be made to hasNext, next, hasPrev, and prev.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1586. Binary Search Tree Iterator II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Flatten Binary Search Tree: Recursive Inorder Traversal | Java, Python3 |
| Follow-up: Iterative Inorder Traversal | Java, Python3 |

## Approach 1: Flatten Binary Search Tree: Recursive Inorder Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class BSTIterator {

    List<Integer> arr = new ArrayList();
    int pointer;
    int n;
    
    public void inorder(TreeNode r, List<Integer> arr) {
        if (r == null) return;
        inorder(r.left, arr);
        arr.add(r.val);
        inorder(r.right, arr);
    }

    public BSTIterator(TreeNode root) {
        inorder(root, arr);
        n = arr.size();
        pointer = -1;
    }
    
    public boolean hasNext() {
        return pointer < n - 1;
    }
    
    public int next() {
        ++pointer;
        return arr.get(pointer);
    }
    
    public boolean hasPrev() {
        return pointer > 0;
    }
    
    public int prev() {
        --pointer;
        return arr.get(pointer);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class BSTIterator:

    def __init__(self, root: TreeNode):
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        self.arr = inorder(root)
        self.n = len(self.arr)
        self.pointer = -1

    def hasNext(self) -> bool:
        return self.pointer < self.n - 1

    def next(self) -> int:
        self.pointer += 1
        return self.arr[self.pointer]

    def hasPrev(self) -> bool:
        return self.pointer > 0

    def prev(self) -> int:
        self.pointer -= 1
        return self.arr[self.pointer]
```

</details>

<br>

## Approach 2: Follow-up: Iterative Inorder Traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class BSTIterator {

    Deque<TreeNode> stack;
    List<Integer> arr;
    TreeNode last;
    int pointer;

    public BSTIterator(TreeNode root) {
        last = root;
        stack = new ArrayDeque();
        arr = new ArrayList();
        pointer = -1;
    }
    
    public boolean hasNext() {
        return !stack.isEmpty() || last != null || pointer < arr.size() - 1;
    }
    
    public int next() {
        ++pointer;
        // if the pointer is out of precomputed range
        if (pointer == arr.size()) {
            // process all predecessors of the last node:
            // go left till you can and then one step right
            while (last != null) {
                stack.push(last);
                last = last.left;                
            }
            TreeNode curr = stack.pop();
            last = curr.right;
        
            arr.add(curr.val);
        }
            
        return arr.get(pointer);
    }
    
    public boolean hasPrev() {
        return pointer > 0;
    }
    
    public int prev() {
        --pointer;
        return arr.get(pointer);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.last = root
        self.stack, self.arr = [], []
        self.pointer = -1

    def hasNext(self) -> bool:
        return self.stack or self.last or self.pointer < len(self.arr) - 1

    def next(self) -> int:
        self.pointer += 1
        
        # if the pointer is out of precomputed range
        if self.pointer == len(self.arr):
            # process all predecessors of the last node:
            # go left till you can and then one step right
            while self.last:
                self.stack.append(self.last)
                self.last = self.last.left
            curr = self.stack.pop()
            self.last = curr.right
        
            self.arr.append(curr.val)
            
        return self.arr[self.pointer]

    def hasPrev(self) -> bool:
        return self.pointer > 0

    def prev(self) -> int:
        self.pointer -= 1
        return self.arr[self.pointer]
```

</details>
