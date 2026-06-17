# 107. Binary Tree Level Order Traversal II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)  
`Tree` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 107 - Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

## Problem

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
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
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 107. Binary Tree Level Order Traversal II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion: DFS Preorder Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iteration: BFS Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion: DFS Preorder Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
void helper(struct TreeNode* node, int level, int* returnSize,
            int** columnSizes, int*** levels) {
    // start the current level
    if (*returnSize == level) {
        (*returnSize)++;
        *columnSizes = (int*)realloc(*columnSizes, (*returnSize) * sizeof(int));
        (*columnSizes)[level] = 0;
        *levels = (int**)realloc(*levels, (*returnSize) * sizeof(int*));
        (*levels)[level] = (int*)malloc(1000 * sizeof(int));
    }
    // append the current node value
    (*levels)[level][(*columnSizes)[level]++] = node->val;
    // process child nodes for the next level
    if (node->left != NULL)
        helper(node->left, level + 1, returnSize, columnSizes, levels);
    if (node->right != NULL)
        helper(node->right, level + 1, returnSize, columnSizes, levels);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize,
                       int** columnSizes) {
    *returnSize = 0;
    *columnSizes = NULL;
    int** levels = NULL;
    if (root != NULL) helper(root, 0, returnSize, columnSizes, &levels);
    // reverse the levels
    for (int i = 0; i < *returnSize / 2; i++) {
        int* tmp = levels[i];
        levels[i] = levels[*returnSize - 1 - i];
        levels[*returnSize - 1 - i] = tmp;
        int tmp_size = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - 1 - i];
        (*columnSizes)[*returnSize - 1 - i] = tmp_size;
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
    vector<vector<int>> levels;
    void helper(TreeNode* node, int level) {
        // start the current level
        if (levels.size() == level) levels.push_back(vector<int>());
        // append the current node value
        levels[level].push_back(node->val);
        // process child nodes for the next level
        if (node->left != NULL) helper(node->left, level + 1);
        if (node->right != NULL) helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return levels;
        helper(root, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    List<IList<int>> levels = new List<IList<int>>();

    public void Helper(TreeNode node, int level) {
        if (levels.Count == level)
            levels.Add(new List<int>());
        levels[level].Add(node.val);
        if (node.left != null)
            Helper(node.left, level + 1);
        if (node.right != null)
            Helper(node.right, level + 1);
    }

    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        if (root == null)
            return levels;
        Helper(root, 0);
        levels.Reverse();
        return levels;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func levelOrderBottom(root *TreeNode) [][]int {
    levels := make([][]int, 0)
    var helper func(node *TreeNode, level int)
    helper = func(node *TreeNode, level int) {
        if node == nil {
            return
        }
        // start the current level
        if len(levels) == level {
            levels = append(levels, []int{})
        }
        // append the current node value
        levels[level] = append(levels[level], node.Val)
        // process child nodes for the next level
        if node.Left != nil {
            helper(node.Left, level+1)
        }
        if node.Right != nil {
            helper(node.Right, level+1)
        }
    }
    helper(root, 0)
    // reverse the levels
    for i := 0; i < len(levels)/2; i++ {
        levels[i], levels[len(levels)-1-i] = levels[len(levels)-1-i], levels[i]
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

        // append the current node value
        levels.get(level).add(node.val);

        // process child nodes for the next level
        if (node.left != null) helper(node.left, level + 1);
        if (node.right != null) helper(node.right, level + 1);
    }

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        Collections.reverse(levels);
        return levels;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var levelOrderBottom = function (root) {
    let levels = [];
    function helper(node, level) {
        if (!node) return;
        // start the current level
        if (!levels[level]) levels[level] = [];
        // append the current node value
        levels[level].push(node.val);
        // process child nodes for the next level
        if (node.left) helper(node.left, level + 1);
        if (node.right) helper(node.right, level + 1);
    }
    helper(root, 0);
    return levels.reverse();
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        if not root:
            return levels

        def helper(node: Optional[TreeNode], level: int) -> None:
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
        return levels[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function levelOrderBottom(root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    function helper(node: TreeNode | null, level: number) {
        if (!node) return;
        // start the current level
        if (!levels[level]) levels[level] = [];
        // append the current node value
        levels[level].push(node.val);
        // process child nodes for the next level
        if (node.left) helper(node.left, level + 1);
        if (node.right) helper(node.right, level + 1);
    }
    helper(root, 0);
    return levels.reverse();
}
```

</details>

<br>

## Approach 2: Iteration: BFS Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Node {
    struct TreeNode* val;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Node* newNode(struct TreeNode* v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = v;
    temp->next = NULL;
    return temp;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
};
void enQueue(struct Queue* q, struct TreeNode* v) {
    struct Node* temp = newNode(v);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    int** result = malloc(sizeof(int*) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    *returnSize = 0;
    if (root == NULL) return result;
    struct Queue* q = createQueue();
    enQueue(q, root);
    while (q->front != NULL) {
        struct Queue* temp_q = createQueue();
        result[*returnSize] = malloc(sizeof(int) * 2000);
        (*returnColumnSizes)[*returnSize] = 0;
        while (q->front != NULL) {
            struct TreeNode* v = q->front->val;
            deQueue(q);
            result[*returnSize][(*returnColumnSizes)[*returnSize]] = v->val;
            (*returnColumnSizes)[*returnSize]++;
            if (v->left) enQueue(temp_q, v->left);
            if (v->right) enQueue(temp_q, v->right);
        }
        *returnSize += 1;
        q = temp_q;
    }
    int s = 0, e = *returnSize - 1;
    while (s < e) {
        int tempSize = (*returnColumnSizes)[s];
        int* temp = result[s];
        (*returnColumnSizes)[s] = (*returnColumnSizes)[e];
        result[s] = result[e];
        (*returnColumnSizes)[e] = tempSize;
        result[e] = temp;
        s++;
        e--;
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) return levels;
        deque<TreeNode*> next_level;
        next_level.push_back(root);
        while (!next_level.empty()) {
            deque<TreeNode*> curr_level = next_level;
            next_level.clear();
            levels.push_back(vector<int>());
            for (TreeNode* node : curr_level) {
                // append the current node value
                levels.back().push_back(node->val);
                // process child nodes for the next level
                if (node->left != NULL) next_level.push_back(node->left);
                if (node->right != NULL) next_level.push_back(node->right);
            }
        }
        reverse(levels.begin(), levels.end());
        return levels;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        IList<IList<int>> levels = new List<IList<int>>();
        if (root == null)
            return levels;
        Queue<TreeNode> nextLevel = new Queue<TreeNode>();
        nextLevel.Enqueue(root);
        while (nextLevel.Count > 0) {
            Queue<TreeNode> currLevel = new Queue<TreeNode>(nextLevel);
            nextLevel.Clear();
            levels.Add(new List<int>());
            foreach (TreeNode node in currLevel) {
                // append the current node value
                levels[levels.Count - 1].Add(node.val);
                // process child nodes for the next level
                if (node.left != null)
                    nextLevel.Enqueue(node.left);
                if (node.right != null)
                    nextLevel.Enqueue(node.right);
            }
        }

        ((List<IList<int>>)levels).Reverse();
        return levels;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func levelOrderBottom(root *TreeNode) [][]int {
    levels := make([][]int, 0)
    if root == nil {
        return levels
    }
    nextLevel := []*TreeNode{root}
    for len(nextLevel) > 0 {
        currLevel := nextLevel
        nextLevel = make([]*TreeNode, 0)
        levels = append(levels, make([]int, 0))
        for _, node := range currLevel {
            // append the current node value
            levels[len(levels)-1] = append(levels[len(levels)-1], node.Val)
            // process child nodes for the next level
            if node.Left != nil {
                nextLevel = append(nextLevel, node.Left)
            }
            if node.Right != nil {
                nextLevel = append(nextLevel, node.Right)
            }
        }
    }
    // reverse the array in-place
    for i := 0; i < len(levels)/2; i++ {
        levels[i], levels[len(levels)-1-i] = levels[len(levels)-1-i], levels[i]
    }
    return levels
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        if (root == null) return levels;

        ArrayDeque<TreeNode> nextLevel = new ArrayDeque() {
            {
                offer(root);
            }
        };
        ArrayDeque<TreeNode> currLevel = new ArrayDeque();

        while (!nextLevel.isEmpty()) {
            currLevel = nextLevel.clone();
            nextLevel.clear();
            levels.add(new ArrayList<Integer>());

            for (TreeNode node : currLevel) {
                // append the current node value
                levels.get(levels.size() - 1).add(node.val);

                // process child nodes for the next level
                if (node.left != null) nextLevel.offer(node.left);
                if (node.right != null) nextLevel.offer(node.right);
            }
        }

        Collections.reverse(levels);
        return levels;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var levelOrderBottom = function (root) {
    let levels = [];
    if (root == null) return levels;
    let nextLevel = [root];
    while (nextLevel.length > 0) {
        let currLevel = [...nextLevel];
        nextLevel = [];
        levels.push([]);
        for (let node of currLevel) {
            // append the current node value
            levels[levels.length - 1].push(node.val);
            // process child nodes for the next level
            if (node.left != null) nextLevel.push(node.left);
            if (node.right != null) nextLevel.push(node.right);
        }
    }
    levels.reverse();
    return levels;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        levels = []
        next_level = deque([root])

        while root and next_level:
            curr_level = next_level
            next_level = deque()
            levels.append([])

            for node in curr_level:
                # append the current node value
                levels[-1].append(node.val)
                # process child nodes for the next level
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

        return levels[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function levelOrderBottom(root: TreeNode | null): number[][] {
    let levels: number[][] = [];
    if (root == null) return levels;
    let nextLevel: (TreeNode | null)[] = [root];
    while (nextLevel.length > 0) {
        let currLevel: (TreeNode | null)[] = [...nextLevel];
        nextLevel = [];
        levels.push([]);
        for (let node of currLevel) {
            if (node != null) {
                // append the current node value
                levels[levels.length - 1].push(node.val);
                // process child nodes for the next level
                if (node.left != null) nextLevel.push(node.left);
                if (node.right != null) nextLevel.push(node.right);
            }
        }
    }
    levels.reverse();
    return levels;
}
```

</details>
