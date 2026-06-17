# 746. Min Cost Climbing Stairs

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/min-cost-climbing-stairs/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 746 - Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

## Problem

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

### Example 1

```text
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

### Example 2

```text
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```

## Constraints

- 2 <= cost.length <= 1000
- 0 <= cost[i] <= 999

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find Number of Ways to Reach the K-th Stair](https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 746. Min Cost Climbing Stairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-Up Dynamic Programming (Tabulation) | Java, Python3 |
| Top-Down Dynamic Programming (Recursion + Memoization) | Java, Python3 |
| Bottom-Up, Constant Space | Java, Python3 |

## Approach 1: Bottom-Up Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        // The array's length should be 1 longer than the length of cost
        // This is because we can treat the "top floor" as a step to reach
        int minimumCost[] = new int[cost.length + 1];
        
        // Start iteration from step 2, since the minimum cost of reaching
        // step 0 and step 1 is 0
        for (int i = 2; i < minimumCost.length; i++) {
            int takeOneStep = minimumCost[i - 1] + cost[i - 1];
            int takeTwoSteps = minimumCost[i - 2] + cost[i - 2];
            minimumCost[i] = Math.min(takeOneStep, takeTwoSteps);
        }
        
        // The final element in minimumCost refers to the top floor
        return minimumCost[minimumCost.length - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # The array's length should be 1 longer than the length of cost
        # This is because we can treat the "top floor" as a step to reach
        minimum_cost = [0] * (len(cost) + 1)
        
        # Start iteration from step 2, since the minimum cost of reaching
        # step 0 and step 1 is 0
        for i in range(2, len(cost) + 1):
            take_one_step = minimum_cost[i - 1] + cost[i - 1]
            take_two_steps = minimum_cost[i - 2] + cost[i - 2]
            minimum_cost[i] = min(take_one_step, take_two_steps)

        # The final element in minimum_cost refers to the top floor
        return minimum_cost[-1]
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Recursion + Memoization)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();

    public int minCostClimbingStairs(int[] cost) {
        return minimumCost(cost.length, cost);
    }

    private int minimumCost(int i, int[] cost) {
        // Base case, we are allowed to start at either step 0 or step 1
        if (i <= 1) {
            return 0;
        }

        // Check if we have already calculated minimumCost(i)
        if (memo.containsKey(i)) {
            return memo.get(i);
        }

        // If not, cache the result in our hash map and return it
        int downOne = cost[i - 1] + minimumCost(i - 1, cost);
        int downTwo = cost[i - 2] + minimumCost(i - 2, cost);
        memo.put(i, Math.min(downOne, downTwo));
        return memo.get(i);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def minimum_cost(i):
            # Base case, we are allowed to start at either step 0 or step 1
            if i <= 1:
                return 0

            # Check if we have already calculated minimum_cost(i)
            if i in memo:
                return memo[i]

            # If not, cache the result in our hash map and return it
            down_one = cost[i - 1] + minimum_cost(i - 1)
            down_two = cost[i - 2] + minimum_cost(i - 2)
            memo[i] = min(down_one, down_two)
            return memo[i]

        memo = {}
        return minimum_cost(len(cost))
```

</details>

<br>

## Approach 3: Bottom-Up, Constant Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int downOne = 0;
        int downTwo = 0;
        for (int i = 2; i < cost.length + 1; i++) {
            int temp = downOne;
            downOne = Math.min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }
        
        return downOne;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:        
        down_one = down_two = 0
        for i in range(2, len(cost) + 1):
            temp = down_one
            down_one = min(down_one + cost[i - 1], down_two + cost[i - 2])
            down_two = temp

        return down_one
```

</details>
