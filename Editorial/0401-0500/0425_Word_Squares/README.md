# 425. Word Squares

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/word-squares/)  
`Array` `String` `Backtracking` `Trie`

**Problem Link:** [LeetCode 425 - Word Squares](https://leetcode.com/problems/word-squares/)

## Problem

Given an array of unique strings words, return all the word squares you can build from words. The same word from words can be used multiple times. You can return the answer in any order.

A sequence of strings forms a valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).

- For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

### Example 1

```text
Input: words = ["area","lead","wall","lady","ball"]
Output: [["ball","area","lead","lady"],["wall","area","lead","lady"]]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
```

### Example 2

```text
Input: words = ["abat","baba","atan","atal"]
Output: [["baba","abat","baba","atal"],["baba","abat","baba","atan"]]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 4
- All words[i] have the same length.
- words[i] consists of only lowercase English letters.
- All words[i] are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Word Square](https://leetcode.com/problems/valid-word-square/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 425. Word Squares

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking with HashTable | Java, Python |
| Backtracking with Trie | Java, Python |

## Approach 1: Backtracking with HashTable

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  int N = 0;
  String[] words = null;
  HashMap<String, List<String>> prefixHashTable = null;

  public List<List<String>> wordSquares(String[] words) {
    this.words = words;
    this.N = words[0].length();

    List<List<String>> results = new ArrayList<List<String>>();
    this.buildPrefixHashTable(words);

    for (String word : words) {
      LinkedList<String> wordSquares = new LinkedList<String>();
      wordSquares.addLast(word);
      this.backtracking(1, wordSquares, results);
    }
    return results;
  }

  protected void backtracking(int step, LinkedList<String> wordSquares,
                              List<List<String>> results) {
    if (step == N) {
      results.add((List<String>) wordSquares.clone());
      return;
    }

    StringBuilder prefix = new StringBuilder();
    for (String word : wordSquares) {
      prefix.append(word.charAt(step));
    }

    for (String candidate : this.getWordsWithPrefix(prefix.toString())) {
      wordSquares.addLast(candidate);
      this.backtracking(step + 1, wordSquares, results);
      wordSquares.removeLast();
    }
  }

  protected void buildPrefixHashTable(String[] words) {
    this.prefixHashTable = new HashMap<String, List<String>>();

    for (String word : words) {
      for (int i = 1; i < this.N; ++i) {
        String prefix = word.substring(0, i);
        List<String> wordList = this.prefixHashTable.get(prefix);
        if (wordList == null) {
          wordList = new ArrayList<String>();
          wordList.add(word);
          this.prefixHashTable.put(prefix, wordList);
        } else {
          wordList.add(word);
        }
      }
    }
  }

  protected List<String> getWordsWithPrefix(String prefix) {
    List<String> wordList = this.prefixHashTable.get(prefix);
    return (wordList != null ? wordList : new ArrayList<String>());
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])
        self.buildPrefixHashTable(self.words)

        results = []
        word_squares = []
        for word in words:
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def backtracking(self, step, word_squares, results):
        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        for candidate in self.getWordsWithPrefix(prefix):
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def buildPrefixHashTable(self, words):
        self.prefixHashTable = {}
        for word in words:
            for prefix in (word[:i] for i in range(1, len(word))):
                self.prefixHashTable.setdefault(prefix, set()).add(word)

    def getWordsWithPrefix(self, prefix):
        if prefix in self.prefixHashTable:
            return self.prefixHashTable[prefix]
        else:
            return set([])
```

</details>

<br>

## Approach 2: Backtracking with Trie

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
  HashMap<Character, TrieNode> children = new HashMap<Character, TrieNode>();
  List<Integer> wordList = new ArrayList<Integer>();

  public TrieNode() {}
}


class Solution {
  int N = 0;
  String[] words = null;
  TrieNode trie = null;

  public List<List<String>> wordSquares(String[] words) {
    this.words = words;
    this.N = words[0].length();

    List<List<String>> results = new ArrayList<List<String>>();
    this.buildTrie(words);

    for (String word : words) {
      LinkedList<String> wordSquares = new LinkedList<String>();
      wordSquares.addLast(word);
      this.backtracking(1, wordSquares, results);
    }
    return results;
  }

  protected void backtracking(int step, LinkedList<String> wordSquares,
                              List<List<String>> results) {
    if (step == N) {
      results.add((List<String>) wordSquares.clone());
      return;
    }

    StringBuilder prefix = new StringBuilder();
    for (String word : wordSquares) {
      prefix.append(word.charAt(step));
    }

    for (Integer wordIndex : this.getWordsWithPrefix(prefix.toString())) {
      wordSquares.addLast(this.words[wordIndex]);
      this.backtracking(step + 1, wordSquares, results);
      wordSquares.removeLast();
    }
  }

  protected void buildTrie(String[] words) {
    this.trie = new TrieNode();

    for (int wordIndex = 0; wordIndex < words.length; ++wordIndex) {
      String word = words[wordIndex];

      TrieNode node = this.trie;
      for (Character letter : word.toCharArray()) {
        if (node.children.containsKey(letter)) {
          node = node.children.get(letter);
        } else {
          TrieNode newNode = new TrieNode();
          node.children.put(letter, newNode);
          node = newNode;
        }
        node.wordList.add(wordIndex);
      }
    }
  }

  protected List<Integer> getWordsWithPrefix(String prefix) {
    TrieNode node = this.trie;
    for (Character letter : prefix.toCharArray()) {
      if (node.children.containsKey(letter)) {
        node = node.children.get(letter);
      } else {
        // return an empty list.
        return new ArrayList<Integer>();
      }
    }
    return node.wordList;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:

    def wordSquares(self, words: List[str]) -> List[List[str]]:

        self.words = words
        self.N = len(words[0])
        self.buildTrie(self.words)

        results = []
        word_squares = []
        for word in words:
            word_squares = [word]
            self.backtracking(1, word_squares, results)
        return results

    def buildTrie(self, words):
        self.trie = {}

        for wordIndex, word in enumerate(words):
            node = self.trie
            for char in word:
                if char in node:
                    node = node[char]
                else:
                    newNode = {}
                    newNode['#'] = []
                    node[char] = newNode
                    node = newNode
                node['#'].append(wordIndex)

    def backtracking(self, step, word_squares, results):
        if step == self.N:
            results.append(word_squares[:])
            return

        prefix = ''.join([word[step] for word in word_squares])
        for candidate in self.getWordsWithPrefix(prefix):
            word_squares.append(candidate)
            self.backtracking(step+1, word_squares, results)
            word_squares.pop()

    def getWordsWithPrefix(self, prefix):
        node = self.trie
        for char in prefix:
            if char not in node:
                return []
            node = node[char]
        return [self.words[wordIndex] for wordIndex in node['#']]
```

</details>
