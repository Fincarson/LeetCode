# 2185. Counting Words With a Given Prefix

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/counting-words-with-a-given-prefix/)  
`Array` `String` `String Matching`

**Problem Link:** [LeetCode 2185 - Counting Words With a Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

## Problem

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

### Example 1

```text
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
```

### Example 2

```text
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length, pref.length <= 100
- words[i] and pref consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check If a Word Occurs As a Prefix of Any Word in a Sentence](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2185. Counting Words With a Given Prefix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Built-In Methods | C++, Java, Python3 |
| Trie | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            count += hasPrefix(word, pref);
        }
        return count;
    }

private:
    // Returns 1 if str has pref as prefix, 0 otherwise
    int hasPrefix(string& str, string& pref) {
        int itr;
        // Compare characters until we reach the end of either string
        for (itr = 0; itr < str.length() && itr < pref.length(); itr++) {
            if (str[itr] != pref[itr]) {
                return 0;  // Mismatch found
            }
        }

        // Check if we've matched the entire prefix
        if (itr != pref.length()) {
            return 0;  // str is shorter than pref
        }
        return 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int prefixCount(String[] words, String pref) {
        int count = 0;
        for (String word : words) {
            count += hasPrefix(word, pref);
        }
        return count;
    }

    // Returns 1 if str has pref as prefix, 0 otherwise
    private int hasPrefix(String str, String pref) {
        int itr;
        // Compare characters until we reach end of either string
        for (itr = 0; itr < str.length() && itr < pref.length(); itr++) {
            if (str.charAt(itr) != pref.charAt(itr)) {
                return 0; // Mismatch found
            }
        }

        // Check if we've matched entire prefix
        if (itr != pref.length()) {
            return 0; // str is shorter than pref
        }
        return 1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        for word in words:
            count += self._has_prefix(word, pref)
        return count

    # Returns 1 if str has pref as prefix, 0 otherwise
    def _has_prefix(self, str: str, pref: str) -> int:
        itr = 0
        # Compare characters until we reach the end of either string
        while itr < len(str) and itr < len(pref):
            if str[itr] != pref[itr]:
                return 0  # Mismatch found
            itr += 1

        # Check if we've matched the entire prefix
        if itr != len(pref):
            return 0  # str is shorter than pref
        return 1
```

</details>

<br>

## Approach 2: Built-In Methods

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;  // Found a string with pref as prefix
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int prefixCount(String[] words, String pref) {
        int count = 0;
        for (String word : words) {
            if (word.startsWith(pref)) {
                count++; // Found a string with pref as prefix
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(word.startswith(pref) for word in words)
```

</details>

<br>

## Approach 3: Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        // Add all words to trie
        for (string& word : words) {
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

private:
    class Trie {
        // Node class represents each character in Trie
        struct Node {
            // Links to child nodes
            vector<Node*> links;
            // Number of strings having prefix till this node
            int count;

            Node() : links(26, nullptr), count(0) {}
        };

        Node* root;

    public:
        Trie() { root = new Node(); }

        // Add word to trie and update prefix counts
        void addWord(string& word) {
            Node* curr = root;
            for (char c : word) {
                if (curr->links[c - 'a'] == nullptr) {
                    curr->links[c - 'a'] = new Node();
                }
                curr = curr->links[c - 'a'];
                curr->count++;  // Increment count for this prefix
            }
        }

        // Return count of strings having pref as prefix
        int countPrefix(string& pref) {
            Node* curr = root;
            for (char c : pref) {
                if (curr->links[c - 'a'] == nullptr) {
                    return 0;  // Prefix not found
                }
                curr = curr->links[c - 'a'];
            }
            return curr->count;  // Return count at last node
        }
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int prefixCount(String[] words, String pref) {
        int count = 0;
        Trie trie = new Trie();

        // Add all words to trie
        for (String word : words) {
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

    private class Trie {

        // Node class represents each character in Trie
        class Node {

            // Links to child nodes
            Node[] links;
            // Number of strings having prefix till this node
            int count;

            Node() {
                // For lowercase English letters
                links = new Node[26];
                count = 0;
            }
        }

        Node root;

        Trie() {
            root = new Node();
        }

        // Add word to trie and update prefix counts
        public void addWord(String word) {
            Node curr = root;
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                if (curr.links[c - 'a'] == null) {
                    curr.links[c - 'a'] = new Node();
                }
                curr = curr.links[c - 'a'];
                curr.count++; // Increment count for this prefix
            }
        }

        // Return count of strings having pref as prefix
        public int countPrefix(String pref) {
            Node curr = root;
            for (int i = 0; i < pref.length(); i++) {
                char c = pref.charAt(i);
                if (curr.links[c - 'a'] == null) {
                    return 0; // Prefix not found
                }
                curr = curr.links[c - 'a'];
            }
            return curr.count; // Return count at last node
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        trie = self._Trie()

        # Add all words to trie
        for word in words:
            trie._add_word(word)
        return trie._count_prefix(pref)

    class _Trie:
        # Node class represents each character in Trie
        class _Node:
            def __init__(self):
                # Links to child nodes
                self.links = [None] * 26
                # Number of strings having prefix till this node
                self.count = 0

        def __init__(self):
            self.root = self._Node()

        # Add word to trie and update prefix counts
        def _add_word(self, word: str) -> None:
            curr = self.root
            for c in word:
                idx = ord(c) - ord("a")
                if curr.links[idx] is None:
                    curr.links[idx] = self._Node()
                curr = curr.links[idx]
                curr.count += 1  # Increment count for this prefix

        # Return count of strings having pref as prefix
        def _count_prefix(self, pref: str) -> int:
            curr = self.root
            for c in pref:
                idx = ord(c) - ord("a")
                if curr.links[idx] is None:
                    return 0  # Prefix not found
                curr = curr.links[idx]
            return curr.count  # Return count at last node
```

</details>
