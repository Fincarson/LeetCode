# 145. Binary Tree Postorder Traversal

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/binary-tree-postorder-traversal/)  
`Stack` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 145 - Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

## Problem

Given the root of a binary tree, return the postorder traversal of its nodes' values.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- The number of the nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 145. Binary Tree Postorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Postorder Traversal | C++, Java, Python3 |
| Manipulating Preorder Traversal (Iterative Hack) | C++, Java, Python3 |
| Two Stack Postorder Traversal (Iterative) | C++, Java, Python3 |
| Single Stack Postorder Traversal (Iterative) | C++, Java, Python3 |
| Morris Traversal (No stack) | C++, Java, Python3 |

## Approach 1: Recursive Postorder Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
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
    void postorderTraversalHelper(TreeNode* currentNode, vector<int>& result) {
        // Base case: if the node is null, return
        if (!currentNode) {
            return;
        }
        // Traverse left subtree
        postorderTraversalHelper(currentNode->left, result);
        // Traverse right subtree
        postorderTraversalHelper(currentNode->right, result);
        // Add the current node's value to the result list
        result.push_back(currentNode->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        // Start traversal from root
        postorderTraversalHelper(root, result);
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    private void postorderTraversalHelper(
        TreeNode currentNode,
        List<Integer> result
    ) {
        // Base case: if the node is null, return
        if (currentNode == null) {
            return;
        }
        // Traverse left subtree
        postorderTraversalHelper(currentNode.left, result);
        // Traverse right subtree
        postorderTraversalHelper(currentNode.right, result);
        // Add the current node's value to the result list
        result.add(currentNode.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        // Start traversal from root
        postorderTraversalHelper(root, result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversalHelper(self, currentNode, result):
        # Base case: if the node is null, return
        if not currentNode:
            return
        # Traverse left subtree
        self.postorderTraversalHelper(currentNode.left, result)
        # Traverse right subtree
        self.postorderTraversalHelper(currentNode.right, result)
        # Add the current node's value to the result list
        result.append(currentNode.val)

    def postorderTraversal(self, root):
        result = []
        # Start traversal from root
        self.postorderTraversalHelper(root, result)
        return result
```

</details>

<br>

## Approach 2: Manipulating Preorder Traversal (Iterative Hack)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
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
    vector<int> postorderTraversal(TreeNode* root) {
        // Vector to store the result of postorder traversal
        vector<int> result;
        // Stack to facilitate the traversal of nodes
        stack<TreeNode*> traversalStack;
        TreeNode* currentNode = root;

        // Traverse the tree while there are nodes to process
        while (currentNode != nullptr || !traversalStack.empty()) {
            if (currentNode != nullptr) {
                // Add current node's value to result list before going to its
                // children
                result.push_back(currentNode->val);
                // Push current node onto the stack
                traversalStack.push(currentNode);
                // Move to the right child
                currentNode = currentNode->right;
            } else {
                // Pop the node from the stack and move to its left child
                currentNode = traversalStack.top();
                traversalStack.pop();
                currentNode = currentNode->left;
            }
        }
        // Reverse the result list to get the correct postorder sequence
        reverse(result.begin(), result.end());
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {
        // List to store the result of postorder traversal
        List<Integer> result = new ArrayList<>();
        // Stack to facilitate the traversal of nodes
        Deque<TreeNode> traversalStack = new ArrayDeque<>();
        TreeNode currentNode = root;

        // Traverse the tree while there are nodes to process
        while (currentNode != null || !traversalStack.isEmpty()) {
            if (currentNode != null) {
                // Add current node's value to result list before going to its children
                result.add(currentNode.val);
                // Push current node onto the stack
                traversalStack.push(currentNode);
                // Move to the right child
                currentNode = currentNode.right;
            } else {
                // Pop the node from the stack and move to its left child
                currentNode = traversalStack.pop();
                currentNode = currentNode.left;
            }
        }
        // Reverse the result list to get the correct postorder sequence
        Collections.reverse(result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root):
        # List to store the result of postorder traversal
        result = []
        # Stack to facilitate the traversal of nodes
        traversal_stack = []
        current_node = root

        # Traverse the tree while there are nodes to process
        while current_node or traversal_stack:
            if current_node:
                # Add current node's value to result list before going to its children
                result.append(current_node.val)
                # Push current node onto the stack
                traversal_stack.append(current_node)
                # Move to the right child
                current_node = current_node.right
            else:
                # Pop the node from the stack and move to its left child
                current_node = traversal_stack.pop()
                current_node = current_node.left
        # Reverse the result list to get the correct postorder sequence
        result.reverse()
        return result
```

</details>

<br>

## Approach 3: Two Stack Postorder Traversal (Iterative)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        // If the root is null, return an empty list
        if (!root) {
            return result;
        }

        // Stack to manage the traversal
        stack<TreeNode*> mainStack;
        // Stack to manage the path
        stack<TreeNode*> pathStack;

        // Start with the root node
        mainStack.push(root);

        // Process nodes until the main stack is empty
        while (!mainStack.empty()) {
            root = mainStack.top();

            // If the node is in the path stack and it's the top, add its value
            if (!pathStack.empty() && pathStack.top() == root) {
                result.push_back(root->val);
                mainStack.pop();
                pathStack.pop();
            } else {
                // Push the current node to the path stack
                pathStack.push(root);
                // Push right child if it exists
                if (root->right) {
                    mainStack.push(root->right);
                }
                // Push left child if it exists
                if (root->left) {
                    mainStack.push(root->left);
                }
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return an empty list
        if (root == null) {
            return result;
        }

        // Stack to manage the traversal
        Stack<TreeNode> mainStack = new Stack<>();
        // Stack to manage the path
        Stack<TreeNode> pathStack = new Stack<>();

        // Start with the root node
        mainStack.push(root);

        // Process nodes until the main stack is empty
        while (!mainStack.isEmpty()) {
            root = mainStack.peek();

            // If the node is in the path stack and it's the top, add its value
            if (!pathStack.isEmpty() && pathStack.peek() == root) {
                result.add(root.val);
                mainStack.pop();
                pathStack.pop();
            } else {
                // Push the current node to the path stack
                pathStack.push(root);
                // Push right child if it exists
                if (root.right != null) {
                    mainStack.push(root.right);
                }
                // Push left child if it exists
                if (root.left != null) {
                    mainStack.push(root.left);
                }
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root):
        result = []

        # If the root is null, return an empty list
        if root is None:
            return result

        # Stack to manage the traversal
        main_stack = []
        # Stack to manage the path
        path_stack = []

        # Start with the root node
        main_stack.append(root)

        # Process nodes until the main stack is empty
        while main_stack:
            root = main_stack[-1]

            # If the node is in the path stack and it's the top, add its value
            if path_stack and path_stack[-1] == root:
                result.append(root.val)
                main_stack.pop()
                path_stack.pop()
            else:
                # Push the current node to the path stack
                path_stack.append(root)
                # Push right child if it exists
                if root.right is not None:
                    main_stack.append(root.right)
                # Push left child if it exists
                if root.left is not None:
                    main_stack.append(root.left)

        return result
```

</details>

<br>

## Approach 4: Single Stack Postorder Traversal (Iterative)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        // If the root is null, return an empty list
        if (root == nullptr) {
            return result;
        }

        // To keep track of the previously processed node
        TreeNode* previousNode = nullptr;
        // Stack to manage the traversal
        stack<TreeNode*> traversalStack;

        // Process nodes until both the root is null and the stack is empty
        while (root != nullptr || !traversalStack.empty()) {
            // Traverse to the leftmost node
            if (root != nullptr) {
                traversalStack.push(root);
                root = root->left;
            } else {
                // Peek at the top node of the stack
                root = traversalStack.top();

                // If there is no right child or the right child was already
                // processed
                if (root->right == nullptr || root->right == previousNode) {
                    result.push_back(root->val);
                    traversalStack.pop();
                    previousNode = root;
                    root = nullptr;  // Ensure we donÃ¢â‚¬â„¢t traverse again from this
                                     // node
                } else {
                    // Move to the right child
                    root = root->right;
                }
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return an empty list
        if (root == null) {
            return result;
        }

        // To keep track of the previously processed node
        TreeNode previousNode = null;
        // Stack to manage the traversal
        Stack<TreeNode> traversalStack = new Stack<>();

        // Process nodes until both the root is null and the stack is empty
        while (root != null || !traversalStack.isEmpty()) {
            // Traverse to the leftmost node
            if (root != null) {
                traversalStack.push(root);
                root = root.left;
            } else {
                // Peek at the top node of the stack
                root = traversalStack.peek();

                // If there is no right child or the right child was already processed
                if (root.right == null || root.right == previousNode) {
                    result.add(root.val);
                    traversalStack.pop();
                    previousNode = root;
                    root = null; // Ensure we donÃ¢â‚¬â„¢t traverse again from this node
                } else {
                    // Move to the right child
                    root = root.right;
                }
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        # If the root is null, return an empty list
        if root is None:
            return result

        # To keep track of the previously processed node
        previous_node = None
        # Stack to manage the traversal
        traversal_stack = []

        # Process nodes until both the root is null and the stack is empty
        while root is not None or len(traversal_stack) > 0:
            # Traverse to the leftmost node
            if root is not None:
                traversal_stack.append(root)
                root = root.left
            else:
                # Peek at the top node of the stack
                root = traversal_stack[-1]

                # If there is no right child or the right child was already processed
                if root.right is None or root.right == previous_node:
                    result.append(root.val)
                    traversal_stack.pop()
                    previous_node = root
                    root = None  # Ensure we donÃ¢â‚¬â„¢t traverse again from this node
                else:
                    # Move to the right child
                    root = root.right

        return result
```

</details>

<br>

## Approach 5: Morris Traversal (No stack)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        // If the root is null, return an empty list
        if (root == NULL) {
            return result;
        }

        // Create a dummy node to simplify edge cases
        TreeNode dummy = -1;
        TreeNode* dummyNode = &dummy;
        TreeNode* predecessor = NULL;
        dummyNode->left = root;
        root = dummyNode;

        // Traverse the tree
        while (root != NULL) {
            // If the current node has a left child
            if (root->left != NULL) {
                predecessor = root->left;

                // Find the rightmost node in the left subtree or the thread
                // back to the current node
                while (predecessor->right != NULL &&
                       predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // Create a thread if it doesn't exist
                if (predecessor->right == NULL) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Process the nodes in the left subtree
                    TreeNode* node = predecessor;
                    reverseSubtreeLinks(root->left, predecessor);

                    // Add nodes from right to left
                    while (node != root->left) {
                        result.push_back(node->val);
                        node = node->right;
                    }

                    result.push_back(node->val);  // Add root.left's value
                    reverseSubtreeLinks(predecessor, root->left);
                    predecessor->right = NULL;
                    root = root->right;
                }
            } else {
                // Move to the right child if there's no left child
                root = root->right;
            }
        }

        return result;
    }

    void reverseSubtreeLinks(TreeNode* startNode, TreeNode* endNode) {
        if (startNode == endNode) {
            return;  // If the start and end nodes are the same, no need to
                     // reverse
        }

        TreeNode* prev = NULL;
        TreeNode* current = startNode;
        TreeNode* next = NULL;

        // Reverse the direction of the pointers in the subtree
        while (current != endNode) {
            next = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }

        // Reverse the last node
        current->right = prev;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return an empty list
        if (root == null) {
            return result;
        }

        // Create a dummy node to simplify edge cases
        TreeNode dummyNode = new TreeNode(-1);
        TreeNode predecessor = null;
        dummyNode.left = root;
        root = dummyNode;

        // Traverse the tree
        while (root != null) {
            // If the current node has a left child
            if (root.left != null) {
                predecessor = root.left;

                // Find the rightmost node in the left subtree or the thread to the current node
                while (predecessor.right != null && predecessor.right != root) {
                    predecessor = predecessor.right;
                }

                // Create a thread if it doesn't exist
                if (predecessor.right == null) {
                    predecessor.right = root;
                    root = root.left;
                } else {
                    // Process the nodes in the left subtree
                    TreeNode node = predecessor;
                    reverseSubtreeLinks(root.left, predecessor);

                    // Add nodes from right to left
                    while (node != root.left) {
                        result.add(node.val);
                        node = node.right;
                    }
                    result.add(node.val); // Add root.left value
                    reverseSubtreeLinks(predecessor, root.left);
                    predecessor.right = null;
                    root = root.right;
                }
            } else {
                // Move to the right child if there's no left child
                root = root.right;
            }
        }

        return result;
    }

    private void reverseSubtreeLinks(TreeNode startNode, TreeNode endNode) {
        if (startNode == endNode) {
            return; // If the start and end nodes are the same, no need to reverse
        }

        TreeNode prev = null;
        TreeNode current = startNode;
        TreeNode next = null;

        // Reverse the direction of the pointers in the subtree
        while (current != endNode) {
            next = current.right;
            current.right = prev;
            prev = current;
            current = next;
        }
        // Reverse the last node
        current.right = prev;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def postorderTraversal(self, root):
        result = []

        # If the root is None, return an empty list
        if not root:
            return result

        # Create a dummy node to simplify edge cases
        dummy_node = TreeNode(-1)
        dummy_node.left = root
        root = dummy_node

        # Traverse the tree
        while root:
            if root.left:  # If the current node has a left child
                predecessor = root.left

                # Find the rightmost node in the left subtree or the thread back to the current node
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right

                # Create a thread if it doesn't exist
                if predecessor.right == None:
                    predecessor.right = root
                    root = root.left
                else:
                    # Process the nodes in the left subtree
                    node = predecessor
                    self._reverse_subtree_links(root.left, predecessor)

                    # Add nodes from right to left
                    while node != root.left:
                        result.append(node.val)
                        node = node.right
                    result.append(node.val)  # Add root.left's value
                    self._reverse_subtree_links(predecessor, root.left)
                    predecessor.right = None
                    root = root.right
            else:
                # Move to the right child if there's no left child
                root = root.right

        return result

    def _reverse_subtree_links(self, start_node, end_node):
        if start_node == end_node:
            return  # If the start and end nodes are the same, no need to reverse

        prev = None
        current = start_node
        next = None

        # Reverse the direction of the pointers in the subtree
        while current != end_node:
            next = current.right
            current.right = prev
            prev = current
            current = next
        # Reverse the last node
        current.right = prev
```

</details>
