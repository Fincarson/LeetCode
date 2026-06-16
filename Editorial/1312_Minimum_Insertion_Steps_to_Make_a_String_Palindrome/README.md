# 1312. Minimum Insertion Steps to Make a String Palindrome

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1312 - Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

## Problem

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

### Example 1

```text
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
```

### Example 2

```text
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

### Example 3

```text
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

## Constraints

- 1 <= s.length <= 500
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Moves to Make Palindrome](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1312. Minimum Insertion Steps to Make a String Palindrome

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
    int lcs(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        if (s1[m - 1] == s2[n - 1]) {
            return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        }
        return memo[m][n] = max(lcs(s1, s2, m - 1, n, memo),
                                lcs(s1, s2, m, n - 1, memo));
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());
        vector<vector<int>> memo(n + 1, vector<int>(n + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = -1;
            }
        }

        return n - lcs(s, sReverse, n, n, memo);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int lcs(String s1, String s2, int m, int n, int[][] memo) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
            return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        }
        return (
            memo[m][n] = Math.max(
                lcs(s1, s2, m - 1, n, memo),
                lcs(s1, s2, m, n - 1, memo)
            )
        );
    }

    public int minInsertions(String s) {
        int n = s.length();
        String sReverse = new StringBuilder(s).reverse().toString();
        int[][] memo = new int[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = -1;
            }
        }

        return n - lcs(s, sReverse, n, n, memo);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lcs(self, s1: str, s2: str, m: int, n: int, memo: [[int]]) -> int:
        if memo[m][n] != -1:
            return memo[m][n]
        if s1[m - 1] == s2[n - 1]:
            memo[m][n] = 1 + self.lcs(s1, s2, m - 1, n - 1, memo)
            return memo[m][n]
        memo[m][n] = max(
            self.lcs(s1, s2, m - 1, n, memo), self.lcs(s1, s2, m, n - 1, memo)
        )
        return memo[m][n]

    def minInsertions(self, s: str) -> int:
        n = len(s)
        sReverse = s[::-1]
        memo = [[-1] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            memo[i][0] = 0
            memo[0][i] = 0
        return n - self.lcs(s, sReverse, n, n, memo)
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
    int lcs(string& s1, string& s2, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int lcs(String s1, String s2, int n) {
        int[][] dp = new int[n + 1][n + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }

    public int minInsertions(String s) {
        int n = s.length();
        String sReverse = new StringBuilder(s).reverse().toString();

        return n - lcs(s, sReverse, n);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lcs(self, s1: str, s2: str, n: int) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

        for i in range(n + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif s1[i - 1] == s2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[n][n]

    def minInsertions(self, s: str) -> int:
        n = len(s)
        sReverse = s[::-1]

        return n - self.lcs(s, sReverse, n)
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
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1), dpPrev(n + 1);

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private int lcs(String s1, String s2, int m, int n) {
        int[] dp = new int[n + 1];
        int[] dpPrev = new int[n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = Math.max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp.clone();
        }

        return dp[n];
    }

    public int minInsertions(String s) {
        int n = s.length();
        String sReverse = new StringBuilder(s).reverse().toString();

        return n - lcs(s, sReverse, n, n);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lcs(self, s1, s2, m, n):
        dp = [0] * (n + 1)
        dpPrev = [0] * (n + 1)

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    # One of the two strings is empty.
                    dp[j] = 0
                elif s1[i - 1] == s2[j - 1]:
                    dp[j] = 1 + dpPrev[j - 1]
                else:
                    dp[j] = max(dpPrev[j], dp[j - 1])
            dpPrev = list(dp)

        return dp[n]

    def minInsertions(self, s):
        n = len(s)
        sReverse = s[::-1]

        return n - self.lcs(s, sReverse, n, n)
```

</details>
