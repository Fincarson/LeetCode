# 894. All Possible Full Binary Trees

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/all-possible-full-binary-trees/)  
`Dynamic Programming` `Tree` `Recursion` `Memoization` `Binary Tree`

**Problem Link:** [LeetCode 894 - All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/)

## Problem

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

### Example 1

```text
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
```

### Example 2

```text
Input: n = 3
Output: [[0,0,0]]
```

## Constraints

- 1 <= n <= 20

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 894. All Possible Full Binary Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion + Memoization (Top-Down DP) | C++, Java, Python3 |
| Iterative Dynamic Programming | C++, Java, Python3 |

## Approach 1: Recursion + Memoization (Top-Down DP)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n % 2) == 0) {
            return {};
        }
        
        if (n == 1) {
            return {new TreeNode()};
        }
        
        if(memo.find(n) != memo.end()) {
            return memo[n];
        }

        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);
            
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(0, l, r);
                    res.push_back(root);
                }
            }
        }
        
        return memo[n] = res;
    }
};
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
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Map<Integer, List<TreeNode>> memo = new HashMap<>();

    public List<TreeNode> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return new ArrayList<TreeNode>();
        }

        if (n == 1) {
            return Arrays.asList(new TreeNode());
        }

        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        List<TreeNode> res = new ArrayList<TreeNode>();
        for (int i = 1; i < n; i += 2) {
            List<TreeNode> left = allPossibleFBT(i);
            List<TreeNode> right = allPossibleFBT(n - i - 1);

            for (TreeNode l : left) {
                for (TreeNode r : right) {
                    TreeNode root = new TreeNode(0, l, r);
                    res.add(root);
                }
            }
        }

        memo.put(n, res);
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        if n % 2 == 0:
            return []
        if n == 1:
            return [TreeNode()]

        res = []
        for i in range(1, n, 2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(n - i - 1)

            for l in left:
                for r in right:
                    root = TreeNode(0, l, r)
                    res.append(root)

        return res
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        vector<vector<TreeNode*>> dp(n + 1);

        dp[1].push_back(new TreeNode(0));
        for (int count = 3; count <= n; count += 2) {
            for (int i = 1; i < count - 1; i += 2) {
                int j = count - 1 - i;
                for (auto left : dp[i]) {
                    for (auto right : dp[j]) {
                        TreeNode* root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};
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
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<TreeNode> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return new ArrayList<>();
        }

        List<List<TreeNode>> dp = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            dp.add(new ArrayList<>());
        }
        
        dp.get(1).add(new TreeNode(0));
        for (int count = 3; count <= n; count += 2) {
            for (int i = 1; i < count - 1; i += 2) {
                int j = count - 1 - i;
                for (TreeNode left : dp.get(i)) {
                    for (TreeNode right : dp.get(j)) {
                        TreeNode root = new TreeNode(0, left, right);
                        dp.get(count).add(root);
                    }
                }
            }
        }
        
        return dp.get(n);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        if n % 2 == 0:
            return []

        dp = [[] for _ in range(n + 1)]
        dp[1].append(TreeNode(0))
        
        for count in range(3, n + 1, 2):
            for i in range(1, count - 1, 2):
                j = count - 1 - i
                for left in dp[i]:
                    for right in dp[j]:
                        root = TreeNode(0, left, right)
                        dp[count].append(root)

        return dp[n]
```

</details>
