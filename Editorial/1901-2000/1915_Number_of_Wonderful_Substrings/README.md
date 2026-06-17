# 1915. Number of Wonderful Substrings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-wonderful-substrings/)  
`Hash Table` `String` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1915 - Number of Wonderful Substrings](https://leetcode.com/problems/number-of-wonderful-substrings/)

## Problem

A wonderful string is a string where at most one letter appears an odd number of times.

- For example, "ccjjc" and "abab" are wonderful, but "ab" is not.

Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

### Example 1

```text
Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
```

### Example 2

```text
Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
```

### Example 3

```text
Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"
```

## Constraints

- 1 <= word.length <= 105
- word consists of lowercase English letters from 'a' to 'j'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1915. Number of Wonderful Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Count Parity Prefixes | Java, Python3 |

## Approach: Count Parity Prefixes

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public long wonderfulSubstrings(String word) {
        int N = word.length();

        // Create the frequency map
        // Key = bitmask, Value = frequency of bitmask key
        Map<Integer, Integer> freq = new HashMap<>();

        // The empty prefix can be the smaller prefix, which is handled like this
        freq.put(0, 1);

        int mask = 0;
        long res = 0L;
        for (int i = 0; i < N; i++) {
            char c = word.charAt(i);
            int bit = c - 'a';

            // Flip the parity of the c-th bit in the running prefix mask
            mask ^= (1 << bit);
            
            // Count smaller prefixes that create substrings with no odd occurring letters
            res += freq.getOrDefault(mask, 0);

            // Increment value associated with mask by 1
            freq.put(mask, freq.getOrDefault(mask, 0) + 1);

            // Loop through every possible letter that can appear an odd number of times in a substring
            for (int odd_c=0; odd_c < 10; odd_c++) {
                res += freq.getOrDefault(mask ^ (1 << odd_c),0);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def wonderfulSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        # Create the frequency map
        # Key = bitmask, Value = frequency of bitmask key
        freq = {}

        # The empty prefix can be the smaller prefix, which is handled like this
        freq[0] = 1

        mask = 0
        res = 0
        for c in word:
            bit = ord(c) - 97

            # Flip the parity of the c-th bit in the running prefix mask
            mask ^= (1 << bit)

            # Count smaller prefixes that create substrings with no odd occurring letters
            if mask in freq:
                res += freq[mask]
                freq[mask] += 1
            else:
                freq[mask] = 1

            # Loop through every possible letter that can appear an odd number of times in a substring
            for odd_c in range(0, 10):
                if (mask ^ (1 << odd_c)) in freq:
                    res += freq[mask ^ (1 << odd_c)]

        return res
```

</details>
