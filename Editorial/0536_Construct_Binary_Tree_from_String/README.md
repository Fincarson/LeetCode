# 536. Construct Binary Tree from String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-binary-tree-from-string/)  
`String` `Stack` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 536 - Construct Binary Tree from String](https://leetcode.com/problems/construct-binary-tree-from-string/)

## Problem

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

### Example 1

```text
Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
```

### Example 2

```text
Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
```

### Example 3

```text
Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]
```

## Constraints

- 0 <= s.length <= 3 * 104
- s consists of digits, '(', ')', and '-' only.
- All numbers in the tree have value at most than 230.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 536. Construct Binary Tree from String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python3 |
| Stack | Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode str2tree(String s) {
        return this.str2treeInternal(s, 0).getKey();
    }
    
    public Pair<Integer, Integer> getNumber(String s, int index) {
        
        boolean isNegative = false;
        
        // A negative number
        if (s.charAt(index) == '-') {
            isNegative = true;
            index++;
        }
            
        int number = 0;
        while (index < s.length() && Character.isDigit(s.charAt(index))) {
            number = number * 10 + (s.charAt(index) - '0');
            index++;
        }
        
        return new Pair<Integer, Integer>(isNegative ? -number : number, index);
    } 
    
    public Pair<TreeNode, Integer> str2treeInternal(String s, int index) {
        
        if (index == s.length()) {
            return new Pair<TreeNode, Integer>(null, index);
        }
        
        // Start of the tree will always contain a number representing
        // the root of the tree. So we calculate that first.
        Pair<Integer, Integer> numberData = this.getNumber(s, index);
        int value = numberData.getKey();
        index = numberData.getValue();
        
        TreeNode node = new TreeNode(value);
        Pair<TreeNode, Integer> data;
        
        // Next, if there is any data left, we check for the first subtree
        // which according to the problem statement will always be the left child.
        if (index < s.length() && s.charAt(index) == '(') {
            data = this.str2treeInternal(s, index + 1);
            node.left = data.getKey();
            index = data.getValue();
        }
            
        
        // Indicates a right child
        if (node.left != null && index < s.length() && s.charAt(index) == '(') {
            data = this.str2treeInternal(s, index + 1);
            node.right = data.getKey();
            index = data.getValue();
        }
            
        
        return new Pair<TreeNode, Integer>(node, index < s.length() && s.charAt(index) == ')' ? index + 1 : index);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def str2tree(self, s: str) -> TreeNode:
        return self._str2treeInternal(s, 0)[0]
    
    def _getNumber(self, s: str, index: int) -> (int, int):
        
        is_negative = False
        
        # A negative number
        if s[index] == '-':
            is_negative = True
            index = index + 1
        
        number = 0
        while index < len(s) and s[index].isdigit():
            number = number * 10 + int(s[index])
            index += 1
        
        return number if not is_negative else -number, index
            
    
    def _str2treeInternal(self, s: str, index: int) -> (TreeNode, int):
        
        if index == len(s):
            return None, index
        
        # Start of the tree will always contain a number representing
        # the root of the tree. So we calculate that first.
        value, index = self._getNumber(s, index)
        node = TreeNode(value)
        
        # Next, if there is any data left, we check for the first subtree
        # which according to the problem statement will always be the left child.
        if index < len(s) and s[index] == '(':
            node.left, index = self._str2treeInternal(s, index + 1)
        
        # Indicates a right child
        if node.left and index < len(s) and s[index] == '(':
            node.right, index = self._str2treeInternal(s, index + 1)
        
        return node, index + 1 if index < len(s) and s[index] == ')' else index
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public TreeNode str2tree(String s) {
        
        if (s.isEmpty()) {
            return null;
        }
        
        TreeNode root = new TreeNode();
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        stack.add(root);
        
        for (int index = 0; index < s.length();) {
            
            TreeNode node = stack.pop();
            
            // NOT_STARTED
            if (Character.isDigit(s.charAt(index)) || s.charAt(index) == '-') {
                
                Pair<Integer, Integer> numberData = this.getNumber(s, index);
                int value = numberData.getKey();
                index = numberData.getValue();
                
                node.val = value;
                
                // Next, if there is any data left, we check for the first subtree
                // which according to the problem statement will always be the left child.
                if (index < s.length() && s.charAt(index) == '(') {
                    
                    stack.add(node);

                    node.left = new TreeNode();
                    stack.add(node.left);
                }
            } else if (s.charAt(index) == '(' && node.left != null) { // LEFT_DONE
                
                stack.add(node);

                node.right = new TreeNode();
                stack.add(node.right);
            }
            
            ++index;
        }
        
        return stack.empty() ? root : stack.pop();
        
    }
    
    public Pair<Integer, Integer> getNumber(String s, int index) {
        
        boolean isNegative = false;
        
        // A negative number
        if (s.charAt(index) == '-') {
            isNegative = true;
            index++;
        }
            
        int number = 0;
        while (index < s.length() && Character.isDigit(s.charAt(index))) {
            number = number * 10 + (s.charAt(index) - '0');
            index++;
        }
        
        return new Pair<Integer, Integer>(isNegative ? -number : number, index);
    } 
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python


class Solution:
    
    def str2tree(self, s: str) -> TreeNode:
        
        if not s:
            return None
        
        root = TreeNode()
        stack = [root]
        
        index = 0
        while index < len(s):
            
            node = stack.pop()

            # NOT_STARTED
            if s[index].isdigit() or s[index] == '-':
                value, index = self._getNumber(s, index)
                node.val = value

                # Next, if there is any data left, we check for the first subtree
                # which according to the problem statement will always be the left child.
                if index < len(s) and s[index] == '(':
                    stack.append(node)

                    node.left = TreeNode()
                    stack.append(node.left)
            
            # LEFT_DONE
            elif node.left and s[index] == '(':
                stack.append(node)

                node.right = TreeNode()
                stack.append(node.right)
            
            index += 1
        return stack.pop() if stack else root
    
    def _getNumber(self, s: str, index: int) -> (int, int):
        
        is_negative = False
        
        # A negative number
        if s[index] == '-':
            is_negative = True
            index = index + 1
        
        number = 0
        while index < len(s) and s[index].isdigit():
            number = number * 10 + int(s[index])
            index += 1
        
        return number if not is_negative else -number, index
```

</details>
