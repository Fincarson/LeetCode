# 648. Replace Words

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/replace-words/)  
`Array` `Hash Table` `String` `Trie`

**Problem Link:** [LeetCode 648 - Replace Words](https://leetcode.com/problems/replace-words/)

## Problem

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

### Example 1

```text
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

### Example 2

```text
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```

## Constraints

- 1 <= dictionary.length <= 1000
- 1 <= dictionary[i].length <= 100
- dictionary[i] consists of only lower-case letters.
- 1 <= sentence.length <= 106
- sentence consists of only lower-case letters and spaces.
- The number of words in sentence is in the range [1, 1000]
- The length of each word in sentence is in the range [1, 1000]
- Every two consecutive words in sentence will be separated by exactly one space.
- sentence does not have leading or trailing spaces.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 648. Replace Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Set | C++, Java, Python3 |
| Prefix Trie | C++, Java, Python3 |

## Approach 1: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

        // Replace each word in sentence with the corresponding shortest root
        string word;
        string newSentence;
        while (getline(sStream, word, ' ')) {
            newSentence += shortestRoot(word, dictSet) + " ";
        }

        newSentence.pop_back();  // remove extra space
        return newSentence;
    }

private:
    string shortestRoot(string word, unordered_set<string> dictSet) {
        // Find the shortest root of the word in the dictionary
        for (int i = 1; i <= word.length(); i++) {
            string root = word.substr(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        // There is not a corresponding root in the dictionary
        return word;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String replaceWords(List<String> dictionary, String sentence) {
        String[] wordArray = sentence.split(" ");
        Set<String> dictSet = new HashSet<>(dictionary);

        // Replace each word in sentence with the corresponding shortest root
        for (int i = 0; i < wordArray.length; i++) {
            wordArray[i] = shortestRoot(wordArray[i], dictSet);
        }

        return String.join(" ", wordArray);
    }

    private String shortestRoot(String word, Set<String> dictSet) {
        // Find the shortest root of the word in the dictionary
        for (int i = 1; i <= word.length(); i++) {
            String root = word.substring(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        // There is not a corresponding root in the dictionary
        return word;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        word_array = sentence.split()
        dict_set = set(dictionary)

        def shortest_root(word, dict_set):
            # Find the shortest root of the word in the dictionary
            for i in range(len(word)):
                root = word[0:i]
                if root in dict_set:
                    return root
            # There is not a corresponding root in the dictionary
            return word

        # Replace each word in sentence with the corresponding shortest root
        for word in range(len(word_array)):
            word_array[word] = shortest_root(word_array[word], dict_set)

        return " ".join(word_array)
```

</details>

<br>

## Approach 2: Prefix Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : children(26, nullptr) { isEnd = false; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEnd = true;
    }

    // Find the shortest root of the word in the trie
    string shortestRoot(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr) {
                // There is not a corresponding root in the trie
                return word;
            }
            current = current->children[c - 'a'];
            if (current->isEnd) {
                return word.substr(0, i + 1);
            }
        }
        // There is not a corresponding root in the trie
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);

        Trie dictTrie;
        for (string word : dictionary) {
            dictTrie.insert(word);
        }

        // Replace each word in sentence with the corresponding shortest root
        string word;
        string newSentence;
        while (getline(sStream, word, ' ')) {
            newSentence += dictTrie.shortestRoot(word) + " ";
        }

        newSentence.pop_back();  // remove extra space
        return newSentence;
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

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode current = root;
        for (char c : word.toCharArray()) {
            if (current.children[c - 'a'] == null) {
                current.children[c - 'a'] = new TrieNode();
            }
            current = current.children[c - 'a'];
        }
        current.isEnd = true;
    }

    // Find the shortest root of the word in the trie
    public String shortestRoot(String word) {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (current.children[c - 'a'] == null) {
                // There is not a corresponding root in the trie
                return word;
            }
            current = current.children[c - 'a'];
            if (current.isEnd) {
                return word.substring(0, i + 1);
            }
        }
        // There is not a corresponding root in the trie
        return word;
    }
}

class Solution {

    public String replaceWords(List<String> dictionary, String sentence) {
        String wordArray[] = sentence.split(" ");

        Trie dictTrie = new Trie();
        for (String word : dictionary) {
            dictTrie.insert(word);
        }

        // Replace each word in the sentence with the corresponding shortest root
        for (int word = 0; word < wordArray.length; word++) {
            wordArray[word] = dictTrie.shortestRoot(wordArray[word]);
        }

        return String.join(" ", wordArray);
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
        self.children = [None] * 26


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for c in word:
            if current.children[ord(c) - ord("a")] is None:
                current.children[ord(c) - ord("a")] = TrieNode()
            current = current.children[ord(c) - ord("a")]
        current.isEnd = True

    # Find the shortest root of the word in the trie
    def shortest_root(self, word):
        current = self.root
        for i in range(len(word)):
            c = word[i]
            if current.children[ord(c) - ord("a")] is None:
                # There is not a corresponding root in the trie
                return word
            current = current.children[ord(c) - ord("a")]
            if current.isEnd:
                return word[: i + 1]
        # There is not a corresponding root in the trie
        return word


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        word_array = sentence.split()

        dict_trie = Trie()
        for word in dictionary:
            dict_trie.insert(word)

        # Replace each word in the sentence with the corresponding shortest root
        for word in range(len(word_array)):
            word_array[word] = dict_trie.shortest_root(word_array[word])

        return " ".join(word_array)
```

</details>
