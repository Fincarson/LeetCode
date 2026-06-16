# 437. Path Sum III

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/path-sum-iii/)  
`Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 437 - Path Sum III](https://leetcode.com/problems/path-sum-iii/)

## Problem

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

### Example 1

```text
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
```

### Example 2

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

## Constraints

- The number of nodes in the tree is in the range [0, 1000].
- -109 <= Node.val <= 109
- -1000 <= targetSum <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Path Sum](https://leetcode.com/problems/path-sum/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Path Sum IV](https://leetcode.com/problems/path-sum-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 437. Path Sum III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Sum | Java, Python3 |

## Approach 1: Prefix Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int count = 0;
    int k;
    HashMap<Long, Integer> h = new HashMap();
    
    public void preorder(TreeNode node, long currSum) {
        if (node == null)
            return;
        
        // The current prefix sum
        currSum += node.val;

        // Here is the sum we're looking for
        if (currSum == k)
            count++;
        
        // The number of times the curr_sum − k has occurred already, 
        // determines the number of times a path with sum k 
        // has occurred up to the current node
        count += h.getOrDefault(currSum - k, 0);
        
        //Add the current sum into the hashmap
        // to use it during the child node's processing
        h.put(currSum, h.getOrDefault(currSum, 0) + 1);

        // Process the left subtree
        preorder(node.left, currSum);

        // Process the right subtree
        preorder(node.right, currSum);

        // Remove the current sum from the hashmap
        // in order not to use it during 
        // the parallel subtree processing
        h.put(currSum, h.get(currSum) - 1);
    }    
            
    public int pathSum(TreeNode root, int sum) {
        k = sum;
        preorder(root, 0L);
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def preorder(node: TreeNode, curr_sum) -> None:
            nonlocal count
            if not node:
                return 
            
            # The current prefix sum
            curr_sum += node.val
            
            # Here is the sum we're looking for
            if curr_sum == k:
                count += 1
            
            # The number of times the curr_sum − k has occurred already, 
            # determines the number of times a path with sum k 
            # has occurred up to the current node
            count += h[curr_sum - k]
            
            # Add the current sum into a hashmap
            # to use it during the child nodes' processing
            h[curr_sum] += 1
            
            # Process the left subtree
            preorder(node.left, curr_sum)
            # Process the right subtree
            preorder(node.right, curr_sum)
            
            # Remove the current sum from the hashmap
            # in order not to use it during 
            # the parallel subtree processing
            h[curr_sum] -= 1
            
        count, k = 0, sum
        h = defaultdict(int)
        preorder(root, 0)
        return count
```

</details>
