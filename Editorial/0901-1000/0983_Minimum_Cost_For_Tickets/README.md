# 983. Minimum Cost For Tickets

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-cost-for-tickets/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 983 - Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)

## Problem

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

- a 1-day pass is sold for costs[0] dollars,
- a 7-day pass is sold for costs[1] dollars, and
- a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.

- For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

### Example 1

```text
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
```

### Example 2

```text
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
```

## Constraints

- 1 <= days.length <= 365
- 1 <= days[i] <= 365
- days is in strictly increasing order.
- costs.length == 3
- 1 <= costs[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Coin Change](https://leetcode.com/problems/coin-change/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Most Expensive Item That Can Not Be Bought](https://leetcode.com/problems/most-expensive-item-that-can-not-be-bought/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 983. Minimum Cost For Tickets

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-up Dynamic Programming | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    unordered_set<int> isTravelNeeded;
    
    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int currDay) {
        // If we have iterated over travel days, return 0.
        if (currDay > days[days.size() - 1]) {
            return 0;
        }
        
        // If we don't need to travel on this day, move on to next day.
        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }
        
        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1) {
            return dp[currDay];
        }
        
        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);
        
        // Store the cost with the minimum of the three options.
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);
        
        // Mark the days on which we need to travel.
        for (int day : days) {
            isTravelNeeded.insert(day);
        }
        
        return solve(dp, days, costs, 1);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    HashSet<Integer> isTravelNeeded = new HashSet<>();

    private int solve(int[] dp, int[] days, int[] costs, int currDay) {
        // If we have iterated over travel days, return 0.
        if (currDay > days[days.length - 1]) {
            return 0;
        }

        // If we don't need to travel on this day, move on to next day.
        if (!isTravelNeeded.contains(currDay)) {
            return solve(dp, days, costs, currDay + 1);
        }

        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1) {
            return dp[currDay];
        }

        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);

        // Store the cost with the minimum of the three options.
        return dp[currDay] = Math.min(oneDay, Math.min(sevenDay, thirtyDay));
    }

    public int mincostTickets(int[] days, int[] costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.length - 1];
        int dp[] = new int[lastDay + 1];
        Arrays.fill(dp, -1);

        // Mark the days on which we need to travel.
        for (int day : days) {
            isTravelNeeded.add(day);
        }

        return solve(dp, days, costs, 1);
    }
}
```

</details>

<br>

## Approach 2: Bottom-up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
        
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
     
        return dp[lastDay];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.length - 1];
        int dp[] = new int[lastDay + 1];
        Arrays.fill(dp, 0);

        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            // If we don't need to travel on this day, the cost won't change.
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                // Buy a pass on this day, and move on to the next travel day.
                i++;
                // Store the cost with the minimum of the three options.
                dp[day] = Math.min(dp[day - 1] + costs[0],
                        Math.min(dp[Math.max(0, day - 7)] + costs[1],
                                dp[Math.max(0, day - 30)] + costs[2]));
            }
        }

        return dp[lastDay];
    }
}
```

</details>
