# 103. Binary Tree Zigzag Level Order Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 103 - Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

## Problem

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 103. Binary Tree Zigzag Level Order Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| BFS (Breadth-First Search) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| DFS (Depth-First Search) | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: BFS (Breadth-First Search)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct QueueNode {
    struct TreeNode* tree_node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
    int size;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp =
        (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->tree_node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->tree_node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int isEmpty(struct Queue* q) { return q->front == NULL; }

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue* nodeQueue = createQueue();
    enqueue(nodeQueue, root);
    enqueue(nodeQueue, NULL);  // Delimiter for levels

    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    bool leftToRight = true;

    int* currentLevel =
        malloc(1000 * sizeof(int));  // Assuming level width max is 1000
    int currentLevelSize = 0;

    while (!isEmpty(nodeQueue)) {
        struct TreeNode* node = dequeue(nodeQueue);

        if (node) {
            if (leftToRight) {
                currentLevel[currentLevelSize++] = node->val;
            } else {
                memmove(&currentLevel[1], &currentLevel[0],
                        currentLevelSize * sizeof(int));
                currentLevel[0] = node->val;
                currentLevelSize++;
            }

            if (node->left) enqueue(nodeQueue, node->left);
            if (node->right) enqueue(nodeQueue, node->right);
        } else {
            int* newLevel = malloc(currentLevelSize * sizeof(int));
            memcpy(newLevel, currentLevel, currentLevelSize * sizeof(int));

            int** tempResult =
                realloc(result, (*returnSize + 1) * sizeof(int*));
            result = tempResult;
            result[*returnSize] = newLevel;

            int* tempCols =
                realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
            *returnColumnSizes = tempCols;
            (*returnColumnSizes)[*returnSize] = currentLevelSize;
            (*returnSize)++;

            currentLevelSize = 0;  // Reset for next level
            leftToRight = !leftToRight;
            if (!isEmpty(nodeQueue))
                enqueue(nodeQueue, NULL);  // Delimiter for new level
        }
    }

    free(currentLevel);
    free(nodeQueue);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// Definition for a binary tree node.
//  struct TreeNode {
//      int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>();
        vector<vector<int>> result;
        deque<TreeNode*> node_queue;
        node_queue.push_back(root);
        node_queue.push_back(nullptr);  // Delimiter for a single level
        deque<int> level_list;
        bool is_order_left = true;
        while (!node_queue.empty()) {
            TreeNode* temp = node_queue.front();
            node_queue.pop_front();
            if (temp != nullptr) {
                if (is_order_left)
                    level_list.push_back(temp->val);
                else
                    level_list.push_front(temp->val);
                if (temp->left) node_queue.push_back(temp->left);
                if (temp->right) node_queue.push_back(temp->right);
            } else {
                // Add current level to result and prepare for the next level
                result.push_back(
                    vector<int>{level_list.begin(), level_list.end()});
                level_list.clear();
                if (!node_queue.empty()) node_queue.push_back(nullptr);
                is_order_left = !is_order_left;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        List<IList<int>> result = new List<IList<int>>();
        if (root == null)
            return result;
        Queue<TreeNode> nodeQueue = new Queue<TreeNode>();
        nodeQueue.Enqueue(root);
        nodeQueue.Enqueue(null);
        LinkedList<int> levelList = new LinkedList<int>();
        bool isOrderLeft = true;
        while (nodeQueue.Count > 0) {
            TreeNode currentNode = nodeQueue.Dequeue();
            if (currentNode != null) {
                if (isOrderLeft)
                    levelList.AddLast(currentNode.val);
                else
                    levelList.AddFirst(currentNode.val);
                if (currentNode.left != null)
                    nodeQueue.Enqueue(currentNode.left);
                if (currentNode.right != null)
                    nodeQueue.Enqueue(currentNode.right);
            } else {
                result.Add(new List<int>(levelList));
                levelList.Clear();
                if (nodeQueue.Count > 0)
                    nodeQueue.Enqueue(null);
                isOrderLeft = !isOrderLeft;
            }
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return nil
    }
    var res [][]int
    nodeQueue := []*TreeNode{root, nil}
    levelList := []int{}
    isOrderLeft := true
    for len(nodeQueue) > 0 {
        currNode := nodeQueue[0]
        nodeQueue = nodeQueue[1:]
        if currNode != nil {
            if isOrderLeft {
                levelList = append(levelList, currNode.Val)
            } else {
                levelList = append([]int{currNode.Val}, levelList...)
            }
            if currNode.Left != nil {
                nodeQueue = append(nodeQueue, currNode.Left)
            }
            if currNode.Right != nil {
                nodeQueue = append(nodeQueue, currNode.Right)
            }
        } else {
            res = append(res, levelList)
            levelList = []int{}
            if len(nodeQueue) > 0 {
                nodeQueue = append(nodeQueue, nil)
            }
            isOrderLeft = !isOrderLeft
        }
    }
    return res
}
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }

        List<List<Integer>> results = new ArrayList<List<Integer>>();

        // add the root element with a delimiter to kick off the BFS loop
        LinkedList<TreeNode> node_queue = new LinkedList<TreeNode>();
        node_queue.addLast(root);
        node_queue.addLast(null);

        LinkedList<Integer> level_list = new LinkedList<Integer>();
        boolean is_order_left = true;

        while (node_queue.size() > 0) {
            TreeNode curr_node = node_queue.pollFirst();
            if (curr_node != null) {
                if (is_order_left) level_list.addLast(curr_node.val);
                else level_list.addFirst(curr_node.val);

                if (curr_node.left != null) node_queue.addLast(curr_node.left);
                if (curr_node.right != null) node_queue.addLast(
                    curr_node.right
                );
            } else {
                // we finish the scan of one level
                results.add(level_list);
                level_list = new LinkedList<Integer>();
                // prepare for the next level
                if (node_queue.size() > 0) node_queue.addLast(null);
                is_order_left = !is_order_left;
            }
        }
        return results;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function (root) {
    if (root === null) return [];
    const results = [];
    const node_queue = [root, null];
    const level_list = [];
    let is_order_left = true;
    while (node_queue.length > 0) {
        const curr_node = node_queue.shift();
        if (curr_node !== null) {
            if (is_order_left) level_list.push(curr_node.val);
            else level_list.unshift(curr_node.val);
            if (curr_node.left !== null) node_queue.push(curr_node.left);
            if (curr_node.right !== null) node_queue.push(curr_node.right);
        } else {
            results.push([...level_list]);
            level_list.length = 0;
            if (node_queue.length > 0) node_queue.push(null);
            is_order_left = !is_order_left;
        }
    }
    return results;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x: int):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ret = []
        level_list = deque()
        if root is None:
            return []
        # start with the level 0 with a delimiter
        node_queue = deque([root, None])
        is_order_left = True

        while len(node_queue) > 0:
            curr_node = node_queue.popleft()

            if curr_node:
                if is_order_left:
                    level_list.append(curr_node.val)
                else:
                    level_list.appendleft(curr_node.val)

                if curr_node.left:
                    node_queue.append(curr_node.left)
                if curr_node.right:
                    node_queue.append(curr_node.right)
            else:
                # we finish one level
                ret.append(list(level_list))
                # add a delimiter to mark the level
                if len(node_queue) > 0:
                    node_queue.append(None)

                # prepare for the next level
                level_list = deque()
                is_order_left = not is_order_left

        return ret
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function zigzagLevelOrder(root: TreeNode | null): number[][] {
    let res: number[][] = [];
    if (root === null) return res;
    let queue: (TreeNode | null)[] = [root, null];
    let levelVals: number[] = [],
        dir = 1;
    while (queue.length > 0) {
        let node: TreeNode | null | undefined = queue.shift();
        if (node !== null) {
            if (dir === 1) levelVals.push(node.val);
            else levelVals.unshift(node.val);
            if (node.left !== null) queue.push(node.left);
            if (node.right !== null) queue.push(node.right);
        } else {
            res.push(levelVals);
            levelVals = [];
            if (queue.length) queue.push(null);
            dir *= -1;
        }
    }
    return res;
}
```

</details>

<br>

## Approach 2: DFS (Depth-First Search)

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *head;
    Node *tail;
    int size;
} Deque;

// Deque functions
Deque *createDeque() {
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    if (!dq) return NULL;
    dq->head = dq->tail = NULL;
    dq->size = 0;
    return dq;
}

void pushFront(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->value = value;
    newNode->next = dq->head;
    newNode->prev = NULL;
    if (dq->head)
        dq->head->prev = newNode;
    else
        dq->tail = newNode;
    dq->head = newNode;
    dq->size++;
}

void pushBack(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = dq->tail;
    if (dq->tail)
        dq->tail->next = newNode;
    else
        dq->head = newNode;
    dq->tail = newNode;
    dq->size++;
}

// Free deque memory
void freeDeque(Deque *dq) {
    Node *current = dq->head, *tmp;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(dq);
}

// DFS function to fill the deque according to the zigzag order
void DFS(struct TreeNode *node, int level, Deque **levels, int *maxLevel) {
    if (!node) return;
    if (level > *maxLevel) {
        *maxLevel = level;
        levels[level] = createDeque();
    }
    if (level % 2 == 0)
        pushBack(levels[level], node->val);
    else
        pushFront(levels[level], node->val);

    DFS(node->left, level + 1, levels, maxLevel);
    DFS(node->right, level + 1, levels, maxLevel);
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
    Deque *levels[1000];  // Max 1000 levels for simplicity
    int maxLevel = -1;
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    DFS(root, 0, levels, &maxLevel);
    *returnSize = maxLevel + 1;
    int **results = malloc(*returnSize * sizeof(int *));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));

    for (int i = 0; i <= maxLevel; i++) {
        (*returnColumnSizes)[i] = levels[i]->size;
        results[i] = malloc(levels[i]->size * sizeof(int));
        Node *current = levels[i]->head;
        for (int j = 0; j < levels[i]->size; j++) {
            results[i][j] = current->value;
            current = current->next;
        }
        freeDeque(levels[i]);
    }
    return results;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<deque<int>> results;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int level) {
            if (level >= results.size()) {
                results.emplace_back(deque<int>(1, node->val));
            } else {
                if (level % 2 == 0)
                    results[level].push_back(node->val);
                else
                    results[level].push_front(node->val);
            }
            if (node->left != nullptr) dfs(node->left, level + 1);
            if (node->right != nullptr) dfs(node->right, level + 1);
        };
        dfs(root, 0);
        vector<vector<int>> final_results;
        for (auto r : results) {
            final_results.push_back(vector<int>{r.begin(), r.end()});
        }
        return final_results;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/* Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new List<IList<int>>();
        }

        List<List<int>> results = new List<List<int>>();
        Action<TreeNode, int> dfs = null;
        dfs = (node, level) => {
            if (level >= results.Count) {
                results.Add(new List<int>() { node.val });
            } else {
                if (level % 2 == 0)
                    results[level].Add(node.val);
                else
                    results[level].Insert(0, node.val);
            }

            if (node.left != null)
                dfs(node.left, level + 1);
            if (node.right != null)
                dfs(node.right, level + 1);
        };
        dfs(root, 0);
        return results.ToArray();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/* Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
    if root == nil {
        return [][]int{}
    }
    results := [][]int{}
    var dfs func(node *TreeNode, level int)
    dfs = func(node *TreeNode, level int) {
        if level >= len(results) {
            results = append(results, []int{node.Val})
        } else {
            if level%2 == 0 {
                results[level] = append(results[level], node.Val)
            } else {
                results[level] = append([]int{node.Val}, results[level]...)
            }
        }
        if node.Left != nil {
            dfs(node.Left, level+1)
        }
        if node.Right != nil {
            dfs(node.Right, level+1)
        }
    }
    dfs(root, 0)
    return results
}
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    protected void DFS(TreeNode node, int level, List<List<Integer>> results) {
        if (level >= results.size()) {
            LinkedList<Integer> newLevel = new LinkedList<Integer>();
            newLevel.add(node.val);
            results.add(newLevel);
        } else {
            if (level % 2 == 0) results.get(level).add(node.val);
            else results.get(level).add(0, node.val);
        }

        if (node.left != null) DFS(node.left, level + 1, results);
        if (node.right != null) DFS(node.right, level + 1, results);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        DFS(root, 0, results);
        return results;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/* Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
var zigzagLevelOrder = function (root) {
    if (root == null) {
        return [];
    }
    let results = [];
    let dfs = function (node, level) {
        if (level >= results.length) {
            results.push([node.val]);
        } else {
            if (level % 2 == 0) results[level].push(node.val);
            else results[level].unshift(node.val);
        }
        if (node.left != null) dfs(node.left, level + 1);
        if (node.right != null) dfs(node.right, level + 1);
    };
    dfs(root, 0);
    return results;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        results = []

        def dfs(node: TreeNode, level: int) -> None:
            if level >= len(results):
                results.append(deque([node.val]))
            else:
                if level % 2 == 0:
                    results[level].append(node.val)
                else:
                    results[level].appendleft(node.val)

            for next_node in [node.left, node.right]:
                if next_node is not None:
                    dfs(next_node, level + 1)

        # normal level order traversal with DFS
        dfs(root, 0)

        return [list(level) for level in results]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *    val: number
 *    left: TreeNode | null
 *    right: TreeNode | null
 *    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *        this.val = (val===undefined ? 0 : val)
 *        this.left = (left===undefined ? null : left)
 *        this.right = (right===undefined ? null : right)
 *    }
 * }
 */
function zigzagLevelOrder(root: TreeNode | null): number[][] {
    if (root == null) {
        return [];
    }
    let results: number[][] = [];
    let dfs = function (node: TreeNode | null, level: number) {
        if (level >= results.length) {
            results.push([node.val]);
        } else {
            if (level % 2 == 0) results[level].push(node.val);
            else results[level].unshift(node.val);
        }
        if (node.left != null) dfs(node.left, level + 1);
        if (node.right != null) dfs(node.right, level + 1);
    };
    dfs(root, 0);
    return results;
}
```

</details>
