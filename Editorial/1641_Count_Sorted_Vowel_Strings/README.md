# 1641. Count Sorted Vowel Strings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-sorted-vowel-strings/)  
`Math` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 1641 - Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)

## Problem

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

### Example 1

```text
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

### Example 2

```text
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

### Example 3

```text
Input: n = 33
Output: 66045
```

## Constraints

- 1 <= n <= 50

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1641. Count Sorted Vowel Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force Using Backtracking | C++, Java |

## Approach 1: Brute Force Using Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        return countVowelStringUtil(n, 1);
    }

    int countVowelStringUtil(int n, int vowels) {
        if (n == 0)
            return 1;
        int result = 0;
        for (int i = vowels; i <= 5; i++) {
            result += countVowelStringUtil(n - 1, i);
        }
        return result;
    }   
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countVowelStrings(int n) {
        return countVowelStringUtil(n, 1);
    }

    int countVowelStringUtil(int n, int vowels) {
        if (n == 0)
            return 1;
        int result = 0;
        for (int i = vowels; i <= 5; i++) {
            result += countVowelStringUtil(n - 1, i);
        }
        return result;
    }
}
```

</details>
