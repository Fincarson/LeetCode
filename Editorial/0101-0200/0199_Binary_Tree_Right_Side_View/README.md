# 199. Binary Tree Right Side View

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-right-side-view/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 199 - Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

## Problem

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

### Example 1

### Example 2

### Example 3

### Example 4

## Constraints

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 199. Binary Tree Right Side View

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS: Two Queues | C++, Java, Python3 |
| BFS: One Queue + Sentinel | C++, Java, Python3 |
| BFS: One Queue + Level Size Measurements | C++, Java, Python3 |
| Recursive DFS | C++, Java, Python3 |

## Approach 1: BFS: Two Queues

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();

        deque<TreeNode*> nextLevel{root};
        deque<TreeNode*> currLevel;
        vector<int> rightside;

        TreeNode* node = nullptr;
        while (!nextLevel.empty()) {
            currLevel = nextLevel;
            nextLevel.clear();

            while (!currLevel.empty()) {
                node = currLevel.front();
                currLevel.pop_front();

                if (node->left != nullptr) nextLevel.push_back(node->left);
                if (node->right != nullptr) nextLevel.push_back(node->right);
            }

            rightside.push_back(node->val);
        }
        return rightside;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList<Integer>();

        ArrayDeque<TreeNode> nextLevel = new ArrayDeque() {
            {
                offer(root);
            }
        };
        ArrayDeque<TreeNode> currLevel = new ArrayDeque();
        List<Integer> rightside = new ArrayList();

        TreeNode node = null;
        while (!nextLevel.isEmpty()) {
            // prepare for the next level
            currLevel = nextLevel;
            nextLevel = new ArrayDeque<>();

            while (!currLevel.isEmpty()) {
                node = currLevel.poll();

                // add child nodes of the current level
                // in the queue for the next level
                if (node.left != null) nextLevel.offer(node.left);
                if (node.right != null) nextLevel.offer(node.right);
            }

            // The current level is finished.
            // Its last element is the rightmost one.
            rightside.add(node.val);
        }
        return rightside;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        next_level = deque(
            [
                root,
            ]
        )
        rightside = []

        while next_level:
            # prepare for the next level
            curr_level = next_level
            next_level = deque()

            while curr_level:
                node = curr_level.popleft()

                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            # The current level is finished.
            # Its last element is the rightmost one.
            rightside.append(node.val)

        return rightside
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return vector<int>();

        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(NULL);
        TreeNode *prev, *curr = root;
        vector<int> rightside;

        while (!queue.empty()) {
            prev = curr;
            curr = queue.front();
            queue.pop();

            while (curr != NULL) {
                // add child nodes in the queue
                if (curr->left != NULL) {
                    queue.push(curr->left);
                }
                if (curr->right != NULL) {
                    queue.push(curr->right);
                }

                prev = curr;
                curr = queue.front();
                queue.pop();
            }

            // the current level is finished
            // and prev is its rightmost element
            rightside.push_back(prev->val);

            // add a sentinel to mark the end
            // of the next level
            if (!queue.empty()) queue.push(NULL);
        }
        return rightside;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList<Integer>();

        Queue<TreeNode> queue = new LinkedList() {
            {
                offer(root);
                offer(null);
            }
        };
        TreeNode prev, curr = root;
        List<Integer> rightside = new ArrayList();

        while (!queue.isEmpty()) {
            prev = curr;
            curr = queue.poll();

            while (curr != null) {
                // add child nodes in the queue
                if (curr.left != null) {
                    queue.offer(curr.left);
                }
                if (curr.right != null) {
                    queue.offer(curr.right);
                }

                prev = curr;
                curr = queue.poll();
            }

            // the current level is finished
            // and prev is its rightmost element
            rightside.add(prev.val);

            // add a sentinel to mark the end
            // of the next level
            if (!queue.isEmpty()) queue.offer(null);
        }
        return rightside;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        queue = deque(
            [
                root,
                None,
            ]
        )
        rightside = []

        curr = root
        while queue:
            prev, curr = curr, queue.popleft()

            while curr:
                # add child nodes in the queue
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)

                prev, curr = curr, queue.popleft()

            # the current level is finished
            # and prev is its rightmost element
            rightside.append(prev.val)

            # add a sentinel to mark the end
            # of the next level
            if queue:
                queue.append(None)

        return rightside
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        deque<TreeNode*> queue;
        queue.push_back(root);
        vector<int> rightside;

        while (!queue.empty()) {
            int levelLength = queue.size();

            for (int i = 0; i < levelLength; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();

                // if it's the rightmost element
                if (i == levelLength - 1) {
                    rightside.push_back(node->val);
                }

                // add child nodes in the queue
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
            }
        }
        return rightside;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList<Integer>();

        ArrayDeque<TreeNode> queue = new ArrayDeque() {
            {
                offer(root);
            }
        };
        List<Integer> rightside = new ArrayList();

        while (!queue.isEmpty()) {
            int levelLength = queue.size();

            for (int i = 0; i < levelLength; ++i) {
                TreeNode node = queue.poll();

                // if it's the rightmost element
                if (i == levelLength - 1) {
                    rightside.add(node.val);
                }

                // add child nodes in the queue
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
        }
        return rightside;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        queue = deque(
            [
                root,
            ]
        )
        rightside = []

        while queue:
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()

                # if it's the rightmost element
                if i == level_length - 1:
                    rightside.append(node.val)

                # add child nodes in the queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return rightside
```

</details>

<br>

## Approach 4: Recursive DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> rightside;

    void helper(TreeNode* node, int level) {
        if (level == rightside.size()) rightside.push_back(node->val);

        if (node->right != nullptr) helper(node->right, level + 1);
        if (node->left != nullptr) helper(node->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return rightside;

        helper(root, 0);
        return rightside;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    List<Integer> rightside = new ArrayList();

    public void helper(TreeNode node, int level) {
        if (level == rightside.size()) rightside.add(node.val);

        if (node.right != null) helper(node.right, level + 1);
        if (node.left != null) helper(node.left, level + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return rightside;

        helper(root, 0);
        return rightside;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        rightside = []

        def helper(node: TreeNode, level: int) -> None:
            if level == len(rightside):
                rightside.append(node.val)
            for child in [node.right, node.left]:
                if child:
                    helper(child, level + 1)

        helper(root, 0)
        return rightside
```

</details>
