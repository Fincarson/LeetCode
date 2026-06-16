# 820. Short Encoding of Words

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/short-encoding-of-words/)  
`Array` `Hash Table` `String` `Trie`

**Problem Link:** [LeetCode 820 - Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)

## Problem

A valid encoding of an array of words is any reference string s and array of indices indices such that:

- words.length == indices.length
- The reference string s ends with the '#' character.
- For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].

Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

### Example 1

```text
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
```

### Example 2

```text
Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].
```

## Constraints

- 1 <= words.length <= 2000
- 1 <= words[i].length <= 7
- words[i] consists of only lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 820. Short Encoding of Words

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Store Prefixes [Accepted] | Java, Python |
| Approach #2: Trie [Accepted] | Java, Python |

## Approach #1: Store Prefixes [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> good = new HashSet(Arrays.asList(words));
        for (String word: words) {
            for (int k = 1; k < word.length(); ++k)
                good.remove(word.substring(k));
        }

        int ans = 0;
        for (String word: good)
            ans += word.length() + 1;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minimumLengthEncoding(self, words):
        good = set(words)
        for word in words:
            for k in range(1, len(word)):
                good.discard(word[k:])

        return sum(len(word) + 1 for word in good)
```

</details>

<br>

## Approach #2: Trie [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        TrieNode trie = new TrieNode();
        Map<TrieNode, Integer> nodes = new HashMap();

        for (int i = 0; i < words.length; ++i) {
            String word = words[i];
            TrieNode cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur.get(word.charAt(j));
            nodes.put(cur, i);
        }

        int ans = 0;
        for (TrieNode node: nodes.keySet()) {
            if (node.count == 0)
                ans += words[nodes.get(node)].length() + 1;
        }
        return ans;

    }
}

class TrieNode {
    TrieNode[] children;
    int count;
    TrieNode() {
        children = new TrieNode[26];
        count = 0;
    }
    public TrieNode get(char c) {
        if (children[c-'a'] == null) {
            children[c-'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minimumLengthEncoding(self, words):
        words = list(set(words)) #remove duplicates
        #Trie is a nested dictionary with nodes created
        # when fetched entries are missing
        Trie = lambda: collections.defaultdict(Trie)
        trie = Trie()

        #reduce(..., S, trie) is trie[S[0]][S[1]][S[2]][...][S[S.length - 1]]
        nodes = [reduce(dict.__getitem__, word[::-1], trie)
                 for word in words]

        #Add word to the answer if it's node has no neighbors
        return sum(len(word) + 1
                   for i, word in enumerate(words)
                   if len(nodes[i]) == 0)
```

</details>
