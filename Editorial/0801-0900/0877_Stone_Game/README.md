# 877. Stone Game

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/stone-game/)  
`Array` `Math` `Dynamic Programming` `Game Theory`

**Problem Link:** [LeetCode 877 - Stone Game](https://leetcode.com/problems/stone-game/)

## Problem

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

### Example 1

```text
Input: piles = [5,3,4,5]
Output: true
Explanation:
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
```

### Example 2

```text
Input: piles = [3,7,2,3]
Output: true
```

## Constraints

- 2 <= piles.length <= 500
- piles.length is even.
- 1 <= piles[i] <= 500
- sum(piles[i]) is odd.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stone Game V](https://leetcode.com/problems/stone-game-v/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Stone Game VI](https://leetcode.com/problems/stone-game-vi/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Stone Game VII](https://leetcode.com/problems/stone-game-vii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Stone Game IX](https://leetcode.com/problems/stone-game-ix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Strictly Palindromic Number](https://leetcode.com/problems/strictly-palindromic-number/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Visit Array Positions to Maximize Score](https://leetcode.com/problems/visit-array-positions-to-maximize-score/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 877. Stone Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, JavaScript, Python3 |
| Mathematical | C++, Java, JavaScript, Python |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N+2][N+2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j) {
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean stoneGame(int[] piles) {
        int N = piles.length;

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]].
        int[][] dp = new int[N+2][N+2];
        for (int size = 1; size <= N; ++size)
            for (int i = 0; i + size <= N; ++i) {
                int j = i + size - 1;
                int parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i+1][j+1] = Math.max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
                else
                    dp[i+1][j+1] = Math.min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
            }

        return dp[1][N] > 0;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var stoneGame = function(piles) {
    const N = piles.length;
    // Make a (N+2) by (N+2) array, initialized with 0s.
    const dp = Array(N + 2).fill(0).map(() => Array(N + 2).fill(0));

    // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
    for (let size = 1; size <= N; ++size)
        for (let i = 0, j = size - 1; j < N; ++i, ++j) {
            let parity = (j + i + N) % 2;  // j - i - N; but +x = -x (mod 2)
            if (parity == 1)
                dp[i+1][j+1] = Math.max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
            else
                dp[i+1][j+1] = Math.min(-piles[i] + dp[i+2][j+1], -piles[j] + dp[i+1][j]);
        }

    return dp[1][N] > 0;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from functools import lru_cache

class Solution:
    def stoneGame(self, piles):
        N = len(piles)

        @lru_cache(None)
        def dp(i, j):
            # The value of the game [piles[i], piles[i+1], ..., piles[j]].
            if i > j: return 0
            parity = (j - i - N) % 2
            if parity == 1:  # first player
                return max(piles[i] + dp(i+1,j), piles[j] + dp(i,j-1))
            else:
                return min(-piles[i] + dp(i+1,j), -piles[j] + dp(i,j-1))

        return dp(0, N - 1) > 0
```

</details>

<br>

## Approach 2: Mathematical

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var stoneGame = function(piles) {
    return true;
};
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def stoneGame(self, piles):
        return True
```

</details>
