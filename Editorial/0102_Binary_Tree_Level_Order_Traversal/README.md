# 102. Binary Tree Level Order Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-level-order-traversal/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 102 - Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Problem

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

### Example 2

```text
Input: root = [1]
Output: [[1]]
```

### Example 3

```text
Input: root = []
Output: []
```

## Constraints

- The number of nodes in the tree is in the range [0, 2000].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Number of Operations to Sort a Binary Tree by Level](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Divide Nodes Into the Maximum Number of Groups](https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 102. Binary Tree Level Order Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    int** res = malloc(sizeof(int*));
    *returnColumnSizes = malloc(sizeof(int));
    *returnSize = 0;
    if (root == NULL) return res;
    struct TreeNode* queue[10000];
    int front = 0, rear = -1, lastLevelNode = 0, cnt = 1;
    queue[++rear] = root;
    while (cnt > 0) {
        int* level = malloc(sizeof(int) * cnt);
        *returnColumnSizes =
            realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));
        (*returnColumnSizes)[*returnSize] = cnt;
        for (int i = 0; i < cnt; i++) {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;
            if (node->left != NULL) queue[++rear] = node->left;
            if (node->right != NULL) queue[++rear] = node->right;
        }
        res = realloc(res, sizeof(int*) * (*returnSize + 1));
        res[(*returnSize)++] = level;
        cnt = rear - lastLevelNode;
        lastLevelNode = rear;
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> levels;
    void helper(TreeNode* node, int level) {
        if (levels.size() == level) levels.push_back(vector<int>());
        levels[level].push_back(node->val);
        if (node->left != nullptr) helper(node->left, level + 1);
        if (node->right != nullptr) helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return levels;
        helper(root, 0);
        return levels;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    IList<IList<int>> levels = new List<IList<int>>();

    public void Helper(TreeNode node, int level) {
        if (levels.Count == level)
            levels.Add(new List<int>());
        levels[level].Add(node.val);
        if (node.left != null)
            Helper(node.left, level + 1);
        if (node.right != null)
            Helper(node.right, level + 1);
    }

    public IList<IList<int>> LevelOrder(TreeNode root) {
        if (root == null)
            return levels;
        Helper(root, 0);
        return levels;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func levelOrder(root *TreeNode) [][]int {
    levels := [][]int{}
    var helper func(*TreeNode, int)
    helper = func(node *TreeNode, level int) {
        if len(levels) == level {
            levels = append(levels, []int{})
        }
        levels[level] = append(levels[level], node.Val)
        if node.Left != nil {
            helper(node.Left, level+1)
        }
        if node.Right != nil {
            helper(node.Right, level+1)
        }
    }
    if root != nil {
        helper(root, 0)
    }
    return levels
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();

    public void helper(TreeNode node, int level) {
        // start the current level
        if (levels.size() == level) levels.add(new ArrayList<Integer>());

        // fulfil the current level
        levels.get(level).add(node.val);

        // process child nodes for the next level
        if (node.left != null) helper(node.left, level + 1);
        if (node.right != null) helper(node.right, level + 1);
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        return levels;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var levelOrder = function (root) {
    let levels = [];
    function helper(node, level) {
        if (levels.length === level) levels.push([]);
        levels[level].push(node.val);
        if (node.left !== null) helper(node.left, level + 1);
        if (node.right !== null) helper(node.right, level + 1);
    }
    if (root !== null) helper(root, 0);
    return levels;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if not root:
            return levels

        def helper(node: TreeNode, level: int) -> None:
            # start the current level
            if len(levels) == level:
                levels.append([])

            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)

        helper(root, 0)
        return levels
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function levelOrder(root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    function helper(node: TreeNode, level: number) {
        if (levels.length === level) levels.push([]);
        levels[level].push(node.val);
        if (node.left !== null) helper(node.left, level + 1);
        if (node.right !== null) helper(node.right, level + 1);
    }
    if (root !== null) helper(root, 0);
    return levels;
}
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) return NULL;
    typedef struct Node {
        void* data;
        struct Node* next;
    } Node;
    typedef struct Queue {
        Node* head;
        Node* tail;
    } Queue;
    Queue* createQueue() {
        Queue* queue = malloc(sizeof(Queue));
        queue->head = queue->tail = NULL;
        return queue;
    }
    void push(Queue * queue, void* data) {
        Node* node = malloc(sizeof(Node));
        node->data = data;
        node->next = NULL;
        if (queue->head == NULL) {
            queue->head = queue->tail = node;
        } else {
            queue->tail = queue->tail->next = node;
        }
    }
    void* pop(Queue * queue) {
        if (!queue->head) return NULL;
        Node* head = queue->head;
        void* data = head->data;
        queue->head = queue->head->next;
        if (queue->head == NULL) queue->tail = NULL;
        free(head);
        return data;
    }
    size_t size(Queue * queue) {
        size_t count = 0;
        for (Node* node = queue->head; node; node = node->next) count++;
        return count;
    }
    int isEmpty(Queue * queue) { return queue->head == NULL; }
    Queue* queue = createQueue();
    push(queue, root);
    int** levels = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    while (!isEmpty(queue)) {
        int level_size = size(queue);
        levels[*returnSize] = malloc(sizeof(int) * level_size);
        (*returnColumnSizes)[*returnSize] = level_size;
        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = pop(queue);
            levels[*returnSize][i] = node->val;
            if (node->left) push(queue, node->left);
            if (node->right) push(queue, node->right);
        }
        (*returnSize)++;
    }
    return levels;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) return levels;
        deque<TreeNode*> queue;
        queue.push_back(root);
        int level = 0;
        while (!queue.empty()) {
            // start the current level
            levels.push_back({});
            // number of elements in the current level
            int level_length = queue.size();
            for (int i = 0; i < level_length; ++i) {
                TreeNode* node = queue.front();
                queue.pop_front();
                // fulfill the current level
                levels[level].push_back(node->val);
                // add child nodes of the current level
                // in the queue for the next level
                if (node->left != NULL) queue.push_back(node->left);
                if (node->right != NULL) queue.push_back(node->right);
            }
            // go to next level
            level++;
        }
        return levels;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        List<IList<int>> levels = new List<IList<int>>();
        if (root == null)
            return levels;
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);
        int level = 0;
        while (queue.Count > 0) {
            // start the current level
            levels.Add(new List<int>());
            // number of elements in the current level
            int level_length = queue.Count;
            for (int i = 0; i < level_length; ++i) {
                TreeNode node = queue.Dequeue();
                // fulfill the current level
                levels[level].Add(node.val);
                // add child nodes of the current level
                // in the queue for the next level
                if (node.left != null)
                    queue.Enqueue(node.left);
                if (node.right != null)
                    queue.Enqueue(node.right);
            }

            // go to the next level
            level++;
        }

        return levels;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
import llq "github.com/emirpasic/gods/queues/linkedlistqueue"

func levelOrder(root *TreeNode) [][]int {
    var levels [][]int
    if root == nil {
        return levels
    }

    queue := llq.New()  // Initialize a new queue
    queue.Enqueue(root) // Start with the root node

    for !queue.Empty() {
        levelSize := queue.Size()
        currentLevel := make([]int, 0, levelSize)

        for i := 0; i < levelSize; i++ {
            node, _ := queue.Dequeue() // Dequeue returns (interface{}, bool)
            treeNode := node.(*TreeNode)

            currentLevel = append(
                currentLevel,
                treeNode.Val,
            ) // Fulfill the current level

            if treeNode.Left != nil {
                queue.Enqueue(treeNode.Left) // Enqueue left child
            }
            if treeNode.Right != nil {
                queue.Enqueue(treeNode.Right) // Enqueue right child
            }
        }

        levels = append(
            levels,
            currentLevel,
        ) // Append the current level to the results
    }

    return levels
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        if (root == null) return levels;

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        int level = 0;
        while (!queue.isEmpty()) {
            // start the current level
            levels.add(new ArrayList<Integer>());

            // number of elements in the current level
            int level_length = queue.size();
            for (int i = 0; i < level_length; ++i) {
                TreeNode node = queue.remove();

                // fulfill the current level
                levels.get(level).add(node.val);

                // add child nodes of the current level
                // in the queue for the next level
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            // go to next level
            level++;
        }
        return levels;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var levelOrder = function (root) {
    var levels = [];
    if (root === null) return levels;
    var queue = [root];
    var level = 0;
    while (queue.length !== 0) {
        // Start the current level
        levels.push([]);
        // Number of elements in the current level
        var level_length = queue.length;
        for (var i = 0; i < level_length; i++) {
            var node = queue.shift();
            // fulfill the current level
            levels[level].push(node.val);
            // add child nodes of the current level
            // in the queue for the next level
            if (node.left !== null) queue.push(node.left);
            if (node.right !== null) queue.push(node.right);
        }
        // go to next level
        level++;
    }
    return levels;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from collections import deque


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if not root:
            return levels

        level = 0
        queue = deque(
            [
                root,
            ]
        )
        while queue:
            # start the current level
            levels.append([])
            # number of elements in the current level
            level_length = len(queue)

            for i in range(level_length):
                node = queue.popleft()
                # fulfill the current level
                levels[level].append(node.val)

                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # go to next level
            level += 1

        return levels
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const levelOrder = function (root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    if (!root) return levels;
    let queue: TreeNode[] = [root];
    let level: number = 0;
    while (queue.length) {
        // Start the current level
        levels.push([]);
        // Number of elements in the current level
        let level_length: number = queue.length;
        for (let i = 0; i < level_length; ++i) {
            let node: TreeNode | undefined = queue.shift();
            // Fulfill the current level
            if (node) levels[level].push(node.val);
            // Add child nodes of the current level
            // In the queue for the next level
            if (node?.left) queue.push(node.left);
            if (node?.right) queue.push(node.right);
        }
        // Go to next level
        level++;
    }
    return levels;
};
```

</details>
