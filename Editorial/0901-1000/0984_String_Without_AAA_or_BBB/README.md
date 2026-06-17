# 984. String Without AAA or BBB

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/string-without-aaa-or-bbb/)  
`String` `Greedy`

**Problem Link:** [LeetCode 984 - String Without AAA or BBB](https://leetcode.com/problems/string-without-aaa-or-bbb/)

## Problem

Given two integers a and b, return any string s such that:

- s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
- The substring 'aaa' does not occur in s, and
- The substring 'bbb' does not occur in s.

### Example 1

```text
Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
```

### Example 2

```text
Input: a = 4, b = 1
Output: "aabaa"
```

## Constraints

- 0 <= a, b <= 100
- It is guaranteed such an s exists for the given a and b.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 984. String Without AAA or BBB

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | Java, Python |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String strWithout3a3b(int A, int B) {
        StringBuilder ans = new StringBuilder();

        while (A > 0 || B > 0) {
            boolean writeA = false;
            int L = ans.length();
            if (L >= 2 && ans.charAt(L-1) == ans.charAt(L-2)) {
                if (ans.charAt(L-1) == 'b')
                    writeA = true;
            } else {
                if (A >= B)
                    writeA = true;
            }

            if (writeA) {
                A--;
                ans.append('a');
            } else {
                B--;
                ans.append('b');
            }
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
    def strWithout3a3b(self, A, B):
        ans = []

        while A or B:
            if len(ans) >= 2 and ans[-1] == ans[-2]:
                writeA = ans[-1] == 'b'
            else:
                writeA = A >= B

            if writeA:
                A -= 1
                ans.append('a')
            else:
                B -= 1
                ans.append('b')

        return "".join(ans)
```

</details>
