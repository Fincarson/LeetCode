# 345. Reverse Vowels of a String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-vowels-of-a-string/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 345 - Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)

## Problem

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 3 * 105
- s consist of printable ASCII characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse String](https://leetcode.com/problems/reverse-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Remove Vowels from a String](https://leetcode.com/problems/remove-vowels-from-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Faulty Keyboard](https://leetcode.com/problems/faulty-keyboard/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sort Vowels in a String](https://leetcode.com/problems/sort-vowels-in-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 345. Reverse Vowels of a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, Java |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    // Return true if the character is a vowel (case-insensitive)
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        int start = 0;
        int end  = s.size() - 1;
        
        // While we still have characters to traverse
        while (start < end) {
            // Find the leftmost vowel
            while (start < s.size() && !isVowel(s[start])) {
                start++;
            }
            // Find the rightmost vowel
            while (end >= 0 && !isVowel(s[end])) {
                end--;
            }
            // Swap them if start is left of end
            if (start < end) {
                swap(s[start++], s[end--]);
            }
        }
        
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    // Return true if the character is a vowel (case-insensitive)
    boolean isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    // Function to swap characters at index x and y
    void swap(char[] chars, int x, int y) {
        char temp = chars[x];
        chars[x] = chars[y];
        chars[y] = temp;
    }
    
    public String reverseVowels(String s) {
        int start = 0;
        int end = s.length() - 1;
        // Convert String to char array as String is immutable in Java
        char[] sChar = s.toCharArray();
        
        // While we still have characters to traverse
        while (start < end) {
            // Find the leftmost vowel
            while (start < s.length () && !isVowel(sChar[start])) {
                start++;
            }
            // Find the rightmost vowel
            while (end >= 0 && !isVowel(sChar[end])) {
                end--;
            }
            // Swap them if start is left of end
            if (start < end) {
                swap(sChar, start++, end--);
            }
        }
        
        // Converting char array back to String
        return new String(sChar);
    }
};
```

</details>
