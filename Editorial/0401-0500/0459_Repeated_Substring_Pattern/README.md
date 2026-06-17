# 459. Repeated Substring Pattern

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/repeated-substring-pattern/)  
`String` `String Matching`

**Problem Link:** [LeetCode 459 - Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/)

## Problem

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

### Example 1

```text
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
```

### Example 2

```text
Input: s = "aba"
Output: false
```

### Example 3

```text
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
```

## Constraints

- 1 <= s.length <= 104
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Repeated String Match](https://leetcode.com/problems/repeated-string-match/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 459. Repeated Substring Pattern

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Divisors | C++, Java, Python3 |
| String Concatenation | C++, Java, Python3 |

## Approach 1: Using Divisors

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                string pattern = "";
                for (int j = 0; j < n / i; j++) {
                    pattern += s.substr(0, i);
                }
                if (s == pattern) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                StringBuilder pattern = new StringBuilder();
                for (int j = 0; j < n / i; j++) {
                    pattern.append(s.substring(0, i));
                }
                if (s.equals(pattern.toString())) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n // 2 + 1):
            if n % i == 0:
                pattern = s[:i] * (n // i)
                if s == pattern:
                    return True
        return False
```

</details>

<br>

## Approach 2: String Concatenation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String t = s + s;
        if (t.substring(1, t.length() - 1).contains(s))
            return true;
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        t = s + s
        if s in t[1:-1]:
            return True
        return False
```

</details>
