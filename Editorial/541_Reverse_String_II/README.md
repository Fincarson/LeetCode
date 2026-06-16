# 541. Reverse String II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/reverse-string-ii/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 541 - Reverse String II](https://leetcode.com/problems/reverse-string-ii/)

## Problem

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

### Example 1

```text
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
```

### Example 2

```text
Input: s = "abcd", k = 2
Output: "bacd"
```

## Constraints

- 1 <= s.length <= 104
- s consists of only lowercase English letters.
- 1 <= k <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse String](https://leetcode.com/problems/reverse-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Faulty Keyboard](https://leetcode.com/problems/faulty-keyboard/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 541. Reverse String II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Direct [Accepted] | Java, Python |

## Approach #1: Direct [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String reverseStr(String s, int k) {
        char[] a = s.toCharArray();
        for (int start = 0; start < a.length; start += 2 * k) {
            int i = start, j = Math.min(start + k - 1, a.length - 1);
            while (i < j) {
                char tmp = a[i];
                a[i++] = a[j];
                a[j--] = tmp;
            }
        }
        return new String(a);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reverseStr(self, s, k):
        a = list(s)
        for i in xrange(0, len(a), 2*k):
            a[i:i+k] = reversed(a[i:i+k])
        return "".join(a)
```

</details>
