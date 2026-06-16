# 720. Longest Word in Dictionary

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-word-in-dictionary/)  
`Array` `Hash Table` `String` `Trie` `Sorting`

**Problem Link:** [LeetCode 720 - Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)

## Problem

Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word.

### Example 1

```text
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
```

### Example 2

```text
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 30
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Implement Magic Dictionary](https://leetcode.com/problems/implement-magic-dictionary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Word With All Prefixes](https://leetcode.com/problems/longest-word-with-all-prefixes/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 720. Longest Word in Dictionary

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Accepted] | Python3 |
| Approach #2: Trie + Depth-First Search [Accepted] | Python3 |

## Approach #1: Brute Force [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def longestWord(self, words):
    ans = ""
    wordset = set(words)
    for word in words:
        if len(word) > len(ans) or len(word) == len(ans) and word < ans:
            if all(word[:k] in wordset for k in xrange(1, len(word))):
                ans = word

    return ans
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def longestWord(self, words):
        wordset = set(words)
        words.sort(key = lambda c: (-len(c), c))
        for word in words:
            if all(word[:k] in wordset for k in xrange(1, len(word))):
                return word

        return ""
```

</details>

<br>

## Approach #2: Trie + Depth-First Search [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def longestWord(self, words):
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()
        END = True

        for i, word in enumerate(words):
            reduce(dict.__getitem__, word, trie)[END] = i

        stack = trie.values()
        ans = ""
        while stack:
            cur = stack.pop()
            if END in cur:
                word = words[cur[END]]
                if len(word) > len(ans) or len(word) == len(ans) and word < ans:
                    ans = word
                stack.extend([cur[letter] for letter in cur if letter != END])

        return ans
```

</details>
