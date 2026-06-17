# 2370. Longest Ideal Subsequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-ideal-subsequence/)  
`Hash Table` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 2370 - Longest Ideal Subsequence](https://leetcode.com/problems/longest-ideal-subsequence/)

## Problem

You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

- t is a subsequence of the string s.
- The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.

Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

### Example 1

```text
Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
```

### Example 2

```text
Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
```

## Constraints

- 1 <= s.length <= 105
- 0 <= k <= 25
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2370. Longest Ideal Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming (Top Down) | C++, Java, Python3 |
| Iterative Dynamic Programming (Bottom Up, Space Optimized) | C++, Java, Python3 |

## Approach 1: Recursive Dynamic Programming (Top Down)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = size(s);
        vector<vector<int>> dp(N, vector<int>(26, -1));

        // Find the maximum dp[N-1][c] and return the result
        int res = 0;
        for (int c = 0; c < 26; c++) {
            res = max(res, dfs(N - 1, c, dp, s, k));
        }
        return res;
    }

    int dfs(int i, int c, vector<vector<int>>& dp, string& s, int k) {
        // Memoized value
        if (dp[i][c] != -1) {
            return dp[i][c];
        }

        // State is not visited yet
        dp[i][c] = 0;
        bool match = c == (s[i] - 'a');
        if (match) {
            dp[i][c] = 1;
        }

        // Non base case handling
        if (i > 0) {
            dp[i][c] = dfs(i - 1, c, dp, s, k);
            if (match) {
                for (int p = 0; p < 26; p++) {
                    if (abs(c - p) <= k) {
                        dp[i][c] = max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1);
                    }
                }
            }
        }
        return dp[i][c];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestIdealString(String s, int k) {
        int N = s.length();

        // Initialize all dp values to -1 to indicate non-visited states
        int[][] dp = new int[N][26];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }

        // Find the maximum dp[N-1][c] and return the result
        int res = 0;
        for (int c = 0; c < 26; c++) {
            res = Math.max(res, dfs(N - 1, c, dp, s, k));
        }
        return res;
    }

    public int dfs(int i, int c, int[][] dp, String s, int k) {
        // Memoized value
        if (dp[i][c] != -1) {
            return dp[i][c];
        }

        // State is not visited yet
        dp[i][c] = 0;
        boolean match = c == (s.charAt(i) - 'a');
        if (match) {
            dp[i][c] = 1;
        }

        // Non base case handling
        if (i > 0) {
            dp[i][c] = dfs(i - 1, c, dp, s, k);
            if (match) {
                for (int p = 0; p < 26; p++) {
                    if (Math.abs(c - p) <= k) {
                        dp[i][c] = Math.max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1);
                    }
                }
            }
        }
        return dp[i][c];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        N = len(s)

        # Initialize all dp values to -1 to indicate non-visited states
        dp = [[-1] * 26 for _ in range(N)]

        def dfs(i: int, c: int, dp: list, s: str, k: int) -> int:
            # Memoized value
            if dp[i][c] != -1:
                return dp[i][c]

            # State is not visited yet
            dp[i][c] = 0
            match = c == (ord(s[i]) - ord('a'))
            if match:
                dp[i][c] = 1

            # Non base case handling
            if i > 0:
                dp[i][c] = dfs(i - 1, c, dp, s, k)
                if match:
                    for p in range(26):
                        if abs(c - p) <= k:
                            dp[i][c] = max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1)
            return dp[i][c]

        # Find the maximum dp[N-1][c] and return the result
        res = 0
        for c in range(26):
            res = max(res, dfs(N - 1, c, dp, s, k))
        return res
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming (Bottom Up, Space Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = s.size();
        vector<int> dp(26, 0);

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = max(0, curr - k); prev < min(26, curr + k + 1); prev++) {
                best = max(best, dp[prev]);
            }

            // Append s[i] to the previous longest ideal subsequence
            dp[curr] = best + 1;
            res = max(res, dp[curr]);
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestIdealString(String s, int k) {
        int N = s.length();
        int[] dp = new int[26];

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s.charAt(i) - 'a';
            int best = 0;
            for (int prev = Math.max(0, curr - k); prev < Math.min(26, curr + k + 1); prev++) {
                best = Math.max(best, dp[prev]);
            }

            // Append s[i] to the previous longest ideal subsequence
            dp[curr] = best + 1;
            res = Math.max(res, dp[curr]);
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        N = len(s)
        dp = [0] * 26

        res = 0
        # Updating dp with the i-th character
        for i in range(N):
            curr = ord(s[i]) - ord('a')
            best = 0
            for prev in range(max(0, curr - k), min(26, curr + k + 1)):
                    best = max(best, dp[prev])

            # Append s[i] to the previous longest ideal subsequence
            dp[curr] =  best + 1
            res = max(res, dp[curr])

        return res
```

</details>
