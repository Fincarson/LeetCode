# 848. Shifting Letters

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/shifting-letters/)  
`Array` `String` `Prefix Sum`

**Problem Link:** [LeetCode 848 - Shifting Letters](https://leetcode.com/problems/shifting-letters/)

## Problem

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

- For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

### Example 1

```text
Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
```

### Example 2

```text
Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- shifts.length == s.length
- 0 <= shifts[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Replace All Digits with Characters](https://leetcode.com/problems/replace-all-digits-with-characters/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Shifting Letters II](https://leetcode.com/problems/shifting-letters-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Lexicographically Smallest String After Substring Operation](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shift Distance Between Two Strings](https://leetcode.com/problems/shift-distance-between-two-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find the K-th Character in String Game II](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 848. Shifting Letters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Prefix Sum [Accepted] | Java, Python |

## Approach #1: Prefix Sum [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        StringBuilder ans = new StringBuilder();
        int X = 0;
        for (int shift: shifts)
            X = (X + shift) % 26;

        for (int i = 0; i < S.length(); ++i) {
            int index = S.charAt(i) - 'a';
            ans.append((char) ((index + X) % 26 + 97));
            X = Math.floorMod(X - shifts[i], 26);
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def shiftingLetters(self, S, shifts):
        ans = []
        X = sum(shifts) % 26
        for i, c in enumerate(S):
            index = ord(c) - ord('a')
            ans.append(chr(ord('a') + (index + X) % 26))
            X = (X - shifts[i]) % 26

        return "".join(ans)
```

</details>
