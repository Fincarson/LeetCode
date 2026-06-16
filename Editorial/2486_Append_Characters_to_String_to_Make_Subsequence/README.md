# 2486. Append Characters to String to Make Subsequence

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/)  
`Two Pointers` `String` `Greedy`

**Problem Link:** [LeetCode 2486 - Append Characters to String to Make Subsequence](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/)

## Problem

You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

### Example 1

```text
Input: s = "coaching", t = "coding"
Output: 4
Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
Now, t is a subsequence of s ("coachingding").
It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
```

### Example 2

```text
Input: s = "abcde", t = "a"
Output: 0
Explanation: t is already a subsequence of s ("abcde").
```

### Example 3

```text
Input: s = "z", t = "abcde"
Output: 5
Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
Now, t is a subsequence of s ("zabcde").
It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
```

## Constraints

- 1 <= s.length, t.length <= 105
- s and t consist only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Minimum Operations to Make a Subsequence](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2486. Append Characters to String to Make Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy (Two Pointers) | C++, Java, Python3 |

## Approach 1: Greedy (Two Pointers)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, longestPrefix = 0;

        while (first < s.length() && longestPrefix < t.length()) {
            if (s[first] == t[longestPrefix]) {
                // Since at the current position both the characters are equal,
                // increment longestPrefix by 1
                longestPrefix++;
            }
            first++;
        }

        // The number of characters appended is given by the difference in
        // length of t and longestPrefix
        return t.length() - longestPrefix;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int appendCharacters(String s, String t) {
        int first = 0, longestPrefix = 0;

        while (first < s.length() && longestPrefix < t.length()) {
            if (s.charAt(first) == t.charAt(longestPrefix)) {
                // Since at the current position both the characters are equal,
                // increment longestPrefix by 1
                longestPrefix++;
            }
            first++;
        }

        // The number of characters appended is given by the difference in
        // length of t and longestPrefix
        return t.length() - longestPrefix;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        first = 0
        longest_prefix = 0

        while first < len(s) and longest_prefix < len(t):
            if s[first] == t[longest_prefix]:
                # Since at the current position both the characters are equal,
                # increment longest_prefix by 1
                longest_prefix += 1
            first += 1

        # The number of characters appended is given by the difference in length of t
        # and longest_prefix
        return len(t) - longest_prefix
```

</details>
