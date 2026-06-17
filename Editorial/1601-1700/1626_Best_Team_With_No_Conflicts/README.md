# 1626. Best Team With No Conflicts

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/best-team-with-no-conflicts/)  
`Array` `Dynamic Programming` `Sorting`

**Problem Link:** [LeetCode 1626 - Best Team With No Conflicts](https://leetcode.com/problems/best-team-with-no-conflicts/)

## Problem

You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.

However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.

Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

### Example 1

```text
Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.
```

### Example 2

```text
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
```

### Example 3

```text
Input: scores = [1,2,3,5], ages = [8,9,10,1]
Output: 6
Explanation: It is best to choose the first 3 players.
```

## Constraints

- 1 <= scores.length, ages.length <= 1000
- scores.length == ages.length
- 1 <= scores[i] <= 106
- 1 <= ages[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1626. Best Team With No Conflicts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java |
| Bottom-Up Dynamic Programming | C++, Java |
| Binary Indexed Tree (BIT) / Fenwick Tree | C++, Java |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxScore(vector<vector<int>>& dp, vector<pair<int, int>>& ageScorePair, int prev, int index) {
        // Return 0 if we have iterated over all the players.
        if (index >= ageScorePair.size()) {
            return 0;
        }
        
        // We have already calculated the answer, so no need to go into recursion.
        if (dp[prev + 1][index] != -1) {
            return dp[prev + 1][index];
        }

        // If we can add this player, return the maximum of two choices we have.
        if (prev == -1 || ageScorePair[index].second >= ageScorePair[prev].second) {
            return dp[prev + 1][index] = max(findMaxScore(dp, ageScorePair, prev, index + 1), 
                       ageScorePair[index].second + findMaxScore(dp, ageScorePair, index, index + 1));
        }
        
        // This player cannot be added; return the corresponding score.
        return dp[prev + 1][index] = findMaxScore(dp, ageScorePair, prev, index + 1);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({ages[i], scores[i]});
        }
        
        // Sort in ascending order of age and then by score.
        sort(ageScorePair.begin(), ageScorePair.end());
        // Mark all the states as -1, denoting not yet calculated.
        vector<vector<int>> dp(scores.size(), vector<int>(scores.size(), -1));
        return findMaxScore(dp, ageScorePair, -1, 0);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        final int n = ages.length;
        int[][] ageScorePair = new int[n][2];

        for (int i = 0; i < n; i++) {
            ageScorePair[i][0] = ages[i];
            ageScorePair[i][1] = scores[i];
        }

        // Sort in ascending order of age and then by score.
        Arrays.sort(ageScorePair, (a,b) -> a[0] == b[0] ? a[1]-b[1] : a[0]-b[0]);
        // Initially, all states are null, denoting not yet calculated.
        Integer[][] dp = new Integer[n][n];

        return findMaxScore(dp, ageScorePair, -1, 0);
    }

    private int findMaxScore(Integer[][] dp, int[][] ageScorePair, int prev, int index) {
        // Return 0 if we have iterated over all the players.
        if (index >= ageScorePair.length) {
            return 0;
        }

        // We have already calculated the answer, so no need to go into recursion.
        if (dp[prev + 1][index] != null) {
            return dp[prev + 1][index];
        }

        // If we can add this player, return the maximum of two choices we have.
        if (prev == -1 || ageScorePair[index][1] >= ageScorePair[prev][1]) {
            return dp[prev + 1][index] = Math.max(findMaxScore(dp, ageScorePair, prev, index + 1),
                    ageScorePair[index][1] + findMaxScore(dp, ageScorePair, index, index + 1));
        }

        // This player cannot be added; return the corresponding score.
        return dp[prev + 1][index] = findMaxScore(dp, ageScorePair, prev, index + 1);
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
    int findMaxScore(vector<pair<int, int>>& ageScorePair) {
        int n = (int) ageScorePair.size();
        int answer = 0;
        
        vector<int> dp(n);
        // Initially, the maximum score for each player will be equal to the individual scores.
        for (int i = 0; i < n; i++) {
            dp[i] = ageScorePair[i].second;
            answer = max(answer, dp[i]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // If the players j and i could be in the same team.
                if (ageScorePair[i].second >= ageScorePair[j].second) {
                    // Update the maximum score for the ith player.
                    dp[i] = max(dp[i], ageScorePair[i].second + dp[j]);
                }
            }
            // Maximum score among all the players.
            answer = max(answer, dp[i]);
        }
        
        return answer;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({ages[i], scores[i]});
        }
        
        // Sort in ascending order of age and then by score.
        sort(ageScorePair.begin(), ageScorePair.end());
        return findMaxScore(ageScorePair);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int findMaxScore(int[][] ageScorePair) {
        int n = ageScorePair.length;
        int answer = 0;

        int[] dp = new int[n];
        // Initially, the maximum score for each player will be equal to the individual scores.
        for (int i = 0; i < n; i++) {
            dp[i] = ageScorePair[i][1];
            answer = Math.max(answer, dp[i]);
        }


        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                // If the players j and i could be in the same team.
                if (ageScorePair[i][1] >= ageScorePair[j][1]) {
                    // Update the maximum score for the ith player.
                    dp[i] = Math.max(dp[i], ageScorePair[i][1] + dp[j]);
                }
            }
            // Maximum score among all the players.
            answer = Math.max(answer, dp[i]);
        }

        return answer;
    }

    public int bestTeamScore(int[] scores, int[] ages) {
        int N = ages.length;
        int[][] ageScorePair = new int[N][2];

        for (int i = 0; i < N; i++) {
            ageScorePair[i][0] = ages[i];
            ageScorePair[i][1] = scores[i];
        }

        // Sort in ascending order of age and then by score.
        Arrays.sort(ageScorePair, (a,b) -> a[0] == b[0] ? a[1]-b[1] : a[0]-b[0]);
        return findMaxScore(ageScorePair);
    }
}
```

</details>

<br>

## Approach 3: Binary Indexed Tree (BIT) / Fenwick Tree

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({scores[i], ages[i]});
        }
        // Sort in ascending order of score and then by age.
        sort(ageScorePair.begin(), ageScorePair.end());

        int highestAge = 0;
        for (int i : ages) {
            highestAge = max(highestAge, i);
        }
        vector<int> BIT(highestAge + 1, 0);
        
        int answer = INT_MIN;
        for (pair<int, int> ageScore : ageScorePair) {
            // Maximum score up to this age might not have all the players of this age.
            int currentBest = ageScore.first + queryBIT(BIT, ageScore.second);
            // Update the tree with the current age and its best score.
            updateBIT(BIT, ageScore.second, currentBest);
            
            answer = max(answer, currentBest);
        }

        return answer;
    }
    
    // Query tree to get the maximum score up to this age.
    int queryBIT(vector<int>& BIT, int age) {
        int maxScore = INT_MIN;
        for (int i = age; i > 0; i -= i & (-i)) {
            maxScore = max(maxScore, BIT[i]);
        }
        return maxScore;
    }


    // Update the maximum score for all the nodes with an age greater than the given age.
    void updateBIT(vector<int>& BIT, int age, int currentBest) {
        for (int i = age; i < BIT.size(); i += i & (-i)) {
            BIT[i] = max(BIT[i], currentBest);
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int N = ages.length;
        int[][] ageScorePair = new int[N][2];

        for (int i = 0; i < N; i++) {
            ageScorePair[i][0] = scores[i];
            ageScorePair[i][1] = ages[i];
        }

        // Sort in ascending order of score and then by age.
        Arrays.sort(ageScorePair, (a,b) -> a[0] == b[0] ? a[1]-b[1] : a[0]-b[0]);

        int highestAge = 0;
        for (int i : ages) {
            highestAge = Math.max(highestAge, i);
        }
        int[] BIT = new int[highestAge + 1];

        int answer = Integer.MIN_VALUE;
        for (int[] ageScore : ageScorePair) {
            // Maximum score up to this age might not have all the players of this age.
            int currentBest = ageScore[0] + queryBIT(BIT, ageScore[1]);
            // Update the tree with the current age and its best score.
            updateBIT(BIT, ageScore[1], currentBest);

            answer = Math.max(answer, currentBest);
        }

        return answer;
    }

    // Query tree to get the maximum score up to this age.
    private int queryBIT(int[] BIT, int age) {
        int maxScore = Integer.MIN_VALUE;
        for (int i = age; i > 0; i -= i & (-i)) {
            maxScore = Math.max(maxScore, BIT[i]);
        }
        return maxScore;
    }

    // Update the maximum score for all the nodes with an age greater than the given age.
    private void updateBIT(int[] BIT, int age, int currentBest) {
        for (int i = age; i < BIT.length; i += i & (-i)) {
            BIT[i] = Math.max(BIT[i], currentBest);
        }
    }
}
```

</details>
