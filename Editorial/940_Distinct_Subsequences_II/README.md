# 940. Distinct Subsequences II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/distinct-subsequences-ii/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 940 - Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)

## Problem

Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
```

### Example 2

```text
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
```

### Example 3

```text
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
```

## Constraints

- 1 <= s.length <= 2000
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Unique Good Subsequences](https://leetcode.com/problems/number-of-unique-good-subsequences/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count K-Subsequences of a String With Maximum Beauty](https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 940. Distinct Subsequences II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int MOD = 1e9 + 7;
        
        vector<int> dp(N+1);
        dp[0] = 1;
        vector<int> last(26, -1);
        
        for(int i = 0; i < N; i++){
            int x = s[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if(last[x] >= 0) // if this is the first occurence of ch
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }
        dp[N]--;
        if(dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int distinctSubseqII(String S) {
        int MOD = 1_000_000_007;
        int N = S.length();
        int[] dp = new int[N+1];
        dp[0] = 1;

        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = 0; i < N; ++i) {
            int x = S.charAt(i) - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[x] >= 0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def distinctSubseqII(self, S):
        dp = [1]
        last = {}
        for i, x in enumerate(S):
            dp.append(dp[-1] * 2)
            if x in last:
                dp[-1] -= dp[last[x]]
            last[x] = i

        return (dp[-1] - 1) % (10**9 + 7)
```

</details>
