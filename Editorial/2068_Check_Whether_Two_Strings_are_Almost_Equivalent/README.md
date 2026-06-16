# 2068. Check Whether Two Strings are Almost Equivalent

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 2068 - Check Whether Two Strings are Almost Equivalent](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/)

## Problem

Two strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.

Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.

The frequency of a letter x is the number of times it occurs in the string.

### Example 1

```text
Input: word1 = "aaaa", word2 = "bccb"
Output: false
Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
The difference is 4, which is more than the allowed 3.
```

### Example 2

```text
Input: word1 = "abcdeef", word2 = "abaaacc"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.
```

### Example 3

```text
Input: word1 = "cccddabba", word2 = "babababab"
Output: true
Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.
```

## Constraints

- n == word1.length == word2.length
- 1 <= n <= 100
- word1 and word2 consist only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find the Occurrence of First Almost Equal Substring](https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2068. Check Whether Two Strings are Almost Equivalent

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Array | C++, Java |

## Approach: Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26] = {0};
        
        for (int i = 0; i < word1.size(); i++) {
            cnt[word1[i] - 'a']++;
            cnt[word2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (abs(cnt[i]) > 3) {
                return false;
            }
        }
        
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int[] cnt = new int[26];
        
        for (int i = 0; i < word1.length(); i++) {
            cnt[word1.charAt(i) - 'a']++;
            cnt[word2.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (Math.abs(cnt[i]) > 3) {
                return false;
            }
        }
        
        return true;
    }
}
```

</details>
