# 606. Construct String from Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-string-from-binary-tree/)  
`String` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 606 - Construct String from Binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/)

## Problem

Given the root node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

- Node Representation: Each node in the tree should be represented by its integer value.
- Parentheses for Children: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:

		If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
		If a node has a right child, the value of the right child should also be enclosed in parentheses. The parentheses for the right child should follow those of the left child.
- Omitting Empty Parentheses: Any empty parentheses pairs (i.e., ()) should be omitted from the final string representation of the tree, with one specific exception: when a node has a right child but no left child. In such cases, you must include an empty pair of parentheses to indicate the absence of the left child. This ensures that the one-to-one mapping between the string representation and the original binary tree structure is maintained.

	In summary, empty parentheses pairs should be omitted when a node has only a left child or no children. However, when a node has a right child but no left child, an empty pair of parentheses must precede the representation of the right child to reflect the tree's structure accurately.

### Example 1

```text
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the empty parenthesis pairs. And it will be "1(2(4))(3)".
```

### Example 2

```text
Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except the () after 2 is necessary to indicate the absence of a left child for 2 and the presence of a right child.
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -1000 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Construct Binary Tree from String](https://leetcode.com/problems/construct-binary-tree-from-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 606. Construct String from Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach 1 Using Recursion | Java |
| Approach 2 Iterative Method Using stack | Java |

## Approach 1 Using Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public String tree2str(TreeNode t) {
        StringBuilder res = new StringBuilder();
        dfs(t, res);
        return res.toString();
    }

    public static void dfs(TreeNode t, StringBuilder res) {
        if (t == null)
            return;
        res.append(String.valueOf(t.val));
        if (t.left == null && t.right == null)
            return;
        res.append('(');
        dfs(t.left, res);
        res.append(')');
        if (t.right != null) {
            res.append('(');
            dfs(t.right, res);
            res.append(')');
        }
    }
}
```

</details>

<br>

## Approach 2 Iterative Method Using stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public String tree2str(TreeNode t) {
        if (t == null)
            return "";
        Stack < TreeNode > stack = new Stack < > ();
        stack.push(t);
        Set < TreeNode > visited = new HashSet < > ();
        StringBuilder s = new StringBuilder();
        while (!stack.isEmpty()) {
            t = stack.peek();
            if (visited.contains(t)) {
                stack.pop();
                s.append(")");
            } else {
                visited.add(t);
                s.append("(" + t.val);
                if (t.left == null && t.right != null)
                    s.append("()");
                if (t.right != null)
                    stack.push(t.right);
                if (t.left != null)
                    stack.push(t.left);
            }
        }
        return s.substring(1, s.length() - 1);
    }
}
```

</details>
