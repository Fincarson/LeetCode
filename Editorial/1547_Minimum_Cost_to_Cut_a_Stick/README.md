# 1547. Minimum Cost to Cut a Stick

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)  
`Array` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1547 - Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

## Problem

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

### Example 1

```text
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
```

### Example 2

```text
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
```

## Constraints

- 2 <= n <= 106
- 1 <= cuts.length <= min(n - 1, 100)
- 1 <= cuts[i] <= n - 1
- All the integers in cuts array are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Divide a Long Corridor](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1547. Minimum Cost to Cut a Stick

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-down Dynamic Programming | Java, Python3 |
| Bottom-up Dynamic Programming | Java, Python |

## Approach 1: Top-down Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    int newCuts[];
    private int cost(int left, int right) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (right - left == 1) {
            return 0;
        }
        int ans = Integer.MAX_VALUE;
        for (int mid = left + 1; mid < right; mid++) {
            int cost = cost(left, mid) + cost(mid, right) + newCuts[right] - newCuts[left];
            ans = Math.min(ans, cost);
        }
        memo[left][right] = ans;
        return ans;
    }
    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        newCuts = new int[m + 2];
        System.arraycopy(cuts, 0, newCuts, 1, m);
        newCuts[m + 1] = n;
        Arrays.sort(newCuts);
        
        memo = new int[m + 2][m + 2];
        for (int r = 0; r < m + 2; ++r) {
            Arrays.fill(memo[r], -1);
        }
        
        return cost(0, newCuts.length - 1);
    }    
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        memo = {}
        cuts = [0] + sorted(cuts) + [n]
        
        def cost(left, right):
            if (left, right) in memo:
                return memo[(left, right)]
            if right - left == 1:
                return 0
            ans = min(cost(left, mid) + cost(mid, right) + cuts[right] - cuts[left] for mid in range(left + 1, right))
            memo[(left, right)] = ans
            return ans
        
        return cost(0, len(cuts) - 1)
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        int[] newCuts = new int[m + 2];
        System.arraycopy(cuts, 0, newCuts, 1, m);
        newCuts[m + 1] = n;
        Arrays.sort(newCuts);
        
        int[][] dp = new int[m + 2][m + 2];
        
        for (int diff = 2; diff < m + 2; ++diff) {
            for (int left = 0; left < m + 2 - diff; ++left) {
                int right = left + diff;
                int ans = Integer.MAX_VALUE;
                for (int mid = left + 1; mid < right; ++mid) {
                    ans = Math.min(ans, dp[left][mid] + dp[mid][right] + newCuts[right] - newCuts[left]);
                }
                dp[left][right] = ans;
            }
        } 
        
        return dp[0][m + 1];
    }    
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        m = len(cuts)
        cuts = [0] + sorted(cuts) + [n]
        
        dp = [[0] * (m + 2) for _ in range(m + 2)]
        
        for diff in range(2, m + 2):
            for left in range(m + 2 - diff):
                right = left + diff
                ans = float('inf')
                for mid in range(left + 1, right):
                    ans = min(ans, dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left])
                dp[left][right] = ans
        
        return dp[0][m + 1]
```

</details>
