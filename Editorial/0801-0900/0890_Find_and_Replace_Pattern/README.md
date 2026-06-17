# 890. Find and Replace Pattern

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-and-replace-pattern/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 890 - Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/)

## Problem

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

### Example 1

```text
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
```

### Example 2

```text
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
```

## Constraints

- 1 <= pattern.length <= 20
- 1 <= words.length <= 50
- words[i].length == pattern.length
- pattern and words[i] are lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Word Pattern](https://leetcode.com/problems/word-pattern/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 890. Find and Replace Pattern

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Maps | Java, Python |
| One Map | Java, Python |

## Approach 1: Two Maps

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList();
        for (String word: words)
            if (match(word, pattern))
                ans.add(word);
        return ans;
    }

    public boolean match(String word, String pattern) {
        Map<Character, Character> m1 = new HashMap();
        Map<Character, Character> m2 = new HashMap();

        for (int i = 0; i < word.length(); ++i) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            if (!m1.containsKey(w)) m1.put(w, p);
            if (!m2.containsKey(p)) m2.put(p, w);
            if (m1.get(w) != p || m2.get(p) != w)
                return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            m1, m2 = {}, {}
            for w, p in zip(word, pattern):
                if w not in m1: m1[w] = p
                if p not in m2: m2[p] = w
                if (m1[w], m2[p]) != (p, w):
                    return False
            return True

        return filter(match, words)
```

</details>

<br>

## Approach 2: One Map

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList();
        for (String word: words)
            if (match(word, pattern))
                ans.add(word);
        return ans;
    }

    public boolean match(String word, String pattern) {
        Map<Character, Character> M = new HashMap();
        for (int i = 0; i < word.length(); ++i) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            if (!M.containsKey(w)) M.put(w, p);
            if (M.get(w) != p) return false;
        }

        boolean[] seen = new boolean[26];
        for (char p: M.values()) {
            if (seen[p - 'a']) return false;
            seen[p - 'a'] = true;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        def match(word):
            P = {}
            for x, y in zip(pattern, word):
                if P.setdefault(x, y) != y:
                    return False
            return len(set(P.values())) == len(P.values())

        return filter(match, words)
```

</details>
