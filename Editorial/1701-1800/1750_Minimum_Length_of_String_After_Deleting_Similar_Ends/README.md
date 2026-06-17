# 1750. Minimum Length of String After Deleting Similar Ends

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 1750 - Minimum Length of String After Deleting Similar Ends](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/)

## Problem

Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Return the minimum length of s after performing the above operation any number of times (possibly zero times).

### Example 1

```text
Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.
```

### Example 2

```text
Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".
```

### Example 3

```text
Input: s = "aabccabba"
Output: 3
Explanation: An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
```

## Constraints

- 1 <= s.length <= 105
- s only consists of characters 'a', 'b', and 'c'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1750. Minimum Length of String After Deleting Similar Ends

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, Java, Python3 |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumLength(string s) {
        int begin = 0;
        int end = s.length() - 1;

        // Delete similar ends until the ends differ or they meet in the middle
        while (begin < end && s[begin] == s[end]) {
            char c = s[begin];

            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s[begin] == c) {
                begin++;
            }

            // Delete consecutive occurrences of c from suffix
            while (end > begin && s[end] == c) {
                end--;
            }
        }

        // Return the number of remaining characters
        return end - begin + 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int minimumLength(String s) {
        int begin = 0;
        int end = s.length() - 1;

        // Delete similar ends until the ends differ or they meet in the middle
        while (begin < end && s.charAt(begin) == s.charAt(end)) {
            char c = s.charAt(begin);

            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s.charAt(begin) == c) {
                begin++;
            }

            // Delete consecutive occurrences of c from suffix
            while (end > begin && s.charAt(end) == c) {
                end--;
            }
        }

        // Return the number of remaining characters
        return end - begin + 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumLength(self, s: str) -> int:
        begin = 0
        end = len(s) - 1

        # Delete similar ends until the ends differ or they meet in the middle
        while begin < end and s[begin] == s[end]:
            c = s[begin]

            # Delete consecutive occurrences of c from prefix
            while begin <= end and s[begin] == c:
                begin += 1

            # Delete consecutive occurrences of c from suffix
            while end > begin and s[end] == c:
                end -= 1

        # Return the number of remaining characters
        return end - begin + 1
```

</details>
