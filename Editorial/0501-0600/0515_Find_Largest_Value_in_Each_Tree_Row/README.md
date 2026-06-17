# 515. Find Largest Value in Each Tree Row

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)  
`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 515 - Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

## Problem

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

### Example 1

```text
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```

### Example 2

```text
Input: root = [1,2,3]
Output: [1,3]
```

## Constraints

- The number of nodes in the tree will be in the range [0, 104].
- -231 <= Node.val <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 515. Find Largest Value in Each Tree Row

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth First Search (BFS) | C++, Java, Python3 |
| Depth First Search (DFS) | C++, Java, Python3 |
| DFS, Iterative | C++, Java, Python3 |

## Approach 1: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int currentLength = queue.size();
            int currMax = INT_MIN;
            
            for (int i = 0; i < currentLength; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                currMax = max(currMax, node->val);
                
                if (node->left) {
                    queue.push(node->left);
                }
                
                if (node->right) {
                    queue.push(node->right);
                }
            }
            
            ans.push_back(currMax);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        if (root == null) {
            return new ArrayList<Integer>();
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            int currentLength = queue.size();
            int currMax = Integer.MIN_VALUE;
            
            for (int i = 0; i < currentLength; i++) {
                TreeNode node = queue.remove();
                currMax = Math.max(currMax, node.val);
                
                if (node.left != null) {
                    queue.add(node.left);
                }
                
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            
            ans.add(currMax);
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        ans = []
        queue = deque([root])
        
        while queue:
            current_length = len(queue)
            curr_max = float("-inf")
            
            for _ in range(current_length):
                node = queue.popleft()
                curr_max = max(curr_max, node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            ans.append(curr_max)
        
        return ans
```

</details>

<br>

## Approach 2: Depth First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> ans;
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
        
        if (depth == ans.size()) {
            ans.push_back(node->val);
        } else {
            ans[depth] = max(ans[depth], node->val);
        }
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    List<Integer> ans;
    
    public List<Integer> largestValues(TreeNode root) {
        ans = new ArrayList<Integer>();
        dfs(root, 0);
        return ans;
    }
    
    public void dfs(TreeNode node, int depth) {
        if (node == null) {
            return;
        }
        
        if (depth == ans.size()) {
            ans.add(node.val);
        } else {
            ans.set(depth, Math.max(ans.get(depth), node.val));
        }
        
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node, depth):
            if not node:
                return
            
            if depth == len(ans):
                ans.append(node.val)
            else:
                ans[depth] = max(ans[depth], node.val)
            
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)
        
        ans = []
        dfs(root, 0)
        return ans
```

</details>

<br>

## Approach 3: DFS, Iterative

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        vector<int> ans;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 0));
        
        while (!stack.empty()) {
            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            TreeNode* node = pair.first;
            int depth = pair.second;
            
            if (depth == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[depth] = max(ans[depth], node->val);
            }
            
            if (node->left) {
                stack.push(make_pair(node->left, depth + 1));
            }
            
            if (node->right) {
                stack.push(make_pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        if (root == null) {
            return new ArrayList<Integer>();
        }
        
        List<Integer> ans = new ArrayList<>();
        Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
        stack.push(new Pair<>(root, 0));
        
        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> pair = stack.pop();
            TreeNode node = pair.getKey();
            int depth = pair.getValue();
            
            if (depth == ans.size()) {
                ans.add(node.val);
            } else {
                ans.set(depth, Math.max(ans.get(depth), node.val));
            }
            
            if (node.left != null) {
                stack.push(new Pair<>(node.left, depth + 1));
            }
            
            if (node.right != null) {
                stack.push(new Pair<>(node.right, depth + 1));
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        ans = []
        stack = [(root, 0)]
        
        while stack:
            node, depth = stack.pop()
            if depth == len(ans):
                ans.append(node.val)
            else:
                ans[depth] = max(ans[depth], node.val)
            
            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:
                stack.append((node.right, depth + 1))
        
        return ans
```

</details>
