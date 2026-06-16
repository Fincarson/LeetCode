# 375. Guess Number Higher or Lower II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)  
`Math` `Dynamic Programming` `Game Theory`

**Problem Link:** [LeetCode 375 - Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)

## Problem

We are playing the Guessing Game. The game will work as follows:

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

### Example 1

```text
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
```

### Example 2

```text
Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
```

### Example 3

```text
Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
```

## Constraints

- 1 <= n <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Flip Game II](https://leetcode.com/problems/flip-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Can I Win](https://leetcode.com/problems/can-i-win/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 375. Guess Number Higher or Lower II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Modified Brute Force [Time Limit Exceeded] | Java |
| Approach #3 Using DP [Accepted] | Java |
| Approach #4 Better Approach using DP [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int calculate(int low, int high) {
        if (low >= high)
            return 0;
        int minres = Integer.MAX_VALUE;
        for (int i = low; i <= high; i++) {
            int res = i + Math.max(calculate(i + 1, high), calculate(low, i - 1));
            minres = Math.min(res, minres);
        }

        return minres;
    }
    public int getMoneyAmount(int n) {
        return calculate(1, n);
    }
}
```

</details>

<br>

## Approach #2 Modified Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int calculate(int low, int high) {
        if (low >= high)
            return 0;
        int minres = Integer.MAX_VALUE;
        for (int i = (low + high) / 2; i <= high; i++) {
            int res = i + Math.max(calculate(i + 1, high), calculate(low, i - 1));
            minres = Math.min(res, minres);
        }
        return minres;
    }
    public int getMoneyAmount(int n) {
        return calculate(1, n);
    }
}
```

</details>

<br>

## Approach #3 Using DP [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = Integer.MAX_VALUE;
                for (int piv = start; piv < start + len - 1; piv++) {
                    int res = piv + Math.max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = Math.min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }
        }
        return dp[1][n];
    }
}
```

</details>

<br>

## Approach #4 Better Approach using DP [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];

        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = Integer.MAX_VALUE;
                for (int piv = start + (len - 1) / 2; piv < start + len - 1; piv++) {
                    int res = piv + Math.max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = Math.min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }

        }
        return dp[1][n];
    }
}
```

</details>
