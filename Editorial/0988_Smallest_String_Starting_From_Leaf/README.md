# 988. Smallest String Starting From Leaf

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/smallest-string-starting-from-leaf/)  
`String` `Backtracking` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 988 - Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

## Problem

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

- For example, "ab" is lexicographically smaller than "aba".

A leaf of a node is a node that has no children.

### Example 1

```text
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
```

### Example 2

```text
Input: root = [25,1,3,1,3,0,2]
Output: "adz"
```

### Example 3

```text
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
```

## Constraints

- The number of nodes in the tree is in the range [1, 8500].
- 0 <= Node.val <= 25

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 988. Smallest String Starting From Leaf

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth First Search (DFS) | C++, Java, Python3 |
| Breadth First Search (BFS) Approach | C++, Java, Python3 |

## Approach 1: Depth First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestString;
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallestString;
    }

    // Helper function to find the lexicographically smallest string
    void dfs(TreeNode* root, string currentString) {

        // If the current node is NULL, return
        if (!root) {
            return;
        }

        // Construct the current string by appending 
        // the character corresponding to the node's value
        currentString = char(root->val + 'a') + currentString; 

        // If the current node is a leaf node
        if (!root->left && !root->right) { 
            
            // If the current string is smaller than the result 
            // or if the result is empty
            if (smallestString == "" || smallestString > currentString) { 
                smallestString = currentString;
            }
        }

        // Recursively traverse the left subtree
        if (root->left) {
            dfs(root->left, currentString);
        }

        // Recursively traverse the right subtree
        if (root->right) {
            dfs(root->right, currentString);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    String smallestString = "";

    public String smallestFromLeaf(TreeNode root) {
        dfs(root, "");
        return smallestString;
    }

    // Helper function to find the lexicographically smallest string
    void dfs(TreeNode root, String currentString) {

        // If the current node is NULL, return
        if (root == null) {
            return;
        }

        // Construct the current string by appending 
        // the character corresponding to the node's value
        currentString = (char) (root.val + 'a') + currentString;

        // If the current node is a leaf node
        if (root.left == null && root.right == null) {

            // If the current string is smaller than the result 
            // or if the result is empty
            if (smallestString.isEmpty() || smallestString.compareTo(currentString) > 0) {
                smallestString = currentString;
            }
        }

        // Recursively traverse the left subtree
        if (root.left != null) {
            dfs(root.left, currentString);
        } 

        // Recursively traverse the right subtree
        if (root.right != null) {
            dfs(root.right, currentString);
        }

    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.smallest_string = ""
        self.dfs(root, "")
        return self.smallest_string

    # Helper function to find the lexicographically smallest string
    def dfs(self, root, current_string):
        # If the current node is NULL, return
        if not root:
            return

        # Construct the current string by appending 
        # the character corresponding to the node's value
        current_string = chr(root.val + ord('a')) + current_string

        # If the current node is a leaf node
        if not root.left and not root.right:
            # If the current string is smaller than the result 
            # or if the result is empty
            if not self.smallest_string or self.smallest_string > current_string:
                self.smallest_string = current_string

        # Recursively traverse the left subtree
        if root.left:
            self.dfs(root.left, current_string)
        
        # Recursively traverse the right subtree
        if root.right:
            self.dfs(root.right, current_string)
```

</details>

<br>

## Approach 2: Breadth First Search (BFS) Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        queue<pair<TreeNode*, string>> nodeQueue;

        // Add root node to queue along with its value converted to a character
        nodeQueue.push({root, string(1, root->val + 'a')});

        // Perform BFS traversal until queue is empty
        while (!nodeQueue.empty()) {

            // Pop the leftmost node and its corresponding string from queue
            auto[node, currentString] = nodeQueue.front();
            nodeQueue.pop();

            // If current node is a leaf node
            if (!node->left && !node->right) {

                // Update smallest_string if it's empty or current string is smaller
                if (smallestString.empty()) {
                    smallestString = currentString;
                } else {
                    smallestString = min(smallestString, currentString);
                }
            }

            // If current node has a left child, append it to queue
            if (node->left) {
                nodeQueue.push({node->left, char(node->left->val + 'a') + currentString});
            }

            // If current node has a right child, append it to queue
            if (node->right) {
                nodeQueue.push({node->right, char(node->right->val + 'a') + currentString});
            }
        }

        return smallestString;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String smallestFromLeaf(TreeNode root) {
        String smallestString = "";
        Queue<Pair<TreeNode, String>> nodeQueue = new LinkedList<>();

        // Add root node to queue along with its value converted to a character
        nodeQueue.add(new Pair<>(root, String.valueOf((char)(root.val + 'a'))));

        // Perform BFS traversal until queue is empty
        while (!nodeQueue.isEmpty()) {

            // Pop the leftmost node and its corresponding string from queue
            Pair<TreeNode, String> pair = nodeQueue.poll();
            TreeNode node = pair.getKey();
            String currentString = pair.getValue();
    
            // If current node is a leaf node
            if (node.left == null && node.right == null) {
            
                // Update smallest_string if it's empty or current string is smaller
                if (smallestString.isEmpty()) {
                    smallestString = currentString;
                } else {
                    smallestString = currentString.compareTo(smallestString) < 0 ? currentString : smallestString;
                }
            }

            // If current node has a left child, append it to queue
            if (node.left != null) {
                nodeQueue.add(new Pair<>(node.left, (char)(node.left.val + 'a') + currentString));
            }

            // If current node has a right child, append it to queue
            if (node.right != null) {
                nodeQueue.add(new Pair<>(node.right, (char)(node.right.val + 'a') + currentString));
            }
        }

        return smallestString;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        smallest_string = ""
        node_queue = deque()
        
        # Add root node to deque along with its value converted to a character
        node_queue.append([root, chr(root.val + ord('a'))])
        
        # Perform BFS traversal until deque is empty
        while node_queue:
            # Pop the leftmost node and its corresponding string from deque
            node, current_string = node_queue.popleft()
            
            # If current node is a leaf node
            if not node.left and not node.right:
                # Update smallest_string if it's empty or current string is smaller
                smallest_string = min(smallest_string, current_string) if smallest_string else current_string
            
            # If current node has a left child, append it to deque
            if node.left:
                node_queue.append([node.left, chr(node.left.val + ord('a')) + current_string])
            
            # If current node has a right child, append it to deque
            if node.right:
                node_queue.append([node.right, chr(node.right.val + ord('a')) + current_string])

        return smallest_string
```

</details>
