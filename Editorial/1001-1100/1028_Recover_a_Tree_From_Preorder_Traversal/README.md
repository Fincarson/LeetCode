# 1028. Recover a Tree From Preorder Traversal

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)  
`String` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1028 - Recover a Tree From Preorder Traversal](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)

## Problem

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

### Example 1

```text
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
```

### Example 2

```text
Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
```

### Example 3

```text
Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
```

## Constraints

- The number of nodes in the original tree is in the range [1, 1000].
- 1 <= Node.val <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1028. Recover a Tree From Preorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Recursive with String Manipulation) | C++, Java, Python3 |
| Iterative Approach with Stack (Single Pass) | C++, Java, Python3 |
| Iterative Approach with List | C++, Java, Python3 |

## Approach 1: Brute Force (Recursive with String Manipulation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return helper(traversal, index, 0);
    }

private:
    TreeNode* helper(const string& traversal, int& index, int depth) {
        if (index >= traversal.size()) return nullptr;

        // Count the number of dashes
        int dashCount = 0;
        while (index + dashCount < traversal.size() &&
               traversal[index + dashCount] == '-') {
            dashCount++;
        }

        // If the number of dashes doesn't match the current depth, return null
        if (dashCount != depth) return nullptr;

        // Move index past the dashes
        index += dashCount;

        // Extract the node value
        int value = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }

        // Create the current node
        TreeNode* node = new TreeNode(value);

        // Recursively build the left and right subtrees
        node->left = helper(traversal, index, depth + 1);
        node->right = helper(traversal, index, depth + 1);

        return node;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    static int index = 0;

    public TreeNode recoverFromPreorder(String traversal) {
        index = 0;
        return helper(traversal, 0);
    }

    private TreeNode helper(String traversal, int depth) {
        if (index >= traversal.length()) return null;
        // Count the number of dashes
        int dashCount = 0;
        while (
            (index + dashCount) < traversal.length() &&
            traversal.charAt(index + dashCount) == '-'
        ) {
            dashCount++;
        }

        // If the number of dashes doesn't match the current depth, return null
        if (dashCount != depth) return null;

        // Move index past the dashes
        index += dashCount;

        // Extract the node value
        int value = 0;
        while (
            index < traversal.length() &&
            Character.isDigit(traversal.charAt(index))
        ) {
            value = value * 10 + (traversal.charAt(index++) - '0');
        }

        // Create the current node
        TreeNode node = new TreeNode(value);

        // Recursively build the left and right subtrees
        node.left = helper(traversal, depth + 1);
        node.right = helper(traversal, depth + 1);

        return node;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        self.index = 0

    def recoverFromPreorder(self, traversal: str) -> TreeNode:
        return self.helper(traversal, 0)

    def helper(self, traversal, depth):
        if self.index >= len(traversal):
            return None

        dash_count = 0
        while (
            self.index + dash_count < len(traversal)
            and traversal[self.index + dash_count] == "-"
        ):
            dash_count += 1

        # If the number of dashes doesn't match the current depth, return null
        if dash_count != depth:
            return None

        self.index += dash_count

        # Extract the node value
        value = 0
        while self.index < len(traversal) and traversal[self.index].isdigit():
            value = value * 10 + int(traversal[self.index])
            self.index += 1

        # Create the current node
        node = TreeNode(value)

        # Recursively build the left and right subtrees
        node.left = self.helper(traversal, depth + 1)
        node.right = self.helper(traversal, depth + 1)

        return node
```

</details>

<br>

## Approach 2: Iterative Approach with Stack (Single Pass)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stack;
        int index = 0;

        while (index < traversal.size()) {
            // Count the number of dashes
            int depth = 0;
            while (index < traversal.size() && traversal[index] == '-') {
                depth++;
                index++;
            }

            // Extract the node value
            int value = 0;
            while (index < traversal.size() && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the current node
            TreeNode* node = new TreeNode(value);

            // Adjust the stack to the correct depth
            while (stack.size() > depth) {
                stack.pop();
            }

            // Attach the node to the parent
            if (!stack.empty()) {
                if (stack.top()->left == nullptr) {
                    stack.top()->left = node;
                } else {
                    stack.top()->right = node;
                }
            }

            // Push the current node onto the stack
            stack.push(node);
        }

        // The root is the first node in the stack
        while (stack.size() > 1) {
            stack.pop();
        }

        return stack.top();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int index = 0;

        while (index < traversal.length()) {
            // Count the number of dashes
            int depth = 0;
            while (
                index < traversal.length() && traversal.charAt(index) == '-'
            ) {
                depth++;
                index++;
            }

            // Extract the node value
            int value = 0;
            while (
                index < traversal.length() &&
                Character.isDigit(traversal.charAt(index))
            ) {
                value = value * 10 + (traversal.charAt(index) - '0');
                index++;
            }

            // Create the current node
            TreeNode node = new TreeNode(value);

            // Adjust the stack to the correct depth
            while (stack.size() > depth) {
                stack.pop();
            }

            // Attach the node to the parent
            if (!stack.empty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = node;
                } else {
                    stack.peek().right = node;
                }
            }

            // Push the current node onto the stack
            stack.push(node);
        }

        // The root is the first node in the stack
        while (stack.size() > 1) {
            stack.pop();
        }

        return stack.peek();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        stack = []
        index = 0

        while index < len(traversal):
            # Count the number of dashes
            depth = 0
            while index < len(traversal) and traversal[index] == "-":
                depth += 1
                index += 1

            # Extract the node value
            value = 0
            while index < len(traversal) and traversal[index].isdigit():
                value = value * 10 + int(traversal[index])
                index += 1

            # Create the current node
            node = TreeNode(value)

            # Adjust the stack to the correct depth
            while len(stack) > depth:
                stack.pop()

            # Attach the node to the parent
            if stack:
                if stack[-1].left is None:
                    stack[-1].left = node
                else:
                    stack[-1].right = node

            # Push the current node onto the stack
            stack.append(node)

        return stack[0]
```

</details>

<br>

## Approach 3: Iterative Approach with List

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        // Stores the last node at each depth level
        vector<TreeNode*> levels;
        int index = 0, n = traversal.size();

        while (index < n) {
            // Count depth (number of dashes)
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }

            // Extract node value
            int value = 0;
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            // Create the new node
            TreeNode* node = new TreeNode(value);

            // Adjust levels list to match the current depth
            if (depth < levels.size()) {
                levels[depth] = node;
            } else {
                levels.push_back(node);
            }

            // Attach the node to its parent
            if (depth > 0) {
                TreeNode* parent = levels[depth - 1];
                if (parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }

        // The root node is always at index 0
        return levels[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public TreeNode recoverFromPreorder(String traversal) {
        // List to track the last node at each depth
        List<TreeNode> levels = new ArrayList<>();
        int index = 0, n = traversal.length();

        while (index < n) {
            // Count depth (number of dashes)
            int depth = 0;
            while (index < n && traversal.charAt(index) == '-') {
                depth++;
                index++;
            }

            // Extract node value
            int value = 0;
            while (index < n && Character.isDigit(traversal.charAt(index))) {
                value = value * 10 + (traversal.charAt(index) - '0');
                index++;
            }

            // Create the new node
            TreeNode node = new TreeNode(value);

            // Adjust levels list to match the current depth
            if (depth < levels.size()) {
                levels.set(depth, node);
            } else {
                levels.add(node);
            }

            // Attach the node to its parent
            if (depth > 0) {
                TreeNode parent = levels.get(depth - 1);
                if (parent.left == null) {
                    parent.left = node;
                } else {
                    parent.right = node;
                }
            }
        }

        // The root node is always at index 0
        return levels.get(0);
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
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        levels = []  # List to track the last node at each depth
        index, n = 0, len(traversal)

        while index < n:
            # Count depth (number of dashes)
            depth = 0
            while index < n and traversal[index] == "-":
                depth += 1
                index += 1

            # Extract node value
            value = 0
            while index < n and traversal[index].isdigit():
                value = value * 10 + int(traversal[index])
                index += 1

            # Create the new node
            node = TreeNode(value)

            # Adjust levels list to match the current depth
            if depth < len(levels):
                levels[depth] = node
            else:
                levels.append(node)

            # Attach the node to its parent
            if depth > 0:
                parent = levels[depth - 1]
                if parent.left is None:
                    parent.left = node
                else:
                    parent.right = node

        # The root node is always at index 0
        return levels[0]
```

</details>
