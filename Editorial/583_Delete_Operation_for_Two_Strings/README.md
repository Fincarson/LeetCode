# 583. Delete Operation for Two Strings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/delete-operation-for-two-strings/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 583 - Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/)

## Problem

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

### Example 1

```text
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

### Example 2

```text
Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

## Constraints

- 1 <= word1.length, word2.length <= 500
- word1 and word2 consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Edit Distance](https://leetcode.com/problems/edit-distance/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Make Three Strings Equal](https://leetcode.com/problems/make-three-strings-equal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 583. Delete Operation for Two Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using Longest Common Subsequence [Time Limit Exceeded] | Java |
| Approach #2 Longest Common Subsequence with Memoization [Accepted] | Java |
| Approach #3 Using Longest Common Subsequence- Dynamic Programming [Accepted] | Java |
| Approach #4 Without using LCS Dynamic Programmming [Accepted]: | Java |
| Approach #5 1-D Dynamic Programming [Accepted]: | Java |

## Approach #1 Using Longest Common Subsequence [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public int minDistance(String s1, String s2) {
        return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length());
    }
    public int lcs(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return 1 + lcs(s1, s2, m - 1, n - 1);
        else
            return Math.max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
}
```

</details>

<br>

## Approach #2 Longest Common Subsequence with Memoization [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] memo = new int[s1.length() + 1][s2.length() + 1];
        return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length(), memo);
    }
    public int lcs(String s1, String s2, int m, int n, int[][] memo) {
        if (m == 0 || n == 0)
            return 0;
        if (memo[m][n] > 0)
            return memo[m][n];
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        else
            memo[m][n] = Math.max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));
        return memo[m][n];
    }
}
```

</details>

<br>

## Approach #3 Using Longest Common Subsequence- Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    continue;
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return s1.length() + s2.length() - 2 * dp[s1.length()][s2.length()];
    }
}
```

</details>

<br>

## Approach #4 Without using LCS Dynamic Programmming [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minDistance(String s1, String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
}
```

</details>

<br>

## Approach #5 1-D Dynamic Programming [Accepted]:

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minDistance(String s1, String s2) {
        int[] dp = new int[s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            int[] temp=new int[s2.length()+1];
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    temp[j] = i + j;
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + Math.min(dp[j], temp[j - 1]);
            }
            dp=temp;
        }
        return dp[s2.length()];
    }
}
```

</details>
