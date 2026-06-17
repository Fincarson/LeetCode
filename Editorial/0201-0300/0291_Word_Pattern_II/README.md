# 291. Word Pattern II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/word-pattern-ii/)  
`Hash Table` `String` `Backtracking`

**Problem Link:** [LeetCode 291 - Word Pattern II](https://leetcode.com/problems/word-pattern-ii/)

## Problem

Given a pattern and a string s, return true if s matches the pattern.

A string s matches a pattern if there is some bijective mapping of single characters to non-empty strings such that if each character in pattern is replaced by the string it maps to, then the resulting string is s. A bijective mapping means that no two characters map to the same string, and no character maps to two different strings.

### Example 1

```text
Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"
```

### Example 2

```text
Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"
```

### Example 3

```text
Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false
```

## Constraints

- 1 <= pattern.length, s.length <= 20
- pattern and s consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Pattern](https://leetcode.com/problems/word-pattern/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 291. Word Pattern II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Table and Backtracking | C++, Java, Python3 |
| Optimized Backtracking | C++, Java, Python3 |

## Approach 1: Hash Table and Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> symbolMap;
        unordered_set<string> wordSet;

        return isMatch(s, 0, pattern, 0, symbolMap, wordSet);
    }

private:
    bool isMatch(string& s, int sIndex, string& pattern, int pIndex,
                 unordered_map<char, string>& symbolMap,
                 unordered_set<string>& wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True iff also reached end of s
        }

        // Get current pattern character
        char symbol = pattern[pIndex];

        // This symbol already has an associated word
        if (symbolMap.find(symbol) != symbolMap.end()) {
            string word = symbolMap[symbol];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.length(), word)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1,
                           symbolMap, wordSet);
        }

        // This symbol does not exist in the map
        for (int k = sIndex + 1; k <= s.length(); k++) {
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end()) {
                continue;
            }
            // Create or update it
            symbolMap[symbol] = newWord;
            wordSet.insert(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbolMap, wordSet)) {
                return true;
            }
            // Backtracking
            symbolMap.erase(symbol);
            wordSet.erase(newWord);
        }
        // No mappings were valid
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordPatternMatch(String pattern, String s) {
        Map<Character, String> symbolMap = new HashMap<>();
        Set<String> wordSet = new HashSet<>();

        return isMatch(s, 0, pattern, 0, symbolMap, wordSet);
    }

    private boolean isMatch(String s, int sIndex, String pattern, int pIndex, Map<Character, String> symbolMap,
            Set<String> wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True iff also reached end of s
        }

        // Get current pattern character
        char symbol = pattern.charAt(pIndex);

        // This symbol already has an associated word
        if (symbolMap.containsKey(symbol)) {
            String word = symbolMap.get(symbol);
            // Check if we can use it to match s[sIndex...sIndex + word.length()]
            if (!s.startsWith(word, sIndex)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1, symbolMap, wordSet);
        }

        // This symbol does not exist in the map
        for (int k = sIndex + 1; k <= s.length(); k++) {
            String newWord = s.substring(sIndex, k);
            if (wordSet.contains(newWord)) {
                continue;
            }
            // Create or update it
            symbolMap.put(symbol, newWord);
            wordSet.add(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbolMap, wordSet)) {
                return true;
            }
            // Backtracking
            symbolMap.remove(symbol);
            wordSet.remove(newWord);
        }
        // No mappings were valid
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        symbol_map = {}
        word_set = set()

        def is_match(p_index, s_index):
            # Base case: reached end of pattern
            if p_index == len(pattern):
                return s_index == len(s)  # True iff also reached end of s

            # Get current pattern character
            symbol = pattern[p_index]

            # This symbol already has an associated word
            if symbol in symbol_map:
                word = symbol_map[symbol]
                # Check if we can use it to match s[sIndex...sIndex + word.length()]
                if s[s_index : s_index + len(word)] != word:
                    return False
                # If it matches continue to match the rest
                return is_match(p_index + 1, s_index + len(word))

            # This symbol does not exist in the map
            for k in range(s_index + 1, len(s) + 1):
                new_word = s[s_index:k]
                if new_word in word_set:
                    continue
                # Create or update it
                symbol_map[symbol] = new_word
                word_set.add(new_word)
                # Continue to match the rest
                if is_match(p_index + 1, s_index + len(new_word)):
                    return True
                # Backtracking
                del symbol_map[symbol]
                word_set.remove(new_word)

        return is_match(0, 0)
```

</details>

<br>

## Approach 2: Optimized Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        vector<string> symbols(26, "");
        unordered_set<string> wordSet;

        return isMatch(s, 0, pattern, 0, symbols, wordSet);
    }

private:
    bool isMatch(string& s, int sIndex, string& pattern, int pIndex,
                 vector<string>& symbols, unordered_set<string>& wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True if and only if also reached end of s
        }

        // Get current pattern character
        char symbol = pattern[pIndex];

        // This symbol already has an associated word
        if (!symbols[symbol - 'a'].empty()) {
            string word = symbols[symbol - 'a'];
            // Check if it matches s[sIndex...sIndex + word.length()]
            if (s.compare(sIndex, word.length(), word)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1,
                           symbols, wordSet);
        }

        // Count the number of spots the remaining symbols in the pattern take
        int filledSpots = 0;
        for (int i = pIndex + 1; i < pattern.length(); i++) {
            char p = pattern[i];
            filledSpots += symbols[p - 'a'].empty() ? 1 : symbols[p - 'a'].length();
        }

        // This symbol does not have an associated word
        for (int k = sIndex + 1; k <= s.length() - filledSpots; k++) {
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end())
                continue;
            // Create or update it
            symbols[symbol - 'a'] = newWord;
            wordSet.insert(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbols, wordSet)) {
                return true;
            }
            // Backtracking
            symbols[symbol - 'a'] = "";
            wordSet.erase(newWord);
        }
        // No mappings were valid
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean wordPatternMatch(String pattern, String s) {
        String[] symbols = new String[26];
        Arrays.fill(symbols, "");
        Set<String> wordSet = new HashSet<>();

        return isMatch(s, 0, pattern, 0, symbols, wordSet);
    }

    private boolean isMatch(String s, int sIndex, String pattern, int pIndex,
            String[] symbols, Set<String> wordSet) {
        // Base case: reached end of pattern
        if (pIndex == pattern.length()) {
            return sIndex == s.length(); // True if and only if also reached end of s
        }

        // Get current pattern character
        char symbol = pattern.charAt(pIndex);

        // This symbol already has an associated word
        if (!symbols[symbol - 'a'].equals("")) {
            String word = symbols[symbol - 'a'];
            // Check if we can use it to match s[sIndex...sIndex + word.length()]
            if (!s.startsWith(word, sIndex)) {
                return false;
            }
            // If it matches continue to match the rest
            return isMatch(s, sIndex + word.length(), pattern, pIndex + 1, symbols, wordSet);
        }

        // Count the number of spots the remaining symbols in the pattern take
        int filledSpots = 0;
        for (int i = pIndex + 1; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            filledSpots += symbols[p - 'a'].equals("") ? 1 : symbols[p - 'a'].length();
        }

        // This symbol does not have an associated word
        for (int k = sIndex + 1; k <= s.length() - filledSpots; k++) {
            String newWord = s.substring(sIndex, k);
            if (wordSet.contains(newWord))
                continue;
            // Create or update it
            symbols[symbol - 'a'] = newWord;
            wordSet.add(newWord);
            // Continue to match the rest
            if (isMatch(s, k, pattern, pIndex + 1, symbols, wordSet)) {
                return true;
            }
            // Backtracking
            symbols[symbol - 'a'] = "";
            wordSet.remove(newWord);
        }
        // No mappings were valid
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        symbols = [""] * 26
        word_set = set()

        def is_match(s_index: int, p_index: int):
            # Base case: reached end of pattern
            if p_index == len(pattern):
                return s_index == len(s)  # True if and only if also reached end of s

            # Get current pattern character
            symbol = pattern[p_index]

            # This symbol already has an associated word
            if symbols[ord(symbol) - ord("a")]:
                word = symbols[ord(symbol) - ord("a")]
                # Check if it matches s[s_index...s_index + len(word)]
                if s[s_index : s_index + len(word)] != word:
                    return False
                # If it matches continue to match the rest
                return is_match(s_index + len(word), p_index + 1)

            # Count the number of spots the remaining symbols in the pattern take
            filled_spots = 0
            for i in range(p_index + 1, len(pattern)):
                if symbols[ord(pattern[i]) - ord("a")]:
                    filled_spots += len(symbols[ord(pattern[i]) - ord("a")])
                else:
                    filled_spots += 1

            # This symbol does not have an associated word
            for k in range(s_index + 1, len(s) - filled_spots + 1):
                new_word = s[s_index:k]
                if new_word in word_set:
                    continue
                # Create or update it
                symbols[ord(symbol) - ord("a")] = new_word
                word_set.add(new_word)
                # Continue to match the rest
                if is_match(k, p_index + 1):
                    return True
                # Backtracking
                symbols[ord(symbol) - ord("a")] = ""
                word_set.remove(new_word)
            # No mappings were valid
            return False

        return is_match(0, 0)
```

</details>
