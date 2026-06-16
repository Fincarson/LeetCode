# 1602. Find Nearest Right Node in Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1602 - Find Nearest Right Node in Binary Tree](https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/)

## Problem

Given the root of a binary tree and a node u in the tree, return the nearest node on the same level that is to the right of u, or return null if u is the rightmost node in its level.

### Example 1

```text
Input: root = [1,2,3,null,4,5,6], u = 4
Output: 5
Explanation: The nearest node on the same level to the right of node 4 is node 5.
```

### Example 2

```text
Input: root = [3,null,4,2], u = 2
Output: null
Explanation: There are no nodes to the right of 2.
```

## Constraints

- The number of nodes in the tree is in the range [1, 105].
- 1 <= Node.val <= 105
- All values in the tree are distinct.
- u is a node in the binary tree rooted at root.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1602. Find Nearest Right Node in Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS: Two Queues | C++, Java, Python3 |
| BFS: One Queue + Sentinel | C++, Java, Python3 |
| BFS: One Queue + Level Size Measurements | C++, Java, Python3 |
| Recursive DFS: Preorder Traversal | C++, Java, Python3 |

## Approach 1: BFS: Two Queues

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == nullptr) {
            return nullptr;
        }
        // note that here we use a deque instead of a queue
        // because deque offers the clear() method, while queue
        // does not
        deque<TreeNode*> next_level;
        next_level.push_back(root);

        while (!next_level.empty()) {
            // prepare for next level
            deque<TreeNode*> curr_level(next_level);
            next_level.clear();

            while (!curr_level.empty()) {
                TreeNode* node = curr_level.front();
                curr_level.pop_front();

                if (node == u) {
                    return (curr_level.empty() ? nullptr : curr_level.front());
                }

                // add child nodes of the current level
                // in the queue for the next level
                if (node->left != nullptr) {
                    next_level.push_back(node->left);
                }
                if (node->right != nullptr) {
                    next_level.push_back(node->right);
                }
            }
        }
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;

        ArrayDeque<TreeNode> nextLevel = new ArrayDeque() {{ offer(root); }};
        ArrayDeque<TreeNode> currLevel = new ArrayDeque();

        TreeNode node = null;
        while (!nextLevel.isEmpty()) {
            // prepare for the next level
            currLevel = nextLevel.clone();
            nextLevel.clear();

            while (!currLevel.isEmpty()) {
                node = currLevel.poll();

                if (node == u)
                    return currLevel.poll();

                // add child nodes of the current level
                // in the queue for the next level
                if (node.left != null)
                    nextLevel.offer(node.left);
                if (node.right != null)
                    nextLevel.offer(node.right);
            }
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if root is None:
            return []

        next_level = deque([root,])
        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()

            while curr_level:
                node = curr_level.popleft()

                if node == u:
                    return curr_level.popleft() if curr_level else None
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
```

</details>

<br>

## Approach 2: BFS: One Queue + Sentinel

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr != nullptr) {
                // if it's the given node
                if (curr == u) {
                    return q.front();
                }

                // add child nodes in the queue
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            } else {
                // add a senitel to mark end of level
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;

        Queue<TreeNode> queue = new LinkedList(){{ offer(root); offer(null); }};
        TreeNode curr = null;

        while (!queue.isEmpty()) {
            curr = queue.poll();

            if (curr != null) {
                // if it's the given node
                if (curr == u)
                    return queue.poll();

                // add child nodes in the queue
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }
            } else {
                // add a sentinel to mark end of level
                if (!queue.isEmpty())
                    queue.offer(null);
            }
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if root is None:
            return None

        queue = deque([root, None,])
        while queue:
            curr = queue.popleft()

            # if it's the given node
            if curr == u:
                return queue.popleft()

            if curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
            else:
                # once the level is finished,
                # add a sentinel to mark end of level
                if queue:
                    queue.append(None)
```

</details>

<br>

## Approach 3: BFS: One Queue + Level Size Measurements

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t level_size = q.size();
            for (size_t i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                // if it's the given node
                if (curr == u) {
                    if (i == level_size - 1) {
                        return nullptr;
                    } else {
                        return q.front();
                    }
                }

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
        return nullptr;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode curr = queue.poll();
                // if it's the given node
                if (curr == u) {
                    if (i == levelSize - 1) {
                        return null;
                    }
                    else {
                        return queue.poll();
                    }
                }

                if (curr.left != null) queue.offer(curr.left);
                if (curr.right != null) queue.offer(curr.right);
            }
        }
        return null;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        if root is None:
            return None

        queue = deque([root,])
        while queue:
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()
                # if it's the given node
                if node == u:
                    return queue.popleft() if i != level_length - 1 else None

                # add child nodes in the queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
```

</details>

<br>

## Approach 4: Recursive DFS: Preorder Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int u_depth;
    TreeNode* next_node;
    TreeNode* target_node;

public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        this->u_depth = -1;
        this->target_node = u;
        this->next_node = nullptr;
        dfs(root, 0);
        return this->next_node;
    }

    void dfs(TreeNode* curr_node, int depth) {
        // the depth to look for next node is identified
        if (curr_node == this->target_node) {
            this->u_depth = depth;
            return;
        }

        // we're on the level to look for the next node
        if (depth == this->u_depth) {
            if (this->next_node == nullptr) {
                this->next_node = curr_node;
            }
            return;
        }

        // continue to traverse the tree
        if (curr_node->left != nullptr) {
            dfs(curr_node->left, depth + 1);
        }
        if (curr_node->right != nullptr) {
            dfs(curr_node->right, depth + 1);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int uDepth;
    private TreeNode nextNode, targetNode;

    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        uDepth = - 1;
        targetNode = u;
        nextNode = null;
        dfs(root, 0);
        return nextNode;
    }

    public void dfs(TreeNode currNode, int depth) {
        // the depth to look for next node is identified
        if (currNode == targetNode) {
            uDepth = depth;
            return;
        }

        // we're on the level to look for the next node
        if (depth == uDepth) {
            if (nextNode == null) nextNode = currNode;
            return;
        }

        // continue to traverse the tree
        if (currNode.left != null) dfs(currNode.left, depth + 1);
        if (currNode.right != null) dfs(currNode.right, depth + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        def dfs(current_node, depth):
            nonlocal u_depth, next_node
            # the depth to look for next node is identified
            if current_node == u:
                u_depth = depth
                return
            # we're on the level to look for the next node
            if depth == u_depth:
                # if this next node is not identified yet
                if next_node is None:
                    next_node = current_node
                return
            # continue to traverse the tree
            if current_node.left:
                dfs(current_node.left, depth + 1)
            if current_node.right:
                dfs(current_node.right, depth + 1)

        u_depth, next_node = -1, None
        dfs(root, 0)
        return next_node
```

</details>
