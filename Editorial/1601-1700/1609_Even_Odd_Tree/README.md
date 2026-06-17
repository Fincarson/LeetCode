# 1609. Even Odd Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/even-odd-tree/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1609 - Even Odd Tree](https://leetcode.com/problems/even-odd-tree/)

## Problem

A binary tree is named Even-Odd if it meets the following conditions:

- The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
- For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
- For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).

Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

### Example 1

```text
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
```

### Example 2

```text
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
```

### Example 3

```text
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1609. Even Odd Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search | C++, Java, Python3 |
| Breadth-First Search | C++, Java, Python3 |

## Approach 1: Depth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* current = root;
        return dfs(current, 0);
    }

private:
    vector<int> prev;
    bool dfs(TreeNode* current, size_t level) {
        // Base case, an empty tree is Even-Odd
        if (current == nullptr) {
            return true;
        }

        // Compare the parity of current and level
        if (current->val % 2 == level % 2) {
            return false;
        }

        // Resize prev to make room for the new level
        prev.resize(max(prev.size(), level + 1));

        // If there are previous nodes on this level, check increasing/decreasing
        // If on an even level, check that currrent's value is greater than the previous on this level
        // If on an odd level, check that current's value is less than the previous on this level
        if (prev[level] != 0 && 
                ((level % 2 == 0 && current->val <= prev[level]) ||
                 (level % 2 == 1 && current->val >= prev[level]))) {
            return false;  // Not in the required order
        }

        // Add current value to prev at index level
        prev[level] = current->val;

        // Recursively call DFS on the left and right children
        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private List<Integer> prev = new ArrayList<>();

    public boolean isEvenOddTree(TreeNode root) {
        TreeNode current = root;
        return dfs(current, 0);
    }

    private boolean dfs(TreeNode current, int level) {
        // Base case, an empty tree is Even-Odd
        if (current == null) {
            return true;
        }

        // Compare the parity of current and level
        if (current.val % 2 == level % 2) {
            return false;
        }

        // Add a new level to prev if we've reached a new level
        while (prev.size() <= level) {
            prev.add(0);
        }

        // If there are previous nodes on this level, check increasing/decreasing
        // If on an even level, check that current's value is greater than the previous on this level
        // If on an odd level, check that current's value is less than the previous on this level
        if (prev.get(level) != 0 && 
                ((level % 2 == 0 && current.val <= prev.get(level)) || 
                 (level % 2 == 1 && current.val >= prev.get(level)))) {
            return false;
        }

        // Add current value to prev at index level
        prev.set(level, current.val);

        // Recursively call DFS on the left and right children
        return dfs(current.left, level + 1) && dfs(current.right, level + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        prev = []

        def dfs(current: TreeNode, level: int) -> bool:
            # Base case, an empty tree is Even-Odd
            if current is None:
                return True

            # Compare the parity of current and level
            if current.val % 2 == level % 2:
                return False

            # Add a new level to prev if we've reached a new level
            while(len(prev) <= level):
                prev.append(0)

            # If there are previous nodes on this level, check increasing/decreasing
            # If on an even level, check that current's value is greater than the previous on this level
            # If on an odd level, check that current's value is less than the previous on this level
            if prev[level] != 0 and \
                    ((level % 2 == 0 and current.val <= prev[level]) or \
                     (level % 2 == 1 and current.val >= prev[level])):
                return False

            # Add current value to prev at index level
            prev[level] = current.val

            # Recursively call DFS on the left and right children
            return dfs(current.left, level + 1) and dfs(current.right, level + 1)
        
        current = root
        return dfs(current, 0)
```

</details>

<br>

## Approach 2: Breadth-First Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // Create a queue for nodes that need to be visted and add the root
        queue<TreeNode*> queue;
        TreeNode* current = root;
        queue.push(current);

        // Keeps track of whether we are on an even level
        bool even = true;

        // While there are more nodes in the queue
        // Determine the size of the level and handle the nodes
        while (!queue.empty()) {
            int size = queue.size();

            // Prev holds the value of the previous node in this level
            int prev = INT_MAX;
            if (even) {
                prev = INT_MIN;
            }

            // While there are more nodes in this level
            // Remove a node, check whether it satisfies the conditons
            // Add its children to the queue
            while (size > 0) {
                current = queue.front();
                queue.pop();

                // If on an even level, check that the node's value is odd and greater than prev
                // If on an odd level, check that the node's value is even and less than prev
                if ((even && (current->val % 2 == 0 || current->val <= prev)) || 
                        (!even && (current->val % 2 == 1 || current->val >= prev))) {
                    return false;
                }
                prev = current->val;
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
                // Decrement size, we have handled a node on this level
                size--;
            }
            // Flip the value of even, the next level will be opposite
            even = !even;
        }
        // If every node meets the condtions, the tree is Even-Odd
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        // Create a queue for nodes that need to be visited and add the root
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode current = root;
        queue.add(current);

        // Keeps track of whether we are on an even level
        boolean even = true;

        // While there are more nodes in the queue
        // Determine the size of the level and handle the nodes
        while (!queue.isEmpty()) {
            int size = queue.size();

            // Prev holds the value of the previous node in this level
            int prev = Integer.MAX_VALUE;
            if (even) {
                prev = Integer.MIN_VALUE;
            }

            // While there are more nodes in this level
            // Remove a node, check whether it satisfies the conditions
            // Add its children to the queue
            while (size > 0) {
                current = queue.poll();

                // If on an even level, check that the node's value is odd and greater than prev
                // If on an odd level, check that the node's value is even and less than prev
                if ((even && (current.val % 2 == 0 || current.val <= prev)) ||
                        (!even && (current.val % 2 == 1 || current.val >= prev))) {
                    return false;
                }

                prev = current.val;
                if (current.left != null) {
                    queue.add(current.left);
                }
                if (current.right != null) {
                    queue.add(current.right);
                }
                // Decrement size, we have handled a node on this level
                size--;
            }
            // Flip the value of even, the next level will be opposite
            even = !even;
        }
        // If every node meets the conditions, the tree is Even-Odd
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        # Create a queue for nodes that need to be visited and add the root
        queue = deque()
        current = root
        queue.append(current)

        # Keeps track of whether we are on an even level
        even = True

        # While there are more nodes in the queue
        # Determine the size of the level and handle the nodes
        while queue:
            size = len(queue)

            # Prev holds the value of the previous node in this level
            prev = float("inf")
            if even:
                prev = -prev

            # While there are more nodes in this level
            # Remove a node, check whether it satisfies the conditions
            # Add its children to the queue
            while size > 0:
                current = queue.popleft()

                # If on an even level, check that the node's value is odd and greater than prev
                # If on an odd level, check that the node's value is even and less than prev
                if (even and (current.val % 2 == 0 or current.val <= prev)) or \
                        (not even and (current.val % 2 == 1 or current.val >= prev)):
                    return False

                prev = current.val
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
                # Decrement size, we have handled a node on this level
                size -= 1

            # Flip the value of even, the next level will be opposite
            even = not even

        # If every node meets the conditions, the tree is Even-Odd
        return True
```

</details>
