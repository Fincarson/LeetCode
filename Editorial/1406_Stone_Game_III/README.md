# 1406. Stone Game III

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/stone-game-iii/)  
`Array` `Math` `Dynamic Programming` `Game Theory`

**Problem Link:** [LeetCode 1406 - Stone Game III](https://leetcode.com/problems/stone-game-iii/)

## Problem

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

### Example 1

```text
Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
```

### Example 2

```text
Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
```

### Example 3

```text
Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
```

## Constraints

- 1 <= stoneValue.length <= 5 * 104
- -1000 <= stoneValue[i] <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stone Game V](https://leetcode.com/problems/stone-game-v/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game VI](https://leetcode.com/problems/stone-game-vi/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game VII](https://leetcode.com/problems/stone-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Stone Game VIII](https://leetcode.com/problems/stone-game-viii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Stone Game IX](https://leetcode.com/problems/stone-game-ix/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1406. Stone Game III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Top-Down Dynamic Programming (Memoization) | C++, Java, Python3 |
| Bottom-Up Dynamic Programming, Space Complexity Optimized | C++, Java, Python3 |

## Approach 1: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];
            if (i + 2 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }
            if (i + 3 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        int[] dp = new int [n + 1];
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];
            if (i + 2 <= n) {
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }
            if (i + 3 <= n) {
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            dp[i] = stoneValue[i] - dp[i + 1]
            if i + 2 <= n:
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2])
            if i + 3 <= n:
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1]
                            + stoneValue[i + 2] - dp[i + 3])
        if dp[0] > 0:
            return "Alice"
        if dp[0] < 0:
            return "Bob"
        return "Tie"
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        function<int(int)> f = [&](int i) -> int {
            if (i == n) {
                return 0;
            }
            int result = stoneValue[i] - f(i + 1);
            if (i + 2 <= n) {
                result = max(result, stoneValue[i] + stoneValue[i + 1] - f(i + 2));
            }
            if (i + 3 <= n) {
                result = max(result, stoneValue[i] + stoneValue[i + 1]
                    + stoneValue[i + 2] - f(i + 3));
            }
            return result;
        };

        int dif = f(0);
        if (dif > 0) {
            return "Alice";
        }
        if (dif < 0) {
            return "Bob";
        }
        return "Tie";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int f(int[] stoneValue, int n, int i) {
        if (i == n) {
            return 0;
        }
        int result = stoneValue[i] - f(stoneValue, n, i + 1);
        if (i + 2 <= n) {
            result = Math.max(result, stoneValue[i]
                + stoneValue[i + 1] - f(stoneValue, n, i + 2));
        }
        if (i + 3 <= n) {
            result = Math.max(result, stoneValue[i] + stoneValue[i + 1]
                + stoneValue[i + 2] - f(stoneValue, n, i + 3));
        }
        return result;
    }

    public String stoneGameIII(int[] stoneValue) {
        int dif = f(stoneValue, stoneValue.length, 0);
        if (dif > 0) {
            return "Alice";
        }
        if (dif < 0) {
            return "Bob";
        }
        return "Tie";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        def f(i):
            if i == n:
                return 0
            result = stoneValue[i] - f(i + 1)
            if i + 2 <= n:
                result = max(result, stoneValue[i] + stoneValue[i + 1] - f(i + 2))
            if i + 3 <= n:
                result = max(result, stoneValue[i] + stoneValue[i + 1]
                            + stoneValue[i + 2] - f(i + 3))
            return result

        dif = f(0)
        if dif > 0:
            return "Alice"
        if dif < 0:
            return "Bob"
        return "Tie"
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming, Space Complexity Optimized

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4);
        for (int i = n - 1; i >= 0; i--) {
            dp[i % 4] = stoneValue[i] - dp[(i + 1) % 4];
            if (i + 2 <= n) {
                dp[i % 4] = max(dp[i % 4], stoneValue[i]
                    + stoneValue[i + 1] - dp[(i + 2) % 4]);
            }
            if (i + 3 <= n) {
                dp[i % 4] = max(dp[i % 4], stoneValue[i] + stoneValue[i + 1]
                    + stoneValue[i + 2] - dp[(i + 3) % 4]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        int[] dp = new int [4];
        for (int i = n - 1; i >= 0; i--) {
            dp[i % 4] = stoneValue[i] - dp[(i + 1) % 4];
            if (i + 2 <= n) {
                dp[i % 4] = Math.max(dp[i % 4], stoneValue[i] + stoneValue[i + 1]
                    - dp[(i + 2) % 4]);
            }
            if (i + 3 <= n) {
                dp[i % 4] = Math.max(dp[i % 4], stoneValue[i] + stoneValue[i + 1]
                    + stoneValue[i + 2] - dp[(i + 3) % 4]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [0] * 4
        for i in range(n - 1, -1, -1):
            dp[i % 4] = stoneValue[i] - dp[(i + 1) % 4]
            if i + 2 <= n:
                dp[i % 4] = max(dp[i % 4], stoneValue[i]
                		+ stoneValue[i + 1] - dp[(i + 2) % 4])
            if i + 3 <= n:
                dp[i % 4] = max(dp[i % 4], stoneValue[i] + stoneValue[i + 1]
                           	+ stoneValue[i + 2] - dp[(i + 3) % 4])
        if dp[0] > 0:
            return "Alice"
        if dp[0] < 0:
            return "Bob"
        return "Tie"
```

</details>
