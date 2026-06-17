# 2466. Count Ways To Build Good Strings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-ways-to-build-good-strings/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 2466 - Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings/)

## Problem

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

- Append the character '0' zero times.
- Append the character '1' one times.

This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

### Example 1

```text
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.
```

### Example 2

```text
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
```

## Constraints

- 1 <= low <= high <= 105
- 1 <= zero, one <= low

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2466. Count Ways To Build Good Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Iterative). | Java, Python3 |
| Dynamic Programming (Recursive) | Java, Python3 |

## Approach 1: Dynamic Programming (Iterative).

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        // Use dp[i] to record to number of good strings of length i.
        int[] dp = new int[high + 1];
        dp[0] = 1;
        int mod = 1_000_000_007;
        
        // Iterate over each length `end`.
        for (int end = 1; end <= high; ++end) {
            // check if the current string can be made by append zero `0`s or one `1`s.
            if (end >= zero) {
                dp[end] += dp[end - zero];
            }
            if (end >= one) {
                dp[end] += dp[end - one];
            }
            dp[end] %= mod;
        }
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int i = low; i <= high; ++i) {
            answer += dp[i];
            answer %= mod;
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # Use dp[i] to record to number of good strings of length i.
        dp = [1] + [0] * (high)
        mod = 10 ** 9 + 7
        
        # Iterate over each length `end`.
        for end in range(1, high + 1):
            # check if the current string can be made by append zero `0`s or one `1`s.
            if end >= zero:
                dp[end] += dp[end - zero]
            if end >= one:
                dp[end] += dp[end - one]
            dp[end] %= mod
        
        # Add up the number of strings with each valid length [low ~ high].
        return sum(dp[low : high + 1]) % mod
```

</details>

<br>

## Approach 2: Dynamic Programming (Recursive)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Use dp[i] to record to number of good strings of length i.
    int[] dp;
    int mod = 1_000_000_007;
    
    // Find the number of good strings of length `end`.
    private int dfs(int end, int zero, int one) {
        if (dp[end] != -1)
            return dp[end];
        int count = 0;
        if (end >= one) {
            count += dfs(end - one, zero, one);
        }
        if (end >= zero) {
            count += dfs(end - zero, zero, one);
        }
        dp[end] = count % mod;
        return dp[end];
    }
    
    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new int[high + 1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int end = low; end <= high; ++end) {
            answer += dfs(end, zero, one);
            answer %= mod;
        }
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # Use dp[i] to record to number of good strings of length i.
        dp = [1] + [-1] * (high)
        mod = 10 ** 9 + 7
        
        # Find the number of good strings of length `end`.
        def dfs(end):
            if dp[end] != -1:
                return dp[end]
            count = 0
            if end >= zero:
                count += dfs(end - zero)
            if end >= one:
                count += dfs(end - one)
            dp[end] = count % mod
            return dp[end]
            
        
        # Add up the number of strings with each valid length [low ~ high].
        return sum(dfs(end) for end in range(low, high + 1)) % mod
```

</details>
