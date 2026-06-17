# 474. Ones and Zeroes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/ones-and-zeroes/)  
`Array` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 474 - Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

## Problem

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

### Example 1

```text
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
```

### Example 2

```text
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
```

## Constraints

- 1 <= strs.length <= 600
- 1 <= strs[i].length <= 100
- strs[i] consists only of digits '0' and '1'.
- 1 <= m, n <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Subarrays With More Ones Than Zeros](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [All Divisions With the Highest Score of a Binary Array](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 474. Ones and Zeroes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Better Brute Force [Time Limit Exceeded] | Java |
| Approach #3 Using Recursion [Time Limit Exceeded] | Java |
| Approach #4 Using Memoization [Accepted] | Java |
| Approach #5 Dynamic Programming [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int maxlen = 0;
        for (int i = 0; i < (1 << strs.length); i++) {
            int zeroes = 0, ones = 0, len = 0;
            for (int j = 0; j < strs.length; j++) {
                if ((i & (1 << j)) != 0) {
                    int[] count = countzeroesones(strs[j]);
                    zeroes += count[0];
                    ones += count[1];
                    len++;
                }
            }
            if (zeroes <= m && ones <= n)
                maxlen = Math.max(maxlen, len);
        }
        return maxlen;

    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

</details>

<br>

## Approach #2 Better Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int maxlen = 0;
        for (int i = 0; i < (1 << strs.length); i++) {
            int zeroes = 0, ones = 0, len = 0;
            for (int j = 0; j < 32; j++) {
                if ((i & (1 << j)) != 0) {
                    int[] count = countzeroesones(strs[j]);
                    zeroes += count[0];
                    ones += count[1];
                    if (zeroes > m || ones > n)
                        break;
                    len++;
                }
            }
            if (zeroes <= m && ones <= n)
                maxlen = Math.max(maxlen, len);
        }
        return maxlen;
    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

</details>

<br>

## Approach #3 Using Recursion [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        return calculate(strs, 0, m, n);
    }
    public int calculate(String[] strs, int i, int zeroes, int ones) {
        if (i == strs.length)
            return 0;
        int[] count = countzeroesones(strs[i]);
        int taken = -1;
        if (zeroes - count[0] >= 0 && ones - count[1] >= 0)
            taken = calculate(strs, i + 1, zeroes - count[0], ones - count[1]) + 1;
        int not_taken = calculate(strs, i + 1, zeroes, ones);
        return Math.max(taken, not_taken);
    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

</details>

<br>

## Approach #4 Using Memoization [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][][] memo = new int[strs.length][m + 1][n + 1];
        return calculate(strs, 0, m, n, memo);
    }
    public int calculate(String[] strs, int i, int zeroes, int ones, int[][][] memo) {
        if (i == strs.length)
            return 0;
        if (memo[i][zeroes][ones] != 0)
            return memo[i][zeroes][ones];
        int[] count = countzeroesones(strs[i]);
        int taken = -1;
        if (zeroes - count[0] >= 0 && ones - count[1] >= 0)
            taken = calculate(strs, i + 1, zeroes - count[0], ones - count[1], memo) + 1;
        int not_taken = calculate(strs, i + 1, zeroes, ones, memo);
        memo[i][zeroes][ones] = Math.max(taken, not_taken);
        return memo[i][zeroes][ones];
    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

</details>

<br>

## Approach #5 Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (String s: strs) {
            int[] count = countzeroesones(s);
            for (int zeroes = m; zeroes >= count[0]; zeroes--)
                for (int ones = n; ones >= count[1]; ones--)
                    dp[zeroes][ones] = Math.max(1 + dp[zeroes - count[0]][ones - count[1]], dp[zeroes][ones]);
        }
        return dp[m][n];
    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

</details>
