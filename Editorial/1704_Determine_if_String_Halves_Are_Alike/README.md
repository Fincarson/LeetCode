# 1704. Determine if String Halves Are Alike

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/determine-if-string-halves-are-alike/)  
`String` `Counting`

**Problem Link:** [LeetCode 1704 - Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/)

## Problem

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

### Example 1

```text
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
```

### Example 2

```text
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
```

## Constraints

- 2 <= s.length <= 1000
- s.length is even.
- s consists of uppercase and lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1704. Determine if String Halves Are Alike

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Vowels | C++, Java, Python3 |

## Approach 1: Count Vowels

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        string vowels = "aeiouAEIOU";
        string a = s.substr(0, n / 2);
        string b = s.substr(n / 2);

        int aVowelCount = 0;
        for (auto c : a) {
            if (vowels.find(c) != string::npos) {
                aVowelCount++;
            }
        }

        int bVowelCount = 0;
        for (auto c : b) {
            if (vowels.find(c) != string::npos) {
                bVowelCount++;
            }
        }

        return aVowelCount == bVowelCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();

        String vowels = "aeiouAEIOU";
        String a = s.substring(0, n / 2);
        String b = s.substring(n / 2, n);

        int aVowelCount = 0;
        for (char c : a.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                aVowelCount++;
            }
        }

        int bVowelCount = 0;
        for (char c : b.toCharArray()) {
            if (vowels.indexOf(c) != -1) {
                bVowelCount++;
            }
        }

        return aVowelCount == bVowelCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)

        a = s[:n//2]
        b = s[n//2:]

        a_vowel_count = 0
        for c in a:
            if c in "aeiouAEIOU":
                a_vowel_count += 1

        b_vowel_count = 0
        for c in b:
            if c in "aeiouAEIOU":
                b_vowel_count += 1

        return a_vowel_count == b_vowel_count
```

</details>
