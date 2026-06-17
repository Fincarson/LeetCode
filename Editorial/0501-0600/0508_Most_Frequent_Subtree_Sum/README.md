# 508. Most Frequent Subtree Sum

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/most-frequent-subtree-sum/)  
`Hash Table` `Tree` `Depth-First Search` `Binary Tree`

**Problem Link:** [LeetCode 508 - Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

## Problem

Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

### Example 1

```text
Input: root = [5,2,-3]
Output: [2,-3,4]
```

### Example 2

```text
Input: root = [5,2,-5]
Output: [2]
```

## Constraints

- The number of nodes in the tree is in the range [1, 104].
- -105 <= Node.val <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Nodes Equal to Sum of Descendants](https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 508. Most Frequent Subtree Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Pre-Order Traversal | C++, Java, JavaScript, Python3 |
| Post-Order Traversal | C++, Java, JavaScript, Python3 |

## Approach 1: Pre-Order Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTreeSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        // Current root's tree's sum.
        return root -> val + findTreeSum(root -> left) + findTreeSum(root -> right);
    }
    
    void preOrderTraversal(TreeNode* root, unordered_map<int, int>& sumFreq, int& maxFreq) {
        if (!root) {
            return;
        }
        
        // Find current node's tree's sum.
        int currSum = findTreeSum(root);
        sumFreq[currSum]++;
        maxFreq = max(maxFreq, sumFreq[currSum]);
        
        // Iterate on left and right subtrees and find their sums.
        preOrderTraversal(root -> left, sumFreq, maxFreq);
        preOrderTraversal(root -> right, sumFreq, maxFreq);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        int maxFreq = 0;
        
        // Traverse on all nodes one by one, and find it's tree's sum.
        preOrderTraversal(root, sumFreq, maxFreq);
        
        vector<int> maxFreqSums;
        for(auto& it : sumFreq) {
            if (it.second == maxFreq) {
                maxFreqSums.push_back(it.first);
            }
        }
        
        return maxFreqSums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> sumFreq = new HashMap<Integer, Integer>();
    private Integer maxFreq = 0;
    
    private int findTreeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // Current root's tree's sum.
        return root.val + findTreeSum(root.left) + findTreeSum(root.right);
    }
    
    private void preOrderTraversal(TreeNode root) {
        if (root == null) {
            return;
        }
        
        // Find current node's tree's sum.
        int currSum = findTreeSum(root);
        sumFreq.put(currSum, sumFreq.getOrDefault(currSum, 0) + 1);
        maxFreq = Math.max(maxFreq, sumFreq.get(currSum));
        
        // Iterate on left and right subtrees and find their sums.
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }
    
    public int[] findFrequentTreeSum(TreeNode root) {
        // Traverse on all nodes one by one, and find it's tree's sum.
        preOrderTraversal(root);
        
        List<Integer> ansList = new ArrayList<Integer>(); 
        for (Map.Entry<Integer, Integer> mapElement : sumFreq.entrySet()) {
            Integer sum = mapElement.getKey();
            Integer freq = mapElement.getValue();
            
            if (freq == maxFreq) {
                ansList.add(sum);
            }
        }
        
        int maxFreqSums[] = new int[ansList.size()];
        for (int i = 0; i < ansList.size(); i++) {
            maxFreqSums[i] =  ansList.get(i).intValue();
        }
        
        return maxFreqSums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let sumFreq = {};
let maxFreq = 0;

let findTreeSum = (root) => {
    if (!root) {
        return 0;
    }
    // Current root's tree's sum.
    return root.val + findTreeSum(root.left) + findTreeSum(root.right);
}

let preOrderTraversal = (root) => {
    if (!root) {
        return;
    }

    // Find current node's tree's sum.
    let currSum = findTreeSum(root);
    sumFreq[currSum] = (sumFreq[currSum] ?? 0) + 1;
    maxFreq = Math.max(maxFreq, sumFreq[currSum]);

    // Iterate on left and right subtrees and find their sums.
    preOrderTraversal(root.left);
    preOrderTraversal(root.right);
}

let findFrequentTreeSum = function(root) {
    sumFreq = {};
    maxFreq = 0;
    
    // Traverse on all nodes one by one, and find it's tree's sum.
    preOrderTraversal(root);
    
    let maxFreqSums = [];
    for (let sum in sumFreq) {
        if (sumFreq[sum] == maxFreq) {
            maxFreqSums.push(sum);
        }
    }

    return maxFreqSums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:    
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        self.sum_freq = {}
        self.max_freq = 0
        
        def find_tree_sum(root):
            if not root:
                return 0
            # Current root's tree's sum.
            return root.val + find_tree_sum(root.left) + find_tree_sum(root.right)
        
        def pre_order_traversal(root):
            if not root:
                return

            # Find current node's tree's sum.
            curr_sum = find_tree_sum(root)
            self.sum_freq[curr_sum] = self.sum_freq.get(curr_sum, 0) + 1
            self.max_freq = max(self.max_freq, self.sum_freq[curr_sum])

            # Iterate on left and right subtrees and find their sums.
            pre_order_traversal(root.left)
            pre_order_traversal(root.right)
        
        # Traverse on all nodes one by one, and find it's tree's sum.
        pre_order_traversal(root)
        max_freq_sums = []
        for sum in self.sum_freq:
            if self.sum_freq[sum] == self.max_freq:
                max_freq_sums.append(sum)
        
        return max_freq_sums
```

</details>

<br>

## Approach 2: Post-Order Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int subtreeSum(TreeNode* root, unordered_map<int, int>& sumFreq, int& maxFreq) {
        if (!root) {
            return 0;
        }
        
        // Get left and right subtree's sum.
        int leftSubtreeSum = subtreeSum(root -> left, sumFreq, maxFreq);
        int rightSubtreeSum = subtreeSum(root -> right, sumFreq, maxFreq);
        
        // Use the sum of subtrees to get the sum of the current tree.
        int currSum = root -> val + leftSubtreeSum + rightSubtreeSum;
        
        sumFreq[currSum]++;
        maxFreq = max(maxFreq, sumFreq[currSum]);
        return currSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        int maxFreq = 0;
        
        // Traverse on all nodes one by one, and find it's tree's sum.
        subtreeSum(root, sumFreq, maxFreq);
        
        vector<int> maxFreqSums;
        for(auto& it : sumFreq) {
            if (it.second == maxFreq) {
                maxFreqSums.push_back(it.first);
            }
        }
        
        return maxFreqSums;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> sumFreq = new HashMap<Integer, Integer>();
    private Integer maxFreq = 0;
    
    private int subtreeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        // Get left and right subtree's sum.
        int leftSubtreeSum = subtreeSum(root.left);
        int rightSubtreeSum = subtreeSum(root.right);

        // Use child's tree's sums to get current root's tree's sum
        int currSum = root.val + leftSubtreeSum + rightSubtreeSum;
        
        sumFreq.put(currSum, sumFreq.getOrDefault(currSum, 0) + 1);
        maxFreq = Math.max(maxFreq, sumFreq.get(currSum));
        return currSum;
    }
    
    public int[] findFrequentTreeSum(TreeNode root) {
        // Traverse on all nodes one by one, and find it's tree's sum.
        subtreeSum(root);
        
        List<Integer> ansList = new ArrayList<Integer>(); 
        for (Map.Entry<Integer, Integer> mapElement : sumFreq.entrySet()) {
            Integer sum = mapElement.getKey();
            Integer freq = mapElement.getValue();
            
            if (freq == maxFreq) {
                ansList.add(sum);
            }
        }
        
        int maxFreqSums[] = new int[ansList.size()];
        for (int i = 0; i < ansList.size(); i++) {
            maxFreqSums[i] =  ansList.get(i).intValue();
        }
        
        return maxFreqSums;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let sumFreq = {};
let maxFreq = 0;

let subtreeSum = (root) => {
    if (!root) {
        return 0;
    }

    // Get left and right subtree's sum.
    let leftSubtreeSum = subtreeSum(root.left);
    let rightSubtreeSum = subtreeSum(root.right);

    // Use child's tree's sums to get current root's tree's sum
    let currSum = root.val + leftSubtreeSum + rightSubtreeSum;
    
    sumFreq[currSum] = (sumFreq[currSum] ?? 0) + 1;
    maxFreq = Math.max(maxFreq, sumFreq[currSum]);
    return currSum;
}

let findFrequentTreeSum = function(root) {
    sumFreq = {};
    maxFreq = 0;
    
    // Traverse on all nodes one by one, and find it's tree's sum.
    subtreeSum(root);
    
    let maxFreqSums = [];
    for (let sum in sumFreq) {
        if (sumFreq[sum] == maxFreq) {
            maxFreqSums.push(sum);
        }
    }

    return maxFreqSums;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:    
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        self.sum_freq = {}
        self.max_freq = 0
        
        def sub_tree_sum(root) -> int:
            if not root:
                return 0

            # Get left and right subtree's sum.
            left_subtree_sum = sub_tree_sum(root.left)
            right_subtree_sum = sub_tree_sum(root.right)

            # Use child's tree's sums to get current root's tree's sum
            curr_sum = root.val + left_subtree_sum + right_subtree_sum

            self.sum_freq[curr_sum] = self.sum_freq.get(curr_sum, 0) + 1
            self.max_freq = max(self.max_freq, self.sum_freq[curr_sum])
            return curr_sum
        
        # Traverse on all nodes one by one, and find it's tree's sum.
        sub_tree_sum(root)
        max_freq_sums = []
        for sum in self.sum_freq:
            if self.sum_freq[sum] == self.max_freq:
                max_freq_sums.append(sum)
        
        return max_freq_sums
```

</details>
