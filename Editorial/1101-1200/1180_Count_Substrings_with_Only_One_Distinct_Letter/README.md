# 1180. Count Substrings with Only One Distinct Letter

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/)  
`Math` `String`

**Problem Link:** [LeetCode 1180 - Count Substrings with Only One Distinct Letter](https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/)

## Problem

Given a string s, return the number of substrings that have only one distinct letter.

### Example 1

```text
Input: s = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.
```

### Example 2

```text
Input: s = "aaaaaaaaaa"
Output: 55
```

## Constraints

- 1 <= s.length <= 1000
- s[i] consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1180. Count Substrings with Only One Distinct Letter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Arithmetic Sequence | Java, Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Arithmetic Sequence

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countLetters(String S) {
        int total = 0;
        for (int left = 0, right = 0; right <= S.length(); right++) {
            if (right == S.length() || S.charAt(left) != S.charAt(right)) {
                int lenSubstring = right - left;
                // more details about the sum of the arithmetic sequence:
                // https://en.wikipedia.org/wiki/Arithmetic_progression#Sum
                total += (1 + lenSubstring) * lenSubstring / 2;
                left = right;
            }
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countLetters(self, S: str) -> int:
        total = left = 0

        for right in range(len(S) + 1):
            if right == len(S) or S[left] != S[right]:
                len_substring = right - left
                # more details about the sum of the arithmetic sequence:
                # https://en.wikipedia.org/wiki/Arithmetic_progression#Sum
                total += (1 + len_substring) * len_substring // 2
                left = right
        return total
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countLetters(String S) {
        int substrings[] = new int[S.length()];
        int total = 1;
        substrings[0] = 1;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) == S.charAt(i - 1)) {
                substrings[i] = substrings[i - 1] + 1;
            } else {
                substrings[i] = 1;
            }
            total += substrings[i];
        }
        return total;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countLetters(self, S: str) -> int:
        total = 1
        substrings = [0] * len(S)
        substrings[0] = 1
        for i in range(1, len(S)):
            if S[i - 1] == S[i]:
                substrings[i] = substrings[i-1] + 1
            else:
                substrings[i] = 1
            total += substrings[i]
        return total
```

</details>
