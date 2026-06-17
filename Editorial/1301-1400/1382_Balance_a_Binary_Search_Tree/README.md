# 1382. Balance a Binary Search Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/balance-a-binary-search-tree/)  
`Divide and Conquer` `Greedy` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 1382 - Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

## Problem

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

### Example 1

```text
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
```

### Example 2

```text
Input: root = [2,1,3]
Output: [2,1,3]
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1382. Balance a Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Inorder Traversal + Recursive Construction | C++, Java, Python3 |
| Day-Stout-Warren Algorithm / In-Place Balancing | C++, Java, Python3 |

## Approach 1: Inorder Traversal + Recursive Construction

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        // Create a vector to store the inorder traversal of the BST
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int size = inorder.size();

        // Construct and return the balanced BST
        return createBalancedBST(inorder, 0, size - 1);
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        // Perform an inorder traversal to store the elements in sorted order
        if (root == nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* createBalancedBST(const vector<int>& inorder, int start,
                                int end) {
        // Base case: if the start index is greater than the end index, return
        // nullptr
        if (start > end) return nullptr;

        // Find the middle element of the current range
        int mid = start + (end - start) / 2;

        // Recursively construct the left and right subtrees
        TreeNode* leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode* rightSubtree = createBalancedBST(inorder, mid + 1, end);

        // Create a new node with the middle element and attach the subtrees
        return new TreeNode(inorder[mid], leftSubtree, rightSubtree);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode balanceBST(TreeNode root) {
        // Create a list to store the inorder traversal of the BST
        List<Integer> inorder = new ArrayList<>();
        inorderTraversal(root, inorder);

        // Construct and return the balanced BST
        return createBalancedBST(inorder, 0, inorder.size() - 1);
    }

    private void inorderTraversal(TreeNode root, List<Integer> inorder) {
        // Perform an inorder traversal to store the elements in sorted order
        if (root == null) return;
        inorderTraversal(root.left, inorder);
        inorder.add(root.val);
        inorderTraversal(root.right, inorder);
    }

    private TreeNode createBalancedBST(
        List<Integer> inorder,
        int start,
        int end
    ) {
        // Base case: if the start index is greater than the end index, return null
        if (start > end) return null;

        // Find the middle element of the current range
        int mid = start + (end - start) / 2;

        // Recursively construct the left and right subtrees
        TreeNode leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode rightSubtree = createBalancedBST(inorder, mid + 1, end);

        // Create a new node with the middle element and attach the subtrees
        TreeNode node = new TreeNode(
            inorder.get(mid),
            leftSubtree,
            rightSubtree
        );
        return node;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        # Create a list to store the inorder traversal of the BST
        inorder = []
        self.inorder_traversal(root, inorder)

        # Construct and return the balanced BST
        return self.create_balanced_bst(inorder, 0, len(inorder) - 1)

    def inorder_traversal(self, root: TreeNode, inorder: list):
        # Perform an inorder traversal to store the elements in sorted order
        if not root:
            return
        self.inorder_traversal(root.left, inorder)
        inorder.append(root.val)
        self.inorder_traversal(root.right, inorder)

    def create_balanced_bst(
        self, inorder: list, start: int, end: int
    ) -> TreeNode:
        # Base case: if the start index is greater than the end index, return None
        if start > end:
            return None

        # Find the middle element of the current range
        mid = start + (end - start) // 2

        # Recursively construct the left and right subtrees
        left_subtree = self.create_balanced_bst(inorder, start, mid - 1)
        right_subtree = self.create_balanced_bst(inorder, mid + 1, end)

        # Create a new node with the middle element and attach the subtrees
        node = TreeNode(inorder[mid], left_subtree, right_subtree)
        return node
```

</details>

<br>

## Approach 2: Day-Stout-Warren Algorithm / In-Place Balancing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;

        // Step 1: Create the backbone (vine)
        // Temporary dummy node
        TreeNode* vineHead = new TreeNode(0);
        vineHead->right = root;
        TreeNode* current = vineHead;
        while (current->right) {
            if (current->right->left) {
                rightRotate(current, current->right);
            } else {
                current = current->right;
            }
        }

        // Step 2: Count the nodes
        int nodeCount = 0;
        current = vineHead->right;
        while (current) {
            ++nodeCount;
            current = current->right;
        }

        // Step 3: Create a balanced BST
        int m = pow(2, floor(log2(nodeCount + 1))) - 1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1) {
            m /= 2;
            makeRotations(vineHead, m);
        }

        TreeNode* balancedRoot = vineHead->right;
        // Delete the temporary dummy node
        delete vineHead;
        return balancedRoot;
    }

private:
    // Function to perform a right rotation
    void rightRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }

    // Function to perform a left rotation
    void leftRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        parent->right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode* vineHead, int count) {
        TreeNode* current = vineHead;
        for (int i = 0; i < count; ++i) {
            TreeNode* tmp = current->right;
            leftRotate(current, tmp);
            current = current->right;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode balanceBST(TreeNode root) {
        if (root == null) return null;

        // Step 1: Create the backbone (vine)
        // Temporary dummy node
        TreeNode vineHead = new TreeNode(0);
        vineHead.right = root;
        TreeNode current = vineHead;
        while (current.right != null) {
            if (current.right.left != null) {
                rightRotate(current, current.right);
            } else {
                current = current.right;
            }
        }

        // Step 2: Count the nodes
        int nodeCount = 0;
        current = vineHead.right;
        while (current != null) {
            ++nodeCount;
            current = current.right;
        }

        // Step 3: Create a balanced BST
        int m =
            (int) Math.pow(
                2,
                Math.floor(Math.log(nodeCount + 1) / Math.log(2))
            ) -
            1;
        makeRotations(vineHead, nodeCount - m);
        while (m > 1) {
            m /= 2;
            makeRotations(vineHead, m);
        }

        TreeNode balancedRoot = vineHead.right;
        return balancedRoot;
    }

    // Function to perform a right rotation
    private void rightRotate(TreeNode parent, TreeNode node) {
        TreeNode tmp = node.left;
        node.left = tmp.right;
        tmp.right = node;
        parent.right = tmp;
    }

    // Function to perform a left rotation
    private void leftRotate(TreeNode parent, TreeNode node) {
        TreeNode tmp = node.right;
        node.right = tmp.left;
        tmp.left = node;
        parent.right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    private void makeRotations(TreeNode vineHead, int count) {
        TreeNode current = vineHead;
        for (int i = 0; i < count; ++i) {
            TreeNode tmp = current.right;
            leftRotate(current, tmp);
            current = current.right;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return None

        # Step 1: Create the backbone (vine)
        # Temporary dummy node
        vine_head = TreeNode(0)
        vine_head.right = root
        current = vine_head
        while current.right:
            if current.right.left:
                self.right_rotate(current, current.right)
            else:
                current = current.right

        # Step 2: Count the nodes
        node_count = 0
        current = vine_head.right
        while current:
            node_count += 1
            current = current.right

        # Step 3: Create a balanced BST
        m = 2 ** math.floor(math.log2(node_count + 1)) - 1
        self.make_rotations(vine_head, node_count - m)
        while m > 1:
            m //= 2
            self.make_rotations(vine_head, m)

        balanced_root = vine_head.right
        # Delete the temporary dummy node
        vine_head = None
        return balanced_root

    # Function to perform a right rotation
    def right_rotate(self, parent: TreeNode, node: TreeNode):
        tmp = node.left
        node.left = tmp.right
        tmp.right = node
        parent.right = tmp

    # Function to perform a left rotation
    def left_rotate(self, parent: TreeNode, node: TreeNode):
        tmp = node.right
        node.right = tmp.left
        tmp.left = node
        parent.right = tmp

    # Function to perform a series of left rotations to balance the vine
    def make_rotations(self, vine_head: TreeNode, count: int):
        current = vine_head
        for _ in range(count):
            tmp = current.right
            self.left_rotate(current, tmp)
            current = current.right
```

</details>
