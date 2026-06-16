# 634. Find the Derangement of An Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-derangement-of-an-array/)  
`Math` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 634 - Find the Derangement of An Array](https://leetcode.com/problems/find-the-derangement-of-an-array/)

## Problem

In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

You are given an integer n. There is originally an array consisting of n integers from 1 to n in ascending order, return the number of derangements it can generate. Since the answer may be huge, return it modulo 109 + 7.

### Example 1

```text
Input: n = 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
```

### Example 2

```text
Input: n = 2
Output: 1
```

## Constraints

- 1 <= n <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 634. Find the Derangement of An Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Java |
| Dynamic Programming | Java |
| Constant Space Dynamic Programming | Java |
| Formula | Java |

## Approach 2: Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findDerangement(int n) {
        Integer[] memo = new Integer[n + 1];
        return find(n, memo);
    }
    
    public int find(int n, Integer[] memo) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        if (memo[n] != null)
            return memo[n];
        memo[n] = (int)(((n - 1L) * (find(n - 1, memo) + find(n - 2, memo))) % 1000000007);
        return memo[n];
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
    public int findDerangement(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
            dp[i] = (int)(((i - 1L) * (dp[i - 1] + dp[i - 2])) % 1000000007);
        return dp[n];
    }
}
```

</details>

<br>

## Approach 4: Constant Space Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findDerangement(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        int first = 1, second = 0;
        for (int i = 2; i <= n; i++) {
            int temp = second;
            second = (int)(((i - 1L) * (first + second)) % 1000000007);
            first = temp;
        }
        return second;
    }
}
```

</details>

<br>

## Approach 5: Formula

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findDerangement(int n) {
        long mul = 1, sum = 0, M = 1000000007;
        for (int i = n; i >= 0; i--) {
            sum = (sum + M + mul * (i % 2 == 0 ? 1 : -1)) % M;
            mul = (mul * i) % M;
        }
        return (int) sum;
    }
}
```

</details>
