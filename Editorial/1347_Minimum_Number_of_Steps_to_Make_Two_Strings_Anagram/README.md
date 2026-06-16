# 1347. Minimum Number of Steps to Make Two Strings Anagram

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 1347 - Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)

## Problem

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

### Example 1

```text
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
```

### Example 2

```text
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
```

### Example 3

```text
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.
```

## Constraints

- 1 <= s.length <= 5 * 104
- s.length == t.length
- s and t consist of lowercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Determine if Two Strings Are Close](https://leetcode.com/problems/determine-if-two-strings-are-close/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Number of Steps to Make Two Strings Anagram II](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimum Operations to Make Character Frequencies Equal](https://leetcode.com/problems/minimum-operations-to-make-character-frequencies-equal/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1347. Minimum Number of Steps to Make Two Strings Anagram

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: HashMap | C++, Java |

## Approach: HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        // Storing the difference of frequencies of characters in t and s.
        for (int i = 0; i < s.size(); i++) {
            count[t[i] - 'a']++;
            count[s[i] - 'a']--;
        }

        int ans = 0;
        // Adding the difference where string t has more instances than s.
        // Ignoring where t has fewer instances as they are redundant and
        // can be covered by the first case.
        for (int i = 0; i < 26; i++) {
            ans += max(0, count[i]);
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
    public int minSteps(String s, String t) {
        int[] count = new int[26];
        // Storing the difference of frequencies of characters in t and s.
        for (int i = 0; i < s.length(); i++) {
            count[t.charAt(i) - 'a']++;
            count[s.charAt(i) - 'a']--;
        }

        int ans = 0;
        // Adding the difference where string t has more instances than s.
        // Ignoring where t has fewer instances as they are redundant and
        // can be covered by the first case.
        for (int i = 0; i < 26; i++) {
            ans += Math.max(0, count[i]);
        }

        return ans;
    }
}
```

</details>
