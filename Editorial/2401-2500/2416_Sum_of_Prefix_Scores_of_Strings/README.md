# 2416. Sum of Prefix Scores of Strings

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/)  
`Array` `String` `Trie` `Counting`

**Problem Link:** [LeetCode 2416 - Sum of Prefix Scores of Strings](https://leetcode.com/problems/sum-of-prefix-scores-of-strings/)

## Problem

You are given an array words of size n consisting of non-empty strings.

We define the score of a string term as the number of strings words[i] such that term is a prefix of words[i].

- For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".

Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

Note that a string is considered as a prefix of itself.

### Example 1

```text
Input: words = ["abc","ab","bc","b"]
Output: [5,4,3,2]
Explanation: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.
```

### Example 2

```text
Input: words = ["abcd"]
Output: [4]
Explanation:
"abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 = 4.
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 1000
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2416. Sum of Prefix Scores of Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Tries | C++, Java, Python3 |

## Approach: Tries

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0;
};

class Solution {
    // Initialize the root node of the trie.
    TrieNode root;

public:
    // Insert function for the word.
    void insert(string word) {
        auto node = &root;
        for (char c : word) {
            // If new prefix, create a new trie node.
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            // Increment the count of the current prefix.
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }
    // Calculate the prefix count using this function.
    int count(string s) {
        auto node = &root;
        int ans = 0;
        // The ans would store the total sum of counts.
        for (char c : s) {
            ans += node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        // Insert words in trie.
        for (int i = 0; i < N; i++) {
            insert(words[i]);
        }
        vector<int> scores(N, 0);
        for (int i = 0; i < N; i++) {
            // Get the count of all prefixes of given string.
            scores[i] = count(words[i]);
        }
        return scores;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TrieNode {

    TrieNode[] next = new TrieNode[26];
    int cnt = 0;
}

class Solution {

    // Initialize the root node of the trie.
    TrieNode root = new TrieNode();

    // Insert function for the word.
    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            // If new prefix, create a new trie node.
            if (node.next[c - 'a'] == null) {
                node.next[c - 'a'] = new TrieNode();
            }
            // Increment the count of the current prefix.
            node.next[c - 'a'].cnt++;
            node = node.next[c - 'a'];
        }
    }

    // Calculate the prefix count using this function.
    int count(String s) {
        TrieNode node = root;
        int ans = 0;
        // The ans would store the total sum of counts.
        for (char c : s.toCharArray()) {
            ans += node.next[c - 'a'].cnt;
            node = node.next[c - 'a'];
        }
        return ans;
    }

    public int[] sumPrefixScores(String[] words) {
        int N = words.length;
        // Insert words in trie.
        for (int i = 0; i < N; i++) {
            insert(words[i]);
        }
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            // Get the count of all prefixes of given string.
            scores[i] = count(words[i]);
        }
        return scores;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class trie_node:
    def __init__(self):
        self.next = [None] * 26
        self.cnt = 0


class Solution:
    def __init__(self):
        # Initialize the root node of the trie.
        self.root = trie_node()

    # Insert function for the word.
    def insert(self, word):
        node = self.root
        for c in word:
            # If new prefix, create a new trie node.
            if node.next[ord(c) - ord("a")] is None:
                node.next[ord(c) - ord("a")] = trie_node()
            # Increment the count of the current prefix.
            node.next[ord(c) - ord("a")].cnt += 1
            node = node.next[ord(c) - ord("a")]

    # Calculate the prefix count using this function.
    def count(self, s):
        node = self.root
        ans = 0
        # The ans would store the total sum of counts.
        for c in s:
            ans += node.next[ord(c) - ord("a")].cnt
            node = node.next[ord(c) - ord("a")]
        return ans

    def sumPrefixScores(self, words):
        N = len(words)
        # Insert words in trie.
        for i in range(N):
            self.insert(words[i])
        scores = [0] * N
        for i in range(N):
            # Get the count of all prefixes of given string.
            scores[i] = self.count(words[i])
        return scores
```

</details>
