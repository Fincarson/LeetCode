# 104. Maximum Depth of Binary Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/maximum-depth-of-binary-tree/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

## Problem

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example 1

```text
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

### Example 2

```text
Input: root = [1,null,2]
Output: 2
```

## Constraints

- The number of nodes in the tree is in the range [0, 104].
- -100 <= Node.val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Height of Binary Tree After Subtree Removal Queries](https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 104. Maximum Depth of Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Tail Recursion + BFS | C, C++, C#, Go, Java, JavaScript, Python3 |
| Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
    int maxDepth(TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      return max(1 + maxDepth(root -> left), 1 + maxDepth(root -> right));
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int left_height = MaxDepth(root.left);
            int right_height = MaxDepth(root.right);
            return 1 + Math.Max(left_height, right_height);
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    left_height := maxDepth(root.Left)
    right_height := maxDepth(root.Right)
    return 1 + max(left_height, right_height)
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int left_height = maxDepth(root.left);
            int right_height = maxDepth(root.right);
            return java.lang.Math.max(left_height, right_height) + 1;
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDepth = function (root) {
    if (root === null) {
        return 0;
    }
    const left_height = maxDepth(root.left);
    const right_height = maxDepth(root.right);
    return 1 + Math.max(left_height, right_height);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            return max(left_height, right_height) + 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDepth(root: TreeNode | null): number {
    if (root === null) {
        return 0;
    }
    const left_height = maxDepth(root.left);
    const right_height = maxDepth(root.right);
    return 1 + Math.max(left_height, right_height);
}
```

</details>

<br>

## Approach 2: Tail Recursion + BFS

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Item {
    struct TreeNode* node;
    int level;
};
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    // The queue that contains the next nodes to visit, along with the
    // level/depth that each node is located.
    int max_depth = 0;
    struct Item
        next_items[10000];  // Assuming tree will not be deeper than 10K levels
    int start = 0;
    int end = 0;
    next_items[end++] = (struct Item){.node = root, .level = 0};
    while (start != end) {
        struct Item next_item = next_items[start++];
        int next_level = next_item.level + 1;
        max_depth = next_level > max_depth ? next_level : max_depth;
        // Add the nodes to visit in the following recursive calls.
        if (next_item.node->left)
            next_items[end++] = (struct Item){.node = next_item.node->left,
                                              .level = next_level};
        if (next_item.node->right)
            next_items[end++] = (struct Item){.node = next_item.node->right,
                                              .level = next_level};
    }
    return max_depth;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {

  private:
    // The queue that contains the next nodes to visit, 
    //   along with the level/depth that each node is located.
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;
    
    /**
     * A tail recursion function to calculate the max depth
     *   of the binary tree.
     */
    int next_maxDepth() {
    
      if (next_items.size() == 0) {
        return max_depth;
      }
        
      auto next_item = next_items.front();
      next_items.pop();

      auto next_node = next_item.first;
      auto next_level = next_item.second + 1;
      
      max_depth = max(max_depth, next_level);

      // Add the nodes to visit in the following recursive calls.
      if (next_node->left != NULL) {
        next_items.push(make_pair(next_node->left, next_level));
      }
      if (next_node->right != NULL) {
        next_items.push(make_pair(next_node->right, next_level));
      }
    
      // The last action should be the ONLY recursive call
      //   in the tail-recursion function.
      return next_maxDepth();
    }
    
  public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) return 0;
        
      // Clear the previous queue.
      std::queue<pair<TreeNode*, int>> empty;
      std::swap(next_items, empty);
      max_depth = 0;
        
      // Push the root node into the queue to kick off the next visit.
      next_items.push(make_pair(root, 0));
        
      return next_maxDepth();
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private Queue<Tuple<TreeNode, int>> next_items =
        new Queue<Tuple<TreeNode, int>>();

    private int max_depth = 0;

    private int NextMaxDepth() {
        if (next_items.Count == 0) {
            return max_depth;
        }

        Tuple<TreeNode, int> next_item = next_items.Dequeue();
        TreeNode next_node = next_item.Item1;
        int next_level = next_item.Item2 + 1;
        max_depth = Math.Max(max_depth, next_level);
        // Add the nodes to visit in the following recursive calls.
        if (next_node.left != null) {
            next_items.Enqueue(
                new Tuple<TreeNode, int>(next_node.left, next_level));
        }

        if (next_node.right != null) {
            next_items.Enqueue(
                new Tuple<TreeNode, int>(next_node.right, next_level));
        }

        return NextMaxDepth();
    }

    public int MaxDepth(TreeNode root) {
        if (root == null)
            return 0;
        // Clear the previous queue.
        next_items.Clear();
        max_depth = 0;
        // Push the root node into the queue to kick off the next visit.
        next_items.Enqueue(new Tuple<TreeNode, int>(root, 0));
        return NextMaxDepth();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Item struct {
    Node  *TreeNode
    Level int
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    // The queue that contains the next nodes to visit, along with the level/depth that each node is located.
    nextItems := make([]Item, 0)
    maxDepth := 0
    nextItems = append(nextItems, Item{Node: root, Level: 0})
    for len(nextItems) > 0 {
        nextItem := nextItems[0]
        nextItems = nextItems[1:]
        nextLevel := nextItem.Level + 1
        if nextLevel > maxDepth {
            maxDepth = nextLevel
        }
        // Add the nodes to visit in the following recursive calls.
        if nextItem.Node.Left != nil {
            nextItems = append(
                nextItems,
                Item{Node: nextItem.Node.Left, Level: nextLevel},
            )
        }
        if nextItem.Node.Right != nil {
            nextItems = append(
                nextItems,
                Item{Node: nextItem.Node.Right, Level: nextLevel},
            )
        }
    }
    return maxDepth
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.AbstractMap.SimpleEntry;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    private Queue<SimpleEntry<TreeNode, Integer>> next_items =
        new LinkedList<>();
    private int max_depth = 0;

    private int next_maxDepth() {
        if (next_items.isEmpty()) {
            return max_depth;
        }
        SimpleEntry<TreeNode, Integer> next_item = next_items.poll();
        TreeNode next_node = next_item.getKey();
        int next_level = next_item.getValue() + 1;
        max_depth = Math.max(max_depth, next_level);
        if (next_node.left != null) {
            next_items.add(new SimpleEntry<>(next_node.left, next_level));
        }
        if (next_node.right != null) {
            next_items.add(new SimpleEntry<>(next_node.right, next_level));
        }
        return next_maxDepth();
    }

    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        next_items.clear();
        max_depth = 0;
        next_items.add(new SimpleEntry<>(root, 0));
        return next_maxDepth();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var next_items = [];
var max_depth = 0;
function next_maxDepth() {
    if (!next_items.length) return max_depth;
    var next_level = next_items[0][1] + 1;
    max_depth = Math.max(max_depth, next_level);
    var next_node = next_items.shift()[0];
    if (next_node.left) {
        next_items.push([next_node.left, next_level]);
    }
    if (next_node.right) {
        next_items.push([next_node.right, next_level]);
    }
    return next_maxDepth();
}
function maxDepth(root) {
    if (!root) return 0;
    next_items = [];
    max_depth = 0;
    next_items.push([root, 0]);
    return next_maxDepth();
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def __init__(self):
        # The queue that contains the next nodes to visit,
        # along with the level/depth that each node is located.
        self.next_items = []
        self.max_depth = 0

    def next_maxDepth(self):
        if not self.next_items:
            return self.max_depth
        next_node, next_level = self.next_items.pop(0)
        next_level += 1
        self.max_depth = max(self.max_depth, next_level)
        # Add the nodes to visit in the following recursive calls.
        if next_node.left:
            self.next_items.append((next_node.left, next_level))
        if next_node.right:
            self.next_items.append((next_node.right, next_level))
        # The last action should be the ONLY recursive call
        # in the tail-recursion function.
        return self.next_maxDepth()

    def maxDepth(self, root):
        if not root:
            return 0
        # Clear the previous queue.
        self.next_items = []
        self.max_depth = 0
        # Push the root node into the queue to kick off the next visit.
        self.next_items.append((root, 0))
        return self.next_maxDepth()
```

</details>

<br>

## Approach 3: Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
struct Pair {
    struct TreeNode* node;
    int depth;
};
struct Pair* pair_create(struct TreeNode* node, int depth) {
    struct Pair* pair = malloc(sizeof(struct Pair));
    pair->node = node;
    pair->depth = depth;
    return pair;
}
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct Pair** stack = malloc(10000 * sizeof(struct TreeNode*));
    int top = 0;
    stack[top++] = pair_create(root, 1);
    int max_depth = 0;
    while (top != 0) {
        struct Pair* pair = stack[--top];
        int c_depth = pair->depth;
        struct TreeNode* c_node = pair->node;
        max_depth = c_depth > max_depth ? c_depth : max_depth;
        free(pair);
        if (c_node->left != NULL) {
            stack[top++] = pair_create(c_node->left, c_depth + 1);
        }
        if (c_node->right != NULL) {
            stack[top++] = pair_create(c_node->right, c_depth + 1);
        }
    }
    free(stack);
    return max_depth;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }

    vector<pair<int, TreeNode*>> my_stack;
    my_stack.push_back(pair<int, TreeNode*>(1, root));
    int max_depth = 0;
    while (!my_stack.empty()) {
      pair<int, TreeNode*> my_pair = my_stack.back();
      int c_depth = get<0>(my_pair);
      TreeNode* c_node = get<1>(my_pair);
      max_depth = max(max_depth, c_depth);
      my_stack.pop_back();
      if (c_node->left != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->left));
      }
      if (c_node->right != NULL) {
        my_stack.push_back(pair<int, TreeNode*>(c_depth + 1, c_node->right));
      }
    }
    return max_depth;
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        var stack = new Stack<(TreeNode, int)>();
        stack.Push((root, 1));
        int depth = 0;
        while (stack.Count != 0) {
            var current = stack.Pop();
            depth = Math.Max(depth, current.Item2);
            if (current.Item1.left != null) {
                stack.Push((current.Item1.left, current.Item2 + 1));
            }

            if (current.Item1.right != null) {
                stack.Push((current.Item1.right, current.Item2 + 1));
            }
        }

        return depth;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    stack := []struct {
        depth int
        node  *TreeNode
    }{{1, root}}
    depth := 0
    for len(stack) != 0 {
        current := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if current.node != nil {
            if depth < current.depth {
                depth = current.depth
            }
            stack = append(stack, struct {
                depth int
                node  *TreeNode
            }{current.depth + 1, current.node.Left})
            stack = append(stack, struct {
                depth int
                node  *TreeNode
            }{current.depth + 1, current.node.Right})
        }
    }
    return depth
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDepth(TreeNode root) {
        LinkedList<TreeNode> stack = new LinkedList<>();
        LinkedList<Integer> depths = new LinkedList<>();
        if (root == null) return 0;

        stack.add(root);
        depths.add(1);

        int depth = 0, current_depth = 0;
        while (!stack.isEmpty()) {
            root = stack.pollLast();
            current_depth = depths.pollLast();
            if (root != null) {
                depth = Math.max(depth, current_depth);
                stack.add(root.left);
                stack.add(root.right);
                depths.add(current_depth + 1);
                depths.add(current_depth + 1);
            }
        }
        return depth;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxDepth = function (root) {
    let stack = [];
    if (root != null) stack.push({ node: root, depth: 1 });
    let depth = 0;
    while (stack.length != 0) {
        let { node, depth: currentDepth } = stack.pop();
        if (node != null) {
            depth = Math.max(depth, currentDepth);
            stack.push({ node: node.left, depth: currentDepth + 1 });
            stack.push({ node: node.right, depth: currentDepth + 1 });
        }
    }
    return depth;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        stack = []
        if root is not None:
            stack.append((1, root))

        depth = 0
        while stack != []:
            current_depth, root = stack.pop()
            if root is not None:
                depth = max(depth, current_depth)
                stack.append((current_depth + 1, root.left))
                stack.append((current_depth + 1, root.right))

        return depth
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxDepth(root: TreeNode | null): number {
    if (root == null) {
        return 0;
    }
    let stack: [TreeNode | null, number][] = [];
    stack.push([root, 1]);
    let depth = 0;
    while (stack.length !== 0) {
        let [node, current_depth] = stack.pop() as [TreeNode, number];
        if (node != null) {
            depth = Math.max(depth, current_depth);
            stack.push([node.left, current_depth + 1]);
            stack.push([node.right, current_depth + 1]);
        }
    }
    return depth;
}
```

</details>
