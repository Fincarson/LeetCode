# 501. Find Mode in Binary Search Tree

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-mode-in-binary-search-tree/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 501 - Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

## Problem

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than or equal to the node's key.
- The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
- Both the left and right subtrees must also be binary search trees.

### Example 1

```text
Input: root = [1,null,2,2]
Output: [2]
```

### Example 2

```text
Input: root = [0]
Output: [0]
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 501. Find Mode in Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Frequency With Hash Map (DFS) | C++, Java, Python3 |
| Iterative DFS | C++, Java, Python3 |
| Breadth First Search (BFS) | C++, Java, Python3 |
| No Hash-Map | C++, Java, Python3 |
| No "Values" Array | C++, Java, Python3 |
| True Constant Space: Morris Traversal | C++, Java, Python3 |

## Approach 1: Count Frequency With Hash Map (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        dfs(root, counter);
        int maxFreq = 0;

        for (auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }
        
        vector<int> ans;
        for (auto& [key, val] : counter) {
            if (val == maxFreq) {
                ans.push_back(key);
            } 
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, unordered_map<int, int>& counter) {
        if (node == nullptr) {
            return;
        }

        counter[node->val]++;
        dfs(node->left, counter);
        dfs(node->right, counter);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> counter = new HashMap();
        dfs(root, counter);
        int maxFreq = 0;
        
        for (int key : counter.keySet()) {
            maxFreq = Math.max(maxFreq, counter.get(key));
        }
        
        List<Integer> ans = new ArrayList();
        for (int key : counter.keySet()) {
            if (counter.get(key) == maxFreq) {
                ans.add(key);
            }
        }
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
    
    public void dfs(TreeNode node, Map<Integer, Integer> counter) {
        if (node == null) {
            return;
        }
        
        counter.put(node.val, counter.getOrDefault(node.val, 0) + 1);
        dfs(node.left, counter);
        dfs(node.right, counter);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node, counter):
            if not node:
                return
            
            counter[node.val] += 1
            dfs(node.left, counter)
            dfs(node.right, counter)
            
        counter = defaultdict(int)
        dfs(root, counter)
        max_freq = max(counter.values())
        
        ans = []
        for key in counter:
            if counter[key] == max_freq:
                ans.append(key)
        
        return ans
```

</details>

<br>

## Approach 2: Iterative DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        vector<TreeNode*> stack;
        stack.push_back(root);
        
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();

            counter[node->val]++;
            if (node->left != nullptr) {
                stack.push_back(node->left);
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
            }
        }
        
        int maxFreq = 0;

        for (auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }
        
        vector<int> ans;
        for (auto& [key, val] : counter) {
            if (val == maxFreq) {
                ans.push_back(key);
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
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> counter = new HashMap();
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            
            counter.put(node.val, counter.getOrDefault(node.val, 0) + 1);
            if (node.left != null) {
                stack.push(node.left);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
        }
        
        
        int maxFreq = 0;
        for (int key : counter.keySet()) {
            maxFreq = Math.max(maxFreq, counter.get(key));
        }
        
        List<Integer> ans = new ArrayList();
        for (int key : counter.keySet()) {
            if (counter.get(key) == maxFreq) {
                ans.add(key);
            }
        }
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        counter = defaultdict(int)
        stack = [root]
        
        while stack:
            node = stack.pop()
            counter[node.val] += 1
            
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        max_freq = max(counter.values())
        
        ans = []
        for key in counter:
            if counter[key] == max_freq:
                ans.append(key)
        
        return ans
```

</details>

<br>

## Approach 3: Breadth First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            counter[node->val]++;
            if (node->left != nullptr) {
                queue.push(node->left);
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }
        
        int maxFreq = 0;
        for (auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }
        
        vector<int> ans;
        for (auto& [key, val] : counter) {
            if (val == maxFreq) {
                ans.push_back(key);
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
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> counter = new HashMap();
        Queue<TreeNode> queue = new LinkedList();
        queue.add(root);
        
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();
            
            counter.put(node.val, counter.getOrDefault(node.val, 0) + 1);
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        
        int maxFreq = 0;
        for (int key : counter.keySet()) {
            maxFreq = Math.max(maxFreq, counter.get(key));
        }
        
        List<Integer> ans = new ArrayList();
        for (int key : counter.keySet()) {
            if (counter.get(key) == maxFreq) {
                ans.add(key);
            }
        }
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        counter = defaultdict(int)
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            counter[node.val] += 1
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        max_freq = max(counter.values())
        
        ans = []
        for key in counter:
            if counter[key] == max_freq:
                ans.append(key)
        
        return ans
```

</details>

<br>

## Approach 4: No Hash-Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> values;
        dfs(root, values);
        
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        vector<int> ans;
        
        for (int num : values) {
            if (num == currNum) {
                currStreak++;
            } else {
                currStreak = 1;
                currNum = num;
            }
            
            if (currStreak > maxStreak) {
                ans = {};
                maxStreak = currStreak;
            }
            
            if (currStreak == maxStreak) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        
        // Inorder traversal visits nodes in sorted order
        dfs(node->left, values);
        values.push_back(node->val);
        dfs(node->right, values);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] findMode(TreeNode root) {
        List<Integer> values = new ArrayList();
        dfs(root, values);

        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        List<Integer> ans = new ArrayList();

        for (int num : values) {
            if (num == currNum) {
                currStreak++;
            } else {
                currStreak = 1;
                currNum = num;
            }
            
            if (currStreak > maxStreak) {
                ans = new ArrayList();
                maxStreak = currStreak;
            }
            
            if (currStreak == maxStreak) {
                ans.add(num);
            }
        }
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
    
    public void dfs(TreeNode node, List<Integer> values) {
        if (node == null) {
            return;
        }
        
        // Inorder traversal visits nodes in sorted order
        dfs(node.left, values);
        values.add(node.val);
        dfs(node.right, values);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node, values):
            if not node:
                return
            
            # Inorder traversal visits nodes in sorted order
            dfs(node.left, values)
            values.append(node.val)
            dfs(node.right, values)
            
        values = []
        dfs(root, values)
        
        max_streak = 0
        curr_streak = 0
        curr_num = 0
        ans = []
        
        for num in values:
            if num == curr_num:
                curr_streak += 1
            else:
                curr_streak = 1
                curr_num = num
                
            if curr_streak > max_streak:
                ans = []
                max_streak = curr_streak

            if curr_streak == max_streak:
                ans.append(num)

        return ans
```

</details>

<br>

## Approach 5: No "Values" Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> ans;
    int maxStreak = 0;
    int currStreak = 0;
    int currNum = 0;
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left);
        
        int num = node->val;
        if (num == currNum) {
            currStreak++;
        } else {
            currStreak = 1;
            currNum = num;
        }

        if (currStreak > maxStreak) {
            ans = {};
            maxStreak = currStreak;
        }

        if (currStreak == maxStreak) {
            ans.push_back(num);
        }

        
        dfs(node->right);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int maxStreak = 0;
    int currStreak = 0;
    int currNum = 0;
    List<Integer> ans = new ArrayList();
    
    public int[] findMode(TreeNode root) {
        dfs(root);
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
    
    public void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        
        dfs(node.left);
        int num = node.val;
        if (num == currNum) {
            currStreak++;
        } else {
            currStreak = 1;
            currNum = num;
        }

        if (currStreak > maxStreak) {
            ans = new ArrayList();
            maxStreak = currStreak;
        }

        if (currStreak == maxStreak) {
            ans.add(num);
        }
        
        dfs(node.right);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node):
            nonlocal max_streak, curr_streak, curr_num, ans
            if not node:
                return
            
            dfs(node.left)
            
            num = node.val
            if num == curr_num:
                curr_streak += 1
            else:
                curr_streak = 1
                curr_num = num

            if curr_streak > max_streak:
                ans = []
                max_streak = curr_streak

            if curr_streak == max_streak:
                ans.append(num)
            
            dfs(node.right)

        max_streak = 0
        curr_streak = 0
        curr_num = 0
        ans = []
        dfs(root)
        return ans
```

</details>

<br>

## Approach 6: True Constant Space: Morris Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:   
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the friend
                TreeNode* friendNode = curr->left;
                while (friendNode->right != nullptr) {
                    friendNode = friendNode->right;
                }
                
                friendNode->right = curr;
                
                // Delete the edge after using it
                TreeNode* left = curr->left;
                curr->left = nullptr;
                curr = left;
            } else {
                // Handle the current node
                int num = curr->val;
                if (num == currNum) {
                    currStreak++;
                } else {
                    currStreak = 1;
                    currNum = num;
                }

                if (currStreak > maxStreak) {
                    ans = {};
                    maxStreak = currStreak;
                }

                if (currStreak == maxStreak) {
                    ans.push_back(num);
                }
                
                curr = curr->right;
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
    public int[] findMode(TreeNode root) {
        int maxStreak = 0;
        int currStreak = 0;
        int currNum = 0;
        List<Integer> ans = new ArrayList();
        
        TreeNode curr = root;
        while (curr != null) {
            if (curr.left != null) {
                // Find the friend
                TreeNode friend = curr.left;
                while (friend.right != null) {
                    friend = friend.right;
                }
                
                friend.right = curr;
                
                // Delete the edge after using it
                TreeNode left = curr.left;
                curr.left = null;
                curr = left;
            } else {
                // Handle the current node
                int num = curr.val;
                if (num == currNum) {
                    currStreak++;
                } else {
                    currStreak = 1;
                    currNum = num;
                }

                if (currStreak > maxStreak) {
                    ans = new ArrayList();
                    maxStreak = currStreak;
                }

                if (currStreak == maxStreak) {
                    ans.add(num);
                }
                
                curr = curr.right;
            }
        }
        
        
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        max_streak = 0
        curr_streak = 0
        curr_num = 0
        ans = []
        
        curr = root
        while curr:
            if curr.left:
                # Find the friend
                friend = curr.left
                while friend.right:
                    friend = friend.right
                
                friend.right = curr
                
                # Delete the edge after using it
                left = curr.left
                curr.left = None
                curr = left
            else:
                # Handle the current node
                num = curr.val
                if num == curr_num:
                    curr_streak += 1
                else:
                    curr_streak = 1
                    curr_num = num

                if curr_streak > max_streak:
                    ans = []
                    max_streak = curr_streak

                if curr_streak == max_streak:
                    ans.append(num)
                
                curr = curr.right
        
        return ans
```

</details>
