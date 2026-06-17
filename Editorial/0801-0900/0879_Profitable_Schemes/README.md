# 879. Profitable Schemes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/profitable-schemes/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 879 - Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)

## Problem

There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.
```

### Example 2

```text
Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
```

## Constraints

- 1 <= n <= 100
- 0 <= minProfit <= 100
- 1 <= group.length <= 100
- 1 <= group[i] <= 100
- profit.length == group.length
- 0 <= profit[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 879. Profitable Schemes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mod = 1e9 + 7;
    int memo[101][101][101];
    
    int find(int pos, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
        if (pos == group.size()) {
            // If profit exceeds the minimum required; it's a profitable scheme.
            return profit >= minProfit;
        }
        
        if (memo[pos][count][profit] != -1) {
            // Repeated subproblem, return the stored answer.
            return memo[pos][count][profit];
        }
        
        // Ways to get a profitable scheme without this crime.
        int totalWays = find(pos + 1, count, profit, n, minProfit, group, profits);
        if (count + group[pos] <= n) {
            // Adding ways to get profitable schemes, including this crime.
            totalWays += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
        }
        
        return memo[pos][count][profit] = totalWays % mod;
    }
             
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, -1,sizeof(memo));
        return find(0, 0, 0, n, minProfit, group, profit);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int mod = 1000000007;
    int[][][] memo = new int[101][101][101];
    
    int find(int pos, int count, int profit, int n, int minProfit, int[] group, int[] profits) {
        if (pos == group.length) {
            // If profit exceeds the minimum required; it's a profitable scheme.
            return profit >= minProfit ? 1 : 0;
        }
        
        if (memo[pos][count][profit] != -1) {
            // Repeated subproblem, return the stored answer.
            return memo[pos][count][profit];
        }
        
        // Ways to get a profitable scheme without this crime.
        int totalWays = find(pos + 1, count, profit, n, minProfit, group, profits);
        if (count + group[pos] <= n) {
            // Adding ways to get profitable schemes, including this crime.
            totalWays += find(pos + 1, count + group[pos], Math.min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
        }
        
        return memo[pos][count][profit] = totalWays % mod;
    }
    
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        // Initializing all states as -1.
        for (int i = 0; i <= group.length; i++) {
            for(int j = 0; j <= n; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }
        
        return find(0, 0, 0, n, minProfit, group, profit);
    }
}
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101][101];
          
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        // Initializing the base case.
        for (int count = 0; count <= n; count++) {
            dp[group.size()][count][minProfit] = 1;
         }
        
        for (int index = group.size() - 1; index >= 0; index--) {
            for (int count = 0; count <= n; count++) {
                for(int profit = 0; profit <= minProfit; profit++) {
                    // Ways to get a profitable scheme without this crime.
                    dp[index][count][profit] = dp[index + 1][count][profit];
                    if (count + group[index] <= n) {
                        // Adding ways to get profitable schemes, including this crime.
                        dp[index][count][profit] 
                            = (dp[index][count][profit] + dp[index + 1][count + group[index]][min(minProfit, profit + profits[index])]) % mod;
                    }
                }
            }
        }
        
        return dp[0][0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int mod = 1000000007;
    int[][][] dp = new int[101][101][101];

    public int profitableSchemes(int n, int minProfit, int[] group, int[] profits) {
        // Initializing the base case.
        for (int count = 0; count <= n; count++) {
            dp[group.length][count][minProfit] = 1;
        }

        for (int index = group.length - 1; index >= 0; index--) {
            for (int count = 0; count <= n; count++) {
                for(int profit = 0; profit <= minProfit; profit++) {
                    // Ways to get a profitable scheme without this crime.
                    dp[index][count][profit] = dp[index + 1][count][profit];
                    if (count + group[index] <= n) {
                        // Adding ways to get profitable schemes, including this crime.
                        dp[index][count][profit]
                                = (dp[index][count][profit] + dp[index + 1][count + group[index]][Math.min(minProfit, profit + profits[index])]) % mod;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
}
```

</details>
