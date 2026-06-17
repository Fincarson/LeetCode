# 486. Predict the Winner

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/predict-the-winner/)  
`Array` `Math` `Dynamic Programming` `Recursion` `Game Theory`

**Problem Link:** [LeetCode 486 - Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

## Problem

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

### Example 1

```text
Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return false.
```

### Example 2

```text
Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
```

## Constraints

- 1 <= nums.length <= 20
- 0 <= nums[i] <= 107

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Can I Win](https://leetcode.com/problems/can-i-win/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find the Winning Player in Coin Game](https://leetcode.com/problems/find-the-winning-player-in-coin-game/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Number of Winning Players](https://leetcode.com/problems/find-the-number-of-winning-players/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count The Number of Winning Sequences](https://leetcode.com/problems/count-the-number-of-winning-sequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 486. Predict the Winner

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java, Python3 |
| Dynamic Programming, Top-Down | Java, Python3 |
| Dynamic Programming, Bottom-Up | Java, Python3 |
| Dynamic Programming, Space-Optimized | Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int maxDiff(int[] nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);
        
        return Math.max(scoreByLeft, scoreByRight);
    }
    
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        
        return maxDiff(nums, 0, n - 1) >= 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        
        def maxDiff(left, right):
            if left == right:
                return nums[left]
            score_by_left = nums[left] - maxDiff(left + 1, right)
            score_by_right = nums[right] - maxDiff(left, right - 1)
            return max(score_by_left, score_by_right)
        
        return maxDiff(0, n - 1) >= 0
```

</details>

<br>

## Approach 2: Dynamic Programming, Top-Down

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    
    private int maxDiff(int[] nums, int left, int right) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (left == right) {
            return nums[left];
        }
        
        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);
        memo[left][right] = Math.max(scoreByLeft, scoreByRight);
        
        return memo[left][right];
    }
    
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        memo = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(memo[i], -1);
        }
        
        return maxDiff(nums, 0, n - 1) >= 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        memo = collections.defaultdict(int)
        
        def maxDiff(left, right):
            if (left, right) in memo:
                return memo[(left, right)]
            if left == right:
                return nums[left]
            score_by_left = nums[left] - maxDiff(left + 1, right)
            score_by_right = nums[right] - maxDiff(left, right - 1)
            
            memo[(left, right)] = max(score_by_left, score_by_right)
            return memo[(left, right)]
        
        return maxDiff(0, n - 1) >= 0
```

</details>

<br>

## Approach 3: Dynamic Programming, Bottom-Up

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        
        for (int diff = 1; diff < n; ++diff) {
            for (int left = 0; left < n - diff; ++left) {
                int right = left + diff;
                dp[left][right] = Math.max(nums[left] - dp[left + 1][right],
                                          nums[right] - dp[left][right - 1]);
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = nums[i]
        
        for diff in range(1, n):
            for left in range(n - diff):
                right = left + diff
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1])
        
        return dp[0][n - 1] >= 0
```

</details>

<br>

## Approach 4: Dynamic Programming, Space-Optimized

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int[] dp = Arrays.copyOf(nums, n);
        
        for (int diff = 1; diff < n; ++diff) {
            for (int left = 0; left < n - diff; ++left) {
                int right = left + diff;
                dp[left] = Math.max(nums[left] - dp[left + 1], nums[right] - dp[left]);
            }
        }
        
        return dp[0] >= 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = nums[:]
        
        for diff in range(1, n):
            for left in range(n - diff):
                right = left + diff
                dp[left] = max(nums[left] - dp[left + 1], nums[right] - dp[left])
        
        return dp[0] >= 0
```

</details>
