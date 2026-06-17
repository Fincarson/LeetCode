# 889. Construct Binary Tree from Preorder and Postorder Traversal

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)  
`Array` `Hash Table` `Divide and Conquer` `Tree` `Binary Tree`

**Problem Link:** [LeetCode 889 - Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

## Problem

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

### Example 1

```text
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
```

### Example 2

```text
Input: preorder = [1], postorder = [1]
Output: [1]
```

## Constraints

- 1 <= preorder.length <= 30
- 1 <= preorder[i] <= preorder.length
- All the values of preorder are unique.
- postorder.length == preorder.length
- 1 <= postorder[i] <= postorder.length
- All the values of postorder are unique.
- It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 889. Construct Binary Tree from Preorder and Postorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide and Conquer | C++, Java, Python3 |
| Using Index Array | C++, Java, Python3 |
| Optimized Recursion | C++, Java, Python3 |

## Approach 1: Divide and Conquer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int numOfNodes = preorder.size();
        return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
    }

private:
    // Helper function to construct the tree recursively
    TreeNode* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder, vector<int>& postorder) {
        // Base case: If there are no nodes to process, return NULL
        if (preStart > preEnd) return NULL;

        // Base case: If only one node is left, return that node
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // The left child root in preorder traversal (next element after root)
        int leftRoot = preorder[preStart + 1];

        // Calculate the number of nodes in the left subtree by searching in
        // postorder
        int numOfNodesInLeft = 1;
        while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot) {
            numOfNodesInLeft++;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        // Recursively construct the left subtree
        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, postorder);

        // Recursively construct the right
        root->right =
            constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                          postStart + numOfNodesInLeft, preorder, postorder);

        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int numOfNodes = preorder.length;
        return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
    }

    // Helper function to construct the tree recursively
    private TreeNode constructTree(
        int preStart,
        int preEnd,
        int postStart,
        int[] preorder,
        int[] postorder
    ) {
        // Base case: If there are no nodes to process, return null
        if (preStart > preEnd) return null;

        // Base case: If only one node is left, return that node
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // The left child root in preorder traversal (next element after root)
        int leftRoot = preorder[preStart + 1];

        // Calculate the number of nodes in the left subtree by searching in postorder
        int numOfNodesInLeft = 1;
        while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot) {
            numOfNodesInLeft++;
        }

        TreeNode root = new TreeNode(preorder[preStart]);

        // Recursively construct the left subtree
        root.left = constructTree(
            preStart + 1,
            preStart + numOfNodesInLeft,
            postStart,
            preorder,
            postorder
        );

        // Recursively construct the right subtree
        root.right = constructTree(
            preStart + numOfNodesInLeft + 1,
            preEnd,
            postStart + numOfNodesInLeft,
            preorder,
            postorder
        );

        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        num_of_nodes = len(preorder)
        return self._construct_tree(0, num_of_nodes - 1, 0, preorder, postorder)

    # Helper function to construct the tree recursively
    def _construct_tree(
        self,
        pre_start: int,
        pre_end: int,
        post_start: int,
        preorder: List[int],
        postorder: List[int],
    ) -> Optional[TreeNode]:
        # Base case: If there are no nodes to process, return None
        if pre_start > pre_end:
            return None

        # Base case: If only one node is left, return that node
        if pre_start == pre_end:
            return TreeNode(preorder[pre_start])

        # The left child root in preorder traversal (next element after root)
        left_root = preorder[pre_start + 1]

        # Calculate the number of nodes in the left subtree by searching in postorder
        num_of_nodes_in_left = 1
        while postorder[post_start + num_of_nodes_in_left - 1] != left_root:
            num_of_nodes_in_left += 1

        root = TreeNode(preorder[pre_start])

        # Recursively construct the left subtree
        root.left = self._construct_tree(
            pre_start + 1,
            pre_start + num_of_nodes_in_left,
            post_start,
            preorder,
            postorder,
        )

        # Recursively construct the right subtree
        root.right = self._construct_tree(
            pre_start + num_of_nodes_in_left + 1,
            pre_end,
            post_start + num_of_nodes_in_left,
            preorder,
            postorder,
        )

        return root
```

</details>

<br>

## Approach 2: Using Index Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int numOfNodes = preorder.size();

        // Create the index array of `postorder`
        vector<int> indexInPostorder(numOfNodes + 1);
        for (int index = 0; index < numOfNodes; index++) {
            // Store the index of the current element
            indexInPostorder[postorder[index]] = index;
        }

        return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostorder);
    }

private:
    // Helper function to construct the tree recursively
    TreeNode* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder,
                            vector<int>& indexInPostorder) {
        // Base case: If there are no nodes to process, return NULL
        if (preStart > preEnd) return NULL;

        // Base case: If only one node is left, return that node
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // The left child root in preorder traversal (next element after root)
        int leftRoot = preorder[preStart + 1];

        // Calculate the number of nodes in the left subtree by searching in
        // postorder
        int numOfNodesInLeft = indexInPostorder[leftRoot] - postStart + 1;

        TreeNode* root = new TreeNode(preorder[preStart]);

        // Recursively construct the left subtree
        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, indexInPostorder);

        // Recursively construct the right
        root->right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                                    postStart + numOfNodesInLeft, preorder,
                                    indexInPostorder);

        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int numOfNodes = preorder.length;

        // Create the index array for `postorder`
        int[] indexInPostOrder = new int[numOfNodes + 1];
        for (int index = 0; index < numOfNodes; index++) {
            // Store the index of the current element
            indexInPostOrder[postorder[index]] = index;
        }

        return constructTree(0, numOfNodes - 1, 0, preorder, indexInPostOrder);
    }

    // Helper function to construct the tree recursively
    private TreeNode constructTree(
        int preStart,
        int preEnd,
        int postStart,
        int[] preorder,
        int[] indexInPostOrder
    ) {
        // Base case: If there are no nodes to process, return null
        if (preStart > preEnd) return null;

        // Base case: If only one node is left, return that node
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // The left child root in preorder traversal (next element after root)
        int leftRoot = preorder[preStart + 1];

        // Calculate the number of nodes in the left subtree by searching in postorder
        int numOfNodesInLeft = indexInPostOrder[leftRoot] - postStart + 1;

        TreeNode root = new TreeNode(preorder[preStart]);

        // Recursively construct the left subtree
        root.left = constructTree(
            preStart + 1,
            preStart + numOfNodesInLeft,
            postStart,
            preorder,
            indexInPostOrder
        );

        // Recursively construct the right subtree
        root.right = constructTree(
            preStart + numOfNodesInLeft + 1,
            preEnd,
            postStart + numOfNodesInLeft,
            preorder,
            indexInPostOrder
        );

        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        num_of_nodes = len(preorder)

        # Create the index list for `postorder`
        index_in_post_order = [0] * (num_of_nodes + 1)
        for index in range(num_of_nodes):
            # Store the index of the current element
            index_in_post_order[postorder[index]] = index

        return self._construct_tree(
            0, num_of_nodes - 1, 0, preorder, index_in_post_order
        )

    # Helper function to construct the tree recursively
    def _construct_tree(
        self,
        pre_start: int,
        pre_end: int,
        post_start: int,
        preorder: List[int],
        index_in_post_order: List[int],
    ) -> Optional[TreeNode]:
        # Base case: If there are no nodes to process, return None
        if pre_start > pre_end:
            return None

        # Base case: If only one node is left, return that node
        if pre_start == pre_end:
            return TreeNode(preorder[pre_start])

        # The left child root in preorder traversal (next element after root)
        left_root = preorder[pre_start + 1]

        # Calculate the number of nodes in the left subtree by searching in postorder
        num_of_nodes_in_left = index_in_post_order[left_root] - post_start + 1

        root = TreeNode(preorder[pre_start])

        # Recursively construct the left subtree
        root.left = self._construct_tree(
            pre_start + 1,
            pre_start + num_of_nodes_in_left,
            post_start,
            preorder,
            index_in_post_order,
        )

        # Recursively construct the right subtree
        root.right = self._construct_tree(
            pre_start + num_of_nodes_in_left + 1,
            pre_end,
            post_start + num_of_nodes_in_left,
            preorder,
            index_in_post_order,
        )

        return root
```

</details>

<br>

## Approach 3: Optimized Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return constructTree(preIndex, postIndex, preorder, postorder);
    }

private:
    // Helper function to recursively build the tree
    TreeNode* constructTree(int& preIndex, int& postIndex,
                            vector<int>& preorder, vector<int>& postorder) {
        // Create a new node with the value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;  // Mark this node as created

        // Recursively construct the left subtree if the root is not the last of
        // its subtree
        if (root->val != postorder[postIndex]) {
            root->left =
                constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Recursively construct the right subtree if the root is still not the
        // last of its subtree
        if (root->val != postorder[postIndex]) {
            root->right =
                constructTree(preIndex, postIndex, preorder, postorder);
        }

        // Mark this node and its subtree as fully processed
        postIndex++;

        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int preIndex = 0;
    private int postIndex = 0;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return constructTree(preorder, postorder);
    }

    // Helper function to recursively build the tree
    private TreeNode constructTree(int[] preorder, int[] postorder) {
        // Create a new node with the value at the current preorder index
        TreeNode root = new TreeNode(preorder[preIndex++]);

        // Recursively construct the left subtree if the root is not the last of
        // its subtree
        if (root.val != postorder[postIndex]) {
            root.left = constructTree(preorder, postorder);
        }

        // Recursively construct the right subtree if the root is still not the
        // last of its subtree
        if (root.val != postorder[postIndex]) {
            root.right = constructTree(preorder, postorder);
        }

        // Mark this node and its subtree as fully processed
        postIndex++;
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.pre_index = 0
        self.post_index = 0

    # Helper function to recursively build the tree
    def constructFromPrePost(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        return self._construct_tree(preorder, postorder)

    def _construct_tree(
        self, preorder: List[int], postorder: List[int]
    ) -> Optional[TreeNode]:
        root = TreeNode(preorder[self.pre_index])
        self.pre_index += 1

        # Recursively construct the left subtree if the root is not the last of
        # its subtree
        if root.val != postorder[self.post_index]:
            root.left = self._construct_tree(preorder, postorder)

        # Recursively construct the right subtree if the root is not the last of
        # its subtree
        if root.val != postorder[self.post_index]:
            root.right = self._construct_tree(preorder, postorder)

        # Mark this node and its subtree as fully processed
        self.post_index += 1
        return root
```

</details>
