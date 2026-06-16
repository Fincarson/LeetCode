# 3042. Count Prefix and Suffix Pairs I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/)  
`Array` `String` `Trie` `Rolling Hash` `String Matching` `Hash Function`

**Problem Link:** [LeetCode 3042 - Count Prefix and Suffix Pairs I](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/)

## Problem

You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

- isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.

For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

### Example 1

```text
Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.
```

### Example 2

```text
Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
Therefore, the answer is 2.
```

### Example 3

```text
Input: words = ["abab","ab"]
Output: 0
Explanation: In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
Therefore, the answer is 0.
```

## Constraints

- 1 <= words.length <= 50
- 1 <= words[i].length <= 10
- words[i] consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3042. Count Prefix and Suffix Pairs I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Dual Trie | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Step 1: Iterate through each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string& str1 = words[i];
                string& str2 = words[j];

                // Step 2: Skip if the first string is larger than the second
                if (str1.size() > str2.size()) continue;

                // Step 3: Check if str1 is both the prefix and suffix of str2
                if (str2.find(str1) == 0 &&
                    str2.rfind(str1) == str2.size() - str1.size()) {
                    ++count;
                }
            }
        }

        // Step 4: Return the total count of prefix-suffix pairs
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countPrefixSuffixPairs(String[] words) {
        int n = words.length;
        int count = 0;

        // Step 1: Iterate through each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                String str1 = words[i];
                String str2 = words[j];

                // Step 2: Skip if the first string is larger than the second
                if (str1.length() > str2.length()) continue;

                // Step 3: Check if str1 is both the prefix and suffix of str2
                if (str2.startsWith(str1) && str2.endsWith(str1)) {
                    ++count;
                }
            }
        }

        // Step 4: Return the total count of prefix-suffix pairs
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        count = 0

        # Step 1: Iterate through each pair of words
        for i in range(n):
            for j in range(i + 1, n):
                str1 = words[i]
                str2 = words[j]

                # Step 2: Skip if the first string is larger than the second
                if len(str1) > len(str2):
                    continue

                # Step 3: Check if str1 is both the prefix and suffix of str2
                if str2.startswith(str1) and str2.endswith(str1):
                    count += 1

        # Step 4: Return the total count of prefix-suffix pairs
        return count
```

</details>

<br>

## Approach 2: Dual Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Node {
public:
    Node* links[26] = {};

    // Check if the character is present in the current node
    bool contains(char c) { return links[c - 'a'] != NULL; }

    // Insert a new node for the character
    void put(char c, Node* node) { links[c - 'a'] = node; }

    // Get the next node for the character
    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    // Insert a word into the Trie
    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }

    // Check if the Trie contains a given prefix
    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) {
                return false;
            }
            node = node->next(c);
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Step 1: Iterate over each word
        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;

            // Step 2: Insert the current word into the prefix Trie
            prefixTrie.insert(words[i]);

            // Step 3: Reverse the word and insert it into the suffix Trie
            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            // Step 4: Iterate over all previous words
            for (int j = 0; j < i; j++) {
                // Step 5: Skip words[j] if it is longer than words[i]
                if (words[j].size() > words[i].size()) continue;

                // Step 6: Extract the prefix and reversed prefix of words[j]
                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                // Step 7: Check if words[j] is both a prefix and suffix of
                // words[i]
                if (prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }

        // Step 8: Return the total count of valid pairs
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Node {

    private Node[] links = new Node[26];

    // Check if the character is present in the current node
    public boolean contains(char c) {
        return links[c - 'a'] != null;
    }

    // Insert a new node for the character
    public void put(char c, Node node) {
        links[c - 'a'] = node;
    }

    // Get the next node for the character
    public Node next(char c) {
        return links[c - 'a'];
    }
}

class Trie {

    private Node root;

    public Trie() {
        root = new Node();
    }

    // Insert a word into the Trie
    public void insert(String word) {
        Node node = root;
        for (char c : word.toCharArray()) {
            if (!node.contains(c)) {
                node.put(c, new Node());
            }
            node = node.next(c);
        }
    }

    // Check if the Trie contains a given prefix
    public boolean startsWith(String prefix) {
        Node node = root;
        for (char c : prefix.toCharArray()) {
            if (!node.contains(c)) {
                return false;
            }
            node = node.next(c);
        }
        return true;
    }
}

class Solution {

    public int countPrefixSuffixPairs(String[] words) {
        int n = words.length;
        int count = 0;

        // Step 1: Iterate over each word
        for (int i = 0; i < n; i++) {
            Trie prefixTrie = new Trie();
            Trie suffixTrie = new Trie();

            // Step 2: Insert the current word into the prefix Trie
            prefixTrie.insert(words[i]);

            // Step 3: Reverse the word and insert it into the suffix Trie
            String revWord = new StringBuilder(words[i]).reverse().toString();
            suffixTrie.insert(revWord);

            // Step 4: Iterate over all previous words
            for (int j = 0; j < i; j++) {
                // Step 5: Skip words[j] if it is longer than words[i]
                if (words[j].length() > words[i].length()) continue;

                // Step 6: Extract the prefix and reversed prefix of words[j]
                String prefixWord = words[j];
                String revPrefixWord = new StringBuilder(prefixWord)
                    .reverse()
                    .toString();

                // Step 7: Check if words[j] is both a prefix and suffix of words[i]
                if (
                    prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)
                ) {
                    count++;
                }
            }
        }

        // Step 8: Return the total count of valid pairs
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Node:
    def __init__(self):
        self.links = [None] * 26

    # Check if the character is present in the current node
    def _contains(self, c: str) -> bool:
        return self.links[ord(c) - ord("a")] is not None

    # Insert a new node for the character
    def _put(self, c: str, node: "Node") -> None:
        self.links[ord(c) - ord("a")] = node

    # Get the next node for the character
    def _next(self, c: str) -> "Node":
        return self.links[ord(c) - ord("a")]


class Trie:
    def __init__(self):
        self.root = Node()

    # Insert a word into the Trie
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if not node._contains(c):
                node._put(c, Node())
            node = node._next(c)

    # Check if the Trie contains a given prefix
    def starts_with(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if not node._contains(c):
                return False
            node = node._next(c)
        return True


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        count = 0

        # Step 1: Iterate over each word
        for i in range(n):
            prefix_trie = Trie()
            suffix_trie = Trie()

            # Step 2: Insert the current word into the prefix Trie
            prefix_trie.insert(words[i])

            # Step 3: Reverse the word and insert it into the suffix Trie
            rev_word = words[i][::-1]
            suffix_trie.insert(rev_word)

            # Step 4: Iterate over all previous words
            for j in range(i):
                # Step 5: Skip words[j] if it is longer than words[i]
                if len(words[j]) > len(words[i]):
                    continue

                # Step 6: Extract the prefix and reversed prefix of words[j]
                prefix_word = words[j]
                rev_prefix_word = prefix_word[::-1]

                # Step 7: Check if words[j] is both a prefix and suffix of words[i]
                if prefix_trie.starts_with(
                    prefix_word
                ) and suffix_trie.starts_with(rev_prefix_word):
                    count += 1

        # Step 8: Return the total count of valid pairs
        return count
```

</details>
