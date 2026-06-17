# 1038. Binary Search Tree to Greater Sum Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 1038 - Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

## Problem

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

### Example 1

```text
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

### Example 2

```text
Input: root = [0,null,1]
Output: [1,null,1]
```

## Constraints

- The number of nodes in the tree is in the range [1, 100].
- 0 <= Node.val <= 100
- All the values in the tree are unique.

Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1038. Binary Search Tree to Greater Sum Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| In-order Traversal (Brute-Force) | C++, Java, Python3 |
| Reverse In-order Traversal | C++, Java, Python3 |
| Iterative Reverse In-order Traversal | C++, Java, Python3 |
| Morris Traversal | C++, Java, Python3 |

## Approach 1: In-order Traversal (Brute-Force)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        // Store the inorder traversal in an array.
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);

        // Reverse the array to get descending order.
        reverse(inorderTraversal.begin(), inorderTraversal.end());

        // Modify the values in the tree.
        replaceValues(root, inorderTraversal);

        return root;
    }

private:
    // Perform any traversal of your choice to store node values.
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    // Function to modify the values in the tree.
    void replaceValues(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        replaceValues(root->left, inorderTraversal);
        replaceValues(root->right, inorderTraversal);

        int nodeSum = 0;
        // Replace node with values greater than the current value.
        for (auto i : inorderTraversal) {
            if (i > root->val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root->val += nodeSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode bstToGst(TreeNode root) {
        // Store the inorder traversal in an array.
        List<Integer> inorderTraversal = new ArrayList<>();
        inorder(root, inorderTraversal);

        // Reverse the array to get descending order.
        Collections.reverse(inorderTraversal);

        // Modify the values in the tree.
        replaceValues(root, inorderTraversal);
        return root;
    }

    // Perform any traversal of your choice to store node values.
    private void inorder(TreeNode root, List<Integer> inorderTraversal) {
        if (root == null) {
            return;
        }
        inorder(root.left, inorderTraversal);
        inorderTraversal.add(root.val);
        inorder(root.right, inorderTraversal);
    }

    // Function to modify the values in the tree.
    private void replaceValues(TreeNode root, List<Integer> inorderTraversal) {
        if (root == null) {
            return;
        }
        replaceValues(root.left, inorderTraversal);
        replaceValues(root.right, inorderTraversal);

        int nodeSum = 0;
        // Replace node with values greater than the current value.
        for (int i : inorderTraversal) {
            if (i > root.val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root.val += nodeSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bstToGst(self, root):
        # Store the inorder traversal in an array.
        self.inorder_traversal = []
        self.inorder(root)

        # Reverse the array to get descending order.
        self.inorder_traversal.reverse()

        # Modify the values in the tree.
        self.replace_values(root)

        return root

    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        self.inorder_traversal.append(root.val)
        self.inorder(root.right)

    # Function to modify the values in the tree.
    def replace_values(self, root):
        if root is None:
            return
        self.replace_values(root.left)
        self.replace_values(root.right)

        # Replace node with values greater than the current value.
        node_sum = 0
        for i in self.inorder_traversal:
            if i > root.val:
                node_sum += i
            else:
                break

        root.val += node_sum
```

</details>

<br>

## Approach 2: Reverse In-order Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        // Initialize a local variable nodeSum.
        int nodeSum = 0;
        bstToGstHelper(root, nodeSum);
        return root;
    }

private:
    void bstToGstHelper(TreeNode* root, int& nodeSum) {
        // If root is null, make no changes.
        if (!root) {
            return;
        }

        bstToGstHelper(root->right, nodeSum);
        nodeSum += root->val;
        // Update the value of root.
        root->val = nodeSum;
        bstToGstHelper(root->left, nodeSum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode bstToGst(TreeNode root) {
        int[] nodeSum = new int[1];
        bstToGstHelper(root, nodeSum);
        return root;
    }

    private void bstToGstHelper(TreeNode root, int[] nodeSum) {
        // If root is null, make no changes.
        if (root == null) {
            return;
        }

        bstToGstHelper(root.right, nodeSum);
        nodeSum[0] += root.val;
        // Update the value of root.
        root.val = nodeSum[0];
        bstToGstHelper(root.left, nodeSum);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bstToGst(self, root):
        node_sum = [0]  # Using a list to emulate a mutable integer reference
        self.bst_to_gst_helper(root, node_sum)
        return root

    def bst_to_gst_helper(self, root, node_sum):
        # If root is null, make no changes.
        if root is None:
            return

        self.bst_to_gst_helper(root.right, node_sum)
        node_sum[0] += root.val
        # Update the value of root.
        root.val = node_sum[0]
        self.bst_to_gst_helper(root.left, node_sum)
```

</details>

<br>

## Approach 3: Iterative Reverse In-order Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (!st.empty() or node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->right;
            }

            // Store the top value of stack in node and pop it.
            node = st.top();
            st.pop();

            // Update value of node.
            nodeSum += node->val;
            node->val = nodeSum;

            // Move to the left child of node.
            node = node->left;
        }
        return root;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode bstToGst(TreeNode root) {
        int nodeSum = 0;
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root;

        while (!st.empty() || node != null) {
            while (node != null) {
                st.push(node);
                node = node.right;
            }

            // Store the top value of stack in node and pop it.
            node = st.pop();

            // Update value of node.
            nodeSum += node.val;
            node.val = nodeSum;

            // Move to the left child of node.
            node = node.left;
        }
        return root;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        node_sum = 0
        st = []
        node = root

        while st or node is not None:

            while node is not None:
                st.append(node)
                node = node.right
            # Store the top value of stack in node and pop it.
            node = st.pop()

            # Update value of node.
            node_sum += node.val
            node.val = node_sum

            # Move to the left child of node.
            node = node.left
        return root
```

</details>

<br>

## Approach 4: Morris Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr) {
            /*
             * If there is no right subtree, then we can visit this node and
             * continue traversing left.
             */
            if (node->right == nullptr) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            /*
             * If there is a right subtree, then there is at least one node that
             * has a greater value than the current one. therefore, we must
             * traverse that subtree first.
             */
            else {
                TreeNode* succ = getSuccessor(node);
                /*
                 * If the left subtree is null, then we have never been here
                 * before.
                 */
                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                }
                /*
                 * If there is a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else {
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }

        return root;
    }

private:
    /* Get the node with the smallest value greater than this one. */
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode bstToGst(TreeNode root) {
        int sum = 0;
        TreeNode node = root;

        while (node != null) {
            // If there is no right subtree, then we can visit this node and
            // continue traversing left.
            if (node.right == null) {
                sum += node.val;
                node.val = sum;
                node = node.left;
            }
            //  If there is a right subtree, then there is at least one node that
            //  has a greater value than the current one. therefore, we must
            //  traverse that subtree first.
            else {
                TreeNode succ = getSuccessor(node);
                //If the left subtree is null, then we have never been here before.
                if (succ.left == null) {
                    succ.left = node;
                    node = node.right;
                }
                //If there is a left subtree, it is a link that we created on a
                //previous pass, so we should unlink it and visit this node.
                else {
                    succ.left = null;
                    sum += node.val;
                    node.val = sum;
                    node = node.left;
                }
            }
        }

        return root;
    }

    // Get the node with the smallest value greater than this one.
    private TreeNode getSuccessor(TreeNode node) {
        TreeNode succ = node.right;
        while (succ.left != null && succ.left != node) {
            succ = succ.left;
        }
        return succ;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def bstToGst(self, root):
        # Get the node with the smallest value greater than this one.
        def get_successor(node):
            succ = node.right
            while succ.left is not None and succ.left is not node:
                succ = succ.left
            return succ

        total = 0
        node = root
        while node is not None:
            # If there is no right subtree, then we can visit this node and
            # continue traversing left.
            if node.right is None:
                total += node.val
                node.val = total
                node = node.left
            # If there is a right subtree, then there is a node that has a
            # greater value than the current one. therefore, we must traverse
            # that node first.
            else:
                succ = get_successor(node)
                # If there is no left subtree (or right subtree, because we are
                # in this branch of control flow), make a temporary connection
                # back to the current node.
                if succ.left is None:
                    succ.left = node
                    node = node.right
                # If there is a left subtree, it is a link that we created on
                # a previous pass, so we should unlink it and visit this node.
                else:
                    succ.left = None
                    total += node.val
                    node.val = total
                    node = node.left

        return root
```

</details>
