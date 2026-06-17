# 761. Special Binary String

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/special-binary-string/)  
`String` `Divide and Conquer` `Sorting`

**Problem Link:** [LeetCode 761 - Special Binary String](https://leetcode.com/problems/special-binary-string/)

## Problem

Special binary strings are binary strings with the following two properties:

- The number of 0's is equal to the number of 1's.
- Every prefix of the binary string has at least as many 1's as 0's.

You are given a special binary string s.

A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

### Example 1

```text
Input: s = "11011000"
Output: "11100100"
Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
```

### Example 2

```text
Input: s = "10"
Output: "10"
```

## Constraints

- 1 <= s.length <= 50
- s[i] is either '0' or '1'.
- s is a special binary string.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Good Binary Strings](https://leetcode.com/problems/number-of-good-binary-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 761. Special Binary String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Recursion [Accepted] | Java, Python |

## Approach #1: Recursion [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String makeLargestSpecial(String S) {
        if (S.length() == 0) return S;
        int anchor = 0, bal = 0;
        List<String> mountains = new ArrayList();
        for (int i = 0; i < S.length(); ++i) {
            bal += S.charAt(i) == '1' ? 1 : -1;
            if (bal == 0) {
                mountains.add("1" + makeLargestSpecial(S.substring(anchor+1, i)) + "0");
                anchor = i+1;
            }
        }
        Collections.sort(mountains, Collections.reverseOrder());
        StringBuilder ans = new StringBuilder();
        for (String mtn: mountains)
            ans.append(mtn);
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def makeLargestSpecial(self, S):
        if not S: return S
        mountains = []
        anchor = bal = 0
        for i, x in enumerate(S):
            bal += 1 if x == '1' else -1
            if bal == 0:
                mountains.append("1{}0".format(
                    self.makeLargestSpecial(S[anchor+1: i])))
                anchor = i+1

        mountains.sort(reverse = True)
        return "".join(mountains)
```

</details>
