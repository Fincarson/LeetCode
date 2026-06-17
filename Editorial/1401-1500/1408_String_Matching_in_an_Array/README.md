# 1408. String Matching in an Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/string-matching-in-an-array/)  
`Array` `String` `String Matching`

**Problem Link:** [LeetCode 1408 - String Matching in an Array](https://leetcode.com/problems/string-matching-in-an-array/)

## Problem

Given an array of string words, return all strings in words that are a substring of another word. You can return the answer in any order.

### Example 1

```text
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
```

### Example 2

```text
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
```

### Example 3

```text
Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 30
- words[i] contains only lowercase English letters.
- All the strings of words are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Substring XOR Queries](https://leetcode.com/problems/substring-xor-queries/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1408. String Matching in an Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| KMP Algorithm | C++, Java, Python3 |
| Suffix Trie | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        // Iterate through each word in the input list.
        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex])) {
                    // Add it to the result list if true.
                    matchingWords.push_back(words[currentWordIndex]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Helper function to check if `sub` is a substring of `main`.
    bool isSubstringOf(string &sub, string &main) {
        // Loop through possible starting indices in `main`.
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;

            // Check if the substring matches from the current start index.
            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false;  // The substring doesn't match.
                    break;  // No need to continue further for this start index.
                }
            }

            if (subFits) {
                return true;  // Found a match, return true.
            }
        }

        return false;  // No match found.
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> stringMatching(String[] words) {
        List<String> matchingWords = new ArrayList<>();

        // Iterate through each word in the input array.
        for (
            int currentWordIndex = 0;
            currentWordIndex < words.length;
            currentWordIndex++
        ) {
            // Compare the current word with all other words.
            for (
                int otherWordIndex = 0;
                otherWordIndex < words.length;
                otherWordIndex++
            ) {
                if (currentWordIndex == otherWordIndex) continue; // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (
                    isSubstringOf(
                        words[currentWordIndex],
                        words[otherWordIndex]
                    )
                ) {
                    matchingWords.add(words[currentWordIndex]); // Add it to the result list if true.
                    break; // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

    // Helper function to check if `sub` is a substring of `main`.
    private boolean isSubstringOf(String sub, String main) {
        // Loop through possible starting indices in `main`.
        for (int startIndex = 0; startIndex < main.length(); startIndex++) {
            boolean subFits = true;

            // Check if the substring matches from the current start index.
            for (int subIndex = 0; subIndex < sub.length(); subIndex++) {
                if (
                    startIndex + subIndex >= main.length() ||
                    main.charAt(startIndex + subIndex) != sub.charAt(subIndex)
                ) {
                    subFits = false; // The substring doesn't match.
                    break; // No need to continue further for this start index.
                }
            }

            if (subFits) {
                return true; // Found a match, return true.
            }
        }

        return false; // No match found.
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stringMatching(self, words):
        matching_words = []

        # Iterate through each word in the input list.
        for current_word_index in range(len(words)):
            # Compare the current word with all other words.
            for other_word_index in range(len(words)):
                # Skip comparing the word with itself.
                if current_word_index == other_word_index:
                    continue
                if words[current_word_index] in words[other_word_index]:
                    # Add it to the result list if true.
                    matching_words.append(words[current_word_index])
                    break  # No need to check further for this word.
        return matching_words
```

</details>

<br>

## Approach 2: KMP Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            vector<int> lps = computeLPSArray(words[currentWordIndex]);
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex], lps)) {
                    matchingWords.push_back(words[currentWordIndex]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Function to compute the LPS (Longest Prefix Suffix) array for the
    // substring `sub`.
    vector<int> computeLPSArray(string &sub) {
        vector<int> lps(sub.size(), 0);  // Initialize the LPS array with 0.
        int currentIndex = 1;            // Start from the second character.
        // Length of the current longest prefix which is also a suffix.
        int len = 0;

        while (currentIndex < sub.size()) {
            if (sub[currentIndex] == sub[len]) {
                len++;  // If the current characters match, extend the prefix.
                lps[currentIndex] = len;  // Store the length of the prefix.
                currentIndex++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];  // Backtrack using LPS array to find a
                                         // shorter match.
                } else {
                    currentIndex++;
                }
            }
        }
        return lps;
    }

    // Function to check if `sub` is a substring of `main` using the KMP
    // algorithm.
    bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
        int mainIndex = 0;  // Pointer for `main`.
        int subIndex = 0;   // Pointer for `sub`.

        while (mainIndex < main.size()) {
            if (main[mainIndex] == sub[subIndex]) {
                subIndex++;
                mainIndex++;
                if (subIndex == sub.size()) return true;  // Found a match.
            } else {
                if (subIndex > 0) {
                    // Use the LPS to skip unnecessary comparisons.
                    subIndex = lps[subIndex - 1];
                } else {
                    mainIndex++;
                }
            }
        }
        return false;  // No match found.
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public List<String> stringMatching(String[] words) {
        List<String> matchingWords = new ArrayList<>();

        // Iterate through each word in the input array.
        for (
            int currentWordIndex = 0;
            currentWordIndex < words.length;
            currentWordIndex++
        ) {
            int[] lps = computeLPSArray(words[currentWordIndex]);
            // Compare the current word with all other words.
            for (
                int otherWordIndex = 0;
                otherWordIndex < words.length;
                otherWordIndex++
            ) {
                if (currentWordIndex == otherWordIndex) continue; // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (
                    isSubstringOf(
                        words[currentWordIndex],
                        words[otherWordIndex],
                        lps
                    )
                ) {
                    matchingWords.add(words[currentWordIndex]); // Add it to the result list if true.
                    break; // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

    // Function to compute the LPS (Longest Prefix Suffix) array for the substring 'sub'.
    private int[] computeLPSArray(String sub) {
        int[] lps = new int[sub.length()];
        int currentIndex = 1;
        int len = 0;

        while (currentIndex < sub.length()) {
            if (sub.charAt(currentIndex) == sub.charAt(len)) {
                len++;
                lps[currentIndex] = len;
                currentIndex++;
            } else {
                if (len > 0) {
                    len = lps[len - 1]; // Backtrack using LPS array to find a shorter match.
                } else {
                    currentIndex++;
                }
            }
        }
        return lps;
    }

    // Function to check if 'sub' is a substring of 'main' using the KMP algorithm.
    private boolean isSubstringOf(String sub, String main, int[] lps) {
        int mainIndex = 0;
        int subIndex = 0;

        while (mainIndex < main.length()) {
            if (main.charAt(mainIndex) == sub.charAt(subIndex)) {
                mainIndex++;
                subIndex++;
                if (subIndex == sub.length()) return true; // Found a match.
            } else {
                if (subIndex > 0) {
                    subIndex = lps[subIndex - 1]; // Use the LPS to skip unnecessary comparisons.
                } else {
                    mainIndex++;
                }
            }
        }
        return false; // No match found.
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        matching_words = []

        for current_word_index in range(len(words)):
            lps = self._compute_lps_array(words[current_word_index])
            # Compare the current word with all other words.
            for other_word_index in range(len(words)):
                if current_word_index == other_word_index:
                    continue  # Skip comparing the word with itself.

                # Check if the current word is a substring of another word.
                if self._is_substring_of(
                    words[current_word_index], words[other_word_index], lps
                ):
                    matching_words.append(words[current_word_index])
                    break  # No need to check further for this word.

        return matching_words

    # Function to compute the LPS (Longest Prefix Suffix) array for the substring 'sub'.
    def _compute_lps_array(self, sub: str) -> List[int]:
        lps = [0] * len(sub)
        current_index = 1
        length = 0

        while current_index < len(sub):
            if sub[current_index] == sub[length]:
                length += 1
                lps[current_index] = length
                current_index += 1
            else:
                if length > 0:
                    length = lps[
                        length - 1
                    ]  # Backtrack using LPS array to find a shorter match.
                else:
                    current_index += 1
        return lps

    # Function to check if 'sub' is a substring of 'main' using the KMP algorithm.
    def _is_substring_of(self, sub: str, main: str, lps) -> bool:
        main_index = 0
        sub_index = 0

        while main_index < len(main):
            if main[main_index] == sub[sub_index]:
                main_index += 1
                sub_index += 1
                if sub_index == len(sub):
                    return True  # Found a match.
            else:
                if sub_index > 0:
                    # Use the LPS to skip unnecessary comparisons.
                    sub_index = lps[sub_index - 1]
                else:
                    main_index += 1
        return False  # No match found.
```

</details>

<br>

## Approach 3: Suffix Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        TrieNode* root = new TrieNode();  // Initialize the root of the Trie.

        // Insert all suffixes of each word into the Trie.
        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                // Insert each suffix starting from index `startIndex`.
                insertWord(root, word.substr(startIndex));
            }
        }

        // Check each word to see if it exists as a substring in the Trie.
        for (auto word : words) {
            if (isSubstring(root, word)) {
                matchingWords.push_back(word);
            }
        }

        return matchingWords;
    }

private:
    class TrieNode {
    public:
        // Tracks how many times this substring appears in the Trie.
        int frequency;
        // Maps characters to their respective child nodes.
        unordered_map<char, TrieNode*> childNodes;
    };

    // Function to insert a word (or suffix) into the Trie.
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            // If the character already exists as a child node, move to it.
            if (currentNode->childNodes.find(c) !=
                currentNode->childNodes.end()) {
                currentNode = currentNode->childNodes[c];
                // Increment the frequency of the node.
                currentNode->frequency++;
            } else {
                // If the character does not exist, create a new node.
                TrieNode* newNode = new TrieNode();
                // Initialize the frequency to 1.
                newNode->frequency = 1;
                // Add the new node as a child.
                currentNode->childNodes[c] = newNode;
                currentNode = newNode;  // Move to the new node.
            }
        }
    }

    // Function to check if a word exists as a substring in the Trie.
    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* currentNode = root;  // Start from the root node.
        for (char c : word) {
            // Traverse the Trie following the characters of the word.
            currentNode = currentNode->childNodes[c];
        }
        // A word is a substring or a different string if its frequency in the
        // Trie is greater than 1.
        return currentNode->frequency > 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    class TrieNode {

        // Tracks how many times this substring appears in the Trie.
        int frequency;
        // Maps characters to their respective child nodes.
        Map<Character, TrieNode> childNodes;

        TrieNode() {
            frequency = 0;
            childNodes = new HashMap<>();
        }
    }

    public List<String> stringMatching(String[] words) {
        List<String> matchingWords = new ArrayList<>();
        TrieNode root = new TrieNode(); // Initialize the root of the Trie.

        // Insert all suffixes of each word into the Trie.
        for (String word : words) {
            for (int startIndex = 0; startIndex < word.length(); startIndex++) {
                // Insert each suffix starting from index startIndex.
                insertWord(root, word.substring(startIndex));
            }
        }

        // Check each word to see if it exists as a substring in the Trie.
        for (String word : words) {
            if (isSubstring(root, word)) {
                matchingWords.add(word);
            }
        }

        return matchingWords;
    }

    private void insertWord(TrieNode root, String word) {
        TrieNode currentNode = root;
        for (char c : word.toCharArray()) {
            // If the character already exists as a child node, move to it.
            currentNode.childNodes.putIfAbsent(c, new TrieNode());
            currentNode = currentNode.childNodes.get(c);
            currentNode.frequency++; // Increment the frequency of the node.
        }
    }

    private boolean isSubstring(TrieNode root, String word) {
        TrieNode currentNode = root;
        for (char c : word.toCharArray()) {
            // Traverse the Trie following the characters of the word.
            currentNode = currentNode.childNodes.get(c);
        }
        // A word is a substring if its frequency in the Trie is greater than 1.
        return currentNode.frequency > 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    class TrieNode:
        def __init__(self):
            # Tracks how many times this substring appears in the Trie.
            self.frequency = 0
            # Maps characters to their respective child nodes.
            self.child_nodes = {}

    def stringMatching(self, words: List[str]) -> List[str]:
        matching_words = []
        root = self.TrieNode()  # Initialize the root of the Trie.

        # Insert all suffixes of each word into the Trie.
        for word in words:
            for start_index in range(len(word)):
                # Insert each suffix starting from index start_index.
                self._insert_word(root, word[start_index:])

        # Check each word to see if it exists as a substring in the Trie.
        for word in words:
            if self._is_substring(root, word):
                matching_words.append(word)

        return matching_words

    def _insert_word(self, root: "TrieNode", word: str) -> None:
        current_node = root
        for char in word:
            if char not in current_node.child_nodes:
                # Create a new node if the character does not exist.
                current_node.child_nodes[char] = self.TrieNode()
            current_node = current_node.child_nodes[char]
            current_node.frequency += 1  # Increment the frequency of the node.

    def _is_substring(self, root: "TrieNode", word: str) -> bool:
        current_node = root
        for char in word:
            # Traverse the Trie following the characters of the word.
            current_node = current_node.child_nodes[char]
        # A word is a substring if its frequency in the Trie is greater than 1.
        return current_node.frequency > 1
```

</details>
