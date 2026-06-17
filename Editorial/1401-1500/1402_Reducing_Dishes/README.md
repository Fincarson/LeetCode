# 1402. Reducing Dishes

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/reducing-dishes/)  
`Array` `Dynamic Programming` `Greedy` `Sorting`

**Problem Link:** [LeetCode 1402 - Reducing Dishes](https://leetcode.com/problems/reducing-dishes/)

## Problem

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

### Example 1

```text
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
```

### Example 2

```text
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
```

### Example 3

```text
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
```

## Constraints

- n == satisfaction.length
- 1 <= n <= 500
- -1000 <= satisfaction[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1402. Reducing Dishes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming (Space Optimized) | C++, Java |
| Greedy | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxSatisfaction(vector<int>& satisfaction, vector<vector<int>>& memo, int index, int time) {
        // Return 0 if we have iterated over all the dishes.
        if (index == satisfaction.size()) {
            return 0;
        }
        
        // We have already calculated the answer, so no need to go into recursion.
        if (memo[index][time] != -1) {
            return memo[index][time];
        }
        
        // Return the maximum of two choices:
        // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
        // 2. Skip the current dish and move on to the next dish at the same time.
        return memo[index][time] = max(satisfaction[index] * time + findMaxSatisfaction(satisfaction, memo, index + 1, time + 1), 
                                       findMaxSatisfaction(satisfaction, memo, index + 1, time));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        // Mark, all the states as -1, denoting not yet calculated.
        vector<vector<int>> memo(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        
        return findMaxSatisfaction(satisfaction, memo, 0, 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int findMaxSatisfaction(int[] satisfaction, int[][] memo, int index, int time) {
        // Return 0 if we have iterated over all the dishes.
        if (index == satisfaction.length) {
            return 0;
        }

        // We have already calculated the answer, so no need to go into recursion.
        if (memo[index][time] != -1) {
            return memo[index][time];
        }

        // Return the maximum of two choices:
        // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
        // 2. Skip the current dish and move on to the next dish at the same time.
        return memo[index][time] = Math.max(satisfaction[index] * time + findMaxSatisfaction(satisfaction, memo, index + 1, time + 1),
                findMaxSatisfaction(satisfaction, memo, index + 1, time));
    }

    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);

        int[][] memo = new int[satisfaction.length + 1][satisfaction.length + 1];
        // Mark, all the states as -1, denoting not yet calculated.
        for (int i = 0; i < satisfaction.length; i++) {
            Arrays.fill(memo[i], -1);
        }

        return findMaxSatisfaction(satisfaction, memo, 0, 1);
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
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        // Mark all the states initially as 0.
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 2, 0));
        for (int index = satisfaction.size() - 1; index >= 0; index--) {
            for (int time = 1; time <= satisfaction.size(); time++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move on to the next dish at the same time.
                dp[index][time] = max(satisfaction[index] * time + dp[index + 1][time + 1], dp[index + 1][time]);
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
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        
        int[][] dp = new int[satisfaction.length + 1][satisfaction.length + 2];
        // Mark all the states initially as 0.
        for (int i = 0; i <= satisfaction.length; i++) {
            Arrays.fill(dp[i], 0);
        }
        
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            for (int j = 1; j <= satisfaction.length; j++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move on to the next dish at the same time.
                dp[i][j] = Math.max(satisfaction[i] * j + dp[i + 1][j + 1], dp[i + 1][j]);
            }
        }
        
        return dp[0][1];
    }
}
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming (Space Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        // Array to keep the result for the previous iteration.
        vector<int> prev(satisfaction.size() + 2, 0);
        for (int index = satisfaction.size() - 1; index >= 0; index--) {
            // Array to keep the result for the current iteration.
            vector<int> dp(satisfaction.size() + 2);
            
            for (int time = 1; time <= satisfaction.size(); time++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move on to the next dish at the same time.
                dp[time] = max(satisfaction[index] * time + prev[time + 1], prev[time]);
            }
            // Assign the current iteration result to prev to be used in the next iteration.
            prev = dp;
        }
        // dp and prev have the same value here, but dp is not defined at this scope.
        return prev[1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        
        // Array to keep the result for the previous iteration.
        int[] prev = new int[satisfaction.length + 2];
        Arrays.fill(prev, 0);
        
        for (int index = satisfaction.length - 1; index >= 0; index--) {
            // Array to keep the result for the current iteration.
            int[] dp = new int[satisfaction.length + 2];
            
            for (int time = 1; time <= satisfaction.length; time++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move on to the next dish at the same time.
                dp[time] = Math.max(satisfaction[index] * time + prev[time + 1], prev[time]);
            }
            // Assign the current iteration result to prev to be used in the next iteration.
            prev = dp;
        }
        // dp and prev have the same value here, but dp is not defined at this scope.
        return prev[1];
    }
}
```

</details>

<br>

## Approach 4: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int maxSatisfaction = 0;
        int suffixSum = 0;
        for (int i = satisfaction.size() - 1; i >= 0 && suffixSum + satisfaction[i] > 0; i--) {
            // Total satisfaction with all dishes so far.
            suffixSum += satisfaction[i];
            // Adding one instance of previous dishes as we add one more dish on the left.
            maxSatisfaction += suffixSum;
        }
        
        return maxSatisfaction;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);

        int maxSatisfaction = 0;
        int suffixSum = 0;
        for (int i = satisfaction.length - 1; i >= 0 && suffixSum + satisfaction[i] > 0; i--) {
            // Total satisfaction with all dishes so far.
            suffixSum += satisfaction[i];
            // Adding one instance of previous dishes as we add one more dish on the left.
            maxSatisfaction +=  suffixSum;
        }
        return maxSatisfaction;
    }
}
```

</details>
