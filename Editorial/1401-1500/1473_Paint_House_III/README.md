# 1473. Paint House III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/paint-house-iii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1473 - Paint House III](https://leetcode.com/problems/paint-house-iii/)

## Problem

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

- For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

Given an array houses, an m x n matrix cost and an integer target where:

- houses[i]: is the color of the house i, and 0 if the house is not painted yet.
- cost[i][j]: is the cost of paint the house i with the color j + 1.

Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

### Example 1

```text
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
```

### Example 2

```text
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}].
Cost of paint the first and last house (10 + 1) = 11.
```

### Example 3

```text
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.
```

## Constraints

- m == houses.length == cost.length
- n == cost[i].length
- 1 <= m <= 100
- 1 <= n <= 20
- 1 <= target <= m
- 0 <= houses[i] <= n
- 1 <= cost[i][j] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Distinct Roll Sequences](https://leetcode.com/problems/number-of-distinct-roll-sequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Paint House IV](https://leetcode.com/problems/paint-house-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1473. Paint House III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming (Space Optimized) | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Assign the size as per maximum value for different params
    int memo[100][100][21];
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;
    
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int targetCount, int currIndex,
                    int neighborhoodCount, int prevHouseColor) {
        if (currIndex == houses.size()) {
            // If all houses are traversed, check if the neighbor count is as expected or not
            return neighborhoodCount == targetCount ? 0 : MAX_COST;
        }
        
        if (neighborhoodCount > targetCount) {
            // If the neighborhoods are more than the threshold, we can't have target neighborhoods
            return MAX_COST;
        }
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][neighborhoodCount][prevHouseColor] != -1) {
            return memo[currIndex][neighborhoodCount][prevHouseColor];
        }
        
        int minCost = MAX_COST;
        // If the house is already painted, update the values accordingly
        if (houses[currIndex]) {
            int newNeighborhoodCount = neighborhoodCount + (houses[currIndex] != prevHouseColor);
            minCost = 
                findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, houses[currIndex]);
        } else {
            int totalColors = cost[0].size();
            
            // If the house is not painted, try every possible color and store the minimum cost
            for (int color = 1; color <= totalColors; color++) {
                int newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor);
                int currCost = cost[currIndex][color - 1]
                    + findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, color);
                minCost = min(minCost, currCost);
            }
        }
        
        // Return the minimum cost and also storing it for future reference (memoization)
        return memo[currIndex][neighborhoodCount][prevHouseColor] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Marking all values to -1 to denote that we don't have the answer ready for these params yet
        memset(memo, -1, sizeof(memo));
        int answer = findMinCost(houses, cost, target, 0, 0, 0);
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return answer == MAX_COST ? -1 : answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Assign the size as per maximum value for different params
    Integer[][][] memo = new Integer[100][100][21];
    // Maximum cost possible plus 1
    final int MAX_COST = 1000001;
    
    int findMinCost(int[] houses, int[][] cost, int targetCount, int currIndex,
                    int neighborhoodCount, int prevHouseColor) {
        if (currIndex == houses.length) {
            // If all houses are traversed, check if the neighbor count is as expected or not
            return neighborhoodCount == targetCount ? 0 : MAX_COST;
        }
        
        if (neighborhoodCount > targetCount) {
            // If the neighborhoods are more than the threshold, we can't have target neighborhoods
            return MAX_COST;
        }
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][neighborhoodCount][prevHouseColor] != null) {
            return memo[currIndex][neighborhoodCount][prevHouseColor];
        }
        
        int minCost = MAX_COST;
        // If the house is already painted, update the values accordingly
        if (houses[currIndex] != 0) {
            int newNeighborhoodCount = neighborhoodCount + (houses[currIndex] != prevHouseColor ? 1 : 0);
            minCost = 
                findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, houses[currIndex]);
        } else {
            int totalColors = cost[0].length;
            
            // If the house is not painted, try every possible color and store the minimum cost
            for (int color = 1; color <= totalColors; color++) {
                int newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor ? 1 : 0);
                int currCost = cost[currIndex][color - 1] 
                    + findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, color);
                minCost = Math.min(minCost, currCost);
            }
        }
        
        // Return the minimum cost and also storing it for future reference (memoization)
        return memo[currIndex][neighborhoodCount][prevHouseColor] = minCost;
    }
    
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int answer = findMinCost(houses, cost, target, 0, 0, 0);
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return answer == MAX_COST ? -1 : answer;
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
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Initialize memo array
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));
            
        // Initialize for house 0, neighborhoods will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                memo[0][1][color - 1] = 0;
            } else if (!houses[0]) {
                // If the house is not painted, assign the corresponding cost
                memo[0][1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = min(currCost, memo[house - 1][neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = min(currCost, memo[house - 1][neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, memo[m - 1][target][color - 1]);
        }
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum cost possible plus 1
    final int MAX_COST = 1000001;
    
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][][] memo = new int[m][target + 1][n];
      
        // Initialize memo array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= target; j++) {
                Arrays.fill(memo[i][j], MAX_COST);
            }
        }
            
        // Initialize for house 0, neighborhoods will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                memo[0][1][color - 1] = 0;
            } else if (houses[0] == 0) {
                // If the house is not painted, assign the corresponding cost
                memo[0][1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            for (int neighborhoods = 1; neighborhoods <= Math.min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] != 0 && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = Math.min(currCost, memo[house - 1][neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = Math.min(currCost, memo[house - 1][neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted, cost to paint is 0
                    int costToPaint = houses[house] != 0 ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = Math.min(minCost, memo[m - 1][target][color - 1]);
        }
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
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
    // Maximum cost possible plus 1
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Initialize prevMemo array
        vector<vector<int>> prevMemo(target + 1, vector<int>(n, MAX_COST));
       
        // Initialize for house 0, neighborhood will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                prevMemo[1][color - 1] = 0;
            } else if (!houses[0]) {
                // If the house is not painted, assign the corresponding cost
                prevMemo[1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            // Initialize memo array
            vector<vector<int>> memo(target + 1, vector<int>(n, MAX_COST));
            
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = min(currCost, prevMemo[neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = min(currCost, prevMemo[neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
            // Update the table to have the current house results
            prevMemo = memo;
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, prevMemo[target][color - 1]);
        }
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum cost possible plus 1
    final int MAX_COST = 1000001;
    
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][] prevMemo = new int[target + 1][n];
      
        // Initialize prevMemo array
        for (int i = 0; i <= target; i++) {
            Arrays.fill(prevMemo[i], MAX_COST);
        }
            
        // Initialize for house 0, neighborhood will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                prevMemo[1][color - 1] = 0;
            } else if (houses[0] == 0) {
                // If the house is not painted, assign the corresponding cost
                prevMemo[1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            int[][] memo = new int[target + 1][n];
      
            // Initialize memo array
            for (int i = 0; i <= target; i++) {
                Arrays.fill(memo[i], MAX_COST);
            }
            
            for (int neighborhoods = 1; neighborhoods <= Math.min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    
                    // If the house is already painted, and color is different
                    if (houses[house] != 0 && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = Math.min(currCost, prevMemo[neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = Math.min(currCost, prevMemo[neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] != 0 ? 0 : cost[house][color - 1];
                    memo[neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
            // Update the table to have the current house results
            prevMemo = memo;
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = Math.min(minCost, prevMemo[target][color - 1]);
        }
        
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
    }
}
```

</details>
