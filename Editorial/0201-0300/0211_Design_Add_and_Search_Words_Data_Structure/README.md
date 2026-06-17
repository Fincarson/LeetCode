# 211. Design Add and Search Words Data Structure

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-add-and-search-words-data-structure/)  
`String` `Depth-First Search` `Design` `Trie`

**Problem Link:** [LeetCode 211 - Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

## Problem

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

- WordDictionary() Initializes the object.
- void addWord(word) Adds word to the data structure, it can be matched later.
- bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:

```text
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
```

## Constraints

- 1 <= word.length <= 25
- word in addWord consists of lowercase English letters.
- word in search consist of '.' or lowercase English letters.
- There will be at most 2 dots in word for search queries.
- At most 104 calls will be made to addWord and search.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Match Substring After Replacement](https://leetcode.com/problems/match-substring-after-replacement/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Prefix and Suffix Pairs II](https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count Prefix and Suffix Pairs I](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 211. Design Add and Search Words Data Structure

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Trie | C++, Java, Python3 |

## Approach 1: Trie

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode* trie;

public:
    /** Initialize your data structure here. */
    WordDictionary() { trie = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = trie;

        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    Map<Character, TrieNode> children = new HashMap();
    boolean word = false;

    public TrieNode() {}
}

class WordDictionary {
    TrieNode trie;

    /** Initialize your data structure here. */
    public WordDictionary() {
        trie = new TrieNode();
    }

    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = trie;

        for (char ch : word.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                node.children.put(ch, new TrieNode());
            }
            node = node.children.get(ch);
        }
        node.word = true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node = self.trie

        for ch in word:
            if not ch in node:
                node[ch] = {}
            node = node[ch]
        node["$"] = True
```

</details>
