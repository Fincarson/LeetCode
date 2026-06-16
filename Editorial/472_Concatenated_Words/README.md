# 472. Concatenated Words

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/concatenated-words/)  
`Array` `String` `Dynamic Programming` `Depth-First Search` `Trie` `Sorting`

**Problem Link:** [LeetCode 472 - Concatenated Words](https://leetcode.com/problems/concatenated-words/)

## Problem

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.

### Example 1

```text
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```

### Example 2

```text
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
```

## Constraints

- 1 <= words.length <= 104
- 1 <= words[i].length <= 30
- words[i] consists of only lowercase English letters.
- All the strings of words are unique.
- 1 <= sum(words[i].length) <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Break II](https://leetcode.com/problems/word-break-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 472. Concatenated Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java |
| DFS | C++, Java |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary(words.begin(), words.end());
        vector<string> answer;
        for (const string& word : words) {
            const int length = word.length();
            vector<bool> dp(length + 1);
            dp[0] = true;
            for (int i = 1; i <= length; ++i) {
                for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                    dp[i] = dp[j] && dictionary.count(word.substr(j, i - j));
                }
            }
            if (dp[length]) {
                answer.push_back(word);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        final Set<String> dictionary = new HashSet<>(Arrays.asList(words));
        final List<String> answer = new ArrayList<>();
        for (final String word : words) {
            final int length = word.length();
            final boolean[] dp = new boolean[length + 1];
            dp[0] = true;
            for (int i = 1; i <= length; ++i) {
                for (int j = (i == length ? 1 : 0); !dp[i] && j < i; ++j) {
                    dp[i] = dp[j] && dictionary.contains(word.substring(j, i)); 
                }
            }
            if (dp[length]) {
                answer.add(word);
            }
        }
        return answer;   
    }
}
```

</details>

<br>

## Approach 2: DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    bool dfs(const string& word, int length, vector<bool>& visited,
             const unordered_set<string>& dictionary) {
        if (length == word.length()) {
            return true;
        }
        if (visited[length]) {
            return false;
        }
        visited[length] = true;
        for (int i = word.length() - (length == 0 ? 1 : 0); i > length; --i) {
            if (dictionary.count(word.substr(length, i - length)) &&
                dfs(word, i, visited, dictionary)) {
                return true;
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary(words.begin(), words.end());
        vector<string> answer;
        for (const string& word : words) {
            vector<bool> visited(word.length());
            if (dfs(word, 0, visited, dictionary)) {
                answer.push_back(word);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private boolean dfs(final String word, int length, final boolean[] visited, final Set<String> dictionary) {
        if (length == word.length()) {
            return true;
        }
        if (visited[length]) {
            return false;
        }
        visited[length] = true;
        for (int i = word.length() - (length == 0 ? 1 : 0); i > length; --i) {
            if (dictionary.contains(word.substring(length, i)) 
                && dfs(word, i, visited, dictionary)) {
                return true;
            }
            
        }
        return false;
    }
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        final Set<String> dictionary = new HashSet<>(Arrays.asList(words));
        final List<String> answer = new ArrayList<>();
        for (final String word : words) {
            final int length = word.length();
            final boolean[] visited = new boolean[length];
            if (dfs(word, 0, visited, dictionary)) {
                answer.add(word);
            }
        }
        return answer;   
    }
}
```

</details>
