# 403. Frog Jump

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/frog-jump/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 403 - Frog Jump](https://leetcode.com/problems/frog-jump/)

## Problem

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

### Example 1

```text
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
```

### Example 2

```text
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
```

## Constraints

- 2 <= stones.length <= 2000
- 0 <= stones[i] <= 231 - 1
- stones[0] == 0
- stones is sorted in a strictly increasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Sideway Jumps](https://leetcode.com/problems/minimum-sideway-jumps/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 403. Frog Jump

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
    unordered_map<int, int> mark;
    int dp[2001][2001];
    
    int solve(vector<int>& stones, int n, int index, int prevJump) {
        // If reached the last stone, return 1.
        if (index == n - 1) {
            return 1;
        }
        
        // If this subproblem has been already calculated, return it.
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump];  
        }
        
        int ans = false;
        // Iterate over the three possibilities {k - 1, k, k + 1}.
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && mark.find(stones[index] + nextJump) != mark.end()) {
                ans = ans || solve(stones, n, mark[stones[index] + nextJump], nextJump);
            }
        }

        // Store the result to fetch later.
        return dp[index][prevJump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < stones.size(); i++) {
            mark.insert({stones[i], i});
        }
        
        // Mark all states as -1 to denote they're not calculated.
        memset(dp, -1, sizeof(dp));
        return solve(stones, stones.size(), 0, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    HashMap<Integer, Integer> mark = new HashMap<>();
    int dp[][] = new int[2001][2001];
    
    boolean solve(int[] stones, int n, int index, int prevJump) {
        // If reached the last stone, return 1.
        if (index == n - 1) {
            return true;
        }
        
        // If this subproblem has already been calculated, return it.
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump] == 1;
        }
        
        boolean ans = false;
        // Iterate over the three possibilities {k - 1, k, k + 1}.
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && mark.containsKey(stones[index] + nextJump)) {
                ans = ans || solve(stones, n, mark.get(stones[index] + nextJump), nextJump);
            }
        }

        // Store the result to fetch later.
        dp[index][prevJump] = (ans ? 1 :0);
        return ans;
    }
    
    public boolean canCross(int[] stones) {
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < stones.length; i++) {
            mark.put(stones[i], i);
        }
        
        //Mark all states as -1 to denote they're not calculated.
        for (int i = 0; i < 2000; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        return solve(stones, stones.length, 0, 0);
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
    unordered_map<int, int> mark;
    int dp[2001][2001];

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < n; i++) {
            mark[stones[i]] = i;
        }
        
        dp[0][0] = 1;
        for (int index = 0; index < n; index++) {
            for (int prevJump = 0; prevJump <= n; prevJump++) {
                // If stone exists, mark the value with position and jump as 1.
                if (dp[index][prevJump]) {
                    if (mark[stones[index] + prevJump]) {
                        dp[mark[stones[index] + prevJump]][prevJump] = 1;
                    }
                    if (mark[stones[index] + prevJump + 1]) {
                        dp[mark[stones[index] + prevJump + 1]][prevJump + 1] = 1;
                    }
                    if (mark[stones[index] + prevJump - 1]) {
                        dp[mark[stones[index] + prevJump - 1]][prevJump - 1] = 1;
                    }
                }
                
                
            }
        }
        
        // If any value with index as n - 1 is true, return true.
        for (int prevJump = 0; prevJump <= n; prevJump++) {
            if (dp[n - 1][prevJump]) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    HashMap<Integer,Integer> mark = new HashMap<Integer,Integer>();
    boolean dp[][] = new boolean[2001][2001];

    public boolean canCross(int[] stones) {
        int n = stones.length;
        // Mark stones in the map to identify if such stone exists or not.
        for (int i = 0 ; i < n; i++) {
            mark.put(stones[i], i);
        }

        dp[0][0] = true;
        for (int index = 0; index < n; index++) {
            for (int prevJump = 0; prevJump <= n; prevJump++) {
                // If stone exists, mark the value with position and jump as 1.
                if (dp[index][prevJump]) {
                    if (mark.containsKey(stones[index] + prevJump)) {
                        dp[mark.get(stones[index] + prevJump)][prevJump] = true;
                    }
                    if (mark.containsKey(stones[index] + prevJump + 1)) {
                        dp[mark.get(stones[index] + prevJump + 1)][prevJump + 1] = true;
                    }
                    if (mark.containsKey(stones[index] + prevJump - 1)) {
                        dp[mark.get(stones[index] + prevJump - 1)][prevJump - 1] = true;
                    }
                }


            }
        }

        // If any value with index as n - 1 is true, return true.
        for (int index = 0; index <= n; index++) {
            if (dp[n - 1][index]) {
                return true;
            }
        }
        return false;
    }
}
```

</details>
