# 242. Valid Anagram

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/valid-anagram/)  
`Hash Table` `String` `Sorting`

**Problem Link:** [LeetCode 242 - Valid Anagram](https://leetcode.com/problems/valid-anagram/)

## Problem

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

### Example 1

### Example 2

## Constraints

- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 242. Valid Anagram

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | Java |
| Frequency Counter | Java |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    char[] str1 = s.toCharArray();
    char[] str2 = t.toCharArray();
    Arrays.sort(str1);
    Arrays.sort(str2);
    return Arrays.equals(str1, str2);
}
```

</details>

<br>

## Approach 2: Frequency Counter

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}
```

</details>
