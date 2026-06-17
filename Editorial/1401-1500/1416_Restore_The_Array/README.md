# 1416. Restore The Array

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/restore-the-array/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1416 - Restore The Array](https://leetcode.com/problems/restore-the-array/)

## Problem

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
```

### Example 2

```text
Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
```

### Example 3

```text
Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
```

## Constraints

- 1 <= s.length <= 105
- s consists of only digits and does not contain leading zeros.
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Separate Numbers](https://leetcode.com/problems/number-of-ways-to-separate-numbers/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Number of Beautiful Partitions](https://leetcode.com/problems/number-of-beautiful-partitions/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1416. Restore The Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Top Down) | Java, Python3 |
| Dynamic Programming (Bottom Up) | Java, Python3 |
| Dynamic Programming (with less space complexity) | Java, Python3 |

## Approach 1: Dynamic Programming (Top Down)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int mod = 1_000_000_007;

    // Number of possible splits for substring s[start ~ m-1].
    private int dfs(int[] dp, int start, String s, int k) {
        // If we have already updated dp[start], return it.
        if (dp[start] != 0)
            return dp[start];

        // There is only 1 split for an empty string.
        if (start == s.length())
            return 1;

        // Number can't have leading zeros.
        if (s.charAt(start) == '0')
            return 0;

        // For all possible starting number, add the number of arrays 
        // that can be printed as the remaining string to count.
        int count = 0;
        for (int end = start; end < s.length(); ++end) {
            String currNumber = s.substring(start, end + 1);
            if (Long.parseLong(currNumber) > k)
                break;
            count = (count + dfs(dp, end + 1, s, k)) % mod;
        }

        // Update dp[start] so we don't recalculate it later.
        dp[start] = count;
        return count;
    }
    
    public int numberOfArrays(String s, int k) {
        int m = s.length();
        int[] dp = new int[m + 1];
        return dfs(dp, 0, s, k);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7   
        dp = [0] * (m + 1)
        
        # Number of possible splits for s[start ~ m-1].
        def dfs(start):
            # If we have already updated dp[start], return it.
            if dp[start]:
                return dp[start]
            
            # There is only 1 split for an empty string.
            if start == m:
                return 1
            
            # Number can't have leading zeros.
            if s[start] == '0':
                return 0
            
            # For all possible starting number, add the number of arrays 
            # that can be printed as the remaining string to count.
            count = 0
            for end in range(start, m):
                curr_number = s[start: end + 1]
                if int(curr_number) > k:
                    break
                count += dfs(end + 1)
                
            # Update dp[start] so we don't recalculate it later.
            dp[start] = count % mod
            return count
        
        return dfs(0) % mod
```

</details>

<br>

## Approach 2: Dynamic Programming (Bottom Up)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfArrays(String s, int k) {
        int m = s.length(), n = String.valueOf(k).length();
        int mod = 1_000_000_007;
        
        // dp[i] records the number of arrays that can be printed as
        // the prefix substring s[0 ~ i - 1]
        int[] dp = new int[m + 1];
        
        // Empty string has 1 valid split.
        dp[0] = 1;
        
        // Iterate over every digit, for each digit s[start]
        for (int start = 0; start < m; ++start) {
            if (s.charAt(start) == '0')
                continue;
            
            // Iterate over ending digit end and find all valid numbers 
            // s[start ~ end].
            for (int end = start; end < m; ++end) {
                String currNumber = s.substring(start, end + 1);
                
                if (Long.parseLong(currNumber) > k)
                    break;
                
                // If s[start ~ end] is valid, increment dp[end + 1] by dp[start].
                dp[end + 1] = (dp[end + 1] + dp[start]) % mod;
            }
        }
        return dp[m];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7
        
        # dp[i] records the number of arrays that can be printed as
        # the prefix substring s[0 ~ i - 1]
        dp = [1] + [0] * m
        
        # Iterate over every digit, for each digit s[start]:
        for start in range(m):
            if s[start] == '0':
                continue            
            count = 0
    
            # Iterate over ending digit end and find all valid numbers 
            # s[start ~ end].
            for end in range(start, m):  
                curr_number = s[start:end + 1]
                if int(curr_number) > k:
                    break
                
                # If s[start ~ end] is valid, increment dp[end + 1] by dp[start].
                dp[end + 1] += dp[start]
                dp[end + 1] %= mod
                    
        return dp[-1]
```

</details>

<br>

## Approach 3: Dynamic Programming (with less space complexity)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numberOfArrays(String s, int k) {
        int m = s.length(), n = String.valueOf(k).length();
        int mod = 1_000_000_007;
        
        // dp[i % (n + 1)] stands for the number of splits for substring s[0 ~ i - 1]
        int[] dp = new int[n + 1];
        
        // Empty string has 1 valid split.
        dp[0] = 1;
        
        // Iterate over every digit, for each digit s[start]
        for (int start = 0; start < m; ++start) {
            if (s.charAt(start) == '0') {
                dp[start % (n + 1)] = 0;
                continue;
            }
            
            // We travers forward to find all valid numbers s[start ~ end].
            for (int end = start; end < m; ++end) {
                String currNumber = s.substring(start, end + 1);
                
                if (Long.parseLong(currNumber) > k)
                    break;
                
                // If s[start ~ end] is valid, increment dp[(end + 1) % (n + 1)] by dp[start].
                dp[(end + 1) % (n + 1)] = (dp[(end + 1) % (n + 1)] + dp[start % (n + 1)]) % mod;
            }

            // Set dp[start % (n + 1)] as 0.
            dp[start % (n + 1)] = 0;
        }
        return dp[m % (n + 1)];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        m, n = len(s), len(str(k))
        mod = 10 ** 9 + 7
        # dp[i % (n + 1)] records the number of arrays that can be printed as
        # the prefix substring s[0 ~ i - 1]
        dp = [1] + [0] * n
        
        # Iterate over every digit, for each digit s[start]:
        for start in range(m):
            if s[start] == '0':
                dp[start % (n + 1)] = 0
                continue
            
            # Iterate over ending digit end and find all valid numbers 
            # s[start ~ end].
            for end in range(start, m):
                if int(s[start : end + 1]) > k:
                    break

                # If s[start ~ end] is valid, increment dp[(end + 1) % (n + 1)] by dp[start].
                dp[(end + 1) % (n + 1)] += dp[start % (n + 1)]
                dp[(end + 1) % (n + 1)] %= mod
            
            # Set dp[start % (n + 1)] as 0.
            dp[start % (n + 1)] = 0

        return dp[m % (n + 1)]
```

</details>
