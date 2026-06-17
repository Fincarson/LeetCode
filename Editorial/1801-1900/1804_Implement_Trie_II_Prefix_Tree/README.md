# 1804. Implement Trie II (Prefix Tree)

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)  
`Hash Table` `String` `Design` `Trie`

**Problem Link:** [LeetCode 1804 - Implement Trie II (Prefix Tree)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)

## Problem

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
- int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
- void erase(String word) Erases the string word from the trie.

### Example 1

```text
Input
["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
[[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
Output
[null, null, null, 2, 2, null, 1, 1, null, 0]

Explanation
Trie trie = new Trie();
trie.insert("apple");               // Inserts "apple".
trie.insert("apple");               // Inserts another "apple".
trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
trie.erase("apple");                // Erases one "apple".
trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
trie.countWordsStartingWith("app"); // return 1
trie.erase("apple");                // Erases "apple". Now the trie is empty.
trie.countWordsStartingWith("app"); // return 0
```

## Constraints

- 1 <= word.length, prefix.length <= 2000
- word and prefix consist only of lowercase English letters.
- At most 3 * 104 calls in total will be made to insert, countWordsEqualTo, countWordsStartingWith, and erase.
- It is guaranteed that for any function call to erase, the string word will exist in the trie.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1804. Implement Trie II (Prefix Tree)

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: | C++, Go, Java, JavaScript, Python3 |

## Approach:

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TrieNode {
public:
    TrieNode* links[26];
    int wordsEndingHere = 0;
    int wordsStartingHere = 0;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char& w : word) {
            int charIndex = w - 'a';
            if (!node->links[charIndex]) {
                node->links[charIndex] = new TrieNode();
            }
            node = node->links[charIndex];
            node->wordsStartingHere++;
        }
        node->wordsEndingHere++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char& w : word) {
            int charIndex = w - 'a';
            if (!node->links[charIndex]) {
                return 0;
            }
            node = node->links[charIndex];
        }
        return node->wordsEndingHere;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char& w : prefix) {
            int charIndex = w - 'a';
            if (!node->links[charIndex]) {
                return 0;
            }
            node = node->links[charIndex];
        }
        return node->wordsStartingHere;
    }

    void erase(string word) {
        TrieNode* node = root;
        for (char& w : word) {
            int charIndex = w - 'a';
            node = node->links[charIndex];
            node->wordsStartingHere--;
        }
        node->wordsEndingHere--;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type TrieNode struct {
	links             [26]*TrieNode
	wordsEndingHere   int
	wordsStartingHere int
}

type Trie struct {
	root *TrieNode
}

func Constructor() Trie {
	return Trie{
		root: &TrieNode{},
	}
}

func (this *Trie) Insert(word string) {
	node := this.root
	for _, w := range word {
		charIndex := int(w - 'a')
		if node.links[charIndex] == nil {
			node.links[charIndex] = &TrieNode{}
		}
		node = node.links[charIndex]
        node.wordsStartingHere++
	}
	node.wordsEndingHere++
}

func (this *Trie) CountWordsEqualTo(word string) int {
	node := this.root
	for _, w := range word {
		charIndex := int(w - 'a')
		if node.links[charIndex] == nil {
			return 0
		}
		node = node.links[charIndex]
	}
	return node.wordsEndingHere
}

func (this *Trie) CountWordsStartingWith(prefix string) int {
	node := this.root
	for _, w := range prefix {
		charIndex := int(w - 'a')
		if node.links[charIndex] == nil {
			return 0
		}
		node = node.links[charIndex]
	}
	return node.wordsStartingHere
}

func (this *Trie) Erase(word string) {
	node := this.root
	for _, w := range word {
		charIndex := int(w - 'a')
		node = node.links[charIndex]
        node.wordsStartingHere--
	}
	node.wordsEndingHere--
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {
    TrieNode[] links = new TrieNode[26];
    int wordsEndingHere = 0;
    int wordsStartingHere = 0;
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                node.links[charIndex] = new TrieNode();
            }
            node = node.links[charIndex];
            node.wordsStartingHere++;
        }
        node.wordsEndingHere++;
    }

    public int countWordsEqualTo(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                return 0;
            }
            node = node.links[charIndex];
        }
        return node.wordsEndingHere;
    }

    public int countWordsStartingWith(String prefix) {
        TrieNode node = root;
        for (char w : prefix.toCharArray()) {
            int charIndex = w - 'a';
            if (node.links[charIndex] == null) {
                return 0;
            }
            node = node.links[charIndex];
        }
        return node.wordsStartingHere;
    }

    public void erase(String word) {
        TrieNode node = root;
        for (char w : word.toCharArray()) {
            int charIndex = w - 'a';
            node = node.links[charIndex];
            node.wordsStartingHere--;
        }
        node.wordsEndingHere--;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
class TrieNode {
    constructor() {
        this.links = new Array(26).fill(null);
        this.wordsEndingHere = 0;
        this.wordsStartingHere = 0;
    }
}

var Trie = function() {
    this.root = new TrieNode();
};

Trie.prototype.insert = function(word) {
    let node = this.root;
    for (let w of word) {
        const charIndex = w.charCodeAt(0) - 'a'.charCodeAt(0);
        if (!node.links[charIndex]) {
            node.links[charIndex] = new TrieNode();
        }
        node = node.links[charIndex];
        node.wordsStartingHere++;
    }
    node.wordsEndingHere++;
};

Trie.prototype.countWordsEqualTo = function(word) {
    let node = this.root;
    for (let w of word) {
        const charIndex = w.charCodeAt(0) - 'a'.charCodeAt(0);
        if (!node.links[charIndex]) {
            return 0;
        }
        node = node.links[charIndex];
    }
    return node.wordsEndingHere;
};

Trie.prototype.countWordsStartingWith = function(prefix) {
    let node = this.root;
    for (let w of prefix) {
        const charIndex = w.charCodeAt(0) - 'a'.charCodeAt(0);
        if (!node.links[charIndex]) {
            return 0;
        }
        node = node.links[charIndex];
    }
    return node.wordsStartingHere;
};

Trie.prototype.erase = function(word) {
    let node = this.root;
    for (let w of word) {
        const charIndex = w.charCodeAt(0) - 'a'.charCodeAt(0);
        node = node.links[charIndex];
        node.wordsStartingHere--;
    }
    node.wordsEndingHere--;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TrieNode:
    def __init__(self):
        self.links = [None] * 26
        self.words_ending_here = 0
        self.words_starting_here = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for w in word:
            char_index = ord(w) - ord('a')
            if not node.links[char_index]:
                node.links[char_index] = TrieNode()
            node = node.links[char_index]
            node.words_starting_here += 1
        node.words_ending_here += 1

    def countWordsEqualTo(self, word: str) -> int:
        node = self.root
        for w in word:
            char_index = ord(w) - ord('a')
            if not node.links[char_index]:
                return 0
            node = node.links[char_index]
        return node.words_ending_here

    def countWordsStartingWith(self, prefix: str) -> int:
        node = self.root
        for w in prefix:
            char_index = ord(w) - ord('a')
            if not node.links[char_index]:
                return 0
            node = node.links[char_index]
        return node.words_starting_here

    def erase(self, word: str) -> None:
        node = self.root
        for w in word:
            char_index = ord(w) - ord('a')
            node = node.links[char_index]
            node.words_starting_here -= 1
        node.words_ending_here -= 1
```

</details>
