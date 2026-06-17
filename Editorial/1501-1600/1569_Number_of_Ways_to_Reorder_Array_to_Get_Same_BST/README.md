# 1569. Number of Ways to Reorder Array to Get Same BST

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)  
`Array` `Math` `Divide and Conquer` `Dynamic Programming` `Tree` `Union-Find` `Binary Search Tree` `Memoization` `Combinatorics` `Binary Tree`

**Problem Link:** [LeetCode 1569 - Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

## Problem

Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

- For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.

Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
```

### Example 2

```text
Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```

### Example 3

```text
Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= nums.length
- All integers in nums are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1569. Number of Ways to Reorder Array to Get Same BST

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Recursion | C++, Java, Python3 |

## Approach: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int m = nums.size();
        // Table of Pascal's triangle
        table.resize(m + 1);
        for(int i = 0; i < m + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        return (dfs(nums) - 1) % mod;
    }
    
private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;
    
    long long dfs(vector<int> &nums){
        int m = nums.size();
        if(m < 3) {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for(int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
		
        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;
		
        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private long mod = (long)1e9 + 7;
    private long[][] table;

    public int numOfWays(int[] nums) {
        int m = nums.length;
        
        // Table of Pascal's triangle
        table = new long[m][m];
        for (int i = 0; i < m; ++i) {
            table[i][0] = table[i][i] = 1;
        }
        for (int i = 2; i < m; i++) {
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        List<Integer> arrList = Arrays.stream(nums).boxed().collect(Collectors.toList());
        return (int)((dfs(arrList) - 1) % mod);
    }

    private long dfs(List<Integer> nums) {
        int m = nums.size();
        if (m < 3) {
            return 1;
        }

        List<Integer> leftNodes = new ArrayList<>();
        List<Integer> rightNodes = new ArrayList<>();
        for (int i = 1; i < m; ++i) {
            if (nums.get(i) < nums.get(0)) {
                leftNodes.add(nums.get(i));
            } else {
                rightNodes.add(nums.get(i));
            }
        }
        long leftWays = dfs(leftNodes) % mod;
        long rightWays = dfs(rightNodes) % mod;

        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        mod = 10 ** 9 + 7
        
        def dfs(nums):
            m = len(nums)
            if m < 3: 
                return 1
            left_nodes = [a for a in nums if a < nums[0]]
            right_nodes = [a for a in nums if a > nums[0]]
            return dfs(left_nodes) * dfs(right_nodes) * comb(m - 1, len(left_nodes)) % mod
        
        return (dfs(nums) - 1) % mod
```

</details>
