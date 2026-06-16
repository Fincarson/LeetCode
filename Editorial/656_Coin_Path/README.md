# 656. Coin Path

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/coin-path/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 656 - Coin Path](https://leetcode.com/problems/coin-path/)

## Problem

You are given an integer array coins (1-indexed) of length n and an integer maxJump. You can jump to any index i of the array coins if coins[i] != -1 and you have to pay coins[i] when you visit index i. In addition to that, if you are currently at index i, you can only jump to any index i + k where i + k <= n and k is a value in the range [1, maxJump].

You are initially positioned at index 1 (coins[1] is not -1). You want to find the path that reaches index n with the minimum cost.

Return an integer array of the indices that you will visit in order so that you can reach index n with the minimum cost. If there are multiple paths with the same cost, return the lexicographically smallest such path. If it is not possible to reach index n, return an empty array.

A path p1 = [Pa1, Pa2, ..., Pax] of length x is lexicographically smaller than p2 = [Pb1, Pb2, ..., Pbx] of length y, if and only if at the first j where Paj and Pbj differ, Paj < Pbj; when no such j exists, then x < y.

### Example 1

```text
Input: coins = [1,2,4,-1,2], maxJump = 2
Output: [1,3,5]
```

### Example 2

```text
Input: coins = [1,2,4,-1,2], maxJump = 1
Output: []
```

## Constraints

- 1 <= coins.length <= 1000
- -1 <= coins[i] <= 100
- coins[1] != -1
- 1 <= maxJump <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [House Robber](https://leetcode.com/problems/house-robber/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 656. Coin Path

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force[Time Limit Exceeded] | Java |
| Approach #2 Using Memoization [Accepted] | Java |
| Approach #3 Using Dynamic Programming [Accepted] | Java |

## Approach #1 Brute Force[Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        Arrays.fill(next, -1);
        jump(A, B, 0, next);
        List < Integer > res = new ArrayList();
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i]>= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
    public long jump(int[] A, int B, int i, int[] next) {
        if (i == A.length - 1 && A[i] >= 0)
            return A[i];
        long min_cost = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + B && j < A.length; j++) {
            if (A[j] >= 0) {
                long cost = A[i] + jump(A, B, j, next);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        return min_cost;
    }
}
```

</details>

<br>

## Approach #2 Using Memoization [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        Arrays.fill(next, -1);
        long[] memo = new long[A.length];
        jump(A, B, 0, next, memo);
        List < Integer > res = new ArrayList();
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i] >= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
    public long jump(int[] A, int B, int i, int[] next, long[] memo) {
        if (memo[i] > 0)
            return memo[i];
        if (i == A.length - 1 && A[i] >= 0)
            return A[i];
        long min_cost = Integer.MAX_VALUE;
        for (int j = i + 1; j <= i + B && j < A.length; j++) {
            if (A[j] >= 0) {
                long cost = A[i] + jump(A, B, j, next, memo);
                if (cost < min_cost) {
                    min_cost = cost;
                    next[i] = j;
                }
            }
        }
        memo[i] = min_cost;
        return min_cost;
    }
}
```

</details>

<br>

## Approach #3 Using Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public List < Integer > cheapestJump(int[] A, int B) {
        int[] next = new int[A.length];
        long[] dp = new long[A.length];
        Arrays.fill(next, -1);
        List < Integer > res = new ArrayList();
        for (int i = A.length - 2; i >= 0; i--) {
            long min_cost = Integer.MAX_VALUE;
            for (int j = i + 1; j <= i + B && j < A.length; j++) {
                if (A[j] >= 0) {
                    long cost = A[i] + dp[j];
                    if (cost < min_cost) {
                        min_cost = cost;
                        next[i] = j;
                    }
                }
            }
            dp[i] = min_cost;
        }
        int i;
        for (i = 0; i < A.length && next[i] > 0; i = next[i])
            res.add(i + 1);
        if (i == A.length - 1 && A[i] >= 0)
            res.add(A.length);
        else
            return new ArrayList < Integer > ();
        return res;
    }
}
```

</details>
