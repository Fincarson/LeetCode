# 516. Longest Palindromic Subsequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-palindromic-subsequence/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 516 - Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)

## Problem

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

### Example 1

```text
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

### Example 2

```text
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

## Constraints

- 1 <= s.length <= 1000
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Palindromic Subsequence II](https://leetcode.com/problems/longest-palindromic-subsequence-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximize Palindrome Length From Subsequences](https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 516. Longest Palindromic Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming | C++, Java, Python3 |
| Iterative Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming with Space Optimization | C++, Java, Python3 |

## Approach 1: Recursive Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n));
        return lps(s, 0, n - 1, memo);
    }

    int lps(string s, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }

        if (s[i] == s[j]) {
            memo[i][j] = lps(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = max(lps(s, i + 1, j, memo), lps(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] memo = new int[n][n];
        return lps(s, 0, n - 1, memo);
    }

    private int lps(String s, int i, int j, int[][] memo) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }

        if (s.charAt(i) == s.charAt(j)) {
            memo[i][j] = lps(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = Math.max(lps(s, i + 1, j, memo), lps(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        
        memo = {}
        def lps(l, r):
            if (l,r) in memo:
                return memo[(l,r)]
            if l > r:
                return 0
            if l == r:
                return 1

            if s[l] == s[r]:
                memo[(l,r)] = lps(l + 1, r - 1) + 2
            else:
                memo[(l,r)] = max(lps(l, r - 1), lps(l + 1, r))
            return memo[(l, r)]

        return lps(0, n - 1)
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()];

        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.length() - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

        return dp[0][n - 1]
```

</details>

<br>

## Approach 3: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n), dpPrev(n);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[j] = dpPrev[j - 1] + 2;
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n - 1];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[] dp = new int[n];
        int[] dpPrev = new int[n];

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[j] = dpPrev[j - 1] + 2;
                } else {
                    dp[j] = Math.max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp.clone();
        }

        return dp[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp, dpPrev = [0] * n, [0] * n

        for i in range(n - 1, -1, -1):
            dp[i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[j] = dpPrev[j - 1] + 2
                else:
                    dp[j] = max(dpPrev[j], dp[j - 1])
            dpPrev = dp[:]

        return dp[n - 1]
```

</details>
