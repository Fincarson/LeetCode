# 290. Word Pattern

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/word-pattern/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 290 - Word Pattern](https://leetcode.com/problems/word-pattern/)

## Problem

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

- Each letter in pattern maps to exactly one unique word in s.
- Each unique word in s maps to exactly one letter in pattern.
- No two letters map to the same word, and no two words map to the same letter.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= pattern.length <= 300
- pattern contains only lower-case English letters.
- 1 <= s.length <= 3000
- s contains only lowercase English letters and spaces ' '.
- s does not contain any leading or trailing spaces.
- All the words in s are separated by a single space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Word Pattern II](https://leetcode.com/problems/word-pattern-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 290. Word Pattern

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Hash Maps | Java, Python3 |
| Single Index Hash Map | Java, Python3 |

## Approach 1: Two Hash Maps

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap <Character, String> map_char = new HashMap();
        HashMap <String, Character> map_word = new HashMap();
        String[] words = s.split(" ");

        if (words.length != pattern.length())
            return false;

        for (int i = 0; i < words.length; i++) {
            char c = pattern.charAt(i);
            String w = words[i];
            if (!map_char.containsKey(c)) {
                if (map_word.containsKey(w)) {
                    return false;
                } else {
                    map_char.put(c, w);
                    map_word.put(w, c);
                }

            } else {
                String mapped_word = map_char.get(c);
                if (!mapped_word.equals(w))
                    return false;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map_char = {}
        map_word = {}
        
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        
        for c, w in zip(pattern, words):
            if c not in map_char:
                if w in map_word:
                    return False
                else:
                    map_char[c] = w
                    map_word[w] = c
            else:
                if map_char[c] != w:
                    return False
        return True
```

</details>

<br>

## Approach 2: Single Index Hash Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap map_index = new HashMap();
        String[] words = s.split(" ");

        if (words.length != pattern.length())
            return false;

        for (Integer i = 0; i < words.length; i++) {
            char c = pattern.charAt(i);
            String w = words[i];

            if (!map_index.containsKey(c))
                map_index.put(c, i);

            if (!map_index.containsKey(w))
                map_index.put(w, i);

            if (map_index.get(c) != map_index.get(w))
                return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        map_index = {}
        words = s.split()
        
        if len(pattern) != len(words):
            return False
        
        for i in range(len(words)):
            c = pattern[i]
            w = words[i]

            char_key = 'char_{}'.format(c)
            char_word = 'word_{}'.format(w)
            
            if char_key not in map_index:
                map_index[char_key] = i
            
            if char_word not in map_index:
                map_index[char_word] = i 
            
            if map_index[char_key] != map_index[char_word]:
                return False
        
        return True
```

</details>
