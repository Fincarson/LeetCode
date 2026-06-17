# 1328. Break a Palindrome

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/break-a-palindrome/)  
`String` `Greedy`

**Problem Link:** [LeetCode 1328 - Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/)

## Problem

Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

### Example 1

```text
Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
```

### Example 2

```text
Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
```

## Constraints

- 1 <= palindrome.length <= 1000
- palindrome consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1328. Break a Palindrome

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C++, Java |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.size();
        
        if (length == 1) { 
            return "";
        }
        
        for (int i = 0; i < length / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[length - 1] = 'b';
        return palindrome;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String breakPalindrome(String palindrome) {
        int length = palindrome.length();
        if (length == 1) { 
            return "";
        }
        // Strings are immutable in Java, convert it into a char array
        char[] palindromeArray = palindrome.toCharArray();
        
        for (int i = 0; i < length / 2; i++) {
            if (palindromeArray[i] != 'a') {
                palindromeArray[i] = 'a';
                return String.valueOf(palindromeArray);
            }
        }
        
        palindromeArray[length - 1] = 'b';
        return String.valueOf(palindromeArray);
    }
}
```

</details>
