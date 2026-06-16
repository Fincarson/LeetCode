# 208. Implement Trie (Prefix Tree)

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/implement-trie-prefix-tree/)  
`Hash Table` `String` `Design` `Trie`

**Problem Link:** [LeetCode 208 - Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

## Problem

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

### Example 1

```text
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
```

## Constraints

- 1 <= word.length, prefix.length <= 2000
- word and prefix consist only of lowercase English letters.
- At most 3 * 104 calls in total will be made to insert, search, and startsWith.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Replace Words](https://leetcode.com/problems/replace-words/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Implement Magic Dictionary](https://leetcode.com/problems/implement-magic-dictionary/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Implement Trie II (Prefix Tree)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Prefix and Suffix Pairs II](https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Count Prefix and Suffix Pairs I](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 208. Implement Trie (Prefix Tree)

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
private:
    // R links to node children
    TrieNode* links[26];
    bool isEnd;

public:
    TrieNode() {
        // Initialize all links to null
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    // R links to node children
    private TrieNode[] links;

    private final int R = 26;

    private boolean isEnd;

    public TrieNode() {
        links = new TrieNode[R];
    }

    public boolean containsKey(char ch) {
        return links[ch -'a'] != null;
    }
    public TrieNode get(char ch) {
        return links[ch -'a'];
    }
    public void put(char ch, TrieNode node) {
        links[ch -'a'] = node;
    }
    public void setEnd() {
        isEnd = true;
    }
    public boolean isEnd() {
        return isEnd;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class TrieNode:
    def __init__(self):
        # Initialize links array and isEnd flag
        self.links = [None] * 26
        self.is_end = False

    def contains_key(self, ch: str) -> bool:
        return self.links[ord(ch) - ord('a')] is not None

    def get(self, ch: str) -> 'TrieNode':
        return self.links[ord(ch) - ord('a')]

    def put(self, ch: str, node: 'TrieNode') -> None:
        self.links[ord(ch) - ord('a')] = node

    def set_end(self) -> None:
        self.is_end = True

    def is_end(self) -> bool:
        return self.is_end
```

</details>
