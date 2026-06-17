# 590. N-ary Tree Postorder Traversal

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)  
`Stack` `Tree` `Depth-First Search`

**Problem Link:** [LeetCode 590 - N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

## Problem

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

### Example 1

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
```

### Example 2

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- 0 <= Node.val <= 104
- The height of the n-ary tree is less than or equal to 1000.

Follow up: Recursive solution is trivial, could you do it iteratively?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [N-ary Tree Preorder Traversal](https://leetcode.com/problems/n-ary-tree-preorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 590. N-ary Tree Postorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive | C++, Java, Python3 |
| Iterative (Explicit Reversal) | C++, Java, Python3 |
| Iterative (Two Stacks) | C++, Java, Python3 |
| Iterative (Without Reverse) | C++, Java, Python3 |

## Approach 1: Recursive

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        traversePostorder(root, result);
        return result;
    }

private:
    void traversePostorder(Node* currentNode, vector<int>& postorderList) {
        if (currentNode == nullptr) {
            return;
        }

        // First, visit all children
        for (Node* childNode : currentNode->children) {
            traversePostorder(childNode, postorderList);
        }

        // Then, add the current node's value
        postorderList.push_back(currentNode->val);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) {
            return result;
        }
        traversePostorder(root, result);
        return result;
    }

    private void traversePostorder(
        Node currentNode,
        List<Integer> postorderList
    ) {
        if (currentNode == null) {
            return;
        }

        // First, visit all children
        for (Node childNode : currentNode.children) {
            traversePostorder(childNode, postorderList);
        }

        // Then, add the current node's value
        postorderList.add(currentNode.val);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def postorder(self, root: "Node") -> List[int]:
        result = []
        if not root:
            return result
        self._traverse_postorder(root, result)
        return result

    def _traverse_postorder(
        self, current_node: "Node", postorder_list: List[int]
    ) -> None:
        if not current_node:
            return

        # First, visit all children
        for child_node in current_node.children:
            self._traverse_postorder(child_node, postorder_list)

        # Then, add the current node's value
        postorder_list.append(current_node.val)
```

</details>

<br>

## Approach 2: Iterative (Explicit Reversal)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        // If the root is null, return the empty list
        if (root == nullptr) return result;

        stack<Node*> nodeStack;
        nodeStack.push(root);

        // Traverse the tree using the stack
        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            nodeStack.pop();

            result.push_back(currentNode->val);
            // Push all the children of the current node to the stack
            for (Node* child : currentNode->children) nodeStack.push(child);
        }

        // Reverse the result list to get the correct postorder traversal
        reverse(result.begin(), result.end());
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<Node> stack = new Stack<>();
        stack.add(root);

        // Traverse the tree using the stack
        while (!stack.isEmpty()) {
            Node currentNode = stack.pop();

            result.add(currentNode.val);
            // Push all the children of the current node to the stack
            for (Node child : currentNode.children) stack.add(child);
        }

        // Reverse the result list to get the correct postorder traversal
        Collections.reverse(result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def postorder(self, root: "Node") -> List[int]:
        result = []

        # If the root is None, return the empty list
        if root is None:
            return result

        node_stack = [root]

        # Traverse the tree using the stack
        while node_stack:
            current_node = node_stack.pop()
            result.append(current_node.val)
            # Push all the children of the current node to the stack
            for child in current_node.children:
                node_stack.append(child)

        # Reverse the result list to get the correct postorder traversal
        result.reverse()
        return result
```

</details>

<br>

## Approach 3: Iterative (Two Stacks)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        // If the root is nullptr, return the empty vector
        if (root == nullptr) return result;

        stack<Node*> nodeStack;     // Stack for traversal
        stack<Node*> reverseStack;  // Stack to reverse the order

        nodeStack.push(root);

        // Traverse the tree using the nodeStack
        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            nodeStack.pop();
            reverseStack.push(currentNode);

            // Push all the children of the current node to nodeStack
            for (Node* child : currentNode->children) {
                nodeStack.push(child);
            }
        }

        // Pop nodes from reverseStack and add their values to the result vector
        while (!reverseStack.empty()) {
            Node* currentNode = reverseStack.top();
            reverseStack.pop();
            result.push_back(currentNode->val);
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<Node> nodeStack = new Stack<>(); // Stack for traversal
        Stack<Node> reverseStack = new Stack<>(); // Stack to reverse the order

        nodeStack.push(root);

        // Traverse the tree using the nodeStack
        while (!nodeStack.isEmpty()) {
            Node currentNode = nodeStack.pop();
            reverseStack.push(currentNode);

            // Push all the children of the current node to nodeStack
            for (Node child : currentNode.children) {
                nodeStack.push(child);
            }
        }

        // Pop nodes from reverseStack and add their values to the result list
        while (!reverseStack.isEmpty()) {
            Node currentNode = reverseStack.pop();
            result.add(currentNode.val);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def postorder(self, root: "Node") -> List[int]:
        result = []

        # If the root is None, return the empty list
        if root is None:
            return result

        node_stack = [root]  # Stack for traversal
        reverse_stack = []  # Stack to reverse the order

        # Traverse the tree using the node_stack
        while node_stack:
            current_node = node_stack.pop()
            reverse_stack.append(current_node)

            # Push all the children of the current node to node_stack
            for child in current_node.children:
                node_stack.append(child)

        # Pop nodes from reverse_stack and add their values to the result list
        while reverse_stack:
            current_node = reverse_stack.pop()
            result.append(current_node.val)

        return result
```

</details>

<br>

## Approach 4: Iterative (Without Reverse)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        // If the root is null, return the empty vector
        if (root == nullptr) return result;

        stack<NodeVisitPair> nodeStack;
        nodeStack.push(NodeVisitPair(root, false));

        while (!nodeStack.empty()) {
            NodeVisitPair currentPair = nodeStack.top();
            nodeStack.pop();

            if (currentPair.isVisited) {
                // If the node has been visited, add its value to the result
                result.push_back(currentPair.node->val);
            } else {
                // Mark the current node as visited and push it back to the
                // stack
                currentPair.isVisited = true;
                nodeStack.push(currentPair);

                // Push all children to the stack in reverse order
                vector<Node*>& children = currentPair.node->children;
                for (int i = children.size() - 1; i >= 0; i--) {
                    nodeStack.push(NodeVisitPair(children[i], false));
                }
            }
        }

        return result;
    }

private:
    // Helper class to pair a node with its visited status
    struct NodeVisitPair {
        Node* node;
        bool isVisited;

        NodeVisitPair(Node* n, bool visited) : node(n), isVisited(visited) {}
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();
        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<NodeVisitPair> nodeStack = new Stack<>();
        nodeStack.push(new NodeVisitPair(root, false));

        while (!nodeStack.isEmpty()) {
            NodeVisitPair currentPair = nodeStack.pop();

            if (currentPair.isVisited) {
                // If the node has been visited, add its value to the result
                result.add(currentPair.node.val);
            } else {
                // Mark the current node as visited and push it back to the stack
                currentPair.isVisited = true;
                nodeStack.push(currentPair);

                // Push all children to the stack in reverse order
                List<Node> children = currentPair.node.children;
                for (int i = children.size() - 1; i >= 0; i--) {
                    nodeStack.push(new NodeVisitPair(children.get(i), false));
                }
            }
        }

        return result;
    }

    // Helper class to pair a node with its visited status
    private class NodeVisitPair {

        Node node;
        boolean isVisited;

        NodeVisitPair(Node node, boolean isVisited) {
            this.node = node;
            this.isVisited = isVisited;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def postorder(self, root: "Node") -> List[int]:
        result = []
        # If the root is None, return the empty list
        if root is None:
            return result

        node_stack = [(root, False)]

        while node_stack:
            current_node, is_visited = node_stack.pop()

            if is_visited:
                # If the node has been visited, add its value to the result
                result.append(current_node.val)
            else:
                # Mark the current node as visited and push it back to the stack
                node_stack.append((current_node, True))

                # Push all children to the stack in reverse order
                for child in reversed(current_node.children):
                    node_stack.append((child, False))

        return result
```

</details>
