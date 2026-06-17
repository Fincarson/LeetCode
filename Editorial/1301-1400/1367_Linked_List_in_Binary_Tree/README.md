# 1367. Linked List in Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/linked-list-in-binary-tree/)  
`Linked List` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1367 - Linked List in Binary Tree](https://leetcode.com/problems/linked-list-in-binary-tree/)

## Problem

Given a binary tree root and a linked list with head as the first node.

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

### Example 1

```text
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.
```

### Example 2

```text
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
```

### Example 3

```text
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
```

## Constraints

- The number of nodes in the tree will be in the range [1, 2500].
- The number of nodes in the list will be in the range [1, 100].
- 1 <= Node.val <= 100 for each node in the linked list and binary tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1367. Linked List in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS | C++, Java, Python3 |
| Iterative Approach | C++, Java, Python3 |
| Knuth-Morris-Pratt (KMP) Algorithm | C++, Java, Python3 |

## Approach 1: DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return checkPath(root, head);
    }

private:
    bool checkPath(TreeNode* node, ListNode* head) {
        if (!node) return false;
        if (dfs(node, head)) return true;  // If a matching path is found
        // Recursively check left and right subtrees
        return checkPath(node->left, head) || checkPath(node->right, head);
    }

    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;  // All nodes in the list matched
        if (!node)
            return false;  // Reached end of tree without matching all nodes
        if (node->val != head->val) return false;  // Value mismatch
        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) return false;
        return checkPath(root, head);
    }

    private boolean checkPath(TreeNode node, ListNode head) {
        if (node == null) return false;
        if (dfs(node, head)) return true; // If a matching path is found
        // Recursively check left and right subtrees
        return checkPath(node.left, head) || checkPath(node.right, head);
    }

    private boolean dfs(TreeNode node, ListNode head) {
        if (head == null) return true; // All nodes in the list matched
        if (node == null) return false; // Reached end of tree without matching all nodes
        if (node.val != head.val) return false; // Value mismatch
        return dfs(node.left, head.next) || dfs(node.right, head.next);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubPath(
        self, head: Optional[ListNode], root: Optional[TreeNode]
    ) -> bool:
        if root is None:
            return False
        return self._check_path(root, head)

    def _check_path(
        self, node: Optional[TreeNode], head: Optional[ListNode]
    ) -> bool:
        if node is None:
            return False
        if self._dfs(node, head):
            return True  # If a matching path is found

        # Recursively check left and right subtrees
        return self._check_path(node.left, head) or self._check_path(
            node.right, head
        )

    def _dfs(self, node: Optional[TreeNode], head: Optional[ListNode]) -> bool:
        if head is None:
            return True  # All nodes in the list matched
        if node is None:
            return False  # Reached end of tree without matching all nodes
        if node.val != head.val:
            return False  # Value mismatch
        return self._dfs(node.left, head.next) or self._dfs(
            node.right, head.next
        )
```

</details>

<br>

## Approach 2: Iterative Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        // Initialize a stack for DFS on the tree
        stack<TreeNode*> nodes;
        nodes.push(root);

        // Perform DFS
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            // Check if the current node's path matches the linked list
            if (isMatch(node, head)) {
                return true;
            }

            // Push left and right children onto the stack
            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
        }

        return false;
    }

private:
    bool isMatch(TreeNode* node, ListNode* lst) {
        stack<pair<TreeNode*, ListNode*>> s;
        s.push({node, lst});

        while (!s.empty()) {
            auto [currentNode, currentList] = s.top();
            s.pop();

            while (currentNode && currentList) {
                if (currentNode->val != currentList->val) {
                    break;
                }
                currentList = currentList->next;

                if (currentList) {
                    if (currentNode->left) {
                        s.push({currentNode->left, currentList});
                    }
                    if (currentNode->right) {
                        s.push({currentNode->right, currentList});
                    }
                    break;
                }
            }

            if (!currentList) {
                return true;
            }
        }

        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubPath(ListNode head, TreeNode root) {
        if (root == null) return false;

        Stack<TreeNode> nodes = new Stack<>();
        nodes.push(root);

        while (!nodes.isEmpty()) {
            TreeNode node = nodes.pop();

            if (isMatch(node, head)) {
                return true;
            }

            if (node.left != null) {
                nodes.push(node.left);
            }
            if (node.right != null) {
                nodes.push(node.right);
            }
        }

        return false;
    }

    private boolean isMatch(TreeNode node, ListNode lst) {
        Stack<Map.Entry<TreeNode, ListNode>> s = new Stack<>();
        s.push(new HashMap.SimpleEntry<>(node, lst));

        while (!s.isEmpty()) {
            Map.Entry<TreeNode, ListNode> entry = s.pop();
            TreeNode currentNode = entry.getKey();
            ListNode currentList = entry.getValue();

            while (currentNode != null && currentList != null) {
                if (currentNode.val != currentList.val) {
                    break;
                }
                currentList = currentList.next;

                if (currentList != null) {
                    if (currentNode.left != null) {
                        s.push(
                            new HashMap.SimpleEntry<>(
                                currentNode.left,
                                currentList
                            )
                        );
                    }
                    if (currentNode.right != null) {
                        s.push(
                            new HashMap.SimpleEntry<>(
                                currentNode.right,
                                currentList
                            )
                        );
                    }
                    break;
                }
            }

            if (currentList == null) {
                return true;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubPath(
        self, head: Optional[ListNode], root: Optional[TreeNode]
    ) -> bool:
        if not root:
            return False
        stack = [root]

        while stack:
            node = stack.pop()

            if self._is_match(node, head):
                return True
            # Push left and right children onto the stack
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return False

    def _is_match(
        self, node: Optional[TreeNode], lst: Optional[ListNode]
    ) -> bool:
        # Stack to keep track of (current_tree_node, current_list_node)
        stack = [(node, lst)]

        while stack:
            current_node, current_list = stack.pop()

            while current_node and current_list:
                if current_node.val != current_list.val:
                    break
                current_list = current_list.next

                # Continue to the next node in the tree, left or right
                if current_list:
                    if current_node.left:
                        stack.append((current_node.left, current_list))
                    if current_node.right:
                        stack.append((current_node.right, current_list))
                    break
            if not current_list:
                return True
        return False
```

</details>

<br>

## Approach 3: Knuth-Morris-Pratt (KMP) Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // Build the pattern and prefix table from the linked list
        vector<int> pattern = {head->val}, prefixTable = {0};
        int patternIndex = 0;
        head = head->next;

        while (head) {
            while (patternIndex && head->val != pattern[patternIndex])
                patternIndex = prefixTable[patternIndex - 1];
            patternIndex += head->val == pattern[patternIndex];
            pattern.push_back(head->val);
            prefixTable.push_back(patternIndex);
            head = head->next;
        }

        // Perform DFS to search for the pattern in the tree
        return searchInTree(root, 0, pattern, prefixTable);
    }

private:
    bool searchInTree(TreeNode* node, int patternIndex,
                      const vector<int>& pattern,
                      const vector<int>& prefixTable) {
        if (!node) return false;

        while (patternIndex && node->val != pattern[patternIndex])
            patternIndex = prefixTable[patternIndex - 1];
        patternIndex += node->val == pattern[patternIndex];

        // Check if the pattern is fully matched
        if (patternIndex == pattern.size()) return true;

        // Recursively search left and right subtrees
        return searchInTree(node->left, patternIndex, pattern, prefixTable) ||
               searchInTree(node->right, patternIndex, pattern, prefixTable);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubPath(ListNode head, TreeNode root) {
        // Build the pattern and prefix table from the linked list
        List<Integer> pattern = new ArrayList<>();
        List<Integer> prefixTable = new ArrayList<>();
        pattern.add(head.val);
        prefixTable.add(0);
        int patternIndex = 0;
        head = head.next;

        while (head != null) {
            while (patternIndex > 0 && head.val != pattern.get(patternIndex)) {
                patternIndex = prefixTable.get(patternIndex - 1);
            }
            patternIndex += head.val == pattern.get(patternIndex) ? 1 : 0;
            pattern.add(head.val);
            prefixTable.add(patternIndex);
            head = head.next;
        }

        // Perform DFS to search for the pattern in the tree
        return searchInTree(root, 0, pattern, prefixTable);
    }

    private boolean searchInTree(
        TreeNode node,
        int patternIndex,
        List<Integer> pattern,
        List<Integer> prefixTable
    ) {
        if (node == null) return false;

        while (patternIndex > 0 && node.val != pattern.get(patternIndex)) {
            patternIndex = prefixTable.get(patternIndex - 1);
        }
        patternIndex += node.val == pattern.get(patternIndex) ? 1 : 0;

        // Check if the pattern is fully matched
        if (patternIndex == pattern.size()) return true;

        // Recursively search left and right subtrees
        return (
            searchInTree(node.left, patternIndex, pattern, prefixTable) ||
            searchInTree(node.right, patternIndex, pattern, prefixTable)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubPath(
        self, head: Optional[ListNode], root: Optional[TreeNode]
    ) -> bool:

        # Build the pattern and prefix table from the linked list
        pattern = [head.val]
        prefix_table = [0]
        pattern_index = 0
        head = head.next

        while head:
            while pattern_index > 0 and head.val != pattern[pattern_index]:
                pattern_index = prefix_table[pattern_index - 1]
            pattern_index += 1 if head.val == pattern[pattern_index] else 0
            pattern.append(head.val)
            prefix_table.append(pattern_index)
            head = head.next

        # Perform DFS to search for the pattern in the tree
        return self._search_in_tree(root, 0, pattern, prefix_table)

    def _search_in_tree(
        self,
        node: Optional[TreeNode],
        pattern_index: int,
        pattern: List[int],
        prefix_table: List[int],
    ) -> bool:
        if not node:
            return False

        while pattern_index > 0 and node.val != pattern[pattern_index]:
            pattern_index = prefix_table[pattern_index - 1]
        pattern_index += 1 if node.val == pattern[pattern_index] else 0

        # Check if the pattern is fully matched
        if pattern_index == len(pattern):
            return True

        # Recursively search left and right subtrees
        return self._search_in_tree(
            node.left, pattern_index, pattern, prefix_table
        ) or self._search_in_tree(
            node.right, pattern_index, pattern, prefix_table
        )
```

</details>
