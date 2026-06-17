# 568. Maximum Vacation Days

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/maximum-vacation-days/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 568 - Maximum Vacation Days](https://leetcode.com/problems/maximum-vacation-days/)

## Problem

LeetCode wants to give one of its best employees the option to travel among n cities to collect algorithm problems. But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions you need to follow.

Rules and restrictions:

Given the two matrices flights and days, return the maximum vacation days you could take during k weeks.

### Example 1

```text
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
Output: 12
Explanation:
One of the best strategies is:
1st week : fly from city 0 to city 1 on Monday, and play 6 days and work 1 day.
(Although you start at city 0, we could also fly to and start at other cities since it is Monday.)
2nd week : fly from city 1 to city 2 on Monday, and play 3 days and work 4 days.
3rd week : stay at city 2, and play 3 days and work 4 days.
Ans = 6 + 3 + 3 = 12.
```

### Example 2

```text
Input: flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
Output: 3
Explanation:
Since there are no flights that enable you to move to another city, you have to stay at city 0 for the whole 3 weeks.
For each week, you only have one day to play and six days to work.
So the maximum number of vacation days is 3.
Ans = 1 + 1 + 1 = 3.
```

### Example 3

```text
Input: flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
Output: 21
Explanation:
One of the best strategies is:
1st week : stay at city 0, and play 7 days.
2nd week : fly from city 0 to city 1 on Monday, and play 7 days.
3rd week : fly from city 1 to city 2 on Monday, and play 7 days.
Ans = 7 + 7 + 7 = 21
```

## Constraints

- n == flights.length
- n == flights[i].length
- n == days.length
- k == days[i].length
- 1 <= n, k <= 100
- flights[i][j] is either 0 or 1.
- 0 <= days[i][j] <= 7

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 568. Maximum Vacation Days

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using Depth First Search [Time Limit Exceeded] | Java |
| Approach #2 Using DFS with memoization [Accepted]: | Java |
| Approach #3 Using 2-D Dynamic Programming [Accepted]: | Java |
| Approach #4 Using 1-D Dynamic Programming [Accepted]: | Java |

## Approach #1 Using Depth First Search [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        return dfs(flights, days, 0, 0);
    }
    public int dfs(int[][] flights, int[][] days, int cur_city, int weekno) {
        if (weekno == days[0].length)
            return 0;
        int maxvac = 0;
        for (int i = 0; i < flights.length; i++) {
            if (flights[cur_city][i] == 1 || i == cur_city) {
                int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1);
                maxvac = Math.max(maxvac, vac);
            }
        }
        return maxvac;
    }
}
```

</details>

<br>

## Approach #2 Using DFS with memoization [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int[][] memo = new int[flights.length][days[0].length];
        for (int[] l: memo)
            Arrays.fill(l, Integer.MIN_VALUE);
        return dfs(flights, days, 0, 0, memo);
    }
    public int dfs(int[][] flights, int[][] days, int cur_city, int weekno, int[][] memo) {
        if (weekno == days[0].length)
            return 0;
        if (memo[cur_city][weekno] != Integer.MIN_VALUE)
            return memo[cur_city][weekno];
        int maxvac = 0;
        for (int i = 0; i < flights.length; i++) {
            if (flights[cur_city][i] == 1 || i == cur_city) {
                int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1, memo);
                maxvac = Math.max(maxvac, vac);
            }
        }
        memo[cur_city][weekno] = maxvac;
        return maxvac;
    }
}
```

</details>

<br>

## Approach #3 Using 2-D Dynamic Programming [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        if (days.length == 0 || flights.length == 0) return 0;
        int[][] dp = new int[days.length][days[0].length + 1];
        for (int week = days[0].length - 1; week >= 0; week--) {
            for (int cur_city = 0; cur_city < days.length; cur_city++) {
                dp[cur_city][week] = days[cur_city][week] + dp[cur_city][week + 1];
                for (int dest_city = 0; dest_city < days.length; dest_city++) {
                    if (flights[cur_city][dest_city] == 1) {
                        dp[cur_city][week] = Math.max(days[dest_city][week] + dp[dest_city][week + 1], dp[cur_city][week]);
                    }
                }
            }
        }
        return dp[0][0];
    }
}
```

</details>

<br>

## Approach #4 Using 1-D Dynamic Programming [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        if (days.length == 0 || flights.length == 0) return 0;
        int[] dp = new int[days.length];
        for (int week = days[0].length - 1; week >= 0; week--) {
            int[] temp = new int[days.length];
            for (int cur_city = 0; cur_city < days.length; cur_city++) {
                temp[cur_city] = days[cur_city][week] + dp[cur_city];
                for (int dest_city = 0; dest_city < days.length; dest_city++) {
                    if (flights[cur_city][dest_city] == 1) {
                        temp[cur_city] = Math.max(days[dest_city][week] + dp[dest_city], temp[cur_city]);
                    }
                }
            }
            dp = temp;
        }

        return dp[0];
    }
}
```

</details>
