# 1858. Longest Word With All Prefixes

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-word-with-all-prefixes/)  
`Array` `String` `Depth-First Search` `Trie`

**Problem Link:** [LeetCode 1858 - Longest Word With All Prefixes](https://leetcode.com/problems/longest-word-with-all-prefixes/)

## Problem

Given an array of strings words, find the longest string in words such that every prefix of it is also in words.

- For example, let words = ["a", "app", "ap"]. The string "app" has prefixes "ap" and "a", all of which are in words.

Return the string described above. If there is more than one string with the same length, return the lexicographically smallest one, and if no string exists, return "".

### Example 1

```text
Input: words = ["k","ki","kir","kira", "kiran"]
Output: "kiran"
Explanation: "kiran" has prefixes "kira", "kir", "ki", and "k", and all of them appear in words.
```

### Example 2

```text
Input: words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: Both "apple" and "apply" have all their prefixes in words.
However, "apple" is lexicographically smaller, so we return that.
```

### Example 3

```text
Input: words = ["abc", "bc", "ab", "qwe"]
Output: ""
```

## Constraints

- 1 <= words.length <= 105
- 1 <= words[i].length <= 105
- 1 <= sum(words[i].length) <= 105
- words[i] consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1858. Longest Word With All Prefixes

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C++, Java, Python3 |
| Trie | C++, Java, Python3 |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        // Sort the words lexicographically
        sort(words.begin(), words.end());

        // Set to store valid words
        unordered_set<string> validWords;
        string longestValidWord = "";

        // Iterate through each word
        for (string& currentWord : words) {
            // Check if the word is of length 1 or if its prefix exists in the
            // set
            if (currentWord.length() == 1 ||
                validWords.find(currentWord.substr(
                    0, currentWord.length() - 1)) != validWords.end()) {
                validWords.insert(currentWord);

                if (longestValidWord.length() < currentWord.length()) {
                    longestValidWord = currentWord;
                }
            }
        }

        return longestValidWord;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String longestWord(String[] words) {
        // Sort the words lexicographically
        Arrays.sort(words);

        // Set to store valid words
        Set<String> validWords = new HashSet<>();
        String longestValidWord = "";

        // Iterate through each word
        for (String currentWord : words) {
            // Check if the word is of length 1 or if its prefix exists in the set
            if (
                currentWord.length() == 1 ||
                validWords.contains(
                    currentWord.substring(0, currentWord.length() - 1)
                )
            ) {
                // Add the current word to the set of valid words
                validWords.add(currentWord);

                // Update the longest valid word if necessary
                if (longestValidWord.length() < currentWord.length()) {
                    longestValidWord = currentWord;
                }
            }
        }

        // Return the longest valid word found
        return longestValidWord;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestWord(self, words: List[str]) -> str:
        # Sort the words lexicographically
        words.sort()

        # Set to store valid words
        valid_words = set()
        longest_valid_word = ""

        # Iterate through each word
        for current_word in words:
            # Check if the word is of length 1 or if its prefix exists in the set
            if len(current_word) == 1 or current_word[:-1] in valid_words:
                # Add the current word to the set of valid words
                valid_words.add(current_word)

                # Update the longest valid word if necessary
                if len(current_word) > len(longest_valid_word):
                    longest_valid_word = current_word

        # Return the longest valid word found
        return longest_valid_word
```

</details>

<br>

## Approach 2: Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        string longestValidWord = "";

        // Insert all words into the trie
        for (string& word : words) {
            trie.insert(word);
        }

        // Check each word and update the longest valid word
        for (string& word : words) {
            if (trie.hasAllPrefixes(word)) {
                if (word.length() > longestValidWord.length() ||
                    (word.length() == longestValidWord.length() &&
                     word < longestValidWord)) {
                    longestValidWord = word;
                }
            }
        }

        return longestValidWord;
    }

private:
    class Trie {
    private:
        struct TrieNode {
            TrieNode* children[26] = {nullptr};
            bool isEndOfWord = false;
        };

        TrieNode* root;

    public:
        Trie() : root(new TrieNode()) {}

        // Insert a word into the trie
        void insert(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->isEndOfWord = true;
        }

        // Check if all prefixes of the word exist in the trie
        bool hasAllPrefixes(string& word) {
            TrieNode* node = root;
            for (char c : word) {
                node = node->children[c - 'a'];
                if (node == nullptr || !node->isEndOfWord) {
                    return false;
                }
            }
            return true;
        }

        // Destructor to free allocated memory
        ~Trie() { deleteTrie(root); }

    private:
        void deleteTrie(TrieNode* node) {
            if (node == nullptr) return;
            for (int i = 0; i < 26; i++) {
                deleteTrie(node->children[i]);
            }
            delete node;
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String longestWord(String[] words) {
        Trie trie = new Trie();
        String longestValidWord = "";

        // Insert all words into the trie
        for (String word : words) {
            trie.insert(word);
        }

        // Check each word and update the longest valid word
        for (String word : words) {
            if (trie.hasAllPrefixes(word)) {
                if (
                    word.length() > longestValidWord.length() ||
                    (word.length() == longestValidWord.length() &&
                        word.compareTo(longestValidWord) < 0)
                ) {
                    longestValidWord = word;
                }
            }
        }

        return longestValidWord;
    }

    private static class Trie {

        private static class TrieNode {

            TrieNode[] children = new TrieNode[26];
            boolean isEndOfWord;
        }

        private final TrieNode root = new TrieNode();

        // Insert a word into the trie
        public void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEndOfWord = true;
        }

        // Check if all prefixes of the word exist in the trie
        public boolean hasAllPrefixes(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                node = node.children[c - 'a'];
                if (node == null || !node.isEndOfWord) {
                    return false;
                }
            }
            return true;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        longest_valid_word = ""

        # Insert all words into the trie
        for word in words:
            trie._insert(word)

        # Check each word and update the longest valid word
        for word in words:
            if trie._has_all_prefixes(word):
                if len(word) > len(longest_valid_word) or (
                    len(word) == len(longest_valid_word)
                    and word < longest_valid_word
                ):
                    longest_valid_word = word

        return longest_valid_word


class Trie:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.is_end_of_word = False

    def __init__(self):
        self.root = self.TrieNode()

    # Insert a word into the trie
    def _insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = self.TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    # Check if all prefixes of the word exist in the trie
    def _has_all_prefixes(self, word):
        node = self.root
        for char in word:
            if (
                char not in node.children
                or not node.children[char].is_end_of_word
            ):
                return False
            node = node.children[char]
        return True
```

</details>
