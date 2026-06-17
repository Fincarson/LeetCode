# 2742. Painting the Walls

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/painting-the-walls/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 2742 - Painting the Walls](https://leetcode.com/problems/painting-the-walls/)

## Problem

You are given two 0-indexed integer arrays, cost and time, of size n representing the costs and the time taken to paint n different walls respectively. There are two painters available:

- A paid painter that paints the ith wall in time[i] units of time and takes cost[i] units of money.
- A free painter that paints any wall in 1 unit of time at a cost of 0. But the free painter can only be used if the paid painter is already occupied.

Return the minimum amount of money required to paint the n walls.

### Example 1

```text
Input: cost = [1,2,3,2], time = [1,2,3,2]
Output: 3
Explanation: The walls at index 0 and 1 will be painted by the paid painter, and it will take 3 units of time; meanwhile, the free painter will paint the walls at index 2 and 3, free of cost in 2 units of time. Thus, the total cost is 1 + 2 = 3.
```

### Example 2

```text
Input: cost = [2,3,4,2], time = [1,1,1,1]
Output: 4
Explanation: The walls at index 0 and 3 will be painted by the paid painter, and it will take 2 units of time; meanwhile, the free painter will paint the walls at index 1 and 2, free of cost in 2 units of time. Thus, the total cost is 2 + 2 = 4.
```

## Constraints

- 1 <= cost.length <= 500
- cost.length == time.length
- 1 <= cost[i] <= 106
- 1 <= time[i] <= 500

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2742. Painting the Walls

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memo = vector(n, vector(n + 1, -1));
        return dp(0, n, cost, time);
    }
    
    int dp(int i, int remain, vector<int>& cost, vector<int>& time) { 
        if (remain <= 0) {
            return 0;
        }
        
        if (i == n) {
            return 1e9;
        }
        
        if (memo[i][remain] != -1) {
            return memo[i][remain];
        }
        
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], cost, time);
        int dontPaint = dp(i + 1, remain, cost, time);
        memo[i][remain] = min(paint, dontPaint);
        return memo[i][remain];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    int n;
    
    public int paintWalls(int[] cost, int[] time) {
        n = cost.length;
        memo = new int[n][n + 1];
        return dp(0, n, cost, time);
    }
    
    public int dp(int i, int remain, int[] cost, int[] time) {
        if (remain <= 0) {
            return 0;
        }
        
        if (i == n) {
            return (int) 1e9;
        }
        
        if (memo[i][remain] != 0) {
            return memo[i][remain];
        }
        
        int paint = cost[i] + dp(i + 1, remain - 1 - time[i], cost, time);
        int dontPaint = dp(i + 1, remain, cost, time);
        memo[i][remain] = Math.min(paint, dontPaint);
        return memo[i][remain];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        @cache
        def dp(i, remain):
            if remain <= 0:
                return 0
            if i == n:
                return inf
            
            paint = cost[i] + dp(i + 1, remain - 1 - time[i])
            dont_paint = dp(i + 1, remain)
            return min(paint, dont_paint)
    
        n = len(cost)
        return dp(0, n)
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
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            dp[n][i] = 1e9;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])];
                int dontPaint = dp[i + 1][remain];
                dp[i][remain] = min(paint, dontPaint);
            }
        }
        
        return dp[0][n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int paintWalls(int[] cost, int[] time) {
        int n = cost.length;
        int[][] dp = new int[n + 1][n + 1];
        
        for (int i = 1; i <= n; i++) {
            dp[n][i] = (int) 1e9;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + dp[i + 1][Math.max(0, remain - 1 - time[i])];
                int dontPaint = dp[i + 1][remain];
                dp[i][remain] = Math.min(paint, dontPaint);
            }
        }
        
        return dp[0][n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            dp[n][i] = inf

        for i in range(n - 1, -1, -1):
            for remain in range(1, n + 1):
                paint = cost[i] + dp[i + 1][max(0, remain - 1 - time[i])]
                dont_paint = dp[i + 1][remain]
                dp[i][remain] = min(paint, dont_paint)
        
        return dp[0][n]
```

</details>

<br>

## Approach 3: Space-Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp = vector(n + 1, 0);
        vector<int> prevDp = vector(n + 1, (int) 1e9);
        prevDp[0] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            dp = vector(n + 1, 0);
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + prevDp[max(0, remain - 1 - time[i])];
                int dontPaint = prevDp[remain];
                dp[remain] = min(paint, dontPaint);
            }
            
            prevDp = dp;
        }
        
        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int paintWalls(int[] cost, int[] time) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        int[] prevDp = new int[n + 1];
        Arrays.fill(prevDp, (int) 1e9);
        prevDp[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            dp = new int[n + 1];
            for (int remain = 1; remain <= n; remain++) {
                int paint = cost[i] + prevDp[Math.max(0, remain - 1 - time[i])];
                int dontPaint = prevDp[remain];
                dp[remain] = Math.min(paint, dontPaint);
            }
            
            prevDp = dp;
        }
        
        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n + 1)
        prev_dp = [inf] * (n + 1)
        prev_dp[0] = 0

        for i in range(n - 1, -1, -1):
            dp = [0] * (n + 1)
            for remain in range(1, n + 1):
                paint = cost[i] + prev_dp[max(0, remain - 1 - time[i])]
                dont_paint = prev_dp[remain]
                dp[remain] = min(paint, dont_paint)

            prev_dp = dp
        
        return dp[n]
```

</details>
