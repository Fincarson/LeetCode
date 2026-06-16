# 2108. Find First Palindromic String in the Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)  
`Array` `Two Pointers` `String`

**Problem Link:** [LeetCode 2108 - Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)

## Problem

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

### Example 1

```text
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
```

### Example 2

```text
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
```

### Example 3

```text
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2108. Find First Palindromic String in the Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reverse String | C++, Java |
| Two Pointers | C++, Java |

## Approach 1: Reverse String

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            string reversed = s;
            reverse(reversed.begin(), reversed.end());
            
            if (s == reversed) {
                return s;
            }
        }
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String firstPalindrome(String[] words) {
        for (String s : words) {
            String reversed = new StringBuilder(s).reverse().toString();

            if (s.equals(reversed)) {
                return s;
            }
        }
        return "";
    }
}
```

</details>

<br>

## Approach 2: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPalindrome(string& s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start <= end) {
            // Return false if the characters are not the same.
            if (s[start] != s[end]) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            if (isPalindrome(s)) {
                return s;
            }
        }
        
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start <= end) {
            // Return false if the characters are not the same.
            if (s.charAt(start) != s.charAt(end)) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
    public String firstPalindrome(String[] words) {
        for (String s : words) {
            if (isPalindrome(s)) {
                return s;
            }
        }
        
        return "";
    }
}
```

</details>
