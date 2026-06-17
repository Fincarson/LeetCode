# 1305. All Elements in Two Binary Search Trees

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)  
`Tree` `Depth-First Search` `Binary Search Tree` `Sorting` `Binary Tree`

**Problem Link:** [LeetCode 1305 - All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)

## Problem

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

### Example 1

```text
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
```

### Example 2

```text
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
```

## Constraints

- The number of nodes in each tree is in the range [0, 5000].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1305. All Elements in Two Binary Search Trees

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Inorder Traversal + Sort, Linearithmic Time. | Java, Python |
| Iterative Inorder Traversal, One Pass, Linear Time. | Java, Python |

## Approach 1: Recursive Inorder Traversal + Sort, Linearithmic Time.

### Implementation

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
  public List<Integer> inorder(TreeNode root, List<Integer> arr) {
    if (root == null) return arr;
    inorder(root.left, arr);
    arr.add(root.val);
    inorder(root.right, arr);
    return arr;
  }

  public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
    List<Integer> output = new ArrayList<>();
    Stream.of(inorder(root1, new ArrayList()), inorder(root2, new ArrayList())).forEach(output::addAll);
    Collections.sort(output);
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(r: TreeNode):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        return sorted(inorder(root1) + inorder(root2))
```

</details>

<br>

## Approach 2: Iterative Inorder Traversal, One Pass, Linear Time.

### Implementation

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
  public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
    ArrayDeque<TreeNode> stack1 = new ArrayDeque(), stack2 = new ArrayDeque();
    List<Integer> output = new ArrayList();

    while (root1 != null || root2 != null || !stack1.isEmpty() || !stack2.isEmpty()) {
      // update both stacks
      // by going left till possible
      while (root1 != null) {
        stack1.push(root1);
        root1 = root1.left;
      }
      while (root2 != null) {
        stack2.push(root2);
        root2 = root2.left;
      }

      // Add the smallest value into output,
      // pop it from the stack,
      // and then do one step right
      if (stack2.isEmpty() || !stack1.isEmpty() && stack1.getFirst().val <= stack2.getFirst().val) {
        root1 = stack1.pop();
        output.add(root1.val);
        root1 = root1.right;
      }
      else {
        root2 = stack2.pop();
        output.add(root2.val);
        root2 = root2.right;
      }
    }
    return output;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        stack1, stack2, output = [], [], []
        
        while root1 or root2 or stack1 or stack2:
            # update both stacks
            # by going left till possible
            while root1:
                stack1.append(root1)
                root1 = root1.left
            while root2:
                stack2.append(root2)
                root2 = root2.left

            # Add the smallest value into output,
            # pop it from the stack,
            # and then do one step right
            if not stack2 or stack1 and stack1[-1].val <= stack2[-1].val:
                root1 = stack1.pop()
                output.append(root1.val)
                root1 = root1.right
            else:
                root2 = stack2.pop()
                output.append(root2.val)   
                root2 = root2.right

        return output
```

</details>
