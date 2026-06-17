# 2331. Evaluate Boolean Binary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/evaluate-boolean-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 2331 - Evaluate Boolean Binary Tree](https://leetcode.com/problems/evaluate-boolean-binary-tree/)

## Problem

You are given the root of a full binary tree with the following properties:

- Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
- Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.

The evaluation of a node is as follows:

- If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
- Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.

Return the boolean result of evaluating the root node.

A full binary tree is a binary tree where each node has either 0 or 2 children.

A leaf node is a node that has zero children.

### Example 1

```text
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
```

### Example 2

```text
Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.
```

## Constraints

- The number of nodes in the tree is in the range [1, 1000].
- 0 <= Node.val <= 3
- Every node has either 0 or 2 children.
- Leaf nodes have a value of 0 or 1.
- Non-leaf nodes have a value of 2 or 3.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check If Two Expression Trees are Equivalent](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Design an Expression Tree With Evaluate Function](https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Flips in Binary Tree to Get Result](https://leetcode.com/problems/minimum-flips-in-binary-tree-to-get-result/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2331. Evaluate Boolean Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion (Depth First Search) | C++, Java, Python3 |
| Iterative approach (Depth First Search) | C++, Java, Python3 |

## Approach 1: Recursion (Depth First Search)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr and root->right == nullptr) {
            // Handles the case for leaf nodes.
            return root->val;
        }

        // Store the evaluations for the left subtree and right subtree.
        bool evaluateLeftSubtree = evaluateTree(root->left);
        bool evaluateRightSubtree = evaluateTree(root->right);
        bool evaluateRoot;
        if (root->val == 2) {
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        } else {
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        }

        return evaluateRoot;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean evaluateTree(TreeNode root) {
        // Handles the case for leaf nodes.
        if (root.left == null && root.right == null) {
            return root.val != 0;
        }

        // Store the evaluations for the left subtree and right subtree.
        boolean evaluateLeftSubtree = evaluateTree(root.left);
        boolean evaluateRightSubtree = evaluateTree(root.right);
        boolean evaluateRoot;
        if (root.val == 2) {
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        } else {
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        }

        return evaluateRoot;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if not root.left and not root.right:
            # Handles the case for leaf nodes.
            return root.val != 0

        # Store the evaluations for the left subtree and right subtree.
        evaluate_left_subtree = self.evaluateTree(root.left)
        evaluate_right_subtree = self.evaluateTree(root.right)
        if root.val == 2:
            evaluate_root = evaluate_left_subtree or evaluate_right_subtree
        else:
            evaluate_root = evaluate_left_subtree and evaluate_right_subtree

        return evaluate_root
```

</details>

<br>

## Approach 2: Iterative approach (Depth First Search)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, bool> evaluated;

        while (!st.empty()) {
            TreeNode* topNode = st.top();

            // If the node is a leaf node, store its value in the evaluated
            // hashmap and continue
            if (!topNode->left and !topNode->right) {
                st.pop();
                evaluated[topNode] = topNode->val;
                continue;
            }

            // If both the children have already been evaluated, use their
            // values to evaluate the current node.
            if (evaluated.find(topNode->left) != evaluated.end() and
                evaluated.find(topNode->right) != evaluated.end()) {
                st.pop();
                if (topNode->val == 2) {
                    evaluated[topNode] =
                        evaluated[topNode->left] || evaluated[topNode->right];
                } else {
                    evaluated[topNode] =
                        evaluated[topNode->left] && evaluated[topNode->right];
                }
            } else {
                // If both the children are not leaf nodes, push the current
                // node along with its left and right child back into the stack.
                st.push(topNode->right);
                st.push(topNode->left);
            }
        }

        return evaluated[root] == 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean evaluateTree(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        HashMap<TreeNode, Boolean> evaluated = new HashMap<>();

        while (!st.isEmpty()) {
            TreeNode topNode = st.peek();

            // If the node is a leaf node, store its value in the evaluated hashmap
            // and continue
            if (topNode.left == null && topNode.right == null) {
                st.pop();
                evaluated.put(topNode, topNode.val == 1);
                continue;
            }

            // If both the children have already been evaluated, use their
            // values to evaluate the current node.
            if (evaluated.containsKey(topNode.left) &&
                evaluated.containsKey(topNode.right)) {
                st.pop();
                if (topNode.val == 2) {
                    evaluated.put(topNode,
                            evaluated.get(topNode.left) || evaluated.get(topNode.right));
                } else {
                    evaluated.put(topNode,
                            evaluated.get(topNode.left) && evaluated.get(topNode.right));
                }
            } else {
                // If both the children are not leaf nodes, push the current
                // node along with its left and right child back into the stack.
                st.push(topNode.right);
                st.push(topNode.left);
            }
        }
        
        return evaluated.get(root);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        stack = [root]
        evaluated = {}
        
        while stack:
            top_node = stack[-1]
            
            # If the node is a leaf node, store its value in the evaluated dictionary
            # and continue
            if not top_node.left and not top_node.right:
                stack.pop()
                evaluated[top_node] = top_node.val == 1
                continue
            
            # If both the children have already been evaluated, use their
            # values to evaluate the current node.
            if top_node.left in evaluated and top_node.right in evaluated:
                stack.pop()
                if top_node.val == 2:
                    evaluated[top_node] = evaluated[top_node.left] or evaluated[top_node.right]
                else:
                    evaluated[top_node] = evaluated[top_node.left] and evaluated[top_node.right]
            else:
                # If both the children are not leaf nodes, push the current
                # node along with its left and right child back into the stack.
                if top_node.left:
                    stack.append(top_node.left)
                if top_node.right:
                    stack.append(top_node.right)
        
        return evaluated[root]
```

</details>
