# 745. Prefix and Suffix Search

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/prefix-and-suffix-search/)  
`Array` `Hash Table` `String` `Design` `Trie`

**Problem Link:** [LeetCode 745 - Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)

## Problem

Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

- WordFilter(string[] words) Initializes the object with the words in the dictionary.
- f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

### Example 1

```text
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = "e".
```

## Constraints

- 1 <= words.length <= 104
- 1 <= words[i].length <= 7
- 1 <= pref.length, suff.length <= 7
- words[i], pref and suff consist of lowercase English letters only.
- At most 104 calls will be made to the function f.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 745. Prefix and Suffix Search

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Trie + Set Intersection [Time Limit Exceeded] | Java, Python3 |
| Approach #2: Paired Trie [Accepted] | Java, Python3 |
| Approach #3: Trie of Suffix Wrapped Words [Accepted] | Java, Python3 |

## Approach #1: Trie + Set Intersection [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class WordFilter {
    TrieNode trie1, trie2;
    public WordFilter(String[] words) {
        trie1 = new TrieNode();
        trie2 = new TrieNode();
        int wt = 0;
        for (String word: words) {
            char[] ca = word.toCharArray();

            TrieNode cur = trie1;
            cur.weight.add(wt);
            for (char letter: ca) {
                if (cur.children[letter - 'a'] == null) {
                    cur.children[letter - 'a'] = new TrieNode();
                }
                cur = cur.children[letter - 'a'];
                cur.weight.add(wt);
            }

            cur = trie2;
            cur.weight.add(wt);
            for (int j = ca.length - 1; j >= 0; --j) {
                char letter = ca[j];
                if (cur.children[letter - 'a'] == null) {
                    cur.children[letter - 'a'] = new TrieNode();
                }
                cur = cur.children[letter - 'a'];
                cur.weight.add(wt);
            }
            wt++;
        }
    }

    public int f(String prefix, String suffix) {
        TrieNode cur1 = trie1, cur2 = trie2;
        for (char letter: prefix.toCharArray()) {
            if (cur1.children[letter - 'a'] == null) {
                return -1;
            }
            cur1 = cur1.children[letter - 'a'];
        }
        char[] ca = suffix.toCharArray();
        for (int j = ca.length - 1; j >= 0; --j) {
            char letter = ca[j];
            if (cur2.children[letter - 'a'] == null) {
                return -1;
            }
            cur2 = cur2.children[letter - 'a'];
        }

        int ans = -1;
        for (int w1: cur1.weight) {
            if (w1 > ans && cur2.weight.contains(w1)) {
                ans = w1;
            }
        }

        return ans;
    }
}

class TrieNode {
    TrieNode[] children;
    Set<Integer> weight;
    public TrieNode() {
        children = new TrieNode[26];
        weight = new HashSet();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
Trie = lambda: collections.defaultdict(Trie)
WEIGHT = False

class WordFilter:
    def __init__(self, words: List[str]):
        self.trie1 = Trie() #prefix
        self.trie2 = Trie() #suffix
        for weight, word in enumerate(words):
            cur = self.trie1
            self.addw(cur, weight)
            for letter in word:
                cur = cur[letter]
                self.addw(cur, weight)

            cur = self.trie2
            self.addw(cur, weight)
            for letter in word[::-1]:
                cur = cur[letter]
                self.addw(cur, weight)

    def addw(self, node, w):
        if WEIGHT not in node:
            node[WEIGHT] = {w}
        else:
            node[WEIGHT].add(w)

    def f(self, pref: str, suff: str) -> int:
        cur1 = self.trie1
        for letter in pref:
            if letter not in cur1:
                return -1
            cur1 = cur1[letter]

        cur2 = self.trie2
        for letter in suff[::-1]:
            if letter not in cur2: r
                eturn -1
            cur2 = cur2[letter]

        return max(cur1[WEIGHT] & cur2[WEIGHT], default=-1)
```

</details>

<br>

## Approach #2: Paired Trie [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class WordFilter {
    TrieNode trie;
    public WordFilter(String[] words) {
        trie = new TrieNode();
        int wt = 0;
        for (String word: words) {
            TrieNode cur = trie;
            cur.weight = wt;
            int L = word.length();
            char[] chars = word.toCharArray();
            for (int i = 0; i < L; ++i) {

                TrieNode tmp = cur;
                for (int j = i; j < L; ++j) {
                    int code = (chars[j] - '`') * 27;
                    if (tmp.children.get(code) == null) {
                        tmp.children.put(code, new TrieNode());
                    }
                    tmp = tmp.children.get(code);
                    tmp.weight = wt;
                }

                tmp = cur;
                for (int k = L - 1 - i; k >= 0; --k) {
                    int code = (chars[k] - '`');
                    if (tmp.children.get(code) == null) {
                        tmp.children.put(code, new TrieNode());
                    }
                    tmp = tmp.children.get(code);
                    tmp.weight = wt;
                }

                int code = (chars[i] - '`') * 27 + (chars[L - 1 - i] - '`');
                if (cur.children.get(code) == null) {
                    cur.children.put(code, new TrieNode());
                }
                cur = cur.children.get(code);
                cur.weight = wt;

            }
            wt++;
        }
    }

    public int f(String prefix, String suffix) {
        TrieNode cur = trie;
        int i = 0, j = suffix.length() - 1;
        while (i < prefix.length() || j >= 0) {
            char c1 = i < prefix.length() ? prefix.charAt(i) : '`';
            char c2 = j >= 0 ? suffix.charAt(j) : '`';
            int code = (c1 - '`') * 27 + (c2 - '`');
            cur = cur.children.get(code);
            if (cur == null) {
                return -1;
            }
            i++;
            j--;
        }
        return cur.weight;
    }
}

class TrieNode {
    Map<Integer, TrieNode> children;
    int weight;
    public TrieNode() {
        children = new HashMap();
        weight = 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
Trie = lambda: collections.defaultdict(Trie)
WEIGHT = False

class WordFilter:
    def __init__(self, words: List[str]):
        self.trie = Trie()

        for weight, word in enumerate(words):
            cur = self.trie
            cur[WEIGHT] = weight
            for i, x in enumerate(word):
                #Put all prefixes and suffixes
                tmp = cur
                for letter in word[i:]:
                    tmp = tmp[letter, None]
                    tmp[WEIGHT] = weight

                tmp = cur
                for letter in word[:-i or None][::-1]:
                    tmp = tmp[None, letter]
                    tmp[WEIGHT] = weight

                #Advance letters
                cur = cur[x, word[~i]]
                cur[WEIGHT] = weight

    def f(self, pref: str, suff: str) -> int:
        cur = self.trie
        for a, b in zip_longest(pref, suff[::-1]):
            if (a, b) not in cur:
                return -1
            cur = cur[a, b]
        return cur[WEIGHT]
```

</details>

<br>

## Approach #3: Trie of Suffix Wrapped Words [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class WordFilter {
    TrieNode trie;
    public WordFilter(String[] words) {
        trie = new TrieNode();
        for (int weight = 0; weight < words.length; ++weight) {
            String word = words[weight] + "{";
            for (int i = 0; i < word.length(); ++i) {
                TrieNode cur = trie;
                cur.weight = weight;
                for (int j = i; j < 2 * word.length() - 1; ++j) {
                    int k = word.charAt(j % word.length()) - 'a';
                    if (cur.children[k] == null) {
                        cur.children[k] = new TrieNode();
                    }
                    cur = cur.children[k];
                    cur.weight = weight;
                }
            }
        }
    }
    public int f(String prefix, String suffix) {
        TrieNode cur = trie;
        for (char letter: (suffix + '{' + prefix).toCharArray()) {
            if (cur.children[letter - 'a'] == null) {
                return -1;
            }
            cur = cur.children[letter - 'a'];
        }
        return cur.weight;
    }
}

class TrieNode {
    TrieNode[] children;
    int weight;
    public TrieNode() {
        children = new TrieNode[27];
        weight = 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
Trie = lambda: collections.defaultdict(Trie)
WEIGHT = False

class WordFilter:
    def __init__(self, words: List[str]):
        self.trie = Trie()

        for weight, word in enumerate(words):
            word += '#'
            for i in range(len(word)):
                cur = self.trie
                cur[WEIGHT] = weight
                for j in range(i, 2 * len(word) - 1):
                    cur = cur[word[j % len(word)]]
                    cur[WEIGHT] = weight

    def f(self, pref: str, suff: str) -> int:
        cur = self.trie
        for letter in suff + '#' + pref:
            if letter not in cur:
                return -1
            cur = cur[letter]
        return cur[WEIGHT]
```

</details>
