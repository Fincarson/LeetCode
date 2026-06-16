# 549. Binary Tree Longest Consecutive Sequence II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 549 - Binary Tree Longest Consecutive Sequence II](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)

## Problem

Given the root of a binary tree, return the length of the longest consecutive path in the tree.

A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.

- For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.

On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

### Example 1

```text
Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
```

### Example 2

```text
Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
```

## Constraints

- The number of nodes in the tree is in the range [1, 3 * 104].
- -3 * 104 <= Node.val <= 3 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check if an Array Is Consecutive](https://leetcode.com/problems/check-if-an-array-is-consecutive/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 549. Binary Tree Longest Consecutive Sequence II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #2 Single traversal | Java, Python3 |

## Approach #2 Single traversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    int maxval = 0;
    
    public int longestConsecutive(TreeNode root) {
        longestPath(root);
        return maxval;
    }
    
    public int[] longestPath(TreeNode root) {
        if (root == null) {
            return new int[] {0,0};
        }
        
        int inr = 1, dcr = 1;
        if (root.left != null) {
            int[] left = longestPath(root.left);
            if (root.val == root.left.val + 1) {
                dcr = left[1] + 1;
            } else if (root.val == root.left.val - 1) {
                inr = left[0] + 1;
            }
        }
        
        if (root.right != null) {
            int[] right = longestPath(root.right);
            if (root.val == root.right.val + 1) {
                dcr = Math.max(dcr, right[1] + 1);
            } else if (root.val == root.right.val - 1) {
                inr = Math.max(inr, right[0] + 1);
            }
        }
        
        maxval = Math.max(maxval, dcr + inr - 1);
        return new int[] {inr, dcr};
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
                
        def longest_path(root: TreeNode) -> List[int]:
            nonlocal maxval
            
            if not root:
                return [0, 0]
            
            inr = dcr = 1
            if root.left:
                left = longest_path(root.left)
                if (root.val == root.left.val + 1):
                    dcr = left[1] + 1
                elif (root.val == root.left.val - 1):
                    inr = left[0] + 1
            
            if root.right:
                right = longest_path(root.right)
                if (root.val == root.right.val + 1):
                    dcr = max(dcr, right[1] + 1)
                elif (root.val == root.right.val - 1):
                    inr = max(inr, right[0] + 1)
                    
            maxval = max(maxval, dcr + inr - 1)
            return [inr, dcr]
        
        maxval = 0
        longest_path(root)
        return maxval
```

</details>
