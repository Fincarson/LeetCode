# 1339. Maximum Product of Splitted Binary Tree

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 1339 - Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

## Problem

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

### Example 1

```text
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
```

### Example 2

```text
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
```

## Constraints

- The number of nodes in the tree is in the range [2, 5 * 104].
- 1 <= Node.val <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Nodes With the Highest Score](https://leetcode.com/problems/count-nodes-with-the-highest-score/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1339. Maximum Product of Splitted Binary Tree

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One-Pass DFS | Java, Python |
| Two-Pass DFS | Java, Python |
| Advanced Strategies for Dealing with 32-Bit Integers | Java |

## Approach 1: One-Pass DFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private List<Integer> allSums = new ArrayList<>();

    public int maxProduct(TreeNode root) {
        // long is a 64-bit integer.
        long totalSum = treeSum(root);
        long best = 0;
        for (long sum : allSums) {
            best = Math.max(best, sum * (totalSum - sum));
        }
        // We have to cast back to an int to match return value.
        return (int)(best % 1000000007);

    }

    private int treeSum(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = treeSum(subroot.left);
        int rightSum = treeSum(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        allSums.add(totalSum);
        return totalSum;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def maxProduct(self, root: TreeNode) -> int:
    all_sums = []

    def tree_sum(subroot):
        if subroot is None: return 0
        left_sum = tree_sum(subroot.left)
        right_sum = tree_sum(subroot.right)
        total_sum = left_sum + right_sum + subroot.val
        all_sums.append(total_sum)
        return total_sum

    total = tree_sum(root)
    best = 0
    for s in all_sums:
        best = max(best, s * (total - s))   
    return best % (10 ** 9 + 7)
```

</details>

<br>

## Approach 2: Two-Pass DFS

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private long maximumProduct = 0;
    private int totalTreeSum = 0;

    private int treeSum(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = treeSum(subroot.left);
        int rightSum = treeSum(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        return totalSum;
    }

    private int findMaximumProduct(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = findMaximumProduct(subroot.left);
        int rightSum = findMaximumProduct(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        long totalProduct = (long)totalSum * (totalTreeSum - totalSum);
        this.maximumProduct = Math.max(this.maximumProduct, totalProduct);
        return totalSum;
    }

    public int maxProduct(TreeNode root) {
        this.totalTreeSum = treeSum(root);
        findMaximumProduct(root);
        return (int)(maximumProduct % 1000000007);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
def maxProduct(self, root: TreeNode) -> int:

    def tree_sum(subroot):
        if subroot is None: return 0
        left_sum = tree_sum(subroot.left)
        right_sum = tree_sum(subroot.right)
        return left_sum + right_sum + subroot.val

    def maximum_product(subroot, total):
        best = 0
        def recursive_helper(subroot):
            nonlocal best
            if subroot is None: return 0
            left_sum = recursive_helper(subroot.left)
            right_sum = recursive_helper(subroot.right)
            total_sum = left_sum + right_sum + subroot.val
            product = total_sum * (tree_total_sum - total_sum)
            best = max(best, product)
            return total_sum
        recursive_helper(subroot)
        return best

    tree_total_sum = tree_sum(root)
    return maximum_product(root, tree_total_sum) % (10 ** 9 + 7)
```

</details>

<br>

## Approach 3: Advanced Strategies for Dealing with 32-Bit Integers

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

    private static final int MOD = 1000000007;

    private List<Integer> allSums = new ArrayList<>();

    public int maxProduct(TreeNode root) {
        int totalSum = treeSum(root);
        int nearestToHalf = 0;
        int smallestDistanceBetween = Integer.MAX_VALUE;
        for (int sum : allSums) {
            // We want to do this in a way that doesn't require floats.
            // One way is to minimise the *distance* between the 2 halves.
            int distanceBetween = Math.abs(totalSum - sum * 2);
            if (distanceBetween < smallestDistanceBetween) {
                smallestDistanceBetween = distanceBetween;
                nearestToHalf = sum;
            }
        }
        return modularMultiplication(nearestToHalf, totalSum - nearestToHalf, MOD);
    }


    private int modularMultiplication(int a, int b, int m) {
        int product = 0;
        int currentSum = a;
        while (b > 0) {
            int bit = b % 2;
            b >>= 1;
            if (bit == 1) {
                product += currentSum;
                product %= m;
            }
            currentSum <<= 1;
            currentSum %= m;
        }
        return product;
    }    

    private int treeSum(TreeNode subroot) {
        if (subroot == null) return 0;
        int leftSum = treeSum(subroot.left);
        int rightSum = treeSum(subroot.right);
        int totalSum = leftSum + rightSum + subroot.val;
        allSums.add(totalSum);
        return totalSum;
    }
}
```

</details>
