# 3068. Find the Maximum Sum of Node Values

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-maximum-sum-of-node-values/)  
`Array` `Dynamic Programming` `Greedy` `Bit Manipulation` `Tree` `Sorting`

**Problem Link:** [LeetCode 3068 - Find the Maximum Sum of Node Values](https://leetcode.com/problems/find-the-maximum-sum-of-node-values/)

## Problem

There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

- Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:

		nums[u] = nums[u] XOR k
		nums[v] = nums[v] XOR k

Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

### Example 1

```text
Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
Output: 6
Explanation: Alice can achieve the maximum sum of 6 using a single operation:
- Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array nums becomes: [1,2,1] -> [2,2,2].
The total sum of values is 2 + 2 + 2 = 6.
It can be shown that 6 is the maximum achievable sum of values.
```

### Example 2

```text
Input: nums = [2,3], k = 7, edges = [[0,1]]
Output: 9
Explanation: Alice can achieve the maximum sum of 9 using a single operation:
- Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3 XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
The total sum of values is 5 + 4 = 9.
It can be shown that 9 is the maximum achievable sum of values.
```

### Example 3

```text
Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
Output: 42
Explanation: The maximum achievable sum is 42 which can be achieved by Alice performing no operations.
```

## Constraints

- 2 <= n == nums.length <= 2 * 104
- 1 <= k <= 109
- 0 <= nums[i] <= 109
- edges.length == n - 1
- edges[i].length == 2
- 0 <= edges[i][0], edges[i][1] <= n - 1
- The input is generated such that edges represent a valid tree.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Score After Applying Operations on a Tree](https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Number of Coins to Place in Tree Nodes](https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3068. Find the Maximum Sum of Node Values

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming - Memoization | C++, Java, Python3 |
| Bottom-up Dynamic Programming (Tabulation) | C++, Java, Python3 |
| Greedy (Sorting based approach) | C++, Java, Python3 |
| Greedy (Finding local maxima and minima) | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming - Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

private:
    long long maxSumOfNodes(int index, int isEven, vector<int>& nums, int k,
                            vector<vector<long long>>& memo) {
        if (index == nums.size()) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long long noXorDone =
            nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long long xorDone = (nums[index] ^ k) +
                            maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = max(xorDone, noXorDone);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long[][] memo = new long[nums.length][2];
        for (long[] row : memo) {
            Arrays.fill(row, -1);
        }
        return maxSumOfNodes(0, 1, nums, k, memo);
    }

    private long maxSumOfNodes(int index, int isEven, int[] nums, int k,
            long[][] memo) {
        if (index == nums.length) {
            // If the operation is performed on an odd number of elements return
            // INT_MIN
            return isEven == 1 ? 0 : Integer.MIN_VALUE;
        }
        if (memo[index][isEven] != -1) {
            return memo[index][isEven];
        }
        // No operation performed on the element
        long noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
        // XOR operation is performed on the element
        long xorDone = (nums[index] ^ k) +
                maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

        // Memoize and return the result
        return memo[index][isEven] = Math.max(xorDone, noXorDone);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumOfNodes(self, index, isEven, nums, k, memo):
        if index == len(nums):
            # If the operation is performed on an odd number of elements return INT_MIN
            return 0 if isEven == 1 else -float("inf")
        if memo[index][isEven] != -1:
            return memo[index][isEven]

        # No operation performed on the element
        noXorDone = nums[index] + self.maxSumOfNodes(index + 1, isEven, nums, k, memo)
        # XOR operation is performed on the element
        xorDone = (nums[index] ^ k) + self.maxSumOfNodes(
            index + 1, isEven ^ 1, nums, k, memo
        )

        # Memoize and return the result
        memo[index][isEven] = max(xorDone, noXorDone)
        return memo[index][isEven]

    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        memo = [[-1] * 2 for _ in range(len(nums))]
        return self.maxSumOfNodes(0, 1, nums, k, memo)
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[n][1] = 0;
        dp[n][0] = INT_MIN;
        
        for (int index = n - 1; index >= 0; index--) {
            for (int isEven = 0; isEven <= 1; isEven++) {
                // Case 1: we perform the operation on this element.
                long long performOperation =
                    dp[index + 1][isEven ^ 1] + (nums[index] ^ k);
                // Case 2: we don't perform operation on this element.
                long long dontPerformOperation =
                    dp[index + 1][isEven] + nums[index];

                dp[index][isEven] = max(performOperation, dontPerformOperation);
            }
        }
        return dp[0][1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.length;
        long[][] dp = new long[n + 1][2];
        dp[n][1] = 0;
        dp[n][0] = Integer.MIN_VALUE;
        
        for (int index = n - 1; index >= 0; index--) {
            for (int isEven = 0; isEven <= 1; isEven++) {
                // Case 1: we perform the operation on this element.
                long performOperation = dp[index + 1][isEven ^ 1] + (nums[index] ^ k);
                // Case 2: we don't perform operation on this element.
                long dontPerformOperation = dp[index + 1][isEven] + nums[index];

                dp[index][isEven] = Math.max(performOperation, dontPerformOperation);
            }
        }
        
        return dp[0][1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        dp = [[0] * 2 for _ in range(n + 1)]
        dp[n][1] = 0
        dp[n][0] = -float('inf')
        
        for index in range(n - 1, -1, -1):
            for isEven in range(2):
                # Case 1: we perform an operation on this element.
                performOperation = dp[index + 1][isEven ^ 1] + (nums[index] ^ k)
                # Case 2: we don't perform operation on this element.
                dontPerformOperation = dp[index + 1][isEven] + nums[index]

                dp[index][isEven] = max(performOperation, dontPerformOperation)
        
        return dp[0][1]
```

</details>

<br>

## Approach 3: Greedy (Sorting based approach)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<int> netChange;
        long long nodeSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            netChange.push_back((nums[i] ^ k) - nums[i]);
            nodeSum += 1ll * nums[i];
        }
        
        // Sort netChange in decreasing order
        sort(netChange.begin(), netChange.end(), greater<int>());
        
        for (int i = 0; i < netChange.size(); i += 2) {
            // If netChange contains odd number of elements break the loop
            if (i + 1 == netChange.size()) {
                break;
            }
            long long pairSum = netChange[i] + netChange[i + 1];
            
            // Include in nodeSum if pairSum is positive
            if (pairSum > 0) {
                nodeSum += pairSum;
            }
        }
        return nodeSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.length;
        int[] netChange = new int[n];
        long nodeSum = 0;

        for (int i = 0; i < n; i++) {
            netChange[i] = (nums[i] ^ k) - nums[i];
            nodeSum += nums[i];
        }

        Arrays.sort(netChange);
        // Reverse the sorted array
        for (int i = 0; i < n / 2; i++) {
            int temp = netChange[i];
            netChange[i] = netChange[n - 1 - i];
            netChange[n - 1 - i] = temp;
        }

        for (int i = 0; i < n; i += 2) {
            // If netChange contains odd number of elements break the loop
            if (i + 1 == n) {
                break;
            }
            long pairSum = netChange[i] + netChange[i + 1];
            // Include in nodeSum if pairSum is positive
            if (pairSum > 0) {
                nodeSum += pairSum;
            }
        }
        return nodeSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        netChange = [(nums[i] ^ k) - nums[i] for i in range(n)]
        nodeSum = sum(nums)

        netChange.sort(reverse=True)

        for i in range(0, n, 2):
            # If netChange contains odd number of elements break the loop
            if i + 1 == n:
                break
            pairSum = netChange[i] + netChange[i + 1]
            # Include in nodeSum if pairSum is positive
            if pairSum > 0:
                nodeSum += pairSum

        return nodeSum
```

</details>

<br>

## Approach 4: Greedy (Finding local maxima and minima)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0, positiveMinimum = (1 << 30),
            negativeMaximum = -1 * (1 << 30);
            
        for (int nodeValue : nums) {
            int operatedNodeValue = nodeValue ^ k;
            sum += nodeValue;
            int netChange = operatedNodeValue - nodeValue;
            
            if (netChange > 0) {
                positiveMinimum = min(positiveMinimum, netChange);
                sum += netChange;
                count++;
            } else {
                negativeMaximum = max(negativeMaximum, netChange);
            }
        }
        
        // If the number of positive netChange values is even return the sum.
        if (count % 2 == 0) {
            return sum;
        }
        
        // Otherwise return the maximum of both discussed cases.
        return max(sum - positiveMinimum, sum + negativeMaximum);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long sum = 0;
        int count = 0, positiveMinimum = (1 << 30), negativeMaximum = -1 * (1 << 30);

        for (int nodeValue : nums) {
            int operatedNodeValue = nodeValue ^ k;
            sum += nodeValue;
            int netChange = operatedNodeValue - nodeValue;
            if (netChange > 0) {
                positiveMinimum = Math.min(positiveMinimum, netChange);
                sum += netChange;
                count++;
            } else {
                negativeMaximum = Math.max(negativeMaximum, netChange);
            }
        }

        // If the number of positive netChange values is even, return the sum.
        if (count % 2 == 0) {
            return sum;
        }

        // Otherwise return the maximum of both discussed cases.
        return Math.max(sum - positiveMinimum, sum + negativeMaximum);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        sumVal = 0
        count = 0
        positiveMinimum = 1 << 30
        negativeMaximum = -1 * (1 << 30)

        for nodeValue in nums:
            operatedNodeValue = nodeValue ^ k
            sumVal += nodeValue
            netChange = operatedNodeValue - nodeValue
            if netChange > 0:
                positiveMinimum = min(positiveMinimum, netChange)
                sumVal += netChange
                count += 1
            else:
                negativeMaximum = max(negativeMaximum, netChange)

        # If the number of positive netChange values is even, return the sum.
        if count % 2 == 0:
            return sumVal

        # Otherwise return the maximum of both discussed cases.
        return max(sumVal - positiveMinimum, sumVal + negativeMaximum)
```

</details>
