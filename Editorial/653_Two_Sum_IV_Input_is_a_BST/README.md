# 653. Two Sum IV - Input is a BST

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)  
`Hash Table` `Two Pointers` `Tree` `Depth-First Search` `Breadth-First Search` `Binary Search Tree` `Binary Tree`

**Problem Link:** [LeetCode 653 - Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Problem

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

### Example 1

```text
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

### Example 2

```text
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -104 <= Node.val <= 104
- root is guaranteed to be a valid binary search tree.
- -105 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Two Sum](https://leetcode.com/problems/two-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Sum BSTs](https://leetcode.com/problems/two-sum-bsts/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 653. Two Sum IV - Input is a BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using HashSet[Accepted] | Java |
| Approach #2 Using BFS and HashSet [Accepted] | Java |
| Approach #3 Using BST [Accepted] | Java |

## Approach #1 Using HashSet[Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set < Integer > set = new HashSet();
        return find(root, k, set);
    }
    public boolean find(TreeNode root, int k, Set < Integer > set) {
        if (root == null)
            return false;
        if (set.contains(k - root.val))
            return true;
        set.add(root.val);
        return find(root.left, k, set) || find(root.right, k, set);
    }
}
```

</details>

<br>

## Approach #2 Using BFS and HashSet [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set < Integer > set = new HashSet();
        Queue < TreeNode > queue = new LinkedList();
        queue.add(root);
        while (!queue.isEmpty()) {
            if (queue.peek() != null) {
                TreeNode node = queue.remove();
                if (set.contains(k - node.val))
                    return true;
                set.add(node.val);
                queue.add(node.right);
                queue.add(node.left);
            } else
                queue.remove();
        }
        return false;
    }
}
```

</details>

<br>

## Approach #3 Using BST [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public boolean findTarget(TreeNode root, int k) {
        List < Integer > list = new ArrayList();
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            int sum = list.get(l) + list.get(r);
            if (sum == k)
                return true;
            if (sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
    public void inorder(TreeNode root, List < Integer > list) {
        if (root == null)
            return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
}
```

</details>
