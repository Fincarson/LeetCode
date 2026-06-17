# 173. Binary Search Tree Iterator

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-search-tree-iterator/)  
`Stack` `Tree` `Design` `Binary Search Tree` `Binary Tree` `Iterator`

**Problem Link:** [LeetCode 173 - Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)

## Problem

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

- BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
- int next() Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

### Example 1

```text
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 0 <= Node.val <= 106
- At most 105 calls will be made to hasNext, and next.

Follow up:

- Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Flatten 2D Vector](https://leetcode.com/problems/flatten-2d-vector/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Peeking Iterator](https://leetcode.com/problems/peeking-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Inorder Successor in BST](https://leetcode.com/problems/inorder-successor-in-bst/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Search Tree Iterator II](https://leetcode.com/problems/binary-search-tree-iterator-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 173. Binary Search Tree Iterator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Flattening the BST | C++, Java, Python3 |
| Controlled Recursion | C++, Java, Python3 |

## Approach 1: Flattening the BST

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// Definition for a binary tree node.
// struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class BSTIterator {
private:
    vector<int> nodesSorted;
    int index;

    void _inorder(TreeNode* root) {
        if (root == nullptr) return;

        this->_inorder(root->left);
        this->nodesSorted.push_back(root->val);
        this->_inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        this->nodesSorted = vector<int>();
        this->index = -1;
        this->_inorder(root);
    }

    /** @return the next smallest number */
    int next() { return this->nodesSorted[++this->index]; }

    /** @return whether we have a next smallest number */
    bool hasNext() { return this->index + 1 < this->nodesSorted.size(); }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {
    ArrayList<Integer> nodesSorted;
    int index;

    public BSTIterator(TreeNode root) {
        // Array containing all the nodes in the sorted order
        this.nodesSorted = new ArrayList<Integer>();

        // Pointer to the next smallest element in the BST
        this.index = -1;

        // Call to flatten the input binary search tree
        this._inorder(root);
    }

    private void _inorder(TreeNode root) {
        if (root == null) {
            return;
        }

        this._inorder(root.left);
        this.nodesSorted.add(root.val);
        this._inorder(root.right);
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        return this.nodesSorted.get(++this.index);
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return this.index + 1 < this.nodesSorted.size();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x: int):
#         self.val = x
#         self.left = None
#         self.right = None


class BSTIterator:

    def __init__(self, root: TreeNode):

        # Array containing all the nodes in the sorted order
        self.nodes_sorted = []

        # Pointer to the next smallest element in the BST
        self.index = -1

        # Call to flatten the input binary search tree
        self._inorder(root)

    def _inorder(self, root: TreeNode) -> None:
        if not root:
            return
        self._inorder(root.left)
        self.nodes_sorted.append(root.val)
        self._inorder(root.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.index += 1
        return self.nodes_sorted[self.index]

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.index + 1 < len(self.nodes_sorted)
```

</details>

<br>

## Approach 2: Controlled Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class BSTIterator {
public:
    stack<TreeNode*> stack;

    BSTIterator(TreeNode* root) {
        // Stack for the recursion simulation
        this->_leftmostInorder(root);
    }

    void _leftmostInorder(TreeNode* root) {
        // For a given node, add all the elements in the leftmost branch of the
        // tree under it to the stack.
        while (root != NULL) {
            this->stack.push(root);
            root = root->left;
        }
    }

    /**
     * @return the next smallest number
     */
    int next() {
        // Node at the top of the stack is the next smallest element
        TreeNode* topmostNode = this->stack.top();
        this->stack.pop();

        // Need to maintain the invariant. If the node has a right child, call
        // the helper function for the right child
        if (topmostNode->right != NULL) {
            this->_leftmostInorder(topmostNode->right);
        }

        return topmostNode->val;
    }

    /**
     * @return whether we have a next smallest number
     */
    bool hasNext() { return !this->stack.empty(); }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {
    Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        // Stack for the recursion simulation
        this.stack = new Stack<TreeNode>();

        // Remember that the algorithm starts with a call to the helper function
        // with the root node as the input
        this._leftmostInorder(root);
    }

    private void _leftmostInorder(TreeNode root) {
        // For a given node, add all the elements in the leftmost branch of the tree
        // under it to the stack.
        while (root != null) {
            this.stack.push(root);
            root = root.left;
        }
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        // Node at the top of the stack is the next smallest element
        TreeNode topmostNode = this.stack.pop();

        // Need to maintain the invariant. If the node has a right child, call the
        // helper function for the right child
        if (topmostNode.right != null) {
            this._leftmostInorder(topmostNode.right);
        }

        return topmostNode.val;
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return this.stack.size() > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x: int):
#         self.val = x
#         self.left = None
#         self.right = None


class BSTIterator:

    def __init__(self, root: TreeNode) -> None:

        # Stack for the recursion simulation
        self.stack = []

        # Remember that the algorithm starts with a call to the helper function
        # with the root node as the input
        self._leftmost_inorder(root)

    def _leftmost_inorder(self, root: TreeNode) -> None:

        # For a given node, add all the elements in the leftmost branch of the tree
        # under it to the stack.
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        # Node at the top of the stack is the next smallest element
        topmost_node = self.stack.pop()

        # Need to maintain the invariant. If the node has a right child, call the
        # helper function for the right child
        if topmost_node.right:
            self._leftmost_inorder(topmost_node.right)
        return topmost_node.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) > 0
```

</details>
