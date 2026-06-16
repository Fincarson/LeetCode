# 1008. Construct Binary Search Tree from Preorder Traversal

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)  
`Array` `Stack` `Tree` `Binary Search Tree` `Monotonic Stack` `Binary Tree`

**Problem Link:** [LeetCode 1008 - Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

## Problem

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

### Example 1

```text
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
```

### Example 2

```text
Input: preorder = [1,3]
Output: [1,null,3]
```

## Constraints

- 1 <= preorder.length <= 100
- 1 <= preorder[i] <= 1000
- All the values of preorder are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1008. Construct Binary Search Tree from Preorder Traversal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Construct binary tree from preorder and inorder traversal | Java, Python |
| Recursion | Java, Python |
| Iteration | Java, Python |

## Approach 1: Construct binary tree from preorder and inorder traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  //Start from the first preorder element
  int pre_idx = 0;
  int[] preorder;
  HashMap<Integer, Integer> idx_map = new HashMap<Integer, Integer>();

  public TreeNode helper(int in_left, int in_right) {
    //If there is no elements to construct subtrees
    if (in_left == in_right)
      return null;

    // pick up pre_idx element as a root
    int root_val = preorder[pre_idx];
    TreeNode root = new TreeNode(root_val);

    // root splits inorder list
    // into left and right subtrees
    int index = idx_map.get(root_val);

    // recursion 
    pre_idx++;
    // build the left subtree
    root.left = helper(in_left, index);
    // build the right subtree
    root.right = helper(index + 1, in_right);
    return root;
  }

  public TreeNode bstFromPreorder(int[] preorder) {
    this.preorder = preorder;
    int [] inorder = Arrays.copyOf(preorder, preorder.length);
    Arrays.sort(inorder);

    // build a hashmap value -> its index
    int idx = 0;
    for (Integer val : inorder)
      idx_map.put(val, idx++);
    return helper(0, inorder.length);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def helper(in_left = 0, in_right = len(preorder)):
            nonlocal pre_idx
            # If there is no elements to construct subtrees
            if in_left == in_right:
                return None
            
            # pick up pre_idx element as a root
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[root_val]

            # recursion 
            pre_idx += 1
            # build the left subtree
            root.left = helper(in_left, index)
            # build the right subtree
            root.right = helper(index + 1, in_right)
            return root
        
        inorder = sorted(preorder)
        # start from the first preorder element
        pre_idx = 0
        # build a hashmap value -> its index
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper()
```

</details>

<br>

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  int idx = 0;
  int[] preorder;
  int n;

  public TreeNode helper(int lower, int upper) {
    //If all elements from preorder are used
    // then the tree is constructed
    if (idx == n) return null;

    int val = preorder[idx];
    //If the current element 
    // couldn't be placed here to meet BST requirements
    if (val < lower || val > upper) return null;

    //Place the current element
    // and recursively construct subtrees
    idx++;
    TreeNode root = new TreeNode(val);
    root.left = helper(lower, val);
    root.right = helper(val, upper);
    return root;
  }

  public TreeNode bstFromPreorder(int[] preorder) {
    this.preorder = preorder;
    n = preorder.length;
    return helper(Integer.MIN_VALUE, Integer.MAX_VALUE);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def helper(lower = float('-inf'), upper = float('inf')):
            nonlocal idx
            # If all elements from preorder are used
            # Then the tree is constructed
            if idx == n:
                return None
            
            val = preorder[idx]
            # If the current element 
            # couldn't be placed here to meet BST requirements
            if val < lower or val > upper:
                return None
            
            # place the current element
            # and recursively construct subtrees
            idx += 1
            root = TreeNode(val)
            root.left = helper(lower, val)
            root.right = helper(val, upper)
            return root
        
        idx = 0
        n = len(preorder)
        return helper()
```

</details>

<br>

## Approach 3: Iteration

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public TreeNode bstFromPreorder(int[] preorder) {
    int n = preorder.length;
    if (n == 0) return null;

    TreeNode root = new TreeNode(preorder[0]);
    Deque<TreeNode> deque = new ArrayDeque<TreeNode>();
    deque.push(root);

    for (int i = 1; i < n; i++) {
      //Take the last element of the deque as a parent
      // and create a child from the next preorder element
      TreeNode node = deque.peek();
      TreeNode child = new TreeNode(preorder[i]);
      //Adjust the parent 
      while (!deque.isEmpty() && deque.peek().val < child.val)
        node = deque.pop();

      // follow BST logic to create a parent-child link
      if (node.val < child.val) node.right = child;
      else node.left = child;
      // add the child into deque
      deque.push(child);
    }
    return root;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        n = len(preorder)
        if not n:
            return None
        
        root = TreeNode(preorder[0])         
        stack = [root, ] 
        
        for i in range(1, n):
            # take the last element of the stack as a parent
            # and create a child from the next preorder element
            node, child = stack[-1], TreeNode(preorder[i])
            # adjust the parent 
            while stack and stack[-1].val < child.val: 
                node = stack.pop()
             
            # follow BST logic to create a parent-child link
            if node.val < child.val:
                node.right = child 
            else:
                node.left = child 
            # add the child into stack
            stack.append(child)
  
        return root
```

</details>
