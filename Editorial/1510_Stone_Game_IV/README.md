# 1510. Stone Game IV

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/stone-game-iv/)  
`Math` `Dynamic Programming` `Game Theory`

**Problem Link:** [LeetCode 1510 - Stone Game IV](https://leetcode.com/problems/stone-game-iv/)

## Problem

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

### Example 1

```text
Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
```

### Example 2

```text
Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
```

### Example 3

```text
Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
```

## Constraints

- 1 <= n <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stone Game V](https://leetcode.com/problems/stone-game-v/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game VI](https://leetcode.com/problems/stone-game-vi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game VII](https://leetcode.com/problems/stone-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game IX](https://leetcode.com/problems/stone-game-ix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Removal Game](https://leetcode.com/problems/stone-removal-game/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1510. Stone Game IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| DFS with memoization | Java, Python3 |
| DP | Java, Python3 |

## Approach 1: DFS with memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean winnerSquareGame(int n) {
        HashMap<Integer, Boolean> cache = new HashMap<>();
        cache.put(0, false);
        return dfs(cache, n);
    }

    public static boolean dfs(HashMap<Integer, Boolean> cache, int remain) {
        if (cache.containsKey(remain)) {
            return cache.get(remain);
        }
        int sqrt_root = (int) Math.sqrt(remain);
        for (int i = 1; i <= sqrt_root; i++) {
            // if there is any chance to make the opponent lose the game in the next round,
            // then the current player will win.
            if (!dfs(cache, remain - i * i)) {
                cache.put(remain, true);
                return true;
            }
        }
        cache.put(remain, false);
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:

        @lru_cache(maxsize=None)
        def dfs(remain):
            if remain == 0:
                return False

            sqrt_root = int(remain**0.5)
            for i in range(1, sqrt_root+1):
                # if there is any chance to make the opponent lose the game in the next round,
                #  then the current player will win.
                if not dfs(remain - i*i):
                    return True

            return False

        return dfs(n)
```

</details>

<br>

## Approach 2: DP

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean winnerSquareGame(int n) {
        boolean[] dp = new boolean[n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (dp[i - k * k] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False]*(n+1)
        for i in range(1, n+1):
            for k in range(1, int(i**0.5)+1):
                if dp[i-k*k] == False:
                    dp[i] = True
                    break
        return dp[n]
```

</details>
