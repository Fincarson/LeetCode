# 2361. Minimum Costs Using the Train Line

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-costs-using-the-train-line/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 2361 - Minimum Costs Using the Train Line](https://leetcode.com/problems/minimum-costs-using-the-train-line/)

## Problem

A train line going through a city has two routes, the regular route and the express route. Both routes go through the same n + 1 stops labeled from 0 to n. Initially, you start on the regular route at stop 0.

You are given two 1-indexed integer arrays regular and express, both of length n. regular[i] describes the cost it takes to go from stop i - 1 to stop i using the regular route, and express[i] describes the cost it takes to go from stop i - 1 to stop i using the express route.

You are also given an integer expressCost which represents the cost to transfer from the regular route to the express route.

Note that:

- There is no cost to transfer from the express route back to the regular route.
- You pay expressCost every time you transfer from the regular route to the express route.
- There is no extra cost to stay on the express route.

Return a 1-indexed array costs of length n, where costs[i] is the minimum cost to reach stop i from stop 0.

Note that a stop can be counted as reached from either route.

### Example 1

```text
Input: regular = [1,6,9,5], express = [5,2,3,10], expressCost = 8
Output: [1,7,14,19]
Explanation: The diagram above shows how to reach stop 4 from stop 0 with minimum cost.
- Take the regular route from stop 0 to stop 1, costing 1.
- Take the express route from stop 1 to stop 2, costing 8 + 2 = 10.
- Take the express route from stop 2 to stop 3, costing 3.
- Take the regular route from stop 3 to stop 4, costing 5.
The total cost is 1 + 10 + 3 + 5 = 19.
Note that a different route could be taken to reach the other stops with minimum cost.
```

### Example 2

```text
Input: regular = [11,5,13], express = [7,10,6], expressCost = 3
Output: [10,15,24]
Explanation: The diagram above shows how to reach stop 3 from stop 0 with minimum cost.
- Take the express route from stop 0 to stop 1, costing 3 + 7 = 10.
- Take the regular route from stop 1 to stop 2, costing 5.
- Take the express route from stop 2 to stop 3, costing 3 + 6 = 9.
The total cost is 10 + 5 + 9 = 24.
Note that the expressCost is paid again to transfer back to the express route.
```

## Constraints

- n == regular.length == express.length
- 1 <= n <= 105
- 1 <= regular[i], express[i], expressCost <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bus Routes](https://leetcode.com/problems/bus-routes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Distance Between Bus Stops](https://leetcode.com/problems/distance-between-bus-stops/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2361. Minimum Costs Using the Train Line

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |
| Space-Optimized Bottom-Up Dynamic Programming | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long solve(int i, int lane, long dp[][2], vector<int>& regular, vector<int>& express, int expressCost) {
        // If all stops are covered, return 0.
        if (i < 0) {
            return 0;
        }
        
        if (dp[i][lane] != -1) {
            return dp[i][lane];
        }
        
        // Use the regular lane; no extra cost to switch lanes if required.
        long regularLane = regular[i] + solve(i - 1, 1, dp, regular, express, expressCost);
        // Use express lane; add expressCost if the previously regular lane was used.
        long expressLane = (lane ? expressCost : 0) + express[i] 
                                                    + solve(i - 1, 0, dp, regular, express, expressCost);

        return dp[i][lane] = min(regularLane, expressLane);
    }
    
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        long dp[regular.size()][2];
        memset(dp, -1, sizeof(dp));
        
        solve(regular.size() - 1, 1, dp, regular, express, expressCost);
        
        // Store cost for each stop.
        vector<long long> ans;
        for (int i = 0 ; i < regular.size(); i++) {
            ans.push_back(dp[i][1]);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    long solve(int i, int lane, long[][] dp, int[] regular, int[] express, int expressCost) {
        // If all stops are covered, return 0.
        if (i < 0) {
            return 0;
        }
        
        if (dp[i][lane] != -1) {
            return dp[i][lane];
        }
        
        // Use the regular lane; no extra cost to switch lanes if required.
        long regularLane = regular[i] + solve(i - 1, 1, dp, regular, express, expressCost);
        // Use express lane; add expressCost if the previously regular lane was used.
        long expressLane = (lane == 1 ? expressCost : 0) + express[i] 
                                                    + solve(i - 1, 0, dp, regular, express, expressCost);

        return dp[i][lane] = Math.min(regularLane, expressLane);
    }
    
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        long[][] dp = new long[regular.length][2];
        for (int i = 0; i < regular.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        solve(regular.length - 1, 1, dp, regular, express, expressCost);
        
        long[] ans = new long[regular.length];
        // Store cost for each stop.
        for (int i = 0 ; i < regular.length; i++) {
            ans[i] = dp[i][1];
        }
        
        return ans;
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
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int N = regular.size() + 1;
        vector<long long> ans;
        
        long dp[N][2];
        dp[0][1] = 0;
        // Need to spend expressCost, as we start from the regular lane initially.
        dp[0][0] = expressCost;
        
        for (int i = 1; i < N; i++) {
            // Use the regular lane; no extra cost to switch to the express lane.
            dp[i][1] = regular[i - 1] + min(dp[i - 1][1], dp[i - 1][0]);
            // Use express lane; add extra cost if the previously regular lane was used.
            dp[i][0] = express[i - 1] + min(expressCost + dp[i - 1][1], dp[i - 1][0]);
            
            ans.push_back(min(dp[i][0], dp[i][1]));
        }
        return ans; 
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
        long[] ans = new long[regular.length];
        
        long[][] dp = new long[regular.length + 1][2];
        dp[0][1] = 0;
        // Need to spend expressCost, as we start from the regular lane initially.
        dp[0][0] = expressCost;
        
        for (int i = 1; i < regular.length + 1; i++) {
            // Use the regular lane; no extra cost to switch to the express lane.
            dp[i][1] = regular[i - 1] + Math.min(dp[i - 1][1], dp[i - 1][0]);
            // Use express lane; add extra cost if the previously regular lane was used.
            dp[i][0] = express[i - 1] + Math.min(expressCost + dp[i - 1][1], dp[i - 1][0]);
            
            ans[i - 1] = Math.min(dp[i][0], dp[i][1]);
        }
        return ans; 
    }
}
```

</details>

<br>

## Approach 3: Space-Optimized Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int N = regular.size() + 1;
        
        long prevRegularLane = 0;
        // Need to spend expressCost, as we start from the regular lane initially.
        long prevExpressLane = expressCost;
        
        vector<long long> ans;
        for (int i = 1; i < N; i++) {
            // Use the regular lane; no extra cost to switch to the express lane.
            long regularLaneCost = regular[i - 1] + min(prevRegularLane, prevExpressLane);
            // Use express lane; add extra cost if the previously regular lane was used.
            long expressLaneCost = express[i - 1] + min(expressCost + prevRegularLane, prevExpressLane);
            
            ans.push_back(min(regularLaneCost, expressLaneCost));
            
            prevRegularLane = regularLaneCost;
            prevExpressLane = expressLaneCost;
        }
        
        return ans; 
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long[] minimumCosts(int[] regular, int[] express, int expressCost) {

        long prevRegularLane = 0;
        // Need to spend expressCost, as we start from the regular lane initially.
        long prevExpressLane = expressCost;

        long[] ans = new long[regular.length];
        for (int i = 1; i < regular.length + 1; i++) {
            // Use the regular lane; no extra cost to switch to the express lane.
            long regularLaneCost = regular[i - 1] + Math.min(prevRegularLane, prevExpressLane);
            // Use express lane; add extra cost if the previously regular lane was used.
            long expressLaneCost = express[i - 1] + Math.min(expressCost + prevRegularLane, prevExpressLane);

            ans[i - 1] = Math.min(regularLaneCost, expressLaneCost);

            prevRegularLane = regularLaneCost;
            prevExpressLane = expressLaneCost;
        }

        return ans;

    }
}
```

</details>
