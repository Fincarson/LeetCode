# 1531. String Compression II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/string-compression-ii/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1531 - String Compression II](https://leetcode.com/problems/string-compression-ii/)

## Problem

Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

### Example 1

```text
Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
```

### Example 2

```text
Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
```

### Example 3

```text
Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
```

## Constraints

- 1 <= s.length <= 100
- 0 <= k <= s.length
- s contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [String Compression III](https://leetcode.com/problems/string-compression-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1531. String Compression II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private Map<Integer, Integer> memo = new HashMap<>();
    private Set<Integer> add = Set.of(1, 9, 99);

    public int getLengthOfOptimalCompression(String s, int k) {
        return dp(s, 0, (char) ('a' + 26), 0, k);
    }

    private int dp(String s, int idx, char lastChar, int lastCharCount, int k) {
        if (k < 0) {
            return Integer.MAX_VALUE / 2;
        }

        if (idx == s.length()) {
            return 0;
        }

        int key = idx * 101 * 27 * 101 + (lastChar - 'a') * 101 * 101 + lastCharCount * 101 + k;

        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int keepChar;
        int deleteChar = dp(s, idx + 1, lastChar, lastCharCount, k - 1);
        if (s.charAt(idx) == lastChar) {
            keepChar = dp(s, idx + 1, lastChar, lastCharCount + 1, k) + (add.contains(lastCharCount) ? 1 : 0);
        } else {
            keepChar = dp(s, idx + 1, s.charAt(idx), 1, k) + 1;
        }
        int res = Math.min(keepChar, deleteChar);
        memo.put(key, res);

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def dp(idx, last_char, last_char_count, k):
            if k < 0:
                return float('inf')
            if idx == n:
                return 0
            
            delete_char = dp(idx + 1, last_char, last_char_count, k - 1)
            if s[idx] == last_char:
                keep_char = dp(idx + 1, last_char, last_char_count + 1, k) + (last_char_count in [1, 9, 99])
            else:
                keep_char = dp(idx + 1, s[idx], 1, k) + 1
            
            return min(keep_char, delete_char)
        
        n = len(s)
        return dp(0, "", 0, k)
```

</details>
