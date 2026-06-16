# 10. Regular Expression Matching

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/regular-expression-matching/)  
`String` `Dynamic Programming` `Recursion`

**Problem Link:** [LeetCode 10 - Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

## Problem

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.

Return a boolean indicating whether the matching covers the entire input string (not partial).

### Example 1

```text
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2

```text
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

### Example 3

```text
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

## Constraints

- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 10. Regular Expression Matching

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
def match(text, pattern):
    if not pattern:
        return not text
    first_match = bool(text) and pattern[0] in {text[0], "."}
    return first_match and match(text[1:], pattern[1:])
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
enum Result {
    TRUE,
    FALSE,
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()) {
            ans = i == text.length();
        } else {
            boolean first_match =
                (i < text.length() &&
                    (pattern.charAt(j) == text.charAt(i) ||
                        pattern.charAt(j) == '.'));

            if (j + 1 < pattern.length() && pattern.charAt(j + 1) == '*') {
                ans = (dp(i, j + 2, text, pattern) ||
                    (first_match && dp(i + 1, j, text, pattern)));
            } else {
                ans = first_match && dp(i + 1, j + 1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def isMatch(self, text: str, pattern: str) -> bool:
        memo = {}

        def dp(i: int, j: int) -> bool:
            if (i, j) not in memo:
                if j == len(pattern):
                    ans = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in {text[i], "."}
                    if j + 1 < len(pattern) and pattern[j + 1] == "*":
                        ans = dp(i, j + 2) or first_match and dp(i + 1, j)
                    else:
                        ans = first_match and dp(i + 1, j + 1)

                memo[i, j] = ans
            return memo[i, j]

        return dp(0, 0)
```

</details>
