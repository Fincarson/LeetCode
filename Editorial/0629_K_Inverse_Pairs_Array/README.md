# 629. K Inverse Pairs Array

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/k-inverse-pairs-array/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 629 - K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/)

## Problem

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

### Example 1

```text
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
```

### Example 2

```text
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
```

## Constraints

- 1 <= n <= 1000
- 0 <= k <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Inversions](https://leetcode.com/problems/count-the-number-of-inversions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 629. K Inverse Pairs Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Recursion with Memoization | Java |
| Dynamic Programming | Java |
| Dynamic Programming with Cumulative Sum | Java |
| Another Optimized Dynamic Programming Approach | Java |
| Once Again Memoization | Java |
| 1-D Dynamic Programmming | Java |

## Approach 2: Using Recursion with Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    Integer[][] memo = new Integer[1001][1001];
    public int kInversePairs(int n, int k) {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (memo[n][k] != null)
            return memo[n][k];
        int inv = 0;
        for (int i = 0; i <= Math.min(k, n - 1); i++)
            inv = (inv + kInversePairs(n - 1, k - i)) % 1000000007;
        memo[n][k] = inv;
        return inv;
    }
}
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    for (int p = 0; p <= Math.min(j, i - 1); p++)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
                }
            }
        }
        return dp[n][k];
    }
}
```

</details>

<br>

## Approach 4: Dynamic Programming with Cumulative Sum

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        int M = 1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    int val = (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return ((dp[n][k] + M - (k > 0 ? dp[n][k - 1] : 0)) % M);
    }
}
```

</details>

<br>

## Approach 5: Another Optimized Dynamic Programming Approach

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        int M = 1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k && j <= i * (i - 1) / 2; j++) {
                if (i == 1 && j == 0) {
                    dp[i][j] = 1;
                    break;
                } else if (j == 0)
                    dp[i][j] = 1;
                else {
                    int val = (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return dp[n][k];
    }
}
```

</details>

<br>

## Approach 6: Once Again Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    Integer[][] memo = new Integer[1001][1001];
    int M = 1000000007;
    public int kInversePairs(int n, int k) {
        return ((inv(n, k) + M - (k > 0 ? inv(n, k - 1) : 0)) % M);
    }
    public int inv(int n, int k) {
        if (n == 0)
            return 0;
        if (k == 0)
            return 1;
        if (memo[n][k] != null)
            return memo[n][k];
        int val = (inv(n - 1, k) + M - ((k - n) >= 0 ? inv(n - 1, k - n) : 0)) % M;
        memo[n][k] = (inv(n, k - 1) + val) % M;
        return memo[n][k];
    }
}
```

</details>

<br>

## Approach 7: 1-D Dynamic Programmming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int kInversePairs(int n, int k) {
        int[] dp = new int[k + 1];
        int M = 1000000007;
        for (int i = 1; i <= n; i++) {
            int[] temp = new int[k + 1];
            temp[0] = 1;
            for (int j = 1; j <= k ; j++) {
                int val = (dp[j] + M - ((j - i) >= 0 ? dp[j - i] : 0)) % M;
                temp[j] = (temp[j - 1] + val) % M;
            }
            dp = temp;
        }
        return ((dp[k] + M - (k > 0 ? dp[k - 1] : 0)) % M);
    }
}
```

</details>
