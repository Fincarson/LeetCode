# 654. Maximum Binary Tree

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-binary-tree/)  
`Array` `Divide and Conquer` `Stack` `Tree` `Monotonic Stack` `Binary Tree`

**Problem Link:** [LeetCode 654 - Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)

## Problem

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Return the maximum binary tree built from nums.

### Example 1

```text
Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
```

### Example 2

```text
Input: nums = [3,2,1]
Output: [3,null,2,null,1]
```

## Constraints

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 1000
- All integers in nums are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Binary Tree II](https://leetcode.com/problems/maximum-binary-tree-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 654. Maximum Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Solution | Java |

## Approach 1: Recursive Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length);
    }
    public TreeNode construct(int[] nums, int l, int r) {
        if (l == r)
            return null;
        int max_i = max(nums, l, r);
        TreeNode root = new TreeNode(nums[max_i]);
        root.left = construct(nums, l, max_i);
        root.right = construct(nums, max_i + 1, r);
        return root;
    }
    public int max(int[] nums, int l, int r) {
        int max_i = l;
        for (int i = l; i < r; i++) {
            if (nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
}
```

</details>
