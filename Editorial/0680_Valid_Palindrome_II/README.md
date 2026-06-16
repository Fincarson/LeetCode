# 680. Valid Palindrome II

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/valid-palindrome-ii/)  
`Two Pointers` `String` `Greedy`

**Problem Link:** [LeetCode 680 - Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)

## Problem

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

### Example 1

```text
Input: s = "aba"
Output: true
```

### Example 2

```text
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

### Example 3

```text
Input: s = "abc"
Output: false
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Valid Palindrome IV](https://leetcode.com/problems/valid-palindrome-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 680. Valid Palindrome II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Two Pointers | Java, Python3 |

## Approach: Two Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
boolean checkPalindrome(String s, int i, int j) {
    while (i < j) {
        if (s.charAt(i) != s.charAt(j)) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def check_palindrome(s, i, j):
    while i < j:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
    
    return True
```

</details>
