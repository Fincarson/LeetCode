# 792. Number of Matching Subsequences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/number-of-matching-subsequences/)  
`Array` `Hash Table` `String` `Binary Search` `Dynamic Programming` `Trie` `Sorting`

**Problem Link:** [LeetCode 792 - Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)

## Problem

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, "ace" is a subsequence of "abcde".

### Example 1

```text
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
```

### Example 2

```text
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
```

## Constraints

- 1 <= s.length <= 5 * 104
- 1 <= words.length <= 5000
- 1 <= words[i].length <= 50
- s and words[i] consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 792. Number of Matching Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Time Limit Exceeded] | Java, Python |
| Approach #2: Next Letter Pointers [Accepted] | Java, Python |

## Approach #1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    char[] ca, cb;
    public int numMatchingSubseq(String S, String[] words) {
        int ans = 0;
        ca = S.toCharArray();
        for (String word: words)
            if (subseq(word)) ans++;
        return ans;
    }

    public boolean subseq(String word) {
        int i = 0;
        cb = word.toCharArray();
        for (char c: ca) {
            if (i < cb.length && c == cb[i]) i++;
        }
        return (i == cb.length);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numMatchingSubseq(self, S, words):
        def subseq(word):
           it = iter(S)
           return all(x in it for x in word)

        return sum(subseq(word) for word in words)
```

</details>

<br>

## Approach #2: Next Letter Pointers [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        int ans = 0;
        ArrayList<Node>[] heads = new ArrayList[26];
        for (int i = 0; i < 26; ++i)
            heads[i] = new ArrayList<Node>();

        for (String word: words)
            heads[word.charAt(0) - 'a'].add(new Node(word, 0));

        for (char c: S.toCharArray()) {
            ArrayList<Node> old_bucket = heads[c - 'a'];
            heads[c - 'a'] = new ArrayList<Node>();

            for (Node node: old_bucket) {
                node.index++;
                if (node.index == node.word.length()) {
                    ans++;
                } else {
                    heads[node.word.charAt(node.index) - 'a'].add(node);
                }
            }
            old_bucket.clear();
        }
        return ans;
    }

}

class Node {
    String word;
    int index;
    public Node(String w, int i) {
        word = w;
        index = i;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def numMatchingSubseq(self, S, words):
        ans = 0
        heads = [[] for _ in xrange(26)]
        for word in words:
            it = iter(word)
            heads[ord(next(it)) - ord('a')].append(it)

        for letter in S:
            letter_index = ord(letter) - ord('a')
            old_bucket = heads[letter_index]
            heads[letter_index] = []

            while old_bucket:
                it = old_bucket.pop()
                nxt = next(it, None)
                if nxt:
                    heads[ord(nxt) - ord('a')].append(it)
                else:
                    ans += 1

        return ans
```

</details>
