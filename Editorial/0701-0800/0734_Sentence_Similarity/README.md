# 734. Sentence Similarity

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sentence-similarity/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 734 - Sentence Similarity](https://leetcode.com/problems/sentence-similarity/)

## Problem

We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

- They have the same length (i.e., the same number of words)
- sentence1[i] and sentence2[i] are similar.

Notice that a word is always similar to itself, also notice that the similarity relation is not transitive. For example, if the words a and b are similar, and the words b and c are similar, a and c are not necessarily similar.

### Example 1

```text
Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","fine"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
```

### Example 2

```text
Input: sentence1 = ["great"], sentence2 = ["great"], similarPairs = []
Output: true
Explanation: A word is similar to itself.
```

### Example 3

```text
Input: sentence1 = ["great"], sentence2 = ["doubleplus","good"], similarPairs = [["great","doubleplus"]]
Output: false
Explanation: As they don't have the same length, we return false.
```

## Constraints

- 1 <= sentence1.length, sentence2.length <= 1000
- 1 <= sentence1[i].length, sentence2[i].length <= 20
- sentence1[i] and sentence2[i] consist of English letters.
- 0 <= similarPairs.length <= 1000
- similarPairs[i].length == 2
- 1 <= xi.length, yi.length <= 20
- xi and yi consist of lower-case and upper-case English letters.
- All the pairs (xi, yi) are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Accounts Merge](https://leetcode.com/problems/accounts-merge/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sentence Similarity II](https://leetcode.com/problems/sentence-similarity-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 734. Sentence Similarity

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Using Hash Map and Hash Set | C++, Java, Python3 |

## Approach: Using Hash Map and Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        unordered_map<string, unordered_set<string>> wordToSimilarWords;
        for (auto& pair : similarPairs) {
            wordToSimilarWords[pair[0]].insert(pair[1]);
            wordToSimilarWords[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            // If the words are equal, continue.
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            // If the words form a similar pair, continue.
            if (wordToSimilarWords[sentence1[i]].count(sentence2[i])) {
                continue;
            }
            return false;
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
public
    boolean areSentencesSimilar(String[] sentence1, String[] sentence2,
                                List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) {
            return false;
        }
        Map<String, Set<String>> wordToSimilarWords = new HashMap<>();
        for (List<String> pair : similarPairs) {
            wordToSimilarWords.computeIfAbsent(pair.get(0), value->new HashSet<String>())
                .add(pair.get(1));
            wordToSimilarWords.computeIfAbsent(pair.get(1), value->new HashSet<String>())
                .add(pair.get(0));
        }

        for (int i = 0; i < sentence1.length; i++) {
            // If the words are equal, continue.
            if (sentence1[i].equals(sentence2[i])) {
                continue;
            }
            // If the words form a similar pair, continue.
            if (wordToSimilarWords.containsKey(sentence1[i]) &&
                wordToSimilarWords.get(sentence1[i]).contains(sentence2[i])) {
                continue;
            }
            return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2, similarPairs):
        if len(sentence1) != len(sentence2):
            return False
        wordToSimilarWords = defaultdict(set)
        for word1, word2 in similarPairs:
            wordToSimilarWords[word1].add(word2)
            wordToSimilarWords[word2].add(word1)
        for i in range(len(sentence1)):
            if sentence1[i] == sentence2[i] or sentence2[i] in wordToSimilarWords[sentence1[i]]:
                continue
            return False
        return True
```

</details>
