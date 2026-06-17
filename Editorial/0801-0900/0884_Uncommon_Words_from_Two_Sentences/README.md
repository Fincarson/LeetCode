# 884. Uncommon Words from Two Sentences

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/uncommon-words-from-two-sentences/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 884 - Uncommon Words from Two Sentences](https://leetcode.com/problems/uncommon-words-from-two-sentences/)

## Problem

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

### Example 1

### Example 2

## Constraints

- 1 <= s1.length, s2.length <= 200
- s1 and s2 consist of lowercase English letters and spaces.
- s1 and s2 do not have leading or trailing spaces.
- All the words in s1 and s2 are separated by a single space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 884. Uncommon Words from Two Sentences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting | C++, Java, Python3 |

## Approach 1: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        stringstream ss1(A), ss2(B);
        string word;

        // Count occurrences of words in sentence A
        while (ss1 >> word) {
            count[word]++;
        }

        // Count occurrences of words in sentence B
        while (ss2 >> word) {
            count[word]++;
        }

        vector<string> ans;
        for (const auto& entry : count) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> count = new HashMap();
        for (String word : A.split(" ")) count.put(
            word,
            count.getOrDefault(word, 0) + 1
        );
        for (String word : B.split(" ")) count.put(
            word,
            count.getOrDefault(word, 0) + 1
        );

        List<String> ans = new LinkedList();
        for (String word : count.keySet()) if (count.get(word) == 1) ans.add(
            word
        );

        return ans.toArray(new String[ans.size()]);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        from collections import defaultdict

        count = defaultdict(int)

        # Count occurrences of words in sentence A
        for word in A.split():
            count[word] += 1

        # Count occurrences of words in sentence B
        for word in B.split():
            count[word] += 1

        # Collect words that appear exactly once
        return [word for word in count if count[word] == 1]
```

</details>
