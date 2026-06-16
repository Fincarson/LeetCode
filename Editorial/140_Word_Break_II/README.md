# 140. Word Break II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/word-break-ii/)  
`Array` `Hash Table` `String` `Dynamic Programming` `Backtracking` `Trie` `Memoization`

**Problem Link:** [LeetCode 140 - Word Break II](https://leetcode.com/problems/word-break-ii/)

## Problem

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

### Example 1

```text
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

### Example 2

```text
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
```

### Example 3

```text
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
```

## Constraints

- 1 <= s.length <= 20
- 1 <= wordDict.length <= 1000
- 1 <= wordDict[i].length <= 10
- s and wordDict[i] consist of only lowercase English letters.
- All the strings of wordDict are unique.
- Input is generated in a way that the length of the answer doesn't exceed 105.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Break](https://leetcode.com/problems/word-break/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Concatenated Words](https://leetcode.com/problems/concatenated-words/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 140. Word Break II

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Dynamic Programming - Memoization | C++, Java, Python3 |
| Dynamic Programming - Tabulation | C++, Java, Python3 |
| Trie Optimization | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to a set for O(1) lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> results;
        string currentSentence;
        // Start the backtracking process
        backtrack(s, wordSet, currentSentence, results, 0);
        return results;
    }

private:
    void backtrack(const string& s, const unordered_set<string>& wordSet,
                   string& currentSentence, vector<string>& results,
                   int startIndex) {
        // If we've reached the end of the string, add the current sentence to
        // results
        if (startIndex == s.length()) {
            results.push_back(currentSentence);
            return;
        }

        // Iterate over possible end indices
        for (int endIndex = startIndex + 1; endIndex <= s.length();
             ++endIndex) {
            string word = s.substr(startIndex, endIndex - startIndex);
            // If the word is in the set, proceed with backtracking
            if (wordSet.find(word) != wordSet.end()) {
                string originalSentence = currentSentence;
                if (!currentSentence.empty()) currentSentence += " ";
                currentSentence += word;
                // Recursively call backtrack with the new end index
                backtrack(s, wordSet, currentSentence, results, endIndex);
                // Reset currentSentence to its original state
                currentSentence = originalSentence;
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Convert wordDict to a set for O(1) lookups
        Set<String> wordSet = new HashSet<>(wordDict);
        List<String> results = new ArrayList<>();
        // Start the backtracking process
        backtrack(s, wordSet, new StringBuilder(), results, 0);
        return results;
    }

    private void backtrack(
        String s,
        Set<String> wordSet,
        StringBuilder currentSentence,
        List<String> results,
        int startIndex
    ) {
        // If we've reached the end of the string, add the current sentence to results
        if (startIndex == s.length()) {
            results.add(currentSentence.toString().trim());
            return;
        }

        // Iterate over possible end indices
        for (
            int endIndex = startIndex + 1;
            endIndex <= s.length();
            endIndex++
        ) {
            String word = s.substring(startIndex, endIndex);
            // If the word is in the set, proceed with backtracking
            if (wordSet.contains(word)) {
                int currentLength = currentSentence.length();
                currentSentence.append(word).append(" ");
                // Recursively call backtrack with the new end index
                backtrack(s, wordSet, currentSentence, results, endIndex);
                // Reset currentSentence to its original length
                currentSentence.setLength(currentLength);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Convert wordDict to a set for O(1) lookups
        word_set = set(wordDict)
        results = []
        # Start the backtracking process
        self._backtrack(s, word_set, [], results, 0)
        return results

    def _backtrack(
        self,
        s: str,
        word_set: set,
        current_sentence: List[str],
        results: List[str],
        start_index: int,
    ):
        # If we've reached the end of the string, add the current sentence to results
        if start_index == len(s):
            results.append(" ".join(current_sentence))
            return

        # Iterate over possible end indices
        for end_index in range(start_index + 1, len(s) + 1):
            word = s[start_index:end_index]
            # If the word is in the set, proceed with backtracking
            if word in word_set:
                current_sentence.append(word)
                # Recursively call backtrack with the new end index
                self._backtrack(
                    s, word_set, current_sentence, results, end_index
                )
                # Remove the last word to backtrack
                current_sentence.pop()
```

</details>

<br>

## Approach 2: Dynamic Programming - Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memoization;
        return dfs(s, wordSet, memoization);
    }

private:
    // Depth-first search function to find all possible word break combinations
    vector<string> dfs(const string& remainingStr,
                       const unordered_set<string>& wordSet,
                       unordered_map<string, vector<string>>& memoization) {
        // Check if result for this substring is already memoized
        if (memoization.count(remainingStr)) return memoization[remainingStr];
        // Base case: when the string is empty, return a list containing an
        // empty string
        if (remainingStr.empty()) return {""};
        vector<string> results;
        for (int i = 1; i <= remainingStr.length(); ++i) {
            string currentWord = remainingStr.substr(0, i);
            // If the current substring is a valid word
            if (wordSet.count(currentWord)) {
                for (const string& nextWord :
                     dfs(remainingStr.substr(i), wordSet, memoization)) {
                    // Append current word and next word with space in between
                    // if next word exists
                    results.push_back(currentWord +
                                      (nextWord.empty() ? "" : " ") + nextWord);
                }
            }
        }
        // Memoize the results for the current substring
        memoization[remainingStr] = results;
        return results;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Main function to break the string into words
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);
        Map<String, List<String>> memoization = new HashMap<>();
        return dfs(s, wordSet, memoization);
    }

    // Depth-first search function to find all possible word break combinations
    private List<String> dfs(
        String remainingStr,
        Set<String> wordSet,
        Map<String, List<String>> memoization
    ) {
        // Check if result for this substring is already memoized
        if (memoization.containsKey(remainingStr)) {
            return memoization.get(remainingStr);
        }

        // Base case: when the string is empty, return a list containing an empty string
        if (remainingStr.isEmpty()) return Collections.singletonList("");
        List<String> results = new ArrayList<>();
        for (int i = 1; i <= remainingStr.length(); ++i) {
            String currentWord = remainingStr.substring(0, i);
            // If the current substring is a valid word
            if (wordSet.contains(currentWord)) {
                for (String nextWord : dfs(
                    remainingStr.substring(i),
                    wordSet,
                    memoization
                )) {
                    // Append current word and next word with space in between if next word exists
                    results.add(
                        currentWord + (nextWord.isEmpty() ? "" : " ") + nextWord
                    );
                }
            }
        }
        // Memoize the results for the current substring
        memoization.put(remainingStr, results);
        return results;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        memoization = {}
        return self._dfs(s, word_set, memoization)

    # Depth-first search function to find all possible word break combinations
    def _dfs(
        self, remaining_str: str, word_set: set, memoization: dict
    ) -> List[str]:
        # Check if result for this substring is already memoized
        if remaining_str in memoization:
            return memoization[remaining_str]
        # Base case: when the string is empty, return a list containing an empty string
        if not remaining_str:
            return [""]
        results = []
        for i in range(1, len(remaining_str) + 1):
            current_word = remaining_str[:i]
            # If the current substring is a valid word
            if current_word in word_set:
                for next_word in self._dfs(
                    remaining_str[i:], word_set, memoization
                ):
                    # Append current word and next word with space in between if next word exists
                    results.append(
                        current_word + (" " if next_word else "") + next_word
                    )
        # Memoize the results for the current substring
        memoization[remaining_str] = results
        return results
```

</details>

<br>

## Approach 3: Dynamic Programming - Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Map to store results of subproblems
        unordered_map<int, vector<string>> dp;

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            vector<string> validSentences;

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
                // Extract substring from startIdx to endIdx
                string currentWord = s.substr(startIdx, endIdx - startIdx + 1);

                // Check if the current substring is a valid word
                if (isWordInDict(currentWord, wordDict)) {
                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence
                        // formed by the remaining substring
                        vector<string> sentencesFromNextIndex = dp[endIdx + 1];
                        for (const auto& sentence : sentencesFromNextIndex) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }
            // Store the valid sentences in dp
            dp[startIdx] = validSentences;
        }
        // Return the sentences formed from the entire string
        return dp[0];
    }

private:
    // Helper function to check if a word is in the word dictionary
    bool isWordInDict(const string& word, const vector<string>& wordDict) {
        for (const auto& dictWord : wordDict) {
            if (dictWord == word) {
                return true;
            }
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Map to store results of subproblems
        Map<Integer, List<String>> dp = new HashMap<>();

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.length(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            List<String> validSentences = new ArrayList<>();

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.length(); endIdx++) {
                // Extract substring from startIdx to endIdx
                String currentWord = s.substring(startIdx, endIdx + 1);

                // Check if the current substring is a valid word
                if (isWordInDict(currentWord, wordDict)) {
                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.length() - 1) {
                        validSentences.add(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence formed by the remaining substring
                        List<String> sentencesFromNextIndex = dp.get(
                            endIdx + 1
                        );
                        for (String sentence : sentencesFromNextIndex) {
                            validSentences.add(currentWord + " " + sentence);
                        }
                    }
                }
            }
            // Store the valid sentences in dp
            dp.put(startIdx, validSentences);
        }
        // Return the sentences formed from the entire string
        return dp.getOrDefault(0, new ArrayList<>());
    }

    // Helper function to check if a word is in the word dictionary
    private boolean isWordInDict(String word, List<String> wordDict) {
        return wordDict.contains(word);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Map to store results of subproblems
        dp = {}

        # Iterate from the end of the string to the beginning
        for start_idx in range(len(s), -1, -1):
            # List to store valid sentences starting from start_idx
            valid_sentences = []

            # Iterate from start_idx to the end of the string
            for end_idx in range(start_idx, len(s)):
                # Extract substring from start_idx to end_idx
                current_word = s[start_idx : end_idx + 1]

                # Check if the current substring is a valid word
                if self.is_word_in_dict(current_word, wordDict):
                    # If it's the last word, add it as a valid sentence
                    if end_idx == len(s) - 1:
                        valid_sentences.append(current_word)
                    else:
                        # If it's not the last word, append it to each sentence formed by the remaining substring
                        sentences_from_next_index = dp.get(end_idx + 1, [])
                        for sentence in sentences_from_next_index:
                            valid_sentences.append(
                                current_word + " " + sentence
                            )

            # Store the valid sentences in dp
            dp[start_idx] = valid_sentences

        # Return the sentences formed from the entire string
        return dp.get(0, [])

    # Helper function to check if a word is in the word dictionary
    def is_word_in_dict(self, word: str, word_dict: List[str]) -> bool:
        return word in word_dict
```

</details>

<br>

## Approach 4: Trie Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie from the word dictionary
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }

        // Map to store results of subproblems
        unordered_map<int, vector<string>> dp;

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            vector<string> validSentences;

            // Initialize current node to the root of the trie
            TrieNode* currentNode = trie.root;

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
                char c = s[endIdx];
                int index = c - 'a';

                // Check if the current character exists in the trie
                if (!currentNode->children[index]) {
                    break;
                }

                // Move to the next node in the trie
                currentNode = currentNode->children[index];

                // Check if we have found a valid word
                if (currentNode->isEnd) {
                    string currentWord =
                        s.substr(startIdx, endIdx - startIdx + 1);

                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence
                        // formed by the remaining substring
                        for (string sentence : dp[endIdx + 1]) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }

            // Store the valid sentences in dp
            dp[startIdx] = validSentences;
        }

        // Return the sentences formed from the entire string
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    boolean isEnd;
    TrieNode[] children;

    TrieNode() {
        isEnd = false;
        children = new TrieNode[26];
    }
}

class Trie {

    TrieNode root;

    Trie() {
        root = new TrieNode();
    }

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            if (node.children[index] == null) {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isEnd = true;
    }
}

class Solution {

    public List<String> wordBreak(String s, List<String> wordDict) {
        // Build the Trie from the word dictionary
        Trie trie = new Trie();
        for (String word : wordDict) {
            trie.insert(word);
        }

        // Map to store results of subproblems
        Map<Integer, List<String>> dp = new HashMap<>();

        // Iterate from the end of the string to the beginning
        for (int startIdx = s.length(); startIdx >= 0; startIdx--) {
            // List to store valid sentences starting from startIdx
            List<String> validSentences = new ArrayList<>();

            // Initialize current node to the root of the trie
            TrieNode currentNode = trie.root;

            // Iterate from startIdx to the end of the string
            for (int endIdx = startIdx; endIdx < s.length(); endIdx++) {
                char c = s.charAt(endIdx);
                int index = c - 'a';

                // Check if the current character exists in the trie
                if (currentNode.children[index] == null) {
                    break;
                }

                // Move to the next node in the trie
                currentNode = currentNode.children[index];

                // Check if we have found a valid word
                if (currentNode.isEnd) {
                    String currentWord = s.substring(startIdx, endIdx + 1);

                    // If it's the last word, add it as a valid sentence
                    if (endIdx == s.length() - 1) {
                        validSentences.add(currentWord);
                    } else {
                        // If it's not the last word, append it to each sentence formed by the remaining substring
                        List<String> sentencesFromNextIndex = dp.get(
                            endIdx + 1
                        );
                        for (String sentence : sentencesFromNextIndex) {
                            validSentences.add(currentWord + " " + sentence);
                        }
                    }
                }
            }

            // Store the valid sentences in dp
            dp.put(startIdx, validSentences);
        }

        // Return the sentences formed from the entire string
        return dp.getOrDefault(0, new ArrayList<>());
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.children = [None] * 26  # For lowercase English letters


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            index = ord(char) - ord("a")
            if not node.children[index]:
                node.children[index] = TrieNode()
            node = node.children[index]
        node.isEnd = True


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Build the Trie from the word dictionary
        trie = Trie()
        for word in wordDict:
            trie.insert(word)

        # Map to store results of subproblems
        dp = {}

        # Iterate from the end of the string to the beginning
        for start_idx in range(len(s), -1, -1):
            # List to store valid sentences starting from start_idx
            valid_sentences = []

            # Initialize current node to the root of the trie
            current_node = trie.root

            # Iterate from start_idx to the end of the string
            for end_idx in range(start_idx, len(s)):
                char = s[end_idx]
                index = ord(char) - ord("a")

                # Check if the current character exists in the trie
                if not current_node.children[index]:
                    break

                # Move to the next node in the trie
                current_node = current_node.children[index]

                # Check if we have found a valid word
                if current_node.isEnd:
                    current_word = s[start_idx : end_idx + 1]

                    # If it's the last word, add it as a valid sentence
                    if end_idx == len(s) - 1:
                        valid_sentences.append(current_word)
                    else:
                        # If it's not the last word, append it to each sentence formed by the remaining substring
                        sentences_from_next_index = dp.get(end_idx + 1, [])
                        for sentence in sentences_from_next_index:
                            valid_sentences.append(
                                current_word + " " + sentence
                            )

            # Store the valid sentences in dp
            dp[start_idx] = valid_sentences

        # Return the sentences formed from the entire string
        return dp.get(0, [])
```

</details>
