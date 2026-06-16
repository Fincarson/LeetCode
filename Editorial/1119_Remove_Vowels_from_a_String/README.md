# 1119. Remove Vowels from a String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/remove-vowels-from-a-string/)  
`String`

**Problem Link:** [LeetCode 1119 - Remove Vowels from a String](https://leetcode.com/problems/remove-vowels-from-a-string/)

## Problem

Given a string s, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

### Example 1

```text
Input: s = "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
```

### Example 2

```text
Input: s = "aeiou"
Output: ""
```

## Constraints

- 1 <= s.length <= 1000
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1119. Remove Vowels from a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: String | C++, Java |

## Approach: String

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }

    string removeVowels(string s) {
        string ans;

        for (char c : s) {
            if (!isVowel(c)) {
                ans += c;
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
    
    public String removeVowels(String s) {
        StringBuffer ans = new StringBuffer(s.length());
        
        for (int i = 0; i < s.length(); i++) {
            if (!isVowel(s.charAt(i))) {
                ans.append(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
}
```

</details>
