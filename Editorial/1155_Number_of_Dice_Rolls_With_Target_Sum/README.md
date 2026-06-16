# 1155. Number of Dice Rolls With Target Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 1155 - Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

## Problem

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
```

### Example 2

```text
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```

### Example 3

```text
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
```

## Constraints

- 1 <= n, k <= 30
- 1 <= target <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Equal Sum Arrays With Minimum Number of Operations](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Missing Observations](https://leetcode.com/problems/find-missing-observations/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1155. Number of Dice Rolls With Target Sum

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
    const int MOD = 1e9 + 7;
    
    int waysToTarget(vector<vector<int>>& memo, int diceIndex, int n, int currSum, int target, int k) {
        // All the n dice are traversed, the sum must be equal to target for valid combination
        if (diceIndex == n) {
            return currSum == target;
        }

        // We have already calculated the answer so no need to go into recursion
        if (memo[diceIndex][currSum] != -1) {
            return memo[diceIndex][currSum];
        }
		
        int ways = 0;
        // Iterate over the possible face value for current dice
        for (int i = 1; i <= min(k, target - currSum); i++) {
            ways = (ways + waysToTarget(memo, diceIndex + 1, n, currSum + i, target, k)) % MOD;
        }
        return memo[diceIndex][currSum] = ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return waysToTarget(memo, 0, n, 0, target, k);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    final int MOD = 1000000007;
    
    int waysToTarget(Integer[][] memo, int diceIndex, int n, int currSum, int target, int k) {
        // All the n dice are traversed, the sum must be equal to target for valid combination
        if (diceIndex == n) {
            return currSum == target ? 1 : 0;
        }
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[diceIndex][currSum] != null) {
            return memo[diceIndex][currSum];
        }
        
        int ways = 0;
        // Iterate over the possible face value for current dice
        for (int i = 1; i <= Math.min(k, target - currSum); i++) {
            ways = (ways + waysToTarget(memo, diceIndex + 1, n, currSum + i, target, k)) % MOD;
        }
        return memo[diceIndex][currSum] = ways;
    }
    
    public int numRollsToTarget(int n, int k, int target) {
        Integer[][] memo = new Integer[n + 1][target + 1];
        return waysToTarget(memo, 0, n, 0, target, k);
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
    const int MOD = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, 0));
        // Intialize the base case
        memo[n][target] = 1;
        
        for (int diceIndex = n - 1; diceIndex >= 0; diceIndex--) {
            for (int currSum = 0; currSum <= target; currSum++) {
               int ways = 0;
                
                // Iterate over the possible face value for current dice
                for (int i = 1; i <= min(k, target - currSum); i++) {
                    ways = (ways + memo[diceIndex + 1][currSum + i]) % MOD;
                }
                
                memo[diceIndex][currSum] = ways;
            }
        }
        
        return memo[0][0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    final int MOD = 1000000007;
    
    public int numRollsToTarget(int n, int k, int target) {
        int[][] memo = new int[n + 1][target + 1];
        // Intialize the base case
        memo[n][target] = 1;
        
        for (int diceIndex = n - 1; diceIndex >= 0; diceIndex--) {
            for (int currSum = 0; currSum <= target; currSum++) {
               int ways = 0;
                
                // Iterate over the possible face value for current dice
                for (int i = 1; i <= Math.min(k, target - currSum); i++) {
                    ways = (ways + memo[diceIndex + 1][currSum + i]) % MOD;
                }
                
                memo[diceIndex][currSum] = ways;
            }
        }
        
        return memo[0][0];
    }
}
```

</details>
