# 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)  
`Two Pointers` `String` `String Matching`

**Problem Link:** [LeetCode 1455 - Check If a Word Occurs As a Prefix of Any Word in a Sentence](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)

## Problem

Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

### Example 1

```text
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
```

### Example 2

```text
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
```

### Example 3

```text
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
```

## Constraints

- 1 <= sentence.length <= 100
- 1 <= searchWord.length <= 10
- sentence consists of lowercase English letters and spaces.
- searchWord consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Counting Words With a Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |
| Using Built-In Function | C++, Java, Python3 |
| Using Trie | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // List to store the words from the sentence
        vector<string> wordsList;
        // String to build the current word
        string currentWord;

        // Iterate through each character in the sentence
        for (char character : sentence) {
            if (character != ' ') {
                // Append the character to the current word
                currentWord += character;
            } else {
                // If we encounter a space, add the current word to the list
                if (!currentWord.empty()) {
                    wordsList.push_back(currentWord);
                    currentWord = "";  // Reset the string
                }
            }
        }
        // Add the last word if the sentence doesn't end with a space
        if (!currentWord.empty()) {
            wordsList.push_back(currentWord);
        }

        // Iterate through the list of words to find the prefix match
        for (int wordIndex = 0; wordIndex < wordsList.size(); ++wordIndex) {
            if (wordsList[wordIndex].length() >= searchWord.length()) {
                bool isMatch = true;
                for (int charIndex = 0; charIndex < searchWord.length();
                     ++charIndex) {
                    if (wordsList[wordIndex][charIndex] !=
                        searchWord[charIndex]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) {
                    return wordIndex + 1;  // Return 1-based index
                }
            }
        }
        return -1;  // Return -1 if no match is found
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        // List to store the words from the sentence
        List<String> wordsList = new ArrayList<>();
        // StringBuilder to build the current word
        StringBuilder currentWord = new StringBuilder();

        // Iterate through each character in the sentence
        for (char character : sentence.toCharArray()) {
            if (character != ' ') {
                // Append the character to the current word
                currentWord.append(character);
            } else {
                // If we encounter a space, add the current word to the list
                if (currentWord.length() > 0) {
                    wordsList.add(currentWord.toString());
                    currentWord.setLength(0); // Reset the StringBuilder
                }
            }
        }
        // Add the last word if the sentence doesn't end with a space
        if (currentWord.length() > 0) {
            wordsList.add(currentWord.toString());
        }

        // Iterate through the list of words to find the prefix match
        for (int wordIndex = 0; wordIndex < wordsList.size(); ++wordIndex) {
            String word = wordsList.get(wordIndex);
            if (word.length() >= searchWord.length()) {
                boolean isMatch = true;
                for (
                    int charIndex = 0;
                    charIndex < searchWord.length();
                    ++charIndex
                ) {
                    if (
                        word.charAt(charIndex) != searchWord.charAt(charIndex)
                    ) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) {
                    return wordIndex + 1; // Return 1-based index
                }
            }
        }
        return -1; // Return -1 if no match is found
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # List to store the words from the sentence
        words_list = []
        # String to build the current word
        current_word = ""

        # Iterate through each character in the sentence
        for character in sentence:
            if character != " ":
                # Append the character to the current word
                current_word += character
            else:
                # If we encounter a space, add the current word to the list
                if current_word:
                    words_list.append(current_word)
                    current_word = ""  # Reset the string

        # Add the last word if the sentence doesn't end with a space
        if current_word:
            words_list.append(current_word)

        # Iterate through the list of words to find the prefix match
        for word_index, word in enumerate(words_list):
            if len(word) >= len(searchWord):
                is_match = True
                for char_index in range(len(searchWord)):
                    if word[char_index] != searchWord[char_index]:
                        is_match = False
                        break
                if is_match:
                    return word_index + 1  # Return 1-based index

        return -1  # Return -1 if no match is found
```

</details>

<br>

## Approach 2: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize the word position counter
        int currentWordPosition = 1;
        // Initialize the current index in the sentence
        int currentIndex = 0;
        // Get the length of the sentence
        int sentenceLength = sentence.length();

        // Loop through the sentence
        while (currentIndex < sentenceLength) {
            // Skip leading spaces
            while (currentIndex < sentenceLength &&
                   sentence[currentIndex] == ' ') {
                currentIndex++;
                currentWordPosition++;
            }

            // Check if the current word starts with searchWord
            int matchCount = 0;
            while (currentIndex < sentenceLength &&
                   matchCount < searchWord.length() &&
                   sentence[currentIndex] == searchWord[matchCount]) {
                currentIndex++;
                matchCount++;
            }

            // If the entire searchWord matches, return the current word
            // position
            if (matchCount == searchWord.length()) {
                return currentWordPosition;
            }

            // Move to the end of the current word
            while (currentIndex < sentenceLength &&
                   sentence[currentIndex] != ' ') {
                currentIndex++;
            }
        }
        // If no match is found, return -1
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        // Check for invalid input
        if (
            sentence == null ||
            searchWord == null ||
            searchWord.length() > sentence.length()
        ) {
            return -1;
        }

        // Initialize the word position counter
        int currentWordPosition = 1;
        // Initialize the current index in the sentence
        int currentIndex = 0;
        // Get the length of the sentence
        int sentenceLength = sentence.length();

        // Loop through the sentence
        while (currentIndex < sentenceLength) {
            // Skip leading spaces
            while (
                currentIndex < sentenceLength &&
                sentence.charAt(currentIndex) == ' '
            ) {
                currentWordPosition++;
                while (
                    currentIndex < sentenceLength &&
                    sentence.charAt(currentIndex) == ' '
                ) {
                    currentIndex++;
                }
            }

            // Check if the current word starts with searchWord
            int matchCount = 0;
            while (
                currentIndex < sentenceLength &&
                matchCount < searchWord.length() &&
                sentence.charAt(currentIndex) == searchWord.charAt(matchCount)
            ) {
                currentIndex++;
                matchCount++;
            }

            // If the entire searchWord matches, return the current word position
            if (matchCount == searchWord.length()) {
                return currentWordPosition;
            }

            // Move to the end of the current word
            while (
                currentIndex < sentenceLength &&
                sentence.charAt(currentIndex) != ' '
            ) {
                currentIndex++;
            }
        }

        // If no match is found, return -1
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # Initialize the word position counter
        current_word_position = 1
        # Initialize the current index in the sentence
        current_index = 0
        # Get the length of the sentence
        sentence_length = len(sentence)

        # Loop through the sentence
        while current_index < sentence_length:
            # Skip leading spaces
            while (
                current_index < sentence_length
                and sentence[current_index] == " "
            ):
                current_index += 1
                current_word_position += 1

            # Check if the current word starts with searchWord
            matchCount = 0
            while (
                current_index < sentence_length
                and matchCount < len(searchWord)
                and sentence[current_index] == searchWord[matchCount]
            ):
                current_index += 1
                matchCount += 1

            # If the entire searchWord matches, return the current word position
            if matchCount == len(searchWord):
                return current_word_position

            # Move to the end of the current word
            while (
                current_index < sentence_length
                and sentence[current_index] != " "
            ):
                current_index += 1

        # If no match is found, return -1
        return -1
```

</details>

<br>

## Approach 3: Using Built-In Function

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize a string stream to read words from the sentence
        istringstream sentenceStream(sentence);
        string currentWord;

        // Start counting word positions from 1
        int wordPosition = 1;

        // Loop through each word in the sentence
        while (sentenceStream >> currentWord) {
            // Check if the current word is long enough to contain the
            // searchWord as a prefix and if the prefix matches the searchWord
            if (currentWord.length() >= searchWord.length() &&
                currentWord.compare(0, searchWord.length(), searchWord) == 0) {
                // If a match is found, return the current word position
                return wordPosition;
            }
            // Move to the next word position
            wordPosition++;
        }
        // If no match is found, return -1
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        // Split the sentence into words
        String[] words = sentence.split(" ");
        // Iterate over the words with their positions
        for (int i = 0; i < words.length; i++) {
            // Check if the current word is long enough to contain the searchWord as a prefix
            // and if the prefix matches the searchWord
            if (
                words[i].length() >= searchWord.length() &&
                words[i].substring(0, searchWord.length()).equals(searchWord)
            ) {
                // If a match is found, return the current word position (adjusted to 1-based index)
                return i + 1;
            }
        }
        // If no match is found, return -1
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # Split the sentence into words
        words = sentence.split()
        # Iterate over the words with their positions (starting from 1)
        for i, word in enumerate(words, 1):
            # Check if the current word starts with the searchWord
            if word[: len(searchWord)] == searchWord:
                # If a match is found, return the current word position
                return i
        # If no match is found, return -1
        return -1
```

</details>

<br>

## Approach 4: Using Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<int> currentWordPosition;

    TrieNode() {}
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void addToTrie(const string& word, int currentWordPosition) {
        TrieNode* node = root;
        for (char c : word) {
            // If the current character is not in the children, create a new
            // node
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            // Store the position of the current word in the node
            node->currentWordPosition.push_back(currentWordPosition);
        }
    }

    vector<int> checkPrefix(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            // If the character is not found, the prefix does not exist
            if (node->children.find(c) == node->children.end()) {
                return {};
            }
            node = node->children[c];
        }
        // Return the list of word positions where the prefix matches
        return node->currentWordPosition;
    }
};

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        Trie trie;
        istringstream iss(sentence);
        string word;
        int currentWordPosition = 1;

        // Split the sentence into words and add each word to the Trie
        while (iss >> word) {
            trie.addToTrie(word, currentWordPosition);
            currentWordPosition++;
        }

        // Check if the searchWord is a prefix of any word in the Trie
        vector<int> currentWordPositions = trie.checkPrefix(searchWord);

        // Return the smallest word position where the prefix matches, or -1 if
        // not found
        return currentWordPositions.empty()
                   ? -1
                   : *min_element(currentWordPositions.begin(),
                                  currentWordPositions.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    Map<Character, TrieNode> children;
    List<Integer> currentWordPosition;

    public TrieNode() {
        children = new HashMap<>();
        currentWordPosition = new ArrayList<>();
    }
}

class Trie {

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void addToTrie(String word, int currentWordPosition) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            // If the current character is not in the children, create a new node
            if (!node.children.containsKey(c)) {
                node.children.put(c, new TrieNode());
            }
            node = node.children.get(c);
            // Store the position of the current word in the node
            node.currentWordPosition.add(currentWordPosition);
        }
    }

    public List<Integer> checkPrefix(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            // If the character is not found, the prefix does not exist
            if (!node.children.containsKey(c)) {
                return new ArrayList<>();
            }
            node = node.children.get(c);
        }
        // Return the list of word positions where the prefix matches
        return node.currentWordPosition;
    }
}

class Solution {

    public int isPrefixOfWord(String sentence, String searchWord) {
        Trie trie = new Trie();
        String[] words = sentence.split(" ");
        // Split the sentence into words and add each word to the Trie
        for (
            int currentWordPosition = 1;
            currentWordPosition <= words.length;
            currentWordPosition++
        ) {
            trie.addToTrie(words[currentWordPosition - 1], currentWordPosition);
        }

        // Check if the searchWord is a prefix of any word in the Trie
        List<Integer> currentWordPositions = trie.checkPrefix(searchWord);
        // Return the smallest word position where the prefix matches, or -1 if not found
        return currentWordPositions.isEmpty()
            ? -1
            : Collections.min(currentWordPositions);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.current_word_position = []


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add_to_trie(self, word, current_word_position):
        root = self.root
        for c in word:
            # If the current character is not in the children, create a new node implicitly via defaultdict
            root = root.children[c]
            # Store the position of the current word in the node
            root.current_word_position.append(current_word_position)

    def check_prefix(self, word):
        root = self.root
        for c in word:
            # If the character is not found, the prefix does not exist
            if c not in root.children:
                return []
            root = root.children[c]

        # Return the list of word positions where the prefix matches
        return root.current_word_position


class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        trie = Trie()
        words = sentence.split(" ")

        # Split the sentence into words and add each word to the Trie
        for current_word_position, word in enumerate(words, 1):
            trie.add_to_trie(word, current_word_position)

        # Check if the searchWord is a prefix of any word in the Trie
        current_word_position = trie.check_prefix(searchWord)

        # Return the smallest word position where the prefix matches, or -1 if not found
        return min(current_word_position) if current_word_position else -1
```

</details>
