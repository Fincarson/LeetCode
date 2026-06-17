# 647. Palindromic Substrings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/palindromic-substrings/)  
`Two Pointers` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 647 - Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)

## Problem

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

### Example 1

```text
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

### Example 2

```text
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

## Constraints

- 1 <= s.length <= 1000
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 647. Palindromic Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Check All Substrings | C++, Java |
| Dynamic Programming | C++, Java |
| Expand Around Possible Centers | C++, Java |

## Approach 1: Check All Substrings

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi])
                return false;

            ++lo;
            --hi;
        }

        return true;
    }

 public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int lo = 0; lo < s.size(); ++lo)
            for (int hi = lo; hi < s.size(); ++hi)
                ans += isPalindrome(s, lo, hi);

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start) != s.charAt(end)) 
                return false;

            ++start;
            --end;
        }

        return true;
    }

    public int countSubstrings(String s) {
        int ans = 0;

        for (int start = 0; start < s.length(); ++start)
            for (int end = start; end < s.length(); ++end) 
                ans += isPalindrome(s, start, end) ? 1 : 0;

        return ans;
    }
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;

        if (n == 0)
            return 0;

        bool dp[n][n];
        fill_n(*dp, n * n, false);

        // Base case: single letter substrings
        for (int i = 0; i < n; ++i, ++ans)
            dp[i][i] = true;

        // Base case: double letter substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += dp[i][i + 1];
        }

        // All other cases: substrings of length 3 to n
        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                ans += dp[i][j];
            }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countSubstrings(String s) {
        int n = s.length(), ans = 0;

        if (n == 0) 
            return 0;

        boolean[][] dp = new boolean[n][n];

        // Base case: single letter substrings
        for (int i = 0; i < n; ++i, ++ans) 
            dp[i][i] = true;

        // Base case: double letter substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
            ans += (dp[i][i + 1] ? 1 : 0);
        }

        // All other cases: substrings of length 3 to n
        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s.charAt(i) == s.charAt(j));
                ans += (dp[i][j] ? 1 : 0);
            }

        return ans;
    }
}
```

</details>

<br>

## Approach 3: Expand Around Possible Centers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
 public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            // odd-length palindromes, single character center
            ans += countPalindromesAroundCenter(s, i, i);

            // even-length palindromes, consecutive characters center
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }

        return ans;
    }

    int countPalindromesAroundCenter(const string& ss, int lo, int hi) {
        int ans = 0;

        while (lo >= 0 and hi < ss.size()) {
            if (ss[lo] != ss[hi])
                break;      // the first and last characters don't match!

            // expand around the center
            lo--;
            hi++;

            ans++;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countSubstrings(String s) {
        int ans = 0;

        for (int i = 0; i < s.length(); ++i) {
            // odd-length palindromes, single character center
            ans += countPalindromesAroundCenter(s, i, i);

            // even-length palindromes, consecutive characters center
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }

        return ans;
    }

    private int countPalindromesAroundCenter(String ss, int lo, int hi) {
        int ans = 0;

        while (lo >= 0 && hi < ss.length()) {
            if (ss.charAt(lo) != ss.charAt(hi))
                break;      // the first and last characters don't match!

            // expand around the center
            lo--;
            hi++;

            ans++;
        }

        return ans;
    }
}
```

</details>
