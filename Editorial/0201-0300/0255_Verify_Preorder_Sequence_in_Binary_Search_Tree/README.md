# 255. Verify Preorder Sequence in Binary Search Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)  
`Array` `Stack` `Tree` `Binary Search Tree` `Recursion` `Monotonic Stack` `Binary Tree`

**Problem Link:** [LeetCode 255 - Verify Preorder Sequence in Binary Search Tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)

## Problem

Given an array of unique integers preorder, return true if it is the correct preorder traversal sequence of a binary search tree.

### Example 1

```text
Input: preorder = [5,2,1,3,6]
Output: true
```

### Example 2

```text
Input: preorder = [5,2,6,1,3]
Output: false
```

## Constraints

- 1 <= preorder.length <= 104
- 1 <= preorder[i] <= 104
- All the elements of preorder are unique.

Follow up: Could you do it using only constant space complexity?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 255. Verify Preorder Sequence in Binary Search Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Monotonic Stack | C++, Java, Python3 |
| Constant Auxiliary Space | C++, Java, Python3 |
| Recursion | C++, Java, Python3 |

## Approach 1: Monotonic Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        stack<int> stack;
        
        for (int num: preorder) {
            while (!stack.empty() && stack.top() < num) {
                minLimit = stack.top();
                stack.pop();
            }
            
            if (num <= minLimit) {
                return false;
            }
            
            stack.push(num);
        }
        
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        int minLimit = Integer.MIN_VALUE;
        Stack<Integer> stack = new Stack<>();
        
        for (int num: preorder) {
            while (!stack.isEmpty() && stack.peek() < num) {
                minLimit = stack.pop();
            }
            
            if (num <= minLimit) {
                return false;
            }
            
            stack.push(num);
        }
        
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        min_limit = -inf
        stack = []
        
        for num in preorder:
            while stack and stack[-1] < num:
                min_limit = stack.pop()
                
            if num <= min_limit:
                return False
            
            stack.append(num)
        
        return True
```

</details>

<br>

## Approach 2: Constant Auxiliary Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        int i = 0;
        
        for (int num: preorder) {
            while (i > 0 && preorder[i - 1] < num) {
                minLimit = preorder[i - 1];
                i--;
            }
            
            if (num <= minLimit) {
                return false;
            }
            
            preorder[i] = num;
            i++;
        }
        
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        int minLimit = Integer.MIN_VALUE;
        int i = 0;
        
        for (int num: preorder) {
            while (i > 0 && preorder[i - 1] < num) {
                minLimit = preorder[i - 1];
                i--;
            }
            
            if (num <= minLimit) {
                return false;
            }
            
            preorder[i] = num;
            i++;
        }
        
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        min_limit = -inf
        i = 0
        
        for num in preorder:
            while i > 0 and preorder[i - 1] < num:
                min_limit = preorder[i - 1]
                i -= 1
                
            if num <= min_limit:
                return False
            
            preorder[i] = num
            i += 1
        
        return True
```

</details>

<br>

## Approach 3: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MIN, INT_MAX);
    }
    
    bool helper(vector<int>& preorder, int& i, int minLimit, int maxLimit) {
        if (i == preorder.size()) {
            return true;
        }
        
        int root = preorder[i];
        if (root <= minLimit || root >= maxLimit) {
            return false;
        }
        
        i++;
        bool left = helper(preorder, i, minLimit, root);
        bool right = helper(preorder, i, root, maxLimit);
        return left || right;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        int[] i = {0};
        return helper(preorder, i, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    public boolean helper(int[] preorder, int[] i, int minLimit, int maxLimit) {
        if (i[0] == preorder.length) {
            return true;
        }
        
        int root = preorder[i[0]];
        if (root <= minLimit || root >= maxLimit) {
            return false;
        }
        
        i[0]++;
        boolean left = helper(preorder, i, minLimit, root);
        boolean right = helper(preorder, i, root, maxLimit);
        return left || right;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        def helper(i, min_limit, max_limit):
            if i[0] == len(preorder):
                return True
            
            root = preorder[i[0]]
            if not min_limit < root < max_limit:
                return False

            i[0] += 1
            left = helper(i, min_limit, root)
            right = helper(i, root, max_limit)
            return left or right
            
        return helper([0], -inf, inf)
```

</details>
