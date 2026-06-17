# 270. Closest Binary Search Tree Value

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/closest-binary-search-tree-value/)  
`Binary Search` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 270 - Closest Binary Search Tree Value](https://leetcode.com/problems/closest-binary-search-tree-value/)

## Problem

Given the root of a binary search tree and a target value, return the value in the BST that is closest to the target. If there are multiple answers, print the smallest.

### Example 1

```text
Input: root = [4,2,5,1,3], target = 3.714286
Output: 4
```

### Example 2

```text
Input: root = [1], target = 4.428571
Output: 1
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- 0 <= Node.val <= 109
- -109 <= target <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Closest Nodes Queries in a Binary Search Tree](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 270. Closest Binary Search Tree Value

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Inorder + Linear search, O(N) time | Java, Python |
| Iterative Inorder, O(k) time | Java, Python |
| Binary Search, O(H) time | Java, Python |

## Approach 1: Recursive Inorder + Linear search, O(N) time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public void inorder(TreeNode root, List<Integer> nums) {
    if (root == null) return;
    inorder(root.left, nums);
    nums.add(root.val);
    inorder(root.right, nums);
  }

  public int closestValue(TreeNode root, double target) {
    List<Integer> nums = new ArrayList();
    inorder(root, nums);
    return Collections.min(nums, new Comparator<Integer>() {
      @Override
      public int compare(Integer o1, Integer o2) {
        return Math.abs(o1 - target) < Math.abs(o2 - target) ? -1 : 1;
      }
    });
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        def inorder(r: TreeNode):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        return min(inorder(root), key = lambda x: abs(target - x))
```

</details>

<br>

## Approach 2: Iterative Inorder, O(k) time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int closestValue(TreeNode root, double target) {
    LinkedList<TreeNode> stack = new LinkedList();
    long pred = Long.MIN_VALUE;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.removeLast();

      if (pred <= target && target < root.val)
        return Math.abs(pred - target) <= Math.abs(root.val - target) ? (int)pred : root.val;

      pred = root.val;
      root = root.right;
    }
    return (int)pred;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        stack, pred = [], float('-inf')
        
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            
            if pred <= target and target < root.val:
                return min(pred, root.val, key = lambda x: abs(target - x))
                
            pred = root.val
            root = root.right

        return pred
```

</details>

<br>

## Approach 3: Binary Search, O(H) time

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int closestValue(TreeNode root, double target) {
    int val, closest = root.val;
    while (root != null) {
      val = root.val;
      closest = Math.abs(val - target) < Math.abs(closest - target) 
          || (Math.abs(val - target) == Math.abs(closest - target) && val < closest) ? val : closest;
      root =  target < root.val ? root.left : root.right;
    }
    return closest;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        closest = root.val
        while root:
            closest = min(root.val, closest, key = lambda x: (abs(target - x), x))
            root = root.left if target < root.val else root.right
        return closest
```

</details>
