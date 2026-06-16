# 1066. Campus Bikes II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/campus-bikes-ii/)  
`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

**Problem Link:** [LeetCode 1066 - Campus Bikes II](https://leetcode.com/problems/campus-bikes-ii/)

## Problem

On a campus represented as a 2D grid, there are n workers and m bikes, with n <= m. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the Manhattan distances between each worker and their assigned bike is minimized.

Return the minimum possible sum of Manhattan distances between each worker and their assigned bike.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.

### Example 1

```text
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation:
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.
```

### Example 2

```text
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation:
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.
```

### Example 3

```text
Input: workers = [[0,0],[1,0],[2,0],[3,0],[4,0]], bikes = [[0,999],[1,999],[2,999],[3,999],[4,999]]
Output: 4995
```

## Constraints

- n == workers.length
- m == bikes.length
- 1 <= n <= m <= 10
- workers[i].length == 2
- bikes[i].length == 2
- 0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
- All the workers and the bikes locations are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Campus Bikes](https://leetcode.com/problems/campus-bikes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1066. Campus Bikes II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy Backtracking | C++, Java |
| Top-Down Dynamic Programming + BitMasking | C++, Java |
| Bottom-Up Dynamic Programming + BitMasking | C++, Java |
| Priority Queue (Similar to Dijkstra's Algorithm) | C++, Java |

## Approach 1: Greedy Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Maximum number of bikes is 10
    int smallestDistanceSum = INT_MAX;
    int visited[10];
    
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    void minimumDistanceSum(vector<vector<int>>& workers, int workerIndex, 
                            vector<vector<int>>& bikes, int currDistanceSum) {
        if (workerIndex >= workers.size()) {
            smallestDistanceSum = min(smallestDistanceSum, currDistanceSum);
            return;
        }
        // If the current distance sum is greater than the smallest result 
        // found then stop exploring this combination of workers and bikes
        if (currDistanceSum >= smallestDistanceSum) {
            return;
        }
        
        for (int bikeIndex = 0; bikeIndex < bikes.size(); bikeIndex++) {
            // If bike is available
            if (!visited[bikeIndex]) {
                visited[bikeIndex] = true;
                minimumDistanceSum(workers, workerIndex + 1, bikes, 
                    currDistanceSum + findDistance(workers[workerIndex], bikes[bikeIndex]));
                visited[bikeIndex] = false;
            }
        }
        
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        minimumDistanceSum(workers, 0, bikes, 0);
        return smallestDistanceSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum number of bikes is 10
    boolean visited [] = new boolean[10];
    int smallestDistanceSum = Integer.MAX_VALUE;
    
    // Manhattan distance
    private int findDistance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
    
    private void minimumDistanceSum(int[][] workers, int workerIndex, int[][] bikes, int currDistanceSum) {
        if (workerIndex >= workers.length) {
            smallestDistanceSum = Math.min(smallestDistanceSum, currDistanceSum);
            return;
        }
        // If the current distance sum is greater than the smallest result 
        // found then stop exploring this combination of workers and bikes
        if (currDistanceSum >= smallestDistanceSum) {
            return;
        }
        for (int bikeIndex = 0; bikeIndex < bikes.length; bikeIndex++) {
            // If bike is available
            if (!visited[bikeIndex]) {
                visited[bikeIndex] = true;
                minimumDistanceSum(workers, workerIndex + 1, bikes, 
                    currDistanceSum + findDistance(workers[workerIndex], bikes[bikeIndex]));
                visited[bikeIndex] = false;
            }
        }
    }
    
    public int assignBikes(int[][] workers, int[][] bikes) {
        minimumDistanceSum(workers, 0, bikes, 0);
        return smallestDistanceSum;
    } 
}
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming + BitMasking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Maximum value of mask will be 2^(Number of bikes)
    // and number of bikes can be 10 at max
    int memo[1024];
    
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int minimumDistanceSum(vector<vector<int>>& workers, vector<vector<int>>& bikes, int workerIndex, int mask) {
        if (workerIndex >= workers.size()) {
            return 0;
        }
        
        // If result is already calculated, return it no recursion needed
        if (memo[mask] != -1)
            return memo[mask];
        
        int smallestDistanceSum = INT_MAX;
        for (int bikeIndex = 0; bikeIndex < bikes.size(); bikeIndex++) {
            // Check if the bike at bikeIndex is available
            if ((mask & (1 << bikeIndex)) == 0) {
                // Adding the current distance and repeat the process for next worker
                // also changing the bit at index bikeIndex to 1 to show the bike there is assigned
                smallestDistanceSum = min(smallestDistanceSum, 
                             findDistance(workers[workerIndex], bikes[bikeIndex]) + 
                                          minimumDistanceSum(workers, bikes, workerIndex + 1, 
                                                             mask | (1 << bikeIndex)));
            }
        }
        
        // Memoizing the result corresponding to mask
        return memo[mask] = smallestDistanceSum;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) { 
        // Marking all positions to -1 that signifies result 
        // has not been calculated yet for this mask
        memset(memo, -1, sizeof(memo));
        return minimumDistanceSum(workers, bikes, 0, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum value of mask will be 2^(Number of bikes)
    // and number of bikes can be 10 at max
    int memo [] = new int[1024];
    
    // Manhattan distance
    private int findDistance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
    
    private int minimumDistanceSum(int[][] workers, int[][] bikes, int workerIndex, int mask) {
        if (workerIndex >= workers.length) {
            return 0;
        }
        
        // If result is already calculated, return it no recursion needed
        if (memo[mask] != -1)
            return memo[mask];
        
        int smallestDistanceSum = Integer.MAX_VALUE;
        for (int bikeIndex = 0; bikeIndex < bikes.length; bikeIndex++) {
            // Check if the bike at bikeIndex is available
            if ((mask & (1 << bikeIndex)) == 0) {
                // Adding the current distance and repeat the process for next worker
                // also changing the bit at index bikeIndex to 1 to show the bike there is assigned
                smallestDistanceSum = Math.min(smallestDistanceSum, 
                                               findDistance(workers[workerIndex], bikes[bikeIndex]) + 
                                               minimumDistanceSum(workers, bikes, workerIndex + 1, 
                                                                  mask | (1 << bikeIndex)));
            }
        }
        
        // Memoizing the result corresponding to mask
        return memo[mask] = smallestDistanceSum;
    }
    
    public int assignBikes(int[][] workers, int[][] bikes) {
        Arrays.fill(memo, -1);
        return minimumDistanceSum(workers, bikes, 0, 0);
    }
}
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming + BitMasking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Maximum value of mask will be 2^(Number of bikes)
    // And number of bikes can be 10 at max
    int memo [1024];
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int minimumDistanceSum(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int numOfBikes = bikes.size();
        int numOfWorkers = workers.size();
        int smallestDistanceSum = INT_MAX;

        // 0 signifies that no bike has been assigned and
        // Distance sum for not assigning any bike is equal to 0
        memo[0] = 0;
        // Traverse over all the possible values of mask
        for (int mask = 0; mask < (1 << numOfBikes); mask++) {
            int nextWorkerIndex = countNumOfOnes(mask);
            
            // If mask has more number of 1's than the number of workers
            // Then we can update our answer accordingly
            if (nextWorkerIndex >= numOfWorkers) {
                smallestDistanceSum = min(smallestDistanceSum, memo[mask]);
                continue;
            }
            
            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has already been assigned
                if ((mask & (1 << bikeIndex)) == 0) {
                    int newMask = (1 << bikeIndex) | mask;
                    
                    // Updating the distance sum for newMask
                    memo[newMask] = min(memo[newMask], memo[mask] + 
                                        findDistance(workers[nextWorkerIndex], bikes[bikeIndex]));
                }
            }
        }
        
        return smallestDistanceSum;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) { 
        // Initializing the answers for all masks to be INT_MAX
        for (int i = 0; i < 1024; i++) {
            memo[i] = INT_MAX;
        }
        return minimumDistanceSum(workers, bikes);
	}
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Maximum value of mask will be 2^(Number of bikes)
    // And number of bikes can be 10 at max
    int memo [] = new int[1024];
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    private int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    // Manhattan distance
    private int findDistance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
    
    private int minimumDistanceSum(int[][] workers, int[][] bikes) {
        int numOfBikes = bikes.length;
        int numOfWorkers = workers.length;
        int smallestDistanceSum = Integer.MAX_VALUE;

        // 0 signifies that no bike has been assigned and
        // Distance sum for not assigning any bike is equal to 0
        memo[0] = 0;
        
        // Traverse over all the possible values of mask
        for (int mask = 0; mask < (1 << numOfBikes); mask++) {
            int nextWorkerIndex = countNumOfOnes(mask);
            
            // If mask has more number of 1's than the number of workers
            // Then we can update our answer accordingly
            if (nextWorkerIndex >= numOfWorkers) {
                smallestDistanceSum = Math.min(smallestDistanceSum, memo[mask]);
                continue;
            }
            
            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has already been assigned
                if ((mask & (1 << bikeIndex)) == 0) {
                    int newMask = (1 << bikeIndex) | mask;
                    
                    // Updating the distance sum for newMask
                    memo[newMask] = Math.min(memo[newMask], memo[mask] + 
                                             findDistance(workers[nextWorkerIndex], bikes[bikeIndex]));
                }
            }
        }
        
        return smallestDistanceSum;
    }
    
    public int assignBikes(int[][] workers, int[][] bikes) {      
        // Initializing the answers for all masks to be INT_MAX
        Arrays.fill(memo, Integer.MAX_VALUE);
        return minimumDistanceSum(workers, bikes);
	}
}
```

</details>

<br>

## Approach 4: Priority Queue (Similar to Dijkstra's Algorithm)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Manhattan distance
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) { 
        int numOfBikes = bikes.size();
        int numOfWorkers = workers.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        unordered_set<int> visited;

        // Initially both distance sum and mask is 0
        priorityQueue.push({0, 0});
        while (!priorityQueue.empty()) {
            int currentDistanceSum = priorityQueue.top().first;
            int currentMask = priorityQueue.top().second;
            priorityQueue.pop();
            
            // Continue if the mask is already traversed
            if (visited.find(currentMask) != visited.end())
                continue;
            
            // Marking the mask as visited
            visited.insert(currentMask);
            // Next Worker index would be equal to the number of 1's in currentMask
            int workerIndex = countNumOfOnes(currentMask);
            
            // Return the current distance sum if all workers are covered
            if (workerIndex == numOfWorkers) {
                return currentDistanceSum;
            }

            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has been assigned or not
                if ((currentMask & (1 << bikeIndex)) == 0) {
                    int nextStateDistanceSum = currentDistanceSum + 
                        findDistance(workers[workerIndex], bikes[bikeIndex]);
                    
                    // Put the next state pair into the priority queue
                    int nextStateMask = currentMask | (1 << bikeIndex);
                    priorityQueue.push({nextStateDistanceSum, nextStateMask});
                }
            }
        }
        
        // This statement will never be executed provided there is at least one bike per worker
        return -1;
	}
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Manhattan distance
    private int findDistance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
    
    // Count the number of ones using Brian Kernighan’s Algorithm
    private int countNumOfOnes(int mask) {
        int count = 0;
        while (mask != 0) {
            mask &= (mask - 1);
            count++;
        } 
        return count;
    }
    
    public int assignBikes(int[][] workers, int[][] bikes) {
        int numOfBikes = bikes.length, numOfWorkers = workers.length;
        
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Set<Integer> visited = new HashSet<>();

        // Initially both distance sum and mask is 0
        priorityQueue.add(new int[]{0, 0});
        while (!priorityQueue.isEmpty()) {
            int currentDistanceSum = priorityQueue.peek()[0];
            int currentMask = priorityQueue.peek()[1];
            priorityQueue.remove();
            
            // Continue if the mask is already traversed
            if (visited.contains(currentMask))
                continue;
            
            // Marking the mask as visited
            visited.add(currentMask);
            // Next Worker index would be equal to the number of 1's in currentMask
            int workerIndex = countNumOfOnes(currentMask);
            
            // Return the current distance sum if all workers are covered
            if (workerIndex == numOfWorkers) {
                return currentDistanceSum;
            }

            for (int bikeIndex = 0; bikeIndex < numOfBikes; bikeIndex++) {
                // Checking if the bike at bikeIndex has been assigned or not
                if ((currentMask & (1 << bikeIndex)) == 0) {
                    int nextStateDistanceSum = currentDistanceSum + 
                        findDistance(workers[workerIndex], bikes[bikeIndex]);
                    
                    // Put the next state pair into the priority queue
                    int nextStateMask = currentMask | (1 << bikeIndex);
                    priorityQueue.add(new int[]{nextStateDistanceSum, nextStateMask});
                }
            }
        }
        
        // This statement will never be executed provided there is at least one bike per worker
        return -1;
    }
}
```

</details>
