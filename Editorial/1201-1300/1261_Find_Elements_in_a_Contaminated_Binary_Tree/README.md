# 1261. Find Elements in a Contaminated Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/)  
`Hash Table` `Tree` `Depth-First Search` `Breadth-First Search` `Design` `Binary Tree`

**Problem Link:** [LeetCode 1261 - Find Elements in a Contaminated Binary Tree](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/)

## Problem

Given a binary tree with the following rules:

Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

- FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
- bool find(int target) Returns true if the target value exists in the recovered binary tree.

### Example 1

```text
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True
```

### Example 2

```text
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

### Example 3

```text
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
```

## Constraints

- TreeNode.val == -1
- The height of the binary tree is less than or equal to 20
- The total number of nodes is between [1, 104]
- Total calls of find() is between [1, 104]
- 0 <= target <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1261. Find Elements in a Contaminated Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Tree Traversal (DFS) | C++, Java, Python3 |
| Tree Traversal (BFS) | C++, Java, Python3 |

## Approach 1: Tree Traversal (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class FindElements {
public:
    FindElements(TreeNode* root) { dfs(root, 0); }

    bool find(int target) { return seen.count(target) > 0; }

private:
    unordered_set<int> seen;

    void dfs(TreeNode* currentNode, int currentValue) {
        if (!currentNode) return;
        // visit current node by adding its value to seen
        seen.insert(currentValue);
        dfs(currentNode->left, currentValue * 2 + 1);
        dfs(currentNode->right, currentValue * 2 + 2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FindElements {

    HashSet<Integer> seen;

    public FindElements(TreeNode root) {
        seen = new HashSet<>();
        dfs(root, 0);
    }

    public boolean find(int target) {
        return seen.contains(target);
    }

    private void dfs(TreeNode currentNode, int currentValue) {
        if (currentNode == null) return;
        // visit current node by adding its value to seen
        seen.add(currentValue);
        dfs(currentNode.left, currentValue * 2 + 1);
        dfs(currentNode.right, currentValue * 2 + 2);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FindElements:
    def __init__(self, root: TreeNode):
        self.seen = set()
        self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.seen

    def dfs(self, current_node, current_value):
        if current_node is None:
            return
        # visit current node by adding its value to seen
        self.seen.add(current_value)
        self.dfs(current_node.left, current_value * 2 + 1)
        self.dfs(current_node.right, current_value * 2 + 2)
```

</details>

<br>

## Approach 2: Tree Traversal (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class FindElements {
    unordered_set<int> seen;

public:
    FindElements(TreeNode* root) { bfs(root); }

    bool find(int target) { return seen.find(target) != seen.end(); }

private:
    void bfs(TreeNode* root) {
        queue<TreeNode*> queue;
        root->val = 0;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* currentNode = queue.front();
            queue.pop();
            // visit currentNode by adding its recovered value to the set
            seen.insert(currentNode->val);
            if (currentNode->left) {
                currentNode->left->val = currentNode->val * 2 + 1;
                queue.push(currentNode->left);
            }
            if (currentNode->right) {
                currentNode->right->val = currentNode->val * 2 + 2;
                queue.push(currentNode->right);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FindElements {

    HashSet<Integer> seen;

    public FindElements(TreeNode root) {
        seen = new HashSet<>();
        bfs(root);
    }

    public boolean find(int target) {
        return seen.contains(target);
    }

    private void bfs(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        root.val = 0;
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.remove();
            // visit currentNode by adding its recovered value to the set
            seen.add(currentNode.val);
            if (currentNode.left != null) {
                currentNode.left.val = currentNode.val * 2 + 1;
                queue.add(currentNode.left);
            }
            if (currentNode.right != null) {
                currentNode.right.val = currentNode.val * 2 + 2;
                queue.add(currentNode.right);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class FindElements:

    def __init__(self, root: TreeNode):
        self.seen = set()
        self.bfs(root)

    def find(self, target: int) -> bool:
        return target in self.seen

    def bfs(self, root: TreeNode) -> None:
        queue = [root]
        root.val = 0

        while queue:
            current_node = queue.pop(0)
            # visit current_node by adding its recovered value to the set
            self.seen.add(current_node.val)
            if current_node.left:
                current_node.left.val = current_node.val * 2 + 1
                queue.append(current_node.left)
            if current_node.right:
                current_node.right.val = current_node.val * 2 + 2
                queue.append(current_node.right)
```

</details>
